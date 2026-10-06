/*
 * function: func_021BB5B4
 * address: 0x021BB5B4
 * packet: pkt_ov072_021BB5B4
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BB49C 0x021BB49C thumb ov072
 */
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021BB49C(void **p);
void func_021BB5B4(u32 *p,u32 v) { func_0204B3DC((void *)p[4],v); if(v==0) { p[7]=0; p[6]=0; func_021BB49C((void **)p); } }
