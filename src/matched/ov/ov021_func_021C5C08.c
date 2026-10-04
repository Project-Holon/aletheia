/*
 * function: func_021C5C08
 * address:  0x021C5C08
 * packet:   pkt_ov021_021C5C08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  pooled 0x000000AB is an overlay-id-like absolute symbol passed to
 *           func_020146F8 (0x020146F8), which is not in match.py
 *           OVERLAY_ID_CONSUMERS, so the ABS32 has no witness (literal class
 *           refuses the range's own pool word).  Every concrete byte matches.
 *
 * symbols:
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   ov171_id       0x000000AB  data  a1
 *   d_021DEA44    0x021DEA44  data  ov021  a1
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    u16 f8[3];
    u16 fE;
    u16 *f10;
} Arg;

extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern char d_021DEA44[];
extern char ov171_id[];

int func_021C5C08(void *a, int *st, Arg *p)
{
    int v;

    switch (*st) {
    case 0:
        func_02012374(a, func_020146F8((char *)p->f0, p->f4, (int)ov171_id, (int)d_021DEA44, (int)p->f8));
        *st = *st + 1;
        break;
    case 1:
        switch (p->fE) {
        case 0:
            v = 0;
            *p->f10 = v;
            break;
        case 1:
            v = 1;
            *p->f10 = v;
            break;
        }
        return 1;
    }
    return 0;
}
