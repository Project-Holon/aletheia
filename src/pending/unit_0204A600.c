/*
 * unit:     yes
 * address:  0x0204A600
 * packet:   pkt_0204A600
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Cell-actor system update / tick execution functions.
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_0204BAEC  0x0204BAEC  arm
 *   func_0204BB04  0x0204BB04  arm
 *   func_0204BB20  0x0204BB20  arm
 *   func_0204BB54  0x0204BB54  arm
 *   func_0204BB8C  0x0204BB8C  arm
 *   func_0204BCF4  0x0204BCF4  arm
 *   func_0204C7A4  0x0204C7A4  arm
 *   func_02066998  0x02066998  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_02146A74;

extern void func_0204BAEC(u32 which);
extern u32  func_0204BB04(void);
extern void func_0204BB20(u32 val);
extern void func_0204BB54(void);
extern void func_0204BB8C(void);
extern void func_0204BCF4(void *p);
extern void func_0204C7A4(void *p);
extern void func_02066998(void *p);

void func_0204A600(void)
{
    if (g_02146A74 == 0) {
        return;
    }
    func_0204BAEC(0);
    func_0204BB54();
    func_0204BB8C();
    if (*(void **)(g_02146A74 + 0xec) != 0) {
        func_02066998(*(void **)(g_02146A74 + 0xec));
    }
    func_0204BAEC(1);
}

void func_0204A648(void)
{
    if (g_02146A74 == 0) {
        return;
    }
    if (func_0204BB04() == 0) {
        return;
    }
    func_0204BCF4(g_02146A74);
    if (*(void **)(g_02146A74 + 0xec) != 0) {
        func_0204C7A4(g_02146A74 + 0xe0);
    }
    func_0204BB20(1);
}

void func_0204A698(void)
{
    if (g_02146A74 == 0) {
        return;
    }
    func_0204BAEC(0);
    func_0204BB54();
    func_0204BAEC(1);
}