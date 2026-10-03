/*
 * function: func_021ADCB8
 * address:  0x021ADCB8
 * packet:   pkt_ov021_021ADCB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE10C  0x021DE10C  data
 *   func_021ADCF0  0x021ADCF0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; } P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021ADCF0(P *p);
extern char d_021DE10C[];

P *func_021ADCB8(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x20, 1, d_021DE10C, 0x67);
    p->f0 = a;
    func_021ADCF0(p);
    return p;
}
