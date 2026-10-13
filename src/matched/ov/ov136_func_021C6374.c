/*
 * function: func_021C6374
 * address: 0x021C6374
 * packet: pkt_ov136_021C6374
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): byte-correct; only PMSI_PARAM_IsEnabled lacks a witness. Witness filed as
 *   src/matched/arm9/PMSI_PARAM_IsEnabled.c (EXACT). Re-verify after its shard exists, then file EXACT.
 * symbols:
 *   func_02008FC8 0x02008FC8 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02008FC0 0x02008FC0 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02008F84 0x02008F84 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   func_021C5F80 0x021C5F80 thumb
 */
#include "../include/Obj00627.h"
#include "../include/Obj23579.h"
#include "../include/Obj23580.h"
#include "../include/Obj23581.h"
#include "../include/Obj23582.h"
#include "../include/Obj23583.h"
#include "../include/Obj23584.h"
#include "../include/Obj23585.h"
#include "../include/Obj23586.h"
#include "../include/Obj23587.h"
#include "../include/Obj23588.h"
#include "../include/Obj23589.h"
#include "../include/Obj23590.h"
#include "../include/Obj23591.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Sub02008F80Entry;
struct Sub02008F80Obj;
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void PMS_DRAW_Print(void *, void *, void *, u8);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 layer);
extern u16 func_02008FC0(const struct Sub02008F80Obj *obj);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u8 *func_02008F84(struct Sub02008F80Obj *obj);
struct Strbuf;
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void func_021C5F80(void *unused, void *text, u8 *slot, void *owner, int x, int y, u32 mode, u16 color, int align);

void func_021C6374(u8 *p)
{
    u32 i;
    void *mon;
    void *w;

    for (i = 0; i < 3; i++) {
        mon = func_02008FC8(*(void **)(*(u8 * *)&((struct Obj00627 *)p)->f8 + p[0x1F] * 4 + 0x298), (u8)i);
        if (PMSI_PARAM_IsEnabled(mon)) {
            PMS_DRAW_Print(((struct Obj23579 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f35C, *(void **)(*(u8 * *)&((struct Obj00627 *)p)->f8 + i * 4 + 0xB0), mon, (u8)i);
            w = *(void **)(*(u8 * *)&((struct Obj00627 *)p)->f8 + i * 4 + 0xB0);
            BMP_WIN_TransferChars(w);
            BMP_WIN_MakeScreen(w);
            func_02041B6C(BMP_WIN_GetBgLayer(w));
        }
    }
    ((struct Obj23580 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f360 = 6;
    ((struct Obj23581 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f362 = 0;
    ((struct Obj23582 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f364 = func_02008FC0(*(void **)(*(u8 * *)&((struct Obj00627 *)p)->f8 + p[0x1F] * 4 + 0x298));
    if (((struct Obj23583 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f364 != 0) {
        PMS_DRAW_Print(((struct Obj23584 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f35C, ((struct Obj23585 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->fBC, *(u8 * *)&((struct Obj00627 *)p)->f8 + 0x360, 3);
    }
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj23586 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->fC0), 0);
    STRBUF_SetString(((struct Obj23587 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f1D8, (const u16 *)func_02008F84(*(void **)(*(u8 * *)&((struct Obj00627 *)p)->f8 + p[0x1F] * 4 + 0x298)));
    func_021C5F80(((struct Obj23588 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->fC0, ((struct Obj23589 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f1D8, *(u8 * *)&((struct Obj00627 *)p)->f8 + 0x1BC,
                  ((struct Obj23590 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->f1C4, 0, 2, ((struct Obj00627 *)p)->f18, 0x440, 0);
    w = ((struct Obj23591 *)(*(u8 * *)&((struct Obj00627 *)p)->f8))->fC0;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_02041B6C(BMP_WIN_GetBgLayer(w));
}
