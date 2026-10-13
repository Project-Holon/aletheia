/*
 * function: FIELD_SUBSCREEN_ExitPowerOnoff
 * address:  0x021A1590
 * packet:   pkt_ov021_021A1590
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_Delete  0x021EFF2C  thumb  ov035
 *   func_02034A5C  0x02034A5C  arm
 *   abs_id_23      0x00000023  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_23[];
extern void C_GEAR_POWER_ONOFF_Delete(char *p);
extern void func_02034A5C(int handle);

void FIELD_SUBSCREEN_ExitPowerOnoff(u32 *p)
{
    C_GEAR_POWER_ONOFF_Delete((char *)p[8]);
    func_02034A5C((int)abs_id_23);
}
