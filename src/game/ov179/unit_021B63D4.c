/*
 * file:     unit_021B63D4.c
 * unit:     yes
 * function: func_021B63D4, func_021B6448, func_021B6490, func_021B64AC, func_021B64B0, func_021B64E0, func_021B669C, func_021B66DC, func_021B6710, func_021B6730, func_021B6744, func_021B6758, func_021B676C, func_021B6780, func_021B6794, func_021B67DC, func_021B67F4, func_021B680C, func_021B6830, func_021B6854, func_021B6878, func_021B687C, func_021B6888, func_021B6894, func_021B6898, func_021B689C, func_021B68A0
 * address:  0x021B63D4
 * region:   ov179
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02043534 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   func_021B615C 0x021B615C thumb ov179
 *   func_021B616C 0x021B616C thumb ov179
 *   func_020490F4 0x020490F4 arm
 *   func_021B622C 0x021B622C thumb ov179
 *   func_021B624C 0x021B624C thumb ov179
 *   func_021B6290 0x021B6290 thumb ov179
 *   d_021B6A1C 0x021B6A1C data a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_021B6268 0x021B6268 thumb ov179
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021B6248 0x021B6248 thumb ov179
 *   func_021B6220 0x021B6220 thumb ov179
 *   func_020870D0  0x020870D0  arm
 *   func_0204047C  0x0204047C  arm
 *   data_021B6A1C  0x021B6A1C  data  ov179
 *   _ull_mul       0x0209C054  arm
 *   _ll_udiv       0x0209C00C  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207EB78  0x0207EB78  arm
 *   func_0207ECF0  0x0207ECF0  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021B6A40 0x021B6A40 data a4
 *   d_021B6A90 0x021B6A90 data a4
 *   func_021B62B8  0x021B62B8  thumb  ov179
 *   func_021B62E0  0x021B62E0  thumb  ov179
 *   func_021B630C  0x021B630C  thumb  ov179
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_021B6338 0x021B6338 thumb ov179
 *   func_02040588  0x02040588  arm
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb  arm9
 */
#include "../../matched/include/Obj14386.h"
#include "../../matched/include/Obj14387.h"
#include "../../matched/include/Obj24472.h"
#include "../../matched/include/Obj14388.h"
#include "../../matched/include/Obj00546.h"
#include "../../matched/include/Obj08293.h"
#include "../../matched/include/Obj10717.h"
#include "../../matched/include/Obj14389.h"
#include "../../matched/include/Obj14390.h"
#include "../../matched/include/Obj14391.h"
#include "../../matched/include/Obj14392.h"
#include "../../matched/include/Obj14393.h"
#include "../../matched/include/Obj14394.h"
#include "../../matched/include/Obj14395.h"
#include "../../matched/include/Obj14396.h"
#include "../../matched/include/Obj08294.h"
#include "../../matched/include/Obj08295.h"
#include "../../matched/include/Obj08296.h"
#include "../../matched/include/Obj03875.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {unsigned short value;char pad[10];} Entry_021B63D4;

typedef unsigned char u8;

typedef unsigned long long u64;

typedef struct {
    u16 unk0;
    u16 count;
    int a;
    int b;
} Entry_021B64E0;

