/*
 * function: func_021F6000, func_021F601C
 * address: 0x021F6000
 * packet: pkt_ov215_021F6000
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
void func_021F6000(void *unused, char *p)
{
    *(int *)(p + 0x24) = 0;
    func_020063B4(0x519, p + 0x24, 1);
    *(int *)(p + 0x18) = 5;
}

int func_021F601C(void *unused, char *p)
{
    int state = *(int *)(p + 0x18);
    int result = 1;
    if (state != 5 && state != 6) result = 0;
    return result;
}
