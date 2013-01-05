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
    core->Update();
    while(view->IsLoading()){
        ofLog(OF_LOG_NOTICE,"View is loading page");
    }
    
    
}

void ofxAwesomium::updateCluster(){
    core->Update();
    for(int i = 0;i<webviews.size();i++){
        while(webviews.at(i)->IsLoading()){
            ofLog(OF_LOG_NOTICE,"Views are loading their pages");
        }
    }
    
    
}

void ofxAwesomium::setWebView(string url,int width,int height){
    
    const char * path = url.c_str();
    
    WebView * view = core->CreateWebView(width,height);
    
    view->LoadURL(Awesomium::WebURL(Awesomium::WSLit(path)));
       
}


void ofxAwesomium::makeWebView(string url,int width,int height){
    const char * path = url.c_str();
    
    for(int i = 0;i<webviews.size();i++){
        webviews.at(i)->LoadURL(Awesomium::WebURL(Awesomium::WSLit(path)));
    }
}

void ofxAwesomium::draw(float x,float y, float w, float h){
    viewData.draw(x,y,w,h);
}
void ofxAwesomium::draw(float x, float y){
    viewData.draw(x,y);
    
}

void ofxAwesomium::draw(float x, float y, float z, float w, float h){
    viewData.draw(x,y,z,w,h);
}

void ofxAwesomium::draw(float x,float y,float z){
    viewData.draw(x,y,z);
}


/**======================
    SURFACE HANDLING
 ==========================*/
ofTexture ofxAwesomium::createTexture(Awesomium::WebView view){

    BitmapSurface * surface = (BitmapSurface*)view.surface();
    
    ofTexture data;
    data.loadData(surface->buffer(), surface->width(),surface->height(), GL_RGB);
  
    
    return data;
    
    
};

void ofxAwesomium::setTexture(Awesomium::WebView view){
    BitmapSurface * surface = (BitmapSurface*)view.surface();
    
    viewData.loadData(surface->buffer(),surface->width(),surface->height(),GL_RGB);
    
}