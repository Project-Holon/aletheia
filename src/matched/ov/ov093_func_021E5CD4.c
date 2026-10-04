/*
 * function: func_021E5CD4
 * address:  0x021E5CD4
 * packet:   pkt_ov093_021E5CD4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021C824C  0x021C824C  thumb  ov093
 *   func_021E869C  0x021E869C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u32 func_021D5B40(void *p);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021C824C(u8 *p, int v);
extern int func_021E869C(void *p, int id);
extern int func_021D76BC(int key, u32 val);

void func_021E5CD4(u8 *p, void *a, int b)
{
    if (b != func_021D775C(2))
        return;
    {
        void *r = func_021C7CF4(a, b);
        u16 v = func_021D5B40(r);
        if (v == 0 || func_021D805C((void *)v, 10) == 0 || func_021C824C(a, b) == 0
            || func_021E869C(a, b) != 0)
            func_021D76BC(0x22, 0x1a);
    }
}
