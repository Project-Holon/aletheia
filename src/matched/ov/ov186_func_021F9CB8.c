/*
 * function: func_021F9CB8
 * address: 0x021F9CB8
 * packet: pkt_ov186_021F9CB8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045808 0x02045808 arm
 *   func_021FB5E4 0x021FB5E4 thumb ov186
 *   func_021FB788 0x021FB788 thumb ov186
 *   func_021FB760 0x021FB760 thumb ov186
 *   func_021FB704 0x021FB704 thumb ov186
 *   func_021FB7D0 0x021FB7D0 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FAC20 0x021FAC20 thumb ov186
 *   func_021FA020 0x021FA020 thumb ov186
 *   func_021FAEC0 0x021FAEC0 thumb ov186
 *   func_021FAF08 0x021FAF08 thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FA274 0x021FA274 thumb ov186
 *   func_021FA920 0x021FA920 thumb ov186
 *   func_021FAAD0 0x021FAAD0 thumb ov186
 *   d_02200D18 0x02200D18 data a1
 *   d_02200D1C 0x02200D1C data a1
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Rec { u16 a, b; };
struct Set { struct Rec rec[6]; u32 count; };
struct Obj {
    u16 heap;
    u16 pad0;
    int f4;
    int f8;
    int *fC;
    int f10;
    int f14;
    int pad18;
    int f1C;
    int pad20[6];
    u8 f38;
    u8 f39;
    u8 f3a;
    u8 f3b;
    char *f3c;
    char *f40;
    void *f44;
    void *f48;
    u32 f4c;
    int pad50[2];
    int f58;
    struct Set *f5c;
};
extern char d_02200D18[];
extern char d_02200D1C[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
struct U16Vec;
extern void *func_02025538(u32 a0, void *a1);
extern u32 func_0201C440(void *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_021FB5E4(int *ctx, int heap);
extern unsigned func_021FB788(void *);
extern unsigned short func_021FB760(void *, int);
extern void *func_021FB704(char *ctx, int section, unsigned item);
extern void *func_021FB7D0(unsigned * const *p, void *record, int archive, unsigned short heap);
extern void func_021FBE54(char *base, u32 idx, u32 area);
extern void func_021FAC20(void *ctx, void *object, int a, void *b, int owner, void *arg, int index, u32 heap);
extern void func_021FA020(u8 *ctx, int a1, int a2);
extern void func_021FAEC0(char *p, unsigned index);
extern void func_021FAF08(char *p, int a1);
extern int func_021FC214(char *p);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021FD73C(int *p, int v);
extern void func_021FA274(void *p);
extern void func_021FA920(int *task, int *state, u8 *ctx);
extern void func_021FAAD0(void *p, int *state, unsigned char *ctx);
struct Obj *func_021F9CB8(int a, int b, int c, int d, int e, int f, u32 heap)
{
    struct Obj *p;
    int tmp;
    int size;
    int i;
    int arch;
    u8 buf[0x44];
    if (a >= 12) func_02034714(d_02200D18, 0, d_02200D18);
    p = func_02030734(heap, 0x60, 0, d_02200D1C, 0x13F);
    func_02082BCC(p, 0, 0x60);
    p->f4 = c;
    p->f8 = b;
    p->heap = heap;
    p->f5c = (struct Set *)e;
    p->f48 = func_02025538(heap, (void *)b);
    p->f4c = func_0201C440((void *)heap);
    p->f58 = f;
    p->f14 = 1;
    func_02082BCC(&tmp, 0, 4);
    tmp = d;
    p->f44 = func_021FB5E4(&tmp, heap);
    if (a >= 10) p->f10 = 2;
    else p->f10 = 0;
    func_021FBE54((char *)p->f4, p->f10, heap);
    func_021FBE54((char *)p->f4, p->f10 + 1, heap);
    p->f38 = func_021FB788(p->f44);
    size = p->f38 * 0x44;
    p->f40 = func_02030734(heap, size, 0, d_02200D1C, 0x167);
    func_02082BCC(p->f40, 0, size);
    p->f3a = 6;
    p->f3c = func_02030734(heap, 0x198, 0, d_02200D1C, 0x171);
    func_02082BCC(p->f3c, 0, 0x198);
    p->fC = func_021FD6D8((int)p, (int)func_021FA274, heap);
    if (p->f5c->count != 0) {
        arch = func_021FC214((char *)c);
        for (i = 0; i < p->f5c->count; i++) {
            void *q = func_021FB704(p->f44, p->f5c->rec[i].a, (unsigned short)p->f5c->rec[i].b);
            void *rec = func_021FB7D0(p->f44, q, arch, (heap & 0x7FFF) | 0x8000);
            func_02082BCC(buf, 0, 0x44);
            func_021FAC20(buf, q, b, p->f48, c, rec, p->f10, heap);
            func_021FA020((u8 *)p, (int)buf, 0);
            func_02045808(rec);
        }
        for (i = 0; i < p->f3b; i++)
            func_021FAEC0(p->f3c + (p->f3b - i - 1) * 0x44, (unsigned short)i);
        func_021FD73C(p->fC, (int)func_021FA920);
        p->f1C = 2;
    } else {
        arch = func_021FC214((char *)c);
        p->f39 = func_021FB760(p->f44, a);
        for (i = 0; i < p->f39; i++) {
            void *q = func_021FB704(p->f44, a, (unsigned short)i);
            void *rec = func_021FB7D0(p->f44, q, arch, (heap & 0x7FFF) | 0x8000);
            func_021FAC20(p->f40 + i * 0x44, q, b, p->f48, c, rec, p->f10, heap);
            func_02045808(rec);
        }
        for (i = 0; i < p->f39; i++)
            func_021FAF08(p->f40 + i * 0x44, 0xe0);
        func_021FD73C(p->fC, (int)func_021FAAD0);
    }
    return p;
}
