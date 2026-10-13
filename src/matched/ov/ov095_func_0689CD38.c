/*
 * unit:     yes
 * function: BTL_POKESET_GetCount, BTL_POKESET_GetCountMax, BTL_POKESET_SetEmptyMarked, BTL_POKESET_IsRemovedAll
 * address:  0x0689CD38
 * packet:   pkt_ov095_0689CD38
 * region:   ov095
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
    u32 id[6];
    u16 a[6];
    u16 b[6];
    u8 c[6];
    u16 d[6];
    u8 n;
    u8 max;
    u8 f44;
    u8 f45;
} S;

int BTL_POKESET_GetCount(S *p)
{
    return p->n;
}

int BTL_POKESET_GetCountMax(S *p)
{
    return p->max;
}

void BTL_POKESET_SetEmptyMarked(S *p, u8 v)
{
    p->f45 = v;
}

int BTL_POKESET_IsRemovedAll(S *p)
{
    if (p->max != 0 || p->f45 != 0) {
        if (p->n == 0)
            return 1;
        return 0;
    }
    return 0;
}
