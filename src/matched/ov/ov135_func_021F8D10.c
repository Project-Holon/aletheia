/*
 * function: WORLDTRADE_ENTER_PushWifiSetup
 * address: 0x021F8D10
 * packet: pkt_ov135_021F8D10
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: ov115 data hint is witnessed by this function loading ov115 via PROCSYS_Push; no hint remains MATCH.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Push 0x02031348 arm
 *   WORLDTRADE_ENTER_RunDialog 0x021F8E88 thumb ov135
 *   str_02203C34 0x02203C34 data a1
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb  arm9
 */
#include "../include/Obj03294.h"
#include "../include/Obj23401.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    void *handle;
    u32 f4, f8, fc;
    void *f10;
    u32 f14, f18, f1c;
    void (*callback)(void *, void *);
    void *user;
} State;
extern const char str_02203C34[], ov115_id[];
extern const u32 gNetSaveMainProc[];
extern int WORLDTRADE_ENTER_RunDialog(void *dialog, u8 *p);
typedef unsigned short u16;
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, u32 value, u32 size);
extern void *func_020120F4(const struct Ctx *p);
extern void PROCSYS_Push(void *h, u32 id, const void *a, void *b);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
int WORLDTRADE_ENTER_PushWifiSetup(u8 *p)
{
    State *s;
    *(State * *)&((struct Obj03294 *)p)->f10DC = func_02030734(0x48, sizeof(State), 0, str_02203C34, 0x263);
    MI_CpuFill8(*(State * *)&((struct Obj03294 *)p)->f10DC, 0, sizeof(State));
    s = *(State * *)&((struct Obj03294 *)p)->f10DC;
    s->handle = func_020120F4(((struct Obj23401 *)(*(u8 * *)&((struct Obj03294 *)p)->f0))->f40);
    s->f4 = 0;
    s->f8 = 1;
    s->f10 = p + 0x116C;
    s->fc = 30;
    s->callback = (void (*)(void *, void *))WORLDTRADE_ENTER_RunDialog;
    s->user = p;
    ((struct Obj03294 *)p)->f12EC = 0;
    if (((struct Obj03294 *)p)->f20 == 21) s->f14 = 1;
    else s->f14 = 0;
    PROCSYS_Push(((struct Obj03294 *)p)->f12F0, (u32)ov115_id, gNetSaveMainProc, *(State **)(p + 0x10DC));
    GFL_NET_ERR_ShowScreen(0);
    ((struct Obj03294 *)p)->f28 = 3;
    return 2;
}
