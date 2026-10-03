/*
 * function: func_021D9488
 * address: 0x021D9488
 * packet: pkt_ov121_021D9488
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DA978 0x021DA978 thumb ov121
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DA958 0x021DA958 thumb ov121
 *   func_02025588 0x02025588 thumb
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_021DA978(void *),func_021DA958(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void *func_021D6C58(u8 *p, int i);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02025588(void *);
extern void func_02082BCC(void *,int,int);
void func_021D9488(void **p) {
 func_021DA978(p[1]);func_0204B3DC(func_021D6C58(p[2],34),0);func_021DA958(p[1]);func_02025588(p[0]);func_02082BCC(p,0,12);
}
