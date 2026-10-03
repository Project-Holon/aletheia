/*
 * function: func_021E231C
 * address:  0x021E231C
 * packet:   pkt_ov093_021E231C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
struct QQ;
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(int a, int k, int b);
extern void func_021C88C8(int a, void *b);
extern void func_021E03D8(u8 *a, int b);
extern u16 func_021D70A8(struct QQ *p);

void func_021E231C(void *u, int a, int b)
{
    void *q;
    u8 *r;

    if (b == func_021D775C(2)) {
        q = func_021C7CF4(a, b);
        if (func_021D62C4(q, 2) != 0) {
            r = func_021C88A4(a, 0xb, b);
            *(int *)(r + 4) = 0x19;
            r[0x14] = 1;
            r[8] = b;
            func_021C88C8(a, r);
            func_021E03D8(q, func_021D70A8(u));
        }
    }
}
