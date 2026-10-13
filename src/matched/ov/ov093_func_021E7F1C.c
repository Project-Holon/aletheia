/*
 * function: func_021E7F1C
 * address:  0x021E7F1C
 * packet:   pkt_ov093_021E7F1C
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
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QF;
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E7F1C(int a, void *b, int c)
{
    void *m;
    int r;
    if (c == BTL_EVENT_GetVar(3)) {
        u8 k = BTL_EVENT_GetVar(4);
        m = func_021C7CF4(b, k);
        r = BTL_POKEPARAM_GetSpecies(m);
        if (r == 0x32 || r == 0x33 || BTL_POKEPARAM_HasSick(m, 0x1f) != 0
            || BTL_POKEPARAM_HasSick(m, 0x15) != 0)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}
