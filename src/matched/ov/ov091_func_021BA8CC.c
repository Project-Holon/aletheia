/*
 * function: PLIST_PLATE_Update
 * address:  0x021BA8CC
 * packet:   pkt_ov091_021BA8CC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   PLIST_PLATE_GetActorOffset  0x021BB56C  thumb  ov091
 *   CLACT_GetActorAnimFrame  0x0204B8F4  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 */
#include "../include/Obj20873.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    int w0;
    u16 pad4;
    u16 h6;
    int pad8[2];
    int w10;
    int w14;
    int w18;
    int pad1c;
    u32 w20;
    int pad24[3];
    int w30;
} S;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Cfg;
struct Obj;
struct PrintSys;
struct Vec2;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u32 POKE_TOOL_GetStatusCondition(void *p);
extern void PLIST_PLATE_GetActorOffset(u32 p, int x, int y, u16 *out);
extern u32 CLACT_GetActorAnimFrame(struct Obj *p);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void PLIST_PLATE_Update(u32 a, S *s)
{
    s16 buf[2];

    if (s->w14 != 0)
        return;
    if (s->w18 == 1) {
        u32 t = (u32)BMP_WIN_GetBmp((struct Descriptor *)s->w20);

        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((struct Obj20873 *)a)->f140), (void *)t) == 0) {
            a = s->w20;
            s->w18 = 0;
            BMP_WIN_TransferChars((struct Descriptor *)a);
            BMP_WIN_MakeScreen((struct Cfg *)a);
            func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)a));
        }
    }
    if (s->w10 == 1 && POKE_TOOL_GetStatusCondition((void *)s->w0) == 0 && s->h6 != 0) {
        PLIST_PLATE_GetActorOffset((u32)s, 0x1a, 0x13, (u16 *)buf);
        if (CLACT_GetActorAnimFrame((struct Obj *)s->w30) == 1)
            buf[1] = buf[1] - 6;
        CLACT_AddActorSurfacePos((struct Obj *)s->w30, (const struct Vec2 *)buf, 0);
    }
}
