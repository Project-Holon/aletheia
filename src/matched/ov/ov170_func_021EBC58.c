/*
 * function: func_021EBC58
 * address:  0x021EBC58
 * packet:   pkt_ov170_021EBC58
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_0201EF14 0x0201EF14 thumb
 *   func_021EBA84 0x021EBA84 thumb
 *
 * Picks the prompt for a menu kind (kind 1 first names the Pokemon in the
 * current slot) and prints it into window i.  An out-of-range kind prints
 * whatever msg holds; the image does not initialise it.
 */

typedef unsigned int u32;

extern void *func_021DD2D0(unsigned char *p, int a, unsigned b);
extern void func_0201EF14(void *ws, u32 i, void *mon);
extern void func_021EBA84(unsigned char *p, int msg, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EBC58(unsigned char *p, int sel, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x10;
        break;
    case 1:
        msg = 0;
        func_0201EF14(*(void **)(WORK(p) + 0x84), 0, func_021DD2D0(p, p[0x14], p[0x16]));
        break;
    case 2:
        msg = 5;
        break;
    case 3:
        msg = 0x11;
        break;
    case 4:
        msg = 0xC;
        break;
    case 5:
        msg = 0x1B;
        break;
    }
    func_021EBA84(p, msg, i);
}
