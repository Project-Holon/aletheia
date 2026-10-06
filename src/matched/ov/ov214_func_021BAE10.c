/*
 * unit: no
 * function: func_021BAE10
 * address: 0x021BAE10
 * packet: pkt_ov214_021BAE10
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware registers 0x04001050 (021BAE30), 0x04001000 read/write (021BAE34/021BAE3A).
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   d_021BB498 0x021BB498 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern const u8 d_021BB498[];extern void func_020403F4(u8);
static inline void GXS_SetVisibleWnd(int window){*(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000&~0xe000u)|(window<<13);}
void func_021BAE10(int unused, char *p){int i;for(i=0;i<1u;i++)func_020403F4(*(u32 *)(d_021BB498+i*44));*(volatile u16 *)0x04001050=0;GXS_SetVisibleWnd(0);}
