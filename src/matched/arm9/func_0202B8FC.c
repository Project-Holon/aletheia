/*
 * function: ISS_3DS_SYS_Enter
 * address: 0x0202B8FC
 * packet: pkt_arm9_0202B8FC
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/iss_3ds_sys.c and filed here.
 *
 * symbols:
 *   ISS_3DS_SYS_EnterImpl 0x0202BABC thumb
 */

typedef unsigned char u8;
void ISS_3DS_SYS_Enter(u8 *p);
void ISS_3DS_SYS_EnterImpl(u8 *o);

void ISS_3DS_SYS_Enter(u8 *p)
{
    ISS_3DS_SYS_EnterImpl(p);
}
