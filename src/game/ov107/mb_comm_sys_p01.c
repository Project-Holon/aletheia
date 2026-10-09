/*
 * file:     mb_comm_sys_p01.c
 * unit:     yes
 * function: func_021EE740, func_021EE824, func_021EE894, func_021EEEAC, func_021EEEB4, func_021EEEF8, func_021EEF28, func_021EF080, func_021EF0D0, func_021EF0F4, func_021EF444, func_021EF588, func_021EF74C, func_021EF79C, func_021EF96C, func_021EFA14, func_021EFC10, func_021EFC1C, func_021EFCA8, func_021EFD24, func_021EFD98, func_021EFE3C, func_021EFE40, func_021EFFB0, func_021F05DC, func_021F0608, func_021F0694, func_021F0728, func_021F0754, func_021F080C, func_021F0850, func_021F08E4, func_021F0938, func_021F09B0, func_021F0A28, func_021F0A64, func_021F0AE4, func_021F0B04, func_021F0B2C, func_021F0D1C, func_021F0D28, func_021F0D34, func_021F0DB4, func_021F0DDC, func_021F0DE8, func_021F0E40, func_021F0E6C, func_021F0EFC, func_021F0FE8, func_021F1008, func_021F1010, func_021F1018, func_021F1028, func_021F1040, func_021F1050, func_021F1060, func_021F1064, func_021F10D4, func_021F10DC, func_021F10E4, func_021F10EC, func_021F10F4, func_021F10FC, func_021F1104, func_021F110C, func_021F1110, func_021F1118, func_021F1120, func_021F1134, func_021F1148, func_021F115C, func_021F1164, func_021F116C, func_021F1174, func_021F1184, func_021F11BC, func_021F11C4, func_021F11CC, func_021F11E0, func_021F11F0
 * address:  0x021EE740
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F1404 0x021F1404 thumb ov107
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C1B0 0x0200C1B0 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02005654 0x02005654 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02034F84 0x02034F84 arm
 *   d_021F6EA0 0x021F6EA0 data a4
 *   func_02034FB8 0x02034FB8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0200566C 0x0200566C thumb
 *   func_020370C8 0x020370C8 arm
 *   func_02005D28 0x02005D28 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020143CC 0x020143CC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021F1520 0x021F1520 thumb ov107
 *   func_021F1628 0x021F1628 thumb ov107
 *   func_021F1704 0x021F1704 thumb ov107
 *   func_021F1A58 0x021F1A58 thumb ov107
 *   func_021F1B24 0x021F1B24 thumb ov107
 *   func_021F1B14 0x021F1B14 thumb ov107
 *   func_021F19E4 0x021F19E4 thumb ov107
 *   func_021F1A2C 0x021F1A2C thumb ov107
 *   func_021F1898 0x021F1898 thumb ov107
 *   func_021F1A24 0x021F1A24 thumb ov107
 *   func_021F1370 0x021F1370 thumb ov107
 *   func_021F15B0 0x021F15B0 thumb ov107
 *   func_0203D34C 0x0203D34C arm
 *   func_020461E4 0x020461E4 arm
 *   func_020788AC 0x020788AC arm
 *   func_02078C18 0x02078C18 arm
 *   func_02078B44 0x02078B44 arm
 *   func_02078C28 0x02078C28 arm
 *   func_02078B70 0x02078B70 arm
 *   func_02078A80 0x02078A80 arm
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02012E40 0x02012E40 thumb
 *   func_02012E08 0x02012E08 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0202EB44 0x0202EB44 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_0200C184 0x0200C184 thumb
 *   func_0200575C 0x0200575C thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0201293C 0x0201293C thumb
 *   func_02007774 0x02007774 thumb
 *   d_021F6E08 0x021F6E08 data a4
 *   d_021F6E0C 0x021F6E0C data a4
 *   func_02040618 0x02040618 arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   d_021F6C10 0x021F6C10 data a4
 *   d_021F6B00 0x021F6B00 data a4
 *   d_021F6B50 0x021F6B50 data a4
 *   d_021F6B70 0x021F6B70 data a4
 *   d_021F6B90 0x021F6B90 data a4
 *   d_021F6BB0 0x021F6BB0 data a4
 *   d_021F6BD0 0x021F6BD0 data a4
 *   d_021F6BF0 0x021F6BF0 data a4
 *   d_021F6B10 0x021F6B10 data a4
 *   d_021F6B30 0x021F6B30 data a4
 *   d_020A1448 0x020A1448 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021F1B04 0x021F1B04 thumb ov107
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02012944 0x02012944 thumb
 *   func_021F18D8 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   func_021F1918 0x021F1918 thumb ov107
 *   func_021F1AFC 0x021F1AFC thumb ov107
 *   func_021F1B00 0x021F1B00 thumb ov107
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_020458F8 0x020458F8 arm
 *   func_02045A90 0x02045A90 arm
 *   func_02082A60 0x02082A60 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_020774A0 0x020774A0 arm
 *   ov014_id 0x0000000E data
 *   func_02034A5C 0x02034A5C arm
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02178E84 0x02178E84 thumb ov014
 *   func_02179498 0x02179498 thumb ov014
 *   func_02179158 0x02179158 thumb ov014
 *   func_021790E4 0x021790E4 thumb ov014
 *   func_02037010 0x02037010 arm
 *   func_02037118 0x02037118 arm
 *   func_020351F8 0x020351F8 arm
 *   func_021F18EC 0x021F18EC thumb ov107
 *   func_021F17E0 0x021F17E0 thumb ov107
 *   func_021F1B38 0x021F1B38 thumb ov107
 *   func_0204B878 0x0204B878 arm
 *   func_02179570 0x02179570 thumb ov014
 *   func_0208EE9C 0x0208EE9C arm
 *   func_020370F4 0x020370F4 arm
 *   func_02037154 0x02037154 arm
 *   d_021F6D68 0x021F6D68 data ov107 a4
 *   d_021F6D70 0x021F6D70 data ov107 a4
 *   d_021F6D60 0x021F6D60 data ov107 a4
 *   d_021F6C40 0x021F6C40 data ov107 a4
 *   func_02179024 0x02179024 thumb ov014
 *   func_02082D44 0x02082D44 arm
 *   func_02035C08 0x02035C08 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F1930 0x021F1930 thumb ov107
 *   func_021F19C8 0x021F19C8 thumb ov107
 *   func_021F19B8 0x021F19B8 thumb ov107
 *   d_021F6AF8 0x021F6AF8 data a4
 *   func_0200C1A4 0x0200C1A4 thumb
 *   func_0208459C 0x0208459C arm
 *   func_0200C18C 0x0200C18C thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_0202F27C  0x0202F27C  thumb
 *   func_020074D8  0x020074D8  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_021F1B08 0x021F1B08 thumb ov107
 *   func_020056EC 0x020056EC thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021F1900  0x021F1900  thumb  ov107
 *   func_0201292C  0x0201292C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 *   func_0216BF74  0x0216BF74  thumb  ov010
 *   func_02007E50  0x02007E50  thumb
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_0203630C 0x0203630C arm
 *   func_020124F4 0x020124F4 thumb
 *   func_02012704 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F7B8 0x0200F7B8 thumb
 *   func_0200F83C 0x0200F83C thumb
 *   func_02035544 0x02035544 arm
 *   func_0200FB38 0x0200FB38 thumb
 *   func_02087D28 0x02087D28 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_021F5904 0x021F5904 arm ov107
 *   func_021F5B4C 0x021F5B4C arm ov107
 *   func_021F1B3C 0x021F1B3C arm ov107
 *   d_021F6EB4 0x021F6EB4 data a4
 *   d_021F6E1C 0x021F6E1C data a4
 *   d_021F6EAC 0x021F6EAC data a4
 *   d_021F6E24 0x021F6E24 data a4
 *   func_021F5E7C 0x021F5E7C arm ov107
 *   func_021F2F1C 0x021F2F1C arm ov107
 *   func_021F2FA0 0x021F2FA0 arm ov107
 *   func_021F3544 0x021F3544 arm ov107
 *   func_021F1C30 0x021F1C30 arm ov107
 *   func_021F5FB0 0x021F5FB0 arm ov107
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_021F1BE0 0x021F1BE0 arm ov107
 *   func_021F5F74 0x021F5F74 arm ov107
 *   func_021F1B64 0x021F1B64 arm ov107
 *   func_0203D7FC 0x0203D7FC arm
 *   d_021F6EC8 0x021F6EC8 data a4
 *   d_021F6EDE 0x021F6EDE data a2
 *   d_021F6EDF 0x021F6EDF data a1
 *   d_021F6EE0 0x021F6EE0 data a1
 *   d_021F6EE1 0x021F6EE1 data a1
 *   d_021F6EE2 0x021F6EE2 data a1
 *   d_021F6EE3 0x021F6EE3 data a1
 *   d_021F6EE4 0x021F6EE4 data a2
 *   func_020173E8 0x020173E8 thumb
 *   d_021F6E28 0x021F6E28 data a4
 *   func_0203E6C0 0x0203E6C0 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_020399A8 0x020399A8 arm
 *   func_020399B8 0x020399B8 arm
 *   func_0203D394 0x0203D394 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   request_021F6C94 0x021F6C94 data a4
 *   func_0203CBAC 0x0203CBAC arm
 *   func_0203E5F8 0x0203E5F8 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D01C 0x0203D01C arm
 *   func_0203E758 0x0203E758 arm
 *   func_02017550  0x02017550  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_0203996C  0x0203996C  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */
#include "../../matched/include/Obj00057.h"
#include "../../matched/include/Obj22273.h"
#include "../../matched/include/Obj00979.h"
#include "../../matched/include/Obj22274.h"
#include "../../matched/include/Obj10258.h"
#include "../../matched/include/Obj00072.h"
#include "../../matched/include/Obj22277.h"
#include "../../matched/include/Obj22278.h"
#include "../../matched/include/Obj07994.h"
#include "../../matched/include/Obj22279.h"
#include "../../matched/include/Obj02457.h"
#include "../../matched/include/Obj01529.h"
#include "../../matched/include/Obj13761.h"
#include "../../matched/include/Obj04440.h"
#include "../../matched/include/Obj10259.h"
#include "../../matched/include/Obj22294.h"
#include "../../matched/include/Obj22296.h"
#include "../../matched/include/Obj22298.h"
#include "../../matched/include/Obj22299.h"

