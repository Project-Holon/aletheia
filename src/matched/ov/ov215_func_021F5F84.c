/*
 * function: func_021F5F84, func_021F5FA0
 * address: 0x021F5F84
 * packet: pkt_ov215_021F5F84
 * region: ov215
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005D90 0x02005D90 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02005D90(unsigned, unsigned);
void func_021F5F84(void *unused, char *p)
{
    func_02005D90(0x3f2, 0xffff);
    *(int *)(p + 0x18) = 2;
}

int func_021F5FA0(void *unused, char *p)
{
    if (*(int *)(p + 0x18) == 2) return 1;
    return 0;
}
