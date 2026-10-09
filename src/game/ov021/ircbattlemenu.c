/*
 * file:     ircbattlemenu.c
 * unit:     yes
 * function: func_0219728C, func_021973A0, func_0219749C, func_021974A0, func_02197534, func_021975D0, func_02197644, func_02197700, func_02197738, func_02197798, func_021977C0, func_02197800, func_021978AC, func_021978D4, func_021978DC, func_02197AAC, func_02197B5C, func_02197C4C, func_02197C78, func_02197C9C, func_02197CCC, func_02197D3C, func_02197DA0, func_02197DAC, func_02197DCC, func_02197DE8, func_02197DF4, func_02197E10, func_02197E28, func_02197E44, func_02197E78, func_02197E7C, func_02197EB4, func_02197EDC, func_02197F20, func_02197F5C, func_02197F6C, func_02197F90, func_02197F9C, func_02197FA8, func_02197FB4, func_02197FC0, func_0219800C, func_02198060, func_02198074, func_02198088, func_0219809C, func_021980B0, func_021980C4, func_021980DC, func_021980F0, func_02198104, func_0219811C, func_02198134, func_02198148, func_0219815C, func_02198170, func_02198184, func_02198198, func_021981AC, func_021981C4, func_021981DC, func_021981F0, func_02198208, func_0219821C, func_02198234, func_02198248, func_02198260, func_02198278, func_02198290, func_021982A4, func_021982BC, func_021982D4, func_021982EC, func_02198300, func_02198318, func_0219834C, func_02198380, func_02198390, func_021983A0, func_021983B0, func_021983C0, func_021983D0, func_021983E0, func_021983F0, func_02198400, func_02198410, func_02198420, func_02198430, func_02198440, func_02198450, func_02198460, func_02198470, func_02198480, func_02198490, func_021984A0, func_021984B0, func_021984C0, func_0219852C, func_02198550, func_0219862C, func_02198650, func_02198674, func_02198694, func_021986B8, func_021986D8, func_021986F8, func_02198718, func_02198738, func_02198758, func_0219877C, func_021987A0, func_021987C0, func_021987E0, func_02198804, func_02198824, func_02198848, func_02198868, func_02198888, func_021988AC, func_021988D0, func_021988F4, func_02198918, func_0219893C, func_02198960, func_02198978, func_02198998, func_021989A4, func_021989B0, func_021989BC, func_021989C8, func_021989D4, func_021989E0, func_021989EC, func_02198A10, func_02198A58, func_02198A8C, func_02198AD4, func_02198AE8, func_02198AFC, func_02198B10, func_02198B24, func_02198B38, func_02198B4C, func_02198B80, func_02198BA8, func_02198BB8, func_02198BC8, func_02198BD8, func_02198BE8, func_02198BF8, func_02198C08, func_02198C4C, func_02198CA4, func_02198CB4, func_02198CC4, func_02198CD4, func_02198CE4, func_02198CF4, func_02198D04, func_02198D14
 * address:  0x0219728C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D3FC0     0x021D3FC0  data   a1
 *   d_021D3FD0     0x021D3FD0  data   a1
 *   d_021D3FB8     0x021D3FB8  data   a1
 *   func_02197058  0x02197058  thumb  ov021
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   d_021D3F98     0x021D3F98  data   a1
 *   d_021D3FA4     0x021D3FA4  data   a1
 *   d_021D3F90     0x021D3F90  data   a1
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02027778  0x02027778  thumb
 *   func_02027CD8  0x02027CD8  thumb
 *   func_02045808  0x02045808  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02196228  0x02196228  thumb  ov021
 *   func_02041570  0x02041570  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02012DD0  0x02012DD0  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 *   func_02012DAC  0x02012DAC  thumb
 *   func_020414EC  0x020414EC  arm
 *   func_021962F4  0x021962F4  thumb  ov021
 *   func_02196A4C  0x02196A4C  thumb  ov021
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_02196290  0x02196290  thumb  ov021
 *   func_02027858  0x02027858  thumb
 *   func_0204A648  0x0204A648  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_020433E0  0x020433E0  arm
 *   d_021DDB14     0x021DDB14  data   ov021  a4
 *   d_021D4090     0x021D4090  data   ov021  a4
 *   func_0203FC28  0x0203FC28  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   d_020A1448     0x020A1448  data   a4
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0219603C  0x0219603C  thumb  ov021
 *   func_02196538  0x02196538  thumb  ov021
 *   d_021DDBC4     0x021DDBC4  data   ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02027F60  0x02027F60  thumb
 *   func_02196FFC  0x02196FFC  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_021966F0  0x021966F0  thumb  ov021
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02027974  0x02027974  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02040618  0x02040618  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_020121CC  0x020121CC  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_02012204  0x02012204  thumb
 *   func_0202223C  0x0202223C  thumb
 *   func_02196768  0x02196768  thumb  ov021
 *   func_02155A8C  0x02155A8C  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02028148  0x02028148  thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C5D0  0x0219C5D0  thumb  ov021
 *   func_0216D528  0x0216D528  thumb
 *   func_0219D488  0x0219D488  thumb  ov021
 *   func_0216D95C  0x0216D95C  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D8F0  0x0216D8F0  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F4  0x0216D4F4  thumb  ov010
 *   func_0216D514  0x0216D514  thumb  ov010
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DDBE0     0x021DDBE0  data  a4
 *   func_02030EE8  0x02030EE8  arm
 *   func_0216D480  0x0216D480  thumb  ov010
 *   d_021D4A50     0x021D4A50  data  a4
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   d_021D5D6C     0x021D5D6C  data  a4
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_0216D7D4  0x0216D7D4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   d_021D624C     0x021D624C  data  a4
 *   d_021D5F58     0x021D5F58  data  a4
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 */
#include "../../matched/include/Obj00094.h"
#include "../../matched/include/Obj05989.h"
#include "../../matched/include/Obj00150.h"
#include "../../matched/include/Obj01495.h"
#include "../../matched/include/Obj19637.h"
#include "../../matched/include/Obj17950.h"
#include "../../matched/include/Obj12072.h"
#include "../../matched/include/Obj09177.h"
#include "../../matched/include/Obj12073.h"
#include "../../matched/include/Obj07465.h"
#include "../../matched/include/Obj05990.h"
#include "../../matched/include/Obj05004.h"
#include "../../matched/include/Obj01032.h"
#include "../../matched/include/Obj17951.h"
#include "../../matched/include/Obj17952.h"
#include "../../matched/include/Obj05005.h"

struct Obj_0219728C;
struct Actor;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
struct Ctx;
struct Rec;
struct Rec3;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Big;
struct Obj;
struct Obj0203159C;
struct DispConfig;
struct DispVram;
struct Bank;
struct R;
struct Tcbl;
struct BigObj;
struct IcaAnime;
struct PrintSys;
struct Node;
struct S02031140;
struct TaskMenuState;
struct S020315D4;
struct VecFx32;
struct S02030EE8;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u16 a, b, c; u8 d, e; } Rect;

typedef struct { u8 v[5]; } B5;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int arr[5];
} Sub_0219728C;

typedef struct {
    u8 pad0[0x10];
    u16 f10;
    u8 pad12[0x26C - 0x12];
    Sub_0219728C sub;
} Obj_0219728C;

typedef struct { u8 v[3]; } B3;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int arr[3];
} Sub_021973A0;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj_0219749C {
    u8 pad[0x270];
    void *c[6];
    u32 x288;
    void *b[2];
    void *a[5];
} Obj_0219749C;

typedef struct { u32 w; u16 h; u16 pad; u32 z; } Ent;

typedef struct Obj {
    u8 pad0[0x10];
    u16 x10;
    u8 pad12[0x16];
    u32 x28;
    u8 pad2c[0x294];
    u32 x2c0;
    Ent e[2];
    u32 x2dc;
} Obj;

typedef struct {
    u32 x0;
    u8 x4;
    Ent *x8;
    u32 xc;
    u8 x10;
    u8 x11;
    u8 x12;
    u8 x13;
} Desc;

typedef signed int     s32;

typedef struct { u32 w[4]; } Q16;

typedef struct IrcTask {
    int state;
    int f4;
    int idx;
    int fc;
    u16 *data;
} IrcTask;

