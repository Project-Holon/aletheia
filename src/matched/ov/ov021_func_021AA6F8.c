/*
 * function: func_021AA6F8
 * address:  0x021AA6F8
 * packet:   pkt_ov021_021AA6F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Pos { u16 x, y, z; u16 f06; u32 f08; };

extern void *func_021A3074(void *q);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern u16 func_0216D83C(void *o);
extern u16 func_0216D854(void *o);
extern u16 func_0216D86C(void *o);

void func_021AA6F8(struct Pos *p, void *q)
{
    void *o = func_021A3074(q);

    MI_CpuFill8(p, 0, sizeof(*p));
    p->x = func_0216D83C(o);
    p->y = func_0216D854(o);
    p->z = func_0216D86C(o);
}
