/*
 * function: func_021D72A0
 * address: 0x021D72A0
 * packet: pkt_ov120_021D72A0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4F70 0x021D4F70 thumb ov120
 *   func_021D71B8 0x021D71B8 thumb ov120
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_021D4F70(void *, int);
extern void func_021D71B8(u8 *, void *, int);
void func_021D72A0(u8 *p, void *container, int offset)
{
    int i;
    void *entry;
    for (i = 0; i < 6; i++) {
        if ((int)((u32)i + (u32)offset) >= 0) {
            entry = func_021D4F70(container, (int)((u32)i + (u32)offset));
            if (entry != 0) func_021D71B8(p, entry, i);
        }
    }
}
