/*
 * function: PARTY_SELECT_LIST_Create
 * address:  0x021CC720
 * packet:   pkt_ov021_021CC720
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PARTY_SELECT_LIST_InitMessageResources  0x021CCEB8  thumb  ov021
 *   PARTY_SELECT_LIST_LoadMonIconResources  0x021CC8DC  thumb  ov021
 *   PARTY_SELECT_LIST_CreateMonIcons  0x021CCA00  thumb  ov021
 *   PARTY_SELECT_LIST_LoadStatusIconResources  0x021CCC50  thumb  ov021
 *   PARTY_SELECT_LIST_CreateStatusIcons  0x021CCCE4  thumb  ov021
 *   d_021DE5BC  0x021DE5BC  data  a1
 *   d_021DE5C0  0x021DE5C0  data  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u8 padE[2];
    u32 f10;
    u32 f14;
    u32 f18;
    u8 pad1C[0xb8 - 0x1c];
    u32 fB8;
    u8 padBC[0xc4 - 0xbc];
} Obj;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Bank;
struct GfFont;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void PARTY_SELECT_LIST_InitMessageResources(Obj *p);
extern void PARTY_SELECT_LIST_LoadMonIconResources(Obj *p);
extern void PARTY_SELECT_LIST_CreateMonIcons(Obj *p);
extern void PARTY_SELECT_LIST_LoadStatusIconResources(u8 *p);
extern void PARTY_SELECT_LIST_CreateStatusIcons(Obj *p);
extern const char d_021DE5BC[];
extern const char d_021DE5C0[];

Obj *PARTY_SELECT_LIST_Create(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap)
{
    Obj *p;

    if (b == 0 || c == 0)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    p = func_02030734(heap, 0xc4, 1, d_021DE5C0, 0xd3);
    p->f0 = a;
    p->f4 = b;
    p->f8 = c;
    p->fC = heap;
    p->f10 = d;
    p->f14 = e;
    p->f18 = (u32)CLACT_CreateUnit(0x20, 0xa, p->fC);
    p->fB8 = (u32)GF_FONT_Create(0x17, 3, 0, 0, p->fC);
    PARTY_SELECT_LIST_InitMessageResources(p);
    PARTY_SELECT_LIST_LoadMonIconResources(p);
    PARTY_SELECT_LIST_CreateMonIcons(p);
    PARTY_SELECT_LIST_LoadStatusIconResources((u8 *)p);
    PARTY_SELECT_LIST_CreateStatusIcons(p);
    return p;
}
