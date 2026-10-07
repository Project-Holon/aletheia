/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3778, func_021F3828
 * address:  0x021F3778
 * region:   ov053
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_0218ECB4  0x0218ECB4  thumb  ov021
 *   func_0202B93C  0x0202B93C  thumb
 *   func_021F3A5C  0x021F3A5C  thumb  ov053
 *   func_021C4DE4  0x021C4DE4  thumb  ov021
 *   func_021F3A38  0x021F3A38  thumb  ov053
 *   func_021F3A7C  0x021F3A7C  thumb  ov053
 *   func_021F3A6C  0x021F3A6C  thumb  ov053
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021F3B40  0x021F3B40  thumb  ov053
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   func_021C4D7C  0x021C4D7C  thumb  ov021
 *   func_021C4DC0  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021F3978  0x021F3978  thumb  ov053
 *   func_021F39BC  0x021F39BC  thumb  ov053
 *   func_021F3B30  0x021F3B30  thumb  ov053
 */
struct Obj;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct O {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int w[5];
    char pad30[0x34];
    int f64;
    char f68[1];
} O;

typedef unsigned int   u32;

extern int *func_021897BC(char *p, int idx);
extern void *func_02188C58(void *p);
extern void func_0218ECE4(int, int *);
extern void func_0218ECB4(int, int *);
extern void func_0202B93C(int a, void *b, void *c);
extern int func_021F3A5C(char *p, int i);
extern int func_021C4DE4(int, int);
extern void func_021F3A38(char *a, int i);
extern void func_021F3A7C(char *p, int a);
extern void func_021F3A6C(int *);
extern int func_02188D2C(int *p);
extern void func_021BE580(int);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021F3B40(struct Obj *o, int h, u8 *a2);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern unsigned int func_02012134(unsigned int *p);
extern unsigned int func_0202B57C(void *obj);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_021BE480(char *p, unsigned i, int j);
extern void *func_021C4D14(int a, int b, int c, int d, int e);
extern int func_021C4D7C(int, int);
extern void func_021C4DC0(int, int, int, int);
extern u32 func_020307B0(void *p);
extern void func_021F3978(char *a);
extern void func_021F39BC(char *a);
extern void func_021F3B30(void *);
void func_021F3778(int a);
void func_021F3828(O *o, u32 q);


void func_021F3778(int a)
{
    int i;
    int h;
    int *p;
    int v1[3];
    int v2[3];

    i = 0;
    p = func_021897BC((char *)a, 0);
    h = (int)func_02188C58((void *)a);
    func_0218ECE4(h, v1);
    func_0218ECB4(h, v2);
    func_0202B93C(p[1], v1, v2);
    for (i = 0; i < 5; i++) {
        int *q = p + i;
        if (q[7] > 0) {
            if (--q[7] <= 0) {
                func_021F3A5C((char *)p, i);
                switch (i) {
                case 0:
                    p[8] = 1;
                    break;
                case 2:
                    p[10] = 1;
                    break;
                }
            }
        } else if (func_021C4DE4(q[2], 0x1000)) {
            func_021F3A38((char *)p, i);
        }
    }
    func_021F3A7C((char *)p, a);
    func_021F3A6C(p);
    func_021BE580(func_02188D2C((int *)a));
    func_021F3B40((struct Obj *)(p + 0x1a), h, (u8 *)func_02188CB4((struct Obj00020 *)a));
}


void func_021F3828(O *o, u32 q)
{
    int i;
    int a;
    int t8;
    int s0;
    int s1;
    int *p;
    int r;

    a = func_02188C84((u8 *)q);
    t8 = func_02188D2C((int *)q);
    i = 0;
    o->h0 = a;
    o->f64 = 0;
    o->f4 = func_0202B57C((void *)func_02012134((unsigned int *)func_02188C80((void *)q)));
    p = func_02048F60(0x94, 1, a);
    s0 = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 0), 8, p[0] << 12, p[1]);
    func_021C4DC0(s0, 0x94, 3, 10);
    o->f8 = s0;
    func_020307B0(p);
    r = func_021C4D7C(q, func_021BE480((char *)t8, 0, 1));
    func_021C4DC0(r, 0x94, 5, 10);
    o->fc = r;
    p = func_02048F60(0x94, 6, a);
    s1 = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 2), 9, p[0] << 12, p[1]);
    func_021C4DC0(s1, 0x94, 8, 10);
    o->f10 = s1;
    func_020307B0(p);
    r = func_021C4D7C(q, func_021BE480((char *)t8, 0, 3));
    func_021C4DC0(r, 0x94, 10, 10);
    o->f14 = r;
    p = func_02048F60(0x94, 12, a);
    r = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 4), 7, p[0] << 12, p[1]);
    func_021C4DC0(r, 0x94, 11, 10);
    o->f18 = r;
    func_020307B0(p);
    for (i = 0; i < 5; i++)
        o->w[i] = 0;
    func_021F3978((char *)o);
    func_021F39BC((char *)o);
    func_021F3B30(o->f68);
}
