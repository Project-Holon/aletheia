/*
 * function: SCRCMD_POKE_ICON_Task
 * address:  0x021D26D0
 * packet:   pkt_ov021_021D26D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   SCRCMD_POKE_ICON_DeleteIcon  0x021D26AC  thumb  ov021
 *   SCRCMD_POKE_ICON_ShowWindow  0x021D25E8  thumb  ov021
 *   BMP_WIN_Delete  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 KEY_GetTrg(void);
extern int SCRCMD_POKE_ICON_DeleteIcon(u32 *a);
extern void SCRCMD_POKE_ICON_ShowWindow(u32 *p);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

u32 SCRCMD_POKE_ICON_Task(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        if (KEY_GetTrg() & 3) {
            SCRCMD_POKE_ICON_DeleteIcon(p);
            SCRCMD_POKE_ICON_ShowWindow(p);
            st[0]++;
        }
        break;
    case 1:
        BMP_WIN_Delete((struct Descriptor *)p[0]);
        return 1;
    }
    return 0;
}
