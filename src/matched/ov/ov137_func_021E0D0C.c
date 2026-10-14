/*
 * function: GURU2_MAIN_DropEffectStateLand
 * address: 0x021E0D0C
 * packet: pkt_ov137_021E0D0C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021E0D4E.
 * symbols:
 *   GURU2_MAIN_PrintPlayerName 0x021E0450 thumb ov137
 */
typedef unsigned char  u8;
extern void GURU2_MAIN_PrintPlayerName(u8 *p, void *text, int index, int a);
int GURU2_MAIN_DropEffectStateLand(int *p)
{
    int *q = (int *)p[4];
    char *r;
    if (p[3] > 0x1000) {
        p[3] -= 0x1000;
        if (p[3] < 0x1000) p[3] = 0x1000;
    }
    q[21] -= p[3];
    if (q[21] <= 0) {
        q[21] = 0;
        r = (char *)p[5];
        GURU2_MAIN_PrintPlayerName((u8 *)r, (void *)(*(int *)(r + 0xa4 + q[3]*4)), q[5], q[3]);
        return 2;
    }
    return 0;
}
