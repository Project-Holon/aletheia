/*
 * function: func_021BA098
 * address: 0x021BA098
 * packet: pkt_ov172_021BA098
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 36 bytes; next instruction at 021BA0BC belongs to separate owned lead.
 * evidence: Singleton pointer re-read at 021BA0AA after stores to its object.
 * symbols:
 *   g_021C88EC 0x021C88EC data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *g_021C88EC;
void func_021BA098(void)
{
    u8 *p = g_021C88EC;
    if (*(u32 *)(p + 12) == 1) (*(u32 *)(p + 20))++;
    p = g_021C88EC;
    if (p[16] < 180) p[16]++;
}
