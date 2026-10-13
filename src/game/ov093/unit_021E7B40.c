/*
 * file:     unit_021E7B40.c
 * unit:     yes
 * function: func_021E7B40, func_021E7B8C
 * address:  0x021E7B40
 * packet:   pkt_ov093_021E7B40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * d_021F283C: the ov093 hint is contested at this address; the plain
 * `data a4` line resolves it as sole-ref/data.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTLV_CORE_BytesOverlap  0x021E8D48  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F283C     0x021F283C  data   a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetTypePair(void *p);
extern int BTLV_CORE_BytesOverlap(int a, int b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int d_021F283C[];

void func_021E7B40(int a, int b, int c)
{
    u8 k;
    void *x, *y;
    u32 u;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(4);
        x = func_021C7CF4((int *)b, k);
        y = func_021C7CF4((int *)b, c);
        u = BTL_POKEPARAM_GetTypePair(y);
        if (BTLV_CORE_BytesOverlap(u, BTL_POKEPARAM_GetTypePair(x)) == 0)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}

int *func_021E7B8C(int *p)
{
    *p = 1;
    return d_021F283C;
}
