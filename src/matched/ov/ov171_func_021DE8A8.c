/*
 * function: DENDOU_VIEW_ReadOverviewInput
 * address: 0x021DE8A8
 * packet: pkt_ov171_021DE8A8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   DENDOU_VIEW_ReadTouchedMember 0x021DE960 thumb ov171
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   d_021DED24 0x021DED24 data a4
 */
typedef unsigned int u32;
extern int TOUCHPANEL_HitTrg(const void *);
extern int DENDOU_VIEW_ReadTouchedMember(char *);
extern unsigned int KEY_GetRepeat(void);
extern u32 KEY_GetTrg(void);
extern const char d_021DED24[];
int DENDOU_VIEW_ReadOverviewInput(char *p)
{
    int result = TOUCHPANEL_HitTrg(d_021DED24);
    if (result == -1) {
        result = DENDOU_VIEW_ReadTouchedMember(p);
        if (result == 0xFF) {
            if (KEY_GetRepeat() & 0x220) return 0;
            if (KEY_GetRepeat() & 0x110) return 1;
            if (KEY_GetTrg() & 1) return 4;
            if (KEY_GetTrg() & 2) return 3;
            return (KEY_GetTrg() & 0x400) ? 2 : 0xFF;
        }
    }
    return result;
}
