/*
 * unit:     yes
 * function: MAP_ATTR_IsDeepSand, MAP_ATTR_IsDeepSandB, MAP_ATTR_IsSand, MAP_ATTR_IsGrassSingleB, MAP_ATTR_IsGrassDoubleB, MAP_ATTR_IsMirrorFloor, MAP_ATTR_IsNoDash
 * address:  0x021AB404
 * packet:   pkt_021AB404
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seven one-line equality predicates, one per constant.
 */

int MAP_ATTR_IsDeepSand(int x)
{
    return x == 0xBE;
}

int MAP_ATTR_IsDeepSandB(int x)
{
    return x == 0xBF;
}

int MAP_ATTR_IsSand(int x)
{
    return x == 0xC;
}

int MAP_ATTR_IsGrassSingleB(int x)
{
    return x == 0x5;
}

int MAP_ATTR_IsGrassDoubleB(int x)
{
    return x == 0x7;
}

int MAP_ATTR_IsMirrorFloor(int x)
{
    return x == 0x1B;
}

int MAP_ATTR_IsNoDash(int x)
{
    return x == 0x33;
}
