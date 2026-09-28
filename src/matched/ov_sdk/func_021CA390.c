/*
 * function: func_021CA390
 * address:  0x021CA390
 * packet:   pkt_021CA390
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA390   0x021CA390  arm
 *   tbl_021DA61C   0x021DA61C  data
 *   func_021CE7B0   0x021CE7B0  arm
 *
 * Index the shared byte table and tail-call the dispatcher.
 * Addresses are Black-image addresses.
 */

extern void func_021CE7B0(int, int, int);
extern unsigned char tbl_021DA61C[];

void func_021CA390(void)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int i = *g - 0xb;
    int y = tbl_021DA61C[i];

    func_021CE7B0(*(int *)(*(int *)(g + 8) + 0x10), y, y);
}

