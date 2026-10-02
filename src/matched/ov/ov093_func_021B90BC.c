/*
 * function: func_021B90BC
 * address: 0x021B90BC
 * packet: pkt_ov093_021B90BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007E50 0x02007E50 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02007E50(void *,u32,int,u16);
void func_021B90BC(u8 *p,u8 k,u32 x) { u8 *q; q=*(u8 **)p; if(q[0x23]==0 && k==p[0x46c]) func_02007E50(*(void **)(q+0x60),x,1,*(u16 *)(p+0x468)); }
