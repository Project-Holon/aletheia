/*
 * function: func_021AD3D4
 * address:  0x021AD3D4
 * packet:   pkt_ov021_021AD3D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE080  0x021DE080  data
 *   func_021AD410  0x021AD410  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; } P;

extern void *func_02030734(int heap, int size, int clear, const char *file, int line);
extern void func_021AD410(P *p);
extern char d_021DE080[];

P *func_021AD3D4(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x10, 1, d_021DE080, 0x3cf);
    p->f0 = a;
    func_021AD410(p);
    return p;
}
