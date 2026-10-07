/*
 * function: func_02155264
 * address: 0x02155264
 * packet: pkt_ov009_02155264
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02155B14 0x02155B14 thumb ov009
 */
extern int func_02155B14(int, int);
int func_02155264(int a, int b, int c, void (*cb)(int))
{
    if (func_02155B14(a, b)) {
        if (cb) cb(1);
        return 1;
    }
    return 0;
}
