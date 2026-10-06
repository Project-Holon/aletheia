/*
 * file:     net_state_p09.c
 * unit:     yes
 * function: func_02036B4C, func_02036B88, func_02036B98, func_02036BD4, func_02036CA8, func_02036D64, func_02036DC8, func_02036E74
 * address:  0x02036B4C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   func_02036F24   0x02036F24  arm
 *   wm_icon_File    0x020A79F0  data
 *   g_021469C8      0x021469C8  data
 *   str_020A79F0  0x020A79F0  data
 *   str_020A79FC  0x020A79FC  data
 *   GX_GetBankForOBJ     0x02080C24  arm
 *   GX_GetBankForSubOBJ  0x02080C64  arm
 *   func_02034714        0x02034714  arm
 */
#include "../../matched/include/Obj04065.h"
#include "../../matched/include/Obj15906.h"
#include "../../matched/include/Obj11350.h"
#include "../../matched/include/Obj15907.h"

typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

struct Handler {
    u32 unk00;      /* 0x00 */
    u16 unk04;      /* 0x04 */
    u16 unk06;      /* 0x06 */
    u8  pad08[4];   /* 0x08 */
    u8  unk0c;      /* 0x0c */
    u8  kind;       /* 0x0d */
    u8  busy;       /* 0x0e */
    u8  unk0f;      /* 0x0f */
    u32 unk10;      /* 0x10 */
};

struct Notifier {
    u16 unk00;                /* 0x00 */
    u16 unk02 : 14;           /* 0x02, bits 0-13 */
    u16 mode  : 2;            /* 0x02, bits 14-15 */
    struct Handler *handler;  /* 0x04 */
};

typedef int BOOL;

typedef struct {
    union {
        u32 attr01;
        struct { u16 attr0; u16 attr1; };
    };
    u16 attr2;
    u16 _3;
} GXOamAttr;

struct Icon {
    u32 f00;
    u16 f04;
    u16 f06;
    u8  pad08[7];
    u8  f0f;
    GXOamAttr *f10;
};

