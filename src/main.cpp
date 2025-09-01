#include <iostream>

#include "vector.hpp"
#include "matrix.hpp"
#include "vertex.h"
#include "mesh.h"
#include "framebuffer.h"
#include "camera.h"
#include "renderer.h"

Camera camera(Vec3f(0, 2, -5), Vec3f(0, 0, 0), Vec3f(0, 1, 0), 1.5f);
Framebuffer fb(800, 600);

Renderer renderer;

int main()
{

    renderer.attach_framebuffer(fb);

    Mesh m;

    Vertex v0(-1, 1, 0), v1(1, 1, 0), v2(0, -1, 0);
    m.add_vertex(v0), m.add_vertex(v1), m.add_vertex(v2);
    m.add_index(0), m.add_index(1), m.add_index(2);

    SubMesh sub_mesh;
    sub_mesh.mesh = &m;

    
    
    FILE *fp = fopen("binary.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", 800, 600);

    for (int x = 600 - 1; x >= 0; x--) {
        for (int y = 0; y < 800; y++) {
            int index = x * 800 + y;
            unsigned char color[3];

            color[0] = fb.get_color(index).x_;
            color[1] = fb.get_color(index).y_;
            color[2] = fb.get_color(index).z_;

            fwrite(color, 1, 3, fp);
        }
    }
    fclose(fp);



    return 0;
}