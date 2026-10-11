/*
 * file:     btl_server_p13.c
 * unit:     yes
 * function: func_021C7D34, func_021C7D44, func_021C7D54, func_021C7DAC, func_021C7E14, func_021C7EC4, func_021C7ED8, func_021C7EEC, func_021C7F04, func_021C7F24, func_021C7F4C, func_021C7F68, func_021C7FCC, func_021C7FE0, func_021C8010, func_021C8020, func_021C8030, func_021C804C, func_021C80AC, func_021C8114, func_021C8120, func_021C812C, func_021C8130, func_021C8138, func_021C8140, func_021C814C, func_021C815C, func_021C8168, func_021C8174, func_021C8180, func_021C818C, func_021C81C8, func_021C81D0, func_021C8234, func_021C824C, func_021C8288, func_021C8290, func_021C82B8, func_021C82C4, func_021C82D0, func_021C82F4, func_021C8300, func_021C830C, func_021C831C, func_021C8338, func_021C8348, func_021C8374, func_021C83A0, func_021C83CC, func_021C83D4, func_021C83DC, func_021C83E8, func_021C8408, func_021C8434, func_021C846C, func_021C8494, func_021C84AC, func_021C84D0, func_021C84D8, func_021C84E0, func_021C84E8, func_021C84F4, func_021C8534, func_021C8588, func_021C859C, func_021C85B8, func_021C85D4, func_021C8810, func_021C8828, func_021C8838, func_021C8860, func_021C888C, func_021C88A4, func_021C88B4, func_021C88C8, func_021C88E4, func_021C8910, func_021C8918, func_021C8C6C
 * address:  0x021C7D34
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689D5F4 0x0689D5F4 thumb ov095
 *   func_0689D5FC 0x0689D5FC thumb ov095
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   func_021C64B4  0x021C64B4  thumb  ov093
 *   func_021C6E3C  0x021C6E3C  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021C1E74  0x021C1E74  thumb  ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B997C 0x021B997C thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B9BC4 0x021B9BC4 thumb ov093
 *   func_021B8778   0x021B8778  thumb  ov093
 *   func_021B98A4   0x021B98A4  thumb  ov093
 *   func_021D5B68   0x021D5B68  thumb  ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_0689D588 0x0689D588 thumb ov095
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0201B718 0x0201B718 thumb
 *   func_021BC948   0x021BC948  thumb ov093
 *   func_021C6F0C   0x021C6F0C  thumb  ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021C2AB0   0x021C2AB0  thumb ov093
 *   func_021BFA00 0x021BFA00 thumb ov093
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_06898CF4  0x06898CF4  thumb  ov095
 *   func_021B9AE0 0x021B9AE0 thumb ov093
 *   func_021C82E4 0x021C82E4 thumb ov093
 *   func_068982AC  0x068982AC  thumb
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021C2AF0 0x021C2AF0 thumb ov093
 *   func_021D67E8 0x021D67E8 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_021C2E4C   0x021C2E4C  thumb ov093
 *   func_021BC2B0   0x021BC2B0  thumb ov093
 *   func_021BB908 0x021BB908 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BB914 0x021BB914 thumb ov093
 *   func_021C845C 0x021C845C thumb ov093
 *   func_021BE52C 0x021BE52C thumb ov093
 *   func_021BFEAC 0x021BFEAC thumb ov093
 *   func_021BFF60   0x021BFF60  thumb  ov093
 *   func_021C2128 0x021C2128 thumb ov093
 *   func_021BDBB8   0x021BDBB8  thumb ov093
 *   func_021CC668   0x021CC668  thumb ov093
 *   func_021C8578  0x021C8578  thumb  ov093
 *   func_021C87A0 0x021C87A0 thumb ov093
 *   func_021C87B0 0x021C87B0 thumb ov093
 *   func_021C87C0 0x021C87C0 thumb ov093
 *   func_021C87D0 0x021C87D0 thumb ov093
 *   func_021C87E0 0x021C87E0 thumb ov093
 *   func_021C87F0 0x021C87F0 thumb ov093
 *   func_021C8800 0x021C8800 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_02082BCC 0x02082BCC arm
 *   func_021CC9AC   0x021CC9AC  thumb  ov093
 *   func_021CCA74   0x021CCA74  thumb  ov093
 *   func_021CC96C  0x021CC96C  thumb  ov093
 *   func_021CC9A4  0x021CC9A4  thumb  ov093
 *   func_021B9940   0x021B9940  thumb ov093
 *   func_021C8CBC   0x021C8CBC  thumb ov093
 *   func_021C8D0C   0x021C8D0C  thumb ov093
 *   func_021C8D2C   0x021C8D2C  thumb ov093
 *   func_021C8DE4   0x021C8DE4  thumb ov093
 *   func_021C8E58   0x021C8E58  thumb ov093
 *   func_021C8F24   0x021C8F24  thumb ov093
 *   func_021C8FA4   0x021C8FA4  thumb ov093
 *   func_021C9010   0x021C9010  thumb ov093
 *   func_021C9068   0x021C9068  thumb ov093
 *   func_021C9178   0x021C9178  thumb ov093
 *   func_021C9250   0x021C9250  thumb ov093
 *   func_021C9394   0x021C9394  thumb ov093
 *   func_021C9448   0x021C9448  thumb ov093
 *   func_021C947C   0x021C947C  thumb ov093
 *   func_021C94C8   0x021C94C8  thumb ov093
 *   func_021C95D0   0x021C95D0  thumb ov093
 *   func_021C962C   0x021C962C  thumb ov093
 *   func_021C96D4   0x021C96D4  thumb ov093
 *   func_021C9728   0x021C9728  thumb ov093
 *   func_021C9750   0x021C9750  thumb ov093
 *   func_021C9778   0x021C9778  thumb ov093
 *   func_021C97A4   0x021C97A4  thumb ov093
 *   func_021C97D0   0x021C97D0  thumb ov093
 *   func_021C9828   0x021C9828  thumb ov093
 *   func_021C9898   0x021C9898  thumb ov093
 *   func_021C98C4   0x021C98C4  thumb ov093
 *   func_021C98E4   0x021C98E4  thumb ov093
 *   func_021C9A24   0x021C9A24  thumb ov093
 *   func_021C9A60   0x021C9A60  thumb ov093
 *   func_021C9BB8   0x021C9BB8  thumb ov093
 *   func_021C9CC0   0x021C9CC0  thumb ov093
 *   func_021C9DCC   0x021C9DCC  thumb ov093
 *   func_021C9DE8   0x021C9DE8  thumb ov093
 *   func_021C9E3C   0x021C9E3C  thumb ov093
 *   func_021C9ECC   0x021C9ECC  thumb ov093
 *   func_021C9F0C   0x021C9F0C  thumb ov093
 *   func_021C9F4C   0x021C9F4C  thumb ov093
 *   func_021C9F6C   0x021C9F6C  thumb ov093
 *   func_021CA128   0x021CA128  thumb ov093
 *   func_021CA158   0x021CA158  thumb ov093
 *   func_021CA1D0   0x021CA1D0  thumb ov093
 *   func_021CA248   0x021CA248  thumb ov093
 *   func_021CA270   0x021CA270  thumb ov093
 *   func_021CA2E8   0x021CA2E8  thumb ov093
 *   func_021CA318   0x021CA318  thumb ov093
 *   func_021CA370   0x021CA370  thumb ov093
 *   func_021CA394   0x021CA394  thumb ov093
 *   func_021CA3AC   0x021CA3AC  thumb ov093
 *   func_021CA3D0   0x021CA3D0  thumb ov093
 *   func_021CA47C   0x021CA47C  thumb ov093
 *   func_021CA570   0x021CA570  thumb ov093
 *   func_021CA5CC   0x021CA5CC  thumb ov093
 *   func_021CA6C4   0x021CA6C4  thumb ov093
 *   func_021CA6FC   0x021CA6FC  thumb ov093
 *   func_021CA738   0x021CA738  thumb ov093
 *   func_021CA748   0x021CA748  thumb ov093
 *   func_021CA7C4   0x021CA7C4  thumb ov093
 *   func_021CA7D4   0x021CA7D4  thumb ov093
 *   func_021CC960   0x021CC960  thumb ov093
 *   func_021CC974   0x021CC974  thumb ov093
 *   func_021CC99C   0x021CC99C  thumb ov093
 *   func_021C8CAC  0x021C8CAC  thumb  ov093
 *   func_021C60D4  0x021C60D4  thumb  ov093
 */
