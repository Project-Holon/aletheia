/*
 * function: func_021FAEE8, func_021FAF10
 * unit: yes
 * follower: func_021FAF10 at 0x021FAF10
 * address: 0x021FAEE8
 * packet: pkt_ov132_021FAEE8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;

int func_021FAEE8(char *p)
{
    *(unsigned *)(p + 4) += 1;
    if (*(unsigned *)(p + 4) >= *(unsigned *)(p + 8)) {
        *(unsigned *)(p + 0xc) -= 1;
        *(unsigned *)(p + 4) = 0;
        if (*(unsigned *)(p + 0xc) == 0) return 2;
        return 1;
    }
    return 0;
}

int func_021FAF10(void *unused, char *p)
{
    *(u16 *)(p + 0x16) = 1 | *(u16 *)(p + 0x16);
    return 1;
}
