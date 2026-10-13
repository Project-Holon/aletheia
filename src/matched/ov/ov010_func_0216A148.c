/*
 * function: REPORT_EVENT_OpenYesNoMenu
 * address:  0x0216A148
 * packet:   pkt_ov010_0216A148
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_OpenMenuFastDecide  0x0202784C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    void *f0C;          /* 0x0C */
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

typedef struct Desc {
    u32 heap;           /* 0x00 */
    u8 f04;             /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0C;            /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 f11;             /* 0x11 */
    u8 f12;             /* 0x12 */
    u8 f13;             /* 0x13 */
} Desc;

extern int APP_TASKMENU_OpenMenuFastDecide(int a0, int a1);

void REPORT_EVENT_OpenYesNoMenu(Work *w)
{
    Desc d;

    d.heap = w->f10;
    d.f04 = 2;
    d.f08 = &w->f18->f24;
    d.f0C = 1;
    d.f10 = 0x20;
    d.f11 = 12;
    d.f12 = 8;
    d.f13 = 3;
    w->f18->f40 = (void *)APP_TASKMENU_OpenMenuFastDecide((int)(&d), (int)w->f18->f3C);
}
