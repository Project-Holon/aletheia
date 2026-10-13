/*
 * unit:     no
 * function: PROCSYS_Push
 * address:  0x02031348
 * packet:   pkt_02031348
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_PushInternal  0x020314F4  arm
 */

extern void PROCSYS_PushInternal(void);
void PROCSYS_Push(void){ PROCSYS_PushInternal(); }
