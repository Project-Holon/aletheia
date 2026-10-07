/*
 * file:     box2_seq_p40.c
 * unit:     yes
 * function: func_021ECB20, func_021ECB60, func_021ECB74, func_021ECB84, func_021ECBD8
 * address:  0x021ECB20
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ECA6C  0x021ECA6C  thumb  ov170
 *   func_021EC060  0x021EC060  thumb  ov170
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC768 0x021EC768 thumb
 */
extern void func_021ECA6C(unsigned char *p, int flag, int i, unsigned end, int mode);
extern void func_021EC060(char *p, unsigned i, int b);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021EC768(char *p, unsigned i, int flag);
void func_021ECB20(char *p, int f, int c);
void func_021ECB60(char *p, int i, int f);
void func_021ECB74(char *a, int b);
void func_021ECB84(char *w, unsigned i);
void func_021ECBD8(unsigned char *p, int i);

/*
 * Dispatch flag bits 1 and 2 to the two range halves, with bit
 *   0x80 selecting the sub-range selector.  Matches on the tst-based ternary.
 */
void func_021ECB20(char *p, int f, int c)
{
    int t = (f & 0x80) ? 1 : 0;
    if (f & 1)
        func_021ECA6C((unsigned char *)p, c, 0, 0x1e, t);
    if (f & 2)
        func_021ECA6C((unsigned char *)p, c, 0x1e, 0x25, t);
}


/*
 * Forward the byte at the pooled table offset.  The callee takes three
 * arguments, so the forwarded byte is argument 1 and the passing flag
 * stays in r2 untouched; that is what forces the sum into r3.
 */
void func_021ECB60(char *p, int i, int f)
{
    func_021EC060(p, *(unsigned char *)(p + i + 0x3DD2), f);
}

/*
 * One range call with the selector pair fixed.
 */
void func_021ECB74(char *a, int b)
{
    func_021ECA6C((unsigned char *)a, 1, b, b + 1, 1);
}


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


void func_021ECBD8(unsigned char *p, int i)
{
    short xy[2];
    unsigned char t;
    func_021EC0B0((char *)p, p[0x3DF6], &xy[1], &xy[0], 0);
    t = (p + 0x3DD2)[i];
    (p + 0x3DD2)[i] = p[0x3DF6];
    p[0x3DF6] = t;
    func_021EC08C((char *)p, p[0x3DF6], xy[1], xy[0], 0);
}
