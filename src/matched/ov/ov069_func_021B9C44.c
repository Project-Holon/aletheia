/*
 * function: func_021B9C44
 * address:  0x021B9C44
 * packet:   pkt_ov069_021B9C44
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021BA874  0x021BA874  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u32 f0;
    u8 f4, f5, f6, f7;
    u16 f8;
} Ent;

typedef struct Obj {
    unsigned char pad000[0x10];
    int b[10];
    int a[8];
} Obj;

extern Ent *d_021BA874[];

extern void func_02045088(int);
extern int func_020450F0(u8, int, int, int, int, u8, int);
extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_02045334(int);
extern void func_02045374(int);
extern void func_02045730(int);
extern void func_020409B4(void);

void func_021B9C44(Obj *o)
{
    int i;
    int j;
    int h;
    Ent *e;

    func_02045088(0x80);
    for (i = 0; i < 8; i++) {
        e = d_021BA874[i];
        o->a[i] = func_020450F0(e->f0, e->f4, e->f5, e->f6, e->f7, e->f8, 1);
        func_02043B5C(func_02045770(o->a[i]), 0);
        h = o->a[i];
        func_02045334(h);
        func_02045374(h);
        func_02045730(h);
        func_020409B4();
    }
    for (j = 0; j < 10; j++) {
        o->b[j] = func_020450F0(1, 2, 1, 10, 2, 1, 1);
        func_02043B5C(func_02045770(o->b[j]), 4);
    }
}
