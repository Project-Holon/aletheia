/*
 * function: func_021EFF48
 * address:  0x021EFF48
 * packet:   pkt_ov033_021EFF48
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216476C 0x0216476C thumb ov010
 *   func_021EFEEC 0x021EFEEC thumb ov033
 *   func_021CFB68 0x021CFB68 thumb ov021
 */

typedef struct {
    unsigned kind;
    unsigned a;
    unsigned b;
} Rec;

typedef struct {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned short h6;
    unsigned f8;
    unsigned short hc;
} T;

extern char *func_0216476C(unsigned short *);
extern int func_021EFEEC(char *p, int *q);
extern unsigned func_021CFB68(unsigned, unsigned *);

int func_021EFF48(T *p, unsigned *out, int mode)
{
    unsigned short cnt;
    unsigned idx;
    Rec rec;
    char *tbl;
    unsigned v;
    int found;

    found = 0;
    tbl = func_0216476C(&cnt);
    idx = p->hc;
    if (mode == 0 || mode == 1) {
        while (p->h4 < cnt) {
            rec.kind = 1;
            rec.a = (unsigned)(tbl + p->h4 * 10);
            if (func_021EFEEC((char *)p, (int *)(&rec))) {
                out[0] = rec.kind;
                out[1] = rec.a;
                found = 1;
            }
            p->h4++;
            if (found)
                return 1;
        }
    }
    if (mode == 0 || mode == 2) {
        v = func_021CFB68(p->f8, &idx);
        p->hc = idx;
        while (v != 0) {
            rec.b = v;
            rec.kind = 2;
            if (func_021EFEEC((char *)p, (int *)(&rec))) {
                out[0] = rec.kind;
                out[2] = rec.b;
                found = 1;
            }
            if (found)
                return 1;
            v = func_021CFB68(p->f8, &idx);
            p->hc = idx;
        }
    }
    out[0] = 0;
    return 0;
}
