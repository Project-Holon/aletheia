/*
 * function: func_021DA698
 * address: 0x021DA698
 * packet: pkt_ov121_021DA698
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DA2A8 0x021DA2A8 thumb ov121
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021DA2A8(u8 *);
extern void func_021DA280(u8 *);
extern void func_020409B4(u8);
extern void func_020307B0(void *);
void func_021DA698(u8 *p) { if(*(u32 **)(p+0x60) && *(u32 *)(p+8)!=3) **(u32 **)(p+0x60)=*(u32 *)(p+8); func_0204B3DC(*(void **)(p+4),0); func_021DA2A8(*(u8 **)p); func_021DA280(*(u8 **)p); func_020409B4(*(u16 *)(p+0x28)); func_020307B0(p); }
