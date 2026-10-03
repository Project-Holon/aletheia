/*
 * function: func_021BB38C
 * address: 0x021BB38C
 * packet: pkt_ov223_021BB38C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027F60 0x02027F60 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct R;extern struct R *func_02027F60(u16,u16,u32,u32,u16);
void func_021BB38C(char *p) {*(struct R **)(p+0x25c)=func_02027F60(3,11,*(u32 *)(p+24),*(u32 *)(p+28),*(u16 *)p);}
