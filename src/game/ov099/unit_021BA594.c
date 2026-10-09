/*
 * file:     unit_021BA594.c
 * unit:     yes
 * function: func_021BA594, func_021BA5B4, func_021BA5DC, func_021BA5F0, func_021BA60C, func_021BA648, func_021BA660, func_021BA674, func_021BA6DC, func_021BA764, func_021BA770, func_021BA78C, func_021BA794, func_021BA7BC, func_021BA7CC, func_021BA7D4, func_021BA7D8, func_021BA7F8, func_021BA804, func_021BA808, func_021BA80C, func_021BA810
 * address:  0x021BA594
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C5F44  0x021C5F44  thumb  ov127
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021BA2D4  0x021BA2D4  thumb
 *   func_021BA264  0x021BA264  thumb  ov099
 *   func_021BA2A4  0x021BA2A4  thumb  ov099
 *   func_02082BCC 0x02082BCC arm
 *   func_02049F34 0x02049F34 arm
 *   d_021C2878 0x021C2878 data ov099 a2
 *   sub_020307B0  0x020307B0  arm
 *   sub_02082BCC  0x02082BCC  arm
 *   func_02061CA4  0x02061CA4  arm
 *   d_021C287C     0x021C287C  data  ov099  a1
 *   data_021C28A8  0x021C28A8  data
 *   func_0203A574  0x0203A574  arm
 *   sub_0203A5E4  0x0203A5E4  arm
 *   data_021C28F0  0x021C28F0  data  a4
 */
#include "../../matched/include/Obj13682.h"
#include "../../matched/include/Obj06351.h"
#include "../../matched/include/Obj22018.h"
#include "../../matched/include/Obj18161.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BA594;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021BA594;

typedef int BOOL;

typedef struct {
    char pad[0x18];
    void *f18;
} S_021BA594;

typedef unsigned int u32_021BA60C;

typedef unsigned long  u32_021BA648;

typedef struct {
    char pad00[8];
    u8  f8;
    u8  f9;
    s16 fa;
} S_021BA674;

typedef signed int     s32_021BA674;

typedef unsigned int   u32_021BA674;

typedef struct {
    char pad00[0xc];
    u8  fc;
    u8  fd;
    s16 fe;
    u8  f10;
} S;

typedef struct {
    u8 a, b, c, d;
} E;

typedef unsigned long  u32_021BA764;

typedef struct {
    u32_021BA764 f00, f04;
} T;

typedef struct {
    char pad[0x0C];
    u16 *table;
} Q;

typedef signed long    s32_021BA764;

typedef struct {
    char pad[8];
    u8 f08;
    char pad2[3];
    u8 f0C;
    u8 f0D;
    u16 f0E;
    u8 f10;
} S_021BA764;

typedef struct {
    char pad[0x10];
    u8 f10;
} S_021BA78C;

typedef struct {
    char pad[0x0D];
    u8 f0D;
} S_021BA7BC;

typedef unsigned long  u32;

typedef signed long    s32;

extern void func_021C5F44(void *a, void *b);
extern int func_021C49A4(u8 *, unsigned int);
extern void func_021BA2D4(void);
extern void func_021BA264(void *a, void *b);
extern void func_021BA2A4(void *w, u8 *s);
extern void func_02082BCC(void *, u32_021BA60C, u32_021BA60C);
extern void *func_02049F34(u32_021BA60C a0, u32_021BA60C a1, u32_021BA60C a2, u32_021BA60C a3);
extern u32_021BA648 sub_020307B0(void *p);
extern void sub_02082BCC(void *p, int c, u32_021BA648 n);
extern s32_021BA674 func_02061CA4(void *p, u32_021BA674 a, u32_021BA674 b, s32_021BA674 size);
extern void func_0203A574(u32_021BA764 a, u32_021BA764 b, u32_021BA764 c, u32_021BA764 d);
extern void sub_0203A5E4(u32_021BA764 key);
void func_021BA594(char *p, int a, int b, int c);
void func_021BA5B4(void *a, int b, u8 **p);
BOOL func_021BA5DC(S_021BA594 *s);
void func_021BA5F0(void *a, char *b, u8 c);
void func_021BA60C(char *a, char *p, u32_021BA60C unused, u32_021BA60C arc);
void func_021BA648(int unused, void *p);
void func_021BA660(int unused, void *p);
void func_021BA674(S_021BA674 *s);
void func_021BA6DC(S *s);
u16 *func_021BA764(T *t, int i);
void func_021BA770(S_021BA764 *s);
void func_021BA78C(S_021BA78C *s);
void func_021BA794(u8 *p, u8 b);
void func_021BA7BC(S_021BA7BC *s);
u8 *func_021BA7CC(void);
int func_021BA7D4(void);
void func_021BA7D8(void *p);
void func_021BA7F8(char *a0);
void func_021BA804(int a, int b, int c, int d);
void func_021BA808(int a, int b, int c, int d);
void func_021BA80C(int a, int b, int c, int d);
u32 func_021BA810(int i);
extern const u16 d_021C2878[];
extern const E d_021C287C[];
extern u8 data_021C28A8[];
extern u32 data_021C28F0[];








void func_021BA594(char *p, int a, int b, int c)
{
    struct S_021BA594 { u16 a; u8 b; u8 c; } s;

    s.a = a;
    s.b = b;
    s.c = c;
    func_021C5F44(((struct Obj13682 *)p)->f59C, &s);
}







void func_021BA5B4(void *a, int b, u8 **p) {
    int c = func_021C49A4(*p, 6);
    int d = func_021C49A4(*p, 4);
    func_021BA594(a,b,c,d);
}








