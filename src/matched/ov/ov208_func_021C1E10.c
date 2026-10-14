/*
 * function: ZUKAN_DETAIL_AREA_SwitchAreaSet
 * address:  0x021C1E10
 * packet:   pkt_ov208_021C1E10
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb  ov208
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   ZUKAN_DETAIL_AREA_DrawAreaSetTitle  0x021C1F50  thumb  ov208
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb  ov208
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown  0x021C0CCC  thumb  ov208
 *   ZUKAN_DETAIL_AREA_DrawTownName  0x021C1D30  thumb  ov208
 *   ZUKAN_DETAIL_AREA_BeginModeTransition  0x021C1FC4  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateTerrainIcons  0x021C2238  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry;

struct Obj;
struct PrintSys;
extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void ZUKAN_DETAIL_AREA_DrawAreaSetTitle(u16 *heap, u8 *p, int key);
extern void CLACT_SetActorAnimSeq(u32 obj, u32 anim);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 v);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(void *s, u32 on);
extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);
extern void ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_BeginModeTransition(void *a, char *b, int c);
extern void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))
#define OBJ(i) (((u32 *)(p + 0xbc))[i])

void ZUKAN_DETAIL_AREA_SwitchAreaSet(u16 *heap, u8 *p, int key, int dir, int touch)
{
    void *s;
    int other;
    u32 anim;

    s = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    if (W(0x8c) == 0)
        W(0x90) = ((Entry *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry *)W(0x94))[p[0x78]].f1 == 0;
    W(0x2c) = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)W(0x3c));
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)W(0x1c)), 0);
    ZUKAN_DETAIL_AREA_DrawAreaSetTitle(heap, p, key);
    if (dir) {
        p[0xd8] = 2;
        anim = 3;
        other = 1;
    } else {
        p[0xd8] = 1;
        anim = 5;
        other = 2;
    }
    CLACT_SetActorAnimSeq(OBJ(p[0xd8]), anim);
    CLACT_SetActorAutoAnim((struct Obj *)OBJ(other), 0);
    CLACT_SetActorAnimFrame((struct Obj *)OBJ(other), 0);
    ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(s, 0);
    if (touch == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)W(0xcc), 0);
    } else if (W(0x6c) == 5 && W(0x90) == 1) {
        ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(heap, p, key);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
    }
    ZUKAN_DETAIL_AREA_BeginModeTransition(heap, (char *)p, key);
    ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
}
