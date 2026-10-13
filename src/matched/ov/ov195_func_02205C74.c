/*
 * function: func_02205C74
 * address:  0x02205C74
 * packet:   pkt_02205C74
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208F68 0x02208F68 data
 *   func_02030734 0x02030734 arm
 *   func_020173EC 0x020173EC thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   POKE_TOOL_ChangeSpecies 0x020178D8 thumb
 *   func_0220609C 0x0220609C thumb ov195
 *   func_02206108 0x02206108 thumb ov195
 *   func_022063E0 0x022063E0 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    u16 heap;
    u16 pad02;
    void *res0;
    u32 f08;
    u16 f0c;
    u16 pad0e;
    void *res1;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u8 pad28[0x34 - 0x28];
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    float scale;
    u8 f48;
    u8 pad49[0x5c - 0x49];
    u32 f5c;
} Owner;

extern char d_02208F68[];
struct RecDC;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020173EC(void);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void POKE_TOOL_ChangeSpecies(void *p, u32 a);
extern void func_0220609C(char *a);
extern void func_02206108(Owner *o);
extern void func_022063E0(Owner *o);

Owner *func_02205C74(u16 heap, u32 f08, void *res0, u16 f0c)
{
    Owner *o = func_02030734(heap, 0x60, 1, d_02208F68, 0x201);

    o->heap = heap;
    o->f08 = f08;
    o->res0 = res0;
    o->f0c = f0c;
    o->res1 = 0;
    if (f08 == 0) {
        o->res1 = func_02030734(o->heap, func_020173EC(), 1, d_02208F68, 0x213);
        func_02019CE0(o->res0, o->res1);
        POKE_TOOL_ChangeSpecies(o->res1, o->f0c);
    }
    if (o->f08 == 0)
        o->f14 = 0;
    else
        o->f14 = 0x16;
    o->f18 = 0;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f34 = 0;
    o->f38 = 0;
    o->f3c = 0;
    o->f40 = 0;
    o->scale = 16.0f;
    if (o->f08 == 0)
        o->f48 = 0;
    else
        o->f48 = 1;
    func_0220609C((char *)o);
    func_02206108(o);
    func_022063E0(o);
    o->f5c = 1;
    return o;
}
