/*
 * function: INTRUDE_FIELD_GetHostGender
 * address:  0x0217C0A8
 * packet:   pkt_ov018_0217C0A8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 */
#include "../include/Obj19353.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern unsigned int GAME_COMM_GetGameData(void *obj);
struct BigObj;
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern u8 GAME_DATA_GetIntrudeId(const struct BigObj *p);
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern unsigned int GAME_COMM_GetKind(void *obj);
extern unsigned int GAME_COMM_GetWork(void *obj);
typedef unsigned int   u32;
extern u32 ZONEDATA_IsEntralink(u32 id);
struct Rec44;
struct Sub24;
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);

u8 INTRUDE_FIELD_GetHostGender(void *a0)
{
    int h;
    u8 *q;
    u8 *obj;

    h = GAME_COMM_GetGameData(a0);
    if (GAME_DATA_GetIntrudeCount((const struct BigObj *)h) == 0) {
        obj = GAME_DATA_GetMyStatus((void *)h);
    } else if (GAME_DATA_GetIntrudeId((const struct BigObj *)h) == GAME_DATA_GetOwnNetId((const struct BigObj *)h)) {
        obj = GAME_DATA_GetMyStatus((void *)h);
    } else {
        q = 0;
        if (GAME_COMM_GetKind(a0) == 2 && GAME_COMM_GetWork(a0) != 0)
            q = (u8 *)GAME_COMM_GetWork(a0);
        if (q == 0) {
            obj = GAME_DATA_GetMyStatus((void *)h);
        } else if (ZONEDATA_IsEntralink(((struct Obj19353 *)q)->f84) == 1) {
            obj = GAME_DATA_GetMyStatus((void *)h);
        } else {
            obj = (u8 *)GAME_DATA_GetMyStatusPlayer((struct Sub24 *)h, GAME_DATA_GetIntrudeId((const struct BigObj *)h));
        }
    }
    return func_02008550((const struct Sub0200852CObj *)obj);
}