typedef int BOOL;

typedef struct { int x, y, z; } Vec;

extern void func_02197058(Obj_0219728C *);
extern struct Obj_0219728C *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj_0219728C *, unsigned int);
extern void func_0204B3DC(struct Obj_0219728C *, unsigned int);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj_0219749C *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern int func_02027CD8(int a0, int a1);
extern void func_02045808(struct U16Vec *vec);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *h);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4();
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32, u32, u32);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void func_02196228(u8 *p, int flag);
extern void func_02041570(int channel, u16 val);
extern void func_02196034(u8 *, void (*)(), u32);
extern int func_02012DD0(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02196A60(u8 *p);
extern void func_02196804(u8 *p);
extern int func_02012DAC(int a0);
extern void func_020414EC(u32);
extern void func_021962F4(u8 *);
extern void func_02196A4C(u8 *a);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_020071F0(void);
extern void func_02196290(u8 *);
extern void func_02027858(struct TaskMenu *m);
extern void func_0204A648(void);
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, u32, u32);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_020056A0(void (*)(void), void *, u32);
extern void func_0219603C(void *a0);
extern void func_02196538(u8 *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32, u32, u32, u32);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_02196FFC(u8 *);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021966F0(u8 *p);
extern u32 func_02155A90(u8 *);
extern void *func_020120F4(const struct Ctx *);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0203D34C(u32, u32);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
extern void func_02027974(u32);
extern void func_02028178(u8 *p);
extern void func_02040618(u32, u32, u32);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_020221A4(void);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(u32, u32);
extern void func_02196768(u8 *p);
extern void func_02155A8C(u8 *, u32);
extern void func_0202F038(u8 *p);
extern u32 func_020307B0(void *p);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_020403F4(u32);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02028148(u8 *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern u32 func_0216D520(void *p);
extern u32 func_0216D528(u32);
extern u32 func_0216D95C(u32, u32);
extern void func_0219C5D0(u32 a);
extern void func_0219D488(u32 a);
extern void *func_0216D67C(void *a0);
extern int func_0216D4D4(int a0, int a1);
extern int func_0216DAA0(void *a0);
extern void func_0216D758(void *a0);
extern int func_0216D55C(int a0, int a1);
extern int func_0216DB10(void *a0);
extern int func_0216DC4C(void *a0);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_0216D8B0(u8 *p, u8 *q);
extern void func_0216D8D0(u8 *p, u8 *q);
extern void func_0216D8F0(u8 *p, u8 *q);
extern void func_0216D92C(u8 *, s32 *);
extern u32 func_0216D4F8(u8 *p);
extern u16 func_0216D4F4(void *p);
extern u32 func_0216D514(void *p);
extern void func_02030DA8(u32, void (*)(), u32 *, u32);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_0216D480(char *p);
extern int func_0216D3CC(int a0);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(int a0, u32 a1, u32 a2, u32 a3);
extern u16 func_0216D7C4(u8 *p);
extern u16 func_0216D7D4(u8 *p);
extern u32 func_0216D57C(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern void func_0216D7C0(void *p, u16 v);
extern void *func_0216D7C8(void *p, u16 v);
extern void *func_0216D568(void *p, u32 v);
extern int func_02163F10(int a0);
extern void func_0216D5E0(int a0, int a1);
extern u32 func_0216D674(void *p, u16 v);
extern u32 func_0216D7CC(u32);
extern void *func_0216D6BC(u32 heap, u32 size);
extern void func_02163E7C(int a, int b);
extern int func_0216D60C(u8 *, u16);
extern void *func_0216D6D4(void *p);
extern void func_02163FC0(int a, int dir, int amt);
extern int func_02164010(int a);
extern void func_0216D8C0(u32, Vec *);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 *func_0216D550(u32 *p, u32 v);
extern u32 func_0216D534(void *p);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021BB528(u32, u32, u32, u32);
extern int func_021BB5C8(u32);
extern void func_021AC154(u32);
void func_0219728C(Obj_0219728C *p);
void func_021973A0(Obj_0219728C *p);
void func_0219749C(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_021974A0(Obj_0219749C *o);
void func_02197534(Obj *a);
int func_021975D0(u8 *p);
void func_02197644(u8 *a, u32 b);
void func_02197700(u8 *a);
void func_02197738(u8 *a);
void func_02197798(u8 *a);
void func_021977C0(u8 *a);
void func_02197800(u8 *a);
void func_021978AC(u8 *a);
void func_021978D4(void);
int func_021978DC(struct Obj0203159C *a, u32 b, u32 c);
u32 func_02197AAC(u32 r0, u32 r1, u32 r2, u8 *a);
int func_02197B5C(u32 a, u32 b, u8 *c, u32 *d);
int func_02197C4C(u32 a, u32 b, u32 c, u32 d);
void func_02197C78(u32 a);
int func_02197C9C(u32 a);
void func_02197CCC(u8 *p, s32 *out);
void func_02197D3C(u32 p0, u32 p1);
int func_02197DA0(u32 a);
void func_02197DAC(void *a);
void func_02197DCC(void *a, int *b);
int func_02197DE8(IrcTask *w);
int func_02197DF4(u32 a);
int func_02197E10(u32 a, u32 b, u32 c, u32 d);
int func_02197E28(u32 a, u32 b, u32 c, u32 d);
int func_02197E44(IrcTask *w);
int func_02197E78(void);
int func_02197E7C(int a, int b);
void func_02197EB4(u32 a);
u32 func_02197EDC(u8 *p);
int func_02197F20(u32 a, u32 b, u32 c);
int func_02197F5C(u32 a, u32 b, u32 c, u32 d);
int func_02197F6C(u32 a, u32 b);
u32 func_02197F90(u32 a1);
u32 func_02197F9C(u32 a1);
u32 func_02197FA8(u32 a1);
u32 func_02197FB4(u32 a1);
void func_02197FC0(u8 *a, u32 b, u32 c, u16 d, u16 e);
u32 func_0219800C(u8 *p);
int func_02198060(u32 a);
int func_02198074(u32 a);
int func_02198088(u32 a);
int func_0219809C(u32 a);
int func_021980B0(u32 a);
int func_021980C4(u32 a);
int func_021980DC(u32 a, u32 b, u32 c, u32 d);
int func_021980F0(u32 a);
int func_02198104(u32 a);
int func_0219811C(u32 a);
int func_02198134(u32 a);
int func_02198148(u32 a, u32 b, u32 c, u32 d);
int func_0219815C(u32 a, u32 b, u32 c, u32 d);
int func_02198170(u32 a, u32 b, u32 c, u32 d);
int func_02198184(u32 a, u32 b, u32 c, u32 d);
int func_02198198(u32 a, u32 b, u32 c, u32 d);
int func_021981AC(u32 a);
int func_021981C4(u32 a);
int func_021981DC(u32 a);
int func_021981F0(u32 a);
int func_02198208(u32 a, u32 b, u32 c, u32 d);
int func_0219821C(u32 a);
int func_02198234(u32 a);
int func_02198248(u32 a);
int func_02198260(u32 a);
int func_02198278(u32 a);
int func_02198290(u32 a);
int func_021982A4(u32 a);
int func_021982BC(u32 a);
int func_021982D4(u32 a);
int func_021982EC(u32 a);
int func_02198300(u32 a);
void func_02198318(u32 a, u32 b, u16 c, u16 d);
int func_0219834C(u32 a);
u32 func_02198380(u32 a1);
u32 func_02198390(u32 a1);
u32 func_021983A0(u32 a1);
u32 func_021983B0(u32 a1);
u32 func_021983C0(u32 a1);
u32 func_021983D0(u32 a1);
u32 func_021983E0(u32 a1);
u32 func_021983F0(u32 a1);
u32 func_02198400(u32 a1);
u32 func_02198410(u32 a1);
u32 func_02198420(u32 a1);
u32 func_02198430(u32 a1);
u32 func_02198440(u32 a1);
u32 func_02198450(u32 a1);
u32 func_02198460(u32 a1);
u32 func_02198470(u32 a1);
u32 func_02198480(u32 a1);
u32 func_02198490(u32 a1);
u32 func_021984A0(u32 a1);
u32 func_021984B0(u32 a1);
void func_021984C0(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g, u32 h);
void func_0219852C(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g);
int func_02198550(u32 a);
int func_0219862C(u8 *a);
int func_02198650(u8 *a);
int func_02198674(u8 *a);
int func_02198694(u8 *a);
int func_021986B8(u8 *a);
int func_021986D8(u8 *a);
int func_021986F8(u8 *a);
int func_02198718(u8 *a);
int func_02198738(u8 *a);
int func_02198758(u8 *a);
int func_0219877C(u8 *a);
int func_021987A0(u8 *a);
int func_021987C0(u8 *a);
int func_021987E0(u8 *a);
int func_02198804(u8 *a);
int func_02198824(u8 *a);
int func_02198848(u8 *a);
int func_02198868(u8 *a);
int func_02198888(u8 *a);
int func_021988AC(u8 *a);
int func_021988D0(u8 *a);
int func_021988F4(u8 *a);
int func_02198918(u8 *a);
int func_0219893C(u8 *a);
int func_02198960(u32 a, u32 b);
int func_02198978(u32 a);
u32 func_02198998(u32 a1);
u32 func_021989A4(u32 a1);
u32 func_021989B0(u32 a1);
u32 func_021989BC(u32 a1);
u32 func_021989C8(u32 a1);
u32 func_021989D4(u32 a1);
u32 func_021989E0(u32 a1);
int func_021989EC(u32 a, u32 b, u32 c, u32 d);
int func_02198A10(u32 a);
int func_02198A58(u32 a);
int func_02198A8C(u32 a);
int func_02198AD4(u32 a, u32 b, u32 c, u32 d);
int func_02198AE8(u32 a, u32 b, u32 c, u32 d);
int func_02198AFC(u32 a, u32 b, u32 c, u32 d);
int func_02198B10(u32 a, u32 b, u32 c, u32 d);
int func_02198B24(u32 a, u32 b, u32 c, u32 d);
int func_02198B38(u32 a, u32 b, u32 c, u32 d);
void func_02198B4C(u32 a, u32 b, u32 a3);
int func_02198B80(u32 a);
u32 func_02198BA8(u32 a1);
u32 func_02198BB8(u32 a1);
u32 func_02198BC8(u32 a1);
u32 func_02198BD8(u32 a1);
u32 func_02198BE8(u32 a1);
u32 func_02198BF8(u32 a1);
void func_02198C08(u32 a, u32 b, u32 c, u16 d);
int func_02198C4C(u32 a, u32 *b);
u32 func_02198CA4(u32 a1);
u32 func_02198CB4(u32 a1);
u32 func_02198CC4(u32 a1);
u32 func_02198CD4(u32 a1);
u32 func_02198CE4(u32 a1);
u32 func_02198CF4(u32 a1);
u32 func_02198D04(u32 a1);
u32 func_02198D14(u32 a1);
extern const B5 d_021D3FC0;
extern const B5 d_021D3FD0;
extern const B5 d_021D3FB8;
extern const B3 d_021D3F98;
extern const B3 d_021D3FA4;
extern const B3 d_021D3F90;
extern u8 d_021DDB14[];
extern const Q16 d_021D4090;
extern u8 d_020A1448[];
extern u8 d_021DDBC4[];
extern u8 d_021DDBE0;
extern int *d_021D5D6C[];
extern int *d_021DDBD4[];













/*
 * Addresses are Black-image addresses.
 */
void func_0219728C(Obj_0219728C *p)
{
    B5 x0 = d_021D3FC0;
    B5 x1 = d_021D3FD0;
    B5 x2 = d_021D3FB8;
    Rect r;
    int i;

    func_02197058(p);
    for (i = 0; i < 5; i++) {
        r.a = x0.v[i];
        r.b = x1.v[i];
        r.c = x2.v[i];
        r.d = 0;
        r.e = 1;
        p->sub.arr[i] = (int)func_0204B294((void *)p->sub.f0, p->sub.f10, p->sub.f8, p->sub.f18, &r, 1, p->f10);
        func_0204B92C((struct Obj_0219728C *)p->sub.arr[i], 0);
        func_0204B3DC((struct Obj_0219728C *)p->sub.arr[i], 1);
        func_0204B688((struct Actor *)p->sub.arr[i], 1);
    }
}













void func_021973A0(Obj_0219728C *p)
{
    B3 x0 = d_021D3F98;
    B3 x1 = d_021D3FA4;
    B3 x2 = d_021D3F90;
    Rect r;
    int i;

    func_02197058(p);
    for (i = 0; i < 3; i++) {
        r.a = x0.v[i];
        r.b = x1.v[i];
        r.c = x2.v[i];
        r.d = 0;
        r.e = 1;
        p->sub.arr[i] = (int)func_0204B294((void *)p->sub.f0, p->sub.f10, p->sub.f8, p->sub.f18, &r, 1, p->f10);
        func_0204B92C((struct Obj_0219728C *)p->sub.arr[i], 0);
        func_0204B3DC((struct Obj_0219728C *)p->sub.arr[i], 1);
        func_0204B688((struct Actor *)p->sub.arr[i], 1);
    }
}













/*
 * An empty function.
 */
void func_0219749C(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
}













void func_021974A0(Obj_0219749C *o)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (o->a[i] != 0) {
            func_0204B3B4(o->a[i]);
            o->a[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (o->b[i] != 0) {
            func_0204B3B4(o->b[i]);
            o->b[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (o->c[i] != 0) {
            func_0204ADA4((u32)o->c[i]);
        }
    }
    for (; i < 4; i++) {
        if (o->c[i] != 0) {
            func_0204A8D4((u32)o->c[i]);
        }
    }
    for (; i < 6; i++) {
        if (o->c[i] != 0) {
            func_0204AFD8((u32)o->c[i]);
        }
    }
}












void func_02197534(Obj *a)
{
    Desc d;

    d.x0 = a->x10;
    d.x4 = 2;
    d.x8 = a->e;
    d.xc = 1;
    d.x10 = 0x20;
    d.x11 = 0xE;
    d.x12 = 0xD;
    d.x13 = 3;
    a->e[0].w = (u32)func_020457B0(100, a->x10);
    func_02045CAC((struct MsgBank *)a->x28, 26, (void *)a->e[0].w);
    a->e[0].h = 0x39E3;
    a->e[1].w = (u32)func_020457B0(100, a->x10);
    func_02045CAC((struct MsgBank *)a->x28, 27, (void *)a->e[1].w);
    a->e[1].h = 0x39E3;
    a->e[0].z = 0;
    a->e[1].z = 0;
    a->x2c0 = (u32)func_02027778((struct TaskMenuTmpl *)(&d), (void *)a->x2dc);
    func_02027CD8(a->x2c0, 1);
    func_02045808((struct U16Vec *)a->e[0].w);
    func_02045808((struct U16Vec *)a->e[1].w);
}












/*
 * Per-frame poll of the object at +0x2B4; returns 1 when it is absent.
 *
 * Addresses are Black-image addresses.
 */
int func_021975D0(u8 *p)
{
    if (((struct Obj00094 *)p)->f2B4 != 0) {
        if (((struct Obj00094 *)p)->f2B0 != 0)
            func_020286C4(((struct Obj00094 *)p)->f2A8, ((struct Obj00094 *)p)->f2B4, ((struct Obj00094 *)p)->f2B0);
        switch (func_0201CE30(((struct Obj00094 *)p)->f2B4)) {
        case 2:
            func_0201CE48(((struct Obj00094 *)p)->f2B4);
            ((struct Obj00094 *)p)->f2B4 = 0;
            break;
        case 1:
            if (func_02035C60() != 0) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00094 *)p)->f2B4);
            }
            break;
        case 0:
            if (func_02035C38() != 0)
                func_0201CE5C(((struct Obj00094 *)p)->f2B4, 0);
            break;
        }
        return 0;
    }
    return 1;
}












void func_02197644(u8 *a, u32 b)
{
    u32 t;

    if (*(u32 *)&((struct Obj00094 *)a)->f2B0 == 0) {
        *(u32 *)&((struct Obj00094 *)a)->f2B0 = func_020450F0(5, 1, 3, 30, 4, 11, 1);
    }
    t = *(u32 *)&((struct Obj00094 *)a)->f2B0;
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)t)), 15);
    func_0201DD78(1, 2, 15);
    if (b == 0) {
        *(u32 *)&((struct Obj00094 *)a)->f2B4 = func_0201CCE4(t, 0, 0, ((struct Obj00094 *)a)->f38, ((struct Obj00094 *)a)->f2C, func_02012FFC(), ((struct Obj00094 *)a)->f2B8, 2, ((struct Obj00094 *)a)->f10, 15);
    } else {
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)t)), 0, 0, (void *)(((struct Obj00094 *)a)->f38), (void *)(((struct Obj00094 *)a)->f2C));
        *(u32 *)&((struct Obj00094 *)a)->f2B4 = 0;
    }
    func_0201F73C((void *)t, 1, (u16)((struct Obj00094 *)a)->f3C, 12);
    func_02045334((struct Descriptor *)t);
    func_02045374((struct Cfg *)t);
    func_02041B6C(5);
}












