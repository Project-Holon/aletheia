/*
 * function: func_021AD7B4
 * address:  0x021AD7B4
 * packet:   pkt_ov021_021AD7B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE0E8  0x021DE0E8  data
 *   func_021AD7E4  0x021AD7E4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; } P;

extern void *func_02030734(int heap, int size, int clear, const char *file, int line);
extern void func_021AD7E4(P *p, u32 c);
extern char d_021DE0E8[];

P *func_021AD7B4(u32 a, int heap, u32 c)
{
    P *p;

    p = (P *)func_02030734(heap, 0x98, 1, d_021DE0E8, 0x11e);
    p->f0 = a;
    func_021AD7E4(p, c);
    return p;
}
