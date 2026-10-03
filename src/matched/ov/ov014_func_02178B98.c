/*
 * function: func_02178B98
 * address:  0x02178B98
 * packet:   pkt_ov014_02178B98
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02179498  0x02179498  thumb  ov014
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_0203D5D4  0x0203D5D4  arm
 *   func_0209004C  0x0209004C  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u8 *g_021797A8;
void func_02178138(int a);
void func_0217814C(int a);
int func_02179498(void);
u32 func_0203D6BC(void);
u32 func_0203D680(void);
u32 func_0203D5D4(void);
int func_0209004C(void *p, int a, u32 mask, u32 b, int c);

void func_02178B98(u8 *m)
{
    u32 v = *(u16 *)(m + 2);
    u32 mask;
    u32 who;
    int c;

    if (v != 0) {
        if (v == 0xF || v == 9 || v == 0xD)
            return;
        func_0217814C(v);
        func_02178138(9);
        return;
    }
    switch (*(u16 *)(m + 4)) {
    case 0xA:
        if (*(u32 *)(g_021797A8 + 0x1E74) == 5) {
            int r;
            int n;

            who = func_0203D6BC();
            n = func_0203D680() - 1;
            mask = (u16)((1 << (n + 1)) - 1);
            c = 1;
            if (func_0203D5D4() == 2)
                c = 0;
            r = func_0209004C(g_021797A8 + 0x1444, 0xD, mask, (u16)who, c);
            if (r != 0) {
                func_0217814C(r);
                func_02179498();
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 0xB:
    case 0xC:
    case 0xD:
        break;
    }
}
