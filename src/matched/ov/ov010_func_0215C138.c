/*
 * function: func_0215C138
 * address: 0x0215C138
 * packet: pkt_ov010_0215C138
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: selector remains live in r2 and is func_0215B4DC's third argument.
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215B4DC 0x0215B4DC thumb ov010
 *   d_02171182 0x02171182 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 *func_02159AE8(void *c, void *vm);
extern u32 func_02159B10(void *c, void *vm);
extern int func_0215B4DC(void *vm, u32 v, u32 selector);
extern const u8 d_02171182[];
int func_0215C138(void *c, void *vm)
{
    u16 *dst;
    u32 arg;
    u32 sel;
    u32 i;
    dst = func_02159AE8(c, vm);
    arg = func_02159B10(c, vm);
    sel = func_02159B10(c, vm);
    for (i = 0; i < 12; i++) {
        if (sel == d_02171182[i]) {
            *dst = func_0215B4DC(vm, arg, sel);
            return 0;
        }
    }
    *dst = 0;
    return 0;
}
