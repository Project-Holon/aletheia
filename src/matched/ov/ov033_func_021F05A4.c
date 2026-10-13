/*
 * function: DOWSING_UpdateDisplay
 * address:  0x021F05A4
 * packet:   pkt_ov033_021F05A4
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DOWSING_UpdateFade 0x021F0C44 thumb ov033
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   sDowsingLevelTable 0x021F0DC8 data ov033 a4
 */
#include "../include/Obj00323.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a : 3;
    u32 b : 3;
    u32 c : 3;
    u32 x : 8;
    u32 y : 8;
    u32 pad : 7;
} Ent;

typedef struct {
    u16 x;
    u16 y;
} Pt;

extern const Ent sDowsingLevelTable[];
struct Obj;
extern void DOWSING_UpdateFade(char *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

void DOWSING_UpdateDisplay(char *p, int flag)
{
    Pt pt;

    DOWSING_UpdateFade(p);
    if (flag == 0)
        return;
    if (((struct Obj00323 *)p)->f6C != ((struct Obj00323 *)p)->f68) {
        func_0204B3DC(((struct Obj00323 *)p)->f50,
                      (((struct Obj00323 *)p)->f68 == 8 || ((struct Obj00323 *)p)->f68 == 9) ? 0 : 1);
        func_0204B3DC(((struct Obj00323 *)p)->f5C, ((struct Obj00323 *)p)->f68 == 8);
        pt.x = sDowsingLevelTable[*(int *)(p + 0x68)].x;
        pt.y = sDowsingLevelTable[*(int *)(p + 0x68)].y;
        func_0204B404(((struct Obj00323 *)p)->f50, (const struct Vec2 *)(&pt), 1);
        CLACT_SetActorAnimSeq(((struct Obj00323 *)p)->f38, sDowsingLevelTable[*(int *)(p + 0x68)].a);
        CLACT_SetActorAnimSeq(((struct Obj00323 *)p)->f44, sDowsingLevelTable[*(int *)(p + 0x68)].b);
        CLACT_SetActorAnimSeq(((struct Obj00323 *)p)->f50, sDowsingLevelTable[*(int *)(p + 0x68)].c);
        ((struct Obj00323 *)p)->f6C = ((struct Obj00323 *)p)->f68;
    }
    if (((struct Obj00323 *)p)->f68 == 8 && ((struct Obj00323 *)p)->fA4 != 0) {
        CLACT_SetActorAnimSeq(((struct Obj00323 *)p)->f5C, 0);
        func_0204B92C(((struct Obj00323 *)p)->f5C, 1);
        CLACT_SetActorAnimFrame(((struct Obj00323 *)p)->f5C, 0);
        ((struct Obj00323 *)p)->fA4 = 0;
    }
}
