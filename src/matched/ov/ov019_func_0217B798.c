/*
 * function: UNION_CHARA_OnBeaconUpdate
 * address:  0x0217B798
 * packet:   pkt_ov019_0217B798
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_CHAT_LOG_Add 0x021BBA70  thumb  ov021
 *   func_02087C6C 0x02087C6C  arm
 *   memcmp        0x0203EFC8  arm
 *   UNION_ONESELF_SetNextPlayCategoryInMainPhase 0x0217B8F0  thumb  ov019
 *   UNION_COMM_SetSituationParam 0x021734A8  thumb  ov012
 */
#include "../include/Obj07381.h"

typedef unsigned char u8;
typedef unsigned short u16;

struct Ctx;
struct Src;
extern void UNION_CHAT_LOG_Add(struct Ctx *ctx, struct Src *src, u16 *v, u8 kind);
extern void func_02087C6C(void *);
extern int memcmp(const void *a, const void *b, int n);
extern int UNION_ONESELF_SetNextPlayCategoryInMainPhase(char *p, char v);
typedef unsigned int   u32;
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);

void UNION_CHARA_OnBeaconUpdate(char *base, u8 *p)
{
    u8 *q = (u8 *)base + 0x2830;
    u8 buf[6];

    UNION_CHAT_LOG_Add((struct Ctx *)base, (struct Src *)p, 0, 0);
    if (q[1] == 0 && q[0x71] == 0 && p[0xa] == 5 && ((struct Obj07381 *)p)->f6C != 0) {
        func_02087C6C(buf);
        if (memcmp(p, buf, 6) == 0 && UNION_ONESELF_SetNextPlayCategoryInMainPhase(base, 6) == 1) {
            UNION_COMM_SetSituationParam((u8 *)base, 2, (u32)p);
            UNION_COMM_SetSituationParam((u8 *)base, 0, (u32)p);
        }
    }
}
