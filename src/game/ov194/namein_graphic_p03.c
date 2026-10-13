/*
 * file:     namein_graphic_p03.c
 * unit:     yes
 * function: func_021F2F8C, func_021F3008, func_021F31B8, func_021F31F4, func_021F32D8, func_021F32FC, func_021F3304, func_021F3350, func_021F3358, func_021F3364, func_021F33C0, func_021F35A8, func_021F366C, func_021F36E8, func_021F37EC, func_021F38CC, func_021F391C, func_021F3A0C, func_021F3B18, func_021F3BD4, func_021F3C40, func_021F3CD0, func_021F3D54, func_021F3D70, func_021F3DE0, func_021F3E18, func_021F3E78, func_021F3EB0, func_021F3ED0, func_021F3EF0, func_021F3FBC, func_021F42A0, func_021F42E8, func_021F436C, func_021F4390, func_021F4394, func_021F43A0, func_021F4408, func_021F4450, func_021F4480, func_021F4524, func_021F45A8, func_021F45EC, func_021F4608, func_021F4614, func_021F4628, func_021F462C, func_021F4634, func_021F463C, func_021F4674, func_021F46B4, func_021F46F4, func_021F47B4, func_021F4A5C, func_021F4AA8, func_021F4AE4, func_021F4B84, func_021F4BD8, func_021F4BEC, func_021F4BF8, func_021F4C0C, func_021F4C6C, func_021F4CA4, func_021F4CA8, func_021F4CB0, func_021F4CF0, func_021F4D0C, func_021F4D14, func_021F4D20, func_021F4D34, func_021F4D3C, func_021F4D78, func_021F4D94, func_021F4D9C, func_021F4DA0, func_021F4DA4, func_021F4DBC, func_021F4DD0, func_021F4DD8, func_021F4DDC, func_021F4E18, func_021F4E58, func_021F4E98, func_021F4ED8, func_021F4F10, func_021F4F50, func_021F4F60, func_021F4F68, func_021F4F6C, func_021F4F7C, func_021F5004, func_021F513C, func_021F51A4, func_021F51E4
 * address:  0x021F2F8C
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02049EB4 0x02049EB4 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F19A0 0x021F19A0 thumb ov194
 *   func_021F256C 0x021F256C thumb ov194
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F2608 0x021F2608 thumb ov194
 *   func_021F1A10 0x021F1A10 thumb ov194
 *   func_021F23E4 0x021F23E4 thumb ov194
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_021F1BFC 0x021F1BFC thumb ov194
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02040804 0x02040804 arm
 *   func_02040618 0x02040618 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F2884 0x021F2884 thumb ov194
 *   func_021F25F8 0x021F25F8 thumb ov194
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F26E0 0x021F26E0 thumb ov194
 *   func_02035D20 0x02035D20 arm
 *   func_021F265C 0x021F265C thumb ov194
 *   func_021F2614 0x021F2614 thumb ov194
 *   func_020457B0 0x020457B0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   MI_CpuFill8    0x02082BCC arm
 *   func_0203101C  0x0203101C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F164 0x0201F164 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045874 0x02045874 arm
 *   func_0204581C 0x0204581C arm
 *   func_0216C0D4 0x0216C0D4 thumb ov010
 *   func_0216C0E4 0x0216C0E4 thumb ov010
 *   func_020275E4  0x020275E4  thumb
 *   func_020276A4  0x020276A4  thumb
 *   func_020276A8  0x020276A8  thumb
 *   func_020276AC  0x020276AC  thumb
 *   func_020276B0  0x020276B0  thumb
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_0201C724  0x0201C724  thumb
 *   d_021F5569     0x021F5569  data ov194
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_020257D0 0x020257D0 thumb
 *   func_0204B404 0x0204B404 arm
 *   d_020A1B38 0x020A1B38 data a4
 *   func_020458F8  0x020458F8  arm
 *   d_020A7370     0x020A7370  data
 *   func_021F2328 0x021F2328 thumb ov194
 *   func_0204589C 0x0204589C arm
 *   func_021F253C 0x021F253C thumb ov194
 *   func_02045838 0x02045838 arm
 *   func_021F23F4 0x021F23F4 thumb
 *   func_021F23F8 0x021F23F8 thumb
 *   func_021F22E8 0x021F22E8 thumb ov194
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   sub_020310C4 0x020310C4 arm
 *   sub_0201CE30 0x0201CE30 thumb
 *   sub_0203630C 0x0203630C arm
 *   sub_02035C38 0x02035C38 arm
 *   sub_0201CE5C 0x0201CE5C thumb
 *   sub_020355D8 0x020355D8 arm
 *   sub_020362DC 0x020362DC arm
 *   sub_02035C60 0x02035C60 arm
 *   sub_0201CE38 0x0201CE38 thumb
 *   func_021F2190 0x021F2190 thumb ov194
 *   func_021F21BC 0x021F21BC thumb ov194
 *   func_021F21FC 0x021F21FC thumb ov194
 *   func_021F22AC 0x021F22AC thumb ov194
 *   func_021F2150 0x021F2150 thumb ov194
 *   func_021F233C 0x021F233C thumb ov194
 *   func_021F235C 0x021F235C thumb ov194
 *   func_021F5370 0x021F5370 thumb ov194
 *   func_021F54CC 0x021F54CC thumb ov194
 *   func_021F2394 0x021F2394 thumb ov194
 *   func_021F23B8 0x021F23B8 thumb ov194
 *   func_021F1FB4 0x021F1FB4 thumb ov194
 *   func_02045A90 0x02045A90 arm
 *   func_0200C0FC 0x0200C0FC thumb
 *   func_021BD368 0x021BD368 thumb ov088
 *   func_021BD380 0x021BD380 thumb ov088
 *   func_02030734 0x02030734 arm
 *   sub_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   sub_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   sub_020056A0 0x020056A0 thumb
 *   d_021F5784 0x021F5784 data a1
 *   d_021F55D0 0x021F55D0 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0203F8F4 0x0203F8F4 arm
 *   sub_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   sub_02040588 0x02040588 arm
 *   d_021F55A4 0x021F55A4 data a4
 *   d_021F5600 0x021F5600 data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021F5798 0x021F5798 data a4
 *   func_0201F41C 0x0201F41C thumb
 *   func_02045A98 0x02045A98 arm
 *   func_0204A1BC 0x0204A1BC arm
 *   func_02082D44 0x02082D44 arm
 *   func_02049250 0x02049250 arm
 *   func_0206E964 0x0206E964 arm
 *   func_0204B7F0 0x0204B7F0 arm
 *   func_0204AA94 0x0204AA94 arm
 *   func_020862F0 0x020862F0 arm
 *   func_0204B764 0x0204B764 arm
 *   func_02063800 0x02063800 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   d_021F57A8 0x021F57A8 data ov194 a1
 */
#include "../../matched/include/Obj00733.h"
#include "../../matched/include/Obj24905.h"
#include "../../matched/include/Obj00117.h"
#include "../../matched/include/Obj10809.h"
#include "../../matched/include/Obj24907.h"
#include "../../matched/include/Obj05512.h"
#include "../../matched/include/Obj24908.h"
#include "../../matched/include/Obj01773.h"
#include "../../matched/include/Obj14503.h"
#include "../../matched/include/Obj01774.h"
#include "../../matched/include/Obj14504.h"
#include "../../matched/include/Obj02239.h"
#include "../../matched/include/Obj02532.h"
#include "../../matched/include/Obj05513.h"
#include "../../matched/include/Obj24909.h"
#include "../../matched/include/Obj10810.h"
#include "../../matched/include/Obj03900.h"
#include "../../matched/include/Obj04591.h"
#include "../../matched/include/Obj03342.h"
#include "../../matched/include/Obj01576.h"
#include "../../matched/include/Obj06641.h"
#include "../../matched/include/Obj24910.h"
#include "../../matched/include/Obj05514.h"
#include "../../matched/include/Obj14505.h"
#include "../../matched/include/Obj01287.h"
#include "../../matched/include/Obj03343.h"
#include "../../matched/include/Obj10811.h"
#include "../../matched/include/Obj24911.h"
#include "../../matched/include/Obj24912.h"
#include "../../matched/include/Obj24913.h"
#include "../../matched/include/Obj24914.h"
#include "../../matched/include/Obj24915.h"
#include "../../matched/include/Obj24916.h"
#include "../../matched/include/Obj24917.h"
#include "../../matched/include/Obj24918.h"
#include "../../matched/include/Obj24919.h"
#include "../../matched/include/Obj24920.h"
#include "../../matched/include/Obj14507.h"
#include "../../matched/include/Obj24921.h"
#include "../../matched/include/Obj14508.h"
#include "../../matched/include/Obj24922.h"
#include "../../matched/include/Obj03901.h"
#include "../../matched/include/Obj01577.h"
#include "../../matched/include/Obj14510.h"
#include "../../matched/include/Obj24924.h"
#include "../../matched/include/Obj24925.h"
#include "../../matched/include/Obj24926.h"
#include "../../matched/include/Obj24927.h"
#include "../../matched/include/Obj14512.h"
#include "../../matched/include/Obj24928.h"
#include "../../matched/include/Obj14518.h"
#include "../../matched/include/Obj14519.h"

