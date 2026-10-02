/*
 * function: func_021B6950
 * address: 0x021B6950
 * packet: pkt_ov172_021B6950
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02085D3C 0x02085D3C arm
 *   func_021B6974 0x021B6974 arm ov172
 *   func_021B68A0 0x021B68A0 thumb ov172
 */
extern int func_02085D3C(void);
extern void func_021B6974(int, int, int);
extern void func_021B68A0(char *);

void func_021B6950(char *p, int v)
{
    if (func_02085D3C() == 1) func_021B6974(3, 3, v);
    *(int *)(p + 0x30) = v;
    func_021B68A0(p);
}
