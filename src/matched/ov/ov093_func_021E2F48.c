/*
 * function: func_021E2F48
 * address:  0x021E2F48
 * packet:   pkt_ov093_021E2F48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C8288(u8 *p);
extern int func_021D76BC(int key, u32 val);
extern void func_021C83DC(void *p, int x);

void func_021E2F48(int u, void *p, int key)
{
    int two = 2;
    if (key == func_021D775C(two)) {
        int s = func_021C8288(p);
        u8 v = func_021D775C(0x16);
        int r = 0;
        switch (s) {
        case 1: v = 9; r = 1; break;
        case 2: v = 10; r = 4; break;
        case 4: v = 5; r = 3; break;
        case 3: v = 14; r = two; break;
        }
        func_021D76BC(0x16, v);
        func_021C83DC(p, r);
    }
}