#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define O P(12)
#define M P(104)
#define SAVE (*(void **)((u8 *)P(8)+4))
#define PHASE (*(Phase *)(p+32))
#define OBJ (*(void **)(p+0xc))
#define MSG (*(void **)(p+0x68))
#define TARGET (*(u8 **)(*(u8 **)(p+8)+4))
struct Big;
struct Blk34;
struct Object;
struct Work;
struct Node;
struct BigObj;
struct Bits;
struct FSFile;
struct Sub02008C20Obj;
struct DispVram;
struct DispConfig;
struct BgTemplate;
struct Bank;
struct Obj;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct CharBuf;
struct Cfg;
struct Sub0200852CObj;
struct WordSet;
struct Blk37;
struct Mon;
struct Sub02007454Entry;
struct Obj0203159C;
struct S020315D4;
struct OSOwnerInfoEx;
struct Link;
struct Req;
struct Entry;
struct Sav;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { FS_OK=0, FS_ERROR=1 } FSResult;

typedef struct File {
 struct File *next; void *userdata; void *arc; u32 stat;
 void *argument; FSResult error; void *queue[2];
 u8 reserved1[16]; u8 arg[24];
} File;

typedef signed int     s32;

typedef enum { SEEK_SET=0, SEEK_CUR=1, SEEK_END=2 } SeekOrigin;

typedef enum { Phase0=0,Phase33=33 } Phase;

struct Counter { u8 f0; u8 f1; u16 f2; u32 f4; int f8; };

struct Cfg { u32 prefix[4];u16 dimensions[6]; };

struct Placement { u16 x,y,z;u8 f6,f7; };

typedef signed int     s32_021EF444;

typedef signed short s16_021EF444;

struct Work {
    u16 f0;
    u8 pad_2[6];
    u8 **f8;
    u8 pad_c[0x18];
    u8 f24;
    u8 pad_25;
    u8 f26;
    u8 pad_27;
    u8 f28;
    u8 pad_29[7];
    int f30;
    u8 pad_34[0x1c];
    u16 *f50;
    u16 *f54;
    u8 pad_58[0x10];
    u8 *f68;
};

typedef struct { int a,b; } Pair;

typedef struct { int words[15]; } Config;

typedef struct {
    int f00;
    void *f04;
} Ov107Save;

typedef struct {
    unsigned short f00;
    unsigned char pad02[6];
    Ov107Save *f08;
    void *f0C;
    unsigned char pad10[0x18];
    unsigned char f28;
} Ov107Ctx;

typedef struct {
    unsigned short f00;
    unsigned char pad02[6];
    Ov107Save *f08;
    void *f0C;
    unsigned char pad10[0x10];
    int f20;
    unsigned char pad24;
    unsigned char state;
    unsigned char pad26[0xE];
    int f34;
    unsigned char pad38[8];
    int f40;
    int f44;
    int f48;
    unsigned char pad4C[0x1C];
    void *f68;
} Ov107Main;

typedef struct {u8 f00;u8 pad[3];void *f04;} Save;

typedef struct {u16 f00,pad02;u32 f04;Save *f08;u32 f0C,f10,f14,f18;u8 pad1C[160];} Ctx_021F0608;

typedef struct {u16 f00,pad02;u32 f04;Save *f08;u32 f0C,f10,f14,f18;} Ctx_021F0694;

typedef struct {u8 f00,f01,f02,f03;u16 f04[10];u16 f18,f1A;u16 f1C[26];u16 f50,f52;u8 f54;} User;

typedef struct {u8 f00:4;u8 f00hi:4;u8 f01;u16 f02[10];} MBUser;

typedef struct {u32 words[5];} Zero;

struct Masks {
    void *f00;
    void *f04;
    u16 f08;
    u16 f0A;
    u16 f0C;
    u16 f0E;
    u16 f10;
    u16 f12;
    u16 f14;
    int f18;
};

typedef short s16_021F0B04;

typedef signed char s8;

typedef int s32_021F0B04;

typedef struct {u16 f00,f02,f04,f06,f08,f0A,f0C,f0E,f10,f12;} Snapshot;

typedef short s16;

typedef int s32_021F0DB4;

typedef struct {u16 f00,pad02;u32 f04,f08,f0C;void *f10;u32 f14;u16 pad18:11;u16 f18:1;u16 pad19:4;u8 pad1A[14];} Object;

typedef struct {u8 pad[24];unsigned short low:11,flag:1,rest:4;} State_021F0DB4;

typedef struct {u32 f00,f04,f08,f0C;} State_021F0E6C;

typedef struct {
    u32 f00,f04; u8 pad08[0x40]; u32 f48; u8 pad4c[8];
    u16 f54,f56,f58,f5a,f5c,f5e;
    u8 pad60,f61,pad62[3],f65,pad66,f67,pad68[8];
} Request;

typedef struct {
    u16 b00:1,b01:1,b02:1,b03:1,b04:1,b05:1,b06:1,b07:1;
    u16 b08:1,b09:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1;
} Flags;

typedef struct {
    u16 heap; u8 pad02[22]; Flags f18,f1a;
    u8 f1c,pad1d; u16 f1e; u8 f20,pad21[3]; u32 f24;
} State_021F0EFC;

typedef struct {u32 a; u32 f4; u8 pad[16];unsigned short low:11,flag:1,rest:4;} State_021F0FE8;

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags;

