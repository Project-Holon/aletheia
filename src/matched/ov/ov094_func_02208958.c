/*
 * unit:     yes
 * function: BTLV_GAUGE_GetSlotHealthInfo, BTLV_GAUGE_RequestStop
 * address:  0x02208958
 * packet:   pkt_ov094_02208958
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202D034  0x0202D034  thumb
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 */
typedef unsigned int u32;

typedef struct {
    int f00;                /* 0x40 in the work area */
    int h04;                /* 0x44 */
    int h08;                /* 0x48 */
    char pad0c[0x14 - 0x0c];
    int h14;                /* 0x54 */
    char pad18[0x40 - 0x18];
    int state;              /* 0x80 */
    char pad44[0x48 - 0x44];
    int f48;                /* 0x88 */
    int f4c;                /* 0x8c */
    char pad50[0x70 - 0x50];
    struct {
        u32 lo : 3;
        u32 b3 : 1;
        u32 mid : 16;
        u32 b20 : 1;
        u32 hi : 9;
        u32 b30 : 1;
        u32 b31 : 1;
    } flags;                /* 0xb0 */
    char pad74[0x80 - 0x74];
} Row;

typedef struct {
    char pad00[0x40];
    Row r[8];               /* 0x40 */
    struct {
        u32 lo : 4;
        u32 b4 : 1;
        u32 mid : 16;
        u32 b21 : 1;
        u32 b22 : 1;
        u32 hi : 9;
    } flags;                /* 0x440 */
} W;

extern int func_0202D034(u32 a, u32 b);
typedef unsigned short u16;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);

int BTLV_GAUGE_GetSlotHealthInfo(W *w, int i, int *o1, int *o2)
{
    if (w->r[i].f00 == 0 || !w->r[i].flags.b3 || w->r[i].flags.b30) {
        *o1 = 0;
        *o2 = 8;
        return 0;
    }
    *o1 = func_0202D034(w->r[i].f48, w->r[i].f4c);
    *o2 = CLACT_GetActorAnimSeq((struct Obj *)w->r[i].h14);
    if (*o2 == 0)
        *o2 = 8;
    return 1;
}

void BTLV_GAUGE_RequestStop(W *w)
{
    w->flags.b22 = 1;
}
