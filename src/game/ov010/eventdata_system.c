/*
 * file:     eventdata_system.c
 * unit:     yes
 * function: func_02161E60, func_02161E78, func_02161E84, func_02161ECC, func_02161EEC, func_02161F00, func_02161F14, func_02161F54, func_02161F68, func_02161F74, func_02161F90, func_02161FEC, func_02161FF0, func_02162008, func_02162024, func_0216202C, func_02162038, func_02162040, func_02162048, func_0216208C, func_0216209C, func_021620A0, func_021620B0, func_0216210C, func_02162120, func_02162198, func_021621C0, func_021621E8, func_0216220C, func_02162230, func_02162254, func_02162278, func_02162298, func_021622AC, func_021622D8, func_021622F4, func_0216230C, func_02162330, func_02162358, func_02162370, func_0216237C, func_021623BC, func_021623DC, func_02162408, func_0216242C, func_02162438, func_02162450, func_02162458, func_0216245C, func_02162478, func_021624B0, func_02162530, func_0216255C, func_02162560, func_02162564, func_02162598, func_021625CC, func_021625E8, func_021625FC, func_02162694, func_021626A8, func_021626B0, func_021626B8, func_021626E8, func_021626EC, func_02162708, func_02162740, func_02162744, func_02162748, func_02162774, func_02162788, func_0216279C, func_021627C8, func_0216282C, func_02162890, func_021628E4, func_02162928, func_02162940, func_02162958, func_02162970, func_02162A54, func_02162A5C, func_02162A64, func_02162A6C, func_02162A74, func_02162AA4, func_02162B68, func_02162BCC, func_02162C54, func_02162C84, func_02162CE8, func_02162D2C, func_02162D90, func_02162E00, func_02162E48, func_02162E9C, func_02162ECC, func_02162F0C, func_02162F74, func_02162FC8, func_02163010, func_02163028, func_02163090, func_021630F4, func_0216310C, func_02163130, func_02163154, func_02163188, func_021631C0, func_02163230, func_02163288, func_021632F0, func_02163340, func_021633A8, func_02163418, func_02163464, func_021634D8, func_021634FC, func_0216352C, func_0216355C, func_02163580, func_02163618, func_02163650, func_0216369C, func_021636A8, func_021636C8, func_021636F0, func_0216372C, func_0216375C, func_0216377C, func_021637B0, func_021637E4, func_02163868, func_021638AC, func_021638C8, func_021638CC, func_02163994, func_021639C0, func_02163A08, func_02163A40, func_02163AF0, func_02163BAC, func_02163C04, func_02163C9C, func_02163D04, func_02163E1C, func_02163E34, func_02163E58, func_02163E7C, func_02163F10, func_02163F40, func_02163F8C, func_02163FC0, func_02164010, func_021640B0, func_02164168, func_021641C8, func_021641E8, func_021641F8, func_02164208, func_02164240, func_02164280, func_02164294, func_021642A4, func_021642B4, func_021642D4, func_021642F8, func_02164304, func_0216435C, func_02164380, func_021643AC, func_021643E8, func_02164454, func_0216445C, func_02164464, func_0216446C, func_02164474, func_0216447C, func_02164480, func_021644C4
 * address:  0x02161E60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02045A98  0x02045A98  arm
 *   func_021867C4  0x021867C4  thumb ov023
 *   func_0218682C  0x0218682C  thumb
 *   func_02186804  0x02186804  thumb
 *   func_02039338  0x02039338  arm
 *   func_02161DC4  0x02161DC4  thumb
 *   func_02186520  0x02186520  thumb
 *   d_0217144C     0x0217144C  data  ov010  a4
 *   func_02082D44  0x02082D44  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   d_02172990     0x02172990  data  ov010  a4
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_0217299C     0x0217299C  data  ov010  a1
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0215E2B8  0x0215E2B8  thumb  ov010
 *   func_02013ECC  0x02013ECC  thumb
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_020140F8 0x020140F8 thumb
 *   func_02014110 0x02014110 thumb
 *   func_02014134 0x02014134 thumb
 *   func_0201416C  0x0201416C  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02164708  0x02164708  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 *   func_0201441C 0x0201441C thumb
 *   func_0207C768 0x0207C768 arm
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
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0215E428 0x0215E428 thumb ov010
 *   func_0215E3A0 0x0215E3A0 thumb ov010
 *   func_0201296C 0x0201296C thumb
 *   func_0201433C 0x0201433C thumb
 *   func_0215E33C 0x0215E33C thumb ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02013F6C  0x02013F6C  thumb
 *   func_02014464  0x02014464  thumb
 *   func_0215E364  0x0215E364  thumb ov010
 *   func_02164728  0x02164728  thumb ov010
 *   func_02013FFC  0x02013FFC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008988  0x02008988  thumb
 *   func_0215E34C  0x0215E34C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02028748  0x02028748  thumb
 *   func_02012B28  0x02012B28  thumb
 *   d_021714DC     0x021714DC  data
 */

struct R;
struct ArcFile;
struct Q;
struct Out;
struct EventRec;
struct Ctx;
struct CellKey;
struct VecFx32;
struct TriggerSet;
struct Grid;
struct Actor;
struct Obj_021636F0;
struct Rec;
struct Big;
struct BigObj;
struct Sub02008828Obj;
struct Sub02014444Obj;
struct Rec44;
struct SaveBlock;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct EventSlot { unsigned x; u16 b; u16 t; } EventSlot;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
    u8 b1;
    u8 b2;
    u8 pad;
    u16 ids[8];
} T;

typedef int (*Fn)(int, int, u16 *, u16 *);



typedef signed char    s8;



typedef struct {
    u16 a;
    u16 b;
    u8 rest[0x10];
} Rec14;

typedef struct {
    u8 n[4];
    u8 data[1];
} H;


typedef struct { u16 h0; u16 h2; } R;


typedef struct { u16 a, b; s16 c; u16 d; } B;

typedef struct { int x, y, z; } A;






typedef struct {
    u16 x;
    u16 h;
    u32 w;
} EventLinkSub;

typedef struct EventLink {
    u8 pad0[0xC];
    u16 a;
    u8 pad1[0xA];
    u32 busy;
    EventLinkSub s;
} EventLink;


struct EventRec {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 area[6];     /* 0x0A: x, z, w, h, ... */
};


typedef int s32;


struct Sub {
    u16 f0;
    u16 f2;
    s16 f4;
    u16 f6;
    u16 f8;
    u16 fa;
};

typedef struct TrigPos {
    s32 x;              /* 0x08 */
    s32 z;              /* 0x0C */
    s32 y;              /* 0x10 */
} TrigPos;

typedef struct TrigCell {
    u16 a;              /* 0x08 */
    u16 b;              /* 0x0A */
    s16 c;              /* 0x0C */
} TrigCell;

typedef union TrigData {
    s32 data[3];
    TrigPos pos;
    TrigCell cell;
    struct Sub sub;
} TrigData;

typedef struct Trigger {
    u16 id;             /* 0x00 */
    u16 kind2;          /* 0x02 */
    u16 kind;           /* 0x04 */
    u16 mode;           /* 0x06 */
    TrigData u;         /* 0x08 */
} Trigger;

typedef struct EventSlots {
    u16 f0;
    u16 flags;              /* bit i: slot i valid, bits 0-9 */
    u16 f4;
    u8 pad6[2];
    EventSlot slot[10];     /* 0x08 */
} EventSlots;

typedef struct EventState {
    u8 pad0[4];
    u8 f4;
    u8 f5;
} EventState;

typedef struct EventMsgSrc {
    u8 pad0[0xC];
    s16 fC;
    u8 padE[0xA];
    int f18;
    u16 f1C[3];
} EventMsgSrc;

typedef struct EventMark {
    u32 magic;
    u16 v[4];
} EventMark;

typedef struct EventData {
    u32 f0;
    struct ArcFile *arc;    /* 0x04 */
    void *f8;
    void *fC;
    u16 f10;
    u16 trigCount;          /* 0x12 */
    u16 linkCount;          /* 0x14 */
    u16 boxCount;           /* 0x16 */
    u16 recCount;           /* 0x18 */
    u16 pad1A;
    Trigger *trig;          /* 0x1C */
    EventLink *link;        /* 0x20 */
    Trigger *box;           /* 0x24 */
    struct EventRec *rec;   /* 0x28 */
    u16 saveTrigCount;      /* 0x2C */
    u16 saveLinkCount;
    u16 saveBoxCount;
    u16 saveRecCount;
    u32 f34;
    u8 pad38[7];
    u8 low : 7;
    u8 flag : 1;            /* 0x3F */
    u8 pad40[0x120 - 0x40];
    char *p120;
    int size;
    H hdr;
} EventData;


typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef struct { u32 e,f,g; } Payload;

typedef struct { u16 a,b,c,d; Payload data; } Rec_02162A74;






struct Q {
    u16 f0;
    u16 pad2;
    s16 f4;
    u16 f6;
};




typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u16 w;
    u16 h;
} Box_02162CE8;

typedef struct {
    u8 pad[8];
    Box_02162CE8 box;
} Obj_02161E60;



struct Out { u16 f0; u8 f2; u8 f3; s16 f4; u16 f6; };


typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct CellKey {
    u16 a;              /* 0x00 */
    u16 pad02;
    s16 c;              /* 0x04 */
    u16 b;              /* 0x06 */
} CellKey;




typedef struct EventTarget {
    u8 pad0[4];
    u8 f4;
    u8 f5;
    u8 f6;
} EventTarget;

typedef struct EventInfo {
    int a;
    int b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;
    EventTarget *g;
    int h;
    u8 i;
} EventInfo;

typedef struct { int x, y, z; } V;

typedef struct Obj_021636F0 {
    u32 f00;
    fx32 f04;           /* 0x04 */
} Obj_021636F0;


typedef struct { s16 x0, y0, x1, y1; } Rect;

typedef int (*AttrTest)(u16 attr);

typedef struct { u16 a,b,c,d; int p,q; } E;


typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Quad;


typedef struct {
    u16 a;
    u8 b;
    u8 c;
    s16 d;
    u16 e;
} Msg;

typedef struct Flags_021639C0 {
    u32 f00;
    u32 f04;
    u8 pad[0x10];
} Flags_021639C0;

typedef int (*Handler)(void *sys, void *b, void *save);

