/*
 * file:     box2_main.c
 * unit:     yes
 * function: func_021DC9E0, func_021DCB48, func_021DCB8C, func_021DCDB8, func_021DCDD8, func_021DCDF0, func_021DCE14, func_021DCE80, func_021DCEC0, func_021DCF30, func_021DCF58, func_021DCFC0, func_021DD090, func_021DD14C, func_021DD16C, func_021DD1C4, func_021DD1E8, func_021DD210, func_021DD238, func_021DD25C, func_021DD2B4, func_021DD2D0, func_021DD314, func_021DD330, func_021DD39C, func_021DD3DC, func_021DD414, func_021DD42C, func_021DD464, func_021DD4B8, func_021DD530, func_021DD684, func_021DD694, func_021DD6E8, func_021DD718, func_021DD810, func_021DD8A8, func_021DD8D0, func_021DD8F8, func_021DD908, func_021DD930, func_021DDAE8, func_021DDC00, func_021DDE20, func_021DDE80, func_021DDEFC, func_021DDFD4, func_021DE07C, func_021DE120, func_021DE158, func_021DE428, func_021DE530, func_021DE5C8, func_021DE5F8, func_021DE66C, func_021DE720, func_021DE728, func_021DE7B4, func_021DE7C8, func_021DE898, func_021DE8B4, func_021DE980, func_021DEA3C, func_021DEA4C, func_021DEA6C, func_021DEAFC, func_021DEB08, func_021DEB14, func_021DEB40, func_021DEB70, func_021DEB90, func_021DEC64, func_021DEC98, func_021DED58, func_021DEDCC, func_021DEDD8, func_021DEF58, func_021DEF60, func_021DEF98, func_021DEFEC, func_021DEFF8, func_021DF040, func_021DF0BC, func_021DF0D4, func_021DF110, func_021DF11C, func_021DF128, func_021DF144, func_021DF1BC, func_021DF1DC, func_021DF228, func_021DF254, func_021DF288, func_021DF324, func_021DF348, func_021DF378, func_021DF38C, func_021DF404, func_021DF43C, func_021DF484, func_021DFA30
 * address:  0x021DC9E0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021EF7FC 0x021EF7FC data
 *   d_021EF82C 0x021EF82C data
 *   d_021EF8CC 0x021EF8CC data
 *   d_021EF86C 0x021EF86C data
 *   d_021EF88C 0x021EF88C data
 *   d_021EF80C 0x021EF80C data
 *   d_021EF8AC 0x021EF8AC data
 *   d_021EF84C 0x021EF84C data
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_02049740  0x02049740  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02049F34  0x02049F34  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_02027628  0x02027628  thumb
 *   func_02027624  0x02027624  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_020260F0 0x020260F0 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_02027778 0x02027778 thumb
 *   func_02027CFC 0x02027CFC thumb
 *   func_021EBFCC 0x021EBFCC thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CFC0 0x0202CFC0 thumb
 *   func_0202CF8C 0x0202CF8C thumb
 *   func_021EE038  0x021EE038  thumb  ov170
 *   func_021EF660  0x021EF660  thumb  ov170
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021EDECC  0x021EDECC  thumb  ov170
 *   func_021EE008  0x021EE008  thumb  ov170
 *   func_021ED904  0x021ED904  thumb  ov170
 *   func_021ED9B4  0x021ED9B4  thumb  ov170
 *   func_021EDF5C  0x021EDF5C  thumb  ov170
 *   func_021EB85C  0x021EB85C  thumb  ov170
 *   func_021EF738  0x021EF738  thumb  ov170
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_02007A18 0x02007A18 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_021EDAB0 0x021EDAB0 thumb ov170
 *   func_0201747C 0x0201747C thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_020075B0 0x020075B0 thumb
 *   func_0201AB48 0x0201AB48 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_021EDB34 0x021EDB34 thumb ov170
 *   func_0200752C 0x0200752C thumb
 *   func_02007664 0x02007664 thumb
 *   func_02017988 0x02017988 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_02007610 0x02007610 thumb
 *   func_020179B8  0x020179B8  thumb
 *   func_02019CF8 0x02019CF8 thumb
 *   func_02019D00 0x02019D00 thumb
 *   func_021EC48C 0x021EC48C thumb ov170
 *   func_02017D30  0x02017D30  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_0201AF80 0x0201AF80 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_020092AC 0x020092AC thumb
 *   func_021EC7B8 0x021EC7B8 thumb
 *   func_021EC548 0x021EC548 thumb
 *   func_021EF4A4 0x021EF4A4 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021ED75C 0x021ED75C thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 *   func_020078C4 0x020078C4 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EDA70 0x021EDA70 thumb
 *   func_021ECBD8 0x021ECBD8 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F1400 0x021F1400 data a1
 *   func_02012F98  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 *   func_021ED164 0x021ED164 thumb ov170
 *   func_021ED198 0x021ED198 thumb ov170
 *   func_021ED14C 0x021ED14C thumb ov170
 *   func_021ED310 0x021ED310 thumb ov170
 *   func_02049DB4  0x02049DB4  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_02049EB4 0x02049EB4 arm
 *   func_02041090 0x02041090 arm
 *   func_02041300 0x02041300 arm
 *   func_021EB7E8 0x021EB7E8 thumb
 *   func_021EE224 0x021EE224 thumb
 *   func_021EE234 0x021EE234 thumb
 *   func_021EE244 0x021EE244 thumb
 *   func_02021640 0x02021640 thumb
 *   func_0200781C  0x0200781C  thumb  ov170
 *   func_020185A0 0x020185A0 thumb
 *   func_02017F08 0x02017F08 thumb
 *   func_02017EB4 0x02017EB4 thumb
 *   func_0201B268 0x0201B268 thumb
 *   func_0201B28C 0x0201B28C thumb
 *   func_021ECCCC  0x021ECCCC  thumb  ov170
 *   func_021ED028  0x021ED028  thumb  ov170
 *   func_021EB2A4  0x021EB2A4  thumb  ov170
 *   func_02017DBC 0x02017DBC thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_021EB324 0x021EB324 thumb
 *   func_02041EE4 0x02041EE4 arm
 *   func_021ED6E4  0x021ED6E4  thumb  ov170
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021EF798 0x021EF798 data a1
 *   func_021EF224  0x021EF224  thumb  ov170
 *   func_02031348 0x02031348 arm
 *   d_021DC800 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 *   func_0202E474  0x0202E474  thumb
 *   d_021BB96C     0x021BB96C  data  ov170  a4
 *   ov070_id       0x00000046  data
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200785C 0x0200785C thumb
 *   func_0216BFD4 0x0216BFD4 thumb ov010
 *   d_021F5580 0x021F5580 data a4 ov194
 *   ov194_id 0x000000C2 data a1
 *   func_02007898 0x02007898 thumb
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   func_020061E4 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_02035C38 0x02035C38 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021E01C4 0x021E01C4 thumb
 *   func_021E01E0 0x021E01E0 thumb
 *   func_021E19D4 0x021E19D4 thumb
 *   func_021E1A28 0x021E1A28 thumb
 *   func_021EC5A0 0x021EC5A0 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021EF180 0x021EF180 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021EF1C4 0x021EF1C4 thumb
 *   func_021EF264 0x021EF264 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EF3A0 0x021EF3A0 thumb
 *   func_021EF400 0x021EF400 thumb
 *   func_021EF45C 0x021EF45C thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF60C 0x021EF60C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021EF680 0x021EF680 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_021EF69C 0x021EF69C thumb
 *   func_021EF75C 0x021EF75C thumb
 *   func_021EF770 0x021EF770 thumb
 *   func_021EF248 0x021EF248 thumb
 *   func_021EF3D8 0x021EF3D8 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_02026124 0x02026124 thumb
 *   func_021EF480 0x021EF480 thumb
 *   d_021EF7B4 0x021EF7B4 data a1
 *   d_021EF79C 0x021EF79C data a1
 */
#include "../../matched/include/Obj12146.h"
#include "../../matched/include/Obj18439.h"
#include "../../matched/include/Obj18440.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23825.h"
#include "../../matched/include/Obj23826.h"
#include "../../matched/include/Obj23827.h"
#include "../../matched/include/Obj18441.h"
#include "../../matched/include/Obj18442.h"
#include "../../matched/include/Obj18443.h"
#include "../../matched/include/Obj18444.h"
#include "../../matched/include/Obj09221.h"
#include "../../matched/include/Obj12149.h"
#include "../../matched/include/Obj18446.h"
#include "../../matched/include/Obj18447.h"
#include "../../matched/include/Obj23829.h"
#include "../../matched/include/Obj18451.h"
#include "../../matched/include/Obj10646.h"
#include "../../matched/include/Obj23832.h"
#include "../../matched/include/Obj23834.h"
#include "../../matched/include/Obj18452.h"
#include "../../matched/include/Obj06551.h"
#include "../../matched/include/Obj23835.h"
#include "../../matched/include/Obj23836.h"
#include "../../matched/include/Obj23837.h"
#include "../../matched/include/Obj23838.h"
#include "../../matched/include/Obj23839.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23841.h"
#include "../../matched/include/Obj23843.h"
#include "../../matched/include/Obj01418.h"
#include "../../matched/include/Obj23845.h"
#include "../../matched/include/Obj23846.h"
#include "../../matched/include/Obj23847.h"
#include "../../matched/include/Obj23848.h"
#include "../../matched/include/Obj23849.h"
#include "../../matched/include/Obj23850.h"
#include "../../matched/include/Obj18453.h"
#include "../../matched/include/Obj23851.h"
#include "../../matched/include/Obj09222.h"
#include "../../matched/include/Obj18454.h"
#include "../../matched/include/Obj10648.h"
#include "../../matched/include/Obj10649.h"
#include "../../matched/include/Obj23852.h"
#include "../../matched/include/Obj12153.h"
#include "../../matched/include/Obj14262.h"
#include "../../matched/include/Obj23854.h"
#include "../../matched/include/Obj23855.h"
#include "../../matched/include/Obj23856.h"
#include "../../matched/include/Obj23857.h"
#include "../../matched/include/Obj23858.h"
#include "../../matched/include/Obj23859.h"
#include "../../matched/include/Obj23860.h"
#include "../../matched/include/Obj18455.h"
#include "../../matched/include/Obj18456.h"
#include "../../matched/include/Obj18457.h"
#include "../../matched/include/Obj18458.h"
#include "../../matched/include/Obj14263.h"
#include "../../matched/include/Obj05437.h"
#include "../../matched/include/Obj04901.h"
#include "../../matched/include/Obj12155.h"
#include "../../matched/include/Obj12156.h"
#include "../../matched/include/Obj18460.h"
#include "../../matched/include/Obj10650.h"
#include "../../matched/include/Obj06546.h"
#include "../../matched/include/Obj23861.h"
#include "../../matched/include/Obj23862.h"
#include "../../matched/include/Obj23863.h"
#include "../../matched/include/Obj23864.h"
#include "../../matched/include/Obj23865.h"
#include "../../matched/include/Obj23866.h"
#include "../../matched/include/Obj23867.h"

#define HALF(p,n) (*(unsigned short *)(WORK(p)+(n)))
#define SYS(p) (*(unsigned **)(p))
#define RESULT(p) (*(unsigned char *)(*(char **)((p) + 0x2C) + 0xA173))
#define FLAGS(o) (*(unsigned *)((char *)(o) + 0x18))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
struct PalAnmSlot;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Rec;
struct R;
struct TaskMenuState;
struct Sound;
struct TaskMenu;
struct TaskMenuTmpl;
struct WinMgr;
struct Struct_02025CD0;
struct Sub020079BCEntry;
struct Party;
struct Mon;
struct PartyMon;
struct Sub020075B0Entry;
struct Sub02007454Entry;
struct Blk37;
struct Sav;
struct Bank;
struct CharBuf;
struct Descriptor;
struct Node;
struct Sub02007AC8Entry;
struct PerapVoice;
struct BigObj;
struct Big;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct { u32 f0; u32 f4; u32 f8; u8 *fC; } PlttData;

struct Ov170Ctx { char pad[0x2c]; char *f2c; };

typedef struct {
    u32 heapId;
    u8 count;
    u8 pad05[3];
    const void *items;
    u32 unk0c;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} MenuTmpl;

typedef struct {
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} Fade;

typedef struct {
    unsigned char pad[0x1A6];
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} Work_021DC9E0;

typedef struct {
    unsigned char pad[0x2C];
    Work_021DC9E0 *work;
} Sys;

typedef signed char s8;

typedef signed int     s32;

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry;

typedef struct {
    Entry e[7];
    int count;
    unsigned a;
    unsigned b;
} Move;

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short f4;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry_021DD684;

typedef struct {
    Entry_021DD684 e[7];
    int count;
} Move_021DD684;