typedef struct {
    unsigned char pad00[0xC];
    int f0C;
    unsigned char pad10[8];
    Ov107Flags f18;
    Ov107Flags f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx_021F0DB4;

typedef struct { u8 pad00[0x18]; Flags f18; u16 f1a; u8 f1c; } State_021F1064;

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags_021F116C;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags_021F116C f18;
    Ov107Flags_021F116C f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx_021F116C;

typedef struct {
    unsigned char f00;
    unsigned char pad01;
    unsigned short f02;
} Ov107List;

typedef struct {
    unsigned short b0 : 1;
    unsigned short b1 : 1;
    unsigned short b2 : 1;
    unsigned short rest : 13;
} Ov107Flags_021F1184;

typedef struct {
    unsigned char pad00[0x10];
    Ov107List *f10;
    unsigned char pad14[4];
    Ov107Flags_021F1184 f18;
} Ov107Ctx_021F1184;

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags_021F11BC;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags_021F11BC f18;
    Ov107Flags_021F11BC f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx_021F11BC;

typedef struct {
    unsigned char pad00[0x10];
    unsigned char *f10;
} Ov107Ctx_021F11CC;

struct Bits { unsigned char pad[24]; u16 unused:2; u16 flag:1; u16 rest:13; };

typedef struct {
    unsigned int f00;
    unsigned char f04;
} Ov107Msg;

typedef signed int     s32_021F11F0;

extern struct Work *func_021F1404(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_02012EBC(struct Big *);
extern void *func_0200C0F0(void *);
extern void func_0200C1B0(struct Blk34 *,u32);
extern void *func_020056A0(u32,u32,u32);
extern int func_02005654(int,int);
extern void func_02005D90(u32,u16);
extern void func_02034F84(u32);
extern void func_02034FB8(u32 v);
extern void func_02030EAC(struct Node *n);
extern void func_0200566C(void);
extern void func_020370C8(void);
extern void func_02005D28(void);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020143CC(u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern void func_021F1520(char *p);
extern u8 func_02012E40(const u8 *);
extern void func_02012E08(char *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern int func_0202EB44(void);
extern signed char func_02012FFC(void);
extern void func_02005E30(u32);
extern void func_0203D34C(u32,u32);
extern void func_021F1628(void *,int);
extern void func_021F1704(void *,int,int);
extern void func_021F1A58(char *p, int a);
extern void func_021F1B24(void *,int);
extern int func_021F1B14(void *);
extern int func_021F1A2C(void *);
extern void func_021F19E4(void *,int);
extern void func_021F1898(void *);
extern void func_021F1A24(u8 *p);
extern u32 func_020461E4(int);
extern u32 func_0200C184(struct Blk34 *p);
extern int func_021F1370(void *,void *);
extern void *func_0200575C(u32);
extern void func_020788AC(File *);
extern int func_02078C18(File *,const char *);
extern int func_02078A80(File *);
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern u32 func_02078C28(struct FSFile *a0);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02012F2C(int *p);
extern u32 func_0201293C(const struct BigObj *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_02007774(void *);
extern void *func_021F15B0(void *);
extern void func_0204A600(void *);
extern void func_0204A648(void);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0202223C(u32,u32);
extern u32 func_02022224(void *);
extern void func_020433E0(const struct DispVram *);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern struct Bank *func_0204B100(int,u8,u32);
extern void func_0204B270(struct Bank *);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020403F4(unsigned);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049238(void *);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void func_0204B3DC(struct Obj *,u32);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern unsigned int func_021F1B04(unsigned char *p);
extern void func_0201C7D0(void *,s16_021EF444,s16_021EF444,void *,void *,u16);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02045808(struct U16Vec *);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern u8 *func_02012944(void *p);
extern void func_021F18D8(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_021F1918(unsigned char *a, int b, int c, int d);
extern u32 func_021F1AFC(u8 *p);
extern u32 func_021F1B00(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02082A60(const void *, void *, int);
extern int func_02034AC4(s32_021EF444 handle);
extern void func_020774A0(int (*callback)(void));
extern void func_02034A5C(int);
extern int func_02178E4C(void);
extern int func_02178E84(void);
extern int func_02179498(void);
extern void func_02179158(void);
extern int func_021790E4(u32,int,int);
extern void func_02037010(u32,u32,u32,u32);
extern void func_02037118(u32,u32);
extern void func_020351F8(u32 a, u32 b);
extern void func_021F18EC(void *);
extern void func_021F17E0(void *,int);
extern void func_021F1B38(u8 *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_02179570(void (*cb)(int));
extern int func_0208EE9C(void);
extern u32 func_020370F4(u32);
extern void func_02037154(void);
extern u16 func_02179024(void);
extern void func_02082D44(const void *,void *,unsigned);
extern int func_02035C08(const void *);
extern int func_021F19C8(unsigned char *a);
extern u32 func_020362DC(void);
extern void func_0204B92C(struct Obj *,u32);
extern void func_020061E4(u32);
extern void func_021F1930(char *p, int kind);
extern void func_021F19B8(unsigned char *a);
extern u8 func_0200C1A4(struct Blk34 *p);
extern void func_0208459C(int clear, u32 irqFlags);
extern void func_0200C18C(struct Blk34 *p, u32 v);
void *func_0200CA1C(void *);
u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
void func_0202F27C(void *);
int func_020074D8(void **save, const struct Sub02007454Entry *src);
void *func_0201747C(struct Mon *p, u32 heap);
void func_0200CDE0(struct Blk37 *p, void *m);
extern int func_021F1B08(void *);
extern u32 func_020056EC(u32);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
void func_021F1900(void *, int, int, int);
void *func_0201292C(const struct BigObj *p);
void *func_02012F08(int *p);
int func_0216BF9C(void *, int, void *);
void func_0216BF74(void *, int, void *);
u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern void func_02043534(int);
extern void func_020435F4(int);
extern int func_0203CDBC(void);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern unsigned int func_0203630C(void);
extern void *func_020124F4(u16);
extern void func_02012704(unsigned char *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern u32 func_0200FB24(void);
extern int func_0200FBB0(void);
extern void func_0200F7B8(int);
extern void func_0200F83C(void);
extern void func_02035544(int);
extern void func_0200FB38(void);
extern void func_02087D28(struct OSOwnerInfoEx *info);
extern void *func_0203D7C8(u32,u32,const char *,u16);
extern int func_021F5904(void *,MBUser *,int,int,u16);
extern int func_021F5B4C(u16,u16);
extern void func_021F1B3C(void (*)(u16,u32,u8 *));
extern int func_021F5E7C(int);
extern u32 func_021F2F1C(void *);
extern int func_021F2FA0(void *,void *,u32);
extern int func_021F3544(void *,void *);
extern int func_021F1C30(u16,int);
extern void func_021F5FB0(u16);
extern u32 func_02087988(void);
extern u32 func_0208799C(u32);
extern int func_021F1BE0(u16);
extern void func_021F5F74(void);
extern void *func_021F1B64(u16);
extern void func_0203D7FC(void *);
extern u32 func_020173E8(void);
extern void func_0203E6C0(void);
extern int func_02039ACC(void);
extern void *func_020399A8(void);
extern int func_020399B8(void *);
extern int func_0203D394(void *);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void func_0203D7BC(int);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_0203E5F8(int,int);
extern int func_0203CEAC(int);
extern int func_0203CD98(void);
extern void func_0203D01C(void);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern void func_0203E758(int,int,int,int);
void func_02017550(struct Sav *);
u32 func_0203D378(void);
struct Entry *func_0203996C(s32_021F11F0 idx);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_021EE740(u8 *p);
void func_021EE824(u8 *p);
int func_021EE894(u8 *p);
void func_021EEEAC(void);
void func_021EEEB4(void);
void func_021EEEF8(void);
void func_021EEF28(u8 *p);
void func_021EF080(char *p);
void func_021EF0D0(u32 a,u32 b,u32 c);
void func_021EF0F4(u8 *p);
void func_021EF444(u8 *p);
void func_021EF588(u8 *p);
void func_021EF74C(unsigned char *p);
int func_021EF79C(u8 *p);
void func_021EF96C(u8 *p);
void func_021EFA14(u8 *p);
int func_021EFC10(void);
void func_021EFC1C(u8 *p,int mode);
void func_021EFCA8(u8 *p);
void func_021EFD24(u8 *p);
void func_021EFD98(Ov107Ctx *p);
void func_021EFE3C(u8 *p);
void func_021EFE40(u8 *p);
void func_021EFFB0(Ov107Main *p);
int func_021F05DC(void);
int func_021F0608(void *task,void *arg,Save *save);
int func_021F0694(void *task,int unused,int keep,Ctx_021F0694 *p);
int func_021F0728(int a,int b,int c,u8 *p);
void func_021F0754(int a,int b);
void func_021F080C(void *p,int channel);
int func_021F0850(const char **p);
void func_021F08E4(u16 aid);
void func_021F0938(u16 aid);
void func_021F09B0(u16 aid);
int func_021F0A28(void);
void func_021F0A64(void);
void func_021F0AE4(void);
void func_021F0B04(void);
void func_021F0B2C(u16 aid,u32 event,u8 *p);
void func_021F0D1C(u16 v);
u16 func_021F0D28(void);
int func_021F0D34(u16 aid);
void func_021F0DB4(void);
u32 func_021F0DDC(void);
Object *func_021F0DE8(u16 heap);
void func_021F0E40(State_021F0DB4 *p);
void func_021F0E6C(State_021F0E6C *p);
void func_021F0EFC(State_021F0EFC *p);
void func_021F0FE8(State_021F0FE8 *p);
int func_021F1008(void *p);
int func_021F1010(void *p);
void func_021F1018(u8 *p);
void func_021F1028(int *p);
int func_021F1040(int *p);
int func_021F1050(int *p);
int func_021F1060(Ov107Ctx_021F0DB4 *p);
void func_021F1064(unsigned char *p);
int func_021F10D4(State_021F1064 *p);
int func_021F10DC(State_021F1064 *p);
int func_021F10E4(State_021F1064 *p);
int func_021F10EC(State_021F1064 *p);
int func_021F10F4(State_021F1064 *p);
int func_021F10FC(State_021F1064 *p);
int func_021F1104(State_021F1064 *p);
int func_021F110C(State_021F1064 *p);
int func_021F1110(Ov107Ctx_021F0DB4 *p);
unsigned short func_021F1118(Ov107Ctx_021F0DB4 *p);
unsigned short func_021F1120(Ov107Ctx_021F0DB4 *p);
int func_021F1134(Ov107Ctx_021F0DB4 *p);
int func_021F1148(Ov107Ctx_021F0DB4 *p);
int func_021F115C(Ov107Ctx_021F0DB4 *p);
int func_021F1164(Ov107Ctx_021F0DB4 *p);
int func_021F116C(Ov107Ctx_021F116C *p);
void func_021F1174(int a,int b,int c);
void func_021F1184(Ov107Ctx_021F1184 *p);
int func_021F11BC(Ov107Ctx_021F11BC *p);
u8 func_021F11C4(u8 *p);
void *func_021F11CC(Ov107Ctx_021F11CC *p, int i);
int func_021F11E0(unsigned char *a);
int func_021F11E8(struct Bits *a);
int func_021F11F0(void *p, unsigned char kind, unsigned int val);
extern struct Counter d_021F6EA0;
extern const char d_021F6E08[], d_021F6E0C[];
extern const struct Cfg d_020A1448;
extern const struct DispVram d_021F6C10;
extern struct DispConfig d_021F6B00;
extern const struct BgTemplate d_021F6B50,d_021F6B70,d_021F6B90,d_021F6BB0,d_021F6BD0,d_021F6BF0,d_021F6B10,d_021F6B30;
extern u8 ov014_id[];
extern const Pair d_021F6D68,d_021F6D70,d_021F6D60;
extern const Config d_021F6C40;
extern u8 d_021F6AF8[];
extern const char d_021F6E08[];
extern Zero d_021F6EB4;
extern struct Masks d_021F6EAC;
extern const char d_021F6E1C[], d_021F6E24[];
extern const char d_021F6E1C[];
extern u8 d_021F6EC8[],d_021F6EDE[],d_021F6EDF[],d_021F6EE0[],d_021F6EE1[],d_021F6EE2[],d_021F6EE3[],d_021F6EE4[];
extern const char d_021F6E28[];
extern const Request request_021F6C94;



void func_021EE740(u8 *p) {
 p[0x25]=0;
 ((struct Obj00057 *)p)->f20=0;
 p[0x28]=**(u8 * *)&((struct Obj00057 *)p)->f8;
 func_021EEF28(p);
 func_021EF0F4(p);
 if(!p[0x28]) ((struct Obj00057 *)p)->f68=func_021F1404(((struct Obj00057 *)p)->f0,5,5,72,0,0);
 else ((struct Obj00057 *)p)->f68=func_021F1404(((struct Obj00057 *)p)->f0,1,1,72,0,1);
 ((struct Obj00057 *)p)->fC=func_021F0DE8(((struct Obj00057 *)p)->f0);
 ((struct Obj00057 *)p)->f2C=0;
 ((struct Obj00057 *)p)->f60=0;
 func_021EF444(p);
 if(!p[0x28]) {
  ((struct Obj00057 *)p)->f4C=func_0200C0F0(func_02012EBC(*(struct Big * *)&((struct Obj22273 *)(*(u8 * *)&((struct Obj00057 *)p)->f8))->f4));
  func_0200C1B0(*(struct Blk34 * *)&((struct Obj00057 *)p)->f4C,4);
 } else {
  *(u32 *)&((struct Obj00057 *)p)->f4C=0;
  d_021F6EA0.f2=0;
 }
 ((struct Obj00057 *)p)->f4=func_020056A0((u32)func_021EEEAC,(u32)p,8);
 if(!p[0x28]) func_02005654((int)func_021EEEB4,0);
 else { func_02005654((int)func_021EEEF8,0); func_02005D90(1154,0xffff); }
 ((struct Obj00057 *)p)->f1C=0;
 ((struct Obj00057 *)p)->f44=0;
 ((struct Obj00057 *)p)->f48=0;
 ((struct Obj00057 *)p)->f38=0;
 ((struct Obj00057 *)p)->f3A=0;
 ((struct Obj00057 *)p)->f3C=0;
 func_02034F84(16);
}



void func_021EE824(u8 *p) {
 void *q; u16 *a,*b;
 func_02034FB8(16); func_02030EAC(((struct Obj00979 *)p)->f4);func_0200566C();func_020370C8();
 if(p[40]==1) func_02005D28();
 else { q=(void *)func_0201296C(((struct Obj22274 *)(*(u8 * *)&((struct Obj00979 *)p)->f8))->f4); a=(u16 *)func_020143CC((u32)q,16384);b=(u16 *)func_020143CC((u32)q,16385);*a=((struct Obj00979 *)p)->f38;*b=((struct Obj00979 *)p)->f3A; }
 if(((struct Obj00979 *)p)->f60) func_020307B0(((struct Obj00979 *)p)->f60);
 func_021F0E40(((struct Obj00979 *)p)->fC);func_021F1520(((struct Obj00979 *)p)->f68);func_021EF080((char *)p);
}



static inline void load_payload(u8 *p) {
 File file; void *name;
 name=func_0200575C(142);func_020788AC(&file);
 if(!func_02078C18(&file,name))func_02034714(d_021F6E08,0,d_021F6E08);
 func_02078B44((struct FSFile *)(&file),0,0);W(100)=func_02078C28((struct FSFile *)(&file));
 P(96)=func_02030734(H(0),W(100),1,d_021F6E0C,660);
 func_02078B70((struct FSFile *)(&file),P(96),W(100));
 if(!func_02078A80(&file))func_02034714(d_021F6E08,0,d_021F6E08);
 W(32)=13;
}



int func_021EE894(u8 *p) {
 u32 result;
 func_021F0E6C(O);
 if(W(16)==1 && W(32)!=2 && W(32)!=3) {
  W(24)=func_02012E40(SAVE);
  if(W(24)==1)func_02012E08(SAVE);
  W(32)=2;func_021EFC1C(p,3);
 }
 switch(PHASE) {
 case 0:func_0202208C(0,1,1,0,6,1,H(0));W(32)=1;break;
 case 1:
  if(func_020221A4()==1) {
   if(func_0202EB44()==1){if(p[40]==0)W(32)=7;else W(32)=4;}
   else {func_021F1628(M,5);func_021F1A58(M,func_02012FFC());func_021F1B24(M,1);W(32)=33;}
  }break;
 case 2:
  if(*(u8 *)P(8)==0)func_0202208C(0,0,0,0,6,1,H(0));
  else {func_0202208C(0,0,0,32767,6,1,H(0));func_02005E30(6);}
  W(32)=3;break;
 case 3:if(func_020221A4()==1)return 1;break;
 case 4:func_021F1628(M,5);func_021F1704(M,43,func_02012FFC());W(32)=5;break;
 case 5:if(func_021F1B14(M)==1){func_021F19E4(M,0);W(32)=6;}break;
 case 6:
  result=func_021F1A2C(M);
  if(result==1){W(32)=7;func_021F1898(M);func_021F1A24(M);}
  else if(result==2)W(32)=2;break;
 case 7:func_021EF588(p);W(32)=8;break;
 case 8:if(func_021EF79C(p)==1)W(32)=9;break;
 case 9:
  func_021EF74C(p);
  if(W(48)==1){W(32)=10;H(42)=0;func_021F0EFC(O);if(p[40]==0)func_0203D34C(0,H(0));else func_0203D34C(1,H(0));}
  else W(32)=2;break;
 case 10:if(func_021F1008(O)==1){W(32)=11;func_021F1018(O);}break;
 case 11:
  H(42)++;
  if(H(42)>=1800){func_021EFC1C(p,3);W(32)=30;}
  else if(func_021F1050(O)==1){
   W(88)=func_02012FFC();p[94]=func_020461E4(W(88));
   if(p[40]==0)H(92)=func_0200C184(P(76));
   if(func_021F1370(O,p+88)==1){if(p[40]==0)W(32)=12;else W(32)=32;}
  }break;
 case 12:load_payload(p);break;
 case 13:W(32)=14;break;
 case 14:
  if(func_021F1060(O)==10)goto failure;
  if(func_021F1060(O)==2){
   if(W(44)==0){W(44)=1;func_021F1174((int)O,(int)P(96),W(100));}
   func_021F1704(M,2,func_02012FFC());W(32)=15;
  }break;
 case 15:
  if(func_021F1060(O)==3){func_021F1704(M,3,func_02012FFC());W(32)=16;}
  else if(func_021F1060(O)==13){func_021EFC1C(p,4);func_021F1704(M,8,func_02012FFC());func_021F1028(O);W(32)=28;}
 case 16:
  if(func_021F1060(O)==4){func_021F1184(O);func_021F1704(M,4,func_02012FFC());W(32)=17;}break;
 case 17:
  if(func_021F1060(O)==5){func_02008DF0(func_02012F2C(SAVE),120);H(58)++;W(32)=18;}
  else if(func_021F1060(O)==8){func_02008DF0(func_02012F2C(SAVE),120);H(58)++;func_021EFC1C(p,2);W(32)=23;}
  break;
 case 18:if(func_021F11BC(O)==1 && func_021F11F0(O,0,0)==1)W(32)=19;break;
 case 19:
  if(func_021F11E8(O)==1 || p[40]==1){
   if(func_021F1060(O)==6)W(32)=20;
   else if(func_021F1060(O)==10){
    if(p[40]==0){
failure:func_021EFC1C(p,3);func_021F1704(M,8,func_02012FFC());
fail_tail:func_021F1028(O);W(32)=28;
    }else {func_021F1704(M,38,func_02012FFC());func_021F1B24(M,1);W(32)=26;}
   }
  }break;
 case 20:func_021EFD24(p);W(32)=21;p[36]=9;break;
 case 21:func_021EFE40(p);break;
 case 22:
  func_021EFE3C(p);
  if(p[40]==0){func_021F1704(M,7,func_02012FFC());W(32)=23;}
  else {func_021F1704(M,39,func_02012FFC());func_021F1B24(M,1);W(32)=27;}break;
 case 23:
  if(func_021F1B14(M)==1) {u16 cnt=func_02007774((void *)func_0201293C(SAVE));if(func_021F11F0(O,5,cnt)==1){func_021F1704(M,11,func_02012FFC());W(32)=24;}}break;
 case 24:
  if(func_021F1060(O)==2){func_021F1064(O);W(32)=14;}
  else if(func_021F1060(O)==9 || func_021F1060(O)==10){
   if(func_021F1060(O)==10)func_021EFC1C(p,3);
   func_021F1704(M,8,func_02012FFC());W(32)=27;
  }break;
 case 27:if(func_021F11F0(O,18,0)!=1)break;goto fail_tail;
 case 28:if(func_021F1B14(M)==1 && func_021F1040(O)==1){func_021F0FE8(O);W(32)=29;}break;
 case 29:if(func_021F1010(O)==1){if(p[40]==0)W(32)=2;else W(32)=25;}break;
 case 25:
  if(func_021F1B14(M)==1){func_021F1898(M);func_021F1628(M,1);func_021F1704(M,35,func_02012FFC());func_021F1B24(M,1);W(32)=26;}break;
 case 26:if(func_021F1010(O)==1 && func_021F1B14(M)==1)W(32)=2;break;
 case 30:func_021F1704(M,10,func_02012FFC());func_021F1B24(M,1);W(32)=31;func_021F0FE8(O);break;
 case 31:if(func_021F1B14(M)==1)W(32)=29;
 case 32:func_021EFFB0((Ov107Main *)p);break;
 case 33:if(func_021F1B14(M)==1)W(32)=2;break;
 }
 func_0204A600(func_021F15B0(M));return 0;
}



/*
 * note: Full 8-byte tailstub loads the even ARM target 0204A648; its own matched body takes no inputs.
 */
void func_021EEEAC(void) { func_0204A648(); }


void func_021EEEB4(void) {
 if(d_021F6EA0.f0>1) {
 d_021F6EA0.f0=0;
 func_02040618(3,2,1); func_02040618(3,5,1);
 func_02040618(7,2,1); func_02040618(7,5,1);
 } else d_021F6EA0.f0++;
}





/*
 * volatile: 021EEF02 re-reads counter after 021EEF00 store.
 */
void func_021EEEF8(void) { d_021F6EA0.f2++; if(d_021F6EA0.f2>=5){d_021F6EA0.f2=0;func_02040618(3,5,1);func_02040618(7,5,1);} }




/*
 * volatile: Hardware MMIO read/write at 021EEF3A..021EEF78; display and power registers.
 */
void func_021EEF28(u8 *p) {
 struct Cfg cfg;
 func_020434CC();func_02043588();
 *(volatile u32 *)0x04000000 &= 0xffffe0ff;
 *(volatile u32 *)0x04001000 &= 0xffffe0ff;
 func_0202223C(0,0);func_0202223C(1,0);
 func_02022224((void *)0);func_02022224((void *)1);
 *(volatile u16 *)0x04000050=0;
 *(volatile u16 *)0x04001050=0;
 *(volatile u16 *)0x04000304 |= 0x8000;
 func_020433E0(&d_021F6C10);
 func_0203F8F4(((struct Obj00057 *)p)->f0);func_02045088(((struct Obj00057 *)p)->f0);
 func_0203FC28(&d_021F6B00);
 func_021EF0D0((u32)(&d_021F6B50),0,0);func_021EF0D0((u32)(&d_021F6B70),1,0);
 func_021EF0D0((u32)(&d_021F6B90),2,0);func_021EF0D0((u32)(&d_021F6BB0),3,0);
 func_021EF0D0((u32)(&d_021F6BD0),4,0);func_021EF0D0((u32)(&d_021F6BF0),5,0);
 func_021EF0D0((u32)(&d_021F6B10),6,0);func_021EF0D0((u32)(&d_021F6B30),7,0);
 if(!p[0x28])func_02040588(6,1);else func_02040588(6,0);
 cfg=d_020A1448;cfg.dimensions[0]=64;
 func_0204A48C(&cfg,(u32)&d_021F6C10,((struct Obj00057 *)p)->f0);
 *(struct Bank * *)&((struct Obj00057 *)p)->f6C=func_0204B100(8,0,((struct Obj00057 *)p)->f0);
 func_0204B270(*(struct Bank * *)&((struct Obj00057 *)p)->f6C);
 func_020434DC(16,1);func_02043598(16,1);
}



/*
 * extent: two bytes of alignment padding follow the return.
 */
void func_021EF080(char *p) {
 func_0204B3B4(((struct Obj00979 *)p)->f7C);
 func_0204B1CC(((struct Obj00979 *)p)->f6C);
 func_0204A5AC();
 func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
 func_020403F4(7);func_020403F4(6);func_020403F4(5);func_020403F4(4);
 func_020450C8();func_0203F9B4();
}



void func_021EF0D0(u32 a,u32 b,u32 c) { func_0203FCA0(b,(const struct BgTemplate *)a,c);func_02040588(b,1);func_020414AC(b);func_020409B4(b); }


void func_021EF0F4(u8 *p) {
 void *archive;
 u32 first;
 struct Placement placement;
 if(!p[0x28]) {
 archive=func_020490F4(139,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),1,4,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),5,7,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),9,7,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),4,3,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),8,3,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049BDC((void *)((u32)archive),2,0,288,288,128,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),6,2,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),10,2,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049BDC((void *)((u32)archive),3,0,416,416,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),7,0,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),11,0,0,0,0,((struct Obj00057 *)p)->f0);
 func_020409B4(2);func_02049238(archive);
 } else {
 archive=func_020490F4(34,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),6,4,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),15,7,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),31,7,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),6,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),15,3,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),31,3,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049238(archive);
 archive=func_020490F4(139,((struct Obj00057 *)p)->f0);
 func_02049BDC((void *)((u32)archive),2,4,288,288,128,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),6,5,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),10,5,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049BDC((void *)((u32)archive),3,4,416,416,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),7,4,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),11,4,0,0,0,((struct Obj00057 *)p)->f0);
 func_020409B4(5);func_02040588(5,0);func_02040588(4,0);func_02049238(archive);
 }
 archive=func_020490F4(func_020275E4(),((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),func_02027624(),4,256,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),func_02027628(),6,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),func_0202762C(),6,0,0,0,((struct Obj00057 *)p)->f0);
 func_020413B0(6,0,21,32,3,8);func_020409B4(6);
 *(int *)&((struct Obj00057 *)p)->f70=func_0204AC18((void *)((u32)archive),func_02027614(),1,0,0,3,((struct Obj00057 *)p)->f0);
 *(int *)&((struct Obj00057 *)p)->f74=func_0204A6C8((void *)((u32)archive),func_02027618(),0,1,((struct Obj00057 *)p)->f0);
 first=func_0202761C(2);
 *(int *)&((struct Obj00057 *)p)->f78=func_0204AF28((void *)((u32)archive),first,func_02027620(2),((struct Obj00057 *)p)->f0);
 func_02049238(archive);
 placement.x=232;placement.y=168;placement.z=1;placement.f7=0;placement.f6=0;
 *(struct Obj * *)&((struct Obj00057 *)p)->f7C=func_0204B294((void *)*(u32 *)&((struct Obj00057 *)p)->f6C,((struct Obj00057 *)p)->f74,((struct Obj00057 *)p)->f70,((struct Obj00057 *)p)->f78,&placement,1,((struct Obj00057 *)p)->f0);
 if(!p[0x28]) {func_0204B3DC(*(struct Obj * *)&((struct Obj00057 *)p)->f7C,1);return;}
 else {func_0204B3DC(*(struct Obj * *)&((struct Obj00057 *)p)->f7C,0);return;}
}











