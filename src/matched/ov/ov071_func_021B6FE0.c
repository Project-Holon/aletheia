/*
 * function: func_021B6FE0
 * address: 0x021B6FE0
 * packet: pkt_ov071_021B6FE0
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B8A0 0x0204B8A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef enum { V4 = 4, V5 = 5 } Value;
extern void func_0204B3DC(void *,int);
extern void func_0204B8A0(void *,u16);
void func_021B6FE0(void *p, u8 *q, int i) { Value v; if((q+i)[6]==1) v=V5; else if((q+i)[6]==2) v=V4; else {func_0204B3DC(p,0);return;} func_0204B3DC(p,1);func_0204B8A0(p,v); }
