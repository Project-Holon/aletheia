/*
 * file:     vs_multi_list_p01.c
 * unit:     yes
 * function: func_021F6560, func_021F6590, func_021F65C4, func_021F65D4, func_021F6654, func_021F6684, func_021F66B4, func_021F67C8, func_021F67F0, func_021F681C, func_021F682C, func_021F683C, func_021F68E0, func_021F68FC, func_021F6970, func_021F69C0, func_021F69E4, func_021F69FC, func_021F6A08
 * address:  0x021F6560
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   D_021F7608 0x021F7608 data a4
 *   func_0202CD94 0x0202CD94 thumb
 *   func_021F6B38 0x021F6B38 thumb ov097
 *   func_0204A600 0x0204A600 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_021F6A28  0x021F6A28  thumb  ov097
 *   func_021F6A98  0x021F6A98  thumb  ov097
 *   func_021F6F24  0x021F6F24  thumb  ov097
 *   func_021F734C  0x021F734C  thumb  ov097
 *   func_021F75E0 0x021F75E0 thumb ov097
 *   func_021F6F3C 0x021F6F3C thumb ov097
 *   func_021F6B1C 0x021F6B1C thumb ov097
 *   func_020221A4 0x020221A4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202CD64 0x0202CD64 thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021F7308 0x021F7308 thumb ov097
 *   func_0202208C 0x0202208C thumb
 *   d_021F761C 0x021F761C data a4
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   d_021F75F8     0x021F75F8  data  ov097  a4
 *   d_021F7688     0x021F7688  data  ov097  a4
 *   d_021F7668     0x021F7668  data  ov097  a4
 *   d_021F76A8     0x021F76A8  data  ov097  a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049238  0x02049238  arm
 *   func_02040EBC  0x02040EBC  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C450  0x0201C450  thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 */
#include "../../matched/include/Obj21988.h"
#include "../../matched/include/Obj10194.h"
#include "../../matched/include/Obj10193.h"
#include "../../matched/include/Obj21989.h"
#include "../../matched/include/Obj00111.h"
#include "../../matched/include/Obj21990.h"
#include "../../matched/include/Obj21991.h"
#include "../../matched/include/Obj06345.h"
#include "../../matched/include/Obj21992.h"

struct Obj0203159C;
struct WinMgr;
struct S020315D4;
struct P;
struct PrintSys;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct Node;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef short s16;

typedef int s32;

typedef struct {
    u32 w[4];
} Disp;

typedef struct {
    u32 w[8];
} Bg;

extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *,unsigned int,unsigned int);
extern void func_02082BCC(void *,int,unsigned int);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_021F6B38(char *);
extern void func_0204A600(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021F6A28(int *p);
extern void func_021F6A98(int);
extern void func_021F6F24(struct P *p);
extern void func_021F734C(struct P *p);
extern void func_021F75E0(int *);
extern void func_021F6F3C(char *p);
extern void func_021F6B1C(u8 *);
extern u32 func_020221A4(void);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern void func_020061E4(u32);
extern void func_021F7308(int a, unsigned b, int c);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020403F4(u32);
extern void func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049238(void *h);
extern void func_02040EBC(u32 a, u32 b);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_0201C450(u16 n, u32 heap);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void *func_020056A0(void (*)(void), void *, u32);
extern void func_02030EAC(struct Node *n);
extern void func_020419E4(void);
extern void func_0204A648(void);
int func_021F6560(struct Obj0203159C *a, int b, int c);
int func_021F6590(int a,int *b,int c,char *d);
int func_021F65C4(void *p);
void func_021F65D4(int a);
int func_021F6654(u8 *p);
int func_021F6684(u8 *p);
int func_021F669C(u8 *p);
int func_021F66B4(u8 *p);
int func_021F67C8(u8 *p, int value);
int func_021F67F0(u8 *p, int value);
int func_021F681C(u8 *p, int count, int result);
void func_021F682C(void);
void func_021F683C(void);
void func_021F68E0(void);
void func_021F68FC(int a0);
void func_021F6970(u8 *p);
void func_021F69C0(u8 *p);
void func_021F69E4(u8 *p);
void func_021F69FC(u8 *p);
void func_021F6A08(void);
extern u8 d_021F761C;
extern const Disp d_021F75F8;
extern const Bg d_021F7688;
extern const Bg d_021F7668;
extern const Bg d_021F76A8;
extern u32 SDK_AUTOLOAD_DTCM_START[];

int func_021F6560(struct Obj0203159C *a, int b, int c) { void *p; func_0203064C(1,0x71,0x18000); p=func_0203159C(a,0x120,0x71); func_02082BCC(p,0,0x120); ((struct Obj21988 *)p)->f0=c; return 1; }

extern int (*D_021F7608[])(char *);

int func_021F6590(int a,int *b,int c,char *d) { *b=D_021F7608[*b](d); if(*b==5) return 1; func_0202CD94(*(struct WinMgr * *)&((struct Obj10194 *)d)->f8); func_021F6B38(d); func_0204A600(); return 0; }

int func_021F65C4(void *p) { func_020315D4(p); func_020306F0(0x71); return 1; }


void func_021F65D4(int a)
{
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(1);
    func_021F6A28((int *)a);
    func_021F682C();
    func_021F683C();
    func_021F68FC(a);
    func_021F6970((u8 *)a);
    func_021F6A98(a);
    func_021F6F24((struct P *)a);
    func_021F734C((struct P *)a);
    func_0203D34C(1, 0x71);
    func_020434DC(0x17, 1);
    func_021F69E4((u8 *)a);
    func_021F67C8((u8 *)a, func_021F681C((u8 *)a, 0x80, 4));
}

int func_021F6654(u8 *p) { func_021F69FC(p); func_020434DC(0x17,0); func_021F75E0((int *)p); func_021F6F3C((char *)p); func_021F6B1C(p); func_021F69C0(p); func_021F68E0(); return 5; }

int func_021F6684(u8 *p) { if(func_020221A4()==1) return ((struct Obj21989 *)p)->f118; return 2; }

int func_021F669C(u8 *p) { if(((struct Obj10193 *)p)->f11C==0) return ((struct Obj10193 *)p)->f114; (((struct Obj10193 *)p)->f11C)--; return 3; }

/*
 * lever: byte-pointer object base keeps field addresses inline instead
 * of the integer-base spelling's extra loop-invariant address register.
 */
int func_021F66B4(u8 *p)
{
    u32 i;
    switch (((struct Obj00111 *)p)->f110) {
    case 0:
        if (func_0201C6B4(((struct Obj00111 *)p)->f1C) == 0) break;
        if (*(int *)(*(int *)&((struct Obj00111 *)p)->f0 + 8) == 0) {
            for (i = 0; i < 3; i++) {
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 3, -1, 0, 16);
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 9, -1, 0, 16);
            }
        } else {
            for (i = 0; i < 3; i++) {
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i, 1, 0, 16);
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 6, 1, 0, 16);
            }
        }
        func_020061E4(0x642);
        (((struct Obj00111 *)p)->f110)++;
    case 1:
        if (*(int *)(*(int *)&((struct Obj00111 *)p)->f0 + 8) == 0) {
            if (func_0202CE40(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, 3) == 0) {
                (((struct Obj00111 *)p)->f110)++;
                func_020061E4(0x57a);
                return func_021F681C(p, 0x80, 4);
            }
            func_021F7308((int)p, 3, -8);
        } else {
            if (func_0202CE40(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, 0) == 0) {
                (((struct Obj00111 *)p)->f110)++;
                func_020061E4(0x57a);
                return func_021F681C(p, 0x80, 4);
            }
            func_021F7308((int)p, 0, 8);
        }
        break;
    case 2:
        return func_021F67F0(p, 1);
    }
    return 4;
}

