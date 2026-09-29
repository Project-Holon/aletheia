/*
 * function: func_021FD15C
 * address:  0x021FD15C
 * packet:   pkt_ov094_021FD15C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */
typedef struct {
    char pad[0x4c];
    int slot[16];
} Tbl;

int func_021FD15C(Tbl *p, int key, int *out)
{
    int i;
    int r = 1;

    for (i = 0; i < 16; i++) {
        if (key == p->slot[i]) {
            r = 0;
            break;
        }
    }
    if (i == 16) {
        for (i = 0; i < 16; i++) {
            if (p->slot[i] == -1) {
                p->slot[i] = key;
                break;
            }
        }
    }
    *out = i;
    return r;
}
