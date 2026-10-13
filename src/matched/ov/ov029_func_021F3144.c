/*
 * function: C_GEAR_SetPowerState
 * address:  0x021F3144
 * packet:   pkt_ov029_021F3144
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   C_GEAR_ShowCommIndicator  0x021F2CF4  thumb
 *   C_GEAR_HideCommIndicator  0x021F2D10  thumb
 *   C_GEAR_ShowOffIndicator  0x021F2CD8  thumb
 *   C_GEAR_HideOffIndicator  0x021F2D30  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int GFL_NET_GetRunState(void);
extern void C_GEAR_ShowCommIndicator(u8 *);
extern void C_GEAR_HideCommIndicator(u8 *);
extern void C_GEAR_ShowOffIndicator(char *p);
extern void C_GEAR_HideOffIndicator(u8 *);

void C_GEAR_SetPowerState(u8 *p, int v)
{
    if (GFL_NET_GetRunState() == 0 && p[0x45A] != 0)
        C_GEAR_ShowCommIndicator(p);
    else
        C_GEAR_HideCommIndicator(p);
    if (p[0x454] != v) {
        if (v == 0)
            C_GEAR_ShowOffIndicator((char *)p);
        else
            C_GEAR_HideOffIndicator(p);
        p[0x454] = v;
    }
}
