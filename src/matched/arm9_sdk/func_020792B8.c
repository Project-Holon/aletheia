/*
 * function: func_020792B8
 * address:  0x020792B8
 * packet:   pkt_020792B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02078D34  0x02078D34  arm
 *   func_02079254  0x02079254  arm
 *
 * Builds a 44-byte iterator/descriptor on the stack from (a, b) and, if
 * that succeeded, runs it once; the result is normalised to 0/1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020792B8.c \
 *       --func func_020792B8 --addr 0x020792B8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Iter020792B8 {
    u32 words[11];
};

struct FSOverlayInfo;
extern int func_02078D34(struct FSOverlayInfo *p_ovi, u32 target, u32 id);
extern int func_02079254(struct Iter020792B8 *it);

int func_020792B8(u32 a, u32 b)
{
    struct Iter020792B8 it;

    if (func_02078D34((struct FSOverlayInfo *)(&it), a, b) != 0 && func_02079254(&it) != 0) {
        return 1;
    }
    return 0;
}
