/*
 * file:     unit_021E54EC.c
 * unit:     yes
 * function: func_021E54EC, func_021E5520, func_021E552C, func_021E556C, func_021E55B8
 * address:  0x021E54EC
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
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   func_021B9A50  0x021B9A50  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E3C5C  0x021E3C5C  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2484     0x021F2484  data   ov093  a4
 *   d_021F2DF8     0x021F2DF8  data   ov093  a4
 */
#include "../../matched/include/Obj13525.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

extern Word BTLV_CORE_MakeSlotKind1Empty(void);
extern unsigned char func_021B9A50(unsigned int x);
extern Word BTLV_CORE_MakeSlotKind2Index(int v);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021E3C5C(void *a, int b, int c);
extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
void func_021E54EC(int a, void *b, int c, int d);
int *func_021E5520(int *p);
void func_021E552C(int a, int b, int c, int d);
void func_021E556C(int a, void *b, int c, int d, u8 e, int f, Word g, u16 h);
int *func_021E55B8(int *p);
extern int d_021F2484[];
extern int d_021F2DF8[];


/*
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void func_021E54EC(int a, void *b, int c, int d)
{
    Word t = BTLV_CORE_MakeSlotKind1Empty();
    u8 e = func_021B9A50(c);
    func_021E556C(a, b, c, d, e, 8, t, 0x9c);
}


/*
 * volatile: 0x04000060 reread at 021E552E, 021E553E, 021E554A, 021E5556; 0x04000008 display register; 0x04000580 hardware store at 021E557A.
 */
int *func_021E5520(int *p)
{
    *p = 4;
    return d_021F2DF8;
}


void func_021E552C(int a, int b, int c, int d)
{
    Word t;

    t = BTLV_CORE_MakeSlotKind2Index(1);
    func_021E556C(a, (void *)b, c, d, func_021B9A40(c), 9, t, 0xa0);
    func_021E3C5C((void *)b, c, 1);
}



void func_021E556C(int a, void *b, int c, int d, u8 e, int f, Word g, u16 h)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (u8 *)func_021C88A4(b, 0x19, c);
        ((struct Obj13525 *)m)->f4 = f;
        m[0xc] = e;
        *(Word *)(m + 8) = g;
        func_021C8838(m + 0x10, 1, h);
        func_021C8860((struct S *)(m + 0x10), e);
        func_021C88C8(b, m);
    }
}



int *func_021E55B8(int *p)
{
    *p = 1;
    return d_021F2484;
}
