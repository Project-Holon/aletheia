/*
 * function: BTL_POKESET_CopyEnemies
 * address:  0x0689CE58
 * packet:   pkt_ov095_0689CE58
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
 *   BTL_POKESET_Add  0x0689CB48  thumb  ov095
 *   func_0689CEB4  0x0689CEB4  thumb
 *   func_0689CEC4  0x0689CEC4  thumb
 *   func_0689CED4  0x0689CED4  thumb
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
void BTL_POKESET_Add(S *p, u32 id);
int func_0689CEB4(int a);
int func_0689CEC4(u32 x);
int func_0689CED4(int a, int b);

int BTL_POKESET_CopyEnemies(S *p, int a, S *q)
{
    u32 i;
    u32 n;
    u32 x;
    int s;

    BTL_POKESET_Clear(q);
    s = func_0689CEB4(a);
    n = BTL_POKESET_GetCount(p);
    for (i = 0; i < n; i++) {
        x = BTL_POKESET_Get(p, i);
        if (!func_0689CED4(s, func_0689CEC4(x)))
            BTL_POKESET_Add(q, x);
    }
    return BTL_POKESET_GetCount(q);
}
