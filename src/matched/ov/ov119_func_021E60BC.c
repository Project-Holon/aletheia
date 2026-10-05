/*
 * function: func_021E60BC
 * address: 0x021E60BC
 * packet: pkt_ov119_021E60BC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed long loop index, u8-qualified guard base versus char-qualified creation base, and mutable p keep the byte index live without a cached address spill.
 * domain: the local counter visits exactly 0..7; all unsigned index conversions preserve its full value. Creator x/state are caller-observed u8 arguments (021E61F8 and 021E620E); B878 state is u16 (021E61DA).
 * table-bounds: original words 021E7EC4..021E7EE0 are 25,26,27,28,29,30,20,21; coords.v[i]*8 is 160..240 without signed overflow or value loss.
 * initialization: both table objects are copied in full; every meaningful descriptor field is assigned before 021B6208.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`offOwner=0x98c;` before `offOwner=0x98c+0x38;`; `offStore=0x98c;` before
 * `offStore=0x98c+0x14;` and 2 more). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_0201B280 0x0201B280 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027748 0x02027748 thumb
 *   func_0202774C 0x0202774C thumb
 *   func_02027750 0x02027750 thumb
 *   func_02027754 0x02027754 thumb
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021E7EC4 0x021E7EC4 data a4
 *   d_021E7F84 0x021E7F84 data a4
 */
#include "../include/Obj00001.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;
struct Obj;
typedef struct { int v[8]; } Coords;
typedef struct { int v[8][2]; } States;
extern const Coords d_021E7EC4;
extern const States d_021E7F84;
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_02017EAC(void *);
extern u32 func_0201B280(void *);
extern u32 func_020275E4(void);
extern int func_02027748(void);
extern int func_0202774C(int);
extern int func_02027750(int);
extern int func_02027754(int);
extern void func_021B6208(void *,In *,int,u16);
extern int func_021B629C(void *,int,u8,u16,u8,u16);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B3DC(struct Obj *,u32);
void func_021E60BC(char *p,void *mon,int flag)
{
    In in;
    Coords coords;
    States states;
    int offOwner,offStore,offLoad,offSprite;
    u32 bits;
    long i;
    int state,sprite;
    int *row;
    bits=func_02017E1C(mon,11,0);
    coords=d_021E7EC4;
    states=d_021E7F84;
    in.f0=0; in.f4=0;
    in.f8=func_020275E4();
    in.fC=func_02027748();
    in.f10=func_0202774C(2);
    in.f14=func_02027750(2);
    in.f18=func_02027754(2);
    in.b1c=13; in.b1d=0; in.b1e=1;
    if (!flag && func_02017EAC(mon)) bits|=64;
    if (func_0201B280(mon)) bits|=128;
    if (!((struct Obj00001 *)p)->f99C) {
        func_021B6208((void *)(p+0x98c),&in,((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f5F4);
        ((struct Obj00001 *)p)->f99C=1;
    }
    offOwner=0x98c+0x38;
    offStore=0x98c+0x14;
    offLoad=0x98c+0x14;
    offSprite=0x98c+0x14;
    for (i=0;i<8;i++) {
        sprite=*(int *)((const u8 *)p+(unsigned long)i*4+offSprite);
        if (bits&(1<<i)) { row=states.v[(unsigned)i]; state=states.v[i][0]; }
        else { row=states.v[i]; state=row[1]; }
        if (sprite) {
            if (state==-1) func_0204B3DC((struct Obj *)sprite,0);
            else if (flag && i==6) func_0204B3DC((struct Obj *)sprite,0);
            else { func_0204B878((struct Obj *)sprite,state); func_0204B3DC((struct Obj *)sprite,1); }
        } else {
            *(int *)(p+(unsigned long)i*4+offStore)=func_021B629C((void *)(p+0x98c),*(int *)(p+offOwner),coords.v[(unsigned long)i]*8,101,state==-1?row[0]:state,((struct Obj00001 *)p)->f5F4);
            sprite=*(int *)(p+(unsigned long)i*4+offLoad);
            if (state==-1) func_0204B3DC((struct Obj *)sprite,0);
            else if (flag && i==6) func_0204B3DC((struct Obj *)sprite,0);
        }
    }
}
