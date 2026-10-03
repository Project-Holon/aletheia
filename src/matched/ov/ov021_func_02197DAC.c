/*
 * function: func_02197DAC
 * address:  0x02197DAC
 * packet:   pkt_ov021_02197DAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 *func_02030EE8(void *);
extern void func_0216D480(u32);
extern void func_020307B0(void *);
struct Node;
extern void func_02030EAC(struct Node *n);

void func_02197DAC(void *a)
{
    u32 *p;

    p = func_02030EE8(a);
    func_0216D480(p[3]);
    func_020307B0(p);
    func_02030EAC(a);
}
