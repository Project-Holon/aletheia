/*
 * packet: pkt_ov186_021FFB80
 * function: BR_NET_OnRapError
 * address: 0x021FFB80
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   GDS_RAP_ReleaseSession 0x021D7124 thumb ov125
 *   GDS_RAP_Exit 0x021D6770 thumb ov125
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 */
#include "../include/Obj10800.h"
typedef unsigned char  u8;
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern void GDS_RAP_ReleaseSession(char *, int, int, int);
extern void GDS_RAP_Exit(char *);
extern void DWC_RAP_SetErrorHookCallback(int, int);
int BR_NET_OnRapError(char *p, int b, int kind, int d)
{
    if (GAME_DATA_IsSaving(((struct Obj10800 *)p)->f5E0)) return 1;
    GDS_RAP_ReleaseSession(p, b, kind, d);
    if (kind == 3 || kind == 6) {
        if (((struct Obj10800 *)p)->f5A4) {
            GDS_RAP_Exit(p);
            ((struct Obj10800 *)p)->f5A4 = 0;
        }
        DWC_RAP_SetErrorHookCallback(0, 0);
    }
    return 0;
}
