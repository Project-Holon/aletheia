/*
 * function: func_021D4A04
 * address: 0x021D4A04
 * packet: pkt_ov123_021D4A04
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: one-word struct = {0} keeps add r1, sp then str [r1]; scalar/array sink the address.
 * symbols:
 *   func_021D45F4 0x021D45F4 thumb ov123
 *   func_02051B84 0x02051B84 arm
 *   func_021D4778 0x021D4778 thumb ov123
 *   func_021D4BA8 0x021D4BA8 thumb ov123
 *   func_021D4CA0 0x021D4CA0 thumb ov123
 *   func_021DA9C0 0x021DA9C0 data a4
 *   d_021DA640 0x021DA640 data a4
 *   d_021DA648 0x021DA648 data a4
 *   func_021D4244 0x021D4244 thumb ov123
 */
typedef unsigned short u16;
extern void func_021D45F4(int, void *, char *, void *, void *, void *);
extern void *func_02051B84(void *, void *, char *, u16);
extern void func_021D4778(void);
extern void func_021D4BA8(void);
extern void func_021D4CA0(void);
extern char func_021DA9C0[];
extern int d_021DA640[];
extern int d_021DA648[];
extern void func_021D4244(char *, void *, int);
void func_021D4A04(char *p)
{
    struct { int value; } zero = {0};
    func_021D45F4(1, &zero, p, func_021DA9C0, d_021DA640, d_021DA640 + 1);
    *(void **)(p + 0x20) = func_02051B84(d_021DA648, func_021D4778, p, *(u16 *)(p + 12));
    *(void **)(p + 4) = func_021D4BA8;
    func_021D4244(p, func_021D4CA0, 0x321);
}
