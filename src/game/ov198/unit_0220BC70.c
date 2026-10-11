/*
 * file:     unit_0220BC70.c
 * unit:     yes
 * function: func_0220BC70, func_0220BD34, func_0220BD84, func_0220BDA0, func_0220BDD4, func_0220BE04, func_0220BE2C, func_0220BEB8, func_0220C0D0, func_0220C16C, func_0220C2F8, func_0220C398, func_0220C42C, func_0220C4DC, func_0220C5AC, func_0220C60C, func_0220C67C, func_0220C688, func_0220C694, func_0220C714, func_0220C8F0, func_0220C9F0, func_0220CAF0, func_0220CBF0, func_0220CCF0, func_0220CDF0, func_0220CFC4, func_0220D034, func_0220D090, func_0220D1BC, func_0220D218, func_0220D348, func_0220D3B4, func_0220D418, func_0220D494, func_0220D628, func_0220D6AC, func_0220D6DC, func_0220D884, func_0220D920, func_0220D988, func_0220D9B4, func_0220DA6C, func_0220DC04, func_0220DCA8, func_0220DD78, func_0220DE4C, func_0220DF20, func_0220E088, func_0220E13C, func_0220E168, func_0220E1D4, func_0220E22C, func_0220E25C, func_0220E27C, func_0220E2B4, func_0220E2F8, func_0220E340, func_0220E3F0, func_0220E460, func_0220E518, func_0220E584, func_0220E5FC, func_0220E684, func_0220E6E0, func_0220E74C, func_0220E7CC, func_0220E7E4, func_0220E82C, func_0220E8B4, func_0220E974, func_0220E9A0, func_0220EA30, func_0220EA68, func_0220EAF0, func_0220EBCC, func_0220EC2C, func_0220ECCC, func_0220ED54, func_0220EE44, func_0220EECC, func_0220EFD8
 * address:  0x0220BC70
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   d_02211BDA 0x02211BDA data a1
 *   d_02211B80 0x02211B80 data a1
 *   d_02211CB0 0x02211CB0 data a1
 *   d_02211BFE 0x02211BFE data a1
 *   d_02211C24 0x02211C24 data a1
 *   d_02211B98 0x02211B98 data a1
 *   d_02211BB6 0x02211BB6 data a1
 *   d_02211C68 0x02211C68 data a1
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045778 0x02045778 arm
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045738 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   d_02211B68 0x02211B68 data ov198 a4
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0202D01C 0x0202D01C thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_02043AF4 0x02043AF4 arm
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020276C4  0x020276C4  thumb
 *   d_02211AFF  0x02211AFF  data  a1
 *   d_02211AF4 0x02211AF4 data a1
 *   func_02210DA8 0x02210DA8 thumb ov198
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_02211B06 0x02211B06 data a1
 *   d_02211B3C 0x02211B3C data a4
 *   d_02211B50 0x02211B50 data a1
 *   d_02211B20 0x02211B20 data a1
 *   d_02211B0D 0x02211B0D data a1
 *   sub_0201BD28 0x0201BD28 thumb
 *   d_02211B2C 0x02211B2C data a1
 *   sub_0201C1F4 0x0201C1F4 thumb
 *   d_02211AF9 0x02211AF9 data a1
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0220B0B0 0x0220B0B0 thumb ov196
 *   func_0220B094 0x0220B094 thumb ov196
 *   func_0220B07C 0x0220B07C thumb ov196
 *   func_0220F1F4 0x0220F1F4 thumb ov198
 *   func_02043598 0x02043598 arm
 *   func_020490F4  0x020490F4  arm
 *   func_020185F4  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_020275F8 0x020275F8 thumb
 *   func_02027610 0x02027610 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0202775C 0x0202775C thumb
 *   func_02027758 0x02027758 thumb
 *   func_02027760 0x02027760 thumb
 *   func_02027764 0x02027764 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020216D4 0x020216D4 thumb
 *   d_02211DFC 0x02211DFC data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0220AFC4 0x0220AFC4 thumb ov196
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020275EC 0x020275EC thumb
 *   func_02027604 0x02027604 thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0202136C 0x0202136C thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   d_02211DB4 0x02211DB4 data a2
 *   d_02211DCC 0x02211DCC data a2
 *   d_02211DE4 0x02211DE4 data a2
 *   d_02211D34 0x02211D34 data a2
 *   func_0220F060 0x0220F060 thumb ov198
 *   func_0201BD28 0x0201BD28 thumb
 */
#include "../../matched/include/Obj25130.h"
#include "../../matched/include/Obj14554.h"
#include "../../matched/include/Obj25132.h"
#include "../../matched/include/Obj00507.h"
#include "../../matched/include/Obj04598.h"
#include "../../matched/include/Obj08357.h"
#include "../../matched/include/Obj05523.h"
#include "../../matched/include/Obj25133.h"
#include "../../matched/include/Obj25134.h"
#include "../../matched/include/Obj25135.h"
#include "../../matched/include/Obj04599.h"
#include "../../matched/include/Obj14555.h"
#include "../../matched/include/Obj25136.h"
#include "../../matched/include/Obj25137.h"
#include "../../matched/include/Obj04600.h"
#include "../../matched/include/Obj25138.h"
#include "../../matched/include/Obj25139.h"
#include "../../matched/include/Obj25140.h"
#include "../../matched/include/Obj10841.h"
#include "../../matched/include/Obj25141.h"
#include "../../matched/include/Obj25142.h"
#include "../../matched/include/Obj08358.h"
#include "../../matched/include/Obj25143.h"
#include "../../matched/include/Obj25144.h"
#include "../../matched/include/Obj00508.h"
#include "../../matched/include/Obj14556.h"
#include "../../matched/include/Obj25145.h"
#include "../../matched/include/Obj25146.h"
#include "../../matched/include/Obj25147.h"
#include "../../matched/include/Obj25148.h"
#include "../../matched/include/Obj25149.h"
#include "../../matched/include/Obj25150.h"
#include "../../matched/include/Obj25151.h"
#include "../../matched/include/Obj01579.h"
#include "../../matched/include/Obj25152.h"
#include "../../matched/include/Obj01580.h"
#include "../../matched/include/Obj25153.h"
#include "../../matched/include/Obj01581.h"
#include "../../matched/include/Obj25154.h"
#include "../../matched/include/Obj01582.h"
#include "../../matched/include/Obj25155.h"
#include "../../matched/include/Obj00509.h"
#include "../../matched/include/Obj14557.h"
#include "../../matched/include/Obj25156.h"
#include "../../matched/include/Obj25157.h"
#include "../../matched/include/Obj25158.h"
#include "../../matched/include/Obj25159.h"
#include "../../matched/include/Obj25160.h"
#include "../../matched/include/Obj25161.h"
#include "../../matched/include/Obj25162.h"
#include "../../matched/include/Obj25163.h"
#include "../../matched/include/Obj06650.h"
#include "../../matched/include/Obj25164.h"
#include "../../matched/include/Obj25165.h"
#include "../../matched/include/Obj25166.h"
#include "../../matched/include/Obj10842.h"
#include "../../matched/include/Obj25167.h"
#include "../../matched/include/Obj02533.h"
#include "../../matched/include/Obj10843.h"
#include "../../matched/include/Obj25168.h"
#include "../../matched/include/Obj02534.h"
#include "../../matched/include/Obj10844.h"
#include "../../matched/include/Obj25169.h"
#include "../../matched/include/Obj25170.h"
#include "../../matched/include/Obj08359.h"
#include "../../matched/include/Obj25171.h"
#include "../../matched/include/Obj25172.h"
#include "../../matched/include/Obj05524.h"
#include "../../matched/include/Obj25173.h"
#include "../../matched/include/Obj25174.h"
#include "../../matched/include/Obj25175.h"
#include "../../matched/include/Obj02247.h"
#include "../../matched/include/Obj01077.h"
#include "../../matched/include/Obj25176.h"
#include "../../matched/include/Obj25177.h"
#include "../../matched/include/Obj25178.h"
#include "../../matched/include/Obj25179.h"
#include "../../matched/include/Obj25180.h"
#include "../../matched/include/Obj25181.h"
#include "../../matched/include/Obj25182.h"
#include "../../matched/include/Obj25183.h"
#include "../../matched/include/Obj25184.h"
#include "../../matched/include/Obj25185.h"
#include "../../matched/include/Obj25186.h"
#include "../../matched/include/Obj25187.h"
#include "../../matched/include/Obj25188.h"
#include "../../matched/include/Obj25189.h"
#include "../../matched/include/Obj25190.h"
#include "../../matched/include/Obj25191.h"
#include "../../matched/include/Obj25192.h"
#include "../../matched/include/Obj25193.h"
#include "../../matched/include/Obj25194.h"
#include "../../matched/include/Obj25195.h"
#include "../../matched/include/Obj03351.h"
#include "../../matched/include/Obj25197.h"
#include "../../matched/include/Obj00172.h"
#include "../../matched/include/Obj25198.h"
#include "../../matched/include/Obj25199.h"
#include "../../matched/include/Obj25200.h"
#include "../../matched/include/Obj25201.h"
#include "../../matched/include/Obj25202.h"
#include "../../matched/include/Obj25203.h"
#include "../../matched/include/Obj25204.h"
#include "../../matched/include/Obj25205.h"
#include "../../matched/include/Obj25206.h"
#include "../../matched/include/Obj25207.h"
#include "../../matched/include/Obj25208.h"
#include "../../matched/include/Obj25209.h"
#include "../../matched/include/Obj25210.h"
#include "../../matched/include/Obj25211.h"
#include "../../matched/include/Obj25212.h"
#include "../../matched/include/Obj25213.h"
#include "../../matched/include/Obj25214.h"
#include "../../matched/include/Obj25215.h"
#include "../../matched/include/Obj25216.h"
#include "../../matched/include/Obj25217.h"
#include "../../matched/include/Obj25218.h"
#include "../../matched/include/Obj25219.h"
#include "../../matched/include/Obj25220.h"
#include "../../matched/include/Obj25221.h"
#include "../../matched/include/Obj25222.h"
#include "../../matched/include/Obj14559.h"
#include "../../matched/include/Obj10847.h"
#include "../../matched/include/Obj14560.h"

struct Descriptor;
struct CharBuf;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
struct Bmp;
struct Rec;
struct Config;
struct Cfg;
struct Entry;
struct Obj;
struct Bank;
struct PalAnmSlot;
struct Vec2;
struct Sub0204A9D0;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Item { u8 a,b,c,d,e,f; } Item;

typedef struct Bits_0220BC70 { unsigned char low:5; unsigned char high:3; } Bits_0220BC70;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

struct R {
    u8 pad[0x16];
    u8 a0 : 7;
    u8 a1 : 1;
    u8 b0 : 3;
    u8 b1 : 4;
    u8 b2 : 1;
};

struct Ov198Hdr { char pad[0xC]; u32 font; u16 f10; };

struct Ov198P_0220BC70 { struct Ov198Hdr *hdr; char pad[0x1E9C]; void *f1EA0; void *f1EA4; void *pad8; u32 f1EAC; };

typedef struct Bits_0220C0D0 { unsigned char low:7; unsigned char high:1; } Bits_0220C0D0;

struct Ov198P_0220C16C { char pad[0x1E9C]; u32 f1E9C; void *f1EA0; void *f1EA4; void *f1EA8; u32 f1EAC; };

struct Flags { u8 pad[0x2177]; u8 low:4; u8 high:4; };

struct Bits7 { unsigned char value:7; unsigned char flag:1; };

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    unsigned short f10;
} Sub;

