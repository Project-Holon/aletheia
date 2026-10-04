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
 *   func_0203CD98                0x0203CD98  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *
 * Quit-confirmation dialog step (state at +0xec): waits for the trigger and the button, prints the question, waits for the message, opens the yes/no window, then on yes prints the goodbye and closes the connection (returns 3 when finished), on no returns 2; returns 1 while the dialog is active and 0 when idle.
 *
 * Closed: the final state test is a switch, which keeps the `return 0` arm as the
 *     fall-through where every if/else spelling inverts it (EXACT* once the
 *     ov177 getter 0x021E8844 got its label).
 */

typedef unsigned long u32;

extern u32 func_020362DC(void);
extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *p);
extern void func_021D98E4(char *obj, u32 kind);
extern int func_021D9A08(char *obj);
extern void func_021D99F4(char *obj);
extern int func_021DA434(u32 h);
extern void func_021E7E0C(void **p, int on);
extern void func_021DA36C(u32 h);
extern u32 func_0200FB24(void);
extern int func_0203CD98(void);
extern void DWC_CloseAllConnectionsHard(void);

int func_021D9C34(char *obj, int trigger, int go)
{
    int r;

    switch (*(u32 *)(obj + 0xec)) {
    case 0:
        if (trigger == 0)
            break;
        if (!(func_020362DC() & 2))
            break;
        *(u32 *)(obj + 0xec) = *(u32 *)(obj + 0xec) + 1;
        break;
    case 1:
        func_021E8738((int *)(*(u32 *)(obj + 0x2c)), *(u32 *)(obj + 0x14), 0x23, 1);
        *(u32 *)(obj + 0xec) = *(u32 *)(obj + 0xec) + 1;
        break;
    case 2:
        if (!func_021E8844((const int *)(*(u32 *)(obj + 0x2c))))
            break;
        *(u32 *)(obj + 0xec) = *(u32 *)(obj + 0xec) + 1;
        break;
    case 3:
        func_021D98E4(obj, 0);
        *(u32 *)(obj + 0xec) = *(u32 *)(obj + 0xec) + 1;
        break;
    case 4:
        r = func_021D9A08(obj);
        if (r == -1)
            break;
        func_021D99F4(obj);
        switch (r) {
        case 0:
            *(u32 *)(obj + 0xec) = 5;
            break;
        case 1:
            func_021E8738((int *)(*(u32 *)(obj + 0x2c)), *(u32 *)(obj + 0x14), 0x21, 0);
            *(u32 *)(obj + 0xec) = 0;
            return 2;
        }
        break;
    case 5:
        func_021E8738((int *)(*(u32 *)(obj + 0x2c)), *(u32 *)(obj + 0x14), 0x2b, 2);
        *(u32 *)(obj + 0xec) = *(u32 *)(obj + 0xec) + 1;
        break;
    case 6:
        if (go == 0)
            break;
        func_021DA434(*(u32 *)(obj + 0x34));
        *(u32 *)(obj + 0xec) = *(u32 *)(obj + 0xec) + 1;
        func_021E7E0C((void **)(*(u32 *)(obj + 0x28)), 0);
        func_021DA36C(*(u32 *)(obj + 0x34));
        if (!func_0200FB24() && func_0203CD98())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        *(u32 *)(obj + 0xec) = 0;
        return 3;
    }
    switch (*(u32 *)(obj + 0xec)) {
    case 0:
        return 0;
    default:
        return 1;
    }
}
