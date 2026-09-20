/*
 * function: func_0202708C
 * address:  0x0202708C
 * packet:   pkt_0202685C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209FC04 literal
 *
 * symbols:
 *   g_0209FC04  0x0209FC04  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 g_0209FC04[];

int func_0202708C(u16 v)
{
    u32 i = 0;

    while (i < 0xe) {
        if (v == g_0209FC04[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}
