#pragma once

#include <vector>
#include <fstream>
class ResourcePack;
class ResourcePackRepository;
class OfferRepository;
class PackIdVersion;
class ResourcePackMergeStrategy;

struct PackReport {
    int filler[0x5C/4];
    PackReport();
};

struct PackPair {
    ResourcePack* pack;
    bool unknown;
    PackReport report;
};

class ResourcePackStack {

public:

    std::vector<PackPair> stack;

    // virtual
    virtual ~ResourcePackStack();
    virtual void* loadAllVersionsOf(ResourceLocation const&) const;
    virtual void* loadAllVersionsOf(ResourceLocation const&, ResourcePackMergeStrategy&) const;

    // non virtual
    ResourcePackStack(std::vector<ResourcePack*, std::allocator<ResourcePack*>> const&, ResourcePackRepository const&);
    ResourcePackStack(std::vector<PackIdVersion, std::allocator<PackIdVersion>> const&, ResourcePackRepository const&);
    void add(ResourcePack*, ResourcePackRepository const&, bool);
    void* _populateDependencies(std::vector<PackPair, std::allocator<PackPair>>&, ResourcePack&, ResourcePackRepository const&, bool);
    void* getSplitStacks(ResourcePackStack&, ResourcePackStack&) const;
    void* getStack() const;
    void* getStackWithoutDependencies() const;
    void* getStackAsIdentities() const;
    void* deserialize(std::basic_fstream<char, std::char_traits<char>>&, ResourcePackRepository const&);
    void* serialize(std::basic_fstream<char, std::char_traits<char>>&) const;
    void* getLoadingReport() const;
    void* clearPackReports();
    void* mergePackReports(std::vector<PackReport, std::allocator<PackReport>>&);
    void* removeDuplicates();

};

