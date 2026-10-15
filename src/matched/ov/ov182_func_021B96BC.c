/*
 * function: THE_END_GRAPHIC_Main
 * address: 0x021B96BC
 * packet: pkt_ov182_021B96BC
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: follower 021B9784 already matched separately.
 * symbols:
 *   FADE_IsActive 0x0204E804 arm
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   THE_END_GRAPHIC_LoadGraphics 0x021B9788 thumb ov182
 *   THE_END_GRAPHIC_StartFade 0x021B9814 thumb ov182
 *   THE_END_GRAPHIC_Update 0x021B99E8 thumb ov182
 */
#include "../include/Obj06594.h"
typedef unsigned short u16;
extern int FADE_IsActive(void);
extern unsigned KEY_GetTrg(void);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void THE_END_GRAPHIC_LoadGraphics(u16 *);
extern void THE_END_GRAPHIC_StartFade(void *, void *, void *);
extern void THE_END_GRAPHIC_Update(char *);
int THE_END_GRAPHIC_Main(void *a, unsigned *state, void *c, char *p)
{
    int ready;
    switch (*state) {
    case 0: *state = 4; break;
    case 1:
        if (!FADE_IsActive()) *state = 2;
        break;
    case 2:
        ready = 0;
        if (++((struct Obj06594 *)p)->f18 > 0x384) ready = 1;
        if (ready) {
            *state = 3;
            THE_END_GRAPHIC_StartFade(0, (void *)0x10, 0);
        }
        break;
    case 3:
        if (!FADE_IsActive()) {
            THE_END_GRAPHIC_LoadGraphics((u16 *)p);
            THE_END_GRAPHIC_StartFade((void *)0x10, 0, 0);
            *state = 4;
        }
        break;
    case 4:
        if (!FADE_IsActive()) {
            ((struct Obj06594 *)p)->f18 = 0;
            *state = 5;
        }
        break;
    case 5:
        if ((KEY_GetTrg() & 0xb) || ++((struct Obj06594 *)p)->f18 > 0x384) {
            *state = 6;
            THE_END_GRAPHIC_StartFade(0, (void *)0x10, 0);
        }
        break;
    case 6:
        if (!FADE_IsActive()) *state = 7;
        break;
    case 7: return 1;
    }
    PRINTSYS_QUE_Main(((struct Obj06594 *)p)->fC);
    THE_END_GRAPHIC_Update(*(char * *)&((struct Obj06594 *)p)->f4);
    return 0;
}
