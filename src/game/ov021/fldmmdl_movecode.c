/*
 * file:     fldmmdl_movecode.c
 * unit:     yes
 * function: func_0219A098, func_0219A0CC, func_0219A0D8, func_0219A0E4, func_0219A0F0, func_0219A0FC, func_0219A108, func_0219A114, func_0219A120, func_0219A12C, func_0219A138, func_0219A144, func_0219A150, func_0219A1E8, func_0219A24C, func_0219A250, func_0219A260, func_0219A270, func_0219A280, func_0219A290, func_0219A2B8, func_0219A3D8, func_0219A4CC, func_0219A528, func_0219A54C, func_0219A574, func_0219A580, func_0219A58C, func_0219A598, func_0219A5A4, func_0219A5C8, func_0219A5D4, func_0219A5E0, func_0219A604, func_0219A638, func_0219A660, func_0219A6CC, func_0219A750, func_0219A75C, func_0219A780, func_0219A7A8, func_0219A7C4, func_0219A7DC, func_0219A87C, func_0219A89C, func_0219A8C0, func_0219A900, func_0219AA08, func_0219AA38, func_0219AA68, func_0219AA78, func_0219AA88, func_0219AA98, func_0219AAA8, func_0219AAB8, func_0219AAC8, func_0219AAD8, func_0219AAE8, func_0219AAF8, func_0219AB08, func_0219AB18, func_0219AB28, func_0219AB38, func_0219AB48, func_0219AB58, func_0219AB68, func_0219AB8C, func_0219ACE8, func_0219AD18, func_0219AD48, func_0219AD58, func_0219AD68, func_0219AD78, func_0219AD88, func_0219AD98, func_0219ADA8, func_0219ADB8, func_0219ADC8, func_0219ADEC, func_0219AE10, func_0219AE68, func_0219AEC8, func_0219B030, func_0219B060, func_0219B074, func_0219B0C4, func_0219B0D8, func_0219B0F0, func_0219B104, func_0219B120, func_0219B13C, func_0219B200, func_0219B2E8, func_0219B334, func_0219B358, func_0219B374, func_0219B390, func_0219B404, func_0219B414, func_0219B41C, func_0219B440, func_0219B45C, func_0219B478, func_0219B494, func_0219B4C8, func_0219B4FC, func_0219B500, func_0219B504, func_0219B508, func_0219B520, func_0219B59C, func_0219B6B0, func_0219B6E0, func_0219B75C, func_0219B8A8, func_0219B8BC, func_0219B8E8, func_0219B920, func_0219B924, func_0219B968, func_0219B984, func_0219B9B0, func_0219B9D8, func_0219BA0C, func_0219BA2C, func_0219BA6C, func_0219BAE0, func_0219BB08, func_0219BB38, func_0219BB3C, func_0219BB48, func_0219BB84, func_0219BBA4, func_0219BC48, func_0219BCC0, func_0219BCE4, func_0219BD30, func_0219BDC4, func_0219BE0C, func_0219BE18, func_0219BE24, func_0219BE30, func_0219BE3C, func_0219BE60, func_0219BE70, func_0219BEB4, func_0219BED0, func_0219BF00, func_0219BF3C, func_0219BF48, func_0219BF54, func_0219BF60, func_0219BF7C, func_0219BF88, func_0219BF94, func_0219BFA0, func_0219BFAC, func_0219BFB8, func_0219BFC4, func_0219BFD0, func_0219BFDC, func_0219C000, func_0219C034, func_0219C04C, func_0219C080, func_0219C0AC, func_0219C0D4, func_0219C0E8, func_0219C0F4, func_0219C100, func_0219C10C, func_0219C118, func_0219C13C, func_0219C150, func_0219C164, func_0219C180, func_0219C20C, func_0219C298, func_0219C2BC, func_0219C2E0, func_0219C314, func_0219C338
 * address:  0x0219A098
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from unit_02198D3C.c at 0x0219A098 (lane L138, move code handlers, step tables and helpers; original unknown).
 * Field model move codes: turn in place, random walk, fixed direction, spin, swing, back and forth, route patrol (work areas in fldmmdl_movecode_types.h), and the event type helpers they share.
 * Merged from unit_0219A098.c and unit_0219B508.c, which are one original (model move code file).
 *
 * symbols:
 *   func_02198C08  0x02198C08  thumb
 *   func_02198C4C       0x02198C4C  thumb
 *   DWCca_ghttp_caList  0x021D4A44  data
 *   DWCca_ghttp_caList_b 0x021D4A80  data
 *   DWCca_ghttp_caList_c 0x021D4A9C  data
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02198E44  0x02198E44  thumb
 *   func_02198E60  0x02198E60  thumb
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_020508EC  0x020508EC  arm
 *   func_021D04A4  0x021D04A4  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_021D04C4  0x021D04C4  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021D4C1C     0x021D4C1C  data   a4
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D848  0x0216D848  thumb  ov010
 *   func_0216D860  0x0216D860  thumb  ov010
 *   func_0216D87C  0x0216D87C  thumb  ov010
 *   func_02163F8C  0x02163F8C  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   d_021D4B44     0x021D4B44  data  ov021  a4
 *   d_021D4204     0x021D4204  data  ov021  a4
 *   d_021D4C04     0x021D4C04  data  a4
 *   d_021D41E0     0x021D41E0  data  ov021  a4
 *   d_021D4210     0x021D4210  data  a4
 *   d_021D4C10     0x021D4C10  data  a4
 *   d_021D4648     0x021D4648  data  a4
 *   d_021D4BF8     0x021D4BF8  data  a4
 *   d_021D4BEC     0x021D4BEC  data  a4
 *   d_021D4BE0     0x021D4BE0  data  a4
 *   d_021D4BD4     0x021D4BD4  data  a4
 *   d_021D4BC8     0x021D4BC8  data  a4
 *   d_021D4BBC     0x021D4BBC  data  a4
 *   d_021D4BB0     0x021D4BB0  data  a4
 *   d_021D4BA4     0x021D4BA4  data  a4
 *   d_021D4B98  0x021D4B98  data  a4
 *   d_021D4B8C  0x021D4B8C  data  a4
 *   d_021D4B80  0x021D4B80  data  a4
 *   d_021D4B74  0x021D4B74  data  a4
 *   d_021D4B68  0x021D4B68  data  a4
 *   d_021D4B5C  0x021D4B5C  data  a4
 *   d_021D4B50  0x021D4B50  data  a4
 *   d_021D45E8  0x021D45E8  data  a4
 *   d_021D4B38  0x021D4B38  data  a4
 *   d_021D4B2C  0x021D4B2C  data  a4
 *   d_021D4B20  0x021D4B20  data  a4
 *   d_021D4B14  0x021D4B14  data  a4
 *   d_021D4B08  0x021D4B08  data  a4
 *   d_021D4AFC  0x021D4AFC  data  a4
 *   d_021D4AF0  0x021D4AF0  data  a4
 *   d_021D4AE4  0x021D4AE4  data  a4
 *   d_021D4AD8  0x021D4AD8  data  a4
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0219FC68  0x0219FC68  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   d_021D4ACC     0x021D4ACC  data  a4
 *   func_0219FCC0  0x0219FCC0  thumb  ov021
 *   func_0219FE64  0x0219FE64  thumb  ov021
 *   func_0219FE20  0x0219FE20  thumb  ov021
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   d_021D4FA4     0x021D4FA4  data  a4
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   d_021D5074  0x021D5074  data  a4
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   func_0216D7E8  0x0216D7E8  thumb  ov010
 *   func_0216D7F8  0x0216D7F8  thumb  ov010
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   d_021D4DE8  0x021D4DE8  data  a4
 *   d_021D5024     0x021D5024  data  a4
 *   d_021D5038     0x021D5038  data  a4
 *   d_021D4DB8  0x021D4DB8  data  a4
 *   d_021D504C     0x021D504C  data  a4
 *   d_021D5060     0x021D5060  data  a4
 *   func_0216D5D4  0x0216D5D4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   d_021D4D60  0x021D4D60  data  a4
 *   func_0216D608  0x0216D608  thumb  ov010
 *   d_021D4D04  0x021D4D04  data  a4
 *   d_021D4D78  0x021D4D78  data  a4
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_021AE198  0x021AE198  thumb  ov021
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   d_021D4F90     0x021D4F90  data    a2
 *   func_0203630C  0x0203630C  arm
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_020362DC  0x020362DC  arm
 *   func_020056EC  0x020056EC  thumb
 *   d_021D50F8  0x021D50F8  data  a4
 *   func_021642B4  0x021642B4  thumb  ov010
 *   d_021D4FEC  0x021D4FEC  data  a4
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   d_021D4FCC     0x021D4FCC  data    a4
 *   func_0216D550  0x0216D550  thumb  ov010
 *   data_021D5278  0x021D5278  data   ov021  a4
 *   d_021D52CC  0x021D52CC  data  a4
 *   d_021D5320  0x021D5320  data  a4
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_0216D6A0  0x0216D6A0  thumb  ov010
 *   func_0216D6B8  0x0216D6B8  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   d_021D5238     0x021D5238  data   ov021  a4
 *   d_021D5248     0x021D5248  data   ov021  a4
 *   d_021D5258     0x021D5258  data   ov021  a4
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   d_021D5374  0x021D5374  data  a4
 *   d_021D538C  0x021D538C  data  a4
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_021AE884  0x021AE884  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   d_021D5474     0x021D5474  data   ov021  a4
 *   d_021D537C  0x021D537C  data  a4
 *   d_021D5480     0x021D5480  data   ov021  a4
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021D046C  0x021D046C  thumb  ov021
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   d_021D53A0  0x021D53A0  data  a4
 *   d_021D5394  0x021D5394  data  a4
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021D53B4  0x021D53B4  data  a4
 *   d_021D53D4  0x021D53D4  data  a4
 *   d_021D5414  0x021D5414  data  a4
 *   d_021D5434  0x021D5434  data  a4
 *   d_021D53F4  0x021D53F4  data  a4
 *   d_021D5384     0x021D5384  data   a4
 *   d_021D5454     0x021D5454  data   ov021  a4
 */
#include "fldmmdl_movecode_types.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

/* One step of a move code: returns 1 to run the next step in the same frame. */
typedef int (*MmdlStepProc)(Mmdl *mmdl, void *work);