void func_02197700(u8 *a)
{
    func_02196228(a, 1);
    func_02041570(5, 0);
    func_02045CAC((struct MsgBank *)(((struct Obj00094 *)a)->f28), 25, (void *)(((struct Obj00094 *)a)->f38));
    func_02197644(a, 0);
    func_02196034(a, func_021978AC, 0x761);
}












void func_02197738(u8 *a)
{
    if (func_02012DD0(*(u8 * *)&((struct Obj05989 *)a)->f30) == 2) {
        func_02196228(a, 0);
        func_0201F7A8((void *)(((struct Obj05989 *)a)->f2B0), 2);
        func_020456F8((struct Descriptor *)(((struct Obj05989 *)a)->f2B0));
        func_02041B6C(5);
        if (((struct Obj05989 *)a)->f8 == 1) {
            func_02196034(a, func_02196A60, 0x776);
        } else {
            func_02196034(a, func_02196804, 0x779);
        }
        ((struct Obj05989 *)a)->f2F8 = 1;
    }
}













/*
 * Addresses are Black-image addresses.
 */
void func_02197798(u8 *a)
{
    if (func_021975D0(a) != 0) {
        func_02012DAC(((struct Obj00094 *)a)->f30);
        func_02196034(a, func_02197738, 0x78E);
    }
}













