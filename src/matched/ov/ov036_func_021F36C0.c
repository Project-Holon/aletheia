/*
 * function: DAILY_LAYOUT_Generate
 * address:  0x021F36C0
 * packet:   pkt_ov036_021F36C0
 * region:   ov036
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the four tables are `extern const`: with plain externs the d.b loop
 *           computes &d.order[n] before &d.b[i] and stores the id early. Other
 *           levers: switch arms in the order 1,2,3,4,5,6,0,default; a u8 y indexing
 *           w->ent[y] (not an Ent *); `15u` in the last loop bound.
 *
 * symbols:
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   DAILY_LAYOUT_ResetDeck  0x021F38F4  thumb  ov036
 *   DAILY_LAYOUT_DealCells  0x021F3980  thumb  ov036
 *   DAILY_LAYOUT_PickDistinct  0x021F38AC  thumb  ov036
 *   gDailyLayoutCellFlags     0x021F3AD4  data  a4
 *   gDailyLayoutMainDefs     0x021F3B4C  data  a4
 *   gDailyLayoutBonusDefs     0x021F3A98  data  a4
 *   gDailyLayoutFillerDefs     0x021F3BEC  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct {
    u8 slot[15];
    u8 order[15];
    u8 count;
    u8 max;
    u8 a[7];
    u8 b[2];
    u8 c[10];
} Deck;

typedef struct {
    int id;
    int sub;
    int a;
    int type;
    int c;
    int d;
    int e;
} Ent;

typedef struct {
    u8 pad0[6];
    u16 f6;
    u8 pad8[4];
    Ent ent[15];
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} W;

typedef struct {
    int a;
    int b;
} P8;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} P16;

typedef struct {
    int a;
    int b;
    int c;
} P12;

extern const P8 gDailyLayoutCellFlags[];
extern const P16 gDailyLayoutMainDefs[];
extern const P12 gDailyLayoutBonusDefs[];
extern const P12 gDailyLayoutFillerDefs[];

struct RtcDate;
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern void DAILY_LAYOUT_ResetDeck(unsigned char *p);
extern int DAILY_LAYOUT_DealCells(u8 *p);
extern void DAILY_LAYOUT_PickDistinct(int n, int m, u8 *buf, u8 *out);

void DAILY_LAYOUT_Generate(W *w)
{
    RTCDate date;
    Deck d;
    u8 ta[10];
    u8 tc[15];
    u8 tb[5];
    int v;
    u8 i;
    int n;
    int cnt;
    u8 s;
    u8 x;
    u8 y;

    GF_STANDARD_SetField00_F4E4((struct RtcDate *)(&date));
    switch (date.week) {
    case 1:
        v = 4;
        break;
    case 2:
        v = 3;
        break;
    case 3:
        v = 4;
        break;
    case 4:
        v = 5;
        break;
    case 5:
        v = 4;
        break;
    case 6:
        v = 6;
        break;
    case 0:
        v = 7;
        break;
    default:
        v = 0;
        break;
    }
    w->f6 = v;
    DAILY_LAYOUT_ResetDeck((unsigned char *)(&d));
    if (DAILY_LAYOUT_DealCells((u8 *)(&d)) == 0)
        DAILY_LAYOUT_ResetDeck((unsigned char *)(&d));
    DAILY_LAYOUT_PickDistinct(10, v, ta, d.a);
    DAILY_LAYOUT_PickDistinct(5, 2, tb, d.b);
    DAILY_LAYOUT_PickDistinct(15, 15 - (v + 2), tc, d.c);
    for (i = 0; i < v; i++) {
        s = d.order[i];
        if (gDailyLayoutCellFlags[s].a == 0)
            w->c0++;
        else
            w->c1++;
        if (gDailyLayoutCellFlags[s].b == 0)
            w->c2++;
        else
            w->c3++;
    }
    n = 0;
    for (i = 0; i < v; i++) {
        y = d.order[n];
        x = d.a[i];
        w->ent[y].id = x;
        w->ent[y].sub = gDailyLayoutMainDefs[x].b;
        w->ent[y].a = gDailyLayoutMainDefs[x].a;
        w->ent[y].type = 0;
        w->ent[y].c = gDailyLayoutMainDefs[x].c;
        w->ent[y].d = gDailyLayoutMainDefs[x].d;
        n++;
    }
    for (i = 0; i < 2; i++) {
        y = d.order[n];
        x = d.b[i];
        w->ent[y].id = i;
        w->ent[y].sub = 0;
        w->ent[y].a = gDailyLayoutBonusDefs[x].a;
        w->ent[y].type = 2;
        w->ent[y].c = gDailyLayoutBonusDefs[x].b;
        w->ent[y].d = gDailyLayoutBonusDefs[x].c;
        n++;
    }
    cnt = 15u - (v + 2);
    for (i = 0; i < cnt; i++) {
        y = d.order[n];
        x = d.c[i];
        w->ent[y].id = i;
        w->ent[y].sub = 0;
        w->ent[y].a = gDailyLayoutFillerDefs[x].a;
        w->ent[y].type = 1;
        w->ent[y].c = gDailyLayoutFillerDefs[x].b;
        w->ent[y].d = gDailyLayoutFillerDefs[x].c;
        n++;
    }
}
