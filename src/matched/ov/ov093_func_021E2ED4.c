/*
 * unit:     yes
 * function: func_021E2ED4, func_021E2F3C
 * address:  0x021E2ED4
 * packet:   pkt_ov093_021E2ED4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021C83A0  0x021C83A0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2A18     0x021F2A18  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u32 func_021C83A0(u8 *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u8 d_021F2A18[];

void func_021E2ED4(int u, void *p, int k)
{
    u32 n;
    int v;
    if (k == BTL_EVENT_GetVar(3)) {
        n = func_021C83A0(p, BTL_POKEPARAM_GetPokeId(func_021C7CF4(p, (u8)BTL_EVENT_GetVar(4))));
        if (n >= 2000) {
            v = 0x78;
        } else if (n >= 1000) {
            v = 100;
        } else if (n >= 500) {
            v = 80;
        } else if (n >= 250) {
            v = 60;
        } else {
            v = 40;
            if (n < 100)
                v = 20;
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}

u8 *func_021E2F3C(int *p)
{
    *p = 2;
    return d_021F2A18;
}
