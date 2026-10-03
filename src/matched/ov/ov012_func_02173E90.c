/*
 * function: func_02173E90
 * address:  0x02173E90
 * packet:   pkt_ov012_02173E90
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    Nested null recheck retains the original dead second bne.
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_02034714  0x02034714  arm
 *   func_02183F88  0x02183F88  thumb ov022
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0203D378(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02183F88(u8 *p, u8 a);

void func_02173E90(int a, int b, int c, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 0) {
        q = *(u8 **)(p + 0x3528);
        if (q == 0) {
            if (q == 0) {
                func_02034714((void *)0x02175624, 0, (void *)0x02175624);
                return;
            }
        } else {
            func_02183F88(q, (u8)a);
        }
    }
}
