/*
 * function: IRCBATTLEMATCH_IsEqual
 * address: 0x021B95AC
 * packet: pkt_ov100_021B95AC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Unlabelled leaf at the start of ov100 (the listing prints it as .word
 * data); referenced as 0x021B95AD from the table word at 021BB85C.
 */

int IRCBATTLEMATCH_IsEqual(int a, int b)
{
    if (a == b)
        return 1;
    return 0;
}
