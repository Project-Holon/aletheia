/*
 * function: POKELIST_CreateClactUnit
 * address:  0x021B709C
 * packet:   pkt_ov091_021B709C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */
#include "../include/Obj00047.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R;

struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);

void POKELIST_CreateClactUnit(u8 *p)
{
    R b;
    R a;
    int x;
    u32 bank;

    bank = (u32)CLACT_CreateUnit(10, 8, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1D4 = bank;
    CLACT_SetUnitDefaultRenderer((struct Bank *)bank);
    b.a = 0;
    b.b = 0;
    b.c = 0;
    b.d = 10;
    b.e = 3;
    ((struct Obj00047 *)p)->f1D8 = (int)CLACT_CreateActor((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f198,
                                        ((struct Obj00047 *)p)->f178, ((struct Obj00047 *)p)->f1B4, &b, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1DC = (int)CLACT_CreateActor((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f198,
                                        ((struct Obj00047 *)p)->f178, ((struct Obj00047 *)p)->f1B4, &b, 0, ((struct Obj00047 *)p)->f0);
    func_0204B92C((struct Obj *)((struct Obj00047 *)p)->f1D8, 1);
    func_0204B92C((struct Obj *)((struct Obj00047 *)p)->f1DC, 1);
    func_0204B3DC((struct Obj *)((struct Obj00047 *)p)->f1D8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00047 *)p)->f1DC, 0);
    a.a = 0xe0;
    a.b = 0xa8;
    a.c = 1;
    a.d = 0;
    a.e = 0;
    x = (int)CLACT_CreateActor((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f1A0,
                      ((struct Obj00047 *)p)->f17C, ((struct Obj00047 *)p)->f1BC, &a, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1E0 = x;
    func_0204B92C((struct Obj *)x, 1);
    a.a = 0xc4;
    a.c = 0;
    x = (int)CLACT_CreateActor((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f1A0,
                      ((struct Obj00047 *)p)->f17C, ((struct Obj00047 *)p)->f1BC, &a, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1E4 = x;
    func_0204B92C((struct Obj *)x, 1);
}
