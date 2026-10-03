/*
 * function: func_021B85F4
 * address: 0x021B85F4
 * packet: pkt_ov102_021B85F4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_02051C6C(void *);
extern void func_02082BCC(void *, int, u32);
void func_021B85F4(u8 *p) { int i; for(i=0;i<*(u16 *)(p+44);i++)func_020452E8(*(void **)(p+4+i*4)); func_02051C6C(*(void **)p); func_02082BCC(p,0,60); }
