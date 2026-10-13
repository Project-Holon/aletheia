/*
 * function: WIFICLUB_DropActorsOfMissingPeers
 * address: 0x021BF1CC
 * packet: pkt_ov099_021BF1CC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind WIFICLUB_GetFriendStatus result before evaluating the outer call's
 *   byte argument; nesting caches that byte across the inner call.
 * symbols:
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUBACTOR_SpawnSlotActor 0x021B9968 thumb ov099
 *   WIFICLUB_SetSlotState 0x021C2028 thumb ov099
 *   WIFICLUB_AddPeerActor 0x021BE21C thumb ov099
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj22050.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void *WIFICLUB_FindPeerActor(char *p, int key);
extern int WIFICLUB_GetFriendStatus(int i);
extern void *WIFICLUBACTOR_SpawnSlotActor(char *, int, int);
extern void WIFICLUB_SetSlotState(char *p, int i, u8 v);
extern void WIFICLUB_AddPeerActor(char *, void *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void WIFICLUB_DropActorsOfMissingPeers(char *p)
{
    int changed = 0;
    int i;
    void *v;
    char *s;
    for (i = 0; i < 32; i++) {
        if (*(u8 *)(p + i + 0x10) && !WIFICLUB_FindPeerActor(p, *(u8 *)(p + i + 0x10))) {
            s = (char *)WIFICLUB_GetFriendStatus(*(u8 *)(p + i + 0x10) - 1);
            v = WIFICLUBACTOR_SpawnSlotActor(p + 0x274, ((struct Obj22050 *)s)->f14, *(u8 *)(p + i + 0x10));
            if (v) {
                WIFICLUB_SetSlotState(p, *(u8 *)(p + i + 0x10), 2);
                WIFICLUB_AddPeerActor(p, v);
                *(u8 *)(p + i + 0x50) = 0;
                *(u8 *)(p + i + 0x70) = 0;
                *(u8 *)(p + i + 0x90) = 0;
                changed = 1;
            }
        }
    }
    if (changed == 1) GFL_USE_PlaySeDefaultVolume(0x676);
}
