/*
 * function: func_021869C0
 * address:  0x021869C0
 * packet:   pkt_ov023_021869C0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 b5;
} Rec;

void func_021869C0(Rec *d, char *p)
{
    int i = *(int *)(p + 0xBB8);

    if (i != *(int *)(p + 0xBBC)) {
        *d = *(Rec *)(p + i * 30);
    } else {
        d->mid = 0;
    }
}
