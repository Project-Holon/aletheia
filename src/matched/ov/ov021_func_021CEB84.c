/*
 * function: func_021CEB84
 * address:  0x021CEB84
 * packet:   pkt_ov021_021CEB84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CEE00  0x021CEE00  thumb  ov021
 *   func_021CEE48  0x021CEE48  thumb  ov021
 *   func_021CEDA0  0x021CEDA0  thumb  ov021
 *   func_021CEF1C  0x021CEF1C  thumb  ov021
 *   func_02190A14  0x02190A14  thumb  ov021
 *   func_020392B8  0x020392B8  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
 *   func_021CF1AC  0x021CF1AC  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02190B1C  0x02190B1C  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021CEE00(u8 *p);
extern void func_021CEE48(u8 *p);
extern int func_021CEDA0(u8 *p);
extern void func_021CEF1C(u8 *p);
struct Handle;
extern void func_02190A14(u8 *p);
extern int func_020392B8(void);
extern int func_02039ACC(void);
extern u32 func_020362DC(void);
extern void func_021CE9E4(u8 *p, int n);
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern int func_021CF1AC(u8 *p, int a, u8 b);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_0219049C(u32 a);
extern int func_021909BC(u32 a);
extern void func_02190B1C(u32 h);
extern u32 func_02190EF0(u32 *p);

typedef struct {
    u8 pad0[0x2c8];
    u32 busy;
    u32 result;
    u8 state;
    u8 pad2d1[2];
    u8 prev;
    u16 timer;
} Sub;

u32 func_021CEB84(u8 *p)
{
    u32 *w = (u32 *)(p + 0x130);
    Sub *s = (Sub *)(p + 0x13c);
    u32 r;

    switch (s->state) {
    case 0:
        if (s->busy == 0) {
            func_021CEE00(p);
            func_021CEE48(p);
            if (func_021CEDA0(p) == 0) {
                s->result = 3;
                s->state = 3;
            } else if (p[0x40d] == 1) {
                func_021CEF1C(p);
                func_02190A14((u8 *)(*(u32 *)(p + 0x140)));
                p[0x40d] = 0;
            }
        } else if (func_020392B8() > 1) {
            if (func_02039ACC() == 1) {
                s->state++;
            }
        } else {
            if (func_020362DC() & 2) {
                s->prev = s->state;
                s->state = 4;
            }
            (s->timer)++;
            if (s->timer >= 300) {
                s->state = 6;
                func_021CE9E4(p, 0x24);
            }
        }
        break;
    case 1:
        if (func_020399B8((u8 *)func_020399A8()) == 1) {
            *(u32 *)(p + 0x52c) = 0;
            if (func_021CF1AC(p + 0x30, 0, p[0x51b]) == 1) {
                s->state = 2;
            }
        } else if (func_020362DC() & 2) {
            s->prev = s->state;
            s->state = 4;
        }
        if (p[0x51a] == 1) {
            s->result = 1;
            s->state = 3;
        }
        break;
    case 2:
        if (*(u32 *)(p + 0x52c) == 1) {
            s->result = 1;
            s->state = 3;
        } else if (*(u32 *)(p + 0x52c) == 2) {
            s->result = 2;
            s->state = 3;
        } else if (func_020362DC() & 2) {
            s->prev = s->state;
            s->state = 4;
        }
        if (p[0x51a] == 1) {
            s->result = 1;
            s->state = 3;
        }
        break;
    case 3:
        return s->result;
    case 4:
        func_021CE9E4(p, 0x23);
        *w = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)(*(u32 *)p)), 0);
        s->state = 5;
        break;
    case 5:
        r = func_02190C78((struct Handle *)(*w));
        if (func_0219049C(func_02188C54((u8 *)(*(u32 *)p))) == 1 && p[0x576] == 1) {
            r = 1;
        }
        if (r == 2 && func_0219049C(func_02188C54((u8 *)(*(u32 *)p))) == 1) {
            if (p[0x519] == 1 || p[0x51a] == 1) {
                func_021909BC(*w);
                *w = 0;
                s->result = 1;
                s->state = 3;
            }
        } else {
            func_021909BC(*w);
            *w = 0;
            if (r == 1) {
                s->state = s->prev;
                func_021CE9E4(p, 0x20);
                if (*(u32 *)(p + 0x140) != 0) {
                    func_02190B1C(*(u32 *)(p + 0x140));
                }
            } else {
                s->result = 3;
                s->state = 3;
            }
        }
        break;
    case 6:
        if (func_02190EF0((u32 *)(*(u32 *)(p + 0x14))) == 1) {
            s->result = 3;
            s->state = 3;
        }
        break;
    }
    return 0;
}
