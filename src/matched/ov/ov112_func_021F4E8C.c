/*
 * function: func_021F4E8C
 * address: 0x021F4E8C
 * packet: pkt_ov112_021F4E8C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry;
void func_021F4E8C(u32 unused,Entry *p,const int *q) { p->x=q[0]; p->y=q[1]; p->z=q[2]; p->flags |=2; }
