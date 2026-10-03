/*
 * function: func_02200A7C
 * address: 0x02200A7C
 * packet: pkt_ov135_02200A7C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_022028C8 0x022028C8 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_022028C8(void *,u8,void *,u32,u32,u32,u16,void *);
void func_02200A7C(void *p,void *bank,u32 b,u32 id,u32 fifth,void *out,u16 se) { void *s=func_02045EC0(bank,id); func_022028C8(p,b,s,0,0,0,se,out); func_02045808(s); }
