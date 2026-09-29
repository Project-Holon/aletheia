/*
 * function: func_021D29CC
 * address:  0x021D29CC
 * packet:   pkt_ov093_021D29CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   d_021EFF88     0x021EFF88  data  ov093  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B9934(char *p, int i);
extern u32 func_021D5844(u32 *p);
extern int func_02017E1C(void *a, int b, int c);
extern void func_02017E40(void *a, int b, int c);
extern u16 d_021EFF88[];

int func_021D29CC(u32 *a, int b, u32 *c)
{
    void *m;
    u32 i;
    int k;
    u32 v;

    m = (void *)func_021D5844((u32 *)func_021B9934((char *)a[1], (u8)c[0]));
    for (i = 0; i < 6; i++) {
        if (d_021EFF88[i + 1] != 0) {
            k = d_021EFF88[i];
            v = c[i + 1] + func_02017E1C(m, k, 0);
            if (v > 0xff) {
                v = 0xff;
            }
            func_02017E40(m, k, v);
        }
    }
    return 1;
}
