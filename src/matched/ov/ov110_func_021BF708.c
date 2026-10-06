/*
 * function: func_021BF708
 * address:  0x021BF708
 * packet:   pkt_ov110_021BF708
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Struct_0202441C;
extern void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId);
void *func_021BF708(u8 *p, u32 heapId) { return func_0202441C((const struct Struct_0202441C *)(p + 8), heapId); }
