/*
 * function: func_021EF400
 * address:  0x021EF400
 * packet:   pkt_ov170_021EF400
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CDD4 0x0202CDD4 thumb
 *   func_021EC8E4 0x021EC8E4 thumb
 */

extern void func_0202CF98(int, int, signed char *, signed char *);
extern unsigned func_0202CDD4(int mgr, unsigned idx);
extern void func_021EC8E4(char *p);

int func_021EF400(char *p)
{
    signed char a[2];
    signed char b[2];
    unsigned r;
    func_0202CF98(*(int *)(*(char **)(p + 0x2C) + 0x74), 8, &a[1], &a[0]);
    r = func_0202CDD4(*(int *)(*(char **)(p + 0x2C) + 0x74), 8);
    func_0202CF98(*(int *)(*(char **)(p + 0x2C) + 0x74), 8, &b[1], &b[0]);
    if (a[1] != b[1] || a[0] != b[0])
        func_021EC8E4(p);
    {
        int ret = 0;
        if (r != 0)
            ret = 1;
        return ret;
    }
}