typedef struct {
    unsigned short idx;
    unsigned short slot;
    unsigned short f4;
    unsigned short f6;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Obj;

typedef struct {
    unsigned short idx, slot, f4, f6;
    int vx,vy;
    short dx,dy,x,y;
} Obj_021DDFD4;

typedef struct {
    unsigned short idx;
    unsigned short slot;
    unsigned short f4;
    unsigned short f6;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Obj_021DE07C;

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry_021DE158;

typedef struct {
    Entry_021DE158 e[7];
    int count;
    unsigned a;
    unsigned b;
    unsigned req;
} Move_021DE158;

typedef struct {
    unsigned short idx;
    unsigned short slot;
    unsigned short f4;
    unsigned short f6;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Obj_021DE530;

typedef struct {
    unsigned short id;
    unsigned short val;
    unsigned short f4;
    unsigned short used;
    unsigned char pad[0x10];
} Entry_021DE530;

typedef struct {
    unsigned short idx,slot,f4,f6;
    int vx,vy;
    short dx,dy,x,y;
} Obj_021DE5F8;

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry_021DE5F8;

typedef struct {void *p;unsigned short f4;unsigned char flags;unsigned char pad[5];} State_021DE728;

typedef struct {void *p;unsigned short index;unsigned char flags;unsigned char pad[5];} State_021DE7C8;

typedef struct {
    unsigned short idx, slot;
    int mode, x, y, vx, vy;
    unsigned left:1;
    unsigned up:1;
} Mover_021DE8B4;

typedef struct {
    unsigned short idx;
    unsigned short slot;
    int mode;
    int x;
    int y;
    int vx;
    int vy;
    unsigned int left : 1;
    unsigned int up : 1;
} Mover_021DE980;

typedef struct {
    unsigned short index;
    unsigned short pad;
    int value, x, y, dx, dy;
    unsigned dirX:1;
    unsigned dirY:1;
    unsigned count:30;
} Motion;

typedef struct {
    char pad[0xA178];
    signed char box;
    unsigned char flip;
} Work_021DE728;

typedef struct {
    void *mon;
    unsigned short species;
    unsigned short form;
    unsigned pid;
    unsigned char cC;
    unsigned char cD;
    unsigned char cE;
    unsigned char cF;
    unsigned short item;
    unsigned char level : 7;
    unsigned char egg : 1;
    unsigned char gender : 4;
    unsigned char showgender : 1;
    unsigned char shiny : 1;
    unsigned char mark : 2;
    unsigned short moves[4];
} Summary;

typedef struct {
    void *mon;
    void *f4;
    void *save;
    unsigned char kind, mode, count, slot, zero;
    char pad[7];
    void *f18;
    char pad1C[12];
} Request_021DF040;

typedef struct { void *task; void *text; } Request_021DF378;

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk;

extern void func_0203F8F4(u16 heap);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020403F4(unsigned);
extern void func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_020275E4(void);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02040E78(u32 a, void *src, u32 size, u32 ofs);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern u32 func_02027628(void);
extern u32 func_02027624(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern u32 func_0204162C(int channel);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_0207D63C(int, int, int, int, int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_0201C450(unsigned short,unsigned);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern u32 func_020260F0(struct Sound *obj);
extern void func_020355D8(u8 v);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027CFC(u8 *p, int sel);
extern void func_021EBFCC(char *p, int i, int v);
extern u32 func_021EBFEC(char *p, int i);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
extern u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);
extern void func_021EE038(char *, int, int, int);
extern void func_021EF660(struct WinMgr *mgr);
extern void func_021EBFA8(char *p, int i, int v);
extern void func_021EC35C(char **p, int box);
extern void func_021EDECC(unsigned char *p, int d);
extern void func_021EE008(char *, int, int);
extern void func_021ED904(unsigned char *p);
extern void func_021ED9B4(int);
extern void func_021EDF5C(unsigned char *p);
extern void func_021EB85C(unsigned char *p, int i);
extern void func_021EF738(struct WinMgr *mgr);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_0201AA18(void *p);
extern void *func_0201AB28(void *party, unsigned i);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern unsigned func_02017E88(void *p, unsigned id, unsigned v);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void func_02017E64(void *p, u32 id, u32 v);
extern int func_020185F0(void *p);
extern void func_02007664(void *save, u32 box, u32 slot);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern void func_021EDAB0(char *p, int i);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void *func_020185F4(void *);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern void func_021EDB34(char *p, int a);
extern u32 func_02017988(void *p, u32 a);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_02007610(void *save, unsigned b1, unsigned a, unsigned b2, unsigned c);
extern int func_020179B8(int a0, int a1);
extern u16 func_02019CF8(u32 item);
extern u32 func_02019D00(u32 item);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern u32 func_02017D30(struct Sav *p);
extern void func_020185C4(void *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern u32 func_0200CA38(struct Blk37 *);
extern u32 func_020092AC(const u8 *bits, int n);
extern void func_021EC7B8(char *p, int i, unsigned j, int flag);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern int func_021EF4A4(struct WinMgr *mgr);
extern void func_021EC000(char *p, int i, int v);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ED75C(char **p, int i);
extern void func_021ED7C4(char *p, int i);
extern int func_020078C4(void *save, u32 box);
extern unsigned func_0202136C(unsigned short v);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EDA70(int a0, int a1, short *a2, short *a3);
extern void func_021ECBD8(unsigned char *p, int i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Sub02007AC8Entry *func_02012F98(void *p);
extern void func_02007C34(struct PerapVoice *p, void *a);
extern void func_021ED164(char *w, int i, int v);
extern void func_021ED198(char *w, int i, int v);
extern void func_021ED14C(int a, int b, int c);
extern void func_021ED310(char *w);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void *func_02049EB4(u32,u32,u32,u32,u16);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041300(u32,int,u8,int,u8,u8,u8);
extern void func_021EB7E8(char **p, unsigned box, int i);
extern void func_021EE224(char *p, int i, int v);
extern int func_021EE234(int *a, int i);
extern void func_021EE244(char *p, int i, int flag);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern unsigned char func_0200781C(int save, unsigned int box);
extern unsigned char func_020185A0(void *mon);
extern unsigned char func_02017F08(void *mon);
extern u32 func_02017EB4(void *p);
extern u32 func_0201B268(void *mon);
extern u32 func_0201B28C(void *mon);
extern void func_021ECCCC(char *p, void **mon, int index);
extern void func_021ED028(char *p, unsigned char *q);
extern void func_021EB2A4(u8 *p, int a);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void func_021EB324(char *w);
extern void func_021ED6E4(char **p, int v);
extern int func_021EF224(int, int);
extern void func_02031348(void *p, int a, const void *b, void *c);
extern void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern void func_0200785C(void *save, unsigned box, void *dest);
extern int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
extern void func_02007898(void *save, u32 box, const void *src);
extern int func_0216C0C0(int);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern int func_021E01C4(char *p);
extern int func_021EF5C4(struct WinMgr *mgr);
extern int func_02035C38(void);
extern void func_021EF57C(struct WinMgr *mgr);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern int func_021EF770(struct WinMgr *mgr);
extern void func_021EF75C(struct WinMgr *mgr);
extern void func_020061E4(unsigned se);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021EF248(void);
extern void func_021EF3D8(struct WinMgr *mgr);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED888(char *q, int a);
extern void func_02026124(struct Sound *obj, u32 idx);
extern int func_021EF480(struct WinMgr *mgr);
extern int func_021EF60C(struct WinMgr *mgr);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021EF180(int a, int b);
extern void func_021EE364(char **p, int idx, int v);
extern int func_021EF1B4(void);
extern int func_021EF264(void);
extern void func_021EF3A0(struct WinMgr *mgr);
extern int func_021EF1C4(void);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021E1A28(char *p);
extern int func_021E19D4(char *p);
extern int func_021E01E0(char *p);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(char **p, int flag);
extern void func_021EF680(char *p);
extern void func_021EF68C(char *p);
extern int func_021EF400(unsigned char *p);
extern void func_021EF69C(char *p);
extern void func_021EF670(char *p);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021ED55C(char **p, int flag);
void func_021DC9E0(u8 *a0);
void func_021DCB48(void *p);
void func_021DCB8C(struct Ov170Ctx *ctx);
void func_021DCDB8(char *p);
void func_021DCDD8(int *p);
void func_021DCDF0(int a);
void func_021DCE14(char *p);
void func_021DCE80(char *p);
void func_021DCEC0(char *p);
void func_021DCF30(char *p);
void func_021DCF58(unsigned char *p, int sel);
int func_021DCFC0(char *p);
void func_021DD090(Sys *p, unsigned idx);
void func_021DD14C(char *p);
void func_021DD16C(unsigned char *p, int dir);
void func_021DD1C4(char *p, int a);
void func_021DD1E8(char *p);
int func_021DD210(unsigned char *p, unsigned a, unsigned b);
void func_021DD238(char *p);
unsigned func_021DD25C(void ***p, unsigned short a, unsigned short box, unsigned id, unsigned v);
void func_021DD2B4(int a, int b, int c, int d, int e);
int func_021DD2D0(void ***p, int a, unsigned b);
void func_021DD314(char **p, int a, unsigned b);
void func_021DD330(unsigned char *p,unsigned short *q,unsigned short *t);
void func_021DD39C(unsigned char *p, unsigned short *q);
void func_021DD3DC(char *p, unsigned char *a);
void func_021DD414(char **p, char *q);
void func_021DD42C(int *p, unsigned char *a);
void func_021DD464(unsigned char *p,unsigned a,unsigned b,unsigned c);
void func_021DD4B8(unsigned char *p,unsigned a,unsigned b);
void func_021DD530(unsigned char *p);
int func_021DD684(unsigned char *p, unsigned i);
int func_021DD694(void ***p, unsigned skip);
void func_021DD6E8(void **pp, void *a, u32 b);
int func_021DD718(void **pp, void *mon);
void func_021DD810(unsigned char *p,unsigned a,unsigned b,unsigned box);
void func_021DD8A8(void **pp, u32 idx);
void func_021DD8D0(char *p);
void func_021DD8F8(char *p);
int func_021DD908(char *p, u32 a);
int func_021DD930(unsigned char *p);
int func_021DDAE8(unsigned char *p);
int func_021DDC00(unsigned char *p, unsigned a, unsigned b);
int func_021DDE20(unsigned char *p,unsigned a,unsigned b);
int func_021DDE80(unsigned char *p, unsigned a, unsigned b);
void func_021DDEFC(unsigned char *p, Obj *o);
void func_021DDFD4(unsigned char *p,Obj_021DDFD4 *o);
void func_021DE07C(unsigned char *p, Obj_021DE07C *o);
void func_021DE120(char *p, int a, int b);
int func_021DE158(unsigned char *p, unsigned a, unsigned b);
void func_021DE428(unsigned char *p, unsigned a, unsigned b);
void func_021DE530(unsigned char *p, int a, int b);
int func_021DE5C8(char *p, unsigned id);
void func_021DE5F8(unsigned char *p,unsigned a);
void func_021DE66C(char *p, Entry_021DE5F8 *e);
int func_021DE720(unsigned short a);
void func_021DE728(unsigned char *p);
void func_021DE7B4(char *p);
int func_021DE7C8(unsigned char *p);
void func_021DE898(int *q);
void func_021DE8B4(unsigned char *p, int slot, unsigned idx, int mode, int flag);
void func_021DE980(unsigned char *p, int mode);
void func_021DEA3C(int a, int b, int c, int d);
void func_021DEA4C(char *p, int a, int b);
int func_021DEA6C(char *p, int a);
int func_021DEAFC(int a);
int func_021DEB08(unsigned char *p);
unsigned char func_021DEB14(unsigned char *p, int a);
void func_021DEB40(u32 a, int b, void *c);
void func_021DEB70(int a, int b, int c);
void func_021DEB90(void *unused, void *unused2, int x, u32 base, u32 pal);
void func_021DEC64(void *a, void *b, int c, void *d, int e);
void func_021DEC98(char *p, void *a, int dir);
void func_021DED58(char *p, int a);
int func_021DEDCC(char *p, int box);
Summary *func_021DEDD8(void *mon);
void func_021DEF58(void *s);
void func_021DEF60(char *p, int a);
int func_021DEF98(char *p, int a, unsigned b);
void func_021DEFEC(char *p, int b);
void func_021DEFF8(char *p, unsigned b);
void func_021DF040(char *p);
void func_021DF0BC(unsigned char *p);
void func_021DF0D4(char *p,int base,u32 bits);
void func_021DF110(char *p, int b);
void func_021DF11C(char *p, int b);
void func_021DF128(int p);
void func_021DF144(char *w, Summary *s);
int func_021DF1BC(int a, int b, unsigned char *r);
int func_021DF1DC(short x, int y);
int func_021DF228(short x, short y, const unsigned char *r);
int func_021DF254(unsigned char *p, short x, short y);
int func_021DF288(char *p);
int func_021DF324(char *p);
int func_021DF348(void **p);
int func_021DF378(char *p);
int func_021DF38C(char *p);
int func_021DF404(u8 *p);
void func_021DF43C(char *p, int x, int y);
int func_021DF484(unsigned char *p);
int func_021DFA30(unsigned char *p);
extern const struct DispConfig d_021EF7FC;
extern const struct BgTemplate d_021EF82C;
extern const struct BgTemplate d_021EF8CC;
extern const struct BgTemplate d_021EF86C;
extern const struct BgTemplate d_021EF88C;
extern const struct BgTemplate d_021EF80C;
extern const struct BgTemplate d_021EF8AC;
extern const struct BgTemplate d_021EF84C;
extern const char d_021F1400[];
extern const unsigned char d_021EF798[];
extern const unsigned d_021DC800[];
extern const char ov131_id[];
extern u8 ov070_id[];
extern const unsigned d_021F5580[];
extern const char ov194_id[];
extern const unsigned char d_021EF79C[];
extern const unsigned char d_021EF7B4[];








/*
 * Background setup of the box screen: display banks, seven layers from
 * the rodata templates (clearing 1, 4 and 6), then the plane masks.
 */
void func_021DC9E0(u8 *a0)
{
    struct DispConfig c;
    struct BgTemplate t0;
    struct BgTemplate t1;
    struct BgTemplate t2;
    struct BgTemplate t3;
    struct BgTemplate t4;
    struct BgTemplate t5;
    struct BgTemplate t6;

    func_0203F8F4(0x4C);
    c = d_021EF7FC;
    func_0203FC28(&c);
    t0 = d_021EF82C;
    func_0203FCA0(0, &t0, 0);
    t1 = d_021EF8CC;
    func_0203FCA0(1, &t1, 0);
    func_020414EC(1);
    func_02040B94(1, 0x20, 0, 0x4C);
    t2 = d_021EF86C;
    func_0203FCA0(2, &t2, 0);
    t3 = d_021EF88C;
    func_0203FCA0(3, &t3, 0);
    t4 = d_021EF80C;
    func_0203FCA0(4, &t4, 0);
    func_020414EC(4);
    func_02040B94(4, 0x20, 0, 0x4C);
    t5 = d_021EF8AC;
    func_0203FCA0(5, &t5, 0);
    t6 = d_021EF84C;
    func_0203FCA0(6, &t6, 0);
    func_020414EC(6);
    func_02040B94(6, 0x20, 0, 0x4C);
    func_020434DC(0xF, 1);
    func_02043598(7, 1);
}







void func_021DCB48(void *p)
{
    func_020434DC(15, 0);
    func_02043598(7, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}








void func_021DCB8C(struct Ov170Ctx *ctx)
{
    void *arc;
    void *arc2;
    void *pal;
    PlttData *pd;
    u8 *src;
    u32 ofs;
    u32 r6;
    u16 *a;
    u16 *b;
    u32 i;

    arc = func_020490F4(0x74, 0x4c);
    func_02049658(arc, 0xc, 1, 0, 0, 1, 0x4c);
    func_02049740(arc, 3, 2, 0, 1, 0x4c);
    func_020498F4(arc, 2, 2, 0, 0, 1, 0x4c);
    func_02049658(arc, 1, 3, 0, 0, 1, 0x4c);
    func_020498F4(arc, 0, 3, 0, 0, 1, 0x4c);
    func_02049B68(arc, 4, 0, 0, 0x80, 0x4c);
    func_02049658(arc, 0x3e, 1, 1000, 0x300, 1, 0x4c);
    func_02049B68(arc, 0x3f, 0, 0x180, 0x40, 0x4c);
    pal = func_02049F34(func_020275E4(), 0x1f, (u32)(&pd), 0x804c);
    src = pd->fC;
    ofs = 0x194;
    func_02040E78(0, src + 0x34, 4, ofs);
    src += 0x14;
    ofs += 0x20;
    func_02040E78(0, src, 4, ofs);
    func_020307B0(pal);
    func_02049658(arc, 6, 5, 0, 0, 1, 0x4c);
    func_020498F4(arc, 5, 5, 0, 0, 1, 0x4c);
    func_02049658(arc, 6, 6, 0, 0, 1, 0x4c);
    func_02049B68(arc, 7, 4, 0, 0, 0x4c);
    func_02049238(arc);
    arc2 = func_020490F4(func_020275E4(), 0x4c);
    func_02049740(arc2, func_02027628(), 0, 0, 0, 0x4c);
    func_02049B68(arc2, func_02027624(), 0, 0xe0, 0x20, 0x4c);
    func_020498F4(arc2, func_0202762C(), 0, 0, 0, 0, 0x4c);
    func_020413B0(0, 0, 0x15, 0x20, 3, 7);
    func_02041B6C(0);
    r6 = func_02049740(arc2, func_02027628(), 2, 0, 0, 0x4c);
    func_02049238(arc2);
    a = (u16 *)func_0204162C(0);
    b = (u16 *)func_0204162C(2);
    for (i = 0; i < 0x60u; i++) {
        *(u16 *)((char *)b + 0x540 + i * 2) = r6 + *(u16 *)((char *)a + 0x540 + i * 2);
    }
    func_02041B6C(2);
    *(int *)(ctx->f2c + 0x178) = (int)func_0201F5DC(0, 10, 0, 0x4c);
    func_02049B40(0x17, 5, 0, 0x160, 0x20, 0x4c);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4c);
}








/*
 * Allocate 76 bytes, keep the handle, then configure it.
 */
void func_021DCDB8(char *p)
{
    int v = (int)func_02021518(0x4c);

    ((struct Obj18439 *)(*(char * *)&((struct Obj12146 *)p)->f2C))->f6C = v;
    func_0202155C((struct PalAnmSlot *)(((struct Obj18440 *)(*(char * *)&((struct Obj12146 *)p)->f2C))->f6C), 0, 0x200, 0x4c);
}








void func_021DCDD8(int *p)
{
    func_020215A0((struct PalAnmSlot *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x6c)), 0);
    func_02021540((void *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x6c)));
}







void func_021DCDF0(int a)
{
    if (a == 1)
        func_0207D63C(0x04000050, 0, 0x2a, 6, 0xa);
    else
        *(volatile unsigned short *)0x04000050 = 0;
}







#define PTR(p,n) (*(void **)(*(char **)((p)+0x2c)+(n)))







void func_021DCE14(char *p)
{
    PTR(p,0x80) = func_02045B38(0,2,9,0x4c);
    PTR(p,0x78) = func_0201D7EC(0x17,0,1,0,0x4c);
    PTR(p,0x7c) = func_0201D7EC(0x17,3,0,0,0x4c);
    PTR(p,0x84) = func_0201EC64(0x4c);
    PTR(p,0x8c) = func_0201C450(0x800,0x4c);
    PTR(p,0x88) = func_020457B0(0x400,0x4c);
}







#define WORK(p) (*(char **)((p)+0x2c))







#undef PTR






#undef PTR





#undef PTR




#undef PTR



#undef PTR


#undef PTR

#undef PTR
#define PTR(p,n) (*(void **)(WORK(p)+(n)))







/*
 * trailing: two bytes alignment padding at 0x021DCEBE.
 */
void func_021DCE80(char *p)
{
    func_02045808(PTR(p,0x88));
    func_0201C4C0(PTR(p,0x8c));
    func_0201ED04(PTR(p,0x84));
    func_0201D83C(PTR(p,0x7c));
    func_0201D83C(PTR(p,0x78));
    func_02045C04(PTR(p,0x80));
}







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p)+0x2c))







#undef PTR






#undef PTR





#undef PTR




#undef PTR



#undef PTR


#undef PTR

#undef PTR
#define PTR(p,n) (*(void **)(WORK(p)+(n)))







void func_021DCEC0(char *p)
{
    PTR(p,0x184)=func_02045EC0(PTR(p,0x80),0x6e);
    HALF(p,0x188)=0x39e3;
    PTR(p,0x18c)=0;
    PTR(p,0x190)=func_02045EC0(PTR(p,0x80),0x6f);
    HALF(p,0x194)=0x39e3;
    PTR(p,0x198)=0;
    PTR(p,0x19c)=func_02027F60(0,8,(u32)PTR(p,0x78),(u32)PTR(p,0x8c),0x4c);
}







/*
 * lane O46
 */
void func_021DCF30(char *p)
{
    func_02027FD8((struct TaskMenuState *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x19C)));
    func_02045808((struct U16Vec *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x190)));
    func_02045808((struct U16Vec *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x184)));
}







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))








