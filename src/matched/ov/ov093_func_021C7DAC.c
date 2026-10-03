/*
 * function: func_021C7DAC
 * address:  0x021C7DAC
 * packet:   pkt_ov093_021C7DAC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   func_021C64B4  0x021C64B4  thumb  ov093
 *   func_021C6E3C  0x021C6E3C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *func_021B9934(char *p, int i);
struct R4;
struct Out64B4;
extern int func_021D6C24(struct R4 *p);
extern u8 *func_021B937C(int a, char *b, u8 *c);
extern void func_021C64B4(u8 *p, int q, u8 *a, struct Out64B4 *out);
extern int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag);

int func_021C7DAC(u8 *p, int a, int b, int c)
{
    int buf[5];
    int r;
    u8 *x = func_021B9934(*(char **)(p + 8), a);
    u8 *y = func_021B9934(*(char **)(p + 8), b);
    *(int *)(p + 0x774) += 1;
    if (func_021D6C24((struct R4 *)y)) {
        y = func_021B937C(*(int *)(p + 4), *(char **)(p + 8), y);
    }
    func_021C64B4(p, c, x, (struct Out64B4 *)buf);
    r = func_021C6E3C(p, x, y, (u8 *)buf, 0);
    *(int *)(p + 0x774) -= 1;
    return r;
}
