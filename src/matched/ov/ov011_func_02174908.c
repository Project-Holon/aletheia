/*
 * function: INTRUDE_COMM_RecvAreaNotice
 * address:  0x02174908
 * packet:   pkt_ov011_02174908
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 */
#include "../include/Obj09346.h"

typedef unsigned int   u32;
struct SaveBlock;
u32 GAME_COMM_GetGameData(void *obj);
typedef unsigned short u16;
struct Entry;
struct Rec44;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
u32 GFL_NET_GetHandleNetID(struct Link *p);
void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
unsigned int ZONEDATA_IsZoneGroup118To120(unsigned int id);

void INTRUDE_COMM_RecvAreaNotice(int a, int b, int c, unsigned char *d)
{
    int h;

    h = GAME_COMM_GetGameData((void *)(((struct Obj09346 *)d)->f4));
    if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()) && ((unsigned)(((struct Obj09346 *)d)->f86 << 29) >> 29) == a) {
        if (ZONEDATA_IsZoneGroup118To120(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct SaveBlock *)h))) != 0) {
            d[0x8F8] |= 4;
        }
    }
}
