/*
 * function: func_02186A04
 * address:  0x02186A04
 * packet:   pkt_ov023_02186A04
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     Five six-byte records; remainder of handed extent is rodata.
 */

typedef unsigned char u8;
typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 b5;
} Rec;

void func_02186A04(Rec *d, char *p)
{
    int i;
    if (*(int *)(p + 0xBB8) != *(int *)(p + 0xBBC)) {
        for (i = 0; i < 5; i++) {
            d[i] = ((Rec *)(p + *(int *)(p + 0xBB8) * 30))[i];
        }
    } else {
        for (i = 0; i < 5; i++) {
            d[i].mid = 0;
        }
    }
}
