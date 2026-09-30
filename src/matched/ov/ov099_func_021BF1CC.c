/*
 * function: func_021BF1CC
 * address: 0x021BF1CC
 * packet: pkt_ov099_021BF1CC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind func_021C23B8 result before evaluating the outer call's
 *   byte argument; nesting caches that byte across the inner call.
 * symbols:
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021B9968 0x021B9968 thumb ov099
 *   func_021C2028 0x021C2028 thumb ov099
 *   func_021BE21C 0x021BE21C thumb ov099
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
extern int func_021BE2A8(char *, int);
extern char *func_021C23B8(int);
extern void *func_021B9968(char *, int, int);
extern void func_021C2028(char *, int, int);
extern void func_021BE21C(char *, void *);
extern void func_020061E4(int);
void func_021BF1CC(char *p)
{
    int changed = 0;
    int i;
    void *v;
    char *s;
    for (i = 0; i < 32; i++) {
        if (*(u8 *)(p + i + 0x10) && !func_021BE2A8(p, *(u8 *)(p + i + 0x10))) {
            s = func_021C23B8(*(u8 *)(p + i + 0x10) - 1);
            v = func_021B9968(p + 0x274, *(u8 *)(s + 0x14), *(u8 *)(p + i + 0x10));
            if (v) {
                func_021C2028(p, *(u8 *)(p + i + 0x10), 2);
                func_021BE21C(p, v);
                *(u8 *)(p + i + 0x50) = 0;
                *(u8 *)(p + i + 0x70) = 0;
                *(u8 *)(p + i + 0x90) = 0;
                changed = 1;
            }
        }
    }
    if (changed == 1) func_020061E4(0x676);
}
