/*
 * function: func_021BB200
 * address: 0x021BB200
 * packet: pkt_ov217_021BB200
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * symbols:
 *   func_021BB98C 0x021BB98C thumb ov217
 *   func_021BC280 0x021BC280 thumb ov217
 *   func_021BC2B8 0x021BC2B8 thumb ov217
 *   func_021BB990 0x021BB990 thumb ov217
 *   func_021BC200 0x021BC200 thumb ov217
 *   func_021BC30C 0x021BC30C thumb ov217
 *   func_021BC380 0x021BC380 thumb ov217
 *   func_021BC43C 0x021BC43C thumb ov217
 *   func_021BC168 0x021BC168 thumb ov217
 *   func_021BC014 0x021BC014 thumb ov217
 *   func_021BC274 0x021BC274 thumb ov217
 *   func_021BC250 0x021BC250 thumb ov217
 *   func_021BC264 0x021BC264 thumb ov217
 *   func_021BC06C 0x021BC06C thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BBA30 0x021BBA30 thumb ov217
 *   func_02035CB8 0x02035CB8 arm
 */
struct S { char pad0[0x34]; int f34; char pad38[0x14]; int f4c; };
extern int func_02035CB8(int *a, int *b);
typedef unsigned int   u32;
extern u32 func_021BB98C(void *p);
extern void func_021BC280(struct S *p);
extern void func_021BC2B8(void *p);
extern void func_021BB990(void *p);
extern int func_021BC200(void *p, int position);
extern void func_021BC30C(struct S *p, int v);
extern void func_021BC380(struct S *p);
extern void func_021BC43C(struct S *p);
extern void func_021BC168(unsigned int p);
extern void func_021BC014(struct S *p);
extern void func_021BC274(void *p);
extern void func_021BC250(void *p);
extern int func_021BC264(void *p);
extern void func_021BC06C(struct S *p);
extern void func_021BB91C(void *p);
extern void func_021BBA30(struct S *p);

void func_021BB200(struct S *p)
{
    int a;
    int b;
    int r = func_02035CB8(&a, &b);
    int m = func_021BB98C(p);
    switch (m) {
    case 0:
    {
        if (r == 0) {
            func_021BC280(p);
            func_021BC2B8(p);
            func_021BB990(p);
        } else {
            func_021BC30C(p, func_021BC200(p, b));
            func_021BC380(p);
            func_021BC43C(p);
            func_021BC168((unsigned int)p);
            func_021BC014(p);
            func_021BC274(p);
        }
        break;
    }
    case 1:
    {
        func_021BC30C(p, p->f34 + p->f4c);
        func_021BC380(p);
        func_021BC43C(p);
        func_021BC168((unsigned int)p);
        func_021BC014(p);
        func_021BC250(p);
        if (func_021BC264(p) == 0) {
            func_021BC06C(p);
            func_021BB91C(p);
        }
        break;
    }
    }
    func_021BBA30(p);
}
