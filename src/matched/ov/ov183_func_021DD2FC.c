/*
 * function: func_021DD2FC
 * address: 0x021DD2FC
 * packet: pkt_ov183_021DD2FC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 */
extern void func_021FD860(int obj, int one, int *args);
extern void func_020061E4(int code);
int func_021DD2FC(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(*(int *)(p + 0x10), 1, args);
        func_020061E4(0x703);
    }
    return ok;
}
