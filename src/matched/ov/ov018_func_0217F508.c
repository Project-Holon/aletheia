/*
 * function: func_0217F508
 * address: 0x0217F508
 * packet: pkt_ov018_0217F508
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02190C78 0x02190C78 thumb ov021
 *   d_02183B2C 0x02183B2C data a4
 */
extern unsigned char d_02183B2C[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Handle;
extern int func_02190C78(struct Handle *h);
int func_0217F508(void **p)
{
    if (p[11] == 0) func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    return func_02190C78(p[11]);
}
