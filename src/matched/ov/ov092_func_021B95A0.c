/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_ov092_021B95A0
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02031324  0x02031324  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct W {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x20];
    u32 f2c;
    u32 f30;
    u32 f34;
    u8 pad38[4];
    u16 f3c;
    u8 pad3e[2];
    u32 f40;
    u32 f44;
    u32 f48;
};

extern void func_0203064C(u32 src, u32 dst, u32 size);
extern struct W *func_0203159C(int, int, int);
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_02031324(u32);

int func_021B95A0(int a0)
{
    struct W *p;

    func_0203064C(1, 0x52, 0x1000);
    p = func_0203159C(a0, 0x4c, 0x52);
    p->f04 = (u32)func_020457B0(0x20, 0x52);
    p->f00 = 0;
    p->f08 = 0;
    p->f2c = 0;
    p->f30 = 0;
    p->f34 = 0;
    p->f3c = 0x52;
    p->f40 = func_02031324(p->f3c);
    p->f44 = 0;
    p->f48 = 0;
    return 1;
}
