/*
 * unit:     no
 * function: sub_020307B0
 * address:  0x020307B0
 * packet:   pkt_02030608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030164  0x02030164  arm
 *   sub_02030A2C  0x02030A2C  arm
 *
 * The release counterpart of sub_02030734, and the second-highest-radiation
 * function of the heap layer: 904 branch references image-wide.  It runs the
 * watched-allocation bookkeeping first (sub_02030A2C, which reads the block
 * header the raw allocator stamped) and then hands the pointer to the raw
 * free at 0x02030164, which walks back over the 0x1c-byte header.
 *
 * The pointer has to survive the first call, which is the whole reason for
 * the `push {r4, lr}` and the `mov r0, r4` before the second: with the calls
 * the other way round the parameter would still be in r0 and the function
 * would be a pair of tail calls.
 *
 * layout/symbols_sdk.json offers the name ENV_SetResourceSet for this
 * address.  It is a signature-matcher guess with eight siblings, and the role
 * here is plainly the heap free, so the canonical sub_ name is used; see the
 * same note in src/matched/sub_02030734.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020307B0.c \
 *       --func sub_020307B0 --addr 0x020307B0 --cc 1.1p1 --arm
 */

extern void sub_02030164(void *p);
extern void sub_02030A2C(void *p);

void sub_020307B0(void *p)
{
    sub_02030A2C(p);
    sub_02030164(p);
}
