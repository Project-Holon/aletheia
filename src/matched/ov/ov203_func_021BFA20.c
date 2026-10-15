/*
 * function: DEMO3D_EXP_C_CRUISER_Create
 * address: 0x021BFA20
 * packet: pkt_ov203_021BFA20
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * note: 2026-10-05 wave P13 lane B1: closed from the 6 B DIFF draft (movs r7,#0 sat after movs r1,#0x14 instead of before str r1,[sp,#0x1c]). The store `config.f4 = 0;` moves to between f10 and f14; the other constant stores keep the listing order. 4 compiles. Callee shapes follow the matched ov203 siblings (021BF9D0, 021BDF30, 021BE620, 021BFAE4). The d_021C3BD2 pool word is the .y field of d_021C3BD0 (struct Vec2 array), folded by the compiler. The volatile read at 021BFA50 rereads the byte just stored at 021BFA4E, the same form as matched sibling 021BFAE4 (volatile: 021BFB12). No constant locals. EXACT in c99 and c.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   DEMO3D_EXP_C_CRUISER_LoadTextures 0x021BF9D0 thumb ov203
 *   func_021BE620 0x021BE620 thumb ov203
 *   func_021BDF30 0x021BDF30 thumb ov203
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021C3D5C 0x021C3D5C data a1
 *   d_021C3BD0 0x021C3BD0 data a2
 */
struct Obj;
struct Vec2 { short x, y; };
typedef struct { int f0, f4, f8, fC; } Out;
typedef struct { int f0; unsigned f4; int f8, fC, f10, f14, f18; unsigned char b1c, b1d, b1e; } In;
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void DEMO3D_EXP_C_CRUISER_LoadTextures(unsigned short);
extern int func_021BE620(char *p);
extern int func_021BDF30(char *p);
extern void UI_SCENE_LoadActorGfx(Out *, In *, int, unsigned short);
extern int UI_SCENE_CreateActor(Out *, int, unsigned char, unsigned char, unsigned char, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned);
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern const char d_021C3D5C[];
extern const struct Vec2 d_021C3BD0[];
void DEMO3D_EXP_C_CRUISER_Create(char *p)
{
    unsigned char *a;
    int resource;
    In config;
    a = func_02030734(*(unsigned short *)p, 24, 1, d_021C3D5C, 0xB3);
    *(unsigned char **)(p + 0x10) = a;
    DEMO3D_EXP_C_CRUISER_LoadTextures(*(unsigned short *)p);
    *a = (func_021BE620(*(void **)(p + 8)) >> 12) / 100;
    if (*(volatile unsigned char *)a >= 54) *a = 53;
    resource = func_021BDF30(*(void **)(p + 4));
    config.f0 = 1;
    config.f8 = 85;
    config.fC = 4;
    config.f10 = 10;
    config.f4 = 0;
    config.f14 = 13;
    config.f18 = 20;
    config.b1c = 0;
    config.b1d = 0;
    config.b1e = 1;
    UI_SCENE_LoadActorGfx((Out *)(a + 4), &config, resource, *(unsigned short *)p);
    *(int *)(a + 0x14) = UI_SCENE_CreateActor((Out *)(a + 4), resource, d_021C3BD0[*a].x, d_021C3BD0[*a].y, 0, *(unsigned short *)p);
    CLACT_SetActorDrawEnable(*(struct Obj **)(a + 0x14), 1);
    CLACT_SetActorAutoAnim(*(struct Obj **)(a + 0x14), 1);
    func_02040588(6, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}
