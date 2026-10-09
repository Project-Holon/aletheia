/*
 * file:     dwc_rap_p30.c
 * unit:     yes
 * function: func_02157048, func_021570B8, func_02157108, func_02157138, func_02157160, func_02157170
 * address:  0x02157048
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02060C5C  0x02060C5C  arm
 *   func_02156F14  0x02156F14  thumb  ov009
 *   func_02060C94  0x02060C94  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021A1C8C  0x021A1C8C  data  ov009  a1
 *   func_02059F6C  0x02059F6C  arm
 *   func_02156F5C  0x02156F5C  thumb  ov009
 *   func_02156FDC  0x02156FDC  thumb  ov009
 *   MIi_CpuClearFast    0x02082AC0  arm
 *   func_02059718       0x02059718  arm
 *   DWC_CreateUserData  0x020596FC  arm
 *   func_02059870       0x02059870  arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203C968 0x0203C968 arm
 *   func_02059F18 0x02059F18 arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200F83C  0x0200F83C  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200FB4C  0x0200FB4C  thumb
 *   func_0200F7C0  0x0200F7C0  thumb
 *   func_0200FAAC  0x0200FAAC  thumb
 *   func_0203C554  0x0203C554  arm
 */
#include "../../matched/include/G_Obj.h"

struct DWCstAccUserData;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u16 f20;
} Obj;

typedef struct Status {
    int f0;
    int f4;
    int f8;
    int fC;
} Status;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern void *func_02060C5C(void *start, u32 size, u32 attr);
extern void func_02156F14(void);
extern void func_02060C94(void *heap);
extern u32 func_020307B0(void *p);
extern int func_02059F6C(void *a, u32 b, void *c, void *d);
extern u32 func_02156F5C(u32 a, u32 b, u32 c);
extern void func_02156FDC(u32 a, void *p, int b);
extern void MIi_CpuClearFast(unsigned int data, void *destp, unsigned int size);
extern int func_02059718(struct DWCstAccUserData *userdata);
extern void DWC_CreateUserData(void *userdata);
extern void func_02059870(void *userdata);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern void func_02059F18(void);
extern int func_0203CD98(void);
extern u32 func_0203CA98(void);
extern u32 func_0200FB24(void);
extern void func_0200F83C(void);
extern void func_0200FBA0(void);
extern void func_0200FB38(void);
extern void func_0200FB4C(unsigned int x);
extern void func_0200F7C0(u32 value);
extern void func_0200FAAC(void);
extern void func_0203C554(u32 a);
void func_02157048(u32 a, u32 b);
void func_021570B8(void);
int func_02157108(u16 a);
/* * Clears the 0x40-byte DWC account user-data block, then rebuilds it when * the check at func_02059718 (CRC validation) fails: DWC_CreateUserData, * then the veneer at 0x02059870 into DWCi_Acc_ClearDirty (func_0205987C). * Called from arm9 sub_02009800 (bl at 0x0200982C), the save-table * constructor at 0x0209DB98. */ void func_02157138(void *userdata);
void func_02157160(void);
/* * padding); the three THM_CALL sites to func_0200FB4C stay wildcarded * because 0x0200FB4C is an unlabelled arm9 Thumb leaf (it prints as .word * data after func_0200FB38), so no class attests it. The leaf verifies * EXACT (literal x2) as pkt_0200FB4C / src/matched/arm9/func_0200FB4C.c * with this body, outside this lane's write set: * * typedef struct State { u8 pad00[0x2C]; int f2C; u8 pad30[0x29]; * u8 f59; u8 f5A; u8 pad5B[5]; int f60; } State; * extern State g_0214617C; symbols: 0x0214617C data a4 * void func_0200FB4C(int x) * { * if (g_0214617C.f2C != 2) { * g_0214617C.f60 = x; * g_0214617C.f5A = 1; * g_0214617C.f59 = 1; * g_0214617C.f2C = 2; * } * } * * Filing that leaf makes this file (and ov135 func_022010BC) EXACT. */ int func_02157170(int a0, int a1);
extern Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];
extern char d_021A1C8C[];



