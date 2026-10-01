/*
 * function: func_02206950
 * address:  0x02206950
 * packet:   pkt_ov094_02206950
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    char p0[0x58];
    int f58;
    char p5c[0x68 - 0x5c];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x242 - 0x6c];
    u8 row[4][8];
    char p262[0x266 - 0x262];
    u16 a266[3];
    u16 a26c[8];
    int k;
} W;

void func_02206950(W *p)
{
    u8 b;

    switch (p->f58) {
    case 2:
        if (p->a266[p->k] != p->a26c[p->row[p->k][p->f58]])
            p->row[p->k][3] = 0;
    case 1:
    case 5:
        p->sel = p->row[p->k][p->f58];
        break;
    case 3:
        b = p->row[p->k][p->f58];
        if (((b & 0xf0) >> 4) == p->row[p->k][2])
            p->sel = b;
        else
            p->sel = 0;
        break;
    default:
        p->sel = 0;
        break;
    }
}
