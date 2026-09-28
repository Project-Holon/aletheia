/*
 * function: func_02062820
 * address:  0x02062820
 * packet:   pkt_02062820
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  PC24 func_02062884 at +0x24: no branch anywhere outside this range reaches 0x02062884
 */

extern int func_02062B64(int a, int tag);
extern void func_02062884(void *p);
int func_02062820(int a, int *out)
{
    char *o = (char *)func_02062B64(a, 0x4345424b);
    if (o == 0) {
        *out = 0;
        return 0;
    }
    func_02062884(o + 8);
    *out = (int)(o + 8);
    return 1;
}
