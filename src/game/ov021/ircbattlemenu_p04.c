/*
 * file:     ircbattlemenu_p04.c
 * unit:     yes
 * function: func_02197E7C, func_02197EB4, func_02197EDC, func_02197F20, func_02197F5C, func_02197F6C
 * address:  0x02197E7C
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
 *   d_021D5D6C     0x021D5D6C  data  a4
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_0216D7D4  0x0216D7D4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   d_021D624C     0x021D624C  data  a4
 *   d_021D5F58     0x021D5F58  data  a4
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u16 func_0216D7C4(u8 *p);
extern u16 func_0216D7D4(u8 *p);
extern u32 func_0216D57C(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern void func_0216D7C0(void *p, u16 v);
extern void *func_0216D7C8(void *p, u16 v);
extern int func_0216D55C(int a0, int a1);
extern void *func_0216D568(void *p, u32 v);
extern int func_02163F10(int a0);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216D7CC(u32);
int func_02197E7C(int a, int b);
void func_02197EB4(u32 a);
u32 func_02197EDC(u8 *p);
int func_02197F20(u32 a, u32 b, u32 c);
int func_02197F5C(u32 a, u32 b, u32 c, u32 d);
int func_02197F6C(u32 a, u32 b);
extern int *d_021D5D6C[];


/*
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the
 * ov021 table is a data start that another overlay mapped over the same
 * window also starts an object at, so the symbols hint is contested.  No C
 * change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * Addresses are Black-image addresses.
 */
int func_02197E7C(int a, int b)
{
    int i;
    int **p;
    int *q;

    p = d_021D5D6C;
    do {
        q = *p;
        for (i = 0; i < 4; i++) {
            if (b == q[i]) {
                return (u16)q[a];
            }
        }
        p++;
    } while (*p != 0);
    return b;
}



/*
 * Addresses are Black-image addresses.
 */
void func_02197EB4(u32 a)
{
    u32 r;

    do {
        r = func_0216D7C4((u8 *)a);
        if (r == 0xFF) {
            return;
        }
    } while (func_02197F20(a, r, func_0216D7D4((u8 *)a)) != 0);
}



u32 func_02197EDC(u8 *p)
{
    if (func_0216D7C4(p) != 0xff) {
        func_02197EB4((u32)p);
        if (func_0216D57C(p, 0x400) == 0) {
            return 0;
        }
    }
    func_0216D570((char *)p, 0x400);
    func_0216D7C0(p, 0xff);
    func_0216D7C8(p, 0);
    return 1;
}


extern int (**const d_021D624C[])(u32);


extern int (**const d_021D5F58[])(u32);



int func_02197F20(u32 a, u32 b, u32 c)
{
    if (func_0216D55C(a, 0x2000) != 0) {
        return d_021D624C[b][c](a);
    }
    return d_021D5F58[b][c](a);
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197F5C(u32 a, u32 b, u32 c, u32 d)
{
func_0216D568((void *)a, (1 << 10));
return 0;
}



/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197F6C(u32 a, u32 b)
{
func_0216D5E0(a, ((b << 16) >> 16));
func_0216D674((void *)a, 0);
func_02163F10(a);
return func_0216D7CC(a);
}
