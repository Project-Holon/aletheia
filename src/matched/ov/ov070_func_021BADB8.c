/*
 * function: func_021BADB8
 * address: 0x021BADB8
 * packet: pkt_ov070_021BADB8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021B61F4 0x021B61F4 thumb ov070
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B61F4(void *, int, unsigned);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_021BADB8(char *p, unsigned v) { func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), 0x2B, (void *)(*(int *)(p + 0x524))); func_021B61F4(p, 0, v); func_0201F250(*(void **)(p + 0x520), *(void **)(p + 0x528), *(void **)(p + 0x524)); }
