/*
 * function: func_0200A094
 * address:  0x0200A094
 * packet:   pkt_0200A034
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
extern int func_0200A400(void *p);
extern void func_0200A49C(void *p);
extern void *func_0200A43C(void *p, unsigned int i);
extern void func_02009F7C(void *p, unsigned int i);
extern void func_0200A480(void *p);
void func_0200A094(void *p, unsigned int idx)
{
    unsigned int n = (unsigned int)func_0200A400(p);
    func_0200A49C(p);
    if (idx < n) {
        void *slot = func_0200A43C(p, idx);
        *(u8 *)((char *)slot + 0xb3) = 0;
        func_02009F7C(p, idx);
    }
    func_0200A480(p);
}
