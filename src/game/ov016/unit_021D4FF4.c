/*
 * file:     unit_021D4FF4.c
 * unit:     yes
 * function: func_021D4FF4, func_021D5098, func_021D5118, func_021D51F0, func_021D5250
 * address:  0x021D4FF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef struct {
    u32 attr01;
    u32 attr23;
} OamAttr_021D4FF4;

typedef struct {
    int pad0;
    int pad4;
    OamAttr_021D4FF4 *oam;
    u8 num;
} CellInfo_021D4FF4;

typedef unsigned short u16;

typedef struct {
    u32 word;
    u16 half;
    u16 pad;
} Slot;

typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct { int pad0; int pad4; GXOamAttr *oam; u8 num; } CellInfo_021D5118;

typedef struct {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 pad;
} OamAttr_021D51F0;

typedef struct {
    int pad0;
    int pad4;
    OamAttr_021D51F0 *oam;
    u8 num;
} CellInfo_021D51F0;

typedef struct {
    u32 attr01;
    u32 attr23;
} OamAttr_021D5250;

typedef struct {
    int pad0;
    int pad4;
    OamAttr_021D5250 *oam;
} CellInfo_021D5250;

void func_021D4FF4(void *cell, int idx, int effect, int affine);
void func_021D5098(u8 *obj, int idx, u32 v, u32 w);
void func_021D5118(void *cell, int idx, int x, int y);
void func_021D51F0(void *cell, int idx, int priority);
void func_021D5250(void *cell, int idx, int *x, int *y);


void func_021D4FF4(void *cell, int idx, int effect, int affine)
{
    CellInfo_021D4FF4 *c = (CellInfo_021D4FF4 *)cell;
    OamAttr_021D4FF4 *oam = c->oam;
    int i;

    if (idx >= 0) {
        if (effect != 0x100 && effect != 0x300)
            { oam[idx].attr01 &= 0xC1FFFCFF; oam[idx].attr01 |= effect; }
        else
            { oam[idx].attr01 &= 0xC1FFFCFF; oam[idx].attr01 |= effect; oam[idx].attr01 |= (u32)affine << 25; }
    } else {
        for (i = 0; i < c->num; i++) {
            if (effect != 0x100 && effect != 0x300)
                { oam[i].attr01 &= 0xC1FFFCFF; oam[i].attr01 |= effect; }
            else
                { oam[i].attr01 &= 0xC1FFFCFF; oam[i].attr01 |= effect; oam[i].attr01 |= (u32)affine << 25; }
        }
    }
}


void func_021D5098(u8 *obj, int idx, u32 v, u32 w)
{
    Slot *arr = *(Slot **)(obj + 8);

    if (idx >= 0) {
        arr[idx].word = (arr[idx].word & ~0xC00u) | (v << 10);
        arr[idx].half = (arr[idx].half & ~0xF000u) | (w << 12);
    } else {
        int i = 0;
        while (i < *(u8 *)(obj + 0xC)) {
            arr[i].word = (arr[i].word & ~0xC00u) | (v << 10);
            arr[i].half = (arr[i].half & ~0xF000u) | (w << 12);
            i++;
        }
    }
}


static inline void G2_GetOBJPosition(const GXOamAttr *oam, unsigned long *x, unsigned long *y)
{
    *x = (oam->attr01 & 0x01FF0000) >> 16;
    *y = (oam->attr01 & 0x000000FF) >> 0;
}


static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}


/*
 * sdk:      DWCi_CELLlSetPosition (libdwcutil.TWL.HYB.a(cell.o))
 */
void func_021D5118(void *cell, int idx, int x, int y)
{
    CellInfo_021D5118 *c = (CellInfo_021D5118 *)cell;
    GXOamAttr *oam;
    int i;
    int x0, y0, x1, y1, dx, dy;

    oam = c->oam;
    if (idx >= 0) {
        G2_SetOBJPosition(&oam[idx], x, y);
    } else {
        G2_GetOBJPosition(&oam[0], (unsigned long *)&x0, (unsigned long *)&y0);
        G2_SetOBJPosition(&oam[0], x, y);
        dx = x - x0;
        dy = y - y0;
        for (i = 1; i < c->num; i++) {
            G2_GetOBJPosition(&oam[i], (unsigned long *)&x1, (unsigned long *)&y1);
            G2_SetOBJPosition(&oam[i], x1 + dx, y1 + dy);
        }
    }
}


/*
 * sdk:      DWCi_CELLlSetPriority (libdwcutil.TWL.HYB.a(cell.o))
 */
void func_021D51F0(void *cell, int idx, int priority)
{
    CellInfo_021D51F0 *c = (CellInfo_021D51F0 *)cell;
    OamAttr_021D51F0 *oam = c->oam;
    int i;

    if (idx >= 0) {
        oam[idx].attr2 = (oam[idx].attr2 & ~0xC00) | (priority << 10);
    } else {
        for (i = 0; i < c->num; i++)
            oam[i].attr2 = (oam[i].attr2 & ~0xC00) | (priority << 10);
    }
}


/*
 * sdk:      DWCi_CELLlGetPosition (libdwcutil.TWL.HYB.a(cell.o))
 */
void func_021D5250(void *cell, int idx, int *x, int *y)
{
    OamAttr_021D5250 *oam = ((CellInfo_021D5250 *)cell)->oam;
    *x = (oam[idx].attr01 & 0x01ff0000) >> 16;
    *y = oam[idx].attr01 & 0xff;
}
