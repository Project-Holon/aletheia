/*
 * function: FILE_UTIL_Create_0F14
 * address:  0x02020F14
 * packet:   pkt_02020E60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker FILE_UTIL_GetBankCount.c is now a manifest entry (matched class)
 *
 * Tail-call thunk: opens handle 0x18 with the caller's argument.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/FILE_UTIL_Create_0F14.c \
 *       --func FILE_UTIL_Create_0F14 --addr 0x02020F14 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);

void *FILE_UTIL_Create_0F14(u32 a)
{
    return func_020490F4(0x18, a);
}
