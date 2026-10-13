/*
 * function: SCRCMD_WarpToRailLocationWithTransition
 * address:  0x021B0000
 * packet:   pkt_ov021_021B0000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   VM_GetU16  0x02011330  thumb
 *   GAMESYSTEM_GetEvent  0x02012104  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_CalcZoneRailLocation  0x021BB3E8  thumb  ov021
 *   EVENT_MAPCHANGE_CreateRailWarpEventWithTransition  0x02184DE8  thumb  ov020
 */

typedef unsigned short u16;
typedef short          s16;

typedef struct { u16 f0; u16 f2; s16 f4; u16 f6; } Q;
struct Ctx;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Evt;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern unsigned int GAMESYSTEM_GetEvent(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern int FIELD_NOGRID_MAPPER_CalcZoneRailLocation();
extern void *EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(void *p, void *unused, int a, const Q *q, int s, int t);

int SCRCMD_WarpToRailLocationWithTransition(int a0, int a1)
{
    struct Ctx *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int w;
    int loc[2];

    h = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork((void *)a1));
    a = GAMESYSTEM_GetFieldMap(h);
    b = VM_GetU16((struct Stream *)a0);
    c = VM_GetU16((struct Stream *)a0);
    d = VM_GetU16((struct Stream *)a0);
    e = VM_GetU16((struct Stream *)a0);
    f = VM_GetU16((struct Stream *)a0);
    w = GAMESYSTEM_GetEvent(h);
    FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FIELDMAP_GetNogridMapper(a), b, c, d, e, loc, 0x15);
    GAME_EVENT_CallEvent((struct Evt *)w, EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(h, a, b, (const Q *)loc, f, 0));
    return 1;
}
