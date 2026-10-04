/*
 * function: func_021B7C3C
 * address:  0x021B7C3C
 * packet:   pkt_ov071_021B7C3C
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B7D6C  0x021B7D6C  thumb  ov071
 *   func_021B7DAC  0x021B7DAC  thumb  ov071
 *   func_021B6F2C  0x021B6F2C  thumb  ov071
 *   func_020457B0  0x020457B0  arm
 *   func_020084F4  0x020084F4  thumb
 *   func_02045994  0x02045994  arm
 *   func_02008550  0x02008550  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_021B6E1C  0x021B6E1C  thumb  ov071
 *   func_021B7DE0  0x021B7DE0  thumb  ov071
 *   func_02040588  0x02040588  arm
 *   func_020434DC  0x020434DC  arm
 */

typedef struct {
    char pad[0x10];
    int f10;
} Inner;

typedef struct {
    int f0;
    Inner *f4;
} C;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Strbuf;
struct U16Vec;
typedef unsigned char  u8;
struct Sub0200852CObj;
int func_021B7C3C(int a, int *b, C *c)
{
    extern void *func_0203159C(int, int, int);
    extern void func_02082BCC(void *, int, int);
    extern void func_021B7D6C(void);
    extern void func_021B7DAC(C *, Inner *);
    extern int func_021B6F2C(C *);
    extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
    extern void *func_020084F4(int);
    extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
    extern u8 func_02008550(const struct Sub0200852CObj *obj);
    extern void func_0201EE0C(int, unsigned, void *, int, unsigned, unsigned);
    extern void func_02045808(struct U16Vec *vec);
    extern void func_021B6E1C(Inner *, void *, int, int, int, int, int, int, int);
    extern void func_021B7DE0(void *, C *);
    extern void func_02040588(u32 which, u32 enable);
    extern void func_020434DC(u32 mask, u32 enable);
    void *m;
    void *s;
    int h;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x24, 0x61);
        func_02082BCC(m, 0, 0x24);
        func_021B7D6C();
        func_021B7DAC(c, c->f4);
        h = func_021B6F2C(c);
        s = func_020457B0(8, 0x61);
        func_02045994(s, func_020084F4(h), 8);
        func_0201EE0C(c->f4->f10, 0, s, func_02008550((const struct Sub0200852CObj *)h), 1, 2);
        func_02045808(s);
        func_021B6E1C(c->f4, m, 0, 0x80, 0xc, 0x1e, 2, 0, c->f4->f10);
        func_021B7DE0(m, c);
        *b = *b + 1;
        break;
    case 1:
        func_02040588(2, 1);
        func_020434DC(0x10, 1);
        return 1;
    }
    return 0;
}
