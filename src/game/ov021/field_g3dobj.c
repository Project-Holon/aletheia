/*
 * file:     field_g3dobj.c
 * unit:     yes
 * function: func_021C5FA8, func_021C5FC0, func_021C5FEC, func_021C6018, func_021C602C, func_021C6054, func_021C6068, func_021C6078, func_021C60B8, func_021C61D4, func_021C61EC, func_021C622C, func_021C62F0, func_021C6368, func_021C63AC, func_021C6400, func_021C6470, func_021C64E0, func_021C6534, func_021C6538, func_021C6574, func_021C6580, func_021C6590, func_021C6628, func_021C6658, func_021C6664, func_021C6678, func_021C6694, func_021C66EC, func_021C6744, func_021C67A8, func_021C67D8, func_021C67F4, func_021C6828, func_021C6844, func_021C6854, func_021C6874, func_021C6940, func_021C69B4, func_021C6A90, func_021C6AE0, func_021C6AF0, func_021C6AF8, func_021C6AFC, func_021C6B18, func_021C6B8C, func_021C6BB4
 * address:  0x021C5FA8
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
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021AE01C  0x021AE01C  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021ADF94  0x021ADF94  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_021C1D68  0x021C1D68  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021A9F40  0x021A9F40  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021D3288  0x021D3288  thumb  ov021
 *   func_021D325C  0x021D325C  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 *   d_021DAAB4     0x021DAAB4  data  a2
 *   func_02040588  0x02040588  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE4A8     0x021DE4A8  data  ov021  a1
 *   func_020307B0  0x020307B0  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047910  0x02047910  arm
 *   func_0204784C  0x0204784C  arm
 *   func_02047828  0x02047828  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02046E24   0x02046E24  arm
 *   func_02046F50   0x02046F50  arm
 *   func_02046F48   0x02046F48  arm
 *   func_0206E964   0x0206E964  arm
 *   func_02022040   0x02022040  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02082C60  0x02082C60  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_0218ED54  0x0218ED54  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DE4B8     0x021DE4B8  data  ov021  a4
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 *   _ffix          0x0209C494  arm
 *   _fflt          0x0209BDBC  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _dsqrt         0x0209C5E0  arm
 *   _fgr           0x0209BBB0  arm
 */
#include "../../matched/include/Obj07564.h"
#include "../../matched/include/Obj06080.h"
#include "../../matched/include/Obj06081.h"
#include "../../matched/include/Obj06082.h"
#include "../../matched/include/Obj18307.h"
#include "../../matched/include/Obj06083.h"
#include "../../matched/include/Obj00458.h"
#include "../../matched/include/Obj18309.h"
#include "../../matched/include/Obj18310.h"
#include "../../matched/include/Obj18311.h"
#include "../../matched/include/Obj12952.h"
#include "../../matched/include/Obj12953.h"
#include "../../matched/include/Obj09694.h"
#include "../../matched/include/Obj18312.h"
#include "../../matched/include/Obj01866.h"
#include "../../matched/include/Obj06084.h"
#include "../../matched/include/Obj18313.h"
#include "../../matched/include/Obj06085.h"
#include "../../matched/include/Obj03145.h"

struct Ctx;
struct Desc;
struct Obj;
struct Obj00020;
struct Evt;
struct St021D3244;
struct St021D325C;
struct Arg;
struct AnmCtl;
struct Tagged;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Node;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x60];
    u32 f60;
} Work;

typedef unsigned short u16;

typedef struct {
    u8 f0;
    u8 pad1[3];
    u32 f4;
    u32 f8;
    void *fC;
    void *f10;
} Work_021C6078;

typedef signed short s16;

typedef signed char s8;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    void *f4;
} Ctx;

typedef struct {
    u16 x;
    u16 y;
} Pt;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    void *f8;
    void *fC;
} Work_021C62F0;

typedef struct {
    u32 kind : 2;
    u32 rest : 30;
    u16 f4;
    u16 f6;
    u8 pad8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6400;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6400 *fC;
} Mgr_021C6400;

typedef struct {
    u32 kind : 2;
    u32 rest : 30;
    u16 f4;
    u16 f6;
    u8 pad8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6470;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6470 *fC;
} Mgr_021C6470;

