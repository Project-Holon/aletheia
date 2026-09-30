/*
 * function: func_021DEBD4
 * address: 0x021DEBD4
 * packet: pkt_ov119_021DEBD4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware WININ 0x04001048, WINOUT 0x0400104A and DISPCNT 0x04001000 read-modify-written at 0x021DEBE8/0x021DEBF8, 0x021DEC0C/0x021DEC18, 0x021DEC1A/0x021DEC22.
 * symbols:
 *   func_0207D658 0x0207D658 arm
 *   func_02040588 0x02040588 arm
 */
typedef unsigned short u16;
typedef unsigned u32;
extern void func_0207D658(u32,int,int);
extern void func_02040588(int,int);
static inline void inside(int wnd,int effect) {u32 tmp=(*(volatile u16 *)0x04001048 & ~0x3f)|wnd;if(effect)tmp|=0x20;*(volatile u16 *)0x04001048=(u16)tmp;}
static inline void outside(int wnd,int effect) {u32 tmp=(*(volatile u16 *)0x0400104a & ~0x3f)|wnd;if(effect)tmp|=0x20;*(volatile u16 *)0x0400104a=(u16)tmp;}
void func_021DEBD4(void *p) {
 func_0207D658(0x04001050,27,-8);
 inside(31,1);
 *(volatile u16 *)0x04001040=0x80ff;
 *(volatile u16 *)0x04001044=0xa9;
 outside(31,0);
 *(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000 & ~0xe000)|0x2000;
 func_02040588(3,1);func_02040588(5,1);func_02040588(4,1);
}
