/*
 * function: ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics
 * address:  0x021C2FEC
 * packet:   pkt_ov208_021C2FEC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 v);
extern void CLACT_ReleaseCharacter(u32 v);
extern void CLACT_ReleaseCellAnim(u32 v);

struct S {
    u8 pad[0x3c];
    u32 a3c[2];
    u32 a44[2];
    u32 a4c[2];
    u32 a54[2];
};

void ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(void *unused, struct S *p, u32 unused2, u32 i)
{
    if (p->a54[i] != 0) {
        CLACT_DeleteActor((struct Obj *)p->a54[i]);
        p->a54[i] = 0;
        CLACT_ReleasePalette(p->a3c[i]);
        CLACT_ReleaseCharacter(p->a44[i]);
        CLACT_ReleaseCellAnim(p->a4c[i]);
    }
}
