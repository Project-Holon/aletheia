/*
 * file:     btl_rec_p03.c
 * unit:     yes
 * function: func_021EE390, func_021EE3E8, func_021EE4B4
 * address:  0x021EE390
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
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045374 0x02045374 arm
 *   func_020454E0 0x020454E0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021EF71C 0x021EF71C thumb ov093
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02040618 0x02040618 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D590C  0x021D590C  thumb  ov093
 *   func_021EF7AC  0x021EF7AC  thumb  ov093
 */
struct Cfg;
struct Descriptor;
struct CharBuf;
typedef unsigned char u8;

struct O {
    u8 pad00[0xe0];
    int (*fe0)(void *, void *);
    int (*fe4)(void *, void *);
    void *fe8;
    int fec;
};

typedef unsigned short u16;

typedef unsigned int u32;

struct C_021EE3E8 {
    u8 pad00[8];
    void *f08;
    int f0c;
    u32 f10;
    u8 pad14[0x10];
    int f24;
    u8 pad28[0xc];
    u32 f34;
    u8 pad38[0x138];
    u16 f170, f172, f174, f176, f178, f17a, f17c;
};

typedef signed short   s16;

struct C_021EE4B4 {
    u8 pad00[0x8];
    int f08;
    int f0c;
    u8 pad10[0x14];
    int f24;
    u8 pad28[0xc];
    int f34;
    u8 pad38[0x134];
    int f16c;
    u16 f170;
    u16 f172;
    u16 f174;
    u16 f176;
    u16 f178;
    u16 f17a;
    u16 f17c;
};

extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_02045374(struct Cfg *cfg);
extern void func_020454E0(struct Cfg *cfg, u16 base, u32 pal);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_021EF71C(u32, u32, u32, u32, u32, u32, u32);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020061E4(u32 a);
extern void func_021D590C(void **p, u16 *out);
extern void func_021EF7AC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
int func_021EE390(struct O *o);
int func_021EE3E8(int *st, struct C_021EE3E8 *c);
int func_021EE4B4(int *st, struct C_021EE4B4 *c);


int func_021EE390(struct O *o)
{
    if (o->fe0 != 0) {
        if (o->fe0(&o->fec, o->fe8) != 0) {
            o->fe0 = 0;
            o->fec = 0;
        }
        return 0;
    }
    if (o->fe4 != 0) {
        if (o->fe4(&o->fec, o->fe8) != 0) {
            o->fe4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

int func_021EE3E8(int *st, struct C_021EE3E8 *c)
{
    switch (*st) {
    case 0:
        func_0201DD78(1, 9, 12);
        func_02045374(c->f08);
        func_020454E0(c->f08, c->f10, 3);
        func_02043B5C((struct CharBuf *)c->f0c, 12);
        func_020409B4(func_02045730(c->f08));
        (*st)++;
        break;
    case 1:
        func_021EF71C(c->f34, c->f172, c->f174, c->f176, c->f178, c->f17a, c->f17c);
        func_0201C7A4((void *)c->f0c, 0, 0, (void *)c->f34, (void *)c->f24);
        (*st)++;
        break;
    case 2:
        func_02045334(c->f08);
        (*st)++;
        break;
    case 3:
        func_02040618(3, 0, 0);
        func_02040618(3, 3, 0x100);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


int func_021EE4B4(int *st, struct C_021EE4B4 *c)
{
    switch (*st) {
    case 0:
        func_021D590C((void **)c->f16c, &c->f170);
        func_021EF7AC(c->f34, c->f172, c->f174, c->f176, c->f178, c->f17a, c->f17c);
        func_02043B5C((struct CharBuf *)c->f0c, 12);
        func_0201C7A4((void *)c->f0c, 0, 0, (void *)c->f34, (void *)c->f24);
        (*st)++;
        break;
    case 1:
        func_02045334((struct Descriptor *)c->f08);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
