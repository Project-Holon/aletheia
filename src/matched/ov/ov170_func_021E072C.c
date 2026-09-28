/*
 * function: func_021E072C
 * address:  0x021E072C
 * packet:   pkt_ov170_021E072C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED544 0x021ED544 thumb
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC768 0x021EC768 thumb
 *
 * Moves the window at 0x3DF6 to four pixels below window 4 and hides
 * sprite 0x24.
 */

extern void func_021ED544(unsigned char *p, int b);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern void func_021EC768(char *p, unsigned i, int flag);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021E072C(unsigned char *p)
{
    short xy[2];
    func_021ED544(p, 8);
    func_021EC0B0(WORK(p), 4, &xy[1], &xy[0], 0);
    func_021EC08C(WORK(p), *(unsigned char *)(WORK(p) + 0x3DF6), xy[1], xy[0] + 4, 0);
    func_021EC768(WORK(p), 0x24, 0);
}
