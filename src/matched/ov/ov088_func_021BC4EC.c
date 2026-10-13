/*
 * function: STARTMENU_ConfigPromptInit
 * address:  0x021BC4EC
 * packet:   pkt_ov088_021BC4EC
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   STARTMENU_ConfigPromptSetupGraphics  0x021BC62C  thumb  ov088
 *   STARTMENU_ConfigPromptDrawQuestion  0x021BC75C  thumb  ov088
 */
#include "../include/Obj09923.h"

extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void STARTMENU_ConfigPromptSetupGraphics(char *);
typedef unsigned char  u8;
extern void STARTMENU_ConfigPromptDrawQuestion(u8 *p);

int STARTMENU_ConfigPromptInit(struct Obj0203159C *a, int b, int *c)
{
    char *r;
    GFL_HEAP_CreateChildHeap(1, 0x39, 0x80000);
    r = PROCSYS_AllocProcWork(a, 0x1c, 0x39);
    if (*c == 0)
        ((struct Obj09923 *)r)->f4 = 0;
    else
        ((struct Obj09923 *)r)->f4 = 2;
    ((struct Obj09923 *)r)->f18 = 0;
    STARTMENU_ConfigPromptSetupGraphics(r);
    STARTMENU_ConfigPromptDrawQuestion((u8 *)r);
    return 1;
}
