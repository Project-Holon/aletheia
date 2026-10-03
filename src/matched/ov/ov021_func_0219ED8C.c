/*
 * function: func_0219ED8C
 * address:  0x0219ED8C
 * packet:   pkt_ov021_0219ED8C
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
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    s16 f4;
    u16 f6;
} Pos;

extern void *func_0219E968(u32 a, u32 size);
extern void func_0219E2F4(u32, Pos *);
extern void func_0216D674(u32, u32);
extern void func_0216DA50(u32);

void func_0219ED8C(u32 a)
{
    u8 *q = func_0219E968(a, 16);
    Pos pos;
    func_0219E2F4(a, &pos);
    q[0xc] = 0;
    q[0xd] = 0;
    q[0xf] = pos.f6;
    q[0xe] = pos.f4;
    func_0216D674(a, 0);
    func_0216DA50(a);
}
