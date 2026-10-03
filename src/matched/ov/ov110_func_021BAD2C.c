/*
 * function: func_021BAD2C
 * address: 0x021BAD2C
 * packet: pkt_ov110_021BAD2C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020499D4 0x020499D4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
void func_021BAD2C(u8 *p,int v) { int id,x; if(v) { id=29; x=96; } else { id=28; x=0; } func_020499D4(*(void **)(p+0x8c),id,3,0,x,0,0,42); *(int *)(p+0x84)=1; *(int *)(p+0x88)=v; }
