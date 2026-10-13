/*
 * function: EVENT_FIELD_PROCLINK_CreateReportParam
 * address:  0x0216163C
 * packet:   pkt_ov010_0216163C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Allocate an 0x10-byte record and store the save handle at +4.
 * The extent also holds the unlabelled leaf at 0x02161668.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 */
#include "../include/Obj18944.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const char d_02172978[];

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

u32 *EVENT_FIELD_PROCLINK_CreateReportParam(char *c)
{
    u32 *r;

    r = func_02030734(4, 0x10, 1, d_02172978, 0x8AC);
    r[1] = (u32)GAMESYSTEM_GetGameData(**(void ** *)&((struct Obj18944 *)c)->f18);
    return r;
}
