/*
 * function: func_021EC48C
 * address:  0x021EC48C
 * packet:   pkt_ov170_021EC48C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EC000 0x021EC000 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021EC45C 0x021EC45C thumb
 *
 * Hides window win, and when slot (box, pos) holds something shows its icon
 * there again.  The image narrows both the slot and the box to 16 bits
 * before func_021DD25C, so its box parameter is declared unsigned short here;
 * the callee body only forwards it and cannot show the width.
 */

extern void func_021EC000(char *w, int i, int v);
extern unsigned func_021DD25C(unsigned char *p, unsigned short a, unsigned short box, unsigned id, unsigned v);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021EC45C(unsigned char *p, void *a, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EC48C(unsigned char *p, int box, int pos, int win)
{
    char *w = WORK(p);
    func_021EC000(WORK(p), win, 0);
    if (func_021DD25C(p, pos, box, 0xA9, 0)) {
        func_021EC45C(p, (void *)func_021DD2D0((void ***)p, box, pos), win);
        func_021EC000(w, win, 1);
    }
}
