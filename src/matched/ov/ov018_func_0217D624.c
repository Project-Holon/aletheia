/*
 * function: INTRUDE_SUBDISP_SystemSetup
 * address:  0x0217D624
 * packet:   pkt_ov018_0217D624
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   TCBL_Create  0x0203101C  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   d_021836B4     0x021836B4  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GfFont;
struct Tcbl;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Obj;
struct Bank;

struct State {
    u8 pad00[0x1C];
    struct GfFont *font;      /* 0x1C */
    struct Tcbl *tcbl;        /* 0x20 */
    struct WordSet *words;    /* 0x24 */
    int unk28;                /* 0x28 */
    struct MsgBank *msg2C;    /* 0x2C */
    struct MsgBank *msg30;    /* 0x30 */
    u8 pad34[4];
    struct U16Vec *str38;     /* 0x38 */
    struct U16Vec *str3C;     /* 0x3C */
    struct U16Vec *str40;     /* 0x40 */
    u8 pad44[0x10];
    struct Bank *bank;        /* 0x54 */
    struct Obj *obj;          /* 0x58 */
    u8 pad5C[0x54];
    void *unkB0;              /* 0xB0 */
};

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Obj *CLACT_CreateRenderer(unsigned char *a0, unsigned int a1, unsigned int heap);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern unsigned char d_021836B4[];

void INTRUDE_SUBDISP_SystemSetup(struct State *o)
{
    struct Obj *t;

    o->bank = CLACT_CreateUnit(0x29, 5, 0x70);
    t = CLACT_CreateRenderer(d_021836B4, 1, 0x70);
    o->obj = t;
    CLACT_SetUnitRenderer(o->bank, t);
    o->unkB0 = BMP_OAM_CreateSys(0x70, o->bank);
    o->tcbl = TCBL_Create(0x70, 0x70, 4, 0x20);
    o->font = GF_FONT_Create(0x17, 0, 0, 0, 0x70);
    o->words = func_0201EC64(0x70);
    o->unk28 = PRINTSYS_QUE_Create((void *)0x70);
    o->msg2C = func_02045B38(0, 2, 0x2D, 0x70);
    o->msg30 = func_02045B38(0, 2, 0x42, 0x70);
    o->str38 = STRBUF_Create(0x80, 0x70);
    o->str3C = STRBUF_Create(0x80, 0x70);
    o->str40 = STRBUF_Create(0x80, 0x70);
}
