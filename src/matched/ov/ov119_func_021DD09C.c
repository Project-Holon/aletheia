/*
 * function: func_021DD09C
 * address: 0x021DD09C
 * packet: pkt_ov119_021DD09C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021E68F4 0x021E68F4 thumb ov119
 */
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void func_021E68F4(void *, int);
void func_021DD09C(char *p)
{
    if (func_020355C4()) {
        func_021E68F4(p, -1);
        return;
    }
    {
        int v = *(int *)(p + 0x10A0);
        if (v != -1)
            func_021E68F4(p, v);
    }
}
