#pragma once
#include <map>
#include <string>

std::map<std::string, std::map<std::string, float>> testCases = {
    //////////////////
    // Lights Group //
    //////////////////
    {
        "cornell_box_point",
        {

        }
    },
    {
        "cornell_box_point_intensity_20",
        {
            {"intensity", 20.f}
        }
    },
    {
        "cornell_box_point_intensity_100",
        {
            {"intensity", 100.f}
        }
    },
    {
        "cornell_box_point_radius_0.2",
        {
            {"radius", 0.2f}
        }
    },
    {
        "cornell_box_point_radius_0.5",
        {
            {"radius", 0.5f}
        }
    },
    {
        "cornell_box_point_radius_1",
        {
            {"radius", 1.f}
        }
    },
    {
        "cornell_box_point_radiance_1",
        {
            {"radiance", 1.f}
        }
    },
    {
        "cornell_box_point_R_1_G_0_B_0",
        {
            {"R", 1.f},
            {"G", 0.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_point_R_0_G_1_B_0",
        {
            {"R", 0.f},
            {"G", 1.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_point_R_0_G_0_B_1",
        {
            {"R", 0.f},
            {"G", 0.f},
            {"B", 1.f}
        }
    },
    {
        "cornell_box_point_X_0.3_Y_0_Z_-1",
        {
            {"X", 0.3f},
            {"Y", 0.f},
            {"Z", -1.f}
        }
    },
    {
        "cornell_box_point_X_0_Y_0.3_Z_-1",
        {
            {"X", 0.f},
            {"Y", 0.3f},
            {"Z", -1.f}
        }
    },
    {
        "cornell_box_point_X_0_Y_0_Z_-0.7",
        {
            {"X", 0.f},
            {"Y", 0.f},
            {"Z", -0.7f}
        }
    },

    {
        "cornell_box_quad",
        {

        }
    },
    {
        "cornell_box_quad_intensity_40",
        {
            {"intensity", 40.f}
        }
    },
    {
        "cornell_box_quad_intensity_100",
        {
            {"intensity", 100.f}
        }
    },
    {
        "cornell_box_quad_radiance_1",
        {
            {"radiance", 1.f}
        }
    },
    {
        "cornell_box_quad_power_20",
        {
            {"intensity", 20.f}
        }
    },
    {
        "cornell_box_quad_R_1_G_0_B_0",
        {
            {"R", 1.f},
            {"G", 0.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_quad_R_0_G_1_B_0",
        {
            {"R", 0.f},
            {"G", 1.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_quad_R_0_G_0_B_1",
        {
            {"R", 0.f},
            {"G", 0.f},
            {"B", 1.f}
        }
    },
    {
        "cornell_box_quad_X_0_Y_0.98_Z_-0.16",
        {
            {"X", 0.f},
            {"Y", 0.98f},
            {"Z", -0.16f}
        }
    },
    {
        "cornell_box_quad_X_-0.23_Y_0.6_Z_-0.16",
        {
            {"X", -0.23f},
            {"Y", 0.6f},
            {"Z", -0.16f}
        }
    },
    {
        "cornell_box_quad_X_-0.23_Y_0.98_Z_0",
        {
            {"X", -0.23f},
            {"Y", 0.98f},
            {"Z", 0.f}
        }
    },

    {
        "cornell_box_directional",
        {

        }
    },
    {
        "cornell_box_directional_angularDiameter_0.2",
        {
            {"angularDiameter", 0.2f}
        }
    },
    {
        "cornell_box_directional_angularDiameter_1",
        {
            {"angularDiameter", 1.f}
        }
    },
    {
        "cornell_box_directional_R_1_G_0_B_0",
        {
            {"R", 1.f},
            {"G", 0.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_directional_R_0_G_1_B_0",
        {
            {"R", 0.f},
            {"G", 1.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_directional_R_0_G_0_B_1",
        {
            {"R", 0.f},
            {"G", 0.f},
            {"B", 1.f}
        }
    },
    {
        "cornell_box_directional_X_0.2_Y_0_Z_1",
        {
            {"dirX", 0.2f},
            {"dirY", 0.f},
            {"dirZ", 1.f}
        }
    },
    {
        "cornell_box_directional_X_0_Y_0.2_Z_1",
        {
            {"dirX", 0.f},
            {"dirY", 0.2f},
            {"dirZ", 1.f}
        }
    },
    {
        "cornell_box_directional_X_0_Y_0_Z_0.8",
        {
            {"dirX", 0.f},
            {"dirY", 0.f},
            {"dirZ", 0.f}
        }
    },

    {
        "cornell_box_spot",
        {

        }
    },
    {
        "cornell_box_spot_intensity_10",
        {
            {"intensity", 10.f}
        }
    },
    {
        "cornell_box_spot_intensity_40",
        {
            {"intensity", 40.f}
        }
    },
    {
        "cornell_box_spot_openingAngle_0.4",
        {
            {"openingAngle", 0.4f}
        }
    },
    {
        "cornell_box_spot_openingAngle_1",
        {
            {"openingAngle", 1.f}
        }
    },
    {
        "cornell_box_spot_falloffAngle_0",
        {
            {"falloffAngle", 0.f}
        }
    },
    {
        "cornell_box_spot_falloffAngle_1",
        {
            {"falloffAngle", 1.f}
        }
    },
    {
        "cornell_box_spot_power_100",
        {
            {"power", 100.f}
        }
    },
    {
        "cornell_box_spot_R_0_G_1_B_0",
        {
            {"R", 0.f},
            {"G", 1.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_spot_R_0_G_0_B_1",
        {
            {"R", 0.f},
            {"G", 0.f},
            {"B", 1.f}
        }
    },
    {
        "cornell_box_spot_X_0_Y_0_Z_-3",
        {
            {"X", 0.f},
            {"Y", 0.f},
            {"Z", -3.f}
        }
    },
    {
        "cornell_box_spot_X_0.1_Y_0_Z_-2",
        {
            {"X", 0.1f},
            {"Y", 0.f},
            {"Z", -2.f}
        }
    },
    {
        "cornell_box_spot_X_0_Y_0.1_Z_-2",
        {
            {"X", 0.f},
            {"Y", 0.1f},
            {"Z", -2.f}
        }
    },
    {
        "cornell_box_spot_dirX_0_dirY_0_dirZ_1.1",
        {
            {"dirX", 0.f},
            {"dirY", 0.f},
            {"dirZ", 1.1f}
        }
    },
    {
        "cornell_box_spot_dirX_0_dirY_0.1_dirZ_1",
        {
            {"dirX", 0.f},
            {"dirY", 0.1f},
            {"dirZ", 1.f}
        }
    },
    {
        "cornell_box_spot_dirX_0.1_dirY_0_dirZ_1",
        {
            {"dirX", 0.1f},
            {"dirY", 0.f},
            {"dirZ", 1.f}
        }
    },

    {
        "cornell_box_ring",
        {

        }
    },
    {
        "cornell_box_ring_intensity_2.5",
        {
            {"intensity", 2.5f}
        }
    },
    {
        "cornell_box_ring_intensity_10",
        {
            {"intensity", 10.f}
        }
    },
    {
        "cornell_box_ring_openingAngle_0.5",
        {
            {"openingAngle", 0.5f}
        }
    },
    {
        "cornell_box_ring_openingAngle_2",
        {
            {"openingAngle", 2.f}
        }
    },
    {
        "cornell_box_ring_openingAngle_4",
        {
            {"openingAngle", 4.f}
        }
    },
    {
        "cornell_box_ring_falloffAngle_1",
        {
            {"falloffAngle", 1.f}
        }
    },
    {
        "cornell_box_ring_falloffAngle_0.5",
        {
            {"falloffAngle", 0.5f}
        }
    },
    {
        "cornell_box_ring_radius_0.5",
        {
            {"radius", 0.5f}
        }
    },
    {
        "cornell_box_ring_radius_2",
        {
            {"radius", 2.f}
        }
    },
    {
        "cornell_box_ring_innerRadius_0.5",
        {
            {"innerRadius", 0.5f}
        }
    },
    {
        "cornell_box_ring_innerRadius_1",
        {
            {"innerRadius", 1.f}
        }
    },
    {
        "cornell_box_ring_radiance_1",
        {
            {"radiance", 1.f}
        }
    },
    {
        "cornell_box_ring_radiance_2",
        {
            {"radiance", 2.f}
        }
    },
    {
        "cornell_box_ring_R_1_G_0_B_0",
        {
            {"R", 1.f},
            {"G", 0.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_ring_R_0_G_1_B_0",
        {
            {"R", 0.f},
            {"G", 1.f},
            {"B", 0.f}
        }
    },
    {
        "cornell_box_ring_R_0_G_0_B_1",
        {
            {"R", 0.f},
            {"G", 0.f},
            {"B", 1.f}
        }
    },
    {
        "cornell_box_ring_X_1_Y_0_Z_0",
        {
            {"X", 1.f},
            {"Y", 0.f},
            {"Z", 0.f}
        }
    },
    {
        "cornell_box_ring_X_0_Y_1_Z_0",
        {
            {"X", 0.f},
            {"Y", 1.f},
            {"Z", 0.f}
        }
    },
    {
        "cornell_box_ring_X_0_Y_0_Z_1",
        {
            {"X", 0.f},
            {"Y", 0.f},
            {"Z", 1.f}
        }
    },
    {
        "cornell_box_ring_dirX_0.2_dirY_0_dirZ_1",
        {
            {"dirX", 0.2f},
            {"dirY", 0.f},
            {"dirZ", 1.f}
        }
    },
    {
        "cornell_box_ring_dirX_0_dirY_0.2_dirZ_1",
        {
            {"dirX", 0.f},
            {"dirY", 0.2f},
            {"dirZ", 1.f}
        }
    },

    {
        "cornell_box_multilight",
        {

        }
    },


    ////////////////////
    // Textures Group //
    ////////////////////
    {
        "textured_cube",
        {

        }
    },

    /////////////////////
    // Instances Group //
    /////////////////////
    {
        "random_spheres",
        {

        }
    },
    {
        "instanced_cubes",
        {

        }
    },
        
    ////////////////////
    // Geometry Group //
    ////////////////////
    {
        "cornell_box_quad_geom",
        {

        }
    },
    {
        "cornell_box_cone_geom",
        {

        }
    },
    {
        "cornell_box_cylinder_geom",
        {

        }
    },
        
    //////////////////
    // Volume Group //
    //////////////////
    {
        "volume_test",
        {

        }
    },
    {
        "volume_test_densityScale_5",
        {
            {"densityScale", 5.f}
        }
    },
    {
        "volume_test_densityScale_0.5",
        {
            {"densityScale", 0.5f}
        }
    },
    {
        "volume_test_valueRangeLeft_0.5",
        {
            {"valueRangeLeft", 0.5f}
        }
    },
    {
        "volume_test_valueRangeRight_2",
        {
            {"valueRangeLeft", 2.f}
        }
    }
};