/*
 * function: func_021F1F80
 * address:  0x021F1F80
 * packet:   pkt_ov029_021F1F80
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   CLACT_GetActorAnimSeqCount  0x0204B918  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_021F1F70  0x021F1F70  thumb  ov029
 *   UI_GetPowerState  0x0203568C  arm
 */
#include "../include/Obj00811.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

struct RtcTime;
extern void func_0203F4CC(struct RtcTime *time);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u16 CLACT_GetActorAnimSeqCount(struct Obj *p);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern int OS_IsRunOnTwl(void);
extern u8 func_021F1F70(void);
extern int UI_GetPowerState(void);

static inline void SetFrame(int o, int v)
{
    if (v != CLACT_GetActorAnimSeqCount((struct Obj *)o)) {
        CLACT_SetActorAnimIndex(o, (u16)v);
    }
}

void func_021F1F80(char *p)
{
    RtcTime t;
    int o;
    int v;

    func_0203F4CC((struct RtcTime *)(&t));
    func_0204B3DC((struct Obj *)((struct Obj00811 *)p)->f12C, 0);

    o = ((struct Obj00811 *)p)->f130;
    v = t.hour / 10;
    SetFrame(o, v);
    if (v == 0) {
        func_0204B3DC((struct Obj *)o, 0);
    } else {
        func_0204B3DC((struct Obj *)o, 1);
    }

    o = ((struct Obj00811 *)p)->f134;
    v = t.hour % 10;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f138;
    v = t.second & 1;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f13C;
    v = t.minute / 10;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f140;
    v = t.minute % 10;
    SetFrame(o, v);

    o = ((struct Obj00811 *)p)->f144;
    if (OS_IsRunOnTwl()) {
        SetFrame(o, func_021F1F70());
    } else {
        SetFrame(o, UI_GetPowerState() == 5);
    }
}
