#pragma once

class ItemInstance;

class FurnaceRecipes {

public:

	static FurnaceRecipes* getInstance();
	void addFurnaceRecipe(int, const ItemInstance&);
	void addFurnaceRecipeAuxData(short, short, const ItemInstance&);

};