void func_021DCF58(unsigned char *p, int sel)
{
    MenuTmpl t;
    t.heapId = 0x4C;
    t.count = 2;
    t.items = WORK(p) + 0x184;
    t.unk0c = 1;
    t.x = 0x20;
    t.y = 0x12;
    t.w = 8;
    t.h = 3;
    if (func_020260F0(*(void **)(WORK(p) + 0x70)) == 1)
        func_020355D8(0);
    else
        func_020355D8(1);
    *(void **)(WORK(p) + 0x1A0) = func_02027778((struct TaskMenuTmpl *)(&t), *(void **)(WORK(p) + 0x19C));
    func_02027CFC(*(void **)(WORK(p) + 0x1A0), sel);
}








int func_021DCFC0(char *p)
{
    Fade *f = (Fade *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x1A6);
    switch (f->state) {
    case 0:
        if (f->flag == 0) {
            func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, f->id, f->lo);
        } else {
            func_020413B0(f->id, f->x, f->y, f->w, f->h, f->lo);
            func_02041B6C(f->id);
        }
        f->state++;
        break;
    case 1:
        if (f->flag == 0) {
            if (func_021EBFEC(*(char * *)&((struct Obj00000 *)p)->f2C, f->id) == 0)
                return 0;
        } else {
            f->count++;
            if (f->count == 4) {
                func_020413B0(f->id, f->x, f->y, f->w, f->h, f->hi);
                func_02041B6C(f->id);
                f->count = 0;
                f->state++;
            }
        }
        break;
    case 2:
        f->count++;
        if (f->count == 2)
            return 0;
        break;
    }
    return 1;
}








void func_021DD090(Sys *p, unsigned idx)
{
    unsigned short w;
    unsigned short h;
    signed char pos[2];
    func_0202CF98(*(struct WinMgr * *)&((struct Obj23825 *)((char *)p->work))->f74, idx, &pos[1], &pos[0]);
    func_0202CFC0(*(struct WinMgr * *)&((struct Obj23826 *)((char *)p->work))->f74, idx, &w, &h);
    p->work->flag = 1;
    p->work->id = func_0202CF8C(*(struct WinMgr * *)&((struct Obj23827 *)((char *)p->work))->f74, idx);
    p->work->lo = 0xD;
    p->work->hi = 0xC;
    p->work->state = 0;
    p->work->count = 0;
    p->work->x = pos[1];
    p->work->y = pos[0];
    p->work->w = w;
    p->work->h = h;
}







