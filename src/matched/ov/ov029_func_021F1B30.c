/*
 * function: func_021F1B30
 * address: 0x021F1B30
 * packet: pkt_ov029_021F1B30
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
extern void func_0204B3DC(int, int);
void func_021F1B30(char *p, int flag)
{
    int i;
    for (i = 0; i < 18; i++)
        func_0204B3DC(*(int *)(p + i * 4 + 0x170), flag);
}
