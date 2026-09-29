/*
 * function: func_021C9934
 * address:  0x021C9934
 * packet:   pkt_ov021_021C9934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE58C     0x021DE58C  data  ov021
 *   func_02008550  0x02008550  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200D868  0x0200D868  thumb
 *   func_02012EE4  0x02012EE4  thumb
 *   func_021CA270  0x021CA270  thumb  ov021
 *   func_0200D85C  0x0200D85C  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_021CA238  0x021CA238  thumb  ov021
 *   func_0200D914  0x0200D914  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_021CA1E4  0x021CA1E4  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_021CBF38  0x021CBF38  thumb  ov021
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DB80  0x0200DB80  thumb
 *   func_021CA258  0x021CA258  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 magic;
    u32 heap;
    u8 f8;
    u8 kind;
    u8 fa;
    u8 fb;
    u16 lo : 5;
    u16 sel : 3;
    u16 hi : 8;
    u8 pad0e[0x1e - 0x0e];
    u8 f1e[4];
    u8 pad22[0x32 - 0x22];
    u16 f32[14];
    u8 pad4e[0x6c - 0x4e];
    void *sys;
    void *f70;
    void *f74;
    void *f78;
    u8 pad7c[0x2c8 - 0x7c];
    u8 big[3][0x120];
    u8 small[22][0x14];
} Obj;

extern const char d_021DE58C[];

extern void *func_020120F4(void *p);
extern void *func_02012944(void *p);
extern void *func_02012EBC(void *p);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_02008550(void *p);
extern void *func_020071CC(void *sys, unsigned int id);
extern void func_0200D868(void *p, u32 v);
extern void func_02012EE4(void *base, void *v);
extern int func_021CA270(int kind);
extern void func_0200D85C(void *p);
extern void func_0200DA14(void *p);
extern u32 func_0200DB44(void *p, u32 i);
extern u16 func_0200DAC4(void *p, u32 i);
extern void func_021CA238(Obj *p, u16 v);
extern void func_0200D914(void *p, u32 id, const void *src);
extern u32 func_0200D884(void *p, u32 id, void *out);
extern void func_021CA1E4(Obj *p);
extern u8 *func_020127A4(void *p);
extern void func_021CBF38(Obj *p, void *a, u16 b, u32 c, void *d, u16 e);
extern u16 func_0200DA54(void *p);
extern u16 func_0200DB80(void *p, u32 i);
extern void func_021CA258(Obj *p, u16 a, u16 b);

Obj *func_021C9934(void *arg, int mode, u8 kind)
{
    void *sys;
    void *save;
    void *res;
    Obj *p;
    int i;
    u32 base;
    u32 k;
    u16 v;
    u8 t;

    sys = func_020120F4(arg);
    save = func_02012944(sys);
    res = func_02012EBC(sys);
    p = func_02030734(4, 0x7EC, 1, d_021DE58C, 0x5f);
    p->heap = 4;
    p->magic = 0x12345678;
    p->sys = sys;
    p->fa = func_02008550(save);
    p->f70 = func_020071CC(res, 0x39);
    p->f74 = func_020071CC(res, 0x3a);
    p->f78 = func_020071CC(res, 0x3b);
    func_0200D868(p->f70, 0);
    func_02012EE4(sys, p);
    if (mode == 0) {
        p->kind = kind;
        p->f8 = func_021CA270(p->kind);
        for (i = 0; i < 4; i++)
            p->f1e[i] = 0xff;
        for (i = 0; i < 14; i++)
            p->f32[i] = 0xffff;
        func_0200D85C(p->f70);
        func_0200DA14(p->f70);
        if (func_0200DB44(p->f74, p->kind) == 1)
            func_021CA238(p, func_0200DAC4(p->f74, p->kind));
        t = p->kind;
        func_0200D914(p->f70, 0, &t);
    } else {
        p->kind = func_0200D884(p->f70, 0, 0);
        p->f8 = func_021CA270(p->kind);
        if (func_0200D884(p->f70, 10, 0) != 0)
            func_021CA1E4(p);
        func_0200D884(p->f70, 5, p->f1e);
        func_0200D884(p->f70, 8, p->f32);
        if (p->kind == 2 || p->kind == 7) {
            p->sel = (u8)func_0200D884(p->f70, 9, 0);
            func_0200D884(p->f70, 6, p->small[p->sel]);
            base = 0x12f;
            if (func_02008550(func_020127A4(sys) + 0x20) != 0)
                base -= 3;
            i = p->sel;
            func_021CBF38(p, p->big[i], base + i, func_0200D884(p->f70, 7, 0), p->small[i], p->heap);
        }
        k = p->kind;
        if (func_0200DB44(p->f74, k) == 1) {
            v = func_0200DA54(p->f70);
            func_021CA258(p, func_0200DB80(p->f74, k), v);
        }
    }
    return p;
}
