/*
 * function: func_021B97D0
 * address:  0x021B97D0
 * packet:   pkt_ov021_021B97D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

typedef struct {
    char b[0x70];
} E70;

typedef struct {
    u16 h0;
    char pad[0xE];
    E70 *f10;
} Obj;

int func_021B97D0(Obj *p, E70 *e)
{
    int i;

    for (i = 0; i < p->h0; i++) {
        if (e == &p->f10[i]) {
            return i;
        }
    }
    return 0;
}
