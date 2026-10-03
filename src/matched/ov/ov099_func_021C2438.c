/*
 * function: func_021C2438
 * address: 0x021C2438
 * packet: pkt_ov099_021C2438
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005F24 0x02005F24 thumb
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02005F24(u32 a0, u32 a1);
int func_021C2438(char *p)
{
    int remaining;
    int start;
    int delta;
    if (*(u8 *)(p + 0x1343) != 0) {
        --*(u8 *)(p + 0x1343);
        remaining = *(u8 *)(p + 0x1343);
        if (remaining != 0) {
            start = *(u8 *)(p + 0x1342);
            delta = start - *(u8 *)(p + 0x1341);
            if (delta < 0) *(u8 *)(p + 0x1340) = start + (-delta / 6) * remaining;
            else *(u8 *)(p + 0x1340) = start - (delta / 6) * remaining;
            func_02005F24(0xffff, *(u8 *)(p + 0x1340));
            return 0;
        }
        *(u8 *)(p + 0x1340) = *(u8 *)(p + 0x1342);
        func_02005F24(0xffff, *(u8 *)(p + 0x1342));
    }
    return 1;
}
