/*
 * function: func_021C1174
 * address: 0x021C1174
 * packet: pkt_ov110_021C1174
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero padding at 0x021C11B6.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(unsigned);
int func_021C1174(unsigned owner, void *p, int *state) {
    unsigned q = (unsigned)BMP_WIN_GetBmp(p);
    if (*state == 1 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)owner, (void *)q) == 0) {
        BMP_WIN_TransferChars(p);
        BMP_WIN_MakeScreen(p);
        func_02041B6C(BMP_WIN_GetBgLayer(p));
        *state = 0;
        return 1;
    }
    return 0;
}
