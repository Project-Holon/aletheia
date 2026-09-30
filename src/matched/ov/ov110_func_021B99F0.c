/*
 * unit: yes
 * function: func_021B99F0, func_021B9A3C
 * address: 0x021B99F0
 * packet: pkt_ov110_021B99F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit if/else increments preserve the branch after the skip call.
 * symbols:
 *   d_021C1C88 0x021C1C88 data ov110 a4
 *   func_021B99E4 0x021B99E4 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *d_021C1C88[];
extern u8 *func_021B99E4(u8 *);
extern int func_02024810(u8 *);
u16 func_021B99F0(int unused, int id, int index) {
    u8 *p = d_021C1C88[id];
    int n = 0;
    while (*(u16 *)p != 65535) {
        if (n == index) {
            if (*(u16 *)p == 65534) p = func_021B99E4(p);
            return *(u16 *)p;
        }
        if (*(u16 *)p == 65534) {
            p = func_021B99E4(p);
            p += 2;
        } else {
            p += 2;
        }
        ++n;
    }
    return 0;
}
int func_021B9A3C(u8 *p) { return func_02024810(*(u8 **)(p+4)); }
