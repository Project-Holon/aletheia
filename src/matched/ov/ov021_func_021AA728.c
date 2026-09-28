/*
 * function: func_021AA728
 * address:  0x021AA728
 * packet:   pkt_ov021_021AA728
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
extern u16 func_0216D83C(void *o);
extern u16 func_0216D854(void *o);
extern u16 func_0216D86C(void *o);

void func_021AA728(struct Pos *p, void *q)
{
    void *o = func_021A3074(q);

    if (p->f06 != 0) {
        if (p->f08 < 0xA000)
            p->f08++;
        return;
    }
    if (p->x != func_0216D83C(o) || p->y != func_0216D854(o) || p->z != func_0216D86C(o)) {
        p->f06 = 1;
        p->f08++;
    }
}
