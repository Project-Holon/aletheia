/*
 * function: func_021F2608
 * address: 0x021F2608
 * packet: pkt_ov032_021F2608
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 */
struct Tcbl;
extern void func_020310C4(struct Tcbl *);
int func_021F2608(char *p, int *unused)
{
    func_020310C4(*(struct Tcbl **)(p + 0xa0));
    if (*(int *)(p + 0xa8) == 0)
        return 1;
    return 0;
}
