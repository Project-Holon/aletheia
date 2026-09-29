/*
 * unit:     yes
 * function: func_021D9A68, func_021D9AD0
 * address:  0x021D9A68
 * packet:   pkt_ov093_021D9A68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F05A8     0x021F05A8  data   a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021D775C(int);
extern int func_021C8288(void *);
extern u8 *func_021C7CF4(void *a, int b);
extern int func_021D62A8(u8 *p);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F05A8[];

void func_021D9A68(int a, void *b, int c)
{
    u8 *p;

    if (c == func_021D775C(2) && func_021C8288(b) == 2) {
        if (func_021D62A8(func_021C7CF4(b, c))) {
            func_021C88B4(b, 2, c);
            p = func_021C88A4(b, 0xb, c);
            *(int *)(p + 4) = 0x24;
            p[8] = c;
            p[0x14] = 1;
            *(u32 *)p |= 0x2000000;
            func_021C88C8(b, p);
            func_021C88B4(b, 3, c);
        }
    }
}

int *func_021D9AD0(int *p)
{
    *p = 1;
    return d_021F05A8;
}
