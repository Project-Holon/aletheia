/*
 * function: DWCi_InitReliableQueue
 * address:  0x021B2F98
 * packet:   pkt_ov013_021B2F98
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B4C24 0x021B4C24 data
*/

typedef struct E E;

typedef struct {
    E *cur;
    E *buf;
} G;

extern G d_021B4C24;

void DWCi_InitReliableQueue(void)
{
    d_021B4C24.cur = 0;
    d_021B4C24.buf = 0;
}

