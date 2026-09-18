/*
 * function: func_020682DC
 * address:  0x020682DC
 * packet:   pkt_02067F78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  data_table -- the pool word is 0x020A1914 and its only occurrence
 *           in the image is this function's own literal at 0x020682F4, so the
 *           `literal`/`data_table` classes both refuse; written as an integer
 *           constant the pool word needs no witness but the front end then
 *           synthesises the address with two `add`s and loses the whole body.
 *
 * symbols:
 *   g_020A1914     0x020A1914  data
 *
 * A 2-D table of four-word rows indexed by the byte at +1 then the byte at +0,
 * which is what makes the first index a `lsl #4` on the base and the second a
 * `lsl #2` inside the load's addressing mode.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020682DC.c \
 *       --func func_020682DC --addr 0x020682DC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 g_020A1914[][4];

u32 func_020682DC(u8 *p)
{
    return g_020A1914[p[1]][p[0]];
}
