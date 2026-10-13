/*
 * function: FRAME_LIST_Create
 * address:  0x021B7754
 * packet:   pkt_ov067_021B7754
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled follower inside YESNO_MENU_CopyPalette's handed 596-byte extent: a
 * 0x9c-byte object constructor (the listing gives it no label).  The f4a
 * loop is the compound `-=`: it keeps &p->f4a in a register for the body's
 * load and store, while the test reloads through p.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gFrameListSourceFile     0x021B9574  data  ov067  a1
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   BLINK_PALANM_Create  0x0202E940  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02082A90  0x02082A90  arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Ent {
    u8 f0;
    u8 pad1[7];
};

typedef struct Tmpl {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 f9;
    u8 fa;
    u8 padb[0x11 - 0xb];
    u8 f11;
    u8 pad12[0x14 - 0x12];
    u16 f14;
    u16 f16;
    u8 pad18[0x1c - 0x18];
    struct Ent *f1c;
    u32 f20;
    u32 f24;
} Tmpl;

struct Slot {
    u32 w;
    u32 pad;
};

typedef struct S {
    Tmpl t;
    void *f28;
    u32 *f2c;
    void *f30;
    void *f34;
    struct Slot *f38;
    void *f3c;
    void **f40;
    u8 f44;
    u8 f45;
    u8 pad46[0x4a - 0x46];
    s8 f4a;
    u8 pad4b[0x54 - 0x4b];
    int f54;
    int f58;
    u8 pad5c[0x98 - 0x5c];
    u16 f98;
    u8 pad9a[2];
} S;

struct WinMgr;
extern const char gFrameListSourceFile[];

struct CodeIn;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02082A90(const void *src, void *dst, u32 size);

S *FRAME_LIST_Create(Tmpl *tmpl, u32 heap)
{
    S *p;
    u32 i;
    u32 n;

    p = func_02030734(heap, sizeof(S), 1, gFrameListSourceFile, 0xf5);
    p->t = *tmpl;
    p->f98 = heap;
    p->f54 = -1;
    p->f58 = -1;
    p->f34 = PRINTSYS_QUE_CreateEx(0x800, heap);
    p->f30 = BLINK_PALANM_Create(p->t.f11 << 4, 0x10, p->t.f0, p->f98);
    p->f28 = func_02030734(p->f98, p->t.f14 * 8, 1, gFrameListSourceFile, 0x104);
    if (p->t.f16 != 0) {
        p->f40 = func_02030734(p->f98, p->t.f16 * 4, 0, gFrameListSourceFile, 0x109);
        for (i = 0; i < p->t.f16; i++)
            p->f40[i] = func_02030734(p->f98, p->t.f4 * p->t.f5 * 2, 0, gFrameListSourceFile, 0x10b);
    }
    p->f44 = 0x18 / p->t.f5 + 2;
    p->f45 = p->f44;
    if (p->t.f1 != 0xff)
        p->f44 = p->f44 * 2;
    p->f3c = BGWINFRM_Create(2, p->f44, p->f98);
    p->f38 = func_02030734(p->f98, p->f44 * 8, 0, gFrameListSourceFile, 0x117);
    for (i = 0; i < p->f44; i++) {
        if (p->t.f1 != 0xff && p->f45 <= i) {
            BGWINFRM_AddFrame(p->f3c, i, p->t.f1, p->t.f4, p->t.f5);
            p->f38[i].w = BMP_WIN_Create(p->t.f1, p->t.f6, p->t.f7, p->t.f8, p->t.f9, p->t.fa, 1);
        } else {
            BGWINFRM_AddFrame(p->f3c, i, p->t.f0, p->t.f4, p->t.f5);
            p->f38[i].w = BMP_WIN_Create(p->t.f0, p->t.f6, p->t.f7, p->t.f8, p->t.f9, p->t.fa, 1);
        }
    }
    p->f4a = 0x18;
    do {
        p->f4a -= (s8)p->t.f5;
    } while (p->f4a > 0);
    if (p->t.f1c != 0) {
        n = 0;
        for (;;) {
            if (p->t.f1c[n].f0 == 0xff)
                break;
            n++;
        }
        p->f2c = func_02030734(p->f98, (n + 1) * 4, 0, gFrameListSourceFile, 0x13e);
        for (i = 0; i < n + 1; i++)
            func_02082A90(&p->t.f1c[i], &p->f2c[i], 4);
    }
    return p;
}
