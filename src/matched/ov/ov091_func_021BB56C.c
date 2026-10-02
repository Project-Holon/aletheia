/*
 * function: func_021BB56C
 * address: 0x021BB56C
 * packet: pkt_ov091_021BB56C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B0C8 0x0204B0C8 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y; } Pair;
extern void func_0204B0C8(u32,int,Pair *);
void func_021BB56C(u32 p,int x,int y,u16 *out) { Pair pos; func_0204B0C8(*(u32 *)(p+36),0,&pos); out[0]=x-pos.x; out[1]=y-pos.y; }
