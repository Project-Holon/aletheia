/*
 * function: func_0220C4EC
 * address: 0x0220C4EC
 * packet: pkt_ov197_0220C4EC
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0220C714 0x0220C714 thumb ov197
 *   func_0220C538 0x0220C538 thumb ov197
 *   func_0220C574 0x0220C574 thumb ov197
 *   func_0220C618 0x0220C618 thumb ov197
 */
extern void func_0204B3DC(int, int);
extern void func_0220C714(char *);
extern void func_0220C538(char *);
extern void func_0220C574(char *);
extern void func_0220C618(char *);
void func_0220C4EC(char *p, int mode)
{
    unsigned int i;
    for (i = 0; i < 63; i++) func_0204B3DC(*(int *)(p + i * 4 + 0x424), 0);
    func_0220C714(p);
    switch (mode) {
    case 0: func_0220C538(p); break;
    case 1: func_0220C574(p); break;
    case 2: func_0220C618(p); break;
    }
}
