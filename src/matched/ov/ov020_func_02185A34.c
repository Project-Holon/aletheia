/*
 * function: func_02185A34
 * address: 0x02185A34
 * packet: pkt_ov020_02185A34
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012B38 0x02012B38 thumb
 *   func_02013F6C 0x02013F6C thumb
 *   func_02014468 0x02014468 thumb
 *   func_0201446C 0x0201446C thumb
 * interface: 0201446C's full-word input matches the absent call-site truncation.
 */
extern void *func_02012B38(void *p);
extern unsigned int func_02013F6C(unsigned int id);
extern unsigned char func_02014468(void *p);
extern void func_0201446C(void *p, unsigned int value);
void func_02185A34(void *p, unsigned int id)
{
    void *object;
    unsigned int flags;
    object = func_02012B38(p);
    flags = func_02013F6C(id);
    if ((flags & 1) && func_02014468(object)) {
        flags &= ~1;
        flags |= 2;
    }
    func_0201446C(object, flags);
}
