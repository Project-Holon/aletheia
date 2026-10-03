/*
 * function: func_021C24F0
 * address:  0x021C24F0
 * packet:   pkt_ov021_021C24F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the per-list base offsets are written as running sums from 0 (`0 + na`,
 *           `0 + i`): the folded add keeps the u8/u16 re-truncation and stops the copy
 *           being propagated (baseb gets its own slot, idx gets lsl/lsr #16). The id
 *           scan uses its own counter j, declared before n, for the r3/r5 colouring.
 *
 * symbols:
 *   func_02048F4C  0x02048F4C  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE3D8     0x021DE3D8  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u16 h4;
    u16 h6;
    u16 a[2];
    u16 hc;
    u16 he;
    u16 b[4];
    u16 c[4];
    u32 w20;
} Src;

typedef struct {
    u32 kind;
    u16 id;
    u32 val;
} E0;

typedef struct {
    u16 idx;
    u16 zero;
} E2;

typedef struct {
    u16 idx;
    u16 zero;
    u16 idx2;
    E2 *list;
    u16 cnt;
} E1;

typedef struct {
    E0 *e0;
    E1 *e1;
    E2 *e2;
    E2 *e3;
    E0 *p10;
    u16 n10;
    E1 *p18;
    u16 n1c;
    u16 pad1e;
    u16 h20;
    u16 h22;
    u16 h24;
    u16 h26;
    u32 w28;
    u8 total;
    u8 na;
    u8 nb;
    u8 nc;
    u32 w30;
} Out;

extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u8 d_021DE3D8;

void func_021C24F0(Out *out, u32 b, u32 heap)
{
    Src s;
    u16 ids[8];
    u8 na, nb, nc, total, baseb, basec;
    u8 i, j, n;

    func_02048F4C(&s, 0x75, b);
    na = 0;
    for (i = 0; i < 2; i++) {
        if (s.a[i] != 0xFFFF) {
            na++;
        }
    }
    nc = 0;
    nb = 0;
    for (i = 0; i < 4; i++) {
        if (s.b[i] != 0xFFFF) {
            nb++;
        }
    }
    for (i = 0; i < 4; i++) {
        if (s.c[i] != 0xFFFF) {
            nc++;
        }
    }
    baseb = 0 + na;
    basec = baseb + nb;
    total = na + nb + nc;
    if (total != 0) {
        out->e0 = func_02030734(heap, total * 12, 1, (const char *)&d_021DE3D8, 0x566);
    }
    if (na != 0) {
        out->e1 = func_02030734(heap, na * 16, 1, (const char *)&d_021DE3D8, 0x56a);
    }
    if (nb != 0) {
        out->e2 = func_02030734(heap, nb * 4, 1, (const char *)&d_021DE3D8, 0x56e);
    }
    if (nc != 0) {
        out->e3 = func_02030734(heap, nc * 4, 1, (const char *)&d_021DE3D8, 0x572);
    }
    out->total = total;
    out->na = na;
    out->nb = nb;
    out->nc = nc;
    out->h20 = s.h4;
    out->h22 = s.h6;
    out->h24 = s.hc;
    out->h26 = s.he;
    ids[0] = s.a[0];
    ids[1] = s.a[1];
    ids[2] = s.b[0];
    ids[3] = s.b[1];
    ids[4] = s.b[2];
    ids[5] = s.c[0];
    ids[6] = s.c[1];
    ids[7] = s.c[2];
    n = 0;
    for (j = 0; j < 8; j++) {
        if (ids[j] != 0xFFFF) {
            out->e0[n].kind = 0x73;
            out->e0[n].id = ids[j];
            out->e0[n].val = 0;
            n++;
        }
    }
    for (i = 0; i < nb; i++) {
        out->e2[i].idx = baseb + i;
        out->e2[i].zero = 0;
    }
    for (i = 0; i < nc; i++) {
        out->e3[i].idx = basec + i;
        out->e3[i].zero = 0;
    }
    for (i = 0; i < na; i++) {
        out->e1[i].idx = 0 + i;
        out->e1[i].zero = 0;
        out->e1[i].idx2 = 0 + i;
    }
    if (na >= 1) {
        out->e1[0].list = out->e2;
        out->e1[0].cnt = nb;
    }
    if (na >= 2) {
        out->e1[1].list = out->e3;
        out->e1[1].cnt = nc;
    }
    out->p10 = out->e0;
    out->n10 = total;
    out->n1c = na;
    out->p18 = out->e1;
    out->w28 = s.w0;
    out->w30 = s.w20;
}
