/*
 * function: func_021D9A04
 * address: 0x021D9A04
 * packet: pkt_ov131_021D9A04
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DA84C 0x021DA84C thumb ov131
 *   func_021D9D44 0x021D9D44 thumb ov131
 *   func_021DBAC0 0x021DBAC0 thumb ov131
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021DA84C(u8 *, u8 *);
extern void func_021D9D44(void *, u8 *);
extern void func_021DBAC0(u8 *);
extern void func_020307B0(void *);
void func_021D9A04(u8 *a, u8 *p)
{
    if (*(u32 *)p == 1) {
        if ((*(u8 **)(a + 8))[13] == 2) func_021DA84C(a, p);
        else func_021D9D44(a, p);
    }
    func_021DBAC0(*(u8 **)(p + 0xa4));
    func_020307B0(*(void **)(p + 0x38));
    func_020307B0(*(void **)(p + 0x40));
    func_020307B0(*(void **)(p + 0x48));
    func_020307B0(*(void **)(p + 0x50));
    func_020307B0(*(void **)(p + 0x58));
}
