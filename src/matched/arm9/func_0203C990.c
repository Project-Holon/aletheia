/*
 * function: func_0203C990
 * address:  0x0203C990
 * packet:   pkt_0203C938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   unk_021469DC   0x021469DC  data
 *
 * The mode byte src/matched/func_0203C938.c writes, read back - 0 when there
 * is no object.  Both loads are conditional, so the function is two
 * instructions plus the two pool words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C990.c \
 *       --func func_0203C990 --addr 0x0203C990 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 unk_021469DC;

u32 func_0203C990(void)
{
    u8 *p;

    p = (u8 *)unk_021469DC;
    return p ? p[0x4D] : 0;
}
