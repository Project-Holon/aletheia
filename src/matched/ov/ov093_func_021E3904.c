/*
 * function: func_021E3904
 * address:  0x021E3904
 * packet:   pkt_ov093_021E3904
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   data_021F2878  0x021F2878  data   a1
 *   data_021F2879  0x021F2879  data   a1
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u32 func_021D78AC(u32 range);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, u16 b);
extern void func_021C88C8(void *a, void *b);
extern u8 data_021F2878[];
extern u8 data_021F2879[];

void func_021E3904(int u, void *p, int key, int *o)
{
    u8 i;
    u8 v;
    u8 *q;
    if (key == func_021D775C(2)) {
        v = func_021D78AC(100);
        for (i = 0; i < 7; i++) {
            if (v < data_021F2878[i * 2])
                break;
        }
        *o = data_021F2879[i * 2];
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 1, i + 0x68);
        func_021C88C8(p, q);
    }
}
