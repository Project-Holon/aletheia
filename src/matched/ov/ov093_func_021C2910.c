/*
 * function: func_021C2910
 * address: 0x021C2910
 * packet: pkt_ov093_021C2910
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021C2AA0 0x021C2AA0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D8 0x021D66D8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021C5D88 0x021C5D88 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021C2BF0 0x021C2BF0 thumb ov093
 *   func_021C2CA8 0x021C2CA8 thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 *   func_021C2C50 0x021C2C50 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x; } S;
struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };
extern void func_021C5C1C(u8 *, u8 *, int, S);
extern void func_021C5480(u8 *, u8 *, int);
extern void func_021C2AA0(int, S, u8 *, struct Msg *);
extern int func_021C99A0(void *, const struct Msg *);
extern void func_021C8810(struct Msg *);
extern u16 func_021D5444(void *);
extern int func_021D59B4(void *, int);
extern void func_021D8510(u8 *);
extern void func_021D66D8(void *, u8);
extern u8 func_021D5440(u8 *);
extern void func_021CD4B0(void *, u32, ...);
extern void func_021D8484(u8 *);
extern void func_021C5D88(u8 *, u8 *, int);
extern u32 func_021CC8D8(void *, int);
extern int func_021D7D6C(int);
extern void func_021C2BF0(u8 *, u8 *, u8 *, u32, u32);
extern void func_021C2CA8(void *, int);
extern void func_021C3FDC(u8 *, u8 *);
extern void func_021C2C50(u8 *, u8 *, u8 *, u32);
extern void func_021CC95C(void *, u32, int);
extern void func_021C195C(u8 *, u8 *, u32);
void func_021C2910(u8 *p, u8 *a, u8 *b, int kind, S value, int f, int g, const struct Msg *m)
{
    u32 lock;
    func_021C5C1C(p, a, kind, value);
    switch (kind) {
    case 5: func_021C5480(p, a, 599); break;
    case 4: func_021C5480(p, a, 600); break;
    case 1: func_021C5480(p, a, 602); break;
    case 3: func_021C5480(p, a, 601); break;
    case 2: func_021C5480(p, a, 598); break;
    case 6: func_021C5480(p, a, 603); break;
    case 7: func_021C5480(p, a, 604); break;
    case 0: break;
    }
    if (f) {
        func_021C2AA0(kind, value, a, (struct Msg *)(p + 0x1ae4));
        func_021C99A0(p, (struct Msg *)(p + 0x1ae4));
        func_021C8810((struct Msg *)(p + 0x1ae4));
    } else if (m) func_021C99A0(p, m);
    if (kind == 3 && func_021D5444(a) == 492 && func_021D59B4(a, 19) == 1) {
        func_021D8510(a);
        func_021D66D8(a, 0);
        func_021CD4B0(*(void **)(p + 12), 79, func_021D5440(a), 0);
        func_021D8484(a);
        func_021C5D88(p, a, 222);
    }
    lock = func_021CC8D8(p + 0x1d74, 7936);
    if (func_021D7D6C(kind)) {
        func_021C2BF0(p, a, b, kind, value.x);
    } else if (kind == 16) {
        func_021C2CA8(p, (int)a);
        if (func_021D59B4(a, 17) == 127) func_021C3FDC(p, a);
    } else func_021C2C50(p, a, b, kind);
    func_021CC95C(p + 0x1d74, lock, 7951);
    if (!g) func_021C195C(p, a, 3);
}
