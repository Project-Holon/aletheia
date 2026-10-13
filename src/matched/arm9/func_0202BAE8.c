/*
 * function: ISS_3DS_SYS_LeaveImpl
 * address: 0x0202BAE8
 * packet: pkt_arm9_0202BAE8
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/iss_3ds_sys_p02.c and filed here.
 */

typedef unsigned int  u32;
void ISS_3DS_SYS_LeaveImpl(u32 *p);

void ISS_3DS_SYS_LeaveImpl(u32 *p)
{
    if (p[1] != 0) {
        p[1] = 0;
    }
}
