/*
 * function: FLD_EXP_OBJ_InitAnimeSet
 * address:  0x021BE630
 * packet:   pkt_ov021_021BE630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLD_EXP_OBJ_InitAnimeSet  0x021BE630  thumb
 *   func_02030734  0x02030734  arm
 *   sFldExpObjFileName     0x021DE390  data  a4
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern int sFldExpObjFileName;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);

void FLD_EXP_OBJ_InitAnimeSet(int *p, int n, int heap)
{
    u8 *e = (u8 *)func_02030734((u16)heap, n << 4, 1, (const char *)&sFldExpObjFileName, 0x19D);
    int i;

    p[1] = (int)e;
    p[0] = n;
    for (i = 0; i < n; i++) {
        e[i * 16] = 0;
        e[i * 16 + 1] = 1;
        e[i * 16 + 2] = 0;
        *(int *)(e + i * 16 + 4) = 0x1000;
    }
}
