/*
 * file:     unit_021E53E4.c
 * unit:     yes
 * function: func_021E53E4, func_021E541C, func_021E5428, func_021E5460, func_021E546C, func_021E54A0
 * address:  0x021E53E4
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
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 *   d_021F260C     0x021F260C  data   ov093  a4
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021B9A50  0x021B9A50  thumb  ov093
 *   d_021F2604     0x021F2604  data   ov093  a4
 *   d_021F243C     0x021F243C  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

extern Word func_021E8940(int k);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021E556C(int a, int b, int c, int d, int e, int f, Word g, int h);
extern Word func_021E89C0(void);
extern unsigned char func_021B9A50(unsigned int x);
void func_021E53E4(int a, int b, int c, int d);
int *func_021E541C(int *p);
void func_021E5428(int a, int b, int c, int d);
int *func_021E5460(int *p);
void func_021E546C(int a, int b, int c, int d);
int *func_021E54A0(int *p);
extern int d_021F260C[];
extern int d_021F2604[];
extern int d_021F243C[];



/*
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void func_021E53E4(int a, int b, int c, int d)
{
    Word t = func_021E8940(4);
    int e = func_021B9A40(c);
    func_021E556C(a, b, c, d, e, 4, t, 0x8c);
}



int *func_021E541C(int *p)
{
    *p = 1;
    return d_021F260C;
}



void func_021E5428(int a, int b, int c, int d)
{
    Word t = func_021E8940(5);
    int e = func_021B9A40(c);
    func_021E556C(a, b, c, d, e, 5, t, 0x90);
}


int *func_021E5460(int *p)
{
    *p = 1;
    return d_021F2604;
}


void func_021E546C(int a, int b, int c, int d)
{
    Word t = func_021E89C0();
    int e = func_021B9A50(c);
    func_021E556C(a, b, c, d, e, 6, t, 0x94);
}


int *func_021E54A0(int *p)
{
    *p = 1;
    return d_021F243C;
}