extern void func_02082BCC(void *, unsigned, unsigned);
extern u16 func_02045A98(void);
extern int func_021867C4(int, int);
extern u16 *func_0218682C(int h);
extern void func_02186804(int);
extern u16 func_02039338(void);
extern char *func_02161DC4(char *p, int id, unsigned mode);
extern void func_02186520(u16 *, int, char *);
extern void func_02082D44(void *, void *, unsigned);
extern u32 func_0200FB24(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *arc);
extern int func_020307B0();
extern int func_0215E2B8(struct R *r, int a, int b, int n);
extern unsigned func_02013ECC(unsigned);
extern unsigned func_020493D4(struct ArcFile *, unsigned);
extern void func_0204944C(struct ArcFile *, unsigned, unsigned, unsigned, void *);
extern void func_020140F8(int p0);
extern void func_02014110(int *, u16, s16, u16, int, unsigned, unsigned, unsigned);
extern void func_02014134(int *, u16, s16, u16, int, u16, u16, s16);
extern int func_0201416C(int a0, int a1, int a2, int a3);
extern u32 func_020143CC(u32 a, u32 b);
extern u16 func_02164708(u16 id);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u8 func_0201441C(int m);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_0216D6F4(void *a0);
extern int func_0219B414(int a);
extern u32 *func_0216D548(u32 *p, u32 v);
extern int func_0216DA20(void *p, unsigned int v);
extern unsigned int func_0216D57C(void *p, unsigned int v);
extern void func_02197EB4(u32 a);
extern int func_0216DB10(void *a0);
extern int func_0219B41C();
extern void func_0216D708(void *a0);
extern int func_0216DA5C(void *a0);
extern u16 func_0216D5A0(void *p);
extern u32 func_0216D564(void *p);
extern int func_0216DB68(void *a0);
extern int func_0216DCB4(void *a0);
extern void func_0216DA70(void *a0);
extern void *func_0216D570(void *p, u32 v);
extern void func_02082C60();
extern u32 func_0216D7E4(void *p);
extern u32 func_0216D7DC(void *p);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern void *func_0216E3C4(void *p);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D534(void *p);
extern u32 func_02188CD0(u8 *p);
extern u8 func_021ABE28(u8 *p);
extern int func_0216DB24(int a0);
extern int func_0216DC00(void *a0);
extern int func_021AB41C(unsigned short);
extern void func_0216D900(int, const V *);
extern int func_021AB4EC();
extern int func_021AB4F8();
extern int func_021AB434();
extern int func_021AB428();
extern int func_021AB250();
extern int func_021AB264();
extern int func_021AB270();
extern int func_021AC760();
extern u16 func_0216D608(void *p);
extern int func_021AB3D4();
extern int func_021AB3E0();
extern int func_021AB334();
extern int func_021AB328();
extern int func_021BBDD4();
extern int func_021AB304();
extern int func_0216DBE8(void *a0);
extern int func_021C4BE0();
extern int func_0216DBCC();
extern int func_021AB364();
extern int func_021C4A10();
extern int func_0216D98C(int a0);
extern int func_021AC2C0(void *p, int h);
extern void *func_0216D568(void *p, u32 v);
extern int func_0216DD04(void *p);
extern void func_021AC528(u32 a, u32 b);
extern int func_021AB2F8(u16 id);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern u32 func_0216D8AC(void *p);
extern int func_021C484C(int h, int x, int y, int z);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216DC34(void *a0);
extern int func_0216DC18(void *a0, int a1);
extern int func_021AB440();
extern int func_021AB358(int x);
extern void func_021BBFB8(u32 a, u32 b, u32 c, u32 d);
extern int func_021AB3EC(u16 id);
extern int func_021C8F7C(void *p, int h);
extern u32 func_0216D52C(void *p);
extern int func_0218DC04(struct Grid *g, VecFx32 *pos);
extern void func_0216D88C(const struct Actor *p, VecFx32 *out);
extern s16 func_0216D854(void *p);
extern u8 func_0216D91C(int a0);
extern u8 func_0216D924(int a0);
extern int func_0216D55C(int a0, int a1);
extern int func_0216D810(void *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D7E8(void *p);
extern int func_0216D660(void *p);
extern int func_0216D7F8(void *p);
extern int func_0216D66C(void *p);
extern int func_021AB11C(u32 attr);
extern int func_0218DAEC(char *, char *, E *);
extern int func_0216D80C(int a, int b);
extern int func_0216D818(int a, int b);
extern int func_0216D824(int a, int b);
extern void func_0216D848(int a, int b);
extern void func_0216D87C(int a, int b);
extern void func_0216D85C(void *p, int v);
extern void func_0216D89C(void *, const VecFx32 *);
extern void func_0216D7E0(void *p, u32 v);
extern void func_0216D7D8(void *p, u32 v);
extern void *func_0216DEE0(void *a0);
extern int func_0216D4D4(int a, int b);
extern void func_0219E2C0(int a, Msg *m);
extern void func_0216D684(int a, int b);
extern void *func_0216D69C(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *);
extern u16 func_02188C9C(u8 *p);
extern void func_0215E428(int a0, int a1);
extern void func_0215E3A0(void *);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_0201433C(char *, int);
extern int func_0215E33C(int a0);
extern void *func_02012B38(const struct BigObj *p);
extern u32 func_02013F6C(u32 id);
extern void func_02014464(struct Sub02014444Obj *o, u8 v);
extern void  func_0215E364(void *a);
extern void  func_02164728(void *a);
extern u32 func_02013FFC(u32 id);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern void func_02008988(struct Sub02008828Obj *obj, u16 value);
extern int func_0215E34C(int a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02028748(struct Obj *obj, int n, int mask);
extern u32 func_02012B28(const struct Rec44 *p);
void func_02161E60(char *p, int a1);
void func_02161E78(void *a0);
int func_02161E84(T *p);
int func_02161ECC(T *p);
void func_02161EEC(u16 *buf);
void func_02161F00(void *p);
void func_02161F14(u16 *out, u8 *in, int c);
void func_02161F54(u16 *p);
void func_02161F68(void *p);
void func_02161F74(int a0, int a1, int a2);
void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v);
void func_02161FEC(char *p, u16 v);
void func_02161FF0(u16 *p, EventSlot *s);
void func_02162008(char *p, int index, void *s);
int func_02162024(char *p, int index, void *out);
int func_0216202C(char *p, void *out, u8 *index);
void func_02162038(char *p, int index);
void func_02162040(char *p);
void func_02162048(u16 *a, int b, int c);
int func_0216208C(char *p, int unused);
u16 func_0216209C(char *p);
void func_021620A0(char *p);
void func_021620B0(char *p);
int func_0216210C(int a0);
void func_02162120(int a, int b, int c);
int func_02162198(int unused, char *p, const EventSlot *s, EventSlot *out);
int func_021621C0(int unused, char *p, const EventSlot *s, EventSlot *out);
int func_021621E8(int unused, char *p, EventSlots *q);
void func_0216220C(u16 *p, EventSlot *s);
void func_02162230(char *p, int index, void *s);
int func_02162254(char *p, u16 index, u16 *out);
void func_02162278(char *p, int index, u16 a, u16 b);
void func_02162298(EventSlots *s, int x, int y);
int func_021622AC(char *p, int index, void *out);
int func_021622D8(char *p, void *out);
void func_021622F4(char *p);
void func_0216230C(char *p, unsigned i);
void func_02162330(char *p, unsigned i);
void func_02162358(char *p);
int func_02162370(int a);
int func_0216237C(int a);
void func_021623BC(EventData *p);
void func_021623DC(char *p);
void func_02162408(char *p, u16 a1, u8 a2);
void func_0216242C(void *a0, u16 a1, u8 a2);
void func_02162438(char *p, int a1, int a2);
u32 func_02162450(void *p);
u32 func_02162458(u8 *p);
void func_0216245C(u8 *o, u16 idx);
int func_02162478(char *p, int *v);
void func_021624B0(EventData *o, int x);
void func_02162530(char *p);
u32 func_0216255C(u32 a);
u16 func_02162560(u8 *p);
int func_02162564(char *p, struct Q *q);
int func_02162598(char *p, struct Q *q);
void *func_021625CC(char *p, unsigned i);
int func_021625E8(R *p);
int func_021625FC(const u8 *q, int *out, int id, int k);
void func_02162694(Trigger *b, int a1, int a2);
u16 func_021626A8(void *b, void *pos);
u16 func_021626B0(void *b, void *q);
int func_021626B8(char *a0, int a1);
u8 func_021626E8(u8 *p);
int func_021626EC(u16 *p);
void func_02162708(EventData *c, u32 idx, u16 a, u32 b, u16 e);
u32 func_02162740(u8 *p);
u16 func_02162744(u8 *p);
void func_02162748(EventData *o, u32 idx, u16 a, u16 b, u32 w, u16 h);
void func_02162774(char *p, unsigned i, u16 v);
void func_02162788(char *p, unsigned i, u16 v);
u16 func_0216279C(int mode);
struct EventRec *func_021627C8(EventData *c, void *a, int key, int mode);
struct EventRec *func_0216282C(EventData *c, void *a, int *key, int mode);
struct EventRec *func_02162890(EventData *c, void *a, int key);
struct EventRec *func_021628E4(EventData *c, void *a, int key);
u16 func_02162928(void *p, void *q, int key, int mode);
u16 func_02162940(void *p, void *q, int key);
u16 func_02162958(void *c, void *a, int key);
u16 func_02162970(EventData *set, void *flags, const void *where, u16 type);
u16 func_02162A54(void *set, void *flags, const void *where, u16 type);
u16 func_02162A5C(void *set, void *flags, const void *where, u16 type);
void func_02162A64(const void *p, V3 *out);
void func_02162A6C(int a, int b);
void func_02162A74(const EventData *c, u32 i, u32 a, u32 b, u16 d);
u16 func_02162AA4(int v, int m, int flag, int dir, u16 n);
u16 func_02162B68(Trigger *b, int *pos);
u16 func_02162BCC(Trigger *b, struct Q *q);
int func_02162C54(u8 *p);
void func_02162C84(Trigger *b, int q, int *out);
void func_02162CE8(const Obj_02161E60 *p, V3 *out);
int func_02162D2C(const Trigger *b, const int *pos);
void func_02162D90(const Trigger *b, int q, struct Out *o);
int func_02162E00(Trigger *b, struct Q *q);
int func_02162E48(Trigger *t, const VecFx32 *pos);
int func_02162E9C(Trigger *t, const CellKey *k);
void func_02162ECC(const char *p, int *out);
int func_02162F0C(char *p, int *v);
int func_02162F74(char *p, int *v);
int func_02162FC8(char *p, u16 *v);
u32 *func_02163010(void *p);
void func_02163028(void *a);
int func_02163090(void *p);
int func_021630F4(void *p);
void func_0216310C(char *p);
void func_02163130(char *p);
void func_02163154(char *p);
void func_02163188(char *p);
void func_021631C0(int a, EventInfo *s);
void func_02163230(int a0);
void func_02163288(int a0);
void func_021632F0(int a0);
void func_02163340(int a0);
void func_021633A8(int a0);
void func_02163418(void *p, EventInfo *s);
int func_02163464(u16 id, u8 dir);
void func_021634D8(void *p, EventInfo *s);
void func_021634FC(void *p, EventInfo *s);
void func_0216352C(void *p, EventInfo *s);
void func_0216355C(void *p, EventInfo *s);
void func_02163580(void *p, EventInfo *s);
int func_02163618(void *p, EventInfo *s);
int func_02163650(void *p, EventInfo *s);
void func_0216369C(void *p, EventInfo *s);
int func_021636A8(void *p, EventInfo *s);
int func_021636C8(EventInfo *s);
void func_021636F0(void *p, EventInfo *s);
void func_0216372C(void *p, EventInfo *s);
void func_0216375C(void *p, EventInfo *s);
void func_0216377C(void *p, EventInfo *s);
void func_021637B0(void *p, EventInfo *s);
void func_021637E4(void *p, EventInfo *s);
void func_02163868(void *p, EventInfo *s);
void func_021638AC(void *p, EventInfo *s);
void func_021638C8(void *p, EventInfo *s);
u32 func_021638CC(void *m, Obj_021636F0 *o, s16 x, s16 y, int z, u16 kind);
u32 func_02163994(void *p, s16 x, s16 y, int z, u16 kind);
void func_021639C0(int a, u16 b);
void func_02163A08(int p, int x, int y, Rect *out);
int func_02163A40(s16 *a, s16 *b);
int func_02163AF0(int a, int b, int c, int d, s16 e, int g);
int func_02163BAC(int a, int b, int c, s16 d);
int func_02163C04(int a, int x, int y, int flag);
int func_02163C9C(int a, int b, int c);
int func_02163D04(void *m, u32 kind, VecFx32 pos);
int func_02163E1C(void *a, char *b, E *c);
int func_02163E34(void *a0, VecFx32 *a1, u32 *a2);
int func_02163E58(void *a0, VecFx32 *a1, int *a2);
void func_02163E7C(int a, int b);
void func_02163F10(int a);
int func_02163F40(int a, int dir);
void func_02163F8C(void *a, const VecFx32 *b);
void func_02163FC0(int a, int dir, int amt);
int func_02164010(int a);
int func_021640B0(int a);
int func_02164168(int a);
void func_021641C8(void *a);
int func_021641E8(int a);
int func_021641F8(int a);
void func_02164208(int dir, int *p, int amt);
void func_02164240(int dir, s16 *x, s16 *z, s16 amt);
void func_02164280(int x, int y, int *p);
void func_02164294(int x, int y, int z, int *out);
u16 func_021642A4(int i);
u16 func_021642B4(int x0, int y0, int x1, int y1);
u8 func_021642D4(int i, int v);
void func_021642F8(void *a0);
void func_02164304(int a, u8 *p);
void func_0216435C(void *a, const u16 *b);
int func_02164380(void *a, u16 *b);
void func_021643AC(void *a, void *b);
void func_021643E8(void *a, void *b);
int func_02164454(int a, int b);
int func_0216445C(int a, int b);
int func_02164464(int a, int b);
int func_0216446C(int a, int b);
void func_02164474(int a, int b);
void func_0216447C(int sys, u16 id);
void func_02164480(Flags_021639C0 *f, void *a, void *b);
int func_021644C4(int i, void *a, void *b);
extern int d_0217144C[];
extern Fn d_02172990[];
extern char d_0217299C[];
extern V d_021714D0;
extern const AttrTest d_021714A0[];
extern const AttrTest d_02171490[];
extern const int d_02171480[];
extern const int d_02171470[];
extern u32 d_021714B0[];
extern u16 d_02171458[];
extern u8 d_02171460[];
extern Quad d_021714C0[];
extern Handler d_021714DC[];














void func_02161E60(char *p, int a1)
{
    if (a1 == 0)
        func_021620B0(p + 8);
    else
        func_021620B0(p + 0xf8);
}














/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02082BCC, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02161E78.c \
 *       --func func_02161E78 --addr 0x02161E78 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02161E78(void *a0)
{

    func_02082BCC(a0, 0, 24);
}













int func_02161E84(T *p)
{
    int id = func_02045A98();
    int i;
    int found;
    if (p->b1 >= 30) return 0;
    if (p->b2 > 100) return 0;
    if (p->hi != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (id == p->ids[i]) found = 1;
        }
        if (found == 0) return 0;
    }
    return 1;
}












