//
//  ofxAwesomium.cpp
//  ofxAwesomium
//
//  Created by Joseph Chow on 1/4/13.
//
//

#include "ofxAwesomium.h"
ofxAwesomium::ofxAwesomium(){}
/**======================
 BASIC FUNCTIONS
 ==========================*/
void ofxAwesomium::setup(){
    const char * path = fs.getCurrentExeDir().c_str();
    
      core = WebCore::Initialize(WebConfig());
    
    session = core->CreateWebSession(WSLit(path),WebPreferences());
}

void ofxAwesomium::update(){
    while(view->IsLoading()){
        ofLog(OF_LOG_NOTICE,"View is loading page");
    }
    
    core->Update();
}

void ofxAwesomium::updateCluster(){
    for(int i = 0;i<webviews.size();i++){
        while(webviews.at(i)->IsLoading()){
            ofLog(OF_LOG_NOTICE,"Views are loading their pages");
        }
    }
    
    core->Update();
}

void ofxAwesomium::setWebView(const char * url,int width,int height){
    WebView * view = core->CreateWebView(width,height);
    
    view->LoadURL(Awesomium::WebURL(Awesomium::WSLit(url)));
       
}


void ofxAwesomium::makeWebView(const char * url,int width,int height){
    for(int i = 0;i<webviews.size();i++){
        webviews.at(i)->LoadURL(Awesomium::WebURL(Awesomium::WSLit(url)));
    }
}

void ofxAwesomium::draw(){
    
}


/**======================
    SURFACE HANDLING
 ==========================*/
ofTexture ofxAwesomium::createTexture(Awesomium::WebView view){
    
    //grab the surface back from the WebView
    Surface * initSurface = view.surface();
    
    
    
};