void func_021977C0(u8 *a)
{
    if (func_021975D0(a) != 0 && func_02035C60() != 0) {
        func_02196228(a, 0);
        func_020414EC(3);
        func_021962F4(a);
        ((struct Obj00094 *)a)->f8 = 12;
        func_02196034(a, func_02196A4C, 0x7a2);
    }
}













void func_02197800(u8 *a)
{
    if (func_020279E8((struct TaskMenu *)(((struct Obj00094 *)a)->f2C0)) != 0) {
        if (func_02027A04((const u8 *)(((struct Obj00094 *)a)->f2C0)) == 0) {
            func_02012EBC((struct Big *)(((struct Obj00094 *)a)->f30));
            if (func_020071F0() != 0) {
                func_02045CAC((struct MsgBank *)(((struct Obj00094 *)a)->f28), 0x2d, (void *)(((struct Obj00094 *)a)->f38));
                func_02197644(a, 0);
                func_02196034(a, func_021977C0, 0x7b9);
            } else {
                func_02045CAC((struct MsgBank *)(((struct Obj00094 *)a)->f28), 0x1c, (void *)(((struct Obj00094 *)a)->f38));
                func_02197644(a, 1);
                func_02196290(a);
                func_02196034(a, func_02197798, 0x7bf);
            }
        } else {
            func_02196228(a, 0);
            func_020414EC(3);
            func_021962F4(a);
            ((struct Obj00094 *)a)->f8 = 12;
            func_02196034(a, func_02196A4C, 0x7c7);
        }
        func_02027858((struct TaskMenu *)(((struct Obj00094 *)a)->f2C0));
        ((struct Obj00094 *)a)->f2C0 = 0;
    }
}













void func_021978AC(u8 *a)
{
    if (func_021975D0(a) != 0) {
        func_02197534((Obj *)((struct Obj *)a));
        func_02196034(a, func_02197800, 0x7DC);
    }
}













/*
 * Untraced thunk: tail call into the ARM9 image.
 *
 * Addresses are Black-image addresses.
 */
void func_021978D4(void)
{
    func_0204A648();
}













int func_021978DC(struct Obj0203159C *a, u32 b, u32 c)
{
    u8 *w;

    func_0203064C(1, 0x1f, 0x18000);
    w = func_0203159C(a, 0x308, 0x1f);
    func_02082BCC(w, 0, 0x308);
    ((struct Obj00150 *)w)->f10 = 0x1f;
    func_0203F8F4(((struct Obj00150 *)w)->f10);
    func_02045088(((struct Obj00150 *)w)->f10);
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021DDB14);
    {
        Q16 q = d_021D4090;
        func_0203FC28((struct DispConfig *)(&q));
    }
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)d_021DDB14, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f26C = (u32)func_0204B100(0x28, 0, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f268 = func_020056A0(func_021978D4, w, 0);
    func_0219603C(w);
    func_02196538(w);
    ((struct Obj00150 *)w)->f2EC = (unsigned int)func_02030734(((struct Obj00150 *)w)->f10, 0x200, 0, (const char *)d_021DDBC4, 0x829);
    ((struct Obj00150 *)w)->f2F0 = (unsigned int)func_02030734(((struct Obj00150 *)w)->f10, 0x200, 0, (const char *)d_021DDBC4, 0x82A);
    ((struct Obj00150 *)w)->f2B8 = (u32)func_0203101C(((struct Obj00150 *)w)->f10, ((struct Obj00150 *)w)->f10, 2, 0);
    ((struct Obj00150 *)w)->f2A8 = func_02028590(0xf, 0, 1, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f2BC = func_0201C440((void *)(((struct Obj00150 *)w)->f10));
    ((struct Obj00150 *)w)->f2DC = (u32)func_02027F60(5, 9, *(u32 *)&((struct Obj00150 *)w)->f2C, ((struct Obj00150 *)w)->f2BC, ((struct Obj00150 *)w)->f10);
    func_02196FFC(w);
    func_0219749C(w, 0x39, 0x9a, 0, 10);
    func_0219749C(w, 0xc8, 0x26, 1, 11);
    func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj00150 *)w)->f10);
    func_02196034(w, (void (*)(void))func_021966F0, 0x83B);
    ((struct Obj00150 *)w)->f2E4 = c;
    ((struct Obj00150 *)w)->f30 = (u32)func_020120F4((const struct Ctx *)func_02155A90((u8 *)((struct Obj00150 *)w)->f2E4));
    func_0207D63C(0x04001050, 4, 1, 0xf, 4);
    func_0203D34C(0, ((struct Obj00150 *)w)->f10);
    func_02043534(0x13);
    func_020435F4(0x17);
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}













u32 func_02197AAC(u32 r0, u32 r1, u32 r2, u8 *a)
{
    u32 ret;
    void (*cb)(u8 *);

    cb = *(void (**)(u8 *))a;
    ret = 1;
    func_0201058C((void *)func_0201283C((const struct BigObj *)(((struct Obj01495 *)a)->f30)));
    if (cb != 0) {
        cb(a);
        ret = 0;
    }
    if (((struct Obj01495 *)a)->f2C0 != 0) {
        func_02027974(((struct Obj01495 *)a)->f2C0);
    }
    if (((struct Obj01495 *)a)->f2E0 != 0) {
        func_02028178((u8 *)(((struct Obj01495 *)a)->f2E0));
    }
    func_02040618(4, 3, ((struct Obj01495 *)a)->f2AC);
    ((struct Obj01495 *)a)->f2AC = ((struct Obj01495 *)a)->f2AC - 1;
    func_020310C4((struct Tcbl *)(((struct Obj01495 *)a)->f2B8));
    func_0201C4E4((struct PrintSys *)(((struct Obj01495 *)a)->f2BC));
    func_0204A600();
    if (((struct Obj01495 *)a)->f306 == 0) {
        func_020121CC((struct IcaAnime *)func_02155A90((u8 *)(((struct Obj01495 *)a)->f2E4)));
    }
    if (func_020221A4() != 0) {
        if (func_02012204((const struct Ctx *)func_02155A90((u8 *)(((struct Obj01495 *)a)->f2E4))) != 0) {
            ((struct Obj01495 *)a)->f8 = 12;
            ret = 1;
            func_0202223C(0, 0);
            func_0202223C(1, 0);
        }
    }
    return ret;
}













