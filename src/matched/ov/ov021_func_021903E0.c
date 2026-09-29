/*
 * function: func_021903E0
 * address:  0x021903E0
 * packet:   pkt_ov021_021903E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_021919C8  0x021919C8  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0219470C  0x0219470C  thumb  ov021
 *   func_02194760  0x02194760  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

typedef struct Obj {
    u32  f00;
    u32  f04;
    u32  f08;
    u32  f0c;
    Slot slot[4];
    u32  f0a0[8];
} Obj;

extern void func_0201C4E4(u32 a);
extern void func_021919C8(u32 a);
extern u32 func_02045770(u32 a);
extern int func_0201C6C4(u32 a, u32 b);
extern void func_02045334(u32 a);
extern void func_020310C4(u32 a);
extern void func_0219470C(u32 a);
extern void func_02194760(u32 a);

void func_021903E0(Obj *o)
{
    int i;
    u32 *w;
    Slot *s;
    int j;
    u32 t;

    func_0201C4E4(o->f0c);
    i = 0;
    w = o->f0a0;
    for (; i < 8; i++, w++) {
        if (*w != 0) {
            func_021919C8(*w);
        }
    }
    s = o->slot;
    for (j = 0; j < 4; j++, s++) {
        t = s->f0c;
        if (t != 0) {
            if (s->f20 != 0) {
                if (func_0201C6C4(t, func_02045770(s->f1c)) == 0) {
                    func_02045334(s->f1c);
                    s->f20 = 0;
                }
            }
            s->f04 = (s->f20 == 0) ? 1 : 0;
        }
    }
    func_020310C4(((u32 *)o)[0x59]);
    if (((u32 *)o)[0x57] != 0) {
        func_0219470C(((u32 *)o)[0x57]);
        func_02194760(((u32 *)o)[0x57]);
    }
}
