/*
 * unit:     yes
 * function: func_021E2D5C, func_021E2DB4
 * address:  0x021E2D5C
 * packet:   pkt_ov093_021E2D5C
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
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_POKEPARAM_FindMoveSlot  0x021D5778  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPChecked  0x021D5584  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2860     0x021F2860  data  ov093  a4
 *   d_021F24BC     0x021F24BC  data  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u16 d_021F2860[];
extern u8 d_021F24BC[];

void func_021E2D5C(int u, void *p, int k)
{
    void *q;
    u32 n;
    int r;
    int v;
    if (k == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(p, k);
        r = BTL_POKEPARAM_FindMoveSlot(q, BTL_EVENT_GetFactorKey((void *)u));
        if (r != 4) {
            n = (u8)(int)BTL_POKEPARAM_GetMovePPChecked(q, (int)r);
            if (n >= 5)
                n = 4;
            v = d_021F2860[n];
        } else {
            v = 0x28;
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}

u8 *func_021E2DB4(int *p)
{
    *p = 1;
    return d_021F24BC;
}
