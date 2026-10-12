/*
 * file:     pms_select_graphic.c
 * unit:     yes
 * function: func_021C025C, func_021C0490, func_021C05B0, func_021C060C, func_021C07E8, func_021C080C, func_021C088C, func_021C098C, func_021C09E0, func_021C09E8, func_021C0A54, func_021C0AB4, func_021C0AC0, func_021C0AC8, func_021C0B44, func_021C0B4C, func_021C0B54, func_021C0C18, func_021C0C38, func_021C0C44, func_021C0C50, func_021C0C64, func_021C0D34, func_021C0DE4, func_021C0E3C, func_021C0EB0, func_021C0F14, func_021C1154, func_021C1174, func_021C11B8, func_021C124C, func_021C12F8, func_021C132C, func_021C133C, func_021C1440, func_021C1450, func_021C1484, func_021C14E0, func_021C154C, func_021C15B4, func_021C1610, func_021C16B0, func_021C1704, func_021C1718, func_021C1724, func_021C1738, func_021C1798, func_021C17D0, func_021C17D4, func_021C17DC, func_021C181C, func_021C1838, func_021C1840
 * address:  0x021C025C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02031330 0x02031330 arm
 *   func_02024910 0x02024910 thumb
 *   func_02024464 0x02024464 thumb
 *   func_021C0250 0x021C0250 thumb ov110
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021C022C 0x021C022C thumb ov110
 *   func_02034A5C 0x02034A5C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   ov067_id 0x00000043 data a1
 *   func_020355C4 0x020355C4 arm
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02027F60 0x02027F60 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021B6284 0x021B6284 thumb ov067
 *   func_020355D8 0x020355D8 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_020413B0 0x020413B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02049238 0x02049238 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020410D0 0x020410D0 arm
 *   tbl_020A1B38 0x020A1B38 data
 *   data_021C39E0 0x021C39E0 data a4
 *   func_021B62E0 0x021B62E0 thumb ov067
 *   func_021B6588 0x021B6588 thumb ov067
 *   data_021C39F8 0x021C39F8 data a4
 *   func_021B639C  0x021B639C  thumb  ov067
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_02027778 0x02027778 thumb
 *   d_021C3C94 0x021C3C94 data ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202DC08 0x0202DC08 thumb
 *   func_0202DBC4 0x0202DBC4 thumb
 *   func_0202DC98 0x0202DC98 thumb
 *   func_02041570 0x02041570 arm
 *   func_0202452C 0x0202452C thumb
 *   sub_0202DCC4 0x0202DCC4 thumb
 *   func_0202DC9C 0x0202DC9C thumb
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B560 0x0204B560 arm
 *   func_0204B550 0x0204B550 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202DE64 0x0202DE64 thumb
 *   func_0202DE5C 0x0202DE5C thumb
 *   func_0202DC48 0x0202DC48 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B64D0 0x021B64D0 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_02023F60 0x02023F60 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02024044 0x02024044 thumb
 *   func_02024108 0x02024108 thumb
 *   func_02031348 0x02031348 arm
 *   d_021C39B8 0x021C39B8 data a4
 *   func_02024120 0x02024120 thumb
 *   func_02024134 0x02024134 thumb
 *   func_02024918 0x02024918 thumb
 *   func_020240FC 0x020240FC thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021C3C98 0x021C3C98 data a1
 *   d_021C3A44 0x021C3A44 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021C1848  0x021C1848  thumb  ov110
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021C3A18 0x021C3A18 data a4
 *   d_021C3A74 0x021C3A74 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4  0x020419E4  arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021C3A28 0x021C3A28 data a4
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A648 0x0204A648 arm
 */
#include "../../matched/include/Obj00435.h"
#include "../../matched/include/Obj06395.h"
#include "../../matched/include/Obj02466.h"
#include "../../matched/include/Obj08011.h"
#include "../../matched/include/Obj05299.h"
#include "../../matched/include/Obj22407.h"
#include "../../matched/include/Obj22408.h"
#include "../../matched/include/Obj22409.h"
#include "../../matched/include/Obj22410.h"
#include "../../matched/include/Obj05300.h"
#include "../../matched/include/Obj10284.h"
#include "../../matched/include/Obj05301.h"
#include "../../matched/include/Obj00217.h"
#include "../../matched/include/Obj10286.h"
#include "../../matched/include/Obj22412.h"
#include "../../matched/include/Obj22413.h"
#include "../../matched/include/Obj06396.h"
#include "../../matched/include/Obj03244.h"
#include "../../matched/include/Obj22414.h"
#include "../../matched/include/Obj22415.h"

struct Cfg;
struct Descriptor;
struct PrintSys;
struct T;
struct Obj;
struct R;
struct TaskMenuState;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct Rec;
struct S;
struct TaskMenu;
struct TaskMenuTmpl;
struct PmsDraw;
struct Obj0202DC98;
struct Obj0202DCC4;
struct Actor;
struct Obj02024838;
struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 pad[0x99]; u8 flag:1,rest:7; } Bits;

typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;

struct Rec { u16 x, y, c, d; };

typedef signed char s8;

typedef struct { unsigned v[8]; } Table;

typedef struct { Table *table; unsigned count; void *p; unsigned mode,a,b,c,d; } Descriptor;

typedef struct Entry { void *str; u16 flag; u16 pad; u32 term; } Entry;

typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x, y, z, w; } Config;

typedef struct { u8 lo:1; u8 hi:7; } Flags;

typedef struct { u8 bit:1; u8 rest:7; } Flag;

typedef struct {u32 id; u32 bg[8]; u32 pal; u32 value;} Row;

typedef short s16;

