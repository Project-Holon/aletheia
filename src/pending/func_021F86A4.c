/*
 * function: func_021F86A4
 * address:  0x021F86A4
 * packet:   pkt_021F86A4
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: every concrete byte reproduces; 0x021FFE90 lies outside ov185's
 *   region and the only branch to it is inside this range.
 *
 * symbols:
 *   func_021F8AA8   0x021F8AA8  thumb
 *   func_021F8658   0x021F8658  thumb
 *   func_021FFC9C   0x021FFC9C  thumb
 *   func_021FFE90   0x021FFE90  thumb
 *   func_021FD73C   0x021FD73C  thumb
 *
 * Poll the handle; on the two-result branch latch the returned halfword
 *   and chain to 0x21F8AA8, otherwise chain to 0x21F8658.
 */


extern void func_021F8AA8(void);
extern void func_021F8658(void);
extern void func_021FFC9C(int);
extern int func_021FFE90(int, unsigned short *);
extern void func_021FD73C(int, void *);

void func_021F86A4(int a, int b, char *p)
{
    unsigned short buf;
    int r;
    func_021FFC9C(*(int *)p);
    r = func_021FFE90(*(int *)p, &buf);
    if (r == 0)
        return;
    if (r == 2) {
        *(unsigned short *)(p + 8) = buf;
        func_021FD73C(a, func_021F8AA8);
    } else {
        func_021FD73C(a, func_021F8658);
    }
}
