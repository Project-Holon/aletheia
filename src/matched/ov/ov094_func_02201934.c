/*
 * function: func_02201934
 * address:  0x02201934
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02209FC8  0x02209FC8  data  ov094
 *   d_02209FD0  0x02209FD0  data  ov094
 *   d_0220A008  0x0220A008  data  ov094
 *   d_0220A020  0x0220A020  data  ov094
 *   d_0220A038  0x0220A038  data  ov094
 */
typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags;

typedef struct {
    char pad[0x510];
    Flags flags;
} Unit;

extern const int d_02209FC8[];
extern const int d_02209FD0[];
extern const int d_0220A008[];
extern const int d_0220A020[];
extern const int d_0220A038[];

int func_02201934(Unit *u, int i, int mode)
{
    if (mode == 0) {
        switch (i) {
        case 0:
        case 1:
            return d_02209FC8[i];
        case 2:
        case 3:
        case 4:
        case 5:
            if (u->flags.b1)
                return d_0220A008[i - 2];
            if (u->flags.b0)
                return d_0220A038[i - 2];
            return d_02209FD0[i - 2];
        case 6:
        case 7:
            if (u->flags.b1)
                return d_0220A008[i - 2];
            return d_0220A038[i - 2];
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            return d_0220A020[i - 8];
        }
    } else {
        if (i < 8) {
            if (i & 1)
                return 0x10000;
            return 0x20000;
        }
        return 0x10000;
    }
}
