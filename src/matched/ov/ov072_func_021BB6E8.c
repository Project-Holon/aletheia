/*
 * function: func_021BB6E8
 * address:  0x021BB6E8
 * packet:   pkt_ov072_021BB6E8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BB7BC  0x021BB7BC  thumb  ov072
 *   func_021BB820  0x021BB820  thumb  ov072
 *   func_021BB9B8  0x021BB9B8  thumb  ov072
 *   func_020056A0  0x020056A0  thumb
 *   d_021BBD6C     0x021BBD6C  data  ov072  a1
 *   d_021BBBDC     0x021BBBDC  data  ov072
 *   func_021BB80C  0x021BB80C  thumb  ov072
 */
typedef unsigned int u32;

extern char d_021BBD6C[];
extern char d_021BBBDC[];
extern void func_021BB80C(int unused, char *p);

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021BB7BC(void);
extern void func_021BB820(u32 *p, u32 a);
extern void func_021BB9B8(u32 *p, char *s, u32 a);
extern u32  func_020056A0(void (*cb)(void), void *arg, int pri);

u32 *func_021BB6E8(u32 heap)
{
    u32 *p;

    p = func_02030734(heap, 0x2C, 0, d_021BBD6C, 0xEC);
    func_02082BCC(p, 0, 0x2C);
    func_021BB7BC();
    func_021BB820(p, heap);
    func_021BB9B8(p + 1, d_021BBBDC, heap);
    p[10] = func_020056A0((void (*)(void))func_021BB80C, p, 1);
    return p;
}
