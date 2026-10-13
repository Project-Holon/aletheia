/*
 * function: BTL_POKESET_CopyAlive
 * address:  0x0689CD78
 * packet:   pkt_ov095_0689CD78
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKESET_Clear  0x0689CB3C  thumb
 *   BTL_POKESET_GetCount  0x0689CD38  thumb  ov095
 *   BTL_POKESET_Get  0x0689CC70  thumb  ov095
 *   func_0689CDBC  0x0689CDBC  thumb
 *   BTL_POKESET_Add  0x0689CB48  thumb  ov095
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

void BTL_POKESET_Clear(void *p);
int BTL_POKESET_GetCount(S *p);
u32 BTL_POKESET_Get(S *p, u32 i);
int func_0689CDBC(u32 x);
void BTL_POKESET_Add(S *p, u32 id);

int BTL_POKESET_CopyAlive(S *p, S *q)
{
    u32 i;
    u32 n;
    u32 x;

    BTL_POKESET_Clear(q);
    n = BTL_POKESET_GetCount(p);
    for (i = 0; i < n; i++) {
        x = BTL_POKESET_Get(p, i);
        if (!func_0689CDBC(x))
            BTL_POKESET_Add(q, x);
    }
    return BTL_POKESET_GetCount(q);
}
