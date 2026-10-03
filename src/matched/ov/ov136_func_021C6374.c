/*
 * function: func_021C6374
 * address: 0x021C6374
 * packet: pkt_ov136_021C6374
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): byte-correct; only func_02024450 lacks a witness. Witness filed as
 *   src/matched/arm9/func_02024450.c (EXACT). Re-verify after its shard exists, then file EXACT.
 * symbols:
 *   func_02008FC8 0x02008FC8 thumb
 *   func_02024450 0x02024450 thumb
 *   func_0202DC48 0x0202DC48 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02008FC0 0x02008FC0 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02008F84 0x02008F84 thumb
 *   func_02045924 0x02045924 arm
 *   func_021C5F80 0x021C5F80 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Sub02008F80Entry;
struct Sub02008F80Obj;
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern int func_02024450(const u16 *p);
extern void func_0202DC48(void *, void *, void *, u8);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 layer);
extern u16 func_02008FC0(const struct Sub02008F80Obj *obj);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 *func_02008F84(struct Sub02008F80Obj *obj);
extern void func_02045924(void *, void *);
extern void func_021C5F80(void *unused, void *text, u8 *slot, void *owner, int x, int y, u32 mode, u16 color, int align);

void func_021C6374(u8 *p)
{
    u32 i;
    void *mon;
    void *w;

    for (i = 0; i < 3; i++) {
        mon = func_02008FC8(*(void **)(*(u8 **)(p + 8) + p[0x1F] * 4 + 0x298), (u8)i);
        if (func_02024450(mon)) {
            func_0202DC48(*(void **)(*(u8 **)(p + 8) + 0x35C), *(void **)(*(u8 **)(p + 8) + i * 4 + 0xB0), mon, (u8)i);
            w = *(void **)(*(u8 **)(p + 8) + i * 4 + 0xB0);
            func_02045334(w);
            func_02045374(w);
            func_02041B6C(func_02045730(w));
        }
    }
    *(u16 *)(*(u8 **)(p + 8) + 0x360) = 6;
    *(u16 *)(*(u8 **)(p + 8) + 0x362) = 0;
    *(u16 *)(*(u8 **)(p + 8) + 0x364) = func_02008FC0(*(void **)(*(u8 **)(p + 8) + p[0x1F] * 4 + 0x298));
    if (*(u16 *)(*(u8 **)(p + 8) + 0x364) != 0) {
        func_0202DC48(*(void **)(*(u8 **)(p + 8) + 0x35C), *(void **)(*(u8 **)(p + 8) + 0xBC), *(u8 **)(p + 8) + 0x360, 3);
    }
    func_02043B5C(func_02045770(*(void **)(*(u8 **)(p + 8) + 0xC0)), 0);
    func_02045924(*(void **)(*(u8 **)(p + 8) + 0x1D8), func_02008F84(*(void **)(*(u8 **)(p + 8) + p[0x1F] * 4 + 0x298)));
    func_021C5F80(*(void **)(*(u8 **)(p + 8) + 0xC0), *(void **)(*(u8 **)(p + 8) + 0x1D8), *(u8 **)(p + 8) + 0x1BC,
                  *(void **)(*(u8 **)(p + 8) + 0x1C4), 0, 2, *(u32 *)(p + 0x18), 0x440, 0);
    w = *(void **)(*(u8 **)(p + 8) + 0xC0);
    func_02045334(w);
    func_02045374(w);
    func_02041B6C(func_02045730(w));
}
