/*
 * function: func_021B6F2C
 * address: 0x021B6F2C
 * packet: pkt_ov071_021B6F2C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_021583EC 0x021583EC thumb ov010
 */
typedef unsigned char u8;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_021583EC(void *, u8);
void *func_021B6F2C(u8 **p)
{
    u8 *q = *p;
    return func_021583EC(func_020120F4(*(void **)q), q[0x3c]);
}
