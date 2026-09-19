// © Joseph Cameron - All Rights Reserved

#ifndef GDK_GFX_TEXTURE_DATA_H
#define GDK_GFX_TEXTURE_DATA_H

#include <cstddef>
#include <vector>

/// \file
/// \brief what the core takes: decoded channel data and the metadata describing it
namespace gdk::graphics::texture_data {
    //TODO: rename one,two,three,four since which channels the data is stored in from the perspective of a shader depends on the implementation
    // Why: opengles rgba, rgb, luminance (1ch), luminance alpha (2ch). I cant change this behavior,
    // giving them the more intuitive 'grey' and 'rg' are misleading
    /// \brief format of data in the component_type array
    ///
    /// **Defined with the data, not the texture**: an image is decoded into a format whether or not
    /// anything uploads it. gdk::graphics::texture::format names this same type.
    enum class format {
        grey, //!< a sequence of 1 channel, single byte color: grey, ...
        rg,   //!< a sequence of 2 channels, single byte colors: red, green, ...
        rgb,  //!< a sequence of 3 channels, single byte colors: red, green, blue, ...
        rgba, //!< a sequence of 4 channels, single byte colors: red, green, blue, alpha, ...
    };

    using channel_type = unsigned char;
    using channel_data = std::vector<channel_type>;
    using encoded_byte = unsigned char;

    /// \brief provides a pointer a contiguous list of channel data representing 2D texture
    /// metadata that contains its size, format and usage info
    /// \warning a view does not own its data.
    struct view {
        size_t width;               //!< number of texels wide
        size_t height;              //!< number of texels tall
        texture_data::format format;     //!< format of the data
        const channel_type *data;   //!< ptr to the start of decoded texture data
    };

    /*/// \brief provides a pointer a contiguous list of channel data representing 3D texture
    /// metadata that contains its size, format and usage info
    /// \warning a view does not own its data.
    struct view3d {
        size_t width; //!< number of texels wide
        size_t height; //!< number of texels tall
        size_t length; //!< number of texels long 
        texture_data::format format; //!< format of the data
        const channel_type *data; //!< ptr to the start of decoded texture data
    };*/

}

#endif

