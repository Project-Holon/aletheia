/*
 * function: func_021BBBD8
 * address:  0x021BBBD8
 * packet:   pkt_ov021_021BBBD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

typedef struct Entry { u8 d[0x24]; } Entry;

typedef struct Ring {
    Entry e[30];
    u8 head;
    u8 tail;
    u8 pad2[2];
    int count;
} Ring;

Entry *func_021BBBD8(Ring *r)
{
    int t;
    Entry *ret;
    if (r->count > 0) {
        t = r->tail;
        if (t == r->head) {
            r->head += 1;
            if (r->head >= 30) r->head = 0;
        }
    }
    ret = &r->e[r->tail];
    r->tail += 1;
    if (r->tail >= 30) r->tail = 0;
    return ret;
}
