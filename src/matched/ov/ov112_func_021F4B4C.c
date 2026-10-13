/*
 * function: func_021F4B4C
 * address:  0x021F4B4C
 * packet:   pkt_ov112_021F4B4C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Tagged;
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
void func_021F4B4C(struct Tagged *a0) { G3D_SYSTEM_DeleteResource(a0); }
