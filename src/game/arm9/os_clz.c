/*
 * file:     os_clz.c
 * function: func_02087EA0
 * address:  0x02087EA0
 * packet:   pkt_02087EA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

/* hand-written in the original: clz is never emitted by mwccarm from C */
asm int func_02087EA0(unsigned int value)
{
    clz r0, r0
    bx lr
}
