/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_ov072_021B95A0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   ov067_id       0x00000043  data
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_021BB6E8  0x021BB6E8  thumb  ov072
 *   func_021BBB24  0x021BBB24  thumb  ov072
 *   func_021B991C  0x021B991C  thumb  ov072
 *   func_021B996C  0x021B996C  thumb  ov072
 *   func_020120F4  0x020120F4  thumb
 *   func_021BB764  0x021BB764  thumb  ov072
 *   func_021BB3E8  0x021BB3E8  thumb  ov072
 *   func_0201DD78  0x0201DD78  thumb
 *   func_021BB448  0x021BB448  thumb  ov072
 *   func_0201DD68  0x0201DD68  thumb
 *   func_021BB778  0x021BB778  thumb  ov072
 *   func_021B9E38  0x021B9E38  thumb  ov072
 *   func_021BB784  0x021BB784  thumb  ov072
 *   func_021BB4B4  0x021BB4B4  thumb  ov072
 *   func_02040618  0x02040618  arm
 *   func_021BA490  0x021BA490  thumb  ov072
 *   func_021BA04C  0x021BA04C  thumb  ov072
 *   func_021BA7F8  0x021BA7F8  thumb  ov072
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_021BA3CC  0x021BA3CC  thumb  ov072
 *   func_021BAF74  0x021BAF74  thumb  ov072
 *   func_021BB1BC  0x021BB1BC  thumb  ov072
 *   func_021BB5D4  0x021BB5D4  thumb  ov072
 *   func_021BA6C8  0x021BA6C8  thumb  ov072
 *   func_021BB5AC  0x021BB5AC  thumb  ov072
 *   func_021BB220  0x021BB220  thumb  ov072
 *   func_021BA69C  0x021BA69C  thumb  ov072
 *   func_021BA3F4  0x021BA3F4  thumb  ov072
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021BB6E4  0x021BB6E4  thumb  ov072
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
} Pos;

typedef struct {
    int f0;
    u8 pad4[4];
    u16 f8;
    u16 fA;
} Arg;

