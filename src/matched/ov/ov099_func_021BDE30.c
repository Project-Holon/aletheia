/*
 * function: func_021BDE30
 * address: 0x021BDE30
 * packet: pkt_ov099_021BDE30
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 98 bytes code followed by two zero alignment bytes.
 * symbols:
 *   func_0203D644 0x0203D644 arm
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_021BDDB4 0x021BDDB4 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 */
extern void func_0203D644(int);
extern void func_021BDD0C(void *, int);
extern int func_021BDDB4(int, int);
extern int func_020399A8(void);
extern int func_0203D1E8(int, int);
void func_021BDE30(void *p, int kind, int value)
{
    if (kind == 1) {
        func_0203D644(0);
        func_021BDD0C(p, 0);
    } else {
        if (func_021BDDB4(kind, value)) func_0203D644(1);
    }
    switch (kind) {
    case 2:
    case 5:
        func_0203D1E8(func_020399A8(), 1);
        return;
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
    default:
        func_0203D1E8(func_020399A8(), 1);
        break;
    }
}
