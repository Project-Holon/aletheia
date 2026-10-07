/*
 * file:     field_nogrid_mapper_p10.c
 * unit:     yes
 * function: func_021BAA9C, func_021BAB30
 * address:  0x021BAA9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CC30  0x0207CC30  arm
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B8314  0x021B8314  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 */
struct Sub;
typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16;

typedef unsigned char  u8;

extern u32 func_021B8220(u8 *p);
extern u32 *func_021B830C(u32);
extern u32 func_021B821C(u8 *p);
extern void func_0218E124(u8 *a, u32 s);
extern int func_0218EC60(u32 a);
extern void func_021B8050(struct Sub *o, s16 *out);
extern int func_0207CFB8(int, int);
extern int func_0207CC30(s16 *);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218EC54(u8 *p);
extern void func_021B8314(u32, u32 *);
extern void func_0218EC90(u32, u32 *);
void func_021BAA9C(u32 a);
void func_021BAB30(u32 a);


void func_021BAA9C(u32 a)
{
    s16 b[6];
    u32 t, h;
    u32 *r;
    int x, y;

    t = func_021B8220((u8 *)a);
    r = func_021B830C(t);
    h = func_021B821C((u8 *)a);
    func_0218E124((u8 *)h, 0);
    func_0218EC60(func_021B821C((u8 *)a));
    func_021B8050((struct Sub *)t, &b[3]);
    x = func_0207CFB8(-b[3], -b[5]);
    b[0] = b[3];
    b[2] = b[5];
    b[1] = 0;
    y = func_0207CFB8(-b[4], func_0207CC30(b));
    func_0218ED34((u8 *)h, y + r[2]);
    func_0218ED58((u8 *)h, r[3]);
    func_0218ED48((u8 *)h, (u16)(x + r[1]));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BAB30(u32 a)
{
    s16 v[4];
    u32 loc[3];
    u32 t, h;
    u32 *r;
    int ang;

    t = func_021B8220((u8 *)a);
    r = func_021B830C(t);
    h = func_021B821C((u8 *)a);
    func_0218E124((u8 *)h, 0);
    func_0218EC54((u8 *)func_021B821C((u8 *)a));
    func_021B8050((struct Sub *)t, v);
    ang = func_0207CFB8(-v[0], -v[2]);
    func_0218ED34((u8 *)h, r[2]);
    func_0218ED58((u8 *)h, r[3]);
    func_0218ED48((u8 *)h, (u16)(ang + r[1]));
    func_021B8314(t, loc);
    func_0218EC90(func_021B821C((u8 *)a), loc);
}