int func_021F67C8(u8 *p, int value) { func_0202208C(0,1,1,0,6,1,0x71); ((struct Obj21990 *)p)->f118=value; return 2; }

/*
 * extent: trailing two-byte zero alignment padding.
 */
int func_021F67F0(u8 *p, int value) { func_0202208C(0,0,0,0,6,1,0x71); ((struct Obj21991 *)p)->f118=value; return 2; }

int func_021F681C(u8 *p, int count, int result) { ((struct Obj00111 *)p)->f11C = count; ((struct Obj00111 *)p)->f114 = result; return 3; }

void func_021F682C(void) { func_020433E0((const struct DispVram *)(&d_021F761C)); }


void func_021F683C(void)
{
    Disp a;
    Bg b0;
    Bg b1;
    Bg b2;
    func_0203F8F4(0x71);
    a = d_021F75F8;
    func_0203FC28((struct DispConfig *)(&a));
    b0 = d_021F7688;
    func_0203FCA0(0, (const struct BgTemplate *)(&b0), 0);
    func_020414EC(0);
    func_02040B94(0, 0x20, 0, 0x71);
    b1 = d_021F7668;
    func_0203FCA0(1, (const struct BgTemplate *)(&b1), 0);
    b2 = d_021F76A8;
    func_0203FCA0(2, (const struct BgTemplate *)(&b2), 0);
}

void func_021F68E0(void) { func_020403F4(2); func_020403F4(1); func_020403F4(0); func_0203F9B4(); }


void func_021F68FC(int a0)
{
    void *h;
    h = func_020490F4(0x64, 0x8071);
    func_02049658(h, 0x12, 2, 0, 0, 1, 0x8071);
    func_020498F4(h, 0, 2, 0, 0, 1, 0x8071);
    func_02049B68(h, 0x13, 0, 0, 0, 0x8071);
    func_020498F4(h, 0x10, 1, 0, 0x800, 1, 0x8071);
    func_02049238(h);
    func_02040EBC(4, 0);
}


void func_021F6970(u8 *p)
{
    ((struct Obj00111 *)p)->f14 = func_02045B38(0, 2, 0x12, 0x71);
    ((struct Obj00111 *)p)->fC = func_0201D7EC(0x17, 0, 0, 0, 0x71);
    ((struct Obj00111 *)p)->f10 = func_0201D7EC(0x17, 3, 0, 0, 0x71);
    ((struct Obj00111 *)p)->f18 = func_0201EC64(0x71);
    ((struct Obj00111 *)p)->f1C = func_0201C450(0x800, 0x71);
}

void func_021F69C0(u8 *p) { func_02045C04(((struct Obj06345 *)p)->f14); func_0201D83C(((struct Obj06345 *)p)->fC); func_0201D83C(((struct Obj06345 *)p)->f10); func_0201ED04(((struct Obj06345 *)p)->f18); func_0201C4C0(((struct Obj06345 *)p)->f1C); }

void func_021F69E4(u8 *p) { ((struct Obj00111 *)p)->f4 = func_020056A0(func_021F6A08, p, 0); }

void func_021F69FC(u8 *p) { func_02030EAC((struct Node *)(((struct Obj21992 *)p)->f4)); }

static inline void OS_SetIrqCheckFlag(u32 intr) { *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3ff8) |= intr; }

/*
 * volatile: SDK OS_SetIrqCheckFlag read-modify-write at 021F6A18/021F6A1C, HW_INTR_CHECK_BUF.
 */
void func_021F6A08(void) { func_020419E4(); func_0204A648(); OS_SetIrqCheckFlag(1); }
