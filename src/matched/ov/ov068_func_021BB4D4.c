/*
 * function: func_021BB4D4
 * address: 0x021BB4D4
 * packet: pkt_ov068_021BB4D4
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA9E0 0x021BA9E0 thumb ov068
 *   func_021BAFA8 0x021BAFA8 thumb ov068
 *   func_020061E4 0x020061E4 thumb
 *   func_021BB138 0x021BB138 thumb ov068
 *   func_021BB188 0x021BB188 thumb ov068
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a,b,c; } Blk;
extern void func_021BA9E0(u8 *p,Blk *out);
extern void func_021BAFA8(u8 *p);
extern void func_020061E4(u32 id);
extern void func_021BB138(void *p,int v);
extern void func_021BB188(void *p,u32 *state);
void func_021BB4D4(void *a,u32 b,u8 *p) { Blk t; func_021BA9E0(p+0x148,&t); func_021BAFA8((u8 *)&t); func_020061E4(0x558); func_021BB138(a,(int)func_021BB188); }
