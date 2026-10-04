/*
 * function: func_021BC664
 * address:  0x021BC664
 * packet:   pkt_ov021_021BC664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD090  0x021BD090  thumb  ov021
 *   func_021BD094  0x021BD094  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_02030734  0x02030734  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02062A98  0x02062A98  arm
 */

typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct ArcFile;
struct NitroFileHeader;
extern u16 func_021BD090(u8 *p);
extern u32 func_021BD094(u8 *p);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);

typedef struct S {
    char pad[0x14c];
    int a;
    int b;
} S;

void func_021BC664(S *p)
{
    int r4, r6, h;

    r4 = func_021BD090((u8 *)((int)p));
    r6 = func_021BD094((u8 *)((int)p));
    h = (int)func_02030734(r4, func_020493D4((struct ArcFile *)r6, 1), 0, (const char *)0x021DE354, 0x2c8);
    p->a = h;
    func_0204932C((struct ArcFile *)r6, 1, (void *)h);
    func_02062A98((struct NitroFileHeader *)p->a, (void **)((int)&p->b));
}