extern u32 func_0216D674(Mmdl *mmdl, u16 v);
extern MmdlSys *func_0216D67C(Mmdl *mmdl);
extern u32 func_0216D5E0(Mmdl *mmdl, int dir);
extern int func_0216D600(Mmdl *mmdl, u16 dir);
extern int func_0216D83C(Mmdl *mmdl);
extern int func_0216D854(Mmdl *mmdl);
extern int func_0216D86C(Mmdl *mmdl);
extern int func_02163F10(Mmdl *mmdl);
extern void *func_0216D684();
extern int func_0216DA50(Mmdl *mmdl);
extern void *func_0216D69C();
extern u16 func_0216D5A8(Mmdl *mmdl);
extern int func_02164168(Mmdl *mmdl);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern u16 func_0216D5A0(Mmdl *mmdl);
extern void func_0216DA7C(Mmdl *mmdl);
extern int func_02197E7C(int dir, int speed);
extern void func_0216D438(Mmdl *mmdl, int acmd);
extern u32 func_02197EDC(Mmdl *mmdl);
extern void func_0216D60C(Mmdl *mmdl, u16 dir);
extern int func_021639C0(Mmdl *mmdl, u16 dir);
extern void func_0216DA44(Mmdl *mmdl);
extern int func_0216D7E8(Mmdl *mmdl);
extern int func_0216D7F8(Mmdl *mmdl);
extern int func_0216D660(Mmdl *mmdl);
extern int func_0216D66C(Mmdl *mmdl);
extern int func_021641E8(int dir);
extern int func_021641F8(u16 dir);
extern int func_0216D5D4(Mmdl *mmdl);
extern u16 func_021642A4(int dir);
extern u16 func_0216D608(Mmdl *mmdl);
extern int func_0216D63C(Mmdl *mmdl, int index);
extern int func_021AE198(Mmdl *mmdl, int a, int b, int c);
extern int func_0216E0E8(Mmdl *mmdl, int moveCode);
extern unsigned int func_0203630C(void);
extern Mmdl *func_0216DEE0(MmdlSys *sys);
extern u16 func_0216D7C4(Mmdl *mmdl);
extern u32 func_020362DC(void);
extern u32 func_020056EC(u32 range);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern int func_0216D55C(Mmdl *mmdl, int bit);
extern u32 *func_0216D548(Mmdl *mmdl, u32 bit);
extern u32 *func_0216D550(Mmdl *mmdl, u32 bit);
extern int func_0216D804(Mmdl *mmdl);
extern int func_0216D81C(Mmdl *mmdl);

extern u32 d_021D4FA4[];
extern u16 d_021D5074[][6];
extern MmdlStepProc d_021D4DE8[];
extern const MmdlDirCycle d_021D5024;
extern const MmdlDirCycle d_021D5038;
extern MmdlStepProc d_021D4DB8[];
extern const MmdlDirCycle d_021D504C;
extern const MmdlDirCycle d_021D5060;
extern MmdlStepProc d_021D4D60[];
extern MmdlStepProc d_021D4D04[];
extern MmdlStepProc d_021D4D78[];
extern u16 d_021D4F90[];
extern MmdlDirSetEntry d_021D50F8[];
extern u32 d_021D4FEC[];
extern u32 d_021D4FCC[][4];
extern int (*const data_021D5278[])(Mmdl *mmdl);
extern u32 (*const d_021D52CC[])(Mmdl *mmdl);
extern u32 (*const d_021D5320[])(Mmdl *mmdl);

int func_0219B060(void);
int func_0219B0C4(void);
int func_0219B0D8(u32 *table, u32 endMark);
int func_0219B0F0(u32 *table, u32 endMark);
u32 func_0219B104(u32 setId, u32 endMark);
u32 *func_0219B120(u32 setId);
int func_0219B200(Mmdl *mmdl, int setId, int endMark);
int func_0219B2E8(Mmdl *mmdl, u8 *triggerCount);
int func_0219B334(Mmdl *mmdl);
int func_0219B358(Mmdl *mmdl);
void func_0219B374(Mmdl *mmdl, MmdlMirrorState *mirror);
void func_0219B390(Mmdl *mmdl, MmdlMirrorState *mirror);
void func_0219B404(Mmdl *mmdl, MmdlMirrorState *mirror);
int func_0219B440(Mmdl *mmdl);
u32 func_0219B45C(Mmdl *mmdl);
u32 func_0219B478(Mmdl *mmdl);
int func_0219A4CC(Mmdl *mmdl, u32 dir);
void func_0219A3D8(Mmdl *mmdl, MmdlMoveRect *rect);
int func_0219A528(Mmdl *mmdl, u32 dir);
void func_0219A5A4(Mmdl *mmdl, u8 rotation);
void func_0219AA38(Mmdl *mmdl, u32 speed, u32 axis, u32 routeId);
void func_0219AD18(Mmdl *mmdl, u32 speed, u32 axis, u32 routeId);
void func_0219A290(Mmdl *mmdl, u32 acmdSpeed, u32 dirSetId, u32 limitMode);
int func_0219A098(Mmdl *mmdl, u32 kind);
u16 func_0219A1E8(u16 moveCode, u16 dir);
void func_0219ADEC(MmdlRoutePatrolSwapWork *work);
struct Actor;
struct VecFx32;

typedef struct DirGroupTable { u32 group[4]; } DirGroupTable;

typedef struct LookAroundDirTable { u32 dir[2][2]; } LookAroundDirTable;

typedef struct SpinDirTable { u32 dir[2][4]; } SpinDirTable;


extern void *func_0216D6A0(Mmdl *mmdl, int size);
extern void *func_0216D6B8(Mmdl *mmdl);
extern int func_0216DA5C(Mmdl *mmdl);
extern u32 func_0216DAE0(Mmdl *mmdl, u32 mode);
extern u16 func_0216D590(Mmdl *mmdl);
extern int func_021AE884(Mmdl *mmdl);
extern int func_0216DD1C(void *mmdlSys, void **outMmdl, u32 *iter);
extern u32 func_0216D57C(Mmdl *mmdl, u32 bits);
extern void *func_0216D568(Mmdl *mmdl, u32 bits);
extern void func_0216D8C0(Mmdl *mmdl, void *offset);
extern void func_021AC154(u32 effect);
extern u32 func_0216D534(void *mmdlSys);
extern u32 func_02188CD0(u8 *fieldMap);
extern u32 func_021D046C(u32 fieldMap, Mmdl *mmdl, u32 kind);
extern int func_0216DB24(Mmdl *mmdl);
u32 func_0219BF60();
u32 func_0219BF7C(Mmdl *mmdl);
u32 func_0219BF88(Mmdl *mmdl);
u32 func_0219BF94(Mmdl *mmdl);
u32 func_0219BFA0(Mmdl *mmdl);
u32 func_0219BFAC(Mmdl *mmdl);
u32 func_0219BFB8(Mmdl *mmdl);
u32 func_0219BFC4(Mmdl *mmdl);
u32 func_0219BFD0(Mmdl *mmdl);
void func_0219C0D4();
void func_0219BFDC(Mmdl *mmdl);
int func_0219C000(Mmdl *mmdl, u32 unusedWork, u32 regR2, u32 regR3);
int func_0219C034(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3);
int func_0219C04C(Mmdl *mmdl, s8 *work);
int func_0219C080(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3);
int func_0219C0AC(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3);
void func_0219C0E8(Mmdl *mmdl);
void func_0219C0F4(Mmdl *mmdl);
void func_0219C100(Mmdl *mmdl);
void func_0219C10C(Mmdl *mmdl);
extern int func_02163E34(Mmdl *mmdl, MmdlVec *pos, u32 *outAttr);
extern int func_021AB11C(u32 attr);
extern void func_0216D88C(const struct Actor *mmdl, struct VecFx32 *pos);
void func_0219B508(Mmdl *mmdl);
int func_0219B520(Mmdl *mmdl);
int func_0219B59C(Mmdl *mmdl);
void func_0219B6B0(Mmdl *mmdl);
int func_0219B6E0(Mmdl *mmdl);
int func_0219B75C(Mmdl *mmdl);
int func_0219B8A8(void);
int func_0219B8BC(Mmdl *mmdl, u32 unusedWork, u32 regR2, u32 regR3);
void func_0219B8E8(Mmdl *mmdl);
void func_0219B920(void);
int func_0219B924(Mmdl *mmdl, MmdlLookWork *work);
int func_0219B968(Mmdl *mmdl, MmdlLookWork *work, u32 regR2, u32 regR3);
int func_0219B984(Mmdl *mmdl, MmdlLookWork *work);
void func_0219B9B0(Mmdl *mmdl, MmdlLookWork *work);
int func_0219B9D8(Mmdl *mmdl, MmdlLookWork *work);
void func_0219BA0C(Mmdl *mmdl, MmdlLookWork *work);
int func_0219BA2C(Mmdl *mmdl);
int func_0219BA6C(Mmdl *mmdl);
void func_0219BAE0(Mmdl *mmdl);
void func_0219BB08(Mmdl *mmdl);
void func_0219BB38(void);
void func_0219BB3C(void);
int func_0219BB48(Mmdl *mmdl, MmdlLookWork *work);
int func_0219BB84(Mmdl *mmdl, MmdlLookWork *work, u32 regR2, u32 regR3);
Mmdl *func_0219BBA4(Mmdl *mmdl);
int func_0219BC48(Mmdl *mmdl, MmdlLookWork *work);
int func_0219BCC0(Mmdl *mmdl, MmdlLookWork *work, Mmdl *fellow);
int func_0219BCE4(Mmdl *mmdl, MmdlLookWork *work);
int func_0219BD30(Mmdl *mmdl, MmdlLookWork *work);
void func_0219BDC4(Mmdl *mmdl, u32 kind);
void func_0219BE0C(Mmdl *mmdl);
void func_0219BE18(Mmdl *mmdl);
void func_0219BE24(Mmdl *mmdl);
void func_0219BE30(Mmdl *mmdl);
void func_0219BE3C(Mmdl *mmdl);
void func_0219BE60(Mmdl *mmdl);
void func_0219BE70(Mmdl *mmdl);
int func_0219BEB4(Mmdl *mmdl, u32 kind);
int func_0219BED0(Mmdl *mmdl, MmdlHideWork *work);
int func_0219BF00(Mmdl *mmdl, MmdlHideWork *work, u32 regR2, u32 regR3);
void func_0219BF3C(Mmdl *mmdl, u32 effect);
int func_0219BF48(Mmdl *mmdl);
void func_0219BF54(Mmdl *mmdl);
void func_0219C118(Mmdl *mmdl);
int func_0219C13C(Mmdl *mmdl, MmdlWallWalkWork *work);
int func_0219C150(Mmdl *mmdl, MmdlWallWalkWork *work);
int func_0219C164(Mmdl *mmdl, MmdlWallWalkWork *work, u32 regR2, u32 regR3);
int func_0219C180(Mmdl *mmdl, MmdlVec *pos, int dir, int hand);
int func_0219C20C(Mmdl *mmdl, MmdlVec *pos, int dir, int hand);
int func_0219C298(Mmdl *mmdl, int dir, int hand);
int func_0219C2BC(Mmdl *mmdl, int dir, int hand);
int func_0219C2E0(Mmdl *mmdl, int dir, int hand);
int func_0219C314(Mmdl *mmdl, int *dir, u32 hand);
int func_0219C338(Mmdl *mmdl, MmdlWallWalkWork *work, u32 acmdKind);
extern DirGroupTable d_021D5238;
extern LookAroundDirTable d_021D5248;
extern SpinDirTable d_021D5258;
extern MmdlStepProc d_021D5374[];
extern MmdlStepProc d_021D538C[];
extern MmdlVec d_021D5474;
extern MmdlStepProc d_021D537C[];
extern MmdlVec d_021D5480;
extern MmdlStepProc d_021D53A0[];
extern MmdlStepProc d_021D5394[];
extern int d_021D53B4[][2];
extern int d_021D53D4[][2];
extern int d_021D5414[][2];
extern int d_021D5434[][2];
extern int d_021D53F4[][2];
extern u32 d_021D5384[];
extern u32 d_021D5454[][2];

