/*
 * function: func_021B8B7C
 * address:  0x021B8B7C
 * packet:   pkt_ov070_021B8B7C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB398  0x021BB398  thumb  ov070
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7128  0x021B7128  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned int   u32;
struct Obj;
extern void func_020061E4(u32 a);
struct CodeIn;
struct Row;
extern void func_021BB398(int p, u32 val);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
typedef signed int     s32;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void func_021B6100(char *p, int k);
extern void func_021B7128(struct Obj *o);

void func_021B8B7C(int p)
{
    switch (((struct Obj00002 *)p)->f864) {
    case 0:
        func_020061E4(0x54C);
    case 3:
        func_021BB398(p, 0);
        ((struct Obj00002 *)p)->f864 += 1;
        return;
    case 1:
    case 4:
    case 6:
        ((struct Obj00002 *)p)->f866 += 1;
        if (((struct Obj00002 *)p)->f866 == 4) {
            ((struct Obj00002 *)p)->f866 = 0;
            ((struct Obj00002 *)p)->f864 += 1;
        }
        return;
    case 2:
    case 5:
        func_021BB398(p, 2);
        ((struct Obj00002 *)p)->f864 += 1;
        return;
    case 7:
        ((struct Obj00002 *)p)->f864 = 0;
        func_021BB398(p, 1);
        BLINK_PALANM_ResetPhase((struct CodeIn *)(*(int *)&((struct Obj00002 *)p)->f850));
        BLINK_PALANM_Update((struct Row *)(*(int *)&((struct Obj00002 *)p)->f850));
        func_021B6100((char *)p, (int)func_021B7128);
        return;
    }
}
