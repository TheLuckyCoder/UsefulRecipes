#include "UsefulRecipes.h"

#include "mcpe/item/Item.h"
#include "mcpe/block/Block.h"

Recipes* UsefulRecipes::_Instance;
std::vector<Recipes::Type> UsefulRecipes::_ingredients;

void UsefulRecipes::initRecipes(Recipes *instance) {	
	_Instance = instance;
	
	//Slimeball
	pushIngredient(325, 's');
	pushIngredient(337, 'c');
	pushIngredient(351, 10, 'd');
	addRecipe(341, 1, 0, {"sc", "d "});
	
	//String
	pushIngredient(338, 'c');
	addRecipe(287, 6, 0, {" c", " c"});
	
	//String
	pushIngredient(35, 'w');
	addRecipe(287, 6, 0, {"w ", "  "});
	
	//Blaze Rod
	pushIngredient(288, 'p');
	pushIngredient(377, 's');
	addRecipe(369, 1, 0, {" s ", "sps", " s "});
	
	//Blaze Powder
	pushIngredient(331, 'r');
	pushIngredient(348, 'g');
	addRecipe(377, 1, 0, {"rg", "  "});
	
	//Nametag
	pushIngredient(287, 's');
	pushIngredient(339, 'p');
	addRecipe(421, 1, 0, {"  s", " p ", "p  "});
	
	//Saddle
	pushIngredient(333, 'l');
	pushIngredient(265, 'i');
	pushIngredient(287, 's');
	addRecipe(329, 1, 0, {"lll", "lsl", " s "});
	
	//Grass Block
	pushIngredient(295, 's');
	pushIngredient(3, 'd');
	addRecipe(2, 1, 0, {"s ", "d "});
	
	//Flint
	pushIngredient(13, 'g');
	addRecipe(318, 1, 0, {"g ", "  "});
	
	//Wodden Planks
	pushIngredient(288, 's');
	addRecipe(5, 1, 0, {"ss", "ss"});

	//Packed Ice
	pushIngredient(79, 'i');
	addRecipe(174, 1, 0, {"ii", "ii"});

	//Mycelium
	pushIngredient(39, 'a');
	pushIngredient(40, 'b');
	pushIngredient(3, 'd');
	addRecipe(110, 1, 0, {"ab", "d "});

	//Chain Helmet
	pushIngredient(101, 'i');
	addRecipe(302, 1, 0, {"iii", "i i", "   "});

	//Chain Chestplate
	pushIngredient(101, 'i');
	addRecipe(303, 1, 0, {"i i", "iii", "iii"});

	//Chain Leggings
	pushIngredient(101, 'i');
	addRecipe(302, 1, 0, {"iii", "i i", "i i"});

	//Chain Boots
	pushIngredient(101, 'i');
	addRecipe(302, 1, 0, {"   ", "i i", "i i"});

	//Cobweb
	pushIngredient(287, 's');
	addRecipe(30, 1, 0, {"sss", "sss", "sss"});

	//Vines
	pushIngredient(18, 3, 'a');
	addRecipe(106, 2, 0, {"a ", "a "});

	//Iron Horse Armor
	pushIngredient(308, 'l');
	pushIngredient(306, 'h');
	pushIngredient(265, 'i');
	addRecipe(110, 1, 0, {"  h", "iii", "l l"});

	//Gold Horse Armor
	pushIngredient(316, 'l');
	pushIngredient(314, 'h');
	pushIngredient(266, 'i');
	addRecipe(110, 1, 0, {"  h", "iii", "l l"});

	//Diamond Horse Armor
	pushIngredient(312, 'l');
	pushIngredient(310, 'h');
	pushIngredient(264, 'i');
	addRecipe(110, 1, 0, {"  h", "iii", "l l"});

	//Nether Wart
	pushIngredient(88, 'a');
	pushIngredient(295, 'b');
	addRecipe(372, 2, 0, {"ab", "ba"});

	//Nether Star
	pushIngredient(406, 'q');
	pushIngredient(388, 'e');
	pushIngredient(264, 'd');
	pushIngredient(377, 'p');
	addRecipe(110, 1, 0, { "eqd", "qpq", "dqe" });
}

void UsefulRecipes::pushIngredient(int id, char letter) {
	pushIngredient(id, 0, letter);
}

void UsefulRecipes::pushIngredient(int id, int data, char letter) {
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
} 

void UsefulRecipes::addRecipe(int outputID, int outputCount, int outputData, const std::vector<std::string> &shape) {
	ItemInstance output(outputID, 1, outputData);
	output.count = outputCount;
	_Instance->addShapedRecipe(output, shape, _ingredients);	
	_ingredients.clear();
}
