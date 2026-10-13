/*
 * file:     fldmmdl_move.c
 * unit:     yes
 * function: func_02163010, func_02163028, func_02163090, func_021630F4, func_0216310C, func_02163130, func_02163154, func_02163188, func_021631C0, func_02163230, func_02163288, func_021632F0, func_02163340, func_021633A8, func_02163418, func_02163464, func_021634D8, func_021634FC, func_0216352C, func_0216355C, func_02163580, func_02163618, func_02163650, func_0216369C, func_021636A8, func_021636C8, func_021636F0, func_0216372C, func_0216375C, func_0216377C, func_021637B0, func_021637E4, func_02163868, func_021638AC, func_021638C8, func_021638CC, func_02163994, func_021639C0, func_02163A08, func_02163A40, func_02163AF0, func_02163BAC, func_02163C04, func_02163C9C, func_02163D04, func_02163E1C, func_02163E34, func_02163E58, func_02163E7C, func_02163F10, func_02163F40, func_02163F8C, func_02163FC0, func_02164010, func_021640B0, func_02164168, func_021641C8, func_021641E8, func_021641F8, func_02164208, func_02164240, func_02164280, func_02164294, func_021642A4, func_021642B4, func_021642D4, func_021642F8, func_02164304, func_0216435C, func_02164380
 * address:  0x02163010
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Field model movement, attribute effects and hit checks (guess: fldmmdl move code).
 *
 * symbols:
 *   func_0201441C 0x0201441C thumb
 *   func_0216D6F4  0x0216D6F4  thumb  ov010
 *   func_0219B414  0x0219B414  thumb  ov021
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216DA20  0x0216DA20  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0219B41C  0x0219B41C  thumb  ov021
 *   func_0216D708  0x0216D708  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D564  0x0216D564  thumb  ov010
 *   func_0216DB68  0x0216DB68  thumb  ov010
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_0216DA70 0x0216DA70 thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 *   func_02082C60  0x02082C60  arm
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0216DC00 0x0216DC00 thumb ov010
 *   func_021AB41C 0x021AB41C thumb ov021
 *   func_0216D900 0x0216D900 thumb ov010
 *   d_021714D0 0x021714D0 data ov010 a4
 *   func_021AB4EC  0x021AB4EC  thumb
 *   func_021AB4F8  0x021AB4F8  thumb
 *   func_021AB434  0x021AB434  thumb
 *   func_021AB428  0x021AB428  thumb
 *   func_021AB250  0x021AB250  thumb
 *   func_021AB264  0x021AB264  thumb
 *   func_021AB270  0x021AB270  thumb
 *   func_021AC760  0x021AC760  thumb
 *   func_0216D608 0x0216D608 thumb ov010
 *   func_021AB3D4  0x021AB3D4  thumb
 *   func_021AB3E0  0x021AB3E0  thumb
 *   func_021AB334  0x021AB334  thumb
 *   func_021AB328  0x021AB328  thumb
 *   func_021BBDD4  0x021BBDD4  thumb
 *   func_021AB304  0x021AB304  thumb
 *   func_0216DBE8  0x0216DBE8  thumb  ov010
 *   func_021C4BE0  0x021C4BE0  thumb
 *   func_0216DBCC  0x0216DBCC  thumb  ov010
 *   func_021AB364  0x021AB364  thumb
 *   func_021C4A10  0x021C4A10  thumb
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_021AC2C0  0x021AC2C0  thumb
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216DD04 0x0216DD04 thumb ov010
 *   func_021AC528 0x021AC528 thumb ov021
 *   func_021AB2F8  0x021AB2F8  thumb
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_021C484C  0x021C484C  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_021AB440  0x021AB440  thumb  ov021
 *   func_021AB358  0x021AB358  thumb  ov021
 *   func_021BBFB8  0x021BBFB8  thumb  ov021
 *   func_021AB3EC  0x021AB3EC  thumb
 *   func_021C8F7C  0x021C8F7C  thumb  ov021
 *   func_0216D52C  0x0216D52C  thumb  ov010
 *   func_0218DC04  0x0218DC04  thumb  ov021
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D91C 0x0216D91C thumb ov010
 *   func_0216D924 0x0216D924 thumb ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D810  0x0216D810  thumb  ov010
 *   func_0216DD1C  0x0216DD1C  thumb
 *   func_0216D7E8  0x0216D7E8  thumb
 *   func_0216D660  0x0216D660  thumb
 *   func_0216D7F8  0x0216D7F8  thumb
 *   func_0216D66C  0x0216D66C  thumb
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021714A0     0x021714A0  data
 *   d_02171490     0x02171490  data
 *   func_0218DAEC 0x0218DAEC thumb ov021
 *   func_0216D80C  0x0216D80C  thumb
 *   func_0216D818  0x0216D818  thumb
 *   func_0216D824  0x0216D824  thumb
 *   func_0216D848  0x0216D848  thumb
 *   func_0216D87C  0x0216D87C  thumb
 *   func_0216D85C  0x0216D85C  thumb
 *   func_0216D89C 0x0216D89C thumb ov010
 *   func_0216D7E0  0x0216D7E0  thumb
 *   func_0216D7D8  0x0216D7D8  thumb
 *   func_0216DEE0  0x0216DEE0  thumb
 *   d_02171480 0x02171480 data a4
 *   d_02171470 0x02171470 data a4
 *   d_021714B0     0x021714B0  data  a4
 *   d_02171458     0x02171458  data  a2
 *   d_02171460     0x02171460  data
 *   d_021714C0     0x021714C0  data  a4
 *   func_0216D4D4  0x0216D4D4  thumb
 *   func_0219E2C0  0x0219E2C0  thumb
 *   func_0216D684  0x0216D684  thumb
 *   func_0216D69C 0x0216D69C thumb ov010
 */

struct MapGrid;

#include "../ov021/fldmmdl_rail_types.h"
#include "fldmmdl_types.h"

typedef unsigned int u32;

typedef int s32;

/* Grid place of a bg event: one cell, height within 2. */
typedef struct BgEventGridPos {
    s32 x;              /* 0x08 */
    s32 z;              /* 0x0C */
    s32 y;              /* 0x10 */
} BgEventGridPos;

/* Rail place of a bg event. */
typedef struct BgEventRailPos {
    u16 railIndex;      /* 0x08 */
    u16 lineGrid;       /* 0x0A */
    s16 widthGrid;      /* 0x0C */
} BgEventRailPos;

/* A bg event record (sign, hidden item), 0x14 bytes. */
typedef struct BgEventData {
    u16 scriptId;       /* 0x00 */
    u16 type;           /* 0x02: 2 hidden item */
    u16 dir;            /* 0x04: which talk directions fire it, 0..6 */
    u16 posType;        /* 0x06: 0 grid, 1 rail */
    union {
        s32 word[3];
        BgEventGridPos grid;
        BgEventRailPos rail;
    } pos;              /* 0x08 */
} BgEventData;

/* A stored rail move request: a RailLocation, valid while magic is 0xEFEFEFEF. */
typedef struct RailMoveRequest {
    u32 magic;          /* 0x00 */
    u16 location[4];    /* 0x04: RailLocation as halfwords */
} RailMoveRequest;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