#define OBJ(p) (*(char **)((p) + 0x2C4))
struct Descriptor;
struct Cfg;
struct Rect;
struct PrintSys;
struct CharBuf;
struct U16Vec;
struct MsgBank;
struct WordSet;
struct S02031140;
struct Rec3;
struct Bmp;
struct Grid;
struct Obj;
struct Param;
struct Sys;
struct Obj020437AC;
struct Actor;
struct PtS;
struct Vec2;
struct Buf;
struct Strbuf;
struct Tcbl;
struct Rec;
struct Blk34;
struct DispVram;
struct Node;
struct DispConfig;
struct Bank;
struct ArcFile;
struct Struct20;
typedef struct {int x,y;} Pair;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned u32_021F2F8C;

typedef struct {int x,y,z,w;} Box;

typedef unsigned int u32_021F31B8;

typedef struct {int left,top,right,bottom;} Rect;

typedef unsigned int u32;

typedef short s16_021F2F8C;

typedef struct {unsigned char pad[0xD8];Pair xy;} Ctx;

typedef signed short   s16_021F3B18;

typedef signed char    s8;

typedef unsigned long long u64;

typedef signed int     s32;

typedef struct {u16 w;u16 h;u32 pad;} Dim8;

typedef struct {short x,y;} Vec2;

typedef void (*fn_021F4614_t)(u8 *, u8 *, u32);

typedef struct {unsigned words[4];} Disp;

typedef struct {unsigned words[8];} Bg;

typedef struct {unsigned id;Bg config;unsigned type,enabled;} Entry;

typedef struct {int w[5];} Palette;

