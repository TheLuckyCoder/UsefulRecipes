#include "UsefulRecipes.h"

#include "mcpe/item/Item.h"
#include "mcpe/block/Block.h"

Recipes* UsefulRecipes::_Instance;
std::vector<Recipes::Type> UsefulRecipes::_ingredients;

void UsefulRecipes::initRecipes(Recipes *instance) {	
	_Instance = instance;
	
	/* Slimeball */
	pushIngredient(325, 's');
	pushIngredient(337, 'c'); // Clay
	pushIngredient(351, 10, 'd'); / /Dye
	addRecipe(341, 1, 0, {"sc", "d "});
	
	/* String */
	pushIngredient(338, 'c'); // Sugar Cane
	addRecipe(287, 6, 0, {"c ", "c "});
	
	/* String */
	pushIngredient(35, 'w'); // Wool
	addRecipe(287, 6, 0, {"w ", "  "});
	
	/* Blaze Rod */
	pushIngredient(280, 's'); // Stick
	pushIngredient(377, 'p'); // Blaze Powder
	addRecipe(369, 1, 0, {" p ", "psp", " s "});
	
	/* Blaze Powder */
	pushIngredient(331, 'r'); // Redstone Dust
	pushIngredient(348, 'g'); // Glowstone Dust
	addRecipe(377, 1, 0, {"rg", "  "});
	
	/* Nametag */
	pushIngredient(287, 's'); // String
	pushIngredient(339, 'p'); // Paper
	addRecipe(421, 1, 0, {"  s", " p ", "p  "});
	
	/* Saddle */
	pushIngredient(334, 'l'); // Leather
	pushIngredient(265, 'i'); // Iron Ingot
	pushIngredient(287, 's'); // String
	addRecipe(329, 1, 0, {"lll", "lsl", " i "});
	
	/* Grass Block */
	pushIngredient(295, 's'); // Seeds
	pushIngredient(3, 'd'); // Dirt
	addRecipe(2, 1, 0, {"s ", "d "});
	
	/* Flint */
	pushIngredient(13, 'g'); // Gravel
	addRecipe(318, 1, 0, {"g ", "  "});
	
	/* Wodden Planks */
	pushIngredient(280, 's'); // Stick
	addRecipe(5, 1, 0, {"ss", "ss"});

	/* Packed Ice */
	pushIngredient(79, 'i'); // Ice
	addRecipe(174, 1, 0, {"ii", "ii"});

	/* Mycelium */
	pushIngredient(39, 'a'); // Brown Mushroom
	pushIngredient(40, 'b'); // Red Mushroom
	pushIngredient(3, 'd'); // Dirt
	addRecipe(110, 1, 0, {"ab", "d "});

	/* Chain Helmet */
	pushIngredient(101, 'i'); // Iron Bars
	addRecipe(302, 1, 0, {"iii", "i i", "   "});

	/* Chain Chestplate */
	pushIngredient(101, 'i'); // Iron Bars
	addRecipe(303, 1, 0, {"i i", "iii", "iii"});

	/* Chain Leggings */
	pushIngredient(101, 'i'); // Iron Bars
	addRecipe(302, 1, 0, {"iii", "i i", "i i"});

	/* Chain Boots */
	pushIngredient(101, 'i'); // Iron Bars
	addRecipe(302, 1, 0, {"   ", "i i", "i i"});

	/* Cobweb */
	pushIngredient(287, 's'); // String
	addRecipe(30, 1, 0, {"sss", "sss", "sss"});

	/* Vines */
	pushIngredient(18, 3, 'a'); // Leaves
	addRecipe(106, 6, 0, {"aa ", "aa ", "aa "});

	/* Iron Horse Armor */
	pushIngredient(308, 'l');
	pushIngredient(306, 'h');
	pushIngredient(265, 'm');
	addRecipe(110, 1, 0, {"  h", "mmm", "l l"});

	/* Gold Horse Armor */
	pushIngredient(316, 'l');
	pushIngredient(314, 'h');
	pushIngredient(266, 'm');
	addRecipe(110, 1, 0, {"  h", "mmm", "l l"});

	/* Diamond Horse Armor */
	pushIngredient(312, 'l');
	pushIngredient(310, 'h');
	pushIngredient(264, 'm');
	addRecipe(110, 1, 0, {"  h", "mmm", "l l"});

	/* Nether Wart */
	pushIngredient(88, 'a'); // Soul Sand
	pushIngredient(295, 'b'); // Seeds
	addRecipe(372, 2, 0, {"ab", "ba"});

	/* Nether Star */
	pushIngredient(406, 'q'); // Nether Quartz
	pushIngredient(388, 'e'); // Emerald
	pushIngredient(264, 'd'); // Diamond
	pushIngredient(377, 'p'); // Blaze Powder
	addRecipe(110, 1, 0, {"eqd", "qpq", "dqe"});

	/* Netherrack */
	pushIngredient(4, 'c'); // Cobblestone
	pushIngredient(259, 'f'); // Flint and Steel
	addRecipe(87, 8, 0, {"ccc", "cfc", "ccc"});

	/* Nether Quartz Ore */
	pushIngredient(87, 'r'); // Netherrack
	pushIngredient(406, 'q'); // Quartz
	addRecipe(153, 1, 0, { "ccc", "cfc", "ccc" });

	/* Soul Sand */
	pushIngredient(30, 'c'); // Cobweb
	pushIngredient(12, 's'); // Sand
	addRecipe(87, 8, 0, {"sss", "scs", "sss"});

	/* Bedrock */
	pushIngredient(49, 'o'); // Obsidian
	addRecipe(7, 1, 0, { "ooo", "ooo", "ooo"});

	/* Spawner */
	pushIngredient(101, 'c'); // Iron Cage
	addRecipe(87, 1, 0, { "ccc", "c c", "ccc" });
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
