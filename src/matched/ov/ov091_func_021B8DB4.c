/*
 * function: POKELIST_HandleTouch
 * address:  0x021B8DB4
 * packet:   pkt_ov091_021B8DB4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_PLATE_IsOccupied  0x021BB3C4  thumb  ov091
 *   PLIST_PLATE_GetTouchRect  0x021BB3FC  thumb  ov091
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   PLIST_PLATE_IsEgg  0x021BB468  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   PLIST_PLATE_SetSelected  0x021BAFA0  thumb  ov091
 *   PLIST_MENU_ButtonWinSetActive  0x021BBE5C  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   POKELIST_IsNotItemUseMode  0x021B9AA0  thumb  ov091
 *   POKELIST_HasBackButton  0x021B9AB4  thumb  ov091
 *   d_021BEC2C     0x021BEC2C  data  ov091  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} Rect;

typedef struct Rect4 {
    Rect r[4];
} Rect4;

#define W(o) (*(int *)(p + (o)))

extern int PLIST_PLATE_IsOccupied(void *unused, u32 p);
extern void PLIST_PLATE_GetTouchRect(int unused, u8 *s, u8 *out);
extern int TOUCHPANEL_HitTrg(const void *p);
extern int PLIST_PLATE_IsEgg(int unused, int *p);
extern void func_020061E4(u32 id);
extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
extern void PLIST_MENU_ButtonWinSetActive(int h, int f);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int POKELIST_IsItemMode(u32 p);
extern int POKELIST_IsNotItemUseMode(u32 p);
extern int  POKELIST_HasBackButton(u8 *p);

extern Rect4 d_021BEC2C;

void POKELIST_HandleTouch(u8 *p)
{
    Rect list[7];
    Rect4 fixed;
    u8 map[6];
    u8 i;
    u8 n;
    int hit;
    int old;
    int r;

    n = 0;
    for (i = 0; i < 6; i++) {
        if (PLIST_PLATE_IsOccupied(p, *(int *)(p + i * 4 + 0x160)) == 1) {
            map[n] = i;
            PLIST_PLATE_GetTouchRect((int)p, (u8 *)(*(int *)(p + i * 4 + 0x160)), (u8 *)(&list[n]));
            n++;
        }
    }
    list[n].top = 0xff;
    hit = TOUCHPANEL_HitTrg(list);
    if (hit != -1) {
        if (W(0x28) == 0 && hit <= 5 && PLIST_PLATE_IsEgg((int)p, (int *)(*(int *)(p + hit * 4 + 0x160))) == 1) {
            func_020061E4(0x557);
        } else {
            p[0xf] = 3;
            old = W(0x2c);
            W(0x2c) = map[hit];
            if (old <= 5) {
                PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + old * 4 + 0x160)), 0);
            } else {
                PLIST_MENU_ButtonWinSetActive(*(int *)(p + (u8)(old - 6) * 4 + 0x108), 0);
            }
            if (W(0x2c) <= 5) {
                PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                PLIST_MENU_ButtonWinSetActive(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                func_0204B3DC((struct Obj *)W(0x1d8), 0);
            }
            p[0x100] = 0xc;
        }
        W(8) = 1;
    }
    if (hit == -1) {
        fixed = d_021BEC2C;
        if (POKELIST_IsItemMode((u32)p) == 1) {
            if (POKELIST_IsNotItemUseMode((u32)p) == 1) {
                fixed.r[1].top = 0xa8;
                fixed.r[1].bottom = 0xc0;
                fixed.r[1].left = 0xb0;
                fixed.r[1].right = 0xff;
                fixed.r[0].top = 0xa8;
                fixed.r[0].bottom = 0xc0;
                fixed.r[0].left = 0x60;
                fixed.r[0].right = 0xb0;
            } else {
                fixed.r[0].top = 0xa8;
                fixed.r[0].bottom = 0xc0;
                fixed.r[0].left = 0xb0;
                fixed.r[0].right = 0xff;
            }
        } else {
            if (POKELIST_HasBackButton(p) == 1) {
                fixed.r[1].top = 0xa8;
                fixed.r[1].bottom = 0xc0;
                fixed.r[1].left = 0xe0;
                fixed.r[1].right = 0xf8;
            }
            if (W(0x14) == 1) {
                fixed.r[2].top = 0xa8;
                fixed.r[2].bottom = 0xc0;
                fixed.r[2].left = 0xc8;
                fixed.r[2].right = 0xe0;
            }
        }
        r = TOUCHPANEL_HitTrg(&fixed);
        if (r != -1) {
            p[0xf] = r;
            W(8) = 1;
        }
    }
}
