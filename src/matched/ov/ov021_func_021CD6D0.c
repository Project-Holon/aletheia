/*
 * function: func_021CD6D0
 * address:  0x021CD6D0
 * packet:   pkt_ov021_021CD6D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_021DB498  0x021DB498  data
 *   func_021CE24C  0x021CE24C  thumb  ov021
 *   func_021CE2BC  0x021CE2BC  thumb  ov021
 *   func_021CE12C  0x021CE12C  thumb  ov021
 *   func_021CE7AC  0x021CE7AC  thumb  ov021
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_021CF1AC  0x021CF1AC  thumb  ov021
 *   func_021CE36C  0x021CE36C  thumb  ov021
 *   func_021CE41C  0x021CE41C  thumb  ov021
 *   func_021CE78C  0x021CE78C  thumb  ov021
 *   func_021CE73C  0x021CE73C  thumb  ov021
 *   func_021CEA28  0x021CEA28  thumb  ov021
 *   func_021CE52C  0x021CE52C  thumb  ov021
 *   func_021CE5AC  0x021CE5AC  thumb  ov021
 *   func_021CF2F0  0x021CF2F0  thumb  ov021
 *   func_021CE6F0  0x021CE6F0  thumb  ov021
 *   func_021CF3B0  0x021CF3B0  thumb  ov021
 *   func_021CF378  0x021CF378  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_021CF12C  0x021CF12C  thumb  ov021
 *   func_021CE81C  0x021CE81C  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D01C  0x0203D01C  arm
 *   func_020392B8  0x020392B8  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_02080D24  0x02080D24  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203D650  0x0203D650  arm
 *
 * Per-frame state machine (state byte at 0x51E, 20 cases). Closed:
 * case 8 placed after case 12 (image layout), case 1 written with the
 * `== 0` arm first, case 14 through an Entry pointer local (keeps the +8
 * out of the pool word), loop condition `(i < 4) ? 1 : 0` (branch to the
 * bottom test), `1u << i` in the x526 test only (an identical `1 << i`
 * there is CSEd across the call and spills the mask), and `1 << (u32)i` in
 * the x578 test: with the plain int promotion of i the shift is evaluated
 * before the x578 load, so `movs r0,#1` is live across the reload of the
 * spilled 0x578 offset and the reload lands in r1; the u32 count orders the
 * load first and the reload takes r0 (2026-10-02).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0x14];
    u32 h;              /* 0x014 */
    u8  pad18[0x14];
    u32 x2C;            /* 0x02C */
    u8  sub[0x4E4];     /* 0x030 */
    u8  x514;           /* 0x514 */
    u8  pad515[6];
    u8  x51B;           /* 0x51B */
    u8  x51C;           /* 0x51C */
    u8  x51D;           /* 0x51D */
    u8  state;          /* 0x51E */
    u8  pad51F;
    u8  x520;           /* 0x520 */
    u8  pad521[5];
    u8  x526;           /* 0x526 */
    u8  pad527[0x4C];
    u8  x573;           /* 0x573 */
    u16 x574;           /* 0x574 */
    u8  pad576[2];
    u8  x578;           /* 0x578 */
} Work;

typedef struct {
    u8  pad0[8];
    u16 f8;
    u8  padA[2];
} Entry;

typedef struct {
    u8  pad0[0x26];
    u16 f26;
} Obj;

typedef struct {
    u8  pad0[0x18];
    Obj *(*get)(u32);
} Vtbl;

extern Entry d_021DB498[];

extern void func_021CE24C(u8 *p);
extern void func_021CE2BC(u8 *p);
extern void func_021CE12C(u8 *p);
extern void func_021CE7AC(u32 *p);
extern void func_021CE9E4(Work *p, int n);
extern void func_0203D01C(void);
extern int func_020392B8(void);
extern int func_02039ACC(void);
extern u32 func_020362DC(void);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_020399B8(u8 *p);
extern u32 func_021CF1AC(u32 a, u32 b, u32 c);
extern void func_021CE36C(u8 *p);
extern void func_021CE41C(u32 *p);
extern int func_021CE78C(u32 a);
extern int func_021CE73C(Work *p);
extern void func_021CEA28(Work *p);
extern int func_0203D1B4(void);
extern int func_021CE52C(u32 *p);
extern void func_0203D1E8(u32 unused, void *arg);
extern u32 func_021CE5AC(u32 *p);
extern int func_021CF2F0(int a);
extern u32 func_0203D1A4(struct Link *p);
extern void func_021CE6F0(Work *p, int a);
extern void func_0203D7BC(u8 a0);
extern u32 func_0203D1C0(u32 index);
extern u32 func_02080D24(int a);
extern int func_021CF3B0(int a);
extern int func_021CF378(int a);
struct Link;
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
extern void *func_0203D798(void);
extern u32 func_0203D650(void);
extern u32 func_02190EF0(u32 *p);
extern int func_021CF12C(int a);
extern void func_021CE81C(u32 *p);
extern u32 func_0200FB24(void);

