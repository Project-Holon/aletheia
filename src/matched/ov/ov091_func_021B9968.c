/*
 * function: func_021B9968
 * address: 0x021B9968
 * packet: pkt_ov091_021B9968
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */
extern void func_020061E4(unsigned);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_021B9968(unsigned char *p) { p[12]=5; p[14]=3; p[260]=0; func_020061E4(0x641); func_0204B3DC((struct Obj *)*(int *)(p+472),0); func_0204B3DC((struct Obj *)*(int *)(p+476),0); }