/* Map attributes under a field model and its draw parameters, read once per
 * step check (func_021631C0). An attribute is a u32: value in the low 16
 * bits, flags in the high 16 bits. */
typedef struct EventInfo {
    int nowAttr;                    /* 0x00 */
    int oldAttr;                    /* 0x04 */
    u16 nowAttrValue;               /* 0x08 */
    u16 oldAttrValue;               /* 0x0A */
    u16 nowAttrFlag;                /* 0x0C */
    u16 oldAttrFlag;                /* 0x0E */
    MmdlObjCodeParam *objCodeParam; /* 0x10 */
    int effectCtrl;                 /* 0x14 */
    u8 effectMode;                  /* 0x18: 0 and 3 checked */
} EventInfo;

typedef struct { s16 x0, y0, x1, y1; } Rect;

typedef int (*AttrTest)(u16 attr);

/* Map attribute and height under a position (func_0218DAEC). */
typedef struct MapAttrInfo {
    u16 reserved[4];    /* 0x00: not read here */
    int attr;           /* 0x08 */
    int height;         /* 0x0C */
} MapAttrInfo;

/* A 4-byte entry of the direction table d_021714C0 (func_021642D4 reads the second byte). */
typedef struct DirLookupEntry {
    u8 entry0;          /* 0x00 */
    u8 dirCode;         /* 0x01 */
    u8 entry2;          /* 0x02 */
    u8 entry3;          /* 0x03 */
} DirLookupEntry;

extern u8 func_0201441C(int m);
extern void func_0216D6F4(Mmdl *mmdl);
extern int func_0219B414(int a);
extern u32 *func_0216D548(Mmdl *mmdl, u32 v);
extern int func_0216DA20(Mmdl *mmdl, unsigned int v);
extern unsigned int func_0216D57C(Mmdl *mmdl, unsigned int v);
extern void func_02197EB4(u32 a);
extern int func_0216DB10(Mmdl *mmdl);
extern int func_0219B41C();
extern void func_0216D708(Mmdl *mmdl);
extern int func_0216DA5C(Mmdl *mmdl);
extern u16 func_0216D5A0(Mmdl *mmdl);
extern u32 func_0216D564(Mmdl *mmdl);
extern int func_0216DB68(Mmdl *mmdl);
extern int func_0216DCB4(Mmdl *mmdl);
extern void func_0216DA70(Mmdl *mmdl);
extern void *func_0216D570(Mmdl *mmdl, u32 v);
extern void func_02082C60();
extern u32 func_0216D7E4(Mmdl *mmdl);
extern u32 func_0216D7DC(Mmdl *mmdl);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern void *func_0216E3C4(Mmdl *mmdl);
extern MmdlSys *func_0216D67C(Mmdl *mmdl);
extern u32 func_0216D534(MmdlSys *mmdlSys);
extern u32 func_02188CD0(u8 *p);
extern u8 func_021ABE28(u8 *p);
extern int func_0216DB24(Mmdl *mmdl);
extern int func_0216DC00(Mmdl *mmdl);
extern int func_021AB41C(unsigned short);
extern void func_0216D900(int, const VecFx32 *);
extern int func_021AB4EC();
extern int func_021AB4F8();
extern int func_021AB434();
extern int func_021AB428();
extern int func_021AB250();
extern int func_021AB264();
extern int func_021AB270();
extern int func_021AC760();
extern u16 func_0216D608(Mmdl *mmdl);
extern int func_021AB3D4();
extern int func_021AB3E0();
extern int func_021AB334();
extern int func_021AB328();
extern int func_021BBDD4();
extern int func_021AB304();
extern int func_0216DBE8(Mmdl *mmdl);
extern int func_021C4BE0();
extern int func_0216DBCC();
extern int func_021AB364();
extern int func_021C4A10();
extern int func_0216D98C(MmdlSys *mmdlSys);
extern int func_021AC2C0(void *p, int h);
extern void *func_0216D568(Mmdl *mmdl, u32 v);
extern int func_0216DD04(Mmdl *mmdl);
extern void func_021AC528(u32 a, u32 b);
extern int func_021AB2F8(u16 id);
extern int func_0216D804(Mmdl *mmdl);
extern int func_0216D81C(Mmdl *mmdl);
extern u32 func_0216D8AC(Mmdl *mmdl);
extern int func_021C484C(int h, int x, int y, int z);
extern int func_0216D83C(Mmdl *mmdl);
extern int func_0216D86C(Mmdl *mmdl);
extern int func_0216DC34(Mmdl *mmdl);
extern int func_0216DC18(Mmdl *mmdl, int a1);
extern int func_021AB440();
extern int func_021AB358(int x);
extern void func_021BBFB8(u32 a, u32 b, u32 c, u32 d);
extern int func_021AB3EC(u16 id);
extern int func_021C8F7C(void *p, int h);
extern struct MapGrid *func_0216D52C(MmdlSys *mmdlSys);
extern int func_0218DC04(struct MapGrid *grid, VecFx32 *pos);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern s16 func_0216D854(Mmdl *mmdl);
extern u8 func_0216D91C(Mmdl *mmdl);
extern u8 func_0216D924(Mmdl *mmdl);
extern int func_0216D55C(Mmdl *mmdl, int a1);
extern int func_0216D810(Mmdl *mmdl);
extern int func_0216DD1C(MmdlSys *mmdlSys, Mmdl **out, u32 *iter);
extern int func_0216D7E8(Mmdl *mmdl);
extern int func_0216D660(Mmdl *mmdl);
extern int func_0216D7F8(Mmdl *mmdl);
extern int func_0216D66C(Mmdl *mmdl);
extern int func_021AB11C(u32 attr);
extern int func_0218DAEC(struct MapGrid *grid, VecFx32 *pos, MapAttrInfo *info);
extern int func_0216D80C(Mmdl *mmdl, int b);
extern int func_0216D818(Mmdl *mmdl, int b);
extern int func_0216D824(Mmdl *mmdl, int b);
extern void func_0216D848(Mmdl *mmdl, int b);
extern void func_0216D87C(Mmdl *mmdl, int b);
extern void func_0216D85C(Mmdl *mmdl, int v);
extern void func_0216D89C(Mmdl *mmdl, const VecFx32 *pos);
extern void func_0216D7E0(Mmdl *mmdl, u32 v);
extern void func_0216D7D8(Mmdl *mmdl, u32 v);
extern Mmdl *func_0216DEE0(MmdlSys *mmdlSys);
extern int func_0216D4D4(MmdlSys *mmdlSys, int bit);
extern void func_0219E2C0(int a, RailLocation *location);
extern void func_0216D684(Mmdl *mmdl, int b);
extern void *func_0216D69C(Mmdl *mmdl);
u32 *func_02163010(Mmdl *mmdl);
void func_02163028(Mmdl *mmdl);
int func_02163090(Mmdl *mmdl);
int func_021630F4(Mmdl *mmdl);
void func_0216310C(Mmdl *mmdl);
void func_02163130(Mmdl *mmdl);
void func_02163154(Mmdl *mmdl);
void func_02163188(Mmdl *mmdl);
void func_021631C0(Mmdl *mmdl, EventInfo *info);
void func_02163230(Mmdl *mmdl);
void func_02163288(Mmdl *mmdl);
void func_021632F0(Mmdl *mmdl);
void func_02163340(Mmdl *mmdl);
void func_021633A8(Mmdl *mmdl);
void func_02163418(Mmdl *mmdl, EventInfo *info);
int func_02163464(u16 attrValue, u8 effectMode);
void func_021634D8(Mmdl *mmdl, EventInfo *info);
void func_021634FC(Mmdl *mmdl, EventInfo *info);
void func_0216352C(Mmdl *mmdl, EventInfo *info);
void func_0216355C(Mmdl *mmdl, EventInfo *info);
void func_02163580(Mmdl *mmdl, EventInfo *info);
int func_02163618(Mmdl *mmdl, EventInfo *info);
int func_02163650(Mmdl *mmdl, EventInfo *info);
void func_0216369C(Mmdl *mmdl, EventInfo *info);
int func_021636A8(Mmdl *mmdl, EventInfo *info);
int func_021636C8(EventInfo *info);
void func_021636F0(Mmdl *mmdl, EventInfo *info);
void func_0216372C(Mmdl *mmdl, EventInfo *info);
void func_0216375C(Mmdl *mmdl, EventInfo *info);
void func_0216377C(Mmdl *mmdl, EventInfo *info);
void func_021637B0(Mmdl *mmdl, EventInfo *info);
void func_021637E4(Mmdl *mmdl, EventInfo *info);
void func_02163868(Mmdl *mmdl, EventInfo *info);
void func_021638AC(Mmdl *mmdl, EventInfo *info);
void func_021638C8(Mmdl *mmdl, EventInfo *info);
u32 func_021638CC(Mmdl *mmdl, VecFx32 *currentPos, s16 gridX, s16 height, int gridZ, u16 kind);
u32 func_02163994(Mmdl *mmdl, s16 gridX, s16 height, int gridZ, u16 kind);
void func_021639C0(Mmdl *mmdl, u16 dir);
void func_02163A08(Mmdl *mmdl, int gridX, int gridZ, Rect *out);
int func_02163A40(Rect *rectA, Rect *rectB);
int func_02163AF0(Mmdl *mmdl, Mmdl *other, int gridX, int height, s16 gridZ, int checkNext);
int func_02163BAC(Mmdl *mmdl, int gridX, int height, s16 gridZ);
int func_02163C04(Mmdl *mmdl, int gridX, int gridZ, int checkNext);
int func_02163C9C(Mmdl *mmdl, int gridX, int gridZ);
int func_02163D04(Mmdl *mmdl, u32 kind, VecFx32 topLeft);
int func_02163E1C(Mmdl *mmdl, VecFx32 *pos, MapAttrInfo *info);
int func_02163E34(Mmdl *mmdl, VecFx32 *pos, u32 *outAttr);
int func_02163E58(Mmdl *mmdl, VecFx32 *pos, int *outHeight);
void func_02163E7C(Mmdl *mmdl, int dir);
void func_02163F10(Mmdl *mmdl);
int func_02163F40(Mmdl *mmdl, int dir);
void func_02163F8C(Mmdl *mmdl, const VecFx32 *delta);
void func_02163FC0(Mmdl *mmdl, int dir, int amount);
int func_02164010(Mmdl *mmdl);
int func_021640B0(Mmdl *mmdl);
int func_02164168(Mmdl *mmdl);
void func_021641C8(Mmdl *mmdl);
int func_021641E8(int dir);
int func_021641F8(int dir);
void func_02164208(int dir, VecFx32 *pos, int amount);
void func_02164240(int dir, s16 *x, s16 *z, s16 amount);
void func_02164280(int gridX, int gridZ, VecFx32 *pos);
void func_02164294(int gridX, int gridY, int gridZ, VecFx32 *pos);
u16 func_021642A4(int index);
u16 func_021642B4(int fromX, int fromZ, int toX, int toZ);
u8 func_021642D4(int tableIndex, int offset);
void func_021642F8(Mmdl *mmdl);
void func_02164304(Mmdl *mmdl, MmdlHeader *header);
void func_0216435C(Mmdl *mmdl, const u16 *locationWords);
int func_02164380(Mmdl *mmdl, u16 *outWords);
extern VecFx32 d_021714D0;
extern const AttrTest d_021714A0[];
extern const AttrTest d_02171490[];
extern const int d_02171480[];
extern const int d_02171470[];
extern u32 d_021714B0[];
extern u16 d_02171458[];
extern u8 d_02171460[];
extern DirLookupEntry d_021714C0[];

