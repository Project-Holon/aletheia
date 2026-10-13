/*
 * file:     unit_021E535C.c
 * unit:     yes
 * function: func_021E535C, func_021E5394, func_021E53A0, func_021E53D8
 * address:  0x021E535C
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
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 *   d_021F2794     0x021F2794  data   ov093  a4
 *   d_021F25EC     0x021F25EC  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

extern Word BTLV_CORE_MakeSlotKind2Index(int k);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021E556C(int a, int b, int c, int d, int e, int f, Word g, int h);
void func_021E535C(int a, int b, int c, int d);
int *func_021E5394(int *p);
void func_021E53A0(int a, int b, int c, int d);
int *func_021E53D8(int *p);
extern int d_021F2794[];
extern int d_021F25EC[];


/*
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void func_021E535C(int a, int b, int c, int d)
{
    int e = func_021B9A40(c);
    Word t = BTLV_CORE_MakeSlotKind2Index(5);
    func_021E556C(a, b, c, d, e, 2, t, 0x84);
}


int *func_021E5394(int *p)
{
    *p = 1;
    return d_021F2794;
}


void func_021E53A0(int a, int b, int c, int d)
{
    Word t = BTLV_CORE_MakeSlotKind2Index(5);
    int e = func_021B9A40(c);
    func_021E556C(a, b, c, d, e, 3, t, 0x88);
}


int *func_021E53D8(int *p)
{
    *p = 1;
    return d_021F25EC;
}
