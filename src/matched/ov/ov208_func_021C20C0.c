/*
 * function: ZUKAN_DETAIL_AREA_DrawNoDataMessage
 * address:  0x021C20C0
 * packet:   pkt_ov208_021C20C0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   sub_0201D304  0x0201D304  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible  0x021C0CC0  thumb  ov208
 *   func_021C0C8C  0x021C0C8C  thumb  ov208
 */
#include "../include/Obj00081.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Bmp;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
struct MsgBank;
struct StrObj;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021C0740(void *a0, u8 *st, void *a2, u8 i);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);
extern int ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(void *a0, u8 *st, void *a2);
extern void func_021C0C8C(void *a0, u8 *st, void *a2, int on);

void ZUKAN_DETAIL_AREA_DrawNoDataMessage(void *a0, u8 *st, void *a2)
{
    int res = CLACT_GetActorDrawEnable((struct Obj *)(*(int *)&((struct Obj00081 *)st)->fC8));

    if (((struct Obj00081 *)st)->f90 == 0) {
        if (res == 0) {
            void *msg;
            u32 w;
            int d;
            int h;
            u32 t;

            msg = func_02045EC0(((struct Obj00081 *)st)->fC, 0x80);
            w = (u16)sub_0201D304(msg, ((struct Obj00081 *)st)->f4, 0);
            h = BMP_GetWidth((const struct Bmp *)((u32)BMP_WIN_GetBmp(((struct Obj00081 *)st)->f20)));
            t = (u32)BMP_WIN_GetBmp(((struct Obj00081 *)st)->f20);
            d = h - w;
            PRINTSYS_PrintQueColor(((struct Obj00081 *)st)->f40, t, (s16)(u16)(d / 2), 1, (u32)msg, ((struct Obj00081 *)st)->f4, 0x3c40);
            STRBUF_Delete(msg);
            ((struct Obj00081 *)st)->f30 = 1;
            func_021C0740(a0, st, a2, 3);
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00081 *)st)->fC8, 1);
        }
    } else {
        u8 i;
        u8 v;
        u8 *tbl;

        v = ((struct Obj00081 *)st)->f8C == 0 ? 0 : st[0x78];
        for (i = 0; i < 0x3d; i++) {
            tbl = *(u8 * *)&((struct Obj00081 *)st)->f94;
            if (tbl[v * 0x3e + st[0x3cc + i] + 2] != 0 && *(u32 *)(st + 0x1e0 + i * 8) != 1) {
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(st + 0xdc + i * 4), 1);
            }
        }
        if (ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(a0, st, a2) == 0) {
            func_021C0C8C(a0, st, a2, 1);
        }
    }
}
