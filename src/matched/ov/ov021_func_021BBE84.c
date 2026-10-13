/*
 * function: FLDEFF_FOOTMARK_InitTask
 * address:  0x021BBE84
 * packet:   pkt_ov021_021BBE84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 */
typedef unsigned short u16;
typedef signed char s8;

struct Head {
    unsigned char pad[4];
    void *h4;
    u16 tab[1];
};

typedef struct Src {
    struct Head *head;
    u16 idx;
    u16 x;
} Src;

typedef struct Res {
    struct Head *head;
    u16 idx;
    u16 x;
    u16 h8;
    unsigned char padA[4];
    short h0e;
} Res;

typedef struct Desc1 {
    u16 a, b, c;
    s8 d;
    int e, f;
} Desc1;

typedef struct Desc2 {
    int pad[3];
    int a;
    Res *b;
} Desc2;

typedef unsigned int   u32;
struct BbActDesc;
struct BbActSys;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern void FIELD_EFFECT_GetObjectPos(int a, Desc2 *d);
extern void FIELD_EFFECT_DeleteObject(int a);
extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);

void FLDEFF_FOOTMARK_InitTask(int a0, Res *r)
{
    Desc2 d2;
    Desc1 d1;
    Src *s = (Src *)FIELD_EFFECT_GetObjectParam(a0);

    *(Src *)r = *s;
    r->h0e = 0x1f;
    d1.a = r->head->tab[r->idx];
    d1.b = 0x1000;
    d1.c = 0x1000;
    d1.d = r->h0e;
    d1.e = 1;
    d1.f = 1;
    d2.a = 0;
    d2.b = r;
    FIELD_EFFECT_GetObjectPos(a0, &d2);
    r->h8 = BILLBOARD_ACT_CreateEntries(r->head->h4, 0, (const struct BbActDesc *)(&d1), 1, 3);
    if (r->h8 == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(a0);
    }
}
