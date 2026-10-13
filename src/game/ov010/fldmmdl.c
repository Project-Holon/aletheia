/*
 * file:     fldmmdl.c
 * unit:     yes
 * function: func_0216CC58, func_0216CCB0, func_0216CCCC, func_0216CCDC, func_0216CD30, func_0216CD50, func_0216CD64, func_0216CD78, func_0216CD88, func_0216CDB8, func_0216CDC4, func_0216CE60, func_0216CE6C, func_0216CEAC, func_0216CEE4, func_0216CF2C, func_0216CF6C, func_0216CFC4, func_0216D02C, func_0216D040, func_0216D0E8, func_0216D0F8, func_0216D1C8, func_0216D208, func_0216D230, func_0216D244, func_0216D268, func_0216D28C, func_0216D2AC, func_0216D2F8, func_0216D38C, func_0216D3A8, func_0216D3B4, func_0216D3CC, func_0216D410, func_0216D438, func_0216D454, func_0216D480, func_0216D4B4, func_0216D4D4, func_0216D4DC, func_0216D4E4, func_0216D4F0, func_0216D4F4, func_0216D4F8, func_0216D4FC, func_0216D508, func_0216D514, func_0216D518, func_0216D51C, func_0216D520, func_0216D524, func_0216D528, func_0216D52C, func_0216D530, func_0216D534, func_0216D538, func_0216D548, func_0216D550, func_0216D55C, func_0216D564, func_0216D568, func_0216D570, func_0216D57C, func_0216D584, func_0216D588, func_0216D58C, func_0216D590, func_0216D594, func_0216D598, func_0216D59C, func_0216D5A0, func_0216D5A4, func_0216D5A8, func_0216D5AC, func_0216D5B0, func_0216D5B4, func_0216D5B8, func_0216D5BC, func_0216D5D4, func_0216D5D8, func_0216D5E0, func_0216D5F8, func_0216D5FC, func_0216D600, func_0216D608, func_0216D60C, func_0216D620, func_0216D63C, func_0216D65C, func_0216D660, func_0216D668, func_0216D66C, func_0216D674, func_0216D678, func_0216D67C, func_0216D684, func_0216D69C, func_0216D6A0, func_0216D6B8, func_0216D6BC, func_0216D6D4, func_0216D6D8, func_0216D6F0, func_0216D6F4, func_0216D708, func_0216D71C, func_0216D730, func_0216D744, func_0216D758, func_0216D76C, func_0216D780, func_0216D794, func_0216D7A8, func_0216D7C0, func_0216D7C4, func_0216D7C8, func_0216D7CC, func_0216D7D4, func_0216D7D8, func_0216D7DC, func_0216D7E0, func_0216D7E4, func_0216D7E8, func_0216D7F0, func_0216D7F4, func_0216D7F8, func_0216D800, func_0216D804, func_0216D80C, func_0216D810, func_0216D818, func_0216D81C, func_0216D824, func_0216D828, func_0216D83C, func_0216D844, func_0216D848, func_0216D854, func_0216D85C, func_0216D860, func_0216D86C, func_0216D874, func_0216D87C, func_0216D888, func_0216D88C, func_0216D89C, func_0216D8AC, func_0216D8B0, func_0216D8C0, func_0216D8D0, func_0216D8E0, func_0216D8F0, func_0216D900, func_0216D910, func_0216D91C, func_0216D924, func_0216D92C, func_0216D948, func_0216D95C, func_0216D974, func_0216D98C, func_0216D9A0, func_0216D9E4, func_0216DA20, func_0216DA30, func_0216DA44, func_0216DA50, func_0216DA5C, func_0216DA70, func_0216DA7C, func_0216DA88, func_0216DA94, func_0216DAA0, func_0216DAB4, func_0216DAC8, func_0216DAE0, func_0216DAF8, func_0216DB04, func_0216DB10, func_0216DB24, func_0216DB4C, func_0216DB68, func_0216DB80, func_0216DB98, func_0216DBB4, func_0216DBCC, func_0216DBE8, func_0216DC00, func_0216DC18, func_0216DC34, func_0216DC4C, func_0216DC64, func_0216DC80, func_0216DC98, func_0216DCB4, func_0216DCCC, func_0216DCE8, func_0216DD04, func_0216DD1C, func_0216DD60, func_0216DDC0, func_0216DDDC, func_0216DE54, func_0216DE94, func_0216DEE0, func_0216DEEC, func_0216DF1C, func_0216DF64, func_0216DFAC, func_0216DFC4, func_0216E014, func_0216E084, func_0216E0AC, func_0216E0E8, func_0216E114, func_0216E160, func_0216E174, func_0216E180, func_0216E190, func_0216E1A4, func_0216E1C4, func_0216E204, func_0216E280, func_0216E290, func_0216E29C, func_0216E2AC, func_0216E2E0, func_0216E2E8, func_0216E39C, func_0216E3C4, func_0216E3C8, func_0216E3CC, func_0216E3D0, func_0216E3D8, func_0216E400, func_0216E40C, func_0216E418, func_0216E42C, func_0216E434, func_0216E464, func_0216E468, func_0216E46C, func_0216E470
 * address:  0x0216CC58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl.c at 0x0216BFD4 and 0x0216CC58 (__FILE__ anchors: namein_setup.c up to 0x0216CC40, fldmmdl.c from 0x0216CC58).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_02172B48     0x02172B48  data  ov010  a1
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02030DA4  0x02030DA4  arm
 *   func_02049238  0x02049238  arm
 *   func_02197C4C  0x02197C4C  thumb
 *   func_02030D28  0x02030D28  arm
 *   func_0219C5FC  0x0219C5FC  thumb
 *   func_0219C624  0x0219C624  thumb
 *   func_0219C630  0x0219C630  thumb
 *   func_02087A3C  0x02087A3C  arm
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_021642F8 0x021642F8 thumb ov010
 *   func_02164304 0x02164304 thumb ov010
 *   func_0216E544  0x0216E544  thumb  ov010
 *   func_02163010  0x02163010  thumb  ov010
 *   func_0219D6B8  0x0219D6B8  thumb
 *   func_02163028   0x02163028  thumb  ov010
 *   func_0219D6CC   0x0219D6CC  thumb
 *   func_02197C78  0x02197C78  thumb
 *   func_02163C04  0x02163C04  thumb  ov010
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_02048F4C  0x02048F4C  arm
 *   func_0200F128 0x0200F128 thumb
 *   func_0204944C 0x0204944C arm
 *   func_020143CC 0x020143CC thumb
 *   d_021D5E04  0x021D5E04  data  ov021  a4
 *   d_021D770C  0x021D770C  data  ov021  a4
 *   func_020142E8  0x020142E8  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef int s32;
typedef long long s64;
#include "fldmmdl_types.h"

/* Current grid position of a field model, as copied out by FLDMMDL_GetGridNowPos. */
typedef struct MmdlGridVec {
    s16 x;
    s16 y;
    s16 z;
} MmdlGridVec;