/*
 * Unblocked by the recursive MATCH unblocker: the +000A call targets
 * 0x0219B414, a labelless Thumb tail-call thunk in ov021 now matched in
 * src/matched/ov021_func_0219B414.c, so the site attests as `matched`.
 */
u32 *func_02163010(Mmdl *mmdl)
{
    func_0216D6F4(mmdl);
    func_0219B414((int)mmdl);
    return func_0216D548(mmdl, 2);
}

void func_02163028(Mmdl *mmdl)
{
    int mask = 2;

    if (func_0216DA20(mmdl, mask) == 0) {
        func_021630F4(mmdl);
        func_0216310C(mmdl);
        func_02163130(mmdl);
        if (func_0216D57C(mmdl, mask << 8) != 0) {
            func_02197EB4((u32)mmdl);
        } else if (func_0216DB10(mmdl) == 0) {
            if (func_02163090(mmdl) == 1) {
                if (func_0219B41C(mmdl) == 0) {
                    func_0216D708(mmdl);
                }
            }
        }
        func_02163154(mmdl);
        func_02163188(mmdl);
    }
}

int func_02163090(Mmdl *mmdl)
{
    u32 statusBits;

    if (func_0216DA5C(mmdl) == 0) {
        if (func_0216D57C(mmdl, 0x1800) == 0)
            return 1;
        if (func_0216D5A0(mmdl) == 0x32)
            return 1;
        statusBits = func_0216D564(mmdl);
        if ((statusBits & 0x1000) != 0 && func_0216DB68(mmdl) == 0)
            return 0;
        if ((statusBits & 0x800) != 0 && func_0216DCB4(mmdl) == 0)
            return 0;
    }
    return 1;
}

int func_021630F4(Mmdl *mmdl)
{
    u32 hasBit = func_0216D57C(mmdl, 0x1000);

    if (hasBit != 0)
        return func_02164010(mmdl);
    return hasBit;
}

/*
 * trailing: two-byte zero alignment at 0x0216312E before func_02163130.
 */
void func_0216310C(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, 0x800) != 0 && func_021640B0(mmdl) == 1)
        func_0216DA70(mmdl);
}

void func_02163130(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, 0x20)) {
        func_021641C8(mmdl);
        func_02163230(mmdl);
    }
    func_0216D570(mmdl, 0xa0);
}

/*
 * trailing: two-byte zero alignment at 0x02163186 before func_02163188.
 */
