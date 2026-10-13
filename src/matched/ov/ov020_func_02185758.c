/*
 * function: EVENT_MAPCHANGE_DirToAngle
 * address: 0x02185758
 * packet: pkt_ov020_02185758
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
int EVENT_MAPCHANGE_DirToAngle(int value)
{
    switch (value) {
    case 0:
    case 1:
    default: return 0;
    case 3: return 0x4000;
    case 2: return 0x8000;
    case 4: return 0xc000;
    }
}
