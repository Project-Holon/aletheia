/*
 * function: func_021D284C
 * address:  0x021D284C
 * packet:   pkt_ov093_021D284C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021F88BC  0x021F88BC  thumb  ov094
 *   func_021F7EA4  0x021F7EA4  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 func_021B8E70(void *p, u8 k);
extern int func_021CD9E0(void *p);
extern void func_021F88BC(int v);
extern void func_021F7EA4(u32 v);
extern int func_021F7EB4(void);

int func_021D284C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u32 t = func_021B8E70(*(void **)p, *c);
        if (func_021CD9E0(p))
            func_021F88BC(1);
        func_021F7EA4(t);
        (*st)++;
        break;
    }
    case 1:
        if (!func_021F7EB4()) {
            if (func_021CD9E0(p))
                func_021F88BC(0);
            return 1;
        }
        break;
    }
    return 0;
}
