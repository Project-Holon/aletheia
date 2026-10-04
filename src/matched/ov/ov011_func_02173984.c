/*
 * function: func_02173984
 * address:  0x02173984
 * packet:   pkt_ov011_02173984
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned int   u32;
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_02173984(char *p, int b)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    r = func_0203D3F8((int)func_020399A8(), 0xFF, 0x205, 0x1C, (u32)((void *)b), 0, 1, 0);
    if (r == 1) {
        p[0x900] = 0;
    }
    return r;
}
