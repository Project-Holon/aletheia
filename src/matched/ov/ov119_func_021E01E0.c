/*
 * function: func_021E01E0
 * address: 0x021E01E0
 * packet: pkt_ov119_021E01E0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200C9EC 0x0200C9EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void *func_0200CA1C(void *);
extern unsigned func_0200C9EC(void);
extern void func_02082D44(void *, void *, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021E01E0(void *h, void *buf)
{
    void *src = func_0200CA1C(h);
    func_02082D44(buf, src, func_0200C9EC());
    func_020307B0(buf);
}
