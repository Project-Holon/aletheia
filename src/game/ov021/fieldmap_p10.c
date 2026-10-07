/*
 * file:     fieldmap_p10.c
 * unit:     yes
 * function: func_02188E50, func_02188EE4, func_02189004, func_02189084, func_021890AC, func_021890C8, func_02189108, func_02189140, func_02189154, func_021891C0, func_02189204, func_021892B4, func_021892CC, func_0218932C, func_02189370, func_021893C0, func_021894E0, func_02189518, func_02189560, func_0218958C, func_021895BC, func_021895D0, func_021895DC, func_021895E8, func_02189614, func_02189684, func_021896F4, func_02189734, func_02189758, func_02189764
 * address:  0x02188E50
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
 *   func_0207DC44  0x0207DC44  arm
 *   func_0207DD10  0x0207DD10  arm
 *   func_0207DD24  0x0207DD24  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   func_02046BE0  0x02046BE0  arm
 *   data_021D3640  0x021D3640  data  a4
 *   data_021D35E4  0x021D35E4  data  a4
 *   func_0204FE94  0x0204FE94  arm
 *   func_02050080  0x02050080  arm
 *   func_0204EDBC  0x0204EDBC  arm
 *   func_0204EDC4  0x0204EDC4  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   func_021C63AC  0x021C63AC  thumb  ov021
 *   func_02048A24  0x02048A24  arm
 *   func_02048BC4  0x02048BC4  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048C58  0x02048C58  arm
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   d_021D36F4     0x021D36F4  data  a4
 *   d_021D36E8     0x021D36E8  data  a4
 *   d_021D35C0     0x021D35C0  data  a4
 *   d_021D35CC     0x021D35CC  data  a4
 *   d_021D35AC     0x021D35AC  data  a4
 *   func_020504D8  0x020504D8  arm
 *   func_021BB36C  0x021BB36C  thumb
 *   func_021AB660  0x021AB660  thumb
 *   func_021A030C  0x021A030C  thumb
 *   func_021A1AF4  0x021A1AF4  thumb
 *   func_021A0140  0x021A0140  thumb
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_021A0458  0x021A0458  thumb
 *   func_0218CB34  0x0218CB34  thumb
 *   func_0203D12C  0x0203D12C  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   d_021D35D8     0x021D35D8  data  a4
 *   func_02047970  0x02047970  arm
 *   d_021D35B4     0x021D35B4  data  a4
 *   func_02048C4C  0x02048C4C  arm
 *   func_02048AC4  0x02048AC4  arm
 *   func_0204FFFC  0x0204FFFC  arm
 *   func_021C6400  0x021C6400  thumb  ov021
 *   func_02005C8C  0x02005C8C  thumb
 *   func_0216CD78  0x0216CD78  thumb  ov010
 *   func_021C6470  0x021C6470  thumb  ov021
 *   func_0204A648  0x0204A648  arm
 *   func_021D31AC  0x021D31AC  thumb  ov021
 *   func_02061CA4  0x02061CA4  arm
 *   func_020140E0  0x020140E0  thumb
 *   func_02013DB8  0x02013DB8  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   data_021EE700  0x021EE700  data  a4
 *   data_021EE700b  0x021EE700  data
 *   func_020140E4  0x020140E4  thumb
 *   func_021CD1C8  0x021CD1C8  thumb
 *   func_021CD204  0x021CD204  thumb
 *   func_021CD214  0x021CD214  thumb
 *   func_021CD1F0  0x021CD1F0  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216CCDC  0x0216CCDC  thumb  ov010
 *   func_0219C554  0x0219C554  thumb
 *   func_0219C680  0x0219C680  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0217C0A8  0x0217C0A8  thumb  ov018
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021A31A4  0x021A31A4  thumb
 *   func_0219C658  0x0219C658  thumb
 *   func_0219D448  0x0219D448  thumb
 *   func_0218ED50  0x0218ED50  thumb
 *   func_0216CDB8  0x0216CDB8  thumb  ov010
 *   func_0216D2F8  0x0216D2F8  thumb  ov010
 *   func_02189AE8  0x02189AE8  thumb
 *   func_0216D974  0x0216D974  thumb  ov010
 *   func_0216D2AC  0x0216D2AC  thumb  ov010
 *   func_0216CD50  0x0216CD50  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_02162458  0x02162458  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02162438  0x02162438  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_020141E0  0x020141E0  thumb
 *   func_020141F0  0x020141F0  thumb
 *   func_02012974  0x02012974  thumb
 *   func_02159C48  0x02159C48  thumb  ov010
 *   func_02159BD4  0x02159BD4  thumb  ov010
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_0216DF1C  0x0216DF1C  thumb  ov010
 *   func_021623DC  0x021623DC  thumb  ov010
 *   func_0216242C  0x0216242C  thumb  ov010
 *   func_021643AC  0x021643AC  thumb  ov010
 *   func_020120D8  0x020120D8  thumb
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_0202735C  0x0202735C  thumb
 *   func_0215A014  0x0215A014  thumb  ov010
 *   func_02158AE0  0x02158AE0  thumb  ov010
 *   func_0215874C  0x0215874C  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 *   func_02012134  0x02012134  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_0202B544  0x0202B544  thumb
 *   func_02029CF0  0x02029CF0  thumb
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_0202C83C  0x0202C83C  thumb
 *   func_02012994  0x02012994  thumb
 *   func_021A1BDC  0x021A1BDC  thumb  ov021
 *   func_02188C68  0x02188C68  thumb  ov021
 *   func_021A0358  0x021A0358  thumb  ov021
 *   func_02013EEC  0x02013EEC  thumb
 *   func_02013F2C  0x02013F2C  thumb
 *   func_021A0338  0x021A0338  thumb  ov021
 *   func_02012AC4  0x02012AC4  thumb
 *   func_02013BD0  0x02013BD0  thumb
 *   func_0218F14C  0x0218F14C  thumb  ov021
 *   func_0218F134  0x0218F134  thumb  ov021
 *   func_02012B38  0x02012B38  thumb
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_0218DC74  0x0218DC74  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_021939C0  0x021939C0  thumb  ov021
 *   func_02193ABC  0x02193ABC  thumb  ov021
 *   func_02193AFC  0x02193AFC  thumb  ov021
 *   func_02013FA8  0x02013FA8  thumb
 *   func_02013C80  0x02013C80  thumb
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 *   func_02026454  0x02026454  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DD9C0     0x021DD9C0  data  a4
 */
