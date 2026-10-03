/*
 * function: func_021F5FB0, func_021F5FCC
 * address: 0x021F5FB0
 * packet: pkt_ov215_021F5FB0
 * region: ov215
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020063B4 0x020063B4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_020063B4(unsigned, void *, int);
void func_021F5FB0(void *unused, char *p)
{
    *(int *)(p + 0x24) = 0;
    func_020063B4(0x3f3, p + 0x24, 1);
    *(int *)(p + 0x18) = 3;
}

int func_021F5FCC(void *unused, char *p)
{
    if (*(int *)(p + 0x18) == 4) return 1;
    return 0;
}
