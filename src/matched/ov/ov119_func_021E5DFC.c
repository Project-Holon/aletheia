/*
 * function: func_021E5DFC
 * address: 0x021E5DFC
 * packet: pkt_ov119_021E5DFC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: x/y are u8 at 021E5ED6..021E5EE2; ov067's own u16 coordinate prototype is narrowed for this caller.
 * domain: side is 0/1 from 021E1E20/021E1E2C at call 021E1F14, or 2 at call 021E23B2 (r1 set 021E23AE).
 * initialization: both domain arms fill x, y, f0 and b1c; all remaining descriptor fields read by ov067 021B6208 are filled below.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`x
 * = side*128;` before `x = side*128+16;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_02027694 0x02027694 thumb
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */
#include "../include/Obj00001.h"
#include "../include/Obj06428.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 func_0202136C(u16);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 func_020275E4(void);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern void UI_SCENE_LoadActorGfx(void *,In *,int,u16);
extern int UI_SCENE_CreateActor(void *,int,u8,u8,u8,u16);
void func_021E5DFC(char *p, int side, void *mon)
{
    char *q = p + 0x950;
    In in;
    int x,y;
    int flag = 0;
    u32 species = POKE_TOOL_GetPartyValue(mon,6,0);
    if (func_0202136C(species)) flag = 1;
    if (((struct Obj06428 *)q)->f10) {
        if (!species) func_0204B3DC((struct Obj *)((struct Obj06428 *)q)->f10,0);
        else {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj06428 *)q)->f10),flag);
            func_0204B3DC((struct Obj *)((struct Obj06428 *)q)->f10,1);
        }
        return;
    }
    if (!species) return;
    switch (side) {
    case 0: case 1:
        x = side*128+16; y = 132;
        in.f0 = 1; in.b1c = 12;
        break;
    case 2:
        x = 32; y = 172;
        in.f0 = 0; in.b1c = 6;
        break;
    }
    in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_02027694();
    in.f10 = func_02027698();
    in.f14 = func_0202769C(2);
    in.f18 = func_020276A0(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q,&in,((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f5F4);
    ((struct Obj06428 *)q)->f10 = UI_SCENE_CreateActor(q,((struct Obj00001 *)p)->f9C4,x,y,flag,((struct Obj00001 *)p)->f5F4);
}
