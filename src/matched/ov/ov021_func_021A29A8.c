/*
 * function: WEATHER_TASK_LoadSpriteResources
 * address:  0x021A29A8
 * packet:   pkt_ov021_021A29A8
 * region:   ov021
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

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    char pad8[8];
    int f10;
} Obj;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fa;
    u16 fc;
} Src;

int CLACT_RegisterCharacter(int a, int b, int c, int d, int e);
int CLACT_RegisterPaletteEx(int a, int b, int c, int d, int e, int f, int g);
typedef signed int     s32;
typedef unsigned int   u32;
s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

void WEATHER_TASK_LoadSpriteResources(Obj *o, Src *s, int heap)
{
    if (s->f2 != 0) {
        o->f2 = CLACT_RegisterCharacter(o->f10, s->f6, 0, 0, heap);
        o->f4 = CLACT_RegisterPaletteEx(o->f10, s->f8, 0, 0, 0, 1, heap);
        o->f6 = CLACT_RegisterCellAnim((void *)o->f10, s->fa, s->fc, heap);
        o->f0 = 1;
    }
}
