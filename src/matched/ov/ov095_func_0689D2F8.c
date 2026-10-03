/*
 * function: func_0689D2F8
 * address: 0x0689D2F8
 * packet: pkt_ov095_0689D2F8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: follower after non-C veneer 0x0689D2E8; code ends at 0x0689D320.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a, b, c; } Rec;
void func_0689D2F8(u8 *p, int b)
{
    u32 i;
    Rec *q;
    for (i = 0; i < 6; i++) {
        q = (Rec *)(p + i * 3);
        if (q->a != 0 && b == q->c) {
            q->c = 31;
            return;
        }
    }
}