int func_02197B5C(u32 a, u32 b, u8 *c, u32 *d)
{
    if (!func_020221A4()) {
        return 0;
    }
    func_02196768((u8 *)d);
    func_02155A8C(c, d[2]);
    ((struct Obj19637 *)c)->f58 = d[3];
    if (d[0xBA] != 0) {
        func_0202F038((u8 *)d[0xBA]);
        d[0xBA] = 0;
    }
    func_020307B0((void *)d[0xBB]);
    func_020307B0((void *)d[0xBC]);
    func_021974A0((Obj_0219749C *)((struct Obj *)d));
    if (d[0xAD] != 0) {
        func_0201CE48((struct Rec3 *)d[0xAD]);
    }
    func_02028604(d[0xAA]);
    func_02031140((struct S02031140 *)d[0xAE]);
    func_020403F4(7);
    func_0201C6EC((struct PrintSys *)d[0xAF]);
    func_0201C4C0((struct PrintSys *)d[0xAF]);
    if (d[0xAC] != 0) {
        func_020452E8((struct Descriptor *)d[0xAC]);
    }
    if (d[0xB0] != 0) {
        func_02027858((struct TaskMenu *)d[0xB0]);
        d[0xB0] = 0;
    }
    if (d[0xB8] != 0) {
        func_02028148((u8 *)d[0xB8]);
    }
    func_02027FD8((struct TaskMenuState *)d[0xB7]);
    func_02030EAC((struct Node *)d[0x9A]);
    func_0204B1CC((struct Bank *)d[0x9B]);
    func_0204A5AC();
    func_020450C8();
    func_0203F9B4();
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x1f);
    return 1;
}













/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197C4C(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D520((void *)a) != 0) {
    func_0219C5D0(a);
}
if (func_0216D528(a) != 0) {
    func_0219D488(a);
}
return func_0216D95C(a, 0);
}













void func_02197C78(u32 a)
{
    if (func_0216D4D4((int)func_0216D67C((void *)a), 4) == 0 && func_0216DAA0((void *)a) != 0) {
        func_0216D758((void *)a);
    }
}













int func_02197C9C(u32 a)
{
if (func_0216DB10((void *)a) != 0) {
    if (func_0216DC4C((void *)a) == 0) {
        return 1;
    }
}
if (func_0216D55C(a, 16) != 0) {
    return 1;
}
return 0;
}













/*
 * Sums five 12-byte records fetched from the actor at p into out.
 *
 * Addresses are Black-image addresses.
 */
void func_02197CCC(u8 *p, s32 *out)
{
    s32 a[3];
    s32 b[3];
    s32 c[3];
    s32 d[3];
    s32 e[3];

    func_0216D88C((const struct Actor *)p, (struct VecFx32 *)a);
    func_0216D8B0(p, (u8 *)b);
    func_0216D8D0(p, (u8 *)c);
    func_0216D8F0(p, (u8 *)d);
    func_0216D92C(p, e);
    out[0] = a[0] + b[0] + c[0] + d[0] + e[0];
    out[1] = a[1] + b[1] + c[1] + d[1] + e[1];
    out[2] = a[2] + b[2] + c[2] + d[2] + e[2];
}













void func_02197D3C(u32 p0, u32 p1)
{
    u32 h;
    u32 *r;
    u32 n;

    h = (u32)func_0216D67C((void *)p0);
    r = func_02030734((u16)(0x8000 | (func_0216D4F8((u8 *)h) & 0x7fff)), 0x14, 1, (const char *)&d_021DDBE0, 0x115);
    n = func_0216D4F4(func_0216D67C((void *)p0)) - 2;
    func_02030DA8(func_0216D514((void *)h), func_02197DCC, r, n);
    r[3] = p0;
    r[4] = p1;
}













int func_02197DA0(u32 a)
{
return ((struct Obj17950 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f4;
}













void func_02197DAC(void *a)
{
    u32 *p;

    p = (u32 *)func_02030EE8(a);
    func_0216D480((char *)p[3]);
    func_020307B0(p);
    func_02030EAC(a);
}











extern int (*const d_021D4A50[])(int *);











/*
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the
 * ov021 table is a data start that another overlay mapped over the same
 * window also starts an object at, so the symbols hint is contested.  No C
 * change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * Addresses are Black-image addresses.
 */
void func_02197DCC(void *a, int *b)
{
    while (d_021D4A50[*b](b) == 1) {
    }
}










int func_02197DE8(IrcTask *w)
{
    w->idx = 0;
    w->state = 1;
    return 1;
}











/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197DF4(u32 a)
{
if (func_0216D3CC(((struct Obj12072 *)((u8 *)(a)))->fC) == 0) {
    return 0;
}
((struct Obj12072 *)((u8 *)(a)))->f0 = 2;
return 1;
}











int func_02197E10(u32 a, u32 b, u32 c, u32 d)
{
func_0216D410((void *)(((struct Obj09177 *)((u8 *)(a)))->fC), *(u16 *)((u8 *)(((struct Obj09177 *)((u8 *)(a)))->f10)));
((struct Obj09177 *)((u8 *)(a)))->f0 = 3;
return 0;
}










int func_02197E28(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D454(((struct Obj12073 *)((u8 *)(a)))->fC, b, c, d) == 0) {
    return 0;
}
((struct Obj12073 *)((u8 *)(a)))->f0 = 4;
return 1;
}









int func_02197E44(IrcTask *w)
{
    u16 *p = w->data;
    int i = ++w->idx;
    if (i < p[1]) {
        w->state = 1;
        return 1;
    }
    w->data = p + 2;
    if (p[2] != 0xfe) {
        w->state = 0;
        return 1;
    }
    w->f4 = 1;
    w->state = 5;
    return 0;
}









int func_02197E78(void)
{
    return 0;
}









/*
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the
 * ov021 table is a data start that another overlay mapped over the same
 * window also starts an object at, so the symbols hint is contested.  No C
 * change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * Addresses are Black-image addresses.
 */
int func_02197E7C(int a, int b)
{
    int i;
    int **p;
    int *q;

    p = d_021D5D6C;
    do {
        q = *p;
        for (i = 0; i < 4; i++) {
            if (b == q[i]) {
                return (u16)q[a];
            }
        }
        p++;
    } while (*p != 0);
    return b;
}










/*
 * Addresses are Black-image addresses.
 */
void func_02197EB4(u32 a)
{
    u32 r;

    do {
        r = func_0216D7C4((u8 *)a);
        if (r == 0xFF) {
            return;
        }
    } while (func_02197F20(a, r, func_0216D7D4((u8 *)a)) != 0);
}










u32 func_02197EDC(u8 *p)
{
    if (func_0216D7C4(p) != 0xff) {
        func_02197EB4((u32)p);
        if (func_0216D57C(p, 0x400) == 0) {
            return 0;
        }
    }
    func_0216D570((char *)p, 0x400);
    func_0216D7C0(p, 0xff);
    func_0216D7C8(p, 0);
    return 1;
}









extern int (**const d_021D624C[])(u32);









extern int (**const d_021D5F58[])(u32);










int func_02197F20(u32 a, u32 b, u32 c)
{
    if (func_0216D55C(a, 0x2000) != 0) {
        return d_021D624C[b][c](a);
    }
    return d_021D5F58[b][c](a);
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197F5C(u32 a, u32 b, u32 c, u32 d)
{
func_0216D568((void *)a, (1 << 10));
return 0;
}










/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197F6C(u32 a, u32 b)
{
func_0216D5E0(a, ((b << 16) >> 16));
func_0216D674((void *)a, 0);
func_02163F10(a);
return func_0216D7CC(a);
}











/*
 * Calls func_02197F6C(its own argument 1, 0x0) and returns 0x1.
 */
u32 func_02197F90(u32 a1)
{
    func_02197F6C(a1, 0x0);

    return 0x1;
}











/*
 * Calls func_02197F6C(its own argument 1, 0x1) and returns 0x1.
 */
u32 func_02197F9C(u32 a1)
{
    func_02197F6C(a1, 0x1);

    return 0x1;
}











/*
 * Calls func_02197F6C(its own argument 1, 0x2) and returns 0x1.
 */
u32 func_02197FA8(u32 a1)
{
    func_02197F6C(a1, 0x2);

    return 0x1;
}











/*
 * Calls func_02197F6C(its own argument 1, 0x3) and returns 0x1.
 */
u32 func_02197FB4(u32 a1)
{
    func_02197F6C(a1, 0x3);

    return 0x1;
}











/*
 * Addresses are Black-image addresses.
 */
void func_02197FC0(u8 *a, u32 b, u32 c, u16 d, u16 e)
{
    u16 *r;

    r = func_0216D6BC((int)a, (u32)12);
    r[0] = e;
    r[1] = d;
    ((struct Obj07465 *)r)->f4 = b;
    ((struct Obj07465 *)r)->f8 = c;
    func_02163E7C((int)a, (u16)b);
    func_0216D60C(a, b);
    func_0216D674(a, e);
    func_0216D568(a, 0x20);
    func_0216D7CC((u32)a);
}











u32 func_0219800C(u8 *p)
{
    u8 *h;

    h = func_0216D6D4(p);
    func_02163FC0((int)p, (u16)(((struct Obj05990 *)h)->f4), (u32)(((struct Obj05990 *)h)->f8));
    func_02164010((int)p);
    ((struct Obj05990 *)h)->f2 = ((struct Obj05990 *)h)->f2 - 1;
    if (((struct Obj05990 *)h)->f2 > 0) {
        return 0;
    }
    func_0216D568(p, 0x440);
    func_02163F10((int)p);
    func_0216D674(p, 0);
    func_0216D7CC((u32)p);
    return 0;
}











/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int func_02198060(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x800, 0x20, 0x1);
    return 1;
}











int func_02198074(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x800, 0x20, 0x1);
    return 1;
}











