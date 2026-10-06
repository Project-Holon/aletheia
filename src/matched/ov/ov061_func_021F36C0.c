/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov061_021F36C0
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021F388C  0x021F388C  thumb  ov061
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   d_021F3974     0x021F3974  data  a4
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021F3974[];

extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE760(void *a, void *b, int c);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern int func_021BE480(char *p, unsigned i, int j);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021F388C(int *o, int a);
extern u16 func_02188C9C(u8 *p);

void func_021F36C0(void *a)
{
    u16 w;
    void *s;
    int *o;
    int i;
    u8 *e;

    w = func_02188C84(a);
    s = (void *)func_02188D2C(a);
    o = func_02189764(a, 0, w, 0xc);
    func_021BE760(s, d_021F3974, 0);
    for (i = 0; i < 9; i++) {
        func_021BE4B4(s, 0, (u16)i, 1);
    }
    o[1] = (int)func_021BE480(s, 0, 0);
    e = func_021BE674(s, 0, 0, 0);
    func_021BE700(s, 0, 0, 0, 1);
    func_021BE6B0(e, 1);
    func_021BE6B8(e, 0);
    func_021F388C(o, (int)a);
    o[2] = func_02188C9C(a);
}