/* Result block of a grid position search: count, then up to 16 models. */
typedef struct MmdlSearchList {
    int count;
    Mmdl *mmdl[16];
} MmdlSearchList;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern int func_020307B0(void *mem);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_02030CB0(u32 capacity);
extern void *func_02030CBC(u32 capacity, void *work);
extern void *func_020490F4(u32 arcId, u32 heapId);
extern void func_02030DA4(void *tcbSys);
extern void func_02049238(void *arc);
extern void func_02197C4C(MmdlSys *sys);
extern void func_02030D28(void *tcbSys);
extern void func_0219C5FC(MmdlSys *sys);
extern void func_0219C624(MmdlSys *sys);
extern int func_0219C630(MmdlSys *sys);
extern void func_02087A3C(int, int);
extern int func_0216E51C();
extern void func_021642F8(Mmdl *mmdl);
extern void func_02164304(Mmdl *mmdl, const MmdlHeader *header);
extern void func_0216E544(Mmdl *mmdl, MmdlVec *pos);
extern void func_02163010(Mmdl *mmdl);
extern void func_0219D6B8(Mmdl *mmdl);
extern void func_02163028(Mmdl *mmdl);
extern void func_0219D6CC(Mmdl *mmdl);
extern void func_02197C78(Mmdl *mmdl);
extern int func_02163C04(Mmdl *mmdl, u32 gridX, u32 gridZ, u32 flag);
extern void *func_02030DA8(void *tcbSys, void (*proc)(void *tcb, void *work), void *work, int priority);
extern void func_02030EAC(void *tcb);
extern void func_02163F10(Mmdl *mmdl);
extern void func_02164010(Mmdl *mmdl);
extern void func_02048F4C(void *dst, u32 arcId, u32 member);
extern u32 func_0200F128(u32 objCode);
extern void func_0204944C(void *arc, u32 member, u32 offset, u32 size, void *dst);
extern u16 *func_020143CC(void *evWork, unsigned int workId);
extern unsigned int func_020142E8(void *evWork, int flag);
MmdlSys *func_0216CC58(int heapId, int mmdlMax, void *saveData);
void func_0216CCB0(MmdlSys *sys);
void func_0216CCCC(MmdlSys *sys);
void func_0216CCDC(MmdlSys *sys, int heapId, void *gameData, void *fieldMap, void *g3dMapper, void *nogridMapper);
void func_0216CD30(MmdlSys *sys);
void func_0216CD50(MmdlSys *sys);
void func_0216CD64(MmdlSys *sys);
void func_0216CD78(MmdlSys *sys);
void func_0216CD88(MmdlSys *sys);
void func_0216CDB8(MmdlSys *sys, const unsigned short *areaIdRef);
Mmdl *func_0216CDC4(MmdlSys *sys, const MmdlHeader *src, int zoneId, void *evWork);
Mmdl *func_0216CE60(MmdlSys *sys, const MmdlHeader *header, int zoneId);
Mmdl *func_0216CE6C(MmdlSys *sys, u16 gridX, u16 gridZ, u16 dir, u16 objId, u16 objCode, u16 moveCode, int zoneId);
void func_0216CEAC(MmdlSys *sys, const MmdlHeader *header, int zoneId, u32 count, void *evWork);
Mmdl *func_0216CEE4(MmdlSys *sys, const MmdlHeader *header, int zoneId, int count, void *evWork, u32 objId);
void func_0216CF2C(Mmdl *mmdl);
void func_0216CF6C(MmdlSys *sys);
void func_0216CFC4(Mmdl *mmdl, const MmdlHeader *header);
void func_0216D02C(Mmdl *mmdl, const MmdlHeader *header);
void func_0216D040(Mmdl *mmdl, const MmdlHeader *header, void *evWork, MmdlSys *sys);
void func_0216D0E8(Mmdl *mmdl, const MmdlHeader *header, int unused);
void func_0216D0F8(Mmdl *mmdl, const MmdlHeader *header);
void func_0216D1C8(Mmdl *mmdl, MmdlSys *sys, int zoneId);
void func_0216D208(Mmdl *mmdl);
void func_0216D230(Mmdl *mmdl);
void func_0216D244(MmdlSys *sys, Mmdl *mmdl);
void func_0216D268(MmdlSys *sys, Mmdl *mmdl);
void func_0216D28C(Mmdl *mmdl);
void func_0216D2AC(MmdlSys *sys);
void func_0216D2F8(MmdlSys *sys);
void func_0216D38C(Mmdl *mmdl);
void func_0216D3A8(void *tcb, void *work);
void func_0216D3B4(Mmdl *mmdl);
int func_0216D3CC(Mmdl *mmdl);
void func_0216D410(Mmdl *mmdl, u16 code);
void func_0216D438(Mmdl *mmdl, u16 code);
int func_0216D454(Mmdl *mmdl);
int func_0216D480(Mmdl *mmdl);
void func_0216D4B4(Mmdl *mmdl);
u32 func_0216D4D4(MmdlSys *sys, u32 bit);
void func_0216D4DC(MmdlSys *sys, u32 bit);
void func_0216D4E4(MmdlSys *sys, u32 bit);
u16 func_0216D4F0(const MmdlSys *sys);
u16 func_0216D4F4(MmdlSys *sys);
u32 func_0216D4F8(MmdlSys *sys);
void func_0216D4FC(MmdlSys *sys);
void func_0216D508(MmdlSys *sys);
void *func_0216D514(MmdlSys *sys);
void *func_0216D518(MmdlSys *sys);
void func_0216D51C(MmdlSys *sys, void *blActCont);
void *func_0216D520(MmdlSys *sys);
void func_0216D524(MmdlSys *sys, void *g3dObjCont);
void *func_0216D528(MmdlSys *sys);
void *func_0216D52C(MmdlSys *sys);
void *func_0216D530(MmdlSys *sys);
void *func_0216D534(MmdlSys *sys);
u32 func_0216D538(MmdlSys *sys);
void func_0216D548(Mmdl *mmdl, u32 bit);
void func_0216D550(Mmdl *mmdl, u32 bit);
u32 func_0216D55C(Mmdl *mmdl, u32 bit);
u32 func_0216D564(Mmdl *mmdl);
void func_0216D568(Mmdl *mmdl, u32 bit);
void func_0216D570(Mmdl *mmdl, u32 bit);
u32 func_0216D57C(Mmdl *mmdl, u32 bit);
void func_0216D584(Mmdl *mmdl, u16 objId);
u16 func_0216D588(Mmdl *mmdl);
void func_0216D58C(Mmdl *mmdl, u16 zoneId);
u16 func_0216D590(Mmdl *mmdl);
void func_0216D594(Mmdl *mmdl, u32 objCode);
u16 func_0216D598(Mmdl *mmdl);
void func_0216D59C(Mmdl *mmdl, u16 moveCode);
u16 func_0216D5A0(Mmdl *mmdl);
void func_0216D5A4(Mmdl *mmdl, u16 eventType);
u16 func_0216D5A8(Mmdl *mmdl);
void func_0216D5AC(Mmdl *mmdl, u16 eventFlag);
u16 func_0216D5B0(Mmdl *mmdl);
void func_0216D5B4(Mmdl *mmdl, u16 eventId);
u32 func_0216D5B8(Mmdl *mmdl);
int func_0216D5BC(Mmdl *mmdl);
int func_0216D5D4(Mmdl *mmdl);
void func_0216D5D8(Mmdl *mmdl, int dir);
void func_0216D5E0(Mmdl *mmdl, int dir);
u16 func_0216D5F8(Mmdl *mmdl);
u16 func_0216D5FC(Mmdl *mmdl);
void func_0216D600(Mmdl *mmdl, int dir);
u16 func_0216D608(Mmdl *mmdl);
void func_0216D60C(Mmdl *mmdl, int dir);
void func_0216D620(Mmdl *mmdl, int param, int no);
int func_0216D63C(Mmdl *mmdl, int no);
void func_0216D65C(Mmdl *mmdl, short limit);
int func_0216D660(Mmdl *mmdl);
void func_0216D668(Mmdl *mmdl, short limit);
int func_0216D66C(Mmdl *mmdl);
void func_0216D674(Mmdl *mmdl, u16 drawStatus);
u16 func_0216D678(Mmdl *mmdl);
MmdlSys *func_0216D67C(Mmdl *mmdl);
void *func_0216D684(Mmdl *mmdl, int size);
void *func_0216D69C(Mmdl *mmdl);
void *func_0216D6A0(Mmdl *mmdl, int size);
void *func_0216D6B8(Mmdl *mmdl);
void *func_0216D6BC(Mmdl *mmdl, int size);
void *func_0216D6D4(Mmdl *mmdl);
void *func_0216D6D8(Mmdl *mmdl, int size);
void *func_0216D6F0(Mmdl *mmdl);
void func_0216D6F4(Mmdl *mmdl);
void func_0216D708(Mmdl *mmdl);
void func_0216D71C(Mmdl *mmdl);
void func_0216D730(Mmdl *mmdl);
void func_0216D744(Mmdl *mmdl);
void func_0216D758(Mmdl *mmdl);
void func_0216D76C(Mmdl *mmdl);
void func_0216D780(Mmdl *mmdl);
void func_0216D794(Mmdl *mmdl);
int func_0216D7A8(Mmdl *mmdl, unsigned int kind);
void func_0216D7C0(Mmdl *mmdl, u16 code);
u16 func_0216D7C4(Mmdl *mmdl);
void func_0216D7C8(Mmdl *mmdl, u16 seq);
void func_0216D7CC(Mmdl *mmdl);
u16 func_0216D7D4(Mmdl *mmdl);
void func_0216D7D8(Mmdl *mmdl, u32 attr);
u32 func_0216D7DC(Mmdl *mmdl);
void func_0216D7E0(Mmdl *mmdl, u32 attr);
u32 func_0216D7E4(Mmdl *mmdl);
int func_0216D7E8(Mmdl *mmdl);
void func_0216D7F0(Mmdl *mmdl, short x);
void func_0216D7F4(Mmdl *mmdl, short y);
int func_0216D7F8(Mmdl *mmdl);
void func_0216D800(Mmdl *mmdl, short z);
int func_0216D804(Mmdl *mmdl);
void func_0216D80C(Mmdl *mmdl, s16 x);
int func_0216D810(Mmdl *mmdl);
void func_0216D818(Mmdl *mmdl, s16 y);
int func_0216D81C(Mmdl *mmdl);
void func_0216D824(Mmdl *mmdl, s16 z);
void func_0216D828(Mmdl *mmdl, MmdlGridVec *out);
int func_0216D83C(Mmdl *mmdl);
void func_0216D844(Mmdl *mmdl, short x);
void func_0216D848(Mmdl *mmdl, short dx);
int func_0216D854(Mmdl *mmdl);
void func_0216D85C(Mmdl *mmdl, int y);
void func_0216D860(Mmdl *mmdl, short dy);
int func_0216D86C(Mmdl *mmdl);
void func_0216D874(Mmdl *mmdl, int z);
void func_0216D87C(Mmdl *mmdl, short dz);
MmdlVec *func_0216D888(Mmdl *mmdl);
void func_0216D88C(const Mmdl *mmdl, MmdlVec *out);
void func_0216D89C(Mmdl *mmdl, const MmdlVec *pos);
s32 func_0216D8AC(Mmdl *mmdl);
void func_0216D8B0(Mmdl *mmdl, MmdlVec *out);
void func_0216D8C0(Mmdl *mmdl, const MmdlVec *offset);
void func_0216D8D0(Mmdl *mmdl, MmdlVec *out);
void func_0216D8E0(Mmdl *mmdl, const MmdlVec *offset);
void func_0216D8F0(Mmdl *mmdl, MmdlVec *out);
void func_0216D900(Mmdl *mmdl, const MmdlVec *offset);
void *func_0216D910(Mmdl *mmdl);
u8 func_0216D91C(Mmdl *mmdl);
u8 func_0216D924(Mmdl *mmdl);
void func_0216D92C(Mmdl *mmdl, MmdlVec *offset);
int func_0216D948(MmdlSys *sys);
void func_0216D95C(MmdlSys *sys, int flag);
void func_0216D974(MmdlSys *sys, int flag);
int func_0216D98C(MmdlSys *sys);
void func_0216D9A0(MmdlSys *sys);
void func_0216D9E4(MmdlSys *sys);
u32 func_0216DA20(Mmdl *mmdl, u32 bit);
int func_0216DA30(Mmdl *mmdl);
void func_0216DA44(Mmdl *mmdl);
void func_0216DA50(Mmdl *mmdl);
int func_0216DA5C(Mmdl *mmdl);
void func_0216DA70(Mmdl *mmdl);
void func_0216DA7C(Mmdl *mmdl);
void func_0216DA88(Mmdl *mmdl);
void func_0216DA94(Mmdl *mmdl);
int func_0216DAA0(Mmdl *mmdl);
int func_0216DAB4(Mmdl *mmdl);
void func_0216DAC8(Mmdl *mmdl, int flag);
void func_0216DAE0(Mmdl *mmdl, int flag);
void func_0216DAF8(Mmdl *mmdl);
void func_0216DB04(Mmdl *mmdl);
int func_0216DB10(Mmdl *mmdl);
int func_0216DB24(Mmdl *mmdl);
void func_0216DB4C(Mmdl *mmdl, int flag);
int func_0216DB68(Mmdl *mmdl);
void func_0216DB80(Mmdl *mmdl, int flag);
void func_0216DB98(Mmdl *mmdl, int flag);
int func_0216DBB4(Mmdl *mmdl);
void func_0216DBCC(Mmdl *mmdl, u32 flag);
int func_0216DBE8(Mmdl *mmdl);
int func_0216DC00(Mmdl *mmdl);
void func_0216DC18(Mmdl *mmdl, int flag);
int func_0216DC34(Mmdl *mmdl);
int func_0216DC4C(Mmdl *mmdl);
void func_0216DC64(Mmdl *mmdl, int flag);
int func_0216DC80(Mmdl *mmdl);
void func_0216DC98(Mmdl *mmdl, int flag);
int func_0216DCB4(Mmdl *mmdl);
void func_0216DCCC(Mmdl *mmdl, int flag);
void func_0216DCE8(Mmdl *mmdl, int flag);
int func_0216DD04(Mmdl *mmdl);
int func_0216DD1C(const MmdlSys *sys, Mmdl **out, u32 *iter);
int func_0216DD60(MmdlSys *sys, u32 gridX, u32 gridZ, u32 flag, MmdlSearchList *out);
Mmdl *func_0216DDC0(MmdlSys *sys, u32 gridX, u32 gridZ, u32 flag);
Mmdl *func_0216DDDC(MmdlSys *sys, u32 gridX, u32 gridZ, s32 posY, s32 range, u32 flag);
Mmdl *func_0216DE54(MmdlSys *sys, u32 moveCode);
Mmdl *func_0216DE94(MmdlSys *sys, u32 objId);
Mmdl *func_0216DEE0(MmdlSys *sys);
Mmdl *func_0216DEEC(MmdlSys *sys);
void func_0216DF1C(MmdlSys *sys);
void func_0216DF64(Mmdl *mmdl, MmdlSys *sys);
void func_0216DFAC(Mmdl *mmdl);
int func_0216DFC4(Mmdl *mmdl, u32 objCode);
void func_0216E014(Mmdl *mmdl, const MmdlVec *pos, int dir);
void func_0216E084(Mmdl *mmdl, unsigned int gridX, unsigned int y, unsigned int gridZ, u16 dir);
void func_0216E0AC(Mmdl *mmdl, const MmdlHeader *header);
void func_0216E0E8(Mmdl *mmdl, u16 moveCode);
void func_0216E114(Mmdl *mmdl);
void func_0216E160(Mmdl *mmdl);
void func_0216E174(Mmdl *mmdl);
void func_0216E180(Mmdl *mmdl);
void func_0216E190(Mmdl *mmdl);
void func_0216E1A4(Mmdl *mmdl, MmdlCheckInfo *info);
int func_0216E1C4(Mmdl *mmdl, const MmdlCheckInfo *info);
void func_0216E204(Mmdl *mmdl, u32 objCode);
void func_0216E280(MmdlSys *sys, int heapId);
void func_0216E290(MmdlSys *sys);
void func_0216E29C(MmdlSys *sys, int member);
void func_0216E2AC(MmdlSys *sys, u32 no, MmdlObjCodeParam *out);
u16 func_0216E2E0(MmdlSys *sys);
void func_0216E2E8(const MmdlSys *sys, u32 objCode, MmdlObjCodeParam *out);
void func_0216E39C(const MmdlSys *sys, u32 objCode, Mmdl *mmdl);
MmdlObjCodeParam *func_0216E3C4(Mmdl *mmdl);
void *func_0216E3C8(MmdlObjCodeParam *param);
void *func_0216E3CC(MmdlObjCodeParam *param);
u32 func_0216E3D0(void *evWork, u32 objCode);
u32 func_0216E3D8(void *evWork, u32 objCode);
const MmdlMoveProcList *func_0216E400(int moveCode);
const MmdlDrawProcList *func_0216E40C(int drawProcNo);
int func_0216E418(const MmdlHeader *header);
unsigned int func_0216E42C(void *evWork, int flag);
u32 func_0216E434(u32 eventType);
void func_0216E464(void);
void func_0216E468(void);
void func_0216E46C(void);
void func_0216E470(void);
extern char d_02172B48[];
extern const MmdlMoveProcList *d_021D5E04[];
extern const MmdlDrawProcList *d_021D770C[];

