/*
 * file:     unit_021E6164.c
 * function: func_021E6164, func_021E61B0
 * address:  0x021E6164
 * packet:   pkt_ov093_021E6164
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F2A88     0x021F2A88  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C8288(u8 *p);
extern int func_021D76BC(int key, u32 val);

void func_021E6164(u8 *p, void *a, int b)
{
    int v;
    if (b != func_021D775C(2))
        return;
    switch (func_021C8288(a)) {
    case 1:
        v = 0xaac;
        break;
    case 2:
    case 3:
    case 4:
        v = 2 << 9;
        break;
    default:
        v = 2 << 10;
        break;
    }
    func_021D76BC(0x35, v);
}


extern int d_021F2A88[];
int *func_021E61B0(int *p);

int *func_021E61B0(int *p)
{
    *p = 2;
    return d_021F2A88;
}
