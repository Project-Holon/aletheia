/*
 * function: func_021BDD90
 * address: 0x021BDD90
 * packet: pkt_ov210_021BDD90
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021BCB88 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 * symbols:
 *   func_021BC8B4 0x021BC8B4 thumb ov210
 *   func_021BEBE8 0x021BEBE8 thumb ov210
 *   func_021C04CC 0x021C04CC thumb ov210
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   func_021BF728 0x021BF728 thumb ov210
 *   func_021BF5B8 0x021BF5B8 thumb ov210
 *   func_021BCB88 0x021BCB88 thumb ov210
 *   func_021BC5C8 0x021BC5C8 thumb ov210
 *   func_021BCD30 0x021BCD30 thumb ov210
 */
#include "../include/Obj06698.h"
typedef unsigned char u8;
extern void func_021BC8B4(int);
extern void func_021BEBE8(u8 *);
extern void func_021C04CC(char *ctx);
struct S;
extern int FRAME_LIST_UpdateInit(struct S *p);
extern void func_021BF728(u8 *, int);
extern void func_021BF5B8(char *p);
extern void func_021BCB88(u8 *);
extern void func_021BC5C8(void);
extern void func_021BCD30(u8 *);
int func_021BDD90(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 4;
        func_021BC8B4(1);
        func_021BEBE8(p);
        func_021C04CC((char *)p);
        p[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((struct Obj06698 *)p)->f1E0) == 0) {
            func_021BF728(p, 0);
            func_021BF5B8((char *)p);
            func_021BCB88(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 22;
        }
    }
    return 21;
}