int func_021CD6D0(Work *p)
{
    int n;
    u16 saved;
    u8 mask;
    u8 i;

    if (p->state != 0) {
        func_021CE24C((u8 *)p);
        func_021CE2BC((u8 *)p);
        func_021CE12C((u8 *)p);
    }

    switch (p->state) {
    case 0:
        func_021CE7AC((u32 *)p);
        func_021CE9E4(p, 8);
        p->state++;
        break;
    case 1:
        if (p->x520 == 0) {
            p->state = 4;
        } else {
            func_0203D01C();
            p->state++;
        }
        break;
    case 2:
        if (func_020392B8() > 1) {
            if (func_02039ACC() == 1) {
                p->state++;
            }
        } else if (func_020362DC() & 2) {
            p->state = 7;
            p->x2C = 2;
            p->state = 0x13;
        }
        break;
    case 3:
        if (func_020399B8((u8 *)((u32)func_020399A8())) == 1) {
            p->state = 4;
        }
        break;
    case 4:
        if (func_021CF1AC((u32)p->sub, 1, p->x51B) == 1) {
            p->state++;
        }
        break;
    case 5:
        func_021CE36C((u8 *)p);
        func_021CE41C((u32 *)p);
        if (func_021CE78C((u32)p) == 1) {
            n = func_021CE73C(p);
            saved = p->x574;
            p->x574 = 0xFFFF;
            if (n >= p->x51D || (n >= p->x51C && (func_020362DC() & 1))) {
                func_021CEA28(p);
                p->state = 6;
            } else if (func_020362DC() & 2) {
                p->state = 7;
            } else if (p->x520 == 0 && func_0203D1B4() <= 1) {
                p->state = 0x11;
            } else if (saved != 0xFFFF) {
                func_021CE9E4(p, saved);
            }
        }
        break;
    case 6:
        n = func_021CE52C((u32 *)p);
        if (n == 1) {
            func_0203D1E8((u32)func_020399A8(), 0);
            p->state = 9;
        } else if (n == 2) {
            if (func_021CE73C(p) >= p->x51D) {
                p->state = 7;
            } else {
                p->state = 5;
                if (func_021CE73C(p) > 1 && p->x520 == 1) {
                    p->x574 = 9;
                } else {
                    p->x574 = 8;
                }
            }
        }
        break;
    case 7:
        n = func_021CE5AC((u32 *)p);
        if (n == 1) {
            func_0203D1E8((u32)func_020399A8(), 0);
            p->state = 0xD;
        } else if (n == 2) {
            p->state = 5;
        }
        break;
    case 9:
        if (func_021CF2F0(p->x51B) == 1) {
            func_021CE6F0(p, func_0203D1A4((struct Link *)((u32)func_020399A8())));
            p->x526 = p->x514;
            func_0203D7BC(1);
            p->state = 10;
        }
        break;
    case 10:
        mask = 1 << func_0203D1A4((struct Link *)((u32)func_020399A8()));
        for (i = 0; (i < 4) ? 1 : 0; i++) {
            if (i != func_0203D1A4((struct Link *)((u32)func_020399A8())) && (p->x526 & (1u << i))) {
                if (func_0203D1C0(i) == 1) {
                    if (p->x578 & (1 << (u32)i)) {
                        mask |= (u8)(1 << i);
                    }
                } else {
                    p->state = 0xB;
                    break;
                }
            }
        }
        if (p->x526 == mask) {
            if (func_02080D24(p->x578) < p->x51C) {
                p->state = 0xB;
            } else {
                p->state = 0xC;
            }
        }
        break;
    case 11:
        if (func_021CF3B0(p->x51B) == 1) {
            p->x526 = p->x514;
            p->x2C = 2;
            p->state = 0xE;
        }
        break;
    case 12:
        if (func_021CF378(p->x51B) == 1) {
            p->x2C = 1;
            p->state = 8;
            p->x573 = func_02080D24(p->x578);
            func_02039C68((struct Link *)func_020399A8(), 1, 0x27);
        }
        break;
    case 8:
        if (p->x573 != func_020392B8() || p->x51C > func_020392B8()) {
            if (func_021CF3B0(p->x51B) == 1) {
                p->x526 = p->x514;
                p->x2C = 2;
                p->state = 0xE;
            }
        } else if (func_02039CB4((struct Link *)func_020399A8(), 1, 0x27) == 1) {
            Vtbl *v;

            p->x2C = 1;
            p->state = 0x13;
            v = func_0203D798();
            v->get(func_0203D650())->f26 = 0;
        }
        break;
    case 13:
        if (func_021CF3B0(p->x51B) == 1) {
            p->x526 = p->x514;
            p->x2C = 2;
            p->state = 0x10;
        }
        break;
    case 14:
        {
            Entry *e = &d_021DB498[p->x520];

            func_021CE9E4(p, e->f8);
        }
        p->state = 0xF;
        break;
    case 15:
        if (func_02190EF0((u32 *)p->h) == 1) {
            p->state = 0x10;
        }
        break;
    case 16:
        if (func_021CF12C(p->x526) == 0) {
            p->state = 0x13;
        }
        break;
    case 17:
        func_021CE9E4(p, 0x14);
        p->state = 0x12;
        break;
    case 18:
        if (func_02190EF0((u32 *)p->h) == 1) {
            p->x2C = 2;
            p->state = 0x13;
        }
        break;
    case 19:
        func_021CE81C((u32 *)p);
        return 1;
    }

    if (func_0200FB24() != 0) {
        p->x2C = 4;
        return 1;
    }
    return 0;
}
