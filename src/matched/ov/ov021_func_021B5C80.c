/*
 * function: func_021B5C80
 * address:  0x021B5C80
 * packet:   pkt_ov021_021B5C80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C2D0  0x0200C2D0  thumb
 *   func_0201EE60  0x0201EE60  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk34;
struct WordSet;

extern void *func_0215A5E4(void *a0);
extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02012F08(int *p);
extern void func_0200C2D0(struct Blk34 *p, u32 i, u16 *dest);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);

int func_021B5C80(void *a, void *b)
{
    void *t;
    struct WordSet *w;
    unsigned int k;
    u16 *out;
    int i;
    int n;
    u16 arr[6];

    t = func_0215A5E4(b);
    w = func_02158F74(func_0215A5F4(b));
    k = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    func_0200C2D0(func_02012F08(t), k, arr);
    for (i = 0, n = 0; i < 6; i++) {
        if (arr[i] != 0) {
            func_0201EE60(w, n, arr[i]);
            n++;
        }
    }
    *out = n;
    return 0;
}
