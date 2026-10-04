/*
 * function: func_021E5164
 * address: 0x021E5164
 * packet: pkt_ov119_021E5164
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021E51A2.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_021E5164(int p)
{
    int i, j;
    for (i = 0; i < 12; i++)
        for (j = 0; j < 5; j++)
            func_0204B3DC((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xac0), 0);
}
