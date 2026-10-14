/*
 * function: EVENT_PERAP_RECORD_CreatePokeIcon
 * address:  0x021D1F78
 * packet:   pkt_ov021_021D1F78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateUnit  0x0204B100  arm
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   POKEGRA_OpenHandle  0x0202D7C8  thumb
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKEGRA_RegisterCgrPP  0x0202D934  thumb
 *   POKEGRA_RegisterPalettePP  0x0202D8D0  thumb
 *   POKEGRA_RegisterCellAnimPP  0x0202D9A4  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   gPerapIconActorParam     0x021DD60C  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h[4];
} Tbl;

extern Tbl gPerapIconActorParam;

typedef unsigned char  u8;
struct Bank;
struct Sav;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern u32 POKE_TOOL_Dummy(u32 a);
extern int POKEGRA_OpenHandle(int a0);
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern int POKEGRA_RegisterCgrPP(int a0, void *a1, int a2, int a3, unsigned short a9);
extern int POKEGRA_RegisterPalettePP(int a0, void *a1, int a2, int a3, unsigned short a8, unsigned short a9);
extern u32 POKEGRA_RegisterCellAnimPP(u32 h, u32 b1, u32 b2, u32 b3, u16 key);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern void ARC_TOOL_DeleteHandle(u32 a);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *a, unsigned int b, unsigned int c, unsigned int d, const void *e, unsigned short f, unsigned short g);

void EVENT_PERAP_RECORD_CreatePokeIcon(u32 *w)
{
    u32 r4, r7, t;
    Tbl buf;

    w[0x38 / 4] = (u32)CLACT_CreateUnit(1, 0, 0x15);
    r4 = POKE_TOOL_Dummy(w[0x14 / 4]);
    r7 = POKEGRA_OpenHandle(0x15);
    t = POKE_TOOL_DecodeBoxParam((struct Sav *)r4);
    w[0x40 / 4] = POKEGRA_RegisterCgrPP(r7, (void *)r4, 0, 0, 0x15);
    w[0x44 / 4] = POKEGRA_RegisterPalettePP(r7, (void *)r4, 0, 0, 0x60, 0x15);
    w[0x48 / 4] = POKEGRA_RegisterCellAnimPP(r4, 0, 1, 0, 0x15);
    POKE_TOOL_EncodeBoxParam((struct Sav *)r4, t);
    ARC_TOOL_DeleteHandle(r7);
    buf = gPerapIconActorParam;
    w[0x3c / 4] = (u32)CLACT_CreateActor((void *)w[0x38 / 4], w[0x40 / 4], w[0x44 / 4], w[0x48 / 4], &buf, 0, 0x15);
}
