/*
 * function: func_021BE708
 * address: 0x021BE708
 * packet: pkt_ov204_021BE708
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SAVE_CONTROL_INTR_IsFinished 0x021BD3A0 thumb ov088
 *   func_021BF23C 0x021BF23C thumb ov204
 *   func_021BF2F4 0x021BF2F4 thumb ov204
 *   func_021BF560 0x021BF560 thumb ov204
 *   func_021BF580 0x021BF580 thumb ov204
 */
#include "../include/Obj05530.h"
typedef unsigned char  u8;
extern int SAVE_CONTROL_INTR_IsFinished(unsigned char *p);
extern void func_021BF23C(char *p, void *a, int flag);
extern int func_021BF2F4(char *a);
extern void func_021BF560(u8 *p);
extern void func_021BF580(u8 *p);
int func_021BE708(char *p, int *state)
{
    switch (*state) {
    case 0:
        if (SAVE_CONTROL_INTR_IsFinished(((struct Obj05530 *)p)->fA4) == 1)
            return 1;
        func_021BF23C(((struct Obj05530 *)p)->f18, (void *)5, 0);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(((struct Obj05530 *)p)->f18) == 1) {
            func_021BF560(((struct Obj05530 *)p)->f18);
            ++*state;
        }
        break;
    case 2:
        if (SAVE_CONTROL_INTR_IsFinished(((struct Obj05530 *)p)->fA4) == 1) {
            func_021BF580(((struct Obj05530 *)p)->f18);
            return 1;
        }
        break;
    }
    return 0;
}
