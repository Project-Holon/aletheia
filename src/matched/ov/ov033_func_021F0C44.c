/*
 * function: DOWSING_UpdateFade
 * address:  0x021F0C44
 * packet:   pkt_ov033_021F0C44
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030D28 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   CLACT_StartActorAnim 0x0204B95C arm
 *   CLACT_StopActorAnim 0x0204B974 arm
 */
#include "../include/Obj00323.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;

struct Actor;
struct Ctx;
extern void func_02030D28(struct Ctx *c);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern void CLACT_StartActorAnim(struct Actor *a);
extern void CLACT_StopActorAnim(struct Actor *a);

void DOWSING_UpdateFade(char *p)
{
    u16 m;
    u8 i;

    func_02030D28(((struct Obj00323 *)p)->fB4);
    if (((struct Obj00323 *)p)->fC0 == 0 || PALANM_GetFadeRequestBits(((struct Obj00323 *)p)->fBC) != 0)
        return;
    switch (((struct Obj00323 *)p)->fC0) {
    case 1:
        if (((struct Obj00323 *)p)->fC4 != 0) {
            m = 0;
            for (i = 0; i < 3; i++)
                m |= (u16)(1 << i);
            PALANM_RequestFade(((struct Obj00323 *)p)->fBC, 2, m, 0, 0, 0, 0, ((struct Obj00323 *)p)->fB4);
            m = 0;
            for (i = 0; i < 4; i++)
                m |= (u16)(1 << i);
            PALANM_RequestFade(((struct Obj00323 *)p)->fBC, 8, m, 0, 0, 0, 0, ((struct Obj00323 *)p)->fB4);
            ((struct Obj00323 *)p)->fC4 = 0;
            for (i = 0; i < 4; i++)
                CLACT_StartActorAnim(*(void **)(p + i * 12 + 0x38));
        }
        break;
    case 2:
        if (((struct Obj00323 *)p)->fC4 != 1) {
            m = 0;
            for (i = 0; i < 3; i++)
                m |= (u16)(1 << i);
            PALANM_RequestFade(((struct Obj00323 *)p)->fBC, 2, m, 0, 8, 8, 0, ((struct Obj00323 *)p)->fB4);
            m = 0;
            for (i = 0; i < 4; i++)
                m |= (u16)(1 << i);
            PALANM_RequestFade(((struct Obj00323 *)p)->fBC, 8, m, 0, 8, 8, 0, ((struct Obj00323 *)p)->fB4);
            ((struct Obj00323 *)p)->fC4 = 1;
            for (i = 0; i < 4; i++)
                CLACT_StopActorAnim(*(void **)(p + i * 12 + 0x38));
        }
        break;
    }
    ((struct Obj00323 *)p)->fC0 = 0;
}
