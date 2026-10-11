/*
 * file:     unit_068987A8.c
 * unit:     yes
 * function: func_068987A8, func_068987B4
 * address:  0x068987A8
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
 *   func_021D59B4  0x021D59B4  thumb
 *   func_021D5B48  0x021D5B48  thumb
 *   func_021D62A8  0x021D62A8  thumb
 *   func_021D7040  0x021D7040  thumb
 *   func_021D775C  0x021D775C  thumb
 *   d_0689D6A8 0x0689D6A8 data a4
 */
#include "../../matched/include/Obj03722.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern int func_021C8010(void *, u32);
extern void *func_021C7CF4(void *, int);
extern int func_021D5B48(void *);
extern int func_021D62A8(void *);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern void func_021C88C8(void *, void *);
extern int func_021D59B4(void *, int);
extern void func_021D7040(void *);
void *func_068987A8(unsigned int *state);
void func_068987B4(void *a, void *b, u8 c);
extern unsigned char d_0689D6A8[];

/*
 * extent: 12-byte store-and-return follower after non-C veneer 06898798.
 */
void *func_068987A8(unsigned int *state)
{
    *state = 2;
    return d_0689D6A8;
}

/*
 * lever: u8 spilled third parameter keeps its reload after the halfword store.
 * audit: permuter only narrowed byte-valued c; no address/index, return or volatile mutation.
 * budget: 4 iterations, first nonshrinker r2, streak 3; extraction/scheduling variants 2/2.
 * checks: 1 veneer targets and matched prototypes; 2 ov095 98328 and ov093 E8190 twins; 3 u8 flag unchanged, const b CCERR (2/2); 4 inline/store/enum idioms; 5 refreshed directory and twins.
 * permuter: once budget 300 types, EXACT at candidate 157; u8 c adopted after behavior audit.
 */
void func_068987B4(void *a, void *b, u8 c)
{
    u8 slot;
    void *m;
    int flag;
    u8 *p;
    int value;
    slot = (u8)func_021D775C(2);
    if (c == func_021C8010(b, slot)) {
        m = func_021C7CF4(b, slot);
        flag = 0;
        if (func_021D5B48(m) == 0)
            flag = 1;
        if (func_021D62A8(m) != 0)
            flag = 1;
        if (flag != 0) {
            p = func_021C88A4(b, 0x37, slot);
            ((struct Obj03722 *)p)->f4 = 0x27f;
            p[6] = c;
            p[7] = 6;
            func_021C8838(p + 12, 2, 0x2b9);
            func_021C8860(p + 12, slot);
            func_021C88C8(b, p);
            if (func_021D5B48(m) == 0) {
                p = func_021C88A4(b, 5, slot);
                p[6] = slot;
                value = func_021D59B4(m, 14);
                ((struct Obj03722 *)p)->f4 = value - func_021D59B4(m, 13);
                func_021C88C8(b, p);
            }
            if (func_021D62A8(m) != 0) {
                p = func_021C88A4(b, 11, slot);
                p[20] = 1;
                p[8] = slot;
                *(int *)(p + 4) = 36;
                func_021C88C8(b, p);
            }
        }
        func_021D7040(a);
    }
}
