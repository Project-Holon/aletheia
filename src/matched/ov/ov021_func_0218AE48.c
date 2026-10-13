/*
 * function: FIELD_EVENT_CHECK_GetFrontPos
 * address:  0x0218AE48
 * packet:   pkt_ov021_0218AE48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct Vec { int x, y, z; } Vec;

typedef struct Obj {
    char pad[0x24];
    unsigned short dir;     /* 0x24 */
    char pad26[0x34 - 0x26];
    Vec *pos;               /* 0x34 */
} Obj;

void FIELD_EVENT_CHECK_GetFrontPos(Obj *p, Vec *out)
{
    *out = *p->pos;
    switch (p->dir) {
    case 0:
        out->z -= 0x10000;
        break;
    case 1:
        out->z += 0x10000;
        break;
    case 2:
        out->x -= 0x10000;
        break;
    case 3:
        out->x += 0x10000;
        break;
    }
}
