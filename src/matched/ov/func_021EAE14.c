/*
 * function: func_021EAE14
 * address:  0x021EAE14
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAE14   0x021EAE14  thumb  ov093
 *   func_021EE25C   0x021EE25C  thumb  ov093

 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021EE25C is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021EAE14(u32 *p) { return func_021EE25C(p[0x5f]); }

