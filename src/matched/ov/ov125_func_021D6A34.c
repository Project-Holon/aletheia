/*
 * function: func_021D6A34
 * address: 0x021D6A34
 * packet: pkt_ov125_021D6A34
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D85C0 0x021D85C0 arm ov125
 *   func_021D6B40 0x021D6B40 thumb ov125
 *   func_021D6FB0 0x021D6FB0 thumb ov125
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj01060.h"
typedef unsigned char u8;
typedef int (*Callback)(void *, void *);
extern unsigned func_021D85C0(void);
extern int func_021D6B40(u8 *p, int *done);
extern int func_021D6FB0(char *);
extern void MI_CpuFill8(void *, int, unsigned);
int func_021D6A34(char *p)
{
    int result;
    if (((struct Obj01060 *)p)->f3B4 == 1) {
        if (((struct Obj01060 *)p)->f3D8 != 0x55f4) {
            if (((struct Obj01060 *)p)->f401 != 0) {
                (((struct Obj01060 *)p)->f401)--;
            } else {
                switch (func_021D85C0()) {
                case 1: case 7: case 8: case 9:
                    if (func_021D6B40((u8 *)p, &result) == 1) {
                        ((struct Obj01060 *)p)->f3D8 = 0x55f4;
                        ((struct Obj01060 *)p)->f402 = 0;
                        if (result == 1) {
                            ((struct Obj01060 *)p)->f168 = 2;
                            ((struct Obj01060 *)p)->f16C = 0x55f0;
                            ((struct Obj01060 *)p)->f170 = ((struct Obj01060 *)p)->f493;
                            ((struct Obj01060 *)p)->f164 = 1;
                            if (*(Callback *)&((struct Obj01060 *)p)->f154 != 0)
                                (*(Callback *)(p + 0x154))(((struct Obj01060 *)p)->f148, p + 0x164);
                        }
                    }
                    break;
                case 0: case 2: case 3: case 4: case 5: case 6:
                default: break;
                }
            }
        }
        func_021D6FB0(p);
        if (*(Callback *)&((struct Obj01060 *)p)->f3FC != 0) {
            if ((*(Callback *)(p + 0x3fc))(p, p + 0x3f0) == 1) {
                *(Callback *)&((struct Obj01060 *)p)->f3FC = 0;
                if (*(Callback *)&((struct Obj01060 *)p)->f3F0 != 0) {
                    (*(Callback *)(p + 0x3f0))(((struct Obj01060 *)p)->f148, p + 0x164);
                    *(Callback *)&((struct Obj01060 *)p)->f3F0 = 0;
                }
                MI_CpuFill8(p + 0x3f0, 0, 16);
                ((struct Obj01060 *)p)->f3DC = 0x55f4;
            }
        }
    }
    return 1;
}