extern void func_02082BCC(void *,unsigned,unsigned);
extern void *func_02049EB4(u32_021F2F8C,u32_021F2F8C,u32_021F2F8C,u32_021F2F8C,u32_021F2F8C);
extern void func_02040AE0(u32_021F2F8C,const void *,u32_021F2F8C);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020409B4(u32_021F2F8C);
extern void func_021F19A0(u8 *,void *,void *,u32_021F2F8C);
extern void func_021F256C(char *,unsigned,int,void *,u32_021F2F8C);
extern u32_021F2F8C func_020450F0(u32_021F2F8C,u32_021F2F8C,u32_021F2F8C,u32_021F2F8C,u8,u8,u8);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_021F26F0(char *,char *,void *,void *,u32_021F2F8C);
extern u8 func_020355C4(void);
extern int func_021F2818(char *,Pair *,Box *);
extern void func_021F1A1C(char *p, int mode, const struct Rect *rect, int flag, int selected);
extern u32_021F31B8 func_020452E8(struct Descriptor *d);
extern u32_021F31B8 func_020307B0(void *p);
extern void func_021F2608(void *);
extern void func_021F1A10(void *);
extern int func_021F2828(const char *,int,Pair *);
extern void func_021F1BFC(char *p, int sel, const void *rect);
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_0207D63C(void *,int,int,int,int);
extern u32 func_02040804(u32 layer);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021F2884(Pair *,int,int);
extern void func_021F25F8(int *,int,int);
extern unsigned func_0203633C(void);
extern unsigned func_020362DC(void);
extern void func_020355D8(u8);
extern void func_020061E4(unsigned);
extern void func_021F26E0(char *,int,int);
extern unsigned func_02035D20(unsigned *,unsigned *);
extern int func_021F265C(const char *,int *,Pair *);
extern unsigned func_021F2614(char *,int *,unsigned short *);
extern struct U16Vec *func_020457B0(unsigned int capacity, unsigned int heapId);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
/* Callee species is u16; this caller passes r2 without truncation. */
extern void *func_020173F0(u32,u16,u64,u16);
extern void func_02017E40(void *,u32,u32);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void MI_CpuFill8(void *, int, int);
extern void *func_0203101C(int, int, int, int);
extern void func_0201CE48(int);
extern void func_02031140(struct S02031140 *);
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_0216C0E4(int *);
extern void func_0216C0D4(int *,int);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F164(struct WordSet *p, u32 i, u32 a, u32 b);
extern void func_0204581C(struct U16Vec *vec);
extern signed char func_02012FFC(void);
/* The caller consumes R0 returned by the legacy void forwarding wrapper. */
extern int func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern u32 func_0201ED04(struct WordSet *p);
extern u32  func_020275E4(void);
extern u32  func_020276A4(void);
extern u32  func_020276A8(void);
extern u32  func_020276AC(u32 a);
extern u32  func_020276B0(u32 a);
extern int func_0201BC3C(void);
extern u32  func_0201BABC(u32 a, u32 b, u32 c, u32 d);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32  func_0201BB5C(u32 a, u32 b, u32 c, u32 d);
extern void *func_020490F4(unsigned,u16);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *h);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0201C724(u32 a, void *b, s16_021F3B18 c, u32 d, void *e, u32 f, u32 g);
extern void func_0204ADA4(u32 i);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_020257D0(struct Obj *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u16 func_020458F8(struct U16Vec *vec);
extern void func_021F2328(char *,struct Strbuf *);
extern int func_0204589C(struct Buf *a, struct Buf *b);
extern int func_021F253C(u8 *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_021F23F4(const u8 *p);
extern u32 func_021F23F8(const u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void sub_020310C4(struct Tcbl *);
extern unsigned sub_0201CE30(void *);
extern unsigned int sub_0203630C(void);
extern int sub_02035C38(void);
extern void sub_0201CE5C(struct Rec *, int);
extern void sub_020355D8(unsigned char);
extern u32 sub_020362DC(void);
extern int sub_02035C60(void);
extern void sub_0201CE38(void *);
extern int func_021F2190(char *,u16);
extern int func_021F21BC(unsigned char *p, unsigned short a, u32 b);
extern int func_021F21FC(unsigned char *a, int b);
extern int func_021F22AC(char *);
extern int func_021F2150(unsigned char *p);
extern void func_021F233C(char *);
extern void func_021F235C(char *);
extern void func_021F2394(unsigned char *p);
extern void func_021F23B8(char *p, const u16 *q);
extern int func_021F5370(const u32 *cache, const void *input, u16 heap);
extern int func_021F54CC(void *,int,int);
extern u16 *func_02045A90(struct U16Vec *vec);
extern int func_021F1FB4(u8 *p);
extern void func_0200C0FC(struct Blk34 *p, u32 i, u8 v);
extern void func_021BD368(unsigned char *);
extern int func_021BD380(unsigned char *);
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void sub_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void sub_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void *sub_020056A0(unsigned, unsigned, unsigned);
extern void func_02030EAC(struct Node *);
extern void func_0201DD68(void);
extern void func_0203F8F4(unsigned short);
extern void sub_02045088(unsigned short);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(unsigned char, const Bg *, unsigned char);
extern void func_020414AC(unsigned char);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern void func_0201F41C(const u16 *,u16 *,u32);
extern unsigned short func_02045A98(void);
extern void func_02082D44(const void *, void *, unsigned);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern u8 *func_0206E964(u8 *);
extern u16 func_0204B7F0(u8 *);
extern void func_0204AA94(int,void *,u32,int,int);
extern void func_020862F0(void *,unsigned);
extern void func_0204B764(const char *src, struct Struct20 *dst);
extern int func_02063800(char *,int);
extern void func_0207E51C(void *,int,unsigned);
extern void func_0207E5D0(void *,int,unsigned);
int func_021F2F8C(Pair *p,Pair *out);
void func_021F3008(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32_021F2F8C heap);
void func_021F31B8(u8 *p);
void func_021F31F4(char *p,char *q);
int func_021F32D8(char *p, unsigned short *out);
u32 func_021F32FC(const u8 *p);
int func_021F3304(char *p);
void *func_021F3350(const u8 *p);
u32 func_021F3358(u32 a,u32 b,u32 c);
int func_021F3364(char *p,int mode);
int func_021F33C0(char *p);
void func_021F35A8(char *p, u32 mode);
void func_021F366C(char *p,int index,int variant);
int func_021F36E8(char *p,int *out);
int func_021F37EC(char *p,int *out);
int func_021F38CC(char *p,int *out);
void func_021F391C(char *p,int *input);
int func_021F3A0C(char *p,int *out);
int func_021F3B18(char *p,int *out);
int func_021F3BD4(char *p,int *out);
void func_021F3C40(char *p,int *input);
void func_021F3CD0(unsigned char *p,int a,int b,int c,int d,unsigned short e);
void func_021F3D54(u8 *p);
void func_021F3D70(char *p,int value);
void func_021F3DE0(char *p,int value,u32 id,u32 form,u16 heap);
void func_021F3E18(char *p,int value,void *mon);
int func_021F3E78(u8 *p);
void func_021F3EB0(char *p, int v);
void func_021F3ED0(unsigned char *p);
void func_021F3EF0(char *p,char *q,int *w,u32 heap);
void func_021F3FBC(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap);
void func_021F42A0(unsigned char *p);
void func_021F42E8(char *p);
void func_021F436C(unsigned char *p);
unsigned func_021F4390(unsigned char *p);
void func_021F4394(unsigned char *p);
int func_021F43A0(char *p);
int func_021F4408(int x, int y);
int func_021F4450(int *p, int *q);
int func_021F4480(u8 *p, int a, int b);
void func_021F4524(char *p);
int func_021F45A8(int p);
void func_021F45EC(u8 *a, u32 b, u32 c);
void func_021F4608(void *p);
void func_021F4614(u8 *p);
unsigned func_021F4628(unsigned char *p);
void func_021F462C(unsigned char *p,unsigned value);
void func_021F4634(unsigned char *p);
void func_021F463C(unsigned char *p,int *unused,unsigned char *q);
void func_021F4674(unsigned char *p,int *state);
void func_021F46B4(unsigned char *p,int *state);
void func_021F46F4(unsigned char *a, int *state, char *p);
void func_021F47B4(unsigned char *owner,void *unused,char *p);
void func_021F4A5C(unsigned char *a, int unused, char *p);
void func_021F4AA8(unsigned char *p,int *state,unsigned char *q);
unsigned char *func_021F4AE4(unsigned swap, unsigned short heap);
void func_021F4B84(unsigned char *p);
void func_021F4BD8(u8 *p);
unsigned func_021F4BEC(unsigned char *p);
void func_021F4BF8(u32 a, u8 *b);
void func_021F4C0C(void *p, unsigned short heap);
void func_021F4C6C(void *p);
void func_021F4CA4(u8 *a0);
void func_021F4CA8(u8 *a0);
void func_021F4CB0(unsigned char *p, int a, int b);
void func_021F4CF0(u8 *p);
void func_021F4D0C(u8 *a0);
void func_021F4D14(u8 *a0);
u32 func_021F4D1C(const u32 *p);
int func_021F4D20(u32 a, u32 b);
void func_021F4D34(void *p);
u32 *func_021F4D3C(u32 heap);
void func_021F4D78(u8 *p);
u32 func_021F4D94(const u8 *p, u32 i);
u16 func_021F4D9C(const u16 *p);
u16 func_021F4DA0(const u16 *p);
u32 func_021F4DA4(u8 *p, u16 a, u16 b);
int func_021F4DBC(int a, int b);
void func_021F4DD0(void *p);
u16 func_021F4DD8(const u16 *p);
void func_021F4DDC(const char *p,int i,u16 *dst,u32 n,u8 *count);
int func_021F4E18(int p, int idx, unsigned short *tab, int val, unsigned char *out);
int func_021F4E58(int p, int idx, unsigned short *tab, int val, unsigned char *out);
int func_021F4E98(char *p, int index, unsigned short *table, unsigned n, unsigned char *out);
u16 func_021F4ED8(const char *p,const u16 *b);
int func_021F4F10(const unsigned short *a, const unsigned short *b);
int func_021F4F50(int a);
void func_021F4F60(void *p);
int func_021F4F68(const u16 *p);
unsigned short func_021F4F6C(char *base, int i, int j);
int func_021F4F7C(char *p, const unsigned short *key, unsigned short *out);
u32 func_021F5004(u16 *s, u32 x);
void func_021F513C(const char *src, int width, int x, int y, int w, int h, char *dst);
void func_021F51A4(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step);
void func_021F51E4(u8 *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap);
extern const u8 d_021F5569[];
extern short d_020A1B38[];
extern u32  d_020A7370;
extern const char d_021F5784[];
extern const struct DispVram d_021F55D0;
extern const Disp d_021F55A4;
extern const Entry d_021F5600[];
extern const char d_021F5798[];
extern const char d_021F57A8[];





int func_021F2F8C(Pair *p,Pair *out) {
 int result;Pair xy;
 result=0;
 switch((unsigned)p->y) {
 case 0: if(p->x==10)result=6;else {xy=*p;result=1;}break;
 case 1: if(p->x==9)result=7;else {xy=*p;result=1;}break;
 case 2: if(p->x==0 || p->x==9)result=8;else {xy.x=p->x-1;xy.y=p->y;result=1;}break;
 case 3: result=9;if(p->x!=4)result=p->x+2;break;
 }
 if(result==1 && out) {*out=xy;}return result;
}





/*
 * tail: two zero alignment bytes at 021F31B6 before 31B8.
 * prototype: 256C retains fifth heap input visibly stored by caller; heap forwards use full words without caller-side truncation.
 */
void func_021F3008(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32_021F2F8C heap)
{
 Box box;
 void *bg;
 int index;
 func_02082BCC(p,0,0x130);
 ((struct Obj00733 *)p)->fD8=0;((struct Obj00733 *)p)->fDC=0;
 ((struct Obj00733 *)p)->fF4=font;((struct Obj00733 *)p)->fF8=window;((struct Obj00733 *)p)->fFE=heap;
 ((struct Obj00733 *)p)->f100=mode;((struct Obj00733 *)p)->f114=mode;((struct Obj00733 *)p)->f12C=data;
 ((struct Obj00733 *)p)->f11C=func_02049EB4(118,10,0,(u32_021F2F8C)(p+0x124),heap);
 ((struct Obj00733 *)p)->f120=func_02049EB4(118,5,0,(u32_021F2F8C)(p+0x128),heap);
 if(mode==3){func_02040AE0(1,*(char * *)&((struct Obj00733 *)p)->f124+12,2048);func_02040588(2,0);}
 else {func_02040AE0(1,*(char * *)&((struct Obj00733 *)p)->f128+12,2048);func_02040588(2,1);}
 func_020409B4(1);
 func_021F19A0(p+0x24,(void *)mode,palette,heap);
 index=func_021F3358(((struct Obj00733 *)p)->f100,((struct Obj00733 *)p)->f104,p[0x108]);
 func_021F256C((char *)p,mode,index,((struct Obj00733 *)p)->f12C,heap);
 bg=(void *)func_020450F0(3,3,5,26,15,15,1);
 ((struct Obj00733 *)p)->fE0=bg;
 func_02045334(bg);func_02045374(bg);func_020409B4(func_02045730(bg));
 ((struct Obj00733 *)p)->fEC=((struct Obj00733 *)p)->fE0;p[0xf0]=0;
 func_021F26F0((char *)p,(char *)p+0xec,window,font,heap);
 if(func_020355C4()==0){
  if(func_021F2818((char *)p,(Pair *)(p+0xd8),&box))func_021F1A1C((char *)p+0x24,1,(const struct Rect *)(&box),((struct Obj00733 *)p)->f104,((struct Obj00733 *)p)->f100);
 }else {
  if(func_021F2818((char *)p,(Pair *)(p+0xd8),&box))func_021F1A1C((char *)p+0x24,0,(const struct Rect *)(&box),((struct Obj00733 *)p)->f104,((struct Obj00733 *)p)->f100);
 }
}





void func_021F31B8(u8 *p) {int off;func_020452E8(((struct Obj24905 *)p)->fE0);func_021F2608(p);func_021F1A10(p+36);off=0x11c;func_020307B0(*(void **)(p+off));func_020307B0(*(void **)(p+off+4));off+=20;func_02082BCC(p,0,off);}





void func_021F31F4(char *p,char *q)
{
    int out0[4];
    int out2[4];
    Rect rect;
    int result;
    ((struct Obj00117 *)p)->fE8=0;
    switch(((struct Obj00117 *)p)->fE4){
    case 0:
        func_02082BCC(out0,0,16);
        result=func_021F38CC(p,out0);
        if(!result){func_021F36E8(p,out0);result=func_021F37EC(p,out0);}
        if(result)func_021F391C(p,out0);
        break;
    case 2:
        func_02082BCC(out2,0,16);
        result=func_021F3BD4(p,out2);
        if(!result){func_021F3A0C(p,out2);result=func_021F3B18(p,out2);}
        if(result)func_021F3C40(p,out2);
        if(func_021F33C0(p))((struct Obj00117 *)p)->fE4=0;
        break;
    case 1:
        if(func_021F23E4(q)){func_021F2828(p,7,(Pair *)(p+0xD8));((struct Obj00117 *)p)->fE8=11;}
        ((struct Obj00117 *)p)->fE4=0;
        break;
    }
    func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect));
    func_021F1BFC(p+0x24,((struct Obj00117 *)p)->f100,&rect);
    func_021F3304(p);
}






int func_021F32D8(char *p, unsigned short *out)
{
    int s = ((struct Obj10809 *)p)->fE8;
    if ((s == 1 || s == 2 || s == 9) && out != 0)
    {
        *out = ((struct Obj10809 *)p)->fFC;
    }
    return ((struct Obj10809 *)p)->fE8;
}




u32 func_021F32FC(const u8 *p) {return (u32)((struct Obj24907 *)p)->f104;}




int func_021F3304(char *p) {
 int q;
 q=((struct Obj05512 *)p)->fF8;
 if(((struct Obj05512 *)p)->fF0) {
 if(func_0201C6C4((struct PrintSys *)q,(void *)func_02045770((struct Descriptor *)*(int *)&((struct Obj05512 *)p)->fEC))==0) {
 func_02045334(((struct Obj05512 *)p)->fEC);((struct Obj05512 *)p)->fF0=0;
 }}
 if(((struct Obj05512 *)p)->fF0==0)return 1;return 0;
}




void *func_021F3350(const u8 *p) {return ((struct Obj24908 *)p)->f100;}




u32 func_021F3358(u32 a,u32 b,u32 c) {if(a==3) a=b+(a+2*c);return a;}




int func_021F3364(char *p,int mode) {
 int flag;
 if(((struct Obj00117 *)p)->f114!=mode) {
 ((struct Obj00117 *)p)->f114=mode;((struct Obj00117 *)p)->f10A=0;((struct Obj00117 *)p)->f10C=0;((struct Obj00117 *)p)->f110=1;
 flag=0;
 if(mode==3 || ((struct Obj00117 *)p)->f100==3)flag=1;
 ((struct Obj00117 *)p)->f118=flag;
 if(flag)func_0207D63C((void *)0x04000050,14,47,16,16);
 else func_0207D63C((void *)0x04000050,10,47,16,16);
 return 1;
 }return 0;
}




/*
 * note: 2026-10-05 wD4 lane09: EXACT. The calls in case 0 are written out in each arm of the f118 test (tail merge builds the shared movs r1,#0 join), so the join block holds only the state stores and the zero is not hoisted.
 */
int func_021F33C0(char *p) {
    int c;
    int y;
    if (*(u32 *)(p + 0x110) != 0)
    switch (*(u16 *)(p + 0x10c)) {
    case 0:
        func_02040804(1);
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16_021F2F8C)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16_021F2F8C)((c * -48) / 7);
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        if ((*(u16 *)(p + 0x10a))++ > 7) {
            if (*(u32 *)(p + 0x118)) {
                func_02040588(1, 0);
                func_02040588(2, 0);
                func_02040588(3, 0);
            } else {
                func_02040588(1, 0);
                func_02040588(3, 0);
            }
            *(u16 *)(p + 0x10a) = 0;
            *(u16 *)(p + 0x10c) = 1;
        }
        break;
    case 1:
        y = -48;
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        func_021F35A8(p, *(u32 *)(p + 0x114));
        *(u16 *)(p + 0x10c) = 2;
        break;
    case 2:
        *(u16 *)(p + 0x10a) = 7;
        *(u16 *)(p + 0x10c) = 3;
        func_02040588(1, 1);
        func_02040588(3, 1);
        if (*(u32 *)(p + 0x100) != 3) func_02040588(2, 1);
        *(u16 *)0x04000052 = 1 << 12;
        break;
    case 3:
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16_021F2F8C)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16_021F2F8C)((c * -48) / 7);
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        if ((*(u16 *)(p + 0x10a))-- == 0) *(u16 *)(p + 0x10c) = 4;
        break;
    case 4:
        func_02040618(1, 3, 0);
        func_02040618(3, 3, 0);
        func_02040618(2, 3, 0);
        *(u32 *)(p + 0x118) = 0;
        *(u16 *)0x04000050 = 0;
        *(u32 *)(p + 0x110) = 0;
        return 1;
    }
    return 0;
}