/* Init of the turn-in-place move codes: kind selects the direction set. */
int func_0219A098(Mmdl *mmdl, u32 kind)
{
    MmdlTurnRandomWork *work;
    int workSize = 8;
    work = func_0216D684(mmdl, 8);
    work->waitFrames = func_0219B0F0(d_021D4FA4, workSize - 9);
    work->dirSetId = kind;
    func_0216D674(mmdl, 0);
    return func_0216DA50(mmdl);
}

int func_0219A0CC(Mmdl *mmdl) { return func_0219A098(mmdl, 0); }

int func_0219A0D8(Mmdl *mmdl) { return func_0219A098(mmdl, 1); }

int func_0219A0E4(Mmdl *mmdl) { return func_0219A098(mmdl, 2); }

int func_0219A0F0(Mmdl *mmdl) { return func_0219A098(mmdl, 3); }

int func_0219A0FC(Mmdl *mmdl) { return func_0219A098(mmdl, 4); }

int func_0219A108(Mmdl *mmdl) { return func_0219A098(mmdl, 5); }

int func_0219A114(Mmdl *mmdl) { return func_0219A098(mmdl, 6); }

int func_0219A120(Mmdl *mmdl) { return func_0219A098(mmdl, 7); }

int func_0219A12C(Mmdl *mmdl) { return func_0219A098(mmdl, 8); }

int func_0219A138(Mmdl *mmdl) { return func_0219A098(mmdl, 9); }

int func_0219A144(Mmdl *mmdl) { return func_0219A098(mmdl, 10); }

void func_0219A150(Mmdl *mmdl)
{
    MmdlTurnRandomWork *work;
    u32 dir;
    u16 curDir;
    u16 nextDir;
    work = func_0216D69C(mmdl);
    if (func_0216D5A8(mmdl) == 11) {
        if (func_02164168(mmdl) == 1 && func_0219B0C4() == 1) {
            curDir = func_0216D5F8(mmdl);
            nextDir = func_0219A1E8(func_0216D5A0(mmdl), curDir);
            if (nextDir != 9)
                func_0216D5E0(mmdl, (u16)nextDir);
        }
    } else {
        dir = func_0219B200(mmdl, work->dirSetId, 9);
        if (dir != 9) {
            func_0216D5E0(mmdl, (u16)dir);
        } else if (work->suspended == 0) {
            work->waitFrames = work->waitFrames - 1;
            if (work->waitFrames <= 0) {
                work->waitFrames = func_0219B0F0(d_021D4FA4, -1);
                dir = func_0219B104(work->dirSetId, 9);
                func_0216D5E0(mmdl, (u16)dir);
            }
        }
    }
    func_02163F10(mmdl);
}

static inline u16 GetNextDirInRow(u16 *row, u16 dir)
{
    int i;
    u16 *p;

    for (i = 1, p = row; p[i] != 9; i++) {
        if (dir == p[i]) {
            i++;
            if (p[i] == 9) i = 1;
            return p[i];
        }
    }
    return 9;
}

/*
 * Row lookup: find the 6-halfword record whose key (the model's move code)
 * matches, then return the entry after dir in its 9-terminated list (wrapping
 * to entry 1). The row is an inline argument formed through a (u8 *) byte
 * offset, so the add stays after the key compare; the helper's
 * `for (i = 1, p = row; ...)` local copy of the row gives the image's colours
 * (row r0, index r3, dir copied to r4).
 */
u16 func_0219A1E8(u16 moveCode, u16 dir)
{
    int i = 0;

    do {
        if (moveCode == d_021D5074[i][0]) {
            return GetNextDirInRow((u16 *)((u8 *)d_021D5074 + i * 12), dir);
        }
        i++;
    } while (d_021D5074[i][0] != 0xFF);
    return 9;
}

/*
 * Empty callback: its address 0x0219A24D is stored in ov021 data at 0x021D5738.
 */
void func_0219A24C(void)
{
}

void func_0219A250(Mmdl *mmdl)
{
    func_0219A290(mmdl, 0xc, 0xb, 0x0);
}

void func_0219A260(Mmdl *mmdl)
{
    func_0219A290(mmdl, 0xc, 0xc, 0x0);
}

void func_0219A270(Mmdl *mmdl)
{
    func_0219A290(mmdl, 0xc, 0xd, 0x0);
}

void func_0219A280(Mmdl *mmdl)
{
    func_0219A290(mmdl, 0xc, 0xd, 0x2);
}

void func_0219A290(Mmdl *mmdl, u32 acmdSpeed, u32 dirSetId, u32 limitMode)
{
    MmdlWalkRandomWork *work = func_0216D684(mmdl, 16);
    work->limitMode = limitMode;
    work->acmdSpeed = acmdSpeed;
    work->dirSetId = dirSetId;
    func_0216D674(mmdl, 0);
    func_0216DA50(mmdl);
}

void func_0219A2B8(Mmdl *mmdl)
{
    MmdlWalkRandomWork *work;
    u32 dir;
    int hit;

    work = func_0216D69C(mmdl);
    switch (work->state) {
    case 0:
        func_0216DA50(mmdl);
        func_0216DA7C(mmdl);
        func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)((u32)func_0216D5F8(mmdl)), (u16)0)));
        work->state++;
        break;
    case 1:
        if (func_02197EDC(mmdl) == 0)
            break;
        work->waitFrames = func_0219B0F0(d_021D4FA4, -1);
        work->state++;
    case 2:
        work->waitFrames--;
        if (work->waitFrames != 0)
            break;
        work->state++;
    case 3:
        dir = func_0219B104(work->dirSetId, 9);
        func_0216D60C(mmdl, dir);
        if (work->limitMode == 1 && func_0219A4CC(mmdl, dir) == 0) {
            work->state = 0;
            return;
        }
        hit = func_021639C0(mmdl, dir);
        if (hit != 0) {
            if (work->limitMode == 2) {
                if (hit & 1) {
                    work->state = 0;
                    return;
                }
            } else {
                work->state = 0;
                return;
            }
        }
        func_0216D438(mmdl, (u16)func_02197E7C((u16)dir, (u16)work->acmdSpeed));
        func_0216DA44(mmdl);
        work->state++;
    case 4:
        if (func_02197EDC(mmdl) != 0) {
            func_0216DA50(mmdl);
            work->state = 0;
        }
        break;
    }
}

/*
 * The move code selects which side of the model the rectangle covers
 * (codes 6 to 13). Store order in each arm is left, right, top, bottom (x
 * pair, then y pair); the field order left, top, right, bottom puts stores to
 * +0/+8 first.
 */
void func_0219A3D8(Mmdl *mmdl, MmdlMoveRect *rect)
{
    int x;
    int y;
    int w;
    int h;

    x = func_0216D7E8(mmdl);
    y = func_0216D7F8(mmdl);
    w = func_0216D660(mmdl);
    h = func_0216D66C(mmdl);
    switch (func_0216D5A0(mmdl)) {
    case 6:
        rect->left = x - w;
        rect->right = x;
        rect->top = y - h;
        rect->bottom = y;
        break;
    case 7:
        rect->left = x;
        rect->right = x + w;
        rect->top = y - h;
        rect->bottom = y;
        break;
    case 8:
        rect->left = x - w;
        rect->right = x;
        rect->top = y;
        rect->bottom = y + h;
        break;
    case 9:
        rect->left = x;
        rect->right = x + w;
        rect->top = y;
        rect->bottom = y + h;
        break;
    case 10:
        rect->left = x - w;
        rect->right = x;
        rect->top = y - h;
        rect->bottom = y + h;
        break;
    case 11:
        rect->left = x;
        rect->right = x + w;
        rect->top = y - h;
        rect->bottom = y + h;
        break;
    case 12:
        rect->left = x - w;
        rect->right = x + w;
        rect->top = y - h;
        rect->bottom = y;
        break;
    case 13:
        rect->left = x - w;
        rect->right = x + w;
        rect->top = y;
        rect->bottom = y + h;
        break;
    }
}

/* Returns 1 when the cell one step in dir stays inside the move rectangle. */
int func_0219A4CC(Mmdl *mmdl, u32 dir)
{
    int r[4];
    int x;
    int y;
    func_0219A3D8(mmdl, (MmdlMoveRect *)r);
    x = func_0216D83C(mmdl) + func_021641E8((u16)dir);
    y = func_0216D86C(mmdl) + func_021641F8(dir);
    if (r[0] > x || r[2] < x)
        return 0;
    if (r[1] > y || r[3] < y)
        return 0;
    return 1;
}

int func_0219A528(Mmdl *mmdl, u32 dir)
{
    MmdlFixedDirWork *work = func_0216D684(mmdl, 8);
    work->dir = dir;
    func_0216D674(mmdl, 0);
    func_0216DA50(mmdl);
    return func_02163F10(mmdl);
}

void func_0219A54C(Mmdl *mmdl)
{
    MmdlFixedDirWork *work = func_0216D69C(mmdl);
    switch (work->state) {
    case 0:
        func_0216D5E0(mmdl, (unsigned short)work->dir);
        work->state = work->state + 1;
        break;
    case 1:
        break;
    }
}

int func_0219A574(Mmdl *mmdl) { return func_0219A528(mmdl, 0); }

int func_0219A580(Mmdl *mmdl) { return func_0219A528(mmdl, 1); }

int func_0219A58C(Mmdl *mmdl) { return func_0219A528(mmdl, 2); }

int func_0219A598(Mmdl *mmdl) { return func_0219A528(mmdl, 3); }

void func_0219A5A4(Mmdl *mmdl, u8 rotation)
{
    MmdlSpinWork *work = func_0216D684(mmdl, 8);
    work->rotation = rotation;
    func_0216D674(mmdl, 0);
    func_0216DA50(mmdl);
    func_02163F10(mmdl);
}

void func_0219A5C8(Mmdl *mmdl) { func_0219A5A4(mmdl, 2); }

void func_0219A5D4(Mmdl *mmdl) { func_0219A5A4(mmdl, 3); }

void func_0219A5E0(Mmdl *mmdl)
{
    MmdlSpinWork *work = func_0216D69C(mmdl);
    while (d_021D4DE8[(s8)work->step](mmdl, work) == 1) {
    }
}

/* Spin step: turn toward the player, else keep the display direction. */
int func_0219A604(Mmdl *mmdl, MmdlSpinWork *work)
{
    u32 dir = func_0219B200(mmdl, 0x26, 9);
    if (dir == 9) {
        dir = func_0216D5F8(mmdl);
    }
    func_0216D438(mmdl, (u16)func_02197E7C((u16)dir, (u16)0));
    work->step = 1;
    return 1;
}

/* Spin step: wait for the turn to end. */
int func_0219A638(Mmdl *mmdl, MmdlSpinWork *work)
{
    if (func_02197EDC(mmdl) == 0) {
        return 0;
    }
    if (func_0216D5A8(mmdl) != 11) {
        work->waitCount = 0;
    }
    work->step = 2;
    return 1;
}

