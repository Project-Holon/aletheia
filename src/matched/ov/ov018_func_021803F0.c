/*
 * function: func_021803F0
 * address:  0x021803F0
 * packet:   pkt_ov018_021803F0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175DCC  0x02175DCC  thumb  ov011
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0217620C  0x0217620C  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u8 pad : 5; u8 f : 1; u8 rest : 2; } Bf;

extern u32 func_02188C80(void *);
extern int func_020120F4(u32);
extern int func_02012B58(int);
extern int func_02175DCC(u8 *);
extern int func_02175BCC(u8 *);
extern int func_02175B14(u8 *);
extern int func_02175B8C(u8 *);
extern int func_0217620C(u8 *, int);

static inline int state(u8 *a, u8 *b, u8 cur)
{
    if (func_02175BCC(b + 0x1AC) == 0 && func_02175B14(b + 0x1AC) == 1) {
        if (func_02175B8C(b + 0x1AC) == 1) {
            if (func_0217620C(b + 0x1AC, a[0x40]) == 1)
                return 3;
            if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 4;
            return 5;
        }
        if (func_0217620C(b + 0x1AC, cur) == 1) {
            if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 6;
            return 7;
        }
        if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
            return 1;
        if (func_0217620C(b + 0x1AC, a[0x40]) == 1)
            return 2;
        return 0;
    }
    return 0;
}

int func_021803F0(u8 *a, u8 *b)
{
    u8 cur;
    int kind;
    int r;

    cur = func_02012B58(func_020120F4(func_02188C80(*(void **)(a + 0xC))));
    kind = func_02175DCC(b + 0x1AC);
    r = state(a, b, cur);
    if (r >= 3) {
        switch (kind) {
        case 0: r += 8; break;
        case 1: r += 13; break;
        case 2: r += 18; break;
        case 3: r += 23; break;
        case 4: r += 28; break;
        case 5: r += 33; break;
        }
        r -= 3;
    }
    return r;
}
