/*
 * function: func_021B8F7C
 * address:  0x021B8F7C
 * packet:   pkt_ov093_021B8F7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B86C8  0x021B86C8  thumb  ov093
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B969C  0x021B969C  thumb  ov093
 *   func_021B985C  0x021B985C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B86C8(unsigned char **p);
extern int func_021B8B9C(u8 *p, u32 k);
extern void func_021B969C(char *a, char *b, int k, int flag);
extern int func_021B985C(char *p, int i);

int func_021B8F7C(u8 *p, u32 k)
{
    if (func_021B86C8((unsigned char **)p)) {
        k = (u8)((k + 2) & 3);
        if (func_021B8B9C(p, k)) {
            func_021B969C((char *)(p + 0xc8), (char *)p, k, 0);
            return func_021B985C((char *)(p + 0xc8), k);
        }
    }
    return 0;
}
