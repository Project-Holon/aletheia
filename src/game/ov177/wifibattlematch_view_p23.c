/*
 * file:     wifibattlematch_view_p23.c
 * unit:     yes
 * function: func_021E8848, func_021E8870, func_021E888C
 * address:  0x021E8848
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_021E88B0  0x021E88B0  thumb  ov177
 */
struct Cfg;
struct Descriptor;
struct CharBuf;
typedef struct {
    char pad0[0x10];
    int  f10;
    int  f14;
    char pad1[0x18];
    int  f30;
} S_021E8848;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct {
    char           pad0[0x14];
    int            f14;
    char           pad1[4];
    unsigned short f1c;
} S_021E8870;

typedef struct {
    char           pad0[0x1c];
    unsigned int f1c;
} S_021E888C;

extern void func_0202F038(u8 *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void func_021E88B0(S_021E888C *, int, unsigned char, int, int, int);
void func_021E8848(S_021E8848 *p);
void func_021E8870(S_021E8870 *p);
void func_021E888C(S_021E888C *p, int a);


void func_021E8848(S_021E8848 *p)
{
    p->f30 = 1;
    if (p->f10 != 0) {
        func_0202F038((u8 *)p->f10);
        p->f10 = 0;
        func_02045374((struct Cfg *)p->f14);
        func_020409B4(func_02045730((struct Descriptor *)p->f14));
    }
}


void func_021E8870(S_021E8870 *p)
{
    int r = (int)func_02045770((struct Descriptor *)p->f14);

    func_02043B5C((struct CharBuf *)r, (unsigned char)p->f1c);
    func_02045334((struct Descriptor *)p->f14);
}


void func_021E888C(S_021E888C *p, int a)
{
    int v = (p->f1c & 0x7f) << 1;

    func_021E88B0(p, 0x13, 0x11 - v, 0xc, v, a);
}
