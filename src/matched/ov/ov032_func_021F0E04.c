/*
 * function: func_021F0E04
 * address: 0x021F0E04
 * packet: pkt_ov032_021F0E04
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021F0E04(char *p, unsigned a) { int i; for(i=0;i<=3;i++) func_0204B3DC(*(void **)(p+i*4+0x2bc),a); }
