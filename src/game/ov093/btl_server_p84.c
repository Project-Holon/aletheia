/*
 * file:     btl_server_p84.c
 * unit:     yes
 * function: func_021C7CD4, func_021C7CDC, func_021C7CE8
 * address:  0x021C7CD4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj18322.h"
#include "../../matched/include/Obj18323.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021C7CD4  movs r1,#0x7e; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q6 { u8 pad[0x1f80]; u16 v; };

u16 func_021C7CD4(struct Q6 *p);
u16 func_021C7CDC(u8 *p);
u16 func_021C7CE8(u8 *p);

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x7e; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */
u16 func_021C7CD4(struct Q6 *p) { return p->v; }


/*
 * ldrh at #0x1f82 (pool constant)
 */
u16 func_021C7CDC(u8 *p)
{
    return ((struct Obj18322 *)p)->f1F82;
}


u16 func_021C7CE8(u8 *p)
{
    return ((struct Obj18323 *)p)->f1F86;
}
