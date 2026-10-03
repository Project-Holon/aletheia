/*
 * function: func_021BA1C4
 * address: 0x021BA1C4
 * packet: pkt_ov099_021BA1C4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4918 0x021C4918 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x,y; u16 a,b,c,d; } Params;
extern void *func_021C4918(void *,Params *);
void func_021BA1C4(u8 *p,void **out,short *xy,int a,u16 d,u8 c,int b) { Params q; q.x=xy[0]; q.y=xy[1]; q.a=a; q.b=b; q.c=c; q.d=d; *out=func_021C4918(*(void **)(p+0x58c),&q); }
