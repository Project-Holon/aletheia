/*
 * function: GDS_RAP_FindMember
 * address: 0x021D7154
 * packet: pkt_ov125_021D7154
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_GetVideoWork 0x021D7700 thumb ov125
 *   BATTLE_REC_GetModeLayout  0x0200B784  thumb  arm9
 */
#include "../include/Obj22999.h"
typedef unsigned short u16;
extern char *GDS_RAP_GetVideoWork(void);
extern void BATTLE_REC_GetModeLayout(u16, int *, int *);
int GDS_RAP_FindMember(int a, int index, int *outer, int *inner)
{
    char *p;
    int n, other;
    int i;
    i = 0;
    p = GDS_RAP_GetVideoWork();
    BATTLE_REC_GetModeLayout(((struct Obj22999 *)p)->fA6, &n, &other);
    for (*outer = 0; *outer < n; ++*outer) {
        for (*inner = 0; *inner < *(u16 *)(p + *outer * 676 + 0xcfe); ++*inner) {
            if (i == index) return 1;
            ++i;
        }
    }
    return 0;
}