MmdlSys *func_0216CC58(int heapId, int mmdlMax, void *saveData)
{
    MmdlSys *sys = func_02030734(heapId, sizeof(MmdlSys), 1, d_02172B48, 0xc3);
    sys->mmdlBuf = func_02030734(heapId, mmdlMax * sizeof(Mmdl), 1, d_02172B48, 0xc4);
    sys->mmdlMax = mmdlMax;
    sys->sysHeapId = heapId;
    sys->saveData = saveData;
    sys->tcbPriority = 0x80;
    func_0216E280(sys, heapId);
    sys->objCodeParamCache = func_02030734(heapId, 0x310, 1, d_02172B48, 0xcf);
    return sys;
}

void func_0216CCB0(MmdlSys *sys)
{
    func_0216E290(sys);
    func_020307B0(sys->objCodeParamCache);
    func_020307B0(sys->mmdlBuf);
    func_020307B0(sys);
}

void func_0216CCCC(MmdlSys *sys)
{
    MI_CpuFill8(sys->objCodeParamCache, 0, 0x310);
}

void func_0216CCDC(MmdlSys *sys, int heapId, void *gameData, void *fieldMap, void *g3dMapper, void *nogridMapper)
{
    void *tcbWork;
    unsigned short mmdlMax;
    sys->g3dMapper = g3dMapper;
    sys->heapId = heapId;
    sys->gameData = gameData;
    sys->fieldMap = fieldMap;
    tcbWork = func_02030734(heapId, func_02030CB0(sys->mmdlMax), 0, d_02172B48, 0x109);
    mmdlMax = sys->mmdlMax;
    sys->tcbSysWork = tcbWork;
    sys->tcbSys = func_02030CBC(mmdlMax, tcbWork);
    sys->resArcHandle = func_020490F4(0x31, heapId);
    sys->nogridMapper = nogridMapper;
    func_0216D4DC(sys, MMDLSYS_STABIT_MOVE_INIT);
}

void func_0216CD30(MmdlSys *sys)
{
    func_02030DA4(sys->tcbSys);
    func_020307B0(sys->tcbSysWork);
    func_02049238(sys->resArcHandle);
    func_0216D4E4(sys, MMDLSYS_STABIT_MOVE_INIT);
}

void func_0216CD50(MmdlSys *sys)
{
    func_02197C4C(sys);
    sys->areaIdRef = 0;
    func_0216CD30(sys);
}

void func_0216CD64(MmdlSys *sys)
{
    func_02030D28(sys->tcbSys);
    func_0219C5FC(sys);
}

void func_0216CD78(MmdlSys *sys)
{
    if (sys->blActCont != 0)
        func_0219C624(sys);
}

void func_0216CD88(MmdlSys *sys)
{
    while (func_0219C630(sys) == 1) {
        func_0216CD64(sys);
        func_02087A3C(1, 1);
        func_0216CD78(sys);
    }
}

void func_0216CDB8(MmdlSys *sys, const unsigned short *areaIdRef)
{
    sys->areaIdRef = areaIdRef;
    func_0216D95C(sys, 1);
}

Mmdl *func_0216CDC4(MmdlSys *sys, const MmdlHeader *src, int zoneId, void *evWork)
{
    MmdlHeader header = *src;
    Mmdl *mmdl;
    mmdl = func_0216DEEC(sys);
    func_0216D1C8(mmdl, sys, zoneId);
    func_0216D040(mmdl, &header, evWork, sys);
    func_0216D208(mmdl);
    if (func_0216E51C(mmdl) == 1)
        func_0216D548(mmdl, MMDL_STABIT_FELLOW_HIT_OFF | MMDL_STABIT_HEIGHT_GET_OFF);
    if (func_0216D4D4(sys, MMDLSYS_STABIT_MOVE_INIT)) {
        func_0216D244(sys, mmdl);
        func_0216D268(sys, mmdl);
    }
    if (func_0216D4D4(sys, MMDLSYS_STABIT_DRAW_INIT))
        func_0216E114(mmdl);
    func_0216D4FC(func_0216D67C(mmdl));
    func_0216D0E8(mmdl, &header, 0);
    return mmdl;
}