#include "../../matched/include/Obj01344.h"
#include "../../matched/include/Obj02367.h"
#include "../../matched/include/Obj19495.h"
#include "../../matched/include/Obj04980.h"
#include "../../matched/include/Obj09442.h"
#include "../../matched/include/Obj00571.h"
#include "../../matched/include/Obj09172.h"
#include "../../matched/include/Obj09443.h"
#include "../../matched/include/Obj19496.h"
#include "../../matched/include/Obj05698.h"
#include "../../matched/include/Obj19497.h"
#include "../../matched/include/Obj03104.h"
#include "../../matched/include/Obj12557.h"
#include "../../matched/include/Obj19498.h"
#include "../../matched/include/Obj09444.h"
#include "../../matched/include/Obj03105.h"

struct Light;
struct LightSet;
struct LightSlot;
struct Blk3;
struct Obj;
struct Owner;
struct BbActSys;
struct Sub020140BCObj;
struct BigObj;
struct Ctx;
struct Sub0200852CObj;
struct SaveBlock;
struct Rec020141E0;
struct Rec020141F0;
struct Rec44;
struct Vec020141E0;
struct Vec020141F0;
struct Vec12;
struct Sub02014444Obj;
struct Comm;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct {
    u32 w[3];
} Vec12;

typedef void (*Fn_02189084)(unsigned char *p);

typedef int (*Fn_021890AC)(unsigned char *p);

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct Vec_0218932C { int x, y, z; } Vec_0218932C;

typedef struct Vec_02189370 { int x, y, z; } Vec_02189370;

