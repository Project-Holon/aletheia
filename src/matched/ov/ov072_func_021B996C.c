/*
 * function: func_021B996C
 * address:  0x021B996C
 * packet:   pkt_ov072_021B996C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021B995C  0x021B995C  thumb  ov072
 *   func_021B99E8  0x021B99E8  thumb  ov072
 */

typedef signed int     s32;
typedef unsigned int   u32;
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
void func_021B995C(int *p, int x);
int func_021B99E8(int *a, int unused, char *p);

void func_021B996C(int a, int *b)
{
    switch (b[0]) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        b[0] = 1;
        break;
    case 1:
        if (func_0204E804() == 0) {
            b[0] = 2;
        }
        break;
    case 2:
        func_021B995C((int *)a, (int)func_021B99E8);
        break;
    }
}
