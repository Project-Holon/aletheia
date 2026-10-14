/*
 * function: BTLV_EFFVM_SeModulationTaskMain
 * address:  0x021FE6A4
 * packet:   pkt_ov094_021FE6A4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_EFFECT_RegisterTask  0x021F896C  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 *   BTLV_EFFVM_StartSeVolumeTweenTask  0x021FE410  thumb  ov094
 *   BTLV_EFFVM_FindFreeSeSlot  0x021FE4D0  thumb  ov094
 *   BTLV_EFFVM_WaitVoiceTaskMain  0x021FE8D8  thumb  ov094
 *   BTLV_MCSS_PlayCry  0x02200218  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094
 */
#include "../include/Obj21693.h"
typedef unsigned short u16;

typedef struct {
    unsigned int f0 : 10;
    unsigned int f10 : 1;
} Flags;
typedef struct {
    Flags fl;
    char pad04[4];
    int h;
} Obj;
typedef struct {
    Obj *obj;
    int a1, a2, a3;
    int a4, a5, a6;
    int cnt;
} Req;

extern char d_0220AE68[];
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_EFFVM_FindFreeSeSlot(char *p);
extern int BTLV_MCSS_PlayCry(char *w, int a, int b, int c, int d, int e, int f);
extern void BTLV_EFFVM_StartSeVolumeTweenTask(Obj *o, int a, int b, int n);
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02030DA8(int owner, void *fn, void *arg, int n);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_EFFECT_DeleteTask(void *h);
extern void BTLV_EFFVM_WaitVoiceTaskMain(void *h, Obj **pp);

void BTLV_EFFVM_SeModulationTaskMain(void *h, Req *r)
{
    int slot;
    Obj **cell;

    r->cnt--;
    if (r->cnt != 0)
        return;
    slot = BTLV_EFFVM_FindFreeSeSlot((char *)r->obj);
    *(int *)((char *)r->obj + 0x26c + slot * 4) =
        BTLV_MCSS_PlayCry((char *)BTLV_EFFECT_GetMcss(), r->a1, r->a2, r->a3, r->a4, r->a5, r->a6);
    BTLV_EFFVM_StartSeVolumeTweenTask(r->obj, 0x7f000, 0x6b000, 10);
    if (!r->obj->fl.f10) {
        cell = func_02030734((u16)(((u16)((struct Obj21693 *)((char *)r->obj))->f238 & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x1e6d);
        *cell = r->obj;
        BTLV_EFFECT_RegisterTask((void *)func_02030DA8(r->obj->h, (void *)BTLV_EFFVM_WaitVoiceTaskMain, cell, 0), 0, 0);
    }
    BTLV_EFFECT_DeleteTask(h);
}
