/*
 * function: func_021B8104
 * address: 0x021B8104
 * packet: pkt_ov104_021B8104
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void func_020061E4(u32 a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021B8104(u32 *p) { if(p[5]) { if(p[3]==0) { func_020061E4(0x66a); func_0204B3DC((void *)p[0],1); func_0204B878((void *)p[0],4-p[4]); } if(p[3]++>=60) { p[3]=0; p[4]++; } if(p[4]==3) { func_020061E4(0x66b); p[6]=1; p[5]=0; func_0204B3DC((void *)p[0],0); } } }