void func_021F35A8(char *p, u32 mode) {
 int index;
 if(((struct Obj01773 *)p)->f100==mode)return;
 func_021F2608(p);
 index=func_021F3358(mode,((struct Obj01773 *)p)->f104,((struct Obj01773 *)p)->f108);
 func_021F256C(p,mode,index,((struct Obj01773 *)p)->f12C,((struct Obj01773 *)p)->fFE);
 func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)((struct Obj01773 *)p)->fE0),0);
 func_021F26F0(p,p+0xEC,(void *)(((struct Obj01773 *)p)->fF8),(void *)(((struct Obj01773 *)p)->fF4),((struct Obj01773 *)p)->fFE);
 if(mode==3) {func_02040AE0(1,*(char * *)&((struct Obj01773 *)p)->f124+12,2048);func_02040588(2,0);}
 else func_02040AE0(1,*(char * *)&((struct Obj01773 *)p)->f128+12,2048);
 func_020409B4(1);
 if(mode==3 || ((struct Obj01773 *)p)->f100==3)func_021F2884((Pair *)(p+0xD8),((struct Obj01773 *)p)->f100,mode);
 ((struct Obj01773 *)p)->f100=mode;
}




/*
 * volatile: 021F3676 and 021F3696 re-read the mode word at +0x100.
 */
void func_021F366C(char *p,int index,int variant) {
 int selected;
 if(*(volatile int *)&((struct Obj00117 *)p)->f100!=3)return;
 if(((struct Obj00117 *)p)->f108==variant && ((struct Obj00117 *)p)->f104==index)return;
 selected=(int)func_021F3358((int)(*(volatile int *)&((struct Obj00117 *)p)->f100),(int)index,(unsigned char)variant);
 func_021F25F8((int *)p,selected,(int)((struct Obj00117 *)p)->f12C);
 func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)((struct Obj00117 *)p)->fE0),0);
 func_021F26F0(p,p+0xEC,(void *)(((struct Obj00117 *)p)->fF8),(void *)(((struct Obj00117 *)p)->fF4),((struct Obj00117 *)p)->fFE);
 ((struct Obj00117 *)p)->f104=index;((struct Obj00117 *)p)->f108=variant;
}




int func_021F36E8(char *p,int *out)
{
    Rect rect;
    Pair delta;
    int changed=0;
    if(func_0203633C()&64){delta.x=0;delta.y=-1;changed=1;}
    else if(func_0203633C()&128){delta.x=0;delta.y=1;changed=1;}
    else if(func_0203633C()&32){delta.x=-1;delta.y=0;changed=1;}
    else if(func_0203633C()&16){delta.x=1;delta.y=0;changed=1;}
    else if(func_020362DC()&8){
        delta.x=0;delta.y=0;changed=1;
        func_021F2828(p,7,(Pair *)(p+0xD8));
        func_021F26E0(p,(int)(p+0xD8),(int)&delta);
    }
    if(changed){
        if(func_020355C4()==1){
            if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                func_020355D8(0);
                func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                func_020061E4(1352);
            }
        }else{
            func_021F26E0(p,(int)p+0xD8,(int)&delta);
            if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                func_020061E4(1352);
                func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            }
        }
    }
    return 0;
}



int func_021F37EC(char *p,int *out)
{
    Rect rect;
    int changed;
    changed=0;
    if(func_020362DC()==1) {
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);
        out[1]=1;changed=1;
    }
    if(func_020362DC()==2) {
        func_021F2828(p,6,(Pair *)(out+2));out[0]=6;changed=1;
    }
    if(func_020362DC()==4) {
        out[0]=((struct Obj00117 *)p)->f100+3;
        if(out[0]>5)out[0]=2;
        func_021F2828(p,out[0],(Pair *)(p+0xD8));
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);changed=1;
    }
    if(func_020362DC()==256){((struct Obj00117 *)p)->fE8=10;changed=0;}
    if(changed && func_020355C4()==1) {
        if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))) {
            func_020061E4(1352);func_020355D8(0);
            func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            return 0;
        }
    }
    return changed;
}



int func_021F38CC(char *p,int *out) {
 int point[2];unsigned x,y;int u;
 if(func_02035D20(&x,&y)) {
 point[0]=x;point[1]=y;
 if(func_021F265C(p,point,(Pair *)(p+0xD8))) {
 u=((struct Obj14503 *)p)->fD8;out[3]=((struct Obj14503 *)p)->fDC;out[1]=1;out[2]=u;func_020355D8(1);return 1;
 }}return 0;
}



void func_021F391C(char *p,int *input)
{
    unsigned code;
    Rect rect;
    if(input[1])code=func_021F2614(p,(int *)(p+0xD8),(unsigned short *)(p+0xFC));
    else code=input[0];
    switch(code){
    case 0:break;
    case 1:((struct Obj00117 *)p)->fE8=1;((struct Obj00117 *)p)->fE4=1;break;
    case 9:((struct Obj00117 *)p)->fE8=9;((struct Obj00117 *)p)->fE4=1;break;
    case 2:case 3:case 4:case 5:
        if(func_021F3364(p,code-2)){
            func_020061E4(1611);((struct Obj00117 *)p)->fE4=2;((struct Obj00117 *)p)->fE8=6;
        }break;
    case 6:((struct Obj00117 *)p)->fE8=5;break;
    case 7:((struct Obj00117 *)p)->fE8=7;break;
    case 8:
        func_020061E4(1356);((struct Obj00117 *)p)->fE8=8;
        func_021F366C(p,((struct Obj00117 *)p)->f104^1,((struct Obj00117 *)p)->f108);break;
    case 10:((struct Obj00117 *)p)->fE8=3;break;
    case 11:((struct Obj00117 *)p)->fE8=4;break;
    }
    if(func_021F2818(p, (Pair *)((int)(input+2)), (Box *)((int)&rect)))
        func_021F1A1C(p+0x24,2,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
}



/*
 * lever: Integer address arithmetic for26E0 avoids caching p+D8 across2818.
 */
int func_021F3A0C(char *p,int *out)
{
    Rect rect;
    Pair delta;
    Pair point;
    int changed=0;
    if(((struct Obj00117 *)p)->f118==0){
        if(func_020362DC()&64){delta.x=0;delta.y=-1;changed=1;}
        else if(func_020362DC()&128){delta.x=0;delta.y=1;changed=1;}
        else if(func_020362DC()&32){delta.x=-1;delta.y=0;changed=1;}
        else if(func_020362DC()&16){delta.x=1;delta.y=0;changed=1;}
    }
    if(changed){
        point=*(Pair *)(p+0xD8);
        func_021F26E0(p,(int)&point,(int)&delta);
        if(func_021F2614(p,&point.x,0)-2<=3){
            if(func_020355C4()==1){
                if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                    func_020061E4(1352);func_020355D8(0);
                    func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                }
            }else{
                func_021F26E0(p,(int)p+0xD8,(int)&delta);
                if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                    func_020061E4(1352);
                    func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                }
            }
        }
    }
    return 0;
}










