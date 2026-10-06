/*
 * function: func_021746A8
 * address:  0x021746A8
 * packet:   pkt_ov012_021746A8
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
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} P;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
typedef unsigned short u16;
extern void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t);

int func_021746A8(int a, int b, int c, int d, int e, int *out, u8 *cnt)
{
    P s;
    int z;

    if (*cnt == 0) {
        s.a = (int)((func_0203D1A4((struct Link *)((u32)func_020399A8())) * 16 + 0x58) << 12);
        z = 0;
        s.b = z;
        s.c = 0x26 << 14;
        *out = (int)func_02184D38((void *)a, c, 0x97, (const int *)(&s), z, z);
    } else {
        return 1;
    }
    *cnt = *cnt + 1;
    return z;
}
