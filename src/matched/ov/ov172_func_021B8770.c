/*
 * function: func_021B8770
 * address: 0x021B8770
 * packet: pkt_ov172_021B8770
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021BE210 0x021BE210 thumb ov172
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_021BE2E0 0x021BE2E0 thumb ov172
 *   func_021BA234 0x021BA234 thumb ov172
 *   func_021BDFFC 0x021BDFFC thumb ov172
 *   func_021B6EA8 0x021B6EA8 thumb ov172
 *   func_021BE0CC 0x021BE0CC thumb ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE078 0x021BE078 thumb ov172
 *   func_021BE0A0 0x021BE0A0 thumb ov172
 *   func_021B7740 0x021B7740 thumb ov172
 *   func_021BA1E8 0x021BA1E8 thumb ov172
 *   func_021BE0D4 0x021BE0D4 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(u32 v);
extern void func_021BE210(u8 *p, u32 arg);
extern void *func_021BDFEC(void *p);
extern void func_021BE2E0(void *p);
extern void func_021BA234(void *p);
extern char *func_021BDFFC(void *p);
extern void func_021B6EA8(void *p, u16 v);
extern void func_021BE0CC(void *p, u32 v);
extern u32 func_021BDFDC(void *p);
extern u32 func_021BE078(void *p);
extern void func_021BE0A0(void *p, u32 v);
extern void func_021B7740(void *p, char *q, int a, int b);
extern int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq);
extern void func_021BE0D4(void *p, u32 v);
void func_021B8770(int id, int size, u32 *msg, char *q)
{
    u32 self;
    void *r;
    char *base;
    u32 v;
    self = func_0203D1A4((u32)func_020399A8());
    switch (*(u8 *)(msg + 1)) {
    case 0:
        if (id == self)
            break;
        *(u8 *)(q + 0x183) |= (u8)(1 << id);
        break;
    case 1:
        v = msg[0];
        *(u8 *)(q + 0x3ae) = v;
        if (v != 0xff) {
            func_021BE210(*(u8 **)(q + 0x3dc), (u8)v);
        } else {
            r = func_021BDFEC(*(void **)(q + 0x3dc));
            func_021BE2E0(*(void **)(q + 0x3dc));
            func_021BA234(r);
        }
        break;
    case 3:
        func_021B6EA8(func_021BDFFC(*(void **)(q + 0x3dc)), msg[0]);
        func_021BE0CC(*(void **)(q + 0x3dc), 0);
        break;
    case 2:
        base = (char *)func_021BDFDC(*(void **)(q + 0x3dc));
        v = msg[0];
        if (v == func_021BE078(*(void **)(q + 0x3dc)))
            break;
        func_021BE0A0(*(void **)(q + 0x3dc), v);
        func_021B7740(*(void **)(q + 0x3dc), base, 1, 0);
        break;
    case 4:
        if (id == self)
            break;
        *(u32 *)(q + 0x3c0) = 1;
        break;
    case 5:
        if (id == self)
            break;
        *(u32 *)(q + 0x3c8) = 1;
        break;
    case 6:
        if (self != 0)
            break;
        *(u32 *)(q + id * 0x40 + 0x74) = 1;
        *(u32 *)(q + 0x3b0) = 1;
        break;
    case 7:
        r = func_021BDFEC(*(void **)(q + 0x3dc));
        if (id == self)
            func_021BA1E8(r, *(char **)(q + 0x1a4), *(u16 *)(q + 0x19c), 0, *(int *)(q + 0x1a0));
        else
            func_021BA1E8(r, *(char **)(q + 0x1a4), *(u16 *)(q + 0x19c), 0x7f, *(int *)(q + 0x1a0));
        break;
    case 8:
        if (self == 0) {
            *(u32 *)(q + id * 0x40 + 0x74) = 0;
            *(u32 *)(q + 0x3b0) = 1;
        }
        func_021BE2E0(*(void **)(q + 0x3dc));
        break;
    case 9:
        if (id == *(u8 *)(q + 0x3ae))
            *(u32 *)(q + 0x3b0) = 1;
        func_021BE2E0(*(void **)(q + 0x3dc));
        break;
    case 10:
        func_021BE0D4(*(void **)(q + 0x3dc), 1);
        break;
    }
}
