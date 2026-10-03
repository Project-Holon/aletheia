/*
 * function: func_021DD380
 * address: 0x021DD380
 * packet: pkt_ov137_021DD380
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DE6DC 0x021DE6DC thumb ov137
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern void func_021DE6DC(u8 *);
extern void func_020307B0(void *);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
void func_021DD380(u8 *p) {int i;func_021DE6DC(p);func_020307B0(*(void **)(p+36));for(i=0;i<5;i++)func_02045808(*(void **)((u32)p+i*4+68));func_02045808(*(void **)(p+96));func_02045808(*(void **)(p+92));}
