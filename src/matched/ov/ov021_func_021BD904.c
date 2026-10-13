/*
 * function: EVENT_ENTRANCE_IN_IsDungeonTransition
 * address:  0x021BD904
 * packet:   pkt_ov021_021BD904
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   func_0202B580  0x0202B580  thumb
 *   ISS_DUNGEON_SYS_IsActive  0x0202B434  thumb
 *   ISS_DUNGEON_SYS_HasRecord  0x0202B438  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x0;
    u32 x4;
    u8 pad8[0x10];
    u16 h18;
    u8 pad1a[6];
    u16 h20;
} Ent;

typedef struct {
    u32 x0;
    u32 x4;
    Ent *e;
} Obj;

extern u32 GAMESYSTEM_GetIssSystem(u32 *p);
extern u32 func_0202B580(void *obj);
extern u32 ISS_DUNGEON_SYS_IsActive(u8 *p);
extern u32 ISS_DUNGEON_SYS_HasRecord(u8 *p, u32 id);

int EVENT_ENTRANCE_IN_IsDungeonTransition(Obj *o)
{
    Ent *e = o->e;
    void *s = (void *)func_0202B580((void *)GAMESYSTEM_GetIssSystem((u32 *)e->x4));

    if (ISS_DUNGEON_SYS_IsActive(s) && ISS_DUNGEON_SYS_HasRecord(s, e->h18) && ISS_DUNGEON_SYS_HasRecord(s, e->h20)) {
        return 1;
    }
    return 0;
}
