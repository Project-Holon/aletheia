/*
 * function: func_021AC68C
 * address:  0x021AC68C
 * packet:   pkt_ov021_021AC68C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE070  0x021DE070  data
 *   func_021AC6D4  0x021AC6D4  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_021ABE14  0x021ABE14  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; u32 f4; u32 w[4]; } P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern void func_021AC6D4(P *p);
extern char d_021DE070[];

P *func_021AC68C(int a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x18, 1, d_021DE070, 0x6c);
    p->f0 = a;
    p->f4 = func_02188C90((u8 *)func_021ABE14((u8 *)a));
    func_021AC6D4(p);
    return p;
}
