/*
 * function: func_0217E714
 * address:  0x0217E714
 * packet:   pkt_ov018_0217E714
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02026608  0x02026608  thumb
 *   func_021585BC  0x021585BC  thumb  ov010
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_021762C0  0x021762C0  thumb  ov011
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021D3554  0x021D3554  thumb  ov021
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_0217EC08  0x0217EC08  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    unsigned int id : 10;
    unsigned int id2 : 10;
    unsigned int rest : 12;
    u8 pad04[0x0A - 0x04];
    u8 x;
    u8 y;
} Mon;

typedef struct {
    Mon *mon;
    u16 id;
    u16 pad06;
} Slot;

typedef struct {
    u8 pad00[4];
    unsigned int a : 4;
    unsigned int b : 3;
    unsigned int c : 11;
    unsigned int d : 14;
    u8 pad08[0x18 - 0x08];
    u8 f18[0x28 - 0x18];
    u8 f28;
} Sel;

typedef struct {
    u32 f00;
    u8 pad04[0x1C - 0x04];
    int f1C;
    u8 pad20[0x24 - 0x20];
    void *f24;
    int f28;
    void *f2C;
    void *f30;
    u8 pad34[0x38 - 0x34];
    void *f38;
    void *f3C;
    u8 pad40[0x4C - 0x40];
    void *f4C;
    u8 f50;
    u8 pad51[0xD8 - 0x51];
    u8 fD8;
    u8 padD9[0xDC - 0xD9];
    int fDC;
    u8 padE0[0xE4 - 0xE0];
    Sel *fE4;
    u8 fE8;
    u8 fE9;
    u8 fEA;
    u8 padEB[0xEC - 0xEB];
    Slot slots[3];
    u8 pad104[0x108 - 0x104];
    s16 f108;
    u8 pad10A[0x10D - 0x10A];
    u8 f10D;
    u8 f10E;
    u8 pad10F[0x169 - 0x10F];
    u8 f169;
} W;

typedef struct { unsigned short a : 9; unsigned short b : 6; unsigned short c : 1; } Fld;

typedef struct { int x; int y; int z; } Vec3;

typedef struct {
    u32 ptr[2];
    u8 slot[2];
    u8 par[2];
    u16 msg;
} Buf;

struct Ctx;
struct Descriptor;
struct CharBuf;
struct WordSet;
struct MsgBank;
u32 func_02012138(const struct Ctx *p);
void *func_020120F4(const struct Ctx *p);
struct BigObj;
struct VecFx32;
u8 func_02012B58(const struct BigObj *p);
struct BigObj;
int func_02012B70(const struct BigObj *p);
void *func_0201210C(const struct Ctx *p);
u32 func_02013D5C(u32 id);
u32 func_02013D9C(u32 id);
int func_0203D1B4(void);
void *func_02045770(struct Descriptor *a0);
void func_02043B5C(struct CharBuf *buf, u8 value);
void func_02045334(struct Descriptor *a0);
void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
void func_0201EE0C(struct WordSet *p, u32 i, void *src, u32 n, u32 f, u32 g);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_0201C724(int a0, int a1, int a2, int a3, void *a4, int a5, int a6);
int func_02026608(u8 *p, u8 *out);
int func_021585BC(u8 *p);
int func_021583EC(void *a0, int a1);
void func_021762C0(void *win, u32 slot, u8 *src, u16 heap);
void func_021762D8(const void *obj, void *a1, void *a2, void *a3);
void *func_02188CB4(u8 *p);
void func_021A3038(u8 *p, struct VecFx32 *out);
int func_021D3554(void *arg0, int arg1);
Mon *func_0217BEA8(int a0);
int func_0217EC08(u16 a, u16 b, u16 c);

void func_0217E714(W *w, u8 *p, u16 q)
{
    u32 sys;
    void *h;
    int done;
    int cur;
    int prev;
    int i;
    int n;
    int msg;
    int off;
    void *t;
    Mon *m1;
    Mon *m2;
    Mon *e;
    Buf b;
    Vec3 v;

    sys = func_02012138((const struct Ctx *)w->f00);
    h = func_020120F4((const struct Ctx *)w->f00);
    done = 0;
    if (w->f108 > 0) {
        w->f108--;
        if (w->f108 == 0 && p == 0) {
            func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)w->f4C), done);
            func_02045334((struct Descriptor *)w->f4C);
        }
        return;
    }
    prev = w->f10D;
    w->f10D = 0;
    cur = func_02012B58(h);
    if (p != 0 && func_0203D1B4() <= 1) {
        off = 0x93A;
        n = p[off - 0x15];
        if (n != 0) {
            if (n == 1) {
                msg = 0x29;
            } else {
                msg = 0x2A;
            }
            for (i = 0; i < p[off - 0x15]; i++) {
                func_0201EE0C((struct WordSet *)w->f24, i, *(void **)(p + i * 4 + off - 0x12),
                              p[i + off - 2], 1, p[i + off]);
            }
            func_02045CAC((struct MsgBank *)w->f2C, msg, w->f38);
            func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
        } else {
            func_02045CAC((struct MsgBank *)w->f2C, 0x33, w->f3C);
        }
        done = 1;
    }
    if (done == 0 && p != 0 && func_0203D1B4() > 1 && func_021585BC(p) != 0) {
        func_02045CAC((struct MsgBank *)w->f2C, 0x35, w->f3C);
        done = 1;
    }
    if (done == 0 && func_02012B70(h) == 0) {
        e = w->slots[cur].mon;
        if (e != 0) {
            for (i = 0; i < 3; i++) {
                if (cur != i && w->slots[i].mon != 0
                    && e->x == w->slots[i].mon->x && e->y == w->slots[i].mon->y) {
                    func_02045CAC((struct MsgBank *)w->f2C, 0x31, w->f3C);
                    done = 1;
                    break;
                }
            }
        }
        if (done == 0 && w->fE9 == 1) {
            func_02045CAC((struct MsgBank *)w->f2C, 0x34, w->f3C);
            done = 1;
        }
        if (done == 0 && w->fEA == 1) {
            func_02045CAC((struct MsgBank *)w->f2C, 0x32, w->f3C);
            done = 1;
        }
    }
    if (done == 0 && p != 0 && w->f169 != 4 && func_021583EC(h, w->f169) != 0) {
        t = (void *)func_021583EC(h, w->f169);
        if (((Fld *)(p + w->f169 * 0x1C + 0xA2))->b == 2) {
            msg = 0x36;
        } else {
            msg = 0x28;
        }
        func_02045CAC((struct MsgBank *)w->f2C, msg, w->f38);
        func_0201F02C((struct WordSet *)w->f24, 0, t);
        func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
        w->f169 = 4;
        done = 1;
    } else if (w->fDC != 0 && w->fE4 != 0 && (w->fDC == 3 || prev != w->fDC)) {
        if (w->fDC == 3 && p != 0 && w->fE4->a != 4) {
            u32 *ep;
            Mon *mm;
            t = func_0201210C((const struct Ctx *)w->f00);
            ep = (u32 *)(p + 0x8C + w->fE4->f28 * 0x1C);
            func_021A3038(func_02188CB4(t), (struct VecFx32 *)(&v));
            func_021762C0(w->f24, 0, w->fE4->f18, 0x70);
            mm = func_0217BEA8(((u16 *)ep)[10]);
            if (w->fD8 == w->fE8 && mm != 0
                && func_0217EC08(q, mm->id, mm->id2) == 1) {
                if (ep[0] == 1) {
                    func_02045CAC((struct MsgBank *)w->f2C, 0x2F, w->f38);
                    func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                } else {
                    int dx = ep[1] - v.x;
                    int dy = ep[3] - v.z;
                    int ady = dy < 0 ? -dy : dy;
                    int adx = dx < 0 ? -dx : dx;
                    if (adx > ady) {
                        msg = 0x2D;
                        if (dx <= 0) {
                            msg = 0x2E;
                        }
                    } else {
                        msg = 0x2C;
                        if (dy <= 0) {
                            msg = 0x2B;
                        }
                    }
                    func_02045CAC((struct MsgBank *)w->f2C, msg, w->f38);
                    func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                }
            } else {
                m1 = func_0217BEA8(((u16 *)ep)[10]);
                m2 = func_0217BEA8(q);
                if (m1 != 0 && m2 != 0 && m1->x == m2->x && m1->y == m2->y) {
                    func_02045CAC((struct MsgBank *)w->f2C, 0x2F, w->f38);
                    func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                }
            }
        }
        if (done == 0 && func_02012B70(h) == 1) {
            w->f10D = 0;
            switch (w->fDC) {
            case 1:
                func_02045CAC((struct MsgBank *)w->f2C, 0x21, w->f3C);
                break;
            case 2:
                func_02045CAC((struct MsgBank *)w->f2C, 0x22, w->f3C);
                break;
            case 3:
                if (w->f10E == 0) {
                    func_02045CAC((struct MsgBank *)w->f2C, w->fE4->a + 0x37, w->f3C);
                } else {
                    func_02045CAC(w->f30, w->fE4->c, w->f38);
                    func_021762D8(w->fE4, w->fE4->f18, w->f24, (void *)0x70);
                    func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
                }
                w->f10E ^= 1;
                break;
            case 0:
            case 4:
                return;
            default:
                return;
            }
            if (w->fDC != 3) {
                w->f10E = 0;
            }
            w->f10D = w->fDC;
            done = 1;
        }
    } else {
        if (func_02026608((u8 *)sys, (u8 *)(&b)) == 1) {
            w->f10D = 0;
            func_02045CAC((struct MsgBank *)w->f2C, b.msg, w->f38);
            done = 1;
            for (i = 0; i < 2; i++) {
                if (b.ptr[i] != 0) {
                    func_0201EE0C((struct WordSet *)w->f24, b.slot[i], (void *)b.ptr[i], b.par[i], 1, 2);
                }
            }
            func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
            done = 1;
        }
    }
    if (done == 0 && func_02012B70(h) == 1 && func_02013D5C(q) == 0 && func_02013D9C(q) == 0
        && func_021D3554(h, q) == 0) {
        func_02045CAC((struct MsgBank *)w->f2C, 0x30, w->f3C);
        done = 1;
    }
    w->f169 = 4;
    if (done == 1) {
        func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)w->f4C), 0);
        n = w->f28;
        func_0201C724(n, (int)func_02045770((struct Descriptor *)w->f4C), 0, 0, w->f3C, w->f1C, 0x3C40);
        w->f50 = 1;
        w->f108 = 0x5A;
    }
}
