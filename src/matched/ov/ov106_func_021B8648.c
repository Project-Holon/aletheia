/*
 * function: func_021B8648
 * address: 0x021B8648
 * packet: pkt_ov106_021B8648
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_020409B4(unsigned int);
void func_021B8648(u8 *p) {
    int i;
    for(i=0;i<2;i++) {
        BMP_WIN_TransferChars(*(void **)((u8 *)((unsigned int *)p+i)+0x568));
        BMP_WIN_MakeScreen(*(void **)((u8 *)((unsigned int *)p+i)+0x568));
    }
    func_020409B4(p[0x548]);
    func_020409B4(p[0x54a]);
    func_020409B4(p[0x549]);
    func_020409B4(p[0x54b]);
}