Mmdl *func_0216CE60(MmdlSys *sys, const MmdlHeader *header, int zoneId)
{
    return func_0216CDC4(sys, header, zoneId, 0);
}

Mmdl *func_0216CE6C(MmdlSys *sys, u16 gridX, u16 gridZ, u16 dir, u16 objId, u16 objCode, u16 moveCode, int zoneId)
{
    MmdlHeader header;
    MmdlHeader *p = &header;
    MmdlHeaderGridPos *gridPos;
    MI_CpuFill8(&header, 0, sizeof(MmdlHeader));
    p->objId = objId;
    p->objCode = objCode;
    p->moveCode = moveCode;
    p->dirHeader = dir;
    header.posType = 0;
    gridPos = (MmdlHeaderGridPos *)header.pos;
    gridPos->gridX = gridX;
    gridPos->gridZ = gridZ;
    return func_0216CE60(sys, &header, zoneId);
}

/*
 * extent: zero alignment halfword at 0x0216CEE2, then labelled 0x0216CEE4.
 */
void func_0216CEAC(MmdlSys *sys, const MmdlHeader *header, int zoneId, u32 count, void *evWork)
{
    do {
        if (func_0216E418(header) == 1 || func_0216E42C(evWork, header->eventFlag) == 0)
            func_0216CDC4(sys, header, zoneId, evWork);
        header++;
    } while (--count);
}

/*
 * The result local is never initialised on the not-found path (the
 * original returns whatever stack slot it had).
 */
Mmdl *func_0216CEE4(MmdlSys *sys, const MmdlHeader *header, int zoneId, int count, void *evWork, u32 objId)
{
    Mmdl *mmdl;
    do {
        if (func_0216E418(header) == 0 && header->objId == objId && func_0216E42C(evWork, header->eventFlag) == 0) {
            mmdl = func_0216CDC4(sys, header, zoneId, evWork);
            break;
        }
        header++;
    } while (--count);
    return mmdl;
}

void func_0216CF2C(Mmdl *mmdl)
{
    if (func_0216D948(func_0216D67C(mmdl)) == 1)
        func_0216D76C(mmdl);
    if (func_0216D55C(mmdl, MMDL_STABIT_MOVE_INIT) != 0) {
        func_0216D71C(mmdl);
        func_0216DFAC(mmdl);
    }
    func_0216D508(mmdl->mmdlSys);
    func_0216E180(mmdl);
}

void func_0216CF6C(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;
    u32 moveInit = MMDL_STABIT_MOVE_INIT;
    iter = 0;
    while (func_0216DD1C(sys, &mmdl, &iter)) {
        if (func_0216D948(sys) == 1)
            func_0216D76C(mmdl);
        func_0216D55C(mmdl, moveInit);
        func_0216D508(mmdl->mmdlSys);
        func_0216E180(mmdl);
    }
}

void func_0216CFC4(Mmdl *mmdl, const MmdlHeader *header)
{
    func_0216D584(mmdl, header->objId);
    func_0216D59C(mmdl, header->moveCode);
    func_0216D5A4(mmdl, header->eventType);
    func_0216D5AC(mmdl, header->eventFlag);
    func_0216D5B4(mmdl, header->eventId);
    mmdl->dirHeader = header->dirHeader;
    mmdl->dirMove = header->dirHeader;
    func_0216D620(mmdl, header->param0, 0);
    func_0216D620(mmdl, header->param1, 1);
    func_0216D620(mmdl, header->param2, 2);
    func_0216D65C(mmdl, header->moveLimitX);
    func_0216D668(mmdl, header->moveLimitZ);
}

void func_0216D02C(Mmdl *mmdl, const MmdlHeader *header)
{
    if (header->posType == 0)
        func_0216D0F8(mmdl, header);
    else
        func_021642F8(mmdl);
}

void func_0216D040(Mmdl *mmdl, const MmdlHeader *header, void *evWork, MmdlSys *sys)
{
    u32 objCode;
    const MmdlObjCodeParam *param;
    func_0216CFC4(mmdl, header);
    objCode = func_0216E3D8(evWork, header->objCode);
    func_0216D594(mmdl, objCode);
    func_0216E39C(sys, objCode, mmdl);
    param = &mmdl->objCodeParam;
    if (objCode == 0xb9) {
        mmdl->sizeWidth = header->param0;
        mmdl->sizeDepth = header->param1;
        if (mmdl->sizeWidth == 0)
            mmdl->sizeWidth += 1;
        if (mmdl->sizeDepth == 0)
            mmdl->sizeDepth += 1;
    } else {
        mmdl->sizeWidth = param->sizeWidth;
        mmdl->sizeDepth = param->sizeDepth;
    }
    mmdl->offsetX = param->offsetX;
    mmdl->offsetY = param->offsetY;
    mmdl->offsetZ = param->offsetZ;
    func_0216D02C(mmdl, header);
}

void func_0216D0E8(Mmdl *mmdl, const MmdlHeader *header, int unused)
{
    if (header->posType == 1)
        func_02164304(mmdl, header);
}

#pragma opt_propagation off

/*
 * The last argument of func_0216D7F4 is a named int local set from the
 * field just before the call, with opt_propagation off around the
 * function. With propagation on the local is folded into the call and the
 * model copy is born before the argument chain (chain in r1); with it off
 * the chain is born first and takes r0, as in the image.
 */
void func_0216D0F8(Mmdl *mmdl, const MmdlHeader *header)
{
    const MmdlHeaderGridPos *gridPos = (const MmdlHeaderGridPos *)header->pos;
    MmdlVec pos;
    s32 gridX;
    s32 gridZ;
    s32 posY;
    if (func_0216E51C(mmdl, (int)header) == 0) {
        gridX = gridPos->gridX;
        gridZ = gridPos->gridZ;
        posY = gridPos->posY;
    } else {
        func_0216E544(mmdl, &pos);
        gridX = (pos.x >> 4) / 4096;
        gridZ = (pos.z >> 4) / 4096;
        posY = pos.y;
    }
    pos.x = (gridX << 16) + 0x8000;
    func_0216D7F0(mmdl, gridPos->gridX);
    func_0216D80C(mmdl, gridX);
    func_0216D844(mmdl, gridX);
    {
        int gridInitY = (gridPos->posY >> 4) / 4096;
        func_0216D7F4(mmdl, gridInitY);
    }
    pos.y = posY;
    gridX = (posY >> 4) / 4096;
    func_0216D818(mmdl, gridX);
    func_0216D85C(mmdl, (s16)gridX);
    pos.z = (gridZ << 16) + 0x8000;
    func_0216D800(mmdl, gridPos->gridZ);
    func_0216D824(mmdl, gridZ);
    func_0216D874(mmdl, (s16)gridZ);
    func_0216D89C(mmdl, &pos);
}

#pragma opt_propagation reset

void func_0216D1C8(Mmdl *mmdl, MmdlSys *sys, int zoneId)
{
    mmdl->mmdlSys = sys;
    func_0216D58C(mmdl, zoneId);
    func_0216D548(mmdl, MMDL_STABIT_USE);
    func_0216D568(mmdl, MMDL_MOVEBIT_ATTR_GET_ERROR | MMDL_MOVEBIT_HEIGHT_GET_ERROR);
    if (func_0216D5BC(mmdl) == 1)
        func_0216DB98(mmdl, 1);
    func_0216D4B4(mmdl);
}

void func_0216D208(Mmdl *mmdl)
{
    func_0216D5D8(mmdl, (u16)func_0216D5D4(mmdl));
    func_0216D600(mmdl, (u16)func_0216D5D4(mmdl));
}

void func_0216D230(Mmdl *mmdl)
{
    mmdl->moveProcList = func_0216E400(func_0216D5A0(mmdl));
}

void func_0216D244(MmdlSys *sys, Mmdl *mmdl)
{
    func_0216D230(mmdl);
    func_0216DF64(mmdl, sys);
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_START | MMDL_MOVEBIT_ATTR_GET_ERROR | MMDL_MOVEBIT_HEIGHT_GET_ERROR);
}

void func_0216D268(MmdlSys *sys, Mmdl *mmdl)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_RAIL_MOVE) == 0)
        func_02163010(mmdl);
    else
        func_0219D6B8(mmdl);
}

void func_0216D28C(Mmdl *mmdl)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_RAIL_MOVE) == 0)
        func_02163028(mmdl);
    else
        func_0219D6CC(mmdl);
}

void func_0216D2AC(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;
    u32 pushBits = MMDL_MOVEBIT_MOVE_PUSH | MMDL_MOVEBIT_DRAW_PUSH;

    iter = 0;
    if (func_0216D948(sys)) {
        while (func_0216DD1C(sys, &mmdl, &iter) == 1) {
            func_0216DFAC(mmdl);
            func_0216D780(mmdl);
            func_0216D568(mmdl, pushBits);
        }
    }
}

void func_0216D2F8(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;
    u32 movePush = MMDL_MOVEBIT_MOVE_PUSH;
    u32 drawPush = MMDL_MOVEBIT_DRAW_PUSH;
    u32 moveInit = MMDL_STABIT_MOVE_INIT;

    iter = 0;
    if (func_0216DD1C(sys, &mmdl, &iter) == 1) {
        do {
            func_0216D244(sys, mmdl);
            if (func_0216D55C(mmdl, moveInit) == 0)
                func_0216D268(sys, mmdl);
            if (func_0216D57C(mmdl, movePush)) {
                func_0216D730(mmdl);
                func_0216D570(mmdl, movePush);
            }
            if (func_0216DAA0(mmdl) == 0)
                func_0216E114(mmdl);
            if (func_0216D57C(mmdl, drawPush)) {
                func_0216D794(mmdl);
                func_0216D570(mmdl, drawPush);
            }
            func_0216E174(mmdl);
        } while (func_0216DD1C(sys, &mmdl, &iter) == 1);
    }
}

