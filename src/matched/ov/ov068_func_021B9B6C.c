/*
 * function: func_021B9B6C
 * address:  0x021B9B6C
 * packet:   pkt_ov068_021B9B6C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021BB614     0x021BB614  data  ov068  a4
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 a);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *p, u32 a, u32 b);
extern u32 d_021BB614[][10];

void func_021B9B6C(u32 *p)
{
    int i;

    for (i = 0; i < 19; i++) {
        if (p[i] != 0) {
            func_020452E8((struct Descriptor *)p[i]);
        }
    }
    func_020307B0((void *)p[21]);
    func_02040DA8(4, 1, 0);
    i = 0;
    func_02040DA8(3, 1, 0);
    for (i = 0; i < 6; i++) {
        func_020403F4((u8)d_021BB614[i][0]);
    }
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 0x7c);
}