typedef struct {
    u32 kind : 2;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 rest : 26;
    u16 f4;
    u16 f6;
    u8 f8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C64E0;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    void *f8;
    Elem_021C64E0 *fC;
} Mgr_021C64E0;

typedef struct { u32 f0; u8 pad[0x28]; } Item_021C6078;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item_021C6078 *f8; } Mgr;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    u32 kind : 2;
    u32 b2 : 1;
    u32 rest : 29;
    u16 f4;
    u16 f6;
    Vec f8;
    int f14;
    int f18;
    int f1C;
    u8 f20[0x24];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6590;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6590 *fC;
} Mgr_021C6590;

typedef struct { u8 pad[0x2c]; } Item_021C6580;

typedef struct { u32 k:2; u32 rest:30; u16 f4; u8 pad[0x62]; } Elem_021C6628;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item_021C6580 *f8; Elem_021C6628 *fC; } Mgr_021C6628;

typedef struct { u32 f0; u32 f4; u32 f8[8]; u8 f28; u8 f29; } S;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10[8];
    u8 f20;
} D;

typedef struct { u32 x, y, z; } V_021C69B4;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C69B4 f8;
    u32 f14;
    u32 f18;
    u32 f1C;
    u8 f20[0x24];
    u32 f44;
    u32 f48[8];
} Elem_021C69B4;

typedef struct { u32 a, b, c; } V_021C6664;

typedef struct { u32 f0; u32 f4; V_021C6664 f8; u8 pad[0x68 - 0x14]; } Elem_021C6664;

typedef struct { u8 pad[0xc]; Elem_021C6664 *fC; } Mgr_021C6664;

typedef struct { u32 k:2; u32 x:1; u32 b:1; u32 rest:28; u8 pad[0x64]; } Elem_021C6678;

typedef struct { u8 pad[0xc]; Elem_021C6678 *fC; } Mgr_021C6678;

typedef struct { u32 k : 2; } K;

typedef signed int s32;

typedef struct { u32 a, b, c; } V_021C67A8;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C67A8 f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem_021C67A8;

typedef struct { u8 pad[0x2c]; } Item;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C67A8 *fC; } Mgr_021C67A8;

typedef struct { u32 a, b, c; } V_021C67D8;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C67D8 f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem_021C67D8;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C67D8 *fC; } Mgr_021C67D8;

typedef struct { u32 a, b, c; } V_021C67F4;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C67F4 f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem_021C67F4;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C67F4 *fC; } Mgr_021C67F4;

typedef struct { u32 a, b, c; } V_021C6828;

typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V_021C6828 f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem_021C6828;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C6828 *fC; } Mgr_021C6828;

typedef struct {
    u8 pad0[0x30];
    u16 f30;
    u8 pad32[6];
    u32 f38;
} Pal;

typedef struct { u32 f0; u16 f4; u16 f6; } P;

