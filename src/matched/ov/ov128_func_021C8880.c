/*
 * function: func_021C8880
 * address: 0x021C8880
 * packet: pkt_ov128_021C8880
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display control MMIO 0x04000000 read/write at 021C888A and 021C8892.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B92C(struct Obj *,u32);
void func_021C8880(u8 *p) {*(volatile u32 *)0x04000000 &= ~0xe000u;func_0204B3DC(*(struct Obj **)(p+416),0);func_0204B92C(*(struct Obj **)(p+416),0);}