int func_021F3B18(char *p,int *out) {
    int changed=0;
    int rect[4];
    if (((struct Obj00117 *)p)->f118==0) {
        if (func_020362DC()&1) {
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1; out[1]=1;
        }
        if (func_020362DC()&4) {
            out[0]=((struct Obj00117 *)p)->f100+3;
            if (out[0]>5) out[0]=2;
            func_021F2828(p,out[0],(Pair *)(p+0xd8));
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1;
        }
        if (changed && func_020355C4()==1) {
            if (func_021F2818(p,(Pair *)(p+0xd8),(Box *)rect)) {
                func_020061E4(1352); func_020355D8(0);
                func_021F1A1C(p+0x24,1,(const struct Rect *)rect,((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                return 0;
            }
        }
    }
    return changed;
}










/*
 * note: unsigned result minus two tests the contiguous range; point precedes x/y declarations.
 */
int func_021F3BD4(char *p,int *out) {
    int point[2],u;
    unsigned x,y;
    if (((struct Obj00117 *)p)->f118==0) {
        if (func_02035D20(&x,&y)) {
            point[0]=x; point[1]=y;
            if (func_021F265C(p,point,(Pair *)(p+0xd8))) {
                if (func_021F2614(p,(int *)(p+0xd8),0)-2<=3) {
                    u=((struct Obj00117 *)p)->fD8;
                    out[3]=((struct Obj00117 *)p)->fDC;
                    out[1]=1; out[2]=u;
                    func_020355D8(1);
                    return 1;
                }
            }
        }
    }
    return 0;
}










void func_021F3C40(char *p,int *input) {
    unsigned code;
    int rect[4];
    if (input[1]) code=func_021F2614(p,(int *)(p+0xd8),(unsigned short *)(p+0xfc));
    else code=input[0];
    switch (code) {
    case 0: case 1: break;
    case 2: case 3: case 4: case 5:
        if (func_021F3364(p,code-2)) {
            func_020061E4(1611);
            ((struct Obj00117 *)p)->fE4=2; ((struct Obj00117 *)p)->fE8=6;
        }
        break;
    }
    if (func_021F2818(p,(Pair *)(input+2),(Box *)rect))
        func_021F1A1C(p+0x24,2,(const struct Rect *)rect,((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
}










void func_021F3CD0(unsigned char *p,int a,int b,int c,int d,unsigned short e) {
    int window;
    func_02082BCC(p,0,0x24);
    ((struct Obj01774 *)p)->f20=15;
    ((struct Obj01774 *)p)->f4=a; ((struct Obj01774 *)p)->f18=d; ((struct Obj01774 *)p)->f0=b; ((struct Obj01774 *)p)->f10=c;
    ((struct Obj01774 *)p)->f1C=(int)func_020457B0(255,e);
    ((struct Obj01774 *)p)->f14=func_020450F0(4,1,19,30,4,15,1);
    func_0201F73C((void *)(((struct Obj01774 *)p)->f14),2,1,14);
    ((struct Obj01774 *)p)->f8=((struct Obj01774 *)p)->f14;
    ((struct Obj01774 *)p)->fC=0;
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)((struct Obj01774 *)p)->f14),((struct Obj01774 *)p)->f20);
    window=((struct Obj01774 *)p)->f14;
    func_02045334((struct Descriptor *)window); func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730((struct Descriptor *)window));
}











/*
 * Addresses are Black-image addresses.
 */
void func_021F3D54(u8 *p)
{
    func_020452E8((struct Descriptor *)(((struct Obj14504 *)p)->f14));
    func_02045808((struct U16Vec *)(((struct Obj14504 *)p)->f1C));
    func_02082BCC(p, 0, 0x24);
}










void func_021F3D70(char *p,int value) {
    int window;
    while (func_0201C6C4((struct PrintSys *)(((struct Obj02239 *)p)->f10),(void *)((int)func_02045770((struct Descriptor *)((struct Obj02239 *)p)->f14))))
        func_0201C4E4((struct PrintSys *)(((struct Obj02239 *)p)->f10));
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj02239 *)p)->f14)),((struct Obj02239 *)p)->f20);
    func_02045CAC((struct MsgBank *)(((struct Obj02239 *)p)->f0),value,(void *)(((struct Obj02239 *)p)->f1C));
    window=((struct Obj02239 *)p)->f10;
    func_0201C6FC((struct PrintSys *)window,(int)func_02045770((struct Descriptor *)((struct Obj02239 *)p)->f8),0,0,(void *)(*(int *)&((struct Obj02239 *)p)->f1C),((struct Obj02239 *)p)->f4);
    ((struct Obj02239 *)p)->fC=1;
}










void func_021F3DE0(char *p,int value,u32 id,u32 form,u16 heap) {void *mon;mon=func_020173F0(id,1,0,heap);func_02017E40(mon,111,form);func_021F3E18(p,value,mon);func_020307B0(mon);}










void func_021F3E18(char *p,int value,void *mon) {
    int text,window;
    func_0201EE84(((struct Obj02532 *)p)->f18,0,mon);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj02532 *)p)->f14)),((struct Obj02532 *)p)->f20);
    text=(int)func_02045EC0((struct MsgBank *)(((struct Obj02532 *)p)->f0),value);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj02532 *)p)->f18),((struct Obj02532 *)p)->f1C,(void *)text);
    window=((struct Obj02532 *)p)->f10;
    func_0201C6FC((struct PrintSys *)window,(int)func_02045770((struct Descriptor *)((struct Obj02532 *)p)->f8),0,0,(void *)(*(int *)&((struct Obj02532 *)p)->f1C),((struct Obj02532 *)p)->f4);
    ((struct Obj02532 *)p)->fC=1;
    func_02045808((struct U16Vec *)text);
}










int func_021F3E78(u8 *p) {int window;window=((struct Obj05513 *)p)->f10;if(p[12]) {if(func_0201C6C4((struct PrintSys *)window,(void *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj05513 *)p)->f8)))==0) {func_02045334(((struct Obj05513 *)p)->f8);p[12]=0;}}if(!p[12]) return 1;return 0;}










void func_021F3EB0(char *p, int v)
{
    MI_CpuFill8(p, 0, 0x10);
    ((struct Obj24909 *)p)->f4 = func_0203101C(v, v, 1, 0);
}









void func_021F3ED0(unsigned char *p){if(((struct Obj10810 *)p)->f0)func_0201CE48(((struct Obj10810 *)p)->f0);func_02031140(*(struct S02031140 * *)&((struct Obj10810 *)p)->f4);func_02082BCC((unsigned char *)p, 0, 16);}








void func_021F3EF0(char *p,char *q,int *w,u32 heap)
{
    void *set=func_0201EC64(heap);
    if(func_0216C0E4(w)) func_0201EEF4(set,0,(void *)w[2]);
    else {
        int text=(int)func_02045874((struct U16Vec *)w[8],heap);
        func_0216C0D4(w,text);
        func_0201EE0C(set,0,(void *)text,0,0,0);
        func_02045808((struct U16Vec *)text);
    }
    func_0201F164(set,1,w[4],w[5]);
    if(((struct Obj04591 *)p)->f0) func_0201CE48((int)((struct Rec3 *)(((struct Obj04591 *)p)->f0)));
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj03900 *)q)->f14)),((struct Obj03900 *)q)->f20);
    func_0204581C(((struct Obj03900 *)q)->f1C);
    func_0201F250(set,((struct Obj03900 *)q)->f1C,(void *)w[3]);
    ((struct Obj04591 *)p)->f0=func_0201CCE4(((struct Obj03900 *)q)->f14,0,0,*(u32 *)&((struct Obj03900 *)q)->f1C,((struct Obj03900 *)q)->f4,func_02012FFC(),((struct Obj04591 *)p)->f4,2,heap,((struct Obj03900 *)q)->f20);
    ((struct Obj04591 *)p)->fE=0;
    *(void (**)(void))(p+8)=(void (*)(void))func_021F46B4;
    ((struct Obj04591 *)p)->fC=60;
    func_0201ED04(set);
}