void func_0216D38C(Mmdl *mmdl)
{
    func_0216D28C(mmdl);
    if (func_0216DA30(mmdl) == 1)
        func_0216D3B4(mmdl);
}

/*
 * Move task procedure (added by func_0216DF64): the task work is the model.
 */
void func_0216D3A8(void *tcb, void *work)
{
    func_0216D38C(work);
}

void func_0216D3B4(Mmdl *mmdl)
{
    if (func_0216D948(func_0216D67C(mmdl)) == 1)
        func_02197C78(mmdl);
}

int func_0216D3CC(Mmdl *mmdl)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_USE) == 0)
        return 0;
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_MOVE))
        return 0;
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_ACMD) && func_0216D57C(mmdl, MMDL_MOVEBIT_ACMD_END) == 0)
        return 0;
    return 1;
}

void func_0216D410(Mmdl *mmdl, u16 code)
{
    func_0216D7C0(mmdl, code);
    func_0216D7C8(mmdl, 0);
    func_0216D568(mmdl, MMDL_MOVEBIT_ACMD);
    func_0216D570(mmdl, MMDL_MOVEBIT_ACMD_END);
}

void func_0216D438(Mmdl *mmdl, u16 code)
{
    func_0216D7C0(mmdl, code);
    func_0216D7C8(mmdl, 0);
    func_0216D570(mmdl, MMDL_MOVEBIT_ACMD_END);
}

int func_0216D454(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_ACMD) == 0)
        return 1;
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_ACMD_END))
        return 1;
    return 0;
}

int func_0216D480(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_ACMD) == 0)
        return 1;
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_ACMD_END) == 0)
        return 0;
    func_0216D570(mmdl, MMDL_MOVEBIT_ACMD | MMDL_MOVEBIT_ACMD_END);
    return 1;
}

void func_0216D4B4(Mmdl *mmdl)
{
    func_0216D570(mmdl, MMDL_MOVEBIT_ACMD | MMDL_MOVEBIT_ACMD_END);
    func_0216D7C0(mmdl, 0xff);
    func_0216D7C8(mmdl, 0);
}

u32 func_0216D4D4(MmdlSys *sys, u32 bit)
{
    return sys->statusBit & bit;
}

void func_0216D4DC(MmdlSys *sys, u32 bit)
{
    sys->statusBit |= bit;
}

void func_0216D4E4(MmdlSys *sys, u32 bit)
{
    sys->statusBit &= ~bit;
}

u16 func_0216D4F0(const MmdlSys *sys)
{
    return sys->mmdlMax;
}

u16 func_0216D4F4(MmdlSys *sys)
{
    return sys->tcbPriority;
}

u32 func_0216D4F8(MmdlSys *sys)
{
    return sys->heapId;
}

void func_0216D4FC(MmdlSys *sys)
{
    sys->mmdlCount++;
}

void func_0216D508(MmdlSys *sys)
{
    sys->mmdlCount--;
}

void *func_0216D514(MmdlSys *sys)
{
    return sys->tcbSys;
}

void *func_0216D518(MmdlSys *sys)
{
    return sys->resArcHandle;
}

void func_0216D51C(MmdlSys *sys, void *blActCont)
{
    sys->blActCont = blActCont;
}

void *func_0216D520(MmdlSys *sys)
{
    return sys->blActCont;
}

void func_0216D524(MmdlSys *sys, void *g3dObjCont)
{
    sys->g3dObjCont = g3dObjCont;
}

void *func_0216D528(MmdlSys *sys)
{
    return sys->g3dObjCont;
}

void *func_0216D52C(MmdlSys *sys)
{
    return sys->g3dMapper;
}

void *func_0216D530(MmdlSys *sys)
{
    return sys->nogridMapper;
}

void *func_0216D534(MmdlSys *sys)
{
    return sys->fieldMap;
}

u32 func_0216D538(MmdlSys *sys)
{
    const u16 *areaId = sys->areaIdRef;
    if (areaId != 0)
        return *areaId;
    return 0;
}

void func_0216D548(Mmdl *mmdl, u32 bit)
{
    mmdl->statusBit |= bit;
}

void func_0216D550(Mmdl *mmdl, u32 bit)
{
    mmdl->statusBit &= ~bit;
}

u32 func_0216D55C(Mmdl *mmdl, u32 bit)
{
    return mmdl->statusBit & bit;
}

u32 func_0216D564(Mmdl *mmdl)
{
    return mmdl->moveBit;
}

void func_0216D568(Mmdl *mmdl, u32 bit)
{
    mmdl->moveBit |= bit;
}

void func_0216D570(Mmdl *mmdl, u32 bit)
{
    mmdl->moveBit &= ~bit;
}

u32 func_0216D57C(Mmdl *mmdl, u32 bit)
{
    return mmdl->moveBit & bit;
}

void func_0216D584(Mmdl *mmdl, u16 objId)
{
    mmdl->objId = objId;
}

u16 func_0216D588(Mmdl *mmdl)
{
    return mmdl->objId;
}

void func_0216D58C(Mmdl *mmdl, u16 zoneId)
{
    mmdl->zoneId = zoneId;
}

u16 func_0216D590(Mmdl *mmdl)
{
    return mmdl->zoneId;
}

void func_0216D594(Mmdl *mmdl, u32 objCode)
{
    mmdl->objCode = objCode;
}

u16 func_0216D598(Mmdl *mmdl)
{
    return mmdl->objCode;
}

void func_0216D59C(Mmdl *mmdl, u16 moveCode)
{
    mmdl->moveCode = moveCode;
}

u16 func_0216D5A0(Mmdl *mmdl)
{
    return mmdl->moveCode;
}

void func_0216D5A4(Mmdl *mmdl, u16 eventType)
{
    mmdl->eventType = eventType;
}

u16 func_0216D5A8(Mmdl *mmdl)
{
    return mmdl->eventType;
}

void func_0216D5AC(Mmdl *mmdl, u16 eventFlag)
{
    mmdl->eventFlag = eventFlag;
}

u16 func_0216D5B0(Mmdl *mmdl)
{
    return mmdl->eventFlag;
}

void func_0216D5B4(Mmdl *mmdl, u16 eventId)
{
    mmdl->eventId = eventId;
}

u32 func_0216D5B8(Mmdl *mmdl)
{
    return mmdl->eventId;
}

int func_0216D5BC(Mmdl *mmdl)
{
    return func_0216D5B8(mmdl) == 0xFFFF;
}

int func_0216D5D4(Mmdl *mmdl)
{
    return mmdl->dirHeader;
}

void func_0216D5D8(Mmdl *mmdl, int dir)
{
    mmdl->dirDispOld = mmdl->dirDisp;
    mmdl->dirDisp = dir;
}

void func_0216D5E0(Mmdl *mmdl, int dir)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_PAUSE_DIR) == 0) {
        mmdl->dirDispOld = mmdl->dirDisp;
        mmdl->dirDisp = dir;
    }
}

u16 func_0216D5F8(Mmdl *mmdl)
{
    return mmdl->dirDisp;
}

u16 func_0216D5FC(Mmdl *mmdl)
{
    return mmdl->dirDispOld;
}

void func_0216D600(Mmdl *mmdl, int dir)
{
    mmdl->dirMoveOld = mmdl->dirMove;
    mmdl->dirMove = dir;
}

u16 func_0216D608(Mmdl *mmdl)
{
    return mmdl->dirMove;
}

void func_0216D60C(Mmdl *mmdl, int dir)
{
    func_0216D5E0(mmdl, dir);
    func_0216D600(mmdl, dir);
}

void func_0216D620(Mmdl *mmdl, int param, int no)
{
    switch (no) {
    case 0:
        mmdl->param0 = param;
        break;
    case 1:
        mmdl->param1 = param;
        break;
    case 2:
        mmdl->param2 = param;
        break;
    }
}

int func_0216D63C(Mmdl *mmdl, int no)
{
    switch (no) {
    case 0:
        return mmdl->param0;
    case 1:
        return mmdl->param1;
    case 2:
        return mmdl->param2;
    default:
        return 0;
    }
}

void func_0216D65C(Mmdl *mmdl, short limit)
{
    mmdl->moveLimitX = limit;
}

int func_0216D660(Mmdl *mmdl)
{
    return mmdl->moveLimitX;
}

void func_0216D668(Mmdl *mmdl, short limit)
{
    mmdl->moveLimitZ = limit;
}

int func_0216D66C(Mmdl *mmdl)
{
    return mmdl->moveLimitZ;
}

void func_0216D674(Mmdl *mmdl, u16 drawStatus)
{
    mmdl->drawStatus = drawStatus;
}

u16 func_0216D678(Mmdl *mmdl)
{
    return mmdl->drawStatus;
}

MmdlSys *func_0216D67C(Mmdl *mmdl)
{
    return mmdl->mmdlSys;
}

void *func_0216D684(Mmdl *mmdl, int size)
{
    void *work = func_0216D69C(mmdl);
    MI_CpuFill8(work, 0, size);
    return work;
}

