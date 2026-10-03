/*
 * function: func_021EF280
 * address: 0x021EF280
 * packet: pkt_ov093_021EF280
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit b = b + classify(k) avoids compound-assignment RHS narrowing.
 * symbols:
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B8CE8 0x021B8CE8 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_02045CAC 0x02045CAC arm
 *   func_021EEFE0 0x021EEFE0 thumb ov093
 *   func_0201F250 0x0201F250 thumb
 *   d_021F6398 0x021F6398 data a4
 *   d_021F63D8 0x021F63D8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f00,f04,f08,f0c,f10,f14; u8 pad18[0x3c]; u32 f54; } G;
typedef struct { u8 pad00[0x18]; u16 f18; } H;
extern G d_021F6398;
extern H d_021F63D8;
extern u8 func_021B8DDC(u32 x);
extern int func_021B8CE8(int, u8, int);
extern void *func_021B86B8(void ***);
extern void func_02045CAC(u32, u16, u32);
extern void func_021EEFE0(u32, u32 *, u32);
extern void func_0201F250(u32, u32, u32);
static inline int classify(u8 k)
{
    int x;
    if (d_021F63D8.f18 == 0 && func_021B8CE8(d_021F6398.f00, (u8)d_021F6398.f54, func_021B8DDC(k))) {
        if (func_021B86B8((void ***)d_021F6398.f00) == 0 || (int)func_021B86B8((void ***)d_021F6398.f00) == 4) x = 1;
        else x = 2;
    } else x = 0;
    return x;
}
void func_021EF280(u32 a, u16 b, u32 *p)
{
    u8 k = p[1];
    int x = classify(p[0]);
    switch (x) {
    case 0:
        b = b + classify(k);
        break;
    case 1:
        b += 3;
        goto second;
    case 2:
        b += 5;
    default:
second:
        if (x == classify(k)) b++;
        break;
    }
    func_02045CAC(d_021F6398.f14, b, d_021F6398.f0c);
    func_021EEFE0(d_021F6398.f0c, p, d_021F6398.f08);
    func_0201F250(d_021F6398.f08, a, d_021F6398.f0c);
}
