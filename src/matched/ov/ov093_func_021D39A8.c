/*
 * function: BTL_CLIENT_CmdCureSickMulti
 * address:  0x021D39A8
 * packet:   pkt_ov093_021D39A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CALC_UnpackPokeIds  0x021D8090  thumb  ov093
 *   func_021D3A10  0x021D3A10  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   func_021D6064  0x021D6064  thumb  ov093
 */
#include "../include/Obj21181.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BTL_CALC_UnpackPokeIds(u32 v, u8 *out);
extern u32 func_021D3A10(u32 i);
extern u8 *func_021B9934(char *p, int i);
union Slot;
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed);

int BTL_CLIENT_CmdCureSickMulti(u8 *a, int b, u32 *s)
{
    u8 buf[6];
    u32 i;
    u32 n;
    u32 m;
    u32 j;
    u32 t;
    u8 *q;

    n = s[1];
    m = s[0];
    BTL_CALC_UnpackPokeIds(s[2], buf);
    for (i = 0; i < n; i++) {
        t = func_021D3A10(i);
        if (t == 0)
            break;
        for (j = 0; j < m; j++) {
            q = func_021B9934((char *)(*(u8 * *)&((struct Obj21181 *)a)->f4), buf[j]);
            if (BTL_POKEPARAM_IsFainted(q) == 0)
                func_021D6064(q, t, 0, 0);
        }
    }
    return 1;
}
