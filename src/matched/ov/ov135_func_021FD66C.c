/*
 * function: func_021FD66C
 * address: 0x021FD66C
 * packet: pkt_ov135_021FD66C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */
struct Obj;
extern unsigned func_020221A4(void);
extern void func_0204B3DC(struct Obj *,unsigned);
int func_021FD66C(char *p) { (*(unsigned *)(p+0xd3c))++; if(func_020221A4()) {*(unsigned *)(p+0xd3c)=0; *(unsigned *)(p+40)=1; func_0204B3DC(*(struct Obj **)(p+0xd34),1);} return 2; }