/*
 * extent: two bytes of alignment padding follow the return.
 */








/*
 * volatile: MMIO palette halfword stores at 021EF56E and 021EF572.
 */
void func_021EF444(u8 *p) {
 u8 bg;
 u32 window;
 void *archive,*text;
 struct MsgBank *bank;
 if(!p[0x28]) {d_021F6EA0.f4=1;bg=4;}
 else {d_021F6EA0.f4=0;bg=2;}
 func_02040588(bg,0);
 archive=func_020490F4(22,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,4,224,32,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,0,224,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),1,bg,0,0,0,((struct Obj00057 *)p)->f0);
 func_020498F4((void *)((u32)archive),2,bg,0,0,0,((struct Obj00057 *)p)->f0);
 func_020413B0(bg,0,0,32,24,7);func_020409B4(bg);func_02049238(archive);
 window=func_020450F0(bg,1,4,30,8,7,1);
 bank=func_02045B38(0,2,0x52,((struct Obj00057 *)p)->f0);
 text=func_02045EC0(bank,1);
 func_02043B5C(func_02045770((struct Descriptor *)window),7);
 func_0201C7D0(func_02045770((struct Descriptor *)window),0,0,text,(void *)func_021F1B04(*(u8 * *)&((struct Obj00057 *)p)->f68),0x1167);
 func_02045334((struct Descriptor *)window);func_02045374((struct Cfg *)window);
 func_020409B4(func_02045730((struct Descriptor *)window));
 func_02045808((struct U16Vec *)text);func_02045C04((struct Rec *)bank);func_020452E8((struct Descriptor *)window);
 *(volatile u16 *)0x05000000=0x7eea;*(volatile u16 *)0x05000400=0x7eea;
}













