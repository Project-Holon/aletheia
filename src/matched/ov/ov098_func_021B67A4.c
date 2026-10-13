/*
 * function: PDC_MAIN_StartFadeIn
 * address: 0x021B67A4
 * packet: pkt_ov098_021B67A4
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D55C 0x0207D55C arm
 *   FADE_Start 0x0204E720 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0207D55C(volatile u16 *reg);
extern void FADE_Start(u32,int,int,int);
void PDC_MAIN_StartFadeIn(int a) { if (func_0207D55C((unsigned short *)0x0400006c) <= 0) FADE_Start(3,16,0,a); else FADE_Start(12,16,0,a); }
