#ifndef QParamPopupMenu_h
#define QParamPopupMenu_h
/***************************************************************************
                          QParamPopupMenu.cpp
	The popup-menu which appears hen pressing right mouse button over a
	 parameter table
                             -------------------
    project              : SUMO - Simulation of Urban MObility
    begin                : Mai 2003
    copyright            : (C) 2003 by Daniel Krajzewicz
    organisation         : IVF/DLR http://ivf.dlr.de
    email                : Daniel.Krajzewicz@dlr.de
 ***************************************************************************/

//---------------------------------------------------------------------------//
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//---------------------------------------------------------------------------//
// $Log$
// Revision 1.1  2003/05/20 09:23:58  dkrajzew
// some statistics added; some debugging done
//
//
/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

#include <qpopupmenu.h>


/* =========================================================================
 * class definitions
 * ======================================================================= */
class GUIParameterTable;
class GUIGlObject;
class GUIApplicationWindow;


/* =========================================================================
 * class declarataions
 * ======================================================================= */
/**
 * @class QParamPopupMenu
 * A popup menu holding the context of a parameter table entry
 */
class QParamPopupMenu :
        public QPopupMenu
{
	// is a q-object (moccing is necessary)
    Q_OBJECT

public:
	/// Constructor
    QParamPopupMenu(GUIApplicationWindow *app,
        GUIParameterTable *parent, GUIGlObject *o,
		int pos);

	/// Destructor
    ~QParamPopupMenu();

public slots:
	/// Opens a new tracker for the variable the context was build for
    void newTracker();

private:
	/// The object the table displays
    GUIGlObject *myObject;

	/** @brief The main application window
		holder of some needed values */
    GUIApplicationWindow *myApplication;

	/// the numerical id of the value (parameter) this popupmenu appears about
	int myItemNo;

};


/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/
//#ifndef DISABLE_INLINE
//#include "QParamPopupMenu.icc"
//#endif

#endif

// Local Variables:
// mode:C++
// End:

