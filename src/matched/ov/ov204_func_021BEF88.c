/*
 * function: func_021BEF88
 * address: 0x021BEF88
 * packet: pkt_ov204_021BEF88
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF228 0x021BF228 thumb ov204
 *   func_021BF030 0x021BF030 thumb ov204
 *   func_021BF094 0x021BF094 thumb ov204
 *   func_021BF00C 0x021BF00C thumb ov204
 *   d_021C09D8 0x021C09D8 data a4
 */
#include "../include/Obj06673.h"
typedef struct Row { unsigned tag; unsigned data[5]; } Row;
typedef unsigned char  u8;
extern void func_021BF228(u8 *p);
extern int func_021BF030(void *);
extern Row *func_021BF094(unsigned);
extern int func_021BF00C(void *, void *);
extern int (*const d_021C09D8[])(void *, void *, void *);
int func_021BEF88(char *p)
{
    func_021BF228(((struct Obj06673 *)p)->f18);
    if (func_021BF030(p) == 0) {
        char *base = p;
        int i;
        base += 0x40;
        for (i = 0; i < 9; i++) {
            Row *row = func_021BF094(((struct Obj06673 *)p)->f1C) + ((struct Obj06673 *)p)->fA0;
            if (row->tag == 1) {
                d_021C09D8[row->tag](p, base + i * 12, row->data);
                row = func_021BF094(((struct Obj06673 *)p)->f1C);
            }
            if (row->tag == 0x34)
                return 0;
            ++((struct Obj06673 *)p)->fA0;
            if (!func_021BF00C(p, row))
                break;
        }
    }
    return 1;
}