void *func_0216D69C(Mmdl *mmdl)
{
    return mmdl->moveProcWork;
}

void *func_0216D6A0(Mmdl *mmdl, int size)
{
    void *work = func_0216D6B8(mmdl);
    MI_CpuFill8(work, 0, size);
    return work;
}

void *func_0216D6B8(Mmdl *mmdl)
{
    return mmdl->moveSubProcWork;
}

void *func_0216D6BC(Mmdl *mmdl, int size)
{
    void *work = func_0216D6D4(mmdl);
    MI_CpuFill8(work, 0, size);
    return work;
}

void *func_0216D6D4(Mmdl *mmdl)
{
    return mmdl->moveCmdWork;
}

void *func_0216D6D8(Mmdl *mmdl, int size)
{
    void *work = func_0216D6F0(mmdl);
    MI_CpuFill8(work, 0, size);
    return work;
}

void *func_0216D6F0(Mmdl *mmdl)
{
    return mmdl->drawProcWork;
}

void func_0216D6F4(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->moveProcList->init;
    if (proc != 0)
        proc(mmdl);
}

void func_0216D708(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->moveProcList->move;
    if (proc != 0)
        proc(mmdl);
}

void func_0216D71C(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->moveProcList->remove;
    if (proc != 0)
        proc(mmdl);
}

void func_0216D730(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->moveProcList->recover;
    if (proc != 0)
        proc(mmdl);
}

void func_0216D744(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->init;
    if (proc != 0)
        proc(mmdl);
}

void func_0216D758(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->draw;
    if (proc != 0)
        proc(mmdl);
}

void func_0216D76C(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->remove;
    if (proc != 0)
        proc(mmdl);
}

void func_0216D780(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->push;
    if (proc != 0)
        proc(mmdl);
}

void func_0216D794(Mmdl *mmdl)
{
    void (*proc)(Mmdl *) = mmdl->drawProcList->pop;
    if (proc != 0)
        proc(mmdl);
}

int func_0216D7A8(Mmdl *mmdl, unsigned int kind)
{
    int (*proc)(Mmdl *, unsigned int);
    proc = mmdl->drawProcList->getParam;
    if (proc != 0)
        return proc(mmdl, kind);
    return 0;
}

void func_0216D7C0(Mmdl *mmdl, u16 code)
{
    mmdl->acmdCode = code;
}

u16 func_0216D7C4(Mmdl *mmdl)
{
    return mmdl->acmdCode;
}

void func_0216D7C8(Mmdl *mmdl, u16 seq)
{
    mmdl->acmdSeq = seq;
}

void func_0216D7CC(Mmdl *mmdl)
{
    mmdl->acmdSeq = mmdl->acmdSeq + 1;
}

u16 func_0216D7D4(Mmdl *mmdl)
{
    return mmdl->acmdSeq;
}

void func_0216D7D8(Mmdl *mmdl, u32 attr)
{
    mmdl->nowAttr = attr;
}

u32 func_0216D7DC(Mmdl *mmdl)
{
    return mmdl->nowAttr;
}

void func_0216D7E0(Mmdl *mmdl, u32 attr)
{
    mmdl->oldAttr = attr;
}

u32 func_0216D7E4(Mmdl *mmdl)
{
    return mmdl->oldAttr;
}

int func_0216D7E8(Mmdl *mmdl)
{
    return mmdl->gridInitX;
}

void func_0216D7F0(Mmdl *mmdl, short x)
{
    mmdl->gridInitX = x;
}

void func_0216D7F4(Mmdl *mmdl, short y)
{
    mmdl->gridInitY = y;
}

int func_0216D7F8(Mmdl *mmdl)
{
    return mmdl->gridInitZ;
}

void func_0216D800(Mmdl *mmdl, short z)
{
    mmdl->gridInitZ = z;
}

int func_0216D804(Mmdl *mmdl)
{
    return mmdl->gridOldX;
}

void func_0216D80C(Mmdl *mmdl, s16 x)
{
    mmdl->gridOldX = x;
}

int func_0216D810(Mmdl *mmdl)
{
    return mmdl->gridOldY;
}

void func_0216D818(Mmdl *mmdl, s16 y)
{
    mmdl->gridOldY = y;
}

int func_0216D81C(Mmdl *mmdl)
{
    return mmdl->gridOldZ;
}

void func_0216D824(Mmdl *mmdl, s16 z)
{
    mmdl->gridOldZ = z;
}

void func_0216D828(Mmdl *mmdl, MmdlGridVec *out)
{
    out->x = mmdl->gridNowX;
    out->y = mmdl->gridNowY;
    out->z = mmdl->gridNowZ;
}

int func_0216D83C(Mmdl *mmdl)
{
    return mmdl->gridNowX;
}

void func_0216D844(Mmdl *mmdl, short x)
{
    mmdl->gridNowX = x;
}

void func_0216D848(Mmdl *mmdl, short dx)
{
    mmdl->gridNowX += dx;
}

int func_0216D854(Mmdl *mmdl)
{
    return mmdl->gridNowY;
}

void func_0216D85C(Mmdl *mmdl, int y)
{
    mmdl->gridNowY = y;
}

void func_0216D860(Mmdl *mmdl, short dy)
{
    mmdl->gridNowY += dy;
}

int func_0216D86C(Mmdl *mmdl)
{
    return mmdl->gridNowZ;
}

void func_0216D874(Mmdl *mmdl, int z)
{
    mmdl->gridNowZ = z;
}

void func_0216D87C(Mmdl *mmdl, short dz)
{
    mmdl->gridNowZ += dz;
}

MmdlVec *func_0216D888(Mmdl *mmdl)
{
    return &mmdl->pos;
}

void func_0216D88C(const Mmdl *mmdl, MmdlVec *out)
{
    *out = mmdl->pos;
}

void func_0216D89C(Mmdl *mmdl, const MmdlVec *pos)
{
    mmdl->pos = *pos;
}

s32 func_0216D8AC(Mmdl *mmdl)
{
    return mmdl->pos.y;
}

void func_0216D8B0(Mmdl *mmdl, MmdlVec *out)
{
    *out = mmdl->drawOffset;
}

void func_0216D8C0(Mmdl *mmdl, const MmdlVec *offset)
{
    mmdl->drawOffset = *offset;
}

void func_0216D8D0(Mmdl *mmdl, MmdlVec *out)
{
    *out = mmdl->drawOffsetOutside;
}

void func_0216D8E0(Mmdl *mmdl, const MmdlVec *offset)
{
    mmdl->drawOffsetOutside = *offset;
}

void func_0216D8F0(Mmdl *mmdl, MmdlVec *out)
{
    *out = mmdl->attrOffset;
}

void func_0216D900(Mmdl *mmdl, const MmdlVec *offset)
{
    mmdl->attrOffset = *offset;
}

void *func_0216D910(Mmdl *mmdl)
{
    return func_0216D520(func_0216D67C(mmdl));
}

u8 func_0216D91C(Mmdl *mmdl)
{
    return mmdl->sizeWidth;
}

u8 func_0216D924(Mmdl *mmdl)
{
    return mmdl->sizeDepth;
}

void func_0216D92C(Mmdl *mmdl, MmdlVec *offset)
{
    offset->x = mmdl->offsetX << 12;
    offset->y = mmdl->offsetY << 12;
    offset->z = mmdl->offsetZ << 12;
}

int func_0216D948(MmdlSys *sys)
{
    int ret = 1;
    if (func_0216D4D4(sys, MMDLSYS_STABIT_DRAW_INIT) == 0)
        ret = 0;
    return ret;
}

void func_0216D95C(MmdlSys *sys, int flag)
{
    if (flag == 1)
        func_0216D4DC(sys, MMDLSYS_STABIT_DRAW_INIT);
    else
        func_0216D4E4(sys, MMDLSYS_STABIT_DRAW_INIT);
}

void func_0216D974(MmdlSys *sys, int flag)
{
    if (flag == 0)
        func_0216D4DC(sys, MMDLSYS_STABIT_DRAW_OFF);
    else
        func_0216D4E4(sys, MMDLSYS_STABIT_DRAW_OFF);
}

int func_0216D98C(MmdlSys *sys)
{
    if (func_0216D4D4(sys, MMDLSYS_STABIT_DRAW_OFF) == 0)
        return 1;
    return 0;
}

void func_0216D9A0(MmdlSys *sys)
{
    u32 iter = 0;
    Mmdl *mmdl;

    while (func_0216DD1C(sys, &mmdl, &iter) == 1) {
        if (func_0216DC80(mmdl) == 0)
            func_0216DAF8(mmdl);
    }
    func_0216D4DC(sys, MMDLSYS_STABIT_MOVE_PAUSE);
}

void func_0216D9E4(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;

    iter = 0;
    while (func_0216DD1C(sys, &mmdl, &iter) == 1)
        func_0216DB04(mmdl);
    func_0216D4E4(sys, MMDLSYS_STABIT_MOVE_PAUSE);
}

u32 func_0216DA20(Mmdl *mmdl, u32 bit)
{
    return func_0216D4D4(func_0216D67C(mmdl), bit);
}

int func_0216DA30(Mmdl *mmdl)
{
    int ret = 1;
    if (func_0216D55C(mmdl, MMDL_STABIT_USE) == 0)
        ret = 0;
    return ret;
}

void func_0216DA44(Mmdl *mmdl)
{
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE);
}

void func_0216DA50(Mmdl *mmdl)
{
    func_0216D570(mmdl, MMDL_MOVEBIT_MOVE);
}

int func_0216DA5C(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_MOVE))
        return 1;
    return 0;
}

