/*
 * file:     unit_02179824_p04.c
 * unit:     yes
 * function: func_02179998, func_021799B4, func_021799C0, func_021799CC
 * address:  0x02179998
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0217AB80 0x0217AB80 data ov015 a1
 *   func_0217A134 0x0217A134 arm ov015
 *   d_0217AAC0 0x0217AAC0 data ov015 a4
 *   d_0217AB40 0x0217AB40 data a4
 *   d_0217AAAC  0x0217AAAC  data  ov015
 *   func_02034714  0x02034714  arm
 */
#include "../../matched/include/G_State.h"

typedef unsigned int   u32;

extern void func_0217A134(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_02179998(void);
void func_021799B4(unsigned v);
void func_021799C0(int a);
void func_021799CC(void);
extern struct State d_0217AB80;
extern unsigned d_0217AAC0;
extern unsigned char d_0217AB40[];
extern unsigned char d_0217AAAC[];

void func_02179998(void)
{
    if (((unsigned char *)&d_0217AB80)[0xC] == 1) func_0217A134();
    ((unsigned char *)&d_0217AB80)[0xC] = 0;
}

/*
 * extent: follower 021799C0 already filed separately.
 */
void func_021799B4(unsigned v) { d_0217AAC0 = v; }

void func_021799C0(int a) { *(int *)(d_0217AB40+0x48)=a; }


void func_021799CC(void)
{
    if (((unsigned char *)&d_0217AB80)[0xc] != 0)
        func_02034714((const char *)d_0217AAAC, 0, (const char *)d_0217AAAC);
    ((unsigned char *)&d_0217AB80)[0xc] = 1;
}
