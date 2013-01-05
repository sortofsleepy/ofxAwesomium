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
    
    void setWebView(const char * url,int width=WEBVIEW_DEFAULT_WIDTH,int height=WEBVIEW_DEFAULT_HEIGHT);
    void makeWebView(const char * url,int width=WEBVIEW_DEFAULT_WIDTH,int height=WEBVIEW_DEFAULT_HEIGHT);
    
    
    void draw();

    /**======================
     CONVERSION FOR RENDERING
     ==========================*/
    //converts the webview surface to ofTexture;
    ofTexture createTexture(Awesomium::WebView view);
    
    
    
};


#endif
