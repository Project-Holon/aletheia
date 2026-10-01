/*
 * function: func_0219CB64
 * address:  0x0219CB64
 * packet:   pkt_ov021_0219CB64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E3C8  0x0216E3C8  thumb  ov010
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_02046E24  0x02046E24  arm
 *   func_0219CB24  0x0219CB24  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 id; u8 pad[5]; u8 f7; u8 f8; } D;
extern u16 *func_0216E3C8(const D *);
extern u32 func_0216D518(u32);
extern u32 func_02046E24(u32, u16);
extern void func_0219CB24(u8 *, u32, u16, u8, u8, u32);

void func_0219CB64(u8 *s, const D *d, u32 g)
{
    u16 *q = func_0216E3C8(d);
    func_0219CB24(s, func_02046E24(func_0216D518(*(u32 *)(s + 0x10)), *q), d->id, d->f7, d->f8, g);
}