typedef struct {
    int x, y, z;
} Vec_021893C0;

typedef struct {
    int id;
    void *buf;
} Slot;

extern void func_0207DC44(int enable, int fogMode, int fogSlope, int fogOffset);
extern void func_0207DD10(void *a);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_0207DCF8(void *a);
extern void func_02046BE0(u32 a, u32 b);
extern void *func_0204FE94(u16 a0, u16 a1, u32 a2, int heap);
extern u32 func_02050080(u32 *p);
extern void func_0204EDBC(u8 *dst, u8 val);
extern void func_0204EDC4(u8 *dst, int a, int b);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern u32 func_021C63AC(u16 heap, int a, int b);
extern u32 func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048AD0(struct Light *l);
extern void func_02048C58(struct LightSlot *slots);
extern void func_020504D8(struct Owner *o);
extern void func_021BB36C(u32 a);
extern int func_021AB660(struct Obj *o, void *arg);
extern void func_021A030C(u8 *p, u32 a);
extern void func_021A1AF4(u8 *p, int x);
extern void func_021A0140(u8 *p);
extern u32 func_0203F4FC(void);
extern void func_021A0458(u8 *a, s32 b);
extern int func_0218CB34(char *p);
extern void func_0203D12C(int a);
void func_02047964(void);
void func_020479D8(void);
void func_02047970(int x);
extern u32 func_02048AC4(void *ptr);
extern u32 func_02048C4C(u32, u32, u32, u32);
extern void func_0204FFFC(struct BbActSys *o);
extern u32 func_021C6400(u32);
int func_02005C8C(void);
int func_0216CD78(int a0);
void func_021C6470(int h);
void func_0204A648(void);
void func_021D31AC(int h);
s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u8 func_020140E0(struct Sub020140BCObj *p);
extern u32 func_02013DB8(u32 a);
extern void func_02048F4C(void *a, u32 b, u32 c);
extern u8 func_020140E4(struct Sub020140BCObj *p);
extern u32 func_021CD1C8(u32 a);
extern void func_021CD204(u32 a, u32 b);
extern void func_021CD214(u8 *s, void *o);
extern int func_021CD1F0(void *a);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012964(const struct BigObj *p);
extern void func_0216CCDC(char *a, int b, int c, int d, int e, int f);
extern void func_0219C554(u32 a, u32 b, u32 c);
extern void func_0219C680(u32 a);
extern u32 func_02013CC8(u32 a);
extern u32 func_02013CE0(u32 a);
extern u32 func_02012138(const struct Ctx *p);
extern u8 func_0217C0A8(void *a0);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *p);
extern int func_021A31A4(int i, int v);
extern void func_0219C658(u32 a, u32 b);
extern void func_0219D448(int a, int b);
extern u8 *func_0218ED50(u8 *p);
extern void func_0216CDB8(u8 *p, u32 v);
extern void func_0216D2F8(u32 a);
extern int func_02189AE8(int a);
extern void func_0216D974(unsigned int *p, unsigned int v);
extern int func_0216CD50(int a0);
extern void func_0216D2AC(u32 x);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02162458(u8 *p);
extern u8 func_02012984(const struct BigObj *p);
extern void func_02162438(int a0, int a1, int a2);
extern void *func_020127A4(struct SaveBlock *p);
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern void func_020141E0(const struct Rec020141E0 *p, struct Vec020141E0 *out);
extern void func_020141F0(struct Rec020141F0 *p, const struct Vec020141F0 *v);
extern u32 func_02012974(const struct BigObj *p);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);
extern void func_021AA8EC(u8 *p);
extern void func_0216DF1C(u32 a);
extern void func_021623DC(char *p);
extern void func_0216242C(void *a0, u16 a1, u8 a2);
extern void func_021643AC(void *a, void *b);
extern int func_020120D8(char *p);
extern void func_021BC550(void *p, int v);
extern void func_0202735C(u32 a0, u32 a1);
extern void func_0215A014(void *a, int b);
extern void func_02158AE0(void *a0, void *a1);
extern void func_0215874C(void *a);
u16 func_02162744(u8 *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_02162740(u8 *p);
void func_0216CEAC(u32 a, u8 *p, u32 b, u32 n, u32 c);
extern u32 func_02012134(u32 *p);
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void func_0202B544(u32 a, u16 b);
extern void func_02029CF0(void *a, void *b, u16 c);
u32 func_02188C6C(u8 *p);
int func_0202C83C(int a0, int a1);
u8 func_02012994(const struct BigObj *p);
void func_021A1BDC(int x, int k);
u32 func_02188C68(u8 *p);
void func_021A0358(int a);
u32 func_02013EEC(u32 id);
int func_02013F2C(unsigned short id);
void func_021A0338(u8 *p, u32 id, u32 c, u8 d);
extern struct Rec44 *func_02012AC4(struct Rec44 *p, u16 v);
unsigned short func_02013BD0(unsigned short id);
void func_0218F14C(u8 *p, u32 a, u32 b);
void func_0218F134(u8 *a);
extern void *func_02012B38(const struct BigObj *p);
extern int func_02013DD0(int v);
extern u32 func_0201444C(struct Sub02014444Obj *o);
extern u8 *func_020127C4(void *p);
extern u8 *func_020127D0(u8 *o, u32 idx);
extern int func_0218DC74(u32 a, u32 b, u32 c);
extern void *func_0218DC70(u8 *p);
extern void func_021939C0(u8 *o, void *dst, int skip, u32 heap);
extern void func_02193ABC(char *p, int a, int b);
extern void func_02193AFC(u8 *p, u32 v);
extern int func_02013FA8(u16 id);
extern int func_02013C80(int a0);
extern void func_021AB650(void *p);
extern void func_021AB868(void *p);
extern void func_021AB840(void *p, int a, int b, int c);
extern u32 func_021AB880(u8 *p);
extern u32 func_021AB884(u8 *p);
extern int func_021AB888(void *p);
extern void func_021AB634(void *p, int a, int b, int c);
extern u32 func_02026454(void *obj);
extern u32 func_0200FB24(void);
extern u32 func_0202647C(void *obj);
extern void func_02026400(struct Comm *p);
extern u32 func_02026460(void *obj);
void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
void func_02188E50(void);
void func_02188EE4(u8 *p);
void func_02189004(u8 *a);
void func_02189084(unsigned char *p);
void func_021890AC(unsigned char *p);
int func_021890C8(u32 a, u32 b, u32 c, u32 d);
void func_02189108(int unused, unsigned char *p);
/* Callback: forwards its last three arguments, with the first folded to 0/1. */ void func_02189140(int x, int b, void *c, int d);
void func_02189154(void *a, u32 b);
void func_021891C0(u8 *a);
void func_02189204(u8 *a);
int func_021892B4(u8 *a);
u32 func_021892CC(u8 *a);
int func_0218932C(char *p);
u32 func_02189370(char *p);
void func_021893C0(u8 *p);
void func_021894E0(int a, int b, int c, int d);
void func_02189518(char *p, unsigned int idx);
void func_02189560(int *p, int b);
void func_0218958C(unsigned char *p, int id);
int func_021895BC(void *a, u32 b);
void func_021895D0(u8 *p, u32 a);
int func_021895DC(u32 a);
void func_021895E8(unsigned char *p, int id, int c);
void func_02189614(void *p, char *q, u16 id);
void func_02189684(char *p, unsigned int id);
int func_021896F4(void *p);
int func_02189734(u32 a, u32 b, u32 c, u32 d);
void func_02189758(int *p);
void *func_02189764(unsigned char *p, int id, int a, int b);
extern u8 data_021D3640[];
extern u8 data_021D35E4[];
extern const s16 d_020A1EB8[];
extern const Vec12 d_021D36F4;
extern const Vec12 d_021D36E8;
extern Vec12 d_021D35C0;
extern Vec12 d_021D35CC;
extern u8 d_021D35AC[];
extern Fn_02189084 d_021D35D8[];
extern Fn_021890AC d_021D35B4[];
extern u8 data_021EE700[];
extern u16 data_021EE700b[];
extern unsigned char d_021DD9C0[];


/*
 * Addresses are Black-image addresses.
 */
void func_02188E50(void)
{
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xFFFFCFFD;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x10;
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFFB;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 8;
    func_0207DC44(0, 0, 5, 0xE00);
    *(volatile u32 *)0x04000358 = 0x7FFF;
    func_0207DD10(data_021D3640);
    func_0207DD24(0, 0x1F, 0x7FFF, 0, 0);
    func_0207DCF8(data_021D35E4);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u32 *)0x04000580 = 0xBFFF0000;
    func_02046BE0(1, 0);
}


