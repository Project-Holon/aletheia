/*
 * function: func_02174B7C
 * address:  0x02174B7C
 * packet:   pkt_ov011_02174B7C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_021738E4  0x021738E4  thumb ov011
 */

typedef unsigned int   u32;
u32 func_0203D378(void);
int func_0203D1C0(unsigned char a);
void func_021738E4(void *p, int i);

void func_02174B7C(unsigned char *p)
{
    int i;

    if (func_0203D378() != 0) {
        for (i = 0; i < p[0x902]; i++) {
            if (func_0203D1C0(i) == 0 && (p[0x8FB] & (1 << i))) {
                func_021738E4(p, i);
            }
        }
    }
}
