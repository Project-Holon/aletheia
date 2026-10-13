/*
 * function: FLDEFF_RIPPLE_InitObj
 * address:  0x021C48A0
 * packet:   pkt_ov021_021C48A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BILLBOARD_ACT_SetEntryList and BILLBOARD_ACT_SetEntryEnabled are witnessed by
 * src/matched/arm9/BILLBOARD_ACT_SetEntryList.c and src/matched/arm9/BILLBOARD_ACT_SetEntryEnabled.c.
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_SetEntryCommands  0x02050804  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   gRippleBoardCommands     0x021DE464  data  a4
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

typedef struct Src { u32 f0; V3 v; } Src;
typedef struct Res { u32 f0; u16 h4; } Res;
typedef struct Head { u8 pad[4]; u32 f4; u16 h8; } Head;

extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern void FIELD_EFFECT_SetObjectPos(u32 a, V3 *v);
struct BbActDesc;
struct BbActSys;
extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern void BILLBOARD_ACT_SetEntryCommands(void *p, int idx, u32 v, u16 h);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryEnabled(void *p, int idx, u32 v);
extern u8 gRippleBoardCommands[];

void FLDEFF_RIPPLE_InitObj(u32 a, Res *r)
{
    Src *s = (Src *)FIELD_EFFECT_GetObjectParam(a);
    Head *h;
    u32 t, k;
    Desc d;

    r->f0 = s->f0;
    FIELD_EFFECT_SetObjectPos(a, &s->v);
    h = (Head *)r->f0;
    t = h->f4;
    d.slot = h->h8;
    d.v12 = 0x1000;
    d.v14 = 0x1000;
    d.k = 0x1f;
    d.flag = 1;
    d.w = 1;
    d.pos = s->v;
    d.f1c = 0;
    d.f20 = (u32)r;
    r->h4 = BILLBOARD_ACT_CreateEntries((struct BbActSys *)t, 0, (const struct BbActDesc *)(&d), 1, 3);
    if (r->h4 == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    BILLBOARD_ACT_SetEntryCommands((void *)t, r->h4, (u32)gRippleBoardCommands, 1);
    k = r->h4;
    BILLBOARD_ACT_SetEntryList((void *)t, k, 0);
    BILLBOARD_ACT_SetEntryEnabled((void *)t, k, 1);
}