void func_021DD14C(char *p)
{
    func_021EE038(p, ((struct Obj00000 *)p)->f1F, ((struct Obj00000 *)p)->f20,
                  ((struct Obj00000 *)p)->f21);
    func_021EF660(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
}








void func_021DD16C(unsigned char *p, int dir)
{
    if (dir == 0) {
        p[0x14] = p[0x14] == 0 ? p[0x15] - 1 : p[0x14] - 1;
        func_021EBFA8(*(char * *)&((struct Obj00000 *)p)->f2C, 0, 2);
    } else {
        p[0x14] = p[0x14] == p[0x15] - 1 ? 0 : p[0x14] + 1;
        func_021EBFA8(*(char * *)&((struct Obj00000 *)p)->f2C, 1, 4);
    }
    func_021EC35C((char **)p, p[0x14]);
    func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
}







/*
 * Fold the signed delta into p[0x19] through the wrap helper,
 *   then refresh and re-key the queue.
 */
void func_021DD1C4(char *p, int a)
{
    ((struct Obj00000 *)p)->f19 = func_021DEB14((unsigned char *)p, (signed char)a);
    func_021EDECC((unsigned char *)p, a);
    func_021EE008(p, 0, 0);
}







/*
 * Five-step reset: fold the delta, rebuild the queue object,
 *   re-run the frame update, clear the flag and re-stage channel 9.
 */
void func_021DD1E8(char *p)
{
    func_021ED904((unsigned char *)p);
    func_021ED9B4(*(int *)&((struct Obj00000 *)p)->f2C);
    func_021EDF5C((unsigned char *)p);
    func_021EB85C((unsigned char *)p, 0);
    func_021EF738(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
}







/*
 * True when the absolute difference of the two unsigned arguments
 * straddles half of the +0x15 counter, in the direction of the order.
 */
int func_021DD210(unsigned char *p, unsigned a, unsigned b)
{
    int d = a - b;
    if (d < 0)
        d = -d;
    if (a > b)
        return d >= ((unsigned)p[0x15] >> 1);
    return d < ((unsigned)p[0x15] >> 1);
}








/*
 * Enable the pooled object when it reports zero.
 */
void func_021DD238(char *p)
{
    func_020355D8(0);
    if (func_020260F0(((struct Obj18441 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70) == 0)
        func_020260F4(((struct Obj18442 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 1);
}








unsigned func_021DD25C(void ***p, unsigned short a, unsigned short box, unsigned id, unsigned v)
{
    if (a >= 0x1E) {
        if (a >= 0x1E)
            a -= 0x1E;
        if ((int)func_0201AA18((*p)[2]) > a)
            return func_02017E1C(func_0201AB28((*p)[2], a), id, v);
    } else if (a != 0xFF) {
        void *m = func_02007A18((*p)[1], box, a);
        if (m != 0)
            return func_02017E88(m, id, v);
    }
    return 0;
}







/*
 * Open the range, then feed the handle to the second call.
 */
void func_021DD2B4(int a, int b, int c, int d, int e)
{
    int r = func_021DD2D0((void ***)a, c, b);
    if (r)
        func_02017E64((void *)r, d, e);
}








int func_021DD2D0(void ***p, int a, unsigned b)
{
    if (a == 0xFF || b >= 0x1E) {
        if (b >= 0x1E)
            b -= 0x1E;
        if (func_0201AA18((*p)[2]) > b)
            return func_020185F0(func_0201AB28((*p)[2], b));
    } else if (b != 0xFF) {
        return (int)func_02007A18((*p)[1], a, b);
    }
    return 0;
}








/*
 * Two ranges: below 30 forward all, at or above rebase.
 * The tested field is unsigned: a signed `b` compiles the inverted
 * branch as blo where the image has bhs.
 */
void func_021DD314(char **p, int a, unsigned b)
{
    if (b < 0x1eU)
        func_02007664((void *)(((struct Obj18443 *)(*p))->f4), a, b);
    else
        func_0201A9C8((struct Party *)(((struct Obj18444 *)(*p))->f8), b - 0x1eU);
}







void func_021DD330(unsigned char *p,unsigned short *q,unsigned short *t)
{
    unsigned box;
    unsigned short slot;
    void *m;
    if (q[0] == 0x24) box=p[0x17]; else box=p[0x14];
    m=func_0201747C((struct Mon *)func_021DD2D0((void ***)p,box,q[2]),0x804c);
    slot=t[2]-30;
    func_020075B0((*(void ***)p)[1],box,q[2],func_020185F4(func_0201AB28((*(void ***)p)[2],slot)));
    func_0201AB48((*(void ***)p)[2],slot,m);
    func_020307B0(m);
    func_021EDAB0((char *)p,box);
}







void func_021DD39C(unsigned char *p, unsigned short *q)
{
    void *m;
    m = func_0201747C((struct Mon *)func_021DD2D0((void ***)p,p[0x17],q[2]),0x804c);
    func_0201A98C((*(void ***)p)[2],m);
    func_021DD314((char **)p,p[0x17],q[2]);
    func_020307B0(m);
    func_021EDAB0((char *)p,p[0x17]);
}







/*
 * Rebuild the row then forward it and the two tag shorts; the
 *   three callers share p[0x14] as the id.
 */
void func_021DD3DC(char *p, unsigned char *a)
{
    int x = (int)func_020185F4(func_0201AB28(*(void **)(*(int *)&((struct Obj00000 *)p)->f0 + 8),
                                        ((struct Obj09221 *)a)->f4 - 0x1e));
    func_020075B0((void *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f0 + 4)), ((struct Obj00000 *)p)->f14,
                  ((struct Obj09221 *)a)->f2, (const struct Sub020075B0Entry *)x);
    func_021DD314((char **)p, ((struct Obj00000 *)p)->f14, ((struct Obj09221 *)a)->f4);
    func_021EDAB0(p, ((struct Obj00000 *)p)->f14);
}








/*
 * Forward two biased halfword coordinates.
 */
void func_021DD414(char **p, char *q)
{
    func_0201AB8C((struct Party *)(((struct Obj18446 *)(*p))->f8), ((struct Obj12149 *)q)->f4 - 0x1e,
                  ((struct Obj12149 *)q)->f2 - 0x1e, 0x4c);
}







/*
 * Walk the p+8 object's entries from tag-0x1e to the current
 *   count, re-reading the count each step.
 */
void func_021DD42C(int *p, unsigned char *a)
{
    unsigned i = ((struct Obj18447 *)a)->f4 - 0x1e;
    while (i < func_0201AA18(*(void **)(*p + 8)) - 1) {
        func_0201AB8C((struct Party *)(*(int *)(*p + 8)), i, i + 1, 0x4c);
        i++;
    }
}







void func_021DD464(unsigned char *p,unsigned a,unsigned b,unsigned c)
{
    void *m;
    unsigned box;
    m = (void *)func_021DD2D0((void ***)p,a,b);
    box = func_021DD684(p,c);
    func_0200752C((*(void ***)p)[1],box,m);
    func_02007664((*(void ***)p)[1],a,b);
    func_021EDAB0((char *)p,a);
    func_021EDB34((char *)p,a);
    func_021EDAB0((char *)p,box);
    func_021EDB34((char *)p,box);
}







/*
 * lever: declaring m before box selects r7 for m and r6 for box.
 */
void func_021DD4B8(unsigned char *p,unsigned a,unsigned b)
{
    void *m;
    unsigned box;
    box=func_021DD684(p,b);
    m=func_0201AB28((*(void ***)p)[2],a-30);
    if(func_02017E1C(m,5,0)==492){
        func_02017988(m,0);
        func_021DD8A8((void **)p,a);
        func_0200CFA0(func_0200CA1C((*(void ***)p)[0]),m);
    }
    func_0200752C((*(void ***)p)[1],box,func_020185F4(m));
    func_021DD314((char **)p,p[0x14],a);
    func_021EDAB0((char *)p,box);
    func_021EDB34((char *)p,box);
}








void func_021DD530(unsigned char *p)
{
    Move *m = *(Move * *)&((struct Obj23829 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned short n;
    if (m->a == 0xFF)
        return;
    n = func_0201AA18(((void **)((struct Obj00000 *)p)->f0)[2]);
    if (m->b >= 0x24) {
        if (m->a < 0x1E)
            func_021DD464(p, p[0x17], m->a, m->b - 0x24);
        else
            func_021DD4B8(p, m->a, m->b - 0x24);
        return;
    }
    if (m->a < 0x1E) {
        if (m->b < 0x1E) {
            func_02007610(((void **)((struct Obj00000 *)p)->f0)[1], p[0x17], m->a, p[0x14], m->b);
            func_021EDAB0((char *)p, p[0x14]);
            func_021EDB34((char *)p, p[0x14]);
            if (p[0x14] != p[0x17]) {
                func_021EDAB0((char *)p, p[0x17]);
                func_021EDB34((char *)p, p[0x17]);
            }
            return;
        }
        if (m->b - 0x1E < n) {
            func_021DD330(p, (short unsigned int *)(&m->e[0]), (short unsigned int *)(&m->e[1]));
            func_021DD810(p, m->b, m->a, p[0x17]);
        } else {
            func_021DD39C(p, (short unsigned int *)(&m->e[0]));
            func_021DD810(p, m->b, m->a, p[0x17]);
        }
        return;
    }
    if (m->b < 0x1E) {
        if (func_021DD25C((void ***)p, m->b, p[0x14], 0xA9, 0)) {
            func_021DD330(p, (short unsigned int *)(&m->e[1]), (short unsigned int *)(&m->e[0]));
            func_021DD810(p, m->b, m->a, p[0x14]);
        } else {
            func_021DD3DC((char *)p, (unsigned char *)(&m->e[m->a - 0x1E]));
            func_021DD810(p, m->b, m->a, p[0x14]);
        }
        return;
    }
    if (m->b - 0x1E < n)
        func_021DD414((char **)p, (char *)m);
    else
        func_021DD42C((int *)p, (unsigned char *)(&m->e[m->a - 0x1E]));
}












int func_021DD684(unsigned char *p, unsigned i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    return v;
}













int func_021DD694(void ***p, unsigned skip)
{
    unsigned i;
    for (i = 0; i < func_0201AA18((*p)[2]); i++) {
        if (i != skip) {
            void *m = func_0201AB28((*p)[2], i);
            if (func_02017E1C(m, 0x4C, 0) == 0 && func_02017E1C(m, 0xA0, 0) != 0)
                return 1;
        }
    }
    return 0;
}













void func_021DD6E8(void **pp, void *a, u32 b)
{
    void *r;

    func_020179B8((int)a, b);
    r = func_0201747C(a, 0x4c);
    func_0200CFA0(func_0200CA1C((void *)(*(u32 *)*pp)), r);
    func_020307B0(r);
}













/*
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/arm9/func_02019CF8.c (EXACT, Thumb forwarder to func_02019BBC).
 * Expected EXACT after the integrator's manifest refresh.
 *
 * Re-derives the form of a species whose form follows its held item
 * (0x1ED by plate, 0x289 by drive, 0x1E7 by the item 0x70) and applies it;
 * returns 1 when the form changed.
 *
 * Blocker (MATCH): the call to 0x02019CF8 has no witness.  0x02019CF8 is an
 * 8-byte Thumb tail-call thunk (ldr r3, =0x02019BBD; bx r3) that the arm9
 * listing decodes as ARM and nothing else calls; seeding it as a Thumb
 * function start promotes this file to EXACT.
 */
int func_021DD718(void **pp, void *mon)
{
    u16 species = func_02017E88(mon, 5, 0);
    if (species == 0x1ED) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 form = func_02017E88(mon, 0x6F, 0);
        u16 want = func_02019CF8(item);
        if (form != want)
            func_021DD6E8(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x289) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 form = func_02017E88(mon, 0x6F, 0);
        u16 want = func_02019D00(item);
        if (form != want)
            func_021DD6E8(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x1E7) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 old = func_02017E88(mon, 0x6F, 0);
        u16 form = old;
        if (old == 0) {
            if (item == 0x70) {
                func_021DD6E8(pp, mon, 1);
                form = 1;
            }
        } else if (item != 0x70) {
            func_021DD6E8(pp, mon, 0);
            form = 0;
        }
        if (old != form)
            return 1;
    }
    return 0;
}












/*
 * lever: the repeated third-argument truncations require a u16 extern parameter.
 */
void func_021DD810(unsigned char *p,unsigned a,unsigned b,unsigned box)
{
    if(a<30 && b<30) return;
    if(a>=30 && b>=30) return;
    if(a>=30) a=b;
    if(func_021DD25C((void ***)p,a,box,5,0)!=492) return;
    if(func_021DD25C((void ***)p,a,box,0x6f,0)==0) return;
    func_021DD6E8((void **)p,(void *)func_021DD2D0((void ***)p,box,a),0);
    func_021DD8A8((void **)p,a);
    if(box==p[0x14])
        func_021EC48C(p,box,a,*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+a+0x3dd2));
    if(p[0x16]==a) func_021DEFEC((char *)p,a);
}













void func_021DD8A8(void **pp, u32 idx)
{
    void *h;
    u32 v;

    if (idx < 0x1e)
        return;
    h = func_0201AB28(((struct Obj18451 *)((char *)*pp))->f8, idx - 0x1e);
    v = func_02017D30(h);
    func_020185C4(h);
    func_02017D70(h, v);
}












void func_021DD8D0(char *p) { *(u16 * *)&((struct Obj23832 *)(*(char * *)&((struct Obj10646 *)p)->f2C))->f180=func_0201AF80(76,0);((struct Obj23834 *)(*(char * *)&((struct Obj10646 *)p)->f2C))->f17C=func_0200CA38(func_0200CA1C(**(void ** *)&((struct Obj10646 *)p)->f0)); }













/*
 * Tail call func_020307B0 with the word at +0x2c/+0x180.
 */
void func_021DD8F8(char *p)
{
    func_020307B0(((struct Obj18452 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f180);
}












int func_021DD908(char *p, u32 a) { u16 n;n=func_021DD25C((void ***)p,a,((struct Obj06551 *)p)->f14,5,0);return func_020092AC(*(u8 * *)&((struct Obj23835 *)(*(char * *)&((struct Obj06551 *)p)->f0))->f20,n); }













int func_021DD930(unsigned char *p)
{
    Move_021DD684 *m = *(Move_021DD684 * *)&((struct Obj23836 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    Entry_021DD684 *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            func_021EC7B8(*(char * *)&((struct Obj00000 *)p)->f2C, e->id, e->slot, 1);
            k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
            if (e->slot < 0x1E) {
                func_021EC548(e->slot, &t[1], &t[0], p[0x1A]);
            } else if (e->slot < 0x24) {
                func_021EC548(e->slot, &t[1], &t[0], p[0x1A]);
                if (p[0x1A] == 2 && func_021EF4A4(*(struct WinMgr * *)&((struct Obj23837 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 0)
                    t[0] += 0xC0;
            } else {
                if (e->id >= 0x1E) {
                    func_021EC548(0x24, &t[1], &t[0], p[0x1A]);
                    if (p[0x1A] == 2 && func_021EF4A4(*(struct WinMgr * *)&((struct Obj23838 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 0)
                        t[0] += 0xC0;
                } else {
                    func_021EC548(e->id, &t[1], &t[0], p[0x1A]);
                }
                func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, k, 0);
            }
            func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
            if (e->used == 2)
                func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, k, 0);
        }
        func_021ED75C((char **)p, p[0x16]);
        func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
        func_021EC768(*(char * *)&((struct Obj00000 *)p)->f2C, e->id, 0);
    }
    func_021ED75C((char **)p, p[0x16]);
    func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
    return 1;
}













/*
 * Twin of src/matched/ov170_func_021DD930.c.
 */
int func_021DDAE8(unsigned char *p)
{
    Move_021DD684 *m = *(Move_021DD684 * *)&((struct Obj23839 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    Entry_021DD684 *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
            func_021EC548(e->slot, &t[1], &t[0], p[0x1A]);
            if (e->slot >= 0x1E)
                t[0] += 0x90;
            func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
        }
        func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
        func_021EC768(*(char * *)&((struct Obj00000 *)p)->f2C, e->id, 0);
        break;
    }
    func_021ED75C((char **)p, p[0x16]);
    func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
    return 1;
}













int func_021DDC00(unsigned char *p, unsigned a, unsigned b)
{
    unsigned m;
    if (b >= 0x24) {
        int n = func_021DD684(p, b - 0x24);
        if (n == p[0x14] || func_020078C4((void *)SYS(p)[1], n) == 0x1E) {
            RESULT(p) = 1;
            return 0;
        }
        if (a >= 0x1E) {
            if (func_021DD694((void ***)p, a - 0x1E) == 0) {
                RESULT(p) = 3;
                return 0;
            }
            if (func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], a - 0x1E), 6, 0)) == 1) {
                RESULT(p) = 2;
                return 0;
            }
        }
        m = 0;
    } else {
        m = func_021DD25C((void ***)p, b, p[0x14], 0xA9, 0);
    }
    if (SYS(p)[9] == 4) {
        if (SYS(p)[5] == 1) {
            RESULT(p) = 5;
            return 0;
        }
        if (a < 0x1E && b >= 0x1E && b < 0x24 && func_021DD25C((void ***)p, a, p[0x17], 0x4C, 0) != 0) {
            RESULT(p) = 4;
            return 0;
        }
        if (a >= 0x1E && a < 0x24 && b < 0x1E && m != 0 && func_021DD25C((void ***)p, b, p[0x14], 0x4C, 0) != 0) {
            RESULT(p) = 4;
            return 0;
        }
    }
    if (a >= 0x1E) {
        if (func_021DD694((void ***)p, a - 0x1E) == 0) {
            if (m == 0) {
                if ((b < 0x1E || b >= 0x24) && SYS(p)[9] != 4) {
                    RESULT(p) = 3;
                    return 0;
                }
            } else if (func_021DD25C((void ***)p, b, p[0x14], 0x4C, 0) != 0 && b < 0x1E && SYS(p)[9] != 4) {
                RESULT(p) = 3;
                return 0;
            }
        }
        if (b < 0x1E && func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], a - 0x1E), 6, 0)) == 1) {
            RESULT(p) = 2;
            return 0;
        }
    } else if (b >= 0x1E && m != 0) {
        if (func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], b - 0x1E), 6, 0)) == 1) {
            RESULT(p) = 2;
            return 0;
        }
        if (func_021DD25C((void ***)p, a, p[0x17], 0x4C, 0) != 0 && func_021DD694((void ***)p, b - 0x1E) == 0 && SYS(p)[9] != 4) {
            RESULT(p) = 3;
            return 0;
        }
    }
    RESULT(p) = 0;
    return 1;
}











