/*
 * function: func_021F3D78
 * address:  0x021F3D78
 * packet:   pkt_021F3D78
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F3A70  0x021F3A70  thumb
 *   func_021F3DF0  0x021F3DF0  thumb
 *   func_021F3D24  0x021F3D24  thumb
 *   func_021F3E2C  0x021F3E2C  thumb
 *   func_021F3DA8  0x021F3DA8  thumb
 */

typedef unsigned char  u8;
extern int func_021F3A70(u8 *p);
extern void func_021F3DF0(u8 *p);
extern int  func_021F3D24(void *p);
extern void func_021F3E2C(u8 *p);
extern void func_021F3DA8(u8 *p);

void func_021F3D78(void *p)
{
    if (func_021F3A70(p) == 1) {
        func_021F3DF0(p);
        return;
    }
    if (func_021F3D24(p) != 0) {
        func_021F3E2C(p);
        return;
    }
    func_021F3DA8(p);
}
