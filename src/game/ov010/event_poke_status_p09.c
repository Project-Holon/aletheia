/*
 * file:     event_poke_status_p09.c
 * unit:     yes
 * function: func_02159C68, func_02159CC4, func_02159D04
 * address:  0x02159C68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159E00  0x02159E00  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159D84  0x02159D84  thumb  ov010
 *   func_02159DC8  0x02159DC8  thumb  ov010
 *   func_02159DCC  0x02159DCC  thumb  ov010
 *   func_02159DEC  0x02159DEC  thumb  ov010
 *   func_02082A48  0x02082A48  arm
 *   func_02082A90  0x02082A90  arm
 */
#include "../../matched/include/Obj12278.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj {
    u16 f00;
    u16 f02;
    u32 pad04[3];
    u32 f10;
} Obj;

struct MatrixFile {
    u16 mode;
    u16 pad02;
    u16 width;
    u16 height;
    u32 cells[];
};

struct MapMatrix {
    u16 field00;
    u16 zone_id;
    u32 matrix_id;
    u16 width;
    u16 height;
    u16 mode;
    u16 pad0e;
    u32 count;
    u16 zone_grid[900];
    u32 map_grid[900];
};

extern int func_02159E00(u8 *a, u32 *b, u32 *c);
extern int func_02159B94(int a0, int a1, int a2, int a3);
extern struct Obj *func_02159D84(int a, int b);
extern u32 func_02159DC8(void *p);
extern u32 func_02159DCC(u8 *p, int n);
extern int func_02159DEC(int a0);
extern void func_02082A48(u32 value, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
void func_02159C68(Obj *a, int b, int c);
void func_02159CC4(u32 *a, int b, int c);
void func_02159D04(struct MapMatrix *dst, const struct MatrixFile *src, u32 matrix_id, u16 zone_id);


void func_02159C68(Obj *a, int b, int c)
{
    u32 v[2];
    int r = func_02159E00((u8 *)b, &v[1], &v[0]);
    switch (r) {
    case 0:
        break;
    case 2:
        func_02159B94((int)a, (u16)v[0], a->f02, c);
        return;
    case 1: {
        u32 i;
        for (i = 0; i < a->f10; i++) {
            u32 *p = (u32 *)((u8 *)a + i * 4);
            if (v[1] == ((struct Obj12278 *)p)->f71C)
                ((struct Obj12278 *)p)->f71C = v[0];
        }
        break;
    }
    }
}


void func_02159CC4(u32 *a, int b, int c)
{
    void *l = func_02159D84(c, b);
    int n = func_02159DC8(l);
    int i;
    for (i = 0; i < n; i++) {
        u32 t = func_02159DCC(l, i);
        if (t == a[1])
            func_02159C68((struct Obj *)a, (int)l, c);
    }
    func_02159DEC((int)l);
}


/*
 * The map-matrix decoder: unpack one a/0/0/9 sub-file into the runtime matrix
 * object. File = { u16 mode; u16 pad; u16 width; u16 height; u32 cells[] },
 * plus a second block of the same length when mode == 1. Block one is copied
 * into the u32 grid at +0x71C. Block two is narrowed into the u16 grid at
 * +0x14; without it the u16 grid is filled with the caller's zone id.
 *
 * final push 2026-10-05 G4L1: closed by storing zone_id first (dst->zone_id =
 * zone_id before the matrix_id store). That gives the parameter the earliest
 * birth, so it takes r7 (the later-born cells and pool take r6 and r4). EXACT
 * in c99 and c.
 */
void func_02159D04(struct MapMatrix *dst, const struct MatrixFile *src,
                   u32 matrix_id, u16 zone_id)
{
    u32 n;
    const u32 *cells;
    const u32 *second;
    u32 i;
    u16 *zone_grid;

    dst->zone_id = zone_id;
    dst->matrix_id = matrix_id;
    n = src->width * src->height;
    dst->height = src->height;
    dst->count = n;
    dst->mode = src->mode;
    dst->width = src->width;
    cells = src->cells;
    func_02082A90(cells, dst->map_grid, n * 4);

    zone_grid = dst->zone_grid;
    if (dst->mode == 1) {
        second = cells + dst->count;
        for (i = 0; i < dst->count; i++)
            zone_grid[i] = (u16)second[i];
    } else {
        func_02082A48(zone_id, zone_grid, 0x708);
    }
}
