/*
 * function: OEKAKI_Exit
 * address:  0x021847C8
 * packet:   pkt_ov023_021847C8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   OEKAKI_CloseYesNoMenu  0x02186694  thumb  ov023
 *   OEKAKI_DeleteWindows  0x02185004  thumb  ov023
 *   OEKAKI_ResetDisplay  0x02184B34  thumb  ov023
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   OEKAKI_GetJoinedBits  0x02186558  thumb  ov023
 *   OEKAKI_FreeWork  0x02184B04  thumb  ov023
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */
#include "../include/Obj01361.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Bank;
struct Node;
struct Rec;
struct WordSet;
extern void func_02030EAC(struct Node *n);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void OEKAKI_CloseYesNoMenu(char *p);
extern void OEKAKI_DeleteWindows(char *p);
extern void OEKAKI_ResetDisplay(void);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern int OEKAKI_GetJoinedBits(char *p);
extern void OEKAKI_FreeWork(char *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);

int OEKAKI_Exit(u32 a, int *seq, u8 *c, u8 *d)
{
    switch (*seq) {
    case 0:
        func_02030EAC((struct Node *)(((struct Obj01361 *)d)->f8));
        CLACT_ReleaseCharacter(((struct Obj01361 *)d)->f58);
        CLACT_ReleasePalette(((struct Obj01361 *)d)->f54);
        CLACT_ReleaseCellAnim(((struct Obj01361 *)d)->f5C);
        CLACT_ReleaseCharacter(((struct Obj01361 *)d)->f4C);
        CLACT_ReleasePalette(((struct Obj01361 *)d)->f48);
        CLACT_ReleaseCellAnim(((struct Obj01361 *)d)->f50);
        CLACT_ReleaseCharacter(((struct Obj01361 *)d)->f40);
        CLACT_ReleasePalette(((struct Obj01361 *)d)->f3C);
        CLACT_ReleaseCellAnim(((struct Obj01361 *)d)->f44);
        CLACT_DeleteUnit((struct Bank *)(((struct Obj01361 *)d)->f38));
        CLACT_ExitSystem();
        if (((struct Obj01361 *)d)->f178 != 0) {
            OEKAKI_CloseYesNoMenu((char *)d);
        }
        OEKAKI_DeleteWindows((char *)d);
        OEKAKI_ResetDisplay();
        MSGDATA_Delete((struct Rec *)(((struct Obj01361 *)d)->f14));
        func_0201ED04((struct WordSet *)(((struct Obj01361 *)d)->f10));
        GF_FONT_Delete((void *)(((struct Obj01361 *)d)->fC));
        (*seq)++;
        break;
    case 1:
        (*seq)++;
        break;
    case 2:
        if (((struct Obj01361 *)d)->f9E78 != 0) {
            if (OEKAKI_GetJoinedBits((char *)d) == 1) {
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 3:
        OEKAKI_FreeWork((char *)d);
        func_020315D4((struct S020315D4 *)a);
        func_020306F0(0x28);
        return 1;
    }
    return 0;
}
