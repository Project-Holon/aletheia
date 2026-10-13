/*
 * function: func_021D5990
 * address:  0x021D5990
 * packet:   pkt_ov118_021D5990
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5950  0x021D5950  thumb  ov118
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 func_02051774(void);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern void func_021D5950(void *obj, int on);

void func_021D5990(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)func_021D5950);
}
