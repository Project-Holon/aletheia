/*
 * function: BTL_POKEPARAM_AddCritStage
 * address:  0x021D5F38
 * packet:   pkt_ov093_021D5F38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the clamp at the bottom stores the field in each arm
 * (`if (p->f > k) p->f = p->f - (u8)k; else p->f = 0;`). A local `v` assigned in the arms
 * and stored once, or a ternary, keeps k out of r4 (no push {r3,r4}; 8 bytes short).
 * `n * 0xffffffff` keeps the mvns/muls (a-multiply-by-minus-one-is-strength-reduced-but-by-0xffffffff-is-not.md).
 *
 * symbols: none (no relocations; pool word 0x142 is a plain constant)
 */
typedef unsigned char u8;

struct S { u8 pad[0x142]; u8 f; };

int BTL_POKEPARAM_AddCritStage(struct S *p, int n)
{
    int k;

    if (n > 0) {
        if (p->f < 4) {
            p->f = p->f + (u8)n;
            if (p->f > 4) p->f = 4;
            return 1;
        }
    } else {
        k = n * 0xffffffff;
        if (p->f != 0) {
            if (p->f > k) p->f = p->f - (u8)k; else p->f = 0;
            return 1;
        }
    }
    return 0;
}
