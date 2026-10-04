/*
 * function: func_021F1A64
 * address:  0x021F1A64
 * packet:   pkt_ov029_021F1A64
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021F1F80  0x021F1F80  thumb  ov029
 */
#include "../include/Obj00106.h"

typedef unsigned char u8;

struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_021F1F80(char *p);

void func_021F1A64(char *p, int flag)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (*(int *)(p + i * 12 + 0x3c) != 0) {
            func_0204B3DC((struct Obj *)*(int *)(p + i * 12 + 0x3c), flag);
        }
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 4 + 0x158) != 0 && ((struct Obj00106 *)p)->f45A != 0) {
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x158), flag);
        }
    }
    for (i = 0; i < 11; i++) {
        if (*(int *)(p + i * 4 + 0x12c) != 0) {
            if ((unsigned)(i - 8) <= 1) {
                if (((struct Obj00106 *)p)->f45A != 0) {
                    func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x12c), flag);
                }
            } else {
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x12c), flag);
            }
        }
    }
    if (((struct Obj00106 *)p)->f164 != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f164, flag);
    }
    if (((struct Obj00106 *)p)->f168 != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f168, flag);
    }
    if (((struct Obj00106 *)p)->f16C != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f16C, flag);
    }
    if (flag == 1) {
        func_021F1F80(p);
    }
}
