#ifndef GUITexturesHelper_h
#define GUITexturesHelper_h

#ifdef HAVE_CONFIG_H
#ifdef WIN32
#include <windows_config.h>
#else
#include <config.h>
#endif
#endif // HAVE_CONFIG_H

#include <fx.h>
#include "GUITextures.h"



class GUITexturesHelper {
public:
    static void init(FXApp *a);
    static void drawDirectionArrow(GUITexture which, SUMOReal size);
    static void drawDirectionArrow(unsigned int which,
        SUMOReal sizeX1, SUMOReal sizeY1, SUMOReal sizeX2, SUMOReal sizeY2);
    static void drawTexturedBox(unsigned int which, SUMOReal size);
    static void drawTexturedBox(unsigned int which,
        SUMOReal sizeX1, SUMOReal sizeY1, SUMOReal sizeX2, SUMOReal sizeY2);
    static void close();
    static unsigned int add(FXImage *i);

private:
    static void assignTextures();

private:
    static bool myWasInitialised;
    static FXApp *myApp;
    static size_t myTextureIDs[TEXTURE_MAX];
    static FXImage *myTextures[TEXTURE_MAX];

};


#endif
