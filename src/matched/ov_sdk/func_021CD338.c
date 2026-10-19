/*
 * function: procInit
 * address:  0x021CD338
 * packet:   pkt_021CD338
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlFade  0x021D55A4  arm
 *   DWCi_GXlVisible  0x021D603C  arm
 *   DWCi_GetParam2_  0x021C0EA0  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   func_021CD3B8  0x021CD3B8  arm
 */

extern void DWCi_EFFlFade(int a, int b, int c, int d);
extern void DWCi_GXlVisible(int a, int b);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CD3B8(void);

void procInit(void)
{
    int v;

    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_GetParam2_(0, (unsigned int *)(&v));
    if (v == 0) {
        DWCi_EFFlFade(2, 1, 1, 8);
        DWCi_GXlVisible(1, 1);
    }
    DWCi_ChangeScene((unsigned int)func_021CD3B8);
}
