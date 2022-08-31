#pragma once
#include "Instance.hpp"
#include "ShaderComp.hpp"
#include <glslang/Include/BaseTypes.h>

namespace wallpaper
{
namespace vulkan
{

VkFormat ToVkType(glslang::TBasicType, size_t);

struct ShaderReflected {
    struct BlockedUniform {
        int    block_index;
        uint   offset;
        size_t size { 0 };
        size_t num { 1 }; // for array,vector,matrix
    };
    struct Block {
        int         index;
        uint        size;
        std::string name;

        Map<std::string, BlockedUniform> member_map;
    };
    std::vector<Block> blocks;

    Map<std::string, VkDescriptorSetLayoutBinding> binding_map;

    struct Input {
        uint     location;
        VkFormat format;
    };
    Map<std::string, Input> input_location_map;
};

bool GenReflect(std::span<const std::vector<uint>> codes, std::vector<Uni_ShaderSpv>& spvs,
                ShaderReflected& ref);
} // namespace vulkan
} // namespace wallpaper