typedef struct {
    Sub *f0;
    char pad04[0x1ea0 - 4];
    int f1ea0;
    int f1ea4;
    int f1ea8;
    int f1eac;
    char pad1eb0[0x1f98 - 0x1eb0];
    int f1f98;
    unsigned char f1f9c;
    char pad1f9d[0x1fe0 - 0x1f9d];
    int f1fe0;
    unsigned char f1fe4;
} Big;

typedef signed int     s32;

struct Ov198P { struct Ov198Hdr *hdr; char pad[0x1E9C]; void *f1EA0; void *f1EA4; void *pad8; u32 f1EAC; };

typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;

typedef struct { u8 pad0[4]; void *obj; u16 cnt; u8 pad1[0x1B-0xA]; Bits fl; u8 pad2[0x4C-0x1C]; } Rec;

typedef struct { unsigned char low:7; unsigned char high:1; } Flags_0220D9B4;

typedef struct { char *volatile global; } Context;

typedef struct {u8 lo:4,hi:4;} Bits4;

typedef struct {short x,y,z; u8 a,b;} Point;

typedef struct {u8 half:3; u8 middle:4; u8 egg:1;} Flags_0220E7E4;

typedef struct {char pad0[8];u16 species;char padA[34];unsigned form;char rest[28];} Record_0220D9B4;

typedef struct {u8 low:7;u8 flip:1;} Flags_0220E8B4;

typedef struct {short x,y;} Pair;

typedef struct {u8 low:5;u8 flip:1;u8 high:2;} Flags_0220E9A0;

typedef struct {u8 bytes[76];} Record_0220EAF0;

typedef struct {u8 low:6;u8 bit:1;u8 high:1;} Flag;

typedef struct {u8 low:6;u8 a:1;u8 b:1;} Fl;

