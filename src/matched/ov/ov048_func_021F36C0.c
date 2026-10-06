/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov048_021F36C0
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_021F3880  0x021F3880  thumb  ov048
 *   func_021F392C  0x021F392C  thumb  ov048
 *   func_021F3BC0  0x021F3BC0  thumb  ov048
 *   func_021F37FC  0x021F37FC  thumb  ov048
 *   func_021F3908  0x021F3908  thumb  ov048
 *   func_021F3818  0x021F3818  thumb  ov048
 *   func_021F3830  0x021F3830  thumb  ov048
 *   func_021F3D78  0x021F3D78  thumb  ov048
 *   func_021F3870  0x021F3870  thumb  ov048
 *   func_021F39E4  0x021F39E4  thumb  ov048
 *   func_021F39BC  0x021F39BC  thumb  ov048
 *   d_021F4E94     0x021F4E94  data  a4
 */

typedef unsigned char u8;

extern u8 d_021F4E94[];

struct Big;
struct Ctx;
struct Sub02008700Obj;
extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void func_021BE760(int a, void *b, int c);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4(unsigned short *p);
struct Obj;
extern struct Obj *func_021F3880(int a);
extern void func_021F392C(struct Obj *o);
extern void func_021F3BC0(u8 *p);
extern void func_021F37FC(int *p);
extern void func_021F3908(int *p);
extern void func_021F3818(int *p);
extern void func_021F3830(int *p);
extern void func_021F3D78(void *p);
extern void func_021F3870(int *p);
extern void func_021F39E4(int *p);
extern void func_021F39BC(int *p);

void func_021F36C0(int a)
{
    int r6;
    int r4;
    int *p;
    int v;

    r6 = func_02188D2C((int *)a);
    v = func_020083E4((short unsigned int *)func_0200873C(func_02012EBC(func_020120F4(func_02188C80((void *)a)))));
    if (v != 0) {
        if (v == 1) {
            r4 = 0;
        }
    } else {
        r4 = 1;
    }
    func_021BE760(r6, d_021F4E94 + r4 * 16, 1);
    p = (int *)func_021F3880(a);
    func_021F392C((struct Obj *)p);
    func_021F3BC0((u8 *)p);
    func_021F37FC(p);
    if (p[4] == 0) {
        func_021F3908(p);
    } else {
        func_021F3818(p);
        func_021F3830(p);
    }
    func_021F3D78(p);
    func_021F3870(p);
    func_021F39E4(p);
    func_021F39BC(p);
}
