/*
 * function: func_021BFBBC
 * address: 0x021BFBBC
 * packet: pkt_ov099_021BFBBC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02156B68 0x02156B68 thumb ov009
 *   func_021BE3CC 0x021BE3CC thumb ov099
 */
extern int func_02156B68(char *);
extern void func_021BE3CC(char *, int, int, int, int, int);
void func_021BFBBC(char *p)
{
    if (func_02156B68(p)) {
        func_021BE3CC(p + 0x898, 1, 2, 1, 0x3c, 0);
    } else {
        func_021BE3CC(p + 0x898, 1, 2, 1, 0x33, 0);
    }
}