void func_02188EE4(u8 *p)
{
    Vec12 v30;
    Vec12 v24;
    u8 v20;
    u8 *h;
    u16 heap;

    ((struct Obj01344 *)p)->fB0 = (u32)func_0204FE94(0x40, 0x80, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    h = (u8 *)func_02050080((u32 *)(((struct Obj01344 *)p)->fB0));
    func_0204EDBC(h, 2);
    func_0204EDC4(h, 0, -0xA00);
    ((struct Obj01344 *)p)->fB4 = (u32)func_0204FE94(0x3A, 0x50, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    ((struct Obj01344 *)p)->fB8 = (u32)func_0204FE94(0x1E, 0x28, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    h = (u8 *)func_02050080((u32 *)(((struct Obj01344 *)p)->fB8));
    v30 = d_021D36F4;
    func_0204ED70(h, (struct Blk3 *)(&v30));
    v20 = 0;
    func_0204EDB0(h, &v20);
    func_021891C0(p);
    ((struct Obj01344 *)p)->f130 = func_021C63AC(((struct Obj01344 *)p)->f0, 0x40, 0x40);
    heap = ((struct Obj01344 *)p)->f0;
    v24 = d_021D36E8;
    ((struct Obj01344 *)p)->fA4 = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                                       &d_021D35C0, &v24, &d_021D35CC, heap);
    ((struct Obj01344 *)p)->fA8 = (u32)func_02048BC4((const struct LightSet *)d_021D35AC, ((struct Obj01344 *)p)->f0);
    func_02048AD0((struct Light *)(((struct Obj01344 *)p)->fA4));
    func_02048C58((struct LightSlot *)(((struct Obj01344 *)p)->fA8));
}


void func_02189004(u8 *a)
{
    u32 t;

    func_020504D8((struct Owner *)(((struct Obj02367 *)a)->fB0));
    func_020504D8((struct Owner *)(((struct Obj02367 *)a)->fB4));
    func_020504D8((struct Owner *)(((struct Obj02367 *)a)->fB8));
    func_021BB36C(((struct Obj02367 *)a)->f3C);
    func_021AB660((struct Obj *)(((struct Obj02367 *)a)->f40), a + 0xF4);
    func_021A030C((u8 *)(((struct Obj02367 *)a)->f1C), ((struct Obj02367 *)a)->f0);
    func_021A1AF4((u8 *)(((struct Obj02367 *)a)->f20), 0x92);
    func_021A0140((u8 *)(((struct Obj02367 *)a)->f18));
    func_021A0458((u8 *)(((struct Obj02367 *)a)->f14), func_0203F4FC());
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    t = func_0218CB34((char *)(((struct Obj02367 *)a)->f48));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    if (t != 0)
        func_0203D12C(2);
}


void func_02189084(unsigned char *p)
{
    Fn_02189084 fn;
    func_02047964();
    func_020479D8();
    fn = d_021D35D8[((struct Obj19495 *)p)->f12C];
    if (fn != 0)
        fn(p);
}


void func_021890AC(unsigned char *p)
{
    func_02047970(d_021D35B4[*(int *)(p + 0x12C)](p));
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021890C8(u32 a, u32 b, u32 c, u32 d)
{
func_02048C4C(*(u32 *)((u8 *)((a + 168))), b, c, d);
func_02048AC4((void *)(*(u32 *)((u8 *)((a + 164)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 176)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 180)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 184)))));
return func_021C6400(*(u32 *)((u8 *)(a) + ((19 << 4))));
}


