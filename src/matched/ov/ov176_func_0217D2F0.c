/*
 * function: func_0217D2F0
 * address:  0x0217D2F0
 * packet:   pkt_0217D2F0
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  byte-correct, but the calls to func_0200BAC8 and POKE_REGULATION_GetDataSize
 *           have no witness outside this range. Both are unlabelled Thumb
 *           leaf code in arm9 that disasm.py emitted as `.word` runs
 *           (0200BAC8 is inside a `0x21314B01` word block, 0201A918 inside a
 *           `0x47704800` word block), so they are neither `label` nor
 *           `sole-ref/code` (not a traced func_ start) and no SDK symbol
 *           exists. Nothing to cut: both call sites are inside this function.
 *
 * symbols:
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02087C6C  0x02087C6C  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E6E8  0x0200E6E8  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   POKE_REGULATION_GetDataSize  0x0201A918  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0200E918  0x0200E918  thumb
 *   func_0200B078  0x0200B078  thumb
 *   ov067_id       0x00000043  data
 */
#include "../include/Obj06578.h"
#include "../include/Obj06579.h"
typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Big;
struct Rec0200E6FC;
struct Reg2;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int MYSTATUS_GetSize(void);
extern void func_02082D44(u32 a, void *p, u32 b);
extern void func_02087C6C(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *func_0200BAC8(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 func_020307B0(void *p);
extern u8 func_0200E918(const u8 *base, u32 idx);
extern s32 func_0200B078(struct Reg2 *p, u32 id);

void func_0217D2F0(u8 *p, u8 *q)
{
    u8 *r = *(u8 * *)&((struct Obj06579 *)q)->f1B8;
    u32 x;
    u32 a;

    ((struct Obj06578 *)p)->f44 = 0x64;
    x = (u32)GAME_DATA_GetMyStatus(r);
    func_02082D44(x, p, MYSTATUS_GetSize());
    func_02087C6C(p + 0x20);
    func_0200E6FC(func_0200E6E8((u32)GAME_DATA_GetSaveControl((struct Big *)r)), 0, (struct Rec0200E6FC *)(p + 0x38));
    a = (u32)func_0200BAF4((int)func_0200BAC8(GAME_DATA_GetSaveControl((struct Big *)r)), 0x8056);
    func_02082D44(a, p + 0xd4, POKE_REGULATION_GetDataSize());
    func_020307B0((void *)a);
    ((struct Obj06578 *)p)->f28 = func_0200E918((const u8 *)(((struct Obj06579 *)q)->f34), 1);
    ((struct Obj06578 *)p)->f2C = func_0200E918((const u8 *)(((struct Obj06579 *)q)->f34), 2);
    ((struct Obj06578 *)p)->f30 = func_0200E918((const u8 *)(((struct Obj06579 *)q)->f34), 0);
    ((struct Obj06578 *)p)->f40 = func_0200B078((struct Reg2 *)(((struct Obj06579 *)q)->f38), 2);
}




