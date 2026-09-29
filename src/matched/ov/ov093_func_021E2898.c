/*
 * unit:     yes
 * function: func_021E2898, func_021E28FC
 * address:  0x021E2898
 * packet:   pkt_ov093_021E2898
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F2CA8     0x021F2CA8  data   ov093  a2
 *   d_021F2CAA     0x021F2CAA  data   ov093  a2
 *   d_021F249C     0x021F249C  data   ov093  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D59B4(void *p, int k);
extern int func_021D76BC(int key, u32 v);
extern u16 d_021F2CA8[];
extern u16 d_021F2CAA[];
extern int d_021F249C[];

void func_021E2898(int a, void *b, int c)
{
    void *m;
    int x;
    int y;
    u32 r;
    u32 i;

    if (c == func_021D775C(3)) {
        m = func_021C7CF4(b, c);
        x = func_021D59B4(m, 0xD);
        y = func_021D59B4(m, 0xE);
        r = x * 0x30 / y;
        if (r == 0)
            r = 1;
        for (i = 0; i < 5; i++) {
            if (r <= d_021F2CA8[i * 2])
                break;
        }
        func_021D76BC(0x30, d_021F2CAA[i * 2]);
    }
}

int *func_021E28FC(int *p)
{
    *p = 1;
    return d_021F249C;
}
