/*
 * function: func_02166CD0
 * address:  0x02166CD0
 * packet:   pkt_ov010_02166CD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009590  0x02009590  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 */

typedef unsigned int u32;

struct Big;
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012F08(int *p);
extern int func_02012944(void *a);
extern void *func_02012EBC(struct Big *p);
extern u32 func_02009470(void *sys);
extern u32 func_02009590(u32 a, int b, int c);
extern int func_020142E8(int a, u32 b);
extern int func_0216BF9C(int a, int b, int c);

int func_02166CD0(void *a, u32 msg)
{
    int r7 = func_0201296C(a);
    int r0 = (int)func_02012F08(a);
    int r6 = func_02012944(a);
    u32 t;
    int res;
    t = func_02009470(func_02012EBC(a));
    switch (msg) {
    case 0xF000:
        return func_0216BF9C(r0, 1, r6);
    case 0xF001:
        res = 0;
        if (func_02009590(t, r6, 0) >= 1)
            res = 1;
        return res;
    }
    return func_020142E8(r7, msg);
}
