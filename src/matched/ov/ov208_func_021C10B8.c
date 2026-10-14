/*
 * function: ZUKAN_DETAIL_AREA_HandleCursorInput
 * address:  0x021C10B8
 * packet:   pkt_ov208_021C10B8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb  ov208
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb  ov208
 *   ZUKAN_DETAIL_AREA_SwitchAreaSet  0x021C1E10  thumb  ov208
 *   ZUKAN_DETAIL_AREA_HandleModeEvent  0x021C1920  thumb  ov208
 *   ZUKAN_DETAIL_AREA_HandleTownTouchInput  0x021C1450  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern u32  KEY_GetTrg(void);
extern unsigned int KEY_GetRepeat(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_020355D8(u8 v);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(void *s, u32 on);
extern void ZUKAN_DETAIL_AREA_SwitchAreaSet(u16 *heap, u8 *p, int key, int dir, int touch);
extern void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, u8 *p, int key, int mode);
extern void ZUKAN_DETAIL_AREA_HandleTownTouchInput(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_AREA_HandleCursorInput(u16 *heap, u8 *p, int key)
{
    void *s;
    int hit, touch;
    int moved, done;
    u32 x, y, tx, ty;

    s = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    if (W(0x428) == 0 || p[0xd8] != 7)
        return;

    switch (W(0x6c)) {
    case 0:
        hit = 0;
        touch = 0;
        if (KEY_GetTrg() & 1) {
            touch = 1;
            hit = 1;
        } else if (W(0x8c) != 0) {
            if (KEY_GetRepeat() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                hit = 1;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
            } else if (KEY_GetRepeat() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
                hit = 1;
            }
        }
        if (hit) {
            func_020355D8(0);
            if (touch)
                W(0x7c) = 0;
        }
        if (hit == 0) {
            if (TOUCHPANEL_GetPointTrg(&x, &y)) {
                if (W(0x8c) == 0) {
                    if (y < 0xa8) {
                        touch = 1;
                        hit = 1;
                    }
                } else if (x >= 0x88 && x < 0xa0 && y < 0x10) {
                    p[0x78]++;
                    if (p[0x78] >= 4)
                        p[0x78] = 0;
                    hit = 1;
                    ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, hit);
                    GFL_USE_PlaySeDefaultVolume(0x54a);
                } else if (x < 0x18 && y < 0x10) {
                    if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                    hit = 1;
                    ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, hit);
                    GFL_USE_PlaySeDefaultVolume(0x54a);
                } else if ((x >= 0xa0 || y >= 0x18) && y < 0xa8) {
                    touch = 1;
                    hit = 1;
                }
            }
            if (hit) {
                hit = 1;
                func_020355D8(1);
                if (touch) {
                    W(0x7c) = hit;
                    p[0x80] = x;
                    p[0x81] = y;
                }
            }
        }
        if (touch && (W(0x8c) != 0 || W(0x90) != 0)) {
            ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(s, 0);
        }
        break;
    case 5:
        moved = 0;
        done = 1;
        if (KEY_GetTrg() & 2) {
            W(0x428) = 0;
            moved = 1;
            done = 0;
        } else if (W(0x8c) != 0) {
            if (KEY_GetRepeat() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                done = 0;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, done);
                moved = 1;
                GFL_USE_PlaySeDefaultVolume(0x54a);
            } else if (KEY_GetRepeat() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                done = 0;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
                moved = 1;
            }
        }
        if (moved)
            func_020355D8(0);
        if (moved == 0) {
            if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
                if (W(0x8c) == 0) {
                    if (ty >= 0xa8)
                        done = 0;
                } else if (W(0x8c) == 1) {
                    if (tx >= 0x88 && tx < 0xa0 && ty < 0x10) {
                        p[0x78]++;
                        if (p[0x78] >= 4)
                            p[0x78] = 0;
                        moved = 1;
                        ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, moved);
                        GFL_USE_PlaySeDefaultVolume(0x54a);
                        done = 0;
                    } else if (tx < 0x18 && ty < 0x10) {
                        if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                        moved = 1;
                        ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, moved);
                        done = 0;
                        GFL_USE_PlaySeDefaultVolume(0x54a);
                    } else if (tx < 0xa0 && ty < 0x18) {
                        done = 0;
                    } else if (ty >= 0xa8) {
                        done = 0;
                    }
                }
            }
            if (moved)
                func_020355D8(1);
        }
        if (done)
            ZUKAN_DETAIL_AREA_HandleTownTouchInput(heap, p, key);
        break;
    }
}
