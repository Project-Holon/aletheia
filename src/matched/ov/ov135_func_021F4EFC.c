/*
 * function: func_021F4EFC
 * address:  0x021F4EFC
 * packet:   pkt_021F4EFC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFCD4  0x021FFCD4  thumb
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 */
#include "../include/Obj00996.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021FFCD4(u8 *p);
extern void CLACT_ReleasePalette(u32 v);
extern void CLACT_ReleaseCharacter(u32 v);
extern void CLACT_ReleaseCellAnim(u32 v);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);

void func_021F4EFC(u8 *p)
{
    func_021FFCD4(p);
    CLACT_ReleasePalette(((struct Obj00996 *)p)->fBE0);
    CLACT_ReleaseCharacter(((struct Obj00996 *)p)->fBDC);
    CLACT_ReleaseCellAnim(((struct Obj00996 *)p)->fBE4);
    CLACT_ReleasePalette(((struct Obj00996 *)p)->fBD4);
    CLACT_ReleaseCharacter(((struct Obj00996 *)p)->fBD0);
    CLACT_ReleaseCellAnim(((struct Obj00996 *)p)->fBD8);
    CLACT_ReleasePalette(((struct Obj00996 *)p)->fBC8);
    CLACT_ReleaseCharacter(((struct Obj00996 *)p)->fBC4);
    CLACT_ReleaseCellAnim(((struct Obj00996 *)p)->fBCC);
    CLACT_ReleaseCharacter(((struct Obj00996 *)p)->fBE8);
    CLACT_ReleaseCellAnim(((struct Obj00996 *)p)->fBF0);
    CLACT_DeleteUnit((struct Bank *)(((struct Obj00996 *)p)->fBC0));
    ((struct Obj00996 *)p)->fBC0 = 0;
    CLACT_ExitSystem();
}
