/*
 * function: func_021E31E8
 * address: 0x021E31E8
 * packet: pkt_ov183_021E31E8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 */
extern void func_021FD860(int obj, int one, int *args);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);

int func_021E31E8(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(*(int *)(p + 0x34), 1, args);
        func_020061E4(0x703);
    }
    return ok;
}
