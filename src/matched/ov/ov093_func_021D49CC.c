/*
 * function: func_021D49CC
 * address: 0x021D49CC
 * packet: pkt_ov093_021D49CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled leaf called by func_021B7968 (+0x1EC): returns the object
 * word at +0x3b14 of the d_021F3B88 block (the word func_021D49E0 frees).
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 */
typedef unsigned char u8;
extern u8 *d_021F3B88;
void *func_021D49CC(void)
{
    return *(void **)(d_021F3B88 + 0x3b14);
}
