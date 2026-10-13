/*
 * function: ISS_ROAD_SYS_Stop
 * address: 0x0202B204
 * packet: pkt_arm9_0202B204
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/iss_road_sys.c and filed here.
 *
 * symbols:
 *   ISS_ROAD_SYS_Deactivate 0x0202B224 thumb
 */

typedef unsigned char u8;
void ISS_ROAD_SYS_Stop(u8 *a0);
void ISS_ROAD_SYS_Deactivate(u8 *p);

void ISS_ROAD_SYS_Stop(u8 *a0)
{
    ISS_ROAD_SYS_Deactivate(a0);
}
