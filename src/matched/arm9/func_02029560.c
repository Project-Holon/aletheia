/*
 * function: func_02029560
 * address:  0x02029560
 * packet:   pkt_02029488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02029488.c is now a manifest entry (matched class)
 *
 * Three-state stepper, kind 3 variant: state 0 emits the descriptor and
 * advances, state 1 advances only once func_020289B8 reports the channel is
 * idle, state 2 reports done.
 *
 * symbols:
 *   func_020289F8  0x020289F8  thumb
 *   func_020289B8  0x020289B8  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02029560.c \
 *       --func func_02029560 --addr 0x02029560 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020289F8(u32 a, u32 b, u32 c, u32 d, u32 e);
extern int func_020289B8(u32 a);

int func_02029560(u32 unused, u32 *state, u8 *cfg)
{
    u32 v = *(u32 *)(cfg + 4);

    switch (*state) {
    case 0:
        func_020289F8(v, 3, 0, *(u16 *)(cfg + 0xe), 0);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(v) == 0) {
            (*state)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
