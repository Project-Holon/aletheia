/*
 * function: YESNO_MENU_Update
 * address:  0x021B7378
 * packet:   pkt_ov067_021B7378
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The handed 848-byte extent also holds the unlabelled leaf 0x021B76B0
 * after the pool (filed separately).
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   UI_SetInputMode  0x020355D8  arm
 *   func_020355C4  0x020355C4  arm
 *   YESNO_MENU_GetButtonPos  0x021B76C8  thumb  ov067
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   d_021B94C4     0x021B94C4  data  a1
 *   TOUCHPANEL_HitPoint  0x02035D40  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   d_021B94D0     0x021B94D0  data  a2
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   YESNO_MENU_CopyPalette  0x021B7718  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 v[12]; } Rect12;

struct Step {
    u16 frame;
    u16 idx;
};

typedef struct S {
    u8 pad00[0x0c];
    int fc;
    u32 f10;
    u8 pad14[0x16 - 0x14];
    u8 f16;
    u8 f17;
    u8 pad18[0x1c - 0x18];
    u32 f1c;
    u8 pad20[0x22 - 0x20];
    u16 f22[1][16];
    u8 pad42[0x88 - 0x42];
    void *f88;
    void *f8c;
    int f90;
    int f94;
    u32 f98;
    int f9c;
    void *fa0[4];
    u8 padb0[0xc0 - 0xb0];
    int fc0;
    u8 fc4;
    u8 padc5;
    u16 fc6;
    u16 fc8;
} S;

extern const Rect12 d_021B94C4;
extern const struct Step d_021B94D0[10];

extern u32 KEY_GetTrg(void);
struct Cfg;
struct Descriptor;
struct Obj;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void UI_SetInputMode(u8 v);
extern u8 func_020355C4(void);
extern u8 YESNO_MENU_GetButtonPos(u32 a, u32 b, u32 c);
struct Ctx;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void YESNO_MENU_CopyPalette(int which, int idx, void *data);

void YESNO_MENU_Update(S *p)
{
    Rect12 rect;
    u32 x;
    u32 y;
    u16 pt[2];
    int update;
    int touch;
    int handled;
    u32 keys;
    int changed;
    u8 i;
    void *o;

    update = 0;
    keys = KEY_GetTrg();
    touch = TOUCHPANEL_GetPointTrg(&x, &y);
    switch (p->f98) {
    case 0:
        break;
    case 1:
        p->f98 = 2;
        break;
    case 2:
        handled = 0;
        if (keys & 2) {
            GFL_USE_PlaySeDefaultVolume(0x552);
            p->f9c = 0;
            handled = 1;
            UI_SetInputMode(0);
        }
        if (!handled && func_020355C4() == 0 && keys != 0) {
            changed = 0;
            if (keys & 1) {
                if (p->fc0 == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x54d);
                    p->f9c = 1;
                } else {
                    GFL_USE_PlaySeDefaultVolume(0x552);
                    p->f9c = 0;
                }
                handled = 1;
            } else if (keys & 0x40) {
                if (p->fc0 != 0) {
                    p->fc0 = 0;
                    changed = 1;
                }
            } else if (keys & 0x80) {
                if (p->fc0 != 1) {
                    p->fc0 = 1;
                    changed = 1;
                }
            }
            if (changed) {
                for (i = 0; i < 4; i++) {
                    pt[0] = YESNO_MENU_GetButtonPos(p->fc0, i, 0);
                    pt[1] = YESNO_MENU_GetButtonPos(p->fc0, i, 1);
                    CLACT_AddActorSurfacePos(p->fa0[i], (const struct Vec2 *)pt, (u16)p->f1c);
                }
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        }
        if (!handled && touch != 0) {
            int res;
            rect = d_021B94C4;
            res = (int)TOUCHPANEL_HitPoint((struct Ctx *)(&rect), x, y);
            if (res != -1) {
                if (res == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x54d);
                    p->f9c = 1;
                } else if (res == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x552);
                    p->f9c = 0;
                }
                handled = 1;
                UI_SetInputMode(1);
            }
        }
        if (!handled && func_020355C4() == 1 && keys != 0) {
            for (i = 0; i < 4; i++) {
                CLACT_SetActorDrawEnable(p->fa0[i], 1);
                CLACT_SetActorAutoAnim(p->fa0[i], 1);
            }
            GFL_USE_PlaySeDefaultVolume(0x548);
            UI_SetInputMode(0);
        }
        if (handled) {
            for (i = 0; i < 4; i++) {
                CLACT_SetActorDrawEnable(p->fa0[i], 0);
                CLACT_SetActorAutoAnim(p->fa0[i], 0);
            }
            p->f98 = 3;
            p->fc4 = 0;
            p->fc8 = 1;
            p->fc6 = 1;
        }
        break;
    case 3:
        if (p->fc6 < 10) {
            if (p->fc8 == d_021B94D0[p->fc6].frame) {
                p->fc4 = d_021B94D0[p->fc6].idx;
                update = 1;
                p->fc6++;
            }
            p->fc8++;
        } else {
            p->f98 = 4;
        }
        break;
    case 4:
        break;
    }
    if (p->f98 != 0) {
        if (p->f90 == 0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)p->fc, (void *)((int)BMP_WIN_GetBmp(p->f88))) == 0) {
            o = p->f88;
            BMP_WIN_TransferChars(o);
            BMP_WIN_MakeScreen(o);
            func_02041B6C(BMP_WIN_GetBgLayer(o));
            p->f90 = 1;
        }
        if (p->f94 == 0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)p->fc, (void *)((int)BMP_WIN_GetBmp(p->f8c))) == 0) {
            o = p->f8c;
            BMP_WIN_TransferChars(o);
            BMP_WIN_MakeScreen(o);
            func_02041B6C(BMP_WIN_GetBgLayer(o));
            p->f94 = 1;
        }
    }
    if (update) {
        YESNO_MENU_CopyPalette((u32)p->f10, (u8)(p->f9c == 1 ? p->f16 : p->f17), p->f22[p->fc4]);
    }
}
