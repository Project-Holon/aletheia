/*
 * function: func_0217E2C0
 * address: 0x0217E2C0
 * packet: pkt_ov176_0217E2C0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_0217E2C0(int unused,int a) {int flag;int v;v=func_0203D1A4((struct Link *)((int)func_020399A8()));flag=1;if(v!=0)flag=0;return func_0203D3F8((int)func_020399A8(),(u8)flag,0x1f03,4,(int)a,(int)1,(int)1,(int)1);}