/*
 * True unless the pointer at +0x18 is func_021BA2D4 itself.
 */
BOOL func_021BA5DC(S_021BA594 *s)
{
    if (s->f18 != (void *)func_021BA2D4) {
        return 1;
    }

    return 0;
}








/*
 * Dispatches on the class byte: case 0 runs func_021BA264, case 1 runs
 * func_021BA2A4, then the class is recorded at +0x0B of the object.  The pair
 * is a switch, not an if/else-if chain: only the switch form lays the case
 * bodies out of line the way the image does.
 */
void func_021BA5F0(void *a, char *b, u8 c)
{
    switch (c) {
    case 0:
        func_021BA264(a, b);
        break;
    case 1:
        func_021BA2A4(a, (u8 *)b);
        break;
    }

    b[0xB] = c;
}







void func_021BA60C(char *a, char *p, u32_021BA60C unused, u32_021BA60C arc)
{
    func_02082BCC(p, 0, 20);
    ((struct Obj06351 *)p)->f0 = func_02049F34(arc, 9, (u32_021BA60C)(p + 4), (u16)(((struct Obj22018 *)a)->f4));
    p[9] = 0;
    p[8] = 15;
    ((struct Obj06351 *)p)->fA = d_021C2878[(u8)p[9]];
}








void func_021BA648(int unused, void *p)
{
    sub_020307B0(((struct Obj18161 *)p)->f0);
    sub_02082BCC(p, 0, 0x14);
}






/*
 * Runs the two arm9 setup routines on the second argument.
 */
void func_021BA660(int unused, void *p)
{
    func_021BA674((S_021BA674 *)p);
    func_021BA6DC((S *)p);
}





void func_021BA674(S_021BA674 *s)
{
    int i;
    int k;

    s->fa = s->fa - 1;
    if (s->fa <= 0) {
        k = 2;
        s->f9 = (s->f9 + 1) % 2;
        s->fa = d_021C2878[s->f9];
        if (s->f9 != 1) {
            k = 1;
        }
        for (i = 0; i < 4; i++) {
            if (s->f8 & (1 << i)) {
                func_02061CA4((void *)0xf, (i + 1) * 2 + 0xe0, (u32_021BA674)func_021BA764((T *)s, k), 2);
            }
        }
    }
}




/*
 * Lever: source order of the three table reads (fe, then a, then b)
 * decides how the pool loads and ldrb group.
 */
void func_021BA6DC(S *s)
{
    int a = 0;
    int b = 0;
    int c = 0;

    if (d_021C287C[s->fd].a == 1) {
        s->fe = s->fe - 1;
        if (s->fe <= 0) {
            c = 1;
        }
    } else if (s->f10 != 0) {
        s->f10 = 0;
        c = 1;
    }
    if (c != 0) {
        s->fd = s->fd + 1;
        if (s->fd >= 8) {
            func_021BA770((S_021BA764 *)s);
            return;
        }
        s->fe = d_021C287C[s->fd].b;
        a = d_021C287C[s->fd].c;
        b = d_021C287C[s->fd].d;
    }
    if (a != 0) {
        func_02061CA4((void *)0xf, (s->fc + 1) * 2 + 0xe0, (u32_021BA594)func_021BA764((T *)s, b), 2);
    }
}









/*
 * Halfword pointer one past index i in the table whose address the word at
 * +0xC of the second word of t holds.  The index is scaled after the +1,
 * which is why the listing is `adds r0, r1, #1; lsls r0, r0, #1`.
 */
u16 *func_021BA764(T *t, int i)
{
    Q *q = (Q *)*(u32_021BA764 **)&t->f04;

    return (u16 *)((u8 *)q->table + (i + 1) * 2);
}









/*
 * Sets bit f0C of the byte at +0x08, then clears the four fields from +0x0C.
 */
void func_021BA770(S_021BA764 *s)
{
    s->f08 = (u8)(s->f08 | (u8)(1 << s->f0C));
    s->f0C = 0;
    s->f0D = 0;
    s->f0E = 0;
    s->f10 = 0;
}








/*
 * Sets the byte at +0x10 to 1.
 */
void func_021BA78C(S_021BA78C *s)
{
    s->f10 = 1;
}








void func_021BA794(u8 *p, u8 b)
{
    if (p[0xD] != 0) {
        func_021BA770((S_021BA764 *)p);
    }

    p[0xC] = b;
    p[0x8] ^= (u8)(1 << b);
    func_021BA78C((S_021BA78C *)p);
}








/*
 * When the byte at +0x0D is set, runs the reset at func_021BA78C on the block.
 */
void func_021BA7BC(S_021BA7BC *s)
{
    if (s->f0D != 0) {
        func_021BA78C((S_021BA78C *)s);
    }
}







u8 *func_021BA7CC(void)
{
    return data_021C28A8;
}






int func_021BA7D4(void)
{
    return 9;
}





/*
 * Plays the 0x0A00 sound with the two constants and the block.
 */
void func_021BA7D8(void *p)
{
    func_0203A574(0x0A00, (u32_021BA764)func_021BA7CC(), func_021BA7D4(), (u32_021BA764)p);
}




void func_021BA7F8(char *a0)
{
    sub_0203A5E4(0xA00);
}



void func_021BA804(int a, int b, int c, int d)
{
    if (d != 0) {
        return;
    }
}



void func_021BA808(int a, int b, int c, int d)
{
    if (d != 0) {
        return;
    }
}



void func_021BA80C(int a, int b, int c, int d)
{
    if (d != 0) {
        return;
    }
}


/*
 * Word getter at index i of the table at 0x021C28F0.
 */
u32 func_021BA810(int i)
{
    return data_021C28F0[i];
}
