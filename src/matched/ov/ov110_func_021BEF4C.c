/*
 * function: PMS_INPUT_HitWordList
 * address: 0x021BEF4C
 * packet: pkt_ov110_021BEF4C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: BAD14 retains r1 explicitly loaded at EF4C+68/+86 despite its unused input.
 * symbols:
 *   gPmsInputWordCellTemplate 0x021C39A8 data a1
 *   gPmsInputWordListButtonHits 0x021C3900 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_HitPoint 0x02035D40 arm
 *   PMS_INPUT_VIEW_CompareWordwinPosition 0x021BACDC thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_SetWordwinScrollOffset 0x021BAD14 thumb ov110
 *   PMS_WORDLIST_JumpUp 0x021BF3A0 thumb ov110
 *   PMS_WORDLIST_JumpDown 0x021BF3D4 thumb ov110
 */
#include "../include/Obj00493.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Box { u8 b[8]; };
struct Ctx;
extern const struct Box gPmsInputWordCellTemplate;
extern const struct Box gPmsInputWordListButtonHits[];
extern int TOUCHPANEL_HitTrg(const void *p);
extern u32 TOUCHPANEL_GetPointTrg(u32 *, u32 *);
extern u32 TOUCHPANEL_HitPoint(struct Ctx *, u32, u32);
extern int PMS_INPUT_VIEW_CompareWordwinPosition(u8 *p, int unused, unsigned n);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_VIEW_SetWordwinScrollOffset(u8 *, u32);
extern int PMS_WORDLIST_JumpUp(u8 *, u8 *);
extern int PMS_WORDLIST_JumpDown(u8 *, u8 *);
int PMS_INPUT_HitWordList(u8 *p)
{
    u32 x, y;
    struct Box box = gPmsInputWordCellTemplate;
    int outer, inner, stop;
    u16 index;
    if (TOUCHPANEL_HitTrg(gPmsInputWordListButtonHits) == 0) {
        TOUCHPANEL_GetPointTrg(&x, &y);
        switch (PMS_INPUT_VIEW_CompareWordwinPosition(*(u8 * *)&((struct Obj00493 *)p)->f14, x, y)) {
        case 0:
            p[106] = 1;
            GFL_USE_PlaySeDefaultVolume(1352);
            return 0;
        case 1:
            p[106] = 1;
            PMS_INPUT_VIEW_SetWordwinScrollOffset(*(u8 * *)&((struct Obj00493 *)p)->f14, y);
            return PMS_WORDLIST_JumpUp(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84);
        case 2:
            p[106] = 1;
            PMS_INPUT_VIEW_SetWordwinScrollOffset(*(u8 * *)&((struct Obj00493 *)p)->f14, y);
            return PMS_WORDLIST_JumpDown(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84);
        case 3:
            break;
        }
    }
    TOUCHPANEL_GetPointTrg(&x, &y);
    index = ((struct Obj00493 *)p)->f54 * 2;
    stop = 0;
    for (outer = 0; outer < 6; outer++) {
        box.b[0] = 24 * outer + 13;
        box.b[1] = box.b[0] + 22;
        for (inner = 0; inner < 2; inner++) {
            box.b[2] = 112 * inner + 16;
            box.b[3] = box.b[2] + 102;
            if (TOUCHPANEL_HitPoint((struct Ctx *)&box, x, y) != (u32)-1) {
                ((struct Obj00493 *)p)->f62 = index;
                p[90] = inner;
                p[91] = outer;
                return 5;
            }
            index++;
            if (index >= ((struct Obj00493 *)p)->f58 - 2) {
                stop = 1;
                break;
            }
        }
        if (stop) break;
    }
    return 0;
}
