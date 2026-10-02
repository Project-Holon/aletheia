/*
 * function: func_021BBC04
 * address: 0x021BBC04
 * packet: pkt_ov206_021BBC04
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef struct S {
    char pad0[0x174];
    void *a[2];
    char padx[0xc];
    void *b[2];
    int sel;
} S;
extern void func_0204B3DC(void *, int);
void func_021BBC04(S *p)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (i != p->sel && p->b[i] != 0)
            func_0204B3DC(p->b[i], 0);
    }
}
