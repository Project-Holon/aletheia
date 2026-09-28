/*
 * function: func_021FD088
 * address:  0x021FD088
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011324  0x02011324  thumb
 *   func_021F8710  0x021F8710  thumb  ov094
 *   d_0220AD58     0x0220AD58  data   ov094
 */
typedef struct {
    unsigned int pad0 : 6;
    unsigned int flag : 1;
    unsigned int pad7 : 25;
    char pad[0xd8];
    int dc;
    int e0;
    char pad2[0x248 - 0xe4];
    unsigned char kind;
} Unit;

extern Unit *func_02011324(int a);
extern int func_021F8710(void);
extern const int d_0220AD58[];

int func_021FD088(int a, int *out)
{
    Unit *s = func_02011324(a);
    int mode = func_021F8710();
    int v;

    *out = s->e0;
    if (*out != 0xff)
        return mode;
    if (mode == 0 || mode == 3 || s->flag == 1) {
        *out = s->dc ^ 1;
        return mode;
    }
    switch (s->kind) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 8:
    case 10:
        if (mode == 1) {
            mode = 0;
            *out = !(s->dc & 1);
        } else {
            v = s->dc;
            if (v != 4 && v != 5) {
                mode = 1;
                *out = d_0220AD58[v];
            } else {
                *out = v ^ 1;
            }
        }
        break;
    case 7:
    case 9:
    case 13:
        *out = s->dc ^ 1;
        break;
    case 11:
        mode = 0;
        *out = !(s->dc & 1);
        break;
    case 6:
    case 12:
        mode = 0;
        *out = (s->dc & 1) != 0;
        break;
    }
    return mode;
}
