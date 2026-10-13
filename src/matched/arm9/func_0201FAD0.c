/*
 * function: BMP_MENU_MoveCursor
 * address:  0x0201FAD0
 * packet:   pkt_0201FA04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_MENU_StepSelection  0x0201FB30  thumb
 *   BMP_MENU_GetItemPixelPos  0x0201FD54  thumb
 *   BMP_MENU_DrawCursor  0x0201FD18  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_020061E4  0x020061E4  thumb
 *
 * Commit a cursor move: remember where the cursor was, ask BMP_MENU_StepSelection to
 * step it, and on a refusal answer 0 without side effects.  On a move, redraw
 * from the old cell through BMP_MENU_GetItemPixelPos into an on-stack pair, repaint at
 * the new position with func_02043AF4 and play the sound id the caller passed
 * in r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_MoveCursor.c \
 *       --func BMP_MENU_MoveCursor --addr 0x0201FAD0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Obj {
    u32 f00;
    u32 f04;
    u8  pad_08[0x25];
    u8  f2D;
    u8  pad_2E[3];
    u8  f31;
    u8  f32;
};

extern int  BMP_MENU_StepSelection(struct Obj *o, u32 dir);
extern void BMP_MENU_GetItemPixelPos(struct Obj *o, u8 *outA, u8 *outB, u32 old);
extern void BMP_MENU_DrawCursor(struct Obj *o);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Bmp;
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_020061E4(u32 id);

int BMP_MENU_MoveCursor(struct Obj *o, u32 dir, u32 sound)
{
    u8 cell[2];
    u8 old;

    old = o->f2D;
    if (BMP_MENU_StepSelection(o, dir) == 0) {
        return 0;
    }

    BMP_MENU_GetItemPixelPos(o, &cell[1], &cell[0], old);
    func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)o->f04)), cell[1], cell[0], o->f31,
                  o->f32, 0xff);
    BMP_MENU_DrawCursor(o);
    func_020061E4(sound);
    return 1;
}
