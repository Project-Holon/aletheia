/*
 * function: EVENT_COMM_COMMON_GetTalkType
 * address:  0x021803F0
 * packet:   pkt_ov018_021803F0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   INTRUDE_COMM_GetRequestKind  0x02175DCC  thumb  ov011
 *   INTRUDE_COMM_GetSessionResult  0x02175BCC  thumb  ov011
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb  ov011
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   INTRUDE_COMM_IsRequestFromNetId  0x0217620C  thumb  ov011
 */
#include "../include/Obj19375.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u8 pad : 5; u8 f : 1; u8 rest : 2; } Bf;

struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern int INTRUDE_COMM_GetRequestKind(void *p);
extern u8 *INTRUDE_COMM_GetSessionResult(u8 *p);
extern int INTRUDE_COMM_IsSessionActive(u8 *);
extern int INTRUDE_COMM_IsSessionAccepted(u8 *);
extern int INTRUDE_COMM_IsRequestFromNetId(u8 *, int);

static inline int state(u8 *a, u8 *b, u8 cur)
{
    if (INTRUDE_COMM_GetSessionResult(b + 0x1AC) == 0 && INTRUDE_COMM_IsSessionActive(b + 0x1AC) == 1) {
        if (INTRUDE_COMM_IsSessionAccepted(b + 0x1AC) == 1) {
            if (INTRUDE_COMM_IsRequestFromNetId(b + 0x1AC, a[0x40]) == 1)
                return 3;
            if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 4;
            return 5;
        }
        if (INTRUDE_COMM_IsRequestFromNetId(b + 0x1AC, cur) == 1) {
            if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 6;
            return 7;
        }
        if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
            return 1;
        if (INTRUDE_COMM_IsRequestFromNetId(b + 0x1AC, a[0x40]) == 1)
            return 2;
        return 0;
    }
    return 0;
}

int EVENT_COMM_COMMON_GetTalkType(u8 *a, u8 *b)
{
    u8 cur;
    int kind;
    int r;

    cur = (int)GAME_DATA_GetOwnNetId((const struct BigObj *)((int)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(((struct Obj19375 *)a)->fC))));
    kind = INTRUDE_COMM_GetRequestKind(b + 0x1AC);
    r = state(a, b, cur);
    if (r >= 3) {
        switch (kind) {
        case 0: r += 8; break;
        case 1: r += 13; break;
        case 2: r += 18; break;
        case 3: r += 23; break;
        case 4: r += 28; break;
        case 5: r += 33; break;
        }
        r -= 3;
    }
    return r;
}
