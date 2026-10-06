/*
 * function: func_02155C0C
 * address:  0x02155C0C
 * packet:   pkt_ov010_02155C0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov010 link sequence: a 27-state machine over s->state that runs the
 * wireless exchange through the ov132 session object (s->link->sess),
 * loads the three sub-procs through func_020120B4, and returns 1 once
 * the heap is torn down in state 10.
 *
 * symbols:
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_021567D8  0x021567D8  thumb  ov010
 *   func_02155F24  0x02155F24  thumb  ov010
 *   func_02156888  0x02156888  thumb  ov010
 *   func_02156770  0x02156770  thumb  ov010
 *   func_02155F9C  0x02155F9C  thumb  ov010
 *   func_02155FB4  0x02155FB4  thumb  ov010
 *   func_02156710  0x02156710  thumb  ov010
 *   func_02155FC8  0x02155FC8  thumb  ov010
 *   func_02156074  0x02156074  thumb  ov010
 *   func_0215611C  0x0215611C  thumb  ov010
 *   func_02156530  0x02156530  thumb  ov010
 *   func_02156420  0x02156420  thumb  ov010
 *   func_02155F4C  0x02155F4C  thumb  ov010
 *   func_02156824  0x02156824  thumb  ov010
 *   func_02156B74  0x02156B74  thumb  ov010
 *   func_02157028  0x02157028  thumb  ov010
 *   func_02157260  0x02157260  thumb  ov010
 *   func_02157298  0x02157298  thumb  ov010
 *   func_021FD908  0x021FD908  thumb  ov132
 *   func_021FD904  0x021FD904  thumb  ov132
 *   func_021FD918  0x021FD918  thumb  ov132
 *   func_021FD8D4  0x021FD8D4  thumb  ov132
 *   func_021FD8EC  0x021FD8EC  thumb  ov132
 *   func_021FCE28  0x021FCE28  thumb  ov132
 *   func_021FD83C  0x021FD83C  thumb  ov132
 *   func_0200A81C  0x0200A81C  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_02030B50  0x02030B50  arm
 *   func_020306F0  0x020306F0  arm
 *   d_02172724     0x02172724  data
 *   d_02172748     0x02172748  data
 *   d_021F8360     0x021F8360  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Link {
    u32 f00;
    void *sess;         /* 0x04 */
};

typedef struct Seq {
    void *f00;          /* 0x00 */
    u32 f04;
    struct Link *link;  /* 0x08 */
    u32 state;          /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 pad11[0x1C - 0x11];
    void *f1c;          /* 0x1C */
    u32 f20;
    void *f24;          /* 0x24 */
    u32 f28;
    void *f2c;          /* 0x2C */
    void *f30;          /* 0x30 */
    void *f34;          /* 0x34 */
    void *f38;          /* 0x38 */
    u32 f3c;
    void *f40;          /* 0x40 */
    u8 f44[4];          /* 0x44 */
    u32 f48;
    u8 f4c;             /* 0x4C */
    u8 pad4d[3];
    u32 f50;            /* 0x50 */
} Seq;

extern u8 d_02172724[];
extern u8 d_02172748[];
extern u8 d_021F8360[];

struct Big;
struct Ctx;
struct Deal;
struct IcaAnime;
struct L0200ED54;
struct Src;
struct Sub0200852CObj;
struct Work;
extern void func_02156BAC(void *p);
extern void func_021567D8(void *evt, Seq *s);
extern void func_02155F24(int *p);
extern void func_02156888(void *a0, void *a1, int a2);
extern int func_02156770(void *evt, Seq *s);
extern void func_02155F9C(Seq *s);
extern void func_02155FB4(struct Work *w);
extern int func_02156710(void *evt, Seq *s);
extern void func_02155FC8(struct Work *w);
extern void func_02156074(struct Work *w);
extern void func_0215611C(struct Work *w);
extern void func_02156530(struct Work *w);
extern void func_02156420(struct Work *w);
extern void func_02155F4C(Seq *s);
extern void func_02156824(void *evt, Seq *s);
extern void func_02156B74(struct Work *w);
extern struct Deal *func_02157028(u32 heap, struct Src *src, u16 lim);
extern u32 func_02157260(const u8 *p);
extern u32 func_02157298(const u8 *p);
extern u32 func_021FD908(u8 *p);
extern int func_021FD904(int *p);
extern void func_021FD918(char *p, u32 a, int b);
extern u32 func_021FD8D4(char *p);
extern u8 func_021FD8EC(char *p, int index);
extern int func_021FCE28(char *p, u32 index);
extern u32 func_021FD83C(char *p);
extern u16 func_0200A81C(struct Big *p);
extern void *func_0200ED48(void *p);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void func_0200FB38(void);
extern void func_02030B50(void *p);
extern void func_020306F0(u32 heap);

