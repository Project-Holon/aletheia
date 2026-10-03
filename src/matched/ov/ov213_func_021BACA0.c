/*
 * function: func_021BACA0
 * address: 0x021BACA0
 * packet: pkt_ov213_021BACA0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * Preserve the pointer explicitly loaded before the no-op/global helper call.
 * symbols:
 *   func_021BAD50 0x021BAD50 thumb ov213
 *   func_021BADBC 0x021BADBC thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021BAD50(void *);
extern void func_021BADBC(void *);
void func_021BACA0(void *unused,char *p) { func_021BAD50(p); func_021BADBC(p+4); }