/*
 * 2026-10-05 (integrator): the fullwidth-to-ASCII constants are plain literals (0xFF29, 0xFF24, 0xFF10..0xFF19, c - 0xFEE0); mwcc derives them from one held value itself, so the earlier `u32 k = 0xFF24` local was not needed. EXACT in c99 and c.
 */
void func_021EF588(u8 *p)
{
    struct Work *w = (struct Work *)p;
    u8 *q;
    struct U16Vec *a;
    struct U16Vec *b;
    void *m;
    u16 la;
    u16 lb;
    int i;
    u16 *dst;
    u16 *src;


    q = func_02012944(w->f8[1]);
    w->f24 = 0;
    w->f26 = 0;
    w->f50 = func_02030734(w->f0, 0x60, 1, d_021F6E0C, 0x553);
    w->f54 = func_02030734(w->f0, 0xC0, 1, d_021F6E0C, 0x554);
    func_021F1628(w->f68, 1);
    func_021F18D8(w->f68);
    func_021F1918(w->f68, 0, func_02008534((const struct Sub0200852CObj *)q), 5);
    if (w->f28 == 0)
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xC);
    else
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xF);
    a = func_020457B0(0x100, w->f0);
    func_0201F250((struct WordSet *)func_021F1B00(w->f68), a, m);
    func_02045808((struct U16Vec *)m);
    if (w->f28 == 0)
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xD);
    else
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0x10);
    b = (struct U16Vec *)m;
    la = (u32)func_020458F8(a);
    lb = (u32)func_020458F8(b);
    dst = w->f50;
    src = func_02045A90(a);
    func_02082A60(src, dst, la * 2);
    dst = w->f54;
    src = func_02045A90(b);
    func_02082A60(src, dst, lb * 2);
    func_02045808(a);
    func_02045808(b);
    w->f50[la] = 0;
    w->f54[lb] = 0;
    for (i = 0; i < 0x60; i++) {
        if (w->f54[i] == 0xFFFE)
            w->f54[i] = 0xA;
    }
    for (i = 0; i < 0x30; i++) {
        u16 c = w->f50[i];
        if (c == 0xFF29)
            w->f50[i] = 0x49;
        else if (c == 0xFF24)
            w->f50[i] = 0x44;
        else if (c >= 0xFF10 && c <= 0xFF19)
            w->f50[i] = c - 0xFEE0;
    }
    w->f30 = 0;
    func_02034AC4((int)ov014_id);
    if (w->f28 == 0) {
        func_02040588(2, 1);
        func_02040588(0, 1);
    } else {
        func_02040588(5, 1);
        func_02040588(4, 1);
    }
    func_020774A0(func_021F05DC);
}












void func_021EF74C(unsigned char *p) {
 func_02034A5C((int)ov014_id);func_020774A0(0);
 func_020307B0(((struct Obj10258 *)p)->f50);func_020307B0(((struct Obj10258 *)p)->f54);
 if(!p[40]) {func_02040588(2,0);func_02040588(0,0);}
 else {func_02040588(5,0);func_02040588(4,0);}
}











int func_021EF79C(u8 *p)
{
 void *q;
 if(func_02178E4C()==9 || func_02178E4C()==10){
  ((struct Obj00072 *)p)->f30=0;((struct Obj00072 *)p)->f14=1;
  if(func_02179498()==1){func_021F0DB4();func_02179158();return 1;}return 0;
 }
 switch(p[0x24]){
 case 0:
  d_021F6EA0.f8=0;((struct Obj00072 *)p)->f1C=1;
  func_021790E4(((struct Obj00072 *)p)->f0,(int)func_021EFC10,0);
  func_02037010(240,0,0,((struct Obj00072 *)p)->f0);
  if(p[0x28]==0)func_02037118(0,((struct Obj00072 *)p)->f0);
  else func_02037118(1,((struct Obj00072 *)p)->f0);
  p[0x24]=1;func_020351F8((u32)func_021EFCA8,(u32)p);break;
 case 1:
  if(func_02178E4C()==1 && func_02178E84()==1)p[0x24]=2;break;
 default:break;
 case 2:
  if(func_02178E4C()==7){
   q=func_02012944(((struct Obj22277 *)(*(u8 * *)&((struct Obj00072 *)p)->f8))->f4);func_021EF96C(p);
   func_021F1898(((struct Obj00072 *)p)->f68);
   if(p[0x28]==0)func_021F1628(((struct Obj00072 *)p)->f68,2);
   else func_021F1628(((struct Obj00072 *)p)->f68,3);
   func_021F18D8(((struct Obj00072 *)p)->f68);func_021F1918(((struct Obj00072 *)p)->f68,0,func_02008534(q),5);
   if(p[0x28]==0)func_021F1704(((struct Obj00072 *)p)->f68,0,func_02012FFC());
   else func_021F1704(((struct Obj00072 *)p)->f68,20,func_02012FFC());
   func_021F18EC(((struct Obj00072 *)p)->f68);p[0x24]=3;
  }break;
 case 3:func_021EFA14(p);break;
 case 4:
  func_021F1898(((struct Obj00072 *)p)->f68);func_021F1628(((struct Obj00072 *)p)->f68,1);
  if(p[0x28]==0)func_021F17E0(((struct Obj00072 *)p)->f68,1);
  else func_021F17E0(((struct Obj00072 *)p)->f68,21);
  func_021F1B38(((struct Obj00072 *)p)->f68,1);func_0204B878(((struct Obj00072 *)p)->f7C,15);p[0x24]=5;break;
 case 5:((struct Obj00072 *)p)->f30=1;p[0x24]=6;break;
 case 8:p[0x24]=6;break;
 case 6:d_021F6EA0.f8=0;func_02179570((void (*)(int))((int (*)(int))func_021EFC10));((struct Obj00072 *)p)->f1C=0;p[0x24]=7;break;
 case 7:if(d_021F6EA0.f8==1){func_020351F8(0,0);func_02179158();return 1;}break;
 }
 func_020370F4(3-func_0208EE9C());func_02037154();return 0;
}











void func_021EF96C(u8 *p) {
 Pair a=d_021F6D68,b=d_021F6D70,c=d_021F6D60;
 Config cfg=d_021F6C40;
 int v=func_02179024();
 func_02082D44(&cfg,p+128,60);
 ((struct Obj00072 *)p)->f80=p[40]==0?a.a:a.b;
 ((struct Obj00072 *)p)->f8C=b.b;((struct Obj00072 *)p)->f90=c.b;
 ((struct Obj00072 *)p)->f84=((struct Obj00072 *)p)->f50;((struct Obj00072 *)p)->f88=((struct Obj00072 *)p)->f54;
 func_021F0754(4992,65536);func_021F080C(p+128,v);
}









/*
 * extent: follower 021EFC10 already has its own matched source/shard.
 * ABI: 19E4 keeps the caller's visibly supplied r1. 0AE4 reads no incoming arguments.
 */