int func_02155C0C(void *evt, void *unused, Seq *s)
{
    func_02156BAC(s);
    switch (s->state) {
    case 11:
        if (func_021FD908(s->link->sess) == 1) {
            u32 lo = 0;
            u32 hi = 0;
            void *list;
            u8 i;

            if (func_021FD904(s->link->sess) == 1) {
                s->f38 = func_02157028(4, s->f24, func_0200A81C(s->f40));
                lo = func_02157260(s->f38);
                hi = func_02157298(s->f38);
            }
            func_021FD918(s->link->sess, lo, hi);
            s->state = 12;
            list = func_0200ED48(s->f1c);
            for (i = 0; i < 4; i++) {
                if (func_021FD8D4(s->link->sess) != func_021FD8EC(s->link->sess, i)) {
                    void *p = (void *)func_021FCE28(s->link->sess, i);
                    if (p != 0)
                        func_0200ED54(list, func_02008530(p));
                }
            }
        } else if (s->f50 == 1) {
            s->state = 0x17;
        }
        break;
    case 12:
        if (func_021FD83C(s->link->sess) == 1) {
            u8 i;

            s->state = 13;
            for (i = 0; i < 4; i++)
                s->f44[i] = func_021FD8EC(s->link->sess, i);
            s->f4c = func_021FD8D4(s->link->sess);
            func_02156B74((struct Work *)s);
        } else if (s->f50 == 1) {
            s->state = 0x17;
        }
        break;
    case 13:
        func_021567D8(evt, s);
        s->state = 14;
        break;
    case 14:
        func_02155F24((int *)s);
        func_02156888(evt, s, 3);
        s->state = 0;
        break;
    case 0:
        if (s->f50 == 1 && s->f10 == 0) {
            s->state = 0x17;
        } else if (func_02156770(evt, s) == 1) {
            s->f10 = 0;
            s->state = 1;
        }
        break;
    case 1:
        s->state = 3;
        break;
    case 3:
        func_02155F9C(s);
        func_020120B4(s->f00, ~0u, d_02172724, s->f2c);
        s->state = 4;
        break;
    case 4:
        if (func_020120F0(s->f00) == 0) {
            func_02155FB4((struct Work *)s);
            s->state = 0x10;
        }
        break;
    case 16:
        if (func_02156710(evt, s) == 1) {
            s->f10 = 0;
            s->state = 0x11;
            if (s->f50 == 1)
                s->state = 0x17;
        }
        break;
    case 17:
        func_02156888(evt, s, 4);
        s->state = 0x12;
        break;
    case 18:
        if (s->f50 == 1 && s->f10 == 0) {
            s->state = 0x17;
        } else if (func_02156770(evt, s) == 1) {
            s->f10 = 0;
            s->state = 5;
        }
        break;
    case 5:
        func_02155FC8((struct Work *)s);
        func_020120B4(s->f00, ~0u, d_02172748, s->f30);
        s->state = 6;
        break;
    case 6:
        if (func_020120F0(s->f00) == 0) {
            func_02156074((struct Work *)s);
            s->state = 7;
            if (s->f50 == 1)
                s->state = 0x16;
        }
        break;
    case 7:
        func_0215611C((struct Work *)s);
        func_020120B4(s->f00, ~0u, d_021F8360, s->f34);
        s->state = 8;
        break;
    case 8:
        if (func_020120F0(s->f00) == 0) {
            s->state = 0x13;
            if (s->f50 == 1)
                s->state = 0x16;
        }
        break;
    case 19:
        if (func_02156710(evt, s) == 1) {
            s->f10 = 0;
            s->state = 0x14;
            func_02156530((struct Work *)s);
            func_02156420((struct Work *)s);
        }
        break;
    case 20:
        func_02156888(evt, s, 5);
        s->state = 2;
        break;
    case 2:
        if (s->f50 == 1) {
            s->state = 0x17;
        } else {
            func_02155F4C(s);
            func_02156824(evt, s);
            s->state = 9;
        }
        break;
    case 9:
        func_02156888(evt, s, 0x28CC);
        s->state = 10;
        break;
    case 10:
        func_02030B50((void *)4);
        func_020306F0(0x2C);
        return 1;
    case 22:
        if (func_02156710(evt, s) == 1)
            s->state = 0x17;
        break;
    case 23:
        func_0200FB38();
        s->state = 0x18;
        break;
    case 24:
        func_02155F4C(s);
        func_02156824(evt, s);
        s->state = 0x19;
        break;
    case 25:
        s->state = 0x1A;
        break;
    case 26:
        func_02156888(evt, s, 0x28CD);
        s->state = 10;
        break;
    }
    return 0;
}