int func_02161ECC(T *p)
{
    if (p->lo == 0) return 0;
    if (func_02161E84(p) != 0) return 1;
    return 0;
}













/*
 * Fills ten halfwords with 0xFFFF.  A leaf with no lr-saving prologue,
 * called only from arm9 (func_0200A848), so the listing emits it as data.
 */
void func_02161EEC(u16 *buf)
{
    int i;
    for (i = 0; i < 10; i++)
        buf[i] = 0xffff;
}











void func_02161F00(void *p)
{
    func_02082BCC(p, 0, 4);
    ((EventSlots *)p)->flags = 10;
}














void func_02161F14(u16 *out, u8 *in, int c)
{
    int h;
    u16 *q;
    if (((EventSlots *)in)->flags == 1) {
        h = func_021867C4(in[9], (u16)((c & 0x7FFF) | 0x8000));
        q = func_0218682C(h);
        out[0] = q[0x24 / 2];
        out[1] = q[8 / 2];
        func_02186804(h);
    } else {
        out[0] = 0;
        out[1] = 10;
    }
}














void func_02161F54(u16 *p)
{
    func_02082BCC(p, 0, 0x48);
    *p = func_02039338();
}














void func_02161F68(void *p)
{
    func_02082BCC(p, 0, 0x48);
}














void func_02161F74(int a0, int a1, int a2)
{
    if (func_0216210C(a0) == 0)
        func_02162120(a0, a1, a2);
}














void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v)
{
    char *r4;
    int h;
    u16 *q;

    r4 = func_02161DC4(y, w, 1);
    h = (int)func_021867C4(w, v);
    q = func_0218682C(h);
    if (x[1] == 0)
        r4[2] = q[3];
    else
        r4[2] = q[2];
    r4[3] = 7;
    func_02186804(h);
    func_02186520(x, z, r4);
    func_02161E78(r4);
    func_02161E60(y, 1);
}













/*
 * Unlabelled leaf, four bytes: strh r1, [r0, 4]; bx lr.
 */
/*
 * Unlabelled leaf, four bytes: strh r1, [r0, #4]; bx lr.
 */
void func_02161FEC(char *p, u16 v)
{
    ((EventSlots *)p)->f4 = v;
}













void func_02161FF0(u16 *p, EventSlot *s)
{
    if (func_0216210C((int)p) == 0)
        func_0216220C(p, s);
}













void func_02162008(char *p, int index, void *s)
{
    if (func_0216210C((int)p) == 0)
        func_02162230(p, index, s);
}












int func_02162024(char *p, int index, void *out)
{
    return func_021622AC(p, index, out);
}












int func_0216202C(char *p, void *out, u8 *index)
{
    *index = ((EventSlots *)p)->f4;
    return func_021622D8(p, out);
}











void func_02162038(char *p, int index)
{
    func_02162330(p, index);
}











/*
 * The full target body overwrites r1/r2 with 0/8 before use; neither
 * caller nor thunk supplies those legacy trailing parameters.
 */
void func_02162040(char *p)
{
    func_02162358(p);
}












void func_02162048(u16 *a, int b, int c)
{
    EventSlot s;
    int t;

    if (func_0216210C((int)a) == 0) {
        func_02162298((EventSlots *)a, b, c);
        return;
    }
    t = d_0217144C[c];
    if (t != 4) {
        s.x = *a;
        s.b = b;
        s.t = t;
        func_0216220C(a, &s);
    }
}











/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 func_021871F8.
 */
int func_0216208C(char *p, int unused)
{
    if (((EventSlots *)p)->flags & 8)
        return 1;
    return 0;
}











u16 func_0216209C(char *p)
{
    return ((EventSlots *)p)->slot[3].t;
}











void func_021620A0(char *p)
{
    func_02162358(p);
    func_021622F4(p);
}











#pragma opt_propagation off










/*
 * pass 3 2026-10-06 P3L07: EXACT. The list is compacted: each empty 0x18-byte entry takes the next
 * used entry after it. The copy destination is written through a second base name dst (= p) under
 * pragma opt_propagation off, so `i * 0x18` is a common subexpression of two different bases. The
 * front end then makes the offset its own temporary local, which takes the stack slot below the
 * named counter i (sp+0 under sp+4), as in the image. With one base name the offset was a back-end
 * spill temporary above i (7 B, 92/92); without the pragma dst folds into p (7 B).
 */
void func_021620B0(char *p)
{
    int i;
    int j;
    char *dst;

    dst = p;
    i = 0;
    do {
        if (func_02161ECC((T *)(p + i * 0x18)) == 0) {
            for (j = i + 1; j < 10; j++) {
                if (func_02161ECC((T *)(p + j * 0x18)) != 0) {
                    func_02082D44(p + j * 0x18, dst + i * 0x18, 0x18);
                    func_02161E78(p + j * 0x18);
                    break;
                }
            }
        }
        i++;
    } while (i < 10);
}










#pragma opt_propagation reset











int func_0216210C(int a0)
{
    if (func_0200FB24() == 0)
        return 0;
    return 1;
}











void func_02162120(int a, int b, int c)
{
    u16 t[4];
    u16 s[4];
    int i;
    int r;

    for (i = 0; i < 3; i++) {
        if ((c & (1 << i)) == 0) {
            func_0216230C((char *)a, (u16)i);
        } else if (func_02162254((char *)a, i, s) != 0) {
            r = d_02172990[s[3]](a, b, s, t);
            func_0216230C((char *)a, (u16)i);
            if (r != 0)
                func_02162278((char *)a, (u16)i, t[2], t[3]);
        }
    }
}










int func_02162198(int unused, char *p, const EventSlot *s, EventSlot *out)
{
    out->x = s->x;
    out->b = s->b;
    if (func_02161DC4(p, s->b, 1) != 0) out->t = 0;
    else out->t = 1;
    return 1;
}










int func_021621C0(int unused, char *p, const EventSlot *s, EventSlot *out)
{
    out->x = s->x;
    out->b = s->b;
    if (func_02161DC4(p, s->b, 1) != 0) out->t = 2;
    else out->t = 3;
    return 1;
}














int func_021621E8(int unused, char *p, EventSlots *q)
{
    char *s;

    s = func_02161DC4(p, q->f4, 1);
    if (s != 0) {
        func_02161E78(s);
        func_02161E60(p, 1);
    }
    return 0;
}













void func_0216220C(u16 *p, EventSlot *s)
{
    if (s->x == *p) {
        func_02082D44(s, (char *)p + 0x20, 8);
        p[1] |= 8;
    }
}














/*
 * note:     caller 0x02162008 forwards all three of its arguments unchanged
 *           (r0-r2); the copy is MI_CpuCopy8-shaped (src, dst, 8) into the
 *           index-th eight-byte slot after an 8-byte head, then bit index of
 *           the u16 at +2 is set.
 */
void func_02162230(char *p, int index, void *s)
{
    func_02082D44(s, p + 8 + index * 8, 8);
    *(u16 *)(p + 2) = (u16)(*(u16 *)(p + 2) | (1 << index));
}













int func_02162254(char *p, u16 index, u16 *out)
{
    int result = 0;
    if (((EventSlots *)p)->flags & (1 << index)) {
        func_02082D44(&((EventSlots *)p)->slot[index], out, 8);
        result = 1;
    }
    return result;
}













void func_02162278(char *p, int index, u16 a, u16 b)
{
    /* stand-in: slot[index + 5].x/b/t stores compile 2 bytes shorter */
    *(int *)(p + 0x30 + index * 8) = index;
    *(u16 *)(p + 0x34 + index * 8) = a;
    *(u16 *)(p + 0x36 + index * 8) = b;
    ((EventSlots *)p)->flags = (u16)(((EventSlots *)p)->flags | (1 << (index + 5)));
}
















void func_02162298(EventSlots *s, int x, int y)
{
    int link;
    int flags;

    s->slot[4].t = y;
    link = s->f4;
    s->slot[4].b = x;
    flags = s->flags;
    s->slot[4].x = link;
    s->flags = flags | 0x10;
}













int func_021622AC(char *p, int index, void *out)
{
    int result = 0;
    if (((EventSlots *)p)->flags & (1 << (index + 5))) {
        func_02082D44(p + 0x30 + index * 8, out, 8);
        result = 1;
    }
    return result;
}













int func_021622D8(char *p, void *out)
{
    int result = 0;
    if (((EventSlots *)p)->flags & 16) {
        func_02082D44(&((EventSlots *)p)->slot[4], out, 8);
        result = 1;
    }
    return result;
}














void func_021622F4(char *p)
{
    func_02082BCC(&((EventSlots *)p)->slot[3], 0, 8);
    ((EventSlots *)p)->flags = ((EventSlots *)p)->flags & ~8;
}













/*
 * domain: Primary calls at 0216213C/0216216E receive loop index 0..2
 *   from 02162120 (zero at 0216212A; increment/test at 02162188..18C).
 *   ov011 02172D70 passes Work+0x35C through 02161F74 to 02162120.
 *   02172BC0 allocates 0x94C bytes and initializes that 0x48-byte record
 *   with 02161F54. The clear spans offsets 8..31; the mask reads offset 2.
 *   Thus primary shift counts 0..2 are defined; no arbitrary-u32 domain claim.
 */
void func_0216230C(char *p, unsigned i) { func_02082BCC(&((EventSlots *)p)->slot[i],0,8); ((EventSlots *)p)->flags = ((EventSlots *)p)->flags & ~(1<<i); }













/*
 * domain: Primary ov011 call 02174C8C reaches this through thunk 02162038.
 *   Its byte counter is zeroed at 02174C64..68, loaded at 02174C88, and
 *   increments/tests against 3 at 02174C90..9A: index 0..2, shifts 5..7.
 *   The record is Work+0x35C (02174C62/6A/8A); 02172BC0 allocates
 *   0x94C bytes and 02161F54 initializes this 0x48-byte record.
 *   Clears cover offsets 0x30..0x47; mask halfword offset 2 is initialized.
 *   No arbitrary-u32 domain claim: all primary arithmetic stays in range.
 */
void func_02162330(char *p, unsigned i) { func_02082BCC(p+0x30+i*8,0,8); ((EventSlots *)p)->flags = ((EventSlots *)p)->flags & ~(1<<(i+5)); }














void func_02162358(char *p)
{
    func_02082BCC(&((EventSlots *)p)->slot[4], 0, 8);
    ((EventSlots *)p)->flags = ((EventSlots *)p)->flags & ~0x10;
}












/*
 * Predicate: is the argument >= 7.
 *
 * Addresses are Black-image addresses.
 */
int func_02162370(int a)
{
return a >= 7;
}













int func_0216237C(int a)
{
    void **p = (void **)func_02030734(a, 0xAA8, 1, d_0217299C, 0xAF);
    p[1] = func_020490F4(0x7D, a);
    p[2] = func_020490F4(0x7E, a);
    p[3] = func_020490F4(0x39, a);
    return (int)p;
}













