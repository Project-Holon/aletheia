/*
 * function: func_021ECB84
 * address:  0x021ECB84
 * packet:   pkt_ov170_021ECB84
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC768 0x021EC768 thumb
 */

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021EC768(char *p, unsigned i, int flag);

void func_021ECB84(char *w, unsigned i)
{
    short xy[2];
    unsigned char *tbl = (unsigned char *)(w + 0x3DD2);
    unsigned char t;
    func_021EC0B0(w, tbl[i], &xy[1], &xy[0], 0);
    t = w[0x3DF6];
    w[0x3DF6] = tbl[i];
    tbl[i] = t;
    func_021EC08C(w, tbl[i], xy[1], xy[0], 0);
    func_021EC768(w, i, 1);
}
