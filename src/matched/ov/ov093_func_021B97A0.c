/*
 * function: func_021B97A0
 * address:  0x021B97A0
 * packet:   pkt_ov093_021B97A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B985C  0x021B985C  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201A948  0x0201A948  thumb
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6B84  0x021D6B84  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_0201A98C  0x0201A98C  thumb
 *   func_021D67D0  0x021D67D0  thumb  ov093
 *   func_0201AC2C  0x0201AC2C  thumb
 *   data_021EFCF0  0x021EFCF0  data  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern const u8 data_021EFCF0[4];

extern void *func_021B985C(char *p, int i);
extern char *func_021B9AEC(char *p, int i);
extern int func_0201AA18(void *l);
extern void func_0201A948(void *p);
extern void *func_021B9BF0(void *p, int i);
extern u8 func_021D5440(u8 *p);
extern void func_021D6B84(void *m, int k);
extern void *func_021D5844(void *m);
extern u32 func_0201A98C(void *l, void *v);
extern int func_021D67D0(void *m);
extern void func_0201AC2C(void *l, void *m);

void func_021B97A0(char *a, char *b, int k)
{
    void *list;
    char *g;
    u32 n;
    u32 t;
    u32 i;
    u32 j;
    void *m;

    list = func_021B985C(a, k);
    g = func_021B9AEC(a, k);
    n = func_0201AA18(list);
    func_0201A948(*(void **)(b + 0x2b8));
    t = data_021EFCF0[k];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m = func_021B9BF0(g, (u8)j);
            if (t + i == func_021D5440(m)) {
                func_021D6B84(m, 1);
                func_0201A98C(*(void **)(b + 0x2b8), func_021D5844(m));
                if (func_021D67D0(m) != 0)
                    *(u8 *)(*(char **)b + i + 0xc2) = 1;
                break;
            }
        }
    }
    func_0201AC2C(*(void **)(b + 0x2b8), list);
}
