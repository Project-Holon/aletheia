/*
 * function: func_0203B52C
 * address:  0x0203B52C
 * packet:   pkt_0203B52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Wave 14: the "unresolvable" second tag site was a misread.  The pool word
 * at 0x0203B5CC (+0xA0) is 0x0203C00C (bytes 0c c0 03 02), not 0x0203B40C;
 * 0x0203C00C is the same tag func_0203AF40 passes and resolves `literal`.
 * The first tag, 0x0203B4DC, resolves `matched` (src/matched/func_0203B4DC.c).
 * The callback takes func_0203D650's result in r0, which is why the
 * function pointer is loaded into r1 (docs/families/net_state.h, THE
 * CALLBACK ARITY RULE).
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_020393D0  0x020393D0  arm
 *   func_020393A8  0x020393A8  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_020399EC  0x020399EC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_0203D650  0x0203D650  arm
 *   g_021469DC     0x021469DC  data
 *   func_0203B4DC  0x0203B4DC  arm
 *   func_0203C00C  0x0203C00C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B52C.c \
 *       --func func_0203B52C --addr 0x0203B52C --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern struct Sys *g_021469DC;
extern void func_0203B4DC(void);
extern void func_0203C00C(void);

extern void *func_0203D798(void);
extern int func_020393D0(void);
extern int func_020393A8(void);
typedef unsigned short u16;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern int func_020399EC(void);
extern int func_02039ACC(void);
extern u32   func_0203D650(void);

struct Slot {
    u8  pad_00[0x2c];
    u32 f2c;
};

void func_0203B52C(struct Slot *p)
{
    func_0203D798();
    if (func_020393D0() != 0)
        return;
    if (func_020393A8() == 0) {
        func_0203AD80((struct NetState *)(*(u32 *)&g_021469DC), (void *)func_0203B4DC, 0, 0x297);
        return;
    }
    if (func_020399EC() == 0)
        return;
    if (func_02039ACC() == 0)
        return;
    if (p->f2c != 0) {
        ((void (*)(u32))p->f2c)(func_0203D650());
        p->f2c = 0;
    }
    func_0203AD80((struct NetState *)(*(u32 *)&g_021469DC), (void *)func_0203C00C, 0, 0x2a6);
}