/*
 * trailing: two bytes alignment padding at 0x021DDE7E.
 */
int func_021DDE20(unsigned char *p,unsigned a,unsigned b)
{
    int result = 0;
    if (func_021DD25C((void ***)p,(unsigned short)b,p[0x14],0xa9,0))
        return result;
    if (!func_021DD694((void ***)p,a-30))
        return result;
    if (func_0202136C((unsigned short)func_02017E1C(func_0201AB28((*(void ***)p)[2],a-30),6,0)) != 1)
        result = 1;
    return result;
}












int func_021DDE80(unsigned char *p, unsigned a, unsigned b)
{
    if (func_021DD25C((void ***)p, b, p[0x14], 0xA9, 0) == 0)
        return 0;
    if (func_021DD25C((void ***)p, b, p[0x14], 0x4C, 0) != 0)
        return 0;
    if (func_0202136C(func_021DD25C((void ***)p, a, p[0x14], 6, 0)) == 1)
        return 0;
    if (func_0202136C(func_021DD25C((void ***)p, b, p[0x14], 6, 0)) == 1)
        return 0;
    return 1;
}












void func_021DDEFC(unsigned char *p, Obj *o)
{
    short t[2];
    func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + o->idx + 0x3DD2), &o->x, &o->y, 0);
    if (o->f6 != 2) {
        if (o->slot < 0x24)
            func_021EC548(o->slot, &t[1], &t[0], p[0x1A]);
        else
            func_021EDA70((int)(*(char * *)&((struct Obj00000 *)p)->f2C), o->slot - 0x24, &t[1], &t[0]);
    } else if (p[0x14] > p[0x17]) {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, 0, &t[1], &t[0], 0);
    } else {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, 1, &t[1], &t[0], 0);
    }
    if (o->x <= t[1]) {
        o->dx = 1;
        o->vx = ((t[1] - o->x) << 16) / 8;
    } else {
        o->dx = -1;
        o->vx = ((o->x - t[1]) << 16) / 8;
    }
    if (o->y <= t[0]) {
        o->dy = 1;
        o->vy = ((t[0] - o->y) << 16) / 8;
    } else {
        o->dy = -1;
        o->vy = ((o->y - t[0]) << 16) / 8;
    }
}










void func_021DDFD4(unsigned char *p,Obj_021DDFD4 *o)
{
    short t[2];
    unsigned i;
    i=*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+o->slot+0x3dd2);
    func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C,*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+o->idx+0x3dd2),&o->x,&o->y,0);
    func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C,i,&t[1],&t[0],0);
    if(o->x<=t[1]){
        o->dx=1;
        o->vx=((t[1]-o->x)<<16)/8;
    }else{
        o->dx=-1;
        o->vx=((o->x-t[1])<<16)/8;
    }
    if(o->y<=t[0]){
        o->dy=1;
        o->vy=((t[0]-o->y)<<16)/8;
    }else{
        o->dy=-1;
        o->vy=((o->y-t[0])<<16)/8;
    }
}











void func_021DE07C(unsigned char *p, Obj_021DE07C *o)
{
    short t[2];
    func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + o->idx + 0x3DD2), &o->x, &o->y, 0);
    func_021EC548(o->slot, &t[1], &t[0], p[0x1A]);
    t[0] += 0xC0;
    if (o->x <= t[1]) {
        o->dx = 1;
        o->vx = ((t[1] - o->x) << 16) / 8;
    } else {
        o->dx = -1;
        o->vx = ((o->x - t[1]) << 16) / 8;
    }
    if (o->y <= t[0]) {
        o->dy = 1;
        o->vy = ((t[0] - o->y) << 16) / 8;
    } else {
        o->dy = -1;
        o->vy = ((o->y - t[0]) << 16) / 8;
    }
}








/*
 * Program the two 4-short descriptor pairs (0x24, arg2, arg1, 1)
 *   of the p+0x2c+0x60 block and publish each.
 */
void func_021DE120(char *p, int a, int b)
{
    unsigned short *q = *(unsigned short **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x60);
    q[0] = 0x24;
    q[1] = b;
    q[2] = a;
    q[3] = 1;
    func_021DDEFC((unsigned char *)p, (Obj *)q);
    q[12] = (unsigned short)b;
    q[13] = a;
    q[14] = (unsigned short)b;
    q[15] = 1;
    func_021DDEFC((unsigned char *)p, (Obj *)(q + 12));
}








