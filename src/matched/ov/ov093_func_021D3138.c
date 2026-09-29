/*
 * function: func_021D3138
 * address:  0x021D3138
 * packet:   pkt_ov093_021D3138
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F7D44  0x021F7D44  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EA614  0x021EA614  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021F7D44(int a, u16 b);
extern int func_021F7EB4(void);
extern void func_021EAF18(u8 *a, int b, int c);
extern void func_021EA614(u32 a, u8 *b);
extern int func_021EA710(u32 a);

int func_021D3138(u32 *a, int *b, u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7D44(func_021B8E70((u8 *)a[0], (u8)c[0]), (u16)c[1]);
        (*b)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EAF18((u8 *)a + 0x58, 1, 0x43);
            func_021EA614(a[0x15], (u8 *)a + 0x58);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710(a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
