/*
 * function: func_02173E40
 * address:  0x02173E40
 * packet:   pkt_ov012_02173E40
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    Nested null recheck retains the original dead second bne.
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02183F7C  0x02183F7C  thumb ov022
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02034714(void *file, u32 line, void *msg);
extern void func_02183F7C(u8 *p);

void func_02173E40(int a, int b, int c, u8 *p)
{
    u8 *q;
    q = *(u8 **)(p + 0x3528);
    if (q == 0) {
        if (q == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
    } else {
        func_02183F7C(q);
    }
}
