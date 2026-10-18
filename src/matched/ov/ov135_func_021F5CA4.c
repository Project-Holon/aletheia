/*
 * function: WORLDTRADE_BOX_CheckArrowTouch
 * address:  0x021F5CA4
 * packet:   pkt_021F5CA4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
 * symbols:
 *   tbl_02202E24  0x02202E24  data  a1
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   UI_SetInputMode  0x020355D8  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0xBF4];
    u32 cursor;
} Work;

extern int TOUCHPANEL_HitTrg(const void *key);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void UI_SetInputMode(u8 v);
extern const u8 tbl_02202E24[];

int WORLDTRADE_BOX_CheckArrowTouch(Work *p)
{
    int r = TOUCHPANEL_HitTrg(tbl_02202E24);

    if (r != -1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
        UI_SetInputMode(1);
    }
    return r;
}