typedef int s32;

extern u32 func_02031330(void *);
extern void *func_02024910(char *p, int idx);
extern int func_02024464(struct T *p, u32 a1);
extern void func_021C0250(int *,u8 *,int);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern int func_021C022C(u8 *);
extern void func_02034A5C(int handle);
extern int func_02034AC4(int handle);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u8 func_020355C4(void);
extern void func_021B6208(void *,In *,int,u16);
extern int func_021B629C(void *,int,u16,u16,u8,u16);
extern void func_0204B84C(void *,u32);
extern void func_0204B92C(struct Obj *p, u32 v);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0203D34C(u32,u32);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_021B6284(unsigned int *);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_020355D8(u8);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern int func_02061CA4(void *,u32,u32,int);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *func_02049EF4(void *,u32,u32,void **,u16);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02049238(void *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020307B0(void *p);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void *func_021B62E0(Descriptor *,int);
extern void func_021B6588(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021B639C(u8 *p);
extern void func_021B63D0(struct S *p);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027858(struct TaskMenu *m);
extern void func_02027974(void);
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0202DC08(struct Obj *p);
extern void func_0202DBC4(u8 *p);
extern u32 func_0202DC98(struct Obj0202DC98 *o);
extern void func_02041570(int,u16);
extern int func_0202452C(const u16 *p);
extern u32 sub_0202DCC4(const struct Obj0202DCC4 *p, u32 i);
extern void func_0202DC9C(struct Obj0202DC98 *o, int i, u32 a1);
extern u32 func_0204B3F4(struct Obj *p);
extern short func_0204B560(const struct Actor *actor, u32 axis);
extern void func_0204B550(struct Actor *actor, signed short value, u32 axis);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020061E4(u32);
extern void func_0202DE64(struct PmsDraw *p, u16 v);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern void func_0202DC48(u32 a, u32 b, u32 c, u32 d);
extern void func_021B64D0(u8 *,u32);
extern int func_021B6470(u8 *);
extern int func_021B6448(u8 *);
extern void func_02023F60(u32,u32,u32);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void func_02024108(u16 *dst, const u16 *src);
extern void func_02031348(void *, int, void *, void *);
extern int func_02024120(u8 *p);
extern void func_02024134(char *a, void *b);
extern void func_02024918(const struct Obj02024838 *p, int idx, void *dest);
extern void func_020240FC(void *);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,unsigned);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void *,void *,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern u32 func_021C1848(u32 *p);
extern void func_0203F8F4(u16);
extern void func_02045088(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(unsigned, unsigned);
extern void func_02043598(unsigned, unsigned);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
int func_021C025C(void *unused,int *q,void *unused2,u8 *p);
void func_021C0490(u8 *p);
void func_021C05B0(char *p);
void func_021C060C(u8 *p,u16 heap,u32 font,void *print,void *bank);
void func_021C07E8(u8 *p);
void func_021C080C(char *p, u8 idx, u32 pal, int flag);
void func_021C088C(u16 *ang, u16 *out, struct Rec *recs, u8 count);
void func_021C098C(char *p);
void func_021C09E0(u8 *p);
void func_021C09E8(char *p, int pal);
void *func_021C0A54(int unused,void *p,int heap);
void func_021C0AB4(u8 *p);
void func_021C0AC0(void *a0);
int func_021C0AC8(void *parent, void *bank, u16 size);
void func_021C0B44(struct TaskMenu *m);
void func_021C0B4C(void *a0);
void func_021C0B54(char *p);
void func_021C0C18(u8 *p);
void func_021C0C38(u8 *p);
void func_021C0C44(void *p);
void func_021C0C50(u8 *p);
void func_021C0C64(u8 *p,int flag);
void func_021C0D34(char *p,int force);
int func_021C0DE4(char *p);
void func_021C0E3C(unsigned y,int count,short *out,short *pos);
int func_021C0EB0(char *p);
int func_021C0F14(u8 *p);
void func_021C1154(char *p);
int func_021C1174(unsigned owner, void *p, int *state);
void func_021C11B8(u8 *p,u8 index,int unused,int flag);
void func_021C124C(u8 *p,u8 index,u8 which,int flag);
int func_021C12F8(void);
int func_021C132C(void *unused,u8 *p);
int func_021C133C(void *unused,u8 *p);
int func_021C1440(void *a, u8 *p);
int func_021C1450(void *a, u8 *p);
int func_021C1484(void *arg, u8 *p);
int func_021C14E0(void *arg, u8 *p);
int func_021C154C(int *state, u8 *p);
int func_021C15B4(int *state, u8 *p);
void *func_021C1610(unsigned arg, u16 heap);
void func_021C16B0(u8 *p);
void func_021C1704(u8 *p);
u32 func_021C1718(u8 *p);
void func_021C1724(int a,u8 *p);
void func_021C1738(void *p, u16 heap);
void func_021C1798(void *p);
void func_021C17D0(void *a0);
void func_021C17D4(void *a0);
void func_021C17DC(void **p, unsigned arg, unsigned heap);
void func_021C181C(void **p);
void func_021C1838(void *a0);
void func_021C1840(void *a0);
extern char ov067_id[];
extern short tbl_020A1B38[];
extern unsigned short data_021C39E0[];
extern const Table data_021C39F8;
extern const u8 d_021C3C94[];
extern const unsigned d_021C39B8[];
extern const char d_021C3C98[];
extern const unsigned d_021C3A44[];
extern const unsigned d_021C3A18[];
extern const Row d_021C3A74[];
extern const unsigned d_021C3A28[];


/*
 * ABI: 02031330 tail-forwards the full-word result and object argument of matched 020313EC.
 */
int func_021C025C(void *unused,int *q,void *unused2,u8 *p)
{
    u32 running;
    void *window;
    running=func_02031330(*(void **)(p+0xac));
    if(running==1) return 0;
    switch(*q) {
    case 0:
        if(!func_02024464(func_02024910(*(void **)(p+0x20),0),*(u16 *)(p+4))) {
            p[0x95]=0;
            func_021C0250(q,p,13);
        } else func_021C0250(q,p,1);
        break;
    case 1:
        if(func_021C132C(p+0x9c,p)) func_021C0250(q,p,2);
        break;
    case 2:
        func_0204E720(3,16,0,0);
        func_021C0250(q,p,3);
        break;
    case 3:
        if(!func_0204E804()) func_021C0250(q,p,4);
        break;
    case 4:
        if(func_021C022C(p) && func_021C133C(p+0x9c,p))
            func_021C0250(q,p,*(int *)(p+0xa0));
        break;
    case 5:
        func_0204E720(3,0,16,0);
        func_021C0250(q,p,6);
        break;
    case 6:
        if(!func_0204E804()) func_021C0250(q,p,7);
        break;
    case 7:
        if(func_021C1440(p+0x9c,p)) func_021C0250(q,p,16);
        break;
    case 8:
        if(func_021C1450(p+0x9c,p)) func_021C0250(q,p,9);
        break;
    case 9:
        if(func_021C1484(p+0x9c,p)) func_021C0250(q,p,10);
        break;
    case 10:
        if(func_021C14E0(p+0x9c,p)) func_021C0250(q,p,*(int *)(p+0xa0));
        break;
    case 11:
        if(func_021C022C(p)) {
            func_0204E720(3,0,16,0);
            func_021C0250(q,p,12);
        }
        break;
    case 12:
        if(!func_0204E804()) func_021C0250(q,p,13);
        break;
    case 13:
        func_021C05B0((char *)p);
        func_02034A5C((int)ov067_id);
        func_021C0250(q,p,14);
        return 0;
    case 14:
        if(func_021C154C((int *)(p+0x9c),p)) func_021C0250(q,p,15);
        return 0;
    case 15:
        if(running!=1 && func_021C15B4((int *)(p+0x9c),p)) {
            func_02034AC4((u32)ov067_id);
            func_021C0490(p);
            func_021C0250(q,p,1);
        }
        return 0;
    case 16:
        return 1;
    }
    func_0201C4E4(*(void **)(p+0x5c));
    if(*(u32 *)(p+0x4c)) {
        if(!func_0201C6C4((struct PrintSys *)(*(u32 *)(p+0x5c)),func_02045770(*(void **)(p+0x48)))) {
            window=*(void **)(p+0x48);
            func_02045334(window);
            func_02045374(window);
            func_02041B6C(func_02045730(window));
            *(u32 *)(p+0x4c)=0;
        }
    }
    func_021C1154((char *)p);
    func_021C0C38(p);
    func_021C1704(*(void **)(p+0x50));
    return 0;
}


/*
 * lever: test source byte +95 after copying to +94; bitfield clear and ordered In stores.
 * prototype: 021C1718 tail-forwards to the returned first-word accessor 021C1848.
 */
void func_021C0490(u8 *p)
{
    int enabled;
    u32 resource;
    In in;
    ((Bits *)p)->flag=0;
    ((struct Obj00435 *)p)->fA4=1;
    enabled=1;
    if(func_020355C4()!=1) enabled=0;
    ((struct Obj00435 *)p)->fA8=enabled;
    p[0x94]=p[0x95];
    if(p[0x95]==255) {
        if(enabled) p[0x96]=0;
        else { p[0x95]=0; p[0x96]=0; }
    } else {
        if(enabled) p[0x95]=255;
    }
    ((struct Obj00435 *)p)->f50=func_021C1610(0,((struct Obj00435 *)p)->f4);
    resource=func_021C1718(*(u8 * *)&((struct Obj00435 *)p)->f50);
    in.f8=43; in.fC=7; in.f10=13; in.f14=35; in.f18=41;
    in.f0=0; in.f4=0;
    in.b1c=0; in.b1d=0; in.b1e=5;
    func_021B6208(p+12,&in,resource,((struct Obj00435 *)p)->f4);
    *(int *)&((struct Obj00435 *)p)->f8=func_021B629C(p+12,resource,240,16,16,((struct Obj00435 *)p)->f4);
    func_0204B84C(((struct Obj00435 *)p)->f8,1);
    func_0204B92C(((struct Obj00435 *)p)->f8,1);
    func_021C060C(p+0x24,((struct Obj00435 *)p)->f4,(u32)(((struct Obj00435 *)p)->f58),((struct Obj00435 *)p)->f5C,((struct Obj00435 *)p)->f60);
    func_021C09E0(p+0x24);
    p[0x44]=0;
    ((struct Obj00435 *)p)->f40=0;
    ((struct Obj00435 *)p)->f54=func_021C0A54((int)p,(void *)func_021C1718(*(u8 * *)&((struct Obj00435 *)p)->f50),((struct Obj00435 *)p)->f4);
    ((struct Obj00435 *)p)->f64=func_02027F60(0,12,*(u32 *)&((struct Obj00435 *)p)->f58,*(u32 *)&((struct Obj00435 *)p)->f5C,((struct Obj00435 *)p)->f4);
    func_021C0B54((char *)p);
    func_0203D34C(1,((struct Obj00435 *)p)->f4);
}


static inline u8 Clear(char *p, u8 i) {
    u8 zero;
    zero = i;
    for (; i < 4; i++) *(int *)(p + 0x7c + i * 4) = zero;
    return zero;
}


void func_021C05B0(char *p) {
    u8 z;
    func_0201C6EC(((struct Obj06395 *)p)->f5C);
    z=Clear(p, 0);
    ((struct Obj06395 *)p)->f4C=z;
    func_021B6284((unsigned int *)(p+0xc));
    func_021C0AB4((u8 *)p);
    func_02027FD8(((struct Obj06395 *)p)->f64);
    func_021C0C18((u8 *)p);
    func_021C07E8((u8 *)(p+0x24));
    func_021C16B0(((struct Obj06395 *)p)->f50);
    if (((struct Obj06395 *)p)->fA8) z=1;
    func_020355D8(z);
}


/*
 * Own callee bodies fix arity and full word payloads; caller0490 loads heap
 *   with ldrh. The original narrows only 49990's fifth argument to u16.
 * No local arrays; p+14/+16/+18/+1a halfwords initialized before queued
 *   two-byte reads. Callback/context pointers retain their full32 bits.
 * First one EXACT476; final text freshly verified after literal move.
 */
void func_021C060C(u8 *p,u16 heap,u32 font,void *print,void *bank)
{
    void *h;
    void *str;
    h=func_020490F4((unsigned int)43,heap);
    func_02049B68((void *)((u32)h),0,0,0,288,heap);
    func_02049B68((void *)((u32)h),0,4,0,256,heap);
    func_02049B40(23,5,0,288,32,heap);
    ((struct Obj02466 *)p)->f14=0x7fff;
    func_02061CA4((void *)15,316,(u32)(p+0x14),2);
    ((struct Obj02466 *)p)->f16=0x7fff;
    func_02061CA4((void *)15,314,(u32)(p+0x16),2);
    func_02049658((void *)((u32)h),10,4,0,0,0,heap);
    func_020498F4((void *)((u32)h),21,4,0,0,0,heap);
    ((struct Obj02466 *)p)->f0=func_02049740((void *)((u32)h),10,3,0,0,heap);
    func_02049990((void *)((u32)h),22,3,0,(u16)(((struct Obj02466 *)p)->f0),0,0,heap);
    func_02049658((void *)((u32)h),11,2,0,0,0,heap);
    ((struct Obj02466 *)p)->f4=func_02049EF4(h,23,0,(void **)(p+8),heap);
    func_02049BDC((void *)((u32)h),4,4,128,256,32,heap);
    ((struct Obj02466 *)p)->f18=0x294b;
    func_02061CA4((void *)31,284,(u32)(p+0x18),2);
    ((struct Obj02466 *)p)->f1A=0x5694;
    func_02061CA4((void *)31,286,(u32)(p+0x1a),2);
    func_02049658((void *)((u32)h),18,5,0,0,0,heap);
    func_020498F4((void *)((u32)h),24,5,0,0,0,heap);
    func_020413B0(5,0,0,32,32,8);
    *(u32 *)&((struct Obj02466 *)p)->f24=func_020450F0(5,3,5,26,7,8,1);
    func_02043B5C(func_02045770(((struct Obj02466 *)p)->f24),7);
    str=func_02045EC0(bank,21);
    func_0201C724(print,(u32)func_02045770(((struct Obj02466 *)p)->f24),2,4,(u32)str,font,0x39e7);
    ((struct Obj02466 *)p)->f28=1;
    func_02045808(str);
    func_02049238(h);
}


void func_021C07E8(u8 *p) { func_020452E8(((struct Obj08011 *)p)->f24); func_0203FB44(3,(u16)(((struct Obj08011 *)p)->f0),(u16)(((struct Obj08011 *)p)->f0>>16)); func_020307B0(((struct Obj08011 *)p)->f4); }


void func_021C080C(char *p, u8 idx, u32 pal, int flag)
{
    int i;
    int n;
    u16 *hdr = *(u16 **)(p + 8);
    u16 *data;
    u32 w;
    u32 h;
    w = (u32)hdr[0] >> 3;
    h = (u32)hdr[1] >> 3;
    data = hdr + 6;
    if (flag)
        pal = 5;
    n = w * h;
    for (i = 0; i < n; i++)
    {
        u32 v = data[i] & 0xFFF;
        data[i] = v + ((pal + 2) << 12);
    }
    func_020410D0(2, 0, (u8)(idx * 6 + 1), (u8)w, 6, (u32)(*(u8 **)(p + 8) + 12), 0, 0, (u8)w, (u8)h);
    func_02041B6C(2);
}


static inline void lerp(u16 *p, int n, u16 a, u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n>>12;
 dr=((u8)(b&31)-r)*n>>12;
 dg=((u8)((b&0x3E0)>>5)-g)*n>>12;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
}


/*
 * lever: the RGB555 lerp is a static inline helper (u16 colour params, as ov105 func_021B8734)
 */
void func_021C088C(u16 *ang, u16 *out, struct Rec *recs, u8 count)
{
    u8 i;
    short t;
    int a = *ang;
    if (a + 0x400 >= 0x10000)
        *ang = a - 0xFC00;
    else
        *ang = a + 0x400;
    t = (tbl_020A1B38[(*ang >> 4) * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < count; i++) {
        lerp(&out[i], t, recs[i].c, recs[i].d);
        func_02061CA4((void *)15, (recs[i].x << 5) + (recs[i].y << 1), (u32)(&out[i]), 2);
    }
}


void func_021C098C(char *p) {
    int v;
    if (((struct Obj05299 *)p)->f1C) {
        v=1;
        if (((struct Obj05299 *)p)->f20<16) {
            v=(((struct Obj05299 *)p)->f20/4)%2;
            (((struct Obj05299 *)p)->f20)++;
        }
        if(v) ((struct Obj05299 *)p)->fC=0xfc00;
        else ((struct Obj05299 *)p)->fC=0x7c00;
    }
    func_021C088C((u16 *)(p+0xc),(u16 *)(p+0xe),(struct Rec *)data_021C39E0,3);
}



void func_021C09E0(u8 *p) { ((struct Obj22407 *)p)->fC = 0; }


void func_021C09E8(char *p, int pal)
{
    int i = 0;
    u16 *hdr = *(u16 **)(p + 8);
    u32 w = (u32)hdr[0] >> 3;
    u32 h = (u32)hdr[1] >> 3;
    u16 *data = hdr + 6;
    int n = w * h;
    for (; i < n; i++)
    {
        u32 v = data[i] & 0xFFF;
        data[i] = v + ((pal + 2) << 12);
    }
    func_020410D0(2, 0, 0, (u8)w, 1, (u32)(*(u8 **)(p + 8) + 12), 0, 5, (u8)w, (u8)h);
    func_02041B6C(2);
}


void *func_021C0A54(int unused,void *p,int heap) {
    Descriptor desc={0};
    Table table=data_021C39F8;
    void *out;
    desc.count=1;
    desc.mode=1;
    desc.a=14;
    desc.b=5;
    desc.c=1;
    desc.table=&table;
    desc.p=p;
    out=func_021B62E0(&desc,heap);
    func_021B6588(out,1,1);
    return out;
}


/*
 * Resolved by the func_021B639C label in ov067 (thumb); cross-overlay target.
 */
void func_021C0AB4(u8 *p) { func_021B639C((u8 *)(((struct Obj22408 *)p)->f54)); }


void func_021C0AC0(void *a0) { func_021B63D0(a0); }


/*
 * note: 2026-10-05 (wD9r lane27): closed by the u16 type of the size parameter (stored to the u32
 *   Config.size). The u32 parameter let the scheduler hoist the size reload above the e[2].term store.
 */
int func_021C0AC8(void *parent, void *bank, u16 size)
{
    Config c;
    Entry e[3];
    u32 i;
    int r;
    for (i = 0; i < 3; i++) {
        e[i].str = func_02045EC0(bank, d_021C3C94[i]);
        e[i].flag = 0x39E3;
        e[i].term = 0;
    }
    e[2].term = 1;
    c.size = size;
    c.flag = 3;
    c.target = e;
    c.mode = 1;
    c.x = 0x20;
    c.y = 0x18;
    c.z = 13;
    c.w = 3;
    r = (int)func_02027778((struct TaskMenuTmpl *)(&c), parent);
    for (i = 0; i < 3; i++)
        func_02045808(e[i].str);
    return r;
}


void func_021C0B44(struct TaskMenu *m) { func_02027858(m); }


void func_021C0B4C(void *a0) { func_02027974(); }


/*
 *   void *func_02024910(char *p,int i) { return p+8+i*8; }
 */
void func_021C0B54(char *p) {
    int i;
    unsigned v;
    *(void **)(p+0x8c)=func_0202DB0C((u32)func_021C1718(*(void **)(p+0x50)),(int)0,(u32)(*(void **)(p+0x5c)),(u32)(*(void **)(p+0x58)),(int)8,(int)4,*(u16 *)(p+4));
    *(u8 *)(p+0x97)=0;
    for(i=0;i<20;i++) {
        if(!func_02024464(func_02024910(*(void **)(p+0x20),i),(u16)(*(u16 *)(p+4)))) break;
        (*(u8 *)(p+0x97))++;
    }
    v=*(u8 *)(p+0x97);
    *(u8 *)(p+0x98)=v;
    if(v<20) (*(u8 *)(p+0x98))++;
    func_0204B3DC(*(void **)(p+8),(int)(*(u8 *)(p+0x98)>3));
    for(i=0;i<4;i++) *(void **)(p+0x6c+i*4)=(void *)func_020450F0((int)2,(int)2,(u8)(i*6+2),(int)25,(int)4,(int)9,(int)1);
    func_021C0C44(p);
    func_021C0D34(p,1);
}


void func_021C0C18(u8 *p) { int i; func_0202DC08(((struct Obj22409 *)p)->f8C); for(i=0;i<4;i++) func_020452E8(*(void **)(p+0x6c+i*4)); }


void func_021C0C38(u8 *p) { func_0202DBC4(((struct Obj22410 *)p)->f8C); }


void func_021C0C44(void *p) { func_021C0C64(p, 0); }


void func_021C0C50(u8 *p) { func_021C0C64(p,1); func_021C09E0(p+0x24); }


/*
 *   primary body reads r0/r1, no memory; fixed-flag scratch EXACT8,
 *   blocker-24910-two.log terminal0, no ARM9 source/shard filed.
 *   void *func_02024910(char *p,unsigned i) { return p+8+i*8; }
 * Caller explicitly narrows the outgoing index to u8. Own ARM9 units and
 *   complete overlay callee bodies fix arity; observed caller truncations
 *   fix the u8 index externs. Both bounded row loops retain indices0..3.
 * A named u8 which before the comparison/call removes duplicate narrowing
 *   (DIFF84/212 -> MATCH208); no volatile or uninitialized local.
 * Caller-only tu --suggest-split: MATCH208, no viable partition.
 */
void func_021C0C64(u8 *p,int flag)
{
    int i;
    if(flag && !func_0202DC98(*(void **)(p+0x8c))) return;
    func_02041570(2,0);
    if(p[0x96]) {
        func_021C09E8((char *)(p+0x24),func_0202452C(func_02024910(*(void **)(p+0x20),(u8)(p[0x96]-1))));
    }
    for(i=0;i<4;i++) {
        if(sub_0202DCC4(*(void **)(p+0x8c),(u8)i)) func_0202DC9C(*(void **)(p+0x8c),(u8)i,0);
    }
    for(i=0;p[0x96]+i<p[0x97] && i<4;i++) {
        u8 which;
        which=p[0x96]+i;
        func_021C124C(p,(u8)i,which,which==p[0x95]);
    }
    if(p[0x97]<20 && i<4) {
        u8 which;
        which=p[0x96]+i;
        func_021C11B8(p,(u8)i,0,which==p[0x95]);
    }
}


/*
 * note: Two zero padding bytes follow at 0x021C0DE2.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`a=t;` before `a=t+16;`). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT* in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021C0D34(char *p,int force) {
    int n,index,y,a,b,t;
    short pos;
    if(!func_0204B3F4(((struct Obj05300 *)p)->f8)) return;
    n=((struct Obj05300 *)p)->f98-2;
    index=((struct Obj05300 *)p)->f96;
    if(!force) {
        y=func_0204B560(((struct Obj05300 *)p)->f8,1);
        t=137*index/n;
        a=t+16;
        b=137*(index+1)/n+16;
        if(index==0) { if(y<b) return; }
        else if(index==n-1) { if(y>=a) return; }
        else { if(a<=y && y<b) return; }
    }
    if(index==0) pos=16;
    else if(index==n-1) pos=152;
    else {
        t=137*(((struct Obj05300 *)p)->f96)/n;
        pos=t+16+137/(n*2);
        if(pos>152) pos=152;
    }
    func_0204B550(((struct Obj05300 *)p)->f8,pos,1);
}


int func_021C0DE4(char *p) {
    unsigned x,y;
    if(!func_0204B3F4(((struct Obj10284 *)p)->f8)) return 0;
    if(!func_02035D20(&x,&y)) return 0;
    if(x>=240 && x<=247 && y<=159 && y>=8) {
        ((struct Obj10284 *)p)->f99=(((struct Obj10284 *)p)->f99&~1)|1;
        return 1;
    }
    return 0;
}


void func_021C0E3C(unsigned y,int count,short *out,short *pos) {
    int n,i,a,b;
    n=count-2;
    for(i=0;i<n;i++) {
        a=137*i/n+16;
        b=(137*i+137)/n+16;
        if(i==0) { if(y<b) { *out=i; break; } }
        else if(i==n-1) { if(y>=a) { *out=i; break; } }
        else { if(a<=y && y<b) { *out=i; break; } }
    }
    if(y>152) y=152;
    else if(y<16) y=16;
    *pos=y;
}


int func_021C0EB0(char *p) {
    unsigned x,y;
    unsigned short index;
    short pos;
    if(!func_02035CB8(&x,&y)) {
        ((struct Obj05301 *)p)->f99=(((struct Obj05301 *)p)->f99&~1);
        return 0;
    }
    func_021C0E3C(y,((struct Obj05301 *)p)->f98,(short int *)(&index),&pos);
    func_0204B550(((struct Obj05301 *)p)->f8,pos,1);
    if((unsigned short)index!=((struct Obj05301 *)p)->f96) {
        ((struct Obj05301 *)p)->f96=index;
        return 1;
    }
    return 0;
}




/*
 * lever: Byte +99 is a one-bit field; selection bytes retain 255 and the signed touch result retains -1.
 */
int func_021C0F14(u8 *p)
{
    int result=0;
    int proceed=1;
    int active;
    int hit;
    if(!((Flags *)(p+0x99))->lo) {
        active=0;
        if(func_020362DC()&~2) active=1;
        if(active && p[0x95]==255) {
            if(p[0x94]==255) p[0x95]=p[0x96];
            else if(p[0x96]<=p[0x94] && p[0x94]<p[0x96]+3) p[0x95]=p[0x94];
            else p[0x95]=p[0x96];
            p[0x94]=255;
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
            func_020061E4(1352);
            func_021C0C50(p);
        }
    }
    if(proceed && p[0x95]!=255 && !((Flags *)(p+0x99))->lo) {
        if(func_020362DC()&1) {
            result=1;
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        } else if(func_0203633C()&64) {
            if(p[0x95]!=0) {
                p[0x94]=p[0x95];
                p[0x95]--;
                if(p[0x95]+1==p[0x96]) p[0x96]--;
                func_021C0D34((char *)p,0);
                func_021C0C50(p);
                func_020061E4(1352);
            }
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        } else if(func_0203633C()&128) {
            if(p[0x95]<p[0x98]-1) {
                p[0x94]=p[0x95];
                p[0x95]++;
                if(p[0x95]==p[0x96]+3) p[0x96]++;
                func_021C0D34((char *)p,0);
                func_021C0C50(p);
                func_020061E4(1352);
            }
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        }
    }
    if(proceed) {
        if(((Flags *)(p+0x99))->lo) {
            if(func_021C0EB0((char *)p)) {
                func_021C0C50(p);
                func_020061E4(1352);
            }
            ((struct Obj00217 *)p)->fA8=1;
        } else {
            hit=func_021C12F8();
            if(hit!=-1 && hit>p[0x98]-1) hit=-1;
            if(hit!=-1) {
                p[0x94]=p[0x95];
                p[0x95]=p[0x96]+hit;
                func_021C0C50(p);
                result=1;
                ((struct Obj00217 *)p)->fA8=1;
            } else {
                if(!((Flags *)(p+0x99))->lo) func_021C0DE4((char *)p);
                if(((Flags *)(p+0x99))->lo==1) {
                    if(func_021C0EB0((char *)p) || p[0x95]!=255) {
                        p[0x94]=p[0x95];
                        p[0x95]=255;
                        func_021C0C50(p);
                    }
                    func_020061E4(1352);
                    ((struct Obj00217 *)p)->fA8=1;
                }
            }
        }
    }
    return result;
}




void func_021C1154(char *p)
{
    int i;
    for (i=0; i<4; i++)
        func_021C1174(*(unsigned *)(p+0x5c), *(void **)(p+i*4+0x6c), (int *)(p+0x7c+i*4));
}




/*
 * Extent ends with two bytes of zero padding at 0x021C11B6.
 */
int func_021C1174(unsigned owner, void *p, int *state) {
    unsigned q = (unsigned)func_02045770(p);
    if (*state == 1 && func_0201C6C4((struct PrintSys *)owner, (void *)q) == 0) {
        func_02045334(p);
        func_02045374(p);
        func_02041B6C(func_02045730(p));
        *state = 0;
        return 1;
    }
    return 0;
}




void func_021C11B8(u8 *p,u8 index,int unused,int flag) {
    void *str;
    u16 color;
    str=func_02045EC0(((struct Obj10286 *)p)->f60,17);
    func_021C080C((char *)(p+0x24), index, 6, flag);
    if (flag) {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),14);
        color=0x44e;
    } else {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),13);
        color=0x44d;
    }
    func_0201C724(((struct Obj10286 *)p)->f5C,(u32)func_02045770(*(void **)(p+0x6c+index*4)),0,0,(u32)str,((struct Obj10286 *)p)->f58,color);
    func_02045808(str);
    func_02045374(*(void **)(p+0x6c+index*4));
    func_02041B6C(func_02045730(*(void **)(p+0x6c+index*4)));
    *(int *)(p+0x7c+index*4)=1;
}




