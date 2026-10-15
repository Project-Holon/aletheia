/*
 * function: DUP_FITTING_HandleTouch
 * address: 0x021B940C
 * packet: pkt_ov133_021B940C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BA594 0x021BA594 data ov133 a1
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   DUP_FITTING_SaveOutfits 0x021B96D8 thumb ov133
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   DUP_FITTING_ResetActorPose 0x021BA098 thumb ov133
 *   DUP_FITTING_ResetSlots 0x021B94C0 thumb ov133
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   DUP_FITTING_SetText 0x021B9C08 thumb ov133
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   DUP_FITTING_HandlePickTouch 0x021B952C thumb ov133
 *   DUP_FITTING_UpdateHeldVisible 0x021B8FA8 thumb ov133
 */
#include "../include/Obj00004.h"
#include "../include/Obj23317.h"
#include "../include/Obj23318.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 bytes[12]; } Rects;
extern const Rects d_021BA594;
extern unsigned int TOUCHPANEL_GetPointCont(unsigned int *outA, unsigned int *outB);
extern int TOUCHPANEL_HitTrg(const void *);
extern void DUP_FITTING_SaveOutfits(char *p);
typedef unsigned int   u32;
struct WordSet;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void DUP_FITTING_ResetActorPose(u8 *);
extern void DUP_FITTING_ResetSlots(u8 *);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);
extern void DUP_FITTING_SetText(u8 *, unsigned int, void *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void DUP_FITTING_HandlePickTouch(u8 *);
extern void DUP_FITTING_UpdateHeldVisible(u8 *);
int DUP_FITTING_HandleTouch(u8 *p)
{
    Rects rects = d_021BA594;
    void *obj;
    TOUCHPANEL_GetPointCont((unsigned int *)(p + 0x1c), (unsigned int *)(p + 0x20));
    switch (TOUCHPANEL_HitTrg(&rects)) {
    case 0:
        DUP_FITTING_SaveOutfits((char *)p);
        GFL_USE_PlaySeDefaultVolume(1358);
        DUP_FITTING_ResetActorPose(p);
        return 2;
    case 1:
        ((struct Obj00004 *)p)->fC = 6;
        ((struct Obj00004 *)p)->f10 = 192;
        GFL_USE_PlaySeDefaultVolume(1962);
        DUP_FITTING_ResetSlots(p);
        obj = WORDSET_CreateDefault(((struct Obj00004 *)p)->f0);
        WORDSET_SetSlotMonSpecies(obj, 0, ((struct Obj23318 *)(*(u8 * *)&((struct Obj23317 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4))->f4);
        DUP_FITTING_SetText(p, 0, obj);
        WORDSET_DeleteStrbufED04(obj);
        DUP_FITTING_ResetActorPose(p);
        break;
    case -1:
        DUP_FITTING_HandlePickTouch(p);
        break;
    }
    DUP_FITTING_UpdateHeldVisible(p);
    return 0;
}
