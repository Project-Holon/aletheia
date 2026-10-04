/*
 * function: func_021E4408
 * address:  0x021E4408
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E4408   0x021E4408  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D62C4   0x021D62C4  thumb ov093
 *   func_021D5B48   0x021D5B48  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *
 * Two-key gate on func_021D775C(2) / func_021D775C(0x22), then classify the
 * func_021C7CF4(b, c) record: the first matching predicate decides which
 * func_021D76BC(0x22, code) event fires, and only the fall-through case
 * looks at the 16-bit func_021D59B4(u, 0x11) result.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
struct Unk021D62A8;
int func_021D76BC(int key, u32 val);
void *func_021C7CF4(int *p, int i);
int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D5B48(u8 *p);
extern int func_021D59B4(u8 *p, int k);
void func_021E4408(void *a, int b, int c)
{
    u16 v;
    void *u;

    if (c != func_021D775C(2))
        return;
    if (func_021D775C(0x22) != 0)
        return;
    u = func_021C7CF4((int *)b, c);
    if (func_021D62C4(u, 2) != 0) {
        func_021D76BC(0x22, 0x1a);
        return;
    }
    if (func_021D62C4(u, 0xf) != 0) {
        func_021D76BC(0x22, 0xd);
        return;
    }
    if (func_021D5B48(u) != 0) {
        func_021D76BC(0x22, 0xe);
        return;
    }
    v = func_021D59B4(u, 0x11);
    if (v == 0xf || v == 0x48)
        func_021D76BC(0x22, 0xf);
}
