/*
 * function: func_021B9E50
 * address:  0x021B9E50
 * packet:   pkt_ov099_021B9E50
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[8];
    int f8;
    int fc;
    int f10;
} Obj;

typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

void func_021B9E50(Obj *o, int a, u32 c)
{
    o->f8 = CLACT_RegisterCharacter((void *)c, 0x11, 0, 0, a);
    o->fc = CLACT_RegisterPaletteEx((void *)c, 8, 0, 0x160, 0, 2, a);
    o->f10 = CLACT_RegisterCellAnim((void *)c, 0x14, 0x20, (u16)a);
}
