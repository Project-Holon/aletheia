/*
 * function: func_021CA570
 * address:  0x021CA570
 * packet:   pkt_ov093_021CA570
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CA5BC  0x021CA5BC  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021CA5BC(u8 *p, int k);
extern int func_021B9934(void *p, int i);
extern int func_021D6C24(int m);
extern void func_021D6C2C(int m);
extern void func_021CD4B0(void *w, u32 id, ...);
extern int func_021C99A0(u8 *p, u8 *q);

int func_021CA570(u8 *p, u8 *q)
{
    int m;
    if (func_021CA5BC(p + 0x1AB8, q[4])) {
        m = func_021B9934(*(void **)(p + 8), q[4]);
        if (func_021D6C24(m)) {
            func_021D6C2C(m);
            func_021CD4B0(*(void **)(p + 0xc), 0x4b, q[4]);
            func_021C99A0(p, q + 8);
            return 1;
        }
    }
    return 0;
}
