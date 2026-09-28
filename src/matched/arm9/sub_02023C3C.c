/*
 * function: sub_02023C3C
 * address:  0x02023C3C
 * packet:   pkt_02023C3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Window-bounds setter: picks one of the four window-bounds register
 * pairs (WIN0H/WIN0V and WIN1H/WIN1V, each in the main or the sub
 * engine) and writes the packed horizontal and vertical limits.
 *
 * The four bodies are textually identical in the original, which is why
 * the value expressions are repeated in each arm rather than hoisted:
 * a shared pair of locals computes once and costs 24 bytes less than the
 * image.  The second halfword is one register plus #4, so each arm holds
 * a pointer to the base register and indexes it [0] and [2]; spelling
 * both addresses absolutely puts two pool words per arm in the image
 * where the original has one.
 *
 * The leading argument shuffle (r4 <- r2, r2 <- r3) is the fourth
 * argument's register being recycled for the fifth.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void sub_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub)
{
    if (win == 0) {
        if (sub == 0) {
            u16 *p = (u16 *)0x04000040;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        } else {
            u16 *p = (u16 *)0x04001040;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        }
    } else {
        if (sub == 0) {
            u16 *p = (u16 *)0x04000042;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        } else {
            u16 *p = (u16 *)0x04001042;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        }
    }
}
