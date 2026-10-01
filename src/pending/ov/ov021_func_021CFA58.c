/*
 * function: func_021CFA58
 * address:  0x021CFA58
 * packet:   pkt_ov021_021CFA58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocked: abs_id_39 (pool ABS32 0x39; a constant would be a movs) and
 * d_021F3900 have no witness outside the range (evidence class: none).
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   abs_id_39      0x00000039  data
 *   d_021F3900     0x021F3900  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern void *func_0201210C(void *p);
extern u32 func_02188D24(u32 a);
extern void func_021BB990(void *a, u32 b, void *c);
extern char abs_id_39[];
extern char d_021F3900[];

int func_021CFA58(void *a, void *b)
{
    func_0215A5F4(b);
    func_021BB990(abs_id_39, func_02188D24((u32)func_0201210C((void *)func_0215A5DC(b))), d_021F3900);
    return 0;
}
