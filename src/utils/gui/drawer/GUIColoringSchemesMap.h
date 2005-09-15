#ifndef GUIColoringSchemesMap_h
#define GUIColoringSchemesMap_h
//---------------------------------------------------------------------------//
//                        GUIColoringSchemesMap.h -
//  A mapping between coloring schemes, their enumerations and int values
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Sept 2002
//  copyright            : (C) 2002 by Daniel Krajzewicz
//  organisation         : IVF/DLR http://ivf.dlr.de
//  email                : Daniel.Krajzewicz@dlr.de
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//---------------------------------------------------------------------------//
// $Log$
// Revision 1.3  2005/09/15 12:19:10  dkrajzew
// LARGE CODE RECHECK
//
// Revision 1.2  2005/02/17 10:33:41  dkrajzew
// code beautifying;
// Linux building patched;
// warnings removed;
// new configuration usage within guisim
//
// Revision 1.1  2004/11/23 10:38:30  dkrajzew
// debugging
//
// Revision 1.1  2004/10/22 12:50:48  dksumo
// initial checkin into an internal, standalone SUMO CVS
//
// Revision 1.1  2004/08/02 11:38:18  dkrajzew
// variable coloring schemes added
//
/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif // HAVE_CONFIG_H

#include <vector>
#include <string>
#include <fx.h>
#include "GUIBaseColorer.h"


/* =========================================================================
 * class definitions
 * ======================================================================= */
/**
 * @class GUIColoringSchemesMap
 * To allow a variable usage of coloring schemes - as not always all are available
 * - this structure holds the mapping between their enumeration representations
 * as understood by the corresponding drawer classes, their names and their
 * numerical representation within a filled chooser widget.
 */
template<typename E1, class T1>
class GUIColoringSchemesMap {
public:
    /// Constructor
    GUIColoringSchemesMap()
        { }

    /// Destructor
    ~GUIColoringSchemesMap()
    {
        typename std::vector<ColorMapping>::iterator i;
        for(i=myAvailableSchemes.begin(); i!=myAvailableSchemes.end(); ++i) {
            delete (*i).colorer;
        }
        myAvailableSchemes.clear();
    }

    /// Adds a named coloring scheme identifier to the list of allowed coloring schemes
    void add(const std::string &name, E1 enumValue, GUIBaseColorer<T1> *colorer) {
        ColorMapping cm;
        cm.name = name;
        cm.enumValue = enumValue;
        cm.colorer = colorer;
        myAvailableSchemes.push_back(cm);
    }

    /** @brief Fills the given combobox with the names of available coloring
        The indices of the coloring schemes are stored within this structures
        in order to allow the retrieval of their enumeration values. */
    void fill(FXComboBox &cb) {
        int choserValue = 0;
        typename std::vector<ColorMapping>::iterator i;
        for(i=myAvailableSchemes.begin(); i!=myAvailableSchemes.end(); ++i) {
            (*i).choserValue = choserValue++;
            cb.appendItem((*i).name.c_str());
        }
    }

    /** @brief Fills the given popup with the names of available coloring
        The indices of the coloring schemes are stored within this structures
        in order to allow the retrieval of their enumeration values. */
    void fill(FXPopup &p, FXObject *target, int selector) {
        int choserValue = 0;
        typename std::vector<ColorMapping>::iterator i;
        for(i=myAvailableSchemes.begin(); i!=myAvailableSchemes.end(); ++i) {
            (*i).choserValue = choserValue++;
            new FXButton(&p, (*i).name.c_str(),
                NULL,target,selector+choserValue-1,FRAME_THICK|FRAME_RAISED);
        }
    }

    /// Returns the enumeration value for a previously given int value
    E1 getEnumValue(int choserValue) const {
        typename std::vector<ColorMapping>::const_iterator i;
        for(i=myAvailableSchemes.begin(); i!=myAvailableSchemes.end(); ++i) {
            if((*i).choserValue==choserValue) {
                return (*i).enumValue;
            }
        }
        throw 1; // !!!
    }

    /// Returns the number of available coloring schemes
    size_t size() const {
        return myAvailableSchemes.size();
    }

    GUIBaseColorer<T1> *getColorer(int choserValue) const {
        typename std::vector<ColorMapping>::const_iterator i;
        for(i=myAvailableSchemes.begin(); i!=myAvailableSchemes.end(); ++i) {
            if((*i).choserValue==choserValue) {
                return (*i).colorer;
            }
        }
        throw 1; // !!!
    }

private:
    /**
     * @struct ColorMapping
     * This structure holds - for each coloring scheme - its name, numerical index
     *  within the filled structure and the enumeration type.
     */
    struct ColorMapping {
        /// The name of the coloring scheme
        std::string name;

        /// The coloring scheme's enumeration value
        E1 enumValue;

        /// The coloring scheme's enumeration index
        int choserValue;

        /// The colorer to use
        GUIBaseColorer<T1> *colorer;

    };

    /// The list of available schemes
    std::vector<ColorMapping> myAvailableSchemes;

};

/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/

#endif

// Local Variables:
// mode:C++
// End:

