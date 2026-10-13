/*
 * function: SCRCMD_SYMBOL_CreateViewEvent
 * address:  0x0216AF74
 * packet:   pkt_ov010_0216AF74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020173EC  0x020173EC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E2BC  0x0200E2BC  thumb
 *   FIELD_ENCOUNT_SetFieldSituation  0x021AA304  thumb
 *   SCRCMD_SYMBOL_ViewEventMain  0x0216B004  thumb  ov010
 */
#include "../include/Obj03543.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Desc;
struct Big;

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
struct Work;
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC();
extern u32 func_020173EC(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 func_0200E2BC(void *a0, u32 *a1, void *heap, u32 mode);
extern void FIELD_ENCOUNT_SetFieldSituation();
extern int SCRCMD_SYMBOL_ViewEventMain(void *evt, u32 *state, struct Work *w);

struct Desc *SCRCMD_SYMBOL_CreateViewEvent(int a0, int a1, int a2, int a3, u16 *a4, u16 a5)
{
    void *h;
    struct Desc *r;
    u8 *p;

    h = func_020120F4((const struct Ctx *)a0);
    r = func_020122C0((void *)a0, 0, (void *)SCRCMD_SYMBOL_ViewEventMain, 0x3C);
    p = func_020124E8((struct Obj *)r);
    func_02082BCC(p, 0, 0x3C);
    ((struct Obj03543 *)p)->f0 = a1;
    *(u16 * *)&((struct Obj03543 *)p)->f28 = a4;
    ((struct Obj03543 *)p)->f24 = a5;
    ((struct Obj03543 *)p)->fC = a2;
    *(int *)&((struct Obj03543 *)p)->f20 = a3;
    ((struct Obj03543 *)p)->f2C = func_0203F1FC((const u8 *)a2, func_020173EC());
    if (func_0200E2BC(GAME_DATA_GetSaveControl(h), (u32 *)(&a3), (void *)a5, 0) == 0)
        ((struct Obj03543 *)p)->f20 = (((struct Obj03543 *)p)->f20 & 0xFFFFF800) | 0x28B;
    FIELD_ENCOUNT_SetFieldSituation(p + 0x10, h, a1);
    return r;
}
