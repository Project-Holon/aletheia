/*
 * file:     iss_switch.c
 * unit:     yes
 * function: ISS_SWITCH_Create, ISS_SWITCH_Delete, ISS_SWITCH_Setup, ISS_SWITCH_IsOn, ISS_SWITCH_On, ISS_SWITCH_Off, ISS_SWITCH_ForceOn, ISS_SWITCH_ForceOff, ISS_SWITCH_Main, ISS_SWITCH_SetVolume, ISS_SWITCH_Alloc, ISS_SWITCH_Free, ISS_SWITCH_Init, ISS_SWITCH_SetParam, ISS_SWITCH_CountUpFade, ISS_SWITCH_IsFadeEnd, ISS_SWITCH_Update, ISS_SWITCH_UpdateOn, ISS_SWITCH_UpdateOff, ISS_SWITCH_UpdateFadeIn, ISS_SWITCH_UpdateFadeOut, ISS_SWITCH_StartFadeIn, ISS_SWITCH_StartFadeOut, ISS_SWITCH_SetOnState, ISS_SWITCH_SetOffState, ISS_SWITCH_GetState, ISS_SWITCH_SetState, ISS_SWITCH_GetVolume, ISS_SWITCH_ApplyVolume, ISS_SWITCH_IsOnState, ISS_SWITCH_IsOffState
 * address:  0x0202C538
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_set.c, iss_switch.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ISS_SWITCH_Alloc 0x0202C590 thumb arm9
 *   ISS_SWITCH_Free 0x0202C5AC thumb arm9
 *   ISS_SWITCH_Init 0x0202C5B4 thumb arm9
 *   ISS_SWITCH_SetParam 0x0202C5C4 thumb arm9
 *   ISS_SWITCH_Update 0x0202C5F0 thumb arm9
 *   ISS_SWITCH_StartFadeIn 0x0202C670 thumb arm9
 *   ISS_SWITCH_StartFadeOut 0x0202C688 thumb arm9
 *   ISS_SWITCH_SetOnState 0x0202C6A0 thumb arm9
 *   ISS_SWITCH_SetOffState 0x0202C6AC thumb arm9
 *   ISS_SWITCH_ApplyVolume 0x0202C710 thumb arm9
 *   ISS_SWITCH_IsOnState 0x0202C72C thumb arm9
 *   IssSwitchFileName      0x020A7780  data
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_set_shared_types.h"

#include "gfl_heap_wrap.h"


void *ISS_SWITCH_Create(u32 heapId);

u32 ISS_SWITCH_Delete(void *sw);

u32 ISS_SWITCH_Setup(void *sw, u16 fadeFrames, u16 trackBits);

u32 ISS_SWITCH_IsOn(void *sw);

u32 ISS_SWITCH_On(void *sw);

u32 ISS_SWITCH_Off(void *sw);

u32 ISS_SWITCH_ForceOn(void *sw);

u32 ISS_SWITCH_ForceOff(void *sw);

void ISS_SWITCH_Main(void *sw);

void ISS_SWITCH_SetVolume(void *sw, u32 maxVolume);

void *ISS_SWITCH_Alloc(u32 heapId);

u32 ISS_SWITCH_Free(void *sw);

void ISS_SWITCH_Init(struct IssSwitch *sw);

u32 ISS_SWITCH_SetParam(struct IssSwitch *sw, u16 fadeFrames, u16 trackBits);

void ISS_SWITCH_Update(void *sw);

u32 ISS_SWITCH_StartFadeIn(void *sw);

u32 ISS_SWITCH_StartFadeOut(void *sw);

u32 ISS_SWITCH_SetOnState(void *sw);

u32 ISS_SWITCH_SetOffState(void *sw);

void ISS_SWITCH_ApplyVolume(struct IssSwitch *sw, s32 maxVolume);

u32 ISS_SWITCH_IsOnState(void *sw);

void *ISS_SWITCH_Create(u32 heapId)
{
    void *sw = ISS_SWITCH_Alloc(heapId);

    ISS_SWITCH_Init(sw);
    return sw;
}

u32 ISS_SWITCH_Delete(void *sw)
{
    return ISS_SWITCH_Free(sw);
}

u32 ISS_SWITCH_Setup(void *sw, u16 fadeFrames, u16 trackBits)
{
    return ISS_SWITCH_SetParam(sw, fadeFrames, trackBits);
}

u32 ISS_SWITCH_IsOn(void *sw)
{
    return ISS_SWITCH_IsOnState(sw);
}

u32 ISS_SWITCH_On(void *sw)
{
    return ISS_SWITCH_StartFadeIn(sw);
}

u32 ISS_SWITCH_Off(void *sw)
{
    return ISS_SWITCH_StartFadeOut(sw);
}

u32 ISS_SWITCH_ForceOn(void *sw)
{
    return ISS_SWITCH_SetOnState(sw);
}

u32 ISS_SWITCH_ForceOff(void *sw)
{
    return ISS_SWITCH_SetOffState(sw);
}

void ISS_SWITCH_Main(void *sw)
{
    ISS_SWITCH_Update(sw);
}

void ISS_SWITCH_SetVolume(void *sw, u32 maxVolume)
{
    ISS_SWITCH_ApplyVolume(sw, maxVolume);
}

#include "gfl_use.h"

void ISS_SWITCH_CountUpFade(struct IssSwitch *sw);

u32 ISS_SWITCH_IsFadeEnd(struct IssSwitch *sw);

void ISS_SWITCH_UpdateOn(void *sw);

void ISS_SWITCH_UpdateOff(void *sw);

u32 ISS_SWITCH_UpdateFadeIn(void *sw);

u32 ISS_SWITCH_UpdateFadeOut(void *sw);

u32 ISS_SWITCH_GetState(struct IssSwitch *sw);

struct IssSwitch *ISS_SWITCH_SetState(struct IssSwitch *sw, u32 state);

s32 ISS_SWITCH_GetVolume(struct IssSwitch *sw);

u32 ISS_SWITCH_IsOffState(void *sw);

extern char IssSwitchFileName[];

void *ISS_SWITCH_Alloc(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 0xc, 0, IssSwitchFileName, 0x115);
}

/*
 * An unlabelled leaf sitting inside ISS_SWITCH_Alloc's own literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a
 * pool-word-and-bx tail call into the ARM SDK function ENV_SetResourceSet
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md
 * covers the shape, though this is a genuine tail call rather than a
 * linker veneer). Reached only through ISS_SWITCH_Delete's own
 * pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_Free.c \
 *       --func ISS_SWITCH_Free --addr 0x0202C5AC --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_Free(void *sw)
{
    return GFL_HEAP_Free(sw);
}

void ISS_SWITCH_Init(struct IssSwitch *sw)
{
    sw->state = 1;
    sw->fadeCount = 0;
    sw->fadeFrames = 0;
    sw->trackBits = 0;
}

/*
 * An unlabelled leaf, six bytes padded to eight, sitting between
 * ISS_SWITCH_Init's trailing padding and ISS_SWITCH_CountUpFade's label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a plain
 * two-field setter with no prologue at all, reached only through
 * ISS_SWITCH_Setup's pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SetParam.c \
 *       --func ISS_SWITCH_SetParam --addr 0x0202C5C4 --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_SetParam(struct IssSwitch *sw, u16 fadeFrames, u16 trackBits)
{
    sw->fadeFrames = fadeFrames;
    sw->trackBits = trackBits;
    return (u32)sw;
}

void ISS_SWITCH_CountUpFade(struct IssSwitch *sw)
{
    sw->fadeCount = sw->fadeCount + 1;
    if (sw->fadeFrames < sw->fadeCount) {
        sw->fadeCount = sw->fadeFrames;
    }
}

u32 ISS_SWITCH_IsFadeEnd(struct IssSwitch *sw)
{
    if (sw->fadeFrames > sw->fadeCount) {
        return 0;
    }
    return 1;
}

void ISS_SWITCH_Update(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        ISS_SWITCH_UpdateOn(sw);
        break;
    case 1:
        ISS_SWITCH_UpdateOff(sw);
        break;
    case 2:
        ISS_SWITCH_UpdateFadeIn(sw);
        break;
    case 3:
        ISS_SWITCH_UpdateFadeOut(sw);
        break;
    }
}

void ISS_SWITCH_UpdateOn(void *sw)
{
}

void ISS_SWITCH_UpdateOff(void *sw)
{
}

u32 ISS_SWITCH_UpdateFadeIn(void *sw)
{
    u32 r;

    ISS_SWITCH_CountUpFade(sw);
    if ((r = ISS_SWITCH_IsFadeEnd(sw)) == 1) {
        r = (u32)ISS_SWITCH_SetState(sw, 0);
    }
    return r;
}

u32 ISS_SWITCH_UpdateFadeOut(void *sw)
{
    u32 r;

    ISS_SWITCH_CountUpFade(sw);
    if ((r = ISS_SWITCH_IsFadeEnd(sw)) == 1) {
        r = (u32)ISS_SWITCH_SetState(sw, 1);
    }
    return r;
}

u32 ISS_SWITCH_StartFadeIn(void *sw)
{
    u32 r;

    r = ISS_SWITCH_IsOnState(sw);
    if (r != 1) {
        r = (u32)ISS_SWITCH_SetState(sw, 2);
    }
    return r;
}

u32 ISS_SWITCH_StartFadeOut(void *sw)
{
    u32 r;

    r = ISS_SWITCH_IsOffState(sw);
    if (r != 1) {
        r = (u32)ISS_SWITCH_SetState(sw, 3);
    }
    return r;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two unlabelled leaves, back to back
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): each is a
 * three-instruction, six-byte forwarding call with a literal second
 * argument, padded to eight with a `nop` and its own pool word. Reached
 * only through ISS_SWITCH_ForceOn and ISS_SWITCH_ForceOff's pool-word-and-bx tail
 * calls (src/matched/unit_0202C548.c). Neither carries a
 * register-saving prologue, so neither is in the worklist's function
 * list; both sit exactly between ISS_SWITCH_StartFadeOut's last instruction and
 * ISS_SWITCH_GetState's label.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C6A0.c \
 *       --addr 0x0202C6A0 --thumb
 */
