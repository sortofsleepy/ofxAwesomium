//
//  ofxAwesomium.h
//  ofxAwesomium
//
//  Created by Joseph Chow on 1/4/13.
//
//

#ifndef ofxAwesomium_ofxAwesomium_h
#define ofxAwesomium_ofxAwesomium_h

#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>
#include <Awesomium/BitmapSurface.h>
#include "ofMain.h"

#include <vector>
#include <string>

using namespace Awesomium;
using namespace std;

#define WEBVIEW_DEFAULT_WIDTH 640
#define WEBVIEW_DEFAULT_HEIGHT 480

class ofxAwesomium{
    //for defining multiple webviews
    std::vector<Awesomium::WebView*> webviews;
    
    //default singluar WebView
    WebView * view;
    WebCore * core;
    WebSession * session;
    
    //surface used to render WebView
    Surface * surface;
    
    //Factory
    SurfaceFactory * factory;
    
    //dealing with filepaths
    ofFilePath fs;
    
    //texture if we only want to deal with one view
    ofTexture viewData;
    
    //set the location
    ofVec2f loc;
public:
    ofxAwesomium();
    
    /**======================
        BASIC FUNCTIONS
    ==========================*/
    void setup();
    
    /*
        Which update you use depends on how many
        WebView's you made.
    */
    void update();
    void updateCluster();
    
    void setWebView(string url,int width=WEBVIEW_DEFAULT_WIDTH,int height=WEBVIEW_DEFAULT_HEIGHT);
    void makeWebView(string url,int width=WEBVIEW_DEFAULT_WIDTH,int height=WEBVIEW_DEFAULT_HEIGHT);
    
    
    void draw(float x, float y, float w, float h);
    void draw(float x, float y);
    void draw(float x, float y, float z, float w, float h);
    void draw(float x, float y, float z);

    /**======================
     FOR USE WITH CUSTOM DATASOURCES
     ==========================*/
    
    
    /**======================
     CONVERSION FOR RENDERING
     ==========================*/
    //converts the webview surface to ofTexture;
    ofTexture createTexture(Awesomium::WebView view);
    
    virtual void setTexture(Awesomium::WebView view);
    
};


#endif
