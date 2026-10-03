/*
 * function: func_021B7D9C
 * address: 0x021B7D9C
 * packet: pkt_ov070_021B7D9C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB1C4 0x021BB1C4 thumb ov070
 *   func_021BB260 0x021BB260 thumb ov070
 *   func_0204B3DC 0x0204B3DC arm
 */

typedef unsigned char u8;
extern void func_021BB1C4(void *p);
extern void func_021BB260(u8 *p, int val);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021B7D9C(u8 *p, int v) { *(int *)(p+0x7EC)=v; func_021BB1C4(p); func_021BB260(p,*(int *)(p+0x7F4)); func_0204B3DC(*(void **)(p+0x724),1); func_0204B3DC(*(void **)(p+0x728),1); }
