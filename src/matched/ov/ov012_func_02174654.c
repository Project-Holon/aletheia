/*
 * function: func_02174654
 * address:  0x02174654
 * packet:   pkt_ov012_02174654
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02184D38  0x02184D38  thumb  ov020
 */

typedef unsigned char u8;

struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t);

int func_02174654(int a, int b, int c, int d, int e, int *out, u8 *cnt)
{
    int v[3];
    int z = 0;

    if (*cnt == 0) {
        v[0] = (func_0203D1A4((struct Link *)((int)func_020399A8())) * 16 + 0x58) << 12;
        v[1] = 0;
        v[2] = 0x98000;
        *out = (int)func_02184D38((void *)a, c, 0x96, v, 0, 0);
    } else {
        return 1;
    }
    (*cnt)++;
    return z;
}
