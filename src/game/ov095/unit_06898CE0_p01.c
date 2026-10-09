/*
 * file:     unit_06898CE0_p01.c
 * unit:     yes
 * function: func_06898CE0, func_06898CF4, func_06898D10
 * address:  0x06898CE0
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
 *   d_0689E7EC 0x0689E7EC data a4
 *   g_0689E7E0     0x0689E7E0  data
 *   func_06898D44 0x06898D44 thumb ov095
 */
#include "../../matched/include/G_Row.h"
#include "../../matched/include/G_Row.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Node Node;

extern void func_06898D44(Node *n);
u32 func_06898CE0(u32 a, u32 b);
int func_06898CF4(int a, int b);
int func_06898D10(u32 a, u32 b);
extern const u32 d_0689E7EC[];
extern struct Row g_0689E7E0;


/*
 * note: Unlabelled follower of veneer 0x06898CD0, ending with alignment padding.
 */
u32 func_06898CE0(u32 a, u32 b)
{
    return *(const u32 *)((u32)d_0689E7EC + a * 224 + b * 16);
}



/*
 * Indexed presence test: element (a,b) of a 0xe0-stride record array with a
 * 16-byte element stride starting at g_0689E7E0.  Returns 1 when the word is
 * non-zero, 0 otherwise.
 */
int func_06898CF4(int a, int b)
{
    return *(u32 *)(((u8 *)&g_0689E7E0) + a * 0xe0 + b * 16) != 0;
}

int func_06898D10(u32 a, u32 b)
{
    u32 *p;
    p = (u32 *)((u32)((u8 *)&g_0689E7E0) + a * 224 + b * 16);
    if (p[0] != 0) {
        func_06898D44((Node *)p[0]);
        p[0] = 0;
        p[3] = 0;
        p[1] &= ~7;
        return 1;
    }
    return 0;
}
