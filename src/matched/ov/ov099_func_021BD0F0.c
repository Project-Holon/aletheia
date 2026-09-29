/*
 * function: func_021BD0F0
 * address:  0x021BD0F0
 * packet:   pkt_ov099_021BD0F0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_021BCBBC  0x021BCBBC  thumb  ov099
 *   func_02012934  0x02012934  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int func_0203D378(void);
extern int func_021BCBBC(int a, int b, int *out);
extern void *func_02012934(u32 a);
extern void func_0201AC2C(void *l, void *m);
extern void func_021BAAB8(char *p, int a, int b);

int func_021BD0F0(char *p, int v)
{
    int t;
    int out;

    t = 0;
    if (func_0203D378() == 0) {
        t = 1;
    }
    if (func_021BCBBC(*(int *)(p + 0x1348), *(int *)(p + 0xCC), &out) != 0
        && *(int *)(p + 0xCC) == 0) {
        func_0201AC2C(func_02012934(*(u32 *)(p + 0xC4)),
                      *(void **)(*(char **)(p + 0x248) + t * 4 + 0x14));
        *(u32 *)(p + 0x1CC) = 0x67;
    } else {
        func_021BAAB8(p, 0x71, 0);
        *(u32 *)(p + 0x1CC) = 0x65;
    }
    return v;
}
