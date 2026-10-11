/*
 * file:     unit_068984BC.c
 * unit:     yes
 * function: func_068984BC, func_068984C8
 * address:  0x068984BC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb
 *   func_021C8010  0x021C8010  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D5448  0x021D5448  thumb
 *   func_021D554C  0x021D554C  thumb
 *   func_021D59B4  0x021D59B4  thumb
 *   func_021D5B48  0x021D5B48  thumb
 *   func_021D62A8  0x021D62A8  thumb
 *   func_021D7040  0x021D7040  thumb
 *   func_021D775C  0x021D775C  thumb
 *   d_0689D6B8 0x0689D6B8 data ov095 a4
 */
#include "../../matched/include/Obj02149.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int func_021D775C(int);
extern int func_021C8010(void *, u32);
extern void *func_021C7CF4(void *, int);
extern int func_021D5B48(void *);
extern int func_021D62A8(void *);
extern u32 func_021D5448(void *);
extern u8 func_021D554C(void *, u8);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern void func_021C88C8(void *, void *);
extern int func_021D59B4(void *, int);
extern void func_021D7040(void *);
u32 *func_068984BC(u32 *p);
void func_068984C8(void *a, void *b, u8 c);
extern u32 d_0689D6B8[];

/*
 * extent: 12-byte unlabelled store-and-return follower after non-C veneer 068984AC; next function 068984C8 is already matched.
 */
u32 *func_068984BC(u32 *p) { *p=2; return d_0689D6B8; }

/*
 * lever: distinct u32 counters for the two loops restore the r4/r5 allocation; u8 c follows the verified 068987B4 twin.
 * trailing: 06898626 c0 46 is a two-byte alignment NOP after pop pc; next veneer starts at 06898628, outside this extent.
 * audit: counters are initialized independently before use; count accessor 021D5448 returns a byte, so no narrowed address or index.
 * budget: 4 iterations, first nonshrinker r2, streak 3; manual order/identity variants 2/2 including C4.
 * checks: 1 all 24 veneer calls resolved and target arities witnessed; 2 068987B4/06898328/021DD39C twins; 3 u16 slot worsens, signed i unchanged (2/2); 4 distinct phase counters EXACT* (1/2); 5 refreshed directory and twins, no stack aggregate residue.
 * permuter: not needed, C4 reached EXACT* before any DIFF was parked.
 */
void func_068984C8(void *a, void *b, u8 c)
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
    slot = (u8)func_021D775C(2);
    if (c == func_021C8010(b, slot)) {
        m = func_021C7CF4(b, slot);
        flag = 0;
        if (func_021D5B48(m) == 0)
            flag = 1;
        if (func_021D62A8(m) != 0)
            flag = 1;
        n = func_021D5448(m);
        for (i = 0; i < n; i++) {
            if (func_021D554C(m, i) != 0)
                flag = 1;
        }
        if (flag != 0) {
            p = func_021C88A4(b, 0x37, slot);
            ((struct Obj02149 *)p)->f4 = 0x280;
            p[6] = c;
            p[7] = 6;
            p[11] = 1;
            func_021C8838(p + 12, 2, 0x2b6);
            func_021C8860(p + 12, slot);
            func_021C88C8(b, p);
            if (func_021D5B48(m) == 0) {
                p = func_021C88A4(b, 5, slot);
                p[6] = slot;
                value = func_021D59B4(m, 14);
                ((struct Obj02149 *)p)->f4 = value - func_021D59B4(m, 13);
                func_021C88C8(b, p);
            }
            if (func_021D62A8(m) != 0) {
                p = func_021C88A4(b, 11, slot);
                p[20] = 1;
                p[8] = slot;
                *(int *)(p + 4) = 36;
                func_021C88C8(b, p);
            }
            n2 = func_021D5448(m);
            for (j = 0; j < n2; j++) {
                v = func_021D554C(m, j);
                if (v != 0) {
                    p = func_021C88A4(b, 9, slot);
                    p[5] = slot;
                    p[4] = v;
                    p[6] = j;
                    func_021C88C8(b, p);
                }
            }
        }
        func_021D7040(a);
    }
}
