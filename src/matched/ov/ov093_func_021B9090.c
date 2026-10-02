/*
 * function: func_021B9090
 * address: 0x021B9090
 * packet: pkt_ov093_021B9090
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007F1C 0x02007F1C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02007F1C(void *,u32,int,u16);
void func_021B9090(u8 *p,u8 k,u32 x) { u8 *q; q=*(u8 **)p; if(q[0x23]==0 && k==p[0x46c]) func_02007F1C(*(void **)(q+0x60),x,1,*(u16 *)(p+0x468)); }
