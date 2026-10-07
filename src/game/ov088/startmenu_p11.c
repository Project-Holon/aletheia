/*
 * file:     startmenu_p11.c
 * unit:     yes
 * function: func_021BB9DC, func_021BBA64
 * address:  0x021BB9DC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0200C308  0x0200C308  thumb
 *   func_02041300  0x02041300  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../../matched/include/Obj03675.h"

struct Blk34;
struct Obj;
typedef unsigned char u8;

typedef unsigned int   u32;

extern void func_0204B3DC(struct Obj *p, u32 v);
extern u8 func_0200C308(struct Blk34 *p, u32 i);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5,
                          u32 a6);
extern void func_02041B6C(u32);
void func_021BB9DC(char *p, int flag);
void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bg);


void func_021BB9DC(char *p, int flag)
{
    unsigned i;
    if (flag == 0) {
        for (i = 0; i <= 5; i++)
            func_0204B3DC(*(void **)(p + 0x1c + i * 4), flag);
        return;
    }
    func_0204B3DC(((struct Obj03675 *)p)->f1C, 1);
    for (i = 0; i < 8; i++) {
        u8 c = *(u8 *)(p + 0x120 + i);
        if (c == 8)
            return;
        if (c == 3) {
            if (func_0200C308(((struct Obj03675 *)p)->f8, 1) == 1)
                func_0204B3DC(((struct Obj03675 *)p)->f24, 1);
        } else if (c == 4) {
            if (func_0200C308(((struct Obj03675 *)p)->f8, 2) == 1)
                func_0204B3DC(((struct Obj03675 *)p)->f28, 1);
        } else if (c == 7) {
            if (func_0200C308(((struct Obj03675 *)p)->f8, 3) == 1)
                func_0204B3DC(((struct Obj03675 *)p)->f2C, 1);
        } else if (c == 5) {
            func_0204B3DC(((struct Obj03675 *)p)->f30, 1);
        }
    }
}


void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bg)
{
    u32 layer = *(u32 *)&bg;

    func_02041300(layer, 1, x, y, 1, 1, 1);
    func_02041300(layer, 3, x + w - 1, y, 1, 1, 1);
    func_02041300(layer, 7, x, y + h - 1, 1, 1, 1);
    func_02041300(layer, 9, x + w - 1, y + h - 1, 1, 1, 1);
    func_02041300(layer, 2, x + 1, y, w - 2, 1, 1);
    func_02041300(layer, 8, x + 1, y + h - 1, w - 2, 1, 1);
    func_02041300(layer, 4, x, y + 1, 1, h - 2, 1);
    func_02041300(layer, 6, x + w - 1, y + 1, 1, h - 2, 1);
    func_02041300(layer, 5, x + 1, y + 1, w - 2, h - 2, 1);
    func_02041B6C(layer);
}
