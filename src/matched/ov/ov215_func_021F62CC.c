/*
 * function: func_021F62CC
 * address: 0x021F62CC
 * packet: pkt_ov215_021F62CC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201FEBC 0x0201FEBC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_0201FEBC(u8 *);
void func_021F62CC(void *unused, char *p)
{
    unsigned result;
    int flag;
    switch (*(int *)(p + 0x20)) {
    case 0:
        break;
    case 1:
        result = func_0201FEBC(*(u8 **)(p + 0x78));
        if (result != 0xffffffff) {
            if (result == 0) flag = 1;
            else flag = 0;
            *(int *)(p + 0x7c) = flag;
            *(int *)(p + 0x20) = 2;
        }
        break;
    }
}
