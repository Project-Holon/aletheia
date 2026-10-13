/*
 * function: FLDEFF_SPLASH_InitBoardObj
 * address:  0x021C4A3C
 * packet:   pkt_ov021_021C4A3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns the field effect object above the owner's position and starts it.
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   gSplashBoardCommands     0x021DE478  data  a4
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm  arm9
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm  arm9
 *   BILLBOARD_ACT_SetEntryCommands  0x02050804  arm  arm9
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V3;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Pair { u32 f0; u32 f4; } Pair;
typedef struct Res { Pair p; u16 h8; } Res;
typedef struct Head { u8 pad[4]; u32 f4; u16 h8; } Head;

extern int FIELD_EFFECT_GetObjectParam(u32 a);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
struct BbActDesc;
struct BbActSys;
extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern void BILLBOARD_ACT_SetEntryCommands(void *p, int idx, u32 v, u16 h);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryEnabled(void *p, int idx, u32 v);
extern u8 gSplashBoardCommands[];

void FLDEFF_SPLASH_InitBoardObj(u32 a, Res *r)
{
    Pair *s = (Pair *)FIELD_EFFECT_GetObjectParam(a);
    Head *h;
    u32 t, k;
    V3 pos;
    Desc d;

    r->p = *s;
    FLDMMDL_GetPos((const struct Actor *)r->p.f4, (struct VecFx32 *)&pos);
    h = (Head *)r->p.f0;
    t = h->f4;
    pos.y -= 0xE000;
    pos.z -= 0xA000;
    d.slot = h->h8;
    d.v12 = 0x1000;
    d.v14 = 0x1000;
    d.k = 0x1f;
    d.flag = 1;
    d.w = 1;
    d.pos = pos;
    d.f1c = 0;
    d.f20 = (u32)r;
    r->h8 = BILLBOARD_ACT_CreateEntries((struct BbActSys *)t, 0, (const struct BbActDesc *)(&d), 1, 3);
    if (r->h8 == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    BILLBOARD_ACT_SetEntryCommands((void *)t, r->h8, (u32)gSplashBoardCommands, 1);
    k = r->h8;
    BILLBOARD_ACT_SetEntryList((void *)t, k, 0);
    BILLBOARD_ACT_SetEntryEnabled((void *)t, k, 1);
}
