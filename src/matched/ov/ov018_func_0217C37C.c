/*
 * function: INTRUDE_FIELD_SpawnSymbolMons
 * address:  0x0217C37C
 * packet:   pkt_ov018_0217C37C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   SYMBOL_MAP_IsHomeCell  0x02166618  thumb  ov010
 *   SYMBOL_MAP_IsPlainCell  0x02166640  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   INTRUDE_FIELD_AddSymbolMonMmdl  0x0217C1D0  thumb  ov018
 *   TPOKE_DATA_Create  0x0202A128  thumb
 *   func_0202A170  0x0202A170  thumb
 *   func_02005728  0x02005728  thumb
 *   INTRUDE_FIELD_gSymbolMonOffsetsHome     0x02183678  data  a4
 *   INTRUDE_FIELD_gSymbolMonOffsetsPlain     0x021835F8  data  a4
 *   INTRUDE_FIELD_gSymbolMonOffsetsOther     0x02183650  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 species : 11;
    u32 move : 10;
    u32 f21 : 2;
    u32 f23 : 6;
    u32 f29 : 3;
} Entry;

typedef struct {
    int f0;
    int f4;
    int f8;
} Ctx;

extern const u8 INTRUDE_FIELD_gSymbolMonOffsetsHome[20][2];
extern const u8 INTRUDE_FIELD_gSymbolMonOffsetsPlain[20][2];
extern const u8 INTRUDE_FIELD_gSymbolMonOffsetsOther[20][2];

extern int SYMBOL_MAP_IsHomeCell(int);
extern int SYMBOL_MAP_IsPlainCell(int);
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_GetGridNowX(void *);
extern int FLDMMDL_GetGridNowZ(void *);
extern int TPOKE_DATA_Create(int);
extern void func_0202A170(int);
extern u32 func_02005728(u32 range);
extern void INTRUDE_FIELD_AddSymbolMonMmdl(Ctx *, Entry *, u16, u16, u16, int);

void INTRUDE_FIELD_SpawnSymbolMons(int a0, int a1, Entry *list, int a3, int kind)
{
    const u8 (*tbl)[2];
    Ctx ctx;
    void *obj;
    u16 cx;
    u16 cy;
    int i;
    int dx;
    int dy;
    int x;
    int y;

    if (SYMBOL_MAP_IsHomeCell(kind))
        tbl = INTRUDE_FIELD_gSymbolMonOffsetsHome;
    else if (SYMBOL_MAP_IsPlainCell(kind))
        tbl = INTRUDE_FIELD_gSymbolMonOffsetsPlain;
    else
        tbl = INTRUDE_FIELD_gSymbolMonOffsetsOther;

    ctx.f0 = TPOKE_DATA_Create(FIELDMAP_GetHeapId((u8 *)a0));
    ctx.f4 = a0;
    ctx.f8 = a1;
    obj = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)a0));
    cx = FLDMMDL_GetGridNowX(obj);
    cy = FLDMMDL_GetGridNowZ(obj);

    for (i = 0; i < 20; i++) {
        if (list[i].species != 0) {
            dx = func_02005728(2) - 1;
            dy = func_02005728(2) - 1;
            x = dx + tbl[i][0];
            y = dy + tbl[i][1];
            if (cx == x && cy == y) {
                if (dx != 0)
                    x -= dx;
                else if (dy != 0)
                    y -= dy;
                else
                    x++;
            }
            INTRUDE_FIELD_AddSymbolMonMmdl(&ctx, &list[i], i, x, y, 0);
        }
    }
    func_0202A170(ctx.f0);
}
