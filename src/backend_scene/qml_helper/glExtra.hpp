#pragma once
#include <memory>
#include <array>
#include <cstdint>

#include <span>
#include "ExSwapchain.hpp"

class GlExtra {
public:
    GlExtra();
    ~GlExtra();
    bool init(void* get_proc_address(const char*));
    uint genExTexture(wallpaper::ExHandle&);
    void deleteTexture(uint);

    std::span<const std::uint8_t> uuid() const;
    wallpaper::TexTiling     tiling() const;

private:
    class impl;
    std::unique_ptr<impl> pImpl;

    bool inited { false };

    wallpaper::TexTiling m_tiling { wallpaper::TexTiling::OPTIMAL };
};