extern u32 func_020362DC(void);
extern u32 func_02188CD0(u8 *p);
extern void func_0216D674(void *p, unsigned short v);
extern u32 func_021BB528(u32 a, u32 b, u32 c, u32 d);
extern void func_021AE01C(u32 a, u16 v);
extern void func_021AC154(u32 a);
extern u32 func_021ADF94(u32 a, void *b, u32 c, int d);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void *func_021A3074(u8 *p);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D480(char *p);
extern void *func_02189A00(u8 *p);
extern int func_021C1D68(int a, int b, int c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02188CE8(u8 *p);
extern int func_021A9F40(struct Ctx *ctx, int mode);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void *func_02188C7C(u8 *p);
extern u32 *func_0216D9E4(void *c);
extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u8 *p);
extern u32 func_02188E30(u8 *p);
extern void func_020061E4(u32 a);
extern void func_021D3288(void *a, int b, int c);
extern void func_021D325C(struct St021D325C *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021D3244(struct St021D3244 *p, int i, u8 v);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_0207ADC4(void *p);
extern int func_020478B8(void *a, int idx, int amount);
extern int func_02047910(void *a, int idx, int amount);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern int func_02046FF8(int *self);
extern void *func_02046E24(u32 a0, u32 a1);
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern void func_02082C60(void *p, int v, int n);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern int func_02047788(int *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_02082A7C(u32 a, u32 b, u32 c);
extern void func_02030EAC(struct Node *n);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *p);
extern u32 func_02188D30(u8 *p);
extern u32 func_0218ED54(u8 *p);
extern void func_02030DA8(u32 a, void *cb, void *arg, int z);
extern void func_0218ED58(u8 *p, u32 v);
extern double _dsqrt(double x);
int func_021C5FA8(Work *w, u32 n);
int func_021C5FC0(u8 *p, u32 lim);
void func_021C5FEC(u8 *p);
void func_021C6018(u32 *p);
void func_021C602C(u8 *p);
void func_021C6054(u32 *p);
void *func_021C6068(void *a, void *b);
void *func_021C6078(void *a, void *b, u8 c);
int func_021C60B8(void *task, int *state, Work_021C6078 *w);
int func_021C61D4(u32 a);
void func_021C61EC(void *a, void *b, void *c);
int func_021C622C(void *unused, int *st, Ctx *c);
void func_021C62F0(u8 *p);
void func_021C6368(u8 *p);
Work_021C62F0 *func_021C63AC(u32 heap, u32 n, u32 m);
void func_021C6400(Mgr_021C6400 *m);
void func_021C6470(Mgr_021C6470 *m);
void func_021C64E0(Mgr_021C64E0 *m);
void func_021C6534(u32 *p, u32 v);
u16 func_021C6538(Mgr *m, void *c, int d, int e);
int func_021C6574(u32 a, u32 b, u32 c);
void func_021C6580(u8 *p, int i);
u16 func_021C6590(Mgr_021C6590 *m, u16 idx, u16 a, Vec *src);
void func_021C6628(Mgr_021C6628 *m, int idx);
int func_021C6658(u32 a, u32 b);
void func_021C6664(Mgr_021C6664 *m, int idx, V_021C6664 *v);
void func_021C6678(Mgr_021C6678 *m, int idx, int v);
int func_021C6694(u32 *a, int idx, int v);
int func_021C66EC(u32 *a, int idx, int v);
void func_021C6744(u32 *a, int idx, int mode, u32 val);
int func_021C67A8(Mgr_021C67A8 *m, int idx, int i);
void func_021C67D8(Mgr_021C67D8 *m, int idx, int v);
void func_021C67F4(Mgr_021C67F4 *m, int idx);
void func_021C6828(Mgr_021C6828 *m, int idx, int v);
int func_021C6844(int a, int b);
void func_021C6854(S *s);
void func_021C6874(S *s, int unused, D *d, int mode, int flag);
void func_021C6940(u8 *p);
void func_021C69B4(Elem_021C69B4 *e, S *s, u16 idx, u16 id, u32 unused, V_021C69B4 *pos, int flag);
void func_021C6A90(u32 *p, u8 *q);
void func_021C6AE0(u32 a);
int func_021C6AF0(u32 a, u32 b, u32 c);
void func_021C6AF8(u32 *p, u32 v);
void func_021C6AFC(D *d, u16 v);
void func_021C6B18(u32 a, u16 b, u32 c);
void func_021C6B8C(void *task, P *p);
void func_021C6BB4(u8 *p);
extern const Pt d_021DAAB4;
extern char d_021DE4A8[];
extern int d_021DE4B8;






int func_021C5FA8(Work *w, u32 n)
{
    if (w->f60++ < n)
        return 0;
    w->f60 = 0;
    return 1;
}






/*
 * Wait step: 1 on a key press, 2 on timeout, otherwise 0.
 */
int func_021C5FC0(u8 *p, u32 lim)
{
    u32 n = ((struct Obj07564 *)p)->f60;

    ((struct Obj07564 *)p)->f60 = n + 1;
    if (n < lim) {
        if (func_020362DC() & 1) {
            ((struct Obj07564 *)p)->f60 = 0;
            return 1;
        }
    } else {
        ((struct Obj07564 *)p)->f60 = 0;
        return 2;
    }
    return 0;
}






/*
 * Switches the window to mode 2 and opens the message box.
 */
void func_021C5FEC(u8 *p)
{
    u32 o = func_02188CD0((u8 *)(((struct Obj06080 *)p)->f8));

    func_0216D674((void *)(((struct Obj06080 *)p)->f1C), 2);
    ((struct Obj06080 *)p)->f2C = func_021BB528(o, ((struct Obj06080 *)p)->f1C, 0, 1);
    func_021AE01C(((struct Obj06080 *)p)->f30, 1);
}





void func_021C6018(u32 *p)
{
    if (p[11] != 0) {
        func_021AC154(p[11]);
        p[11] = 0;
    }
}





void func_021C602C(u8 *p)
{
    ((struct Obj06081 *)p)->f30 = func_021ADF94(func_02188CD0((u8 *)(((struct Obj06081 *)p)->f8)), p + 0x40, ((struct Obj06081 *)p)->f58, ((struct Obj06081 *)p)->f44 == ((struct Obj06081 *)p)->f38);
}




void func_021C6054(u32 *p)
{
    if (p[12] != 0) {
        func_021AC154(p[12]);
        p[12] = 0;
    }
}



void *func_021C6068(void *a, void *b) { return func_021C6078(b, a, 0xff); }










void *func_021C6078(void *a, void *b, u8 c)
{
    void *task;
    u8 *w;

    task = func_020122C0(a, 0, func_021C60B8, 0x14);
    w = func_020124E8(task);
    func_02082BCC(w, 0, 0x14);
    w[0] = c;
    ((struct Obj06082 *)w)->f4 = a;
    ((struct Obj06082 *)w)->fC = b;
    ((struct Obj06082 *)w)->f10 = func_02188CB4(b);
    ((struct Obj06082 *)w)->f8 = func_020120F4(a);
    return task;
}










int func_021C60B8(void *task, int *state, Work_021C6078 *w)
{
    void *t;

    switch (*state) {
    case 0:
        if (w->f0 >= 6) {
            *state = 5;
            break;
        }
        func_021A2F48(w->f10, 0x80);
        (*state)++;
    case 1:
        if (func_021A2F54(w->f10) != 1)
            break;
        func_0216D410(func_021A3074(w->f10), 0xa2);
        (*state)++;
        break;
    case 2:
        if (func_0216D480(func_021A3074(w->f10)) != 1)
            break;
        t = (void *)func_021C1D68(w->f4, (int)func_02189A00(w->fC), w->f0);
        if (t != 0)
            func_02012374(task, t);
        (*state)++;
        break;
    case 3:
        func_021A2F48(w->f10, 8);
        (*state)++;
    case 4:
        if (func_021A2F54(w->f10) != 1)
            break;
        *state = 5;
        break;
    case 5:
        if (func_021C61D4((u32)w) == 0) {
            *state = 8;
            break;
        }
        func_021C61EC(task, (void *)w->f4, w->fC);
        *state = 6;
        break;
    case 6:
        t = (void *)func_021A9F40((struct Ctx *)func_02188CE8(w->fC), 2);
        if (t == 0) {
            *state = 7;
            break;
        }
        func_02012374(task, t);
        *state = 9;
        break;
    case 7:
        func_02158780(task, 0x2793, 0, 0, 0x15);
        *state = 9;
        break;
    case 8:
        func_02158780(task, 0x2794, 0, 0, 0x15);
        *state = 9;
        break;
    case 9:
        func_0216D9E4(func_02188C7C(w->fC));
        return 1;
    }
    return 0;
}










int func_021C61D4(u32 a)
{
if (func_021A1BF4((u8 *)func_02188C6C((u8 *)(((struct Obj18307 *)((u8 *)(a)))->fC))) == 0) {
    return 1;
}
return 0;
}










void func_021C61EC(void *a, void *b, void *c)
{
    void *task;
    u8 *w;

    task = func_020122C0(b, 0, func_021C622C, 8);
    w = func_020124E8(task);
    w[0] = 3;
    w[1] = 0;
    w[2] = 2;
    w[3] = 0;
    ((struct Obj06083 *)w)->f4 = func_02188E30(c);
    func_02012374(a, task);
}










int func_021C622C(void *unused, int *st, Ctx *c)
{
    switch (*st) {
    case 0:
        func_021C62F0((u8 *)c);
        func_020061E4(0x683);
        *st = *st + 1;
        break;
    case 1:
        if (c->f3++ >= c->f2) {
            c->f1++;
            func_021D3288(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 >= 8) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (c->f3++ < 0x1e) {
            *st = *st + 1;
        }
        break;
    case 3:
        if (c->f3++ >= c->f2) {
            c->f1--;
            func_021D3288(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 == 0) {
            *st = *st + 1;
        }
        break;
    case 4:
        func_021D325C(c->f4, 0, 0, 0, 0x1f);
        func_021D3244(c->f4, c->f0, 0);
        *st = *st + 1;
        break;
    default:
        func_021C6368((u8 *)c);
        return 1;
    }
    return 0;
}









void func_021C62F0(u8 *p)
{
    Pt pt;

    pt = d_021DAAB4;
    func_02040588(p[0], 0);
    func_02040E78(p[0], &pt, 8, 0x20);
    func_02040C14(p[0], 1, 1, 0x100);
    func_02041300(p[0], 0x100, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_021D325C(((struct Obj00458 *)p)->f4, 8, 0x37, p[1], 0x10 - p[1]);
    func_021D3244(((struct Obj00458 *)p)->f4, p[0], 1);
}









void func_021C6368(u8 *p)
{
    Pt pt = {0, 0};

    func_02040E78(p[0], &pt, 8, 0x20);
    func_02041300(p[0], 0, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_02040DA8(p[0], 1, 0x100);
}









Work_021C62F0 *func_021C63AC(u32 heap, u32 n, u32 m)
{
    Work_021C62F0 *w;

    w = func_02030734(heap, 0x14, 1, d_021DE4A8, 0x72);
    w->f8 = func_02030734(heap, n * 0x2c, 1, d_021DE4A8, 0x75);
    w->fC = func_02030734(heap, m * 0x68, 1, d_021DE4A8, 0x78);
    w->f0 = heap;
    w->f4 = n;
    w->f6 = m;
    w->f2 = 1;
    return w;
}









void func_021C6400(Mgr_021C6400 *m)
{
    u32 i;
    Elem_021C6400 *e;
    u8 *s;

    i = 0;
    m->f2 = 0;
    e = m->fC;
    if (i < m->f6)
        for (; i < m->f6; i++) {
            if (e->kind == 1 && e->f44 != 0)
                func_021C6A90((u32 *)e, m->f8 + e->f4 * 0x2c);
            e++;
        }
    func_020307B0(m->fC);
    i = 0;
    s = m->f8;
    if (i < m->f4)
        for (; i < m->f4; i++) {
            func_021C6940(s);
            s += 0x2c;
        }
    func_020307B0(m->f8);
    func_020307B0(m);
}









void func_021C6470(Mgr_021C6470 *m)
{
    int i;
    int j;
    Elem_021C6470 *e;
    u8 *s;

    if (m->f2 == 1) {
        e = m->fC;
        s = m->f8;
        for (i = 0; i < m->f4; i++) {
            if (s[0x29] == 2)
                func_021C6854((S *)s);
            s += 0x2c;
        }
        s = m->f8;
        for (j = 0; j < m->f6; j++) {
            if (e->kind == 2)
                func_021C69B4((Elem_021C69B4 *)e, (S *)(s + e->f4 * 0x2c), e->f4, e->f6, m->f0, 0, 0);
            e++;
        }
    }
}









void func_021C64E0(Mgr_021C64E0 *m)
{
    u32 i;
    Elem_021C64E0 *e;

    e = m->fC;
    for (i = 0; i < m->f6; i++) {
        if (e->kind == 1) {
            if (e->b4 == 0 && e->b3 == 0) {
                if (e->b2 == 1)
                    func_02047AC8(e->f44, (struct Arg *)e->f8);
                else
                    func_02047A60(e->f44, (struct Arg *)e->f8);
            }
            e->b5 = 0;
        }
        e++;
    }
}







/*
 * Setter: stores the second argument at +0x10.  Unlabelled in the listing;
 * called from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6534(u32 *p, u32 v)
{
    p[4] = v;
}





u16 func_021C6538(Mgr *m, void *c, int d, int e)
{
    u16 i;
    Item_021C6078 *it = m->f8;
    for (i = 0; i < m->f4; i++, it++) {
        if (it->f0 == 0) {
            func_021C6874((S *)it, m->f0, (D *)c, d, e);
            return i;
        }
    }
    return 0;
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C6574(u32 a, u32 b, u32 c)
{
    return func_021C6538((Mgr *)a, (void *)b, c, ((struct Obj18309 *)((u8 *)(a)))->f10);
}





/*
 * Tail call on a strided element of the array at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6580(u8 *p, int i)
{
    func_021C6940((u8 *)(((struct Obj18310 *)p)->f8 + i * 0x2c));
}





u16 func_021C6590(Mgr_021C6590 *m, u16 idx, u16 a, Vec *src)
{
    u16 i;
    Elem_021C6590 *e;
    u8 *s;

    e = m->fC;
    for (i = 0; i < m->f6; i++) {
        if (e->kind == 0 && e->f44 == 0) {
            s = m->f8 + idx * 0x2c;
            if (s[0x29] == 2) {
                e->f4 = idx;
                e->f6 = a;
                e->kind = 2;
                e->b2 = 1;
                e->f14 = 0x1000;
                e->f18 = 0x1000;
                e->f1C = 0x1000;
                if (src != 0)
                    e->f8 = *src;
                func_0207ADC4(e->f20);
            } else {
                func_021C69B4((Elem_021C69B4 *)e, (S *)s, idx, a, m->f0, (V_021C69B4 *)src, 1);
            }
            return i;
        }
        e++;
    }
    return 0;
}




void func_021C6628(Mgr_021C6628 *m, int idx)
{
    Elem_021C6628 *e;
    e = &m->fC[idx];
    m->f2 = 0;
    if (e->k == 1)
        func_021C6A90((u32 *)e, (u8 *)(&m->f8[e->f4]));
    m->f2 = 1;
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C6658(u32 a, u32 b)
{
return ((((struct Obj18311 *)((u8 *)(a)))->fC + (b * 104)) + 8);
}


void func_021C6664(Mgr_021C6664 *m, int idx, V_021C6664 *v)
{
    m->fC[idx].f8 = *v;
}


void func_021C6678(Mgr_021C6678 *m, int idx, int v)
{
    m->fC[idx].b = v;
}



/*
 * Addresses are Black-image addresses.
 */
int func_021C6694(u32 *a, int idx, int v)
{
    int r = 0;
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj12952 *)e)->f4 * 0x2c + 0x28);
        for (i = r; i < n; i++) {
            if (func_020478B8((void *)(((struct Obj12952 *)e)->f44), (u16)i, v))
                r = 1;
        }
    } else if (((K *)e)->k == 2) {
        r = 1;
    }
    return r;
}



int func_021C66EC(u32 *a, int idx, int v)
{
    int r = 0;
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj12953 *)e)->f4 * 0x2c + 0x28);
        for (i = r; i < n; i++) {
            if (func_02047910((void *)(((struct Obj12953 *)e)->f44), (u16)i, v))
                r = 1;
        }
    } else if (((K *)e)->k == 2) {
        r = 1;
    }
    return r;
}



