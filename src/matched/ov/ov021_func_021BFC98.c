/*
 * function: func_021BFC98
 * address:  0x021BFC98
 * packet:   pkt_ov021_021BFC98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58 0x02188C58 thumb ov021
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_0218E138 0x0218E138 thumb ov021
 *   func_0218E13C 0x0218E13C thumb ov021
 *   func_0216D410 0x0216D410 thumb ov010
 *   func_0216D454 0x0216D454 thumb ov010
 *   func_0216D480 0x0216D480 thumb ov010
 *   func_021BE92C 0x021BE92C thumb ov021
 *   func_02012374 0x02012374 thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern void *func_02188C58(void *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
typedef unsigned short u16;
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(void *);
extern int func_0216D480(char *p);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);

int func_021BFC98(int a, int *s, int *q)
{
    int h = (int)func_02188C58((void *)q[1]);
    void *t;

    t = func_021A3074(func_02188CB4((struct Obj00020 *)q[1]));
    switch (s[0]) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        func_0216D410(t, 0x44);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)q[0], q[1], 0, 1, 1, 0, 0));
        s[0] = s[0] + 1;
        break;
    case 1:
        if (func_0216D454(t) == 1) {
            func_0216D480(t);
            s[0] = s[0] + 1;
        }
        break;
    case 2:
        func_0218E13C((u8 *)h, q[2]);
        s[0] = s[0] + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}
