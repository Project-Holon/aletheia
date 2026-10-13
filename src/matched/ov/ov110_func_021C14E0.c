/*
 * function: func_021C14E0
 * address: 0x021C14E0
 * packet: pkt_ov110_021C14E0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends with zero padding at 0x021C154A.
 * symbols:
 *   func_021C0B44 0x021C0B44 thumb ov110
 *   func_020355C4 0x020355C4 arm
 *   BRIGHTNESS_Set 0x02023F60 thumb
 *   func_021C09E0 0x021C09E0 thumb ov110
 *   func_021C0C50 0x021C0C50 thumb ov110
 */
#include "../include/Obj03244.h"
typedef unsigned char u8;
struct TaskMenu;
extern void func_021C0B44(struct TaskMenu *);
extern u8 func_020355C4(void);
extern void BRIGHTNESS_Set(unsigned, unsigned, unsigned);
extern void func_021C09E0(u8 *);
extern void func_021C0C50(u8 *);
int func_021C14E0(void *arg, u8 *p) {
    func_021C0B44(((struct Obj03244 *)p)->f68);
    ((struct Obj03244 *)p)->fA8 = func_020355C4()==1;
    if (((struct Obj03244 *)p)->fA0==4) {
        BRIGHTNESS_Set(0,30,1);
        func_021C09E0(p+0x24);
        p[0x44]=0;
        ((struct Obj03244 *)p)->f40=0;
        if (((struct Obj03244 *)p)->fA8!=0) {
            p[0x94]=p[0x95];
            p[0x95]=255;
            func_021C0C50(p);
        }
    }
    return 1;
}
