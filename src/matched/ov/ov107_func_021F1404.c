/*
 * function: func_021F1404
 * address: 0x021F1404
 * packet: pkt_ov107_021F1404
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave P8 W4): 0x15 in the pool is an overlay id (ov021_id, passed to func_02034AC4). The sixth parameter is copied to an int local g first (stored to f8, later passed to func_02028590); without the local the copy is propagated and the frame is 4 bytes short. EXACT in c99 and c.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02028590 0x02028590 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   TALKMSGWIN_Create 0x02194670 thumb ov021
 *   d_021F6E38 0x021F6E38 data a4
 *   ov021_id 0x00000015 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
struct R;
struct Work {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 pad_4[4];
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u8 pad_28[8];
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3C;
    u32 f40;
    u32 f44;
    u8 pad_48[8];
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5C;
};
struct Arg {
    u16 h;
    u32 z;
    u32 f8;
    u16 c;
    u32 n;
    u8 a;
    u8 b;
};
extern const char d_021F6E38[];
extern u8 ov021_id[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void GF_FONT_SetDefaultTextColor(void);
struct Tcbl;
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern unsigned func_02028590(int, int, int, unsigned);
extern int func_02034AC4(int);
extern void *TALKMSGWIN_Create(u16 *a);

struct Work *func_021F1404(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    struct Work *w;
    struct Arg t;
    int g;

    w = (struct Work *)func_02030734(heap, 0x60, 1, d_021F6E38, 0x66);
    w->f0 = heap;
    w->f2 = a;
    w->f3 = b;
    g = e;
    w->f8 = g;
    w->f10 = 0;
    w->f14 = (u32)GF_FONT_Create(0x17, 0, 0, 0, w->f0);
    w->f1C = (u32)func_02045B38(0, 2, (u16)c, w->f0);
    func_0201F5BC(a, 1, 0xD, 0, w->f0);
    if (a < 4)
        func_02049B40(0x17, 5, 0, 0x1C0, 0x20, w->f0);
    else
        func_02049B40(0x17, 5, 4, 0x1C0, 0x20, w->f0);
    GF_FONT_SetDefaultTextColor();
    w->fC = (u32)TCBL_Create(w->f0, w->f0, 3, 0x100);
    w->f18 = 0;
    w->f20 = 0;
    w->f24 = 0;
    w->f30 = PRINTSYS_QUE_Create((void *)w->f0);
    w->f40 = (u32)APP_TASKMENU_RES_Create(w->f3, 10, w->f14, w->f30, w->f0);
    w->f3C = 0;
    w->f50 = 0;
    w->f44 = func_02028590(0xF, g, 1, w->f0);
    func_02034AC4((int)ov021_id);
    if (d == 1) {
        t.h = heap;
        t.z = 0;
        t.f8 = w->f14;
        t.c = 10;
        t.n = a;
        t.a = 12;
        t.b = 14;
        w->f54 = (u32)TALKMSGWIN_Create(&t.h);
    } else {
        w->f54 = 0;
    }
    w->f34 = 0;
    w->f38 = 0;
    w->f58 = 0;
    w->f5C = 0;
    return w;
}
