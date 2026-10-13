/*
 * function: UNION_CHARA_ProcessBeaconUpdates
 * address: 0x0217B75C
 * packet: pkt_ov019_0217B75C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the bit at byte 7, bit 4 is a one-bit unsigned char field;
 * integer masks instead produce asrs/movs/ands and grow the body by 4 bytes.
 * symbols:
 *   UNION_CHARA_OnBeaconUpdate 0x0217B798 thumb ov019
 */
typedef unsigned char u8;
typedef struct {
    u8 pad[7];
    unsigned char low : 4;
    unsigned char flag : 1;
    unsigned char high : 3;
} Flags;
extern void UNION_CHARA_OnBeaconUpdate(char *, u8 *);
void UNION_CHARA_ProcessBeaconUpdates(char *p)
{
    int i;
    u8 *q;
    q = (u8 *)p + 0x2910;
    for (i = 0; i < 10; i++, q += 0x8c) {
        if (((Flags *)q)->flag == 1 && q[0x6a] != 0) {
            UNION_CHARA_OnBeaconUpdate(p, q);
            q[0x6a] = 0;
        }
    }
}
