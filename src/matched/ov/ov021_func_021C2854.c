/*
 * function: FLD3D_CI_PokemonFinishStep
 * address:  0x021C2854
 * packet:   pkt_ov021_021C2854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   PM_VOICE_IsAnyActive  0x02006650  thumb
 *   PM_VOICE_GetVolume  0x02006B20  thumb
 *   PM_VOICE_AddVolume  0x02006A8C  thumb
 *   PM_VOICE_StopAll  0x020065D8  thumb
 */
#include "../include/Obj01214.h"
#include "../include/Obj09680.h"

typedef unsigned short u16;

void PM_VOICE_GetPerapVoiceSave(void **out);
unsigned int PM_VOICE_Play(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7);
int PM_VOICE_IsAnyActive(void);
typedef signed char    s8;
typedef unsigned int   u32;
s8 PM_VOICE_GetVolume(u32 i);
void PM_VOICE_AddVolume(u32 idx, int delta);
void PM_VOICE_StopAll(void);

int FLD3D_CI_PokemonFinishStep(int a, char *b)
{
    int r;
    char *q;
    char buf[4];

    q = b + 0x9c;
    if (((struct Obj01214 *)q)->f14 != 0 && ((struct Obj01214 *)q)->f18 != 0) {
        (((struct Obj01214 *)q)->f18)--;
        if (((struct Obj01214 *)q)->f18 == 0) {
            if (((struct Obj01214 *)q)->f0 == 0x1b9) {
                PM_VOICE_GetPerapVoiceSave((void **)buf);
                ((struct Obj01214 *)q)->f1C = PM_VOICE_Play(((struct Obj01214 *)q)->f0, ((struct Obj01214 *)q)->f4, 0x40, 0, 0, 0, 0, (unsigned int)buf);
            } else {
                ((struct Obj01214 *)q)->f1C = PM_VOICE_Play(((struct Obj01214 *)q)->f0, ((struct Obj01214 *)q)->f4, 0x40, 0, 0, 0, 0, 0);
            }
        }
        ((struct Obj01214 *)q)->f1A = 0x1e;
        return 0;
    }
    r = 0;
    if (((struct Obj01214 *)q)->f18 == 0) {
        if (PM_VOICE_IsAnyActive() == 0) {
            r = 1;
        } else if (((struct Obj01214 *)q)->f1A != 0) {
            (((struct Obj01214 *)q)->f1A)--;
        } else if (PM_VOICE_GetVolume(((struct Obj01214 *)q)->f1C) > 0) {
            PM_VOICE_AddVolume(((struct Obj01214 *)q)->f1C, r - 16);
        } else {
            PM_VOICE_StopAll();
            r = 1;
        }
    }
    if (((struct Obj09680 *)b)->f11C != 0 && ((struct Obj09680 *)b)->f120 != 0 && ((struct Obj09680 *)b)->f124 != 0 && r != 0)
        return 1;
    return 0;
}
