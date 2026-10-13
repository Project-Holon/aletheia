/*
 * function: HAND_POS_HealingWishOnSwitchIn
 * address: 0x068987B4
 * packet: pkt_ov095_068987B4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u8 spilled third parameter keeps its reload after the halfword store.
 * audit: permuter only narrowed byte-valued c; no address/index, return or volatile mutation.
 * budget: 4 iterations, first nonshrinker r2, streak 3; extraction/scheduling variants 2/2.
 * checks: 1 veneer targets and matched prototypes; 2 ov095 98328 and ov093 E8190 twins; 3 u8 flag unchanged, const b CCERR (2/2); 4 inline/store/enum idioms; 5 refreshed directory and twins.
 * permuter: once budget 300 types, EXACT at candidate 157; u8 c adopted after behavior audit.
 * symbols:
 *   func_068988A0 0x068988A0 thumb ov095
 *   func_068988B0 0x068988B0 thumb ov095
 *   func_068988C0 0x068988C0 thumb ov095
 *   func_068988D0 0x068988D0 thumb ov095
 *   func_068988E0 0x068988E0 thumb ov095
 *   func_068988F0 0x068988F0 thumb ov095
 *   func_06898900 0x06898900 thumb ov095
 *   func_06898910 0x06898910 thumb ov095
 *   func_06898920 0x06898920 thumb ov095
 *   func_06898930 0x06898930 thumb ov095
 *   func_06898940 0x06898940 thumb ov095
 *   func_06898950 0x06898950 thumb ov095
 *   func_06898960 0x06898960 thumb ov095
 *   func_06898970 0x06898970 thumb ov095
 *   func_06898980 0x06898980 thumb ov095
 *   func_06898990 0x06898990 thumb ov095
 *   func_068989A0 0x068989A0 thumb ov095
 *   func_068989B0 0x068989B0 thumb ov095
 */
#include "../include/Obj03722.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_068988A0(int);
extern int func_068988B0(void *, u32);
extern void *func_068988C0(void *, int);
extern int func_068988D0(void *);
extern int func_068988E0(void *);
extern u8 *func_068988F0(void *, int, int);
extern void func_06898900(void *, int, int);
extern void func_06898910(void *, u32);
extern void func_06898920(void *, void *);
extern int func_06898930(void *);
extern u8 *func_06898940(void *, int, int);
extern int func_06898950(void *, int);
extern int func_06898960(void *, int);
extern void func_06898970(void *, void *);
extern int func_06898980(void *);
extern u8 *func_06898990(void *, int, int);
extern void func_068989A0(void *, void *);
extern void func_068989B0(void *);
void HAND_POS_HealingWishOnSwitchIn(void *a, void *b, u8 c)
{
    u8 slot;
    void *m;
    int flag;
    u8 *p;
    int value;
    slot = (u8)func_068988A0(2);
    if (c == func_068988B0(b, slot)) {
        m = func_068988C0(b, slot);
        flag = 0;
        if (func_068988D0(m) == 0)
            flag = 1;
        if (func_068988E0(m) != 0)
            flag = 1;
        if (flag != 0) {
            p = func_068988F0(b, 0x37, slot);
            ((struct Obj03722 *)p)->f4 = 0x27f;
            p[6] = c;
            p[7] = 6;
            func_06898900(p + 12, 2, 0x2b9);
            func_06898910(p + 12, slot);
            func_06898920(b, p);
            if (func_06898930(m) == 0) {
                p = func_06898940(b, 5, slot);
                p[6] = slot;
                value = func_06898950(m, 14);
                ((struct Obj03722 *)p)->f4 = value - func_06898960(m, 13);
                func_06898970(b, p);
            }
            if (func_06898980(m) != 0) {
                p = func_06898990(b, 11, slot);
                p[20] = 1;
                p[8] = slot;
                *(int *)(p + 4) = 36;
                func_068989A0(b, p);
            }
        }
        func_068989B0(a);
    }
}
