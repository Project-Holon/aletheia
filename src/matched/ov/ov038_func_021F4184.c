/*
 * function: func_021F4184
 * address: 0x021F4184
 * packet: pkt_ov038_021F4184
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
 *   func_021F4200 0x021F4200 thumb ov038
 */
typedef unsigned int u32;
struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern int *func_021897BC(char *, int);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F4200(int, int *);
void *func_021F4184(void *p, int v)
{
    unsigned char *s = (unsigned char *)func_021897BC((char *)func_0201210C(p), 1);
    if (v >= 8) return 0;
    s[0] = v;
    return func_020122C0(p, 0, func_021F4200, 0);
}
