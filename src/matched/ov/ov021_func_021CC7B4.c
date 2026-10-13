/*
 * function: PARTY_SELECT_LIST_Delete
 * address:  0x021CC7B4
 * packet:   pkt_ov021_021CC7B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTY_SELECT_LIST_GetResult  0x021CC8B0  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   PARTY_SELECT_LIST_DeleteStatusIcons  0x021CCDF8  thumb  ov021
 *   PARTY_SELECT_LIST_FreeStatusIconResources  0x021CCCC4  thumb  ov021
 *   PARTY_SELECT_LIST_DeleteMonIcons  0x021CCB98  thumb  ov021
 *   PARTY_SELECT_LIST_FreeMonIconResources  0x021CC9A4  thumb  ov021
 *   PARTY_SELECT_LIST_FreeMessageResources  0x021CCEE4  thumb  ov021
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DE5BC  0x021DE5BC  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u8 pad0[0x18];
    u32 f18;
    u8 pad1C[0xb8 - 0x1c];
    u32 fB8;
    u8 padBC[0xc1 - 0xbc];
    u8 fC1;
} Obj;

extern u32 PARTY_SELECT_LIST_GetResult(Obj *p, u32 *out);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void PARTY_SELECT_LIST_DeleteStatusIcons(u8 *p);
extern int PARTY_SELECT_LIST_FreeStatusIconResources(u32 a);
extern void PARTY_SELECT_LIST_DeleteMonIcons(u8 *p);
extern void PARTY_SELECT_LIST_FreeMonIconResources(u8 *p);
extern int PARTY_SELECT_LIST_FreeMessageResources(u32 a);
struct Bank;
extern u32 GF_FONT_Delete(void *ptr);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern const char d_021DE5BC[];

u32 PARTY_SELECT_LIST_Delete(Obj *p, u32 *out)
{
    u32 r;

    r = PARTY_SELECT_LIST_GetResult(p, out);
    if (p->fC1 != 1)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    PARTY_SELECT_LIST_DeleteStatusIcons((u8 *)p);
    PARTY_SELECT_LIST_FreeStatusIconResources((u32)p);
    PARTY_SELECT_LIST_DeleteMonIcons((u8 *)p);
    PARTY_SELECT_LIST_FreeMonIconResources((u8 *)p);
    PARTY_SELECT_LIST_FreeMessageResources((u32)p);
    GF_FONT_Delete((void *)p->fB8);
    CLACT_DeleteUnit((struct Bank *)p->f18);
    func_020307B0(p);
    return r;
}
