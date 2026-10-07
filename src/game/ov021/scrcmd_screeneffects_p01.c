/*
 * file:     scrcmd_screeneffects_p01.c
 * unit:     yes
 * function: func_021AE66C, func_021AE6E0
 * address:  0x021AE66C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 */
typedef struct Task {
    int state;              /* 0x00 */
    int f04;
    void *f08;              /* 0x08 */
    int f0C[4];
    int f1C;                /* 0x1C */
    int f20;
    int f24;                /* 0x24 */
    int f28[3];
    unsigned char *f34;     /* 0x34 */
} Task;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct S { u32 f0; u8 pad[0x30]; u8 *f34; } S;

extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *x);
extern int func_0216D86C(void *x);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern u16 func_0216D5F8(void *p);
extern int func_0216D3CC(int a0);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a, int b);
extern int func_0216D454(void *a);
extern int func_0216D480(char *p);
int func_021AE66C(Task *p);
int func_021AE6E0(S *s);


int func_021AE66C(Task *p)
{
    void *r4 = func_021A3074(p->f34);
    int r6 = func_0216D83C(r4);
    int r7 = func_0216D86C(r4);
    int t = func_0216D83C(p->f08);

    r6 = func_021642B4(r6, r7, t, func_0216D86C(p->f08));
    if (r6 != func_0216D5F8(r4) && (p->f24 == 0 || p->f1C == 2)) {
        if (func_0216D3CC((int)r4) == 1) {
            func_0216D410(r4, func_02197E7C(r6, 0));
            p->state = 0xf;
        }
    } else {
        p->state = 0x10;
    }
    return 0;
}


int func_021AE6E0(S *s)
{
    void *t = func_021A3074(s->f34);

    if (func_0216D454(t) == 0)
        return 0;
    func_0216D480(t);
    s->f0 = 0x10;
    return 1;
}
