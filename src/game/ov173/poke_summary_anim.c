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
#include "poke_summary_types.h"

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
    ((struct PokeSummaryWork *)p)->textKind = 3;
    ((struct PokeSummaryWork *)p)->state = 3;
    return 2;
}


int POKE_SUMMARY_ANIM_ShowTextKind8(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 8);
    ((struct PokeSummaryWork *)p)->state = 8;
    ((struct PokeSummaryWork *)p)->mon->applyFlag = 1;
    return 2;
}


int POKE_SUMMARY_ANIM_ShowTextKind4(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 4);
    ((struct PokeSummaryWork *)p)->textKind = 2;
    ((struct PokeSummaryWork *)p)->state = 3;
    return 2;
}

int POKE_SUMMARY_ANIM_ShowTextKind5(u8 *p) {POKE_SUMMARY_MAIN_StartTextStream((char *)p,5);((struct PokeSummaryWork *)p)->state=6;return 2;}

int POKE_SUMMARY_ANIM_Finish(u8 *p) {((struct PokeSummaryWork *)p)->state=10;return 0;}
