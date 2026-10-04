/*
 * function: func_021C21B4
 * address:  0x021C21B4
 * packet:   pkt_ov021_021C21B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021C24A8  0x021C24A8  thumb  ov021
 *   func_021C1AB4  0x021C1AB4  thumb  ov021
 */

typedef unsigned short u16;

void func_021C24A8(char *p, int k);
typedef unsigned int   u32;
int func_021C1AB4(u32 *p);

int func_021C21B4(char *p)
{
    if (*(u16 *)(p + 0x64) == 0) {
        if (*(int *)(p + 0x78) == 0) {
            if (*(u16 *)(p + 0x5c) != 0) {
                (*(u16 *)(p + 0x5c))--;
            } else {
                func_021C24A8(p, 0);
                *(int *)(p + 0x78) = 1;
            }
        }
        if (*(int *)(p + 0x7c) == 0) {
            if (*(u16 *)(p + 0x5e) != 0) {
                (*(u16 *)(p + 0x5e))--;
            } else {
                func_021C24A8(p, 1);
                *(int *)(p + 0x7c) = 1;
            }
        }
        if (*(int *)(p + 0x78) != 0 && *(int *)(p + 0x7c) != 0)
            *(u16 *)(p + 0x64) = 1;
    } else if (func_021C1AB4((u32 *)(*(int *)p)) != 0) {
        return 1;
    }
    return 0;
}
