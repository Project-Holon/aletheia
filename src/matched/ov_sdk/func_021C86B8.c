/*
 * function: calcParam
 * address:  0x021C86B8
 * packet:   pkt_021C86B8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   calcParam 0x021C86B8 arm
 *   DWCi_GetParam2_  0x021C0EA0  arm
 *   DWCi_SETTIGNlGet  0x021CF404  arm
 *
 * Poll the input driver into a local and clear the shared counter when it reads zero.
 * Addresses are Black-image addresses.
 */

extern char *DWCi_SETTIGNlGet(void);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);

void calcParam(void)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int z = 0;
    int v;

    DWCi_SETTIGNlGet();
    DWCi_GetParam2_((unsigned int *)z, (unsigned int *)(&v));
    if (v == 0) {
        *(unsigned short *)(g + 4) = z;
        *(unsigned char *)g = z;
        *(unsigned char *)(g + 2) = z;
    }
}

