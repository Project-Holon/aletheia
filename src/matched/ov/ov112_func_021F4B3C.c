/*
 * function: func_021F4B3C
 * address: 0x021F4B3C
 * packet: pkt_ov112_021F4B3C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4AA8 0x021F4AA8 thumb ov112
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u16 func_021F4AA8(int);
extern void *G3D_SYSTEM_CreateResourceArc(u32,u32);
void *func_021F4B3C(int type) { return G3D_SYSTEM_CreateResourceArc(45,func_021F4AA8(type)); }
