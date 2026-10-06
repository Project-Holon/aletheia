/*
 * function: func_021ADEDC
 * address:  0x021ADEDC
 * packet:   pkt_ov021_021ADEDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE124  0x021DE124  data
 *   func_021ADF14  0x021ADF14  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; } P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021ADF14(int *p);
extern char d_021DE124[];

P *func_021ADEDC(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x18, 1, d_021DE124, 0x60);
    p->f0 = a;
    func_021ADF14((int *)p);
    return p;
}
