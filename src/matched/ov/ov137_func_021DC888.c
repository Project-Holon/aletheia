/*
 * function: func_021DC888
 * address: 0x021DC888
 * packet: pkt_ov137_021DC888
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02031330 0x02031330 arm
 *   d_021E1A50 0x021E1A50 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02031330(void *);
extern int (* const d_021E1A50[])(u8 *);
int func_021DC888(void *obj,int a,int b,u8 *p) { switch(func_02031330(*(void **)(p+32))) { case 0: if(d_021E1A50[*(u32 *)p](p)==1) return 1; break; case 1: break; case 2: break; } return 0; }