void func_02189108(int unused, unsigned char *p)
{
    if (func_02005C8C() == 0) {
        if (((struct Obj04980 *)p)->f38 != 0)
            func_0216CD78(((struct Obj04980 *)p)->f38);
        if (((struct Obj04980 *)p)->f130 != 0)
            func_021C6470(((struct Obj04980 *)p)->f130);
    }
    func_0204A648();
    if (((struct Obj04980 *)p)->f14C != 0)
        func_021D31AC(((struct Obj04980 *)p)->f14C);
}


/* Callback: forwards its last three arguments, with the first folded to 0/1. */
void func_02189140(int x, int b, void *c, int d)
{
    func_02061CA4((void *)(x == 0 ? B_FALSE : B_TRUE), b, (u32)c, d);
}


void func_02189154(void *a, u32 b)
{
    u32 r = func_020140E0(a);

    if (r == 0xFF) {
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
        return;
    }
    if (func_02013DB8(b) != 0)
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    else
        *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x20;
    func_02048F4C(data_021EE700, 0xF, r);
    data_021EE700b[7] = 0x4210;
    func_0207DCF8(data_021EE700);
}


void func_021891C0(u8 *a)
{
    u16 v = (((struct Obj09442 *)a)->f0 & 0x7FFF) | 0x8000;
    u32 h;
    u32 t;

    t = func_020140E4((struct Sub020140BCObj *)(((struct Obj09442 *)a)->fC));
    h = func_021CD1C8(v);
    func_021CD204(h, t);
    func_021CD214((u8 *)h, (void *)func_02050080((u32 *)(((struct Obj09442 *)a)->fB0)));
    func_021CD1F0((void *)h);
}