#include "../../matched/include/Obj02135.h"
#include "../../matched/include/Obj18325.h"
#include "../../matched/include/Obj21110.h"
#include "../../matched/include/Obj21111.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13340.h"
#include "../../matched/include/Obj18333.h"
#include "../../matched/include/Obj26329.h"
#include "../../matched/include/Obj26330.h"
#include "../../matched/include/Obj18335.h"
#include "../../matched/include/Obj18336.h"
#include "../../matched/include/Obj18337.h"
#include "../../matched/include/Obj13341.h"
#include "../../matched/include/Obj21115.h"
#include "../../matched/include/Obj21118.h"
#include "../../matched/include/Obj21119.h"
#include "../../matched/include/Obj21120.h"
#include "../../matched/include/Obj13342.h"
#include "../../matched/include/Obj09974.h"
#include "../../matched/include/Obj21121.h"
#include "../../matched/include/Obj00294.h"
#include "../../matched/include/Obj18339.h"
#include "../../matched/include/Obj21124.h"
#include "../../matched/include/Obj21125.h"

struct R4;
struct Out64B4;
struct Unk021B8CB0;
struct QF;
struct Unk021D62A8;
struct UtilWork;
struct Pack;
struct Rec;
struct Q9;
struct S;
struct Cmd;
struct Q;
struct Q10;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Flag { u8 pad[0x78a]; u8 low:3; u8 set:1; u8 high:4; };

typedef struct { u32 lo : 4; u32 hi : 28; } W;

typedef union { u32 u; W w; } U;

typedef struct { u8 *a; U b; u32 c; u32 d; } E;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */
struct Q7 { u8 pad[0x10]; u32 v; };

typedef struct { u32 f0; u8 pad[60]; } E64;

typedef short s16_021C82F4;

typedef int s32_021C82F4;

struct Bits { unsigned char a:1; unsigned char rest:7; };

typedef signed short s16_021C83CC;

typedef signed int s32_021C83CC;

struct Flags_021C7D34 { u8 low:5; u8 flag:1; u8 high:2; };

struct Flags_021C8588 { u8 low : 3; u8 a : 1; u8 b : 1; u8 high : 3; };

struct Unk021BD1E0 {
    u16 f0; u8 f2; u8 f3; u8 f4;
    u8 b0 : 1; u8 b1 : 1; u8 rest : 6;
};

struct Packed021C8810 { u16 low : 8; u16 high : 8; };

struct S {
    u16 x;
    u16 y : 8;
    u16 n : 7;
    u16 z : 1;
    u32 arr[8];
};

struct Packed021C888C { u16 low : 8; u16 index : 7; u16 active : 1; };

typedef struct {
    u32 id : 8;
    u32 client : 5;
    u32 unk13 : 11;
    u32 ignoreIfBusy : 1;
    u32 checkFainted : 1;
    u32 unk26 : 6;
} BtlCmd;

typedef struct {
    u8 unk0[8];
    void *party;        /* 0x0008 */
    u8 unk0C[0x1D68];
    u8 queue[4];        /* 0x1D74 */
} BattleCtx;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent_021C8D2C;

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent;

