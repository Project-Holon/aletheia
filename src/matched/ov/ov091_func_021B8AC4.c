/*
 * function: POKELIST_ReadCursorKeys
 * address:  0x021B8AC4
 * packet:   pkt_ov091_021B8AC4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   POKELIST_MoveCursorToPlate  0x021B8F68  thumb  ov091
 *   PLIST_PLATE_SetSelected  0x021BAFA0  thumb  ov091
 *   PLIST_MENU_ButtonWinSetActive  0x021BBE5C  thumb  ov091
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PLIST_PLATE_IsEgg  0x021BB468  thumb  ov091
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   POKELIST_IsNotItemUseMode  0x021B9AA0  thumb  ov091
 *   POKELIST_HasBackButton  0x021B9AB4  thumb  ov091
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   PLIST_PLATE_IsOccupied  0x021BB3C4  thumb  ov091
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   d_021BEAB0     0x021BEAB0  data  a1
 *   d_021BEAAA     0x021BEAAA  data  a1
 *
 * The two byte tables resolve as sole-ref only without an overlay token
 * (with `ov091` the hint is reported contested).  The spilled locals sit
 * up @0, done @4, old @8, trg @0xc: declared trg, old, done, up.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(int *)(p + (o)))

extern u32  KEY_GetTrg(void);
extern unsigned int KEY_GetRepeat(void);
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void POKELIST_MoveCursorToPlate(u8 *p, int v);
extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
extern void PLIST_MENU_ButtonWinSetActive(int h, int f);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern int PLIST_PLATE_IsEgg(int unused, int *p);
extern int POKELIST_IsItemMode(u32 p);
extern int POKELIST_IsNotItemUseMode(u32 p);
extern int  POKELIST_HasBackButton(u8 *p);
extern u32 POKEPARTY_GetCount(void *p);
extern int PLIST_PLATE_IsOccupied(void *unused, u32 p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern const u8 d_021BEAB0[];
extern const u8 d_021BEAAA[];

void POKELIST_ReadCursorKeys(u8 *p)
{
    u32 trg;
    int old;
    int done;
    u32 up;
    u32 rep;
    int dir;
    int max;
    u8 cnt;
    int n;

    trg = KEY_GetTrg();
    rep = KEY_GetRepeat();
    if (W(8) == 1 && CLACT_GetActorDrawEnable((struct Obj *)W(0x1d8)) == 0) {
        if (trg != 0 && (trg & 0x402) == 0) {
            if (W(0x2c) <= 5) {
                POKELIST_MoveCursorToPlate(p, W(0x2c));
                PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                PLIST_MENU_ButtonWinSetActive(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                CLACT_SetActorDrawEnable((struct Obj *)W(0x1d8), 0);
            }
            GFL_USE_PlaySeDefaultVolume(0x548);
            W(8) = 0;
        }
    } else {
        dir = 0;
        if (trg != 0) {
            W(8) = 0;
        }
        up = rep & 0x40;
        if (up) {
            dir = -2;
        } else if (rep & 0x80) {
            dir = 2;
        } else if (rep & 0x20) {
            dir = -1;
        } else if (rep & 0x10) {
            dir = 1;
        } else if (trg & 1) {
            if (W(0x2c) == 6) {
                p[0xf] = 0;
            } else if (W(0x2c) == 7) {
                p[0xf] = 1;
            } else if (W(0x28) == 0 && PLIST_PLATE_IsEgg((int)p, (int *)(*(int *)(p + W(0x2c) * 4 + 0x160))) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x557);
            } else {
                p[0xf] = 3;
            }
        }
        if (dir != 0) {
            old = W(0x2c);
            done = 0;
            if (POKELIST_IsItemMode((u32)p) == 1) {
                if (POKELIST_IsNotItemUseMode((u32)p) == 1) {
                    max = 7;
                } else {
                    max = 6;
                }
            } else {
                max = 5;
            }
            if ((u32)(W(0x2c) - 6) <= 1 && (rep & 0xc0)) {
                cnt = POKEPARTY_GetCount((void *)*(int *)W(0x280));
                if (up) {
                    if (W(0x2c) == 7 || POKELIST_IsNotItemUseMode((u32)p) == 0) {
                        W(0x2c) = d_021BEAB0[cnt - 1];
                    } else {
                        W(0x2c) = d_021BEAAA[cnt - 1];
                    }
                } else {
                    if (W(0x2c) == 7 || POKELIST_IsNotItemUseMode((u32)p) == 0) {
                        if (cnt > 1) {
                            W(0x2c) = 1;
                        } else {
                            W(0x2c) = 0;
                        }
                    } else {
                        W(0x2c) = 0;
                    }
                }
            } else {
                do {
                    n = W(0x2c) + dir;
                    if (n > max) {
                        if (max == 6 && dir > 1 && old != 6) {
                            W(0x2c) = max;
                        } else {
                            W(0x2c) = n - (max + 1);
                        }
                    } else if (n < 0) {
                        if (max == 6 && dir < 1) {
                            W(0x2c) = max;
                        } else {
                            W(0x2c) = dir + (W(0x2c) + (max + 1));
                        }
                    } else {
                        W(0x2c) += dir;
                    }
                    if (W(0x2c) > 5 || PLIST_PLATE_IsOccupied(p, *(int *)(p + W(0x2c) * 4 + 0x160)) == 1) {
                        done = 1;
                    }
                } while (done == 0);
            }
            if (old != W(0x2c)) {
                if (W(0x2c) <= 5) {
                    POKELIST_MoveCursorToPlate(p, W(0x2c));
                    PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
                } else {
                    PLIST_MENU_ButtonWinSetActive(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                    CLACT_SetActorDrawEnable((struct Obj *)W(0x1d8), 0);
                }
                if (old <= 5) {
                    PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + old * 4 + 0x160)), 0);
                } else {
                    PLIST_MENU_ButtonWinSetActive(*(int *)(p + (u8)(old - 6) * 4 + 0x108), 0);
                }
                p[0x100] = 0xc;
            }
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
    if (trg & 2) {
        if (POKELIST_IsItemMode((u32)p) == 0 || POKELIST_IsNotItemUseMode((u32)p) == 1) {
            if (POKELIST_HasBackButton(p) == 1) {
                p[0xf] = 1;
                W(0x1e8) = W(0x1e0);
                CLACT_SetActorAnimSeq((struct Obj *)W(0x1e8), 9);
                W(8) = 0;
            }
        }
    } else if ((trg & 0x400) && W(0x14) == 1) {
        p[0xf] = 2;
        W(0x1e8) = W(0x1e4);
        CLACT_SetActorAnimSeq((struct Obj *)W(0x1e8), 8);
        W(8) = 0;
    }
}