/* Spin step: wait a number of frames, or for the player's button press (event type 11). */
int func_0219A660(Mmdl *mmdl, MmdlSpinWork *work)
{
    if (func_0216D5A8(mmdl) == 11) {
        if (work->waitCount != 0) {
            work->waitCount = 0;
            return 0;
        }
        if (func_02164168(mmdl) == 0)
            return 0;
        if (func_0219B0C4() == 0)
            return 0;
        work->waitCount = work->waitCount + 1;
    } else {
        if (work->waitCount != 0) {
            if (func_0219B200(mmdl, 0x26, 9) != 9) {
                work->step = 0;
                return 1;
            }
        }
        work->waitCount = work->waitCount + 1;
        if (work->waitCount < 0x18)
            return 0;
    }
    work->step = 3;
    return 1;
}

/* Spin step: turn to the next direction of the cycle for the rotation. */
int func_0219A6CC(Mmdl *mmdl, MmdlSpinWork *work)
{
    MmdlDirCycle left = d_021D5024;
    MmdlDirCycle right = d_021D5038;
    int *cycle;
    int i;
    int cur;
    cycle = left.dirs;
    if (work->rotation != 2)
        cycle = right.dirs;
    cur = func_0216D5F8(mmdl);
    i = 0;
    if (cycle[0] != 9) {
        do {
            if (cur == cycle[i])
                break;
            i++;
        } while (cycle[i] != 9);
    }
    i++;
    if (cycle[i] == 9)
        i = 0;
    func_0216D5E0(mmdl, (u16)cycle[i]);
    work->step = 0;
    return 1;
}

void func_0219A750(Mmdl *mmdl) { func_0219A5A4(mmdl, 3); }

void func_0219A75C(Mmdl *mmdl)
{
    MmdlSpinWork *work = func_0216D69C(mmdl);
    while (d_021D4DB8[(s8)work->step](mmdl, work) == 1) {
    }
}

/* Swing step: turn toward the display direction (the turn acmd with speed 0). */
int func_0219A780(Mmdl *mmdl, MmdlSpinWork *work)
{
    func_0216D438(mmdl, (((u32)func_02197E7C((u32)(((u32)func_0216D5F8(mmdl) << 16) >> 16), (u32)0) << 16) >> 16));
    work->step = 1;
    return 1;
}

/* Swing step: wait for the turn to end. */
int func_0219A7A8(Mmdl *mmdl, MmdlSpinWork *work)
{
    if (func_02197EDC(mmdl) == 0) {
        return 0;
    }
    work->waitCount = 0;
    work->step = 2;
    return 1;
}

/* Swing step: wait 0x18 frames. */
int func_0219A7C4(Mmdl *mmdl, MmdlSpinWork *work)
{
    int count = work->waitCount + 1;
    work->waitCount = count;
    if (count < 0x18)
        return 0;
    work->step = 3;
    return 1;
}

/* Swing step: turn to the next direction; at the header direction reverse the rotation. */
int func_0219A7DC(Mmdl *mmdl, MmdlSpinWork *work)
{
    MmdlDirCycle left = d_021D504C;
    MmdlDirCycle right = d_021D5060;
    int *cycle;
    int i;
    int cur;
    cycle = left.dirs;
    if (work->rotation != 2)
        cycle = right.dirs;
    cur = func_0216D5F8(mmdl);
    i = 0;
    if (cycle[0] != 9) {
        do {
            if (cur == cycle[i])
                break;
            i++;
        } while (cycle[i] != 9);
    }
    i++;
    if (cycle[i] == 9)
        i = 0;
    func_0216D5E0(mmdl, (u16)cycle[i]);
    if (func_0216D5F8(mmdl) == func_0216D5D4(mmdl))
        work->rotation = func_021642A4(work->rotation);
    work->step = 0;
    return 1;
}

void func_0219A87C(Mmdl *mmdl)
{
    MmdlBackForthWork *work = func_0216D684(mmdl, 8);
    if (func_0219B358(mmdl) == 1) {
        func_0219B374(mmdl, &work->mirror);
    }
}

void func_0219A89C(Mmdl *mmdl)
{
    MmdlBackForthWork *work = func_0216D69C(mmdl);
    while (d_021D4D60[work->step](mmdl, work) == 1) {
    }
}

/* Back and forth step: pick the direction (header direction, or its reverse) and face it. */
int func_0219A8C0(Mmdl *mmdl, MmdlBackForthWork *work)
{
    u32 cur = func_0216D5D4(mmdl);
    if (work->reversed == 1)
        cur = func_021642A4((u16)cur);
    func_0216D600(mmdl, cur);
    if (func_0219B358(mmdl) == 0)
        func_0216D5E0(mmdl, (u16)cur);
    work->step = 1;
    return 1;
}

/* Back and forth step: walk one cell, reversing at an obstacle or when back at the start. */
int func_0219A900(Mmdl *mmdl, MmdlBackForthWork *work)
{
    int x;
    int y;
    int tx;
    int ty;
    u32 dir;
    u32 moveDir;
    int hit;
    u32 speed;

    if (func_0219B2E8(mmdl, &work->triggerCount) == 0)
        return 0;
    if (work->reversed != 0) {
        x = func_0216D7E8(mmdl);
        y = func_0216D7F8(mmdl);
        tx = func_0216D83C(mmdl);
        ty = func_0216D86C(mmdl);
        if (x == tx && y == ty) {
            dir = func_021642A4((u16)func_0216D608(mmdl));
            func_0216D600(mmdl, dir);
            if (func_0219B358(mmdl) == 0)
                func_0216D5E0(mmdl, (u16)dir);
            work->reversed = 0;
        }
    }
    moveDir = func_0216D608(mmdl);
    hit = func_021639C0(mmdl, moveDir);
    if (hit & 1) {
        work->reversed = 1;
        moveDir = func_021642A4((u16)moveDir);
        hit = func_021639C0(mmdl, moveDir);
    }
    speed = 12;
    if (func_0219B334(mmdl) != 0 && func_0219B060() == 1 && func_02164168(mmdl) == 1)
        speed = 16;
    if (hit != 0)
        speed = 32;
    func_0216D438(mmdl, (u16)func_02197E7C((u16)moveDir, (u16)speed));
    if (func_0219B358(mmdl) == 1)
        func_0219B390(mmdl, &work->mirror);
    func_0216DA44(mmdl);
    work->step = 2;
    return 1;
}

/* Back and forth step: wait for the walk to end. */
int func_0219AA08(Mmdl *mmdl, MmdlBackForthWork *work)
{
    if (func_02197EDC(mmdl) == 1) {
        func_0216DA50(mmdl);
        if (func_0219B358(mmdl) == 1) {
            func_0219B404(mmdl, &work->mirror);
        }
        work->step = 0;
    }
    return 0;
}

/* Init of the route patrol move codes: axis picks the compared coordinate, routeId the route. */
void func_0219AA38(Mmdl *mmdl, u32 axisCheckIndex, u32 axis, u32 routeId)
{
    MmdlRoutePatrolWork *work = func_0216D684(mmdl, 12);
    work->axisCheckIndex = axisCheckIndex;
    work->axis = axis;
    work->routeId = routeId;
    if (func_0219B358(mmdl) == 1) {
        func_0219B374(mmdl, &work->mirror);
    }
}

void func_0219AA68(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x0, 0xe);
}

void func_0219AA78(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x0, 0xf);
}

void func_0219AA88(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x1, 0x10);
}

void func_0219AA98(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x1, 0x11);
}

void func_0219AAA8(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x0, 0x12);
}

void func_0219AAB8(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x0, 0x13);
}

void func_0219AAC8(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x1, 0x14);
}

void func_0219AAD8(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x1, 0x15);
}

void func_0219AAE8(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x1, 0x16);
}

void func_0219AAF8(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x1, 0x17);
}

void func_0219AB08(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x0, 0x18);
}

void func_0219AB18(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x0, 0x19);
}

void func_0219AB28(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x1, 0x1a);
}

void func_0219AB38(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x1, 0x1b);
}

void func_0219AB48(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x0, 0x1c);
}

void func_0219AB58(Mmdl *mmdl)
{
    func_0219AA38(mmdl, 0x2, 0x0, 0x1d);
}

void func_0219AB68(Mmdl *mmdl)
{
    MmdlRoutePatrolWork *work = func_0216D69C(mmdl);
    while (d_021D4D04[work->step](mmdl, work) == 1) {
    }
}

/* Route patrol step: walk to the next cell of the route (turn at the corner, reverse at an obstacle). */
int func_0219AB8C(Mmdl *mmdl, MmdlRoutePatrolWork *work)
{
    u32 *route;
    u32 dir;
    int x0;
    int y0;
    int x1;
    int y1;
    int hit;
    int speed;

    if (func_0219B2E8(mmdl, &work->triggerCount) == 0) {
        return 0;
    }
    if (work->routeIndex == work->axisCheckIndex) {
        if (work->axis == 0) {
            x0 = func_0216D7E8(mmdl);
            if (x0 == func_0216D83C(mmdl)) {
                work->routeIndex++;
            }
        } else {
            x0 = func_0216D7F8(mmdl);
            if (x0 == func_0216D86C(mmdl)) {
                work->routeIndex++;
            }
        }
    }
    if (work->routeIndex == 3) {
        x0 = func_0216D7E8(mmdl);
        y0 = func_0216D7F8(mmdl);
        x1 = func_0216D83C(mmdl);
        y1 = func_0216D86C(mmdl);
        if (x0 == x1 && y0 == y1) {
            work->routeIndex = 0;
        }
    }
    route = func_0219B120(work->routeId);
    dir = route[work->routeIndex];
    func_0216D600(mmdl, (u16)dir);
    if (func_0219B358(mmdl) == 0) {
        func_0216D5E0(mmdl, (u16)dir);
    }
    hit = func_021639C0(mmdl, (u16)dir);
    if (hit & 1) {
        work->routeIndex++;
        dir = route[work->routeIndex];
        func_0216D600(mmdl, (u16)dir);
        if (func_0219B358(mmdl) == 0) {
            func_0216D5E0(mmdl, (u16)dir);
        }
        hit = func_021639C0(mmdl, (u16)dir);
    }
    speed = 12;
    if (func_0219B334(mmdl) != 0 && func_0219B060() == 1 && func_02164168(mmdl) == 1) {
        speed = 16;
    }
    if (hit != 0) {
        speed = 32;
    }
    func_0216D438(mmdl, (u16)func_02197E7C((u16)dir, (u16)speed));
    if (func_0219B358(mmdl) == 1) {
        func_0219B390(mmdl, &work->mirror);
    }
    func_0216DA44(mmdl);
    work->step = 1;
    return 1;
}

/* Route patrol step: wait for the walk to end. */
int func_0219ACE8(Mmdl *mmdl, MmdlRoutePatrolWork *work)
{
    if (func_02197EDC(mmdl) == 1) {
        func_0216DA50(mmdl);
        if (func_0219B358(mmdl) == 1) {
            func_0219B404(mmdl, &work->mirror);
        }
        work->step = 0;
    }
    return 0;
}

/* Init of the swapping route patrol move codes; same arguments as the plain route patrol. */
void func_0219AD18(Mmdl *mmdl, u32 axisCheckIndex, u32 axis, u32 routeId)
{
    MmdlRoutePatrolSwapWork *work = func_0216D684(mmdl, 12);
    work->axisCheckIndex = axisCheckIndex;
    work->axis = axis;
    work->routeId = routeId;
    if (func_0219B358(mmdl) == 1) {
        func_0219B374(mmdl, &work->mirror);
    }
}

