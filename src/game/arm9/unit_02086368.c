/*
 * file:     unit_02086368.c
 * function: OS_Init
 * address:  0x02086368
 * packet:   pkt_02086368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  02086374 -- a tail call through a pool word
 *           (docs/idioms/tail-call-is-a-pool-word-and-bx.md), and that pool
 *           word is the only reference to 0x02086374 anywhere in the image,
 *           so the `literal` class discards its only witness and no cut
 *           helps: the pool is inside this function's own 12-byte extent.
 *           func_02086374 is itself MATCH-capped (eleven callees each called
 *           from exactly one site), so the `matched` class cannot reach it
 *           either.  Every concrete byte is right: `ldr ip, [pc] ; bx ip`
 *           plus the pool word, 8 bytes of code.
 *
 * A one-line forwarder to the driver at 0x02086374; mwccarm emits exactly
 * this shape for an ARM tail call, which is why the eight bytes are
 * reproducible at all.
 */

extern void func_02086374(void);

void OS_Init(void)
{
    func_02086374();
}
