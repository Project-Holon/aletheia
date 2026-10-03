/*
 * function: func_021DC860
 * address: 0x021DC860
 * packet: pkt_ov171_021DC860
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: func_0203159C returns the allocated buffer in r0 despite its legacy void declaration; original 021DC882 copies r0 to r4 and clears/stores through it.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj0203159C;
extern void func_0203064C(void*,u32,u32);
extern void *func_0203159C(struct Obj0203159C*,u32,u32);
extern void func_02082BCC(void*,u32,u32);
int func_021DC860(struct Obj0203159C*p,void*unused,u32 n){u32*q;func_0203064C((void*)1,0x8c,0x60000);q=func_0203159C(p,0xc78,0x8c);func_02082BCC(q,0,0xc78);*q=n;return 1;}
