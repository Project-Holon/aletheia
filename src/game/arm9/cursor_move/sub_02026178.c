/*
 * function: func_02026178
 * address:  0x02026178
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

int func_02026178(const u8 *ptr, u32 type)
{
    switch (type) {
    case 0:
        if (ptr[5] & 0x80) {
            return 1;
        }
        break;
    case 1:
        if (ptr[4] & 0x80) {
            return 1;
        }
        break;
    case 2:
        if (ptr[7] & 0x80) {
            return 1;
        }
        break;
    case 3:
        if (ptr[6] & 0x80) {
            return 1;
        }
        break;
    }
    return 0;
}
