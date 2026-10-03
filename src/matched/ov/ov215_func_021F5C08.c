/*
 * function: func_021F5C08
 * address: 0x021F5C08
 * packet: pkt_ov215_021F5C08
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02040588(unsigned, unsigned);
void func_021F5C08(void *unused, char *p)
{
    if (*(unsigned *)(p + 0x6c)) {
        func_02040588(1, 1);
        *(unsigned *)(p + 0x6c) = 0;
    }
}
