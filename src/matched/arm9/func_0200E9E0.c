/*
 * function: func_0200E9E0
 * address:  0x0200E9E0
 * packet:   pkt_0200E9E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BSUBWAY_SAVEDATA_InitStats  0x0200DFCC  thumb
 */

typedef unsigned char u8;

extern void func_0200E904(void *p);
extern void BSUBWAY_SAVEDATA_InitStats(void *p);

void func_0200E9E0(void *a0)
{
    func_0200E904(a0);
    BSUBWAY_SAVEDATA_InitStats((u8 *)a0 + 0x5a);
}
