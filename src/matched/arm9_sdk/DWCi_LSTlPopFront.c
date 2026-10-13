/*
 * function: DWCi_LSTlPopFront
 * address:  0x02047250
 * packet:   pkt_02047250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E964 0x0206E964 arm
 */

struct DwcList { unsigned int f0; unsigned char *f4; };
extern unsigned char *func_0206E964(unsigned char *p);

unsigned char *DWCi_LSTlPopFront(struct DwcList *list)
{
    return func_0206E964(list->f4);
}
