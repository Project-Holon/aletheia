/*
 * unit:     yes
 * function: func_021E324C, func_021E32C0
 * address:  0x021E324C
 * packet:   pkt_ov093_021E324C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C824C  0x021C824C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   data_021F2A78  0x021F2A78  data   a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C824C(u8 *p, int v);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B40(void *p);
extern int func_021D76BC(int key, u32 val);
extern void func_021C83DC(void *p, int x);
extern u8 data_021F2A78[];

void func_021E324C(int u, void *p, int key)
{
    int two = 2;
    if (key == func_021D775C(two)) {
        if (func_021C824C(p, key) != 0) {
            u16 x = (u16)func_021D5B40(func_021C7CF4(p, key));
            int v = 0;
            int r = 0;
            switch (x) {
            case 0x74: v = 10; r = 1; break;
            case 0x75: v = 12; r = two; break;
            case 0x76: v = 9; r = 3; break;
            case 0x77: v = 14; r = 4; break;
            }
            func_021D76BC(0x16, v);
            func_021C83DC(p, r);
        }
    }
}

u8 *func_021E32C0(u32 *out)
{
    *out = 2;
    return data_021F2A78;
}
