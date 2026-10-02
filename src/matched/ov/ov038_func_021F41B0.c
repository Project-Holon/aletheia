/*
 * function: func_021F41B0
 * address: 0x021F41B0
 * packet: pkt_ov038_021F41B0
 * region: ov038
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_021897BC 0x021897BC thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_021F42BC 0x021F42BC thumb ov038
 */
typedef unsigned int u32;
extern u32 func_0201210C(const void *);
extern int *func_021897BC(char *, int);
extern void *func_020122C0(void *, void *, void *, u32);
extern int func_021F42BC(int, int *);
void *func_021F41B0(void *p, int v)
{
    unsigned char *s = (unsigned char *)func_021897BC((char *)func_0201210C(p), 1);
    if (v >= 10) return 0;
    s[1] = v;
    return func_020122C0(p, 0, func_021F42BC, 0);
}
