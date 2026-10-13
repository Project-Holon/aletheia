/*
 * function: func_021F2908
 * address:  0x021F2908
 * packet:   pkt_ov032_021F2908
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2908  0x021F2908  thumb
 *   func_021F2664  0x021F2664  thumb  ov032
 *   func_0203101C  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_0201C440  0x0201C440  thumb
 *   PRINTSYS_QUE_SetForceQueue  0x0201C4C8  thumb
 *   PRINTSYS_QUE_SetLimitTick  0x0201C4DC  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern void func_021F2664(int a, char *p);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
struct PalAnmSlot;
struct PrintSys;
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern u32 func_0201C440(void *p);
extern void PRINTSYS_QUE_SetForceQueue(struct PrintSys *p, u32 v);
extern void PRINTSYS_QUE_SetLimitTick(struct PrintSys *p, u32 lo, u32 hi);
extern u32 func_02188C54(u8 *p);
extern u32 func_021904AC(u8 *p);
extern void func_0201DD68(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);

void func_021F2908(char *p)
{
    ((struct Obj00007 *)p)->fA0 = func_0203101C(((struct Obj00007 *)p)->f98, ((struct Obj00007 *)p)->f98, 0x10, 0x80);
    ((struct Obj00007 *)p)->fA4 = func_020056A0((void *)func_021F2664, p, 0);
    ((struct Obj00007 *)p)->fAC = (u32)func_02021518(((struct Obj00007 *)p)->f98);
    func_0202155C((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 1, 0x1c0, ((struct Obj00007 *)p)->f98);
    func_0202155C((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 3, 0x200, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->fB4 = func_0201C440((void *)(((struct Obj00007 *)p)->f98));
    PRINTSYS_QUE_SetForceQueue((struct PrintSys *)(((struct Obj00007 *)p)->fB4), 1);
    PRINTSYS_QUE_SetLimitTick((struct PrintSys *)(((struct Obj00007 *)p)->fB4), 0x1f4, 0);
    ((struct Obj00007 *)p)->fB0 = func_021904AC((u8 *)func_02188C54((u8 *)(*(u32 *)&((struct Obj00007 *)p)->f8)));
    func_0201DD68();
    ((struct Obj00007 *)p)->f110 = func_0201EC64(((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f114 = func_02045B38(1, 2, 8, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f118 = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f11C = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f120 = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
}