void func_021C124C(u8 *p,u8 index,u8 which,int flag) {
    void *item;
    item=func_02024910(*(void **)(p+0x20),which);
    func_021C080C((char *)(p+0x24), index, func_0202452C(item), flag);
    if (flag) {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),14);
        func_0202DE64(*(void **)(p+0x8c),0x44e);
        func_0202DE5C(*(void **)(p+0x8c),14);
    } else {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),13);
        func_0202DE64(*(void **)(p+0x8c),0x44d);
        func_0202DE5C(*(void **)(p+0x8c),13);
    }
    if (func_02024464(item,*(u16 *)(p+4))==1) {
        func_0202DC48((u32)(*(void **)(p+0x8c)),(u32)(*(void **)(p+0x6c+index*4)),(u32)item,index);
        *(int *)(p+0x7c+index*4)=1;
    }
}




int func_021C12F8(void) { u32 x,y; u32 result; if(func_02035D20(&x,&y) && x<232 && y>=8) { result=(y/8-1)/6; if(result<3) return result; } return -1; }




int func_021C132C(void *unused,u8 *p) { func_021B64D0(*(u8 * *)&((struct Obj22412 *)p)->f54,1); return 1; }




/*
 * outside 0x021C133C..0x021C1440; all concrete bytes match, 9/10
 * relocations resolved. Owner-only leaf; no blocker C filed or embedded.
 * Lever: one-bit field at +0x99 gives the original shift pair. Calls in
 * both Boolean arms preserve 355D8's u8 ABI without ternary truncation.
 * Empty switch cases -1 and 7 preserve the original unused comparisons.
 * The original explicitly supplies r0 to the otherwise argument-free
 * 021C0AC0 forwarder; its unused input is retained at this caller.
 */
