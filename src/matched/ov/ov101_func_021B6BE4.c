/*
 * function: func_021B6BE4
 * address: 0x021B6BE4
 * packet: pkt_ov101_021B6BE4
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,u32);
extern void *func_02031324(int);
void func_021B6BE4(u8 *p,int heap) { func_02082BCC(p,0,12); *(void **)p=func_02031324(heap); }
