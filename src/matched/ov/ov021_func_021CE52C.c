/*
 * function: func_021CE52C
 * address:  0x021CE52C
 * packet:   pkt_ov021_021CE52C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_021CEA50  0x021CEA50  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 h;
    u32 pad4;
    u8  state;
} Sub;

extern int func_02190EF0(u32 h);
extern void func_021CE9E4(u32 *p, int n);
extern u32 func_02188C54(u32 a);
extern u32 func_02190BE4(u32 a, u32 b);
extern int func_021CEA50(u32 *p);
extern u32 func_02190C78(u32 a);
extern int func_021909BC(u32 a);

int func_021CE52C(u32 *p)
{
    Sub *q;
    u32 r;

    q = (Sub *)((u8 *)p + 0x130);
    if (!func_02190EF0(p[5])) {
        return 0;
    }
    switch (q->state) {
    case 0:
        func_021CE9E4(p, 0xb);
        q->state++;
        break;
    case 1:
        q->h = func_02190BE4(func_02188C54(p[0]), 0);
        q->state++;
        break;
    case 2:
        if (!func_021CEA50(p)) {
            r = 1;
        } else {
            r = func_02190C78(q->h);
            if (r == 2) {
                break;
            }
        }
        func_021909BC(q->h);
        q->h = 0;
        q->state = 0;
        if (r == 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}