void func_0216DA70(Mmdl *mmdl)
{
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_START);
}

void func_0216DA7C(Mmdl *mmdl)
{
    func_0216D570(mmdl, MMDL_MOVEBIT_MOVE_END);
}

void func_0216DA88(Mmdl *mmdl)
{
    func_0216D568(mmdl, MMDL_MOVEBIT_DRAW_INIT_COMP);
}

void func_0216DA94(Mmdl *mmdl)
{
    func_0216D570(mmdl, MMDL_MOVEBIT_DRAW_INIT_COMP);
}

int func_0216DAA0(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_DRAW_INIT_COMP))
        return 1;
    return 0;
}

int func_0216DAB4(Mmdl *mmdl)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_VANISH))
        return 1;
    return 0;
}

void func_0216DAC8(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D548(mmdl, MMDL_STABIT_VANISH);
    else
        func_0216D550(mmdl, MMDL_STABIT_VANISH);
}

void func_0216DAE0(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D550(mmdl, MMDL_STABIT_FELLOW_HIT_OFF);
    else
        func_0216D548(mmdl, MMDL_STABIT_FELLOW_HIT_OFF);
}

void func_0216DAF8(Mmdl *mmdl)
{
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_PAUSE);
}

void func_0216DB04(Mmdl *mmdl)
{
    func_0216D570(mmdl, MMDL_MOVEBIT_MOVE_PAUSE);
}

int func_0216DB10(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_MOVE_PAUSE))
        return 1;
    return 0;
}

int func_0216DB24(Mmdl *mmdl)
{
    if (func_0216D948(func_0216D67C(mmdl)) == 0)
        return 0;
    if (func_0216DAA0(mmdl))
        return 1;
    return 0;
}

void func_0216DB4C(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D548(mmdl, MMDL_STABIT_HEIGHT_GET_OFF);
    else
        func_0216D550(mmdl, MMDL_STABIT_HEIGHT_GET_OFF);
}

int func_0216DB68(Mmdl *mmdl)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_HEIGHT_GET_OFF))
        return 1;
    return 0;
}

void func_0216DB80(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D548(mmdl, MMDL_STABIT_ZONE_DEL_OFF);
    else
        func_0216D550(mmdl, MMDL_STABIT_ZONE_DEL_OFF);
}

void func_0216DB98(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D548(mmdl, MMDL_STABIT_ALIAS);
    else
        func_0216D550(mmdl, MMDL_STABIT_ALIAS);
}

int func_0216DBB4(Mmdl *mmdl)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_ALIAS))
        return 1;
    return 0;
}

void func_0216DBCC(Mmdl *mmdl, u32 flag)
{
    if (flag == 1)
        func_0216D568(mmdl, MMDL_MOVEBIT_SPLASH_SET);
    else
        func_0216D570(mmdl, MMDL_MOVEBIT_SPLASH_SET);
}

int func_0216DBE8(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_SPLASH_SET))
        return 1;
    return 0;
}

int func_0216DC00(Mmdl *mmdl)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_ATTR_OFFSET_OFF))
        return 1;
    return 0;
}

void func_0216DC18(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D568(mmdl, MMDL_MOVEBIT_REFLECT_SET);
    else
        func_0216D570(mmdl, MMDL_MOVEBIT_REFLECT_SET);
}

int func_0216DC34(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_REFLECT_SET))
        return 1;
    return 0;
}

int func_0216DC4C(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_ACMD))
        return 1;
    return 0;
}

void func_0216DC64(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D568(mmdl, MMDL_MOVEBIT_SYS_PAUSE_OFF);
    else
        func_0216D570(mmdl, MMDL_MOVEBIT_SYS_PAUSE_OFF);
}

int func_0216DC80(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_SYS_PAUSE_OFF))
        return 1;
    return 0;
}

void func_0216DC98(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D548(mmdl, MMDL_STABIT_ATTR_GET_OFF);
    else
        func_0216D550(mmdl, MMDL_STABIT_ATTR_GET_OFF);
}

int func_0216DCB4(Mmdl *mmdl)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_ATTR_GET_OFF))
        return 1;
    return 0;
}

void func_0216DCCC(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D568(mmdl, MMDL_MOVEBIT_ATTR_EFFECT_OFF);
    else
        func_0216D570(mmdl, MMDL_MOVEBIT_ATTR_EFFECT_OFF);
}

void func_0216DCE8(Mmdl *mmdl, int flag)
{
    if (flag == 1)
        func_0216D568(mmdl, MMDL_MOVEBIT_SHADOW_VANISH);
    else
        func_0216D570(mmdl, MMDL_MOVEBIT_SHADOW_VANISH);
}

int func_0216DD04(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_SHADOW_VANISH))
        return 1;
    return 0;
}

/*
 * Iterator over the models in use: advances *iter and returns TRUE with
 * *out set at the next model whose use bit is on.
 */
int func_0216DD1C(const MmdlSys *sys, Mmdl **out, u32 *iter)
{
    u32 max;
    Mmdl *mmdl;

    max = func_0216D4F0(sys);
    if (*iter < max) {
        mmdl = &sys->mmdlBuf[*iter];
        do {
            (*iter)++;
            if (func_0216D55C(mmdl, MMDL_STABIT_USE)) {
                *out = mmdl;
                return 1;
            }
            mmdl++;
        } while (*iter < max);
    }
    return 0;
}

/*
 * Collects up to 16 models on the grid position into a 0x44-byte result
 * block (count word, then the pointers).
 */
int func_0216DD60(MmdlSys *sys, u32 gridX, u32 gridZ, u32 flag, MmdlSearchList *out)
{
    u32 iter;
    Mmdl *mmdl;

    iter = 0;
    MI_CpuFill8(out, 0, sizeof(MmdlSearchList));
    while (func_0216DD1C(sys, &mmdl, &iter) == 1) {
        if (func_02163C04(mmdl, gridX, gridZ, flag) == 1) {
            int i = out->count++;
            out->mmdl[i] = mmdl;
            if (out->count >= 16)
                break;
        }
    }
    return out->count;
}

Mmdl *func_0216DDC0(MmdlSys *sys, u32 gridX, u32 gridZ, u32 flag)
{
    MmdlSearchList list;
    if (func_0216DD60(sys, gridX, gridZ, flag, &list) != 0)
        return list.mmdl[0];
    return 0;
}

Mmdl *func_0216DDDC(MmdlSys *sys, u32 gridX, u32 gridZ, s32 posY, s32 range, u32 flag)
{
    MmdlSearchList list;
    u32 i;
    u32 count;

    count = func_0216DD60(sys, gridX, gridZ, flag, &list);
    if (count == 0)
        return 0;
    for (i = 0; i < count; i++) {
        s32 diff = func_0216D8AC(list.mmdl[i]) - posY;

        if (diff < 0)
            diff = (s32)(((s64)diff * (s64)(s32)0xFFFFF000 + 0x800) >> 12);
        if (diff < range)
            return list.mmdl[i];
    }
    return 0;
}

Mmdl *func_0216DE54(MmdlSys *sys, u32 moveCode)
{
    u32 iter;
    Mmdl *mmdl;

    iter = 0;
    while (func_0216DD1C(sys, &mmdl, &iter) == 1) {
        if (func_0216D5A0(mmdl) == moveCode)
            return mmdl;
    }
    return 0;
}

Mmdl *func_0216DE94(MmdlSys *sys, u32 objId)
{
    u32 iter;
    Mmdl *mmdl;

    iter = 0;
    while (func_0216DD1C(sys, &mmdl, &iter) == 1) {
        if (func_0216DBB4(mmdl) == 0 && func_0216D588(mmdl) == objId)
            return mmdl;
    }
    return 0;
}

Mmdl *func_0216DEE0(MmdlSys *sys)
{
    return func_0216DE94(sys, 0xff);
}

Mmdl *func_0216DEEC(MmdlSys *sys)
{
    int i = 0;
    int max = func_0216D4F0(sys);
    Mmdl *mmdl = sys->mmdlBuf;

    do {
        if (func_0216D55C(mmdl, MMDL_STABIT_USE) == 0)
            return mmdl;
        i++;
        mmdl++;
    } while (i < max);
    return 0;
}

void func_0216DF1C(MmdlSys *sys)
{
    u32 iter;
    Mmdl *mmdl;
    u32 zoneDelOff = MMDL_STABIT_ZONE_DEL_OFF;

    iter = 0;
    while (func_0216DD1C(sys, &mmdl, &iter)) {
        if (func_0216D55C(mmdl, zoneDelOff) == 0) {
            func_0216D588(mmdl);
            func_0216CF2C(mmdl);
        }
    }
}

void func_0216DF64(Mmdl *mmdl, MmdlSys *sys)
{
    int offset = 0;
    int priority = func_0216D4F4(sys);
    int moveCode = func_0216D5A0(mmdl);

    if (moveCode == 0x30 || moveCode == 0x32)
        offset = 1;
    else if (func_0216D588(mmdl) == 0xff)
        offset--;
    mmdl->moveTcb = func_02030DA8(func_0216D514(sys), func_0216D3A8, mmdl, priority + offset);
}

void func_0216DFAC(Mmdl *mmdl)
{
    if (mmdl->moveTcb != 0) {
        func_02030EAC(mmdl->moveTcb);
        mmdl->moveTcb = 0;
    }
}

