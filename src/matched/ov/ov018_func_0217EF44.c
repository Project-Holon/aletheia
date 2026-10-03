/*
 * function: func_0217EF44
 * address: 0x0217EF44
 * packet: pkt_ov018_0217EF44
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012138 0x02012138 thumb
 *   func_0217EF70 0x0217EF70 thumb ov018
 * interface: r1 holds p[0xd8] at 0x0217EF64 and EF70 reads it.
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern void func_0217EF70(void *, int);
void func_0217EF44(u8 *p)
{
    func_020120F4(*(void **)p);
    func_02012138(*(void **)p);
    if (p[0xd8] != p[0x105]) func_0217EF70(p, p[0xd8]);
}
