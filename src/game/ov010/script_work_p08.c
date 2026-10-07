/*
 * file:     script_work_p08.c
 * unit:     yes
 * function: func_021588D0, func_021588DC, func_02158920, func_0215897C, func_0215898C, func_021589A0, func_021589D0, func_021589DC, func_021589F4
 * address:  0x021588D0
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
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0215882C  0x0215882C  thumb  ov010
 *   func_02158F18  0x02158F18  thumb  ov010
 *   func_021588C0  0x021588C0  thumb  ov010
 *   func_021588B0  0x021588B0  thumb  ov010
 *   func_02158824  0x02158824  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02158804  0x02158804  thumb
 *   func_02158E7C  0x02158E7C  thumb
 *   func_02158F94  0x02158F94  thumb
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_021588A4 0x021588A4 thumb ov010
 *   func_02158BFC 0x02158BFC thumb ov010
 *   func_0215886C 0x0215886C thumb ov010
 *   func_02014368  0x02014368  thumb
 *   func_020143D8  0x020143D8  thumb
 */
#include "../../matched/include/Obj12030.h"
#include "../../matched/include/Obj17626.h"
#include "../../matched/include/Obj01023.h"

struct Ctx;
struct Rec44;
struct Desc;
struct Obj;
struct Evt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

extern u8 *func_020120F8(const struct Ctx *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern int func_0215882C(int a0);
extern int func_02158F18(int a0);
extern int func_021588C0(int a0);
extern int func_021588B0();
extern int func_02158824();
extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02158804(u32 heap);
extern int *func_02158E7C(u16 a, int b, int c, int d, int e, int f);
extern void func_02158F94(void *p, void *q);
extern void *func_02158F50(void *vm);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_021588A4(void *, int);
extern int *func_02158BFC(int a0, int a1, int a2, int a3, int a4);
extern int func_0215886C(int a0, int a1);
extern int func_02014368();
extern int func_020143D8();
int func_021588D0(int a0);
int func_021588DC(int a0, int a1, int a2);
struct Desc *func_02158920(int a, int b, int c, int d, int e);
void func_0215897C(void *vm, void *task);
void func_0215898C(int a, int b);
int func_021589A0(int a, int b, int c);
int func_021589D0(int a0);
int func_021589DC(int a0);
int func_021589F4(int a0);


int func_021588D0(int a0)
{
    u8 *p;

    p = func_020120F8((const struct Ctx *)a0);
loc_021588D6:
    a0 = func_02012AC8((const struct Rec44 *)p);
loc_021588DA:
    return a0;}


int func_021588DC(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = ((struct Obj12030 *)a2)->f4;
t6 = a0 + 0;
a0 = t5 + 0;
t4 = ((struct Obj12030 *)((char *)a2))->f0;
    a0 = func_0215882C(a0);
loc_021588EA:
    if (a0 != 1) goto loc_021588F2;
loc_021588EE:
a0 = 0;
    return a0;
loc_021588F2:
a0 = t4 + 0;
    a0 = func_02158F18(a0);
loc_021588F8:
a0 = t5 + 0;
    a0 = func_021588C0(a0);
loc_021588FE:
    if (a0 != 1) goto loc_02158914;
loc_02158902:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_021588B0(a0, a1);
loc_0215890A:
a0 = t5 + 0;
    a0 = func_02158824(a0);
loc_02158910:
a0 = 0;
    return a0;
loc_02158914:
a0 = t5 + 0;
    a0 = func_02158824(a0);
loc_0215891A:
a0 = 1;
    return a0;}


struct Desc *func_02158920(int a, int b, int c, int d, int e)
{
    struct Desc *h = func_020122C0((void *)a, 0, (void *)func_021588DC, 8);
    void **w = func_020124E8((struct Obj *)h);
    w[1] = func_02158804(4);
    w[0] = func_02158E7C(4, a, (int)h, c, e, 0);
    func_02158F94(w[0], (void *)d);
    func_021589A0((int)w[0], func_021588D0(a), c);
    return h;
}


/*
 * Queue a task on the script's event list.
 */
void func_0215897C(void *vm, void *task)
{
    func_02012374(func_02158F50(vm), task);
}

void func_0215898C(int a, int b) {
    void *p = (void *)func_021589DC(a);
    if (p != 0) func_021588A4(p, b);
}

/*
 * Extent ends in two alignment padding bytes.
 */
int func_021589A0(int a, int b, int c) {
    u16 *p = (u16 *)func_021589DC(a);
    if (p) return func_0215886C((int)p, (int)func_02158BFC(*p, a, b, c, 0));
    return 3;
}


int func_021589D0(int a0)
{
    void *p;

    p = func_020124E8((struct Obj *)a0);
loc_021589D6:
a0 = ((struct Obj17626 *)p)->f0;
    return a0;}


int func_021589DC(int a0)
{
    void *p;

    p = func_02158F50((void *)a0);
loc_021589E2:
    if (p != 0) goto loc_021589EA;
loc_021589E6:
a0 = 0;
    return a0;
loc_021589EA:
    p = func_020124E8((struct Obj *)p);
loc_021589EE:
a0 = *(int *)&((struct Obj01023 *)p)->f4;
    return a0;}


int func_021589F4(int a0)
{
    int a1;
    int a2;
    int t4;

a1 = 0;
a2 = 0x63;
t4 = a0 + 0;
    a0 = func_02014368(a0, a1, a2);
loc_02158A00:
a1 = 1;
a1 = a1 << 0xe;
a2 = a1 + 0;
a0 = t4 + 0;
a2 = a2 + 0x1f;
    a0 = func_020143D8(a0, a1, a2);
loc_02158A0E:
    return a0;}
