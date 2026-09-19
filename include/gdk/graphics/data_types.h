// © Joseph Cameron - All Rights Reserved

#ifndef GDK_GRAPHICS_DATA_TYPES_H
#define GDK_GRAPHICS_DATA_TYPES_H

#include <gdk/graphics/color.h>
#include <gdk/math.h>

/// \file
/// \brief the numbers graphics data is written in: what a mesh, an image or an animation is made of
///
/// **The vocabulary gdk-graphics_data and gdk-graphics share**, defined here so that the data side
/// needs nothing of the renderer's. gdk-graphics' types.h includes this and adds the renderer's own
/// types beside it, so a caller including types.h sees both, as it always has.
/// \see code-style.md §4.6
namespace gdk::graphics {
/// \name Floating point types
///@{
//
    using floating_point_type = float;

    using mat3x3_type = matrix3x3<floating_point_type>;
    using matrix4x4_type = matrix4x4<floating_point_type>;
    using quaternion_type = quaternion<floating_point_type>;
    using vector2_type = vector2<floating_point_type>;
    using vector3_type = vector3<floating_point_type>;
    using vector4_type = vector4<floating_point_type>;
///@}

/// \name Signed integral types
///@{
//
    using signed_integral_type = int;

    using intvector2_type = vector2<signed_integral_type>;
    using intvector3_type = vector3<signed_integral_type>;
    using intvector4_type = vector4<signed_integral_type>;
///@}
}

#endif
