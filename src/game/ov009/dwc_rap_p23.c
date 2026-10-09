/*
 * file:     dwc_rap_p23.c
 * unit:     yes
 * function: func_0215683C, func_02156860, func_02156874
 * address:  0x0215683C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A1C5C 0x021A1C5C data ov009 a1
 *   func_02034714 0x02034714 arm
 *   func_021688FC 0x021688FC arm ov009
 *   g_021A8264  0x021A8264  data  ov009
 */
#include "../../matched/include/G__anon_Work.h"

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_021688FC(char *, unsigned long);
int func_0215683C(char *a, int b);
int func_02156860(int i);
unsigned char func_02156874(int i);
extern char d_021A1C5C[];
extern int g_021A8264;

int func_0215683C(char *a, int b)
{
    if (b > 32)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    return func_021688FC(a, b);
}


/*
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C23B8 +0004.
 * Coherent Thumb code only in ov009 (ov010 opens with adds r3,r7,#0 and an
 * immediate branch), so the ov009 shard makes that site attest as `matched`.
 */
int func_02156860(int i)
{
    return (int)((char *)(int *)g_021A8264 + 0x34C + (i << 5));
}


/*
 * Byte at +0x32c past the index of the block the module pointer holds.
 */
unsigned char func_02156874(int i)
{
    return *(unsigned char *)(((char *)g_021A8264) + i + 0x32c);
}
