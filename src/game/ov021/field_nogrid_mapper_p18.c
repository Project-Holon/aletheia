/*
 * file:     field_nogrid_mapper_p18.c
 * unit:     yes
 * function: func_021BB504, func_021BB528
 * address:  0x021BB504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021BB778  0x021BB778  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9A7C     0x021D9A7C  data  a4
 */
struct Rec;
struct Tagged;
typedef struct {
    int pad0;
    void *a4[4];
    void *a14[4];
    void *a24[4];
} Obj;

typedef unsigned int u32;

typedef unsigned char  u8;

extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_021ABEA0(u32 a, u32 b);
extern int func_0216E1A4(int a0, int a1);
extern u32 func_021ABE14(u8 *p);
extern void func_021BB778(int n);
extern void func_021ABFA8(u32, void *, int, int, void *, int);
void func_021BB504(Obj *p);
void func_021BB528(u32 a, u32 b, u32 c, u32 d);
extern int d_021D9A7C;


void func_021BB504(Obj *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02047738(p->a24[i]);
        func_02047504(p->a14[i]);
        func_02046EFC(p->a4[i]);
    }
}


void func_021BB528(u32 a, u32 b, u32 c, u32 d)
{
    u32 s[7];

    s[0] = c;
    s[1] = d;
    s[2] = func_021ABEA0(a, 4);
    s[3] = b;
    func_0216E1A4(b, (int)(&s[4]));
    s[6] = func_021ABE14((u8 *)a);
    if (d == 1)
        func_021BB778(c);
    func_021ABFA8(a, &d_021D9A7C, 0, 0, s, 0);
}