void func_021EFA14(u8 *p)
{
 int a;void *q;
 func_021F0D28();
 switch(func_021F0D28()){
 case 2:
  if(p[0x26]==0){
   a=func_02035C08(d_021F6AF8);
   if(func_020362DC()==2 || (a==0 && p[0x28]==0)){
    p[0x26]=1;func_0204B878(((struct Obj00072 *)p)->f7C,9);func_0204B92C(((struct Obj00072 *)p)->f7C,1);func_020061E4(1361);
   }else if(func_021F0A28()){func_021F0A64();}
  }break;
 case 5:p[0x24]=4;break;
 case 7:func_021F0AE4();break;
 case 0:p[0x24]=8;break;
 case 1:case 3:case 4:case 6:default:break;
 }
 switch(p[0x26]){
 case 1:
  func_021F1898(((struct Obj00072 *)p)->f68);func_0204B878(((struct Obj00072 *)p)->f7C,15);
  if(p[0x28]==0){func_021F1628(((struct Obj00072 *)p)->f68,7);func_021F1704(((struct Obj00072 *)p)->f68,9,func_02012FFC());}
  else {func_021F1628(((struct Obj00072 *)p)->f68,5);func_021F1704(((struct Obj00072 *)p)->f68,42,func_02012FFC());}
  p[0x26]=2;break;
 case 2:
  if(func_021F1B14(((struct Obj00072 *)p)->f68)==1){
   if(p[0x28]==0)func_021F1930(((struct Obj00072 *)p)->f68,0);
   else func_021F19E4(((struct Obj00072 *)p)->f68,0);
   p[0x26]=3;
  }break;
 case 3:
  if(p[0x28]==0)a=func_021F19C8(((struct Obj00072 *)p)->f68);
  else a=func_021F1A2C(((struct Obj00072 *)p)->f68);
  if(a==1){
   if(func_021F0D28()!=2)func_02034714(d_021F6E08,0,d_021F6E08);
   func_021EFC1C(p,4);func_021F0AE4();p[0x26]=4;
  }else if(a==2){
   q=func_02012944(((struct Obj22278 *)(*(u8 * *)&((struct Obj00072 *)p)->f8))->f4);
   if(p[0x28]==0)func_021F19B8(((struct Obj00072 *)p)->f68);else func_021F1A24(((struct Obj00072 *)p)->f68);
   func_021F1898(((struct Obj00072 *)p)->f68);
   if(p[0x28]==0)func_021F1628(((struct Obj00072 *)p)->f68,2);else func_021F1628(((struct Obj00072 *)p)->f68,3);
   func_021F18D8(((struct Obj00072 *)p)->f68);func_021F1918(((struct Obj00072 *)p)->f68,0,func_02008534(q),5);
   func_0204B878(((struct Obj00072 *)p)->f7C,1);
   if(p[0x28]==0)func_021F1704(((struct Obj00072 *)p)->f68,0,func_02012FFC());else func_021F1704(((struct Obj00072 *)p)->f68,20,func_02012FFC());
   func_021F18EC(((struct Obj00072 *)p)->f68);p[0x26]=0;
  }break;
 }
}









int func_021EFC10(void) { d_021F6EA0.f8=1; return 1; }









void func_021EFC1C(u8 *p,int mode) {
 unsigned cur; int change;
 if(p[40]==0) {
 cur=func_0200C1A4(((struct Obj07994 *)p)->f4C);change=0;
 switch(mode) {
 case 0: if(cur!=1&&cur!=3&&cur!=5) change=1;break;
 case 1: if(cur!=3&&cur!=5) change=1;break;
 case 2: if(cur!=0&&cur!=1&&cur!=3&&cur!=5) change=1;break;
 case 3: change=1;if(((struct Obj07994 *)p)->f3C!=0) mode=5;break;
 case 4: if(cur!=2&&cur!=0&&cur!=1&&cur!=3&&cur!=5) change=1;break;
 }
 if(change==1) func_0200C1B0(((struct Obj07994 *)p)->f4C,mode);
 }
}









/*
 * extent: follower 021EFC10 already has its own matched source/shard.
 * ABI: 19E4 keeps the caller's visibly supplied r1. 0AE4 reads no incoming arguments.
 */










void func_021EFCA8(u8 *p) {
 unsigned v=func_021F0DDC();
 if(v==1) func_021F0AE4();
 while(func_021F0D28()!=0&&func_021F0D28()!=5) func_0208459C(1,1);
 if(((struct Obj22279 *)p)->f1C==1) {
 d_021F6EA0.f8=0;
 while(func_02179570((void (*)(int))((int)func_021EFC10))) func_0208459C(1,1);
 while(d_021F6EA0.f8==0) func_0208459C(1,1);
 }
}













/*
 * extent: two bytes of alignment padding after the return.
 */
void func_021EFD24(u8 *p) {
 unsigned v=func_021F11C4(((struct Obj02457 *)p)->fC);
 unsigned old,cur;
 func_021F17E0(((struct Obj02457 *)p)->f68,6);func_021F1B38(((struct Obj02457 *)p)->f68,1);func_021EFD98((Ov107Ctx *)p);
 if(p[40]==0) {
 old=(u16)func_0200C184(((struct Obj02457 *)p)->f4C);cur=func_021F11E0(((struct Obj02457 *)p)->fC);
 if(old<cur) {func_0200C18C(((struct Obj02457 *)p)->f4C,cur);func_021EFC1C(p,1);}
 else if(v==0) func_021EFC1C(p,2);else func_021EFC1C(p,0);
 if(((struct Obj02457 *)p)->f38<cur) ((struct Obj02457 *)p)->f38=cur;
 ((struct Obj02457 *)p)->f3C=((struct Obj02457 *)p)->f3C+v;
 }
}














void func_021EFD98(Ov107Ctx *p)
{
    void *party;
    void *box;
    unsigned int n;
    void *dex;
    void *mon;
    int ok;
    unsigned char i;

    party = (void *)func_0201293C(p->f08->f04);
    box = func_0200CA1C(p->f08->f04);
    n = func_021F11C4(p->f0C);
    if (p->f28 == 0) {
        dex = func_02012F2C(p->f08->f04);
        func_02008DAC(dex, 7, n);
        func_02008DAC(dex, 0x54, n);
    }
    for (i = 0; i < n; i++) {
        mon = func_021F11CC(p->f0C, i);
        func_0202F27C(mon);
        ok = func_020074D8(party, mon);
        mon = func_0201747C(mon, p->f00);
        func_0200CDE0(box, mon);
        func_020307B0(mon);
        if (ok != 1) {
            func_02034714(d_021F6E08, 0, d_021F6E08);
        }
    }
}













void func_021EFE3C(u8 *p) {}












/*
 * evidence: caller-only TU/split was MATCH with nine overlay-only leaves;
 * parent-cleared 60-byte getter unit10D4 and standalone1B08 each verified
 * before unchanged caller re-run EXACT. Case18 is empty; case19 stores22.
 * prototype: own legacy02012DAC has three unused trailing parameters;
 * original supplies only r0; full body forwards only r0 to02012CE0 and
 * no inputs to0201042C, then replaces r0/r1 before remaining calls.
 */
void func_021EFE40(u8 *p)
{
    switch(p[0x24]) {
    case 9:
        if(func_021F1B08(MSG)==1 && func_021F1B14(MSG)==1 && func_021F10D4(OBJ)==1) {
            if(func_021F11F0(OBJ,1,func_020056EC(20)+10)==1) p[0x24]=10;
        }
        break;
    case 10: if(func_021F10F4(OBJ)==1) p[0x24]=11; break;
    case 11: func_02012DAC((int)TARGET); p[0x24]=12; break;
    case 12: if(func_02012DD0(TARGET)==1) p[0x24]=13; break;
    case 13:
        if(func_021F10DC(OBJ)==1 && func_021F11F0(OBJ,2,func_020056EC(20)+10)==1) {
            p[0x24]=14; p[0x27]=0;
        }
        break;
    case 14:
        if(func_021F10FC(OBJ)==1) {
            p[0x27]++;
            if(p[0x27]>(u32)func_021F110C(OBJ)) p[0x24]=15;
        }
        break;
    case 15: if(func_02012DD0(TARGET)==2) p[0x24]=16; break;
    case 16:
        if(func_021F10E4(OBJ)==1 && func_021F11F0(OBJ,3,0)==1) {
            p[0x24]=17; p[0x27]=0;
        }
        break;
    case 17:
        if(func_021F10EC(OBJ)==1 && func_021F11F0(OBJ,4,0)==1) p[0x24]=19;
        break;
    case 18: break;
    case 19: if(func_021F1104(OBJ)==1) ((struct Obj01529 *)p)->f20=22; break;
    }
}