void func_0219AD48(Mmdl *mmdl)
{
    func_0219AD18(mmdl, 0x2, 0x1, 0x1e);
}

void func_0219AD58(Mmdl *mmdl)
{
    func_0219AD18(mmdl, 0x2, 0x1, 0x1f);
}

void func_0219AD68(Mmdl *mmdl)
{
    func_0219AD18(mmdl, 0x2, 0x0, 0x20);
}

void func_0219AD78(Mmdl *mmdl)
{
    func_0219AD18(mmdl, 0x2, 0x0, 0x21);
}

void func_0219AD88(Mmdl *mmdl)
{
    func_0219AD18(mmdl, 0x2, 0x1, 0x22);
}

void func_0219AD98(Mmdl *mmdl)
{
    func_0219AD18(mmdl, 0x2, 0x1, 0x23);
}

void func_0219ADA8(Mmdl *mmdl)
{
    func_0219AD18(mmdl, 0x2, 0x0, 0x24);
}

void func_0219ADB8(Mmdl *mmdl)
{
    func_0219AD18(mmdl, 0x2, 0x0, 0x25);
}

void func_0219ADC8(Mmdl *mmdl)
{
    MmdlRoutePatrolSwapWork *work = func_0216D69C(mmdl);
    while (d_021D4D78[work->step](mmdl, work) == 1) {
    }
}

/* Moves the route index one cell on, backwards when reverseRoute is set. */
void func_0219ADEC(MmdlRoutePatrolSwapWork *work)
{
    if (work->reverseRoute == 1) {
        work->routeIndex--;
        if (work->routeIndex < 0) {
            work->routeIndex = 3;
        }
    } else {
        work->routeIndex++;
    }
}

/* Swap patrol step: when the player is in sight (event type 10), turn toward it. */
int func_0219AE10(Mmdl *mmdl, MmdlRoutePatrolSwapWork *work)
{
    u32 dir;
    if (func_0216D5A8(mmdl) == 10) {
        dir = func_0216D5F8(mmdl);
        if (func_021AE198(mmdl, dir, func_0216D63C(mmdl, 0), 0) != -1) {
            func_0216D438(mmdl, func_02197E7C(dir, 0x30));
            func_0216DA44(mmdl);
            work->step = 1;
            return 1;
        }
    }
    work->step = 2;
    return 1;
}

/* Swap patrol step: after the turn, change to the mirrored move code and flip the route index. */
int func_0219AE68(Mmdl *mmdl, MmdlRoutePatrolSwapWork *work)
{
    u16 *pair;
    u32 code;
    u32 other;
    u32 moveCode;
    int flipped;

    if (func_02197EDC(mmdl) == 1) {
        other = 0xff;
        moveCode = func_0216D5A0(mmdl);
        pair = d_021D4F90;
        code = 0x25;
        do {
            if (code == moveCode) {
                other = pair[1];
            } else if (pair[1] == moveCode) {
                other = code;
            }
            if (other != 0xff) {
                flipped = 4 - (work->routeIndex + 1);
                func_0216E0E8(mmdl, other);
                work->routeIndex = flipped;
                break;
            }
            pair += 2;
            code = pair[0];
        } while (code != 0xff);
        func_0216DA50(mmdl);
        work->step = 2;
    }
    return 0;
}

/*
 * Twin of func_0219AB8C (same shape; the route index is signed and advanced
 * through func_0219ADEC).
 */
int func_0219AEC8(Mmdl *mmdl, MmdlRoutePatrolSwapWork *work)
{
    u32 *route;
    u32 dir;
    int x0;
    int y0;
    int x1;
    int y1;
    int hit;
    int speed;

    if (func_0219B2E8(mmdl, &work->triggerCount) == 0) {
        return 0;
    }
    if (work->routeIndex == work->axisCheckIndex) {
        if (work->axis == 0) {
            x0 = func_0216D7E8(mmdl);
            if (x0 == func_0216D83C(mmdl)) {
                func_0219ADEC(work);
            }
        } else {
            x0 = func_0216D7F8(mmdl);
            if (x0 == func_0216D86C(mmdl)) {
                func_0219ADEC(work);
            }
        }
    }
    if (work->routeIndex == 3) {
        x0 = func_0216D7E8(mmdl);
        y0 = func_0216D7F8(mmdl);
        x1 = func_0216D83C(mmdl);
        y1 = func_0216D86C(mmdl);
        if (x0 == x1 && y0 == y1) {
            work->routeIndex = 0;
        }
    }
    route = func_0219B120(work->routeId);
    dir = route[work->routeIndex];
    func_0216D600(mmdl, (u16)dir);
    if (func_0219B358(mmdl) == 0) {
        func_0216D5E0(mmdl, (u16)dir);
    }
    hit = func_021639C0(mmdl, (u16)dir);
    if (1 & hit) {
        func_0219ADEC(work);
        dir = route[work->routeIndex];
        func_0216D600(mmdl, (u16)dir);
        if (func_0219B358(mmdl) == 0) {
            func_0216D5E0(mmdl, (u16)dir);
        }
        hit = func_021639C0(mmdl, (u16)dir);
    }
    speed = 12;
    if (func_0219B334(mmdl) != 0 && func_0219B060() == 1 && func_02164168(mmdl) == 1) {
        speed = 16;
    }
    if (hit != 0) {
        speed = 32;
    }
    func_0216D438(mmdl, (u16)func_02197E7C((u16)dir, (u16)speed));
    if (func_0219B358(mmdl) == 1) {
        func_0219B390(mmdl, &work->mirror);
    }
    func_0216DA44(mmdl);
    work->step = 3;
    return 1;
}

/* Swap patrol step: wait for the walk to end. */
int func_0219B030(Mmdl *mmdl, MmdlRoutePatrolSwapWork *work)
{
    if (func_02197EDC(mmdl) == 1) {
        func_0216DA50(mmdl);
        if (func_0219B358(mmdl) == 1) {
            func_0219B404(mmdl, &work->mirror);
        }
        work->step = 0;
    }
    return 0;
}

/* Returns 1 while the B button is held. */
int func_0219B060(void)
{
    if (func_0203630C() & 2) {
        return 1;
    }
    return 0;
}

/* Returns 1 when the player model runs one of the walk acmds. */
int func_0219B074(Mmdl *mmdl)
{
    Mmdl *player;

    player = func_0216DEE0(func_0216D67C(mmdl));
    if (player != 0) {
        switch (func_0216D7C4(player)) {
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0xa3:
        case 0xa4:
        case 0xa5:
        case 0xa6:
            return 1;
        }
    }
    return 0;
}

/* Returns 1 on the frame the B button goes down. */
int func_0219B0C4(void)
{
    if (func_020362DC() & 2) {
        return 1;
    }
    return 0;
}

/* Index of endMark in the table. */
int func_0219B0D8(u32 *table, u32 endMark)
{
    int i;
    for (i = 0; endMark != table[i]; i++) {
    }
    return i;
}

/* Random entry of a table ended by endMark. */
int func_0219B0F0(u32 *table, u32 endMark)
{
    return table[func_020056EC(func_0219B0D8(table, endMark))];
}

/* Random direction of the direction set. */
u32 func_0219B104(u32 setId, u32 endMark)
{
    u32 *dirs = func_0219B120(setId);
    return dirs[func_020056EC(func_0219B0D8(dirs, endMark))];
}

/*
 * The first key is the literal 0 held in a local (row 0 of the table has
 * key 0), then the walk reloads it at the loop bottom.
 */
u32 *func_0219B120(u32 setId)
{
    MmdlDirSetEntry *entry = d_021D50F8;
    u32 key = 0;
    do {
        if (key == setId) {
            return entry->dirs;
        }
        entry++;
        key = entry->id;
    } while (key != 0x27);
    return 0;
}

/*
 * For a trainer-type model (event type 1 or 2) whose move code is in the
 * sight list, returns the direction to the player when the player walks in
 * the same height inside the sight range, else 9.
 */
int func_0219B13C(Mmdl *mmdl)
{
    int eventType;
    u32 moveCode;
    u32 listed;
    int i;
    Mmdl *player;
    int playerX, playerZ, x, z, range;
    int minX, maxX, minZ, maxZ;

    eventType = func_0216D5A8(mmdl);
    if (eventType != 1 && eventType != 2) {
        return 9;
    }
    if (func_0219B074(mmdl) == 0) {
        return 9;
    }
    i = 0;
    moveCode = func_0216D5A0(mmdl);
    do {
        listed = d_021D4FEC[i++];
    } while (listed != moveCode && listed != 0xFF);
    if (moveCode != listed) {
        return 9;
    }
    player = func_0216DEE0(func_0216D67C(mmdl));
    if (player == 0) {
        return 9;
    }
    if (func_0216D854(player) != func_0216D854(mmdl)) {
        return 9;
    }
    playerX = func_0216D83C(player);
    playerZ = func_0216D86C(player);
    range = func_0216D63C(mmdl, 0);
    x = func_0216D83C(mmdl);
    z = func_0216D86C(mmdl);
    minX = x - range;
    maxX = x + range;
    minZ = z - range;
    maxZ = z + range;
    if (minZ <= playerZ && maxZ >= playerZ && minX <= playerX && maxX >= playerX) {
        return func_021642B4(x, z, playerX, playerZ);
    }
    return 9;
}

/*
 * Picks a direction of the set that leads toward the player (the sight
 * direction if it is in the set, else a direction closing the x or z
 * distance); returns endMark's value 9 when none does.
 */
int func_0219B200(Mmdl *mmdl, int setId, int endMark)
{
    int *dirs;
    int count;
    int sightDir;
    int i;
    Mmdl *player;
    int x;
    int z;
    int playerX;
    int playerZ;
    int dirX;
    int dirZ;

    dirs = (int *)func_0219B120(setId);
    count = func_0219B0D8((unsigned int *)dirs, endMark);
    if (count == 1) {
        return 9;
    }
    sightDir = func_0219B13C(mmdl);
    if (sightDir != 9) {
        i = 0;
        do {
            if (sightDir == dirs[i]) {
                return sightDir;
            }
            i++;
        } while (i < count);
        player = func_0216DEE0(func_0216D67C(mmdl));
        dirX = 9;
        dirZ = 9;
        x = func_0216D83C(mmdl);
        z = func_0216D86C(mmdl);
        playerX = func_0216D83C(player);
        playerZ = func_0216D86C(player);
        if (x > playerX) {
            dirX = 2;
        } else if (x < playerX) {
            dirX = 3;
        }
        if (z > playerZ) {
            dirZ = 0;
        } else if (z < playerZ) {
            dirZ = 1;
        }
        i = 0;
        if (dirX == 9) {
            do {
                if (dirZ == dirs[i]) {
                    return dirZ;
                }
                i++;
            } while (i < count);
        } else if (dirZ == 9) {
            do {
                if (dirX == dirs[i]) {
                    return dirX;
                }
                i++;
            } while (i < count);
        } else {
            do {
                if (dirX == dirs[i]) {
                    return dirX;
                }
                if (dirZ == dirs[i]) {
                    return dirZ;
                }
                i++;
            } while (i < count);
        }
        return 9;
    }
    return sightDir;
}

