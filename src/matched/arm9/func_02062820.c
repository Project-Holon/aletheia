/*
 * function: func_02062820
 * address:  0x02062820
 * packet:   pkt_02062820
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  PC24 func_02062884 at +0x24: no branch anywhere outside this range reaches 0x02062884
 *
 * symbols:
 *   NNS_G2dFindBinaryBlock  0x02062B64  arm
 */

typedef unsigned int   u32;
struct NitroFileHeader;
extern void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature);
extern void func_02062884(int *p);
int func_02062820(int a, int *out)
{
    char *o = (char *)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x4345424b);
    if (o == 0) {
        *out = 0;
        return 0;
    }
    func_02062884((int *)(o + 8));
    *out = (int)(o + 8);
    return 1;
}
