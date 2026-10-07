/*
 * file:     btl_server_p53.c
 * unit:     yes
 * function: func_021C2250, func_021C2314
 * address:  0x021C2250
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
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D5B44  0x021D5B44  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C7AD0  0x021C7AD0  thumb  ov093
 *   func_021C7B0C  0x021C7B0C  thumb  ov093
 *   func_021C60EC  0x021C60EC  thumb  ov093
 *   func_021C6134  0x021C6134  thumb  ov093
 *   func_021DCF24  0x021DCF24  thumb  ov093
 *   func_021DCF5C  0x021DCF5C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D6730  0x021D6730  thumb  ov093
 *   func_021C5BE4 0x021C5BE4 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct QI;
struct QK;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
extern u16 func_021D5B40(struct QI *p);
extern void func_021D5B44(struct QI *p, u16 v);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C7AD0(u8 *p, u8 *a, u32 b);
extern void func_021C7B0C(u8 *p, u8 *a);
extern void func_021C60EC(u8 *p, u8 *a, u32 n);
extern void func_021C6134(u8 *p, u8 *a, unsigned int n);
extern void func_021DCF24(u8 *a);
extern void *func_021DCF5C(void *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D6730(struct QK *p, u16 v);
extern void func_021C5BE4(u8 *, u8 *, int);
extern int func_021C4F64(u8 *, u8 *);
void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
int func_021C2314(u8 *p, u8 *a);


void func_021C2250(u8 *p, u8 *a, u16 b, u32 c)
{
    u32 s;
    u16 t;
    int name;
    name = func_021D5440(a);
    t = (u16)(int)func_021D5B40((struct QI *)a);
    s = func_021CC8D8(p + 0x1D74, 7469);
    func_021C7AD0(p, a, b);
    func_021CC95C((u32 *)(p + 0x1D74), s, 7471);
    if (b == 0)
        func_021C60EC(p, a, 15);
    func_021DCF24(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x1E, name, b);
    func_021D5B44((struct QI *)a, b);
    if (b != 0)
        func_021DCF5C(a);
    s = func_021CC8D8(p + 0x1D74, 7485);
    func_021C7B0C(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), s, 7487);
    if (c != 0) {
        func_021D6730((struct QK *)a, t);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x17, name, t);
        func_021C6134(p, a, 8);
    }
}

/*
 * extent: two zero alignment bytes follow the return at 0x021C232A.
 * interface: func_021C5BE4 reads r0/r1/r2 and forwards r2 unchanged;
 * func_021C4F64 has two arguments in its existing DIFF note.
 */
int func_021C2314(u8 *p, u8 *a)
{
    func_021C5BE4(p, a, 0);
    return func_021C4F64(p, a);
}
