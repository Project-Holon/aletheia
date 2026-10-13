/*
 * function: func_021D9C34
 * address:  0x021D9C34
 * packet:   pkt_021D9C34
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020362DC                0x020362DC  arm
 *   func_021E8738                0x021E8738  thumb  ov177
 *   func_021E8844                0x021E8844  thumb  ov177
 *   func_021D98E4                0x021D98E4  thumb
 *   func_021D9A08                0x021D9A08  thumb
 *   func_021D99F4                0x021D99F4  thumb
 *   func_021DA434                0x021DA434  thumb
 *   func_021E7E0C                0x021E7E0C  thumb  ov177
 *   func_021DA36C                0x021DA36C  thumb
 *   func_0200FB24                0x0200FB24  thumb
 *   GFL_NET_GetRunState                0x0203CD98  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *
 * Quit-confirmation dialog step (state at +0xec): waits for the trigger and the button, prints the question, waits for the message, opens the yes/no window, then on yes prints the goodbye and closes the connection (returns 3 when finished), on no returns 2; returns 1 while the dialog is active and 0 when idle.
 *
 * Closed: the final state test is a switch, which keeps the `return 0` arm as the
 *     fall-through where every if/else spelling inverts it (EXACT* once the
 *     ov177 getter 0x021E8844 got its label).
 */
#include "../include/Obj00594.h"

typedef unsigned long u32;

extern u32 func_020362DC(void);
extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *p);
extern void func_021D98E4(u32 *p, int mode);
extern int func_021D9A08(char *obj);
extern void func_021D99F4(char *obj);
extern int func_021DA434(u32 h);
extern void func_021E7E0C(void **p, int on);
extern void func_021DA36C(u32 h);
extern u32 func_0200FB24(void);
extern int GFL_NET_GetRunState(void);
extern void DWC_CloseAllConnectionsHard(void);

int func_021D9C34(char *obj, int trigger, int go)
{
    int r;

    switch (((struct Obj00594 *)obj)->fEC) {
    case 0:
        if (trigger == 0)
            break;
        if (!(func_020362DC() & 2))
            break;
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 1:
        func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x23, 1);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 2:
        if (!func_021E8844((const int *)(((struct Obj00594 *)obj)->f2C)))
            break;
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 3:
        func_021D98E4((u32 *)obj, 0);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 4:
        r = func_021D9A08(obj);
        if (r == -1)
            break;
        func_021D99F4(obj);
        switch (r) {
        case 0:
            ((struct Obj00594 *)obj)->fEC = 5;
            break;
        case 1:
            func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x21, 0);
            ((struct Obj00594 *)obj)->fEC = 0;
            return 2;
        }
        break;
    case 5:
        func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x2b, 2);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 6:
        if (go == 0)
            break;
        func_021DA434(((struct Obj00594 *)obj)->f34);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        func_021E7E0C((void **)(((struct Obj00594 *)obj)->f28), 0);
        func_021DA36C(((struct Obj00594 *)obj)->f34);
        if (!func_0200FB24() && GFL_NET_GetRunState())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        ((struct Obj00594 *)obj)->fEC = 0;
        return 3;
    }
    switch (((struct Obj00594 *)obj)->fEC) {
    case 0:
        return 0;
    default:
        return 1;
    }
}
