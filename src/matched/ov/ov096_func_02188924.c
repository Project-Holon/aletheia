/*
 * function: func_02188924
 * address:  0x02188924
 * packet:   pkt_ov096_02188924
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
typedef struct Slot { u32 a : 3; u32 rest : 29; } Slot;
extern Slot BTL_POKEPARAM_GetSickContRaw(void *, int);
extern int BTLV_CORE_IsSlotKind1Index15(Slot);

int func_02188924(struct Cursor *a, int b, int c)
{
    int t1;
    int t3;
    u8 *r;
    u8 k;
    int x;
    Slot s;

    t1 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    k = func_0218A160((u8 *)b, t1);
    r = func_0218A2FC((u8 *)b, k);
    x = 0;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)r, 5) != 0) {
        s = BTL_POKEPARAM_GetSickContRaw(r, 5);
        if (BTLV_CORE_IsSlotKind1Index15(s) != 0)
            x = 1;
    }
    return func_0218A0F4((u8 *)a, c, x, 1, t3);
}