int func_02198088(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x800, 0x20, 0x1);
    return 1;
}











int func_0219809C(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x800, 0x20, 0x1);
    return 1;
}











int func_021980B0(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x1000, 0x10, 0x2);
    return 1;
}











int func_021980C4(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x1000, 0x10, 0x2);
    return 1;
}











/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021980DC(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 2, (2 << 11), 16, 2);
return 1;
}











int func_021980F0(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x1000, 0x10, 0x2);
    return 1;
}











int func_02198104(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x2000, 0x8, 0x3);
    return 1;
}











int func_0219811C(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x2000, 0x8, 0x3);
    return 1;
}











int func_02198134(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x2000, 0x8, 0x3);
    return 1;
}











int func_02198148(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 3, (2 << 12), 8, 3);
return 1;
}











int func_0219815C(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 0, (4 << 12), 4, 4);
return 1;
}











int func_02198170(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 1, (1 << 14), 4, 4);
return 1;
}











int func_02198184(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 2, (2 << 13), 4, 4);
return 1;
}











int func_02198198(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 3, (4 << 12), 4, 4);
return 1;
}











int func_021981AC(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x8000, 0x2, 0x5);
    return 1;
}











int func_021981C4(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x8000, 0x2, 0x5);
    return 1;
}











int func_021981DC(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x8000, 0x2, 0x5);
    return 1;
}











int func_021981F0(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x8000, 0x2, 0x5);
    return 1;
}











int func_02198208(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 0, (1 << 16), 1, 0);
return 1;
}











int func_0219821C(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x10000, 0x1, 0x0);
    return 1;
}











int func_02198234(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x10000, 0x1, 0x0);
    return 1;
}











int func_02198248(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x10000, 0x1, 0x0);
    return 1;
}











int func_02198260(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x4000, 0x4, 0xa);
    return 1;
}











int func_02198278(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x4000, 0x4, 0xa);
    return 1;
}











int func_02198290(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x4000, 0x4, 0xa);
    return 1;
}











int func_021982A4(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x4000, 0x4, 0xa);
    return 1;
}











int func_021982BC(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x1000, 0x10, 0x5);
    return 1;
}











int func_021982D4(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x1000, 0x10, 0x5);
    return 1;
}











int func_021982EC(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x1000, 0x10, 0x5);
    return 1;
}











int func_02198300(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x1000, 0x10, 0x5);
    return 1;
}











void func_02198318(u32 a, u32 b, u16 c, u16 d)
{
    u16 *p;

    p = func_0216D6BC((u32)a, (u32)12);
    p[0] = d;
    p[1] = c;
    func_0216D5E0((u32)a, (u16)b);
    func_0216D674((void *)a, d);
    func_02163F10(a);
    func_0216D7CC((u32)((u8 *)a));
}











int func_0219834C(u32 a)
{
    s16 *p;

    p = func_0216D6D4((void *)a);
    p[1]--;
    if (p[1] > 0) {
        return 0;
    }
    func_0216D568((void *)a, 0x400);
    func_0216D674((void *)a, 0);
    func_0216D7CC((u32)((u8 *)a));
    return 0;
}











/*
 * Calls func_02198318(its own argument 1, 0x0, 0x20, 0x1) and returns 0x1.
 */
u32 func_02198380(u32 a1)
{
    func_02198318(a1, 0x0, 0x20, 0x1);

    return 0x1;
}











/*
 * Calls func_02198318(its own argument 1, 0x1, 0x20, 0x1) and returns 0x1.
 */
u32 func_02198390(u32 a1)
{
    func_02198318(a1, 0x1, 0x20, 0x1);

    return 0x1;
}











/*
 * Calls func_02198318(its own argument 1, 0x2, 0x20, 0x1) and returns 0x1.
 */
u32 func_021983A0(u32 a1)
{
    func_02198318(a1, 0x2, 0x20, 0x1);

    return 0x1;
}











/*
 * Calls func_02198318(its own argument 1, 0x3, 0x20, 0x1) and returns 0x1.
 */
u32 func_021983B0(u32 a1)
{
    func_02198318(a1, 0x3, 0x20, 0x1);

    return 0x1;
}











/*
 * Calls func_02198318(its own argument 1, 0x0, 0x10, 0x2) and returns 0x1.
 */
u32 func_021983C0(u32 a1)
{
    func_02198318(a1, 0x0, 0x10, 0x2);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x1, 0x10, 0x2) and returns 0x1.
 */
u32 func_021983D0(u32 a1)
{
    func_02198318(a1, 0x1, 0x10, 0x2);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x2, 0x10, 0x2) and returns 0x1.
 */
u32 func_021983E0(u32 a1)
{
    func_02198318(a1, 0x2, 0x10, 0x2);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x3, 0x10, 0x2) and returns 0x1.
 */
u32 func_021983F0(u32 a1)
{
    func_02198318(a1, 0x3, 0x10, 0x2);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x0, 0x8, 0x3) and returns 0x1.
 */
u32 func_02198400(u32 a1)
{
    func_02198318(a1, 0x0, 0x8, 0x3);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x1, 0x8, 0x3) and returns 0x1.
 */
u32 func_02198410(u32 a1)
{
    func_02198318(a1, 0x1, 0x8, 0x3);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x2, 0x8, 0x3) and returns 0x1.
 */
u32 func_02198420(u32 a1)
{
    func_02198318(a1, 0x2, 0x8, 0x3);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x3, 0x8, 0x3) and returns 0x1.
 */
