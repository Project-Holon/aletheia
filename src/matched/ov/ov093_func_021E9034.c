/*
 * function: func_021E9034
 * address:  0x021E9034
 * packet:   pkt_ov093_021E9034
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EECD8  0x021EECD8  thumb  ov093
 *   func_021E907C  0x021E907C  thumb  ov093
 *   func_021EB234  0x021EB234  thumb  ov093
 *   func_02031140  0x02031140  arm
 *   func_02045808  0x02045808  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020307B0  0x020307B0  arm
 */
extern void func_021EECD8(void);
extern void func_021E907C(void *p);
extern void func_021EB234(void *p);
extern void func_02031140(void *p);
extern void func_02045808(void *p);
extern void func_0201D83C(void *p);
extern void func_020307B0(void *p);

void func_021E9034(char *p)
{
    func_021EECD8();
    func_021E907C(*(void **)(p + 0x180));
    func_021EB234(*(void **)(p + 0x17c));
    func_02031140(*(void **)(p + 0x178));
    func_02045808(*(void **)(p + 0xac));
    func_0201D83C(*(void **)(p + 0xb0));
    func_0201D83C(*(void **)(p + 0xb4));
    func_020307B0(p);
}