void func_02163154(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, 0x80)) func_021632F0(mmdl);
    else if (func_0216D57C(mmdl, 0x20)) func_02163288(mmdl);
    func_0216D570(mmdl, 0xa0);
}

/*
 * trailing: two-byte zero alignment at 0x021631BE before func_021631C0.
 */
void func_02163188(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, 0x100)) func_021633A8(mmdl);
    else if (func_0216D57C(mmdl, 0x40)) func_02163340(mmdl);
    func_0216D570(mmdl, 0x140);
}

void func_021631C0(Mmdl *mmdl, EventInfo *info)
{
    int oldAttr;
    u32 effectCtrl;

    func_02082C60(info, 0, 0x1c);
    info->nowAttr = func_0216D7E4(mmdl);
    oldAttr = func_0216D7DC(mmdl);
    info->oldAttr = oldAttr;
    if (oldAttr != -1) {
        info->oldAttrValue = func_021AB0F0(oldAttr);
        info->oldAttrFlag = func_021AB0F8(info->oldAttr);
    }
    if (info->nowAttr != -1) {
        info->nowAttrValue = func_021AB0F0(info->nowAttr);
        info->nowAttrFlag = func_021AB0F8(info->nowAttr);
    }
    info->objCodeParam = func_0216E3C4(mmdl);
    effectCtrl = func_02188CD0((u8 *)func_0216D534(func_0216D67C(mmdl)));
    info->effectCtrl = effectCtrl;
    info->effectMode = func_021ABE28((u8 *)effectCtrl);
}

void func_02163230(Mmdl *mmdl)
{
    EventInfo info;

    func_021640B0(mmdl);
    if (func_0216D57C(mmdl, 0x800) == 0 && func_0216DB24(mmdl) == 1) {
        func_021631C0(mmdl, &info);
        func_021634D8(mmdl, &info);
        func_02163618(mmdl, &info);
        func_021636F0(mmdl, &info);
        func_02163418(mmdl, &info);
        func_021637E4(mmdl, &info);
    }
}

void func_02163288(Mmdl *mmdl)
{
    EventInfo info;

    func_021640B0(mmdl);
    if (func_0216D57C(mmdl, 0x800) == 0 && func_0216DB24(mmdl) == 1) {
        func_021631C0(mmdl, &info);
        func_021634FC(mmdl, &info);
        func_02163580(mmdl, &info);
        func_02163650(mmdl, &info);
        func_021636F0(mmdl, &info);
        func_0216377C(mmdl, &info);
        func_021637E4(mmdl, &info);
        func_021638C8(mmdl, &info);
    }
}

void func_021632F0(Mmdl *mmdl)
{
    EventInfo info;

    func_021640B0(mmdl);
    if (func_0216D57C(mmdl, 0x800) == 0 && func_0216DB24(mmdl) == 1) {
        func_021631C0(mmdl, &info);
        func_021636F0(mmdl, &info);
        func_021637E4(mmdl, &info);
        func_0216369C(mmdl, &info);
        func_021638C8(mmdl, &info);
    }
}

void func_02163340(Mmdl *mmdl)
{
    EventInfo info;

    func_021640B0(mmdl);
    if (func_0216D57C(mmdl, 0x800) == 0 && func_0216DB24(mmdl) == 1) {
        func_021631C0(mmdl, &info);
        func_02163418(mmdl, &info);
        func_0216352C(mmdl, &info);
        func_021637B0(mmdl, &info);
        func_02163650(mmdl, &info);
        func_02163868(mmdl, &info);
        func_0216372C(mmdl, &info);
        func_021638AC(mmdl, &info);
    }
}

void func_021633A8(Mmdl *mmdl)
{
    EventInfo info;

    func_021640B0(mmdl);
    if (func_0216D57C(mmdl, 0x800) == 0 && func_0216DB24(mmdl) == 1) {
        func_021631C0(mmdl, &info);
        func_02163418(mmdl, &info);
        func_021637B0(mmdl, &info);
        func_02163650(mmdl, &info);
        func_02163868(mmdl, &info);
        func_0216372C(mmdl, &info);
        func_0216355C(mmdl, &info);
        func_0216375C(mmdl, &info);
        func_021638AC(mmdl, &info);
    }
}

static inline void vzero(VecFx32 *pos)
{
    pos->x = 0;
    pos->y = 0;
    pos->z = 0;
}

/*
 * lever: block-local cast byte buffer keeps the zeroing pointer on the zero path.
 */
void func_02163418(Mmdl *mmdl, EventInfo *info)
{
    VecFx32 offset;
    if (func_0216DC00(mmdl) == 0 && func_021AB41C(info->oldAttrValue) != 0) {
        offset = d_021714D0;
        func_0216D900((int)mmdl, &offset);
        return;
    }
    {
        unsigned char zeroBuf[12];
        VecFx32 *zero = (VecFx32 *)zeroBuf;
        vzero(zero);
        func_0216D900((int)mmdl, zero);
    }
}

int func_02163464(u16 attrValue, u8 effectMode)
{
    int kind = 0;

    if (func_021AB4EC(attrValue) != 0) {
        kind = 6;
    } else if (func_021AB4F8(attrValue) != 0) {
        kind = 7;
    } else if (func_021AB434(attrValue) != 0) {
        kind = 1;
        if (effectMode == 3)
            kind = 5;
    } else if (func_021AB428(attrValue) != 0) {
        if (effectMode == 3)
            kind = 4;
    } else if (func_021AB250(attrValue) != 0) {
        kind = 1;
    } else if (func_021AB264(attrValue) != 0) {
        kind = 2;
    } else if (func_021AB270(attrValue) != 0) {
        kind = 3;
    }
    return kind;
}

void func_021634D8(Mmdl *mmdl, EventInfo *info)
{
    int kind;

    if (info->oldAttrFlag & 0x20) {
        kind = func_02163464(info->oldAttrValue, info->effectMode);
        func_021AC760(info->effectCtrl, (u32)mmdl, 0, kind);
    }
}

/*
 * trailing: two-byte zero alignment at 0x0216352A before func_0216352C.
 */
void func_021634FC(Mmdl *mmdl, EventInfo *info)
{
    int stepFlag;
    int kind;
    if (info->oldAttrFlag & 0x20) {
        stepFlag = func_0216D608(mmdl);
        kind = func_02163464(info->oldAttrValue, info->effectMode);
        if (stepFlag != 0)
            func_021AC760(info->effectCtrl, (u32)mmdl, 1, kind);
    }
}

/*
 * trailing: two-byte zero alignment at 0x0216355A before func_0216355C.
 */
void func_0216352C(Mmdl *mmdl, EventInfo *info)
{
    int stepFlag;
    int kind;
    if (info->oldAttrFlag & 0x20) {
        stepFlag = func_0216D608(mmdl);
        kind = func_02163464(info->oldAttrValue, info->effectMode);
        if (stepFlag == 0)
            func_021AC760(info->effectCtrl, (u32)mmdl, 1, kind);
    }
}

