/*
 * function: func_021E6BAC
 * address:  0x021E6BAC
 * packet:   pkt_ov093_021E6BAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern int func_021D76BC(int key, u32 val);

void func_021E6BAC(int x, int a, int c)
{
    void *p;
    u16 id;

    if (c == func_021D775C(2)) {
        p = (void *)func_021D775C(0x3f);
        id = func_021D775C(0x12);
        func_021C8838(p, 1, 0x79);
        func_021C8860(p, id);
        func_021D76BC(0x51, 1);
    }
}
