/*
 * function: func_0220663C
 * address: 0x0220663C
 * packet: pkt_ov094_0220663C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_RequestFade 0x0202173C thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   func_0220687C 0x0220687C thumb ov094
 */
#include "../include/Obj21789.h"
#include "../include/Obj21791.h"
#include "../include/Obj21793.h"
#include "../include/Obj21794.h"
#include "../include/Obj21796.h"
#include "../include/Obj21798.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct PalAnmObj PalAnmObj;
typedef struct { char *p; int state, colour, flag; } Ctx;
extern int PALANM_RequestFade(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern void func_0220687C(char *, void *);
void func_0220663C(void *task, Ctx *c)
{
    switch (c->state) {
    case 0:
        if (c->flag == 1)
            PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21789 *)(c->p))->f64, 8, 2, 0, 0, 8, 0x7fff, *(void **)c->p);
        else
            PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21791 *)(c->p))->f64, 2, c->colour, 0, 0, 8, 0x7fff, *(void **)c->p);
        c->state++;
        break;
    case 1:
        if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj21793 *)(c->p))->f64) == 0) {
            if (c->flag == 1)
                PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21794 *)(c->p))->f64, 8, 2, 0, 8, 0, 0x7fff, *(void **)c->p);
            else
                PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21796 *)(c->p))->f64, 2, c->colour, 0, 8, 0, 0x7fff, *(void **)c->p);
            c->state++;
        }
        break;
    case 2:
        if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj21798 *)(c->p))->f64) == 0)
            func_0220687C(c->p, task);
        break;
    }
}
