/*
 * function: func_021B7F00
 * address: 0x021B7F00
 * packet: pkt_ov133_021B7F00
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA25C 0x021BA25C thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_021BA184(char *p);
extern int func_021BA25C(u8 *, int, int);
extern u32 *func_021BA228(u8 *);
extern u32 func_021BA208(u8 *p);
extern void func_020061E4(u32);
int func_021B7F00(u8 *p, void *q, u32 a)
{
    u8 *e = func_021BA184(q);
    u32 *v;
    while (e) {
        if (func_021BA25C(e, *(int *)(p + 0x1c), *(int *)(p + 0x20)) == 1) {
            v = func_021BA228(e);
            *(u32 *)(p + 0x3c) = 2;
            *(u8 **)(p + 0x38) = e;
            func_020061E4(0x623);
            *(u32 *)(p + 0x40) = a;
            *(u32 *)(p + 0x44) = v[0];
            *(u32 *)(p + 0x48) = v[1];
            return 1;
        }
        e = (u8 *)func_021BA208(e);
    }
    return 0;
}
