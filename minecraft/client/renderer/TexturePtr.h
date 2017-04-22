#pragma once

#include <string>
#include "../../resource/ResourceLocation.h"

namespace mce {

struct Texture;
struct TextureGroup;

class TexturePtr {

public:

    TextureGroup* group;
    Texture* texture;
    ResourceLocation location;

    TexturePtr();
    TexturePtr(mce::TexturePtr&&);
    TexturePtr(mce::TextureGroup&, ResourceLocation const&, bool);

    ~TexturePtr();

    mce::TexturePtr& operator=(mce::TexturePtr&&);

    mce::Texture* get() const;
    mce::TextureGroup* getGroup();
    int hashCode() const;

    TexturePtr clone() const;
    void _move(mce::TexturePtr&&);
    void _deref();

    void onGroupReloaded(bool, bool);
    void onGroupDestroyed();

    static TexturePtr makeTemporaryWrapper(mce::Texture&);

    static TexturePtr NONE;

};

};
