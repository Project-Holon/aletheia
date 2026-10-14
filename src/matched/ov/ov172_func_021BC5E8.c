/*
 * function: func_021BC5E8
 * address:  0x021BC5E8
 * packet:   pkt_ov172_021BC5E8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   COMM_TVT_SYS_GetComm  0x021BDFE4  thumb  ov172
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_021BCEF8  0x021BCEF8  thumb  ov172
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   APP_TASKMENU_WIN_IsTouch  0x0202824C  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   d_021C7040     0x021C7040  data
 *
 * Touch handling for the selection list: a tap on a row toggles the entry (a kind 0x20 entry takes the single special slot +3, any other entry one of the three slots +0..+2) and refreshes the prompt; a tap on the scroll thumb grabs it, dragging moves it and scrolls the list; then polls the prompt's buttons and the exit rectangle.
 */
#include "../include/Obj00330.h"
#include "../include/Obj01950.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;

struct SpritePos {
    s16 x;
    s16 y;
};

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern u32 COMM_TVT_SYS_GetComm(void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void func_021BCEF8(void *ctx, u8 *st);
struct Obj;
struct Vec2;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 APP_TASKMENU_WIN_IsTouch(void **p);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern int TOUCHPANEL_HitTrg(const void *p);
extern u32 KEY_GetTrg(void);
extern const u8 d_021C7040[];

void func_021BC5E8(void *ctx, u8 *list)
{
    u32 tx;
    u32 ty;
    u32 dx;
    u32 dy;
    struct SpritePos pos;
    int trg;
    int cont;
    s16 row;
    u8 id;
    u8 *e;
    int done;
    u8 i;
    int s;
    u32 range;

    trg = TOUCHPANEL_GetPointTrg(&tx, &ty);
    cont = TOUCHPANEL_GetPointCont(&dx, &dy);
    COMM_TVT_SYS_GetComm(ctx);
    if (trg == 1) {
        if (tx > 8 && tx < 0xe0) {
            row = (ty + ((struct Obj00330 *)list)->f4) >> 5;
            if (row >= 0 && row < 15) {
                id = *(list + row * 0x1c + 0x58);
                e = list + 0x1e4 + id * 0x24;
                done = 0;
                if (((struct Obj01950 *)e)->f0 == 1 && e[0x1f] < 4) {
                    if (e[0x18] == 0x20) {
                        if (((struct Obj01950 *)e)->f8 == 0) {
                            list[3] = id;
                            done = 1;
                            ((struct Obj01950 *)e)->f8 = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73b);
                        } else {
                            list[3] = 0xff;
                            ((struct Obj01950 *)e)->f8 = 0;
                            done = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73c);
                        }
                    } else if (list[3] == 0xff) {
                        if (((struct Obj01950 *)e)->f8 == 0) {
                            for (i = 0; i < 3; i++) {
                                if (list[i] == 0xff) {
                                    list[i] = id;
                                    break;
                                }
                            }
                            if (i < 3) {
                                done = 1;
                                ((struct Obj01950 *)e)->f8 = 1;
                                ((struct Obj01950 *)e)->f10 = 1;
                                ((struct Obj00330 *)list)->fC = 1;
                                GFL_USE_PlaySeDefaultVolume(0x73b);
                            }
                        } else {
                            for (i = 0; i < 3; i++) {
                                if (id == list[i]) {
                                    list[i] = 0xff;
                                    break;
                                }
                            }
                            ((struct Obj01950 *)e)->f8 = 0;
                            done = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73c);
                        }
                    }
                }
                if (done == 1)
                    func_021BCEF8(ctx, list);
            }
        } else if (tx >= 0xec && tx <= 0x104 && ty >= ((struct Obj00330 *)list)->f6 + 0xc
                   && ty <= ((struct Obj00330 *)list)->f6 + 0x24 && list[0x14] > 5) {
            ((struct Obj00330 *)list)->f10 = 1;
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f404), 0xd);
            GFL_USE_PlaySeDefaultVolume(0x66c);
        }
    }
    if (cont == 1 && ((struct Obj00330 *)list)->f10 == 1 && list[0x14] > 5) {
        if (dx >= 0xec && dx <= 0x104 && dy >= 0xc && dy <= 0x9c) {
            range = (list[0x14] - 5) * 32;
            s = dy - 0x18;
            if (s < 0)
                s = 0;
            else if (s > 0x78)
                s = 0x78;
            ((struct Obj00330 *)list)->f6 = s;
            pos.x = 0xf8;
            pos.y = ((struct Obj00330 *)list)->f6 + 0x18;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj00330 *)list)->f404), (const struct Vec2 *)(&pos), 1);
            ((struct Obj00330 *)list)->f4 = ((struct Obj00330 *)list)->f6 * range / 0x78;
            ((struct Obj00330 *)list)->fC = 1;
        }
    } else {
        ((struct Obj00330 *)list)->f10 = 0;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f404), 0xc);
    }
    if (((struct Obj00330 *)list)->f1C != 0 && APP_TASKMENU_WIN_IsTouch((void **)(((struct Obj00330 *)list)->f1C)) == 1) {
        APP_TASKMENU_WIN_SetDecide((char *)(((struct Obj00330 *)list)->f1C), 1);
        ((struct Obj00330 *)list)->f8 = 6;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (((struct Obj00330 *)list)->f18 == 1)
            GFL_USE_PlaySeInSlot((void *)0x73d, 2);
    }
    if (!TOUCHPANEL_HitTrg(d_021C7040) || (KEY_GetTrg() & 2)) {
        ((struct Obj00330 *)list)->f8 = 6;
        ((struct Obj00330 *)list)->f18 = 5;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f400), 9);
        GFL_USE_PlaySeDefaultVolume(0x551);
    }
}
