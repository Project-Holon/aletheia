/*
 * function: DWCi_COMMENTlDelete
 * address:  0x021BD138
 * packet:   pkt_ov016_021BD138
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_COMMENTlDelete (libdwcutil.TWL.HYB.a comment.o)
 *
 * symbols:
 *   DWCi_FNTlDeleteBgLcd 0x021D5CA8  arm
 *   Flag                 0x021DE50C  data  a1
 */

void DWCi_FNTlDeleteBgLcd(int lcd);
extern unsigned char Flag;

int DWCi_COMMENTlDelete(void)
{
    if (Flag == 0) return 0;
    DWCi_FNTlDeleteBgLcd(1);
    Flag = 0;
    return 1;
}
