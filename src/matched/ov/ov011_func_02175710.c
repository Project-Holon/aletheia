/*
 * unit:     yes
 * function: INTRUDE_COMM_SetIntrudeId, INTRUDE_COMM_SetSuspended
 * address:  0x02175710
 * packet:   pkt_ov011_02175710
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * INTRUDE_COMM_SetSuspended is an unlabelled leaf (bit 1 of the byte at +0x904).
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_SetIntrudeId  0x02012B8C  thumb
 *   EVENT_FIELD_PROCLINK_SetReturnLinkId  0x02161FEC  thumb  ov010
 */
#include "../include/Obj00269.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Lo3 {
    u16 v  : 3;
    u16 hi : 13;
} Lo3;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern void GAME_DATA_SetIntrudeId(struct BigObj *p, u32 v);
extern void EVENT_FIELD_PROCLINK_SetReturnLinkId(char *p, u16 v);

void INTRUDE_COMM_SetIntrudeId(u8 *o, u32 v)
{
    void *p;

    p = GAMESYSTEM_GetGameData(((struct Obj00269 *)o)->f0);
    ((Lo3 *)(o + 0x86))->v = v;
    GAME_DATA_SetIntrudeId(p, v);
    EVENT_FIELD_PROCLINK_SetReturnLinkId((char *)(o + 0x35c), (u8)v);
}

typedef struct Flags {
    u8 a  : 1;
    u8 f  : 1;
    u8 hi : 6;
} Flags;

void INTRUDE_COMM_SetSuspended(u8 *o, u32 v)
{
    ((Flags *)(o + 0x904))->f = (u8)v;
}
