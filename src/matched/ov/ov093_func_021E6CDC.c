/*
 * function: func_021E6CDC
 * address:  0x021E6CDC
 * packet:   pkt_ov093_021E6CDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   func_021E6D90  0x021E6D90  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct QG;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern int func_021E6D90(int e);
extern int WAZA_TOOL_GetFlag(int bag, int item);
extern u32 BTL_CALC_Random(u32 range);
extern int func_021C8030(u8 *p, int v, u16 k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E6CDC(int x, int a, int c, u32 *d)
{
    void *m;
    u8 n;
    u8 cnt;
    u8 i;
    int e;
    int t = 2;
    u16 id;
    int r;

    if (c == BTL_EVENT_GetVar(2)) {
        m = func_021C7CF4((int *)a, c);
        if (BTL_POKEPARAM_HasSick(m, t) != 0) {
            n = BTL_POKEPARAM_GetMoveCount(m);
            i = 0;
            cnt = 0;
            for (; i < n; i++) {
                e = BTL_POKEPARAM_GetMoveId(m, i);
                if (func_021E6D90(e) == 0 && WAZA_TOOL_GetFlag(e, 1) == 0) {
                    d[cnt++] = e;
                }
            }
            if (cnt != 0) {
                id = d[(u8)BTL_CALC_Random(cnt)];
                r = func_021C8030((u8 *)a, c, id);
                BTL_EVENT_OverwriteVar(0x12, id);
                BTL_EVENT_OverwriteVar(0xd, r);
            } else {
                BTL_EVENT_OverwriteVar(0x41, 1);
            }
        }
    }
}