typedef signed int     s32;
struct GfFont;
extern int func_02034AC4(s32 handle);
extern char ov067_id[];
extern void func_0203064C(u32 a, u32 b, u32 c);
extern u8 *func_0203159C(void *a, int b, int c);
extern void func_02082BCC(void *p, int v, int n);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
struct Ctx;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 *func_021BB6E8(u32 heap);
extern int func_021BBB24(int a);
extern void func_021B991C(int *p, int a, int b);
extern void func_021B996C(int a, int *b);
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_021BB764(int unused, u32 i);
extern void func_021BB3E8(void *p, int a, int b, int c, u8 s0, u8 s1, u8 s2, u8 s3, u16 s4);
extern void func_0201DD78(u32 a, u32 b, u32 c);
extern void func_021BB448(void *p, u32 a, int x, int y);
extern void func_0201DD68(void);
extern unsigned int func_021BB778(char *p, int n);
extern void func_021B9E38(void *o, u32 a1, u32 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 heap);
extern unsigned int func_021BB784(char *p, int n);
extern void func_021BB4B4(void *p, u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02040618(u32 a, u32 b, u32 c);
extern void func_021BA490(void *p, u16 x, u16 y, int a, u32 b, u32 c, int heap, int flag);
extern void func_021BA04C(void *p, u32 a, u32 b, int heap);
extern int func_021BA7F8(void *p, u16 x, u16 y);
extern int func_021BA774(char *p, int i);
extern void func_021BA3CC(void *p, Pos *pos);
extern void func_021BAF74(void *p, u32 a, u32 b, int heap);
extern void func_021BB1BC(void *p, int a, int b, int c, int d, u16 e);
extern void func_021BB5D4(void *p, int heap);
extern int func_021BA6C8(void *p, void *a);
extern void func_021BB5AC(void *p, int x);
extern void func_021BB220(void *p, int w);
extern void func_021BA69C(void *p, Pos *o);
extern void func_021BA3F4(void *p, int a, Pos *b);
extern int func_0203CD98(void);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_020056A0(void (*cb)(void *, void *), void *arg, int pri);
extern void func_021BB6E4(void *a, void *b);

int func_021B95A0(void *a, void *b, Arg *c)
{
    Pos pt;
    Pos org;
    u8 *o;
    u32 v;
    int flag;
    int e;

    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x44, 0x60000);
    o = func_0203159C(a, 0x144, 0x44);
    func_02082BCC(o, 0, 0x144);
    *(Arg **)(o + 0x130) = c;
    flag = (*(Arg **)(o + 0x130))->f0 == 2;
    *(void **)(o + 0x124) = func_0201D7EC(0x17, 0, 0, 0, 0x44);
    *(int *)(o + 0x128) = (int)func_02045B38(0, 2, 0x59, 0x44);
    *(int *)(o + 0x12c) = (int)func_02045B38(0, 2, 0xb9, 0x44);
    *(u32 **)(o + 0) = func_021BB6E8(0x44);
    *(int *)(o + 0x34) = func_021BBB24(0x44);
    func_021B991C((int *)(o + 4), (int)o, (int)func_021B996C);
    v = (u32)func_020120F4((const struct Ctx *)((*(u32 **)(o + 0x130))[5]));
    if ((*(Arg **)(o + 0x130))->f0 != 1) {
        func_021BB3E8(o + 0xc4, func_021BB764(*(u32 *)o, 1), *(int *)(o + 0x124), *(int *)(o + 0x12c), 0, 0x15, 0x18, 3, 0x44);
        func_0201DD78(0xf, 1, 0);
        func_021BB448(o + 0xc4, 0, 0x10, 0);
        func_0201DD68();
    }
    func_021B9E38(o + 0x14, (*(Arg **)(o + 0x130))->f0, func_021BB778((char *)(*(u32 *)o), 0), func_021BB764(*(u32 *)o, 0), 0xf, 8, v, 0x44);
    func_021BB4B4(o + 0xd4, func_021BB764(*(u32 *)o, 1), *(int *)(o + 0x124), *(int *)(o + 0x128), func_021BB784((char *)(*(u32 *)o), 0), 0x44);
    func_02040618(func_021BB764(*(u32 *)o, 1), 3, -4);
    func_021BA490(o + 0x50, c->f8, c->fA, *(int *)(o + 0x34), *(u32 *)o, (u32)func_020120F4((const struct Ctx *)((*(u32 **)(o + 0x130))[5])), 0x44, flag);
    func_021BA04C(o + 0x38, func_021BB784((char *)(*(u32 *)o), 1), func_021BB784((char *)(*(u32 *)o), 2), 0x44);
    e = func_021BA7F8(o + 0x50, c->f8, c->fA);
    if (e != 0) {
        pt.x = func_021BA774((char *)e, 4);
        pt.y = func_021BA774((char *)e, 5);
    } else {
        pt.x = 0x80;
        pt.y = 0x60;
    }
    func_021BA3CC(o + 0x38, &pt);
    func_021BAF74(o + 0x78, func_021BB764(*(u32 *)o, 3), func_021BB764(*(u32 *)o, 2), 0x44);
    func_021BB1BC(o + 0xb0, func_021BB764(*(u32 *)o, 5), *(int *)(o + 0x124), *(int *)(o + 0x128), *(int *)(o + 0x12c), 0x44);
    func_021BB5D4(o + 0xf4, 0x44);
    e = func_021BA6C8(o + 0x50, o + 0x38);
    if (e != 0) {
        func_021BB5AC(o + 0xd4, e);
        func_021BB220(o + 0xb0, e);
        *(int *)(o + 0x134) = e;
        func_021BA69C(o + 0x50, &org);
        func_021BA3F4(o + 0x38, e, &org);
    }
    if (func_0203CD98()) {
        func_0203D34C(1, 0x44);
    }
    *(u32 *)(o + 0x13c) = func_020056A0(func_021BB6E4, o, 0);
    return 1;
}
