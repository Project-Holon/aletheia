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
extern void func_020499D4(void *,int,int,int,int,int,int,u16);
void func_021BAD2C(u8 *p,int v) { int id,x; if(v) { id=29; x=96; } else { id=28; x=0; } func_020499D4(*(void **)(p+0x8c),id,3,0,x,0,0,42); *(int *)(p+0x84)=1; *(int *)(p+0x88)=v; }