typedef volatile unsigned int vu32;

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02036F24(int a0, int b, int c);
extern u32  GX_GetBankForOBJ(void);
extern u32  GX_GetBankForSubOBJ(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
u32 func_02036D64(u8 *p);
u32 func_02036DC8(u32 engine, u32 b);
int *func_02036E74(int *p, int v);
int func_02036B4C(int a0);
void func_02036B88(void *a0);
int func_02036B98(char *p, int v);
extern struct Notifier g_021469C8;
extern const char wm_icon_File[];
extern const char str_020A79F0[];
extern const char str_020A79FC[];



int func_02036B4C(int a0){ int t0; t0 = func_02082BCC((int)((struct Obj04065 *)((char *)(a0)))->f18, (int)0, (int)(((struct Obj04065 *)((char *)(a0)))->f1C * 0x14)); ((struct Obj04065 *)((char *)(a0)))->f0 = (int)0; ((struct Obj04065 *)((char *)(a0)))->f4 = (int)0; ((struct Obj04065 *)((char *)(a0)))->f8 = (int)0; ((struct Obj04065 *)((char *)(a0)))->fC = (int)0; ((struct Obj04065 *)((char *)(a0)))->f10 = (int)0; return t0; }


void func_02036B88(void *a0){ func_020307B0((void *)((int)((struct Obj15906 *)((char *)(a0)))->f18)); }



/*
 * Scan the 0x14-stride records behind p's +0x18 pointer for one whose
 * halfword at +0x0E equals the argument; the count is p's word at +0x1C.  A
 * hit returns 1 from inside the loop (`moveq r0, #1` / `bxeq lr`), a miss
 * falls out to `mov r0, #0`.
 *
 * The three scratch registers are decided by declaration order alone: the
 * index declared first takes r2, the record cursor declared second takes r3
 * and the count declared last takes ip.  Any other order of the same three
 * declarations moves the count into r2 or the cursor into ip and misses by
 * seven instructions' worth of register names.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036B98.c \
 *       --func func_02036B98 --addr 0x02036B98 --cc 1.1p1 --arm
 */
int func_02036B98(char *p, int v)
{
    int   i;
    char *e = *(char * *)&((struct Obj11350 *)p)->f18;
    int   n = ((struct Obj11350 *)p)->f1C;

    for (i = 0; i < n; i++, e += 0x14) {
        if (((struct Obj15907 *)e)->fE == v)
            return 1;
    }
    return 0;
}



/*
 * TU: wm_icon.c.  The __FILE__ pointer at 0x020A79F0 reads "wm_icon.c"
 * (line 100 here), which names the whole 0x020366C0-0x020371AC block: the
 * wireless-connection icon.
 *
 * Nine parameters, four in registers and five on the stack, and the first
 * one is never read: every caller passes 0 there.  When the caller hands in
 * a null block, a fresh 0x14-byte one is allocated on the heap named by the
 * low 15 bits of the second argument with bit 15 forced on.  The two
 * halfwords at +0x04 / +0x06 take the caller's values unless the override
 * pair in the global at 0x021469C8 is armed, in which case the whole `if`
 * body is predicated rather than branched.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036BD4.c \
 *       --func func_02036BD4 --addr 0x02036BD4 --cc 1.1p1 --arm
 */
struct Handler *func_02036BD4(u32 unused, u32 b, u32 c, u32 d, u32 e,
                              struct Handler *h, u32 kind, u32 busy,
                              u32 unk00)
{
    if (h == 0)
        h = func_02030734((u16)(((u16)b & 0x7fff) | 0x8000), 0x14, 0,
                          wm_icon_File, 100);

    h->unk04 = c;
    h->unk06 = d;

    if (g_021469C8.unk00 != 0) {
        h->unk04 = g_021469C8.unk00;
        h->unk06 = g_021469C8.unk02;
    }

    h->unk00 = unk00;
    h->unk0c = e;
    h->busy  = busy;
    h->kind  = kind;
    h->unk0f = 0;
    h->unk10 = 0x7000000;

    func_02036F24(func_02036D64((u8 *)h), h->unk0c, (u16)b);
    return h;
}


static inline void G2_SetOBJAttr(GXOamAttr *oam, int x, int y, int priority,
                                 int mode, BOOL mosaic, int effect, int shape,
                                 int color, int charName, int cParam, int rsParam)
{
    oam->attr01 = (u32)(((y & 0xff) << 0) |
                        (mode << 10) |
                        (mosaic << 12) |
                        effect |
                        (color << 13) |
                        shape |
                        ((x & 0x1ff) << 16) |
                        (rsParam << 25));
    oam->attr2 = (u16)((charName << 0) | (priority << 10) | (cParam << 12));
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036CA8.c  *       --func func_02036CA8 --addr 0x02036CA8 --cc 1.1p1 --arm
 *
 * wm_icon.c: write the wireless icon's two 16x16 OAM entries into main
 * (0x07000000) or sub (0x07000400) OAM, and hide the pair at the previous
 * location when the engine changed.  Every store is the NitroSDK
 * G2_SetOBJAttr inline (attr01 = y | mode<<10 | mosaic<<12 | effect |
 * color<<13 | shape | x<<16 | rs<<25, attr2 = name | prio<<10 | cparam<<12):
 * entry 0 is an OBJ-window sprite (mode 2) or a NODISPLAY blank (effect
 * 0x200), entry 1 the normal sprite, palette 14.  Written through the
 * inline, the shift scheduling of docs/notes/pkt_02036CA8.c.txt (31 bytes,
 * hand-expanded) disappears.
 */
void func_02036CA8(struct Icon *c)
{
    u32 mode;
    u32 name;
    GXOamAttr *oam;

    mode = func_02036D64((u8 *)c);
    name = func_02036DC8(mode, c->f00);
    if (mode == 1) {
        oam = (GXOamAttr *)0x07000000;
    } else {
        oam = (GXOamAttr *)0x07000400;
    }
    if (c->f0f == 1) {
        G2_SetOBJAttr(&oam[0], c->f04, c->f06, 0, 2, 0, 0, 0x40000000, 0, name, 14, 0);
    } else {
        G2_SetOBJAttr(&oam[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
    }
    G2_SetOBJAttr(&oam[1], c->f04, c->f06, 0, 0, 0, 0, 0x40000000, 0, name, 14, 0);
    if (oam != c->f10) {
        G2_SetOBJAttr(&c->f10[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        G2_SetOBJAttr(&c->f10[1], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        c->f10 = oam;
    }
}


u32 func_02036D64(u8 *p)
{
    switch (p[0xd]) {
    case 1:
        return ((*(u16 *)0x04000304 & 0x8000) >> 15) == 1 ? 1 : 2;
    case 2:
        return ((*(u16 *)0x04000304 & 0x8000) >> 15) == 1 ? 2 : 1;
    }
    return 1;
}


/*
 * Maps the display control word of the requested engine onto the icon
 * render scale: the OBJ bank bits (20-21) and the OBJ-character mapping
 * bit (4) together pick 4x, 2x or 1x, and anything else is a fatal
 * configuration error.  The mask 0x00300010 is shared by both arms, so
 * the compiler hoists it out of the if and the DISPCNT read happens
 * inside; the switch then binary-searches the three sparse case values
 * with 0x00100010 as the middle.
 *
 * Wave 14: the balanced tree needs a FOURTH case label.  The switch is
 * over the SDK's GXOBJVRamModeChar values (1D_32K 0x10, 1D_64K 0x00100010,
 * 1D_128K 0x00200010, 1D_256K 0x00300010); 256K shares the default's
 * fatal arm, and with four labels mwcc switches from a linear chain to the
 * binary search the image has (docs/notes/pkt_02036DC8.c.txt measured
 * three labels only).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036DC8.c  *       --func func_02036DC8 --addr 0x02036DC8 --cc 1.1p1 --arm
 */
u32 func_02036DC8(u32 engine, u32 b)
{
    int m;

    if (engine == 1) {
        GX_GetBankForOBJ();
        m = *(vu32 *)0x04000000 & 0x00300010;
    } else {
        GX_GetBankForSubOBJ();
        m = *(vu32 *)0x04001000 & 0x00300010;
    }

    switch (m) {
    case 0x10:
        return b * 4;
    case 0x00100010:
        return b * 2;
    case 0x00200010:
        return b;
    case 0x00300010:
    default:
        func_02034714(str_020A79F0, 0xfb, str_020A79FC);
        return b;
    }
}

int *func_02036E74(int *p, int v){ if (v < 4) *p = v;  return p; }
