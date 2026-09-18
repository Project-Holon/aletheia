/*
 * function: func_0200A254
 * address:  0x0200A254
 * packet:   pkt_0200A1E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern void func_0200A49C(void *p);
extern void func_0200A480(void *p);
extern int func_02009F50(void *p, unsigned int i);
extern void *func_02009FD4(void *p, unsigned int i);
extern void func_02082D44(void *src, void *dst, int n);
void func_0200A254(void *p, unsigned int a, unsigned int b)
{
    unsigned char tmp[0xcc];
    func_0200A49C(p);
    if (func_02009F50(p, a) && func_02009F50(p, b)) {
        void *x = func_02009FD4(p, a);
        void *y = func_02009FD4(p, b);
        func_02082D44(x, tmp, 0xcc);
        func_02082D44(y, x, 0xcc);
        func_02082D44(tmp, y, 0xcc);
    }
    func_0200A480(p);
}