int func_021C133C(void *unused,u8 *p)
{
    int result=-1;
    int done=0;
    int input;
    func_021C098C((char *)p+0x24);
    if(!*(int *)(p+0x40)) {
        input=0;
        if(!((Flag *)(p+0x99))->bit) {
            if(*(int *)(p+0xa8)) func_020355D8(1);
            else func_020355D8(0);
            func_021C0AC0(*(void **)(p+0x54));
            if(func_021B6470(*(u8 **)(p+0x54))!=-1) *(int *)(p+0xa4)=0;
            result=func_021B6448(*(u8 **)(p+0x54));
            if(result!=-1) *(int *)(p+0xa4)=1;
            *(int *)(p+0xa8)=func_020355C4()==1;
        }
        switch(result) {
        case -1: break;
        case 1:
            *(int *)(*(u8 **)p+4)=1;
            *(int *)(*(u8 **)p+8)=0;
            *(int *)(p+0xa0)=5;
            return 1;
        case 7: break;
        }
        if(*(int *)(p+0xa4)) input=func_021C0F14(p);
        if(input) {
            func_020061E4(1356);
            *(int *)(p+0x40)=1;
        }
    } else {
        if(p[0x44]==16) done=1;
    }
    if(done) {
        if(func_02024464(func_02024910(*(void **)(p+0x20),p[0x95]),*(u16 *)(p+4))) *(int *)(p+0xa0)=8;
        else *(int *)(p+0xa0)=11;
        return 1;
    }
    return 0;
}




