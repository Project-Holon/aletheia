/*
 * function: sub_0202428C
 * address:  0x0202428C
 * packet:   pkt_02023A50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A slot-clearing sibling of PMSI_PARAM_InitSentence (src/matched/sub_020242A4.c):
 * the same three-halfword sentinel fill, but the leading id field is
 * also set to the sentinel instead of taking a caller-supplied id, so
 * there is no second parameter. The loop counter is signed, the same
 * `blt` tell as the sibling function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202428C.c \
 *       --func sub_0202428C --addr 0x0202428C --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int             s32;

void sub_0202428C(void *obj)
{
    u16 *p = (u16 *)obj;
    s32 i;

    p[0] = 0xFFFF;
    for (i = 0; i < 2; i++) {
        p[i + 2] = 0xFFFF;
    }
}
