/*
 * function: func_021736E0
 * address:  0x021736E0
 * packet:   pkt_ov012_021736E0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_SetGameKind  0x0203D5AC  arm
 */

extern void GFL_NET_SetGameKind(int a, int b);

void func_021736E0(unsigned int x)
{
    switch (x) {
    case 0x14:
        GFL_NET_SetGameKind(0x17, 5);
        break;
    case 0x15:
        GFL_NET_SetGameKind(0x18, 5);
        break;
    case 0x16:
        GFL_NET_SetGameKind(0x19, 5);
        break;
    case 0x17:
        GFL_NET_SetGameKind(0x1a, 5);
        break;
    case 3:
        GFL_NET_SetGameKind(0x16, 5);
        break;
    case 0x19:
        GFL_NET_SetGameKind(0x1b, 5);
        break;
    }
}
