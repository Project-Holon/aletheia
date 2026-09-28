/*
 * function: WCMi_WmifGetAllowedChannel
 * address:  0x02166DE4
 * packet:   pkt_ov009_02166DE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_WmifGetAllowedChannel (wmif.o)
 *
 * symbols:
 *   WM_GetAllowedChannel            0x0208ee60 arm
 */

extern unsigned short WM_GetAllowedChannel(void);

unsigned short WCMi_WmifGetAllowedChannel(void)
{
    unsigned short val = WM_GetAllowedChannel();
    unsigned short low, high, tmp;

    high = 0x8000;
    low = 1;
    if (val == 0)
        return 0;
    if ((val & 0x8000) == 0) {
        do {
            high = (high >> 1) | 0x8000;
        } while ((high & val) == 0);
    }
    if ((val & 1) == 0) {
        do {
            low = (low << 1) | 1;
        } while ((low & val) == 0);
    }
    tmp = (unsigned short)~((unsigned short)((unsigned int)high << 1) | ((unsigned int)low >> 1));
    return tmp;
}
