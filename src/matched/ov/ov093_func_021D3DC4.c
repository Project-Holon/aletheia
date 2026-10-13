/*
 * function: BTL_CLIENT_TakeTrainerItemToUse
 * address:  0x021D3DC4
 * packet:   pkt_ov093_021D3DC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlClientItemSlotLimits  0x021EFF74  data  a1
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   BTL_CLIENT_IsStatItemUsable  0x021D3E70  thumb  ov093
 *   BTL_CLIENT_IsSickItemUsable  0x021D3EC8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 gBtlClientItemSlotLimits[];
struct Q1;
struct Unk021D62A8;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int func_021D59B4(u8 *p, int k);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 b);
extern int BTL_CLIENT_IsStatItemUsable(void *s, void *m);
extern int BTL_CLIENT_IsSickItemUsable(void *s, struct Unk021D62A8 *m);

u32 BTL_CLIENT_TakeTrainerItemToUse(u8 *a, void *b, void *c)
{
    u32 i;
    u32 r;
    u32 v;
    u32 lim;
    u32 off;
    u8 *t;

    lim = BTL_SLOT_GetCount(c);
    if (BTL_POKEPARAM_HasSick(b, 0x13) != 0)
        return 0;
    for (i = 0; i < 4; i++) {
        if (gBtlClientItemSlotLimits[i] < lim)
            break;
        off = i * 2;
        if (*(u16 *)(a + off + 0xe8) != 0) {
            r = 0;
            if (BTL_CALC_GetMonParamWithHeap((void *)(u32)*(u16 *)(a + off + 0xe8), 0x29) != 0) {
                r = func_021D59B4(b, 0xd);
                if (r > BTL_CALC_DivideMaxHp(b, 4))
                    continue;
                r = 1;
            } else {
                if (BTL_CLIENT_IsStatItemUsable((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
                else if (BTL_CLIENT_IsSickItemUsable((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
            }
            if (r != 0) {
                t = a + 0xe8;
                v = *(u16 *)(t + off);
                *(u16 *)(t + off) = 0;
                return v;
            }
        }
    }
    return 0;
}