void func_021623BC(EventData *p)
{
    func_02049238((void *)p->arc);
    func_02049238((void *)p->f8);
    func_02049238((void *)p->fC);
    func_020307B0(p);
}










void func_021623DC(char *p) { func_02162530(p); (((EventData *)p)->p120)=p+0x2328; ((EventData *)p)->f34=0; ((EventData *)p)->flag=0; }










void func_02162408(char *p, u16 a1, u8 a2)
{
    func_021623DC(p);
    func_0216242C(p, a1, a2);
    func_02162438(p, a1, a2);
}













/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_021624B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216242C.c \
 *       --func func_0216242C --addr 0x0216242C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216242C(void *a0, u16 a1, u8 a2)
{
    ((EventData *)a0)->f10 = a1;
    func_021624B0(a0, a1);
}














void func_02162438(char *p, int a1, int a2)
{
    func_0215E2B8((struct R *)(p + 0x38), (int)((EventData *)p)->f8, a1, a2);
    ((EventData *)p)->f34 = 1;
}














/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02162450.c \
 *       --func func_02162450 --addr 0x02162450 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02162450(void *p) { return (u32)((EventData *)p)->p120; }














/*
 * Unlabelled thumb leaf (ldr r0,[r0,0x34]; bx lr), the sole blocker of
 * ov021 func_021892CC (lane S26).
 * Addresses are Black-image addresses.
 */
/*
 * Unlabelled thumb leaf (ldr r0,[r0,#0x34]; bx lr), the sole blocker of
 * ov021 func_021892CC (lane S26).
 * Addresses are Black-image addresses.
 */
u32 func_02162458(u8 *p)
{
    return ((EventData *)p)->f34;
}














/*
 * Unlabelled leaf: when idx is below the halfword count at +0x16, marks the
 * first two halfwords of the 0x14-byte record idx in the table at +0x24 as
 * 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
void func_0216245C(u8 *o, u16 idx)
{
    Trigger *t = ((EventData *)o)->box;

    if (((EventData *)o)->boxCount > idx) {
        t[idx].id = 0xFFFF;
        t[idx].kind2 = 0xFFFF;
    }
}













int func_02162478(char *p, int *v) { struct EventRec *r=((EventData *)p)->rec; u16 n,i; if(r) { n=((EventData *)p)->recCount; for(i=0;i<n;i++,r++) { if(func_02162F0C((char *)r,v) && r->f6==6) return 1; } } return 0; }















/*
 * pass 5 2026-10-06 P5L08: EXACT* (126 B code plus 2 B pad), also EXACT* under -lang c. The file is read
 * into o->size, then the header is parsed: o->p120 is the end of the data, and four sections follow the
 * four count bytes. Each section is its own block with a u8 count local, written in one uniform shape:
 * store the count, store the table pointer d + off, then add count * record size to off. The first
 * pointer is d + 0 (folded), the last section has no step. With this shape the zero offset, the 0x14
 * constant (r7) and h/d (r3/r2) get the original's colours; the earlier straight-line forms (one n local
 * per count, steps before the pointer stores, enum offset local) stayed at 54/126 or 102/128 in passes
 * 1 to 4.
 */
void func_021624B0(EventData *o, int x)
{
    int a;
    unsigned r;
    unsigned d;
    unsigned off;
    const H *h;

    a = func_02013ECC(x);
    r = func_020493D4(o->arc, a);
    func_0204944C(o->arc, a, 0, r, &o->size);
    off = 0;
    h = &o->hdr;
    d = (unsigned)h + 4;
    o->p120 = (char *)h + o->size;
    {
        u8 n = h->n[0];
        o->trigCount = n;
        o->trig = (Trigger *)(d + off);
        off += n * 0x14;
    }
    {
        u8 n = h->n[1];
        o->linkCount = n;
        o->link = (EventLink *)(d + off);
        off += n * 0x24;
    }
    {
        u8 n = h->n[2];
        o->boxCount = n;
        o->box = (Trigger *)(d + off);
        off += n * 0x14;
    }
    {
        u8 n = h->n[3];
        o->recCount = n;
        o->rec = (struct EventRec *)(d + off);
    }
    o->saveTrigCount = o->trigCount;
    o->saveLinkCount = o->linkCount;
    o->saveBoxCount = o->boxCount;
    o->saveRecCount = o->recCount;
}













void func_02162530(char *p) { ((EventData *)p)->saveTrigCount=0; ((EventData *)p)->saveLinkCount=0; ((EventData *)p)->saveBoxCount=0; ((EventData *)p)->saveRecCount=0; ((EventData *)p)->trigCount=0; ((EventData *)p)->linkCount=0; ((EventData *)p)->boxCount=0; ((EventData *)p)->recCount=0; ((EventData *)p)->trig=0; ((EventData *)p)->link=0; ((EventData *)p)->box=0; ((EventData *)p)->rec=0; func_02082BCC(p+0x128,0,0x880); }














/*
 * Addresses are Black-image addresses.
 */
u32 func_0216255C(u32 a)
{
    return a + 0x38;
}














/*
 * Unlabelled leaf getter: the halfword at +0x16.  Blocker of ov061
 * func_021F388C.
 */
u16 func_02162560(u8 *p)
{
    return ((EventData *)p)->boxCount;
}













/*
 * note: same shape as func_02162598 with the callee func_02162D2C.
 */
int func_02162564(char *p, struct Q *q) { int i; Trigger *r; i=0; r=((EventData *)p)->box; for(;i<((EventData *)p)->boxCount;i++,r++) { if(func_02162D2C(r,(const int *)q)) return i; } return 0xffff; }









int func_02162598(char *p, struct Q *q) { int i; Trigger *r; i=0; r=((EventData *)p)->box; for(;i<((EventData *)p)->boxCount;i++,r++) { if(func_02162E00(r,q)) return i; } return 0xffff; }









void *func_021625CC(char *p, unsigned i) { Trigger *r=((EventData *)p)->box; if(!r) return 0; if(i>=((EventData *)p)->boxCount) return 0; return r+i; }










/*
 * Unlabelled leaf, callee of ov020 func_02185360.
 */
int func_021625E8(R *p)
{
    if (p->h2 == 0x100) {
        return 1;
    }
    return 0;
}









/*
 * extent: 150-byte function followed by two alignment bytes at 02162692.
 * lever: read-only const source parameter schedules the final signed-id
 * truncation after the argument loads; exact callee widths keep B on r1.
 * interface: callee argument id is s16 as caller's explicit asrs shows;
 * k stays full-width because the original forwards it without truncation.
 */
int func_021625FC(const u8 *q, int *out, int id, int k)
{
    u8 *r;
    A s;
    B t;
    r = func_021625CC((char *)q, id);
    if (r == 0) return 0;
    func_020140F8((int)out);
    if (((Trigger *)r)->kind2 == 0x100) *out = 3;
    else *out = 2;
    if (((Trigger *)r)->mode == 0) {
        func_02162C84((Trigger *)r, k, (int *)(&s));
        func_02014110(out, ((EventData *)q)->f10, id, r[4], k, s.x, s.y, s.z);
    } else {
        func_02162D90((const Trigger *)r, k, (struct Out *)(&t));
        func_02014134(out, ((EventData *)q)->f10, id, r[4], k, t.a, t.d, t.c);
    }
    return 1;
}










void func_02162694(Trigger *b, int a1, int a2)
{
    func_0201416C(a1, b->id, b->kind2, a2);
}










/*
 * Unlabelled leaf, blocker of ov021 func_0218AD80: compiler tail call (ldr r3,=; bx r3) of
 * func_02162B68; not a linker veneer.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 func_021626A8(void *b, void *pos)
{
    return func_02162B68(b, pos);
}










/*
 * Unlabelled tail-call wrapper over func_02162BCC (a pool word plus bx r3,
 * no prologue); witness for ov021 func_0218B2E8.
 */
u16 func_021626B0(void *b, void *q)
{
    return func_02162BCC(b, q);
}










/*
 * Recursive MATCH unblocker: ABS32 target of func_0218AECC (ov021) +0004.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 */
int func_021626B8(char *a0, int a1)
{
    if ((a1 == 0 && ((EventState *)a0)->f4 == 2) ||
        (a1 == 1 && ((EventState *)a0)->f4 == 1) ||
        (a1 == 2 && ((EventState *)a0)->f4 == 4) ||
        (a1 == 3 && ((EventState *)a0)->f4 == 3))
        return 1;
    return 0;
}











/*
 * Reads the byte field at +0x5.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021626E8(u8 *p)
{
    return ((EventState *)p)->f5;
}










/*
 * Unlabelled leaf (a .word run in the ov010 listing): true when either of
 * the first two halfwords is 0xFFFF.  Callee of ov021 func_0218B0CC.
 * Addresses are Black-image addresses.
 */
int func_021626EC(u16 *p)
{
    if (p[0] == 0xFFFF || p[1] == 0xFFFF)
        return 1;
    return 0;
}










void func_02162708(EventData *c, u32 idx, u16 a, u32 b, u16 e)
{
    Trigger *p;
    if (c->boxCount >= idx && c->box != 0) {
        p = &c->box[idx];
        if (p->mode == 0) {
            /* stand-in: p->u.cell.b/c stores compile 4 bytes shorter */
            u16 *q;
            u16 t = (a << 4) + 8;
            q = &p->u.cell.a;
            p->u.cell.a = t;
            q[1] = b << 4;
            q[2] = (e << 4) + 8;
        }
    }
}











/*
 * Reads the word field at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02162740(u8 *p)
{
    return (u32)((EventData *)p)->link;
}












/*
 * Reads the halfword field at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162744(u8 *p)
{
    return ((EventData *)p)->linkCount;
}











/*
 * Unlabelled leaf: when idx is below the halfword count at +0x14 and the
 * 0x24-byte record idx in the table at +0x20 has a zero word at +0x18, fills
 * the record: halfword at +0xC, then a sub-record at +0x1C (halfword, halfword,
 * word). The last two arguments are stack arguments (word, halfword).
 *
 * 2026-10-05 note: the guard reads o->tbl[idx].busy and the body takes
 * &o->tbl[idx] again. Taking the pointer once before the guard gives the
 * table load before the 0x24 constant (7 bytes off).
 *
 * Addresses are Black-image addresses.
 */
void func_02162748(EventData *o, u32 idx, u16 a, u16 b, u32 w, u16 h)
{
    if (idx < o->linkCount) {
        if (o->link[idx].busy == 0) {
            EventLink *r = &o->link[idx];
            EventLinkSub *s = &r->s;
            r->a = a;
            s->x = b;
            s->w = w;
            s->h = h;
        }
    }
}










void func_02162774(char *p, unsigned i, u16 v) { if(i < ((EventData *)p)->linkCount) *(u16 *)((char *)((EventData *)p)->link+i*0x24+2)=v; }










void func_02162788(char *p, unsigned i, u16 v) { if(i < ((EventData *)p)->linkCount) *(u16 *)((char *)((EventData *)p)->link+i*0x24+10)=v; }










u16 func_0216279C(int mode) {
    switch(mode) { case 0: return 1; case 1: return 2; case 2: return 3; case 3: return 4; default: return 0; }
}