int func_0216DFC4(Mmdl *mmdl, u32 objCode)
{
    u32 iter = 0;
    Mmdl *other;
    MmdlSys *sys;

    sys = func_0216D67C(mmdl);
    while (func_0216DD1C(sys, &other, &iter) == 1) {
        if (other != mmdl) {
            u32 code = func_0216D598(other);
            if (code != 0xFFFF && code == objCode)
                return 1;
        }
    }
    return 0;
}

void func_0216E014(Mmdl *mmdl, const MmdlVec *pos, int dir)
{
    func_0216D844(mmdl, (s16)((pos->x >> 4) / 4096));
    func_0216D85C(mmdl, (s16)((pos->y >> 4) / 4096));
    func_0216D874(mmdl, (s16)((pos->z >> 4) / 4096));
    func_0216D89C(mmdl, pos);
    func_02163F10(mmdl);
    func_0216D5D8(mmdl, dir);
    func_0216D4B4(mmdl);
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_START);
    func_0216D570(mmdl, MMDL_MOVEBIT_MOVE | MMDL_MOVEBIT_MOVE_END);
}

void func_0216E084(Mmdl *mmdl, unsigned int gridX, unsigned int y, unsigned int gridZ, u16 dir)
{
    MmdlVec pos;
    pos.x = (gridX << 16) + 0x8000;
    pos.y = y << 16;
    pos.z = (gridZ << 16) + 0x8000;
    func_0216E014(mmdl, &pos, dir);
}

void func_0216E0AC(Mmdl *mmdl, const MmdlHeader *header)
{
    MmdlSys *sys = func_0216D67C(mmdl);
    func_0216D71C(mmdl);
    func_0216CFC4(mmdl, header);
    func_0216D02C(mmdl, header);
    func_0216D230(mmdl);
    func_0216D268(sys, mmdl);
    func_0216D0E8(mmdl, header, 0);
}

void func_0216E0E8(Mmdl *mmdl, u16 moveCode)
{
    MmdlSys *sys = func_0216D67C(mmdl);
    func_0216D71C(mmdl);
    func_0216D59C(mmdl, moveCode);
    func_0216D230(mmdl);
    func_0216D268(sys, mmdl);
}

void func_0216E114(Mmdl *mmdl)
{
    if (func_0216D948(func_0216D67C(mmdl)) == 0)
        return;
    if (func_0216D57C(mmdl, MMDL_MOVEBIT_HEIGHT_GET_ERROR) != 0)
        func_02164010(mmdl);
    func_0216D674(mmdl, 0);
    if (func_0216DAA0(mmdl) != 0)
        return;
    func_0216E160(mmdl);
    func_0216D744(mmdl);
    func_0216DA88(mmdl);
}

void func_0216E160(Mmdl *mmdl)
{
    mmdl->drawProcList = func_0216E40C(func_0216E3C4(mmdl)->drawProcNo);
}

void func_0216E174(Mmdl *mmdl)
{
    func_0216D570(mmdl, MMDL_MOVEBIT_SHADOW_SET | MMDL_MOVEBIT_SHOAL_SET | MMDL_MOVEBIT_REFLECT_SET | MMDL_MOVEBIT_SPLASH_SET);
}

void func_0216E180(Mmdl *mmdl)
{
    MI_CpuFill8(mmdl, 0, sizeof(Mmdl));
}

void func_0216E190(Mmdl *mmdl)
{
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_START);
    func_0216E174(mmdl);
}

void func_0216E1A4(Mmdl *mmdl, MmdlCheckInfo *info)
{
    info->objId = func_0216D588(mmdl);
    info->objCode = func_0216D598(mmdl);
    info->zoneId = func_0216D590(mmdl);
}

int func_0216E1C4(Mmdl *mmdl, const MmdlCheckInfo *info)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_USE) != 0
        && info->objId == func_0216D588(mmdl)
        && info->objCode == func_0216D598(mmdl)
        && info->zoneId == func_0216D590(mmdl))
        return 1;
    return 0;
}

void func_0216E204(Mmdl *mmdl, u32 objCode)
{
    MmdlSys *sys;
    const MmdlObjCodeParam *param;

    sys = func_0216D67C(mmdl);
    if (func_0216D948(sys) == 1 && func_0216DAA0(mmdl) == 1)
        func_0216D76C(mmdl);
    func_0216D594(mmdl, objCode);
    func_0216E39C(sys, objCode, mmdl);
    param = &mmdl->objCodeParam;
    mmdl->sizeWidth = param->sizeWidth;
    mmdl->sizeDepth = param->sizeDepth;
    mmdl->offsetX = param->offsetX;
    mmdl->offsetY = param->offsetY;
    mmdl->offsetZ = param->offsetZ;
    func_0216DA94(mmdl);
    func_0216E190(mmdl);
    func_0216E114(mmdl);
}

void func_0216E280(MmdlSys *sys, int heapId)
{
    sys->objCodeArcHandle = func_020490F4(0x30, heapId);
}

void func_0216E290(MmdlSys *sys)
{
    func_02049238(sys->objCodeArcHandle);
}

void func_0216E29C(MmdlSys *sys, int member)
{
    func_02048F4C(sys->objCodeParamCache, 0x3a, member);
}

/*
 * The cache holds a count halfword, the object codes (padded to an even
 * count), then one 0x1C-byte parameter record per code.
 */
void func_0216E2AC(MmdlSys *sys, u32 no, MmdlObjCodeParam *out)
{
    u16 *cache = sys->objCodeParamCache;

    if (no < cache[0]) {
        u16 codeSlots = (cache[0] + 1) / 2 * 2;
        MmdlObjCodeParam *params = (MmdlObjCodeParam *)(cache + (codeSlots + 2));

        *out = params[no];
    }
}

u16 func_0216E2E0(MmdlSys *sys)
{
    return *sys->objCodeParamCache;
}

/*
 * The 28-byte record assignments keep sys in r5, objCode in r4 and out in
 * r6; the named u16 offset and the const system parameter give the last
 * stack store.
 */
void func_0216E2E8(const MmdlSys *sys, u32 objCode, MmdlObjCodeParam *out)
{
    u16 offset;
    int i;
    u16 count;
    u16 *cache;
    u32 iter;
    Mmdl *mmdl;

    cache = sys->objCodeParamCache;
    count = cache[0];

    if (count < 0x1a) {
        u16 codeSlots = ((count + 1) / 2) * 2;
        MmdlObjCodeParam *params = (MmdlObjCodeParam *)(cache + (codeSlots + 2));
        for (i = 0; i < count; i++) {
            if (objCode == cache[i + 1]) {
                *out = params[i];
                return;
            }
        }
    }
    iter = 0;
    if (func_0216DD1C(sys, &mmdl, &iter)) {
        do {
            if (objCode == func_0216D598(mmdl)) {
                *out = mmdl->objCodeParam;
                return;
            }
        } while (func_0216DD1C(sys, &mmdl, &iter));
    }
    offset = func_0200F128(objCode) * 0x1c + 4;
    func_0204944C(sys->objCodeArcHandle, 0, offset, 0x1c, out);
}

void func_0216E39C(const MmdlSys *sys, u32 objCode, Mmdl *mmdl)
{
    func_0216D550(mmdl, MMDL_STABIT_USE);
    func_0216E2E8(sys, objCode, &mmdl->objCodeParam);
    func_0216D548(mmdl, MMDL_STABIT_USE);
}

MmdlObjCodeParam *func_0216E3C4(Mmdl *mmdl)
{
    return &mmdl->objCodeParam;
}

void *func_0216E3C8(MmdlObjCodeParam *param)
{
    return param->resource;
}

void *func_0216E3CC(MmdlObjCodeParam *param)
{
    return param->resource;
}

u32 func_0216E3D0(void *evWork, u32 objCode)
{
    return func_0216E3D8(evWork, objCode);
}

u32 func_0216E3D8(void *evWork, u32 objCode)
{
    if (objCode >= 162 && objCode <= 177) {
        if (evWork == 0)
            objCode = 10;
        else
            objCode = *func_020143CC(evWork, (u16)(objCode + 0x3f7e));
    }
    return objCode;
}

/*
 * note: un-hinted, sole-ref/data sees several overlays over 0x021D5E04 and
 * refuses.  ov021 is the only one with data there (a pointer table after a
 * zero word at 0x021D5E00); ov093, ov016 and the rest hold code.  ov021 is
 * resident with ov010: ov010 branches straight into 62 ov021 functions
 * (bl 0x021C3400 and others).  The ov021 hint fixes the choice.
 */
const MmdlMoveProcList *func_0216E400(int moveCode)
{
    return d_021D5E04[moveCode];
}

/*
 * note: the parked file gave no overlay hint; un-hinted, sole-ref saw data at
 * 0x021D770C in several overlapping overlays and refused.  ov021 is the
 * pointer-table home of the word (the ov021 datum is 0x021D86C0), so the hint
 * fixes the choice and the site resolves as sole-ref/self.
 */
const MmdlDrawProcList *func_0216E40C(int drawProcNo)
{
    return d_021D770C[drawProcNo];
}

int func_0216E418(const MmdlHeader *header)
{
    if (header->eventId == 0xFFFF)
        return 1;
    return 0;
}

unsigned int func_0216E42C(void *evWork, int flag)
{
    return func_020142E8(evWork, flag);
}

/*
 * Event types 4..8 and 11..13 count as type 1; the others stay as they are.
 */
u32 func_0216E434(u32 eventType)
{
    switch (eventType) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 11:
    case 12:
    case 13:
        return 1;
    }
    return eventType;
}

void func_0216E464(void)
{
}

void func_0216E468(void)
{
}

void func_0216E46C(void)
{
}

void func_0216E470(void)
{
}