typedef struct {char pad[0x1F58];u8 *a;u8 *b;} Q;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern u8 func_02045778(struct Descriptor *p);
extern int func_022110D4(u8 *, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *owner, u32 a, s16 b, s16 c, void *d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
extern u8 func_0202D01C(u32,u32,u32);
extern int func_0202D034(u32,u32);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern int func_020276C4(int a0);
extern int func_02210DA8(u8 *p);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern unsigned sub_0201BD28(u16,unsigned);
extern u32 sub_0201C1F4(u16 id);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern void func_0201F73C(void *,int,int,int);
extern unsigned func_0201DD78(unsigned,unsigned,unsigned);
extern int func_02012FFC(unsigned);
extern int func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern void func_0220B0B0(struct Entry *,int,u32);
extern void func_0220B094(char *,u8 *);
extern void func_0220B07C(void *);
extern void func_0220F1F4(u8 *p);
extern void func_02043598(u32 mask, u32 enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_020185F4(void *p);
extern u32 func_0201BA68(void *mon);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern int func_0204ABF0(void *, unsigned, unsigned, unsigned, u16);
extern unsigned func_020275F8(unsigned);
extern unsigned func_02027610(unsigned);
extern int func_0204AC18(void *,unsigned,unsigned,unsigned,u16,u16,u16);
extern unsigned func_020275E4(void);
extern int func_0202775C(int);
extern int func_02027758(void);
extern int func_02027760(int);
extern int func_02027764(int);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_0204B3B4(struct Obj *p);
extern void func_0220AFC4(u8 *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned func_0201BB5C(unsigned,unsigned,unsigned,unsigned);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204A9D0(int,struct Sub0204A9D0 *);
extern u32 func_020307B0(void *p);
extern u8 func_020275EC(int i);
extern u8 func_02027604(u8 i);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32),func_0204B878(struct Obj *,u32);
extern u32 func_0202136C(u32);
extern void func_0220F060(u8 *p);
extern u32 func_0201BD28(u16 id, u32 field);
void func_0220BC70(u8 *p,u32 state);
void func_0220BD34(u8 *p);
void func_0220BD84(u8 *p);
void func_0220BDA0(u8 *p);
void func_0220BDD4(char *p);
void func_0220BE04(u8 *p);
void func_0220BE2C(char *a, int idx);
void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
void func_0220C0D0(u8 *p,int slot,int index,s16 value,u8 extra);
void func_0220C16C(u8 *p, int slot, int index, u8 x0, u8 extra);
void func_0220C2F8(u8 *p,int slot,int index,u16 value,u8 extra);
void func_0220C398(u8 *p,int slot,int index);
void func_0220C42C(char *p, int i, int index);
void func_0220C4DC(char *p,int value,int slot,int id,u16 x,s16 y,u32 color);
void func_0220C5AC(char *p, int i, s16 x, s16 y);
void func_0220C60C(char *p, int id);
void func_0220C67C(char *p);
void func_0220C688(char *p);
void func_0220C694(char *p, int i, int id);
void func_0220C714(u8 *p,int index);
void func_0220C8F0(char *obj, int i);
void func_0220C9F0(char *p, int i);
void func_0220CAF0(char *p, int i);
void func_0220CBF0(char *p, int i);
void func_0220CCF0(char *p, int i);
void func_0220CDF0(u8 *p,int index);
void func_0220CFC4(char *p, int index);
void func_0220D034(char *p, int i);
void func_0220D090(char *p, int a1, int a2);
void func_0220D1BC(char *p, int i);
void func_0220D218(char *p, int a1, u32 a2);
void func_0220D348(char *p, int i, int id);
void func_0220D3B4(char *p, int i);
void func_0220D418(char *p, int i, int selector);
void func_0220D494(u8 *p, int slot, int a2, int a3);
void func_0220D628(char *p, int i);
void func_0220D6AC(u8 *p);
void func_0220D6DC(char *p,u8 *record,int slot);
void func_0220D884(u8 *p);
void func_0220D920(u8 *p, int i);
void func_0220D988(u8 *p,int a);
void func_0220D9B4(char *p);
void func_0220DA6C(u8 *p, int idx);
void func_0220DC04(char *p);
void func_0220DCA8(char *p);
void func_0220DD78(char *p);
void func_0220DE4C(char *p);
void func_0220DF20(char *p);
void func_0220E088(char *p);
void func_0220E13C(u8 *p);
void func_0220E168(char *p);
void func_0220E1D4(u8 *p);
void func_0220E22C(u8 *p);
void func_0220E25C(u8 *p);
void func_0220E27C(u8 *p);
void func_0220E2B4(char *p);
void func_0220E2F8(char *p);
void func_0220E340(u8 *p);
void func_0220E3F0(char *p);
void func_0220E460(char *p);
void func_0220E518(char *p);
void func_0220E584(char *p);
void func_0220E5FC(char *p);
unsigned func_0220E684(char *p,const int *q);
void func_0220E6E0(char *p);
void func_0220E74C(char *p);
void func_0220E7CC(u8 *p, u32 b);
void func_0220E7E4(Record_0220D9B4 *records);
void func_0220E82C(char *p,void *obj,int index,int which);
void func_0220E8B4(char *p,int first,int index,int which);
void func_0220E974(int mode,u8 *p,const struct Vec2 *q);
void func_0220E9A0(char *p,u8 *q,const Pair *pos);
void func_0220EA30(u32 mode,u8 *p,const struct Vec2 *q);
void func_0220EA68(char *p,unsigned mode);
void func_0220EAF0(Record_0220EAF0 *records);
void func_0220EBCC(Record_0220EAF0 *records);
void func_0220EC2C(u8 *p);
void func_0220ECCC(u8 *p);
void func_0220ED54(u8 *p);
void func_0220EE44(u8 *p);
void func_0220EECC(u8 *p);
void func_0220EFD8(u8 *p);
extern Item d_02211BDA[],d_02211B80[],d_02211CB0[],d_02211BFE[],d_02211C24[],d_02211B98[],d_02211BB6[],d_02211C68[];
extern u32 d_02211B68[];
extern u8 d_02211AFF[];
extern u8 d_02211AF4[];
extern u8 d_02211B06[];
extern const int d_02211B3C[];
extern u8 d_02211B50[];
extern u8 d_02211B20[];
extern u8 d_02211B0D[];
extern u8 d_02211B2C[];
extern u8 d_02211AF9[];
extern const int d_02211DFC[][5];
extern const Pair d_02211DB4[],d_02211DCC[],d_02211DE4[];
extern Pair d_02211D34[27];









#define P ((struct Ov198P_0220BC70 *)p)












/*
 * precondition: game callers supply state 0..8; every case initializes s.
 * evidence: C88's nine callers pass constants0..8; F4E0 dominates BC24
 * with state-byte2180 stores0/4/6. C88 stores its bounded state at2177+9.
 * Domain and decoded-call audit: Wave30 S26/BC70-domain-review.md.
 */
void func_0220BC70(u8 *p,u32 state)
{
    Item *s;
    u32 i;
    func_0220BD84(p);
    func_0220BD34(p);
    switch(state) {
    case 0: case 8: s=d_02211BDA; p[0x2174]=6; break;
    case 1: s=d_02211B80; p[0x2174]=4; break;
    case 2: s=d_02211CB0; p[0x2174]=22; break;
    case 3: s=d_02211BFE; p[0x2174]=6; break;
    case 4: s=d_02211C24; p[0x2174]=11; break;
    case 5: s=d_02211B98; p[0x2174]=5; break;
    case 6: s=d_02211BB6; p[0x2174]=6; break;
    case 7: s=d_02211C68; p[0x2174]=12; break;
    }
    for(i=0;i<p[0x2174];i++,s++)
        *(void **)(p+i*8+0x1F70)=(void *)func_020450F0(s->a,s->b,s->c,s->d,s->e,s->f,1);
}












void func_0220BD34(u8 *p)
{
    if (((Bits_0220BC70 *)(p+0x2175))->low == 1)
        ((struct Obj25130 *)p)->f2170=(void *)func_020450F0(5,0,0,32,16,0,1);
    ((Bits_0220BC70 *)(p+0x2175))->low ^= 1;
}













/*
 * Addresses are Black-image addresses.
 */
void func_0220BD84(u8 *p)
{
    u32 t = ((struct Obj14554 *)p)->f2170;

    if (t != 0) {
        func_020452E8((struct Descriptor *)t);
        ((struct Obj14554 *)p)->f2170 = 0;
    }
}












void func_0220BDA0(u8 *p){u32 i;for(i=0;i<p[0x2174];i++)func_02043B5C(func_02045770(*(struct Descriptor **)(p+i*8+0x1f70)),0);}













void func_0220BDD4(char *p)
{
    unsigned int i;
    for (i = 0; i < ((struct Obj25132 *)p)->f2174; i++)
    {
        func_020452E8(*(void **)(p + 0x1f70 + i * 8));
    }
}












void func_0220BE04(u8 *p){u32 i;func_0220BDD4((char *)p);for(i=0;i<2;i++)func_020452E8(*(struct Descriptor **)(p+i*8+0x1f60));func_0220BD84(p);}













void func_0220BE2C(char *a, int idx)
{
    switch (idx) {
    case 0: {
        unsigned char c;
        func_0220D884((u8 *)a);
        c = *(unsigned char *)(*(int *)&((struct Obj00507 *)a)->f0 + 0x1f);
        if (c == 3)
            func_0220C60C(a, 7);
        else if (c == 2)
            func_0220C60C(a, 9);
        else
            func_0220C60C(a, 6);
        break;
    }
    case 8:
        func_0220D884((u8 *)a);
        func_0220C60C(a, 0xa);
        break;
    case 1:
        func_0220D9B4(a);
        break;
    case 2:
        func_0220DCA8(a);
        break;
    case 3:
        func_0220DC04(a);
        break;
    case 4:
        func_0220DD78(a);
        break;
    case 5:
        func_0220E088(a);
        break;
    case 6:
        func_0220DE4C(a);
        break;
    case 7:
        func_0220DF20(a);
        break;
    }
}











/*
 * lever: rec is passed as `*(void **)rec` (a real variable, not a CSE temp); ex is an s16 local (the callee's
 *   parameter type) set in each head arm; a2 is u16 (the caller passes `(u16)i`); tail colour depends on b0
 * 2026-10-05 (wD9r lane121): 45 -> EXACT. Fixes: (1) the 0201EEF4 argument written `*(void **)rec`, so rec is a
 *   declared variable with its own slot (the `base + off` form made it a CSE temp in the lowest slot); (2) lane 94's
 *   declaration order (w2, w, off, handle, rec, vec, msg, x, k, c90, cn0, c91, cn1, ex, m3, m2, x2) with the four
 *   tail ctx values as function-scope locals; (3) ex as s16 (the 0201C724 parameter type), assigned in each head
 *   arm: a u8 copy coalesced with the stack parameter; (4) logic fix: the tail colour is 0x2960 for b0 == 0 and
 *   0x31A0 for b0 == 1 in both k arms (the draft had it per k); (5) a2 as u16 (the matched caller passes
 *   `(u16)i`), which puts the a2 spill store first at entry.
 */
void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra)
{
    u32 w2;
    u32 w;
    u32 off;
    void *handle;
    struct R *rec;
    void *vec;
    void *msg;
    u32 x;
    u32 k;
    u32 c90;
    u32 cn0;
    u32 c91;
    u32 cn1;
    s16 ex;
    void *m3;
    void *m2;
    u32 x2;
    int n;
    u8 *base;
    u8 *tab;

    slot = slot * 8;
    tab = p + 0x1F70;
    handle = *(void **)(tab + slot);
    k = func_02045778(handle);
    n = func_022110D4(p, a2);
    base = p + 4;
    off = n * 0x4C;
    rec = (struct R *)(base + off);
    vec = func_020457B0(12, P->hdr->f10);
    msg = func_02045EC0(P->f1EA0, d_02211B68[a2]);
    func_0201EEF4(P->f1EA4, 0, *(void **)rec);
    func_0201F250(P->f1EA4, vec, msg);
    if (k == 9) {
        u32 h9 = P->f1EAC;
        ex = extra;
        func_0201C724((void *)h9, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
        *(p + 0x1F74 + slot) = 1;
    } else {
        u32 hn = P->f1EAC;
        ex = extra;
        func_0201C724((void *)hn, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
        *(p + 0x1F74 + slot) = 1;
    }
    func_02045808(msg);
    func_02045808(vec);
    if (rec->a1 || rec->b2)
        return;
    if (rec->b0 == 0) {
        m2 = func_02045EC0(P->f1EA0, 0x16);
        w = func_02045738(handle);
        x = (u16)((w << 3) - func_0201D304(m2, P->hdr->font, 0));
        if (k == 9) {
            c90 = P->f1EAC;
            func_0201C724((void *)c90, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x2960);
            *(p + 0x1F74 + slot) = 1;
        } else {
            cn0 = P->f1EAC;
            func_0201C724((void *)cn0, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x2960);
            *(p + 0x1F74 + slot) = 1;
        }
        func_02045808(m2);
    } else if (rec->b0 == 1) {
        m3 = func_02045EC0(P->f1EA0, 0x17);
        w2 = func_02045738(handle);
        x2 = (u16)((w2 << 3) - func_0201D304(m3, P->hdr->font, 0));
        if (k == 9) {
            c91 = P->f1EAC;
            func_0201C724((void *)c91, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x31A0);
            *(p + 0x1F74 + slot) = 1;
        } else {
            cn1 = P->f1EAC;
            func_0201C724((void *)cn1, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x31A0);
            *(p + 0x1F74 + slot) = 1;
        }
        func_02045808(m3);
    }
}









void func_0220C0D0(u8 *p,int slot,int index,s16 value,u8 extra)
{
    char *elem=(char *)(p+4)+func_022110D4(p,index)*0x4C;
    void *text=func_02045EC0(((struct Obj04598 *)p)->f1EA0,11);
    u32 context;
    u32 surface;
    func_0201EFA4(((struct Obj04598 *)p)->f1EA4,0,((Bits_0220C0D0 *)(elem+0x16))->low,3,0,1);
    func_0201F250(((struct Obj04598 *)p)->f1EA4,(void *)(((struct Obj04598 *)p)->f1EA8),text);
    context=((struct Obj04598 *)p)->f1EAC;
    surface=(u32)func_02045770(*(void **)(p+slot*8+0x1F70));
    func_0201C724((void *)context,surface,value,extra,(void *)((struct Obj04598 *)p)->f1EA8,((struct Obj04598 *)p)->f1E9C,0x3DC0);
    (p+slot*8)[0x1F74]=1;
    func_02045808(text);
}








#undef P







#undef P






#undef P





#undef P




#undef P



#undef P


#undef P

#undef P
#define P ((struct Ov198P_0220C16C *)p)









static inline u32 half(u32 w) { return w >> 1; }









/*
 * 2026-10-05 (wD9r lane164): EXACT in both --lang c99 and --lang c. The steering cast `(u32)n >> 1` is gone:
 *   the halving is a single-parameter helper `static inline u32 half(u32 w) { return w >> 1; }` (shape of
 *   ov097 021F6D70 center_x), so the u32 parameter gives lsrs. Plain `x0 - (n >> 1)` is DIFF. Locals are
 *   declared at the top in the same order (C89 form), assignments in place; same bytes.
 * 2026-10-05 (wD9r lane156): EXACT. n is a u8 local (`u8 n = func_0201D304(...)`), widened to u32 for the
 *   halving shift (`x0 - ((u32)n >> 1)`, keeps lsrs). mwcc keeps the reload of a spilled narrow local below the
 *   outgoing stack stores (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md).
 * 2026-10-05 (wD9r lane138): still 22 bytes. Tried the matched ov198 sibling prototype (0220C694, 0220D628:
 *   `func_0201C724(void *, u32, u32, u32, u32, u32, u16)` with an (s16) cast at the call): 54, the ex reload
 *   then hoists above the stack stores in all three calls. Also (u32, u32, int, int): 327 (frame grows, slot
 *   spilled); (int, s16): 328; (s16, int): 54; (short, short): 22. Finding: with an s16 parameter the ex
 *   reload stays below the outgoing stores, with u32 or int it hoists, so the s16 prototype is right and the
 *   parameter type changes where a reload lands. The x0 + n add still heads the chain in every form.
 * 2026-10-05 (wD9r lane127): still 22 bytes. Tried two new forms of the 'n lives in memory' idea:
 *   n written through a static inline out-parameter helper `getw(text, font, &n)` (u32 and u8 n; mwcc
 *   promotes the inlined address-taken local, same 22 or 29 lines); and `y = x0 + n;` reusing the call 2
 *   s16 local for call 3 (same 22). Check of the hint: no register parameter here can be a homed narrow
 *   parameter (all four are used in registers at entry, no entry store), and a homed slot would add bytes
 *   (image is 396, ours 396). The 0xC slot is the narrow stack parameter `extra` copied to the frame.
 * 2026-10-05 (wD9r lane111): still 22 bytes. New finding (diagnostic): a reassigned NARROW real parameter
 *   (index declared u16, short or signed char, then `index = (u8)func_0201D304(...)` and `x0 + index` in call 3)
 *   is memory-homed by mwcc, and call 3 then has the image order exactly (three stack stores, ldr r2 n,
 *   ldr r0 ctx3, adds, lsls, ldr r3, asrs). But the home costs an entry store `str r2,[sp,#0xc]` and a reload
 *   for the first call, and the slot is the lowest one (image: no entry store, n at 0x28), so not the source.
 *   A u8 index is not homed (40, still hoisted). Also tried: the body after the 0201D304 call as a static
 *   inline `rest(..., u32/u16/short n)` with n as an inline parameter (328, slot param spilled; the n reload
 *   is still hoisted, inline parameters are not homed). So the image n has the alias class of a param home
 *   or escaped local (ov097 lane95), but no source form with neither an entry store nor an `add rX,sp` found.
 * 2026-10-05 (wD9r lane56): still 22 bytes. Tried: n as u16 (40, n >> 1 becomes asrs and slots shift); the
 *   third x through `static inline s16 xsum(u8 a, u32 b) { return a + b; }` (22, the sum is still evaluated
 *   before the outgoing stack stores). Reading: in this compiler a load does not pass an earlier store (see
 *   ov194 021F3FBC entry), so the original evaluates the stack arguments of call 3 before the x sum and ours
 *   evaluates the sum first; the argument evaluation order, not alias, is the residue.
 * 2026-10-05 (wD9r lane43): still 22 bytes. Tried n declared u8 with the callee result assigned directly
 *   (the narrow-parameter idiom applied to the spilled local): 40 bytes, slots shift and the n reload still hoists
 *   above the stack stores. Compared with the EXACT sibling 0220D494: its third call `x + w1` has u32 x, here x0
 *   is a u8 parameter; no source form found that blocks the hoist.
 * 2026-10-05 (wD9r lane26): still 22 bytes. Tried int return types on 0201EFA4, 0201F250, 02045808 and 0201C724
 *   (the lever that closed ov217 021B9920): same 22. In ov097 021F6D70 an early s16 local for the sum is sunk to
 *   the call by mwcc, so the chain position is decided at the use, not by where the sum is written.
 * 2026-10-05 (wD9r lane12): still 22 bytes. Tried: the 0201D304 result in a u32 local w, then n = (u8)w (two
 *   variables, same 22); the third x through a pointer round trip (stand-in probe only, same 22). Same residue
 *   as ov097 021F6D70: the n reload heads the r2 chain in ours and sits below the stack stores in the image.
 *
 * note: DIFF vs 2026-10-04: 22 bytes differ, only the last 201C724 call: original stores the three stack args first and loads n and adds x0+n late (ldr r2,[sp,#0x28] after the stack stores), ours hoists the n load and add before the stack stores. Everything else matches (declaration order sets slots; x0 param reassigned; ctx and A/B locals). Tried: (s16)(x0+n), n+x0, a y local assigned before the call.
 * note 2026-10-05 (wave D4 lane 10): still DIFF (22 bytes). Tried ctx3 inlined as P->f1EAC (115 bytes) and
 *   A/B locals for the third call as in the second (no change). The sibling 0220D494 (EXACT this wave)
 *   computes its x+w1 early like ours, so the late `ldr r2,[sp,#0x28]; adds` here hints the third x is a
 *   different expression or variable in the original; not found.
 * note 2026-10-05 (wave D5 lane 10): still DIFF (22 bytes). Tried: a static inline put helper for all three calls
 *   (s16 x: no change; int x: 334 bytes), the helper on the third call only with int x (122), u8/int/s16 n (23-40),
 *   `y = x0 + n` before or after ctx3 (no change). The original treats the n reload as if it may alias the outgoing
 *   stack stores; ours hoists it above them.
 * 2026-10-05 (wD6 lane07): still 22 bytes. Tried: the 02045770 result in a block local before the call, with and
 *   without `y = x0 + n` and B3/A3 locals for the stack arguments placed after it (no change: the scheduler, not the
 *   source order, places the n reload); volatile n (337); int prototype for x with (s16) casts (327). In the original
 *   the n reload is not moved above the outgoing stack stores; ours is.
 * 2026-10-05 (wD7 lane10): still DIFF, 22 bytes. Read the scheduling: in the original, every spill reload before
 *   the three 0201C724 calls stays below the outgoing stack stores (call 2 leaves the `ldr r0,[sp,#0x10]; str r0,[sp]`
 *   stall open), so the n reload is blocked by a dependence, not by priority. In ours the n reload heads a 5-instruction
 *   chain and fills the stalls. Tests: an int y in call 2 (needs a conversion) also hoists its reload above the
 *   stores, so chain length drives the hoist in our build. n as a one-element array, n passed by address to a
 *   static inline adder, n used alone as x (no add), u8 n: the reload still hoists. A new u8 local x for
 *   x0 - (n >> 1) instead of reassigning x0: 328. No ex local, no tab local: no change; ctx1 inlined: 314.
 *   Open: what makes the original x chain depend on the stack stores.
 * 2026-10-05 (wD8 lane09): still 22 bytes. Same scheduler residue as ov116 021D7D0C (a spill reload kept
 *   below the outgoing stack stores in the image, hoisted in ours). No new form tested beyond the listing check.
 * 2026-10-05 (wD9 lane20): still 22 bytes. Tested whether n lives in memory in the original (a reload that may alias
 *   the outgoing stores): n as a one-field local struct `struct { u32 v; } n;` is still promoted to a register and
 *   spilled; the reload still hoists above the stack stores (35 bytes, slots shift). Not a memory variable.
 * 2026-10-05 (wD9r lane79): still 22 bytes. Tried the sum as a reassignment before the call: `n = x0 + n;`
 *   then pass n (400 bytes, 99, n gets a new register and slot), and `x0 = x0 + n;` then pass x0 (23, adds a u8
 *   truncation). Neither keeps the n reload below the outgoing stack stores.
 * 2026-10-05 (wD9r lane87): still 22 bytes. Tried the house prototype of func_0201C724 with a u16 colour
 *   (ov021 021905C8, arm9 0202E1F0), with and without a const text pointer: same 22. The n reload still
 *   heads the x chain above the outgoing stack stores.
 * 2026-10-05 (wD9r lane98): still 22 bytes. Reading: in both builds the direct-move reloads (y, ex, ctx) sit
 *   below the outgoing stack stores and do not fill the `ldr; str [sp]` stalls, so reloads never pass those stores;
 *   ours therefore has the n reload (the x0 + n add) before the stores in its IR. Tried: a block u32 x3 = x0 + n and
 *   int x3 = n + x0 before ctx3 (22, sunk to the same place); the 02045770 result in a block local h3 with ctx3
 *   before it (22) and with P->f1EAC inline as the first argument (115). No new source form found.
 * 2026-10-05 (wD9r lane104): still 22 bytes. Tried the short idiom (ov116 021D7D0C): n as short or u16
 *   (40, n >> 1 becomes asrs and slots shift, reload still hoists), func_0201D304 returning short (22),
 *   x0 as a short parameter (24, the x0 truncation becomes 16-bit, reload still hoists), and the dead int
 *   parameter `index` reused for n as short/u16/u8 (40) or int/u32 (376). None keeps the n reload below the
 *   outgoing stack stores.
 */
void func_0220C16C(u8 *p, int slot, int index, u8 x0, u8 extra)
{
    char *elem;
    void *text;
    u8 n;
    u32 ctx1;
    u8 ex;
    u8 *tab;
    u8 *fl;
    void *text2;
    void *text3;
    u32 ctx2;
    s16 y;
    u32 ctx3;
    u32 A;
    void *B;
    elem = (char *)(p + 4) + func_022110D4(p, index) * 0x4C;
    text = func_02045EC0(P->f1EA0, 12);
    n = func_0201D304(text, P->f1E9C, 0);
    x0 = x0 - half(n);
    ctx1 = P->f1EAC;
    ex = extra;
    slot = slot * 8;
    tab = p + 0x1F70;
    fl = p + 0x1F74;
    func_0201C724((void *)ctx1, (u32)func_02045770(*(void **)(tab + slot)), x0, ex, text, P->f1E9C, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text);
    text2 = func_02045EC0(P->f1EA0, 13);
    func_0201EFA4(P->f1EA4, 0, *(u16 *)(elem + 0x10), 3, 0, 1);
    func_0201F250(P->f1EA4, P->f1EA8, text2);
    A = P->f1E9C;
    B = P->f1EA8;
    y = x0 - func_0201D304(B, A, 0);
    ctx2 = P->f1EAC;
    func_0201C724((void *)ctx2, (u32)func_02045770(*(void **)(tab + slot)), y, ex, B, A, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text2);
    text3 = func_02045EC0(P->f1EA0, 13);
    func_0201EFA4(P->f1EA4, 0, *(u16 *)(elem + 0x12), 3, 0, 1);
    func_0201F250(P->f1EA4, P->f1EA8, text3);
    ctx3 = P->f1EAC;
    func_0201C724((void *)ctx3, (u32)func_02045770(*(void **)(tab + slot)), x0 + n, ex, P->f1EA8, P->f1E9C, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text3);
}







#undef P






#undef P





#undef P




#undef P



#undef P


#undef P

#undef P

#define P ((struct Ov198P *)p)









/*
 * lever: u16 value and u8 width/return preserve stack-store scheduling.
 */
void func_0220C2F8(u8 *p,int slot,int index,u16 value,u8 extra)
{
    char *elem=(char *)(p+4)+func_022110D4(p,index)*0x4C;
    u8 color=1;
    u8 width=func_0202D01C(((struct Obj08357 *)elem)->f10,((struct Obj08357 *)elem)->f12,48);
    switch(func_0202D034(((struct Obj08357 *)elem)->f10,((struct Obj08357 *)elem)->f12)) {
    case 3: return;
    case 0: color=1; break;
    case 1: color=3; break;
    case 2: color=5; break;
    }
    func_02043AF4((struct Bmp *)((u32)func_02045770(*(void **)(p+0x1F70+slot*8))),(u16)value,(s16)(extra+3),width,(u8)1,(u8)color);
    color++;
    func_02043AF4((struct Bmp *)((u32)func_02045770(*(void **)(p+0x1F70+slot*8))),(u16)value,(s16)(extra+4),width,(u8)1,(u8)color);
}









void func_0220C398(u8 *p,int slot,int index)
{
    char *elem=(char *)(p+4)+func_022110D4(p,index)*0x4C;
    u32 buf=(u32)func_020457B0(16,((struct Obj25133 *)(*(char * *)&((struct Obj05523 *)p)->f0))->f10);
    void *text=func_02045EC0(((struct Obj05523 *)p)->f1EA0,14);
    u32 context;
    u32 surface;
    func_0201EF8C(((struct Obj05523 *)p)->f1EA4,0,((struct Obj25134 *)elem)->f18);
    func_0201F250(((struct Obj05523 *)p)->f1EA4,(void *)buf,text);
    context=((struct Obj05523 *)p)->f1EAC;
    surface=(u32)func_02045770(*(void **)(p+slot*8+0x1F70));
    func_0201C724((void *)context,surface,0,0,(void *)buf,((struct Obj25135 *)(*(char * *)&((struct Obj05523 *)p)->f0))->fC,0x3DC0);
    (p+slot*8)[0x1F74]=1;
    func_02045808(text);
    func_02045808((void *)buf);
}









void func_0220C42C(char *p, int i, int index)
{
    char *elem;
    void *t;
    void *format;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    if (((struct Obj14555 *)elem)->f1A == 0)
        t = func_02045EC0(((struct Obj04599 *)p)->f1EA0, 0x1E);
    else {
        t = (void *)func_020457B0(0x12, ((struct Obj25136 *)(*(char * *)&((struct Obj04599 *)p)->f0))->f10);
        format = func_02045EC0(((struct Obj04599 *)p)->f1EA0, 15);
        func_0201EF40(((struct Obj04599 *)p)->f1EA4, 0, ((struct Obj14555 *)elem)->f1A);
        func_0201F250(((struct Obj04599 *)p)->f1EA4, (void *)((u32)t), format);
        func_02045808(format);
    }
    f = ((struct Obj04599 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct Obj25137 *)(*(char * *)&((struct Obj04599 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}









void func_0220C4DC(char *p,int value,int slot,int id,u16 x,s16 y,u32 color)
{
    void *handle;
    void *buf;
    void *text;
    void *context;
    u32 width;
    handle=*(void **)(p+0x1F70+slot*8);
    buf=func_020457B0(16,((struct Obj25138 *)(*(char * *)&((struct Obj04600 *)p)->f0))->f10);
    text=func_02045EC0(((struct Obj04600 *)p)->f1EA0,id);
    func_0201EF34(((struct Obj04600 *)p)->f1EA4,0,value);
    func_0201F250(((struct Obj04600 *)p)->f1EA4,buf,text);
    if (x==0xFFFF) {
        width=func_02045738(handle);
        x=((width<<3)-func_0201D304(buf,((struct Obj25139 *)(*(char * *)&((struct Obj04600 *)p)->f0))->fC,0))>>1;
    }
    context=((struct Obj04600 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),x,y,buf,((struct Obj25140 *)(*(char * *)&((struct Obj04600 *)p)->f0))->fC,(u16)color);
    *(u8 *)(p+slot*8+0x1F74)=1;
    func_02045808(text);
    func_02045808(buf);
}









void func_0220C5AC(char *p, int i, s16 x, s16 y)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj10841 *)p)->f1EA0, 0x14);
    f = ((struct Obj10841 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), x, y, t, ((struct Obj25141 *)(*(char * *)&((struct Obj10841 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}









void func_0220C60C(char *p, int id)
{
    void *t;
    void *f;
    func_02043B5C((void *)func_02045770(((struct Obj00507 *)p)->f1F60), 15);
    t = func_02045EC0(((struct Obj00507 *)p)->f1EA0, id);
    f = ((struct Obj00507 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(((struct Obj00507 *)p)->f1F60), 0, 0, t, ((struct Obj25142 *)(*(char * *)&((struct Obj00507 *)p)->f0))->fC, 0x440);
    ((struct Obj00507 *)p)->f1F64 = 1;
    func_02045808(t);
    ((struct Flags *)p)->high = 1;
}









void func_0220C67C(char *p){func_0220C60C(p,9);}









void func_0220C688(char *p){func_0220C60C(p,10);}









void func_0220C694(char *p, int i, int id)
{
    void *t;
    void *handle;
    void *f;
    u32 width;
    u32 font;
    s16 x;
    handle = *(void **)(p + 0x1F70 + i * 8);
    t = func_02045EC0(((struct Obj08358 *)p)->f1EA0, id);
    width = func_0201D304(t, ((struct Obj25143 *)(*(char * *)&((struct Obj08358 *)p)->f0))->fC, 0);
    font = ((struct Obj25144 *)(*(char * *)&((struct Obj08358 *)p)->f0))->fC;
    x = (s16)(((func_02045738(handle) << 3) - width) >> 1);
    f = ((struct Obj08358 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), x, 5, t, font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}









void func_0220C714(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    void *thirdContext;
    u32 width;
    u16 x;
    elem=p+4+func_022110D4(p,index)*0x4C;
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x21);
    context=((struct Obj00508 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00508 *)p)->f2008),0,0,text,((struct Obj25145 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f200C=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x22);
    buf=func_020457B0(8,((struct Obj25146 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,((struct Bits7 *)(elem+0x16))->value,3,0,1);
    func_0201F250(((struct Obj00508 *)p)->f1EA4,buf,text);
    secondContext=((struct Obj00508 *)p)->f1EAC;
    func_0201C724(secondContext,(u32)func_02045770(((struct Obj00508 *)p)->f1FC8),0,0,buf,((struct Obj25147 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f1FCC=1;
    func_02045808(text);
    func_02045808(buf);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x23);
    thirdContext=((struct Obj00508 *)p)->f1EAC;
    func_0201C724(thirdContext,(u32)func_02045770(((struct Obj00508 *)p)->f2010),0,0,text,((struct Obj25148 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f2014=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x24);
    buf=func_020457B0(14,((struct Obj25149 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->f10);
    if (((struct Bits7 *)(elem+0x16))->value<100) {
        func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,((struct Obj14556 *)elem)->f24-((struct Obj14556 *)elem)->f1C,6,1,1);
    } else {
        func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,0,6,1,1);
    }
    func_0201F250(((struct Obj00508 *)p)->f1EA4,buf,text);
    width=func_02045738(((struct Obj00508 *)p)->f1FD0);
    x=(width<<3)-func_0201D304(buf,((struct Obj25150 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0);
    context=((struct Obj00508 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00508 *)p)->f1FD0),x,0,buf,((struct Obj25151 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x2120);
    ((struct Obj00508 *)p)->f1FD4=1;
    func_02045808(text);
    func_02045808(buf);
}










static inline void put(Big *a0, int win, int sel, s16 x, int h, int color)
{
    func_0201C724((void *)win, (int)func_02045770((struct Descriptor *)sel), x, 0, (void *)h, a0->f0->fc, color);
}










/*
 * lever: both 0201C724 calls are one static inline helper; the centred x is a u8 local declared after v
 */
void func_0220C8F0(char *obj, int i)
{
    Big *a0 = (Big *)obj;
    char *entry = (char *)a0 + 4 + func_022110D4((u8 *)a0, i) * 0x4c;
    int h1;
    int h2;
    int p;
    int v;
    unsigned char x;

    h1 = (int)func_02045EC0((struct MsgBank *)a0->f1ea0, 0x2a);
    put(a0, a0->f1eac, a0->f1fe0, 0, h1, 0x3dc0);
    a0->f1fe4 = 1;
    func_02045808((struct U16Vec *)h1);

    h2 = (int)func_02045EC0((struct MsgBank *)a0->f1ea0, 0x2b);
    p = (int)func_020457B0(8, a0->f0->f10);
    func_0201EFA4((struct WordSet *)a0->f1ea4, 0, *(unsigned short *)(entry + 6), 3, 0, 1);
    func_0201F250((struct WordSet *)a0->f1ea4, (void *)p, (void *)h2);

    v = (unsigned char)func_0201D304((struct StrObj *)p, a0->f0->fc, 0);
    x = (func_02045738((struct Descriptor *)a0->f1f98) << 3) - v;
    put(a0, a0->f1eac, a0->f1f98, x, p, 0x2120);
    a0->f1f9c = 1;
    func_02045808((struct U16Vec *)h2);
    func_02045808((struct U16Vec *)p);
}










void func_0220C9F0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01579 *)p)->f1EA0, 0x2c);
    x = ((struct Obj01579 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01579 *)p)->f1FE8);
    func_0201C724((void *)x, y, 0, 0, t, *(u32 *)(((struct Obj01579 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01579 *)p)->f1FEC = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01579 *)p)->f1EA0, 0x2d);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01579 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01579 *)p)->f1EA4, 0, ((struct Obj25152 *)elem)->f8, 3, 0, 1);
    func_0201F250(((struct Obj01579 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01579 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01579 *)p)->f1FA0) << 3) - b;
    d = ((struct Obj01579 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01579 *)p)->f1FA0);
    func_0201C724((void *)d, e, c, 0, (void *)h, *(u32 *)(((struct Obj01579 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01579 *)p)->f1FA4 = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}










void func_0220CAF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01580 *)p)->f1EA0, 0x32);
    x = ((struct Obj01580 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01580 *)p)->f1FF0);
    func_0201C724((void *)x, y, 0, 0, t, *(u32 *)(((struct Obj01580 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01580 *)p)->f1FF4 = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01580 *)p)->f1EA0, 0x33);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01580 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01580 *)p)->f1EA4, 0, ((struct Obj25153 *)elem)->fA, 3, 0, 1);
    func_0201F250(((struct Obj01580 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01580 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01580 *)p)->f1FA8) << 3) - b;
    d = ((struct Obj01580 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01580 *)p)->f1FA8);
    func_0201C724((void *)d, e, c, 0, (void *)h, *(u32 *)(((struct Obj01580 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01580 *)p)->f1FAC = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}










void func_0220CBF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01581 *)p)->f1EA0, 0x2e);
    x = ((struct Obj01581 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01581 *)p)->f1FF8);
    func_0201C724((void *)x, y, 0, 0, t, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01581 *)p)->f1FFC = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01581 *)p)->f1EA0, 0x2f);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01581 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01581 *)p)->f1EA4, 0, ((struct Obj25154 *)elem)->fC, 3, 0, 1);
    func_0201F250(((struct Obj01581 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01581 *)p)->f1FB0) << 3) - b;
    d = ((struct Obj01581 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01581 *)p)->f1FB0);
    func_0201C724((void *)d, e, c, 0, (void *)h, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01581 *)p)->f1FB4 = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}










