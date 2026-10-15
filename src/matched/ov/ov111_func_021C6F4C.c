/*
 * function: VIEWER_TEXT_DeleteActors
 * address:  0x021C6F4C
 * packet:   pkt_ov111_021C6F4C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} ResSet;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0xB8 - 8];
    ResSet res[2];
} Anim;

extern void CLACT_ReleasePalette(u32 r);
extern void CLACT_ReleaseCharacter(u32 r);
extern void CLACT_ReleaseCellAnim(u32 r);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);

void VIEWER_TEXT_DeleteActors(Anim *a)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        CLACT_ReleasePalette(a->res[i].a);
        CLACT_ReleaseCharacter(a->res[i].b);
        CLACT_ReleaseCellAnim(a->res[i].c);
    }
    CLACT_DeleteUnit((struct Bank *)a->f4);
    CLACT_ExitSystem();
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x300010) | 0x10;
}
