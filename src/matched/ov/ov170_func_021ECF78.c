/*
 * function: BOX2_SEQ_CreateHandSlotActors
 * address: 0x021ECF78
 * packet: pkt_ov170_021ECF78
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020275EC has no witness outside this caller.
 * Verified scratch-only with one --thumb, no --region: EXACT, 12 bytes.
 * symbols for blocker: _PokeTypePltOffset 0x0209FCF8 data a1
 * extern const unsigned char _PokeTypePltOffset[];
 * unsigned APP_ICON_GetTypePaletteOffset(unsigned char i) { return _PokeTypePltOffset[i]; }
 * symbols:
 *   d_021EFD34 0x021EFD34 data a4
 *   BOX2_SEQ_CreateActorFromDesc 0x021EBEE0 thumb ov170
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 */
typedef struct { short x, y; unsigned char pad4[2], b6, b7; int a, b, c; unsigned short e, d; } Desc;
extern const Desc d_021EFD34;
extern void *BOX2_SEQ_CreateActorFromDesc(char *, const Desc *);
typedef unsigned char  u8;
extern u8 APP_ICON_GetTypePaletteOffset(int i);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
void BOX2_SEQ_CreateHandSlotActors(char *p)
{
    Desc d = d_021EFD34;
    unsigned i;
    for (i = 0; i < 0x11; i++) {
        d.a = i + 0x28;
        *(void **)(p + i * 4 + 0x9EE4) = BOX2_SEQ_CreateActorFromDesc(p, &d);
        CLACT_SetActorPaletteOffset(*(void **)(p + i * 4 + 0x9EE4), (unsigned)APP_ICON_GetTypePaletteOffset((unsigned char)i), 1);
        BOX2_SEQ_SetActorDrawEnable(p, i + 0x1C, 0);
    }
}
