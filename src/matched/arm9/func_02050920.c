/*
 * function: BILLBOARD_ACT_IsControlCommand
 * address:  0x02050920
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_IsControlCommand.c \
 *       --func BILLBOARD_ACT_IsControlCommand --addr 0x02050920 --cc 1.1p1 --arm
 *
 * symbols:
 *   BILLBOARD_ACT_GetControlHandler  0x02050984  arm
 */

typedef unsigned short u16;

struct S14 {
    u16 f : 14;
};

extern int BILLBOARD_ACT_GetControlHandler(int a);

int BILLBOARD_ACT_IsControlCommand(struct S14 *p)
{
    return BILLBOARD_ACT_GetControlHandler(p->f) != 0;
}