void func_021F3FBC(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap)
{
    u32 flagA = 0;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u8 v2c;
    void *h;
    u32 w24 = 0x22;
    u32 h20 = 0x14;
    u32 v1c;
    u32 flagB = 0;

    func_02082BCC((unsigned char *)o, 0, 0x3c);
    v2c = 0;
    switch (mode) {
    case 0:
    case 1:
        v40 = func_020275E4();
        v3c = func_020276A4();
        v38 = func_020276A8();
        v34 = func_020276AC(2);
        v30 = func_020276B0(2);
        v1c = a2;
        break;
    case 2:
        v40 = 0x20;
        v3c = flagB;
        v2c = d_021F5569[a2];
        v38 = a2 + 0x31;
        v34 = 0x41;
        v30 = 0x42;
        v1c = (a2 >= 8) ? 1 : flagB;
        break;
    case 3:
        flagA = 1;
        v1c = (a3 & 0xFF00) >> 8;
        if (v1c == 2) {
            flagA = 0;
        }
        v40 = 7;
        v3c = func_0201BC3C();
        v38 = func_0201BABC(a2, (u8)a3, v1c, 0);
        v34 = func_0201BC40();
        v30 = func_0201BCB4();
        w24 = 0x1e;
        h20 = 0x14;
        flagB = 1;
        break;
    case 4:
    case 5:
        v40 = 0x76;
        v3c = 9;
        v38 = 8;
        v34 = 7;
        v30 = 6;
        v2c = 1;
        break;
    }
    h = func_020490F4(v40, heap);
    if (flagB != 0) {
        *(void **)(o + 8) = (void *)func_0204ACEC(h, v3c, 0, 0x40, heap);
    } else {
        *(void **)(o + 8) = (void *)func_0204AC18(h, v3c, 0, 0x40, v2c, 1, heap);
    }
    *(void **)(o + 0x10) = (void *)func_0204AF28(h, v34, v30, heap);
    flagB = 0;
    *(void **)(o + 0xC) = (void *)func_0204A6C8(h, v38, 0, 0, heap);
    func_02049238(h);
    {
        Dim8 dim;
        func_02082BCC((unsigned char *)&dim, 0, 8);
        dim.w = w24;
        dim.h = h20;
        *(void **)o = func_0204B294((void *)s0, (u32)(*(void **)(o + 0xC)), (u32)(*(void **)(o + 8)), (u32)(*(void **)(o + 0x10)), &dim, flagB, heap);
    }
    func_0204B92C(*(void **)o, 1);
    switch (mode) {
    case 0:
        if (a2 == 0) {
            func_021F51E4(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
        } else {
            func_021F51E4(*(void **)o, 0x31, 9, 3, 4, 4, 0, 0, heap);
        }
        break;
    case 1:
        func_021F51E4(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
    case 2:
        func_0204B6F4(*(void **)o, 0, 1);
        break;
    case 3:
        func_0204B878(*(void **)o, 1);
        func_0204B6F4(*(void **)o, func_0201BB5C(a2, (u8)a3, (a3 & 0xFF00) >> 8, flagB), flagB);
        break;
    case 5:
        func_0204B878(*(void **)o, 5);
        func_0204B6F4(*(void **)o, flagB, 1);
        break;
    case 4:
        func_0204B878(*(void **)o, 2);
        func_0204B6F4(*(void **)o, flagB, 1);
        break;
    }
    if (flagA != 0) {
        void *h2;
        u32 r;
        u32 idx;
        u8 st[0x18];
        h2 = func_020490F4(0x17, heap);
        *(void **)(o + 0x30) = func_02043678(2, 2, 0x20, heap);
        *(void **)(o + 0x24) = (void *)func_0204ACEC(h2, 5, 0, 0xA0, heap);
        func_02049238(h2);
        func_02082BCC((unsigned char *)st, 0, 0x18);
        *(void **)(st + 0) = *(void **)(o + 0x30);
        *(u16 *)(st + 4) = 0x2e;
        *(u16 *)(st + 6) = 0x14;
        *(void **)(st + 8) = *(void **)(o + 0x24);
        *(u8 *)(st + 0x10) = 0;
        *(u16 *)(st + 0x12) = 0;
        *(u32 *)(st + 0x14) = 0;
        *(u8 *)(st + 0x11) = 0;
        *(u32 *)(st + 0xC) = 0;
        *(void **)(o + 0x2C) = func_020255A0((struct Sys *)s4, (const struct Param *)st);
        if (v1c == 1) {
            idx = 0x11;
            r = 0xC80;
        } else {
            idx = 0x10;
            r = 0x14C0;
        }
        *(void **)(o + 0x28) = func_02045EC0(s3, idx);
        func_02043B5C(*(void **)(o + 0x30), 0);
        func_0201C724(s2, *(void **)(o + 0x30), 0, 0, *(void **)(o + 0x28), s1, r);
        *(u32 *)(o + 0x38) = s2;
        *(u32 *)(o + 0x34) = 1;
    }
}







void func_021F42A0(unsigned char *p) {
    if (((struct Obj03342 *)p)->f2C) {
        func_0204ADA4(((struct Obj03342 *)p)->f24);
        func_02045808(((struct Obj03342 *)p)->f28);
        func_0202570C(((struct Obj03342 *)p)->f2C);
        func_020437AC(((struct Obj03342 *)p)->f30);
    }
    func_0204ADA4(((struct Obj03342 *)p)->f8);
    func_0204A8D4((u32)(((struct Obj03342 *)p)->fC));
    func_0204AFD8(((struct Obj03342 *)p)->f10);
    func_0204B3B4(((struct Obj03342 *)p)->f0);
    func_02082BCC(p,0,0x3c);
}







void func_021F42E8(char *p) {
    int rect[4];
    unsigned x,y;
    Vec2 pos;
    int point[2];
    switch (((struct Obj01576 *)p)->f18) {
    case 0:
        func_0204B454((struct Actor *)((struct Obj01576 *)p)->f0,(struct PtS *)&pos,0);
        ((struct Obj01576 *)p)->f14=0;
        if (func_02035D20(&x,&y)) {
            rect[0]=pos.x-16; rect[1]=pos.y-16;
            rect[2]=pos.x+16; rect[3]=pos.y+16;
            point[0]=x; point[1]=y;
            if (func_021F4450(rect,point)) {
                func_021F4394((unsigned char *)p);
                ((struct Obj01576 *)p)->f18=1;
            }
        }
        break;
    case 1:
        if (func_021F43A0(p)) {((struct Obj01576 *)p)->f14=1; ((struct Obj01576 *)p)->f18=0;}
        break;
    }
}







void func_021F436C(unsigned char *p){if(((struct Obj06641 *)p)->f34){if(func_0201C6C4((struct PrintSys *)(((struct Obj06641 *)p)->f38), (void *)(((struct Obj06641 *)p)->f30))==0){func_020257D0(*(struct Obj * *)&((struct Obj06641 *)p)->f2C);((struct Obj06641 *)p)->f34=0;}}}







unsigned func_021F4390(unsigned char *p){return ((struct Obj24910 *)p)->f14;}







void func_021F4394(unsigned char *p){((struct Obj01576 *)p)->f20=0;*(unsigned *)&((struct Obj01576 *)p)->f1C=1;}







int func_021F43A0(char *p) {
    Vec2 pos;
    int tick;
    if (((struct Obj01576 *)p)->f1C) {
        tick=((struct Obj01576 *)p)->f20;
        ((struct Obj01576 *)p)->f20=tick+1;
        func_0204B454((struct Actor *)((struct Obj01576 *)p)->f0,(struct PtS *)&pos,0);
        pos.y=20-((12*d_020A1B38[((unsigned short)(32767*tick/8)>>4)*2])>>12);
        func_0204B404((struct Obj *)(((struct Obj01576 *)p)->f0),(const struct Vec2 *)(&pos),0);
        if (((struct Obj01576 *)p)->f20>8) ((struct Obj01576 *)p)->f1C=0;
        return 0;
    }
    return 1;
}







int func_021F4408(int x, int y)
{
    switch (x) {
    case 0:
    case 5:
    case 6:
    case 7:
        return 0;
    case 1: return 3;
    case 2: return 4;
    case 3: return 1;
    case 4: return y == 0xffff ? 5 : 2;
    default: return 0;
    }
}







int func_021F4450(int *p, int *q){return ((((struct Obj14505 *)q)->f0-((struct Obj05514 *)p)->f0)<=(((struct Obj05514 *)p)->f8-((struct Obj05514 *)p)->f0)) & ((((struct Obj14505 *)q)->f4-((struct Obj05514 *)p)->f4)<=(((struct Obj05514 *)p)->fC-((struct Obj05514 *)p)->f4));}








int func_021F4480(u8 *p, int a, int b)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        if (func_020458F8((struct U16Vec *)(((struct Obj01287 *)p)->f2D0)) == 0)
            return (int)func_02045EC0((struct MsgBank *)d_020A7370,
                                 *(u16 *)(*(u32 *)&((struct Obj01287 *)p)->f2C4 + 4));
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 2:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 3:
        return 0;
    case 4:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 5:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 6:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 7:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    default:
        return 0;
    }
}