u32 func_02198430(u32 a1)
{
    func_02198318(a1, 0x3, 0x8, 0x3);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x0, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198440(u32 a1)
{
    func_02198318(a1, 0x0, 0x4, 0x4);

    return 0x1;
}










/*
 * Calls func_02198318(its own argument 1, 0x1, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198450(u32 a1)
{
    func_02198318(a1, 0x1, 0x4, 0x4);

    return 0x1;
}









/*
 * Calls func_02198318(its own argument 1, 0x2, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198460(u32 a1)
{
    func_02198318(a1, 0x2, 0x4, 0x4);

    return 0x1;
}









/*
 * Calls func_02198318(its own argument 1, 0x3, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198470(u32 a1)
{
    func_02198318(a1, 0x3, 0x4, 0x4);

    return 0x1;
}









/*
 * Calls func_02198318(its own argument 1, 0x0, 0x2, 0x5) and returns 0x1.
 */
u32 func_02198480(u32 a1)
{
    func_02198318(a1, 0x0, 0x2, 0x5);

    return 0x1;
}









/*
 * Calls func_02198318(its own argument 1, 0x1, 0x2, 0x5) and returns 0x1.
 */
u32 func_02198490(u32 a1)
{
    func_02198318(a1, 0x1, 0x2, 0x5);

    return 0x1;
}









/*
 * Calls func_02198318(its own argument 1, 0x2, 0x2, 0x5) and returns 0x1.
 */
u32 func_021984A0(u32 a1)
{
    func_02198318(a1, 0x2, 0x2, 0x5);

    return 0x1;
}







/*
 * Calls func_02198318(its own argument 1, 0x3, 0x2, 0x5) and returns 0x1.
 */
u32 func_021984B0(u32 a1)
{
    func_02198318(a1, 0x3, 0x2, 0x5);

    return 0x1;
}







/*
 * Addresses are Black-image addresses.
 */
void func_021984C0(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g, u32 h)
{
    u8 *r;

    r = func_0216D6BC((int)a, (u32)16);
    r[12] = b;
    ((struct Obj05004 *)r)->f0 = c;
    r[13] = d;
    r[14] = e;
    r[15] = f;
    ((struct Obj05004 *)r)->f8 = g;
    if (c == 0) {
        func_02163F10((int)a);
    } else {
        func_02163E7C((int)a, (u16)b);
    }
    func_0216D568(a, 0xa0);
    func_0216D60C((u8 *)((int)a), (u16)b);
    func_0216D674(a, e);
    func_0216D7CC((u32)a);
    if (h != 0) {
        func_020061E4();
    }
}










/*
 * Addresses are Black-image addresses.
 */
void func_0219852C(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g)
{
    func_021984C0(a, b, c, d, e, f, g, 0x55E);
}










int func_02198550(u32 a)
{
    u8 *h;

    h = func_0216D6D4((void *)a);
    if (((struct Obj01032 *)h)->f0 != 0) {
        func_02163FC0(a, ((struct Obj01032 *)h)->fC, ((struct Obj01032 *)h)->f0);
        func_02164010(a);
        if (((struct Obj01032 *)h)->f4 >= 0x10000) {
            ((struct Obj01032 *)h)->f4 = 0;
            func_02163E7C(a, ((struct Obj01032 *)h)->fC);
            func_0216D568((void *)a, 0x20);
        }
        ((struct Obj01032 *)h)->f4 += (((struct Obj01032 *)h)->f0 < 0) ? -((struct Obj01032 *)h)->f0 : ((struct Obj01032 *)h)->f0;
    }
    ((struct Obj01032 *)h)->fA += ((struct Obj01032 *)h)->f8;
    if (((struct Obj01032 *)h)->fA > 0xF00) {
        ((struct Obj01032 *)h)->fA = 0xF00;
    }
    {
        Vec v;
        u16 k;
        int i;
        k = ((struct Obj01032 *)h)->fA / 256;
        i = ((struct Obj01032 *)h)->fF;
        v.x = 0;
        v.y = d_021DDBD4[i][k];
        v.z = 0;
        func_0216D8C0(a, &v);
    }
    ((struct Obj01032 *)h)->fD = ((struct Obj01032 *)h)->fD - 1;
    if (((struct Obj01032 *)h)->fD > 0) {
        return 0;
    }
    {
        Vec v = { 0, 0, 0 };
        func_0216D8C0(a, &v);
    }
    func_0216D568((void *)a, 0x540);
    func_02163F10(a);
    func_0216D674((void *)a, 0);
    func_0216D7CC((u32)((u8 *)a));
    func_020061E4(0x67B);
    return 1;
}










int func_0219862C(u8 *a)
{
    func_0219852C(a, 0, 0x0, 16, 2, 1, 0x100);
    return 1;
}










int func_02198650(u8 *a)
{
    func_0219852C(a, 1, 0x0, 16, 2, 1, 0x100);
    return 1;
}










int func_02198674(u8 *a)
{
    func_0219852C(a, 2, 0x0, 16, 2, 1, 0x100);
    return 1;
}










int func_02198694(u8 *a)
{
    func_0219852C(a, 3, 0x0, 16, 2, 1, 0x100);
    return 1;
}










int func_021986B8(u8 *a)
{
    func_0219852C(a, 0, 0x0, 8, 3, 1, 0x200);
    return 1;
}










int func_021986D8(u8 *a)
{
    func_0219852C(a, 1, 0x0, 8, 3, 1, 0x200);
    return 1;
}










int func_021986F8(u8 *a)
{
    func_0219852C(a, 2, 0x0, 8, 3, 1, 0x200);
    return 1;
}










int func_02198718(u8 *a)
{
    func_0219852C(a, 3, 0x0, 8, 3, 1, 0x200);
    return 1;
}










int func_02198738(u8 *a)
{
    func_0219852C(a, 0, 0x2000, 8, 3, 0, 0x200);
    return 1;
}










int func_02198758(u8 *a)
{
    func_0219852C(a, 1, 0x2000, 8, 3, 0, 0x200);
    return 1;
}










int func_0219877C(u8 *a)
{
    func_0219852C(a, 2, 0x2000, 8, 3, 0, 0x200);
    return 1;
}










int func_021987A0(u8 *a)
{
    func_0219852C(a, 3, 0x2000, 8, 3, 0, 0x200);
    return 1;
}










int func_021987C0(u8 *a)
{
    func_0219852C(a, 0, 0x2000, 16, 3, 0, 0x100);
    return 1;
}










int func_021987E0(u8 *a)
{
    func_0219852C(a, 1, 0x2000, 16, 3, 0, 0x100);
    return 1;
}










int func_02198804(u8 *a)
{
    func_0219852C(a, 2, 0x2000, 16, 3, 0, 0x100);
    return 1;
}










int func_02198824(u8 *a)
{
    func_0219852C(a, 3, 0x2000, 16, 3, 0, 0x100);
    return 1;
}










int func_02198848(u8 *a)
{
    func_0219852C(a, 2, 0x1000, 16, 2, 0, 0xF0);
    return 1;
}










int func_02198868(u8 *a)
{
    func_0219852C(a, 3, 0x1000, 16, 2, 0, 0xF0);
    return 1;
}










int func_02198888(u8 *a)
{
    func_0219852C(a, 2, 0x4000, 12, 3, 0, 0x140);
    return 1;
}










int func_021988AC(u8 *a)
{
    func_0219852C(a, 3, 0x4000, 12, 3, 0, 0x140);
    return 1;
}










int func_021988D0(u8 *a)
{
    func_021984C0(a, 0, 0x2000, 24, 3, 0, 0xA0, 0);
    return 1;
}









int func_021988F4(u8 *a)
{
    func_021984C0(a, 1, 0x2000, 24, 3, 0, 0xA0, 0);
    return 1;
}









int func_02198918(u8 *a)
{
    func_021984C0(a, 2, 0x2000, 24, 3, 0, 0xA0, 0);
    return 1;
}







int func_0219893C(u8 *a)
{
    func_021984C0(a, 3, 0x2000, 24, 3, 0, 0xA0, 0);
    return 1;
}






int func_02198960(u32 a, u32 b)
{
((struct Obj17951 *)((u8 *)(func_0216D6BC(a, 4))))->f0 = b;
return func_0216D7CC((u32)((u8 *)a));
}







/*
 * Addresses are Black-image addresses.
 */
int func_02198978(u32 a)
{
    int *p;

    p = (int *)func_0216D6D4((void *)a);
    if (*p != 0) {
        *p -= 1;
        return 0;
    }
    func_0216D7CC((u32)((u8 *)a));
    return 1;
}








/*
 * Calls func_02198960(its own argument 1, 0x1) and returns 0x1.
 */
u32 func_02198998(u32 a1)
{
    func_02198960(a1, 0x1);

    return 0x1;
}








/*
 * Calls func_02198960(its own argument 1, 0x2) and returns 0x1.
 */
u32 func_021989A4(u32 a1)
{
    func_02198960(a1, 0x2);

    return 0x1;
}








/*
 * Calls func_02198960(its own argument 1, 0x4) and returns 0x1.
 */
u32 func_021989B0(u32 a1)
{
    func_02198960(a1, 0x4);

    return 0x1;
}








/*
 * Calls func_02198960(its own argument 1, 0x8) and returns 0x1.
 */
u32 func_021989BC(u32 a1)
{
    func_02198960(a1, 0x8);

    return 0x1;
}








/*
 * Calls func_02198960(its own argument 1, 0xf) and returns 0x1.
 */
u32 func_021989C8(u32 a1)
{
    func_02198960(a1, 0xf);

    return 0x1;
}







/*
 * Calls func_02198960(its own argument 1, 0x10) and returns 0x1.
 */
u32 func_021989D4(u32 a1)
{
    func_02198960(a1, 0x10);

    return 0x1;
}







/*
 * Calls func_02198960(its own argument 1, 0x20) and returns 0x1.
 */
u32 func_021989E0(u32 a1)
{
    func_02198960(a1, 0x20);

    return 0x1;
}






/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC ((u32)0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021989EC(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj17952 *)((u8 *)(func_0216D6BC(a, 8))))->f4 = (8 << 13);
func_0216D674((void *)a, 0);
func_0216D7CC((u32)((u8 *)a));
return 1;
}






