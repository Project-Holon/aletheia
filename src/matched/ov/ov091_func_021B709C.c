/*
 * function: func_021B709C
 * address:  0x021B709C
 * packet:   pkt_ov091_021B709C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R;

struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);

void func_021B709C(u8 *p)
{
    R b;
    R a;
    int x;
    u32 bank;

    bank = (u32)func_0204B100(10, 8, *(u16 *)p);
    *(u32 *)(p + 0x1d4) = bank;
    func_0204B270((struct Bank *)bank);
    b.a = 0;
    b.b = 0;
    b.c = 0;
    b.d = 10;
    b.e = 3;
    *(int *)(p + 0x1d8) = (int)func_0204B294((void *)*(int *)(p + 0x1d4), *(int *)(p + 0x198),
                                        *(int *)(p + 0x178), *(int *)(p + 0x1b4), &b, 0, *(u16 *)p);
    *(int *)(p + 0x1dc) = (int)func_0204B294((void *)*(int *)(p + 0x1d4), *(int *)(p + 0x198),
                                        *(int *)(p + 0x178), *(int *)(p + 0x1b4), &b, 0, *(u16 *)p);
    func_0204B92C((struct Obj *)*(int *)(p + 0x1d8), 1);
    func_0204B92C((struct Obj *)*(int *)(p + 0x1dc), 1);
    func_0204B3DC((struct Obj *)*(int *)(p + 0x1d8), 0);
    func_0204B3DC((struct Obj *)*(int *)(p + 0x1dc), 0);
    a.a = 0xe0;
    a.b = 0xa8;
    a.c = 1;
    a.d = 0;
    a.e = 0;
    x = (int)func_0204B294((void *)*(int *)(p + 0x1d4), *(int *)(p + 0x1a0),
                      *(int *)(p + 0x17c), *(int *)(p + 0x1bc), &a, 0, *(u16 *)p);
    *(int *)(p + 0x1e0) = x;
    func_0204B92C((struct Obj *)x, 1);
    a.a = 0xc4;
    a.c = 0;
    x = (int)func_0204B294((void *)*(int *)(p + 0x1d4), *(int *)(p + 0x1a0),
                      *(int *)(p + 0x17c), *(int *)(p + 0x1bc), &a, 0, *(u16 *)p);
    *(int *)(p + 0x1e4) = x;
    func_0204B92C((struct Obj *)x, 1);
}
