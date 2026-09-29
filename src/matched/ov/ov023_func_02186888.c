/*
 * function: func_02186888
 * address:  0x02186888
 * packet:   pkt_ov023_02186888
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02186878  0x02186878  thumb
 */

typedef unsigned char u8;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 pad;
} Rec;

extern int func_02186878(char *p);

void func_02186888(char *p)
{
    if (((Rec *)(p + *(int *)(p + 0xBBC) * 30))->mid != 0
        || ((Rec *)(p + func_02186878(p) * 30))->mid != 0) {
        *(int *)(p + 0xBBC) += 1;
        if (*(int *)(p + 0xBBC) >= 100) {
            *(int *)(p + 0xBBC) = 0;
        }
    }
}
