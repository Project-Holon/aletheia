/*
 * function: func_02156BD8
 * address: 0x02156BD8
 * packet: pkt_ov009_02156BD8
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 *   func_0203D7FC 0x0203D7FC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *g_021A8264;
extern void func_0203D7FC(void *);
void func_02156BD8(u32 i)
{
    void *p;
    p = *(void **)(g_021A8264 + i * 4 + 0x174);
    if (p != 0) {
        func_0203D7FC(p);
        *(void **)(g_021A8264 + i * 4 + 0x174) = 0;
    }
}
