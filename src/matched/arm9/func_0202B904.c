/*
 * function: ISS_3DS_SYS_Leave
 * address: 0x0202B904
 * packet: pkt_arm9_0202B904
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
 *   ISS_3DS_SYS_LeaveImpl 0x0202BAE8 thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
void ISS_3DS_SYS_Leave(u8 *p);
void ISS_3DS_SYS_LeaveImpl(u32 *p);

void ISS_3DS_SYS_Leave(u8 *p)
{
    ISS_3DS_SYS_LeaveImpl((u32 *)p);
}
