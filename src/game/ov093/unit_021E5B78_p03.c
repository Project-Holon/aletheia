/*
 * file:     unit_021E5B78_p03.c
 * unit:     yes
 * function: func_021E5F30, func_021E5F48, func_021E5FD0
 * address:  0x021E5F30
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021C8180   0x021C8180  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5B68   0x021D5B68  thumb ov093
 *   func_021D5BB0   0x021D5BB0  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021D7090   0x021D7090  thumb ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
struct UtilWork;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

int func_021C8180(int *p);
int func_021D775C(int a);
void *func_021C7CF4(int *p, int i);
int func_021D5B68(void *p);
int func_021D5BB0(struct UtilWork *p, u32 n);
void *func_021C88A4(char *p, int a, int b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);
void func_021D7090(u8 *p);
extern void func_021D7704(int a, int b);
/* 021E5F30 shape F1: gate on func_021D775C(3) */ void func_021E5F30(int a, int b, int c);
void func_021E5F48(void *a, int b, int c, int *d);
void func_021E5FD0(int a, int b, int c, int *d);


/* 021E5F30  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E5F46; movs r0, #0x42; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
void func_021E5F30(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x42, 0);
}


/*
 * func_021C8180(b) must exceed 1, the gate is func_021D775C(3), and the
 * (u8) of func_021D775C(6) keys func_021C7CF4 for two rejection tests.  Record
 * #4 is published as a two-string record, its key goes back through the d
 * pointer, and the first argument is left for the very last call.  a and d
 * both live on the stack because all four saved registers are taken.
 */
void func_021E5F48(void *a, int b, int c, int *d)
{
    u8 k;
    void *r;
    u8 *p;

    if ((u32)func_021C8180((int *)b) <= 1)
        return;
    if (c != func_021D775C(3))
        return;
    k = (u8)func_021D775C(6);
    r = func_021C7CF4((int *)b, k);
    if (func_021D5B68(r) != 0)
        return;
    if (func_021D5BB0(r, 1) != 0)
        return;
    p = func_021C88A4((char *)b, 4, c);
    func_021C8838(p + 4, 2, 0x414);
    func_021C8860((struct S *)(p + 4), c);
    func_021C8860((struct S *)(p + 4), k);
    func_021C88C8((void *)b, p);
    *d = k;
    func_021D7090(a);
}


void func_021E5FD0(int a, int b, int c, int *d)
{
    if (*d == func_021D775C(3))
        func_021D7704(0x31, 3 << 11);
}
