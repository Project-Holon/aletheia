/*
 * function: ZUKAN_DETAIL_VOICE_HandleKeyEvent
 * address:  0x021C2A70
 * packet:   pkt_ov208_021C2A70
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
 *   ZUKAN_DETAIL_VOICE_SwitchPokemonSlot  0x021C34A4  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive  0x021BDC2C  thumb  ov208
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct S {
    u8 pad0[0xcc];
    u32 fcc;
    u32 fd0;
};

extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern u16 ZUKAN_DETAIL_COMMON_GetCurrentEntry(void *p);
extern void ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(char *p);
struct Ov208Cur;
extern void ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(struct Ov208Cur *p);
extern void ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(u16 *heap, u8 *p, int key);
extern void func_021BDBA0(int p);
extern int ZUKAN_DETAIL_COMMON_GetSource(int *p);
extern int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);
extern void GAME_DATA_SetRecentId(void *p, u32 a, u32 b);

void ZUKAN_DETAIL_VOICE_HandleKeyEvent(void *a0, void *a1, void *heap, struct S *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = ZUKAN_DETAIL_COMMON_GetWorkPtr(obj);
    flag = 0;
    switch (key) {
    case 17:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 18:
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 9:
        flag = 1;
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies((char *)obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    case 13: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies((struct Ov208Cur *)obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->fcc = 2;
        return;
    case 6: case 7: case 9:
        st->fcc = 1;
        return;
    case 3:
        func_021BDBA0(sc);
        return;
    case 4:
        func_021BDBA0(sc);
        return;
    case 5:
        GAME_DATA_SetRecentId((void *)ZUKAN_DETAIL_COMMON_GetSource(obj), 0x13, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive((char *)sc));
        func_021BDBA0(sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0(sc);
        }
        break;
    }
}
