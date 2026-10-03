/*
 * function: func_021E1410
 * address: 0x021E1410
 * packet: pkt_ov119_021E1410
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E131C 0x021E131C thumb ov119
 */
extern void func_021E131C(char *p, int *ids, int count, int x, int y);
void func_021E1410(void *p, int *ids, int count)
{
    if (count == 1) {
        func_021E131C(p, ids, count, 0x20, 0x15);
        return;
    }
    func_021E131C(p, ids, count, 0x20, 0x18);
}
