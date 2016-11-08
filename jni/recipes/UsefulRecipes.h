#pragma once 

#include "mcpe/recipe/Recipes.h" 

class UsefulRecipes { 
public: 
	static void initRecipes(Recipes *instance);
	
private: 	
	static Recipes* _Instance; 	
	static std::vector<Recipes::Type> _ingredients; 	 	
	static void pushIngredient(int id, char letter);
	static void pushIngredient(int id, int data, char letter);
	static void addRecipe(int outputId, int outputCount, int outputData, const std::vector<std::string> &shape);
};

