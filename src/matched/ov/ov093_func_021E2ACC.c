/*
 * unit:     yes
 * function: func_021E2ACC, func_021E2B0C
 * address:  0x021E2ACC
 * packet:   pkt_ov093_021E2ACC
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
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021F29F8     0x021F29F8  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u8 d_021F29F8[];

void func_021E2ACC(int u, void *p, int k)
{
    u32 v;
    if (k == BTL_EVENT_GetVar(3)) {
        v = (u32)((0xff - POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon(func_021C7CF4(p, k)), 9, 0)) * 10) / 25;
        if (v == 0)
            v = 1;
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}

u8 *func_021E2B0C(int *p)
{
    *p = 2;
    return d_021F29F8;
}