int func_021DE158(unsigned char *p, unsigned a, unsigned b)
{
    Move_021DE158 *m = *(Move_021DE158 * *)&((struct Obj23841 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned i;
    unsigned n;
    unsigned short t;
    Entry_021DE158 *e;
    for (i = 0; i < 7; i++) {
        m->e[i].id = 0;
        m->e[i].slot = 0;
        m->e[i].src = 0;
        m->e[i].used = 0;
    }
    m->req = b;
    if (b == 0xFF) {
        m->a = 0xFF;
        m->b = 0xFF;
        m->e[0].id = 0x24;
        t = a;
        m->e[0].slot = t;
        m->e[0].src = t;
        m->e[0].used = 1;
        if (p[0x14] == p[0x17]) {
            m->e[1].id = t;
            m->e[1].slot = t;
            m->e[1].src = t;
            m->e[1].used = 1;
        }
        func_021DDEFC(p, (Obj *)(&m->e[0]));
        return 0;
    }
    if ((a == b && (a >= 0x1E || p[0x14] == p[0x17])) || func_021DDC00(p, a, b) == 0) {
        m->a = 0xFF;
        m->b = 0xFF;
        m->e[0].id = 0x24;
        t = a;
        m->e[0].slot = t;
        m->e[0].src = t;
        m->e[0].used = 1;
        m->e[1].id = t;
        m->e[1].slot = t;
        m->e[1].src = t;
        m->e[1].used = 1;
        func_021DDEFC(p, (Obj *)(&m->e[0]));
        return 0;
    }
    m->a = a;
    m->b = b;
    n = func_0201AA18(((void **)((struct Obj00000 *)p)->f0)[2]);
    if (b >= 0x24) {
        m->e[0].id = 0x24;
        m->e[0].slot = b;
        m->e[0].src = 0x24;
        m->e[0].used = 1;
        func_021DDEFC(p, (Obj *)(&m->e[0]));
        if (a >= 0x1E) {
            for (i = a - 0x1D; i < n; i++) {
                e = &m->e[i];
                t = i + 0x1E;
                e->id = t;
                e->slot = i + 0x1D;
                e->src = t;
                e->used = 1;
                func_021DE07C(p, (Obj_021DE07C *)e);
            }
            e = &m->e[n];
            t = a;
            e->id = t;
            e->slot = n + 0x1D;
            e->src = t;
            e->used = 1;
            func_021DE07C(p, (Obj_021DE07C *)e);
        }
        return 1;
    }
    if (p[0x14] != p[0x17] && a < 0x1E) {
        if (b >= 0x1E && b > n + 0x1E)
            b = n + 0x1E;
        m->e[0].id = 0x24;
        t = b;
        m->e[0].slot = t;
        m->e[0].src = a;
        m->e[0].used = 1;
        m->e[1].id = t;
        m->e[1].slot = t;
        m->e[1].src = t;
        m->e[1].used = 2;
        func_021DDEFC(p, (Obj *)(&m->e[0]));
        func_021DDEFC(p, (Obj *)(&m->e[1]));
        return 1;
    }
    if (a < 0x1E) {
        if (b < 0x1E)
            func_021DE120((char *)p, a, b);
        else if (b - 0x1E < n)
            func_021DE120((char *)p, a, b);
        else
            func_021DE120((char *)p, a, n + 0x1E);
    } else if (b < 0x1E) {
        if (func_021DD25C((void ***)p, b, p[0x14], 0xA9, 0) != 0) {
            func_021DE120((char *)p, a, b);
        } else {
            unsigned k = a - 0x1E;
            for (i = k + 1; i < n; i++) {
                e = &m->e[i];
                t = i + 0x1E;
                e->id = t;
                e->slot = i + 0x1D;
                e->src = t;
                e->used = 1;
                func_021DDEFC(p, (Obj *)e);
            }
            m->e[k].id = 0x24;
            m->e[k].slot = b;
            m->e[k].src = a;
            m->e[k].used = 1;
            func_021DDEFC(p, (Obj *)(&m->e[k]));
            e = &m->e[n];
            t = b;
            e->id = t;
            e->slot = n + 0x1D;
            e->src = t;
            e->used = 1;
            func_021DDEFC(p, (Obj *)e);
        }
    } else if (b - 0x1E < n) {
        func_021DE120((char *)p, a, b);
    } else {
        unsigned k = a - 0x1E;
        for (i = k + 1; i < n; i++) {
            e = &m->e[i];
            t = i + 0x1E;
            e->id = t;
            e->slot = i + 0x1D;
            e->src = t;
            e->used = 1;
            func_021DDEFC(p, (Obj *)e);
        }
        m->e[k].id = 0x24;
        m->e[k].slot = n + 0x1D;
        m->e[k].src = a;
        m->e[k].used = 1;
        func_021DDEFC(p, (Obj *)(&m->e[k]));
    }
    return 1;
}







/*
 * Sibling of src/matched/ov170_func_021DE158.c.
 */
void func_021DE428(unsigned char *p, unsigned a, unsigned b)
{
    Move *m = *(Move * *)&((struct Obj23843 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned i;
    unsigned n;
    unsigned short t;
    Entry *e;
    for (i = 0; i < 7; i++) {
        m->e[i].id = 0;
        m->e[i].slot = 0;
        m->e[i].src = 0;
        m->e[i].used = 0;
    }
    if (b == 0xFF || func_021DDE20(p, a, b) == 0) {
        m->a = 0xFF;
        m->b = 0xFF;
        m->e[0].id = 0x24;
        t = a;
        m->e[0].slot = t;
        m->e[0].src = t;
        m->e[0].used = 1;
        m->e[1].id = t;
        m->e[1].slot = t;
        m->e[1].src = t;
        m->e[1].used = 1;
        func_021DDEFC(p, (Obj *)(&m->e[0]));
        return;
    }
    m->a = a;
    m->b = b;
    n = func_0201AA18(((void **)((struct Obj00000 *)p)->f0)[2]);
    if (b < 0x1E) {
        unsigned k = a - 0x1E;
        for (i = k + 1; i < n; i++) {
            e = &m->e[i];
            t = i + 0x1E;
            e->id = t;
            e->slot = i + 0x1D;
            e->src = t;
            e->used = 1;
            func_021DDFD4(p, (Obj_021DDFD4 *)e);
        }
        m->e[k].id = 0x24;
        m->e[k].slot = b;
        m->e[k].src = a;
        m->e[k].used = 1;
        func_021DDFD4(p, (Obj_021DDFD4 *)(&m->e[k]));
        e = &m->e[n];
        t = b;
        e->id = t;
        e->slot = n + 0x1D;
        e->src = t;
        e->used = 1;
        func_021DDFD4(p, (Obj_021DDFD4 *)e);
    }
}




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))







/*
 * Clears the seven move slots, then either starts a slide from a to b or,
 * when b is not a movable box, snaps to it.
 */
void func_021DE530(unsigned char *p, int a, int b)
{
    Obj_021DE530 *o = *(Obj_021DE530 **)(WORK(p) + 0x60);
    unsigned i;
    for (i = 0; i < 7; i++) {
        o[i].idx = 0;
        o[i].slot = 0;
        o[i].f4 = 0;
        o[i].f6 = 0;
    }
    if (b == 0xFF || func_021DD25C((void ***)p, b, p[0x14], 0xA9, 0)) {
        ((struct Obj01418 *)o)->fAC = 0xFF;
        ((struct Obj01418 *)o)->fB0 = 0xFF;
        o[0].idx = 0x24;
        o[0].slot = a;
        o[0].f4 = a;
        o[0].f6 = 1;
        o[1].idx = a;
        o[1].slot = a;
        o[1].f4 = a;
        o[1].f6 = 1;
        func_021DDEFC(p, (Obj *)((Obj_021DE530 *)o));
    } else {
        ((struct Obj01418 *)o)->fAC = a;
        ((struct Obj01418 *)o)->fB0 = b;
        func_021DE120((char *)p, a, func_0201AA18(((struct Obj23845 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8) + 0x1E);
    }
}







int func_021DE5C8(char *p, unsigned id)
{
    Entry_021DE530 *e = *(Entry_021DE530 * *)&((struct Obj23846 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned i;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0 && id == e[i].id)
            return e[i].val;
    }
    return ((unsigned char *)p)[0x16];
}






void func_021DE5F8(unsigned char *p,unsigned a)
{
    Obj_021DE5F8 *o;
    unsigned i;
    unsigned slot;
    o=*(Obj_021DE5F8 * *)&((struct Obj23847 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    slot=a-30;
    for(i=0;i<6;i++){
        o[i].idx=i+30;
        o[i].slot=i+30;
        o[i].f4=i+30;
        o[i].f6=0;
    }
    o[i].f6=0;
    for(i=slot+1;i<6;i++){
        o[i].slot=i+29;
        o[i].f6=1;
        func_021DDEFC(p, (Obj *)((Obj_021DE530 *)(&o[i])));
    }
    o[slot].slot=35;
    o[slot].f6=1;
    func_021DDEFC(p, (Obj *)((Obj_021DE530 *)(&o[slot])));
}







void func_021DE66C(char *p, Entry_021DE5F8 *e)
{
    unsigned char buf[7];
    unsigned short i;
    unsigned short save = 0xFFFF;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0)
            buf[i] = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e[i].src + 0x3DD2);
    }
    for (i = 0; i < 7; i++) {
        if (e[i].used == 0)
            continue;
        if (e[i].slot <= 0x24) {
            *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e[i].slot + 0x3DD2) = buf[i];
            if (e[i].id == 0x24)
                save = e[i].slot;
        } else {
            ((struct Obj23848 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f3DF6 = buf[i];
            if (e[i].id == 0x24)
                save = 0x24;
        }
    }
    if (save != 0xFFFF)
        func_021ECBD8((unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C), save);
    for (i = 0; i < 0x24; i++)
        func_021EC768(*(char * *)&((struct Obj00000 *)p)->f2C, i, 1);
}






/*
 * Return -1.
 */
int func_021DE720(unsigned short a)
{
    return -1;
}



#undef WORK


#undef WORK

#undef WORK


#define WORK(p) (*(char **)((p) + 0x2C))






void func_021DE728(unsigned char *p)
{
    State_021DE728 *s;
    void *m;
    unsigned i;
    int r;
    *(State_021DE728 * *)&((struct Obj23849 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190=func_02030734(0x804c,12,0,d_021F1400,0xa70);
    s=*(State_021DE728 * *)&((struct Obj23850 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190;
    s->p=*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C+*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+p[0x16]+0x3dd2)*4+0x9e74);
    s->f4=0;
    s->flags=0;
    m=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
    for(i=0;i<4;i++){
        r=func_021DE720((unsigned short)func_02017E88(m,i+0x36,0));
        if(r!=-1){s->flags|=(unsigned char)(1<<r);return;}
    }
}







/*
 * Tail call func_020307B0 with the pooled-offset word.
 */
void func_021DE7B4(char *p)
{
    func_020307B0(((struct Obj18453 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190);
}






/*
 * lever: Spell the byte-mask update as plain assignment; compound assignment inserts an extra truncation pair.
 */
int func_021DE7C8(unsigned char *p)
{
    State_021DE7C8 *s=*(State_021DE7C8 * *)&((struct Obj23851 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190;
    unsigned short n=s->index;
    unsigned j,i;
    void *m;
    int box,r,slot;
    if(n==726)return 0;
    for(j=0;j<15;j++){
        if(n<720){
            box=n/30;
            slot=n%30;
            if(box==p[0x14]&&slot==p[0x16]) m=0;
            else m=(void *)func_021DD2D0((void ***)p,box,slot);
        }else{
            slot=n-720;
            if(slot==p[0x16]-30)m=0;
            else m=(void *)func_021DD2D0((void ***)p,255,slot);
        }
        if(m&&func_02017E88(m,0xa9,0)!=0){
            for(i=0;i<4;i++){
                r=func_021DE720((unsigned short)func_02017E88(m,i+0x36,0));
                if(r!=-1)s->flags=s->flags & (255^(1<<r));
            }
        }
        ++s->index;
        n=s->index;
        if(n==726)return 0;
    }
    return 1;
}







/*
 *   func_02012F98 (0x02012F98) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_021DE898(int *q)
{
    int *r = *(int * *)&((struct Obj18454 *)q)->f0;

    if ((((struct Obj09222 *)r)->f24 - 4) > 1)
        func_02007C34((struct PerapVoice *)func_02012F98((void *)(((struct Obj09222 *)r)->f0)), (void *)(((struct Obj09222 *)r)->f8));
}






void func_021DE8B4(unsigned char *p, int slot, unsigned idx, int mode, int flag)
{
    Mover_021DE8B4 *o = *(Mover_021DE8B4 * *)&((struct Obj23852 *)(*(char * *)&((struct Obj10648 *)p)->f2C))->f60;
    short pos[2];
    short to[2];
    int d;
    func_021EC0B0(*(char * *)&((struct Obj10648 *)p)->f2C,10,&pos[1],&pos[0],0);
    func_021EC548(idx,&to[1],&to[0],mode);
    if(flag==1){to[1]+=8;to[0]+=8;}else{to[0]+=4;}
    o->idx=idx;
    o->slot=slot;
    ((struct Obj10649 *)o)->f18&=3;
    o->mode=mode;
    {
        int tx=to[1];
        int px=pos[1];
        int ty;
        int py;
        if(px>tx){o->left=1;d=px-tx;}else{o->left=0;d=tx-px;}
        o->vx=(d<<8)/8;
        ty=to[0];
        py=pos[0];
        if(py>ty){((struct Obj10649 *)o)->f18|=2;d=py-ty;}
        else{((struct Obj10649 *)o)->f18&=~2;d=ty-py;}
        o->vy=(d<<8)/8;
        o->x=px<<8;
        o->y=py<<8;
    }
}







void func_021DE980(unsigned char *p, int mode)
{
    Mover_021DE980 *o = *(Mover_021DE980 **)(WORK(p) + 0x60);
    short pos[2];
    short to[2];
    int d;
    func_021EC0B0(WORK(p), 10, &pos[1], &pos[0], 0);
    if (p[0x14] > p[0x17])
        func_021EC0B0(WORK(p), 0, &to[1], &to[0], 0);
    else
        func_021EC0B0(WORK(p), 1, &to[1], &to[0], 0);
    o->idx = 0xFF;
    o->slot = 0xFF;
    FLAGS(o) &= 3;
    o->mode = mode;
    {
        int tx = to[1];
        int px = pos[1];
        int ty;
        int py;
        if (px > tx) {
            o->left = 1;
            d = px - tx;
        } else {
            o->left = 0;
            d = tx - px;
        }
        o->vx = (d << 8) / 8;
        ty = to[0];
        py = pos[0];
        if (py > ty) {
            FLAGS(o) |= 2;
            d = py - ty;
        } else {
            FLAGS(o) &= ~2;
            d = ty - py;
        }
        o->vy = (d << 8) / 8;
        o->x = px << 8;
        o->y = py << 8;
    }
}






/*
 * Same call with the fifth argument fixed to 1.
 */
void func_021DEA3C(int a, int b, int c, int d)
{
    func_021DE8B4((unsigned char *)a, b, c, d, 1);
}






void func_021DEA4C(char *p, int a, int b)
{
    func_021DE8B4((unsigned char *)p, *(unsigned char *)(*(int *)&((struct Obj10648 *)p)->f2C + 0xA17E), a, b, 0);
}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))






/*
 * extent: final two bytes are zero alignment padding.
 */
int func_021DEA6C(char *p, int a)
{
    Motion *m;
    m = *(Motion **)(WORK(p) + 0x60);
    if (m->count == 8) {
        if (m->index != 255) {
            if (a == 1)
                func_021ED164(WORK(p), m->index, m->value);
            else
                func_021ED198(WORK(p), m->index, m->value);
        }
        func_021ED310(WORK(p));
        return 0;
    }
    if (m->dirX == 0)
        m->x += m->dx;
    else
        m->x -= m->dx;
    if (m->dirY == 0)
        m->y += m->dy;
    else
        m->y -= m->dy;
    func_021ED14C((int)WORK(p), (short)(m->x >> 8), (short)(m->y >> 8));
    func_021ED310(WORK(p));
    m->count++;
    return 1;
}







/*
 * Set the flag on the object.
 */
int func_021DEAFC(int a)
{
    return func_021DEA6C((char *)a, 1);
}







/*
 * Steps the object with mode 0 (sibling of func_021DEAFC, which passes 1).
 */
int func_021DEB08(unsigned char *p)
{
    return func_021DEA6C((char *)p, 0);
}






/*
 * Add the 3rd/4th parameter to the signed byte at +0x19 and fold the
 * +0x15 field in: add it when negative (signed), subtract it when the
 * result is at or above the unsigned byte.
 */
unsigned char func_021DEB14(unsigned char *p, int a)
{
    signed char v = (signed char)p[0x19] + a;
    if (v < 0)
        v = v + (signed char)p[0x15];
    else if (v >= p[0x15])
        v = v - (signed char)p[0x15];
    return v;
}







void func_021DEB40(u32 a, int b, void *c)
{
    void *out;
    void *r;

    r = func_02049DB4(0x74, b + 0xe, 1, (u32)(&out), 0x4c);
    func_02040B1C(3, (const void *)(((struct Obj12153 *)out)->f14), ((struct Obj12153 *)out)->f10, (u32)c);
    func_020307B0(r);
}






/*
 * Tail wrapper: builds the 6-argument NitroSystem call with the
 *   two stack words 0x20 and 0x4c; third argument shifted left 5.
 */
void func_021DEB70(int a, int b, int c)
{
    func_02049B40(0x74, b + 0x26, 0, c << 5, 0x20, 0x4c);
}






/*
 * abi: Original truncates the tile column into r2 before both call kinds, so their column parameters are u8.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`data=(u32)sheet;` before `data=(u32)sheet+12;`). Game code has no line
 * table, so these were stand-ins. The plain single assignment gives EXACT in
 * --lang c99 and --lang c: the output bytes do not change. Older text in
 * this header that asks for the double assignment is superseded.
 */
void func_021DEB90(void *unused, void *unused2, int x, u32 base, u32 pal)
{
    u8 *sheet;
    void *handle;
    u16 value;
    u32 data;
    u8 row,yn;
    u16 *src;
    u32 cur,high;
    u8 col;
    handle=func_02049EB4(116,13,1,(u32)&sheet,76);
    data=(u32)sheet+12;
    row=0;
    high=pal<<12;
    do{
        src=(u16 *)data+row*21;
        cur=x;
        col=0;
        yn=row+1;
        do{
            value=(src[col]&4095)+high+base;
            func_02041090(3,(u32)&value,(u8)cur,yn,1,1);
            ++cur;if(cur>=64)cur=0;
            ++col;
        }while(col<21);
        ++row;
    }while(row<20);
    func_020307B0(handle);
    func_02041300(3,0xe287,cur,0,2,20,17);
    func_02041300(3,0xe2b0,cur,5,2,1,17);
}






void func_021DEC64(void *a, void *b, int c, void *d, int e)
{
    func_021DEB40((int)a, (int)b, d);
    func_021DEB70((int)a, (int)b, e);
    func_021DEB90(a, b, c, (unsigned int)d, e);
    func_02041B6C(3);
}







void func_021DEC98(char *p, void *a, int dir)
{
    int d, e, i;
    char *q;
    if (dir == 0) {
        ((struct Obj23854 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 -= 0x17;
        if (((struct Obj23855 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 < 0)
            ((struct Obj23856 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 += 0x40;
    } else if (dir == 1) {
        ((struct Obj23857 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 += 0x17;
        if (((struct Obj23858 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 >= 0x40)
            ((struct Obj23859 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 -= 0x40;
    }
    q = *(char * *)&((struct Obj00000 *)p)->f2C;
    if (((struct Obj14262 *)q)->fA179 == 0) {
        d = 0x25C;
        e = 0xE;
    } else {
        d = 0xB8;
        e = 0xF;
    }
    ((struct Obj14262 *)q)->fA179 ^= 1;
    func_021DEC64((void *)p, a, ((struct Obj23860 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178, (void *)d, e);
    if (dir == 2) {
        func_021EB7E8((char **)p, (unsigned char)p[0x14], 7);
        func_021EE224(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
        return;
    }
    i = 7;
    if (func_021EE234((int *)(*(char * *)&((struct Obj00000 *)p)->f2C), 7) == 1)
        i = 8;
    func_021EB7E8((char **)p, (unsigned char)p[0x14], i);
    func_021EE244(*(char * *)&((struct Obj00000 *)p)->f2C, i, dir);
    func_021EE224(*(char * *)&((struct Obj00000 *)p)->f2C, i, 1);
}






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(Work_021DE728 **)((p) + 0x2C))






void func_021DED58(char *p, int a)
{
    int offset;
    int bank;
    if (WORK(p)->flip == 0) {
        offset = 0x25C;
        bank = 14;
    } else {
        offset = 0xB8;
        bank = 15;
    }
    WORK(p)->flip ^= 1;
    func_021DEB40((unsigned int)p, a, (void *)offset);
    func_02021640(*(void **)((char *)WORK(p) + 0x6C), 0x74, a + 0x26, 0x4C, 0, 0x20, bank << 4);
    func_021DEB90(p, (void *)a, WORK(p)->box, offset, bank);
    func_02041B6C(3);
}







/*
 * Forward the second word of the head object.
 */
int func_021DEDCC(char *p, int box)
{
    return func_0200781C(((struct Obj18456 *)(*(char * *)&((struct Obj18455 *)p)->f0))->f4, box);
}






/*
 * Allocates the 0x1C-byte summary of a Pokemon (species, form, PID,
 * markings, level, flags, four moves); NULL for an empty slot.
 */
Summary *func_021DEDD8(void *mon)
{
    Summary *s;
    unsigned i;

    if (func_02017E88(mon, 0xA9, 0) != 0) {
        s = func_02030734(0x4C, 0x1C, 0, d_021F1400, 0xCD2);
        s->mon = mon;
        s->species = func_02017E88(mon, 5, 0);
        s->form = func_02017E88(mon, 6, 0);
        s->pid = func_02017E88(mon, 0, 0);
        s->cC = func_02017E88(mon, 0xAE, 0);
        s->cD = func_02017E88(mon, 0xAF, 0);
        s->cE = func_02017E88(mon, 0xA, 0);
        s->cF = func_020185A0(mon);
        s->item = func_02017E88(mon, 0xB, 0);
        s->level = func_02017E88(mon, 0x9E, 0);
        s->egg = (unsigned char)func_02017E88(mon, 0x4C, 0);
        if (s->egg == 0)
            s->gender = func_02017F08(mon);
        else
            s->gender = 0;
        if (func_02017EB4(mon) == 1)
            s->shiny = 1;
        else
            s->shiny = 0;
        if (func_0201B268(mon) == 1)
            s->mark = 1;
        else if (func_0201B28C(mon) == 1)
            s->mark = 2;
        else
            s->mark = 0;
        if (s->species != 0x1D && s->species != 0x20 && s->egg == 0)
            s->showgender = 1;
        else
            s->showgender = 0;
        for (i = 0; i < 4; i++)
            s->moves[i] = func_02017E88(mon, 0x36 + i, 0);
    } else {
        s = 0;
    }
    return s;
}






void func_021DEF58(void *s)
{
    func_020307B0(s);
}





/*
 * Six-step handover: stage 0xb, rebuild, refresh, push the 0x10
 *   tag word, re-tag, then release handle 3.
 */
void func_021DEF60(char *p, int a)
{
    func_021ECCCC(p, (void **)a, 0xb);
    func_021ED028((char *)(*(int *)&((struct Obj00000 *)p)->f2C), (unsigned char *)a);
    func_021EB2A4((u8 *)p, a);
    func_021DF11C(p, ((struct Obj18457 *)a)->f10);
    func_021DF144((char *)*(int *)&((struct Obj00000 *)p)->f2C, (Summary *)a);
    func_02041EE4(5, 3, 0);
}





int func_021DEF98(char *p, int a, unsigned b)
{
    void *mon;
    int state;
    void *s;
    mon = (void *)func_021DD2D0((void ***)p, a, b);
    if (mon) {
        state = func_02017DBC(mon);
        s = func_021DEDD8(mon);
        if (s) {
            func_021DEF60(p, (int)s);
            func_021DEF58(s);
            func_02017DE4(mon, state);
        } else {
            func_021DF040(p);
            func_02017DE4(mon, state);
            return 0;
        }
    } else {
        func_021DF040(p);
        return 0;
    }
    return 1;
}






/*
 * Forward with the byte field at +0x14.
 */
void func_021DEFEC(char *p, int b)
{
    func_021DEF98(p, ((struct Obj18458 *)p)->f14, b);
}





void func_021DEFF8(char *p, unsigned b)
{
    void *mon;
    void *s;
    int state;
    mon = (void *)func_021DD2D0((void ***)p, ((struct Obj00000 *)p)->f14, b);
    state = func_02017DBC(mon);
    s = func_021DEDD8(mon);
    func_021ECCCC(p, s, 11);
    func_021ED028(((struct Obj00000 *)p)->f2C, s);
    func_021EB2A4((u8 *)p, (int)s);
    func_021DEF58(s);
    func_02017DE4(mon, state);
}


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))







void func_021DF040(char *p)
{
    unsigned i;
    if (*(int *)(WORK(p) + 0x9EA0) != 0)
        func_021EC000(WORK(p), 0xB, 0);
    if (*(int *)(WORK(p) + 0x9EA4) != 0)
        func_021EC000(WORK(p), 0xC, 0);
    for (i = 0x1C; i < 0x2D; i++)
        func_021EC000(WORK(p), i, 0);
    func_021EB324(WORK(p));
    func_021DF128((int)WORK(p));
    func_021EC000(WORK(p), 0x19, 0);
    func_021EC000(WORK(p), 0x1A, 0);
    func_021EC000(WORK(p), 0x1B, 0);
    func_02041EE4(5, 3, 0xC0);
}






/*
 * Reset, clear the state, mark the 0x16 field.
 */
void func_021DF0BC(unsigned char *p)
{
    func_021DF040((char *)p);
    func_021ED6E4((char **)p, 0);
    p[0x16] = 0xff;
}






void func_021DF0D4(char *p,int base,u32 bits) { u16 i,v;for(i=0;i<6;i++){if(bits & (1<<i))v=i*2+1;else v=i*2;func_021EBFA8(*(char * *)&((struct Obj14263 *)p)->f2C,base+i,v);func_021EC000(*(char * *)&((struct Obj14263 *)p)->f2C,base+i,1);} }







void func_021DF110(char *p, int b)
{
    func_021DF0D4(p, 0xd, b);
}







/*
 * Forward with index 19.
 */
void func_021DF11C(char *p, int b)
{
    func_021DF0D4(p, 0x13, b);
}






/*
 * Seat the six 0x13 entries.
 */
void func_021DF128(int p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_021EC000((char *)p, i + 0x13, 0);
}






void func_021DF144(char *w, Summary *s)
{
    if (s->shiny == 0 || s->egg == 1)
        func_021EC000(w, 25, 0);
    else
        func_021EC000(w, 25, 1);
    if (s->mark == 0) {
        func_021EC000(w, 26, 0);
        func_021EC000(w, 27, 0);
    } else if (s->mark == 1) {
        func_021EC000(w, 26, 0);
        func_021EC000(w, 27, 1);
    } else {
        func_021EC000(w, 26, 1);
        func_021EC000(w, 27, 0);
    }
}






/*
 * Signed containment test: 1 when a is inside [r[0],r[1]] and b
 *   inside [r[2],r[3]).  Return-1 arm is the fall-through.
 */
int func_021DF1BC(int a, int b, unsigned char *r)
{
    if (a >= r[0] && a <= r[1] && b >= r[2] && b < r[3])
        return 1;
    return 0;
}







int func_021DF1DC(short x, int y)
{
    if (func_021DF1BC(x, y, (unsigned char *)d_021EF798) == 1) {
        if (x < 0xC)
            x = 0;
        else if (x >= 0x9C)
            x = 5;
        else
            x = (short)((x - 0xC) / 0x18);
        y -= 0x28;
        return x + (short)(y / 0x18) * 6;
    }
    return 0xFF;
}








/*
 * Scan the six 4-byte entries of the third argument; the first one that
 * func_021DF1BC accepts returns i + 0x1e, else 0xff.
 */
int func_021DF228(short x, short y, const unsigned char *r)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        if (func_021DF1BC(x, y, (unsigned char *)((const int *)r + i)) == 1)
            return i + 0x1e;
    return 0xff;
}






/*
 * Wrap the -1/0xff query into the 0xc0..0xff window and hand the
 *   wrapped value back; 0xff is the error.  The three byte fields are
 *   unsigned char (ldrb) and the comparison is unsigned (blo).
 */
int func_021DF254(unsigned char *p, short x, short y)
{
    int v = func_021EF224(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA180),
                          *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA184));
    unsigned w;
    if (v == 0xff)
        return v;
    w = v - 0x24 + p[0x19];
    if (w >= p[0x15])
        w -= p[0x15];
    if (w == p[0x14])
        return 0xff;
    return v;
}






int func_021DF288(char *p)
{
    Request_021DF040 *r;
    unsigned mode;
    r = func_02030734(0x4B, 0x28, 0, d_021F1400, 0xEAC);
    if (((struct Obj05437 *)p)->f16 < 30) {
        r->mon = (void *)func_021DD2D0((void ***)p, ((struct Obj05437 *)p)->f17, 0);
        r->kind = 2;
        r->count = 30;
        r->slot = ((struct Obj05437 *)p)->f16;
    } else {
        r->mon = (*(void ***)p)[2];
        r->kind = 1;
        r->count = func_0201AA18((*(void ***)p)[2]);
        r->slot = ((struct Obj05437 *)p)->f16 - 30;
    }
    mode = 0;
    r->zero = 0;
    r->save = (*(void ***)p)[0];
    r->f4 = (*(void ***)p)[6];
    r->f18 = (*(void ***)p)[7];
    if ((*(int **)p)[5] == 1) {
        r->mode = 6;
    } else {
        r->mode = 0;
    }
    func_02031348(((struct Obj05437 *)p)->f4, (int)ov131_id, d_021DC800, r);
    *(Request_021DF040 * *)&((struct Obj05437 *)p)->fC = r;
    return 0;
}






/*
 * Clamp p[0x16] to 0x1e below the limit of the p+0xc object's
 *   byte 0xf, then hand the object to the SDK.  The callee argument is the
 *   re-read expression, not the local, which is why the image re-loads it.
 */
int func_021DF324(char *p)
{
    int q = ((struct Obj04901 *)p)->fC;
    if (((struct Obj04901 *)p)->f18 == 0) {
        if (((struct Obj04901 *)p)->f16 < 0x1e)
            ((struct Obj04901 *)p)->f16 = ((struct Obj12155 *)q)->fF;
        else
            ((struct Obj04901 *)p)->f16 = ((struct Obj12155 *)q)->fF + 0x1e;
    }
    func_020307B0((void *)(((struct Obj04901 *)p)->fC));
    return 0;
}





int func_021DF348(void **p)
{
    void *r = func_0202E474((const struct BigObj *)(*(u32 *)p[0]), 0, 2, 0x4b);

    func_02031348(p[1], (u32)ov070_id, (void *)0x021bb96c, r);
    p[3] = r;
    return 0;
}





/*
 * Mirror a word into a halfword field, forward, return 0.
 */
int func_021DF378(char *p)
{
    char *q = *(char * *)&((struct Obj12156 *)p)->fC;

    ((struct Obj12156 *)p)->f10 = ((struct Obj18460 *)q)->f38;
    func_020307B0(q);
    return 0;
}




/*
 * data: callback descriptor belongs to ov194 loaded by func_02031348.
 */
int func_021DF38C(char *p)
{
    int value;
    Request_021DF378 *r;
    value = (int)func_0200C0F0(func_02012EBC((*(void ***)p)[0]));
    r = func_02030734(0x4B, 8, 1, d_021F1400, 0xF1F);
    r->text = func_020457B0(20, 0x4B);
    func_0200785C((*(void ***)p)[1], ((struct Obj10650 *)p)->f14, r->text);
    r->task = func_0216BFD4(0x4B, 2, 0, 0, 8, (int)r->text, value);
    func_02031348(((struct Obj10650 *)p)->f4, (int)ov194_id, d_021F5580, r->task);
    *(Request_021DF378 * *)&((struct Obj10650 *)p)->fC = r;
    return 0;
}

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))


int func_021DF404(u8 *p){char **q;q=*(char ** *)&((struct Obj06546 *)p)->fC;if(((struct Obj23861 *)(*q))->f1C==0)func_02007898(((struct Obj23862 *)(*(char * *)&((struct Obj06546 *)p)->f0))->f4,p[0x14],((struct Obj23863 *)(*q))->f20);((struct Obj06546 *)p)->f10=((struct Obj23864 *)(*q))->f1C;func_0216C0C0((int)*q);func_02045808((struct U16Vec *)q[1]);func_020307B0(((struct Obj06546 *)p)->fC);return 0;}



void func_021DF43C(char *p, int x, int y)
{
    func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, ((struct Obj23865 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f3DF6, (short)x, (short)((short)y - 8), 0);
    func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
    ((struct Obj23866 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA180 = x;
    ((struct Obj23867 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA184 = y;
}



int func_021DF484(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int busy = func_021EF400(p);
    unsigned r = func_021EF5C4(MGR(p));
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (func_02035C38() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (func_02035CB8(&x, &y) == 0) {
            *(unsigned char *)(WORK(p) + 0xA171) = 0;
            b->timer = 0;
            r = 0xFF;
            if (func_021EF770(MGR(p)) == 1) {
                func_021EE008((char *)p, 0, 0);
                r = func_021DF254(p, *(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184));
                if (r == 0xFF || func_021DE158(p, p[0x16], r) == 0) {
                    func_021EF75C(MGR(p));
                    func_020061E4(0x669);
                    b->state = 0xE;
                    break;
                }
            }
            if (func_021EF45C(MGR(p)) == 1) {
                r = func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
                if (r == 0xFF)
                    r = func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            }
            if (func_021EF480(MGR(p)) == 1)
                r = func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF7B4);
            if ((*(int **)p)[9] == 4 && (*(int **)p)[5] == 1) {
                r = 0xFF;
                *(unsigned char *)(WORK(p) + 0xA173) = 5;
            }
            func_021DE158(p, p[0x16], r);
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4((char **)p, 0);
            if (r != 0xFF)
                p[0x16] = func_021DE5C8((char *)p, 0x24);
            if (func_021EF45C(MGR(p)) == 0 && func_021EF770(MGR(p)) == 0 && busy == 0)
                func_021EF534(MGR(p));
            b->state = 2;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0) {
            if (func_021EF45C(MGR(p)) == 0 && func_021EF770(MGR(p)) == 0 && func_021EF248() == 0) {
                p[0x17] = 0xFF;
                p[0x1A] = 2;
                func_021EF3D8(MGR(p));
                func_020061E4(0x669);
                func_021ECB20((char *)p, 1, 0);
                func_021ED888(WORK(p), 1);
                func_021EE364((char **)p, 6, p[0x16]);
                if ((*(int **)p)[9] == 4)
                    func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
                func_021EE038((char *)p, 2, 1, 2);
                *(int *)(WORK(p) + 0xA168) = p[0x16];
                *(int *)(WORK(p) + 0x68) = 0x17;
            }
            if (b->timer == 0) {
                int dir = func_021EF1B4();
                if (dir == 0) {
                    func_020061E4(0x548);
                    func_021DD16C(p, 0);
                    b->state = 6;
                } else if (dir == 1) {
                    func_020061E4(0x548);
                    func_021DD16C(p, 1);
                    b->state = 7;
                }
            }
            if ((*(int **)p)[9] != 4) {
                if (func_021EF264() != -1) {
                    if (*(unsigned char *)(WORK(p) + 0xA171) == 0) {
                        if (func_021EF770(MGR(p)) == 1) {
                            func_021EF75C(MGR(p));
                            func_021DD090((Sys *)p, 0xA);
                            func_020061E4(0x54C);
                            func_020061E4(0x669);
                            *(unsigned char *)(WORK(p) + 0xA171) = 1;
                            b->state = 0xB;
                        }
                        if (func_021EF45C(MGR(p)) == 1) {
                            func_021EF3A0(MGR(p));
                            func_021DD090((Sys *)p, 0xB);
                            func_020061E4(0x54C);
                            func_020061E4(0x669);
                            *(unsigned char *)(WORK(p) + 0xA171) = 1;
                            b->state = 0xD;
                        }
                    }
                } else {
                    *(unsigned char *)(WORK(p) + 0xA171) = 0;
                }
            }
            if (func_021EF770(MGR(p)) == 1) {
                int dir = func_021EF1C4();
                if (dir == 0) {
                    func_020061E4(0x548);
                    func_021DD1C4((char *)p, -1);
                    b->state = 8;
                    b->timer = 0;
                } else if (dir == 1) {
                    func_020061E4(0x548);
                    func_021DD1C4((char *)p, 1);
                    b->state = 9;
                    b->timer = 0;
                }
            }
            if (func_021EF770(MGR(p)) == 1) {
                int k = func_021EF224(x, y);
                if (k != 0xFF)
                    func_021EE008((char *)p, k - 0x24, 1);
                else
                    func_021EE008((char *)p, 0, 0);
            }
        }
        func_021DF43C((char *)p, x, y);
        break;
    case 2:
        if (func_021DD930(p) == 0) {
            func_020061E4(0x667);
            b->state = 3;
        }
        break;
    case 3:
        if (busy == 0 && r == 0)
            b->state = 0x10;
        break;
    case 6:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 7:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 8:
        if (func_021E1A28((char *)p) == 0)
            b->state = 1;
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 9:
        if (func_021E19D4((char *)p) == 0)
            b->state = 1;
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 10:
        if (func_021E01C4((char *)p) == 0)
            b->state = 1;
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 11:
        func_021DCFC0((char *)p);
        if (func_021E01E0((char *)p) == 0) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 1);
            func_021EF680(WORK(p));
            func_021EF68C(WORK(p));
            func_020061E4(0x669);
            b->state = 0xC;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 12:
        if (busy == 0)
            b->state = 1;
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 13:
        func_021DCFC0((char *)p);
        if (busy == 0) {
            func_021DD1E8((char *)p);
            func_021EF69C(WORK(p));
            func_021EF670(WORK(p));
            func_020061E4(0x669);
            b->state = 0xA;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 16:
        func_021DE66C((char *)p, (Entry_021DE5F8 *)b->moves);
        if (func_021EF480(MGR(p)) == 1) {
            func_021ED7C4(WORK(p), p[0x16]);
            func_021ED6E4((char **)p, 1);
        } else {
            func_021ED6E4((char **)p, 0);
            func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16]);
            func_021EE3E4((char **)p, p[0x16]);
            func_021ED55C((char **)p, 1);
        }
        b->state = 0;
        return 0;
    case 14:
        if (func_021E01E0((char *)p) == 0) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_020061E4(0x669);
            b->state = 0xF;
        }
        break;
    case 15:
        if (busy == 0) {
            p[0x1A] = 2;
            func_021DE158(p, p[0x16], func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184))));
            func_021ED6E4((char **)p, 0);
            b->state = 2;
        }
        break;
    }
    return 1;
}



int func_021DFA30(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int busy = 0;
    unsigned r;
    unsigned x;
    unsigned y;
    if (b->state != 0xA && b->state != 0xB && b->state != 0xE) {
        if (func_0202CE40(MGR(p), 9) == 1)
            busy = func_021E01C4((char *)p);
    }
    r = func_021EF5C4(MGR(p));
    switch (b->state) {
    case 0:
        if (func_02035C38() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (func_02035CB8(&x, &y) == 0) {
            *(unsigned char *)(WORK(p) + 0xA171) = 0;
            r = 0xFF;
            if (func_021EF770(MGR(p)) == 1) {
                r = func_021DF254(p, *(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184));
                if (p[0x16] >= 0x1E && (r == 0xFF || func_021DE158(p, p[0x16], r) == 0)) {
                    func_021EF75C(MGR(p));
                    func_021EE008((char *)p, 0, 0);
                    func_020061E4(0x669);
                    b->state = 0xE;
                    break;
                }
            }
            if (func_021EF45C(MGR(p)) == 1)
                r = func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            if (r == 0xFF)
                r = func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (func_021DE158(p, p[0x16], r) == 0)
                r = 0xFF;
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4((char **)p, 0);
            if (r != 0xFF) {
                if (r >= 0x24)
                    p[0x16] = r - 2;
                else
                    p[0x16] = func_021DE5C8((char *)p, 0x24);
            } else {
                func_021EE008((char *)p, 0, 0);
            }
            if (func_021EF770(MGR(p)) == 0 && func_021EF45C(MGR(p)) == 0 && busy == 0)
                func_021EF534(MGR(p));
            if (r == 0xFF && p[0x16] < 0x1E && p[0x14] != p[0x17]) {
                r = func_021DD210(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                func_021EC35C((char **)p, p[0x14]);
                func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), r);
                if (r == 0)
                    b->state = 4;
                else
                    b->state = 5;
            } else {
                b->state = 2;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0 && func_021EF770(MGR(p)) == 0 && func_021EF45C(MGR(p)) == 0) {
            if (p[0x16] != func_021EF180(x, y)) {
                p[0x19] = p[0x14];
                func_021DD1E8((char *)p);
                func_020061E4(0x669);
                func_021EE364((char **)p, 4, p[0x16]);
                func_021EE038((char *)p, 2, 1, 2);
                *(int *)(WORK(p) + 0xA168) = p[0x16];
                *(int *)(WORK(p) + 0x68) = 0x17;
            }
        }
        if (b->timer == 0) {
            int dir = func_021EF1B4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD16C(p, 0);
                b->state = 6;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD16C(p, 1);
                b->state = 7;
            }
        }
        if (busy == 0 && r == 0) {
            if (func_021EF264() != -1) {
                if (*(unsigned char *)(WORK(p) + 0xA171) == 0) {
                    if (func_021EF770(MGR(p)) == 1) {
                        func_021EF75C(MGR(p));
                        func_021DD090((Sys *)p, 0xA);
                        func_020061E4(0x54C);
                        func_020061E4(0x669);
                        *(unsigned char *)(WORK(p) + 0xA171) = 1;
                        b->state = 0xB;
                    }
                    if (func_021EF45C(MGR(p)) == 1) {
                        func_021EF3A0(MGR(p));
                        func_021DD090((Sys *)p, 0xB);
                        func_020061E4(0x54C);
                        func_020061E4(0x669);
                        *(unsigned char *)(WORK(p) + 0xA171) = 1;
                        b->state = 0xD;
                    }
                }
            } else {
                *(unsigned char *)(WORK(p) + 0xA171) = 0;
            }
        }
        if (func_021EF770(MGR(p)) == 1) {
            int dir = func_021EF1C4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD1C4((char *)p, -1);
                b->state = 8;
                b->timer = 0;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD1C4((char *)p, 1);
                b->state = 9;
                b->timer = 0;
            }
        }
        if (func_021EF770(MGR(p)) == 1) {
            int k = func_021EF224(x, y);
            if (k != 0xFF)
                func_021EE008((char *)p, k - 0x24, 1);
            else
                func_021EE008((char *)p, 0, 0);
        }
        func_021DF43C((char *)p, x, y);
        break;
    case 4:
        if (func_021E00C4((char *)p) == 0)
            b->state = 2;
        break;
    case 5:
        if (func_021E0128((char *)p) == 0)
            b->state = 2;
        break;
    case 2:
        if (func_021DD930(p) == 0) {
            func_020061E4(0x667);
            b->state = 3;
        }
        break;
    case 3:
        if (busy == 0 && r == 0)
            b->state = 0x10;
        break;
    case 6:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 7:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 8:
        if (func_021E1A28((char *)p) == 0)
            b->state = 1;
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 9:
        if (func_021E19D4((char *)p) == 0)
            b->state = 1;
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 10:
        if (func_021E01C4((char *)p) == 0)
            b->state = 1;
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 11:
        func_021DCFC0((char *)p);
        if (func_021E01E0((char *)p) == 0) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 1);
            func_021EF680(WORK(p));
            func_021EF68C(WORK(p));
            func_020061E4(0x669);
            b->state = 0xC;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 12:
        if (func_021EF400(p) == 0) {
            p[0x1A] = 2;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 13:
        func_021DCFC0((char *)p);
        if (func_021EF400(p) == 0) {
            func_021DD1E8((char *)p);
            func_021EF69C(WORK(p));
            func_021EF670(WORK(p));
            func_020061E4(0x669);
            b->state = 0xA;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 14:
        if (func_021E01E0((char *)p) == 0) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_020061E4(0x669);
            b->state = 0xF;
        }
        break;
    case 15:
        if (func_021EF400(p) == 0) {
            func_021DE158(p, p[0x16], func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184))));
            func_021ED6E4((char **)p, 0);
            b->state = 2;
        }
        break;
    case 16:
        func_021DE66C((char *)p, (Entry_021DE5F8 *)b->moves);
        if (func_021EF770(MGR(p)) == 0 && func_021EF45C(MGR(p)) == 0) {
            func_021ED7C4(WORK(p), p[0x16]);
            func_021ED6E4((char **)p, 1);
        } else {
            func_021ED6E4((char **)p, 0);
            func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16]);
            func_021EE3E4((char **)p, p[0x16]);
            func_021ED55C((char **)p, 1);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}