int func_021C1440(void *a, u8 *p) { func_021B64D0(*(u8 * *)&((struct Obj22413 *)p)->f54,0); return 1; }




int func_021C1450(void *a, u8 *p) { if(((struct Obj06396 *)p)->fA8) func_020355D8(1); else func_020355D8(0); ((struct Obj06396 *)p)->f68=(void *)func_021C0AC8((void *)(((struct Obj06396 *)p)->f64),(void *)(((struct Obj06396 *)p)->f60),((struct Obj06396 *)p)->f4); func_02023F60(-8,30,1); return 1; }




/*
 * Blocked on ARM9 0x02024910 (no outside witness); two-byte zero padding follows.
 *   typedef unsigned char u8;
 *   void *func_02024910(u8 *p,int i) { return p+8+i*8; }
 */
int func_021C1484(void *arg, u8 *p) {
    func_021C0B4C(*(void **)(p+0x68));
    if (func_020279E8(*(void **)(p+0x68))) {
        switch (func_02027A04(*(void **)(p+0x68))) {
        case 0:
            *(int *)(p+0xa0)=5;
            *(unsigned *)(*(u8 **)p+8)=(unsigned int)func_02024910(*(void **)(p+0x20),p[0x95]);
            *(unsigned *)(*(u8 **)p+4)=0;
            break;
        case 1: *(int *)(p+0xa0)=11; break;
        case 2: *(int *)(p+0xa0)=4; break;
        }
        return 1;
    }
    return 0;
}




