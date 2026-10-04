/*
 * function: func_021EFEEC
 * address:  0x021EFEEC
 * packet:   pkt_ov033_021EFEEC
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020142E8 0x020142E8 thumb
 *   func_021CFAC0 0x021CFAC0 thumb ov021
 */

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_021CFAC0(u8 *base, int a, int b, int c, int d);

int func_021EFEEC(char *p, int *q)
{
    int r;
    if (q[0] == 1) {
        unsigned short *s = *(unsigned short **)(q + 1);
        return func_020142E8((void *)(*(unsigned *)p), (unsigned short)(*s + 0x384)) == 0;
    }
    if (q[0] == 2) {
        short *s = *(short **)(q + 2);
        r = 0;
        if (func_021CFAC0((u8 *)(*(unsigned *)(p + 8)), (unsigned short)s[3], s[0], s[1], s[2]) != 0xFF)
            r = 1;
        return r;
    }
    return 0;
}
