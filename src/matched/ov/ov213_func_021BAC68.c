/*
 * function: func_021BAC68
 * address: 0x021BAC68
 * packet: pkt_ov213_021BAC68
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * Preserve the pointer explicitly loaded before the no-op/global helper call.
 * symbols:
 *   func_021BADB4 0x021BADB4 thumb ov213
 *   func_021BAD4C 0x021BAD4C thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021BADB4(void *);
extern void func_021BAD4C(void *);
void func_021BAC68(char *p) { func_021BADB4(p+4); func_021BAD4C(p); }
