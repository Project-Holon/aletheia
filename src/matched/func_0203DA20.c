/*
 * function: func_0203DA20
 * address:  0x0203DA20
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469F0  0x021469F0  data
 *
 * Calls func_0203D9EC when the net_irc_wireless singleton exists and its
 * +0x101 byte is clear.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203DA20.c \
 *       --func func_0203DA20 --addr 0x0203DA20 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 g_021469F0[];

extern void func_0203D9EC(void);

void func_0203DA20(void)
{
    u8 *p = *(u8 **)g_021469F0;

    if (p == 0) {
        return;
    }
    if (p[0x101] != 0) {
        return;
    }
    func_0203D9EC();
}