int func_021C14E0(void *arg, u8 *p) {
    func_021C0B44(((struct Obj03244 *)p)->f68);
    ((struct Obj03244 *)p)->fA8 = func_020355C4()==1;
    if (((struct Obj03244 *)p)->fA0==4) {
        func_02023F60(0,30,1);
        func_021C09E0(p+0x24);
        p[0x44]=0;
        ((struct Obj03244 *)p)->f40=0;
        if (((struct Obj03244 *)p)->fA8!=0) {
            p[0x94]=p[0x95];
            p[0x95]=255;
            func_021C0C50(p);
        }
    }
    return 1;
}




/*
 * Blocked on ARM9 leaves 0x02024910 and 0x02024108, no outside witnesses.
 *   typedef unsigned char u8;
 *   void *func_02024910(u8 *p,int i) { return p+8+i*8; }
 *   typedef unsigned char u8; typedef unsigned short u16;
 *   void func_02024108(u8 *p,const u16 *s) {
 *     *(u16 *)(p+16)=s[0]; *(u16 *)(p+18)=s[1];
 *     *(u16 *)(p+20)=s[2]; *(u16 *)(p+22)=s[3];
 *   }
 */
int func_021C154C(int *state, u8 *p) {
    void *q;
    switch (*state) {
    case 0: ++*state; break;
    case 1:
        q=func_02024044(2,0,0,1,*(void **)(p+0x1c),*(u16 *)(p+4));
        func_02024108(q,func_02024910(*(void **)(p+0x20),p[0x95]));
        func_02031348(*(void **)(p+0xac),-1,(void *)d_021C39B8,q);
        *(void **)(p+0x90)=q;
        return 1;
    }
    return 0;
}