extern void func_02043534(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void func_021B615C(void);
extern void func_021B616C(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021B622C(char *);
extern void func_021B624C(int *);
extern void func_021B6290(char *,unsigned,unsigned,unsigned);
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021B6268(char *);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_021B6248(char *);
extern void func_021B6220(void);
extern u64 func_020870D0(void);
extern void func_0204047C(int idx, unsigned short val);
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_020862F0(int, int);
extern void func_0207EB78(int, int, int);
extern void func_0207ECF0(int, int, int);
extern u32 func_020307B0(void *p);
extern void func_021B62B8(char *p, u32 a, u32 b, u32 c);
extern void func_021B62E0(char *p, u32 a, u32 b, u32 c);
extern void func_021B630C(char *p, u32 a, u32 b, u32 c);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_021B6338(void *,int,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GFL_USE_PlayFanfare(void *arg);
int func_021B63D4(char *p);
int func_021B6448(char *p);
u32 func_021B6490(char *p);
int func_021B64AC(void);
u32 func_021B64B0(char *p);
int func_021B64E0(char *p);
void func_021B669C(int a, int b, int c, int d, int e);
int func_021B66DC(char *p);
int func_021B6710(char *p,int *q);
int func_021B6730(int a, int *q);
int func_021B6744(int a, int *q);
int func_021B6758(int a, int *q);
int func_021B676C(int a, int *q);
int func_021B6780(char *p);
int func_021B6794(char *p,const int *q);
int func_021B67DC(int a, int *q);
int func_021B67F4(int a, int *q);
int func_021B680C(char *p, int *q);
int func_021B6830(char *p, int *q);
int func_021B6854(char *p);
int func_021B6878(void);
int func_021B687C(void);
int func_021B6888(void *ctx, unsigned int *rec);
int func_021B6894(void);
int func_021B6898(void);
int func_021B689C(void);
int func_021B68A0(char *p);
extern const Entry_021B63D4 d_021B6A1C[];
extern const Entry_021B64E0 data_021B6A1C[];
extern const unsigned d_021B6A90[];

int func_021B63D4(char *p)
{
 func_02043534(0);BG_SYS_SetSubVisiblePlanes(0);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 BG_SYS_SetLcdSwap(1);func_021B615C();func_021B616C(p);
 ((struct Obj14386 *)p)->f4=func_020490F4(d_021B6A1C[**(unsigned short **)p].value,0x7F);
 func_021B622C(p);func_021B624C((int *)p);func_021B6290(p,1,1,5);
 ((struct Obj14386 *)p)->f6058=1;
 return 2;
}

int func_021B6448(char *p) {
 if(WIPE_SYS_EndCheck()==0) return 1;
 if(GFL_USE_IsBgmFading()==1) return 1;
 GFL_USE_CancelChangeAndStopBgm();
 if(((struct Obj14387 *)p)->f6058==1) { func_021B6268(p); ARC_TOOL_DeleteHandle(((struct Obj14387 *)p)->f4); func_021B6248(p); func_021B6220(); }
 return 6;
}


u32 func_021B6490(char *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct Obj24472 *)p)->f6054;
    return 2;
}

int func_021B64AC(void)
{
    return 3;
}


u32 func_021B64B0(char *p)
{
    do {
        if (**(int * *)&((struct Obj14388 *)p)->f601C == 20) {
            (*(unsigned char **)p)[3] = 0;
            return 1;
        }
    } while (func_021B66DC(p) == 1);
    return ((struct Obj14388 *)p)->f6050;
}


/*
 * Frame-paced step: accumulates OS_GetTick deltas in microseconds and
 * advances one 66,667 us (15 Hz) step at a time. The entry table must be
 * const: that is what lets the e->b load schedule ahead of the count store.
 */
int func_021B64E0(char *p)
{
    const Entry_021B64E0 *e = &data_021B6A1C[**(u16 * *)&((struct Obj00546 *)p)->f0];

    if (((struct Obj00546 *)p)->f6040 == 0) {
        ((struct Obj00546 *)p)->f6040 = func_020870D0();
    } else {
        u64 now = func_020870D0();
        ((struct Obj00546 *)p)->f6048 += (now - ((struct Obj00546 *)p)->f6040) * 64000 / 33514;
        ((struct Obj00546 *)p)->f6040 = now;
        if (((struct Obj00546 *)p)->f6048 < 66667)
            return 4;
        ((struct Obj00546 *)p)->f6048 -= 66667;
    }

    switch (((struct Obj00546 *)p)->f603F) {
    case 0:
        func_021B669C(((struct Obj00546 *)p)->f4, ((struct Obj00546 *)p)->f603C, e->b, e->a, 0);
        (((struct Obj00546 *)p)->f603C)++;
        func_021B669C(((struct Obj00546 *)p)->f4, ((struct Obj00546 *)p)->f603C, e->b, e->a, 1);
        (((struct Obj00546 *)p)->f603C)++;
        func_0204047C((u8)2, (u8)0);
        func_0204047C((u8)3, (u8)1);
        ((struct Obj00546 *)p)->f603F = 1;
        break;
    case 1:
        func_0204047C((u8)((((struct Obj00546 *)p)->f603E ^ 1) + 2), (u8)0);
        func_0204047C((u8)(((struct Obj00546 *)p)->f603E + 2), (u8)1);
        func_021B669C(((struct Obj00546 *)p)->f4, ((struct Obj00546 *)p)->f603C, e->b, e->a, ((struct Obj00546 *)p)->f603E);
        (((struct Obj00546 *)p)->f603C)++;
        if (((struct Obj00546 *)p)->f603C >= e->count) {
            ((struct Obj00546 *)p)->f603F = 2;
        } else {
            ((struct Obj00546 *)p)->f603E ^= 1;
        }
        break;
    case 2:
        func_0204047C((u8)(((struct Obj00546 *)p)->f603E + 2), (u8)0);
        func_0204047C((u8)((((struct Obj00546 *)p)->f603E ^ 1) + 2), (u8)1);
        ((struct Obj00546 *)p)->f603F = 3;
        break;
    case 3:
        return 5;
    }
    return 4;
}


void func_021B669C(int a, int b, int c, int d, int e)
{
    int t = (int)ARC_UTIL_LoadHandleMember((void *)a, b, 1, 0x807f);

    func_020862F0(t, d);
    if (e == 0) {
        func_0207EB78(t, c, d);
    } else {
        func_0207ECF0(t, c, d);
    }
    func_020307B0((void *)t);
}

extern int (*d_021B6A40[])(char *,int *);

int func_021B66DC(char *p) {
 int *q; int result; q=*(int * *)&((struct Obj10717 *)p)->f601C;
 result=d_021B6A40[q[0]](p,q);
 if(result) {
  q=*(int * *)&((struct Obj10717 *)p)->f601C;
  *(int * *)&((struct Obj10717 *)p)->f601C=q+d_021B6A90[q[0]];
 }
 return result;
}

int func_021B6710(char *p,int *q) {
 if(((struct Obj08293 *)p)->f6020==q[1]) { ((struct Obj08293 *)p)->f6020=0; return 2; }
 ((struct Obj08293 *)p)->f6020=((struct Obj08293 *)p)->f6020+1; return 0;
}


int func_021B6730(int a, int *q)
{
    func_021B6290((char *)a, ((struct Obj14389 *)q)->f4, ((struct Obj14389 *)q)->f8, 5);
    return 1;
}


int func_021B6744(int a, int *q)
{
    func_021B62B8((char *)a, ((struct Obj14390 *)q)->f4, ((struct Obj14390 *)q)->f8, 5);
    return 1;
}


int func_021B6758(int a, int *q)
{
    func_021B62E0((char *)a, ((struct Obj14391 *)q)->f4, ((struct Obj14391 *)q)->f8, 5);
    return 1;
}


int func_021B676C(int a, int *q)
{
    func_021B630C((char *)a, ((struct Obj14392 *)q)->f4, ((struct Obj14392 *)q)->f8, 5);
    return 1;
}


int func_021B6780(char *p)
{
    ((struct Obj14393 *)p)->f6050 = 2;
    ((struct Obj14393 *)p)->f6054 = 5;
    return 2;
}

int func_021B6794(char *p,const int *q) {
 func_02049658(((struct Obj14394 *)p)->f4,q[2],q[1],0,0,1,127);
 if(q[2]==0) func_020498F4(((struct Obj14394 *)p)->f4,q[2],q[1],0,0,0,127);
 func_021B6338(p,q[1],q[2]); return 1;
}


int func_021B67DC(int a, int *q)
{
    func_02040588((unsigned char)((struct Obj14395 *)q)->f4,
                  (unsigned char)((struct Obj14395 *)q)->f8);
    return 1;
}


int func_021B67F4(int a, int *q)
{
    func_0204047C((unsigned char)((struct Obj14396 *)q)->f4,
                  (unsigned char)((struct Obj14396 *)q)->f8);
    return 1;
}

int func_021B680C(char *p, int *q)
{
    if (q[1] == 0) {
        ((struct Obj08294 *)p)->f6024 = q[2];
        ((struct Obj08294 *)p)->f6028 = q[3];
    } else {
        ((struct Obj08294 *)p)->f602C = q[2];
        ((struct Obj08294 *)p)->f6030 = q[3];
    }
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6831 at 0x021B6A68).
 */
int func_021B6830(char *p, int *q)
{
    ((struct Obj08295 *)p)->f6034 = q[1];
    ((struct Obj08295 *)p)->f6038 = q[2];
    ((struct Obj08295 *)p)->f6050 = 3;
    ((struct Obj08295 *)p)->f6054 = 5;
    return 2;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6855 at 0x021B6A6C).
 * volatile: 0x04000050 is a hardware register (REG_BLDCNT).
 */
int func_021B6854(char *p)
{
    *(volatile unsigned short *)0x04000050 = 0;
    ((struct Obj08296 *)p)->f6024 = 0;
    ((struct Obj08296 *)p)->f6028 = 0;
    ((struct Obj08296 *)p)->f602C = 0;
    ((struct Obj08296 *)p)->f6030 = 0;
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6879 at 0x021B6A70).
 */
int func_021B6878(void)
{
    return 1;
}


int func_021B687C(void)
{
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}


/*
 * 12-byte leaf: forwards the second word of the record to GFL_USE_PlayFanfare and
 * returns 1.  The lane enumerator reports 664 bytes because this is the last
 * func_ label in ov179; the disassembly ends at the pop and the rest is data.
 */
int func_021B6888(void *ctx, unsigned int *rec)
{
    GFL_USE_PlayFanfare((void *)rec[1]);
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6895 at 0x021B6A7C).
 */
int func_021B6894(void)
{
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6899 at 0x021B6A80).
 */
int func_021B6898(void)
{
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B689D at 0x021B6A84).
 */
int func_021B689C(void)
{
    return 1;
}

int func_021B68A0(char *p)
{
    ((struct Obj03875 *)p)->f603C = 0;
    ((struct Obj03875 *)p)->f603E = 0;
    ((struct Obj03875 *)p)->f603F = 0;
    ((struct Obj03875 *)p)->f6040 = 0;
    ((struct Obj03875 *)p)->f6044 = 0;
    ((struct Obj03875 *)p)->f6048 = 0;
    ((struct Obj03875 *)p)->f604C = 0;
    ((struct Obj03875 *)p)->f6050 = 4;
    return 2;
}
