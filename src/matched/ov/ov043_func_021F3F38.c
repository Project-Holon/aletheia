/*
 * function: func_021F3F38
 * address:  0x021F3F38
 * packet:   pkt_ov043_021F3F38
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F4328     0x021F4328  data  ov043
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 */

typedef unsigned short u16;

extern int d_021F4328[];

extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void  func_021BE6CC(void *p, int i, u16 j, u16 k, int flag);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void  func_021BE6B0(void *p, int b);

void func_021F3F38(int *a, void *b, int c)
{
    int r4, r6;

    if (a[c]) {
        if (d_021F4328[c]) {
            r4 = 0;
            r6 = 1;
        } else {
            r4 = 1;
            r6 = 0;
        }
    } else {
        if (d_021F4328[c]) {
            r4 = 1;
            r6 = 0;
        } else {
            r4 = 0;
            r6 = 1;
        }
    }
    func_021BE700(b, 0, c, r4, 1);
    func_021BE700(b, 0, c, r6, 0);
    func_021BE6CC(b, 0, c, r4, 0);
    func_021BE6B0(func_021BE674(b, 0, c, r4), 1);
}
