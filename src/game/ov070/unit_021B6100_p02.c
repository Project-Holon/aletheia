/*
 * file:     unit_021B6100_p02.c
 * unit:     yes
 * function: func_021B621C, func_021B624C, func_021B6288, func_021B6300
 * address:  0x021B621C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_02008298  0x02008298  thumb
 *   func_02008288  0x02008288  thumb
 *   func_02008270  0x02008270  thumb
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_021BAF38  0x021BAF38  thumb  ov070
 *   func_021BA96C  0x021BA96C  thumb  ov070
 *   func_021BAAA4  0x021BAAA4  thumb  ov070
 */
struct MyItemSave;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef struct Obj_021B6288 {
    unsigned char pad000[0x14];
    void *gfx;
    unsigned char pad018[0x810 - 0x18];
    int f810;
    int f814;
} Obj_021B6288;

typedef struct Obj_021B6300 {
    unsigned char pad000[0x810];
    int a;
    int b;
} Obj_021B6300;

extern void MI_CpuCopy8(const void *, void *, unsigned int);
extern void func_02008298(struct MyItemSave *p, u16 v);
extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern void func_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b);
extern void func_021BA6A4(char *p);
extern void func_021BAF38(int p, int val);
extern void func_021BA96C(int p, unsigned sel);
extern void func_021BAAA4(int p, int mode);
void func_021B621C(u8 *p, int a, int b);
void func_021B624C(void *p, int a, int b);
void func_021B6288(Obj_021B6288 *o, int a, int b);
int func_021B6300(Obj_021B6300 *o, int n, int k);

void func_021B621C(u8 *p, int a, int b)
{
    int tmp;
    MI_CpuCopy8(p + 0x20 + (int)((unsigned int)a * 4U), &tmp, 4);
    MI_CpuCopy8(p + 0x20 + (int)((unsigned int)b * 4U), p + 0x20 + (int)((unsigned int)a * 4U), 4);
    MI_CpuCopy8(&tmp, p + 0x20 + (int)((unsigned int)b * 4U), 4);
}

void func_021B624C(void *p, int a, int b)
{
    if (a == b) return;
    if (a < b) {
        for (; a < b; a++) func_021B621C(p, a, a + 1);
    } else {
        for (; a > b; a--) func_021B621C(p, a, a - 1);
    }
}


void func_021B6288(Obj_021B6288 *o, int a, int b)
{
    s16 s[2];

    func_02008298(o->gfx, a);
    func_02008288(o->gfx, (u16)a, o->f810, o->f814 + 1);
    func_02008270(o->gfx, (u16)b, &s[1], &s[0]);
    o->f810 = s[1];
    o->f814 = s[0] - 1;
    func_021BA6A4((char *)o);
    func_021BAF38((int)o, b);
    func_021BA96C((int)o, b);
    func_021BAAA4((int)o, b);
}


int func_021B6300(Obj_021B6300 *o, int n, int k)
{
    int a, b;

    if (n == 0)
        return 0;
    a = o->a;
    b = o->b;
    if (a == 5 && b + 7 < n) {
        o->b = o->b + 1;
    } else if (a != 5 && a + 1 < n) {
        o->a = o->a + 1;
    } else if (k == 1) {
        o->b = -1;
        o->a = 0;
    }
    return a != o->a || b != o->b;
}
