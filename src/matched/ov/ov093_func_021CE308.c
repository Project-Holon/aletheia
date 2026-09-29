/*
 * function: func_021CE308
 * address:  0x021CE308
 * packet:   pkt_ov093_021CE308
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D0B10  0x021D0B10  thumb  ov093
 *   func_021CF41C  0x021CF41C  thumb  ov093
 *   func_021CF360  0x021CF360  thumb  ov093
 *   func_021D8434  0x021D8434  thumb  ov093
 *   func_021B990C  0x021B990C  thumb  ov093
 *   func_021CF470  0x021CF470  thumb  ov093
 *   func_021CE150  0x021CE150  thumb  ov093
 *   func_021CE4D0  0x021CE4D0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 a : 2; u8 f : 1; } Flags;

extern void func_021D0B10(u8 *p, u32 a, u32 b, u8 *c, u8 *d);
extern void func_021CF41C(u8 *p);
extern void func_021CF360(u8 *p);
extern void func_021D8434(u8 *o);
extern u32 func_021B990C(u32 a, u32 b, u8 i);
extern u32 func_021CF470(u8 *p, u32 q, u32 o);
extern void func_021CE150(u8 *p, u32 fn);
extern u32 func_021CE4D0(u8 *p);

u32 func_021CE308(u8 *p)
{
    u32 i = 0;
    u32 w;
    p[0x11d] = 0;
    ((s8 *)p)[0x11e] = -1;
    p[0x11f] = 0;
    ((Flags *)(p + 0x1b2))->f = 0;
    func_021D0B10(p, 0, p[0x11c], p + 0x184, p + 0x190);
    func_021CF41C(p);
    func_021CF360(p);
    for (i = 0; i < 3; i++) {
        func_021D8434(p + 0x124 + i * 4);
    }
    for (i = 0; i < p[0x11c]; i++) {
        w = func_021B990C(*(u32 *)(p + 4), p[0x1a6], i);
        if (func_021CF470(p, w, 0) == 0) {
            p[0x11f] = i;
            break;
        }
    }
    func_021CE150(p, (u32)func_021CE4D0);
    return 0;
}
