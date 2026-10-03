/*
 * function: func_0689B558
 * address: 0x0689B558
 * packet: pkt_ov095_0689B558
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing 0689B572..0689B574 is Thumb alignment padding.
 * symbols:
 *   func_0689B574 0x0689B574 thumb ov095
 *   func_0689B584 0x0689B584 thumb ov095
 *   func_0689B594 0x0689B594 thumb ov095
 */
extern void func_0689B574(void *, int, int);
extern int func_0689B584(int);
extern void func_0689B594(int);
void func_0689B558(void *p)
{
    func_0689B574(*(void **)((char *)p + 0xb0), 0, 0);
    func_0689B594(func_0689B584(8));
}
