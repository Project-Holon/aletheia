/*
 * function: func_0217BCDC
 * address:  0x0217BCDC
 * packet:   pkt_ov018_0217BCDC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012114  0x02012114  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175598  0x02175598  thumb  ov011
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3220  0x021A3220  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021A322C  0x021A322C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 f : 3; u16 g : 13; } Fh;
typedef struct { u8 lo : 4; u8 b4 : 1; u8 hi : 3; } Fb;
typedef struct { int x, y, z; } Vec;

extern int func_020120F4(void *);
extern int func_02012114(void *);
extern int func_02012944(int);
extern int func_02008550(int);
extern int func_02012B58(int);
extern int func_02175598(u8 *, int);
extern void *func_0201210C(void *p);
extern void *func_02188CB4(unsigned char *p);
extern void func_021A3220(void *, u16);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D8C0(void *, Vec *);
extern void func_021A322C(void *);

void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag)
{
    int res;
    void *obj;
    int has;
    int x;
    int y = func_020120F4(a1);
    Vec v = { 0, 0, 0 };

    if (func_02012114(a1) == 0)
        return;
    x = func_02012944(func_020120F4(a1));
    has = func_02008550(x);
    if (p != 0) {
        if (id == 0xFFFF) {
            if (((Fh *)(p + 0x86))->f == func_02012B58(y))
                id = 0;
        }
        if (id == 0) {
            kind = has == 0 ? 3 : 4;
            flag = has;
        }
        if (*(u16 *)(p + 0x88) == id)
            return;
        *(u16 *)(p + 0x88) = id;
        ((Fb *)(p + 0x8A))->lo = kind;
        ((Fb *)(p + 0x8A))->b4 = flag;
        p[0x900] = 1;
        res = func_02175598(p + 0x70, x);
    } else {
        id = 0;
        res = 1;
        if (has)
            res = 4;
    }
    obj = func_02188CB4(func_0201210C(a1));
    func_021A3220(obj, res);
    func_0216D8C0(func_021A3074(obj), &v);
    if (id == 0)
        func_021A322C(obj);
}
