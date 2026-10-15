/*
 * function: sciWsInit
 * address:  0x021E06DC
 * packet:   pkt_021E06DC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gsCoreIsShutdown  0x0217CE1C  arm
 *
 * Initialise the owner record: refused with 4 while the ov175 session is not
 * up, otherwise the handle is latched at +0, the 0x2c/0x28/0x30 and
 * 0x14/0x10/0x18 triplets and the +4/+8/+0xc words are cleared and the live
 * flag at +0x48 is set.
 */

typedef int s32;
typedef unsigned int u32;

extern s32 gsCoreIsShutdown(void);

s32 sciWsInit(char *p, u32 v)
{
    u32 z = 0;

    if (gsCoreIsShutdown() != 0)
        return 4;
    *(u32 *)(p + 0x00) = v;
    *(u32 *)(p + 0x04) = z;
    *(u32 *)(p + 0x08) = z;
    *(u32 *)(p + 0x0c) = z;
    *(u32 *)(p + 0x2c) = z;
    *(u32 *)(p + 0x28) = z;
    *(u32 *)(p + 0x30) = z;
    *(u32 *)(p + 0x14) = z;
    *(u32 *)(p + 0x10) = z;
    *(u32 *)(p + 0x18) = z;
    *(u32 *)(p + 0x48) = 1;
    return 0;
}
