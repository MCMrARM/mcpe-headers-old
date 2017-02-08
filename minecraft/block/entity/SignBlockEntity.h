#pragma once

#include "BlockEntity.h"

class SignBlockEntity : public BlockEntity {
public:

	/* 0x60 */ std::string text1;
	/* 0x64 */ std::string text2;
	/* 0x68 */ std::string text3;
	/* 0x6C */ std::string text4;
	/* 0x70 */ int selectedLine;
	/* 0x74 */ bool editable;
	/* size = 0x78 */

	// virtual
	virtual ~SignBlockEntity();
	virtual void load(CompoundTag const&);
	virtual void save(CompoundTag&);
	virtual void* getUpdatePacket(BlockSource&);
	virtual void onUpdatePacket(CompoundTag const&, BlockSource&);
	virtual int getShadowRadius(BlockSource&) const;

	// non virtual
	SignBlockEntity(BlockPos const&);
	void setMessage(std::string const&, int);
	void setEditable(bool);
	void setSelectedLine(int);
	std::string getMessage(int) const;
	bool isEditable() const;
	int getSelectedLine() const;
};