/*
 * push {r0-r3} entry (0x021C6744); the fourth parameter's address is taken.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6744(u32 *a, int idx, int mode, u32 val)
{
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj09694 *)e)->f4 * 0x2c + 0x28);
        if (mode == 8) {
            i = 0;
            if (n > 0) {
                do {
                    func_0204784C((struct AnmCtl *)(((struct Obj09694 *)e)->f44), (u16)i, (s32 *)(&val));
                    i++;
                } while (i < n);
            }
        } else if (mode < n) {
            func_0204784C((struct AnmCtl *)(((struct Obj09694 *)e)->f44), (u16)mode, (s32 *)(&val));
        }
    }
}


int func_021C67A8(Mgr_021C67A8 *m, int idx, int i)
{
    int r = 0;
    Elem_021C67A8 *e = &m->fC[idx];
    if (e->k == 1) {
        if ((int)func_02047828((struct AnmCtl *)e->f44, (u16)i, &r) == 0)
            r = 0;
    }
    return r;
}


void func_021C67D8(Mgr_021C67D8 *m, int idx, int v)
{
    m->fC[idx].b4 = v;
}


void func_021C67F4(Mgr_021C67F4 *m, int idx)
{
    Elem_021C67F4 *e = &m->fC[idx];
    if (e->k == 1 && e->b3 == 0) {
        if (e->b2 == 1)
            func_02047AC8((void *)e->f44, (struct Arg *)(&e->f8));
        else
            func_02047A60((void *)e->f44, (struct Arg *)(&e->f8));
    }
}


void func_021C6828(Mgr_021C6828 *m, int idx, int v)
{
    m->fC[idx].b5 = v;
}



int func_021C6844(int a, int b)
{
return ((*(u32 *)((u8 *)(((struct Obj18312 *)((u8 *)(a)))->fC) + ((b * 104))) << 26) >> 31);
}


void func_021C6854(S *s)
{
    s->f29 = 0; if (s->f4 != 0) func_02046FF8((int *)s->f4); else func_02046FF8((int *)s->f0); s->f29 = 1;
}



void func_021C6874(S *s, int unused, D *d, int mode, int flag)
{
    u32 h;
    Pal *p;
    int i;

    if (d->f0 != 0)
        s->f0 = (u32)func_02046E24(d->f0, d->fC);
    if (d->f4 != 0)
        s->f4 = (u32)func_02046E24(d->f4, d->fE);
    if (flag != 0) {
        h = 0;
        if (s->f0 != 0)
            h = s->f0;
        if (s->f4 != 0)
            h = s->f4;
        if (func_02046F50((struct Tagged *)h, 2)) {
            p = (Pal *)func_0206E964((unsigned char *)((u32)func_02046F48((struct Tagged *)h)));
            func_02022040((u16 *)((u8 *)p + p->f38), (u32)(p->f30 << 3) / sizeof(u16), (const u8 *)flag);
        }
    }
    if (s->f0 != 0 || s->f4 != 0) {
        if (mode == 1)
            func_021C6854(s);
        else
            s->f29 = 2;
    }
    if (d->f20 != 0) {
        s->f28 = d->f20;
        MIi_CpuClear32(0, s->f8, sizeof(s->f8));
        for (i = 0; i < s->f28; i++)
            s->f8[i] = (u32)func_02046E24(d->f8, d->f10[i]);
    }
}



void func_021C6940(u8 *p)
{
    int i;
    u8 f = p[0x29];

    p[0x29] = 0;
    if (f == 1) {
        if (((struct Obj01866 *)p)->f4 != 0)
            func_020470D0((u32 *)(((struct Obj01866 *)p)->f4));
        else if (((struct Obj01866 *)p)->f0 != 0)
            func_020470D0((u32 *)(((struct Obj01866 *)p)->f0));
    }
    if (((struct Obj01866 *)p)->f4 != 0)
        func_02046EFC((struct Tagged *)(((struct Obj01866 *)p)->f4));
    if (((struct Obj01866 *)p)->f0 != 0)
        func_02046EFC((struct Tagged *)(((struct Obj01866 *)p)->f0));
    if (p[0x28] != 0) {
        for (i = 0; i < p[0x28]; i++)
            func_02046EFC((struct Tagged *)(*(u32 *)(p + 8 + i * 4)));
    }
    func_02082C60(p, 0, 0x2c);
    p[0x29] = 1;
}


/*
 * Unused 5th parameter puts pos/flag at sp+0x1c/0x20.  func_0204767C takes
 * the count as a third argument (the last f28 load is reused in r2).  The
 * h value starts (i = 0) before the e->f4/f6 stores, so it interferes with
 * idx in r2 and lands in r5, copied to r2 at the call.
 */
