/*
 * function: func_021B6F40
 * address: 0x021B6F40
 * packet: pkt_ov071_021B6F40
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_021583CC 0x021583CC thumb ov010
 */
typedef unsigned char u8;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_021583CC(void *a0, int a1);
void *func_021B6F40(u8 **p)
{
    u8 *q = *p;
    return (void *)func_021583CC(func_020120F4(*(void **)q), q[0x3c]);
}
