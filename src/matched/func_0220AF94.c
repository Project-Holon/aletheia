/*
 * function: func_0220AF94
 * address:  0x0220AF94
 * packet:   pkt_0220AF94
 * region:   ov187
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045808   0x02045808  arm
 *   func_020315D4   0x020315D4  arm
 *   func_020306F0   0x020306F0  arm
 *   func_0220B0CC   0x0220B0CC  thumb
 *   func_0200B424   0x0200B424  thumb
 *
 * Tear down the four table slots at p+0x1780 when p+0x17C4 is set, then
 *   release the channel.
 */


extern void func_02045808(int);
extern void func_020315D4(int);
extern void func_020306F0(int);
extern void func_0220B0CC(int *);
extern void func_0200B424(void);

int func_0220AF94(int a, int b, int c, char *p)
{
    int i;
    if (*(int *)(p + 0x17C4) != 0) {
        for (i = 0; i < 4; i++) {
            int v = *(int *)(p + 0x1780 + i * 4);
            if (v != 0)
                func_02045808(v);
        }
    }
    func_0220B0CC((int *)p);
    func_0200B424();
    func_020315D4(a);
    func_020306F0(0x59);
    return 1;
}