int func_021C15B4(int *state, u8 *p) {
    unsigned pair[2];
    switch (*state) {
    case 0:
        if (func_02024120(*(void **)(p+0x90))) {
            func_02024134(*(void **)(p+0x90),pair);
            func_02024918(*(void **)(p+0x20),p[0x95],pair);
        }
        func_020240FC(*(void **)(p+0x90));
        ++*state;
        break;
    case 1: return 1;
    }
    return 0;
}




void *func_021C1610(unsigned arg, u16 heap) {
    u8 *p;
    p=func_02030734(heap,16,0,d_021C3C98,0x151);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021C3A44);
    func_0204363C(arg);
    func_0204361C(); func_020434CC(); func_02043588();
    func_0201DD60();
    func_021C1738(p,heap);
    func_021C17DC((void **)(p+4),(unsigned)d_021C3A44,heap);
    ((struct Obj22414 *)p)->fC=func_020056A0(func_021C1724,p,0);
    return p;
}




/*
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 re-read at 021C16D6 and 021C16E0.
 */
void func_021C16B0(u8 *p) {
    func_02030EAC(((struct Obj22415 *)p)->fC);
    func_021C181C((void **)(p+4));
    func_021C1798(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}




void func_021C1704(u8 *p) { func_021C1838(p+4); func_021C17D0(p); }




/*
 * Unblocked by matching func_021C1848 in ov110 (pkt_ov110_021C1848).
 */
u32 func_021C1718(u8 *p) { return func_021C1848((u32 *)(p + 4)); }




void func_021C1724(int a,u8 *p) { func_021C17D4(p); func_021C1840(p+4); }




void func_021C1738(void *p, u16 heap) {
    unsigned i;
    const Row *q;
    unsigned id;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021C3A18);
    for (i=0; i<6; i++) {
        q=&d_021C3A74[i];
        id=q->id;
        func_0203FCA0((u8)id,(const struct BgTemplate *)q->bg,(u8)q->pal);
        func_020414AC(id);
        func_02040588(id,q->value);
    }
}



/*
 * lever: observed 44-byte table rows use a typed Row pointer; integer address
 * arithmetic swaps base/index colours, Row member access is EXACT.
 */
void func_021C1798(void *p) { const Row *base; unsigned long i; base=d_021C3A74; for(i=0;i<6;i++) func_020403F4((u8)base[i].id); func_020450C8(); func_0203F9B4(); func_02082BCC(p,0,4); }




void func_021C17D0(void *a0) { }




void func_021C17D4(void *a0)
{
    func_020419E4();
}



void func_021C17DC(void **p, unsigned arg, unsigned heap) {
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)d_021C3A28, arg, heap);
    *p = func_0204B100(128, 0, heap);
    func_0204B270(*p);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}



void func_021C181C(void **p) { func_0204B1CC(*p); func_0204A5AC(); func_02082BCC(p,0,4); }



void func_021C1838(void *a0) { func_0204A600(); }




void func_021C1840(void *a0)
{
    func_0204A648();
}
