/*
 * function: func_02014B08
 * address:  0x02014B08
 * packet:   pkt_02014808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734     0x02030734  arm
 *   func_020637D4     0x020637D4  arm
 *   func_02049F34     0x02049F34  arm
 *   func_020056A0     0x020056A0  thumb
 *   func_02016880     0x02016880  thumb
 *   sFile_020A72CC    0x020A72CC  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u8  pad00[0xc];
    void *f0c;
    u32 f10;
    u32 f14;
    u8  f18[0x18];
    u32 f30;
    u32 f34;
    u8  pad38[8];
    void *f40;
    u32 f44;
} Obj;

typedef struct {
    u8  f00[4];
    u8  f04[8];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    Obj *f20;
} Sub;

extern void *func_02030734(void *heap, u32 size, u32 flag, char *file, u32 line);
extern void  func_020637D4(void *p);
extern u32   func_02049F34(u32 a, u32 b, void *c, u32 d);
extern void *func_020056A0(void *fn, Sub *s, u32 a);
struct Obj_02016880;
extern void func_02016880(void *a0, struct Obj_02016880 *a1);
extern char  sFile_020A72CC[];

void *func_02014B08(u32 id, void *heap)
{
    Obj *o;
    Sub *s;
    u32 m;

    o = func_02030734(heap, 0x4c, 1, sFile_020A72CC, 0x78);
    o->f10 = id;
    o->f40 = heap;
    o->f44 = 0x1000;
    o->f14 = (u32)func_02030734(heap, id * 4, 1, sFile_020A72CC, 0x7f);
    o->f30 = 9 << 14;
    o->f34 = 0x1000;
    func_020637D4(o->f18);
    m = ((u32)heap & 0x7fff) | 0x8000;
    s = func_02030734((void *)(u16)m, 0x2c, 1, sFile_020A72CC, 0x8e);
    s->f20 = o;
    s->f0c = (u32)o->f18;
    s->f1c = 0x1100;
    s->f14 = func_02049F34(0xb, 0x58, s->f04, (u16)m);
    o->f0c = func_020056A0((void *)func_02016880, s, 0);
    return o;
}
