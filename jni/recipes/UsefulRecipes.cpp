#include "UsefulRecipes.h"

#include "mcpe/item/Item.h"
#include "mcpe/block/Block.h"

Recipes* UsefulRecipes::_Instance;
std::vector<Recipes::Type> UsefulRecipes::_ingredients;

void UsefulRecipes::initRecipes(Recipes* instance) {	
	_Instance = instance;
	
	//Slimeball
	pushIngredient(325, 0, 's');
	pushIngredient(337, 0, 'c');
	pushIngredient(351, 10, 'd');
	addRecipe(341, 1, 0, {"sc", "d "});
	
	//String
	pushIngredient(338, 0, 'c');
	addRecipe(287, 6, 0, {" c", " c"});
	
	//String
	pushIngredient(35, 0, 'w');
	addRecipe(287, 6, 0, {"w ", "  "});
	
	//Blaze Rod
	pushIngredient(288, 0, 's');
	pushIngredient(377, 0, 'p');
	addRecipe(369, 1, 0, {" s ", "sps", " s "});
	
	//Blaze Powder
	pushIngredient(331, 0, 'r');
	pushIngredient(348, 0, 'g');
	addRecipe(377, 1, 0, {"rg", "  "});
	
	//Nametag
	pushIngredient(287, 0, 's');
	pushIngredient(339, 0, 'p');
	addRecipe(421, 1, 0, {"  s", " p ", "p  "});
	
	//Saddle
	pushIngredient(333, 0, 'l');
	pushIngredient(265, 0, 'i');
	pushIngredient(287, 0, 's');
	addRecipe(329, 1, 0, {"lll", "lsl", " s "});
	
	//Grass Block
	pushIngredient(295, 0, 's');
	pushIngredient(3, 0, 'd');
	addRecipe(2, 1, 0, {"s ", "d "});
	
	//Flint
	pushIngredient(13, 0, 'g');
	addRecipe(318, 1, 0, {"g ", "  "});
	
	//Wodden Planks
	pushIngredient(288, 0, 's');
	addRecipe(5, 1, 0, {"ss", "ss"});
}

void UsefulRecipes::pushIngredient(int id, int data, char letter) {
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
} 

void UsefulRecipes::addRecipe(int outputID, int outputCount, int outputData, const std::vector<std::string>& shape) {
	ItemInstance output(outputID, 1, outputData);
	output.count = outputCount;
	_Instance->addShapedRecipe(output, shape, _ingredients);	
	_ingredients.clear();
}
