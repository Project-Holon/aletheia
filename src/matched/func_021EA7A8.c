/*
 * function: func_021EA7A8
 * address:  0x021EA7A8
 * packet:   pkt_021E9964
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EA7A8   0x021EA7A8  thumb  ov093
 *   func_021EDB00   0x021EDB00  thumb  ov093
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

void func_021EA7A8(u32 *p, u32 a2) { func_021EDB00(p[0x5f], a2); }