void func_021F4524(char *p) {
    int text;
    char *obj;
    ((struct Obj24911 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=0;
    text=(int)func_02045874((struct U16Vec *)(((struct Obj24912 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20),30);
    func_021F2328(p+0x68,(struct Strbuf *)((struct Obj24913 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20);
    if (func_0204589C((struct Buf *)text,(struct Buf *)(((struct Obj24914 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20)))
        ((struct Obj24915 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=1;
    if (!func_021F253C((u8 *)((int)(p+0x68)))) {
        func_02045838((struct U16Vec *)(((struct Obj24916 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20),(struct U16Vec *)text);
        ((struct Obj24917 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=1;
    }
    func_02045808((struct U16Vec *)text);
    if (!func_020458F8((struct U16Vec *)(((struct Obj24918 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20))) {
        obj=*(char * *)&((struct Obj03343 *)p)->f2C4;
        if (((struct Obj10811 *)obj)->f0!=0 && ((struct Obj10811 *)obj)->f0!=3) ((struct Obj10811 *)obj)->f1C=1;
    }
}







int func_021F45A8(int p)
{
    int *q = *(int * *)&((struct Obj24919 *)p)->f2C4;

    if (*q == 0 || *q == 3) {
        if (func_021F23F4((const u8 *)(p + 0x68)) == 0 && func_021F23F8((const u8 *)(p + 0x68)) == 0) {
            return 0;
        }
        if (func_021F253C((u8 *)(p + 0x68)) == 0) {
            return 0;
        }
    }
    return 1;
}







void func_021F45EC(u8 *a, u32 b, u32 c)
{
    func_02082BCC(a, 0, 0x10);
    ((struct Obj24920 *)a)->fC = b;
    func_021F462C(a, c);
}






void func_021F4608(void *p){func_02082BCC(p,0,16);}







void func_021F4614(u8 *p)
{
    if (((struct Obj14507 *)p)->f4 == 0) {
        ((fn_021F4614_t)*(void **)p)(p, p + 8, ((struct Obj14507 *)p)->fC);
    }
}






unsigned func_021F4628(unsigned char *p){return ((struct Obj24921 *)p)->f4;}






void func_021F462C(unsigned char *p,unsigned value){((struct Obj14508 *)p)->f0=value;((struct Obj14508 *)p)->f8=0;}






void func_021F4634(unsigned char *p){((struct Obj24922 *)p)->f4=1;}






void func_021F463C(unsigned char *p,int *unused,unsigned char *q){int v;v=func_021F3304((char *)(q+252));v|=func_021F22E8(q+104);if(func_021F3E78(q+560)|v)func_021F462C(p,(unsigned)func_021F4674);}






void func_021F4674(unsigned char *p,int *state) {
    switch (*state) {
    case 0: func_0204E720(3,16,0,0); *state=1; break;
    case 1: if (!func_0204E804()) *state=2; break;
    case 2: func_021F462C(p,(unsigned)func_021F47B4); break;
    }
}






void func_021F46B4(unsigned char *p,int *state) {
    switch (*state) {
    case 0: func_0204E720(3,0,16,0); *state=1; break;
    case 1: if (!func_0204E804()) *state=2; break;
    case 2: func_021F462C(p,(unsigned)func_021F4A5C); break;
    }
}






/*
 * Padding: two zero bytes at 0x021F47B2, then a function prologue.
 */
void func_021F46F4(unsigned char *a, int *state, char *p)
{
    char *q = p + 0x254;
    switch (*state) {
    case 0:
        sub_020310C4(*(struct Tcbl * *)&((struct Obj03901 *)q)->f4);
        switch (sub_0201CE30(((struct Obj03901 *)q)->f0)) {
        case 0:
            if (((unsigned)sub_0203630C() & 3) != 0 || sub_02035C38() != 0) {
                sub_0201CE5C(*(struct Rec * *)&((struct Obj03901 *)q)->f0, 0);
                if (((unsigned)sub_0203630C() & 3) != 0) sub_020355D8(0);
                else sub_020355D8(1);
            }
            break;
        case 2:
            *state = 1;
            break;
        case 1:
            if (((unsigned)sub_020362DC() & 3) != 0 || sub_02035C60() != 0) {
                sub_0201CE38(((struct Obj03901 *)q)->f0);
                if (((unsigned)sub_020362DC() & 3) != 0) sub_020355D8(0);
                else sub_020355D8(1);
            }
            break;
        }
        break;
    case 1:
        if (((struct Obj03901 *)q)->fE >= ((struct Obj03901 *)q)->fC) *state = 2;
        else (((struct Obj03901 *)q)->fE)++;
        break;
    case 2:
        func_021F462C(a, ((struct Obj03901 *)q)->f8);
        break;
    }
}






static inline int invert(char *p,int v) { int r=1; if(func_021F21FC((unsigned char *)p,v)==0) r=0; return r; }






void func_021F47B4(unsigned char *owner,void *unused,char *p)
{
    u16 selected;
    u32 action=func_021F32D8(p+0xfc,&selected);
    u32 value=func_021F32FC((const u8 *)(p+0xfc));
    if(((struct Obj01287 *)p)->f2C8==1) {
        if(action!=0 || func_021F4390((unsigned char *)(p+0x264))!=0 || (func_020362DC()&~1u)!=0) {
            int *q=*(int * *)&((struct Obj01287 *)p)->f2C4;
            if(q[0]==1) {
                if(q[2]==0) func_021F3DE0(p+0x230,q[0],((struct Obj01577 *)q)->f4,((struct Obj01577 *)q)->f6,30);
                else func_021F3E18(p+0x230,q[0],(void *)q[2]);
            } else func_021F3D70(p+0x230,q[0]);
            ((struct Obj01287 *)p)->f2C8=0;
        }
    }
    switch(action) {
    case 1: if(func_021F2190(p+0x68,selected)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 2: if(func_021F21BC((unsigned char *)(p+0x68),selected,value)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 3: if(invert(p+0x68,0)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 4: if(invert(p+0x68,1)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 10: if(func_021F22AC(p+0x68)) func_020061E4(0x54c); else func_020061E4(0x557); break;
    case 5: if(func_021F2150((unsigned char *)(p+0x68))) func_020061E4(0x553); else func_020061E4(0x557); break;
    case 6: func_021F233C(p+0x68); break;
    case 11: func_021F235C(p+0x68); break;
    case 7: if(func_021F23F8((const u8 *)((int)(p+0x68)))==0) {
        if(func_021F45A8((int)p)==0) {func_020061E4(0x557);func_021F3D70(p+0x230,8);((struct Obj01287 *)p)->f2C8=1;}
        else {
            if(func_021F5370(*(u32 * *)&((struct Obj01287 *)p)->f2CC,p+0x68,30)) func_020061E4(0x557);
            else if(func_021F54CC(p+0x68,((struct Obj01287 *)p)->f86,30)) {func_020061E4(0x557);func_021F3D70(p+0x230,9);((struct Obj01287 *)p)->f2C8=1;}
            else {
                int *q;
                func_020061E4(0x54d);func_021F4524(p);q=*(int * *)&((struct Obj01287 *)p)->f2C4;
                if(q[0]==1 && q[3]!=0) {func_021F3EF0(p+0x254,p+0x230,q,30);func_021F462C(owner,(u32)func_021F46F4);}
                else func_021F462C(owner,(u32)func_021F46B4);
            }
        }
    } else {func_021F235C(p+0x68);func_020061E4(0x54d);} break;
    case 0: if(func_021F4390((unsigned char *)(p+0x264))) {
        int text=func_021F4480((u8 *)p,**(int * *)&((struct Obj01287 *)p)->f2C4,30);
        func_021F2394((unsigned char *)(p+0x68));
        if(text) {func_021F23B8(p+0x68,func_02045A90((struct U16Vec *)text));func_02045808((struct U16Vec *)text);}
        func_020061E4(0x54c);
    } break;
    case 9: func_021F235C(p+0x68);if(func_021F2190(p+0x68,selected)) func_020061E4(0x54c); else func_020061E4(0x557);break;
    default: break;
    }
    func_021F31F4(p+0xfc,p+0x68);
    func_021F1FB4((u8 *)(p+0x68));
    func_021F42E8(p+0x264);
    func_021F3E78((u8 *)(p+0x230));
}






void func_021F4A5C(unsigned char *a, int unused, char *p)
{
    unsigned n;
    if (*(void **)(OBJ(p) + 0x28) != 0) {
        n = (unsigned int)func_021F3350((const unsigned char *)(p + 0xFC));
        func_0200C0FC(*(void **)(OBJ(p) + 0x28), (u32)(*(void **)OBJ(p)), n);
    }
    if (*(void **)(OBJ(p) + 0x24) != 0) func_021F462C(a, (unsigned)func_021F4AA8);
    else func_021F4634(a);
}






void func_021F4AA8(unsigned char *p,int *state,unsigned char *q){switch(*state){case 0:func_021BD368(*(unsigned char * *)&((struct Obj24924 *)(*(unsigned char * *)&((struct Obj14510 *)q)->f2C4))->f24);*state=1;break;case 1:if(func_021BD380(*(unsigned char * *)&((struct Obj24925 *)(*(unsigned char * *)&((struct Obj14510 *)q)->f2C4))->f24)==1)func_021F4634(p);break;}}






static inline void G2_BlendNone(void) { *(volatile unsigned short *)0x04000050 = 0; }






static inline void G2S_BlendNone(void) { *(volatile unsigned short *)0x04001050 = 0; }






static inline void GX_SetVisibleWnd(int window) { *(volatile unsigned *)0x04000000 = (*(volatile unsigned *)0x04000000 & ~0xE000) | (window << 13); }






static inline void GXS_SetVisibleWnd(int window) { *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xE000) | (window << 13); }






/*
 * volatile: hardware 0x04000050, 0x04001050, 0x04000000, 0x04001000.
 */
unsigned char *func_021F4AE4(unsigned swap, unsigned short heap)
{
    unsigned char *p;
    p = func_02030734(heap, 0x10, 0, d_021F5784, 0x1BB);
    func_02082BCC(p, 0, 0x10);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    sub_0204335C(0);
    func_020433E0(&d_021F55D0);
    func_0204363C(swap);
    func_0204361C();
    sub_020434CC();
    func_02043588();
    func_0201DD60();
    func_021F4C0C(p, heap);
    func_021F4CB0(p + 4, (int)&d_021F55D0, heap);
    ((struct Obj24926 *)p)->fC = sub_020056A0((unsigned)func_021F4BF8, (unsigned)p, 0);
    return p;
}






void func_021F4B84(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj24927 *)p)->fC);
    func_021F4CF0(p + 4);
    func_021F4C6C(p);
    func_0201DD68();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}







void func_021F4BD8(u8 *p)
{
    func_021F4D0C(p + 4);
    func_021F4CA4(p);
}





unsigned func_021F4BEC(unsigned char *p){return func_021F4D1C((const unsigned *)(p+4));}






void func_021F4BF8(u32 a, u8 *b)
{
    func_021F4CA8(b);
    func_021F4D14(b + 4);
}



/*
 * Match lever: bind the entry id before binding its element pointer.
 */
void func_021F4C0C(void *p, unsigned short heap)
{
    unsigned i = 0;
    unsigned id;
    const Entry *e;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    sub_02045088(heap);
    func_0203FC28((struct DispConfig *)(&d_021F55A4));
    for (; i < 8; i++) {
        id = d_021F5600[i].id;
        e = &d_021F5600[i];
        func_0203FCA0(id, &e->config, e->type);
        func_020414AC(id);
        sub_02040588((unsigned char)id, (unsigned char)e->enabled);
    }
}





/*
 * evidence: caller truncates id to u8 before 020403F4, whose own source uses u32.
 */
void func_021F4C6C(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4((u8)d_021F5600[i].id);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}






void func_021F4CA4(u8 *a0) {}






void func_021F4CA8(u8 *a0) { func_020419E4(); }







void func_021F4CB0(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021F55B4, a, b);
    *(int *)&((struct Obj14512 *)p)->f0 = (int)func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14512 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}







void func_021F4CF0(u8 *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj24928 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}






void func_021F4D0C(u8 *a0) { func_0204A600(); }





void func_021F4D14(u8 *a0) { func_0204A648(); }





/*
 * extent: lead tail-call stub followed by unlabelled load-and-return at 021F4D1C.
 */
u32 func_021F4D1C(const u32 *p) { return *p; }






int func_021F4D20(u32 a, u32 b)
{
    return func_0204A1BC(0x77, a, 0, b);
}





void func_021F4D34(void *p) { func_020307B0(p); }





/*
 * evidence: caller consumes 021F4D20 r0; full forwarder leaves 0204A1BC allocation result live despite own void declaration.
 */
u32 *func_021F4D3C(u32 heap)
{
    u32 *p;
    int i = 0;
    p = func_02030734(heap, 20, 0, d_021F5798, 147);
    func_02082BCC(p, 0, 20);
    for (; i < 5; i++)
        p[i] = func_021F4D20(i, heap);
    return p;
}






void func_021F4D78(u8 *p)
{
    int i;

    for (i = 0; i < 5; i++) {
        func_021F4D34((void *)(*(u32 *)(p + i * 4)));
    }
    func_020307B0(p);
}





u32 func_021F4D94(const u8 *p, u32 i) { return *(const u32 *)(p + i * 4); }





u16 func_021F4D9C(const u16 *p) { return *p; }





u16 func_021F4DA0(const u16 *p) { return p[1]; }






u32 func_021F4DA4(u8 *p, u16 a, u16 b)
{
    return *(u16 *)(p + ((a + b * func_021F4D9C((const u16 *)p)) << 1) + 4);
}





int func_021F4DBC(int a, int b)
{
    return func_0204A1BC(0x77, a + 5, 0, b);
}




void func_021F4DD0(void *p) { func_020307B0(p); }




u16 func_021F4DD8(const u16 *p) { return *p; }




void func_021F4DDC(const char *p,int i,u16 *dst,u32 n,u8 *count) {func_0201F41C((const u16 *)(p+2+i*24),dst,n);if(count){*count=0;while(*count<3 && dst[*count]!=0x3000) ++*count;}}





int func_021F4E18(int p, int idx, unsigned short *tab, int val, unsigned char *out)
{
    unsigned char i;

    func_0201F41C((const u16 *)(p + 8 + 0x18 * idx), (u16 *)((int)tab), val);
    i = 0;
    while (i < 3 && tab[i] != 0x3000) {
        i++;
    }
    if (out != 0) {
        *out = (unsigned char)i;
    }
    return i != 0;
}





int func_021F4E58(int p, int idx, unsigned short *tab, int val, unsigned char *out)
{
    unsigned char i;

    func_0201F41C((const u16 *)(p + 0xe + 0x18 * idx), (u16 *)((int)tab), val);
    i = 0;
    while (i < 3 && tab[i] != 0x3000) {
        i++;
    }
    if (out != 0) {
        *out = (unsigned char)i;
    }
    return i != 0;
}




int func_021F4E98(char *p, int index, unsigned short *table, unsigned n, unsigned char *out)
{
    unsigned char i;
    func_0201F41C((const unsigned short *)(p + 0x14 + 0x18 * index), table, n);
    i = 0;
    while (i < 3 && table[i] != 0x3000) i++;
    if (out != 0) *out = i;
    return i != 0;
}




u16 func_021F4ED8(const char *p,const u16 *b) {int n=func_021F4DD8((const u16 *)p);int i;for(i=0;i<n;i++){if(func_021F4F10((const u16 *)(p+2+i*24),b))return i;}return 65535;}




int func_021F4F10(const unsigned short *a, const unsigned short *b)
{
    unsigned short sentinel = func_02045A98();
    int i;
    for (i = 0; i < 3; i++, a++, b++) {
        if (*a == 0x3000 && *b == sentinel) return 1;
        if (*a != *b) return 0;
        if (*b == sentinel) return 0;
    }
    return 1;
}





int func_021F4F50(int a)
{
    return func_0204A1BC(0x77, 8, 0, a);
}




void func_021F4F60(void *p) {func_020307B0(p);}




int func_021F4F68(const u16 *p) {return *p;}




unsigned short func_021F4F6C(char *base, int i, int j)
{
    return *(unsigned short *)(base + i * 6 + 2 + j * 2);
}




int func_021F4F7C(char *p, const unsigned short *key, unsigned short *out)
{
    int i, j;
    if (*key == 0x3000) return 0;
    for (i = 0; i < func_021F4F68((const u16 *)p); i++) {
        for (j = 0; j < 3; j++) {
            if (*key == func_021F4F6C(p, (unsigned short)i, (unsigned short)j)) {
                p += i * 6;
                do {
                    j = (j + 1) % 3;
                    *out = *(unsigned short *)(p + 2 + j * 2);
                } while (*out == 0x3000);
                return 1;
            }
        }
    }
    return 0;
}




/*
 * note (2026-10-05, wD4 lane09): EXACT. `j = 0;` before `p = bufs[k];` at the k-loop top, declaration
 *   order bufs, ret, h, j, idx, k, v, t, and func_021F4DA4 declared with u16 parameters (as its other
 *   callers do) so the call passes m and j uncast; the conversion temp then takes sp+0x20, not sp+0.
 */
u32 func_021F5004(u16 *s, u32 x)
{
    u8 *bufs[4];
    u32 ret;
    u8 *h;
    int j, idx, k;
    u32 v;
    int t;
    int i, m;
    u32 found;
    u8 *p;
    v = (x & 0x7FFF) | 0x8000;
    for (i = 0; i < 4; i++) bufs[i] = (u8 *)func_021F4D20(i, (u16)v);
    h = (u8 *)func_021F4F50(v & 0xFFFF);
    ret = 1;
    idx = 0;
    while (s[idx] != func_02045A98()) {
        found = 0;
        for (k = 0; (u32)k < 4; k++) {
            j = 0;
            p = bufs[k];
            for (; j < (int)func_021F4DA0((const u16 *)p) && found == 0; j++) {
                for (m = 0; m < (int)func_021F4D9C((const u16 *)p) && found == 0; m++) {
                    if (s[idx] == func_021F4DA4(p, m, j)) found = 1;
                }
            }
        }
        for (t = 0; t < func_021F4F68((const u16 *)h); t++) {
            for (m = 0; m < 3; m++) {
                if (s[idx] == func_021F4F6C((char *)h, (u16)t, (u16)m)) found = 1;
            }
        }
        if (found == 0) {
            ret = 0;
            break;
        }
        idx++;
    }
    func_021F4F60(h);
    for (i = 0; i < 4; i++) func_021F4D34(bufs[i]);
    return ret;
}




void func_021F513C(const char *src, int width, int x, int y, int w, int h, char *dst)
{
    unsigned inOffset;
    unsigned outOffset;
    int i, j;
    unsigned step;
    unsigned target;
    step = width * 4;
    target = (unsigned)dst;
    outOffset = 0;
    for (j = y; j < y + h; j++) {
        for (i = x; i < x + w; i++) {
            inOffset = i * 4 + j * step * 8;
            func_021F51A4(src, (char *)target, &inOffset, &outOffset, 4, step);
        }
    }
}




/*
 * Padding: two zero bytes at 0x021F51E2, then a function prologue.
 */
void func_021F51A4(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step)
{
    int i;
    for (i = 0; i < 8; i++) {
        func_02082D44(src + *a, dst + *b, n);
        *a += step;
        *b += n;
    }
}




static inline u8 *entry(u8 *p,u32 i) {
    if(p) {
        u8 *q=p+0x3c;
        if(q && i<((struct Obj14518 *)p)->f3D) {
                u16 off=((struct Obj14518 *)p)->f42;
                u16 stride=*(u16 *)(q+off);
                return q+off+4+stride*i;
        } else return 0;
    }
    return 0;
}




void func_021F51E4(u8 *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap)
{
    Palette pal;
    u32 size=width*height*32;
    void *archive=func_020490F4(arc,heap);
    u8 *raw=func_02049250(archive,member,heap);
    u8 *tex=func_0206E964(raw);
    u8 *pixels;
    u32 offset;
    offset=(*(u32 *)entry(tex,index)&0xffff)*8;
    pixels=tex+((struct Obj14519 *)tex)->f14;
    void *buf=func_02030734((u16)((heap&0x7fff)|0x8000),size,0,d_021F57A8,95);
    func_021F513C((const char *)(pixels+offset),width,0,0,width,height,buf);
    func_0204AA94(func_0204B7F0(dst),buf,size,pos,mode);
    func_020307B0(buf);
    u32 poff=((struct Obj14519 *)tex)->f38;
    func_020862F0(tex+poff,32);
    func_0204B764((const char *)dst,(struct Struct20 *)(&pal));
    if(mode==0 || mode==2) func_0207E51C(tex+poff,func_02063800((char *)&pal,1),32);
    if(mode==1 || mode==2) func_0207E5D0(tex+poff,func_02063800((char *)&pal,2),32);
    func_020307B0(raw);
    func_02049238(archive);
}
