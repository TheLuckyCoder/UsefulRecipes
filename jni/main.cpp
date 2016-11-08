#include <jni.h>
#include "Substrate.h"

#include "recipes/UsefulRecipes.h"

static void (*_initRecipes)(Recipes*);
static void initRecipes(Recipes *self) {	
	_initRecipes(self);	
	
	UsefulRecipes::initRecipes(self);
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm,void* arg) {
	MSHookFunction((void*)&Recipes::init, (void*)&initRecipes, (void**)&_initRecipes);
	
	return JNI_VERSION_1_6;
}
