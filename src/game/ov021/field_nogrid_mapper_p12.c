/*
 * file:     field_nogrid_mapper_p12.c
 * unit:     yes
 * function: func_021BB014, func_021BB088, func_021BB0A4
 * address:  0x021BB014
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
 *   func_021B833C  0x021B833C  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B8328  0x021B8328  thumb  ov021
 *   func_021B836C  0x021B836C  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   d_021DE2C4     0x021DE2C4  data  a4
 *   func_021BB11C  0x021BB11C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32;

extern unsigned char *func_021B833C(unsigned char *p);
extern u32 func_021B82FC(u8 *p);
extern void func_021B8328(u32, u32, u32 *);
extern u32 *func_021B836C(u32, u32);
extern u32 func_021B821C(u8 *p);
extern void func_0218E124(u8 *a, u32 s);
extern void func_0218EC54(u8 *p);
extern void func_0218EC90(u32, u32 *);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
extern void func_021BB11C(u32 *p);
extern u32 func_020307B0(void *p);
void func_021BB014(u32 a, unsigned char *b, u32 c);
void *func_021BB088(int a);
void func_021BB0A4(u8 *p, u32 a1, u32 a2, u32 a3);
extern int d_021DE2C4;


/*
 * Addresses are Black-image addresses.
 */
void func_021BB014(u32 a, unsigned char *b, u32 c)
{
    u32 loc[3];
    u32 x;
    u32 *r;
    u32 h;
    u32 k;

    k = (u32)func_021B833C(b);
    if (k == c)
        x = 0;
    else
        x = func_021B82FC((u8 *)b);
    func_021B8328((u32)b, x, loc);
    r = func_021B836C((u32)b, c);
    h = func_021B821C((u8 *)a);
    func_0218E124((u8 *)h, 0);
    func_0218EC54((u8 *)h);
    func_0218EC90(h, loc);
    func_0218ED34((u8 *)h, r[1]);
    func_0218ED48((u8 *)h, (u16)r[2]);
    func_0218ED58((u8 *)h, r[3]);
}


void *func_021BB088(int a)
{
    return func_02030734((u16)a, 0x10, 1, (const char *)&d_021DE2C4, 0x5C);
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB0A4(u8 *p, u32 a1, u32 a2, u32 a3)
{
    func_021BB11C((u32 *)p);
    func_020307B0(p);
}
