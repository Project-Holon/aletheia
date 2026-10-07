/*
 * file:     unit_02198D3C_p27.c
 * unit:     yes
 * function: func_0219B334, func_0219B358, func_0219B374, func_0219B390, func_0219B404, func_0219B414
 * address:  0x0219B334
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
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   d_021D4FCC     0x021D4FCC  data    a4
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0219B440  0x0219B440  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u16 func_0216D5A8(u8 *p);
extern u16 func_0216D5F8(void *p);
extern int func_0216D55C(int a, int b);
extern void func_0216D5E0(int a0, int a1);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 *func_0216D550(u32 *p, u32 v);
extern int func_0219B440(char *a);
int func_0219B334(u32 a);
int func_0219B358(u32 a);
void func_0219B374(u32 a, u8 *s);
void func_0219B390(int a, s8 *b);
void func_0219B404(u32 a, u8 *s);
int func_0219B414(int a);
extern u32 d_021D4FCC[][4];


int func_0219B334(u32 a)
{
    u32 v = func_0216D5A8((u8 *)a);
    if (v == 13 || (u16)(v + 0xFFF1) <= 4) {
        return 1;
    }
    return 0;
}


int func_0219B358(u32 a)
{
    u32 v = func_0216D5A8((u8 *)a);
    if (v == 7 || v == 8 || v - 17 <= 1) {
        return 1;
    }
    return 0;
}


void func_0219B374(u32 a, u8 *s)
{
    u32 v = func_0216D5A8((u8 *)a);
    if (v == 7 || v == 17) {
        s[1] = 0;
    } else {
        s[1] = 1;
    }
}


void func_0219B390(int a, s8 *b)
{
    int i;
    u32 v;
    u32 n;

    v = func_0216D5F8((void *)a);
    for (i = 0; i < 4 && v != d_021D4FCC[b[1]][i]; i++) {
    }
    i++;
    b[0] = v;
    i %= 4;
    n = d_021D4FCC[b[1]][i];
    if (func_0216D55C(a, 8) != 0) {
        b[2] = 1;
    } else {
        b[2] = 0;
    }
    func_0216D5E0(a, (u16)n);
    func_0216D548((u32 *)a, 8);
}


void func_0219B404(u32 a, u8 *s)
{
    if (s[2] == 0) {
        func_0216D550((u32 *)a, 8);
    }
}


/*
 * Recursive MATCH unblocker: callee of func_02163010 (ov010) +000A.  An
 * unlabelled Thumb tail-call thunk that disasm.py emitted as a word run
 * (`ldr r3,[pc,#0]; bx r3; .word func_0219B440|1`), so no func_ label exists
 * for the caller to reach through `label`/`sole-ref/code`.  Matching it here
 * gives func_02163010's call site a `matched` witness.  Region hint ov021 is
 * required: ov009 overlaps 0x0219B414 but holds unrelated code there.
 */
int func_0219B414(int a)
{
    return func_0219B440((char *)a);
}