void func_02189204(u8 *a)
{
    u32 h;
    u32 x;
    u32 r;
    u32 t;

    h = (u32)func_020120F4((const struct Ctx *)(((struct Obj00571 *)a)->f4));
    r = func_02012964((const struct BigObj *)h);
    ((struct Obj00571 *)a)->f38 = r;
    func_0216CCDC((char *)r, ((struct Obj00571 *)a)->f0, h, (int)a, *(u32 *)&((struct Obj00571 *)a)->f48, ((struct Obj00571 *)a)->f3C);
    func_0219C554(((struct Obj00571 *)a)->f38, ((struct Obj00571 *)a)->fB0, 0x20);
    func_0219C680(((struct Obj00571 *)a)->f38);
    x = ((struct Obj00571 *)a)->fD8;
    if (func_02013CC8(x) == 0 && func_02013CE0(x) == 0) {
        t = func_0217C0A8((void *)((void *)func_02012138((const struct Ctx *)((struct Obj00571 *)a)->f4)));
    } else {
        t = func_02008550((const struct Sub0200852CObj *)func_02012944((void *)h));
    }
    func_0219C658(r, func_021A31A4(t, 0));
    func_0219D448(((struct Obj00571 *)a)->f38, ((struct Obj00571 *)a)->f130);
    func_0216CDB8((u8 *)(((struct Obj00571 *)a)->f38), (u32)func_0218ED50((u8 *)(((struct Obj00571 *)a)->f10)));
    func_0216D2F8(((struct Obj00571 *)a)->f38);
    func_0216D974((unsigned int *)r, func_02189AE8(((struct Obj00571 *)a)->fD0));
}


int func_021892B4(u8 *a)
{
func_0216D2AC(((struct Obj09172 *)((u8 *)(a)))->f38);
func_0216CD50(((struct Obj09172 *)((u8 *)(a)))->f38);
((struct Obj09172 *)((u8 *)(a)))->f38 = 0;
return 0;
}


