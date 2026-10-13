/*
 * function: func_02175240
 * address:  0x02175240
 * packet:   pkt_ov012_02175240
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
 *   POKEPARTY_Init  0x0201A948  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
struct Party;
extern void POKEPARTY_Init(struct Party *p);

void func_02175240(u8 *a, int b)
{
    int self;
    int i;

    self = func_0203D1A4((struct Link *)((u32)func_020399A8()));
    for (i = 0; i < 4; i++) {
        if (b == 0 || self != i) {
            POKEPARTY_Init(*(void **)(a + i * 4 + 0x148));
        }
        a[i + 0x158] = 0;
    }
}
