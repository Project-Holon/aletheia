/*
 * function: WIFICLUB_SyncActorsWithPeers
 * address: 0x021BE7EC
 * packet: pkt_ov099_021BE7EC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: byte bitfield preserves the original left/right shift extraction; declaration order preserves local stack slots.
 * prototypes: C23B8 own tail forwarder void(void) preserves loaded index and live pointer return; C23C0 own void forwarder leaves R0 live for the original test; BDD48/BDD54 own u8 returns are widened to preserve original explicit result truncations.
 * symbols:
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_GetFriendConnectionStatus 0x021C23C0 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUB_IsKindActive 0x021BDDA8 thumb ov099
 *   WIFICLUBACTOR_SetActorMode 0x021B9B00 thumb ov099
 *   func_02009918 0x02009918 thumb
 */
#include "../include/Obj07955.h"
#include "../include/Obj10207.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 low : 2; u8 flag : 2; u8 high : 4; } Flags;
extern int WIFICLUB_GetFriendStatus(int i);
extern u32 WIFICLUB_GetStatusKind(char *, void *);
extern int WIFICLUB_GetStatusPhase(char *, void *);
extern unsigned char WIFICLUB_GetFriendConnectionStatus(void *a);
extern int WIFICLUB_GetStatusSeatFlag(void *);
extern void *WIFICLUB_FindPeerActor(char *, int);
extern int WIFICLUB_IsKindActive(int);
extern void WIFICLUBACTOR_SetActorMode(void *, char *, u8);
struct Sub020097BCObj;
extern void func_02009918(struct Sub020097BCObj *obj, u32 i, u32 field, u32 value);
int WIFICLUB_SyncActorsWithPeers(char *p)
{
    int count = 0;
    int i;
    char *s, *h;
    u8 a, b;
    int old, next;
    for (i = 0; i < 32; i++) {
        s = (char *)WIFICLUB_GetFriendStatus(i);
        a = (u8)WIFICLUB_GetStatusKind(p, s);
        b = (u8)WIFICLUB_GetStatusPhase(p, s);
        if (WIFICLUB_GetFriendConnectionStatus((void *)i) == 0) a = 0;
        if (a != *(u8 *)(p + i + 0x50) ||
            b != *(u8 *)(p + i + 0x70) ||
            *(u8 *)(p + i + 0x90) != WIFICLUB_GetStatusSeatFlag(s)) {
            h = WIFICLUB_FindPeerActor(p, i + 1);
            if (h != 0) {
                old = WIFICLUB_IsKindActive(*(u8 *)(p + i + 0x50));
                next = WIFICLUB_IsKindActive(a);
                if (old == 1 && next == 0) WIFICLUBACTOR_SetActorMode(p + 0x274, h, 0);
                else if (old == 0 && next == 1) WIFICLUBACTOR_SetActorMode(p + 0x274, h, 1);
                func_02009918(((struct Obj07955 *)p)->f4, i, 8, ((struct Obj10207 *)s)->f14);
                func_02009918(((struct Obj07955 *)p)->f4, i, 9, ((Flags *)(s + 0x1b))->flag);
                func_02009918(((struct Obj07955 *)p)->f4, i, 1, ((struct Obj10207 *)s)->f0);
                func_02009918(((struct Obj07955 *)p)->f4, i, 0, ((struct Obj10207 *)s)->f4);
            }
            *(u8 *)(p + i + 0x50) = a;
            *(u8 *)(p + i + 0x70) = b;
            *(u8 *)(p + i + 0x90) = WIFICLUB_GetStatusSeatFlag(s);
            count++;
        }
    }
    return count;
}
