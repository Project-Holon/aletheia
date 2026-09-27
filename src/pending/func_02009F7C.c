/*
 * function: func_02009F7C
 * address:  0x02009F7C
 * packet:   pkt_02009F7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef struct { int w[0x33]; } Slot;
extern int func_0200A400(void *p);
extern int func_02009F50(void *p, unsigned int i);
extern void *func_0200A43C(void *p, unsigned int i);
extern void func_02082BCC(void *dst, int v, int n);
void func_02009F7C(void *p, unsigned int idx)
{
    unsigned int i;
    unsigned int n = (unsigned int)func_0200A400(p);
    if (func_02009F50(p, idx) != 0)
        return;
    for (i = idx; i < n - 1; i++) {
        void *dst = func_0200A43C(p, i);
        void *src = func_0200A43C(p, i + 1);
        *(Slot *)dst = *(Slot *)src;
    }
    func_02082BCC(func_0200A43C(p, i), 0, 0xcc);
}
