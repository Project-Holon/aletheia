/*
 * function: func_021E0FF4
 * address: 0x021E0FF4
 * packet: pkt_ov119_021E0FF4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0EF4 0x021E0EF4 thumb ov119
 */
extern void func_021E0EF4(char *p, int flag, int x, int y, int w, int h);
void func_021E0FF4(void *p, int a, int flag)
{
    if (flag) {
        func_021E0EF4(p, a, 1, 0x12, 0x1E, 4);
        return;
    }
    func_021E0EF4(p, a, 1, 1, 0x1E, 4);
}
