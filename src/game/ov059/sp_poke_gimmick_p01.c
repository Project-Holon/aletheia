/*
 * file:     sp_poke_gimmick_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F376C
 * address:  0x021F36C0
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3E94  0x021F3E94  data  a4
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021BE418  0x021BE418  thumb  ov021
 */
typedef unsigned short u16;

typedef unsigned char  u8;

extern int func_02188D2C(int *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE760(int a, void *b, int c);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern int func_021BE674(int a, int b, int c, u16 d);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_021BE700(int a, int b, int c, u16 d, int e);
extern void func_021897A0(unsigned char *p, int id);
extern void func_021BE418(unsigned char *p, unsigned short i);
void func_021F36C0(int a);
void func_021F376C(unsigned char *p);
extern char d_021F3E94[];


void func_021F36C0(int a)
{
    int i;
    int r5;
    int z;
    int r7;

    r5 = func_02188D2C((int *)a);
    func_02189764((unsigned char *)a, 1, func_02188C84((u8 *)a), 0x28);
    func_021BE760(r5, d_021F3E94, 0);
    i = 0;
    func_021BE4B4((char *)r5, 0, 1, 1);
    func_021BE4B4((char *)r5, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        z = 0;
        r7 = func_021BE674(r5, z, z, i);
        func_021BE6B8((unsigned char *)r7, z);
        func_021BE6B0((unsigned char *)r7, 1);
        func_021BE700(r5, z, z, i, z);
        r7 = func_021BE674(r5, z, 1, i);
        func_021BE6B8((unsigned char *)r7, z);
        func_021BE6B0((unsigned char *)r7, 1);
        func_021BE700(r5, z, 1, i, z);
    }
}


void func_021F376C(unsigned char *p)
{
    void *s;
    s = (void *)func_02188D2C((int *)p);
    func_021897A0(p, 1);
    func_021BE418(s, 0);
}