void func_021EFFB0(Ov107Main *p)
{
    int a;
    int b;
    void *c;
    void *d;
    void *e;

    switch (p->state) {
    case 0:
        if (func_021F1060(p->f0C) == 10 || func_021F1060(p->f0C) == 12) {
            func_021F1704(p->f68, 0x29, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F1028(p->f0C);
            p->f20 = 0x1B;
        }
        if (func_021F1060(p->f0C) == 11) {
            func_021F1704(p->f68, 0x2C, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F1028(p->f0C);
            p->f20 = 0x1B;
        }
        if (func_021F1110(p->f0C) == 1) {
            a = func_021F1118(p->f0C);
            b = func_021F1120(p->f0C);
            if (a != 0) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 5);
                func_021F18D8(p->f68);
                func_021F1900(p->f68, 0, a + b, 3);
                func_021F1704(p->f68, 0x16, func_02012FFC());
                func_021F1B24(p->f68, 1);
                func_021F18EC(p->f68);
                p->state = 1;
            } else {
                p->state = 0x13;
            }
        }
        break;
    case 1:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 2;
        }
        break;
    case 2:
        p->f34 = func_021F1A2C(p->f68);
        if (p->f34 == 1) {
            b = func_021F1118(p->f0C);
            a = (unsigned short)func_02007774((void *)func_0201293C(p->f08->f04));
            func_021F1A24(p->f68);
            if ((unsigned int)a < (unsigned int)b) {
                p->f40 = 1;
                p->state = 0xD;
            } else {
                p->f40 = 0;
                p->state = 3;
            }
        } else if (p->f34 == 2) {
            p->state = 0xD;
        }
        break;
    case 3:
        if (func_021F1120(p->f0C) != 0) {
            a = func_021F1118(p->f0C);
            func_021F1898(p->f68);
            func_021F1628(p->f68, 1);
            func_021F18D8(p->f68);
            func_021F1900(p->f68, 0, a, 3);
            func_021F1704(p->f68, 0x24, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F18EC(p->f68);
            p->state = 4;
        } else {
            p->state = 5;
        }
        break;
    case 4:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 5;
        }
        break;
    case 5:
        if (func_021F1134(p->f0C) == 1) {
            func_021F1898(p->f68);
            func_021F1628(p->f68, 5);
            func_021F1704(p->f68, 0x1A, func_02012FFC());
            p->state = 6;
        } else {
            p->state = 0xD;
        }
        break;
    case 6:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 7;
        }
        break;
    case 7:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            if (func_021F1148(p->f0C) == 1) {
                func_021F1704(p->f68, 0x1B, func_02012FFC());
                p->state = 8;
            } else {
                p->state = 0xD;
            }
        } else if (a == 2) {
            p->state = 0xA;
        }
        break;
    case 8:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 9;
        }
        break;
    case 9:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            p->state = 0xD;
        } else if (a == 2) {
            p->state = 0xA;
        }
        break;
    case 10:
        func_021F1704(p->f68, 0x1C, func_02012FFC());
        p->state = 0xB;
        break;
    case 11:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 0xC;
        }
        break;
    case 12:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            p->f34 = 2;
            p->state = 0xD;
        } else if (a == 2) {
            p->state = 5;
        }
        break;
    case 13:
        if (p->f34 == 1) {
            if (p->f40 == 1) {
                a = 2;
            } else {
                a = 0;
            }
        } else {
            a = 1;
        }
        if (func_021F11F0(p->f0C, 0xF, a) == 1) {
            if (a == 0) {
                p->state = 0xE;
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F17E0(p->f68, 0x19);
                func_021F1B38(p->f68, 1);
            } else if (a == 2) {
                p->state = 0x11;
            } else {
                p->state = 0x13;
            }
        }
        break;
    case 14:
        if (func_021F11BC(p->f0C) == 1) {
            func_021EFD98((Ov107Ctx *)p);
            p->state = 0xF;
        }
        if (func_021F115C(p->f0C) == 1) {
            a = func_021F1118(p->f0C);
            func_021F1898(p->f68);
            func_021F1628(p->f68, 1);
            func_021F18D8(p->f68);
            func_021F1900(p->f68, 0, a, 3);
            func_021F1704(p->f68, 0x1E, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F18EC(p->f68);
            p->state = 0x10;
            p->f44 = 1;
        }
        break;
    case 15:
        if (func_021F11F0(p->f0C, 0, 0) == 1) {
            func_021F1184(p->f0C);
            p->state = 0xE;
        }
        break;
    case 16:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x13;
        }
        break;
    case 17:
        func_021F1898(p->f68);
        func_021F1628(p->f68, 5);
        func_021F1704(p->f68, 0x18, func_02012FFC());
        p->state = 0x12;
        break;
    case 18:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x13;
        }
        break;
    case 19:
        if (func_021F1164(p->f0C) == 1) {
            if (func_021F116C(p->f0C) == 1) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 5);
                func_021F1704(p->f68, 0x1F, func_02012FFC());
                p->state = 0x14;
            } else {
                p->state = 0x19;
            }
        }
        break;
    case 20:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x15;
            func_021F19E4(p->f68, 1);
        }
        break;
    case 21:
        a = func_021F1A2C(p->f68);
        if (a == 1 || a == 2) {
            c = func_0201292C(p->f08->f04);
            d = func_02012944(p->f08->f04);
            e = func_02012F08(p->f08->f04);
            if (a == 1 && func_0216BF9C(e, 0, d) == 1) {
                p->f34 = 2;
                p->state = 0x16;
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x25, func_02012FFC());
                func_021F1B24(p->f68, 1);
            } else {
                p->f34 = a;
                p->state = 0x17;
            }
        }
        break;
    case 22:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x17;
        }
        break;
    case 23:
        a = 1;
        if (p->f34 != 1) {
            a = 0;
        }
        if (func_021F11F0(p->f0C, 0x10, a) == 1) {
            if (a == 1) {
                c = func_0201292C(p->f08->f04);
                d = func_02012944(p->f08->f04);
                e = func_02012F08(p->f08->f04);
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x21, func_02012FFC());
                func_021F1B24(p->f68, 1);
                func_0216BF74(e, 0, d);
                func_02007E50(c, 0x215, 1, p->f00);
                p->f48 = 1;
                p->state = 0x18;
            } else {
                p->state = 0x19;
            }
        }
        break;
    case 24:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x19;
        }
        break;
    case 25:
        if (p->f44 == 1 || p->f48 == 1) {
            if (func_021F11F0(p->f0C, 0x11, 0) == 1) {
                p->f20 = 0x13;
            }
        } else {
            if (func_021F1118(p->f0C) == 0 && func_021F116C(p->f0C) == 0) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x28, func_02012FFC());
                func_021F1B24(p->f68, 1);
            }
            p->f20 = 0x1B;
        }
        break;
    }
}












int func_021F05DC(void) { func_02043534(0);func_020435F4(0);func_02040588(d_021F6EA0.f4==1?4:2,1);return 1; }












int func_021F0608(void *task,void *arg,Save *save){Ctx_021F0608 *p;
if(!func_0203CDBC())return 0;
func_0203064C(1,93,0x130000);p=func_0203159C(task,188,93);
if(!save){save=func_02030734(93,8,0,d_021F6E0C,2788);if(func_0203630C()&256)save->f00=1;else{save->f00=0;save->f04=func_020124F4(93);}}
if(save->f00==1)save->f04=func_020124F4(93);
p->f00=93;p->f08=save;p->f10=0;p->f14=0;p->f18=0;func_021EE740((u8 *)p);return 1;}












/*
 * extent: two zero padding bytes follow the epilogue.
 */
int func_021F0694(void *task,int unused,int keep,Ctx_021F0694 *p){int mode;u32 a,b,c;
a=p->f10;mode=0;c=p->f18;b=p->f14;if(p->f08->f00==1)mode=1;func_021EE824((u8 *)p);
if(!keep){func_02012704(p->f08->f04);func_020307B0(p->f08);}else if(p->f08->f00==1){func_02012704(p->f08->f04);func_020307B0(p->f08);}
func_020315D4(task);func_020306F0(93);
if(a==1){if(mode){if(c==1||func_0200FB24()==1){func_0200FBB0();func_0200F7B8(1);}else func_0200F7B8(0);}else if(c==1){func_0200FBB0();func_0200F7B8(1);}}
if(b==1)func_0200F83C();if(mode==1)func_02035544(0);return 1;}











int func_021F0728(int a,int b,int c,u8 *p) { if(func_021EE894(p)==1)return 1;if(func_0200FB24()!=0 && ((struct Obj13761 *)p)->f10==0){func_0200FB38();((struct Obj13761 *)p)->f10=1;}return 0; }











void func_021F0754(int a,int b){User user;MBUser mb;u8 buffer[20];Zero *zero;
func_02087D28((struct OSOwnerInfoEx *)(&user));mb.f00=user.f01;mb.f01=user.f1A;func_02082D44(user.f04,mb.f02,user.f1A*2);mb.f00hi=0;
zero=(Zero *)buffer;zero->words[0]=0;zero->words[1]=0;zero->words[2]=0;zero->words[3]=0;zero->words[4]=0;d_021F6EB4=*zero;
d_021F6EAC.f04=func_0203D7C8(93,45312,d_021F6E1C,158);
if(func_021F5904(d_021F6EAC.f04,&mb,a,b,1))func_02034714(d_021F6E24, 0, d_021F6E24);
func_021F5B4C(256,1);func_021F1B3C(func_021F0B2C);func_021F0D1C(1);}









void func_021F080C(void *p,int channel){
 func_021F0D1C(2);
 if(func_021F5E7C(channel)){func_021F0D1C(7);return;}
 d_021F6EAC.f18=1;
 if(!func_021F0850(p))func_02034714(d_021F6E24,0,d_021F6E24);
}






int func_021F0850(const char **p){File file;File *fp;int result;
result=0;if(!*p)fp=0;else{fp=&file;func_020788AC(fp);if(!func_02078C18(fp,*p))return 0;}
if(func_021F2F1C(fp)){d_021F6EAC.f00=func_02030734(93,65536,1,d_021F6E1C,287);if(d_021F6EAC.f00){if(func_021F2FA0(fp,d_021F6EAC.f00,65536)){if(func_021F3544(p,d_021F6EAC.f00))result=1;}if(!result)func_020307B0(d_021F6EAC.f00);}}
if(fp==&file)func_02078A80(&file);return result;}






void func_021F08E4(u16 aid){
 u16 mask; u32 state;
 if(!func_021F1C30(aid,1)){
 mask=~(1<<aid);state=func_02087988();
 d_021F6EAC.f0A&=mask;
 d_021F6EAC.f0C&=mask;
 d_021F6EAC.f0E&=mask;
 d_021F6EAC.f10&=mask;
 d_021F6EAC.f12&=mask;
 d_021F6EAC.f14&=mask;
 func_0208799C(state);func_021F5FB0(aid);
 }
}







void func_021F0938(u16 aid){u16 mask;u32 state;
if(!func_021F1C30(aid,0)){mask=~(1<<aid);state=func_02087988();d_021F6EAC.f0A&=mask;d_021F6EAC.f0C&=mask;d_021F6EAC.f0E&=mask;d_021F6EAC.f10&=mask;d_021F6EAC.f12&=mask;d_021F6EAC.f14&=mask;func_0208799C(state);func_021F5FB0(aid);}
else {state=func_02087988();d_021F6EAC.f0C&=(u16)~(1<<aid);d_021F6EAC.f0A&=(u16)~(1<<aid);func_0208799C(state);}}







void func_021F09B0(u16 aid){u16 mask;u32 state;u16 bit;
if(!func_021F1C30(aid,2)){mask=~(1<<aid);state=func_02087988();d_021F6EAC.f0A&=mask;d_021F6EAC.f0C&=mask;d_021F6EAC.f0E&=mask;d_021F6EAC.f10&=mask;d_021F6EAC.f12&=mask;d_021F6EAC.f14&=mask;func_0208799C(state);func_021F5FB0(aid);}
else {state=func_02087988();mask=~(1<<aid);bit=1<<aid;d_021F6EAC.f0E&=mask;d_021F6EAC.f10|=bit;func_0208799C(state);}}







int func_021F0A28(void) { u16 i; if(!d_021F6EAC.f0A)return 0;for(i=1;i<16;i++){if(d_021F6EAC.f0A&(1<<i)){if(!func_021F1BE0(i))return 0;}}return 1; }







void func_021F0A64(void){u32 active;u16 aid;int bit;u16 mask;u32 state;
active=0;for(aid=1;aid<16;aid++){bit=1<<aid;if(d_021F6EAC.f12&bit){if(!func_021F1C30(aid,3)){mask=~bit;state=func_02087988();d_021F6EAC.f0A&=mask;d_021F6EAC.f0C&=mask;d_021F6EAC.f0E&=mask;d_021F6EAC.f10&=mask;d_021F6EAC.f12&=mask;d_021F6EAC.f14&=mask;func_0208799C(state);func_021F5FB0(aid);}else active|=(u16)bit;}}
if(!active){func_021F0D1C(7);return;}func_021F0D1C(4);}







void func_021F0AE4(void) { func_021F0D1C(6);if(d_021F6EAC.f18==1){d_021F6EAC.f18=0;func_021F5F74();} }





void func_021F0B04(void) { if(d_021F6EAC.f08==4 && d_021F6EAC.f0A==d_021F6EAC.f14 && d_021F6EAC.f18==1){d_021F6EAC.f18=0;func_021F5F74();} }





