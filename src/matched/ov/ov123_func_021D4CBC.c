/*
 * function: func_021D4CBC
 * address: 0x021D4CBC
 * packet: pkt_ov123_021D4CBC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D4D3E before next labelled function.
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02021730 0x02021730 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 */
typedef unsigned short u16;
extern void *func_02021518(u16);
extern void func_0202155C(void *, int, int, u16);
extern void func_020216D4(void *, int, int, int);
extern void func_02021FD8(void *, int, int, u16, int, int);
extern void *func_02021730(void *, int);
extern void func_020862F0(void *, int);
extern void func_0207E5D0(void *, int, int);
extern void func_0207E468(void *, int, int);
extern void func_020215A0(void *, int);
extern void func_02021540(void *);
void func_021D4CBC(char *p, int n, int count)
{
    void *obj;
    void *buffer;
    int bytes;
    obj = func_02021518(*(u16 *)(p + 12));
    func_0202155C(obj, n, 0x200, *(u16 *)(p + 12));
    bytes = count * 32;
    func_020216D4(obj, n, 0, bytes);
    func_02021FD8(obj, n, 0, count * 16, 6, 0);
    buffer = func_02021730(obj, n);
    func_020862F0(buffer, bytes);
    switch (n) {
    case 3: func_0207E5D0(buffer, 0, bytes); break;
    case 1: func_0207E468(buffer, 0, bytes); break;
    }
    func_020215A0(obj, n);
    func_02021540(obj);
}
