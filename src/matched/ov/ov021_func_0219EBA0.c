/*
 * function: func_0219EBA0
 * address:  0x0219EBA0
 * packet:   pkt_ov021_0219EBA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219E968  0x0219E968  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u8 pad[0xc];
    u8 lo : 4;
    u8 hi : 4;
    u8 z;
    u8 c;
    u8 d;
} E;

typedef struct {
    u16 a;
    u16 pad;
    s16 c;
    u16 d;
} S;

extern void *func_0219E968(u32 a, u32 size);
extern void func_0219E2F4(void *o, void *out);
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA50(u8 *p);

void func_0219EBA0(u32 o, u32 k)
{
    E *e;
    S s;

    e = func_0219E968(o, 0x10);
    func_0219E2F4((void *)o, &s);
    e->lo = 0;
    e->z = 0;
    e->hi = k;
    e->d = s.d;
    e->c = s.c;
    func_0216D674((void *)o, 0);
    func_0216DA50((u8 *)o);
}
