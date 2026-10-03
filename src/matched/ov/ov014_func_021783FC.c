/*
 * function: func_021783FC
 * address:  0x021783FC
 * packet:   pkt_ov014_021783FC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  ov014  a4
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_0203D5D4  0x0203D5D4  arm
 *   func_0209004C  0x0209004C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A8;
void func_0217814C(int error);
void func_02178138(int state);
u32 func_0203D6BC(void);
u32 func_0203D680(void);
u32 func_0203D5D4(void);
int func_0209004C(void *p, u32 a, u32 b, u16 c, u32 d);

void func_021783FC(u16 *a)
{
    u16 v1 = a[1];
    u16 mask;
    u32 id;
    u32 flag;
    u32 n;
    int r;
    if (v1 != 0) {
        func_0217814C(v1);
        func_02178138(9);
        return;
    }
    switch (a[2]) {
    case 10:
        if (*(int *)(g_021797A8 + 0x1E74) == 4) {
            id = func_0203D6BC();
            n = func_0203D680() - 1;
            mask = (1 << (n + 1)) - 1;
            flag = 1;
            if (func_0203D5D4() == 2)
                flag = 0;
            r = func_0209004C(g_021797A8 + 0x1444, 13, mask, id, flag);
            if (r != 0) {
                func_0217814C(r);
                func_02178138(9);
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 11:
    case 12:
    case 13:
        break;
    }
}
