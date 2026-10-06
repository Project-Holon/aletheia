/*
 * function: func_02186804
 * address: 0x02186804
 * packet: pkt_ov020_02186804
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */

extern void func_02049238(void *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_02186804(void **p) { func_02049238(p[0]); func_020307B0(p); }
