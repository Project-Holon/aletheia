/*
 * file:     btl_server_p68.c
 * unit:     yes
 * function: func_021C54BC, func_021C54C8, func_021C54FC, func_021C5540
 * address:  0x021C54BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C5D88 0x021C5D88 thumb ov093
 *   func_021C5480  0x021C5480  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021D62D8  0x021D62D8  thumb  ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C5B74 0x021C5B74 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct UtilSlots;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021C5D88(u8 *, u8 *, int);
extern void func_021C5480(u8 *p, u8 *a, int b);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5B74(u8 *, u8 *, int, int);
void func_021C54BC(u8 *p, u8 *a);
void func_021C54C8(u8 *p, u8 *a);
void func_021C54FC(u8 *p, u8 *a);
void func_021C5540(u8 *p, u8 *a, int c);

/*
 * leaf: Sole blocker of func_021BCCE0; ordinary default-argument tail call.
 * extent: Next function 021C54C8 is already separately matched; 12-byte leaf.
 * semantics: Forwards both pointer inputs unchanged; literal argument 0x350.
 */
void func_021C54BC(u8 *p, u8 *a)
{
    func_021C5D88(p, a, 0x350);
}


void func_021C54C8(u8 *p, u8 *a)
{
    func_021C5480(p, a, 0x25B);
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x15C, func_021D5440(a), 0xffff0000);
}


void func_021C54FC(u8 *p, u8 *a)
{
    u8 v = func_021D62D8((struct UtilSlots *)a, 7);
    func_021C5480(p, a, 0x25C);
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x14d, func_021D5440(a), v, 0xffff0000);
}

void func_021C5540(u8 *p, u8 *a, int c)
{
    int n;
    n = func_021D5440(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x36, n);
    func_021C5B74(p, a, (int)(0u - (u32)c), 1);
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x50, n, 0xffff0000);
}
