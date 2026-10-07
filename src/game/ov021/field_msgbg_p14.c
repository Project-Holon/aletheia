/*
 * file:     field_msgbg_p14.c
 * unit:     yes
 * function: func_0218BCF4, func_0218BD20
 * address:  0x0218BCF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020113D8  0x020113D8  thumb
 *   d_021D3D50     0x021D3D50  data  a4
 */
#include "../../matched/include/Obj17894.h"

typedef struct {
    int cur;
    int prev;
    int changed;
    unsigned char val;
    unsigned char id;
} S;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

u32 func_020113D8(u32 row);
void func_0218BCF4(S *p);
u32 func_0218BD20(u8 *p);
extern unsigned char d_021D3D50[];


void func_0218BCF4(S *p)
{
    p->prev = p->cur;
    p->cur = func_020113D8(p->id);
    p->changed = p->cur != p->prev;
    p->val = d_021D3D50[p->cur];
}


/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_0218BD20(u8 *p)
{
    return ((struct Obj17894 *)p)->f8;
}