/*
 * Event type 12 waits for a B button press near the player before it moves
 * on; the count then waits the number of frames given by the model's
 * parameter 1. Other event types never wait.
 */
int func_0219B2E8(Mmdl *mmdl, u8 *triggerCount)
{
    if (func_0216D5A8(mmdl) != 12) {
        return 1;
    }
    if (triggerCount[0] == 0) {
        if (func_02164168(mmdl) == 0) {
            return 0;
        }
        if (func_0219B0C4() == 0) {
            return 0;
        }
        triggerCount[0] = func_0216D63C(mmdl, 1);
    }
    if (triggerCount[0] != 0) {
        triggerCount[0]--;
    }
    return 1;
}

/* Event types that dash while the B button is held and the player is near. */
int func_0219B334(Mmdl *mmdl)
{
    u32 eventType = func_0216D5A8(mmdl);
    if (eventType == 13 || (u16)(eventType + 0xFFF1) <= 4) {
        return 1;
    }
    return 0;
}

/* Event types that mirror the player's turns. */
int func_0219B358(Mmdl *mmdl)
{
    u32 eventType = func_0216D5A8(mmdl);
    if (eventType == 7 || eventType == 8 || eventType - 17 <= 1) {
        return 1;
    }
    return 0;
}

/* Sets the mirror side from the event type (7 and 17 mirror to the left). */
void func_0219B374(Mmdl *mmdl, MmdlMirrorState *mirror)
{
    u32 eventType = func_0216D5A8(mmdl);
    if (eventType == 7 || eventType == 17) {
        mirror->side = 0;
    } else {
        mirror->side = 1;
    }
}

/* Turns to the next direction of the side's cycle and pauses the display direction. */
void func_0219B390(Mmdl *mmdl, MmdlMirrorState *mirror)
{
    int i;
    u32 dir;
    u32 nextDir;

    dir = func_0216D5F8(mmdl);
    for (i = 0; i < 4 && dir != d_021D4FCC[mirror->side][i]; i++) {
    }
    i++;
    mirror->savedDir = dir;
    i %= 4;
    nextDir = d_021D4FCC[mirror->side][i];
    if (func_0216D55C(mmdl, 8) != 0) {
        mirror->dirWasPaused = 1;
    } else {
        mirror->dirWasPaused = 0;
    }
    func_0216D5E0(mmdl, (u16)nextDir);
    func_0216D548(mmdl, 8);
}

/* Lifts the direction pause unless it was already set before the turn. */
void func_0219B404(Mmdl *mmdl, MmdlMirrorState *mirror)
{
    if (mirror->dirWasPaused == 0) {
        func_0216D550(mmdl, 8);
    }
}

/*
 * Recursive MATCH unblocker: callee of func_02163010 (ov010) +000A.  An
 * unlabelled Thumb tail-call thunk that disasm.py emitted as a word run
 * (`ldr r3,[pc,#0]; bx r3; .word func_0219B440|1`), so no func_ label exists
 * for the caller to reach through `label`/`sole-ref/code`.  Matching it here
 * gives func_02163010's call site a `matched` witness.  Region hint ov021 is
 * required: ov009 overlaps 0x0219B414 but holds unrelated code there.
 */
int func_0219B414(Mmdl *mmdl)
{
    return func_0219B440(mmdl);
}

int func_0219B41C(Mmdl *mmdl)
{
    if (func_0219B45C(mmdl) == 0) {
        return 0;
    }
    if (func_0219B478(mmdl) != 0) {
        return 1;
    }
    return 0;
}

/*
 * Recursive MATCH dependency: target of the Thumb tail-call thunk
 * func_0219B414 (ov021).  Indexes the function-pointer table at 0x021D5278 by
 * the model's event type and tail-dispatches through it.
 */
int func_0219B440(Mmdl *mmdl)
{
    int eventType = func_0216D5A8(mmdl);

    return data_021D5278[eventType](mmdl);
}

u32 func_0219B45C(Mmdl *mmdl)
{
    return d_021D52CC[func_0216D5A8(mmdl)](mmdl);
}

u32 func_0219B478(Mmdl *mmdl)
{
    return d_021D5320[func_0216D5A8(mmdl)](mmdl);
}

/* Returns 1 when the model's grid cell is not its previous cell. */
int func_0219B494(Mmdl *mmdl)
{
    if (func_0216D83C(mmdl) != func_0216D804(mmdl)) {
        return 1;
    }
    if (func_0216D86C(mmdl) != func_0216D81C(mmdl)) {
        return 1;
    }
    return 0;
}

/* Returns 1 when the model's grid cell is its previous cell. */
int func_0219B4C8(Mmdl *mmdl)
{
    if (func_0216D83C(mmdl) != func_0216D804(mmdl)) {
        return 0;
    }
    if (func_0216D86C(mmdl) == func_0216D81C(mmdl)) {
        return 1;
    }
    return 0;
}

void func_0219B4FC(void)
{
}

int func_0219B500(void)
{
    return 0;
}

int func_0219B504(void)
{
    return 0;
}

/* Walk repeat (init). */
void func_0219B508(Mmdl *mmdl)
{
    MmdlStepRepeatWork *work = func_0216D6A0(mmdl, 9);
    work->countMax = func_0216D63C(mmdl, 1);
}

/* Walk repeat: step, count, then wait for the move to end. */
int func_0219B520(Mmdl *mmdl)
{
    MmdlStepRepeatWork *work;
    work = func_0216D6B8((void *)mmdl);
    switch (work->state) {
    case 0:
        if (func_0219B494(mmdl) == 1) {
            work->state++;
        }
        break;
    case 1:
        if (func_0219B4C8(mmdl) == 0) {
            break;
        }
        work->count++;
        if (work->count < work->countMax) {
            work->state = 0;
            break;
        }
        work->state++;
    case 2:
        if (func_0216DA5C((void *)mmdl) == 1) {
            break;
        }
        work->state++;
        work->count = 0;
        work->waitFlag = 0;
    case 3:
        return 1;
    }
    return 0;
}

/* Turn sub proc: look left and right, four times. */
int func_0219B59C(Mmdl *mmdl)
{
    MmdlTurnSubWork *work;
    int frameMax;
    work = func_0216D6B8((void *)mmdl);
    switch (work->state) {
    case 0: {
        DirGroupTable groupTable = d_021D5238;
        u16 dir = func_0216D5F8((void *)mmdl);
        work->startDir = dir;
        work->dirGroup = groupTable.group[dir];
        work->state++;
    }
    case 1: {
        LookAroundDirTable dirTable = d_021D5248;
        func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)dirTable.dir[work->dirGroup][work->dirIndex], (u16)0)));
        work->state++;
    }
    case 2:
        if (func_02197EDC(mmdl) == 0) {
            return 1;
        }
        work->state++;
    case 3:
        frameMax = 8;
        if (func_0216D5A8(mmdl) == 14 && func_0219B8A8() == 1 && func_02164168(mmdl) == 1) {
            frameMax = 4;
        }
        if (++work->frameCount < frameMax) {
            return 1;
        }
        work->frameCount = 0;
        if (++work->turnCount < 4) {
            work->dirIndex = (work->dirIndex + 1) & 1;
            work->state = 1;
            return 1;
        }
        func_0216D5E0(mmdl, work->startDir);
        work->state++;
        work->turnCount = 0;
        work->busy = 0;
    }
    return 0;
}

/* Walk repeat with spin (init): spin direction from the event type. */
void func_0219B6B0(Mmdl *mmdl)
{
    MmdlTurnSubWork *work = func_0216D6A0(mmdl, 9);
    u32 eventType;
    u8 spinDir = 1;
    work->repeatParam = func_0216D63C(mmdl, 1);
    eventType = func_0216D5A8(mmdl);
    if (eventType == 5 || eventType == 20 || eventType == 15) {
        spinDir = 0;
    }
    work->dirGroup = spinDir;
}

/* Walk repeat with spin: same steps as func_0219B520. */
int func_0219B6E0(Mmdl *mmdl)
{
    MmdlStepRepeatWork *work;
    work = func_0216D6B8((void *)mmdl);
    switch (work->state) {
    case 0:
        if (func_0219B494(mmdl) == 1) {
            work->state++;
        }
        break;
    case 1:
        if (func_0219B4C8(mmdl) == 0) {
            break;
        }
        work->count++;
        if (work->count < work->countMax) {
            work->state = 0;
            break;
        }
        work->state++;
    case 2:
        if (func_0216DA5C((void *)mmdl) == 1) {
            break;
        }
        work->state++;
        work->count = 0;
        work->waitFlag = 0;
    case 3:
        return 1;
    }
    return 0;
}

/* Turn sub proc: spin through the four directions, clockwise or not. */
int func_0219B75C(Mmdl *mmdl)
{
    SpinDirTable spinTable = d_021D5258;
    MmdlTurnSubWork *work;
    int frameMax;
    int i;
    u16 dir;
    u16 eventType;
    work = func_0216D6B8((void *)mmdl);
    switch (work->state) {
    case 0:
        dir = func_0216D5F8((void *)mmdl);
        for (i = 0; i < 4 && dir != spinTable.dir[work->dirGroup][i]; i++) {
        }
        i++;
        work->startDir = dir;
        work->dirIndex = i % 4;
        work->state++;
    case 1:
        func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)spinTable.dir[work->dirGroup][work->dirIndex], (u16)0)));
        work->state++;
    case 2:
        if (func_02197EDC(mmdl) == 0) {
            return 1;
        }
        work->state++;
    case 3:
        frameMax = 8;
        eventType = func_0216D5A8(mmdl);
        if ((eventType == 15 || eventType == 16) && func_0219B8A8() == 1 && func_02164168(mmdl) == 1) {
            frameMax = 4;
        }
        if (++work->frameCount < frameMax) {
            return 1;
        }
        work->frameCount = 0;
        if (++work->turnCount < 4) {
            work->dirIndex = (work->dirIndex + 1) % 4;
            work->state = 1;
            return 1;
        }
        func_0216D5E0(mmdl, work->startDir);
        work->state++;
        work->turnCount = 0;
        work->busy = 0;
    }
    return 0;
}

/* Is the B button held (speeds up the turn animations). */
int func_0219B8A8(void)
{
    if (func_0203630C() & 2) {
        return 1;
    }
    return 0;
}

/*
 * The step functions below take four arguments (mmdl, work, r2, r3) so that
 * r2 and r3 reach the init call, whose old-style declaration passes them on.
 */

/* Look at the player (init). */
int func_0219B8BC(Mmdl *mmdl, u32 unusedWork, u32 regR2, u32 regR3)
{
    func_0219B984(mmdl, func_0216D684(mmdl, 8, regR2, regR3));
    func_0216D674((void *)mmdl, 0);
    func_0216DA50(mmdl);
    return func_0216DAE0(mmdl, 0);
}

/* Look at the player (move). */
void func_0219B8E8(Mmdl *mmdl)
{
    MmdlLookWork *work = func_0216D69C((void *)mmdl);
    if (func_0219B984(mmdl, work)) {
        func_0216DAE0(mmdl, 0);
        while (d_021D5374[work->step](mmdl, work) == 1) {
        }
    }
}