void func_021F0B2C(u16 aid,u32 event,u8 *p)
{
 u32 state;u16 mask;void *q;u32 offset;
 switch(event){
 case 2:
  if(func_021F0D28()!=2)break;
  state=func_02087988();d_021F6EAC.f0A|=(u16)(1<<aid);func_0208799C(state);
  offset=30*(aid-1);
  *(u8 *)((u32)d_021F6EDE+offset)=p[10];
  *(u8 *)((u32)d_021F6EDF+offset)=p[11];
  *(u8 *)((u32)d_021F6EE0+offset)=p[12];
  *(u8 *)((u32)d_021F6EE1+offset)=p[13];
  *(u8 *)((u32)d_021F6EE2+offset)=p[14];
  *(u8 *)((u32)d_021F6EE3+offset)=p[15];
  *(u16 *)((u32)d_021F6EE4+offset)=aid;break;
 case 3:
  if(func_021F0D34(aid)==6)break;
  mask=~(1<<aid);state=func_02087988();
  d_021F6EAC.f0A&=mask;d_021F6EAC.f0C&=mask;d_021F6EAC.f0E&=mask;d_021F6EAC.f10&=mask;d_021F6EAC.f12&=mask;d_021F6EAC.f14&=mask;
  func_0208799C(state);func_021F0B04();break;
 case 10:
  if(func_021F0D28()!=2){func_021F0938(aid);break;}
  d_021F6EAC.f0C|=(u16)(1<<aid);func_021F08E4(aid);
  q=func_021F1B64(aid);if(q)func_02082D44(q,(void *)((u32)d_021F6EC8+30*(aid-1)),22);break;
 case 14:
  d_021F6EAC.f0C&=(u16)~(1<<aid);d_021F6EAC.f0E|=(u16)(1<<aid);func_021F09B0(aid);break;
 case 7:
  d_021F6EAC.f10&=(u16)~(1<<aid);d_021F6EAC.f12|=(u16)(1<<aid);break;
 case 9:
  d_021F6EAC.f12&=(u16)~(1<<aid);d_021F6EAC.f14|=(u16)(1<<aid);func_021F0B04();break;
 case 12:
  if(func_021F0D28()==4)func_021F0D1C(5);else func_021F0D1C(0);
  if(d_021F6EAC.f00){func_020307B0(d_021F6EAC.f00);d_021F6EAC.f00=0;}
  if(d_021F6EAC.f04){func_0203D7FC(d_021F6EAC.f04);d_021F6EAC.f04=0;}break;
 case 13:
  switch(((struct Obj04440 *)p)->f0){case 1:case 2:case 9:func_021F0D1C(7);break;case 8:break;}break;
 case 1:case 4:case 5:case 6:case 8:case 11:
 break;
 case 0:
 default:func_02034714(d_021F6E24,0,d_021F6E24);break;
 }
}





void func_021F0D1C(u16 v) { d_021F6EAC.f08 = v; }





u16 func_021F0D28(void) { return d_021F6EAC.f08; }



int func_021F0D34(u16 aid)
{
    u32 state;
    Snapshot snap;
    u16 bit;
    bit = 1 << aid;
    state = func_02087988();
    if (!(d_021F6EAC.f0A & bit)) {
        func_0208799C(state);
        return 0;
    }
    func_02082D44(((u8 *)&d_021F6EB4), &snap, 20);
    func_0208799C(state);
    if (snap.f04 & bit) return 2;
    if (snap.f06 & bit) return 3;
    if (snap.f08 & bit) return 4;
    if (snap.f0A & bit) return 5;
    if (snap.f0C & bit) return 6;
    return 1;
}








void func_021F0DB4(void) {if(d_021F6EAC.f00) {func_020307B0(d_021F6EAC.f00);d_021F6EAC.f00=0;}if(d_021F6EAC.f04) {func_0203D7FC(d_021F6EAC.f04);d_021F6EAC.f04=0;}}









u32 func_021F0DDC(void) { return d_021F6EAC.f18; }









Object *func_021F0DE8(u16 heap){Object *p;p=func_02030734(heap,40,1,d_021F6E28,159);p->f00=heap;p->f04=0;p->f14=0;p->f18=0;p->f0C=0;p->f08=0;p->f10=func_02030734(p->f00,6*func_020173E8()+4,1,d_021F6E28,169);return p;}









void func_021F0E40(State_021F0DB4 *p) { if(((struct Obj10259 *)p)->f14)func_020307B0(((struct Obj10259 *)p)->f14);if(p->flag==1)func_0203E6C0();func_020307B0(((struct Obj10259 *)p)->f10);func_020307B0(p); }








/*
 * extent: two zero padding bytes follow the epilogue.
 */
void func_021F0E6C(State_021F0E6C *p){switch(p->f04){case 0:break;case 1:if(func_02039ACC()==1)p->f04=2;break;case 2:if(func_020399B8(func_020399A8())==1)p->f04=3;break;case 3:if(func_0203D394(func_020399A8())==1){p->f04=6;func_0203D7BC(1);}break;case 4:if(func_02039CB4(func_020399A8(),64,4)==1){p->f04=5;func_0203D7BC(0);}break;case 5:case 6:default:break;}
if(p->f0C!=p->f08&&p->f08!=0){if(func_021F11F0(p,10,p->f08)==1)p->f0C=p->f08;}}








/*
 * evidence: 112-byte request copy, heap halfword at54, and own matched
 * 0203CBAC/0203E5F8 bodies establish all three/two arguments. The third
 * CBAC input carries the unchanged pointer word through its u32 parameter.
 * Halfword flag fields reproduce every original read/store without volatile.
 */
void func_021F0EFC(State_021F0EFC *p)
{
    Request q=request_021F6C94;
    q.f54=p->heap;
    func_0203CBAC((struct Req *)(&q),0,(u32)p);
    p->f24=0;
    p->f18.b00=0;
    p->f1e=0;
    p->f18.b03=0;
    p->f1c=0;
    p->f18.b04=0;
    p->f18.b05=0;
    p->f18.b06=0;
    p->f18.b07=0;
    p->f18.b08=0;
    p->f18.b09=0;
    p->f18.b10=0;
    p->f18.b11=1;
    p->f18.b14=0;
    p->f18.b13=0;
    p->f18.b15=0;
    p->f1a.b00=0;
    p->f1a.b01=0;
    p->f1a.b02=0;
    p->f1a.b03=0;
    p->f1a.b04=0;
    p->f1a.b05=0;
    p->f20=0;
    func_0203E5F8(p->heap,0);
}








void func_021F0FE8(State_021F0FE8 *p) { func_0203CEAC(0); func_0203E6C0(); p->flag=0; p->f4=0; }








int func_021F1008(void *p) { return func_0203CD98(); }








int func_021F1010(void *p) { return func_0203CDBC(); }








void func_021F1018(u8 *p) { func_0203D01C();((struct Obj22294 *)p)->f4=1; }









void func_021F1028(int *p)
{
    int r = (int)func_020399A8();
    func_02039C68((struct Link *)r, 0x40, 4);
    p[1] = 4;
}








int func_021F1040(int *p) { return p[1] == 5; }








int func_021F1050(int *p) { return p[1] >= 6; }









int func_021F1060(Ov107Ctx_021F0DB4 *p)
{
    return p->f0C;
}







void func_021F1064(unsigned char *p)
{
    unsigned short *h = (unsigned short *)(p + 0x18);
    *h = *h & ~(unsigned short)2;
    *h = *h & ~(unsigned short)4;
    *h = *h & ~(unsigned short)8;
    *h = *h & ~(unsigned short)0x10;
    *h = *h & ~(unsigned short)0x20;
    *h = *h & ~(unsigned short)0x40;
    *h = *h & ~(unsigned short)0x80;
    *h = *h & ~0x100;
    *h = *h & ~0x200;
    *h = *h & ~0x400;
    *h = *h & ~0x1000;
    p[0x1C] = 0;
}







/*
 * leaf: parent cleared all eight original Thumb starts; 60 bytes stop
 * before existing 021F1110. Both 10DC and10E4 read bit4 in the ROM.
 */
int func_021F10D4(State_021F1064 *p) { return p->f18.b03; }







int func_021F10DC(State_021F1064 *p) { return p->f18.b04; }







int func_021F10E4(State_021F1064 *p) { return p->f18.b04; }







int func_021F10EC(State_021F1064 *p) { return p->f18.b06; }







int func_021F10F4(State_021F1064 *p) { return p->f18.b07; }







int func_021F10FC(State_021F1064 *p) { return p->f18.b08; }







int func_021F1104(State_021F1064 *p) { return p->f18.b10; }







int func_021F110C(State_021F1064 *p) { return p->f1c; }








int func_021F1110(Ov107Ctx_021F0DB4 *p)
{
    return p->f18.b14;
}








unsigned short func_021F1118(Ov107Ctx_021F0DB4 *p)
{
    return p->f24;
}








unsigned short func_021F1120(Ov107Ctx_021F0DB4 *p)
{
    return (p->f24 & 0x3FFF0000) >> 16;
}








int func_021F1134(Ov107Ctx_021F0DB4 *p)
{
    if (p->f24 & 0x40000000) {
        return 1;
    }
    return 0;
}








int func_021F1148(Ov107Ctx_021F0DB4 *p)
{
    if (p->f24 & 0x80000000) {
        return 1;
    }
    return 0;
}








int func_021F115C(Ov107Ctx_021F0DB4 *p)
{
    return p->f18.b15;
}








int func_021F1164(Ov107Ctx_021F0DB4 *p)
{
    return p->f1A.b00;
}







int func_021F116C(Ov107Ctx_021F116C *p)
{
    return p->f1A.b01;
}






void func_021F1174(int a,int b,int c) { func_0203E758(b,c,2,1); }







void func_021F1184(Ov107Ctx_021F1184 *p)
{
    Ov107List *list;
    unsigned char i;

    list = p->f10;
    list->f00 = 0;
    list->f02 = 0;
    for (i = 0; i < 6; i++) {
        func_02017550((struct Sav *)((unsigned char *)p->f10 + i * func_020173E8() + 4));
    }
    p->f18.b1 = 0;
    p->f18.b2 = 0;
}







int func_021F11BC(Ov107Ctx_021F11BC *p)
{
    return p->f18.b01;
}







u8 func_021F11C4(u8 *p) { return *(u8 *)(((struct Obj22296 *)p)->f10); }






void *func_021F11CC(Ov107Ctx_021F11CC *p, int i)
{
    return p->f10 + i * func_020173E8() + 4;
}





int func_021F11E0(unsigned char *a) { return ((struct Obj22299 *)(*(unsigned char * *)&((struct Obj22298 *)a)->f10))->f2; }





int func_021F11E8(struct Bits *a) { return a->flag; }




int func_021F11F0(void *p, unsigned char kind, unsigned int val)
{
    Ov107Msg msg;
    void *obj;

    if (func_0203D378() == 1) {
        obj = func_0203996C(0xFF);
    } else {
        obj = func_020399A8();
    }
    msg.f04 = kind;
    msg.f00 = val;
    return func_0203D3F8((u32)obj, 0xFF, 0x400, 8, (u32)(&msg), 1, 0, 0);
}
