/*
 * function: ZUKAN_DETAIL_AREA_HandleModeEvent
 * address:  0x021C1920
 * packet:   pkt_ov208_021C1920
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb  ov208
 *   func_021BDBAC  0x021BDBAC  thumb  ov208
 *   ZUKAN_DETAIL_AREA_SelectPlayerTown  0x021C0D3C  thumb  ov208
 *   ZUKAN_DETAIL_AREA_FindTownAtPoint  0x021C0D5C  thumb  ov208
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   ZUKAN_DETAIL_AREA_DrawTownName  0x021C1D30  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateTerrainIcons  0x021C2238  thumb  ov208
 *   func_021BC3BC  0x021BC3BC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode  0x021BDAAC  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb  ov208
 *   GAME_DATA_ContainsRecentId  0x02012BF8  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern void func_021BDBAC(void *s, u32 on);
extern void ZUKAN_DETAIL_AREA_SelectPlayerTown(int a, char *b, int c);
extern u8 ZUKAN_DETAIL_AREA_FindTownAtPoint(void *unused, char *p, int unused2, u8 x, u8 y);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);
extern void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, u8 *p, int key);
extern u16  func_021BC3BC(char *p);
extern void ZUKAN_DETAIL_TOUCHBAR_SetMode(void *s, u32 mode, u32 kind, u32 flag);
extern void func_021BDBA0(void *s);
extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(void *s, u32 on);
extern int ZUKAN_DETAIL_COMMON_GetSource(int *p);
extern int GAME_DATA_ContainsRecentId(int a0, int a1);
extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(char *p, int b);

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, u8 *p, int key, int mode)
{
    void *s;
    u32 wide;

    s = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    switch (W(0x6c)) {
    case 0:
        if (mode == 1) {
        } else if (mode == 3) {
            W(0x84) = 1;
        } else if (mode == 4) {
            W(0x84) = 1;
        }
        break;
    case 1:
        if (mode == 2)
            func_021BDBAC(s, 0);
        break;
    case 2:
        if (mode == 5) {
            W(0x70) = 1;
            W(0x74) = 1;
            if (W(0x90) == 1) {
                if (W(0x7c) == 0) {
                    ZUKAN_DETAIL_AREA_SelectPlayerTown((int)heap, (char *)p, key);
                } else {
                    p[0x79] = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, (char *)p, key, p[0x80], p[0x81]);
                    if (p[0x79] != 0xff)
                        CLACT_SetActorDrawEnable((struct Obj *)W(0xd0), 1);
                }
                ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
                ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
            }
            ZUKAN_DETAIL_TOUCHBAR_SetMode(s, 1, 1, func_021BC3BC((char *)key) > 1);
        }
        break;
    case 3:
        if (mode == 0) {
            if (W(0x42c) != 0) {
                W(0x430) = 1;
                if (W(0x434) != 0) {
                    W(0x42c) = 0;
                    func_021BDBA0(s);
                }
            }
            if (p[0xd8] == 7 && W(0x88) != 0)
                ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(s, 1);
        }
        break;
    case 4:
        break;
    case 5:
        if (mode == 6) {
        } else if (mode == 8) {
            W(0x84) = 1;
        }
        break;
    case 6:
        if (mode == 7)
            func_021BDBAC(s, 0);
        break;
    case 7:
        if (mode == 0) {
            W(0x70) = 3;
            W(0x74) = 3;
            CLACT_SetActorDrawEnable((struct Obj *)W(0xcc), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0xd0), 0);
            wide = func_021BC3BC((char *)key) > 1 ? 1 : 0;
            ZUKAN_DETAIL_TOUCHBAR_SetMode(s, 0, 1, wide);
            ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(s, GAME_DATA_ContainsRecentId(ZUKAN_DETAIL_COMMON_GetSource((int *)key), 0x12));
        }
        break;
    case 8:
        if (mode == 5) {
            func_021BDBA0(s);
            if (p[0xd8] == 7 && W(0x88) != 0)
                ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(s, 1);
        }
        break;
    }
    W(0x6c) = mode;
}
