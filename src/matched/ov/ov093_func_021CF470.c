/*
 * function: func_021CF470
 * address:  0x021CF470
 * packet:   pkt_ov093_021CF470
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D8434  0x021D8434  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D8444  0x021D8444  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D67C4  0x021D67C4  thumb  ov093
 *   func_021D82D0  0x021D82D0  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D5778  0x021D5778  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D5B68(void *q);
extern void func_021D8434(u8 *o);
struct QL;
struct Unk021D62A8;
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D8444(u8 *o);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
typedef struct { u32 v; } Word;
extern Word func_021D6314(void *q, int i);
extern u16 func_021E8B80(Word v);
extern u8 func_021D67C4(u8 *p);
extern void func_021D82D0(u8 *o, u32 id, u32 sub);
extern u16 func_021D67A8(struct QL *p);
extern u8 func_021D5778(void *q, u32 id);

u32 func_021CF470(u8 *p, void *q, u8 *o)
{
    u32 id;
    u32 a;
    u32 b;
    Word t;
    if (func_021D5B68(q) != 0) {
        if (o != 0) {
            func_021D8434(o);
        }
        return 1;
    }
    if (func_021D5BDC(q, 0xc) != 0) {
        if (o != 0) {
            func_021D8444(o);
        }
        return 1;
    }
    id = 0x19;
    if (func_021D62C4(q, id) != 0) {
        t = func_021D6314(q, id);
        id = func_021E8B80(t);
        b = func_021D67C4(q);
        if (o != 0) {
            func_021D82D0(o, id, b);
        }
        return 1;
    }
    if (func_021D62C4(q, 0x1a) != 0) {
        a = func_021D67A8(q);
        b = func_021D67C4(q);
        func_021D5778(q, a);
        if (o != 0) {
            func_021D82D0(o, a, b);
        }
        return 1;
    }
    return 0;
}
