/*
 * function: UNION_CHARA_FocusRequestedMember
 * address:  0x0217B1D0
 * packet:   pkt_ov019_0217B1D0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   memcmp        0x0203EFC8  arm
 *   memset        0x02082BCC  arm
 *   GAMESYSTEM_IsFieldMapExist 0x02012114  thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C  thumb
 *   FIELDMAP_GetUnionEff 0x02188CE0  thumb  ov021
 *   UNION_CHARA_MakeObjId 0x0217AED4  thumb  ov019
 *   GAME_DATA_GetOccupyInfo 0x02012964  thumb
 *   FLDMMDL_SysSearchObjId 0x0216DE94  thumb  ov010
 *   UNION_EFF_AddAnimEffect 0x0217F93C  thumb  ov019
 */

typedef unsigned char u8;

struct sub {
    u8 mac[6];
    u8 pad;
    u8 : 1;
    u8 f : 1;
    u8 : 6;
};

struct ent {
    u8 pad0[0x28];
    struct sub s[5];
    u8 pad1[0x20];
    int p[5];
};

struct inner {
    int pad0[2];
    int f8;
    int fc;
};

struct obj {
    struct inner *in;
};

extern int memcmp(const void *a, const void *b, int n);
extern void memset(void *p, int v, int n);
struct Ctx;
extern unsigned int GAMESYSTEM_IsFieldMapExist(const struct Ctx *p);
typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetUnionEff(u8 *p);
typedef unsigned short u16;
struct BigObj;
extern u16 UNION_CHARA_MakeObjId(u8 *a, u8 *b);
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern void UNION_EFF_AddAnimEffect(int, int);

int UNION_CHARA_FocusRequestedMember(struct obj *o, struct ent *e)
{
    int i;
    int v;
    int t;
    int r;

    for (i = 0; i < 5; i++) {
        v = e->p[i];
        if (v == 0 || e->s[i].f != 1) {
            continue;
        }
        if (memcmp(e->s[i].mac, (char *)o + 0x28a4, 6) != 0) {
            continue;
        }
        if (GAMESYSTEM_IsFieldMapExist((const struct Ctx *)o->in->fc) == 1) {
            t = FIELDMAP_GetUnionEff(GAMESYSTEM_GetFieldMap((void *)o->in->fc));
            if (t != 0) {
                r = UNION_CHARA_MakeObjId((u8 *)e, (u8 *)v);
                r = (int)FLDMMDL_SysSearchObjId((void *)GAME_DATA_GetOccupyInfo((const struct BigObj *)o->in->f8), r);
                if (r != 0) {
                    UNION_EFF_AddAnimEffect(t, r);
                }
            }
        }
        memset((char *)o + 0x28a4, 0, 6);
        return 1;
    }
    return 0;
}
