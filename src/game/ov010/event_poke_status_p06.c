/*
 * file:     event_poke_status_p06.c
 * unit:     yes
 * function: func_021595CC, func_02159644, func_02159658, func_02159670, func_021596B4, func_021596E8
 * address:  0x021595CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_0215A5D4  0x0215A5D4  thumb  ov010
 *   func_0215A5D8  0x0215A5D8  thumb  ov010
 *   func_02159B38  0x02159B38  thumb  ov010
 *   func_021589A0  0x021589A0  thumb  ov010
 *   func_0215AA48  0x0215AA48  thumb  ov010
 *   func_0215AA24  0x0215AA24  thumb  ov010
 *   func_0215AA34  0x0215AA34  thumb  ov010
 *   func_02158A34  0x02158A34  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021595A0  0x021595A0  thumb  ov010
 *   func_02011290  0x02011290  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_02011398  0x02011398  thumb
 *   d_021705DC     0x021705DC  data  ov010
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_02012B38   0x02012B38  thumb
 *   func_02014474   0x02014474  thumb
 */
#include "../../matched/include/Obj00005.h"

struct Stream;
struct Cursor;
struct Ring;
struct Cur;
struct BigObj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

struct P { int _0[3]; u8 _p[2]; u8 e; u8 _f[5]; u8 *cur; };

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern u16 func_02011330(struct Stream *s);
extern u32 func_0215A5D4(void *p);
extern u32 func_0215A5D8(void *p);
extern int func_02159B38(int);
extern int func_021589A0(int a, int b, int c);
extern void func_0215AA48(void *p, int v);
extern void *func_0215AA24(int a0);
extern int func_0215AA34(int a0);
extern void func_02158A34(void *, void *, int, int);
extern void func_020113D0(char *p, int val);
extern int func_021595A0(int a0, int a1);
extern int func_02011290();
extern int func_0201134C();
extern int func_020113B0();
extern unsigned int func_02011398(struct Ring *r);
extern void func_020113B4(struct Ring *r, u32 v);
extern void *func_0215A5E4(void *a0);
extern void *func_02012B38(const struct BigObj *p);
extern void func_02014474(void *, void *);
int func_021595CC(int a, int b);
int func_02159644(int a0, int a1);
int func_02159658(int a0, int a1, int a2);
int func_02159670(struct P *p);
int func_021596B4(struct P *p);
int func_021596E8(void *a0, void *a1);
extern u8 d_021705DC[][3];


int func_021595CC(int a, int b)
{
    void *x = func_0215A5DC((void *)b);
    void *y = func_0215A5F4((void *)b);
    int z = func_02011330((struct Stream *)a);
    if (func_0215A5D4((void *)b) == 0) {
        func_0215AA48((void *)b, func_021589A0((int)y, func_02159B38(b), z));
        func_0215AA24(b);
        func_020113D0((char *)a, (int)func_021595A0);
        return 1;
    }
    func_0215AA24(b);
    func_02158A34(x, y, z, func_0215A5D8((void *)b));
    func_0215AA34(b);
    return 0;
}


int func_02159644(int a0, int a1)
{
    int t4;
    void *v0;

t4 = a0 + 0;
a0 = a1 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215964E:
a0 = t4 + 0;
    a0 = func_02011290(a0);
loc_02159654:
a0 = 1;
    return a0;}


int func_02159658(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0201134C(a0);
loc_02159660:
a2 = a0 + 0;
a1 = *(int *)&((struct Obj00005 *)t4)->f14;
a0 = t4 + 0;
a1 = a1 + a2;
    a0 = func_020113B0(a0, a1, a2);
loc_0215966C:
a0 = 0;
    return a0;}


int func_02159670(struct P *p)
{
    u8 *q = p->cur;
    u8 c = *q;
    int n;
    p->cur = q + 1;
    n = func_0201134C((struct Cursor *)p);
    if (c == 0xFF) {
        if (func_02011398((struct Ring *)p) == 1)
            goto end;
    } else {
        if (d_021705DC[c][p->e] != 1)
            goto end;
    }
    func_020113B0((struct Cur *)p, (u32)(p->cur + n));
end:
    return 0;
}

/*
 * prototype: 020113B4's matched ARM9 unit copies the full-word second
 * input unchanged into +0x14; original caller supplies a cursor address.
 * Pointer declaration preserves that payload and matches the fixed flags.
 */
int func_021596B4(struct P *p)
{
    u8 *q = p->cur;
    u8 c = *q;
    int n;
    p->cur = q + 1;
    n = func_0201134C((struct Cursor *)p);
    if (d_021705DC[c][p->e] == 1)
        func_020113B4((struct Ring *)p, (u32)(p->cur + n));
    return 0;
}


/*
 * The record's arm9 handle and the caller's second argument are the two
 * operands of the arm9 pair call.
 */
int func_021596E8(void *a0, void *a1)
{
    void *v = (void *)func_02011330(a0);

    func_02014474(func_02012B38(func_0215A5E4(a1)), v);

    return 0;
}
