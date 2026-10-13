/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ModelSetPosition
 * address: 0x021B7F50
 * packet: pkt_ov103_021B7F50
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
struct V3 { u32 a, b, c; };
void IRC_COMPATIBLE_TOUCH_TEST_ModelSetPosition(char *p, struct V3 *q)
{
    *(struct V3 *)(p + 0x1c) = *q;
}
