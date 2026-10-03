/*
 * function: func_021F602C, func_021F603C
 * address: 0x021F602C
 * packet: pkt_ov215_021F602C
 * region: ov215
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005E30 0x02005E30 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02005E30(u32 a);
void func_021F602C(void *unused, char *p)
{
    func_02005E30(0x3c);
    *(int *)(p + 0x18) = 7;
}

int func_021F603C(void *unused, char *p)
{
    if (*(int *)(p + 0x18) == 7) return 1;
    return 0;
}
