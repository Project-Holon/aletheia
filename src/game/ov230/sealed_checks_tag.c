/*
 * file:     sealed_checks_tag.c
 * unit:     yes
 * function: OV230_ReturnTag0, OV230_ReturnTag1
 * address:  0x021893B8
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Second-layer bodies of overlay 230 (region ov230d, opened by tools/ovcrypt.py): two checks that return a fixed tag.
 * The last two chain checks add the tag to their sum.
 *
 * symbols:
 *   OV230_ReturnTag0  0x021893B8  arm  ov230d
 *   OV230_ReturnTag1  0x021893C4  arm  ov230d
 */
typedef unsigned int u32;

u32 OV230_ReturnTag0(void)
{
    return 0xB5B1;
}

u32 OV230_ReturnTag1(void)
{
    return 0xC127;
}
