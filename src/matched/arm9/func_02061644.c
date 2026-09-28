/*
 * function: func_02061644
 * address:  0x02061644
 * packet:   pkt_020613D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * An eight-byte unlabelled leaf: `mov r0, #0; bx lr`.  disasm.py only labels
 * a function whose prologue saves lr, so this stub is invisible in the
 * listing and sits between the tail of func_020614D4's literal pool (which
 * ends at 0x02061640) and the next labelled function at 0x0206164C.
 *
 * It is the default callback func_020613D8 installs at 0x020A8144 as a
 * function pointer, so the pool word naming it is the only reference in the
 * image; filing this entry is what lets that pool word resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061644.c \
 *       --func func_02061644 --addr 0x02061644 --arm --cc 1.1p1
 */

typedef unsigned int u32;

u32 func_02061644(void)
{
    return 0;
}