void func_02157048(u32 a, u32 b)
{
    if (d_021A8268 != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    d_021A8268 = (Obj *)func_02030734(0, 0x24, 1, d_021A1C7C, 0x14C);
    d_021A8268->f4 = (u32)func_02030734(a, b - 0x80, 0, d_021A1C7C, 0x14D);
    d_021A8268->f0 = (u32)func_02060C5C((void *)((d_021A8268->f4 + 0x1f) & ~0x1f), b - 0xc0, 0);
    d_021A8268->f20 = 0;
}



void func_021570B8(void)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->f1C == 1 || d_021A8268->fC != 0) {
        func_02156F14();
    }
    func_02060C94((void *)d_021A8268->f0);
    func_020307B0((void *)d_021A8268->f4);
    func_020307B0(d_021A8268);
    d_021A8268 = 0;
}


int func_02157108(u16 a)
{
    int r;
    func_02157048(a, 0x40000);
    r = func_02059F6C(d_021A1C8C, 0x4952414A, func_02156F5C, func_02156FDC);
    func_021570B8();
    return r;
}



/*
 * Clears the 0x40-byte DWC account user-data block, then rebuilds it when
 * the check at func_02059718 (CRC validation) fails: DWC_CreateUserData,
 * then the veneer at 0x02059870 into DWCi_Acc_ClearDirty (func_0205987C).
 * Called from arm9 sub_02009800 (bl at 0x0200982C), the save-table
 * constructor at 0x0209DB98.
 */
void func_02157138(void *userdata)
{
    MIi_CpuClearFast(0, userdata, 0x40);
    if (func_02059718(userdata) == 0) {
        DWC_CreateUserData(userdata);
        func_02059870(userdata);
    }
}


void func_02157160(void)
{
    func_0203CA04();
    func_0203C968();
    func_02059F18();
}



/*
 * padding); the three THM_CALL sites to func_0200FB4C stay wildcarded
 * because 0x0200FB4C is an unlabelled arm9 Thumb leaf (it prints as .word
 * data after func_0200FB38), so no class attests it. The leaf verifies
 * EXACT (literal x2) as pkt_0200FB4C / src/matched/arm9/func_0200FB4C.c
 * with this body, outside this lane's write set:
 *
 *   typedef struct State { u8 pad00[0x2C]; int f2C; u8 pad30[0x29];
 *                          u8 f59; u8 f5A; u8 pad5B[5]; int f60; } State;
 *   extern State g_0214617C;           symbols: 0x0214617C data a4
 *   void func_0200FB4C(int x)
 *   {
 *       if (g_0214617C.f2C != 2) {
 *           g_0214617C.f60 = x;
 *           g_0214617C.f5A = 1;
 *           g_0214617C.f59 = 1;
 *           g_0214617C.f2C = 2;
 *       }
 *   }
 *
 * Filing that leaf makes this file (and ov135 func_022010BC) EXACT.
 */
int func_02157170(int a0, int a1)
{
    Status *st;
    int v;

    if (func_0203CD98() != 0) {
        st = (Status *)func_0203CA98();
        if (func_0200FB24() != 0) {
            switch (st->f4) {
            case 0:
                break;
            case 1:
            case 2:
                if (a0 == 0) {
                    func_02157160();
                    func_0200F83C();
                    func_0200FBA0();
                    return 1;
                }
                func_02059F18();
            case 3:
            case 4:
            case 5:
                func_0200FB38();
                func_0200FB4C(13);
                return 2;
            case 6:
                func_0200FB38();
                return 2;
            case 7:
                func_0200F7C0(15);
                return 3;
            }
        }
        v = st->fC;
        if (v == 0x3F0 || v == 0x3F1) {
            if (a1 != 0) {
                func_0200FAAC();
                func_02157160();
                func_0203C554(1);
                func_0200F83C();
                func_0200FBA0();
                return 4;
            }
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            func_0203C554(1);
            return 0;
        }
        if (v == 0x3F2 || v == 0x3F3 || v == 0x3F4 || v == 0x3F6) {
            if (a0 == 0) {
                func_02157160();
                func_0200F83C();
                func_0200FBA0();
                return 1;
            }
            func_0200FB38();
            func_0200FB4C(13);
            return 2;
        }
        if (v == 0x3EE || v == 0x3F7) {
            func_0200FB38();
            func_0200FB4C(13);
            return 2;
        }
    }
    return 0;
}