struct EventRec *func_021627C8(EventData *c, void *a, int key, int mode)
{
    struct EventRec *r = c->rec;
    u16 v;
    u16 t;
    u16 i;
    u16 n;
    if (r != 0) {
        t = func_0216279C(mode);
        i = 0;
        n = c->recCount;
        for (; i < n; i++, r++) {
            if (func_02162F0C((char *)r, (int *)key) != 0 && r->f6 == t) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}










struct EventRec *func_0216282C(EventData *c, void *a, int *key, int mode)
{
    struct EventRec *r = c->rec;
    u16 v;
    u16 t;
    u16 i;
    u16 n;
    if (r != 0) {
        t = func_0216279C(mode);
        i = 0;
        n = c->recCount;
        for (; i < n; i++, r++) {
            if (func_02162F74((char *)r, key) != 0 && r->f6 == t) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}










struct EventRec *func_02162890(EventData *c, void *a, int key)
{
    struct EventRec *r = c->rec;
    u16 i;
    u16 n;
    u16 v;
    if (r != 0) {
        n = c->recCount;
        for (i = 0; i < n; i++, r++) {
            if (func_02162F0C((char *)r, (int *)key) != 0 && r->f6 == 6) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}










struct EventRec *func_021628E4(EventData *c, void *a, int key)
{
    struct EventRec *r = c->rec;
    u16 i;
    u16 n;
    u16 v;
    if (r != 0) {
        n = c->recCount;
        for (i = 0; i < n; i++, r++) {
            if (func_02162FC8((char *)r, (u16 *)key) != 0) {
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}









u16 func_02162928(void *p, void *q, int key, int mode) { u16 *r=(u16 *)func_021627C8(p,q,key,mode); if(r) return *r; return 0xffff; }









u16 func_02162940(void *p, void *q, int key) { u16 *r=(u16 *)func_02162890(p,q,key); if(r) return *r; return 0xffff; }










u16 func_02162958(void *c, void *a, int key)
{
    u16 *r = (u16 *)func_021628E4(c, a, key);
    if (r != 0) return *r;
    return 0xffff;
}











/*
 * Finds the trigger that fires at a place: walks the 0x14-byte entries,
 * tests position (mode 0) or map cell (mode 1), then filters by entry
 * kind against the facing/type argument. Answers the entry id or 0xFFFF.
 *
 * Levers (2026-09-28 tree_ov010_4): one guarded body (single 0xFFFF
 * exit), the count held in a u32 local (a u16 local is re-read from its
 * spill slot before the guard), and case 5 as `type == 2 || type == 3`,
 * which 1.1p1 folds to a loop-hoisted `(u16)(type + 0xFFFE) <= 1`
 * (`(u16)(type - 2) <= 1` gives `subs 2` instead).
 */
u16 func_02162970(EventData *set, void *flags, const void *where, u16 type)
{
    Trigger *t;
    u16 i;
    u32 count;

    t = set->trig;
    if (t != 0) {
    count = set->trigCount;
    for (i = 0; i < count; i++, t++) {
        if (t->mode == 0) {
            if (!func_02162E48(t, where))
                continue;
        } else {
            if (!func_02162E9C(t, where))
                continue;
        }
        if (t->kind2 == 2) {
            if (func_020142E8(flags, func_02164708(t->id)) == 0)
                return t->id;
            continue;
        }
        switch (t->kind) {
        case 0:
            if (type == 0)
                return t->id;
            break;
        case 1:
            if (type == 3)
                return t->id;
            break;
        case 2:
            if (type == 2)
                return t->id;
            break;
        case 3:
            if (type == 1)
                return t->id;
            break;
        case 4:
            return t->id;
        case 5:
            if (type == 2 || type == 3)
                return t->id;
            break;
        case 6:
            if (type <= 1)
                return t->id;
            break;
        }
    }
    }
    return 0xFFFF;
}











/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to func_02162970.  Callee of ov021 func_02189BD0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162A54(void *set, void *flags, const void *where, u16 type)
{
    return func_02162970(set, flags, where, type);
}











/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to func_02162970.  Callee of ov021 func_0218A278.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162A5C(void *set, void *flags, const void *where, u16 type)
{
    return func_02162970(set, flags, where, type);
}











/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162CE8.  Blocker of ov061 func_021F388C.
 */
void func_02162A64(const void *p, V3 *out)
{
    func_02162CE8(p, out);
}











/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162ECC.  Blocker of ov021 func_021AFDAC.
 */
void func_02162A6C(int a, int b)
{
    func_02162ECC((const char *)a, (int *)b);
}










static inline void set(Trigger *r, u32 a, u32 b, u16 d)
{
    s32 *p = (s32 *)((u8 *)r + 8);
    r->u.data[0] = a;
    p[1] = d;
    p[2] = b << 4;
}










/*
 * extent: 46 code bytes followed by two zero alignment bytes.
 * lever: inline setter takes the whole Rec_02162A74 and all three payload inputs;
 * its own Payload pointer preserves the parent base and explicit +8 copy.
 * domain: unsigned index comparison and modular word address arithmetic.
 */
void func_02162A74(const EventData *c, u32 i, u32 a, u32 b, u16 d)
{
    Trigger *r;
    if (c->trigCount >= i && c->trig != 0) {
        r = (Trigger *)((u32)c->trig + i * 20u);
        if (r->mode == 0) {
            set(r, a, b, d);
        }
    }
}











/*
 * note 2026-10-05: the old draft (DIFF45) wrote the tail as a do/while(0) with a goto.
 * The branch-to-branch stubs are the tail `a = hw + (a - h)` written out in each arm
 * (cross-jumped later). `long w = n` keeps the final `a >= n` reload from the stack slot;
 * `hw` is unsigned (lsrs). EXACT* = 2 byte trailing pad (194 of 196 listing extent).
 */
u16 func_02162AA4(int v, int m, int flag, int dir, u16 n)
{
    int b, a, c;
    unsigned h, hw;
    int d;
    long w;
    if (v == 0)
        return 0;
    b = (v & 0xf0) >> 4;
    a = v & 0xf;
    c = (v & 0xf00) >> 8;
    if ((c == 0 && m == 3) || (c == 1 && m == 2) || (c == 3 && m == 0) || (c == 2 && m == 1))
        a = (b - 1) - a;
    if (flag != 0) {
        switch (dir) {
        case 0:
            if ((unsigned)(c - 2) <= 1)
                a = (b - 1) - a;
            break;
        case 1:
            if ((unsigned)c <= 1)
                a = (b - 1) - a;
            break;
        case 2:
            a = (b - 1) - a;
            break;
        }
    }
    w = n;
    h = (unsigned)b / 2;
    d = w - b;
    hw = (unsigned)w / 2;
    if (d != 0) {
        if (d % 2 != 0) {
            if (w % 2 != 0) {
                if (a < h) {
                    h = h - 1;
                    a = hw + (a - h);
                } else {
                    a = hw + (a - h);
                }
            } else {
                if (a <= h) {
                    a = (hw - 1) + (a - h);
                    goto clamp;
                } else {
                    a = hw + (a - h);
                }
            }
        } else {
            a = hw + (a - h);
        }
    }
clamp:
    if (a < 0)
        a = 0;
    else if (a >= n)
        a = w - 1;
    return a;
}











u16 func_02162B68(Trigger *b, int *pos)
{
    struct Sub *s;
    int m = func_02162C54((u8 *)b);
    s = &b->u.sub;
    if (s->f6 > 1)
        return (s->f6 << 4) | (((pos[0] >> 12) - (s16)s->f0) / 16) | (m << 8);
    if (s->f8 > 1)
        return (s->f8 << 4) | (((pos[2] >> 12) - s->f4) / 16) | (m << 8);
    return (m << 8) | 0x10;
}







u16 func_02162BCC(Trigger *b, struct Q *q)
{
    struct Sub *s = &b->u.sub;
    int a = 0;
    int c = 0;
    int m = func_02162C54((u8 *)b);
    int d;
    switch (s->fa) {
    case 0:
        a = 1;
        break;
    case 1:
        c = 1;
        break;
    case 2:
        a = 1;
        c = 1;
        break;
    case 3:
        break;
    }
    if (s->f8 > 1) {
        d = q->f4 - s->f4;
        if (c != 0)
            d = s->f8 - 1 - d;
        return (s->f8 << 4) | d | (m << 8);
    }
    if (s->f6 > 1) {
        d = q->f6 - s->f2;
        if (a != 0)
            d = s->f6 - 1 - d;
        return (s->f6 << 4) | d | (m << 8);
    }
    return 0x10 | (m << 8);
}









/*
 * lever: case 0 falls through into default at the final shared return.
 */
int func_02162C54(u8 *p)
{
    switch (p[4]) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 0:
    default: return 1;
    }
}










void func_02162C84(Trigger *b, int q, int *out)
{
    struct Sub *s = &b->u.sub;
    int m = func_02162C54((u8 *)b);
    out[0] = (s16)b->u.sub.f0 << 12;
    out[1] = (s16)s->f2 << 12;
    out[2] = s->f4 << 12;
    if (s->f6 > 1) {
        out[0] += func_02162AA4(q, m, 0, 0, s->f6) << 16;
    } else if (s->f8 > 1) {
        out[2] += func_02162AA4(q, m, 0, 0, s->f8) << 16;
    }
}









/*
 * Unlabelled leaf (push {r3, r4} with no lr), reached through the ov010
 * tail-call thunk func_02162A64.  Blocker of ov061 func_021F388C.
 * The const on both pointers keeps the first ldrsh ahead of the base
 * copy; the lsrs needs the u32 casts.
 */
void func_02162CE8(const Obj_02161E60 *p, V3 *out)
{
    const Box_02162CE8 *b = &p->box;

    out->a = b->x << 12;
    out->b = b->y << 12;
    out->c = b->z << 12;
    if (b->w > 1) {
        out->a += ((u32)b->w >> 1) << 16;
    } else if (b->h > 1) {
        out->c += ((u32)b->h >> 1) << 16;
    }
}








/*
 * following: two-byte alignment padding at 02162D8E.
 * lever: assign the Sub_02162C54 pointer before the position loads; signed x0 has
 * the field's s16 width. Bounded permuter first closed this spelling.
 */
int func_02162D2C(const Trigger *b, const int *pos)
{
    const struct Sub *s;
    s16 x0;
    int z;
    int y;
    int x;
    if ((int)(b->mode == 1)) return 0;
    s = &b->u.sub;
    x = pos[0] >> 12;
    y = pos[1] >> 12;
    z = pos[2] >> 12;
    x0 = (s16)b->u.sub.f0;
    if (x0 <= x && x0 + (s->f6 - 1) * 16 >= x
        && (s16)s->f2 - 2 <= y && (s16)s->f2 + 2 >= y
        && s->f4 <= z && s->f4 + (s->f8 - 1) * 16 >= z)
        return 1;
    return 0;
}







/*
 * lever: const source pointer schedules fa between the signed load and output store.
 * following: two-byte alignment padding at 0x02162DFE.
 */
void func_02162D90(const Trigger *b, int q, struct Out *o)
{
    const struct Sub *s = &b->u.sub;
    int m = func_02162C54((u8 *)b);
    u16 fa;
    o->f0 = b->u.sub.f0;
    o->f2 = 1;
    o->f3 = func_0201441C(m);
    o->f4 = s->f4;
    fa = s->fa;
    o->f6 = s->f2;
    if (s->f8 > 1) {
        o->f4 = o->f4 + (s16)func_02162AA4(q, m, 1, fa, s->f8);
    } else if (s->f6 > 1) {
        o->f6 = o->f6 + func_02162AA4(q, m, 1, fa, s->f6);
    }
}








int func_02162E00(Trigger *b, struct Q *q)
{
    struct Sub *s;
    if (b->mode == 0)
        return 0;
    s = &b->u.sub;
    if (s->f0 == q->f0 && s->f2 <= q->f6 && s->f2 + s->f6 > q->f6
        && s->f4 <= q->f4 && s->f4 + s->f8 > q->f4)
        return 1;
    return 0;
}








/*
 * Position trigger test: an entry of mode 0 matches when the grid cell of
 * pos equals (x, z) and its height is within 2 of the entry's.
 */
int func_02162E48(Trigger *t, const VecFx32 *pos)
{
    s32 gx;
    s32 gy;
    s32 gz;
    TrigPos *p;

    if (t->mode == 1)
        return 0;
    p = &t->u.pos;
    gz = (pos->z >> 4) / 4096;
    gy = pos->y >> 12;
    gx = (pos->x >> 4) / 4096;
    if (p->x == gx && p->z == gz && p->y - 2 <= gy && p->y + 2 > gy)
        return 1;
    return 0;
}








/*
 * Map-cell trigger test: an entry of mode 1 matches the three location
 * halfwords of p.
 */
int func_02162E9C(Trigger *t, const CellKey *k)
{
    TrigCell *c;

    if (t->mode == 0)
        return 0;
    c = &t->u.cell;
    if (c->a == k->a && c->b == k->b && c->c == k->c)
        return 1;
    return 0;
}







/*
 * lever: const source pointer hoists the last halfword load before the output store.
 */
void func_02162ECC(const char *p, int *out)
{
    const u16 *q = (const u16 *)(p + 10);
    int y, x, z;
    z = func_0207C768(q[3] << 16, 0x2000);
    z = ((unsigned)q[1] << 16) + z;
    y = ((const s16 *)q)[4] << 12;
    x = func_0207C768(q[2] << 16, 0x2000);
    out[2] = z;
    out[0] = ((unsigned)((struct EventRec *)p)->area[0] << 16) + x;
    out[1] = y;
}








int func_02162F0C(char *p, int *v)
{
    u16 *q;
    int x, y, z;

    if (((struct EventRec *)p)->f8 == 1) {
        return 0;
    }
    q = (u16 *)(p + 10);
    x = (v[0] >> 4) / 0x1000;
    z = (v[2] >> 4) / 0x1000;
    y = v[1] >> 12;
    if (((struct EventRec *)p)->area[0] <= x && ((struct EventRec *)p)->area[0] + q[2] > x
        && q[1] <= z && q[1] + q[3] > z
        && ((s16 *)q)[4] - 2 <= y && ((s16 *)q)[4] + 2 > y) {
        return 1;
    }
    return 0;
}








int func_02162F74(char *p, int *v)
{
    u16 *q;
    int x, z;

    if (((struct EventRec *)p)->f8 == 1) {
        return 0;
    }
    q = (u16 *)(p + 10);
    x = (v[0] >> 4) / 0x1000;
    z = (v[2] >> 4) / 0x1000;
    if (((struct EventRec *)p)->area[0] <= x && ((struct EventRec *)p)->area[0] + q[2] > x
        && q[1] <= z && q[1] + q[3] > z) {
        return 1;
    }
    return 0;
}








int func_02162FC8(char *p, u16 *v)
{
    u16 *q;

    if (((struct EventRec *)p)->f8 == 0) {
        return 0;
    }
    q = (u16 *)(p + 10);
    if (((struct EventRec *)p)->area[0] == v[0] && q[1] <= v[3] && q[1] + q[3] > v[3]
        && ((s16 *)q)[2] <= ((s16 *)v)[2] && ((s16 *)q)[2] + q[4] > ((s16 *)v)[2]) {
        return 1;
    }
    return 0;
}








/*
 * Unblocked by the recursive MATCH unblocker: the +000A call targets
 * 0x0219B414, a labelless Thumb tail-call thunk in ov021 now matched in
 * src/matched/ov021_func_0219B414.c, so the site attests as `matched`.
 */
u32 *func_02163010(void *p)
{
    func_0216D6F4(p);
    func_0219B414((int)p);
    return func_0216D548(p, 2);
}








void func_02163028(void *a)
{
    int t = 2;

    if (func_0216DA20((void *)a, t) == 0) {
        func_021630F4(a);
        func_0216310C((char *)a);
        func_02163130((char *)a);
        if (func_0216D57C(a, t << 8) != 0) {
            func_02197EB4((u32)a);
        } else if (func_0216DB10((void *)a) == 0) {
            if (func_02163090(a) == 1) {
                if (func_0219B41C(a) == 0) {
                    func_0216D708((void *)a);
                }
            }
        }
        func_02163154((char *)a);
        func_02163188((char *)a);
    }
}








int func_02163090(void *p)
{
    u32 flags;

    if (func_0216DA5C(p) == 0) {
        if (func_0216D57C(p, 0x1800) == 0)
            return 1;
        if (func_0216D5A0(p) == 0x32)
            return 1;
        flags = func_0216D564(p);
        if ((flags & 0x1000) != 0 && func_0216DB68(p) == 0)
            return 0;
        if ((flags & 0x800) != 0 && func_0216DCB4(p) == 0)
            return 0;
    }
    return 1;
}









int func_021630F4(void *p)
{
    u32 r = func_0216D57C(p, 0x1000);

    if (r != 0)
        return func_02164010((int)p);
    return r;
}








/*
 * trailing: two-byte zero alignment at 0x0216312E before func_02163130.
 */
void func_0216310C(char *p)
{
    if (func_0216D57C(p, 0x800) != 0 && func_021640B0((int)p) == 1)
        func_0216DA70(p);
}








void func_02163130(char *p)
{
    if (func_0216D57C(p, 0x20)) {
        func_021641C8(p);
        func_02163230((int)p);
    }
    func_0216D570(p, 0xa0);
}







/*
 * trailing: two-byte zero alignment at 0x02163186 before func_02163188.
 */
void func_02163154(char *p)
{
    if (func_0216D57C(p, 0x80)) func_021632F0((int)p);
    else if (func_0216D57C(p, 0x20)) func_02163288((int)p);
    func_0216D570(p, 0xa0);
}







/*
 * trailing: two-byte zero alignment at 0x021631BE before func_021631C0.
 */
void func_02163188(char *p)
{
    if (func_0216D57C(p, 0x100)) func_021633A8((int)p);
    else if (func_0216D57C(p, 0x40)) func_02163340((int)p);
    func_0216D570(p, 0x140);
}








void func_021631C0(int a, EventInfo *s)
{
    int b;
    u32 h;

    func_02082C60(s, 0, 0x1c);
    s->a = func_0216D7E4((void *)a);
    b = func_0216D7DC((void *)a);
    s->b = b;
    if (b != -1) {
        s->d = func_021AB0F0(b);
        s->f = func_021AB0F8(s->b);
    }
    if (s->a != -1) {
        s->c = func_021AB0F0(s->a);
        s->e = func_021AB0F8(s->a);
    }
    s->g = func_0216E3C4((void *)a);
    h = func_02188CD0((u8 *)func_0216D534((void *)func_0216D67C((void *)a)));
    s->h = h;
    s->i = func_021ABE28((u8 *)h);
}







void func_02163230(int a0)
{
    EventInfo fr;
    void *p = (void *)a0;

    func_021640B0(a0);
    if (func_0216D57C(p, 0x800) == 0 && func_0216DB24(a0) == 1) {
        func_021631C0(a0, &fr);
        func_021634D8(p, &fr);
        func_02163618(p, &fr);
        func_021636F0(p, &fr);
        func_02163418(p, &fr);
        func_021637E4(p, &fr);
    }
}







void func_02163288(int a0)
{
    EventInfo fr;
    void *p = (void *)a0;

    func_021640B0(a0);
    if (func_0216D57C(p, 0x800) == 0 && func_0216DB24(a0) == 1) {
        func_021631C0(a0, &fr);
        func_021634FC(p, &fr);
        func_02163580(p, &fr);
        func_02163650(p, &fr);
        func_021636F0(p, &fr);
        func_0216377C(p, &fr);
        func_021637E4(p, &fr);
        func_021638C8(p, &fr);
    }
}







void func_021632F0(int a0)
{
    EventInfo fr;
    void *p = (void *)a0;

    func_021640B0(a0);
    if (func_0216D57C(p, 0x800) == 0 && func_0216DB24(a0) == 1) {
        func_021631C0(a0, &fr);
        func_021636F0(p, &fr);
        func_021637E4(p, &fr);
        func_0216369C(p, &fr);
        func_021638C8(p, &fr);
    }
}







void func_02163340(int a0)
{
    EventInfo fr;
    void *p = (void *)a0;

    func_021640B0(a0);
    if (func_0216D57C(p, 0x800) == 0 && func_0216DB24(a0) == 1) {
        func_021631C0(a0, &fr);
        func_02163418(p, &fr);
        func_0216352C(p, &fr);
        func_021637B0(p, &fr);
        func_02163650(p, &fr);
        func_02163868(p, &fr);
        func_0216372C(p, &fr);
        func_021638AC(p, &fr);
    }
}







void func_021633A8(int a0)
{
    EventInfo fr;
    void *p = (void *)a0;

    func_021640B0(a0);
    if (func_0216D57C(p, 0x800) == 0 && func_0216DB24(a0) == 1) {
        func_021631C0(a0, &fr);
        func_02163418(p, &fr);
        func_021637B0(p, &fr);
        func_02163650(p, &fr);
        func_02163868(p, &fr);
        func_0216372C(p, &fr);
        func_0216355C(p, &fr);
        func_0216375C(p, &fr);
        func_021638AC(p, &fr);
    }
}









static inline void vzero(V *p)
{
    p->x = 0;
    p->y = 0;
    p->z = 0;
}









/*
 * lever: block-local cast byte buffer keeps the zeroing pointer on the zero path.
 */
void func_02163418(void *p, EventInfo *s)
{
    V v;
    if (func_0216DC00(p) == 0 && func_021AB41C(s->d) != 0) {
        v = d_021714D0;
        func_0216D900((int)p, &v);
        return;
    }
    {
        unsigned char buf[12];
        V *z = (V *)buf;
        vzero(z);
        func_0216D900((int)p, z);
    }
}










int func_02163464(u16 id, u8 dir)
{
    int kind = 0;

    if (func_021AB4EC(id) != 0) {
        kind = 6;
    } else if (func_021AB4F8(id) != 0) {
        kind = 7;
    } else if (func_021AB434(id) != 0) {
        kind = 1;
        if (dir == 3)
            kind = 5;
    } else if (func_021AB428(id) != 0) {
        if (dir == 3)
            kind = 4;
    } else if (func_021AB250(id) != 0) {
        kind = 1;
    } else if (func_021AB264(id) != 0) {
        kind = 2;
    } else if (func_021AB270(id) != 0) {
        kind = 3;
    }
    return kind;
}










void func_021634D8(void *p, EventInfo *s)
{
    int kind;

    if (s->f & 0x20) {
        kind = func_02163464(s->d, s->i);
        func_021AC760(s->h, (u32)p, 0, kind);
    }
}








/*
 * trailing: two-byte zero alignment at 0x0216352A before func_0216352C.
 */
void func_021634FC(void *p, EventInfo *s)
{
    int flag;
    int kind;
    if (s->f & 0x20) {
        flag = func_0216D608(p);
        kind = func_02163464(s->d, s->i);
        if (flag != 0)
            func_021AC760(s->h, (u32)p, 1, kind);
    }
}







/*
 * trailing: two-byte zero alignment at 0x0216355A before func_0216355C.
 */
void func_0216352C(void *p, EventInfo *s)
{
    int flag;
    int kind;
    if (s->f & 0x20) {
        flag = func_0216D608(p);
        kind = func_02163464(s->d, s->i);
        if (flag == 0)
            func_021AC760(s->h, (u32)p, 1, kind);
    }
}







void func_0216355C(void *p, EventInfo *s)
{
    int kind;

    if (s->f & 0x20) {
        kind = func_02163464(s->d, s->i);
        func_021AC760(s->h, (u32)p, 1, kind);
    }
}







void func_02163580(void *p, EventInfo *s)
{
    int kind;

    if (s->e & 8) {
        kind = 5;
        if (func_021AB3D4(s->c) != 0) {
            if (s->i == 3) {
                kind = 2;
                if (s->g->f5 == 2)
                    kind = 3;
            }
        } else if (func_021AB3E0(s->c) != 0) {
            if (s->i == 0 || s->i == 3) {
                kind = 2;
                if (s->g->f5 == 2)
                    kind = 3;
            }
        } else if (func_021AB334(s->c) == 1 || func_021AB328(s->c) == 1) {
            kind = 2;
            if (s->g->f5 == 2)
                kind = 3;
        } else if (func_021AB41C(s->c) == 1) {
            kind = 4;
        } else {
            kind = 0;
            if (s->g->f5 == 2)
                kind = 1;
        }
        if (kind != 5)
            func_021BBDD4(p, s->h, kind);
    }
}




int func_02163618(void *p, EventInfo *s)
{
    int r;

    if (func_021AB304(s->d) == 1) {
        r = func_0216DBE8(p);
        if (r != 0)
            return r;
        func_021C4BE0(s->h, p);
        return func_0216DBCC(p, 1);
    }
    return func_0216DBCC(p, 0);
}




int func_02163650(void *p, EventInfo *s)
{
    int r;

    if (func_021AB304(s->d) == 1) {
        r = func_0216DBE8(p);
        if (r != 0)
            return r;
        func_021C4BE0(s->h, p);
        return func_0216DBCC(p, 1);
    }
    if (func_021AB364(s->d) == 1)
        return func_021C4A10(s->h, p);
    return func_0216DBCC(p, 0);
}




void func_0216369C(void *p, EventInfo *s)
{
    func_0216DBCC(p, 0);
}




int func_021636A8(void *p, EventInfo *s)
{
    if (func_0216D98C((int)func_0216D67C(p)) == 0 || s->g->f4 == 0)
        return 0;
    return 1;
}




int func_021636C8(EventInfo *s)
{
    if ((s->f & 0x80) == 0)
        return 0;
    if (s->i == 3 && func_021AB3D4(s->d) != 0)
        return 0;
    return 1;
}






void func_021636F0(void *p, EventInfo *s)
{
    if (func_021636A8(p, s) == 1 && func_021636C8(s) == 1) {
        if (func_0216D57C(p, 0x4000) == 0) {
            func_021AC2C0(p, s->h);
            func_0216D568(p, 0x4000);
        }
    }
}






void func_0216372C(void *p, EventInfo *s)
{
    if (func_021636A8(p, s) == 1) {
        if (func_021636C8(s) == 0) {
            func_0216D568(p, 0x8000);
            return;
        }
        func_0216D570(p, 0x8000);
    }
}





void func_0216375C(void *p, EventInfo *s)
{
    if (!(s->f & 2) && !func_0216DD04(p))
        func_021AC528((u32)p, s->h);
}






void func_0216377C(void *p, EventInfo *s)
{
    int x, y, z;

    if (func_021AB2F8(s->c) == 1) {
        x = func_0216D804(p);
        y = func_0216D81C(p);
        z = func_0216D8AC(p);
        func_021C484C(s->h, x, y, z);
    }
}






void func_021637B0(void *p, EventInfo *s)
{
    int x, y, z;

    if (func_021AB2F8(s->d) == 1) {
        x = func_0216D83C(p);
        y = func_0216D86C(p);
        z = func_0216D8AC(p);
        func_021C484C(s->h, x, y, z);
    }
}






void func_021637E4(void *p, EventInfo *s)
{
    int r4, r7, obj;

    if (s->g->f6 == 0) {
        return;
    }
    if (func_0216DC34(p) != 0) {
        return;
    }
    r4 = -1;
    if (s->f & 0x40) {
        r4 = s->b;
    } else {
        r7 = func_02163F40((int)p, 1);
        if (func_021AB0F8(r7) & 0x40) {
            r4 = r7;
        }
    }
    if (r4 == -1) {
        return;
    }
    r7 = 1;
    r4 = func_021AB0F0(r4);
    obj = (int)func_0216D67C(p);
    if (func_021AB440(r4) == 1 || func_021AB358(r4) == 1) {
        r7 = 2;
    }
    func_021BBFB8(obj, (u32)p, s->h, r7);
    func_0216DC18(p, 1);
}






void func_02163868(void *p, EventInfo *s)
{
    if (s->g->f6 != 0 && func_0216DC34(p) != 0) {
        int r = func_02163F40((int)p, 1);

        if (r == -1) {
            func_0216DC18(p, 0);
            return;
        }
        if ((func_021AB0F8(r) & 0x40) == 0) {
            func_0216DC18(p, 0);
        }
    }
}






/*
 * unblocked: func_021C8F7C is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 28 bytes against 26 compiled: the unlabelled follower that
 *   precedes ov021's next entry (its bytes are the original's 2-byte pad).
 */
void func_021638AC(void *p, EventInfo *s)
{
    if (func_021AB3EC(s->d) == 1)
        func_021C8F7C(p, s->h);
}








void func_021638C8(void *p, EventInfo *s)
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
u32 func_021638CC(void *m, Obj_021636F0 *o, s16 x, s16 y, int z, u16 kind)
{
    u32 flags = 0;
    VecFx32 pos;
    fx32 h;

    pos.x = (x << 16) + 0x8000;
    pos.y = o->f04;
    pos.z = (*(s16 *)&z << 16) + 0x8000;
    if (func_02163C9C((int)m, x, *(s16 *)&z) == 1)
        flags |= 1;
    if (func_02163D04(m, kind, pos) == 1)
        flags |= 2;
    if (func_02163E58(m, &pos, &h) == 1) {
        fx32 d = o->f04 - h;
        if (d < 0)
            d = -d;
        if (d >= 0x14000)
            flags |= 8;
        y = (h >> 4) / 0x1000;
    } else {
        flags |= 8;
    }
    if (func_02163BAC((int)m, x, y, *(s16 *)&z) == 1)
        flags |= 4;
    if (func_0218DC04((struct Grid *)func_0216D52C(func_0216D67C(m)), &pos) == 1)
        flags |= 0x10;
    return flags;
}




/*
 * trailing: two-byte zero alignment at 0x021639BE before func_021639C0.
 */
u32 func_02163994(void *p, s16 x, s16 y, int z, u16 kind)
{
    VecFx32 pos;
    func_0216D88C((const struct Actor *)p, &pos);
    return func_021638CC(p, (struct Obj_021636F0 *)(&pos), x, y, z, kind);
}





void func_021639C0(int a, u16 b)
{
    s16 x, y, z;

    x = func_0216D83C((void *)a) + func_021641E8(b);
    y = func_0216D854((void *)a);
    z = func_0216D86C((void *)a) + func_021641F8(b);
    func_02163994((void *)a, x, y, z, b);
}




/*
 * Builds a rectangle (s16 x0, y0, x1, y1) from a map object's width and
 * height getters: x spans x .. x + (w - 1), y spans y - (h - 1) .. y, each
 * size clamped at 0. EXACT* only for the 2-byte pad after the function
 * (54 of 56).
 *
 * pass 3 2026-10-06 P3L05: closed. Key: out->x0 = x is written before
 * out->x1 = x + w. Then x is dead at the add and does not interfere with
 * the sum temp, so x and y simplify in one pass and take r6 / r5 in
 * parameter order. With x1 stored first, x and y swapped registers (6 B).
 */
void func_02163A08(int p, int x, int y, Rect *out)
{
    s16 w;
    s16 h;
    w = func_0216D91C(p) - 1;
    if (w < 0) w = 0;
    out->x0 = x;
    out->x1 = x + w;
    h = func_0216D924(p) - 1;
    if (h < 0) h = 0;
    out->y0 = y - h;
    out->y1 = y;
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
int func_02163A40(s16 *a, s16 *b)
{
    {
        s16 d1, d2, lo1, hi1, lo2, hi2, big0, big1, sm0, sm1;
        lo1 = a[0]; hi1 = a[2]; d1 = hi1 - lo1; if (d1 < 0) { d1 = -d1; }
        lo2 = b[0]; hi2 = b[2]; d2 = hi2 - lo2; if (d2 < 0) { d2 = -d2; }
        if (d1 > d2) { big0 = lo1; big1 = hi1; sm0 = lo2; sm1 = hi2; }
        else { big0 = lo2; big1 = hi2; sm0 = lo1; sm1 = hi1; }
        if (!((big0 <= sm0 && big1 >= sm0) || (big0 <= sm1 && big1 >= sm1))) goto fail;
    }
    {
        s16 big0, big1, sm0, sm1, lo1, hi1, lo2, hi2, d1, d2;
        lo1 = a[1]; hi1 = a[3]; d1 = hi1 - lo1; if (d1 < 0) { d1 = -d1; }
        lo2 = b[1]; hi2 = b[3]; d2 = hi2 - lo2; if (d2 < 0) { d2 = -d2; }
        if (d1 > d2) { big0 = lo1; big1 = hi1; sm0 = lo2; sm1 = hi2; }
        else { big0 = lo2; big1 = hi2; sm0 = lo1; sm1 = hi1; }
        if (!((big0 <= sm0 && big1 >= sm0) || (big0 <= sm1 && big1 >= sm1))) goto fail;
    }
    return 1;
fail:
    return 0;
}




int func_02163AF0(int a, int b, int c, int d, s16 e, int g)
{
    Rect v1;
    Rect v0;
    s16 t;

    func_02163A08(a, c, e, &v1);
    if (func_0216D55C(b, 0x80) == 0) {
        func_02163A08(b, func_0216D83C((void *)b), func_0216D86C((void *)b), &v0);
        if (func_02163A40((s16 *)&v1, (s16 *)&v0) != 0) {
            t = d - func_0216D854((void *)b);
            if (t < 0) {
                t = -t;
            }
            if (t < 1) {
                return 1;
            }
        }
        if (g == 1) {
            func_02163A08(b, func_0216D804((void *)b), func_0216D81C((void *)b), &v0);
            if (func_02163A40((s16 *)&v1, (s16 *)&v0) != 0) {
                t = d - func_0216D810((void *)b);
                if (t < 0) {
                    t = -t;
                }
                if (t < 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}










int func_02163BAC(int a, int b, int c, s16 d)
{
    int v;
    int cur;
    int it;

    v = 0;
    it = (int)func_0216D67C((void *)a);
    while (func_0216DD1C((struct Ctx *)it, (struct Rec **)(&cur), (u32 *)(&v)) == 1) {
        if (a != cur) {
            if (func_02163AF0(a, cur, b, c, d, 1) == 1)
                return 1;
        }
    }
    return 0;
}










int func_02163C04(int a, int x, int y, int flag)
{
    Rect r;
    int t;

    t = func_0216D83C((void *)a);
    func_02163A08(a, t, func_0216D86C((void *)a), &r);
    if (r.x0 <= x && r.x1 >= x && r.y0 <= y && r.y1 >= y)
        return 1;
    if (flag == 1) {
        t = func_0216D804((void *)a);
        func_02163A08(a, t, func_0216D81C((void *)a), &r);
        if (r.x0 <= x && r.x1 >= x && r.y0 <= y && r.y1 >= y)
            return 1;
    }
    return 0;
}










int func_02163C9C(int a, int b, int c)
{
    int base;
    int d;
    int hi;
    int lo;

    base = func_0216D7E8((void *)a);
    d = func_0216D660((void *)a);
    if (d != -1) {
        hi = (s16)(base + d);
        lo = (s16)(base - d);
        if (lo > b || hi < b)
            return 1;
    }
    base = func_0216D7F8((void *)a);
    d = func_0216D66C((void *)a);
    if (d != -1) {
        hi = (s16)(base + d);
        lo = (s16)(base - d);
        if (lo > c || hi < c)
            return 1;
    }
    return 0;
}










/*
 * note: 2026-10-05 wave P8 lane W8. The older draft was DIFF 6 B (row copy src/dst r2/r3 swapped).
 *   Closed by writing the inner loop init as "for (j = 0, cur = row; ...)" (copy inside the for-init,
 *   after j = 0). All other spellings of the copy stayed DIFF 6 B.
 */
int func_02163D04(void *m, u32 kind, VecFx32 pos)
{
    int found;
    VecFx32 row;
    VecFx32 cur;
    u32 attr;
    u32 first;
    u8 i;
    u32 h;
    u8 j;
    u32 w;
    u16 a;

    if (func_0216DCB4(m) == 0) {
        found = 0;
        w = func_0216D91C((int)m);
        h = func_0216D924((int)m);
        row = pos;
        for (i = 0; i < h; i++, row.z -= 0x10000) {
            for (j = 0, cur = row; j < w; j++, cur.x += 0x10000) {
                if (func_02163E34(m, &cur, &attr) == 0)
                    return 1;
                if (func_021AB11C(attr) == 1)
                    return 1;
                if (found == 0) {
                    first = attr;
                    found = 1;
                }
            }
        }
        a = func_021AB0F0(func_0216D7DC(m));
        if (d_021714A0[kind](a) == 1)
            return 1;
        if (d_02171490[kind](func_021AB0F0(first)) == 1)
            return 1;
        return 0;
    }
    return 1;
}









int func_02163E1C(void *a, char *b, E *c) { return func_0218DAEC((char *)func_0216D52C(func_0216D67C(a)),b,c); }









int func_02163E34(void *a0, VecFx32 *a1, u32 *a2)
{
    E info;

    *a2 = 0;
    if (func_02163E1C(a0, (char *)a1, &info) == 1) {
        *a2 = info.p;
        return 1;
    }
    return 0;
}








int func_02163E58(void *a0, VecFx32 *a1, int *a2)
{
    E info;

    *a2 = 0;
    if (func_02163E1C(a0, (char *)a1, &info) == 1) {
        *a2 = info.q;
        return 1;
    }
    return 0;
}






void func_02163E7C(int a, int b)
{
    int v;
    int buf[3];

    func_0216D80C(a, func_0216D83C((void *)a));
    func_0216D818(a, func_0216D854((void *)a));
    func_0216D824(a, func_0216D86C((void *)a));
    func_0216D848(a, func_021641E8(b));
    func_0216D87C(a, func_021641F8(b));
    v = 0;
    func_02164280(func_0216D83C((void *)a), func_0216D86C((void *)a), buf);
    buf[1] = func_0216D8AC((void *)a);
    func_02163E58((void *)a, (VecFx32 *)buf, &v);
    func_0216D85C((void *)a, (s16)((v >> 4) / 4096));
}








void func_02163F10(int a)
{
    func_0216D80C(a, func_0216D83C((void *)a));
    func_0216D818(a, func_0216D854((void *)a));
    func_0216D824(a, func_0216D86C((void *)a));
}








int func_02163F40(int a, int dir)
{
    int buf[3];
    int v;

    v = -1;
    func_02164280(func_0216D83C((void *)a), func_0216D86C((void *)a), buf);
    buf[1] = func_0216D8AC((void *)a);
    func_02164208(dir, buf, 0x10000);
    func_02163E34((void *)a, (VecFx32 *)buf, (u32 *)&v);
    return v;
}






/*
 * contract: matched func_0216D88C copies all three Actor.pos words to v;
 * no uninitialized local component is read. Additions wrap as unsigned32.
 */
void func_02163F8C(void *a, const VecFx32 *b) { VecFx32 v; func_0216D88C(a,&v); v.x=(int)((unsigned)v.x+(unsigned)b->x); v.y=(int)((unsigned)v.y+(unsigned)b->y); v.z=(int)((unsigned)v.z+(unsigned)b->z); func_0216D89C(a,&v); }





void func_02163FC0(int a, int dir, int amt)
{
    int buf[3];

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)buf);
    switch (dir) {
    case 0:
        buf[2] -= amt;
        break;
    case 1:
        buf[2] += amt;
        break;
    case 2:
        buf[0] -= amt;
        break;
    case 3:
        buf[0] += amt;
        break;
    }
    func_0216D89C((void *)a, (const VecFx32 *)buf);
}






int func_02164010(int a)
{
    VecFx32 cur;
    VecFx32 next;
    int out;
    int r;

    func_0216D88C((const struct Actor *)a, &cur);
    next = cur;
    if (func_0216D55C(a, 0x2000) != 0)
        return 0;
    if (func_0216DB68((void *)a) == 1) {
        func_0216D570((void *)a, 0x1000);
        return 0;
    }
    r = func_02163E58((void *)a, &next, &out);
    if (r == 1) {
        cur.y = out;
        func_0216D89C((void *)a, &cur);
        func_0216D818(a, func_0216D854((void *)a));
        func_0216D85C((void *)a, (s16)((out >> 4) / 4096));
        func_0216D570((void *)a, 0x1000);
    } else {
        func_0216D568((void *)a, 0x1000);
    }
    return r;
}







int func_021640B0(int a)
{
    int rect[3];
    int o1;
    int o2;
    int r1;
    int r2;

    r1 = 0;
    r2 = 0;
    o1 = -1;
    o2 = -1;
    if (func_0216DCB4((void *)a) == 0) {
        int x = func_0216D804((void *)a);
        int y = func_0216D810((void *)a);
        int z = func_0216D81C((void *)a);
        rect[0] = x << 16;
        rect[1] = y << 16;
        rect[2] = z << 16;
        r1 = func_02163E34((void *)a, (VecFx32 *)rect, (u32 *)&o1);
        func_02164280((s16)func_0216D83C((void *)a), (s16)func_0216D86C((void *)a), rect);
        rect[1] = func_0216D8AC((void *)a);
        r2 = func_02163E34((void *)a, (VecFx32 *)rect, (u32 *)&o2);
    }
    if (r1 == 1)
        func_0216D7E0((void *)a, o1);
    if (r2 == 1)
        func_0216D7D8((void *)a, o2);
    if (r2 == 1) {
        func_0216D570((void *)a, 0x800);
        return 1;
    }
    func_0216D568((void *)a, 0x800);
    return 0;
}







int func_02164168(int a)
{
    int t;
    int tx;
    int ty;
    int x;
    int y;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;

    t = (int)func_0216DEE0(func_0216D67C((void *)a));
    if (t != 0) {
        tx = func_0216D83C((void *)t);
        ty = func_0216D86C((void *)t);
        x = func_0216D83C((void *)a);
        y = func_0216D86C((void *)a);
        x0 = x - 18;
        y0 = y - 18;
        x1 = x + 17;
        y1 = y + 17;
        if (y0 <= ty && y1 >= ty && x0 <= tx && x1 >= tx)
            return 1;
    }
    return 0;
}






/*
 * lever: halfword-wrapped +0xFFCD preserves the literal-pool bias;
 * spelling -51 produced a 26-byte DIFF instead of the 32-byte body.
 */
void func_021641C8(void *a) { if ((u16)(func_0216D5A0(a)+0xFFCD) <= 3) func_0216D708(a); }





/*
 * contract: ROM table at 0x02171480 holds {0,0,-1,1}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 */
int func_021641E8(int a) { return (short)*(const int *)((unsigned)d_02171480+((unsigned)a<<2)); }





/*
 * contract: ROM table at 0x02171470 holds {-1,1,0,0}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 */
int func_021641F8(int a) { return (short)*(const int *)((unsigned)d_02171470+((unsigned)a<<2)); }





void func_02164208(int dir, int *p, int amt)
{
    switch (dir) {
    case 0:
        p[2] -= amt;
        break;
    case 1:
        p[2] += amt;
        break;
    case 2:
        p[0] -= amt;
        break;
    case 3:
        p[0] += amt;
        break;
    }
}






/*
 * Unlabelled leaf (no lr save, prints as .word data): step one of two
 * halfword coordinates by amt in the direction dir (0 z-, 1 z+, 2 x-, 3 x+).
 * Halfword sibling of the word version func_02164208.  Filed as the sole
 * blocker of ov021 func_021A40A8.
 */
void func_02164240(int dir, s16 *x, s16 *z, s16 amt)
{
    switch (dir) {
    case 0:
        z[0] -= amt;
        break;
    case 1:
        z[0] += amt;
        break;
    case 2:
        x[0] -= amt;
        break;
    case 3:
        x[0] += amt;
        break;
    }
}





void func_02164280(int x, int y, int *p)
{
    p[0] = (x << 16) + 0x8000;
    p[2] = (y << 16) + 0x8000;
}






/*
 * Unlabelled leaf, blocker of ov021 func_0218B4B0: widens three integers to 16.16 fixed point.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_02164294(int x, int y, int z, int *out)
{
    out[0] = x << 16;
    out[1] = y << 16;
    out[2] = z << 16;
}






/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov021 func_0219A7DC and func_0219A8C0: returns
 * the low halfword of word i of a table.
 */
u16 func_021642A4(int i)
{
    return d_021714B0[i];
}






/*
 * Unlabelled leaf (word run in the listing), blocker of func_0219B13C and
 * func_0219BA6C (ov021).  Direction code 0..3 from a point pair.
 */
u16 func_021642B4(int x0, int y0, int x1, int y1)
{
    int r;

    if (x0 > x1) {
        return 2;
    }
    if (x0 < x1) {
        return 3;
    }
    r = 1;
    if (y0 > y1) {
        r = 0;
    }
    return r;
}






/*
 * Unlabelled leaf, blocker of ov021 func_0219FFD4: three chained table lookups.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 func_021642D4(int i, int v)
{
    u32 s = (u16)(v + d_02171458[i]);

    return d_021714C0[d_02171460[s >> 12]].b;
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
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
void func_021642F8(void *a0)
{

    func_0216D548(a0, 8192);
}






void func_02164304(int a, u8 *p)
{
    Msg m;
    u16 *q;

    m.a = ((EventMsgSrc *)p)->f1C[0];
    m.b = 1;
    q = ((EventMsgSrc *)p)->f1C;
    m.c = func_0201441C(((EventMsgSrc *)p)->fC);
    m.e = q[1];
    m.d = ((s16 *)q)[2];
    if (func_0216D4D4((int)func_0216D67C((void *)a), 0x10) != 0) {
        func_0219E2C0(a, &m);
        return;
    }
    func_0216D684(a, 0xc);
    func_0216435C((void *)a, (const u16 *)(&m));
}





void func_0216435C(void *a, const u16 *b) { u16 *p=func_0216D69C(a); ((EventMark *)p)->v[0]=b[0]; ((EventMark *)p)->v[1]=b[1]; ((EventMark *)p)->v[2]=b[2]; ((EventMark *)p)->v[3]=b[3]; ((EventMark *)p)->magic=0xEFEFEFEF; }





/*
 * contract: setter func_0216435C writes the four payload halfwords
 * at +4,+6,+8,+10 before publishing 0xEFEFEFEF at +0;
 * this reader loads those halfwords only after the sentinel comparison.
 */
int func_02164380(void *a, u16 *b) { u16 *p=func_0216D69C(a); if (((EventMark *)p)->magic==0xEFEFEFEF) { b[0]=((EventMark *)p)->v[0]; b[1]=((EventMark *)p)->v[1]; b[2]=((EventMark *)p)->v[2]; b[3]=((EventMark *)p)->v[3]; return 1; } return 0; }





/*
 * interface: func_02188C9C reads the u16 field at +0xD8;
 * func_0215E428 forwards its second argument to func_0200D45C,
 * whose matched ARM9 body takes u16 and stores only that halfword.
 * The legacy ov010_func_021643E8 declaration uses a pointer for this ID.
 */
void func_021643AC(void *a, void *b) { void *p=func_0200D418(func_02012EBC(a)); func_0215E428((int)p,func_02188C9C(b)); func_0215E3A0(a); func_0201433C((char *)func_0201296C(a),0x964); func_0215E33C((int)b); }






/*
 * Per-object setup: registers the object with the frame list, applies
 * the flag word and seeds the 177-entry table pass.
 *
 * Addresses are Black-image addresses.
 */
void func_021643E8(void *a, void *b)
{
    void *w = func_02012B38(a);
    void *c;
    if ((func_02013F6C((u32)b) & 3) == 0) {
        func_02014464(w, 0);
    }
    func_0215E428((int)func_0200D418(func_02012EBC(a)), (int)b);
    func_0215E364(a);
    c = (void *)func_0201296C(a);
    func_0201433C(c, 0x964);
    func_02164728(c);
    if (func_02013FFC((u32)b) == 0) {
        func_02008988(func_02008854(func_02012EBC(a)), 0);
    }
}






/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 1 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_02164454(int a, int b)
{
    return func_0215E34C(a);
}






/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 3 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_0216445C(int a, int b)
{
    return func_0215E34C(a);
}






/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 2 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_02164464(int a, int b)
{
    return func_0215E34C(a);
}






/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 func_0218562C.
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 func_0218562C.
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_0216446C(int a, int b)
{
    return func_0215E34C(a);
}






/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 func_02183DE4.
 */
void func_02164474(int a, int b)
{
    func_0215E364((void *)a);
}






/*
 * Empty function after the veneer run; the only Thumb code at this address
 * in any overlay window, called from ov021 func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void func_0216447C(int sys, u16 id)
{
}






void func_02164480(Flags_021639C0 *f, void *a, void *b)
{
    void *save;
    int i;

    save = func_020127A4(func_020120F4(a));
    MI_CpuFill8(f, 0, sizeof(Flags_021639C0));
    for (i = 0; i < 10; i++)
        func_02028748((struct Obj *)f, i, func_021644C4(i, a, b));
    f->f04 = func_02012B28(save);
}






/*
 * Calls entry i of the handler table at 0x021714DC, or returns 1 when the
 * slot is empty.
 */
int func_021644C4(int i, void *a, void *b)
{
    void *sys;
    void *save;
    Handler fn;

    sys = func_020120F4(a);
    save = func_020127A4(sys);
    fn = d_021714DC[i];
    if (fn == 0)
        return 1;
    return fn(sys, b, save);
}
