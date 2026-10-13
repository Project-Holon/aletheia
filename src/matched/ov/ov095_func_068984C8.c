/*
 * function: HAND_POS_LunarDanceOnSwitchIn
 * address: 0x068984C8
 * packet: pkt_ov095_068984C8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: distinct u32 counters for the two loops restore the r4/r5 allocation; u8 c follows the verified 068987B4 twin.
 * trailing: 06898626 c0 46 is a two-byte alignment NOP after pop pc; next veneer starts at 06898628, outside this extent.
 * audit: counters are initialized independently before use; count accessor 021D5448 returns a byte, so no narrowed address or index.
 * budget: 4 iterations, first nonshrinker r2, streak 3; manual order/identity variants 2/2 including C4.
 * checks: 1 all 24 veneer calls resolved and target arities witnessed; 2 068987B4/06898328/021DD39C twins; 3 u16 slot worsens, signed i unchanged (2/2); 4 distinct phase counters EXACT* (1/2); 5 refreshed directory and twins, no stack aggregate residue.
 * permuter: not needed, C4 reached EXACT* before any DIFF was parked.
 * symbols:
 *   func_06898628 0x06898628 thumb ov095
 *   func_06898638 0x06898638 thumb ov095
 *   func_06898648 0x06898648 thumb ov095
 *   func_06898658 0x06898658 thumb ov095
 *   func_06898668 0x06898668 thumb ov095
 *   func_06898678 0x06898678 thumb ov095
 *   func_06898688 0x06898688 thumb ov095
 *   func_06898698 0x06898698 thumb ov095
 *   func_068986A8 0x068986A8 thumb ov095
 *   func_068986B8 0x068986B8 thumb ov095
 *   func_068986C8 0x068986C8 thumb ov095
 *   func_068986D8 0x068986D8 thumb ov095
 *   func_068986E8 0x068986E8 thumb ov095
 *   func_068986F8 0x068986F8 thumb ov095
 *   func_06898708 0x06898708 thumb ov095
 *   func_06898718 0x06898718 thumb ov095
 *   func_06898728 0x06898728 thumb ov095
 *   func_06898738 0x06898738 thumb ov095
 *   func_06898748 0x06898748 thumb ov095
 *   func_06898758 0x06898758 thumb ov095
 *   func_06898768 0x06898768 thumb ov095
 *   func_06898778 0x06898778 thumb ov095
 *   func_06898788 0x06898788 thumb ov095
 *   func_06898798 0x06898798 thumb ov095
 */
#include "../include/Obj02149.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_06898628(int);
extern int func_06898638(void *, u32);
extern void *func_06898648(void *, int);
extern int func_06898658(void *);
extern int func_06898668(void *);
extern u32 func_06898678(void *);
extern u8 func_06898688(void *, u8);
extern u8 *func_06898698(void *, int, int);
extern void func_068986A8(void *, int, int);
extern void func_068986B8(void *, u32);
extern void func_068986C8(void *, void *);
extern int func_068986D8(void *);
extern u8 *func_068986E8(void *, int, int);
extern int func_068986F8(void *, int);
extern int func_06898708(void *, int);
extern void func_06898718(void *, void *);
extern int func_06898728(void *);
extern u8 *func_06898738(void *, int, int);
extern void func_06898748(void *, void *);
extern u32 func_06898758(void *);
extern u8 func_06898768(void *, u8);
extern u8 *func_06898778(void *, int, int);
extern void func_06898788(void *, void *);
extern void func_06898798(void *);
void HAND_POS_LunarDanceOnSwitchIn(void *a, void *b, u8 c)
{
    u32 i;
    u32 j;
    u8 slot;
    void *m;
    int flag;
    u8 *p;
    u32 n;
    int value;
    u32 n2;
    u8 v;
    slot = (u8)func_06898628(2);
    if (c == func_06898638(b, slot)) {
        m = func_06898648(b, slot);
        flag = 0;
        if (func_06898658(m) == 0)
            flag = 1;
        if (func_06898668(m) != 0)
            flag = 1;
        n = func_06898678(m);
        for (i = 0; i < n; i++) {
            if (func_06898688(m, i) != 0)
                flag = 1;
        }
        if (flag != 0) {
            p = func_06898698(b, 0x37, slot);
            ((struct Obj02149 *)p)->f4 = 0x280;
            p[6] = c;
            p[7] = 6;
            p[11] = 1;
            func_068986A8(p + 12, 2, 0x2b6);
            func_068986B8(p + 12, slot);
            func_068986C8(b, p);
            if (func_068986D8(m) == 0) {
                p = func_068986E8(b, 5, slot);
                p[6] = slot;
                value = func_068986F8(m, 14);
                ((struct Obj02149 *)p)->f4 = value - func_06898708(m, 13);
                func_06898718(b, p);
            }
            if (func_06898728(m) != 0) {
                p = func_06898738(b, 11, slot);
                p[20] = 1;
                p[8] = slot;
                *(int *)(p + 4) = 36;
                func_06898748(b, p);
            }
            n2 = func_06898758(m);
            for (j = 0; j < n2; j++) {
                v = func_06898768(m, j);
                if (v != 0) {
                    p = func_06898778(b, 9, slot);
                    p[5] = slot;
                    p[4] = v;
                    p[6] = j;
                    func_06898788(b, p);
                }
            }
        }
        func_06898798(a);
    }
}
