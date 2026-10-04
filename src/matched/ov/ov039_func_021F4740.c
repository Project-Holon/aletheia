/*
 * function: func_021F4740
 * address:  0x021F4740
 * packet:   pkt_ov039_021F4740
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4740  0x021F4740  thumb
 *   func_021F4894  0x021F4894  thumb
 *   func_021F47D8  0x021F47D8  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

struct Big;
struct Ctx;
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u8 *func_0200B3A4(u32 a, u32 b);
extern int func_021F4894(void *a, u8 b, u8 c);
extern void func_021F47D8(void *a, int f, int i);

void func_021F4740(u32 a, void *b)
{
    s8 *p;
    u8 *q;
    u8 *arr;
    u8 v;
    s8 i;

    p = (s8 *)func_021897BC((char *)a, 1);
    q = func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 2);
    i = p[5];
    if (i == -1) {
        return;
    }
    arr = q + 0x10;
    v = arr[i];
    arr[i] = (v + 1) % 2;
    if (func_021F4894(b, i, *((u8 *)p + p[5] + 0x21EC)) != 0) {
        func_021F47D8(b, v, (u8)p[5]);
        i = p[5];
        *((u8 *)p + i + 0x21EC) = i * 2 + *(u8 *)(q + i + 0x10);
    } else {
        u8 *r = (u8 *)p + 0x21E8;

        i = p[5];
        if (r[i] != 0) {
            r[i] = 0;
        } else {
            r[i] = 1;
        }
    }
}
