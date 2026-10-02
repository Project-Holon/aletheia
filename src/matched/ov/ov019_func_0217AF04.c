/*
 * function: func_0217AF04
 * address: 0x0217AF04
 * packet: pkt_ov019_0217AF04
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217AED4 0x0217AED4 thumb ov019
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 *p; u8 f4,f5,f6,f7; u8 pad[4]; } Ent;
extern u16 func_0217AED4(u8 *, u8 *);
int func_0217AF04(u8 *a, u16 key) { int i; Ent *p; p = (Ent *)(a+0x2e88); for(i=0;i<50;i++,p++) { if(p->f7 == 1 && p->p != 0 && key == func_0217AED4(p->p,(u8 *)p)) return p->f5; } return 0; }
