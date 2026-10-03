/*
 * function: func_021F45F0
 * address:  0x021F45F0
 * packet:   pkt_ov048_021F45F0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_021F44B8  0x021F44B8  thumb  ov048
 *   func_0215E404  0x0215E404  thumb  ov010
 *   func_0215E3E4  0x0215E3E4  thumb  ov010
 *   func_020111E8  0x020111E8  thumb
 */

extern int func_02012EBC(int a);
extern int func_0200D418(int sys);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021F44B8(u8 *p);
extern int func_0215E404(int a);
extern u32 func_020111E8(void);
extern int func_0215E3E4(int a, unsigned char b);

void func_021F45F0(int *a, void *b)
{
    int r7;
    int r4;
    int r6;
    int r0;

    r7 = func_0200D418(func_02012EBC(a[2]));
    func_021F44B8(b);
    if (func_0215E404(r7)) {
        r0 = func_020111E8();
        switch (r0) {
        case 0x14:
            r4 = 0;
            break;
        case 0x15:
            r4 = 1;
            break;
        }
        switch (r4) {
        case 0:
            r6 = 6;
            break;
        case 1:
            r6 = 7;
            break;
        }
        r0 = func_0215E3E4(r7, r4);
        if (r0 != 0xFFFF) {
            *(unsigned short *)b = r0;
            *((unsigned char *)b + 8) = r6;
        }
    }
}
