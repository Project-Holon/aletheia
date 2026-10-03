/*
 * function: func_021B9184
 * address: 0x021B9184
 * packet: pkt_ov103_021B9184
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_02082BCC(void *,int,int);
extern void func_0204B6F4(struct Obj *,u8,u32);
void func_021B9184(u8 *p,struct Obj *q,u32 v,u32 w) { func_02082BCC(p,0,0x2c); *(struct Obj **)p=q; *(u32 *)(p+4)=w; func_0204B6F4(q,v,1); }
