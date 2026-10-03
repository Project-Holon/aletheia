/*
 * function: func_021DD8D0
 * address: 0x021DD8D0
 * packet: pkt_ov170_021DD8D0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AF80 0x0201AF80 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA38 0x0200CA38 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern void *func_0200CA1C(void *);
extern u32 func_0200CA38(struct Blk37 *);
void func_021DD8D0(char *p) { *(u16 **)(*(char **)(p+0x2c)+0x180)=func_0201AF80(76,0);*(u32 *)(*(char **)(p+0x2c)+0x17c)=func_0200CA38(func_0200CA1C(**(void ***)p)); }
