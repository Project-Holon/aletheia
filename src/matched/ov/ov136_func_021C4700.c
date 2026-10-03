/*
 * function: func_021C4700
 * address: 0x021C4700
 * packet: pkt_ov136_021C4700
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202822C 0x0202822C thumb
 *   func_02035C08 0x02035C08 arm
 *   func_021C446C 0x021C446C thumb ov136
 *   d_021C7784 0x021C7784 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02035C08(void *);
typedef unsigned int   u32;
struct Obj;
extern void func_020061E4(u32 a);
extern int func_021C446C(void *a);
extern void func_0202822C(char *p, int v);
extern void func_02028218(struct Obj *obj, u32 a);
extern u8 d_021C7784[];
int func_021C4700(u8 *p)
{
    int n;
    n = func_02035C08(d_021C7784);
    if (n == -1) return 0;
    if (n == 4) {
        func_020061E4(0x551);
        p[0xB] = 3;
        return 0;
    }
    if (n < 4) {
        (*(u8 **)(p + 0x1C))[2] = n;
        *(u16 *)*(u8 **)(p + 0x1C) = (*(u8 **)(p + 0x1C))[2];
        (*(u8 **)(p + 0x1C))[3] = p[0x17];
        func_020061E4(0x54D);
        return 1;
    }
    if (func_021C446C(p)) {
        func_020061E4(0x551);
        p[0xB] = 2;
        return 0;
    }
    *(u16 *)*(u8 **)(p + 0x1C) = 4;
    func_020061E4(0x54E);
    (*(u8 **)(p + 0x1C))[2] = 0;
    (*(u8 **)(p + 0x1C))[3] = 0;
    func_0202822C(*(void **)(p + 0x128), 1);
    func_02028218(*(void **)(p + 0x12C), 0);
    return 1;
}
