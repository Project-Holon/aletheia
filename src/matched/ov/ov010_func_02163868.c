/*
 * function: func_02163868
 * address:  0x02163868
 * packet:   pkt_ov010_02163868
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 */

typedef unsigned char u8;

extern int func_0216DC34(void *a0);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_02163F40(int a, int dir);
extern void func_0216DC18();
extern u16 func_021AB0F8(u32 attr);

void func_02163868(int a, int q)
{
    u8 *t = *(u8 **)(q + 0x10);

    if (t[6] != 0 && func_0216DC34((void *)a) != 0) {
        int r = func_02163F40(a, 1);

        if (r == -1) {
            func_0216DC18(a, 0);
            return;
        }
        if ((func_021AB0F8(r) & 0x40) == 0) {
            func_0216DC18(a, 0);
        }
    }
}
