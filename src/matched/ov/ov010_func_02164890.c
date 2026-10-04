/*
 * function: func_02164890
 * address: 0x02164890
 * packet: pkt_ov010_02164890
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204944C 0x0204944C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
void func_02164890(u8 *p){func_0204944C((struct ArcFile *)*(u32 *)(p+8),1,2,0x110,p+12);}
