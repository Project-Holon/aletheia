/*
 * function: func_021FCBF0
 * address: 0x021FCBF0
 * packet: pkt_ov135_021FCBF0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F8290 0x021F8290 thumb ov135
 */
typedef signed short s16;
extern int func_021F886C(int key, int val, int which);
extern void func_021F8290(void *a, void *b, void *c, void *d, int e, int f, int g, void *h);
void func_021FCBF0(char *p)
{
    int n;
    n = func_021F886C(p[0x1d7], p[0x1d8], 0);
    func_021F8290(*(void **)(p + 0xb6c), *(void **)(p + 0xb70), *(void **)(p + 0xb68), p + 0xdb4, *(s16 *)(p + 0x1d4), p[0x1d6], n, p + 0xfa0);
}