/* Look at the player (delete). */
void func_0219B920(void) {}

/* Look at the player, step 0: turn when the player has moved. */
int func_0219B924(Mmdl *mmdl, MmdlLookWork *work)
{
    func_0216DA50(mmdl);
    func_0216DA7C(mmdl);
    if (func_0219B9D8(mmdl, work) == 1) {
        func_0219BA0C(mmdl, work);
        if (func_0219BA6C(mmdl) == 1) {
            func_0216DA44(mmdl);
            work->step++;
            return 1;
        }
    }
    return 0;
}

/* Look at the player, step 1: wait for the turn to end. */
int func_0219B968(Mmdl *mmdl, MmdlLookWork *work, u32 regR2, u32 regR3)
{
    if (func_02197EDC(mmdl) == 1) {
        func_0216DA50(mmdl);
        work->step = 0;
    }
    return 0;
}

/* Is the player present; start tracking him when he appears. */
int func_0219B984(Mmdl *mmdl, MmdlLookWork *work)
{
    if (func_0216DEE0((void *)func_0216D67C((void *)mmdl)) == 0) {
        work->tracking = 0;
        return 0;
    }
    if (work->tracking == 0) {
        func_0219B9B0(mmdl, work);
    }
    return 1;
}

/* Start tracking the player: remember his grid position. */
void func_0219B9B0(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 player = (u32)func_0216DEE0(func_0216D67C((void *)mmdl));
    work->tracking = 1;
    work->targetX = func_0216D83C((void *)player);
    work->targetZ = func_0216D86C((void *)player);
    work->lastDir = 0xFF;
}

/* Has the player left the remembered grid position. */
int func_0219B9D8(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 player = (u32)func_0216DEE0(func_0216D67C((void *)mmdl));
    int x;
    int z;
    if (player != 0) {
        x = func_0216D83C((void *)player);
        z = func_0216D86C((void *)player);
        if (x != work->targetX || z != work->targetZ) {
            return 1;
        }
    }
    return 0;
}

/* Remember the player's current grid position. */
void func_0219BA0C(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 player = (u32)func_0216DEE0(func_0216D67C((void *)mmdl));
    work->targetX = func_0216D83C((void *)player);
    work->targetZ = func_0216D86C((void *)player);
}

/* Acmd code base of the turn: the four 0x58..0x5B codes map to 0x10..0x13. */
int func_0219BA2C(Mmdl *mmdl)
{
    int acmdCode;
    func_0216DEE0(func_0216D67C((void *)mmdl));
    acmdCode = func_0216D7C4(mmdl);
    switch (acmdCode) {
    case 0x58:
        return 0x10;
    case 0x59:
        return 0x11;
    case 0x5a:
        return 0x12;
    case 0x5b:
        return 0x13;
    }
    return acmdCode;
}

/* Turn towards the player when he is on another grid cell. */
int func_0219BA6C(Mmdl *mmdl)
{
    int player;
    int x;
    int z;
    int playerX;
    int playerZ;
    int turnBase;
    player = (int)func_0216DEE0(func_0216D67C((void *)mmdl));
    x = func_0216D83C((void *)mmdl);
    z = func_0216D86C((void *)mmdl);
    playerX = func_0216D804((void *)player);
    playerZ = func_0216D81C((void *)player);
    if (x != playerX || z != playerZ) {
        turnBase = func_0219BA2C(mmdl);
        func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)((int)func_021642B4(x, z, playerX, playerZ)), (u16)turnBase)));
        return 1;
    }
    return 0;
}

/* Look at another model of the zone (init). */
void func_0219BAE0(Mmdl *mmdl)
{
    MmdlLookWork *work = func_0216D684(mmdl, 12);
    func_0219BC48(mmdl, work);
    func_0216D674((void *)mmdl, 0);
    func_0216DA50(mmdl);
    work->tracking = 0;
}

/* Look at another model of the zone (move). */
void func_0219BB08(Mmdl *mmdl)
{
    MmdlLookWork *work = func_0216D69C((void *)mmdl);
    if (func_0219BC48(mmdl, work)) {
        while (d_021D538C[work->step](mmdl, work) == 1) {
        }
    }
}

/* Look at another model of the zone (delete). */
void func_0219BB38(void) {}

/* Forget the other model being watched. */
void func_0219BB3C(void)
{
    MmdlLookWork *work = func_0216D69C();
    work->tracking = 0;
}

/* Look at another model, step 0: turn when it has moved. */
int func_0219BB48(Mmdl *mmdl, MmdlLookWork *work)
{
    func_0216DA50(mmdl);
    func_0216DA7C(mmdl);
    if (func_0219BCE4(mmdl, work) == 1 && func_0219BD30(mmdl, work) == 1) {
        func_0216DA44(mmdl);
        work->step++;
        return 1;
    }
    return 0;
}

/* Look at another model, step 1: wait for the turn to end. */
int func_0219BB84(Mmdl *mmdl, MmdlLookWork *work, u32 regR2, u32 regR3)
{
    if (func_02197EDC(mmdl) == 0) {
        return 0;
    }
    func_0216DA50(mmdl);
    work->step = 0;
    return 0;
}

/* Find another model of the same zone and area that this one can look at. */
Mmdl *func_0219BBA4(Mmdl *mmdl)
{
    Mmdl *other;
    u32 iter;
    u32 eventType;
    int zoneId;
    void *mmdlSys;
    int area;
    iter = 0;
    eventType = func_0216D5A8(mmdl);
    zoneId = func_0216D590((void *)mmdl);
    mmdlSys = func_0216D67C(mmdl);
    area = func_021AE884(mmdl);
    switch (eventType) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 20:
        while (func_0216DD1C(mmdlSys, (void **)(&other), &iter) == 1) {
            if (mmdl != other && zoneId == func_0216D590((void *)other) && area == func_021AE884(other)) {
                return other;
            }
        }
        break;
    }
    return 0;
}

/* Search for the model to watch; start tracking it when first found. */
int func_0219BC48(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 iter;
    Mmdl *other;
    int zoneId;
    int area;
    void *mmdlSys;
    mmdlSys = func_0216D67C(mmdl);
    iter = 0;
    zoneId = func_0216D590((void *)mmdl);
    area = func_021AE884(mmdl);
    while (func_0216DD1C(mmdlSys, (void **)(&other), &iter) == 1) {
        if (mmdl != other && zoneId == func_0216D590((void *)other) && area == func_021AE884(other)) {
            if (work->tracking == 0) {
                func_0219BCC0(mmdl, work, other);
            }
            return 1;
        }
    }
    work->tracking = 0;
    return 0;
}

/* Start tracking the other model: remember its grid position. */
int func_0219BCC0(Mmdl *mmdl, MmdlLookWork *work, Mmdl *fellow)
{
    work->tracking = 1;
    work->targetX = func_0216D83C((void *)fellow);
    work->targetZ = func_0216D86C((void *)fellow);
    work->lastDir = 255;
    work->target = fellow;
    return 255;
}

