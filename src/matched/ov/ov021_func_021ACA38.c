/*
 * function: func_021ACA38
 * address:  0x021ACA38
 * packet:   pkt_ov021_021ACA38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE080  0x021DE080  data
 *   func_021ACA70  0x021ACA70  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; u32 f4; u32 f8; } P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021ACA70(u32 *a);
extern char d_021DE080[];

P *func_021ACA38(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0xc, 1, d_021DE080, 0xac);
    p->f0 = a;
    func_021ACA70((u32 *)p);
    return p;
}