void func_0220CCF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01582 *)p)->f1EA0, 0x30);
    x = ((struct Obj01582 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01582 *)p)->f2000);
    func_0201C724((void *)x, y, 0, 0, t, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01582 *)p)->f2004 = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01582 *)p)->f1EA0, 0x31);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01582 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01582 *)p)->f1EA4, 0, ((struct Obj25155 *)elem)->fE, 3, 0, 1);
    func_0201F250(((struct Obj01582 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01582 *)p)->f1FB8) << 3) - b;
    d = ((struct Obj01582 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01582 *)p)->f1FB8);
    func_0201C724((void *)d, e, c, 0, (void *)h, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01582 *)p)->f1FBC = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}









void func_0220CDF0(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    u16 x;
    elem=p+4+func_022110D4(p,index)*0x4C;
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x26);
    context=((struct Obj00509 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00509 *)p)->f1FD8),0,0,text,((struct Obj25156 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00509 *)p)->f1FDC=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x29);
    width=func_0201D304(text,((struct Obj25157 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0);
    x=((func_02045738(((struct Obj00509 *)p)->f1F90)<<3)-width)>>1;
    secondContext=((struct Obj00509 *)p)->f1EAC;
    func_0201C724(secondContext,(u32)func_02045770(((struct Obj00509 *)p)->f1F90),x,0,text,((struct Obj25158 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x27);
    buf=func_020457B0(8,((struct Obj25159 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00509 *)p)->f1EA4,0,((struct Obj14557 *)elem)->f10,3,0,1);
    func_0201F250(((struct Obj00509 *)p)->f1EA4,buf,text);
    otherWidth=func_0201D304(buf,((struct Obj25160 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0);
    context=((struct Obj00509 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00509 *)p)->f1F90),(x-otherWidth),0,buf,((struct Obj25161 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    func_02045808(text);
    func_02045808(buf);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x28);
    buf=func_020457B0(8,((struct Obj25162 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00509 *)p)->f1EA4,0,((struct Obj14557 *)elem)->f12,3,0,1);
    func_0201F250(((struct Obj00509 *)p)->f1EA4,buf,text);
    context=((struct Obj00509 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00509 *)p)->f1F90),(x+width),0,buf,((struct Obj25163 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    func_02045808(text);
    func_02045808(buf);
}









void func_0220CFC4(char *p, int index)
{
    char *elem;
    void *bank;
    void *t;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    bank = func_02045B38(0, 2, 0xB7, ((struct Obj25164 *)(*(char * *)&((struct Obj06650 *)p)->f0))->f10);
    t = func_02045EC0(bank, ((struct Obj25165 *)elem)->f18);
    f = ((struct Obj06650 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(((struct Obj06650 *)p)->f1F80), 0, 0, t, ((struct Obj25166 *)(*(char * *)&((struct Obj06650 *)p)->f0))->fC, 0x2120);
    ((struct Obj06650 *)p)->f1F84 = 1;
    func_02045808(t);
    func_02045C04(bank);
}









void func_0220D034(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj10842 *)p)->f1EA0, 0x3D);
    f = ((struct Obj10842 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct Obj25167 *)(*(char * *)&((struct Obj10842 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}










void func_0220D090(char *p, int a1, int a2)
{
    u32 handle;
    void *t;
    u16 w;

    handle = *(u32 *)(p + 0x1f70 + a1 * 8);
    if (a2 == 0) {
        u32 f;

        t = func_02045EC0(((struct Obj02533 *)p)->f1EA0, 0x3c);
        w = func_0201D304((struct StrObj *)((u32)t), *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0);
        w = (func_02045738((void *)handle) << 3) - w;
        f = ((struct Obj02533 *)p)->f1EAC;
        func_0201C724((void *)f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), w, 0,
                      t, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t);
    } else {
        void *t2;
        u32 h;
        u32 f;
        u16 w0;
        u16 w2;

        t2 = func_02045EC0(((struct Obj02533 *)p)->f1EA0, 0x3e);
        h = (u32)func_020457B0(8, *(u16 *)(((struct Obj02533 *)p)->f0 + 0x10));
        func_0201EFA4(((struct Obj02533 *)p)->f1EA4, 0, a2, 3, 0, 1);
        func_0201F250(((struct Obj02533 *)p)->f1EA4, (void *)h, t2);
        w0 = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0);
        w2 = (func_02045738((void *)handle) << 3) - w0;
        f = ((struct Obj02533 *)p)->f1EAC;
        func_0201C724((void *)f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), w2, 0,
                      (void *)h, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t2);
        func_02045808((void *)h);
    }
}









void func_0220D1BC(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj10843 *)p)->f1EA0, 0x3A);
    f = ((struct Obj10843 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct Obj25168 *)(*(char * *)&((struct Obj10843 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}










void func_0220D218(char *p, int a1, u32 a2)
{
    u32 handle;
    void *t;
    u16 w;

    handle = *(u32 *)(p + 0x1f70 + a1 * 8);
    if (a2 <= 1) {
        u32 f;

        t = func_02045EC0(((struct Obj02534 *)p)->f1EA0, 0x3c);
        w = func_0201D304((struct StrObj *)((u32)t), *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0);
        w = (func_02045738((void *)handle) << 3) - w;
        f = ((struct Obj02534 *)p)->f1EAC;
        func_0201C724((void *)f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), w, 0,
                      t, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t);
    } else {
        void *t2;
        u32 h;
        u32 f;
        u16 w0;
        u16 w2;

        t2 = func_02045EC0(((struct Obj02534 *)p)->f1EA0, 0x3b);
        h = (u32)func_020457B0(8, *(u16 *)(((struct Obj02534 *)p)->f0 + 0x10));
        func_0201EFA4(((struct Obj02534 *)p)->f1EA4, 0, a2, 3, 0, 1);
        func_0201F250(((struct Obj02534 *)p)->f1EA4, (void *)h, t2);
        w0 = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0);
        w2 = (func_02045738((void *)handle) << 3) - w0;
        f = ((struct Obj02534 *)p)->f1EAC;
        func_0201C724((void *)f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), w2, 0,
                      (void *)h, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t2);
        func_02045808((void *)h);
    }
}









void func_0220D348(char *p, int i, int id)
{
    void *bank;
    void *t;
    void *f;
    bank = func_02045B38(0, 2, 0xCA, ((struct Obj25169 *)(*(char * *)&((struct Obj10844 *)p)->f0))->f10);
    t = func_02045EC0(bank, id);
    f = ((struct Obj10844 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct Obj25170 *)(*(char * *)&((struct Obj10844 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
    func_02045C04(bank);
}









void func_0220D3B4(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj08359 *)p)->f1EA0, 0x3F);
    func_0201D304(t, ((struct Obj25171 *)(*(char * *)&((struct Obj08359 *)p)->f0))->fC, 0);
    f = ((struct Obj08359 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, t, ((struct Obj25172 *)(*(char * *)&((struct Obj08359 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}









/*
 * note: the switch has no default; a selector outside 0..2 branches from
 *   0220D42C straight to the print tail with r7 (t) never assigned, as the
 *   image does. The earlier `default: return;` spelling was a guard the
 *   original lacks.
 */
void func_0220D418(char *p, int i, int selector)
{
    struct U16Vec *t;
    void *f;
    switch (selector) {
    case 0: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x41); break;
    case 1: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x40); break;
    case 2: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x42); break;
    }
    f = *(void **)(p + 0x1EAC);
    func_0201C724(f, (u32)func_02045770(*(struct Descriptor **)(p + 0x1F70 + i * 8)), 0, 0, t, *(u32 *)(*(char **)p + 12), 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}










/*
 * Near miss: the body is byte-for-byte right in shape; the residue is pure
 * register allocation / frame packing. The original keeps `handle` in r7
 * (used only for the 45738 call, then r7 is recycled by the shifted coordinate)
 * with `base` in [sp+0x1c] and `off` in r6, and packs the frame as
 * push {r3,r4,r5,r6,r7,lr} / sub sp,#0x40.  Naming base/off or inlining the
 * array, splitting f/y per block, and hoisting handle all leave the allocator
 * choosing a different split (5-reg push + #0x44) and one extra instruction.
 * Needs a different spelling of the three draw blocks; not an evidence problem.
 *
 * Re-verified (DIFF fixer): still 391 concrete bytes; all 15 relocations
 * resolve, so it is a frame-packing/allocation residue, not evidence.
 */
void func_0220D494(u8 *p, int slot, int a2, int a3)
{
    u8 *tab;
    void *handle;
    void *text;
    u32 w1;
    u32 x;
    u32 ctx1;
    u8 *fl;
    void *text2;
    void *h2;
    u32 w2;
    u32 ctx2;
    void *text3;
    void *h3;
    u32 ctx3;

    slot = slot * 8;
    tab = p + 0x1F70;
    handle = *(void **)(tab + slot);
    text = func_02045EC0(P->f1EA0, 0x38);
    w1 = func_0201D304(text, P->hdr->font, 0);
    x = ((func_02045738(handle) << 3) - w1) >> 1;
    ctx1 = P->f1EAC;
    func_0201C724((void *)ctx1, (u32)func_02045770(*(void **)(tab + slot)), x, 0, text, P->hdr->font, (u32)0x3DC0);
    fl = p + 0x1F74;
    fl[slot] = 1;
    func_02045808(text);
    text2 = func_02045EC0(P->f1EA0, 0x36);
    h2 = func_020457B0(6, P->hdr->f10);
    func_0201EFA4(P->f1EA4, 0, a2, 3, 0, 1);
    func_0201F250(P->f1EA4, h2, text2);
    w2 = func_0201D304(h2, P->hdr->font, 0);
    ctx2 = P->f1EAC;
    func_0201C724((void *)ctx2, (u32)func_02045770(*(void **)(tab + slot)), (x - w2), 0, h2, P->hdr->font, (u32)0x3DC0);
    fl[slot] = 1;
    func_02045808(text2);
    func_02045808(h2);
    text3 = func_02045EC0(P->f1EA0, 0x37);
    h3 = func_020457B0(6, P->hdr->f10);
    func_0201EFA4(P->f1EA4, 0, a3, 3, 0, 1);
    func_0201F250(P->f1EA4, h3, text3);
    ctx3 = P->f1EAC;
    func_0201C724((void *)ctx3, (u32)func_02045770(*(void **)(tab + slot)), (x + w1), 0, h3, P->hdr->font, (u32)0x3DC0);
    fl[slot] = 1;
    func_02045808(text3);
    func_02045808(h3);
}









void func_0220D628(char *p, int i)
{
    void *t;
    void *f;
    u32 width;
    if (((struct Obj25173 *)(*(char * *)&((struct Obj05524 *)p)->f0))->f4B == 4)
        t = func_02045EC0(((struct Obj05524 *)p)->f1EA0, 0x45);
    else
        t = func_02045EC0(((struct Obj05524 *)p)->f1EA0, 0x44);
    width = func_0201D304(t, ((struct Obj25174 *)(*(char * *)&((struct Obj05524 *)p)->f0))->fC, 0);
    f = ((struct Obj05524 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), ((96 - width) >> 1), 5, t, ((struct Obj25175 *)(*(char * *)&((struct Obj05524 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}









void func_0220D6AC(u8 *p){void *s=func_02045EC0(*(struct MsgBank * *)&((struct Obj02247 *)p)->f1EA0,70);func_0201F250(*(struct WordSet * *)&((struct Obj02247 *)p)->f1EA4,((struct Obj02247 *)p)->f1EA8,s);func_02045808(s);func_0220E13C(p);}









void func_0220D6DC(char *p,u8 *record,int slot)
{
    void *buf;
    void *text;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    buf=func_020457B0(6,((struct Obj25176 *)(*(char * *)&((struct Obj01077 *)p)->f0))->f10);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x35);
    context=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),40,24,text,((struct Obj25177 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x38);
    width=func_0201D304(text,((struct Obj25178 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0);
    secondContext=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(secondContext,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),80,24,text,((struct Obj25179 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x37);
    func_0201EFA4(((struct Obj01077 *)p)->f1EA4,0,record[3],2,0,1);
    func_0201F250(((struct Obj01077 *)p)->f1EA4,buf,text);
    context=((struct Obj01077 *)p)->f1EAC;
    width+=80;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),width,24,buf,((struct Obj25180 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x36);
    func_0201EFA4(((struct Obj01077 *)p)->f1EA4,0,record[2],2,0,1);
    func_0201F250(((struct Obj01077 *)p)->f1EA4,buf,text);
    otherWidth=func_0201D304(buf,((struct Obj25181 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0);
    context=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),(80-otherWidth),24,buf,((struct Obj25182 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    func_02045808(buf);
}









void func_0220D884(u8 *p)
{
    s16 i;
    int idx;

    *(void **)(p + 0x253C) = d_02211AFF;
    for (i = 0; i < 6; i++) {
        func_02043B5C((struct CharBuf *)func_02045770(*(struct Descriptor **)(p + i * 8 + 0x1F70)), 0);
        idx = func_022110D4(p, i);
        if (((Rec *)p)[idx].cnt == 0) {
            *(u8 *)(p + i * 8 + 0x1F74) = 1;
        } else {
            func_0220BEB8(p, i, (u16)i, 0x20, 7);
            if (!((Rec *)p)[idx].fl.high) {
                func_0220D920(p, (u8)i);
            }
            if (func_020276C4((int)(((Rec *)p)[idx].obj)) == 8) {
                func_0220D988(p, (u8)i);
            }
        }
    }
}









void func_0220D920(u8 *p, int i)
{
    char *base;
    base = (char *)p + 0x1f70;
    func_02043AF4(func_02045770(*(void **)(base + i * 8)), 92, 32, 24, 8, 0);
    func_02043AF4(func_02045770(*(void **)(base + i * 8)), 64, 24, 64, 8, 0);
    func_0220C16C(p, i, i, 92, 32);
    func_0220C2F8(p, i, i, 64, 24);
}









void func_0220D988(u8 *p,int a){if(((Bits *)(p+(u32)func_022110D4(p,a)*76+0x1b))->high==0)func_0220C0D0(p,a,a,8,32);}












void func_0220D9B4(char *p)
{
    int state, id, i;
    void *obj;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211AF4;
    func_0220BDA0((u8 *)p);
    func_0220DA6C((u8 *)p, (*(u8 **)p)[32]);
    state = func_02210DA8((u8 *)p);
    if (state == 2) id = 26;
    else if (state == 3) id = 27;
    else if (state == 4) id = 28;
    else if (state == 1) id = 29;
    else id = 21;
    func_0220C694(p,1,id);
    i = func_022110D4((u8 *)p, (*(u8 **)p)[32]);
    if (((Flags_0220D9B4 *)(p + i * 76 + 27))->high == 0) {
        func_0220C694(p,2,24);
        func_0220C694(p,3,25);
        return;
    }
    obj = ((struct Obj00507 *)p)->f1F80;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
    obj = ((struct Obj00507 *)p)->f1F88;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
}













static inline u8 center_x(int w)
{
    return w / 2;
}













static inline void put_slot(u8 *p, void *win, void *sel, short x, u32 y, void *h, u16 color)
{
    func_0201C724(win, (u32)func_02045770(sel), x, y, h, *(u32 *)(*(u8 **)p + 0xc), color);
    *(u8 *)(p + 0x1F74) = 1;
}













/*
 * lever: 2026-10-05 (wD9r lane160): three source facts. (1) half is a narrow local: the centre is a static
 *   inline `u8 center_x(int w)` (signed /2) assigned to a `short half`, and t is u8; the put x and the callee x
 *   are short, so half reaches the first call with no s16 conversion and its reload stays below the outgoing
 *   stack stores. (2) The dirty flag store p[0x1F74] = 1 is inside the put helper, which keeps the 0x1EAC base
 *   in r5 across the arms and frees the msg2 arms for cross-jumping. (3) a short (not u8) half takes its
 *   declaration slot 0x18 above the window temps; a u8 half takes the lowest slot. Before: DIFF 153.
 */
void func_0220DA6C(u8 *p, int idx)
{
    void *msg;
    u32 off;
    void *o;
    struct R *rec;
    void *vec;
    u8 t;
    short half;
    void *msg2;
    int a;
    int b;
    u8 *base;
    int n;

    o = *(void **)(p + 0x1F70);
    n = func_022110D4(p, idx);
    base = p + 4;
    off = n * 0x4c;
    rec = (struct R *)(base + off);
    vec = func_020457B0(12, *(u16 *)(*(u8 **)p + 0x10));
    msg = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), d_02211B68[idx]);
    func_0201EEF4(*(struct WordSet **)(p + 0x1EA4), 0, *(void **)rec);
    msg2 = 0;
    func_0201F250(*(struct WordSet **)(p + 0x1EA4), vec, msg);
    func_02045808(msg);
    if (!rec->a1 && !rec->b2) {
        if (rec->b0 == 0) {
            msg2 = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x16);
        } else if (rec->b0 == 1) {
            msg2 = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x17);
        }
    }
    a = 0;
    t = func_0201D304(vec, *(u32 *)(*(u8 **)p + 0xc), 0);
    if (msg2 == 0) {
        b = 0;
    } else {
        a = (u8)func_0201D304(msg2, *(u32 *)(*(u8 **)p + 0xc), a);
        b = 8;
    }
    half = center_x(func_02045738(o) * 8 - t - a - b);
    put_slot(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), half, 7, vec, 0x3DC0);
    func_02045808(vec);
    if (msg2 != 0) {
        if (rec->b0 == 0) {
            put_slot(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), b + (half + t), 8, msg2, 0x2960);
        } else {
            put_slot(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), b + (half + t), 8, msg2, 0x31A0);
        }
        func_02045808(msg2);
    }
}












void func_0220DC04(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211B06;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + func_022110D4((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            func_0220C4DC((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC((char *)p,(u8 *)(rec+offset),i+1);
        }
    }
    func_0220C694((char *)p,5,24);
}












void func_0220DCA8(char *p) {
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B50;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    func_0220CDF0((u8 *)p,(*(u8 **)p)[32]);
    func_0220C2F8((u8 *)p,10,(*(u8 **)p)[32],0,0);
    func_02045334(((struct Obj00507 *)p)->f1FC0);
    func_0220C714((u8 *)p,(*(u8 **)p)[32]);
    func_0220C8F0(p,(*(u8 **)p)[32]);
    func_0220C9F0(p,(*(u8 **)p)[32]);
    func_0220CAF0(p,(*(u8 **)p)[32]);
    func_0220CBF0(p,(*(u8 **)p)[32]);
    func_0220CCF0(p,(*(u8 **)p)[32]);
    func_0220C398((u8 *)p,1,(*(u8 **)p)[32]);
    func_0220C42C(p,3,(*(u8 **)p)[32]);
    func_0220CFC4(p,(*(u8 **)p)[32]);
    func_0220C694(p,21,25);
}












void func_0220DD78(char *p) {
    u8 *owner;
    char *base,*rec;
    unsigned offset;
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B20;
    func_0220BDA0((u8 *)p);
    owner=*(u8 * *)&((struct Obj00507 *)p)->f0;
    base=p+0x30+func_022110D4((u8 *)p,owner[32])*76;
    offset=owner[0x4b]*8;
    rec=base+offset;
    func_0220BEB8((u8 *)p,6,owner[32],0,0);
    func_0220C5AC(p,7,0,0);
    func_0220C4DC(p,*(u16 *)(base+offset),0,d_02211B3C[(*(u8 **)p)[0x4b]],0,0,0x3dc0);
    func_0220D034(p,8);
    func_0220D090(p,2,(u8)rec[6]);
    func_0220D1BC(p,9);
    func_0220D218(p,3,(u8)rec[7]);
    func_0220D348(p,4,*(u16 *)(base+offset));
    func_0220D3B4(p,10);
    func_0220D418(p,5,(u8)rec[5]);
    func_0220D494((u8 *)p,1,(u8)rec[2],(u8)rec[3]);
}












void func_0220DE4C(char *p) {
    long i;
    int offset;
    char *base,*rec;
    u16 value;
    u8 local[8];
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B0D;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base=p+0x30;
    for(i=0;i<4u;i++) {
        offset=i*8;
        value=((u16 *)(rec=base+func_022110D4((u8 *)p,(*(u8 **)p)[32])*76))[i*4];
        if(value==0) *(u8 *)(p+offset+0x1f7c)=1;
        else {
            func_0220C4DC(p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC(p,(u8 *)(rec+offset),i+1);
        }
    }
    func_0220C4DC(p,((struct Obj25183 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5,0x53,65535,7,0x3dc0);
    local[2]=sub_0201BD28(((struct Obj25184 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5);
    local[3]=local[2];
    func_0220D6DC(p,(u8 *)local,5);
}












void func_0220DF20(char *p) {
    unsigned index,offset,type;
    char *base,*rec;
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B2C;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    func_0220C5AC(p,2,0,0);
    func_0220D034(p,4);
    func_0220D1BC(p,5);
    func_0220D3B4(p,9);
    index=(*(u8 **)p)[0x4b];
    if(index<4) {
        base=p+0x30+func_022110D4((u8 *)p,(*(u8 **)p)[32])*76;
        offset=index*8;
        rec=base+offset;
        func_0220C4DC(p,*(u16 *)(base+offset),1,d_02211B3C[index],0,0,0x3dc0);
        func_0220D090(p,6,(u8)rec[6]);
        func_0220D218(p,7,(u8)rec[7]);
        func_0220D348(p,8,*(u16 *)(base+offset));
        func_0220D418(p,10,(u8)rec[5]);
        func_0220D494((u8 *)p,3,(u8)rec[2],(u8)rec[3]);
    } else {
        type=sub_0201BD28(((struct Obj25185 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5);
        func_0220C4DC(p,((struct Obj25186 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,1,0x53,0,0,0x3dc0);
        func_0220D348(p,8,((struct Obj25187 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26);
        if(sub_0201C1F4(((struct Obj25188 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26)==1) func_0220D090(p,6,0);
        else func_0220D090(p,6,sub_0201BD28(((struct Obj25189 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,4));
        func_0220D218(p,7,sub_0201BD28(((struct Obj25190 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,3));
        func_0220D418(p,10,sub_0201BD28(((struct Obj25191 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,2));
        func_0220D494((u8 *)p,3,type,type);
    }
    func_0220D628(p,11);
}












void func_0220E088(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211AF9;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + func_022110D4((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            func_0220C4DC((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC((char *)p,(u8 *)(rec+offset),i+1);
        }
    }
    if (func_02020FE4((void *)(((struct Obj25192 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f24),40,((struct Obj25193 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f10) == 0)
        func_0220C60C((char *)p,104);
}












void func_0220E13C(u8 *p){func_0201F73C(((struct Obj02247 *)p)->f1F68,2,1,14);func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj02247 *)p)->f1F68),15);func_0220E168((char *)p);}












/*
 * volatile: global pointer re-read at 0220E17C and 0220E196 before func_0201CCE4.
 */
void func_0220E168(char *p)
{
    int v;
    void *obj;
    v = func_02012FFC(func_0201DD78(1,2,0));
    ((struct Obj02247 *)p)->f1EB0 = func_0201CCE4(*(unsigned *)&((struct Obj02247 *)p)->f1F68,0,0,*(unsigned *)&((struct Obj02247 *)p)->f1EA8,((struct Obj25194 *)(((Context *)p)->global))->fC,v,((struct Obj02247 *)p)->f1D4,10,((struct Obj25195 *)(((Context *)p)->global))->f10,15);
    obj = ((struct Obj02247 *)p)->f1F68;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
}












/*
 * lever: the row pointer p + 4 + idx * 0x4c is one statement before the
 *   func_02045EC0 allocation, so p + 4 (r6) and idx * 0x4c (r7) stay live
 *   across it and the allocation result spills to [sp]; computing the row
 *   address only at its use (the earlier note's base + i) left t in r7 and
 *   rematerialised p + 4 after the call (DIFF 16).
 */
void func_0220E1D4(u8 *p)
{
    u8 *row;
    void *t;
    row = p + 4 + func_022110D4(p, (*(u8 **)p)[32]) * 0x4c;
    t = func_02045EC0(*(struct MsgBank **)(p + 0x1ea0), 105);
    func_0201EEF4(*(struct WordSet **)(p + 0x1ea4), 0, *(void **)row);
    func_0201EF34(*(struct WordSet **)(p + 0x1ea4), 1, 373);
    func_0201F250(*(struct WordSet **)(p + 0x1ea4), *(void **)(p + 0x1ea8), t);
    func_02045808(t);
}












/*
 * evidence: enum offset k retained across the call; j saves k+0x10 before k-=0xb4. Parenthesised offsets and the sequenced local match the 48-byte original.
 */
void func_0220E22C(u8 *p){enum{K=0x1f60}k=K;u32 j;func_0220B0B0((struct Entry *)(p+k),*(int *)(p+(k-0xb4)),2);j=k+0x10;k-=0xb4;func_0220B0B0((struct Entry *)(p+j),*(int *)(p+k),p[0x2174]);}












void func_0220E25C(u8 *p){func_0220B094((char *)p+0x1f70,*(u8 * *)&((struct Obj03351 *)p)->f253C);func_0220E27C(p);}












void func_0220E27C(u8 *p){if(((Bits4 *)(p+0x2177))->hi==1){func_0201F73C(((struct Obj25197 *)p)->f1F60,2,1,14);func_0220B07C(p+0x1f60);((Bits4 *)(p+0x2177))->hi=0;}}












/*
 * extent: 0220E2F6 alignment padding.
 */
void func_0220E2B4(char *p)
{
    func_0220E2F8(p);
    func_0220E340((u8 *)p);
    func_0220E3F0(p);
    func_0220E518(p);
    func_0220E460(p);
    func_0220E584(p);
    func_0220E5FC(p);
    func_0220E6E0(p);
    func_0220F1F4((u8 *)p);
    func_02043598(16, 1);
}












void func_0220E2F8(char *p)
{
    unsigned int i;
    for (i = 0; i < 26; i++) *(int *)(p + i * 4 + 0x24a4) = -1;
    for (i = 0; i < 6; i++) *(int *)(p + i * 4 + 0x250c) = -1;
    for (i = 0; i < 6; i++) *(int *)(p + i * 4 + 0x2524) = -1;
}













/*
 * pass 2 2026-10-06 P2L21: EXACT (was 9 bytes off, arc/arr r6/r7 swap). Closing form: the A6C8 call and the
 *   array store written in each if/else arm, with the store address as integer arithmetic
 *   `*(int *)((u32)p + 0x24A4 + i * 4)` (no named array pointer; LICM hoists p + 0x24A4, the ov097 021F6F88
 *   `icons + i * 4` style). Either part alone stays at 9 bytes (named arr in both arms, or the integer
 *   address with one join store). EXACT in --lang c99 and --lang c.
 */
void func_0220E340(u8 *p)
{
    void *arc;
    u16 i;

    arc = func_020490F4(7, (u16)((*(u16 *)(*(u8 **)p + 0x10) & 0x7FFF) | 0x8000));
    for (i = 0; i < 6; i++) {
        u8 *e = p + i * 0x4C;
        if (*(u16 *)(e + 8) != 0) {
            *(int *)((u32)p + 0x24A4 + i * 4) = func_0204A6C8(arc, func_0201BA68(func_020185F4(*(void **)(e + 4))), 0, 1, *(u16 *)(*(u8 **)p + 0x10));
        } else {
            *(int *)((u32)p + 0x24A4 + i * 4) = func_0204A6C8(arc, func_0201BABC(0, 0, 0, 0), 0, 1, *(u16 *)(*(u8 **)p + 0x10));
        }
    }
    *(int *)(p + 0x250C) = func_0204ACEC(arc, func_0201BC3C(), 1, 0, *(u16 *)(*(u8 **)p + 0x10));
    *(s32 *)(p + 0x2524) = func_0204AF28(arc, func_0201BC78(), func_0201BCEC(), *(u16 *)(*(u8 **)p + 0x10));
    func_02049238(arc);
}












void func_0220E3F0(char *p)
{
    void *owner;
    owner = func_020490F4(83,(u16)((((struct Obj25198 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f24BC = func_0204A6C8(owner, 12, 0, 1, ((struct Obj25199 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2510 = func_0204ABF0(owner, 11, 1, 96, ((struct Obj25200 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2528 = func_0204AF28(owner, 13, 16, ((struct Obj25201 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}












void func_0220E460(char *p)
{
    void *owner;
    unsigned i;
    owner = func_020490F4(83,(u16)((((struct Obj25202 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f2518 = func_0204ABF0(owner, 33, 1, 160, ((struct Obj25203 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2530 = func_0204AF28(owner, 59, 62, ((struct Obj25204 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    for (i = 8; i <= 21; i++)
        ((int *)(p + 0x24a4))[i] = func_0204A6C8(owner, func_020275F8(0), 0, 1, ((struct Obj25205 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f24FC = func_0204A6C8(owner, func_02027610(0), 0, 1, ((struct Obj25206 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2500 = func_0204A6C8(owner, func_02027610(0), 0, 1, ((struct Obj25207 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}












void func_0220E518(char *p)
{
    void *owner;
    owner = func_020490F4(83,(u16)((((struct Obj25208 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f24C0 = func_0204A6C8(owner, 65, 0, 1, ((struct Obj25209 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2514 = func_0204ABF0(owner, 66, 1, 128, ((struct Obj25210 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f252C = func_0204AF28(owner, 67, 70, ((struct Obj25211 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}












void func_0220E584(char *p)
{
    void *owner;
    owner=func_020490F4(11,(u16)((((struct Obj25212 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    ((struct Obj00172 *)p)->f2504=func_0204A6C8(owner,119,0,1,((struct Obj25213 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f251C=func_0204AC18(owner,116,1,256,4,1,((struct Obj25214 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2534=func_0204AF28(owner,120,121,((struct Obj25215 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}












void func_0220E5FC(char *p)
{
    void *owner;
    int first;
    owner=func_020490F4(func_020275E4(),(u16)((((struct Obj25216 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    ((struct Obj00172 *)p)->f2508=func_0204A6C8(owner,func_0202775C(0),0,1,((struct Obj25217 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2520=func_0204ABF0(owner,func_02027758(),1,0x120,((struct Obj25218 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    first=func_02027760(0);
    ((struct Obj00172 *)p)->f2538=func_0204AF28(owner,first,func_02027764(0),((struct Obj25219 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}












unsigned func_0220E684(char *p,const int *q)
{
    Point point;
    point.x=0;
    point.y=0;
    point.z=0;
    point.a=q[4];
    point.b=q[3];
    return (unsigned)func_0204B294((void *)((struct Obj00172 *)p)->f1EB8,*(unsigned *)(p+q[0]*4+0x24a4),*(unsigned *)(p+q[1]*4+0x250c),*(unsigned *)(p+q[2]*4+0x2524),&point,1,((struct Obj25220 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
}












void func_0220E6E0(char *p)
{
    unsigned i;
    ((struct Obj00172 *)p)->f1EB8=(unsigned int)func_0204B100((unsigned)45,(unsigned)0,(u16)((((struct Obj25221 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    for(i=0;i<41;i++) *(unsigned *)(p+i*4+0x1ebc)=func_0220E684(p,d_02211DFC[i]);
    func_0203D34C(0,((struct Obj25222 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_020216D4((struct PalAnmSlot *)(((struct Obj00172 *)p)->f1D8),(int)3,(int)0,(int)0x1e0);
    func_0220E7E4((Record_0220D9B4 *)p);
}












void func_0220E74C(char *p)
{
    unsigned i;
    for(i=0;i<41;i++) func_0204B3B4(*(void **)(p+i*4+0x1ebc));
    func_0220AFC4(((struct Obj14559 *)p)->f2188);
    for(i=0;i<26;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x24a4)));
    for(i=0;i<6;i++) func_0204ADA4((u32)(*(void **)(p+i*4+0x250c)));
    for(i=0;i<6;i++) func_0204AFD8((u32)(*(void **)(p+i*4+0x2524)));
    func_0204B1CC(((struct Obj14559 *)p)->f1EB8);
}












/*
 * Addresses are Black-image addresses.
 */
void func_0220E7CC(u8 *p, u32 b)
{
    func_0204B3DC((struct Obj *)p, 1);
    func_0204B404((struct Obj *)p, (const struct Vec2 *)b, 1);
}











void func_0220E7E4(Record_0220D9B4 *records)
{
    char *p=(char *)records;
    char *flags;
    short i;
    unsigned value;
    i=0;
    flags=p+0x1b;
    for(;i<6;i++) {
        if(records[i].species!=0) {
            value=func_0201BB5C(records[i].species,records[i].form,((Flags_0220E7E4 *)(flags+i*0x4c))->half,((Flags_0220E7E4 *)(flags+i*0x4c))->egg);
            func_0204B6F4(*(void **)(p+i*4+0x1ed8),value,1);
        }
    }
}











/*
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 * typedef unsigned char u8;
 * extern const u8 d_0209FCF8[];
 * unsigned func_020275EC(u8 index){return d_0209FCF8[index];}
 */
void func_0220E82C(char *p,void *obj,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    owner=func_020490F4(83,(u16)((*(u16 *)(*(char **)p+16)&0x7fff)|0x8000));
    data=func_02049E74((void *)((unsigned)owner),func_020275F8((u8)which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    func_0204A9D0(*(unsigned *)(p+index*4+0x24a4),out);
    func_020307B0(data);
    func_02049238(owner);
    func_0204B6F4(obj,(unsigned)func_020275EC((u8)which),1);
}











/*
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 * typedef unsigned char u8;
 * extern const u8 d_0209FCEC[];
 * unsigned func_02027604(u8 index){return d_0209FCEC[index];}
 */
void func_0220E8B4(char *p,int first,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    int toggle;
    toggle=((Flags_0220E8B4 *)(p+0x2175))->flip;
    first+=toggle;
    index+=toggle;
    owner=func_020490F4(83,(u16)((*(u16 *)(*(char **)p+16)&0x7fff)|0x8000));
    data=func_02049E74((void *)((unsigned)owner),func_02027610((u8)which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    func_0204A9D0(*(int *)(p+index*4+0x24a4),out);
    func_020307B0(data);
    func_02049238(owner);
    func_0204B6F4(*(void **)(p+first*4+0x1ebc),(unsigned)func_02027604(which),1);
    ((Flags_0220E8B4 *)(p+0x2175))->flip^=1;
}











void func_0220E974(int mode,u8 *p,const struct Vec2 *q) { if(mode==8)func_0204B404((struct Obj *)p,q,1);else {func_0204B878((struct Obj *)p,mode);func_0220E7CC(p,(u32)q);} }










void func_0220E9A0(char *p,u8 *q,const Pair *pos)
{
    int first,index;
    char *base;
    if(((Flags_0220E9A0 *)(p+0x2175))->flip==0){first=25;index=8;}
    else{first=27;index=10;}
    base=p+0x1ebc;
    func_0220E82C(p,*(void **)(base+first*4),index,q[20]);
    func_0220E7CC(*(u8 **)(base+first*4),(unsigned)pos);
    if(q[20]!=q[21]){
        func_0220E82C(p,*(void **)(p+0x1ebc+(first+1)*4),index+1,q[21]);
        func_0220E7CC(*(u8 **)(p+0x1ebc+(first+1)*4),(unsigned)(pos+1));
    }
    ((Flags_0220E9A0 *)(p+0x2175))->flip^=1;
}










void func_0220EA30(u32 mode,u8 *p,const struct Vec2 *q) { if(mode==0)func_0204B404((struct Obj *)p,q,1);else {if(func_0202136C(mode)==1)func_0204B878((struct Obj *)p,1);else func_0204B878((struct Obj *)p,0);func_0220E7CC(p,(u32)q);} }








void func_0220EA68(char *p,unsigned mode)
{
    unsigned i;
    for(i=0;i<41;i++)func_0204B3DC(*(void **)(p+i*4+0x1ebc),0);
    switch(mode){
    case 0: case 8: func_0220EAF0((Record_0220EAF0 *)p);return;
    case 1: func_0220EBCC((Record_0220EAF0 *)p);return;
    case 2: func_0220EC2C((u8 *)p);return;
    case 3: func_0220ECCC((u8 *)p);return;
    case 4: func_0220ED54((u8 *)p);return;
    case 5: func_0220EFD8((u8 *)p);return;
    case 6: func_0220EE44((u8 *)p);return;
    case 7: func_0220EECC((u8 *)p);return;
    }
}








/*
 * lever: the final pointer-table subscript preserves the unscaled index
 * spill and its fresh shift. Byte-offset pointer arithmetic CSEs that shift.
 */
void func_0220EAF0(Record_0220EAF0 *records) {
    u8 *p=(u8 *)records;
    short i;
    int index,offset;
    Pair pair;
    for(i=0;i<6;i++) {
        index=func_022110D4(p,i);
        offset=index*76;
        if(*(u16 *)((char *)records+offset+8)!=0) {
            func_0220E7CC(*(u8 **)(p+index*4+0x1ed8),(unsigned)&d_02211DB4[i]);
            func_0220E974(((Bits *)(p+0x1b))[offset].kind,*(u8 **)(p+index*4+0x1ef0),(const struct Vec2 *)(&d_02211DCC[i]));
            if(((Bits *)(p+0x1b))[offset].high==0)
                func_0220E7CC(*(u8 **)(p+index*4+0x1f08),(unsigned)&d_02211DE4[i]);
            pair=d_02211DB4[i];
            pair.x+=8;
            pair.y+=8;
            func_0220EA30(*(u16 *)((char *)records+offset+0x1e),((u8 **)(p+0x1ebc))[index],(const struct Vec2 *)(&pair));
        }
    }
}








/*
 * lever: a char cast only on the later resource access prevents CSE of
 * the base-plus-index sum, preserving the byte-offset spill across E7CC.
 */
void func_0220EBCC(Record_0220EAF0 *records)
{
    u8 *p=(u8 *)records;
    int i;
    Pair pair;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    pair=d_02211D34[0];
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(unsigned)&pair);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(p+i*0x4c+0x1e),*(u8 **)((char *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
}





void func_0220EC2C(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[4];
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(unsigned)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[13]));
    func_0220E9A0((char *)p,rec,&d_02211D34[25]);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(((struct Obj14560 *)rec)->f1A,*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    func_0220EA30(((struct Obj14560 *)rec)->f1A,*(u8 * *)&((struct Obj10847 *)p)->f1ED4,(const struct Vec2 *)(&d_02211D34[1]));
    func_0220E7CC(*(u8 * *)&((struct Obj10847 *)p)->f1F08,(unsigned)&d_02211D34[16]);
}




void func_0220ECCC(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i = func_022110D4(p, (*(u8 **)p)[0x20]);
    rec = p + 4 + i * 0x4c;
    pair = d_02211D34[15];
    func_0220E7CC(*(u8 **)(p + i * 4 + 0x1ed8), (u32)&pair);
    func_0220E974(((Bits *)(rec + 0x17))->kind, *(u8 **)((char *)p + i * 4 + 0x1ef0), (const struct Vec2 *)&d_02211D34[14]);
    func_0220E9A0((char *)p, rec, &d_02211D34[17]);
    pair.x += 8;
    pair.y += 8;
    func_0220EA30(*(u16 *)(rec + 0x1a), *(u8 **)((const u8 *)p + i * 4 + 0x1ebc), (const struct Vec2 *)&pair);
    func_0220F060(p);
}




/*
 * note 2026-10-05 (wD6 lane16): EXACT. The 0x1ebc call is written in each arm of the idx if/else (tail-merged), so the
 *   0x1ED8 pool word stays CSE-live into it; the 0x1F58/0x1F5C read is a ternary of two loads; rec + k*8 + 0x31 as pointer adds.
 */
void func_0220ED54(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    int idx;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[12];
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[11]));
    func_0220E9A0((char *)p,rec,&d_02211D34[21]);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    if (((Flag *)(p+0x2175))->bit==0) {
        idx=(*(u8 **)p)[0x4b]+0x22;
        func_0220E7CC(*(u8 **)(p+idx*4+0x1ebc),(u32)&d_02211D34[9]);
    } else {
        idx=(*(u8 **)p)[0x4b]+0x1d;
        func_0220E7CC(*(u8 **)(p+idx*4+0x1ebc),(u32)&d_02211D34[9]);
    }
    func_0220E7CC(((Flag *)(p+0x2175))->high==0?((u8 **)p)[0x7d6]:((u8 **)p)[0x7d7],(u32)&d_02211D34[5]);
    func_0220E8B4((char *)p,0x27,0x16,*(rec+(*(u8 **)p)[0x4b]*8+0x31));
}




/*
 * lever: d_02211D34 is a non-const Pair array (a const one reorders the schedule).
 */
void func_0220EE44(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[7];
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[6]));
    func_0220E9A0((char *)p,rec,&d_02211D34[19]);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    func_0220F060(p);
}


void func_0220EECC(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    unsigned n;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[8];
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[2]));
    func_0220E9A0((char *)p,rec,&d_02211D34[23]);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    if(((Fl *)(p+0x2175))->a==0) func_0220E7CC(*(u8 **)(p+((*(u8 **)p)[0x4b]+0x22)*4+0x1ebc),(u32)&d_02211D34[3]);
    else func_0220E7CC(*(u8 **)(p+((*(u8 **)p)[0x4b]+0x1d)*4+0x1ebc),(u32)&d_02211D34[3]);
    if(((Fl *)(p+0x2175))->b==0) func_0220E7CC(*(u8 **)(p+0x1F58),(u32)&d_02211D34[10]);
    else func_0220E7CC(*(u8 **)(p+0x1F5C),(u32)&d_02211D34[10]);
    n=(*(u8 **)p)[0x4b];
    if(n<4) func_0220E8B4((char *)p,0x27,0x16,(rec+n*8)[0x31]);
    else func_0220E8B4((char *)p,0x27,0x16,func_0201BD28(*(u16 *)(*(u8 **)p+0x26),2));
}

void func_0220EFD8(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34[7];
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D34[6]));
    func_0220E9A0((char *)p,rec,&d_02211D34[19]);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    func_0220F060(p);
}
