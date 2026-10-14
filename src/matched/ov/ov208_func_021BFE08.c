/*
 * function: ZUKAN_DETAIL_AREA_HandleKeyEvent
 * address:  0x021BFE08
 * packet:   pkt_ov208_021BFE08
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies  0x021BC3CC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies  0x021BC40C  thumb  ov208
 *   ZUKAN_DETAIL_AREA_LoadAreaEntries  0x021C1AD4  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay  0x021C1D0C  thumb  ov208
 *   ZUKAN_DETAIL_AREA_HandleModeEvent  0x021C1920  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive  0x021BDC2C  thumb  ov208
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct S {
    u8 pad0[0x424];
    u32 f424;
    u32 f428;
    u32 f42c;
    u32 f430;
    u32 f434;
};

extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern u16 ZUKAN_DETAIL_COMMON_GetCurrentEntry(void *p);
extern void ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(char *p);
struct Ov208Cur;
extern void ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(struct Ov208Cur *p);
extern void ZUKAN_DETAIL_AREA_LoadAreaEntries(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(int a, int b, int c);
extern void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, u8 *p, int key, int mode);
extern void func_021BDBA0(int p);
extern int ZUKAN_DETAIL_COMMON_GetSource(int *p);
extern int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);

void ZUKAN_DETAIL_AREA_HandleKeyEvent(void *a0, void *a1, void *heap, struct S *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = ZUKAN_DETAIL_COMMON_GetWorkPtr(obj);
    flag = 0;
    switch (key) {
    case 16: case 19:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 17: case 18: case 20:
        st->f428 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 8: case 9: case 19:
        flag = 1;
        st->f428 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies((char *)obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_AREA_LoadAreaEntries(heap, (u8 *)st, (int)obj);
            ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay((int)heap, (int)st, (int)obj);
            st->f42c = 1;
            st->f430 = 0;
            st->f434 = 0;
        } else {
            st->f42c = 1;
            st->f430 = 1;
            st->f434 = 0;
        }
        break;
    }
    case 13: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies((struct Ov208Cur *)obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_AREA_LoadAreaEntries(heap, (u8 *)st, (int)obj);
            ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay((int)heap, (int)st, (int)obj);
            st->f42c = 1;
            st->f430 = 0;
            st->f434 = 0;
        } else {
            st->f42c = 1;
            st->f430 = 1;
            st->f434 = 0;
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f424 = 2;
        return;
    case 6: case 8: case 9:
        st->f424 = 1;
        return;
    case 3:
        if (st->f42c != 0) {
            st->f434 = 1;
            if (st->f430 != 0) {
                st->f42c = 0;
                func_021BDBA0(sc);
                return;
            }
        }
        break;
    case 4:
        if (st->f42c != 0) {
            st->f434 = 1;
            if (st->f430 != 0) {
                st->f42c = 0;
                func_021BDBA0(sc);
                return;
            }
        }
        break;
    case 5:
        GAME_DATA_SetSaveFlag((void *)ZUKAN_DETAIL_COMMON_GetSource(obj), 0x12, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive((char *)sc));
        func_021BDBA0(sc);
        return;
    case 19:
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, (u8 *)st, (int)obj, 6);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0(sc);
        }
        break;
    }
}
