/*
 * unit:     yes
 * function: func_021E2DC0, func_021E2E1C
 * address:  0x021E2DC0
 * packet:   pkt_ov093_021E2DC0
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2D3C     0x021F2D3C  data  ov093  a4
 *   d_021F24C4     0x021F24C4  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u32 d_021F2D3C[];
extern u8 d_021F24C4[];

void func_021E2DC0(int u, void *p, int k)
{
    void *q;
    u32 i;
    int x;
    int sum;
    u32 v;
    if (k == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(p, (u8)BTL_EVENT_GetVar(4));
        sum = 0;
        for (i = 0; i < 7; i++) {
            x = func_021D59B4(q, d_021F2D3C[i]);
            if (x > 6)
                sum += x - 6;
        }
        v = sum * 20 + 0x3c;
        if (v > 200)
            v = 200;
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}

u8 *func_021E2E1C(int *p)
{
    *p = 1;
    return d_021F24C4;
}
