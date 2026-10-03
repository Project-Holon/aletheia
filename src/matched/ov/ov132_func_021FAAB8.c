/*
 * function: func_021FAAB8
 * address: 0x021FAAB8
 * packet: pkt_ov132_021FAAB8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0204B3DC(void *, unsigned);
void func_021FAAB8(char *p, unsigned flag)
{
    if (*(u16 *)(p + 0x48) != 255) {
        func_0204B3DC(*(void **)(p + 0x4c), flag);
        func_0204B3DC(*(void **)(p + 0x54), flag);
    }
    if (*(u16 *)(p + 0x4a) != 255) {
        func_0204B3DC(*(void **)(p + 0x50), flag);
        func_0204B3DC(*(void **)(p + 0x58), flag);
    }
    *(unsigned *)(p + 0xc) = flag;
}
