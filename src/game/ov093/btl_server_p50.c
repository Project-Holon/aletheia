/*
 * file:     btl_server_p50.c
 * unit:     yes
 * function: func_021C36A0, func_021C36E8, func_021C3720, func_021C376C
 * address:  0x021C36A0
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
 *   func_021D5FB8  0x021D5FB8  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C604C 0x021C604C thumb ov093
 *   func_021C16F8 0x021C16F8 thumb ov093
 *   func_021D6D90  0x021D6D90  thumb  ov093
 *   func_021C41C0  0x021C41C0  thumb  ov093
 *   func_021C37E0  0x021C37E0  thumb  ov093
 *   func_021C37F0  0x021C37F0  thumb  ov093
 *   func_021C3800  0x021C3800  thumb  ov093
 *   func_021C3810  0x021C3810  thumb  ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 */
#include "../../matched/include/Obj09970.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21090.h"

struct Msg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } Q;

extern u8 func_021D5440(u8 *p);
extern void func_021D5FB8(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C604C(u8 *, u8 *, int);
extern void func_021C16F8(u8 *, u8 *, int);
extern int func_021D6D90(u8 *p);
extern void func_021C41C0(u8 *p, u8 *a);
extern void func_021C37E0(int it);
extern int func_021C37F0(int it);
extern int func_021C3800(int it);
extern int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg);
extern void func_021C5718(u8 *p, int b, int c);
void func_021C36A0(u8 *p, u8 *a, u16 *b, int c);
void func_021C36E8(u8 *p, u8 *q, u16 *r, int a, int b, u16 c);
u16 func_021C3720(u8 *p, u8 *a, u16 *b, int c);
void func_021C376C(u8 *p, u16 a1, int b, int it);


void func_021C36A0(u8 *p, u8 *a, u16 *b, int c)
{
    int i = func_021D5440(a);
    func_021D5FB8(a);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 3, i);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 0x32, i, (u8)c, *b);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 0x34, i);
}


/*
 * The final 00 00 at 0x021C371E is alignment padding before 0x021C3720.
 * A separate call-result local keeps the halfword load before that call.
 */
void func_021C36E8(u8 *p, u8 *q, u16 *r, int a, int b, u16 c)
{
    int n;
    int v;
    func_021C604C(p, q, c);
    n = *r;
    v = func_021D5440(q);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x32, v, (u8)a, n);
    func_021C16F8(p, q, b);
}



u16 func_021C3720(u8 *p, u8 *a, u16 *b, int c)
{
    int i = func_021D5440(a);
    u16 v = func_021D6D90(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x34, i);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x32, i, (u8)c, *b);
    func_021C41C0(p, a);
    return v;
}



void func_021C376C(u8 *p, u16 a1, int b, int it)
{
    int v = 0;
    int r;
    func_021C37E0(it);
    r = func_021C37F0(it);
    while (r) {
        if (func_021C3810(p, (u8 *)b, (u8 *)r, 0, &v, 0, 0, 0)) {
            Q *q = *(Q * *)&((struct Obj21090 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
        } else if (v == 0) {
            func_021C5718(p, b, a1);
        }
        r = func_021C3800(it);
    }
}
