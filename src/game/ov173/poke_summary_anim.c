/*
 * file:     poke_summary_anim.c
 * unit:     yes
 * function: POKE_SUMMARY_ANIM_ShowTextKind7, POKE_SUMMARY_ANIM_ShowTextKind8, POKE_SUMMARY_ANIM_ShowTextKind4, POKE_SUMMARY_ANIM_ShowTextKind5
 * address:  0x021B75E0
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   POKE_SUMMARY_MAIN_StartTextStream  0x021B7460  thumb  ov173
 */
#include "../../matched/include/Obj14316.h"
#include "../../matched/include/Obj14317.h"
#include "../../matched/include/Obj14318.h"
#include "../../matched/include/Obj24178.h"
#include "../../matched/include/Obj24179.h"

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind);
int POKE_SUMMARY_ANIM_ShowTextKind7(int *p);
int POKE_SUMMARY_ANIM_ShowTextKind8(int *p);
int POKE_SUMMARY_ANIM_ShowTextKind4(int *p);
int POKE_SUMMARY_ANIM_ShowTextKind5(u8 *p);
int POKE_SUMMARY_ANIM_Finish(u8 *p);


int POKE_SUMMARY_ANIM_ShowTextKind7(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 7);
    ((struct Obj14316 *)p)->f1BA = 3;
    ((struct Obj14316 *)p)->f1B0 = 3;
    return 2;
}


int POKE_SUMMARY_ANIM_ShowTextKind8(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 8);
    ((struct Obj14317 *)p)->f1B0 = 8;
    *(unsigned char *)(((struct Obj14317 *)p)->f0 + 0x1a) = 1;
    return 2;
}


int POKE_SUMMARY_ANIM_ShowTextKind4(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 4);
    ((struct Obj14318 *)p)->f1BA = 2;
    ((struct Obj14318 *)p)->f1B0 = 3;
    return 2;
}

int POKE_SUMMARY_ANIM_ShowTextKind5(u8 *p) {POKE_SUMMARY_MAIN_StartTextStream((char *)p,5);((struct Obj24178 *)p)->f1B0=6;return 2;}

int POKE_SUMMARY_ANIM_Finish(u8 *p) {((struct Obj24179 *)p)->f1B0=10;return 0;}
