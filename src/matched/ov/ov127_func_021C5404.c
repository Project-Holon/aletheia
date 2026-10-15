/*
 * function: WF2DMAP_OBJCMD_SpawnIfFree
 * address: 0x021C5404
 * packet: pkt_ov127_021C5404
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJCMD_IsTileOccupied 0x021C54EC thumb ov127
 *   WF2DMAP_ACTOR_FIND_HasMatch 0x021C5550 thumb ov127
 *   WF2DMAP_OBJDRAW_FillSpawnDesc 0x021C5564 thumb ov127
 */
#include "../include/Obj04502.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern int WF2DMAP_OBJCMD_IsTileOccupied(void *, void *, int);
extern int WF2DMAP_ACTOR_FIND_HasMatch(void *, void *, int);
extern void WF2DMAP_OBJDRAW_FillSpawnDesc(u8 *out, void *p, int kind, int index, int value);
int WF2DMAP_OBJCMD_SpawnIfFree(void *p, void *q, void *r, const u8 *s, void *t)
{
    int v = WF2DMAP_OBJ_GetSlot(p, 5);
    if (v == 0 && WF2DMAP_OBJCMD_IsTileOccupied(p, q, s[2]) != 1 && WF2DMAP_ACTOR_FIND_HasMatch(p, r, s[2]) != 1) {
        WF2DMAP_OBJDRAW_FillSpawnDesc(t, p, ((struct Obj04502 *)s)->f0, s[3], s[2]);
        return 1;
    }
    if (v == 0 && WF2DMAP_OBJ_GetSlot(p, 10) >= 8) {
        WF2DMAP_OBJDRAW_FillSpawnDesc(t, p, 5, s[3], s[2]);
        return 1;
    }
    return 0;
}