/* Did the watched model move off its cell and become able to be looked at. */
int func_0219BCE4(Mmdl *mmdl, MmdlLookWork *work)
{
    Mmdl *fellow = work->target;
    u32 x = func_0216D83C((void *)mmdl);
    u32 z = func_0216D86C((void *)mmdl);
    u32 fellowX = func_0216D804((void *)fellow);
    u32 fellowZ = func_0216D81C((void *)fellow);
    if (x != fellowX || z != fellowZ) {
        if (func_0216DA5C((void *)fellow) == 1 || func_0216D57C((void *)fellow, 0x1808) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Turn towards the watched model. */
int func_0219BD30(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 x = func_0216D83C((void *)mmdl);
    u32 z = func_0216D86C((void *)mmdl);
    u32 savedX = func_0216D83C((void *)(work->target));
    u32 savedZ = func_0216D86C((void *)(work->target));
    u32 fellowX = func_0216D804((void *)(work->target));
    u32 fellowZ = func_0216D81C((void *)(work->target));
    u32 dir;
    if (x == savedX && z == savedZ) {
        return 0;
    }
    dir = func_021642B4(x, z, fellowX, fellowZ);
    x += (u32)func_021641E8((u16)dir);
    z += func_021641F8(dir);
    if (x != savedX || z != savedZ) {
        func_0216D438(mmdl, (u16)func_02197E7C(dir & 0xFFFF, 12));
        return 1;
    }
    return 0;
}

/* Hide in a field effect (init, shared by the four hide move codes). */
void func_0219BDC4(Mmdl *mmdl, u32 kind)
{
    MmdlVec drawOffset;
    u32 hideBit = 8;
    ((MmdlHideWork *)func_0216D684(mmdl, 8))->kind = kind;
    func_0216D674((void *)mmdl, 0);
    func_0216DA50(mmdl);
    func_0216D568((void *)mmdl, hideBit << 12);
    drawOffset = d_021D5474;
    func_0216D8C0(mmdl, &drawOffset);
}

void func_0219BE0C(Mmdl *mmdl) { func_0219BDC4(mmdl, 0); }
void func_0219BE18(Mmdl *mmdl) { func_0219BDC4(mmdl, 1); }
void func_0219BE24(Mmdl *mmdl) { func_0219BDC4(mmdl, 1); }
void func_0219BE30(Mmdl *mmdl) { func_0219BDC4(mmdl, 0); }

/* Hide (move). */
void func_0219BE3C(Mmdl *mmdl)
{
    MmdlHideWork *work = func_0216D69C((void *)mmdl);
    while (d_021D537C[work->step](mmdl, work) == 1) {
    }
}

/* Hide (delete): remove the field effect. */
void func_0219BE60(Mmdl *mmdl)
{
    u32 effect = func_0219BF48(mmdl);
    if (effect != 0) {
        func_021AC154(effect);
    }
}

/* Hide (recover after a map change). */
void func_0219BE70(Mmdl *mmdl)
{
    MmdlHideWork *work = func_0216D69C((void *)mmdl);
    MmdlVec drawOffset;
    work->step = 0;
    func_0219BF3C(mmdl, 0);
    if (work->noEffect == 0) {
        drawOffset = d_021D5480;
        func_0216D8C0(mmdl, &drawOffset);
        func_0216D568((void *)mmdl, 2 << 14);
    }
}

/* Create the hide field effect of the given kind. */
int func_0219BEB4(Mmdl *mmdl, u32 kind)
{
    return func_021D046C(func_02188CD0((u8 *)func_0216D534(func_0216D67C((void *)mmdl))), mmdl, kind);
}

/* Hide, step 0: create the effect and pause the model's movement. */
int func_0219BED0(Mmdl *mmdl, MmdlHideWork *work)
{
    if (work->noEffect == 0) {
        func_0219BF3C(mmdl, func_0219BEB4(mmdl, work->kind));
    }
    func_0216DA50(mmdl);
    func_0216DA7C(mmdl);
    work->step++;
    return 0;
}

/* Hide, step 1: keep the effect alive and the model hidden. */
int func_0219BF00(Mmdl *mmdl, MmdlHideWork *work, u32 regR2, u32 regR3)
{
    if (work->noEffect == 0) {
        if (func_0219BF48(mmdl) == 0) {
            if (func_0216DB24(mmdl) == 1) {
                func_0219BF3C(mmdl, func_0219BEB4(mmdl, work->kind));
            }
        }
        func_0216D568((void *)mmdl, (2 << 14));
    }
    return 0;
}

/* Store the hide field effect in the move proc work. */
void func_0219BF3C(Mmdl *mmdl, u32 effect)
{
    ((MmdlHideWork *)func_0216D69C())->effect = effect;
}

/* Get the hide field effect of the move proc work. */
int func_0219BF48(Mmdl *mmdl)
{
    return ((MmdlHideWork *)func_0216D69C((void *)mmdl))->effect;
}

/* Do not create a field effect for this hidden model. */
void func_0219BF54(Mmdl *mmdl)
{
    MmdlHideWork *work = func_0216D69C();
    work->noEffect = 1;
}

/*
 * Face a direction (init). The dir argument is unused here; the model
 * turns to direction 0 first and the step functions set the real one.
 */
u32 func_0219BF60(mmdl, dir, flag, regR3)
Mmdl *mmdl;
u32 dir, flag, regR3;
{
    MmdlFaceDirWork *work = func_0216D684(mmdl, 4, flag, regR3);
    work->dir = 9;
    work->flag = flag;
    return func_0216D5E0(mmdl, 0);
}

u32 func_0219BF7C(Mmdl *mmdl) { return func_0219BF60(mmdl, 0, 0); }
u32 func_0219BF88(Mmdl *mmdl) { return func_0219BF60(mmdl, 1, 0); }
u32 func_0219BF94(Mmdl *mmdl) { return func_0219BF60(mmdl, 2, 0); }
u32 func_0219BFA0(Mmdl *mmdl) { return func_0219BF60(mmdl, 3, 0); }
u32 func_0219BFAC(Mmdl *mmdl) { return func_0219BF60(mmdl, 0, 1); }
u32 func_0219BFB8(Mmdl *mmdl) { return func_0219BF60(mmdl, 1, 1); }
u32 func_0219BFC4(Mmdl *mmdl) { return func_0219BF60(mmdl, 2, 1); }
u32 func_0219BFD0(Mmdl *mmdl) { return func_0219BF60(mmdl, 3, 1); }

/* Face a direction (move). */
void func_0219BFDC(Mmdl *mmdl)
{
    MmdlFaceDirWork *work = func_0216D69C((void *)mmdl);
    while (d_021D53A0[work->step](mmdl, work) == 1) {
    }
}

/* Face a direction, step 0: turn to the model's display direction. */
int func_0219C000(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3)
{
    func_0216D438(mmdl, (((u32)func_02197E7C((u32)(((u32)func_0216D5F8((void *)mmdl) << 16) >> 16), (u32)0) << 16) >> 16));
    func_0216DA50(mmdl);
    func_0216DA7C(mmdl);
    ((MmdlFaceDirWork *)work)->step = 1;
    return 1;
}

/* Face a direction, step 1: wait for the turn to end. */
int func_0219C034(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3)
{
    if (func_02197EDC(mmdl) == 1) {
        ((MmdlFaceDirWork *)work)->step = 2;
        return 1;
    }
    return 0;
}

/* Face a direction, step 2: take the player's direction when none is set. */
int func_0219C04C(Mmdl *mmdl, s8 *work)
{
    u32 player;
    if (work[1] == 9) {
        player = (u32)func_0216DEE0(func_0216D67C((void *)mmdl));
        if (player != 0) {
            work[1] = func_0216D608((void *)player);
        }
    }
    func_0216DA50(mmdl);
    func_0216DA7C(mmdl);
    work[0] = 3;
    return 1;
}

/* Face a direction, step 3: turn to the player's direction. */
int func_0219C080(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3)
{
    func_0216D438(mmdl, (((u32)func_02197E7C((u32)func_0216D608(func_0216DEE0((void *)func_0216D67C((void *)mmdl))), (u32)0) << 16) >> 16));
    ((MmdlFaceDirWork *)work)->step = 4;
    return 1;
}

/* Face a direction, step 4: wait for the turn to end. */
int func_0219C0AC(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3)
{
    if (func_02197EDC(mmdl) == 0) {
        return 0;
    }
    func_0216DA50(mmdl);
    func_0216DA7C(mmdl);
    ((MmdlFaceDirWork *)work)->step = 2;
    return 0;
}

/* Walk along a wall (init). */
void func_0219C0D4(mmdl, mode, hand, regR3)
u32 mmdl, mode, hand, regR3;
{
    MmdlWallWalkWork *work = func_0216D684(mmdl, 12, hand, regR3);
    work->mode = mode;
    work->hand = hand;
}

void func_0219C0E8(Mmdl *mmdl) { func_0219C0D4(mmdl, 0, 0); }
void func_0219C0F4(Mmdl *mmdl) { func_0219C0D4(mmdl, 1, 1); }
void func_0219C100(Mmdl *mmdl) { func_0219C0D4(mmdl, 2, 0); }
void func_0219C10C(Mmdl *mmdl) { func_0219C0D4(mmdl, 2, 1); }

/* Walk along a wall (move). */
void func_0219C118(Mmdl *mmdl)
{
    MmdlWallWalkWork *work = func_0216D69C((void *)mmdl);
    while (d_021D5394[work->step](mmdl, work) == 1) {
    }
}

/* Walk along a wall, step 0: stop the previous move. */
int func_0219C13C(Mmdl *mmdl, MmdlWallWalkWork *work)
{
    func_0216DA50(mmdl);
    work->step++;
    return 1;
}

/* Walk along a wall, step 1: try a step. */
int func_0219C150(Mmdl *mmdl, MmdlWallWalkWork *work)
{
    func_0219C338(mmdl, work, 12);
    work->step++;
    return 1;
}

/* Walk along a wall, step 2: wait for the step to end. */
int func_0219C164(Mmdl *mmdl, MmdlWallWalkWork *work, u32 regR2, u32 regR3)
{
    if (func_02197EDC(mmdl) == 1) {
        func_0216DA50(mmdl);
        work->step = 0;
    }
    return 0;
}

/*
 * result = 0 is the first statement: its early live range pushes mmdl to a
 * stack spill and leaves ip for &checkPos.
 */
/* Is the cell next to pos (offset table A) a blocking attribute. */
int func_0219C180(Mmdl *mmdl, MmdlVec *pos, int dir, int hand)
{
    int result;
    s16 gridX;
    s16 gridZ;
    MmdlVec checkPos;
    u32 attr;
    result = 0;
    checkPos = *pos;
    gridX = (pos->x >> 4) / 4096;
    gridZ = (pos->z >> 4) / 4096;
    gridX += (s16)d_021D53B4[dir][hand];
    gridZ += (s16)d_021D53D4[dir][hand];
    checkPos.x = gridX << 16;
    checkPos.z = gridZ << 16;
    if (func_02163E34(mmdl, &checkPos, &attr) == 1 && func_021AB11C(attr) != 0) {
        result = 1;
    }
    return result;
}

/* Same as func_0219C180 with offset table B. */
int func_0219C20C(Mmdl *mmdl, MmdlVec *pos, int dir, int hand)
{
    int result;
    s16 gridX;
    s16 gridZ;
    MmdlVec checkPos;
    u32 attr;
    result = 0;
    checkPos = *pos;
    gridX = (pos->x >> 4) / 4096;
    gridZ = (pos->z >> 4) / 4096;
    gridX += (s16)d_021D5414[dir][hand];
    gridZ += (s16)d_021D5434[dir][hand];
    checkPos.x = gridX << 16;
    checkPos.z = gridZ << 16;
    if (func_02163E34(mmdl, &checkPos, &attr) == 1 && func_021AB11C(attr) != 0) {
        result = 1;
    }
    return result;
}

/* Table A wall check at the model's position. */
int func_0219C298(Mmdl *mmdl, int dir, int hand)
{
    MmdlVec pos;
    func_0216D88C((const struct Actor *)mmdl, (struct VecFx32 *)&pos);
    return func_0219C180(mmdl, &pos, dir, hand);
}

/* Table B wall check at the model's position. */
int func_0219C2BC(Mmdl *mmdl, int dir, int hand)
{
    MmdlVec pos;
    func_0216D88C((const struct Actor *)mmdl, (struct VecFx32 *)&pos);
    return func_0219C20C(mmdl, &pos, dir, hand);
}

/* Direction to walk next along the wall; 9 when there is no wall. */
int func_0219C2E0(Mmdl *mmdl, int dir, int hand)
{
    if (func_0219C298(mmdl, dir, hand) == 0) {
        if (func_0219C2BC(mmdl, dir, hand) == 0) {
            return 9;
        }
        dir = d_021D53F4[dir][hand];
    }
    return dir;
}

/* Pick the direction along the wall and hit-check it; 0 when 9 (none). */
int func_0219C314(Mmdl *mmdl, int *dir, u32 hand)
{
    int newDir = func_0219C2E0(mmdl, *dir, hand);
    *dir = newDir;
    if (newDir != 9) {
        return func_021639C0(mmdl, newDir);
    }
    return 0;
}

/* Walk one step along the wall, turning to the other hand when blocked. */
int func_0219C338(Mmdl *mmdl, MmdlWallWalkWork *work, u32 acmdKind)
{
    u32 dir;
    u32 hand;
    u32 acmdCode;
    int hit;
    hand = work->hand;
    dir = func_0216D608((void *)mmdl);
    hit = func_0219C314(mmdl, (int *)(&dir), hand);
    if (dir == 9) {
        dir = func_0216D608((void *)mmdl);
        func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)dir, (u16)0x1c)));
        return 0;
    }
    if (hit == 0) {
        acmdCode = (u32)func_02197E7C((u16)dir, (u16)acmdKind);
        func_0216DA44(mmdl);
        func_0216D438(mmdl, (u16)acmdCode);
        return 1;
    }
    if ((1 & hit) && work->mode == 2) {
        dir = func_021642A4(func_0216D608((void *)mmdl));
        hand = d_021D5384[hand];
        work->hand = hand;
        hit = func_0219C314(mmdl, (int *)(&dir), hand);
        if (dir == 9) {
            dir = func_0216D608((void *)mmdl);
            func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)dir, (u16)0x1c)));
            return 0;
        }
        if (hit == 0) {
            acmdCode = (u32)func_02197E7C((u16)dir, (u16)acmdKind);
            func_0216DA44(mmdl);
            func_0216D438(mmdl, (u16)acmdCode);
            return 1;
        }
    }
    if (hit & 2) {
        dir = d_021D5454[dir][hand];
        hit = func_0219C314(mmdl, (int *)(&dir), hand);
        if (dir == 9) {
            dir = func_0216D608((void *)mmdl);
            func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)dir, (u16)0x1c)));
            return 0;
        }
        if (hit == 0) {
            acmdCode = (u32)func_02197E7C((u16)dir, (u16)acmdKind);
            func_0216DA44(mmdl);
            func_0216D438(mmdl, (u16)acmdCode);
            return 1;
        }
    }
    dir = func_0216D608((void *)mmdl);
    func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)dir, (u16)0x1c)));
    return 0;
}
