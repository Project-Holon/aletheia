/*
 * unit:     no
 * function: func_0200A480
 * address:  0x0200A480
 * packet:   pkt_02009F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern int func_0200A418(void *p);
extern int func_0200A3FC(void *p);
extern void func_0200A4B8(int a, int b);
void func_0200A480(char *p)
{
    int n = func_0200A418(p);
    int x = func_0200A3FC(p);
    func_0200A4B8(n, x);
}
