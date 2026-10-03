/*
 * function: func_021EDC28
 * address:  0x021EDC28
 * packet:   pkt_ov093_021EDC28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     a1 is a narrow (u8/u16, both give EXACT*) parameter: it pins the
 *           spill store to the front of the prologue; flag is int, cast (u8)
 *           at the bitfield store.
 *
 * symbols:
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021EDF4C  0x021EDF4C  thumb  ov093
 *   func_021EDE54  0x021EDE54  thumb  ov093
 *   func_021F8AE8  0x021F8AE8  thumb  ov094
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct W {
    char *f00;
    u8 pad04[4];
    u16 f08;
    u8 pad0a[2];
    u8 f0c;
    u8 f0d;
    u8 pad0e[0x14];
    u8 f22_0 : 1;
    u8 f22_1 : 1;
};

extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern void func_021EDF4C(struct W *w);
extern void func_021EDE54(struct W *w);
extern void func_021F8AE8(int a, u32 b);

void func_021EDC28(struct W *w, u8 a1, int flag)
{
    u8 *t;
    u16 h;
    u8 k;

    t = func_021B98AC(*(char *const **)(w->f00 + 0x138), a1);
    h = func_021D59B4(t, 0x10);
    k = func_021D5440(t);
    if (w->f22_0) {
        if (k == w->f0c) {
            return;
        }
        func_021EDF4C(w);
    }
    if (h != w->f08 || k != w->f0c) {
        w->f08 = h;
        w->f0c = k;
        func_021EDE54(w);
    }
    w->f22_1 = (u8)flag;
    w->f0d = 0;
    func_021F8AE8(a1, h);
}
