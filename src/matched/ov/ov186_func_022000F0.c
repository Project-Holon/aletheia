/*
 * packet: pkt_ov186_022000F0
 * function: func_022000F0
 * address: 0x022000F0
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_02035D20 0x02035D20 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   d_02200CD0 0x02200CD0 data a1
 */
extern int func_02035C08(const void *);
extern void func_02035D20(int *, int *);
extern void func_021FD860(int, int, int *);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern const char d_02200CD0[];
int func_022000F0(char *p)
{
    int x, y, args[2];
    int index = func_02035C08(d_02200CD0);
    if (index != -1) {
        if (*(unsigned char *)(p + index + 0x14)) {
            func_02035D20(&x, &y);
            args[0] = x;
            args[1] = y;
            func_021FD860(*(int *)(p + 0x78), 1, args);
            func_020061E4(0x703);
            return index;
        }
        func_020061E4(0x704);
    }
    return 9;
}