/*
 * Addresses are Black-image addresses.
 */
int func_02198A10(u32 a)
{
    int *p;

    p = func_0216D6D4((void *)a);
    p[0] = p[0] + p[1];
    {
        Vec v = { 0, 0, 0 };
        v.y = p[0];
        func_0216D8C0(a, &v);
    }
    if (p[0] / 0x8000 < 0x28) {
        return 0;
    }
    func_0216D7CC((u32)((u8 *)a));
    return 1;
}




int func_02198A58(u32 a)
{
    u32 *p;

    p = (u32 *)func_0216D6BC(a, 8);
    p[0] = 0x140000;
    p[1] = 0xFFFF0000;
    func_020061E4(0x676);
    func_0216D674((void *)a, 0);
    func_0216D7CC((u32)((u8 *)a));
    return 1;
}






/*
 * Addresses are Black-image addresses.
 */
int func_02198A8C(u32 a)
{
    int *p;

    p = func_0216D6D4((void *)a);
    p[0] = p[0] + p[1];
    if (p[0] < 0) {
        p[0] = 0;
    }
    {
        Vec v = { 0, 0, 0 };
        v.y = p[0];
        func_0216D8C0(a, &v);
    }
    if (p[0] > 0) {
        return 0;
    }
    func_0216D7CC((u32)((u8 *)a));
    return 1;
}






/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC ((u32)((u8 *)0x0216D7CC)) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02198AD4(u32 a, u32 b, u32 c, u32 d)
{
func_0216D548((u32 *)a, 4);
func_0216D7CC((u32)((u8 *)a));
return 1;
}






int func_02198AE8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D550((u32 *)a, 4);
func_0216D7CC((u32)((u8 *)a));
return 1;
}






int func_02198AFC(u32 a, u32 b, u32 c, u32 d)
{
func_0216D548((u32 *)a, 8);
func_0216D7CC((u32)((u8 *)a));
return 1;
}






int func_02198B10(u32 a, u32 b, u32 c, u32 d)
{
func_0216D550((u32 *)a, 8);
func_0216D7CC((u32)((u8 *)a));
return 1;
}






int func_02198B24(u32 a, u32 b, u32 c, u32 d)
{
func_0216D548((u32 *)a, 16);
func_0216D7CC((u32)((u8 *)a));
return 1;
}






int func_02198B38(u32 a, u32 b, u32 c, u32 d)
{
func_0216D550((u32 *)a, 16);
func_0216D7CC((u32)((u8 *)a));
return 1;
}






/*
 * Addresses are Black-image addresses.
 */
void func_02198B4C(u32 a, u32 b, u32 a3)
{
    u32 *p;

    p = func_0216D6BC(a, 8);
    p[0] = b;
    p[1] = func_021BB528(func_02188CD0((u8 *)func_0216D534(func_0216D67C((void *)a))), a, b, 1);
    func_0216D7CC((u32)((u8 *)a));
}






int func_02198B80(u32 a)
{
    u32 *p;

    p = func_0216D6D4((void *)a);
    if (func_021BB5C8(p[1]) == 1) {
        func_021AC154(p[1]);
        func_0216D7CC((u32)((u8 *)a));
        return 1;
    }
    return 0;
}






/*
 * Calls func_02198B4C(its own argument 1, 0x0, 0x0) and returns 0x0.
 */
u32 func_02198BA8(u32 a1)
{
    func_02198B4C(a1, 0x0, 0x0);

    return 0x0;
}






u32 func_02198BB8(u32 a1)
{
    func_02198B4C(a1, 0x0, 0x0);

    return 0x0;
}






u32 func_02198BC8(u32 a1)
{
    func_02198B4C(a1, 0x0, 0x0);

    return 0x0;
}






/*
 * Calls func_02198B4C(its own argument 1, 0x1, 0x0) and returns 0x0.
 */
u32 func_02198BD8(u32 a1)
{
    func_02198B4C(a1, 0x1, 0x0);

    return 0x0;
}






/*
 * Calls func_02198B4C(its own argument 1, 0x2, 0x0) and returns 0x0.
 */
u32 func_02198BE8(u32 a1)
{
    func_02198B4C(a1, 0x2, 0x0);

    return 0x0;
}






/*
 * Calls func_02198B4C(its own argument 1, 0x3, 0x0) and returns 0x0.
 */
u32 func_02198BF8(u32 a1)
{
    func_02198B4C(a1, 0x3, 0x0);

    return 0x0;
}




void func_02198C08(u32 a, u32 b, u32 c, u16 d)
{
    u16 *p;

    p = func_0216D6BC(a, 8);
    p[0] = b;
    p[1] = d;
    p[2] = c;
    func_02163E7C(a, ((b << 16) >> 16));
    func_0216D60C((u8 *)a, (u16)b);
    func_0216D674((void *)a, d);
    func_0216D568((void *)a, 32);
    func_0216D7CC((u32)((u8 *)a));
}





/*
 * Addresses are Black-image addresses.
 */
int func_02198C4C(u32 a, u32 *b)
{
    s16 *p;

    p = func_0216D6D4((void *)a);
    func_02163FC0(a, ((struct Obj05005 *)p)->f0, b[p[3]]);
    func_02164010(a);
    p[3] = p[3] + 1;
    if (p[3] < p[2]) {
        return 0;
    }
    func_0216D568((void *)a, 1088);
    func_02163F10(a);
    func_0216D674((void *)a, 0);
    func_0216D7CC((u32)((u8 *)a));
    return 1;
}






/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CA4(u32 a1)
{
    func_02198C08(a1, 0x0, 0x6, 0x6);

    return 0x1;
}






/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CB4(u32 a1)
{
    func_02198C08(a1, 0x1, 0x6, 0x6);

    return 0x1;
}






/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CC4(u32 a1)
{
    func_02198C08(a1, 0x2, 0x6, 0x6);

    return 0x1;
}





/*
 * Calls func_02198C08(its own argument 1, 0x3, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CD4(u32 a1)
{
    func_02198C08(a1, 0x3, 0x6, 0x6);

    return 0x1;
}





/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x6, 0xb) and returns 0x1.
 */
u32 func_02198CE4(u32 a1)
{
    func_02198C08(a1, 0x0, 0x6, 0xb);

    return 0x1;
}





/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x6, 0xb) and returns 0x1.
 */
u32 func_02198CF4(u32 a1)
{
    func_02198C08(a1, 0x1, 0x6, 0xb);

    return 0x1;
}





/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x6, 0xb) and returns 0x1.
 */
u32 func_02198D04(u32 a1)
{
    func_02198C08(a1, 0x2, 0x6, 0xb);

    return 0x1;
}





/*
 * Calls func_02198C08(its own argument 1, 0x3, 0x6, 0xb) and returns 0x1.
 */
u32 func_02198D14(u32 a1)
{
    func_02198C08(a1, 0x3, 0x6, 0xb);

    return 0x1;
}
