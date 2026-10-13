/*
 * file:     unit_021B6100.c
 * unit:     yes
 * function: func_021B6100, func_021B6134, func_021B6148, func_021B6158, func_021B6170, func_021B6188, func_021B6194, func_021B61B4, func_021B61D4, func_021B61FC, func_021B6210, func_021B621C, func_021B6224
 * address:  0x021B6100
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B6A10  0x021B6A10  thumb  ov180
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020056A0  0x020056A0  thumb
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data a4
 *   d_021B8060 0x021B8060 data a4
 *   d_021B8090 0x021B8090 data a4
 *   d_021B80D8 0x021B80D8 data a4
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040EBC 0x02040EBC arm
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 */
#include "../../matched/include/Obj24479.h"
#include "../../matched/include/Obj24480.h"
#include "../../matched/include/Obj24481.h"

struct Obj0203159C;
struct S020315D4;
struct Node;
struct DispVram;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

struct DispConfig {u32 a,b,c,d;};

extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, u32, u32);
extern int func_021B6A10(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern int func_020056A0(void *, int *, int);
extern void func_02030EAC(struct Node *);
extern void func_0204A648(void);
extern void func_0204EA64(void);
extern void func_020419E4(void);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void func_020433E0(const struct DispVram *);
extern void func_0203F8F4(u16);
extern void func_0203F9B4(void);
extern void func_0203FC28(struct DispConfig *);
extern void func_02040EBC(u32,u32);
int func_021B6100(struct Obj0203159C *obj, void *unused, u32 value);
int func_021B6134(int a, int b, int c, int d);
int func_021B6148(void *p);
void func_021B6158(int *p);
void func_021B6170(int *p);
void func_021B6188(u8 *p);
void func_021B6194(void);
void func_021B61B4(void);
void func_021B61D4(int flag);
int func_021B61FC(int a);
void func_021B6210(void);
void func_021B621C(void);
void func_021B6224(void);
extern u32 SDK_AUTOLOAD_DTCM_START[];
extern const struct DispVram d_021B8060;
extern const struct DispVram d_021B8090;
extern const struct DispConfig d_021B80D8;

int func_021B6100(struct Obj0203159C *obj, void *unused, u32 value)
{
    u32 *p;
    func_0203064C(1, 141, 0x60000);
    p = func_0203159C(obj, 0x919C, 141);
    func_02082BCC(p, 0, 0x919C);
    *p = value;
    return 1;
}


int func_021B6134(int a, int b, int c, int d)
{
    if (func_021B6A10((char *)d))
        return 0;
    return 1;
}


int func_021B6148(void *p)
{
    func_020315D4(p);
    func_020306F0(0x8d);
    return 1;
}


void func_021B6158(int *p)
{
    ((struct Obj24479 *)p)->f4 = func_020056A0((void *)0x021B6195, p, 0);
}


void func_021B6170(int *p)
{
    ((struct Obj24480 *)p)->f4 = func_020056A0((void *)0x021B61B5, p, 0);
}

void func_021B6188(u8 *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj24481 *)p)->f4);
}

/*
 * volatile: SDK IRQ check buffer read/write at 021B61A4/021B61A8.
 */
void func_021B6194(void)
{
    func_0204A648();
    func_0204EA64();
    *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}

/*
 * volatile: SDK IRQ check buffer read/write at 021B61C4/021B61C8.
 */
void func_021B61B4(void)
{
    func_020419E4();
    func_0204A648();
    *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}

void func_021B61D4(int flag)
{
    BG_SYS_ClearGraphicsMemory(0);
    if (flag == 0)
        func_020433E0(&d_021B8060);
    else
        func_020433E0(&d_021B8090);
}

int func_021B61FC(int a)
{
    if (a == 0)
        return 0x021B8060;
    return 0x021B8090;
}

void func_021B6210(void) { func_0203F8F4(141); }

void func_021B621C(void) { func_0203F9B4(); }

void func_021B6224(void) {struct DispConfig cfg; cfg=d_021B80D8; func_0203FC28(&cfg); func_02040EBC(0,0); func_02040EBC(4,0);}
