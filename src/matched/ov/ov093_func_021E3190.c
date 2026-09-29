/*
 * unit:     yes
 * function: func_021E3190, func_021E3240
 * address:  0x021E3190
 * packet:   pkt_ov093_021E3190
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
 *   data_021F271C  0x021F271C  data   a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C824C(void *p, int key);
extern void *func_021C7CF4(void *p, int key);
extern int func_021D5B40(void *p);
extern void func_021D76BC(int key, int v);
extern u8 data_021F271C[];

void func_021E3190(int u, void *p, int key)
{
    int two = 2;
    if (key == func_021D775C(two)) {
        if (func_021C824C(p, key) != 0) {
            u16 x = (u16)func_021D5B40(func_021C7CF4(p, key));
            int v = 0;
            switch (x) {
            case 0x12a: v = 9; break;
            case 0x12b: v = 10; break;
            case 0x12c: v = 12; break;
            case 0x12d: v = 11; break;
            case 0x12e: v = 14; break;
            case 0x12f: v = 1; break;
            case 0x130: v = 3; break;
            case 0x131: v = 4; break;
            case 0x132: v = two; break;
            case 0x133: v = 13; break;
            case 0x134: v = 6; break;
            case 0x135: v = 5; break;
            case 0x136: v = 7; break;
            case 0x137: v = 15; break;
            case 0x138: v = 16; break;
            case 0x139: v = 8; break;
            }
            func_021D76BC(0x16, v);
        }
    }
}

u8 *func_021E3240(u32 *out)
{
    *out = 1;
    return data_021F271C;
}
