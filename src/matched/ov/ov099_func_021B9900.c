/*
 * function: func_021B9900
 * address:  0x021B9900
 * packet:   pkt_ov099_021B9900
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA168  0x021BA168  thumb
 *   func_021BA0F8  0x021BA0F8  thumb  ov099
 *   func_021BA1C4  0x021BA1C4  thumb
 *   func_021BA228  0x021BA228  thumb  ov099
 *   func_021BA190  0x021BA190  thumb
 *   func_021C5994  0x021C5994  thumb  ov127
 *   func_021C5A60  0x021C5A60  thumb  ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021BA168(u8 *p);
extern void func_021BA0F8(void *p, u16 *xy);
extern void func_021BA1C4(u8 *p, void *out, u16 *xy, int a, u16 d, u8 c, int b);
extern void func_021BA228(void *w, u8 *s);
extern void func_021BA190(u8 *p, u8 *s, int n);
extern void func_021C5994(void *p, void *q);
extern void func_021C5A60(char *p, void *q);

u8 *func_021B9900(u8 *p, u32 v)
{
    u8 *s;
    u16 xy[2];

    s = func_021BA168(p);
    *(u8 **)(p + 0x570) = s;
    func_021BA0F8(p, xy);
    func_021BA1C4(p, s, xy, 0, v, 0, 0);
    func_021BA228(p, s);
    func_021BA190(p, s, 1);
    func_021C5994(p + 0x594, **(void ***)(p + 0x570));
    func_021C5A60(*(char **)(p + 0x598), p + 0x594);
    return s;
}
