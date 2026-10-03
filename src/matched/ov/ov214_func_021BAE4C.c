/*
 * unit: no
 * function: func_021BAE4C
 * address: 0x021BAE4C
 * packet: pkt_ov214_021BAE4C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB2A8 0x021BB2A8 thumb ov214
 *   func_021BAB0C 0x021BAB0C thumb ov214
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern u32 func_021BB2A8(u8 *);extern int func_021BAB0C(int,u16,int,u8,u32,u32,u32,u32,void *,u8,u8,u8,u8,u8);
void func_021BAE4C(int unused,u8 *p){*(int *)(p+0x2d4)=func_021BAB0C(func_021BB2A8(*(u8 **)(p+4)),*(u16 *)p,0,0,1,0,0,0,p+0x2c4,0,0,0,1,1);}
