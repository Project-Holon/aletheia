/*
 * function: func_021DE950
 * address:  0x021DE950
 * packet:   pkt_ov119_021DE950
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_021E1024  0x021E1024  thumb  ov119
 *   func_021E1030  0x021E1030  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DE918  0x021DE918  thumb  ov119
 */

extern void func_02045CAC(void *arc, int entry, void *dst);
extern void func_021E1024(void *p);
extern void func_021E1030(void *p);
extern void func_021D8E84(void *p, int next);
extern void func_021DE918(void *p);

void func_021DE950(char *p)
{
    func_02045CAC(*(void **)(p + 0x720), 0x88, *(void **)(p + 0x738));
    func_021E1024(p);
    func_021E1030(p);
    *(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DE918);
}