void func_0216355C(Mmdl *mmdl, EventInfo *info)
{
    int kind;

    if (info->oldAttrFlag & 0x20) {
        kind = func_02163464(info->oldAttrValue, info->effectMode);
        func_021AC760(info->effectCtrl, (u32)mmdl, 1, kind);
    }
}

void func_02163580(Mmdl *mmdl, EventInfo *info)
{
    int kind;

    if (info->nowAttrFlag & 8) {
        kind = 5;
        if (func_021AB3D4(info->nowAttrValue) != 0) {
            if (info->effectMode == 3) {
                kind = 2;
                if (info->objCodeParam->footMarkType == 2)
                    kind = 3;
            }
        } else if (func_021AB3E0(info->nowAttrValue) != 0) {
            if (info->effectMode == 0 || info->effectMode == 3) {
                kind = 2;
                if (info->objCodeParam->footMarkType == 2)
                    kind = 3;
            }
        } else if (func_021AB334(info->nowAttrValue) == 1 || func_021AB328(info->nowAttrValue) == 1) {
            kind = 2;
            if (info->objCodeParam->footMarkType == 2)
                kind = 3;
        } else if (func_021AB41C(info->nowAttrValue) == 1) {
            kind = 4;
        } else {
            kind = 0;
            if (info->objCodeParam->footMarkType == 2)
                kind = 1;
        }
        if (kind != 5)
            func_021BBDD4(mmdl, info->effectCtrl, kind);
    }
}

int func_02163618(Mmdl *mmdl, EventInfo *info)
{
    int ret;

    if (func_021AB304(info->oldAttrValue) == 1) {
        ret = func_0216DBE8(mmdl);
        if (ret != 0)
            return ret;
        func_021C4BE0(info->effectCtrl, mmdl);
        return func_0216DBCC(mmdl, 1);
    }
    return func_0216DBCC(mmdl, 0);
}

int func_02163650(Mmdl *mmdl, EventInfo *info)
{
    int ret;

    if (func_021AB304(info->oldAttrValue) == 1) {
        ret = func_0216DBE8(mmdl);
        if (ret != 0)
            return ret;
        func_021C4BE0(info->effectCtrl, mmdl);
        return func_0216DBCC(mmdl, 1);
    }
    if (func_021AB364(info->oldAttrValue) == 1)
        return func_021C4A10(info->effectCtrl, mmdl);
    return func_0216DBCC(mmdl, 0);
}

void func_0216369C(Mmdl *mmdl, EventInfo *info)
{
    func_0216DBCC(mmdl, 0);
}

int func_021636A8(Mmdl *mmdl, EventInfo *info)
{
    if (func_0216D98C(func_0216D67C(mmdl)) == 0 || info->objCodeParam->shadowSize == 0)
        return 0;
    return 1;
}

int func_021636C8(EventInfo *info)
{
    if ((info->oldAttrFlag & 0x80) == 0)
        return 0;
    if (info->effectMode == 3 && func_021AB3D4(info->oldAttrValue) != 0)
        return 0;
    return 1;
}

void func_021636F0(Mmdl *mmdl, EventInfo *info)
{
    if (func_021636A8(mmdl, info) == 1 && func_021636C8(info) == 1) {
        if (func_0216D57C(mmdl, 0x4000) == 0) {
            func_021AC2C0(mmdl, info->effectCtrl);
            func_0216D568(mmdl, 0x4000);
        }
    }
}

void func_0216372C(Mmdl *mmdl, EventInfo *info)
{
    if (func_021636A8(mmdl, info) == 1) {
        if (func_021636C8(info) == 0) {
            func_0216D568(mmdl, 0x8000);
            return;
        }
        func_0216D570(mmdl, 0x8000);
    }
}

void func_0216375C(Mmdl *mmdl, EventInfo *info)
{
    if (!(info->oldAttrFlag & 2) && !func_0216DD04(mmdl))
        func_021AC528((u32)mmdl, info->effectCtrl);
}

void func_0216377C(Mmdl *mmdl, EventInfo *info)
{
    int gridX, gridZ, height;

    if (func_021AB2F8(info->nowAttrValue) == 1) {
        gridX = func_0216D804(mmdl);
        gridZ = func_0216D81C(mmdl);
        height = func_0216D8AC(mmdl);
        func_021C484C(info->effectCtrl, gridX, gridZ, height);
    }
}

void func_021637B0(Mmdl *mmdl, EventInfo *info)
{
    int gridX, gridZ, height;

    if (func_021AB2F8(info->oldAttrValue) == 1) {
        gridX = func_0216D83C(mmdl);
        gridZ = func_0216D86C(mmdl);
        height = func_0216D8AC(mmdl);
        func_021C484C(info->effectCtrl, gridX, gridZ, height);
    }
}

void func_021637E4(Mmdl *mmdl, EventInfo *info)
{
    int reflectAttr, attrOrKind, mmdlSys;

    if (info->objCodeParam->reflectType == 0) {
        return;
    }
    if (func_0216DC34(mmdl) != 0) {
        return;
    }
    reflectAttr = -1;
    if (info->oldAttrFlag & 0x40) {
        reflectAttr = info->oldAttr;
    } else {
        attrOrKind = func_02163F40(mmdl, 1);
        if (func_021AB0F8(attrOrKind) & 0x40) {
            reflectAttr = attrOrKind;
        }
    }
    if (reflectAttr == -1) {
        return;
    }
    attrOrKind = 1;
    reflectAttr = func_021AB0F0(reflectAttr);
    mmdlSys = (int)func_0216D67C(mmdl);
    if (func_021AB440(reflectAttr) == 1 || func_021AB358(reflectAttr) == 1) {
        attrOrKind = 2;
    }
    func_021BBFB8(mmdlSys, (u32)mmdl, info->effectCtrl, attrOrKind);
    func_0216DC18(mmdl, 1);
}

void func_02163868(Mmdl *mmdl, EventInfo *info)
{
    if (info->objCodeParam->reflectType != 0 && func_0216DC34(mmdl) != 0) {
        int neighborAttr = func_02163F40(mmdl, 1);

        if (neighborAttr == -1) {
            func_0216DC18(mmdl, 0);
            return;
        }
        if ((func_021AB0F8(neighborAttr) & 0x40) == 0) {
            func_0216DC18(mmdl, 0);
        }
    }
}

/*
 * unblocked: func_021C8F7C is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 28 bytes against 26 compiled: the unlabelled follower that
 *   precedes ov021's next entry (its bytes are the original's 2-byte pad).
 */
void func_021638AC(Mmdl *mmdl, EventInfo *info)
{
    if (func_021AB3EC(info->oldAttrValue) == 1)
        func_021C8F7C(mmdl, info->effectCtrl);
}

void func_021638C8(Mmdl *mmdl, EventInfo *info)
{
}

/*
 * Collects five placement-test failures into a bit mask: 1 from
 * func_02163C9C, 2 from func_02163D04 (the cell-centre position by
 * value), 8 when the ground-height probe func_02163E58 fails or lands
 * 0x14000 or more from the object's height, 4 from func_02163BAC, 0x10
 * from the ov021 test at 0x0218DC04.
 *
 * x and y are s16 register parameters (their spill homes are stored at
 * entry); z is read as `*(s16 *)&z` from an int stack parameter: an s16
 * z is copied into a fresh spill slot, while this spelling keeps the
 * incoming slot as its home and reloads it with ldrsh after the calls.
 */
