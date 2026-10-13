/*
 * function: func_021C1B04
 * address: 0x021C1B04
 * packet: pkt_ov099_021C1B04
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: byte addition of 254 emits adds #0xfe; subtraction emits subs #2.
 * prototype: B9800/B984C leave their C4864 result live; this caller reads r0.
 * symbols:
 *   func_021B9800 0x021B9800 thumb ov099
 *   func_021B984C 0x021B984C thumb ov099
 *   func_021C208C 0x021C208C thumb ov099
 *   func_021BB2F0 0x021BB2F0 thumb ov099
 *   func_021BB42C 0x021BB42C thumb ov099
 *   func_021BB4D0 0x021BB4D0 thumb ov099
 *   func_021BB4EC 0x021BB4EC thumb ov099
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   func_021C1CD4 0x021C1CD4 thumb ov099
 *   func_021C2090 0x021C2090 thumb ov099
 *   func_021C1C10 0x021C1C10 thumb ov099
 *   func_021C19DC 0x021C19DC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021B9800(void *);
extern u32 func_021B984C(void *);
extern void func_021C208C(char *);
extern void func_021BB2F0(char *, int);
extern void func_021BB42C(void *);
extern void func_021BB4D0(char *);
extern void func_021BB4EC(void *);
typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void func_021C1CD4(void *);
extern void func_021C2090(char *);
extern int func_021C1C10(void *);
extern void func_021C19DC(char *, int);
u8 func_021C1B04(char *p, int heap)
{
    u32 first, second;
    first = func_021B9800(p + 0x274);
    second = func_021B984C(p + 0x274);
    if (second >= 3 && second <= 6) first = second;
    if (first >= 3 && first <= 6 && ((struct Obj00008 *)p)->f8EC != first - 3) {
        ((struct Obj00008 *)p)->f8EC = first - 3;
        func_021C208C(p);
        ((struct Obj00008 *)p)->f8F1 = 1;
        ((struct Obj00008 *)p)->f8F4 = 1;
    }
    if (((struct Obj00008 *)p)->f8EF == 1) {
        ((struct Obj00008 *)p)->f8EF = 2;
        func_021BB2F0(p, heap);
    }
    if (((struct Obj00008 *)p)->f8EF == 0) {
        func_021BB42C(p);
        func_021BB4D0(p);
        func_021BB4EC(p);
        BUTTON_MAN_UpdateSlots(((struct Obj00008 *)p)->f8C8);
        func_021C1CD4(p);
        if (((struct Obj00008 *)p)->f8F1 == 1) {
            func_021C2090(p);
            ((struct Obj00008 *)p)->f8F1 = 0;
        }
    }
    if ((u8)(((struct Obj00008 *)p)->f8EF + 254) <= 1 && func_021C1C10(p) == 1) {
        ((struct Obj00008 *)p)->f8ED = 0;
        ((struct Obj00008 *)p)->f8EE = 0;
        ((struct Obj00008 *)p)->f8F1 = 1;
        ((struct Obj00008 *)p)->f8F4 = 1;
        func_021C19DC(p, heap);
        ((struct Obj00008 *)p)->f8EF = 0;
        ((struct Obj00008 *)p)->f8F4 = 1;
    }
    return ((struct Obj00008 *)p)->f8ED;
}
