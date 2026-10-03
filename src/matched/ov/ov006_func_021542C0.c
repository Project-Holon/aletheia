/*
 * function: func_021542C0
 * address:  0x021542C0
 * packet:   pkt_ov006_021542C0
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0200AEE8  0x0200AEE8  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02013790  0x02013790  thumb
 *   func_020137C0  0x020137C0  thumb
 *   func_02013864  0x02013864  thumb
 *   func_02013894  0x02013894  thumb
 *   func_02013980  0x02013980  thumb
 *   func_02013160  0x02013160  thumb
 *   func_0201A2A8  0x0201A2A8  thumb
 *   func_02012F2C  0x02012F2C  thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32  func_020120F4(u32 a0);
extern void func_0200AEE8(u32 a0, int a1, int a2);
extern u32  func_020399A8(void);
typedef unsigned short u16;
extern void func_02013790(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_020137C0(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013864(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013894(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013980(u32 a0, int a1);
extern void func_02013160(u32 a0, u32 a1, int a2);
extern void func_0201A2A8(u32 a0, u32 a1);
extern u32  func_02012F2C(u32 a0);

typedef struct Sub {
    u32 f00[5];
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  pad20[0x28];
    u8  f48;
} Sub;

void func_021542C0(char *obj, int idx)
{
    u32 h;
    u8 flag;
    int v;

    h = func_020120F4(*(u32 *)(obj + 4));
    flag = (*(Sub **)(obj + 0x5c))->f48;
    if (flag)
        func_0200AEE8((*(Sub **)(obj + 0x5c))->f1c, 0xd, 1);
    else
        func_0200AEE8((*(Sub **)(obj + 0x5c))->f1c, 0xd, 0);

    switch (idx) {
    case 8:
        v = 1;
        if (flag)
            v = 3;
        break;
    case 7:
        v = 0;
        if (flag)
            v = 2;
        break;
    case 10:
        v = 5;
        if (flag)
            v = 7;
        break;
    case 9:
        v = 4;
        if (flag)
            v = 6;
        break;
    case 12:
        v = 9;
        if (flag)
            v = 0xb;
        break;
    case 11:
        v = 8;
        if (flag)
            v = 0xa;
        break;
    case 14:
        v = 0xd;
        if (flag)
            v = 0xf;
        break;
    case 13:
        v = 0xc;
        if (flag)
            v = 0xe;
        break;
    }
    *(int *)(obj + 0x144) = v;
    *(int *)(obj + 0x148) = 0;

    switch (idx) {
    case 7:
    case 8:
        func_02013790(*(u32 *)(obj + 0xdc), h, func_020399A8(), 1, 4);
        break;
    case 9:
    case 10:
        func_020137C0(*(u32 *)(obj + 0xdc), h, func_020399A8(), 1, 4);
        break;
    case 11:
    case 12:
        func_02013864(*(u32 *)(obj + 0xdc), h, func_020399A8(), 1, 4);
        break;
    case 13:
    case 14:
        func_02013894(*(u32 *)(obj + 0xdc), h, func_020399A8(), 1, 4);
        break;
    }
    func_02013980(*(u32 *)(obj + 0xdc), 1);
    func_02013160(*(u32 *)(obj + 0xdc), (*(Sub **)(obj + 0x5c))->f1c, 4);
    func_0201A2A8((*(Sub **)(obj + 0x5c))->f1c, (*(Sub **)(obj + 0x5c))->f14);
    func_0201A2A8((*(Sub **)(obj + 0x5c))->f1c, (*(Sub **)(obj + 0x5c))->f18);
    *(u32 *)(*(char **)(obj + 0xdc) + 0x6c) = func_02012F2C(func_020120F4(*(u32 *)(obj + 4)));
}
