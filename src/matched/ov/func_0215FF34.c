/*
 * function: func_0215FF34
 * address:  0x0215FF34
 * packet:   pkt_0215FF34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three chained arm9 probes; a non-zero result from the last reads as
 * success.
 *
 * symbols:
 *   func_020120F4   0x020120F4  thumb
 *   func_02012EBC   0x02012EBC  thumb
 *   func_0200C404   0x0200C404  thumb
 *   func_0200C468   0x0200C468  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020120F4(void *);
extern int func_02012EBC(int);
extern int func_0200C404(int);
extern int func_0200C468(int);

int func_0215FF34(void *sys)
{
    if (func_0200C468(func_0200C404(func_02012EBC(func_020120F4(sys)))) != 0)
        return 1;

    return 0;
}