void func_021C69B4(Elem_021C69B4 *e, S *s, u16 idx, u16 id, u32 unused, V_021C69B4 *pos, int flag)
{
    int i;
    u32 m;

    i = 0;
    e->f4 = idx;
    e->f6 = id;
    if (s->f29 == 1) {
        i = s->f0;
        if (s->f4 != 0)
            i = s->f4;
    }
    m = (u32)func_02047400((void *)s->f0, id, (void *)i);
    if (s->f28 != 0) {
        MIi_CpuClear32(0, e->f48, sizeof(e->f48));
        for (i = 0; i < s->f28; i++)
            e->f48[i] = (u32)func_02047564((struct G3dOwner *)m, (const struct G3dOwner *)s->f8[i], 0);
    }
    e->f44 = (u32)func_0204767C(m, e->f48, s->f28);
    if (s->f28 != 0) {
        for (i = 0; i < s->f28; i++)
            func_020477A4((struct G3dSys *)e->f44, (u16)i);
    }
    if (pos != 0)
        e->f8 = *pos;
    if (flag != 0) {
        e->b2 = 1;
        e->f14 = 0x1000;
        e->f18 = 0x1000;
        e->f1C = 0x1000;
        func_0207ADC4(e->f20);
    }
    e->k = 1;
}