u32 ISS_SWITCH_SetOnState(void *sw)
{
    return (u32)ISS_SWITCH_SetState(sw, 0);
}

u32 ISS_SWITCH_SetOffState(void *sw)
{
    return (u32)ISS_SWITCH_SetState(sw, 1);
}

u32 ISS_SWITCH_GetState(struct IssSwitch *sw)
{
    return sw->state;
}

struct IssSwitch *ISS_SWITCH_SetState(struct IssSwitch *sw, u32 state)
{
    sw->state = state;
    sw->fadeCount = 0;
    return sw;
}

s32 ISS_SWITCH_GetVolume(struct IssSwitch *sw)
{
    s32 volume;

    switch (ISS_SWITCH_GetState((struct IssSwitch *)sw)) {
    case 0:
        return 0x7F;
    case 1:
        return 0;
    case 2:
        volume = sw->fadeCount * 0x7F / sw->fadeFrames;
        break;
    case 3:
        volume = 0x7F - sw->fadeCount * 0x7F / sw->fadeFrames;
        break;
    }
    return volume;
}

void ISS_SWITCH_ApplyVolume(struct IssSwitch *sw, s32 maxVolume)
{
    GFL_USE_SetBgmTrackVolume(sw->trackBits, maxVolume * ISS_SWITCH_GetVolume(sw) / 0x7F);
}

u32 ISS_SWITCH_IsOnState(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 0;
    }
    return 0;
}

u32 ISS_SWITCH_IsOffState(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return 1;
    }
    return 0;
}
