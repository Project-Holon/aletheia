/*
 * function: func_021E5998
 * address:  0x021E5998
 * packet:   pkt_ov119_021E5998
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u8 func_020355C4(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_021D8FA4(void *p, int a);
extern void *func_020185F4(void *a);
extern u32 func_0201BA68(void *mon);
extern void *func_0204A6C8(void *, int, int, int, int);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02049238(void *);
void func_021E5998(char *p)
{
    void *arc;
    void *a, *b;
    int z;
    ObjTmpl u, t;
    u.x = 0x80;
    u.y = 0x10;
    u.prio = 0x13;
    u.pal = 0xe;
    u.mode = 1;
    *(void **)(p + 0xf08) = func_0204B294(*(void **)(p + 0x9c4), (unsigned int)*(void **)(p + 0x894), (unsigned int)*(void **)(p + 0x880),
        (unsigned int)*(void **)(p + 0x8b0), &u, 1, *(u16 *)(p + 0x5f4));
    func_0204B92C(*(void **)(p + 0xf08), 1);
    func_0204B3DC(*(void **)(p + 0xf08), 1);
    u.x = 0x60;
    u.y = 0x10;
    u.prio = 0;
    u.pal = 0xb;
    u.mode = 1;
    *(void **)(p + 0xf0c) = func_0204B294(*(void **)(p + 0x9c4), (unsigned int)*(void **)(p + 0x894), (unsigned int)*(void **)(p + 0x880),
        (unsigned int)*(void **)(p + 0x8b0), &u, 1, *(u16 *)(p + 0x5f4));
    func_0204B92C(*(void **)(p + 0xf0c), 1);
    if (func_020355C4()) {
        func_0204B3DC(*(void **)(p + 0xf0c), 0);
    }
    arc = func_020490F4(7, *(u16 *)(p + 0x5f4));
    z = 0;
    a = func_020185F4(func_021D8FA4(p, 0));
    b = func_020185F4(func_021D8FA4(p, 1));
    *(void **)(p + 0x89c) = func_0204A6C8(arc, func_0201BA68(a), z, 1, *(u16 *)(p + 0x5f4));
    *(void **)(p + 0x8a0) = func_0204A6C8(arc, func_0201BA68(b), z, 1, *(u16 *)(p + 0x5f4));
    t.x = 0x60;
    t.y = 0xc;
    t.prio = z;
    t.pal = 0xc;
    t.mode = 1;
    *(void **)(p + 0xf10) = func_0204B294(*(void **)(p + 0x9c4), (unsigned int)*(void **)(p + 0x89c), (unsigned int)*(void **)(p + 0x87c),
        (unsigned int)*(void **)(p + 0x8ac), &t, 1, *(u16 *)(p + 0x5f4));
    func_0204B92C(*(void **)(p + 0xf10), 0);
    func_0204B3DC(*(void **)(p + 0xf10), 1);
    func_0204B6F4(*(void **)(p + 0xf10), func_0201BBE8(a), 1);
    t.x = 0xa0;
    *(void **)(p + 0xf14) = func_0204B294(*(void **)(p + 0x9c4), (unsigned int)*(void **)(p + 0x8a0), (unsigned int)*(void **)(p + 0x87c),
        (unsigned int)*(void **)(p + 0x8ac), &t, 1, *(u16 *)(p + 0x5f4));
    func_0204B92C(*(void **)(p + 0xf14), 0);
    func_0204B3DC(*(void **)(p + 0xf14), 1);
    func_0204B6F4(*(void **)(p + 0xf14), func_0201BBE8(b), 1);
    func_02049238(arc);
}