void func_021C6A90(u32 *p, u8 *q)
{
    u32 t;
    int i;

    if (p + 0x12) {
        for (i = 0; i < q[0x28]; i++)
            func_0204762C((struct Rec *)p[0x12 + i]);
    }
    if (p[0x11] != 0) {
        t = func_02047788((int *)p[0x11]);
        func_02047738((struct Rec *)p[0x11]);
        func_02047504((struct Rec *)t);
    }
    func_02082C60(p, 0, 0x68);
}



/*
 * Tail call with a zero first argument and a constant size.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6AE0(u32 a)
{
    func_02082A7C(0, a, 0x24);
}



int func_021C6AF0(u32 a, u32 b, u32 c)
{
((struct Obj06084 *)((u8 *)(a)))->f0 = b;
((struct Obj06084 *)((u8 *)(a)))->fC = c;
return a;
}



/*
 * Field setter at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6AF8(u32 *p, u32 v)
{
    ((struct Obj18313 *)p)->f8 = v;
}


void func_021C6AFC(D *d, u16 v)
{
    d->f10[d->f20] = v;
    d->f20++;
}



void func_021C6B18(u32 a, u16 b, u32 c)
{
    u32 h = func_02188C84((u8 *)a);
    u32 x = (u32)func_02188C58((void *)a);
    u32 y = func_02188D30((u8 *)a);
    u32 *e;

    e = (u32 *)func_02030734((u16)((h & 0x7FFF) | 0x8000), 0x10, 0, (const char *)&d_021DE4B8, 0x5F);
    ((struct Obj06085 *)e)->f4 = 0;
    ((struct Obj06085 *)e)->f6 = b;
    e[2] = func_0218ED54((u8 *)x);
    e[3] = c + func_0218ED54((u8 *)x);
    e[0] = a;
    func_02030DA8(y, (void *)func_021C6B8C, e, 0);
}


void func_021C6B8C(void *task, P *p)
{
    func_021C6BB4((u8 *)p);
    p->f4++;
    if (p->f6 < p->f4) {
        func_020307B0(p);
        func_02030EAC(task);
    }
}



/*
 * Lever: `t = 1.0f; t *= a / b;` keeps the fmul by 1.0f; a plain `1.0f * x`
 * or `x * 1.0f` folds away. The FX32 round (x > 0 ? x*4096+0.5 : x*4096-0.5)
 * must go through one float temp so the _ffix and the call are shared.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6BB4(u8 *p)
{
    u32 h = (u32)func_02188C58((void *)(((struct Obj03145 *)p)->f0));
    u32 n = ((struct Obj03145 *)p)->f6;
    float t, a, b, v;

    if (((struct Obj03145 *)p)->f4 <= n) {
        t = 1.0f;
        t *= (float)(u32)((struct Obj03145 *)p)->f4 / (float)n;
        t = (float)_dsqrt((double)t);
        a = (float)((struct Obj03145 *)p)->f8 / 4096.0f;
        b = (float)((struct Obj03145 *)p)->fC / 4096.0f;
        v = (1.0f - t) * a + t * b;
        if (v > 0.0f)
            v = 4096.0f * v + 0.5f;
        else
            v = 4096.0f * v - 0.5f;
        func_0218ED58((u8 *)h, (int)v);
    }
}
