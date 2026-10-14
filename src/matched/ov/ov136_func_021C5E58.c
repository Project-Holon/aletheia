/*
 * function: MB_SEQ_CreateWindows
 * address: 0x021C5E58
 * packet: pkt_ov136_021C5E58
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lang: c99
 * lever: 021C5EE2 branches to 021C5E9A, after the r6=r4 copy at
 *   021C5E98. The first loop stores zero ids, and a new second loop starts
 *   at zero. Literal zero plus separate loops reproduces that shared r6.
 *   The old j=i inside the loop incorrectly started loop two at 31.
 * symbols:
 *   MB_SEQ_CreateWindows 0x021C5E58 thumb ov136
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   g_7A20 0x021C7A20 data
 *   g_7A20b 0x021C7A20 data
 */
#include "../include/Obj02866.h"
#include "../include/Obj23542.h"
#include "../include/Obj23543.h"
#include "../include/Obj23544.h"
#include "../include/Obj23545.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent {
    u32 w0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 h8;
    u16 pad;
};
struct Slot {
    u32 w;
    u8 id;
    u8 pad[3];
};
extern const struct Ent g_7A20[];
extern const struct Ent g_7A20b[];
extern void BMP_WIN_Init(u16);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Tcbl;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *);
extern u32 BMP_WIN_Create(u32 bg, u32 x, u32 y, u32 w, u8 h, u8 pal, u8 base);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 v);
typedef enum { SLOT_ZERO = 0 } SlotIndex;

void MB_SEQ_CreateWindows(u8 *p)
{
    u32 i;
    u32 j;
    struct Slot *sl;
    void *t;
    BMP_WIN_Init(0x66);
    ((struct Obj02866 *)p)->f18 = GF_FONT_Create(0x17, 0, 0, 0, 0x66);
    ((struct Obj23542 *)(*(u8 * *)&((struct Obj02866 *)p)->f8))->f1CC = TCBL_Create(0x66, 0x66, 0x20, 0x20);
    ((struct Obj23543 *)(*(u8 * *)&((struct Obj02866 *)p)->f8))->f1C4 = PRINTSYS_QUE_Create((void *)0x66);
    for (i = 0; i < 0x20; i++) {
        *(u32 *)(*(u8 * *)&((struct Obj02866 *)p)->f8 + i * 4 + 0x44) = BMP_WIN_Create((u8)g_7A20[i].w0, g_7A20[i].b4, g_7A20[i].b5, g_7A20[i].b6, g_7A20[i].b7, (u8)g_7A20[i].h8, 1);
        sl = (struct Slot *)(*(u8 * *)&((struct Obj02866 *)p)->f8 + 0xC4);
        sl[i].w = *(u32 *)(*(u8 * *)&((struct Obj02866 *)p)->f8 + i * 4 + 0x44);
        sl[i].id = 0;
    }
    for (j = 0; j < 0x16; j++) {
        BMP_Clear(BMP_WIN_GetBmp(*(void **)(*(u8 * *)&((struct Obj02866 *)p)->f8 + j * 4 + 0x44)), 4);
        BMP_WIN_TransferChars(*(void **)(*(u8 * *)&((struct Obj02866 *)p)->f8 + j * 4 + 0x44));
    }
    t = ((struct Obj23544 *)(*(u8 * *)&((struct Obj02866 *)p)->f8))->f44;
    BMP_WIN_TransferChars(t);
    BMP_WIN_MakeScreen(t);
    func_020409B4(BMP_WIN_GetBgLayer(t));
    t = ((struct Obj23545 *)(*(u8 * *)&((struct Obj02866 *)p)->f8))->f48;
    BMP_WIN_TransferChars(t);
    BMP_WIN_MakeScreen(t);
    func_020409B4(BMP_WIN_GetBgLayer(t));
}