u32 func_021638CC(Mmdl *mmdl, VecFx32 *currentPos, s16 gridX, s16 height, int gridZ, u16 kind)
{
    u32 failMask = 0;
    VecFx32 cellPos;
    fx32 groundHeight;

    cellPos.x = (gridX << 16) + 0x8000;
    cellPos.y = currentPos->y;
    cellPos.z = (*(s16 *)&gridZ << 16) + 0x8000;
    if (func_02163C9C(mmdl, gridX, *(s16 *)&gridZ) == 1)
        failMask |= 1;
    if (func_02163D04(mmdl, kind, cellPos) == 1)
        failMask |= 2;
    if (func_02163E58(mmdl, &cellPos, &groundHeight) == 1) {
        fx32 heightDiff = currentPos->y - groundHeight;
        if (heightDiff < 0)
            heightDiff = -heightDiff;
        if (heightDiff >= 0x14000)
            failMask |= 8;
        height = (groundHeight >> 4) / 0x1000;
    } else {
        failMask |= 8;
    }
    if (func_02163BAC(mmdl, gridX, height, *(s16 *)&gridZ) == 1)
        failMask |= 4;
    if (func_0218DC04(func_0216D52C(func_0216D67C(mmdl)), &cellPos) == 1)
        failMask |= 0x10;
    return failMask;
}

/*
 * trailing: two-byte zero alignment at 0x021639BE before func_021639C0.
 */
u32 func_02163994(Mmdl *mmdl, s16 gridX, s16 height, int gridZ, u16 kind)
{
    VecFx32 currentPos;
    func_0216D88C(mmdl, &currentPos);
    return func_021638CC(mmdl, &currentPos, gridX, height, gridZ, kind);
}

void func_021639C0(Mmdl *mmdl, u16 dir)
{
    s16 gridX, height, gridZ;

    gridX = func_0216D83C(mmdl) + func_021641E8(dir);
    height = func_0216D854(mmdl);
    gridZ = func_0216D86C(mmdl) + func_021641F8(dir);
    func_02163994(mmdl, gridX, height, gridZ, dir);
}

/*
 * Builds a rectangle (s16 x0, y0, x1, y1) from a map object's width and
 * height getters: x spans x .. x + (w - 1), y spans y - (h - 1) .. y, each
 * size clamped at 0. EXACT* only for the 2-byte pad after the function
 * (54 of 56).
 *
 * Key: out->x0 = x is written before
 * out->x1 = x + w. Then x is dead at the add and does not interfere with
 * the sum temp, so x and y simplify in one pass and take r6 / r5 in
 * parameter order. With x1 stored first, x and y swapped registers (6 B).
 */
void func_02163A08(Mmdl *mmdl, int gridX, int gridZ, Rect *out)
{
    s16 width;
    s16 height;
    width = func_0216D91C(mmdl) - 1;
    if (width < 0) width = 0;
    out->x0 = gridX;
    out->x1 = gridX + width;
    height = func_0216D924(mmdl) - 1;
    if (height < 0) height = 0;
    out->y0 = gridZ - height;
    out->y1 = gridZ;
}

/*
 * Tests whether two rectangles (s16 x0, y0, x1, y1) overlap: per axis the
 * longer interval comes first, then either end of the shorter one must lie
 * inside it. Leaf, no calls. EXACT* only for the 2-byte pad after the
 * function (174 of 176).
 *
 * Key: each axis is a block with its own locals, and the second block
 * declares them in a different order (big0, big1, sm0, sm1, lo1, hi1, lo2,
 * hi2, d1, d2). Declaration order sets the colouring order of the second
 * axis (d1 after lo2); the first block keeps d1, d2, lo1, ... order.
 * Earlier 15 B residue (shared locals) was only the d1/lo2 register swap.
 */
int func_02163A40(Rect *rectA, Rect *rectB)
{
    {
        s16 lenA, lenB, loA, hiA, loB, hiB, longLo, longHi, shortLo, shortHi;
        loA = rectA->x0; hiA = rectA->x1; lenA = hiA - loA; if (lenA < 0) { lenA = -lenA; }
        loB = rectB->x0; hiB = rectB->x1; lenB = hiB - loB; if (lenB < 0) { lenB = -lenB; }
        if (lenA > lenB) { longLo = loA; longHi = hiA; shortLo = loB; shortHi = hiB; }
        else { longLo = loB; longHi = hiB; shortLo = loA; shortHi = hiA; }
        if (!((longLo <= shortLo && longHi >= shortLo) || (longLo <= shortHi && longHi >= shortHi))) goto fail;
    }
    {
        s16 longLo, longHi, shortLo, shortHi, loA, hiA, loB, hiB, lenA, lenB;
        loA = rectA->y0; hiA = rectA->y1; lenA = hiA - loA; if (lenA < 0) { lenA = -lenA; }
        loB = rectB->y0; hiB = rectB->y1; lenB = hiB - loB; if (lenB < 0) { lenB = -lenB; }
        if (lenA > lenB) { longLo = loA; longHi = hiA; shortLo = loB; shortHi = hiB; }
        else { longLo = loB; longHi = hiB; shortLo = loA; shortHi = hiA; }
        if (!((longLo <= shortLo && longHi >= shortLo) || (longLo <= shortHi && longHi >= shortHi))) goto fail;
    }
    return 1;
fail:
    return 0;
}

