/*
 * function: func_0200A1E4
 * address:  0x0200A1E4
 * packet:   pkt_0200A1E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
extern u8 *func_0200A41C(void *p);
extern void func_0200A49C(void *p);
extern void func_0200A480(void *p);
void func_0200A1E4(void *p, unsigned int idx)
{
    u8 *b = func_0200A41C(p);
    func_0200A49C(p);
    if (idx < 0x800) {
        b[idx >> 3] |= (u8)(1 << (idx & 7));
    }
    func_0200A480(p);
}
