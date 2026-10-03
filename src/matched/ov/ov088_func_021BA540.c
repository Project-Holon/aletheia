/*
 * function: func_021BA540
 * address:  0x021BA540
 * packet:   pkt_ov088_021BA540
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two 0/-2 result tests are small switches: their compare chain puts
 * both bodies after a shared `b` to the tail, which the outer switch's
 * out-of-range `bhi` reuses. The countdown is `-= 1` (re-reads the byte).
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_021BB9DC  0x021BB9DC  thumb  ov088
 *   func_020090E0  0x020090E0  thumb
 *   func_021BC080  0x021BC080  thumb  ov088
 *   func_021BBF1C  0x021BBF1C  thumb  ov088
 *   func_021BBD80  0x021BBD80  thumb  ov088
 *   func_021BBFA8  0x021BBFA8  thumb  ov088
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_0202EB44  0x0202EB44  thumb
 *   func_021BBE3C  0x021BBE3C  thumb  ov088
 *   func_021BBF98  0x021BBF98  thumb  ov088
 *   func_020362DC  0x020362DC  arm
 *   func_021BC024  0x021BC024  thumb  ov088
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
struct Sub020090B0Obj;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021BB9DC(char *, int);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern int func_021BC080(char *p, int v);
extern void func_021BBF1C(char *p, u32 a1);
extern void func_021BBD80(char *p);
extern int func_021BBFA8(char *p);
extern u32 func_0201FEBC(u8 *);
extern int func_0202EB44(void);
extern void func_021BBE3C(char *p);
extern void func_021BBF98(char *p);
extern u32 func_020362DC(void);
extern void func_021BC024(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);

int func_021BA540(char *p)
{
    void *t;
    u32 r;
    switch (*(u8 *)(p + 0x12a)) {
    case 0:
        func_020434DC(6, 0);
        func_021BB9DC(p, 0);
        if (func_020090E0(*(void **)(p + 0xc)) == 0) {
            *(u8 *)(p + 0x12c) = 1;
            *(u8 *)(p + 0x12a) = 0;
            return func_021BC080(p, 1);
        }
        *(u8 *)(p + 0x12b) = 8;
        *(u8 *)(p + 0x12a) = *(u8 *)(p + 0x12a) + 1;
        break;
    case 1:
        if (*(u8 *)(p + 0x12b) != 0) {
            *(u8 *)(p + 0x12b) -= 1;
            break;
        }
        func_021BBF1C(p, 0x1a);
        func_021BBD80(p);
        *(u8 *)(p + 0x12a) = *(u8 *)(p + 0x12a) + 1;
        break;
    case 2:
        if (func_021BBFA8(p) == 0) {
            func_021BC024(p);
            *(u8 *)(p + 0x12a) = *(u8 *)(p + 0x12a) + 1;
        }
        break;
    case 3:
        r = func_0201FEBC(*(u8 **)(p + 0x7c));
        switch (r) {
        case 0:
            if (func_0202EB44() == 0) {
                func_021BBF1C(p, 0x11);
                *(u8 *)(p + 0x12a) = 5;
            } else {
                *(u8 *)(p + 0x12c) = 0;
                *(u8 *)(p + 0x12a) = 4;
            }
            break;
        case (u32)-2:
            func_021BBF1C(p, 0x1b);
            *(u8 *)(p + 0x12a) = 7;
            break;
        }
        break;
    case 4:
        func_021BBE3C(p);
        func_021BBF98(p);
        *(u8 *)(p + 0x12a) = 0;
        return func_021BC080(p, 1);
    case 5:
        if (func_021BBFA8(p) == 0)
            *(u8 *)(p + 0x12a) = *(u8 *)(p + 0x12a) + 1;
        break;
    case 6:
        if (func_020362DC() & 3) {
            *(u8 *)(p + 0x12c) = 1;
            *(u8 *)(p + 0x12a) = 4;
        }
        break;
    case 7:
        if (func_021BBFA8(p) == 0) {
            func_021BC024(p);
            *(u8 *)(p + 0x12a) = *(u8 *)(p + 0x12a) + 1;
        }
        break;
    case 8:
        r = func_0201FEBC(*(u8 **)(p + 0x7c));
        switch (r) {
        case 0:
            *(u8 *)(p + 0x12c) = 1;
            *(u8 *)(p + 0x12a) = 4;
            break;
        case (u32)-2:
            func_021BBF1C(p, 0x1a);
            *(u8 *)(p + 0x12a) = 2;
            break;
        }
        break;
    }
    func_0201C4E4(*(void **)(p + 0x68));
    t = *(void **)(p + 0x68);
    if (*(u8 *)(p + 0xf4) != 0 && func_0201C6C4(t, func_02045770(*(void **)(p + 0xf0))) == 0) {
        func_02045334(*(void **)(p + 0xf0));
        *(u8 *)(p + 0xf4) = 0;
    }
    return 7;
}