int func_02163AF0(Mmdl *mmdl, Mmdl *other, int gridX, int height, s16 gridZ, int checkNext)
{
    Rect rect;
    Rect otherRect;
    s16 heightDiff;

    func_02163A08(mmdl, gridX, gridZ, &rect);
    if (func_0216D55C(other, 0x80) == 0) {
        func_02163A08(other, func_0216D83C(other), func_0216D86C(other), &otherRect);
        if (func_02163A40(&rect, &otherRect) != 0) {
            heightDiff = height - func_0216D854(other);
            if (heightDiff < 0) {
                heightDiff = -heightDiff;
            }
            if (heightDiff < 1) {
                return 1;
            }
        }
        if (checkNext == 1) {
            func_02163A08(other, func_0216D804(other), func_0216D81C(other), &otherRect);
            if (func_02163A40(&rect, &otherRect) != 0) {
                heightDiff = height - func_0216D810(other);
                if (heightDiff < 0) {
                    heightDiff = -heightDiff;
                }
                if (heightDiff < 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int func_02163BAC(Mmdl *mmdl, int gridX, int height, s16 gridZ)
{
    u32 iter;
    Mmdl *other;
    MmdlSys *mmdlSys;

    iter = 0;
    mmdlSys = func_0216D67C(mmdl);
    while (func_0216DD1C(mmdlSys, &other, &iter) == 1) {
        if (mmdl != other) {
            if (func_02163AF0(mmdl, other, gridX, height, gridZ, 1) == 1)
                return 1;
        }
    }
    return 0;
}

int func_02163C04(Mmdl *mmdl, int gridX, int gridZ, int checkNext)
{
    Rect rect;
    int cellX;

    cellX = func_0216D83C(mmdl);
    func_02163A08(mmdl, cellX, func_0216D86C(mmdl), &rect);
    if (rect.x0 <= gridX && rect.x1 >= gridX && rect.y0 <= gridZ && rect.y1 >= gridZ)
        return 1;
    if (checkNext == 1) {
        cellX = func_0216D804(mmdl);
        func_02163A08(mmdl, cellX, func_0216D81C(mmdl), &rect);
        if (rect.x0 <= gridX && rect.x1 >= gridX && rect.y0 <= gridZ && rect.y1 >= gridZ)
            return 1;
    }
    return 0;
}

int func_02163C9C(Mmdl *mmdl, int gridX, int gridZ)
{
    int center;
    int range;
    int maxPos;
    int minPos;

    center = func_0216D7E8(mmdl);
    range = func_0216D660(mmdl);
    if (range != -1) {
        maxPos = (s16)(center + range);
        minPos = (s16)(center - range);
        if (minPos > gridX || maxPos < gridX)
            return 1;
    }
    center = func_0216D7F8(mmdl);
    range = func_0216D66C(mmdl);
    if (range != -1) {
        maxPos = (s16)(center + range);
        minPos = (s16)(center - range);
        if (minPos > gridZ || maxPos < gridZ)
            return 1;
    }
    return 0;
}

/*
 *   Closed by writing the inner loop init as "for (j = 0, cur = row; ...)" (copy inside the for-init,
 *   after j = 0).
 */
int func_02163D04(Mmdl *mmdl, u32 kind, VecFx32 topLeft)
{
    int hasFirst;
    VecFx32 rowPos;
    VecFx32 cellPos;
    u32 cellAttr;
    u32 firstAttr;
    u8 i;
    u32 height;
    u8 j;
    u32 width;
    u16 nowAttrValue;

    if (func_0216DCB4(mmdl) == 0) {
        hasFirst = 0;
        width = func_0216D91C(mmdl);
        height = func_0216D924(mmdl);
        rowPos = topLeft;
        for (i = 0; i < height; i++, rowPos.z -= 0x10000) {
            for (j = 0, cellPos = rowPos; j < width; j++, cellPos.x += 0x10000) {
                if (func_02163E34(mmdl, &cellPos, &cellAttr) == 0)
                    return 1;
                if (func_021AB11C(cellAttr) == 1)
                    return 1;
                if (hasFirst == 0) {
                    firstAttr = cellAttr;
                    hasFirst = 1;
                }
            }
        }
        nowAttrValue = func_021AB0F0(func_0216D7DC(mmdl));
        if (d_021714A0[kind](nowAttrValue) == 1)
            return 1;
        if (d_02171490[kind](func_021AB0F0(firstAttr)) == 1)
            return 1;
        return 0;
    }
    return 1;
}

int func_02163E1C(Mmdl *mmdl, VecFx32 *pos, MapAttrInfo *info) { return func_0218DAEC(func_0216D52C(func_0216D67C(mmdl)),pos,info); }

int func_02163E34(Mmdl *mmdl, VecFx32 *pos, u32 *outAttr)
{
    MapAttrInfo info;

    *outAttr = 0;
    if (func_02163E1C(mmdl, pos, &info) == 1) {
        *outAttr = info.attr;
        return 1;
    }
    return 0;
}

int func_02163E58(Mmdl *mmdl, VecFx32 *pos, int *outHeight)
{
    MapAttrInfo info;

    *outHeight = 0;
    if (func_02163E1C(mmdl, pos, &info) == 1) {
        *outHeight = info.height;
        return 1;
    }
    return 0;
}

void func_02163E7C(Mmdl *mmdl, int dir)
{
    int groundHeight;
    VecFx32 cellPos;

    func_0216D80C(mmdl, func_0216D83C(mmdl));
    func_0216D818(mmdl, func_0216D854(mmdl));
    func_0216D824(mmdl, func_0216D86C(mmdl));
    func_0216D848(mmdl, func_021641E8(dir));
    func_0216D87C(mmdl, func_021641F8(dir));
    groundHeight = 0;
    func_02164280(func_0216D83C(mmdl), func_0216D86C(mmdl), &cellPos);
    cellPos.y = func_0216D8AC(mmdl);
    func_02163E58(mmdl, &cellPos, &groundHeight);
    func_0216D85C(mmdl, (s16)((groundHeight >> 4) / 4096));
}

void func_02163F10(Mmdl *mmdl)
{
    func_0216D80C(mmdl, func_0216D83C(mmdl));
    func_0216D818(mmdl, func_0216D854(mmdl));
    func_0216D824(mmdl, func_0216D86C(mmdl));
}

int func_02163F40(Mmdl *mmdl, int dir)
{
    VecFx32 cellPos;
    int attr;

    attr = -1;
    func_02164280(func_0216D83C(mmdl), func_0216D86C(mmdl), &cellPos);
    cellPos.y = func_0216D8AC(mmdl);
    func_02164208(dir, &cellPos, 0x10000);
    func_02163E34(mmdl, &cellPos, (u32 *)&attr);
    return attr;
}

/*
 * contract: matched func_0216D88C copies all three Actor.pos words to v;
 * no uninitialized local component is read. Additions wrap as unsigned32.
 */
void func_02163F8C(Mmdl *mmdl, const VecFx32 *delta) { VecFx32 pos; func_0216D88C(mmdl,&pos); pos.x=(int)((unsigned)pos.x+(unsigned)delta->x); pos.y=(int)((unsigned)pos.y+(unsigned)delta->y); pos.z=(int)((unsigned)pos.z+(unsigned)delta->z); func_0216D89C(mmdl,&pos); }

void func_02163FC0(Mmdl *mmdl, int dir, int amount)
{
    VecFx32 pos;

    func_0216D88C(mmdl, &pos);
    switch (dir) {
    case 0:
        pos.z -= amount;
        break;
    case 1:
        pos.z += amount;
        break;
    case 2:
        pos.x -= amount;
        break;
    case 3:
        pos.x += amount;
        break;
    }
    func_0216D89C(mmdl, &pos);
}

int func_02164010(Mmdl *mmdl)
{
    VecFx32 curPos;
    VecFx32 probePos;
    int groundHeight;
    int found;

    func_0216D88C(mmdl, &curPos);
    probePos = curPos;
    if (func_0216D55C(mmdl, 0x2000) != 0)
        return 0;
    if (func_0216DB68(mmdl) == 1) {
        func_0216D570(mmdl, 0x1000);
        return 0;
    }
    found = func_02163E58(mmdl, &probePos, &groundHeight);
    if (found == 1) {
        curPos.y = groundHeight;
        func_0216D89C(mmdl, &curPos);
        func_0216D818(mmdl, func_0216D854(mmdl));
        func_0216D85C(mmdl, (s16)((groundHeight >> 4) / 4096));
        func_0216D570(mmdl, 0x1000);
    } else {
        func_0216D568(mmdl, 0x1000);
    }
    return found;
}

int func_021640B0(Mmdl *mmdl)
{
    VecFx32 cellPos;
    int nowAttr;
    int oldAttr;
    int hasNowAttr;
    int hasOldAttr;

    hasNowAttr = 0;
    hasOldAttr = 0;
    nowAttr = -1;
    oldAttr = -1;
    if (func_0216DCB4(mmdl) == 0) {
        int gridX = func_0216D804(mmdl);
        int gridY = func_0216D810(mmdl);
        int gridZ = func_0216D81C(mmdl);
        cellPos.x = gridX << 16;
        cellPos.y = gridY << 16;
        cellPos.z = gridZ << 16;
        hasNowAttr = func_02163E34(mmdl, &cellPos, (u32 *)&nowAttr);
        func_02164280((s16)func_0216D83C(mmdl), (s16)func_0216D86C(mmdl), &cellPos);
        cellPos.y = func_0216D8AC(mmdl);
        hasOldAttr = func_02163E34(mmdl, &cellPos, (u32 *)&oldAttr);
    }
    if (hasNowAttr == 1)
        func_0216D7E0(mmdl, nowAttr);
    if (hasOldAttr == 1)
        func_0216D7D8(mmdl, oldAttr);
    if (hasOldAttr == 1) {
        func_0216D570(mmdl, 0x800);
        return 1;
    }
    func_0216D568(mmdl, 0x800);
    return 0;
}

int func_02164168(Mmdl *mmdl)
{
    Mmdl *player;
    int playerX;
    int playerZ;
    int gridX;
    int gridZ;
    s16 minX;
    s16 minZ;
    s16 maxX;
    s16 maxZ;

    player = func_0216DEE0(func_0216D67C(mmdl));
    if (player != 0) {
        playerX = func_0216D83C(player);
        playerZ = func_0216D86C(player);
        gridX = func_0216D83C(mmdl);
        gridZ = func_0216D86C(mmdl);
        minX = gridX - 18;
        minZ = gridZ - 18;
        maxX = gridX + 17;
        maxZ = gridZ + 17;
        if (minZ <= playerZ && maxZ >= playerZ && minX <= playerX && maxX >= playerX)
            return 1;
    }
    return 0;
}

/*
 * lever: halfword-wrapped +0xFFCD preserves the literal-pool bias;
 * spelling -51 produced a 26-byte DIFF instead of the 32-byte body.
 */
void func_021641C8(Mmdl *mmdl) { if ((u16)(func_0216D5A0(mmdl)+0xFFCD) <= 3) func_0216D708(mmdl); }

/*
 * contract: ROM table at 0x02171480 holds {0,0,-1,1}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 */
int func_021641E8(int dir) { return (short)*(const int *)((unsigned)d_02171480+((unsigned)dir<<2)); }

/*
 * contract: ROM table at 0x02171470 holds {-1,1,0,0}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 */
int func_021641F8(int dir) { return (short)*(const int *)((unsigned)d_02171470+((unsigned)dir<<2)); }

void func_02164208(int dir, VecFx32 *pos, int amount)
{
    switch (dir) {
    case 0:
        pos->z -= amount;
        break;
    case 1:
        pos->z += amount;
        break;
    case 2:
        pos->x -= amount;
        break;
    case 3:
        pos->x += amount;
        break;
    }
}

/*
 * Unlabelled leaf (no lr save, prints as .word data): step one of two
 * halfword coordinates by amt in the direction dir (0 z-, 1 z+, 2 x-, 3 x+).
 * Halfword sibling of the word version func_02164208.  Filed as the sole
 * blocker of ov021 func_021A40A8.
 */
void func_02164240(int dir, s16 *x, s16 *z, s16 amount)
{
    switch (dir) {
    case 0:
        z[0] -= amount;
        break;
    case 1:
        z[0] += amount;
        break;
    case 2:
        x[0] -= amount;
        break;
    case 3:
        x[0] += amount;
        break;
    }
}

void func_02164280(int gridX, int gridZ, VecFx32 *pos)
{
    pos->x = (gridX << 16) + 0x8000;
    pos->z = (gridZ << 16) + 0x8000;
}

/*
 * Unlabelled leaf, blocker of ov021 func_0218B4B0: widens three integers to 16.16 fixed point.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_02164294(int gridX, int gridY, int gridZ, VecFx32 *pos)
{
    pos->x = gridX << 16;
    pos->y = gridY << 16;
    pos->z = gridZ << 16;
}

/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov021 func_0219A7DC and func_0219A8C0: returns
 * the low halfword of word i of a table.
 */
u16 func_021642A4(int index)
{
    return d_021714B0[index];
}

/*
 * Unlabelled leaf (word run in the listing), blocker of func_0219B13C and
 * func_0219BA6C (ov021).  Direction code 0..3 from a point pair.
 */
u16 func_021642B4(int fromX, int fromZ, int toX, int toZ)
{
    int dir;

    if (fromX > toX) {
        return 2;
    }
    if (fromX < toX) {
        return 3;
    }
    dir = 1;
    if (fromZ > toZ) {
        dir = 0;
    }
    return dir;
}

/*
 * Unlabelled leaf, blocker of ov021 func_0219FFD4: three chained table lookups.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 func_021642D4(int tableIndex, int offset)
{
    u32 lookupIndex = (u16)(offset + d_02171458[tableIndex]);

    return d_021714C0[d_02171460[lookupIndex >> 12]].dirCode;
}

/*
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D548, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021642F8.c \
 *       --func func_021642F8 --addr 0x021642F8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021642F8(Mmdl *mmdl)
{

    func_0216D548(mmdl, 8192);
}

void func_02164304(Mmdl *mmdl, MmdlHeader *header)
{
    RailLocation location;
    u16 *railPos;
    location.railIndex = header->pos[0];
    location.type = 1;
    railPos = header->pos;
    location.key = func_0201441C((s16)header->dirHeader);
    location.lineGrid = railPos[1];
    location.widthGrid = ((s16 *)railPos)[2];
    if (func_0216D4D4(func_0216D67C(mmdl), 0x10) != 0) {
        func_0219E2C0((int)mmdl, &location);
        return;
    }
    func_0216D684(mmdl, 0xc);
    func_0216435C(mmdl, (const u16 *)(&location));
}

void func_0216435C(Mmdl *mmdl, const u16 *locationWords) { RailMoveRequest *request=func_0216D69C(mmdl); request->location[0]=locationWords[0]; request->location[1]=locationWords[1]; request->location[2]=locationWords[2]; request->location[3]=locationWords[3]; request->magic=0xEFEFEFEF; }

/*
 * contract: setter func_0216435C writes the four payload halfwords
 * at +4,+6,+8,+10 before publishing 0xEFEFEFEF at +0;
 * this reader loads those halfwords only after the sentinel comparison.
 */
int func_02164380(Mmdl *mmdl, u16 *outWords) { RailMoveRequest *request=func_0216D69C(mmdl); if (request->magic==0xEFEFEFEF) { outWords[0]=request->location[0]; outWords[1]=request->location[1]; outWords[2]=request->location[2]; outWords[3]=request->location[3]; return 1; } return 0; }