u32 func_021892CC(u8 *a)
{
    u32 h;

    if (func_0218932C((char *)a) == 1 && func_02189370((char *)a) == 1) {
        func_021893C0(a);
        return 1;
    }
    h = func_02012844((const struct BigObj *)(((struct Obj09443 *)a)->f8));
    if (func_02162458((u8 *)h) == 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        func_02162438(h, ((struct Obj09443 *)a)->fD8, func_02012984((const struct BigObj *)(((struct Obj09443 *)a)->f8)));
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    return 0;
}


int func_0218932C(char *p)
{
    Vec_0218932C v;
    char *q;
    Vec_0218932C *pos;

    q = p + 0xd4;
    pos = (Vec_0218932C *)func_02012AA0(func_020127A4(func_020120F4(((struct Obj19496 *)p)->f4)));
    func_020141E0((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&v));
    if (pos->x != v.x || pos->z != v.z) {
        func_020141F0((struct Rec020141F0 *)q, (const struct Vec020141F0 *)pos);
        return 1;
    }
    return 0;
}


u32 func_02189370(char *p)
{
    Vec_02189370 v;
    char *q;
    void *m;
    int r;

    q = p + 0xd4;
    m = (void *)func_02012974(((struct Obj19497 *)p)->f8);
    func_020141E0((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&v));
    if (func_02159C48((int)m, v.x, v.z) == 1) {
        r = func_02159BD4((int)m, v.x, v.z);
        if (r != 0xFFFF && r != ((struct Obj05698 *)q)->f4)
            return 1;
    }
    return 0;
}


void func_021893C0(u8 *p)
{
    u8 *q = p + 0xD4;
    void *sys;
    u32 v;
    Vec_021893C0 pos;
    u32 s4;
    u32 s0;

    sys = func_020120F4((const struct Ctx *)(((struct Obj03104 *)p)->f4));
    s4 = func_02012844(sys);
    s0 = ((struct Obj03104 *)p)->f38;
    v = func_02012974((const struct BigObj *)(((struct Obj03104 *)p)->f8));
    func_0203D12C(2);
    func_021AA8EC((u8 *)(((struct Obj03104 *)p)->f90));
    func_020141E0((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&pos));
    v = func_02159BD4(v, pos.x, pos.z);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0216DF1C(s0);
    func_021623DC((char *)s4);
    func_0216242C((void *)s4, v, func_02012984(sys));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021643AC(sys, p);
    func_02189518((char *)p, v);
    func_0218958C(p, v);
    func_02189560((int *)p, (u32)v);
    func_021895D0(p, v);
    func_021895BC(sys, v);
    func_02189684((char *)p, v);
    if (((struct Obj03104 *)p)->f30 != 0 && func_020120D8((char *)((struct Obj03104 *)p)->f4) == 0)
        func_021BC550((void *)(((struct Obj03104 *)p)->f30), v);
    ((struct Obj05698 *)q)->f4 = v;
    func_0202735C((u16)v, (u32)sys);
    func_0215A014(sys, v);
    func_02158AE0((void *)(((struct Obj03104 *)p)->f4), (void *)4);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021894E0((int)sys, s0, s4, v);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_0215874C((void *)func_02012138((const struct Ctx *)((struct Obj03104 *)p)->f4));
}


void func_021894E0(int a, int b, int c, int d)
{
    int r = func_02162744((u8 *)c);
    int y;
    if (r != 0) {
        y = func_0201296C((const struct BigObj *)a);
        func_0216CEAC(b, (u8 *)func_02162740((u8 *)c), d, r, y);
    }
}


void func_02189518(char *p, unsigned int idx)
{
    void *a;
    void *b;
    void *c;
    int k;

    a = func_020120F4(((struct Obj12557 *)p)->f4);
    b = (void *)func_02012134(((struct Obj12557 *)p)->f4);
    c = (void *)func_02012A30(a);
    k = func_02012B28(func_020127A4(a));
    func_0202B544((u32)b, idx);
    if (k != 2)
        func_02029CF0(c, a, idx);
}


void func_02189560(int *p, int b)
{
    int r = (int)func_02188C6C((u8 *)p);
    unsigned short k;
    func_0202C83C(p[1], b);
    k = (int)func_02012994((const struct BigObj *)p[2]);
    if (k != 0xF)
        func_021A1BDC(r, k);
}


void func_0218958C(unsigned char *p, int id)
{
    int a;
    func_021A0358(func_02188C68(p));
    a = (int)func_02013EEC((unsigned short)id);
    func_021A0338((u8 *)(((struct Obj19498 *)p)->f1C), a, func_02013F2C(id), 1);
}


int func_021895BC(void *a, u32 b)
{
return (int)func_02012AC4((struct Rec44 *)func_020127A4((struct SaveBlock *)a), ((b << 16) >> 16));
}


/*
 * Tail call passing the object, a pass-through argument and the leading u16.
 *
 * Addresses are Black-image addresses.
 */
void func_021895D0(u8 *p, u32 a)
{
    func_021895E8(p, a, ((struct Obj09444 *)p)->f0);
}


int func_021895DC(u32 a)
{
*(u32 *)((u8 *)(a) + ((67 << 2))) = 0;
return a;
}


void func_021895E8(unsigned char *p, int id, int c)
{
    int r = func_02013BD0(id);
    if (r != 0xFFFF)
        func_0218F14C((u8 *)(((struct Obj09444 *)p)->f10), r, c);
    else
        func_0218F134((u8 *)(((struct Obj09444 *)p)->f10));
}


void func_02189614(void *p, char *q, u16 id)
{
    void *t;
    int k;
    void *m;
    void *a;

    t = func_02012B38(p);
    if (func_02013DD0(((struct Obj00571 *)q)->fD0) != 0) {
        k = func_0201444C(t);
        if (k == 0)
            m = func_020127C4(((struct Obj00571 *)q)->f8);
        else
            m = func_020127D0(((struct Obj00571 *)q)->f8, 0);
        func_0218DC74((u32)(((struct Obj00571 *)q)->f48), (u32)m, k);
        a = func_0218DC70(((struct Obj00571 *)q)->f48);
        func_021939C0(a, (void *)func_02012844(p), k, ((struct Obj00571 *)q)->f0);
        func_02193ABC(a, *(int *)&((struct Obj00571 *)q)->f10, ((struct Obj00571 *)q)->f0);
        func_02193AFC(a, func_02012964(((struct Obj00571 *)q)->f8));
    }
}


void func_02189684(char *p, unsigned int id)
{
    int k;
    int a;
    int b;

    k = func_02013FA8(id);
    if (k != 0xFFFF) {
        func_021AB650(((struct Obj03105 *)p)->f40);
        func_021AB868(((struct Obj03105 *)p)->f44);
        func_021AB840(((struct Obj03105 *)p)->f44, 1, k, 0x96);
        a = func_021AB880(((struct Obj03105 *)p)->f44);
        b = func_021AB884(((struct Obj03105 *)p)->f44);
        func_021AB634(((struct Obj03105 *)p)->f40, a, b, func_021AB888(((struct Obj03105 *)p)->f44));
        return;
    }
    if (func_02013C80((u16)id) == 0) {
        func_021AB650(((struct Obj03105 *)p)->f40);
        func_021AB868(((struct Obj03105 *)p)->f44);
    }
}


int func_021896F4(void *p)
{
    int r = func_02026454(p);

    switch (r) {
    case 0:
        if (func_0200FB24() != 0)
            r = func_0202647C(p);
        return r;
    case 1:
    case 2:
    case 5:
        return r;
    }
    return 2;
}


int func_02189734(u32 a, u32 b, u32 c, u32 d)
{
if (func_02026454((void *)a) == 0) {
    return 1;
}
if (func_02026460((void *)a) == 0) {
    func_02026400((struct Comm *)a);
}
return 0;
}


void func_02189758(int *p)
{
    p[0] = -1;
    p[1] = 0;
}


void *func_02189764(unsigned char *p, int id, int a, int b)
{
    Slot *s = (Slot *)(p + 0x118);
    if (id == -1)
        return 0;
    if (s->id != -1)
        return 0;
    s->id = id;
    return s->buf = func_02030734(a, b, 1, (const char *)d_021DD9C0, 0xD7C);
}
