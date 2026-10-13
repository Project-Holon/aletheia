/*
 * function: SAVE_CONTROL_Reload
 * address:  0x020070C8
 * packet:   pkt_020070C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BACKUP_SYSTEM_Load  0x02031AE0  arm
 *   func_0200A5F8  0x0200A5F8  thumb
 *   func_0200A7EC  0x0200A7EC  thumb
 *   func_02008784  0x02008784  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_020087C0  0x020087C0  thumb
 *
 * save_control.c.  EXACT* (the 136-byte extent includes the 2-byte pad).
 * Two levers closed the 35-byte near miss of docs/notes/pkt_020070C8.c.txt:
 * the bit loop's counter is an enum, which keeps the `cmp r4, #9; bge`
 * entry guard (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md),
 * and the early exit is `goto end` onto the one `return t`, so the branch
 * lands on the shared `adds r0, r7, #0` instead of straight on the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_Reload.c  *       --func SAVE_CONTROL_Reload --addr 0x020070C8 --thumb --cc 1.1p1
 */
#include "../include/Obj00370.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct State;
extern int  BACKUP_SYSTEM_Load(struct State *v, u32 mode);
extern void *func_0200A5F8(void *self);
struct Big;
extern void func_0200A7EC(struct Big *h, u8 v);
extern int func_02008784(void *sys, u32 index);
struct Ctrl;
extern u32  SAVE_CONTROL_LoadExtraSave(struct Ctrl *self, u32 a, u8 heap);
struct Sub020072A4Ctrl;
extern void func_020072A4(struct Sub020072A4Ctrl *self, u32 a);
extern void func_020087C0(void *sys, u32 index);

typedef enum { BIT_0, BIT_MAX = 9 } Bit;

int SAVE_CONTROL_Reload(char *self)
{
    int t = BACKUP_SYSTEM_Load(*(struct State * *)&((struct Obj00370 *)self)->f10, 1);
    void *h;
    Bit i;

    if (t != 1 && t != 2) {
        goto end;
    }
    {
        ((struct Obj00370 *)self)->f1 = 1;
        h = func_0200A5F8(self);
        func_0200A7EC(h, 0);
        if (func_02008784(self, 6) == 1) {
            int r = SAVE_CONTROL_LoadExtraSave((struct Ctrl *)self, 6, 1);

            func_020072A4((struct Sub020072A4Ctrl *)self, 6);
            if (r != 1 && r != 2)
                goto bits;
            func_0200A7EC(h, 1);
        }
bits:
        if (*(int *)&((struct Obj00370 *)self)->fC != 0) {
            for (i = 0; i < 9; i++) {
                if (*(int *)&((struct Obj00370 *)self)->fC & (1 << (i + 2)))
                    func_020087C0(self, i);
            }
        }
    }
end:
    return t;
}
