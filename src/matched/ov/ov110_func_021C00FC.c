/*
 * function: func_021C00FC
 * address: 0x021C00FC
 * packet: pkt_ov110_021C00FC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
int func_021C00FC(u8 *p) { if(func_0204B898(*(void **)(p+0x14))!=28) return 1; if(!func_0204B98C(*(void **)(p+0x14))) { func_0204B3DC(*(void **)(p+0x14),*(u32 *)(p+0x18)); func_0204B878(*(void **)(p+0x14),8); *(u32 *)(p+0x18)=0; return 1; } return 0; }
