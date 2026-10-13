/*
 * function: func_021B8FE4
 * address:  0x021B8FE4
 * packet:   pkt_ov067_021B8FE4
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_GetBgFrame  0x0202CF8C  thumb
 *   func_021B8FA0  0x021B8FA0  thumb  ov067
 *   BUTTON_MAN_CallHandlerById  0x02051B0C  arm
 *   BGWINFRM_SetFrameData  0x0202CAC4  thumb
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A90  0x02082A90  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u32 f0;
    u32 f4;
};

struct S {
    u8 _0[4];
    u8 f4;
    u8 _5[0x28 - 5];
    struct Ent *f28;
    u8 _2c[0x38 - 0x2c];
    struct Ent *f38;
    void *f3c;
    u16 **f40;
};

struct WinMgr;
extern u8 BGWINFRM_GetBgFrame(struct WinMgr *mgr, u32 idx);
extern int func_021B8FA0(int x);
extern int BUTTON_MAN_CallHandlerById(int i);
extern void BGWINFRM_SetFrameData(struct WinMgr *mgr, u32 idx, const void *src);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
struct Bmp;
struct Descriptor;
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(const void *src, void *dst, u32 size);

void func_021B8FE4(struct S *s, u32 a1, u32 a2)
{
    u8 *gfx;
    int vram;
    void *res;
    u16 *map;
    u8 stride;
    u8 w;
    u8 h;
    u8 x0;
    u8 y0;
    u8 i;
    u8 j;

    res = (void *)s->f38[a2].f0;
    map = s->f40[s->f28[a1].f0];
    vram = BUTTON_MAN_CallHandlerById(func_021B8FA0(BGWINFRM_GetBgFrame(s->f3c, a2)));
    BGWINFRM_SetFrameData(s->f3c, a2, map);
    BGWINFRM_PutBmpWin(s->f3c, a2, res);
    stride = s->f4;
    w = func_02045748(res);
    h = func_02045750(res);
    x0 = func_02045758(res);
    y0 = func_02045760(res);
    gfx = func_020437D4(func_02045770(res));
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            func_02082A90((u8 *)vram + (map[x0 + j + (i + y0) * stride] & 0x3ff) * 32,
                          gfx + (j + i * w) * 32, 0x20);
        }
    }
}