extern int func_0689D5F4(u8 *p, int i);
extern int func_0689D5FC(u8 *p, int i);
extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u32 a, u32 b);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D6C24(struct R4 *p);
extern u8 *func_021B937C(int a, char *b, u8 *c);
extern void func_021C64B4(u8 *p, int q, u8 *a, struct Out64B4 *out);
extern int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
extern u32 func_0201C314(void *p);
extern int func_021C1E74(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);
extern u8 func_021B8DDC(u32 x);
extern int func_021B997C(u8 *, unsigned int);
extern u8 *func_021BB85C(u8 *, unsigned int);
extern u32 func_021B8588(void **p);
extern u8 func_021B9BC4(u8 *, int);
extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *func_021B98A4(char *const *q, u8 b);
extern int func_021D5B68(void *p);
extern char *func_021B9AF8(char *, int);
extern u8 func_021B9010(u8 *p, u8 k);
extern int func_021B8B9C(u8 *, unsigned int);
extern int func_021B8D8C(void *, void *, unsigned int);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D80BC(void *, int, int, u16);
extern int func_0689D588(u8 *, int);
extern void *func_021B86B8(void ***p);
char *func_021B8714(char **p);
unsigned int func_021B8670(unsigned int **p);
extern u16 func_021D5444(struct QF *p);
extern unsigned int func_0201B718(void *, unsigned int, unsigned int, unsigned int);
extern u16 func_021BC948(u8 *p, u8 *x, int flag);
extern int func_021C6F0C(u8 *p, u8 *a, int k);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021EF948(int);
extern int func_021C2AB0(u8 *p);
extern int func_021BFA00(u8 *, u8 *, u8 *, void *);
void func_021B911C(int);
int func_06898CF4(int a, int b);
extern u8 func_021B9AE0(unsigned int);
extern int func_021C82E4(unsigned int, int);
extern int func_068982AC(int);
extern int func_021D5C30(struct UtilWork *p);
extern u8 func_021D69AC(u8 *, int);
extern int func_021C2AF0(u8 *, u8 *);
extern u16 func_021D67E8(u8 *p);
extern u32 func_021D7B10(u32, u32);
extern u32 func_021C2E4C(u8 *p);
extern int func_021BC2B0(u8 *p);
extern void func_021BB908(int *, int);
extern u8 func_021B8FF4(u8 *);
extern void func_021BB914(int *);
extern int func_021C845C(u8 *, int);
extern void func_021BE52C(u8 *, int, int, int);
extern int func_021BFEAC(u8 *, u8 *, u8 *, int *);
extern void func_021BFF60(u8 *p, u8 *a, int z);
extern int func_021C2128(u8 *p, u8 *a);
extern void func_021BDBB8(u8 *p, u8 *a);
extern int func_021CC668(u8 *p);
extern int func_021C8578(u8 *p, int v, u32 *out);
extern void func_021C87A0(void *);
extern void func_021C87B0(void *);
extern void func_021C87C0(void *);
extern void func_021C87D0(void *);
extern void func_021C87E0(void *);
extern void func_021C87F0(void *);
extern void func_021C8800(void *);
extern void func_021BD1E0(struct Unk021BD1E0 *);
extern void func_02082BCC(void *, int, u32);
extern struct Rec *func_021CC9AC(struct Pack *p, int id, int b);
extern void func_021CCA74(void *s, void *cmd);
extern int func_021CC96C(struct Q9 *p);
extern u32 func_021CC9A4(u32 *p);
extern unsigned short func_021CC960(struct S *p);
extern int func_021CC99C(struct Q10 *p);
extern void func_021CC974(void *q, int r);
extern u8 *func_021B9940(char *p, u8 i);
extern u8 func_021C9DE8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8CBC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8D0C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C96D4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8D2C(int p, const Ent_021C8D2C *e, int c);
extern u8 func_021C8DE4(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C8E58(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8F24(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8FA4(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9010(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9068(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9178(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9250(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9394(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C947C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C94C8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9448(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C95D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C962C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9728(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9750(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9778(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C97A4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C97D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9828(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9898(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C98C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C98E4(u8 *w, struct Cmd *c);
extern u8 func_021C9A24(void *p, const struct Cmd *q);
extern u8 func_021C9A60(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9BB8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9DCC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9E3C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9ECC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9CC0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F0C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F4C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F6C(u8 *p, u8 *q);
extern u8 func_021CA128(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA158(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA1D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA248(u8 *p, const u8 *q);
extern u8 func_021CA270(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA2E8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA318(u8 *p, const struct Q *q);
extern u8 func_021CA370(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA394(u8 *p, const u8 *q);
extern u8 func_021CA3AC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA3D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA47C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA570(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA5CC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA6C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA6FC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA738(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA748(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA7C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA7D4(BattleCtx *s, BtlCmd *cmd);
extern int func_021C8CAC(int a, u8 b);
extern void func_021C60D4(u8 *p, u8 *a);
int func_021C7D34(char *p, int i);
int func_021C7D44(char *p, int i);
u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
int func_021C7DAC(u8 *p, int a, int b, int c);
u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
u32 func_021C7EC4(u8 *p);
int func_021C7ED8(u8 *p, int i);
int func_021C7EEC(u8 *p, int i);
int func_021C7F04(u8 *p, int i);
int func_021C7F24(u8 *p, int i);
int func_021C7F4C(struct Flag *p);
u8 func_021C7F68(int *p, int b, u8 *out);
char *func_021C7FCC(u8 *p, int i);
char *func_021C7FE0(u8 *p, int v);
int func_021C8010(u8 *p, unsigned int v);
u8 func_021C8020(u8 *p, u8 v);
int func_021C8030(u8 *p, int v, u16 k);
int func_021C804C(S *p, u8 key, u32 *out);
int func_021C80AC(u8 *p, int key);
u16 func_021C8114(u8 *p);
u8 *func_021C8120(u8 *p, int b);
u8 *func_021C812C(u8 *p);
u8 *func_021C8130(u8 *p);
u16 func_021C8138(struct Q7 *p);
unsigned char func_021C8140(char *p, int i);
int func_021C814C(u8 *p, int v);
int func_021C815C(int *p);
void func_021C8168(int *p);
int func_021C8174(int *p);
int func_021C8180(int *p);
int func_021C818C(u8 *p, int v);
u16 func_021C81C8(u8 *p, u8 *x, int flag);
u16 func_021C81D0(u8 *p, u8 *a, u32 y);
int func_021C8234(u8 *p, int i);
int func_021C824C(u8 *p, int v);
int func_021C8288(u8 *p);
int func_021C8290(u8 *p, int a, int b, void *item);
void func_021C82B8(int *p);
int func_021C82C4(int a, int b, int c);
int func_021C82D0(int unused, unsigned int v, int k);
int func_021C82F4(int a, int b, int c);
u32 func_021C8300(int *p, u8 k);
unsigned int func_021C830C(u8 *p);
void func_021C831C(u8 *p, int v);
int func_021C8338(unsigned char *p, int i);
int func_021C8348(u8 *p, int i);
int func_021C8374(u8 *p, int i);
u32 func_021C83A0(u8 *p, int i);
u32 func_021C83CC(u8 *p);
int func_021C83D4(u8 *p);
void func_021C83DC(char *p, int x);
int func_021C83E8(unsigned char *p, int i, int b);
void func_021C8408(u8 *p, int a);
void func_021C8434(u8 *p, int a, int b);
int func_021C846C(u8 *p, int a, int b, int *out);
void func_021C8494(u8 *p, int i);
int func_021C84AC(u8 *p, u8 *a, u8 *out);
void func_021C84D0(u8 *p, u8 *a);
int func_021C84D8(u8 *p);
void func_021C84E0(unsigned char *p, unsigned int v);
void func_021C84E8(u8 *p);
void func_021C84F4(unsigned char *p, unsigned int v);
int func_021C8534(u8 *p);
void func_021C8588(unsigned char *p);
void func_021C859C(u8 *p);
void func_021C85B8(u8 *p);
void func_021C85D4(u8 *p, int index, int clear);
void func_021C8810(u8 *p);
u32 func_021C8828(u8 *p);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, u32 val);
void func_021C888C(u8 *p, u32 v);
void *func_021C88A4(char *p, int a, int b);
void func_021C88B4(void *a, int k, int b);
void func_021C88C8(void *a, void *b);
int func_021C88E4(u8 *p);
int func_021C8910(u8 *p);
void func_021C8918(BattleCtx *s, BtlCmd *cmd);
u8 func_021C8C6C(BattleCtx *a, BtlCmd *e);











/*
 * witness: owned verified ov095 leaf 0x0689D5F4 resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5F4 + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 */
int func_021C7D34(char *p, int i) { return func_0689D5F4((u8 *)(p + 0x1ab8), i); }











/*
 * witness: owned verified ov095 leaf 0x0689D5FC resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5FC + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 */
int func_021C7D44(char *p, int i) { return func_0689D5FC((u8 *)(p + 0x1ab8), i); }












u8 func_021C7D54(u8 *p, u8 *k, u8 *out)
{
    u32 it;
    u8 *x;
    u8 n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (func_021B9A24((u32)k, func_021D5440(x)) == 0) {
            out[n++] = func_021D5440(x);
        }
    }
    return n;
}












int func_021C7DAC(u8 *p, int a, int b, int c)
{
    int buf[5];
    int r;
    u8 *x = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, a);
    u8 *y = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, b);
    ((struct Obj02135 *)p)->f774 += 1;
    if (func_021D6C24((struct R4 *)y)) {
        y = func_021B937C(((struct Obj02135 *)p)->f4, *(char * *)&((struct Obj02135 *)p)->f8, y);
    }
    func_021C64B4(p, c, x, (struct Out64B4 *)buf);
    r = func_021C6E3C(p, x, y, (u8 *)buf, 0);
    ((struct Obj02135 *)p)->f774 -= 1;
    return r;
}












u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1)
{
    int buf[5];
    u16 o;
    u8 *x;
    u8 *y;
    int z;
    if (c != 0 && func_0201C314((void *)c) != 0) {
        x = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, a);
        y = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, b);
        ((struct Obj02135 *)p)->f774 += 1;
        if (func_021D6C24((struct R4 *)y)) {
            y = func_021B937C(((struct Obj02135 *)p)->f4, *(char * *)&((struct Obj02135 *)p)->f8, y);
        }
        if (e0) {
            z = func_021C7DAC(p, a, b, c);
        } else {
            z = 3;
        }
        func_021C64B4(p, c, x, (struct Out64B4 *)buf);
        func_021C1E74(p, x, y, (u8 *)buf, z, 0x1000, 0, e1 == 0, &o);
        ((struct Obj02135 *)p)->f774 -= 1;
        return o;
    }
    return 0;
}












/* 021C7EC4  nonzero test of the pooled offset 0x774 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021C7ED4; ldr r0, [r0, r1]; cmp r0, #0; beq loc_021C7ED0; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C7EC4(u8 *p)
{
    return (((struct Obj18325 *)p)->f774 != 0);
}











int func_021C7ED8(u8 *p, int i) { return func_021B997C(*(u8 * *)&((struct Obj21110 *)p)->f4, func_021B8DDC(i)); }











int func_021C7EEC(u8 *p, int i) { return func_021BB85C(*(u8 * *)&((struct Obj21111 *)p)->f0, func_021B8DDC(i))[9]; }











int func_021C7F04(u8 *p, int i) { if (func_021B8588(((struct Obj00003 *)p)->f4) != 3) return func_021C7EEC(p, i); return 3; }











int func_021C7F24(u8 *p, int i) { char *q = func_021C7FCC(p, i); if (func_021B9BC4((u8 *)q, func_021C7F04(p, i))) return 1; return 0; }










int func_021C7F4C(struct Flag *p) { if (p->set) return 0; p->set = 1; return 1; }











/*
 * Named by the parked ov093 file func_021D85F4.c.  Builds a candidate list in
 * a local buffer and copies the accepted entries to `out`.  EXACT*: the
 * completed extent runs into an unlabelled follower.  Three levers: `n` must
 * be volatile (it is spilled/reloaded around the loop calls), the boolean is
 * materialised through a `?:` rather than a bare `&&`, and the `u8` locals
 * are declared `j` before `i` with both initialised in the for-clause.
 */
u8 func_021C7F68(int *p, int b, u8 *out)
{
    u8 buf[8];
    volatile u32 n = (u32)func_021B8778((struct Unk021B8CB0 **)p[1], b, buf);
    u8 j;
    u8 i;

    for (i = 0, j = 0; i < n; i++) {
        u8 *x = func_021B98A4((char *const *)p[2], buf[i]);
        int ok = (x != 0) ? (func_021D5B68(x) == 0) : 0;

        if (ok)
            out[j++] = func_021D5440(x);
    }
    return j;
}










char *func_021C7FCC(u8 *p, int i) { return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8, func_021B8DDC(i)); }










/*
 * extent: two bytes alignment padding follow.
 * ABI: original forwards full-word B8DDC/B9010 results without narrowing;
 * widen B9010 and B8B9C input declarations relative to narrow legacy sources.
 */
char *func_021C7FE0(u8 *p, int v) { unsigned int k; k=func_021B9010(*(u8 * *)&((struct Obj00003 *)p)->f4, func_021B8DDC(v)); if(func_021B8B9C(*(u8 * *)&((struct Obj00003 *)p)->f4,k)) return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8,k); return 0; }










int func_021C8010(u8 *p, unsigned int v) { return func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, v); }










/*
 * extent: two bytes alignment padding follow.
 */
u8 func_021C8020(u8 *p, u8 v) { return func_021D5440((u8 *)func_021B98AC(*(char *const * *)&((struct Obj00003 *)p)->f8, v)); }










int func_021C8030(u8 *p, int v, u16 k) { return func_021D80BC(((struct Obj00003 *)p)->f4, *(int *)&((struct Obj00003 *)p)->f8, (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,v), k); }











/*
 * Levers: the record array read as p->e[i] of the twins' S (func_021BCA08,
 * func_021BCAAC), which keeps i*16 live and recomputes p+i*16 for the second
 * load; the second word as a union of u32 and a 4-bit bitfield read in place
 * (a union local takes a stack slot); key as a u8 parameter, which puts its
 * spill ahead of the count load (int/u32 key leave it after).
 */
int func_021C804C(S *p, u8 key, u32 *out)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (key == func_021D5440(p->e[i].a)) {
            if (p->e[i].b.w.lo != 6) {
                *out = p->e[i].b.u;
                return 1;
            }
        }
    }
    return 0;
}











int func_021C80AC(u8 *p, int key)
{
    u32 i;
    u32 total;
    u32 flagged;
    flagged = 0;
    total = 0;
    for (i = 0; i < p[0x782]; i++) {
        u8 *e = p + i * 16;
        if (key != func_021D5440(*(u8 * *)&((struct Obj13340 *)e)->f7E0)) {
            total++;
            if (e[0x7ed] != 0) {
                flagged++;
            }
        }
    }
    return total == flagged;
}











/*
 * ldrh at #0x1f74 (pool constant)
 */
u16 func_021C8114(u8 *p)
{
    return ((struct Obj18333 *)p)->f1F74;
}











/*
 * pointer add #0x1fec
 */
u8 *func_021C8120(u8 *p, int b)
{
    return p + 0x1fec;
}











/* 021C812C  adds r0,#0x1c */
u8 *func_021C812C(u8 *p) { return p + 0x1c; }











/* 021C8130  movs r1,#0x3e; lsls r1,#4; adds r0,r0,r1 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x3e; lsls r1, r1, #4; adds r0, r0, r1; bx lr.
 */
u8 *func_021C8130(u8 *p) { return p + 0x3e0; }










/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0, #0x10]; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 func_021C8138(struct Q7 *p) { return (u16)p->v; }










unsigned char func_021C8140(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x7d9);
}









/*
 * ABI: ov095 D588 forwards the same table pointer and key to D5C8;
 * original keeps r1 live and has no narrowing, so retain a full-word key.
 */
int func_021C814C(u8 *p, int v) { return func_0689D588(p+0x1ab8,v); }










/*
 * Two tail thunks forwarding p->field4 to distinct callees.
 */
int func_021C815C(int *p)
{
    return func_021B8588((void **)(((struct Obj26329 *)p)->f4));
}










void func_021C8168(int *p)
{
    func_021B86B8((void ***)(((struct Obj26330 *)p)->f4));
}










int func_021C8174(int *p)
{
    return ((struct Obj18336 *)((char *)func_021B8714((char **)(((struct Obj18335 *)p)->f4))))->f4;
}










int func_021C8180(int *p)
{
    return func_021B8670((unsigned int **)(((struct Obj18337 *)p)->f4));
}









int func_021C818C(u8 *p, int v) { unsigned int species; u16 i; species=func_021D5444((struct QF *)func_021B9934(*(char * *)&((struct Obj13341 *)p)->f8,v)); for(i=0;i<7;i++) { if(func_0201B718(((struct Obj13341 *)p)->f4A4,species,0,i)) return 1; } return 0; }










u16 func_021C81C8(u8 *p, u8 *x, int flag)
{
    return func_021BC948(p, x, flag);
}










u16 func_021C81D0(u8 *p, u8 *a, u32 y)
{
    u32 it;
    u8 *x;
    u16 n;
    u32 base = func_021C81C8(p, a, y);
    int k = func_021D5440(a);
    n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (k != func_021D5440(x)) {
            if (func_021C81C8(p, x, y) > base) {
                n++;
            }
        }
    }
    return n;
}









/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
int func_021C8234(u8 *p, int i) { return func_021C6F0C(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 1); }








int func_021C824C(u8 *p, int v) { void *m; m=func_021B9934(*(char * *)&((struct Obj21115 *)p)->f8,v); if(func_021D59B4(m,17)==103) return 0; if(func_021D62C4(m,19)) return 0; if(func_021EF948(7)==0) return 1; return 0; }









/*
 * tail-call thunk to func_021C2AB0
 */
int func_021C8288(u8 *p)
{
    return func_021C2AB0(p);
}








int func_021C8290(u8 *p, int a, int b, void *item) { u8 *x; x=func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,a); return func_021BFA00(p,x,func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,b),item); }








void func_021C82B8(int *p)
{
    func_021B911C(p[1]);
}








int func_021C82C4(int a, int b, int c)
{
    (void)a;
    return func_06898CF4(b, c);
}





/*
 * extent: two bytes alignment padding precede non-C veneer 021C82E4.
 */
int func_021C82D0(int unused, unsigned int v, int k) { return func_021C82E4(func_021B9AE0(v),k); }








/*
 * Tail-call stub: mov r0, r2; bx to the pool word 0x068982AD (a thumb
 * target in the 0x06xxxxxx window, not an image address).
 */
int func_021C82F4(int a, int b, int c)
{
    return func_068982AC(c);
}









u32 func_021C8300(int *p, u8 k)
{
    return func_021B9010((u8 *)p[1], k);
}








/*
 * lever: unsigned-char bitfield gives the byte load and 31-bit shift pair.
 */
unsigned int func_021C830C(u8 *p) { return ((struct Bits *)(p+0x78a))->a; }








/*
 * lever: add the byte index to the base before applying the constant offset.
 */
void func_021C831C(u8 *p, int v) { unsigned int n; n=p[0x788]; if(n<6) { p[0x788]=n+1; (p+n)[0x78b]=v; } }








/*
 * extent: Two bytes of alignment padding follow the 14-byte function.
 */
int func_021C8338(unsigned char *p, int i)
{
    return func_021D5C30((struct UtilWork *)func_021B9934(*(char * *)&((struct Obj21118 *)p)->f8, i));
}








/*
 * extent: Two bytes of alignment padding follow the 42-byte function.
 */
int func_021C8348(u8 *p, int i)
{
    u8 n = func_021D69AC(func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 4);
    if (n != 0) {
        n--;
        if (n < 24) goto done;
    }
    n = 31;
done:
    if (n != 31) return 1;
    return 0;
}








int func_021C8374(u8 *p, int i)
{
    if (func_021C8348(p, i)) return 1;
    if (func_021D62C4((struct Unk021D62A8 *)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 33)) return 1;
    return 0;
}








u32 func_021C83A0(u8 *p, int i)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj21119 *)p)->f8, i);
    int b = func_021C2AF0(p, a);
    u32 r = func_021D7B10(func_021D67E8(a), b);
    if (r < 1) r = 1;
    return r;
}








/*
 * tail-call thunk to func_021C2E4C
 */
u32 func_021C83CC(u8 *p)
{
    return func_021C2E4C(p);
}








/*
 * tail-call thunk to func_021BC2B0
 */
int func_021C83D4(u8 *p)
{
    return func_021BC2B0(p);
}








void func_021C83DC(char *p, int x)
{
    *(char *)(((struct Obj21120 *)p)->f4A8 + 4) = x;
}







/*
 * evidence: Original loads r1 for func_021BB908 even though its body ignores it.
 */
int func_021C83E8(unsigned char *p, int i, int b)
{
    if ((unsigned int)func_021B86B8(*(void *** *)&((struct Obj13342 *)p)->f4) <= 1) {
        func_021BB908(*(int * *)&((struct Obj13342 *)p)->f0, i);
        return 1;
    }
    return 0;
}






void func_021C8408(u8 *p, int a)
{
    unsigned int t = (unsigned int)func_021B86B8(*(void *** *)&((struct Obj09974 *)p)->f4);
    int k = func_021B8DDC(a);
    if (t <= 1 && k == func_021B8FF4(*(u8 * *)&((struct Obj09974 *)p)->f4)) func_021BB914(*(int * *)&((struct Obj09974 *)p)->f0);
}






void func_021C8434(u8 *p, int a, int b)
{
    int c = func_021C845C(p + 0x1ab8, b);
    func_021BE52C(*(u8 * *)&((struct Obj21121 *)p)->f4B0, a, b, c);
}





/*
 * extent: Two bytes of alignment padding follow the 38-byte function.
 */
int func_021C846C(u8 *p, int a, int b, int *out)
{
    u8 *x = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, a);
    u8 *y = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, b);
    return func_021BFEAC(p, x, y, out);
}






/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
void func_021C8494(u8 *p, int i) { func_021BFF60(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 1); }





int func_021C84AC(u8 *p, u8 *a, u8 *out)
{
    int r;
    ((struct Flags_021C7D34 *)(p + 0x78a))->flag = 0;
    r = func_021C2128(p, a);
    *out = ((struct Flags_021C7D34 *)(p + 0x78a))->flag;
    return r;
}






/*
 * tail-call thunk to func_021BDBB8
 */
void func_021C84D0(u8 *p, u8 *a)
{
    func_021BDBB8(p, a);
}






/*
 * tail-call thunk to func_021CC668
 */
int func_021C84D8(u8 *p)
{
    return func_021CC668(p);
}






/*
 * Was MATCH (pool word to the unlabelled 0x021C84F4 had no witness); the
 * matched func_021C84F4 now resolves it, verified EXACT.
 */
void func_021C84E0(unsigned char *p, unsigned int v)
{
    func_021C84F4(p, v);
}






void func_021C84E8(u8 *p)
{
    p[0x785] = 0;
}





/*
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021C84F4..0x021C8534
 * (64 bytes, including a 2-byte pool-alignment nop and two pool words).
 * Searches the u8 set at p+0x791 for v; if absent and i < 0x18, appends v
 * and bumps the count at p+0x785.
 */
void func_021C84F4(unsigned char *p, unsigned int v)
{
    unsigned int i;
    unsigned int n = p[0x785];

    for (i = 0; i < n; i++) {
        if (v == p[0x791 + i])
            return;
    }
    if (i < 0x18) {
        *(p + i + 0x791) = v;
        p[0x785] = p[0x785] + 1;
    }
}






int func_021C8534(u8 *p)
{
    u32 i;
    u32 buf;
    for (i = 0; i < p[0x785]; i++) {
        if (func_021C8578(p + 0x1ab8, func_021B8DDC(p[0x791 + i]), &buf)) {
            return 1;
        }
    }
    return 0;
}



void func_021C8588(unsigned char *p)
{
    *(int *)&((struct Obj00294 *)p)->f1A64 = 0;
    func_021C85D4(p, 0, 1);
}



void func_021C859C(u8 *p)
{
    if (((struct Obj00294 *)p)->f1A64 < 6) {
        ++((struct Obj00294 *)p)->f1A64;
        func_021C85D4(p, ((struct Obj00294 *)p)->f1A64, 1);
    }
}



void func_021C85B8(u8 *p)
{
    if (((struct Obj00294 *)p)->f1A64 != 0) {
        --((struct Obj00294 *)p)->f1A64;
        func_021C85D4(p, ((struct Obj00294 *)p)->f1A64, 0);
    }
}




void func_021C85D4(u8 *p, int index, int clear)
{
    u8 *q = p + 0x874 + index * 0x290;
    *(u8 * *)&((struct Obj00294 *)p)->f850 = q;
    *(u8 * *)&((struct Obj00294 *)p)->f854 = q + 0x48;
    *(u8 * *)&((struct Obj00294 *)p)->f858 = q + 0x90;
    *(u8 * *)&((struct Obj00294 *)p)->f85C = q + 0xd8;
    *(u8 * *)&((struct Obj00294 *)p)->f860 = q + 0x120;
    *(u8 * *)&((struct Obj00294 *)p)->f864 = q + 0x168;
    *(u8 * *)&((struct Obj00294 *)p)->f868 = q + 0x1b0;
    *(u8 * *)&((struct Obj00294 *)p)->f4A8 = q + 0x1f8;
    *(u8 * *)&((struct Obj00294 *)p)->f1AB0 = q + 0x200;
    *(u8 * *)&((struct Obj00294 *)p)->f1AB4 = q + 0x214;
    *(u8 * *)&((struct Obj00294 *)p)->f4B4 = q + 0x228;
    *(u8 * *)&((struct Obj00294 *)p)->f4AC = q + 0x22e;
    *(u8 * *)&((struct Obj00294 *)p)->f4B0 = q + 0x241;
    *(u8 * *)&((struct Obj00294 *)p)->f86C = q + 0x254;
    *(u8 * *)&((struct Obj00294 *)p)->f870 = q + 0x270;
    p[0x77f] = q[0x28c];
    ((struct Flags_021C8588 *)(p + 0x78a))->a = q[0x28d];
    ((struct Flags_021C8588 *)(p + 0x78a))->b = q[0x28e];
    if (clear) {
        func_021C87A0(q);
        func_021C87B0(((struct Obj00294 *)p)->f854);
        func_021C87C0(((struct Obj00294 *)p)->f858);
        func_021C87D0(((struct Obj00294 *)p)->f85C);
        func_021C87E0(((struct Obj00294 *)p)->f860);
        func_021C87F0(((struct Obj00294 *)p)->f864);
        func_021C8800(((struct Obj00294 *)p)->f868);
        func_021BD1E0(*(struct Unk021BD1E0 * *)&((struct Obj00294 *)p)->f4A8);
        func_02082BCC(((struct Obj00294 *)p)->f1AB0, 0, 0x14);
        func_02082BCC(((struct Obj00294 *)p)->f1AB4, 0, 0x14);
        func_02082BCC(((struct Obj00294 *)p)->f4B4, 0, 6);
        func_02082BCC(((struct Obj00294 *)p)->f4AC, 0, 0x13);
        func_02082BCC(((struct Obj00294 *)p)->f4B0, 0, 0x13);
        func_02082BCC(((struct Obj00294 *)p)->f86C, 0, 0x1c);
        func_02082BCC(((struct Obj00294 *)p)->f870, 0, 0x1c);
        p[0x77f] = 6;
        ((struct Flags_021C8588 *)(p + 0x78a))->a = 0;
        ((struct Flags_021C8588 *)(p + 0x78a))->b = 0;
    }
}




void func_021C8810(u8 *p)
{
    func_02082BCC(p, 0, 0x24);
    ((struct Packed021C8810 *)(p + 2))->low = 0;
}





/* 021C8828  u8 of the low halfword, != 0 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrh r0, [r0, #2]; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; beq loc_021C8834; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C8828(u8 *p)
{
    return ((u8)((struct Obj18339 *)p)->f2 != 0);
}





/*
 * Named by the parked ov093 files (func_021DF0C4 / func_021DFABC /
 * func_021E7388).  Low byte of the +2 halfword <- (u8)a; +0 halfword <- b;
 * then bits 8..14 of the +2 halfword are cleared.  `(u8)(u16)a` and the
 * `(int)` cast before `~0x7F00` are both load-bearing: the first gives the
 * double narrowing, the second keeps the mask sign-extended (0xFFFF80FF) so
 * the pooled word matches.
 */
void func_021C8838(void *p, int a, int b)
{
    u16 *h = (u16 *)((u8 *)p + 2);
    u8 av = (u8)(u16)a;

    *h = (*h & ~0xff) | av;
    ((struct Obj21124 *)p)->f0 = (u16)b;
    *h = (u16)((int)*h & ~0x7F00);
}





/*
 * Named by the parked ov093 files (func_021DF0C4 / func_021DFABC /
 * func_021E7388).  Appends `val` to the record at p: the count in bits 8..14
 * of the +2 halfword (max 7 entries) is incremented and `val` stored at
 * p + 4 + idx*4.  The 7-bit unsigned bitfield is what makes the count
 * unsigned (`bhs`, not `bge`) and produces the lsl/lsr extraction pair.
 */
void func_021C8860(struct S *p, u32 val)
{
    unsigned int idx = p->n;

    if (idx >= 8)
        return;
    p->n = idx + 1;
    p->arr[idx] = val;
}




/*
 * extent: two-byte alignment padding at 0x021C88A2.
 */
void func_021C888C(u8 *p, u32 v)
{
    if (((struct Packed021C888C *)(p + 2))->index < 8) {
        ((struct Obj21125 *)p)->f20 = v;
        ((struct Packed021C888C *)(p + 2))->active = 1;
    }
}





/*
 * word at +0x0C names 0x021CC9AC.  That address is real Thumb code in ov093
 * (a 176-byte unlabelled bitfield packer, disasm prints it as a `.word` run)
 * but no listing labels it and no branch or pool word anywhere outside this
 * range names it, so `label`, `literal`, `sole-ref/code` and `matched` all
 * refuse.  It can only be witnessed by matching it bottom-up.  Passing the
 * full (char*, int, int) arity through to the callee is what makes the two
 * loads schedule as the original (add before the target load).
 *
 * Named by five parked pending files (func_021D85F4 / func_021DF0C4 /
 * func_021DFABC / func_021E4A70 / func_021E7388).
 *
 * 2026-10-05 (D9 lane 02): unchanged. 0x021CC9AC is a 176-byte packer, not a tiny leaf, and ov093 below 0x021D4000 is pengy's, so no witness filed. Needs the integrator seed.
 * 2026-10-05 (D9r lane 14): callee 0x021CC9AC is now matched EXACT as
 * src/matched/ov/ov093_func_021CC9AC.c (user-approved). Re-verified MATCH: the
 * relocation still waits on that file's shard (integrator manifest), then this
 * should verify EXACT with no source change.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021CC9AC is a real 176-byte Thumb bitfield packer (bitfield insert into a table with 0x3b-entry byte lookup), not a veneer and not tiny; not filed in this lane. Needs bottom-up match or integrator seed.
 */
void *func_021C88A4(char *p, int a, int b)
{
    return func_021CC9AC((struct Pack *)(p + 0x1D74), a, b);
}





/*
 * Named by the parked ov093 files (func_021D85F4 / func_021DF0C4 /
 * func_021DFABC / func_021E4A70 / func_021E7388).  EXACT*: both calls resolve
 * (func_021C88A4 by `label`, func_021C88C8 by `label`), the extent runs two
 * bytes long into the unlabelled follower.
 */
void func_021C88B4(void *a, int k, int b)
{
    func_021C88C8(a, func_021C88A4(a, k, b));
}





/*
 * Unlabelled-record helper reached from the five ov093 packets that name it
 * (func_021DFABC / func_021E4A70 / func_021D85F4 / func_021E7388 /
 * func_021DF0C4).  Runs the battle-command dispatcher on (`a`, `b`), then
 * dispatches the same command through the record `a + 0x1D74`.
 */
void func_021C88C8(void *a, void *b)
{
    func_021C8918(a, b);
    func_021CCA74((char *)a + 0x1d74, b);
}





int func_021C88E4(u8 *p)
{
    if (func_021CC96C((struct Q9 *)(p + 0x1D74)) != 0) {
        if (func_021CC9A4((u32 *)(p + 0x1D74)) != 0) return 2;
        return 1;
    }
    return 0;
}





/*
 * tail-call thunk to func_021C88E4
 */
int func_021C8910(u8 *p)
{
    return func_021C88E4(p);
}





void func_021C8918(BattleCtx *s, BtlCmd *cmd)
{
    int arg = func_021CC960((struct S *)s->queue);
    u8 r;

    if (func_021CC96C((struct Q9 *)s->queue))
        r = func_021CC99C((struct Q10 *)s->queue);
    else
        r = 1;

    if (cmd->ignoreIfBusy && r == 0)
        return;
    if (cmd->checkFainted && func_021D5B68(func_021B9940(s->party, cmd->client)))
        return;

    switch (cmd->id) {
    case 1:
        r = func_021C8C6C(s, cmd);
        break;
    case 2:
        r = func_021C8CBC(s, cmd);
        break;
    case 3:
        r = func_021C8D0C(s, cmd);
        break;
    case 0:
        r = func_021C9DE8(s, cmd);
        break;
    case 5:
        r = func_021C8D2C((int)s, (Ent_021C8D2C *)cmd, arg);
        break;
    case 6:
        r = func_021C8DE4(s, cmd, arg);
        break;
    case 7:
        r = func_021C8E58(s, cmd);
        break;
    case 8:
        r = func_021C8F24(s, cmd);
        break;
    case 9:
        r = func_021C8FA4(s, cmd, arg);
        break;
    case 10:
        r = func_021C9010(s, cmd, arg);
        break;
    case 11:
        r = func_021C9068(s, cmd, arg);
        break;
    case 12:
        r = func_021C9178(s, cmd);
        break;
    case 14:
        r = func_021C9250(s, cmd, arg);
        break;
    case 15:
        r = func_021C9394(s, cmd);
        break;
    case 18:
        r = func_021C9448(s, cmd);
        break;
    case 16:
        r = func_021C947C(s, cmd);
        break;
    case 17:
        r = func_021C94C8(s, cmd);
        break;
    case 19:
        r = func_021C95D0(s, cmd);
        break;
    case 20:
        r = func_021C962C(s, cmd);
        break;
    case 4:
        r = func_021C96D4(s, cmd);
        break;
    case 21:
        r = func_021C9728(s, cmd);
        break;
    case 22:
        r = func_021C9750(s, cmd);
        break;
    case 23:
        r = func_021C9778(s, cmd);
        break;
    case 24:
        r = func_021C97A4(s, cmd);
        break;
    case 25:
        r = func_021C97D0(s, cmd);
        break;
    case 26:
        r = func_021C9828(s, cmd);
        break;
    case 27:
        r = func_021C9898(s, cmd);
        break;
    case 29:
        r = func_021C98E4((u8 *)s, (struct Cmd *)cmd);
        break;
    case 28:
        r = func_021C98C4(s, cmd);
        break;
    case 30:
        r = func_021C9A24(s, (const struct Cmd *)cmd);
        break;
    case 31:
        r = func_021C9A60(s, cmd);
        break;
    case 32:
        r = func_021C9BB8(s, cmd);
        break;
    case 33:
        r = func_021C9DCC(s, cmd);
        break;
    case 34:
        r = func_021C9E3C(s, cmd);
        break;
    case 35:
        r = func_021C9ECC(s, cmd);
        break;
    case 36:
        r = func_021C9CC0(s, cmd);
        break;
    case 37:
        r = func_021C9F0C(s, cmd);
        break;
    case 38:
        r = func_021C9F4C(s, cmd);
        break;
    case 39:
        r = func_021C9F6C((u8 *)s, (u8 *)cmd);
        break;
    case 40:
        r = func_021CA128(s, cmd);
        break;
    case 41:
        r = func_021CA158(s, cmd);
        break;
    case 42:
        r = func_021CA1D0(s, cmd);
        break;
    case 43:
        r = func_021CA248((u8 *)s, (const u8 *)cmd);
        break;
    case 44:
        r = func_021CA270(s, cmd);
        break;
    case 45:
        r = func_021CA2E8(s, cmd);
        break;
    case 46:
        r = func_021CA318((u8 *)s, (const struct Q *)cmd);
        break;
    case 47:
        r = func_021CA370(s, cmd);
        break;
    case 48:
        r = func_021CA394((u8 *)s, (const u8 *)cmd);
        break;
    case 49:
        r = func_021CA3AC(s, cmd);
        break;
    case 50:
        r = func_021CA3D0(s, cmd);
        break;
    case 51:
        r = func_021CA47C(s, cmd);
        break;
    case 52:
        r = func_021CA570(s, cmd);
        break;
    case 53:
        r = func_021CA5CC(s, cmd);
        break;
    case 54:
        r = func_021CA6C4(s, cmd);
        break;
    case 55:
        r = func_021CA6FC(s, cmd);
        break;
    case 56:
        r = func_021CA738(s, cmd);
        break;
    case 57:
        r = func_021CA748(s, cmd);
        break;
    case 58:
        r = func_021CA7C4(s, cmd);
        break;
    case 59:
        r = func_021CA7D4(s, cmd);
        break;
    }
    func_021CC974(s->queue, r);
}



u8 func_021C8C6C(BattleCtx *a, BtlCmd *e)
{
    if (func_021C8CAC((int)a + 0x1ab8, e->client)) {
        func_021C60D4((u8 *)a, func_021B9934(*(char * *)&((struct Obj00003 *)a)->f8, (u8)e->client));
        return 1;
    }
    return 0;
}
