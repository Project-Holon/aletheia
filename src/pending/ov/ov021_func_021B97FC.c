/*
 * function: func_021B97FC
 * address:  0x021B97FC
 * packet:   pkt_ov021_021B97FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 */

/*
 * 2026-10-01: DIFF.  Logic is right; the original reloads p->h2 every
 * iteration (ldrh in the loop) while every tried form (for, u16 index,
 * hoisted base, pointer-add compare, int cast) hoists it like 021B97D0.
 */
typedef unsigned short u16;

typedef struct {
    char b[0x48];
} E48;

typedef struct {
    u16 h0;
    u16 h2;
    char pad[0x10];
    E48 *f14;
} Obj;

int func_021B97FC(Obj *p, E48 *e)
{
    int i;

    for (i = 0; i < p->h2; i++) {
        if (e == &p->f14[i]) {
            return i;
        }
    }
    return 0;
}
