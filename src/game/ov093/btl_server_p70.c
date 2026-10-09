/*
 * file:     btl_server_p70.c
 * unit:     yes
 * function: func_021C54BC, func_021C54C8, func_021C54FC, func_021C5540, func_021C557C, func_021C5604, func_021C5620
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
 *   func_021D61F0  0x021D61F0  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021C5698  0x021C5698  thumb  ov093
 *   func_021D6238  0x021D6238  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj06227.h"
#include "../../matched/include/Obj00003.h"

struct UtilSlots;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Slot { u32 kind : 3; u32 rest : 29; };

extern void func_021C5D88(u8 *, u8 *, int);
extern void func_021C5480(u8 *p, u8 *a, int b);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5B74(u8 *, u8 *, int, int);
extern void func_021D61F0(struct UtilSlots *p);
extern struct Slot func_021D6314(u8 *p, int i);
extern int func_021C5698(void *p, int v);
extern void func_021D6238(struct UtilSlots *p, int k);
void func_021C54BC(u8 *p, u8 *a);
void func_021C54C8(u8 *p, u8 *a);
void func_021C54FC(u8 *p, u8 *a);
void func_021C5540(u8 *p, u8 *a, int c);
void func_021C557C(u8 *p, u8 *a, int k, int flag);
void func_021C5604(u8 *p, u8 *a, int b);
void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);



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




void func_021C557C(u8 *p, u8 *a, int k, int flag)
{
    u8 n = func_021D5440(a);
    func_021D61F0((struct UtilSlots *)a);
    func_021CD4B0(((struct Obj06227 *)p)->fC, 0x10, n);
    func_021CD4B0(((struct Obj06227 *)p)->fC, 0x35, n, 0);
    if (flag != 0) {
        switch (k) {
        case 2:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x138, n, 0xffff0000);
            break;
        case 3:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x126, n, 0xffff0000);
            break;
        default:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x156, n, 0xffff0000);
            break;
        }
    }
}




void func_021C5604(u8 *p, u8 *a, int b)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x59, func_021D5440(a), b);
}

void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out)
{
    u8 n;
    if (k != 0) {
        n = func_021D5440(a);
        if (out != 0) *out = func_021D6314(a, k);
        if (k < 6) {
            func_021D61F0((struct UtilSlots *)a);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x10, n);
            if (func_021C5698(p + 0x1AB8, n) != 6) {
                func_021CD4B0(((struct Obj00003 *)p)->fC, 0x35, n, 0);
            }
        } else {
            func_021D6238((struct UtilSlots *)a, k);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x11, n, (u16)k);
        }
    }
}
