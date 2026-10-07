/*
 * file:     mb_seq_p07.c
 * unit:     yes
 * function: func_021C7600, func_021C7620, func_021C7648
 * address:  0x021C7600
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C7178 0x021C7178 thumb
 *   func_021C7430 0x021C7430 thumb
 *   func_021C630C 0x021C630C thumb ov136
 *   func_021C71A8 0x021C71A8 thumb ov136
 *   func_02035C08  0x02035C08  arm
 *   d_021C7E2C 0x021C7E2C data a4
 */
#include "../../matched/include/Obj10611.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};

extern void func_021C7430(u8 *, int, u16, u16);
extern int func_021C7178(u8 *, u32);
extern void func_021C630C(u8 *, unsigned int);
extern int func_021C71A8(char *, int, int);
extern int func_02035C08(const void *);
int func_021C7600(u8 *p);
void func_021C7620(u8 *p);
int func_021C7648(u8 *p);
extern const u8 d_021C7E2C[];

int func_021C7600(u8 *p)
{
    func_021C7430(p, 9, ((struct Obj10611 *)p)->f22, 0);
    ((struct Obj10611 *)p)->f14 = 1;
    ((struct Obj10611 *)p)->f28 = 6;
    return func_021C7178(p, 1);
}

static inline unsigned int choose(const struct Bf7 *flag)
{
    return flag->w==0 ? 3 : 4;
}

/*
 * lever: call in each conditional arm keeps p live in r0 and bit test in r1;
 *   inline selector/ternary instead use r0 for test and rebuild p, DIFF17/38.
 * extent: 38 code bytes followed by two zero alignment bytes at021C7646;
 *   next function begins021C7648 outside this inferred40-byte extent.
 */
void func_021C7620(u8 *p)
{
    if(((const struct Bf7 *)(p+0x21))->w==0)
        func_021C630C(p,3);
    else
        func_021C630C(p,4);
    func_021C71A8((char *)p, 1, 0x1A);
}

int func_021C7648(u8 *p)
{
    return func_02035C08(d_021C7E2C);
}
