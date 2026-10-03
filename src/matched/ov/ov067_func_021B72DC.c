/*
 * function: func_021B72DC
 * address:  0x021B72DC
 * packet:   pkt_021B72DC
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct S {
    u8 _0[0x14];
    u8 f14;
    u8 _15[0x18 - 0x15];
    u8 f18;
    u8 _19[0x88 - 0x19];
    void *f88;
    void *f8c;
    u8 _90[0x98 - 0x90];
    u32 f98;
    u8 _9c[0xa0 - 0x9c];
    void *arrA0[4];
};

extern void func_02040588(u32 which, u32 enable);
extern int func_02045770(int a);
extern void func_02043B5C(int a, int b);
extern void func_02045334(int a);
extern void func_02045374(int a);
extern int func_02045730(int a);
extern void func_02041B6C(u32 bit);
extern void func_0204B3DC(int a, int b);
extern void func_0204B92C(int a, int b);

void func_021B72DC(struct S *s)
{
    int p;
    u8 i;

    func_02040588(s->f14, 0);
    func_02040588(s->f18, 0);
    func_02043B5C(func_02045770((int)s->f88), 0);
    func_02043B5C(func_02045770((int)s->f8c), 0);
    p = (int)s->f88;
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
    p = (int)s->f8c;
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
    for (i = 0; i < 4; i++) {
        func_0204B3DC((int)s->arrA0[i], 0);
        func_0204B92C((int)s->arrA0[i], 0);
    }
    s->f98 = 0;
}
