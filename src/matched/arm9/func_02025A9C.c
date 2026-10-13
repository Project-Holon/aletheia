/*
 * function: BMP_OAM_AcquireModeSlot
 * address:  0x02025A9C
 * packet:   pkt_02025A9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gModeTable     0x0209F87C  data
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_OAM_AcquireModeSlot.c \
 *       --func BMP_OAM_AcquireModeSlot --addr 0x02025A9C --thumb
 *
 * Map the engine's DISPCNT OBJ-mapping bits (mask 0x00300010) to a slot
 * index 0/1/2 and lazily fill that slot through CLACT_RegisterCellAnim with the
 * gModeTable record's two ids (docs/families/bmp_oam.h, section 5).
 *
 * Closed in wave 13.  The two bytes the 2026-09-21 note could not move
 * (`bne default` against `beq merge` at +0x24) are the 0x00200010 arm: it
 * is NOT empty, it sets mode = 0 itself, and it is written FIRST of the
 * four arms.  The body is then cross-jumped onto default's identical
 * `mode = 0`, which is why the image branches to the same address on both
 * sides of the last compare.  With the arm empty the compiler jumps past
 * the zeroing; with `mode = 0` in any other position it lays the arm out
 * separately (55 bytes out).
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u32 field_0;
    u16 field_4;
    u16 field_6;
    u32 field_8;
    u32 slot[3];
};

struct ModeEntry {
    u32 size;
    u32 a;
    u32 b;
};

extern const struct ModeEntry gModeTable[];

typedef signed int     s32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

u32 BMP_OAM_AcquireModeSlot(struct Obj *obj, u32 engine, u32 arg)
{
    volatile u32 *reg;
    u32 mode;

    if (engine == 0) {
        reg = (volatile u32 *)0x04000000;
    } else {
        reg = (volatile u32 *)0x04001000;
    }

    switch (*reg & 0x00300010) {
    case 0x00200010:
        mode = 0;
        break;
    case 0x00100010:
        mode = 1;
        break;
    case 0x00000010:
        mode = 2;
        break;
    default:
        mode = 0;
        break;
    }

    if (obj->slot[mode] != (u32)-1) {
        return mode;
    }

    obj->slot[mode] = (u32)CLACT_RegisterCellAnim((void *)arg, gModeTable[mode].a,
                                         gModeTable[mode].b, obj->field_4);
    return mode;
}

