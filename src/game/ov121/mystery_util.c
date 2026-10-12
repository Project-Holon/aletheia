/*
 * file:     mystery_util.c
 * unit:     yes
 * function: func_021D9624, func_021D96C4, func_021D9718, func_021D972C, func_021D9738, func_021D9744, func_021D9750, func_021D9790, func_021D97B4, func_021D97C8, func_021D9828, func_021D9860, func_021D9864, func_021D986C, func_021D98C0, func_021D98E0, func_021D98E8, func_021D98F4, func_021D9960, func_021D9974, func_021D9994, func_021D99A4, func_021D9A40, func_021D9A58, func_021D9A64, func_021D9AC8, func_021D9B28, func_021D9B2C, func_021D9B34, func_021D9B9C, func_021D9BC0, func_021D9BE8, func_021D9CA4, func_021D9D4C, func_021D9E04, func_021D9E50, func_021D9F08, func_021D9F24, func_021D9FF8, func_021D9FFC, func_021DA010, func_021DA038, func_021DA148, func_021DA178, func_021DA1BC, func_021DA280, func_021DA2A8, func_021DA2C8, func_021DA2F0, func_021DA318, func_021DA338, func_021DA3C0, func_021DA3EC, func_021DA4A8, func_021DA4DC, func_021DA698, func_021DA6D0, func_021DA840, func_021DA84C, func_021DA854, func_021DA890, func_021DA898, func_021DA8AC, func_021DA8B0, func_021DA8B8, func_021DA8C0, func_021DA8C4, func_021DA8CC, func_021DA958, func_021DA978, func_021DA994, func_021DA9EC, func_021DA9F0, func_021DA9F8, func_021DAA28, func_021DAAA4, func_021DAB50, func_021DAC18, func_021DAE1C, func_021DAEF0, func_021DAFCC, func_021DB018, func_021DB3E8, func_021DB478, func_021DB528, func_021DB54C, func_021DB938, func_021DBA78, func_021DBA94, func_021DBC08, func_021DBCC8, func_021DBDB8, func_021DBDBC, func_021DBDF4, func_021DBEE4, func_021DBF04, func_021DBF08, func_021DBF10, func_021DBF40, func_021DBF70, func_021DBF9C, func_021DBFE4, func_021DC004, func_021DC024, func_021DC02C, func_021DC030, func_021DC03C, func_021DC064, func_021DC08C, func_021DC4F0, func_021DC734, func_021DC9CC, func_021DCCE4, func_021DCEC4, func_021DCF54, func_021DCFA4, func_021DCFC8, func_021DD1FC, func_021DD240, func_021DD24C
 * address:  0x021D9624
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
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
 *   d_021DFB8C 0x021DFB8C data a1
 *   d_021DF604 0x021DF604 data a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040588 0x02040588 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02050B80 0x02050B80 arm
 *   d_021DF598 0x021DF598 data a4
 *   func_02050ED4 0x02050ED4 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   d_021DF634 0x021DF634 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021DF5A8 0x021DF5A8 data a4
 *   d_021DF5C4 0x021DF5C4 data a4
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021D9580 0x021D9580 thumb ov121
 *   d_021DF574 0x021DF574 data a4
 *   d_021DF58C 0x021DF58C data a4
 *   d_021DF580 0x021DF580 data a4
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02050BE8 0x02050BE8 arm
 *   func_02047970  0x02047970  arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021DFBA0 0x021DFBA0 data a1
 *   func_020452E8  0x020452E8  arm
 *   func_02045808  0x02045808  arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045838 0x02045838 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_0203101C 0x0203101C arm
 *   func_02028470 0x02028470 thumb
 *   func_02031140 0x02031140 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0202F038 0x0202F038 thumb
 *   d_021DF78C 0x021DF78C data a4
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02043994 0x02043994 arm
 *   func_02043678 0x02043678 arm
 *   func_020437AC 0x020437AC arm
 *   func_02043814 0x02043814 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045874 0x02045874 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021DF7C0 0x021DF7C0 data a4
 *   d_021DF76C 0x021DF76C data a4
 *   d_021DF770 0x021DF770 data a4
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020257D0  0x020257D0  thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   d_020A1B38 0x020A1B38 data a4
 *   func_02061CA4 0x02061CA4 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0203084C 0x0203084C arm
 *   func_02040618 0x02040618 arm
 *   func_021DE0AC 0x021DE0AC thumb ov121
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF8FC 0x021DF8FC data a4
 *   d_021DF890 0x021DF890 data a4
 *   func_021DD980 0x021DD980 thumb ov121
 *   func_0200A348 0x0200A348 thumb
 *   func_020414EC 0x020414EC arm
 *   func_021DDF84 0x021DDF84 thumb ov121
 *   func_021DE0DC 0x021DE0DC thumb ov121
 *   func_021DD9CC 0x021DD9CC thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B604 0x0204B604 arm
 *   data_021DF86E 0x021DF86E data a1
 *   func_02040DA8 0x02040DA8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   d_021DF86E 0x021DF86E data ov121 a2
 *   d_021DF86F 0x021DF86F data ov121 a1
 *   func_02041300 0x02041300 arm
 *   func_020413B0 0x020413B0 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0200A094  0x0200A094  thumb
 *   func_0200A0E4  0x0200A0E4  thumb
 *   func_0200A000  0x0200A000  thumb
 *   func_0200A254  0x0200A254  thumb
 *   func_02020E60 0x02020E60 thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   d_021DF838 0x021DF838 data a4
 *   d_021DF848 0x021DF848 data a4
 *   func_02035C60 0x02035C60 arm
 *   func_021DDF5C 0x021DDF5C thumb ov121
 *   func_020061E4 0x020061E4 thumb
 *   func_0200A170 0x0200A170 thumb
 *   func_0207D658 0x0207D658 arm
 *   func_021DE014 0x021DE014 thumb ov121
 *   func_0200A0C8 0x0200A0C8 thumb
 *   func_0200A2B8 0x0200A2B8 thumb
 *   func_0200A2D8 0x0200A2D8 thumb
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0204B570 0x0204B570 arm
 *   d_021DF99C 0x021DF99C data a4
 *   func_02045994 0x02045994 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_020186C8 0x020186C8 thumb
 *   func_02017588 0x02017588 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017FA8 0x02017FA8 thumb
 *   func_0201808C 0x0201808C thumb
 *   func_020180F4 0x020180F4 thumb
 *   func_02018A00 0x02018A00 thumb
 *   func_02045A98 0x02045A98 arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_0202F2AC 0x0202F2AC thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_0202D060 0x0202D060 thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_0202D6F4 0x0202D6F4 thumb
 *   d_021DFA14 0x021DFA14 data a4
 *   d_021DF8C0 0x021DF8C0 data a4
 *   g0209DF08 0x0209DF08 data a1
 *   g0209DF0C 0x0209DF0C data a1
 *   gMsgBank 0x020A7370 data
 */
#include "../../matched/include/Obj13944.h"
#include "../../matched/include/Obj22873.h"
#include "../../matched/include/Obj13945.h"
#include "../../matched/include/Obj13946.h"
#include "../../matched/include/Obj13948.h"
#include "../../matched/include/Obj10413.h"
#include "../../matched/include/Obj01929.h"
#include "../../matched/include/Obj13950.h"
#include "../../matched/include/Obj22875.h"
#include "../../matched/include/Obj01057.h"
#include "../../matched/include/Obj22876.h"
#include "../../matched/include/Obj02179.h"
#include "../../matched/include/Obj08092.h"
#include "../../matched/include/Obj02180.h"
#include "../../matched/include/Obj00909.h"
#include "../../matched/include/Obj00236.h"
#include "../../matched/include/Obj22877.h"
#include "../../matched/include/Obj22878.h"
#include "../../matched/include/Obj01542.h"
#include "../../matched/include/Obj01731.h"
#include "../../matched/include/Obj06448.h"
#include "../../matched/include/Obj04493.h"
#include "../../matched/include/Obj02469.h"
#include "../../matched/include/Obj04494.h"
#include "../../matched/include/Obj08093.h"
#include "../../matched/include/Obj22879.h"
#include "../../matched/include/Obj22880.h"
#include "../../matched/include/Obj22881.h"
#include "../../matched/include/Obj13951.h"
#include "../../matched/include/Obj22882.h"
#include "../../matched/include/Obj13952.h"
#include "../../matched/include/Obj13953.h"
#include "../../matched/include/Obj22883.h"
#include "../../matched/include/Obj22884.h"
#include "../../matched/include/Obj03262.h"
#include "../../matched/include/Obj06449.h"
#include "../../matched/include/Obj22885.h"
#include "../../matched/include/Obj22886.h"
#include "../../matched/include/Obj22887.h"
#include "../../matched/include/Obj22888.h"
#include "../../matched/include/Obj13954.h"
#include "../../matched/include/Obj22889.h"
#include "../../matched/include/Obj03786.h"
#include "../../matched/include/Obj00360.h"
#include "../../matched/include/Obj06450.h"
#include "../../matched/include/Obj22893.h"
#include "../../matched/include/Obj13955.h"
#include "../../matched/include/Obj06451.h"
#include "../../matched/include/Obj08095.h"
#include "../../matched/include/Obj10414.h"
#include "../../matched/include/Obj10415.h"
#include "../../matched/include/Obj03787.h"
#include "../../matched/include/Obj22897.h"
#include "../../matched/include/Obj05358.h"
#include "../../matched/include/Obj02470.h"
#include "../../matched/include/Obj00910.h"
#include "../../matched/include/Obj01058.h"
#include "../../matched/include/Obj01153.h"
#include "../../matched/include/Obj10417.h"
#include "../../matched/include/Obj22899.h"
#include "../../matched/include/Obj00828.h"
#include "../../matched/include/Obj13956.h"
#include "../../matched/include/Obj13957.h"
#include "../../matched/include/Obj02834.h"
#include "../../matched/include/Obj22900.h"
#include "../../matched/include/Obj03788.h"
#include "../../matched/include/Obj10418.h"
#include "../../matched/include/Obj13958.h"
#include "../../matched/include/Obj22903.h"
#include "../../matched/include/Obj08097.h"
#include "../../matched/include/Obj06452.h"
#include "../../matched/include/Obj22905.h"
#include "../../matched/include/Obj00061.h"
#include "../../matched/include/Obj00169.h"
#include "../../matched/include/Obj00253.h"
#include "../../matched/include/Obj01930.h"
#include "../../matched/include/Obj22906.h"
#include "../../matched/include/Obj00237.h"

#define W(k) (*(u32 *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
struct DispVram;
struct Node;
struct DispConfig;
struct BgTemplate;
struct Cfg;
struct Bank;
struct Obj;
struct Light;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct MsgBank;
struct PrintSys;
struct Bmp;
struct StrObj;
struct Tcbl;
struct Rec3;
struct S02031140;
struct Blk;
struct Ctx;
struct Slot;
struct Src;
struct Obj020437AC;
struct Vec2;
struct Grid;
struct Param;
struct Sys;
struct Actor;
struct WordSet;
struct Obj_021DB938;
struct PtS;
struct Mon;
struct Strbuf;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { int a,b,c,d; } Config_021D9624;

typedef struct { u32 id; u32 config[8]; u32 a; u32 b; } Entry;

typedef signed short s16;

typedef struct { int x; int y; } Pair_021D9624;

typedef struct {u32 word[13];} Config_021D9BC0;

struct In {
    void *bank;
    u32 f4;
    u32 f8;
    u32 *fC_;
    u32 ids[4];
    u32 f20;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    s16 f2c;
    s16 f2e;
    u16 f30;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 *f3c;
};

struct Out_021D9624 {
    void *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u16 pad10;
    u16 pal[5];
    u16 pad1c[3];
    u16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    u16 f2c;
    u16 f2e;
    u16 f30;
    u16 pad32;
    u32 f34;
    u32 f38;
    u8 pad3c[0x24];
    u32 *f60;
};

struct Rec_021D9624 {
    u8 a;
    u8 b;
    u8 pad[6];
    void *h;
    u8 rest[12];
};

struct Tbl { struct Rec_021D9624 r[4]; };

struct Pt { s16 x; s16 y; };

typedef struct {int x,y;} TablePair;

typedef unsigned long long u64;

typedef struct {s16 x,y;} Position_021D9624;

typedef struct { void *win; s16 x,y; int z; int pal; u8 a,b; u16 c; int d; } Desc_021DA3EC;

typedef struct {u32 w[9];} Input;

typedef struct {u32 w[51];} Record_021D9624;

typedef struct {u32 w[12];} Desc_021DAB50;

typedef struct Obj_021DAE1C { char pad[0xa7c]; char *slots[12]; } Obj_021DAE1C;

typedef struct Item_021D9624 { char raw[0xdc]; } Item_021D9624;

typedef struct Obj_021DAEF0 { char pad[0x28]; Item_021D9624 items[12]; char tail[0xacc-0x28-12*0xdc]; volatile int index; } Obj_021DAEF0;

typedef struct {u8 x,y,pad[6];} Coord_021DC08C;
typedef union { u16 h[4]; Coord_021DC08C c; } Row;

typedef struct { u8 b[16]; } Tmp;

typedef union Rect_021D9624 { s16 h[4]; u8 b[8]; } Rect_021D9624;

typedef struct Cur_021D9624 { s16 x; s16 y; } Cur_021D9624;

typedef struct Pos { s16 x; s16 y; u8 pad[3]; u8 flag; } Pos;

typedef union Rect_021DB938 { u16 h[4]; u8 b[8]; } Rect_021DB938;

typedef signed char s8;

typedef struct Item_021DB938 {
    unsigned char raw[0xDC];
} Item_021DB938;

typedef struct Obj_021DB938 {
    unsigned char pad00[0xC];
    void *list;
    unsigned char pad10[0x14];
    u16 f24;
    unsigned char pad26[2];
    Item_021DB938 items[12];
    unsigned char pad[0xA7C - 0x28 - 12 * 0xDC];
    void *slots[12];
    unsigned char padAAC[0xAD4 - 0xAAC];
    int dirty;
} Obj_021DB938;

typedef struct Obj_021DBCC8 {
    unsigned char pad00[0xC];
    void *list;
    unsigned char pad10[0x10];
    void *ctx;
    u16 f24;
    unsigned char pad26[2];
    Item_021DB938 items[12];
    unsigned char pad[0xA7C - 0x28 - 12 * 0xDC];
    void *slots[12];
    unsigned char padAAC[4];
    void *desc;
    unsigned char padAB4[0xAD4 - 0xAB4];
    int dirty;
} Obj_021DBCC8;

typedef struct { u32 w[51]; } Record_021DB938;

typedef struct { u8 low:1; u8 flag:1; u8 rest:6; } Bits;

typedef struct {short x,y;} Position_021DC030;



typedef struct { u32 v[7]; u16 a,b,c,d; } Desc_021DC4F0;

typedef struct { short x,y; } Vec;

typedef struct { u8 x,y,pad[6]; } Coord_021DC4F0;

typedef struct {u32 v[7];u16 a,b,c,d;} Desc_021DC734;

typedef struct { u8 pad[0xAC8]; u32 row; u32 col; } Cur_021DC030;

typedef struct {u32 v[7];u16 a,b,c,d;} Desc_021DCCE4;

typedef struct {u32 w[12];} Desc_021DCFC8;

typedef struct {u32 w[30];} Config;

typedef struct {s16 x,y,z;u8 a,b;} Record_021DCFC8;

typedef signed int     s32_021DCFC8;

typedef int s32_021DD24C;

typedef struct { u32 w[51]; } Record_021DD24C;

typedef struct { u32 f0; u32 f4; void *f8; u32 fC; u16 f10; u16 f12; u16 f14; u16 pad; } DE;

typedef struct { DE e[5]; } Desc_021DD24C;

struct Rec_021DC030 {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10;
    u16 mv[4];
    u16 species;
    u8 form;
    u8 f1D;
    u16 f1E;
    u8 pad20[0x14];
    u8 f34;
    u8 f35;
    u8 f36;
    u8 f37;
    u16 f38;
    u16 f3A;
    u8 f3C;
    u8 f3D;
    u8 f3E;
    u8 f3F;
    u8 f40;
    u8 f41;
    u8 pad42;
    u8 iv0, iv1, iv2, iv6, iv7, iv3;
    u8 pad49;
    u16 f4A;
    u8 pad4C[0xE];
    u8 f5A;
    u8 f5B;
    u8 f5C;
    u8 pad5D[0x4F];
    u32 fAC;
    u8 padB0[2];
    u8 fB2;
    u8 fB3;
    u8 fB4a:1;
    u8 fB4b:1;
};

struct Ctx {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
};

struct CtxB {
    u32 f0;
    u8 pad4[0xB4];
    u32 fB8;
    u32 fBC;
    u32 fC0;
    u32 fC4;
    u32 fC8;
    u32 fCC;
};

struct Out_021DC030 {
    u8 pad0[0xE0];
    u32 fE0;
    u16 fE4;
    u16 fE6;
    u8 padE8[0x118 - 0xE8];
    u16 heap;
    u8 pad11A[2];
    struct CtxB *b;
    struct Rec_021DC030 *a;
    void *c;
    u8 pad128[0xC];
    u32 f134;
    u32 f138;
    void *f13C;
    void *f140;
    void *f144;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const void *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const void *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void (*)(void *,u8 *),void *,int);
extern void func_02030EAC(void *n);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FC28(const void *cfg);
extern void func_02050B80(u32 heap);
extern void func_02050ED4(void);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FCA0(u32 bgId, const void *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const void *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(void *a0, u32 a1, u32 heap);
extern void func_0204B258(void *bank, void *p);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204B084(void *);
extern u32 func_0204B1CC(void *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021D9580(void);
extern void func_02046440(int, int, int, int, int, u32, void (*)(void));
extern void *func_02048A24(int, int, int, int, int, int, int, int, const void *, const void *, const void *, u32);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_02047964(void *);
extern void func_02048AD0(void *l);
extern void func_020479D8(void);
extern void func_02050BE8(void);
extern void func_02047970(void);
extern void *func_020457B0(u32, u16);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *buf, u8 value);
extern void func_02045334(void *d);
extern void func_02045374(void *cfg);
extern u8 func_02045730(void *p);
extern void func_020409B4(u32);
extern u32 func_020452E8(void *d);
extern void func_02045808(void *vec);
extern void func_020456F8(void *d);
extern void func_02045CAC(void *bank, u32 index, void *dest);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045838(void *dst, void *src);
extern u32 func_0201C6C4(void *p, void *v);
extern void func_02041B6C(unsigned);
extern u16 func_020437DC(const void *bmp);
extern u16 func_020437E4(const void *bmp);
extern u32 func_0201D304(void *s, u32 a, u32 b);
extern u32 func_0201D42C(void *s, void *font);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02028470(void *p, u32 v);
extern void func_0201CE48(void *p);
extern void func_0202F038(void *);
extern int func_02028604(int a0);
extern void func_02031140(void *p);
extern void func_0201F7A8(void *, u32);
extern void func_020286C4(void *ctx, void *p, void *cell);
extern s32 func_02028484(void *blk, void *h);
extern void func_020310C4(void *p);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0201C6FC(void *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void *func_02028590(u32,u32,u32,u32);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,u32,u32,u32,u32,int, void *,u32,u16,u16);
extern void func_0201F73C(void *, int, int, int);
extern void *func_0201F81C(u32,u32);
extern void func_0201F878(void *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct Obj *func_0201FF30(void *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(void *p, int heap);
extern void func_02020D10(void *p, u32 v);
extern void func_0202020C(void *o, void *a, void *b);
extern u32 func_0201F868(void *p);
extern s32 func_020200CC(void *o);
extern u32 func_02020350(void *obj, u32 what);
extern u8 func_02043994(void *b);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(void *p);
extern void func_02043814(void *dst, const void *src);
extern void *func_02045EC0(void *bank, u32 index);
extern struct U16Vec *func_02045874(void *src, u32 heapId);
extern void func_0204B404(void *p, const void *delta, u32 which);
extern void func_0204B3DC(void *p, u32 v);
extern void func_0204B878(void *p, u16 value);
extern void func_0204B92C(void *p, u32 v);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020061E4(u32 a);
extern u64 _u32_div_f(u32,u32);
extern struct Grid *func_020255A0(void *sys, const void *param);
extern void func_0202570C(void *g);
extern void func_020257D0(void *o);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_02082A7C(int, void *,int);
extern void *func_0203084C(u32 heapId);
extern void func_02040618(u32,u32,u32);
extern u32 func_0200A348(void *);
extern u32 func_0200A0E4(void *p, u32 a);
extern int func_0200A000(void *p, int idx, void *buf);
extern void func_021DE0AC(void *p, u32 b);
extern void func_021DD980(void *);
extern void func_020414EC(u32);
extern void func_021DDF84(void *);
extern void func_021DE0DC(void *p);
extern void func_021DD9CC(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern unsigned int func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern s32 func_0204AC18(void *, u32, u32, u32, u16, u16, u16);
extern s32 func_0204AF28(void *, u32, u32, u32);
extern s32 func_0204A6C8(void *, u32, u32, u32, u16);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B604(void *actor, u32 which, u32 set);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0204B3B4(void *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0201EFA4(void *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(void *ws, void *dst, void *src);
extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
extern void func_020413B0(u32,u32,u32,u8,u8,u8);
extern void func_0204B6F4(void *o, u32 v, u32 flag);
extern void func_0204B454(void *actor, void *out, u16 space);
extern void func_0200A094(void *list, u32 idx);
extern void func_0200A254(void *, u32, u32);
extern void func_0201C7A4(void *,s16,s16, void *, void *);
extern u32 func_02020E60(u16,u32);
extern u32 func_0201BB5C(u32,u32,u32,u32);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern int func_02035C60(void);
extern void func_021DDF5C(void *p);
extern int func_0200A170(void *p);
extern void func_0207D658(u32,int,int);
extern int func_021DE014(void *p);
extern u32 func_0200A0C8(void *p);
extern void func_0200A2B8(void *a0, int a1);
extern int func_0200A2D8(void *a0, int a1);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *,int);
extern s32_021DCFC8 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern void func_0204B688(void *actor, u32 value);
extern int func_0202D7C8(int a0);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern int func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D81C(void *,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void func_0204B570(void *actor, u32 value);
extern void func_02045994(void *o, const void *src, u32 len);
extern u32 func_020056EC(u32 range);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const void *obj);
extern void *func_020173F0(u16 species, u16 level, u32 otId, u32 a3, u32 heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(void *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017FA8(void *p);
extern u32 func_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, int move);
extern void func_02018A00(void *p, u32 species, u32 arg);
extern u16 func_02045A98(void);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const void *obj);
extern void *func_020185F0(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_020185C4(void *p);
extern int func_0202D060(void);
extern u32 func_02017EAC(void *p);
extern s32_021DD24C func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_020185F4(void *p);
extern u32 func_0202D6F4(void *a0, void *mon, u32 a2, u32 a3);
u8 *func_021D9624(int arg,u16 heap);
void func_021D96C4(u8 *p);
void func_021D9718(u8 *p);
void func_021D972C(char *p);
void func_021D9738(char *p);
unsigned func_021D9744(char *p);
void func_021D9750(u8 *p);
void func_021D9790(char *p);
void func_021D97B4(void *a, u8 *q);
void func_021D97C8(void *p, u32 a);
void func_021D9828(void *p);
void func_021D9860(void *a0);
void func_021D9864(void *a0);
void func_021D986C(void **p, u32 a, u32 heap);
void func_021D98C0(u8 *p);
void func_021D98E0(void *a0);
void func_021D98E8(void *a0);
unsigned func_021D98F0(unsigned *p);
void func_021D98F4(u32 *p, u32 heap);
void func_021D9960(char *p);
void func_021D9974(void **p);
void func_021D9994(void **p);
void *func_021D99A4(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap);
void func_021D9A40(u8 *p);
void func_021D9A58(u8 *p);
void func_021D9A64(u8 *p, u16 a, int b, int c);
void func_021D9AC8(u8 *p, int a, int b);
void func_021D9B28(u8 *p,unsigned v);
void func_021D9B2C(char *p, u32 a, u32 b, int c);
int func_021D9B34(u8 *p);
void func_021D9B9C(u8 *p);
void func_021D9BC0(const u8 *p,int a,Pair_021D9624 *out);
void func_021D9BE8(u32 mode, const Pair_021D9624 *in, const void *bitmap, void *obj, int a, Pair_021D9624 *out);
void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
void *func_021D9D4C(int a, u8 b, void *c, void *d, u16 heap);
void func_021D9E04(u8 *p);
void func_021D9E50(u8 *p);
void func_021D9F08(u8 *a, int b, int c, int d);
void func_021D9F24(u8 *p,int mode);
unsigned func_021D9FF8(u8 *p);
void func_021D9FFC(u8 *p, int a, int b);
void func_021DA010(u8 *p);
void *func_021DA038(const u8 *p,u16 heap);
void func_021DA148(u8 *p);
int func_021DA178(char *p);
void *func_021DA1BC(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,u16 e,int f,u16 heap);
void func_021DA280(u8 *p);
void func_021DA2A8(u8 *p);
int func_021DA2C8(u8 *p);
void func_021DA2F0(u8 *p,u32 i);
void func_021DA318(u8 *p);
void *func_021DA338(char *p,u16 heap);
void func_021DA3C0(u8 *p);
void func_021DA3EC(char *p,char *desc,void *dst);
void func_021DA4A8(u8 *p);
struct Out_021D9624 *func_021DA4DC(const struct In *in, u16 heap);
void func_021DA698(u8 *p);
int func_021DA6D0(u8 *p);
int func_021DA840(void **p);
void func_021DA84C(u8 *p,u32 i,u32 value);
void *func_021DA854(void *a,void *b,u16 heap);
void func_021DA890(void *p);
void func_021DA898(char *p);
int func_021DA8AC(u32 *p);
void func_021DA8B0(u32 *p,u32 a);
void func_021DA8B8(u32 *p);
void func_021DA8C0(u32 *p,u32 a);
void func_021DA8C4(u32 *p);
void *func_021DA8CC(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap);
void func_021DA958(u8 *p);
void func_021DA978(char *p);
void func_021DA994(char *p,int a,int b,int c);
void func_021DA9EC(u8 *p,int a);
void func_021DA9F0(u32 *p,u32 a,u32 b,u32 c);
int func_021DA9F8(u8 *p);
void func_021DAA28(char *p,int a,int *out);
s32 func_021DAAA4(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);
void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
char *func_021DAC18(const Input *src,u16 heap);
void func_021DAE1C(Obj_021DAE1C *obj);
void func_021DAEF0(Obj_021DAEF0 *obj);
void func_021DAFCC(char *p);
int func_021DB008(char *p);
void func_021DB018(u8 *p, u16 heap);
void func_021DB3E8(char *p);
void func_021DB478(char *p,int a,int b,int c,u16 heap);
void func_021DB528(char *p,int a);
void func_021DB54C(char *p, int a, int b, int c, u16 index, u16 heap);
void func_021DB938(char *p,int a,u16 index);
void func_021DBA78(u8 *p,int a);
int func_021DBA94(char *p);
void func_021DBC08(Obj_021DB938 *o, int idx);
void func_021DBCC8(Obj_021DBCC8 *o, u32 a, u32 b);
int func_021DBDB8(char *p);
u32 func_021DBDBC(u32 p);
void func_021DBDF4(char *out,const Record_021DB938 *src,char *p,u16 heap);
void func_021DBEE4(u32 p);
int func_021DBF04(int *p);
void *func_021DBF08(void *p);
void *func_021DBF10(void *p,u16 heap);
u32 func_021DBF40(void *p);
u32 func_021DBF70(void *p);
int func_021DBF9C(void *p);
int func_021DBFE4(void *p);
int func_021DC004(void *p);
int func_021DC024(void *p);
char *func_021DC02C(void *p);
int func_021DC030(u32 p);
int func_021DC03C(void *p);
int func_021DC064(void *p);
void func_021DC08C(void *task,u32 *state,char *p);
void func_021DC4F0(void *task,u32 *state,u8 *p);
void func_021DC734(void *task,u32 *state,char *p);
void func_021DC9CC(void *task,u32 *state,char *p);
void func_021DCCE4(void *arg,u32 *state,char *p);
void func_021DCEC4(void *arg,int *state,char *p);
void func_021DCF54(char *p,void *arc,int id,int index,u8 other,u16 heap);
void func_021DCFA4(u8 *p,int b,int c,u16 d);
void *func_021DCFC8(const Desc_021DCFC8 *p,u16 heap);
void func_021DD1FC(void **p);
int func_021DD240(void **p);
struct Out_021DC030 *func_021DD24C(Record_021DD24C *a, struct CtxB *b, void *c, u16 heap);
extern const char d_021DFB8C[];
extern const int d_021DF604[];
extern const Config_021D9624 d_021DF598;
extern const Entry d_021DF634[];
extern const u32 d_021DF5A8[];
extern const u32 d_021DF5C4[];
extern const u32 d_021DF574[];
extern const u32 d_021DF58C[];
extern const u32 d_021DF580[];
extern const char d_021DFBA0[];
extern const Config_021D9BC0 d_021DF78C;
extern const struct Tbl d_021DF7C0;
extern const TablePair d_021DF76C[];
extern const TablePair d_021DF770[];
extern const s16 d_020A1B38[];
extern char d_021DFBB0[],d_021DF8FC[],d_021DF890[];
extern const Row data_021DF86E[];
extern const u8 d_021DF86E[];
extern const u8 d_021DF86F[];
extern const int d_021DF838[];
extern const int d_021DF848[];
extern char d_021DFBB0[];
extern const Config d_021DF99C;
extern const Desc_021DD24C d_021DFA14;
extern const u32 d_021DF8C0[];
extern u8 g0209DF08;
extern u8 g0209DF0C;
extern void *gMsgBank;






/*
 * volatile: hardware reads at 021D9654 and 021D965E
 */
u8 *func_021D9624(int arg,u16 heap)
{
    u8 *p;
    p=func_02030734(heap,28,0,d_021DFB8C,448);
    func_02082BCC(p,0,28);
    ((struct Obj13944 *)p)->f18=heap;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021DF604);
    func_0204363C(arg);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021D97C8(p,heap);
    func_021D986C((void **)(p+4),(u32)d_021DF604,heap);
    ((struct Obj13944 *)p)->f14=func_020056A0(func_021D97B4,p,0);
    return p;
}






/*
 * volatile: hardware reads at 021D96EA and 021D96F4
 */
void func_021D96C4(u8 *p)
{
    func_02030EAC(((struct Obj22873 *)p)->f14);
    func_021D98C0(p+4);
    func_021D9828(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,28);
    func_020307B0(p);
}







/*
 * Addresses are Black-image addresses.
 */
void func_021D9718(u8 *p)
{
    func_021D98E0(p + 4);
    func_021D9860(p);
}






void func_021D972C(char *p) { func_021D9974((void **)(p+12)); }






void func_021D9738(char *p) { func_021D9994((void **)(p+12)); }






unsigned func_021D9744(char *p) { return func_021D98F0((unsigned *)(p+4)); }






void func_021D9750(u8 *p)
{
    Config_021D9624 c;
    func_02040588(0,0);
    c=d_021DF598;
    c.d=1;
    func_0203FC28((const struct DispConfig *)(&c));
    func_021D98F4((u32 *)(p+12),((struct Obj13945 *)p)->f18);
    func_02050B80(((struct Obj13945 *)p)->f18);
}







void func_021D9790(char *p) { func_02040588(0,0);func_02050ED4();func_021D9960(p+12);func_0203FC28((const struct DispConfig *)&d_021DF598); }








void func_021D97B4(void *a, u8 *q)
{
    func_021D9864(q);
    func_021D98E8(q + 4);
}







void func_021D97C8(void *p, u32 a)
{
    u32 i;
    const Entry *e;
    u32 id;
    i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(a);
    func_02045088(a);
    func_0203FC28((const struct DispConfig *)&d_021DF598);
    do {
        e = &d_021DF634[i];
        id = e->id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)e->config, (u8)e->a);
        func_020414AC((u8)id);
        func_02040588((u8)id, (u8)e->b);
        ++i;
    } while (i < 7);
}







/*
 * note: u8 extern parameter reproduces original truncation before BLX.
 */
void func_021D9828(void *p) {
    u32 i=0;
    do { func_020403F4((u8)d_021DF634[i].id); ++i; } while(i<7);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p,0,4);
}







/*
 * note: two trailing zero alignment bytes.
 */
void func_021D9860(void *a0) {}







void func_021D9864(void *a0) { func_020419E4(); }







void func_021D986C(void **p, u32 a, u32 heap)
{
    void *q;
    func_02082BCC(p, 0, 8);
    func_0204A48C((const struct Cfg *)d_021DF5A8, a, heap);
    p[0] = func_0204B100(128, 0, heap);
    q = func_0204B034((unsigned char *)d_021DF5C4, 2, heap);
    p[1] = q;
    func_0204B258(p[0], q);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}







void func_021D98C0(u8 *p) {
    func_0204B084(((struct Obj13946 *)p)->f4);
    func_0204B1CC(((struct Obj13946 *)p)->f0);
    func_0204A5AC();
    func_02082BCC(p,0,8);
}







void func_021D98E0(void *a0) { func_0204A600(); }







/*
 * note: tail wrapper plus unlabelled getter follower; seed 021D98F0.
 */
void func_021D98E8(void *a0) { func_0204A648(); }







unsigned func_021D98F0(unsigned *p) { return *p; }







void func_021D98F4(u32 *p, u32 heap)
{
    func_02046440(0, 1, 0, 1, 0, heap, func_021D9580);
    p[0] = (u32)func_02048A24(2, 0x18000, -0x18000, -0x20000, 0x20000, 0x1000, 0x400000, 0,
                         d_021DF574, d_021DF58C, d_021DF580, heap);
    p[1] = 1;
}








void func_021D9960(char *p)
{
    ((struct Obj13948 *)p)->f4 = 0;
    func_02048AC4(((struct Obj13948 *)p)->f0);
    func_02046788();
}







void func_021D9974(void **p) {
    if(((struct Obj10413 *)p)->f4) {
        func_02047964(((struct Obj10413 *)p)->f4);
        func_02048AD0(((struct Obj10413 *)p)->f0);
        func_020479D8();
        func_02050BE8();
    }
}








void func_021D9994(void **p)
{
    if (p[1])
        func_02047970();
}







void *func_021D99A4(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap)
{
    u8 *p;
    void *q;
    p = func_02030734(heap, 0x28, 0, d_021DFBA0, 0x55);
    func_02082BCC(p, 0, 0x28);
    ((struct Obj01929 *)p)->f8 = h;
    ((struct Obj01929 *)p)->f14 = b;
    ((struct Obj01929 *)p)->f16 = 0x440;
    ((struct Obj01929 *)p)->f24 = a;
    ((struct Obj01929 *)p)->f10 = func_020457B0(0x200, heap);
    q = (void *)func_020450F0((u8)b, (u16)c, (u16)d, (u8)e, f, g, 1);
    ((struct Obj01929 *)p)->fC = q;
    ((struct Obj01929 *)p)->f0 = q;
    p[4] = 0;
    func_02043B5C(func_02045770(q), ((struct Obj01929 *)p)->f16 & 31);
    if (((struct Obj01929 *)p)->f24 == 0) {
        func_02045334(((struct Obj01929 *)p)->fC);
        func_02045374(((struct Obj01929 *)p)->fC);
        func_020409B4(func_02045730(((struct Obj01929 *)p)->fC));
    }
    return p;
}








void func_021D9A40(u8 *p)
{
    func_020452E8(((struct Obj13950 *)p)->fC);
    func_02045808(((struct Obj13950 *)p)->f10);
    func_020307B0(p);
}







void func_021D9A58(u8 *p) { func_020456F8(((struct Obj22875 *)p)->fC); }







/*
 * extent: two zero padding bytes at 0x021D9AC6.
 */
void func_021D9A64(u8 *p, u16 a, int b, int c)
{
    Pair_021D9624 xy;
    void *q;
    func_02043B5C(func_02045770(((struct Obj01057 *)p)->fC), ((struct Obj01057 *)p)->f16 & 31);
    func_02045CAC((struct MsgBank *)a, b, ((struct Obj01057 *)p)->f10);
    func_021D9BC0(p, c, &xy);
    q = ((struct Obj01057 *)p)->f8;
    func_0201C724(q, (u32)func_02045770(((struct Obj01057 *)p)->f0), (s16)xy.x, (s16)xy.y,
                 (u32)(((struct Obj01057 *)p)->f10), c, ((struct Obj01057 *)p)->f16);
    p[4] = 1;
}







/*
 * extent: two zero padding bytes at 0x021D9B26.
 */
void func_021D9AC8(u8 *p, int a, int b)
{
    Pair_021D9624 xy;
    void *q;
    func_02043B5C(func_02045770(((struct Obj01057 *)p)->fC), ((struct Obj01057 *)p)->f16 & 31);
    func_02045838(((struct Obj01057 *)p)->f10, (struct U16Vec *)a);
    func_021D9BC0(p, b, &xy);
    q = ((struct Obj01057 *)p)->f8;
    func_0201C724(q, (u32)func_02045770(((struct Obj01057 *)p)->f0), (s16)xy.x, (s16)xy.y,
                 (u32)(((struct Obj01057 *)p)->f10), b, ((struct Obj01057 *)p)->f16);
    p[4] = 1;
}







void func_021D9B28(u8 *p,unsigned v) { ((struct Obj22876 *)p)->f16=v; }








void func_021D9B2C(char *p, u32 a, u32 b, int c)
{
    *(u32 *)(p + 0x18) = a;
    *(u32 *)(p + 0x1c) = b;
    *(u32 *)(p + 0x20) = c;
}







int func_021D9B34(u8 *p)
{
    u32 q;
    if (((struct Obj02179 *)p)->f24 == 0) {
        q = ((struct Obj02179 *)p)->f8;
        if (p[4]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj02179 *)p)->f0);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (func_0201C6C4((struct PrintSys *)(((struct Obj02179 *)p)->f8), (void *)((u32)func_02045770((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0)
                p[4] = 0;
        }
        if (p[4] == 0) return 1;
        return 0;
    }
}







void func_021D9B9C(u8 *p) {
    func_02045334(((struct Obj08092 *)p)->fC);
    if(((struct Obj08092 *)p)->f24==1) {
        func_02045374(((struct Obj08092 *)p)->fC);
        func_02041B6C(func_02045730(((struct Obj08092 *)p)->fC));
    }
}






/*
 * note: const record pointer settles stack-store schedule;
 *       two trailing zero alignment bytes.
 */
void func_021D9BC0(const u8 *p,int a,Pair_021D9624 *out) {
    void *bitmap=func_02045770(((struct Obj01057 *)p)->fC);
    func_021D9BE8(((struct Obj01057 *)p)->f20,(const Pair_021D9624 *)(p+0x18),bitmap,((struct Obj01057 *)p)->f10,a,out);
}






/*
 * extent: two zero padding bytes at 0x021D9CA2.
 * lever: the two-coordinate copy in case 0 is a Pair_021D9624 assignment.
 */
void func_021D9BE8(u32 mode, const Pair_021D9624 *in, const void *bitmap, void *obj, int a, Pair_021D9624 *out)
{
    int x;
    int y;
    switch (mode) {
    case 0:
        *out = *in;
        return;
    case 1:
        x = (u32)func_020437DC(bitmap) / 2;
        y = (u32)func_020437E4(bitmap) / 2;
        x -= func_0201D304(obj, a, 0) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = x + in->x;
        out->y = y + in->y;
        return;
    case 2:
        y = (u32)func_020437E4(bitmap) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = in->x;
        out->y = y + in->y;
        return;
    case 3:
        x = func_020437DC(bitmap);
        x -= func_0201D304(obj, a, 0);
        if (x < 0) x = 0;
        out->x = x + in->x;
        out->y = in->y;
        break;
    }
}






static inline void *allocate(u16 heap, u32 size, const char *site, u16 line)
{
    return func_02030734(heap, size, 0, site, line);
}






/*
 * lever: final push 2026-10-05 G3L5. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, func_020457B0 second, func_0203101C first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order
 *   (lsls of the line constant after the heap load). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov177 func_021E8568.
 */
void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    void *q;
    p = allocate(heap, 0x40, d_021DFBA0, 0x184);
    func_02082BCC(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    *(void **)(p + 0x14) = func_020457B0(0x300, heap);
    q = (void *)func_020450F0((u8)a, 1, 19, 30, 4, b, 1);
    *(void **)(p + 0x10) = q;
    *(void **)(p + 0x1c) = q;
    p[0x20] = 0;
    func_02043B5C(func_02045770(*(void **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(void **)(p + 0x10);
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    *(void **)(p + 0xc) = func_0203101C(heap, heap, 1, 32);
    return p;
}






/*
 * lever: final push 2026-10-05 G4L9. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, func_020457B0 second, func_0203101C first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order. See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov121 func_021D9CA4.
 */
void *func_021D9D4C(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    struct Descriptor *q;
    p = func_02030734(heap, 0x40, 0, d_021DFBA0, 0x1ae);
    func_02082BCC(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    func_02028470(p + 0x34, 2);
    *(struct U16Vec **)(p + 0x14) = func_020457B0(0x200, heap);
    q = (struct Descriptor *)func_020450F0((u8)a, 1, 21, 30, 2, b, 1);
    *(struct Descriptor **)(p + 0x10) = q;
    *(struct Descriptor **)(p + 0x1c) = q;
    p[0x20] = 0;
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(struct Descriptor **)(p + 0x10);
    func_02045334(q);
    func_02045374((struct Cfg *)q);
    func_020409B4(func_02045730(q));
    *(struct Tcbl **)(p + 0xc) = func_0203101C(heap, heap, 1, 32);
    return p;
}






void func_021D9E04(u8 *p)
{
    if (((struct Obj02180 *)p)->f8) {
        func_0201CE48(((struct Obj02180 *)p)->f8);
        ((struct Obj02180 *)p)->f8 = 0;
    }
    if (((struct Obj02180 *)p)->f3C) {
        func_0202F038(((struct Obj02180 *)p)->f3C);
        ((struct Obj02180 *)p)->f3C = 0;
    }
    if (((struct Obj02180 *)p)->f30) func_02028604((int)(((struct Obj02180 *)p)->f30));
    func_02031140(((struct Obj02180 *)p)->fC);
    func_0201F7A8(((struct Obj02180 *)p)->f10, 0);
    func_020452E8(((struct Obj02180 *)p)->f10);
    func_02045808(((struct Obj02180 *)p)->f14);
    func_020307B0(p);
}






/*
 * extent: two trailing zero padding bytes at 0x021D9F06.
 */
void func_021D9E50(u8 *p)
{
    u32 q;
    switch (((struct Obj00909 *)p)->f28) {
    case 2:
        q = ((struct Obj00909 *)p)->f24;
        if (p[0x20]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00909 *)p)->f1C))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj00909 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        break;
    case 0:
        q = ((struct Obj00909 *)p)->f24;
        if (p[0x20]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00909 *)p)->f1C))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj00909 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        ((struct Obj00909 *)p)->f2C = p[0x20] == 0 ? 1 : 0;
        break;
    case 1:
        if (((struct Obj00909 *)p)->f8) {
            if (((struct Obj00909 *)p)->f30)
                func_020286C4((struct Ctx *)(((struct Obj00909 *)p)->f30), (void *)(((struct Obj00909 *)p)->f8), (void *)(((struct Obj00909 *)p)->f10));
            if (func_02028484((struct Blk *)(p + 0x34), (void *)(((struct Obj00909 *)p)->f8)))
                ((struct Obj00909 *)p)->f2C = 1;
        }
        break;
    case 3:
        break;
    }
    func_020310C4((struct Tcbl *)(((struct Obj00909 *)p)->fC));
}







void func_021D9F08(u8 *a, int b, int c, int d)
{
    func_02045CAC((struct MsgBank *)b, c, ((struct Obj00236 *)a)->f14);
    func_021D9F24(a, d);
}






void func_021D9F24(u8 *p,int mode)
{
    u32 q;
    func_02043B5C(func_02045770(((struct Obj00236 *)p)->f10),((struct Obj00236 *)p)->f18);
    if(((struct Obj00236 *)p)->f8) {
        func_0201CE48(((struct Obj00236 *)p)->f8);
        ((struct Obj00236 *)p)->f8=0;
    }
    if(((struct Obj00236 *)p)->f30) {
        func_02028604((int)(((struct Obj00236 *)p)->f30));
        ((struct Obj00236 *)p)->f30=0;
    }
    func_021DA010(p);
    switch(mode) {
    case 2:
        ((struct Obj00236 *)p)->f3C=func_0202EE30((void *)func_020056BC(),((struct Obj00236 *)p)->f10,((struct Obj00236 *)p)->f18,16,((struct Obj00236 *)p)->f1A);
        q=((struct Obj00236 *)p)->f24;
        func_0201C6FC((struct PrintSys *)q,(u32)func_02045770(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 0:
        q=((struct Obj00236 *)p)->f24;
        func_0201C6FC((struct PrintSys *)q,(u32)func_02045770(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 1:
        func_02028470(p+0x34,2);
        ((struct Obj00236 *)p)->f30=func_02028590(((struct Obj00236 *)p)->f18,1,0,((struct Obj00236 *)p)->f1A);
        ((struct Obj00236 *)p)->f8=func_0201CCE4(((struct Obj00236 *)p)->f10,0,0,*(u32 *)&((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4,func_02012FFC(),((struct Obj00236 *)p)->fC,0,((struct Obj00236 *)p)->f1A,((struct Obj00236 *)p)->f18);
        ((struct Obj00236 *)p)->f28=1;
        break;
    }
    ((struct Obj00236 *)p)->f2C=0;
}






unsigned func_021D9FF8(u8 *p) { return ((struct Obj22877 *)p)->f2C; }







void func_021D9FFC(u8 *p, int a, int b)
{
    func_0201F73C(((struct Obj22878 *)p)->f10, 0, a, b);
}






void func_021DA010(u8 *p) { ((struct Obj00236 *)p)->f2C=1; if(*(u8 * *)&((struct Obj00236 *)p)->f3C) { func_0202F038(*(u8 * *)&((struct Obj00236 *)p)->f3C); *(u32 *)&((struct Obj00236 *)p)->f3C=0; func_02045374(((struct Obj00236 *)p)->f10); func_020409B4(func_02045730(((struct Obj00236 *)p)->f10)); } }






/*
 * lever: const source parameter and the original heap stack argument to 0201F878.
 */
void *func_021DA038(const u8 *p,u16 heap)
{
    u8 *out;
    void *q;
    u32 i;
    Config_021D9BC0 cfg;
    out=func_02030734(heap,24,0,d_021DFBA0,0x2cb);
    func_02082BCC(out,0,24);
    ((struct Obj01731 *)out)->f4=((struct Obj01542 *)p)->f8;
    ((struct Obj01731 *)out)->f0=(void *)func_020450F0((u8)(((struct Obj01542 *)p)->f1C),(u16)19,(u16)((u8)(17-(u8)(((struct Obj01542 *)p)->f18*2))),(u8)12,(u8)(((struct Obj01542 *)p)->f18*2),((struct Obj01542 *)p)->f1E,1);
    func_0201F73C(((struct Obj01731 *)out)->f0,2,((struct Obj01542 *)p)->f22,(u8)(((struct Obj01542 *)p)->f20));
    q=((struct Obj01731 *)out)->f0;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    ((struct Obj01731 *)out)->f8=((struct Obj01731 *)out)->f0;
    out[12]=0;
    ((struct Obj01731 *)out)->f14=func_0201F81C(((struct Obj01542 *)p)->f18,heap);
    for(i=0;i<((struct Obj01542 *)p)->f18;i++)
        func_0201F878(((struct Obj01731 *)out)->f14,((struct Obj01542 *)p)->f0,*(u32 *)(p+12+i*4),i,(u16)heap);
    cfg=d_021DF78C;
    cfg.word[0]=*(u32 *)&((struct Obj01731 *)out)->f14;
    *(u16 *)((u8 *)&cfg+0x10)=((struct Obj01542 *)p)->f18;
    *(u16 *)((u8 *)&cfg+0x12)=((struct Obj01542 *)p)->f18;
    cfg.word[3]=*(u32 *)&((struct Obj01731 *)out)->f0;
    cfg.word[9]=((struct Obj01542 *)p)->f0;
    cfg.word[10]=(u32)(out+8);
    cfg.word[11]=((struct Obj01542 *)p)->f8;
    cfg.word[12]=((struct Obj01542 *)p)->f4;
    ((struct Obj01731 *)out)->f10=func_0201FF30((struct Src *)(&cfg),0,0,heap);
    func_02020CF8(((struct Obj01731 *)out)->f10,heap);
    func_02020D10(((struct Obj01731 *)out)->f10,0);
    return out;
}






void func_021DA148(u8 *p) { func_0202020C(((struct Obj06448 *)p)->f10,0,0); func_0201F868(((struct Obj06448 *)p)->f14); func_0201F7A8(((struct Obj06448 *)p)->f0,0); func_020456F8(((struct Obj06448 *)p)->f0); func_020452E8(((struct Obj06448 *)p)->f0); func_020307B0(p); }






/*
 * extent: two bytes of zero alignment padding follow the return.
 */
int func_021DA178(char *p)
{
    u32 q = ((struct Obj04493 *)p)->f4;
    int r;
    if (((struct Obj04493 *)p)->fC) {
        if (func_0201C6C4((struct PrintSys *)q,(void *)((u32)func_02045770((struct Descriptor *)((struct Obj04493 *)p)->f8))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj04493 *)p)->f8);
            ((struct Obj04493 *)p)->fC=0;
        }
    }
    r=func_020200CC(((struct Obj04493 *)p)->f10);
    if (r == -2) r=func_02020350(((struct Obj04493 *)p)->f10,2)-1;
    return r;
}






/*
 * lever: b is u16; const descriptor input and an element slot pointer reproduce scheduling.
 */
void *func_021DA1BC(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,u16 e,int f,u16 heap)
{
    u32 i;
    int size=n*4+16;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x374);
    func_02082BCC(out,0,size);
    *(const char * *)&((struct Obj04494 *)out)->f0=desc;
    ((struct Obj04494 *)out)->f4=n;
    ((struct Obj04494 *)out)->f8=f;
    ((struct Obj04494 *)out)->fC=e;
    for(i=0;i<((struct Obj04494 *)out)->f4;i++) {
        const char *v=desc+i*24;
        char *slot=out+i*4;
        void *q=func_021D99A4((u32)a,b,((struct Obj02469 *)v)->f0,((struct Obj02469 *)v)->f1,((struct Obj02469 *)v)->f2,((struct Obj02469 *)v)->f3,c,d,heap);
        ((struct Obj08093 *)slot)->f10=q;
        func_021D9B2C(q,((struct Obj02469 *)v)->f10,((struct Obj02469 *)v)->f12,((struct Obj02469 *)v)->fC);
        func_021D9B28(((struct Obj08093 *)slot)->f10,((struct Obj02469 *)v)->f14);
        if(((struct Obj02469 *)v)->f8) func_021D9AC8(((struct Obj08093 *)slot)->f10,((struct Obj02469 *)v)->f8,((struct Obj04494 *)out)->f8);
        else func_021D9A64(((struct Obj08093 *)slot)->f10,e,((struct Obj02469 *)v)->f4,((struct Obj04494 *)out)->f8);
    }
    return out;
}






void func_021DA280(u8 *p) { u32 i; for(i=0;i<((struct Obj22879 *)p)->f4;i++) func_021D9A40(*(u8 **)(p+16+i*4)); func_020307B0(p); }






void func_021DA2A8(u8 *p) { u32 i; for(i=0;i<((struct Obj22880 *)p)->f4;i++) func_021D9A58(*(u8 **)(p+16+i*4)); }






int func_021DA2C8(u8 *p) { u32 i; int result=1; for(i=0;i<((struct Obj22881 *)p)->f4;i++) result &= func_021D9B34(*(u8 **)(p+16+i*4)); return result; }






void func_021DA2F0(u8 *p,u32 i) { u8 *d=*(u8 **)(p+16+i*4); func_02043B5C(func_02045770(((struct Obj13951 *)d)->fC),((struct Obj13951 *)d)->f16&31); func_02045334(*(void **)(*(u8 **)(p+16+i*4)+12)); }






void func_021DA318(u8 *p) { u32 i; for(i=0;i<((struct Obj22882 *)p)->f4;i++) func_021D9B9C(*(u8 **)(p+16+i*4)); }






/*
 * lever: heap is u16 in this function and the two callees receiving it.
 */
void *func_021DA338(char *p,u16 heap)
{
    u32 i;
    int size=((struct Obj13952 *)p)->f4*4+8;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x42e);
    func_02082BCC(out,0,size);
    *(char * *)&((struct Obj13953 *)out)->f4=p;
    ((struct Obj13953 *)out)->f0=heap;
    for(i=0;i<((struct Obj13952 *)p)->f4;i++) {
        void *win=func_02045770(*(void **)(*(char **)(p+16+i*4)+12));
        u32 x=func_020437DC(win);
        u32 y=func_020437E4(win);
        u32 type=func_02043994(win);
        *(void **)(out+i*4+8)=func_02043678(x/8,y/8,type,heap);
    }
    return out;
}






void func_021DA3C0(u8 *p) { u32 i; for(i=0;i<((struct Obj22884 *)(*(u8 * *)&((struct Obj22883 *)p)->f4))->f4;i++) func_020437AC(*(void **)(p+8+i*4)); func_020307B0(p); }






/*
 * extent: two bytes of zero alignment padding follow the return.
 */
void func_021DA3EC(char *p,char *desc,void *dst)
{
    u32 i;
    Pair_021D9624 pos,out;
    void *text=func_020457B0(512,((struct Obj06449 *)p)->f0);
    for(i=0;i<((struct Obj22885 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f4;i++) {
        char *d=desc+i*24;
        if(((struct Obj03262 *)d)->f0) {
            func_02043B5C(*(void **)(p+i*4+8),(u8)(((struct Obj03262 *)d)->f14&31));
            pos.x=((struct Obj03262 *)d)->f10;
            pos.y=((struct Obj03262 *)d)->f12;
            func_021D9BE8(((struct Obj03262 *)d)->fC,&pos,*(void **)(p+i*4+8),text,((struct Obj22886 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,&out);
            if(((struct Obj03262 *)d)->f8) func_02045838(text,(struct U16Vec *)(((struct Obj03262 *)d)->f8));
            else func_02045CAC((struct MsgBank *)(((struct Obj22887 *)(*(char * *)&((struct Obj06449 *)p)->f4))->fC),((struct Obj03262 *)d)->f4,text);
            func_0201C724(dst,(u32)(*(void **)(p+i*4+8)),(s16)out.x,(s16)out.y,(u32)text,((struct Obj22888 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,((struct Obj03262 *)d)->f14);
        }
    }
    func_020307B0(text);
}






void func_021DA4A8(u8 *p) { u32 i; for(i=0;i<((struct Obj22889 *)(*(u8 * *)&((struct Obj13954 *)p)->f4))->f4;i++) { void *out=*(void **)(p+8+i*4); func_02043814(out,func_02045770(*(void **)(*(u8 **)(*(u8 * *)&((struct Obj13954 *)p)->f4+16+i*4)+12))); } }






/*
 * note (2026-10-05, lane T7, pengy's share): written bottom-up from the listing.
 *   heap is u16 (callees take it as u16). The input record is const, the
 *   output field f60 is a pointer typed like in->f3c: with a u32 f60 the second
 *   read of in->f3c was merged (4 B short). Struct copy t = d_021DF7C0 (4 records of
 *   24 B). The caller passes a 0x38 B input record and heap.
 */
struct Out_021D9624 *func_021DA4DC(const struct In *in, u16 heap)
{
    struct Tbl t;
    struct Pt pt;
    u32 i;
    u8 c;
    u16 w;
    struct Out_021D9624 *out = func_02030734(heap, 0x64, 0, d_021DFBA0, 0x4e7);
    func_02082BCC(out, 0, 0x64);
    out->fC = in->f20;
    out->f4 = (u32)in->fC_;
    out->f26 = in->f26;
    out->f2a = in->f28;
    out->f2c = in->f2a;
    out->f28 = in->f24;
    out->f34 = in->f34;
    out->f38 = in->f38;
    out->f2e = in->f2c;
    out->f30 = in->f30;
    out->f60 = in->f3c;
    if (in->f3c) {
        u32 v = *in->f3c;
        out->f8 = v;
        out->f8 = (v > out->fC - 1) ? out->fC - 1 : v;
    }
    for (i = 0; i < out->fC; i++)
        out->pal[i] = *(u16 *)(0x05000000 + in->f2a * 32 + (i + 10) * 2);
    out->f22 = *(u16 *)(0x0500001E + in->f2a * 32);
    t = d_021DF7C0;
    for (i = 0; i < out->fC; i++) {
        struct Rec_021D9624 *r = &t.r[i];
        r->b += (u8)in->f2c;
        r->a += (u8)in->f2e;
        if (in->bank) r->h = func_02045EC0(in->bank, in->ids[i]);
        else r->h = func_02045874((struct U16Vec *)in->ids[i], (u16)((heap & 0x7FFF) | 0x8000));
    }
    c = in->f26;
    w = in->f24;
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    out->f0 = ((void *(*)())func_021DA1BC)(0, (const char *)&t, out->fC, w, c, in->f8, (u32)in->bank, in->f4, heap);
    for (i = 0; i < out->fC; i++)
        if (t.r[i].h) func_02045808(t.r[i].h);
    pt.x = d_021DF76C[out->f8].x;
    pt.y = d_021DF770[out->f8].x + in->f2c * 8;
    func_0204B404((void *)out->f4, (const struct Vec2 *)(&pt), 0);
    func_0204B3DC((void *)out->f4, 1);
    func_0204B878((void *)out->f4, out->f30);
    func_0204B92C((void *)out->f4, 1);
    return out;
}






void func_021DA698(u8 *p) { if(*(u32 * *)&((struct Obj03786 *)p)->f60 && ((struct Obj03786 *)p)->f8!=3) **(u32 * *)&((struct Obj03786 *)p)->f60=((struct Obj03786 *)p)->f8; func_0204B3DC(((struct Obj03786 *)p)->f4,0); func_021DA2A8(*(u8 * *)&((struct Obj03786 *)p)->f0); func_021DA280(*(u8 * *)&((struct Obj03786 *)p)->f0); func_020409B4((u8)(((struct Obj03786 *)p)->f28)); func_020307B0(p); }








/*
 * arithmetic: direct division helper uses quotient r0/remainder r1 as a scalar u64;
 *             the caller admits count zero, so ordinary C remainder is not used.
 */
int func_021DA6D0(u8 *p)
{
    u32 keys=func_020362DC();
    u32 repeat=func_0203633C();
    int changed=0;
    int i;
    int phase;
    int oldphase;
    u32 index;
    Position_021D9624 pos;
    if(repeat&64) {
        index=((struct Obj00360 *)p)->f8==0 ? ((struct Obj00360 *)p)->fC-1 : ((struct Obj00360 *)p)->f8-1;
        ((struct Obj00360 *)p)->f8=index;
        if(((struct Obj00360 *)p)->fC!=1) func_020061E4(0x548);
        changed=1;
    } else if(repeat&128) {
        if(((struct Obj00360 *)p)->fC!=1) func_020061E4(0x548);
        ((struct Obj00360 *)p)->f8+=1;
        ((struct Obj00360 *)p)->f8=(u32)(_u32_div_f(((struct Obj00360 *)p)->f8,((struct Obj00360 *)p)->fC)>>32);
        changed=1;
    } else if(keys&1) {
        func_020061E4(0x54c);
        return ((struct Obj00360 *)p)->f8;
    } else if(keys&2) {
        func_020061E4(0x551);
        if(((struct Obj00360 *)p)->fC==1) return -2;
        if(((struct Obj00360 *)p)->f8!=3) **(u32 * *)&((struct Obj00360 *)p)->f60=((struct Obj00360 *)p)->f8;
        ((struct Obj00360 *)p)->f8=((struct Obj00360 *)p)->fC-1;
        return ((struct Obj00360 *)p)->f8;
    }
    if(changed) {
        pos.x=d_021DF76C[*(u32 *)(p+8)].x;
        pos.y=d_021DF76C[*(u32 *)(p+8)].y+((struct Obj00360 *)p)->f2E*8;
        func_0204B404(((struct Obj00360 *)p)->f4,(const struct Vec2 *)(&pos),0);
        if(((struct Obj00360 *)p)->f8==3) func_0204B878(((struct Obj00360 *)p)->f4,2);
        else func_0204B878(((struct Obj00360 *)p)->f4,((struct Obj00360 *)p)->f30);
        if(*(void (**)(u32))(p+0x34)) (*(void (**)(u32))(p+0x34))(((struct Obj00360 *)p)->f38);
    }
    oldphase=((struct Obj00360 *)p)->f24;
    phase=oldphase+0x400;
    if(phase>=0x10000) ((struct Obj00360 *)p)->f24=oldphase-0xfc00;
    else ((struct Obj00360 *)p)->f24=phase;
    for(i=0;i<4;i++) {
        u8 *v=p+i*4;
        if(((struct Obj06450 *)v)->f4C!=((struct Obj06450 *)v)->f3C && ((struct Obj00360 *)p)->f24>=0x7dff && ((struct Obj00360 *)p)->f24<=0x81ff)
            ((struct Obj06450 *)v)->f3C=((struct Obj06450 *)v)->f4C;
        if(((struct Obj06450 *)v)->f3C)
            func_021DAAA4((int)((void *)15),(u16 *)(p+0x1a+i*2),((struct Obj00360 *)p)->f24,(u8)(((struct Obj00360 *)p)->f2C),(u8)(i+10),*(u16 *)(p+0x12+i*2),((struct Obj00360 *)p)->f22);
    }
    return -1;
}









/*
 * Addresses are Black-image addresses.
 */
int func_021DA840(void **p)
{
    return func_021DA2C8(*p);
}








void func_021DA84C(u8 *p,u32 i,u32 value)
{
    *(u32 *)(p+i*4+76)=value;
}








void *func_021DA854(void *a,void *b,u16 heap) { u8 *p; p=func_02030734(heap,20,0,d_021DFBA0,0x61c); func_02082BCC(p,0,20); ((struct Obj22893 *)p)->fC=a; func_021DA8B0((u32 *)p,(u32)b); return p; }








void func_021DA890(void *p) { func_020307B0(p); }









void func_021DA898(char *p)
{
    if (((struct Obj13955 *)p)->f4 == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((struct Obj13955 *)p)->fC);
}









int func_021DA8AC(u32 *p) { return p[1]; }









void func_021DA8B0(u32 *p,u32 a) { p[0]=a; p[2]=0; }









void func_021DA8B8(u32 *p) { p[1]=1; }









void func_021DA8C0(u32 *p,u32 a) { p[4]=a; }









void func_021DA8C4(u32 *p) { p[2]=p[4]; }








/*
 * lever: a and b are u16; the descriptor input pointer is const.
 */
void *func_021DA8CC(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap)
{
    Desc_021DA3EC desc;
    char *out=func_02030734(heap,36,0,d_021DFBA0,0x6b1);
    func_02082BCC(out,0,36);
    ((struct Obj06451 *)out)->f20=g;
    ((struct Obj06451 *)out)->f18=func_020457B0(128,heap);
    ((struct Obj06451 *)out)->f0=func_02043678(a,b,32,heap);
    func_02082BCC(&desc,0,24);
    desc.win=((struct Obj06451 *)out)->f0;
    desc.x=((struct Obj08095 *)p)->f0;
    desc.y=((struct Obj08095 *)p)->f2;
    desc.z=c;
    desc.a=((struct Obj08095 *)p)->f6;
    desc.c=e;
    desc.d=e;
    desc.b=((struct Obj08095 *)p)->f7;
    desc.pal=d;
    ((struct Obj06451 *)out)->f1C=func_020255A0(f,(const struct Param *)(&desc));
    return out;
}








void func_021DA958(u8 *p) { func_0202570C(((struct Obj10414 *)p)->f1C); func_020437AC(((struct Obj10414 *)p)->f0); func_02045808(((struct Obj10414 *)p)->f18); func_020307B0(p); }









void func_021DA978(char *p)
{
    func_02043B5C((struct CharBuf *)(((struct Obj10415 *)p)->f0), (unsigned char)(((struct Obj10415 *)p)->f4 & 0x1f));
    func_020257D0(((struct Obj10415 *)p)->f1C);
}








/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021DA994(char *p,int a,int b,int c)
{
    int xy[2];
    func_02043B5C((struct CharBuf *)(((struct Obj03787 *)p)->f0),(u8)(((struct Obj03787 *)p)->f4&31));
    func_02045CAC((struct MsgBank *)a,b,((struct Obj03787 *)p)->f18);
    func_021DAA28(p,c,xy);
    func_0201C724(((struct Obj03787 *)p)->f20,((struct Obj03787 *)p)->f0,(s16)xy[0],(s16)xy[1],(u32)(((struct Obj03787 *)p)->f18),c,((struct Obj03787 *)p)->f4);
    ((struct Obj03787 *)p)->f8=1;
}









void func_021DA9EC(u8 *p,int a) { ((struct Obj22897 *)p)->f4=a; }









void func_021DA9F0(u32 *p,u32 a,u32 b,u32 c) { p[3]=a; p[4]=b; p[5]=c; }








int func_021DA9F8(u8 *p) { if(((struct Obj05358 *)p)->f8) { if(func_0201C6C4((struct PrintSys *)(((struct Obj05358 *)p)->f20),(void *)(((struct Obj05358 *)p)->f0))==0) { func_020257D0(((struct Obj05358 *)p)->f1C); ((struct Obj05358 *)p)->f8=0; } } if(((struct Obj05358 *)p)->f8==0) return 1; return 0; }








/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: case 0 is an eight-byte aggregate copy (existing pair-copy idiom).
 */
void func_021DAA28(char *p,int a,int *out)
{
    int x,y;
    switch(((struct Obj02470 *)p)->f14) {
    case 0:
        *(Pair_021D9624 *)out=*(Pair_021D9624 *)(p+12);
        break;
    case 1:
        x=func_020437DC((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        y=func_020437E4((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D304(((struct Obj02470 *)p)->f18,a,0)/2;
        y-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=x+((struct Obj02470 *)p)->fC;
        out[1]=y+((struct Obj02470 *)p)->f10;
        break;
    case 2:
        x=func_020437E4((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=((struct Obj02470 *)p)->fC;
        out[1]=x+((struct Obj02470 *)p)->f10;
        break;
    }
}






static inline u16 blend(u16 c1,u16 c2,s16 factor) {
 u8 g1,r1,b1; int db,dr,dg;
 g1=(c1&0x3e0)>>5;
 r1=c1&31;
 b1=(c1&0x7c00)>>10;
 db=(factor*((u8)((c2&0x7c00)>>10)-b1))>>12;
 dr=(factor*((u8)(c2&31)-r1))>>12;
 dg=(factor*((u8)((c2&0x3e0)>>5)-g1))>>12;
 return ((u8)(b1+db)<<10)|((u8)(r1+dr)|((u8)(g1+dg)<<5));
}






/*
 * lever: twin ov104 021B89DC blend spelling, first argument passed through to func_02061CA4.
 */
s32 func_021DAAA4(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2) {
 *p=blend(c1,c2,(s16)((d_020A1B38[((angle>>4)*2)+1]+0x1000)/2));
 return func_02061CA4((void *)a,bank*32+index*2,(u32)p,2);
}











#pragma opt_loop_invariants off







/*
 * lever: int factor before the loop, narrowed to s16 at the inline blend argument
 * inside the loop, with #pragma opt_loop_invariants off: the IR keeps the
 * conversion in the loop (no div+convert fold to lsls #0xf) and the backend
 * hoists it, giving asrs #1; lsls #0x10; asrs #0x10. Counter initialised at its
 * declaration (int i=0; for(;...)) sets the i/index birth order (r6/r4).
 * note pass 2 2026-10-06 P2L51: closed from 147/200 (h5 pragma form 7/200, i/index swap fixed by i=0 at declaration).
 */
void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last) {
 int i=0;
 int factor=(d_020A1B38[((angle>>4)*2)+1]+0x1000)/2;
 for(;i<16;i++) p[i]=blend(first[i],last[i],factor);
 func_02061CA4(a,bank*32,(u32)p,32);
}







#pragma opt_loop_invariants reset







char *func_021DAC18(const Input *src,u16 heap)
{
    char *out;
    int count=0;
    u32 i;
    int j;
    Desc_021DAB50 d;
    Record_021D9624 record;
    const char *table;
    int n;
    void *callback;
    out=func_02030734(heap,0xc70,0,d_021DFBB0,0x19f);
    func_02082BCC(out,0,0xc70);
    ((struct Obj00910 *)out)->fAD0=1;
    *(Input *)out=*src;
    ((struct Obj00910 *)out)->f24=heap;
    func_02082A7C(-1,out+0xb48,32);
    func_02082A7C(-1,out+0xb88,32);
    func_02082A7C(-1,out+0xb68,32);
    for(i=0;i<func_0200A348(((struct Obj00910 *)out)->fC);i++) {
        if(func_0200A0E4(((struct Obj00910 *)out)->fC,i)) {
            count++;
            func_0200A000(((struct Obj00910 *)out)->fC,i,&record);
            func_021DBDF4(out+40+i*0xdc,(const Record_021DB938 *)&record,out,heap);
        }
    }
    callback=(void *)func_021DC08C;
    if(((struct Obj00910 *)out)->f0) callback=(void *)func_021DCEC4;
    ((struct Obj00910 *)out)->fAC4=func_021DA854(out,callback,heap);
    func_021DB018((u8 *)out,heap);
    func_021DB478(out,1,0,((struct Obj00910 *)out)->fAC8,heap);
    if(count) {table=d_021DF8FC;n=3;}
    else {table=d_021DF890;n=2;}
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    ((struct Obj00910 *)out)->fAB8=((void *(*)())func_021DA1BC)(0,table,n,1,3,((struct Obj00910 *)out)->f14,((struct Obj00910 *)out)->f1C,*(int *)&((struct Obj00910 *)out)->f10,heap);
    func_02082BCC(&d,0,48);
    d.w[0]=6;d.w[1]=4;d.w[2]=14;d.w[3]=15;d.w[4]=11;d.w[5]=14;
    d.w[6]=((struct Obj00910 *)out)->f8;d.w[7]=*(u32 *)&((struct Obj00910 *)out)->fC;d.w[8]=((struct Obj00910 *)out)->f1C;
    d.w[9]=((struct Obj00910 *)out)->f10;d.w[10]=((struct Obj00910 *)out)->f14;d.w[11]=((struct Obj00910 *)out)->f18;
    ((struct Obj00910 *)out)->fAB0=func_021DCFC8((const Desc_021DCFC8 *)&d,heap);
    if(func_021DBDBC((u32)out)) {
        for(j=0;j<12;j++) {
            if(func_021DBF04((int *)(out+40+j*0xdc)))
                *(void **)(out+0xa7c+j*4)=func_021DD24C((Record_021DD24C *)func_021DC02C(out+40+j*0xdc),((struct Obj00910 *)out)->fAB0,(void *)src->w[8],heap);
        }
        func_021DE0AC(((struct Obj00910 *)out)->fA7C,0);
        func_0203084C(29);
    }
    func_02040618(3,3,0);
    func_02040618(7,3,0);
    return out;
}







/*
 * lever: The slot array at +0xa7c is the same layout as func_021DBC08;
 * its member access keeps the offset loaded before the loop index.
 */
void func_021DAE1C(Obj_021DAE1C *obj)
{
    char *p=(char *)obj;
    int i;
    u32 j;
    for(i=0;i<12;i++) {
        if(obj->slots[i]) {
            func_021DD980(obj->slots[i]);
            obj->slots[i]=0;
        }
    }
    func_021DD1FC(*(void ** *)&((struct Obj01058 *)p)->fAB0);
    if(((struct Obj01058 *)p)->fABC) {
        func_021D9E04(((struct Obj01058 *)p)->fABC);
        ((struct Obj01058 *)p)->fABC=0;
    }
    func_02040618(3,0,0);
    func_02040618(2,0,0);
    func_021DA2A8(((struct Obj01058 *)p)->fAB8);
    func_021DA280(((struct Obj01058 *)p)->fAB8);
    func_021DB528(p,1);
    func_021DB528(p,0);
    func_021DB3E8(p);
    for(j=0;j<func_0200A348(((struct Obj01058 *)p)->fC);j++)
        func_021DBEE4((u32)(p+0x28+j*0xdc));
    func_020414EC(4);
    func_020414EC(6);
    func_02041B6C(4);
    func_02041B6C(6);
    func_021DA890(((struct Obj01058 *)p)->fAC4);
    func_020307B0(p);
}







void func_021DAEF0(Obj_021DAEF0 *obj)
{
    char *p=(char *)obj;
    int flag;
    u16 old;
    int angle;
    func_021DA898(*(char * *)&((struct Obj01153 *)p)->fAC4);
    func_021DD240(((struct Obj01153 *)p)->fAB0);
    if(((struct Obj01153 *)p)->fA78) {
        flag=0;
        if(*(char * *)&((struct Obj01153 *)p)->fAAC) {
            func_021DDF84(*(char * *)&((struct Obj01153 *)p)->fAAC);
            *(char * *)&((struct Obj01153 *)p)->fAAC=0;
        }
        if(obj->index<4 && func_021DBF04((int *)(&obj->items[obj->index+((struct Obj01153 *)p)->fAC8*4]))) {
            flag=1;
            func_021DE0AC(*(void **)(p+0xa7c+(((struct Obj01153 *)p)->fACC+((struct Obj01153 *)p)->fAC8*4)*4),1);
        }
        if(flag==0) func_021DE0DC(((struct Obj01153 *)p)->fAB0);
        ((struct Obj01153 *)p)->fA78=0;
    }
    old=((struct Obj01153 *)p)->fBAC;
    angle=old+0x400;
    if(angle>=0x10000)
        ((struct Obj01153 *)p)->fBAC=old-0xfc00;
    else
        ((struct Obj01153 *)p)->fBAC=angle;
    func_021DCFA4((u8 *)(p+0xbae),14,0,((struct Obj01153 *)p)->fBAC);
    func_021DCFA4((u8 *)(p+0xc0e),14,2,((struct Obj01153 *)p)->fBAC);
}







static inline void update(void *p)
{
    if(p) func_021DD9CC(p);
}







/*
 * extent: unit includes tail-call follower func_021DB008 (function-start seed).
 */
void func_021DAFCC(char *p)
{
    int i;
    func_021DA2C8(((struct Obj10417 *)p)->fAB8);
    if(((struct Obj10417 *)p)->fAB4) func_021D9B34(((struct Obj10417 *)p)->fAB4);
    for(i=0;i<12;i++) {
        void *q=*(void **)(p+i*4+0xa7c);
        if(q) update(q);
    }
}







int func_021DB008(char *p)
{
    return func_021DA8AC(((struct Obj22899 *)p)->fAC4);
}







#pragma opt_dead_assignments off







/*
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition tail-returns sub_0204968C); with the void declaration the later register zeros were copied from the pooled zero; with the real return type the
 *   bytes are EXACT in c99 and c.
 * note (2026-10-05, lane P10): full body written; size is exact (976 bytes), 110 bytes differ.
 *   Fixed: heap is u16 with the matched u16 callee prototypes (no lsls/lsrs pairs); 0xAB4, 0xBA8
 *   and 320 held as int locals (off, off2, w) so the pool words and derived offsets matched.
 *   Residue 1: colour swap. Original has the early zero (and loop counter i) in r6 and arc in r4;
 *   the build has them swapped (j then takes r6 vs r4 the same way). Tried, no change: i,j and arc
 *   declaration order, separate arc names, loop-scoped i and j, named zero z (propagated),
 *   j = 0 at the top (worse). Pragmas opt_lifetimes/propagation/common_subs/dead_assignments/
 *   scheduling/peephole off: no help.
 *   Residue 2: the original uses movs for zero arguments in r0-r3 between 0xCC and 0x140 (before
 *   the first loop); the build copies the zero register there.
 *   Residue 3: in loop 2 the original forms add r0,sp,#0x44 once before the j test; the build
 *   adds it in each arm. A ternary for the x store and a real Tmp struct were worse.
 * note (2026-10-05, lane P10b): 110 -> 85 bytes, size exact (976). Fixed: loop 2 now writes
 *   the t stores in each if/else arm (x, y=0x10 and z=9 in both arms), so the &t add is hoisted
 *   above the j test and the tail shape matches (residue 3 closed, 110 -> 94). The locals off, off2
 *   and w were stand-ins (literals give identical bytes) and are gone. opt_dead_assignments off
 *   fixes the r0/r1 table-base colours in the i < 4 arm (94 -> 85).
 *   Left: the colour swap. Original W1 = early zero and loop-1 counter i in r6, arcs r4, W2 = copy
 *   of it (`adds r4,r6,#0` before loop 1) = zero args after the loop and loop-2 counter j in r4.
 *   Build: W1 r4, arcs and W2 r6. Likely W1 is coloured before W2 because W1 has about ten extra
 *   uses: between 0xCC and 0x140 the build copies zeros off W1 (adds rN,r4,#0) where the original
 *   has movs. Tried (no help): i=0 at the top of the function (hoists the movs above the first
 *   call, +12 B), `i = 0; j = i;` before loop 1 with empty for inits (+12 B, worse regs), pointer
 *   local for &t in loop 2 (hoisted to r7, worse), j/i and arc declaration order again with the
 *   new loop 2, pragmas opt_lifetimes, opt_propagation, scheduling, peephole (no change),
 *   opt_common_subs (much worse), lifetimes+dead_assignments (85, same), propagation+dead (worse).
 *   Parked per the human-written rule: not tried, a human-spelled zero local reused as the
 *   stack zero arguments (i passed as args 5 and 6) could explain r6 holding a live variable.
 * note (2026-10-05, lane P10c): still 85 B, no change kept. The pragma opt_dead_assignments off
 *   lines are present (the 85 B state). Callee prototypes already match the matched callers (u32
 *   args, u16 heap), so no argument type differs between the stack zeros and the register zeros.
 *   Facts: mine already uses movs for register zeros before +0xB0 and copies only from the last
 *   02049658/020498F4 pair on (+0xB0, +0xD0, +0xF6..+0x134); the original uses movs everywhere in
 *   W1's range, and the copy count raises W1's use count, which colours W1 before the arcs.
 *   Loop 2 original: k is a separate fresh `movs r7,#0`, j is r4.
 *   Tried (each one compile): (1) coordinator lead: i = 0 before the first call, i passed only as
 *   the two stack zero args of 02049658/020498F4, literal 0 for r1-r3 (87 B; the compiler folds
 *   i to 0 so register zeros still copy); (2) i = 0 early with `for (; i < 8; i++)` as in the
 *   matched twin ov099 021BE040 (87 B); (3) static inline helper pair(arc, x, y, heap) for the
 *   three 02049658/020498F4 pairs (85 B, +0xB0 now movs, others unchanged); (4) late zeros
 *   (02049B68 r2, 02040C14 r1/r3, 0201F5BC r0/r3, 0204ACEC r2) spelled 0u (85 B, no change);
 *   (5) first 23 lines of calls inside a static inline setup1(heap) helper (85 B); (6) helper
 *   variant with opt_propagation off (901 B) and opt_lifetimes off (85 B). Idea not done: a
 *   source where W1 is not provably 0 after the first loop-free section.
 */
void func_021DB018(u8 *p, u16 heap)
{
    Tmp t;
    void *arc;
    int i, j;
    u32 k;
    arc = func_020490F4(34, heap);
    func_02049B68(arc, 1, 0, 0, 320, heap);
    func_02049658(arc, 10, 3, 0, 0, 0, heap);
    func_020498F4(arc, 17, 3, 0, 0, 0, heap);
    func_02049658(arc, 10, 1, 0, 0, 0, heap);
    func_020498F4(arc, 19, 1, 0, 0, 0, heap);
    func_020409B4(3);
    func_02049B68(arc, 1, 4, 0, 320, heap);
    func_02049658(arc, 10, 7, 0, 0, 0, heap);
    func_020498F4(arc, 18, 7, 0, 0, 0, heap);
    func_02049238(arc);
    arc = func_020490F4(23, heap);
    func_02049B68(arc, 5, 0, 480, 32, heap);
    func_02049B68(arc, 5, 4, 480, 32, heap);
    func_02049238(arc);
    func_02040C14(1, 0, 1, 0);
    func_02040C14(2, 0, 1, 0);
    func_0201F5BC(0, 1, 13, 0, heap);
    arc = func_020490F4(7, heap);
    *(int *)(p + 0xBA8) = func_0204ACEC(arc, func_0201BC3C(), 0, 384, heap);
    func_02049238(arc);
    for (i = 0; i < 8; i++) {
        if (i >= 4) {
            *(u16 *)(t.b + 8) = data_021DF86E[i - 4].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i - 4].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i - 4].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i - 4].h[3];
            t.b[8] += 0x20;
            t.b[10] += 0x20;
        } else {
            *(u16 *)(t.b + 8) = data_021DF86E[i].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i].h[3];
        }
        *(u32 *)(p + i * 4 + 0xBA8 - 0xA0) = func_020450F0(2, t.b[10], t.b[11], 10, 2, 15, 0);
        func_02045374(*(void **)(p + i * 4 + 0xBA8 - 0xA0));
        func_020409B4(2);
    }
    *(void **)(p + 0xAB4) = func_021D99A4(0, 1, 13, 22, 6, 2, 3, *(u32 *)(p + 0x14), heap);
    arc = func_020490F4(34, heap);
    *(s32 *)(p + 0xAB4 + 0x50) = func_0204AC18(arc, 0, 0, 0, 0, 6, heap);
    *(s32 *)(p + 0xAB4 + 0x4C) = func_0204AF28(arc, 32, 35, heap);
    *(s32 *)(p + 0xAB4 + 0x48) = func_0204A6C8(arc, 9, 0, 0, heap);
    func_021DCF54((char *)p + 0xBAE, arc, 0, 0, 1, heap);
    func_021DCF54((char *)p + 0xC0E, arc, 0, 2, 3, heap);
    func_02049238(arc);
    func_02082BCC(&t, 0, 8);
    *(u16 *)(t.b) = 0;
    *(u16 *)(t.b + 2) = 24;
    t.b[7] = 1;
    t.b[6] = 1;
    {
        struct Obj *o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x38) = o;
        *(u16 *)(t.b + 4) = 2;
        o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x3C) = o;
        func_0204B3DC(o, 0);
    }
    t.b[6] = 0;
    k = 0;
    for (j = 0; j < 2; j++) {
        struct Obj *o;
        u8 *q;
        if (j == 0) {
            *(u16 *)(t.b) = 0x10;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        } else {
            *(u16 *)(t.b) = 0xF0;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        }
        q = p + j * 4;
        o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, k, heap);
        *(struct Obj **)(q + 0xAB4 + 0x40) = o;
        func_0204B92C(*(struct Obj **)(q + 0xAB4 + 0x40), 1);
        func_0204B3DC(*(struct Obj **)(q + 0xAB4 + 0x40), k);
        if (j == 0) func_0204B604((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 1);
        else func_0204B604((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 0);
    }
    func_02040588(2, 1);
}







#pragma opt_dead_assignments reset






void func_021DB3E8(char *p)
{
    int i;
    func_02040DA8(2,1,0);
    func_02040DA8(1,1,0);
    for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+0xaf4+i*4));
    func_0204B3B4(((struct Obj01058 *)p)->fAF0);
    func_0204B3B4(((struct Obj01058 *)p)->fAEC);
    func_0204A8D4((u32)(((struct Obj01058 *)p)->fAFC));
    func_0204AFD8((u32)(((struct Obj01058 *)p)->fB00));
    func_0204ADA4((u32)(((struct Obj01058 *)p)->fB04));
    func_021D9A40(((struct Obj01058 *)p)->fAB4);
    ((struct Obj01058 *)p)->fAB4=0;
    func_0204ADA4((u32)(((struct Obj01058 *)p)->fBA8));
    for(i=0;i<8;i++) func_020452E8(*(void **)(p+0xb08+i*4));
}






void func_021DB478(char *p,int a,int b,int c,u16 heap)
{
    int i;
    void *text,*other;
    for(i=0;i<4;i++) func_021DB54C(p,a,b,c,(u16)i,heap);
    text=func_020457B0(128,heap);
    other=func_02045EC0(((struct Obj00828 *)p)->f1C,150);
    func_0201EFA4(((struct Obj00828 *)p)->f18,0,c+1,1,1,1);
    func_0201EFA4(((struct Obj00828 *)p)->f18,1,func_021DBDB8(p),1,1,1);
    func_0201F250(((struct Obj00828 *)p)->f18,text,other);
    func_021D9B28(((struct Obj00828 *)p)->fAB4,0x39ea);
    func_021D9B2C(((struct Obj00828 *)p)->fAB4,0,0,1);
    func_021D9AC8(((struct Obj00828 *)p)->fAB4,(int)text,((struct Obj00828 *)p)->f10);
    func_02045808(text);
    func_02045808(other);
    func_020409B4(3);
}






void func_021DB528(char *p,int a) { int i; for(i=0;i<4;i++) func_021DB938(p,a,i); func_020409B4(3); }






#pragma opt_loop_invariants off






#pragma opt_lifetimes off






/*
 * note 2026-10-05 (lane P9): first draft, no source existed. DIFF, 1024 vs 1004 bytes.
 *   Structure matches the listing (loops, tail, callee arguments). Separate locals
 *   for rect/pos/cur (not one struct) give the right heap/index prologue; a static
 *   inline ents(p) = p + 0x28 gives the double store of the table base.
 *   Residue: the original keeps the two signed divisions by 3 inside the y loop
 *   (dividend (u8)k hoisted to a spill slot, rem first, quot second); every form
 *   tried hoists the whole tile base out of the loop (parenthesised, one expression,
 *   u8 m, inline cast, cols=3 local: 12 compiles). Spill slot numbers and register
 *   colours (rx r5, x r4, yy r7) follow from that. The 0x100 in the final block is
 *   built as r4(=1)+0xff in the original, not reproduced. Pool-base adds (p+0xb08
 *   etc.) are shared in the draft but recomputed in the original.
 *   Idioms checked: a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters
 *   (heap already u16 in all prototypes), narrow-stack-parameters-and-callee-prototype-
 *   free-the-narrow-home-store (prologue now matches for 14 bytes).
 * note 2026-10-05 (lane P9b): still DIFF, 1028 vs 1004 bytes. 13 more compiles, none changed
 *   the size. Tried: tile base as a static inline tb(k, y) called in the y body; separate
 *   rem/quo locals (rem first); tile expression written inside the x loop call argument;
 *   y loop as do/while; m = (u8)k assigned inside the y body instead of before the loop
 *   (mwcc hoists the cast AND both divisions out of the y loop in every form, so LICM
 *   hoists in one step through the whole chain); per-function pragmas opt_loop_invariants,
 *   opt_lifetimes, opt_propagation, opt_common_subs off (size 1028/1028/1064/1100, no help).
 *   The original hoists the (u8)k cast but keeps both calls in the y body: the divisions
 *   must be loop-variant or non-hoistable at IR level for a reason no source form tried
 *   shows. Untested guesses: a hoist budget limit, or a different dividend source.
 *   Idioms checked: signed-modulo-magic-reappears-when-the-source-divides-by-the-same-
 *   constant-twice (not applicable, divisor 3 is a real call here); matched twin ov217
 *   021BD178 has the divisions inside the loop only because its operands depend on i, j.
 * note 2026-10-05 final push G10L1: DIFF, 53 of 1004 bytes off (was 470 of 1028 at the start of
 *   the push). Size now equals the original. What closed most of the residue:
 *   (1) the tail pos.x chain is `if (a) x = h2; else if (b) x = h2 - 0x100; else if (b == 0)
 *   x = h2 + 0x100; else x = h2;` (the original tests a once; 1028 -> 1016 bytes);
 *   (2) the cur block is `if (a == 0) { if (b) x -= 0x100; else if (b == 0) x += 0x100; }`
 *   (1016 -> 1004); (3) `#pragma opt_loop_invariants off` keeps both /3 and %3 calls inside the
 *   y loop (the old lane tried it only while the size was still wrong); (4) do-while loops with
 *   `x = 0;` first in the y body and `y = 0;` before the loops give the original head order;
 *   (5) a local for func_021DBF08's result puts that call before the idx*4 address work;
 *   (6) declaration order off, tab, idx, y, y2, y3 (one counter per loop), m, src, k, ry, rx
 *   gives the original spill slots for most locals; tab = p + 0x28 plain (no inline helper);
 *   (7) dy = 0 before func_02082BCC.
 *   Residue (53 bytes): rx and x swapped (original x r4, rx r5; mine rx r4, x r5; decl order of
 *   x/rx did not move it, 2 compiles); index and ry slots swapped (original index sp+0x18, ry
 *   sp+0x1c); obj and the p+0xb88 base temp slots swapped (original obj sp+0x48, temp sp+0x44);
 *   `dx = 0` (movs r6) sits before the call to func_021DBF9C in mine, just before the blx of
 *   func_0204A6C8 in the original.
 *   Idioms checked: of-two-equal-temps-the-later-born-one-gets-the-lower-register (no source
 *   order found that flips x/rx), a-separate-index-local-per-loop-reorders-spill-slots (y per
 *   loop: moved y2/y3 next to y), function-scope-versus-block-scope-decides-spill-slot-order,
 *   div-and-mod-are-two-calls, a-reloaded-loop-invariant-means-the-loop-was-not-rotated
 *   (goto loops still hoist). Twin: ov121 021DB938 (same top condition and loops).
 * note 2026-10-05 final push G10L1 round 2: DIFF, 28 of 1004 bytes off. `dx = 0;` moved to just
 *   after the func_0204A6C8 statement (53 -> 28; this also fixed the obj/temp slot swap).
 *   Remaining: x in r5 and rx in r4 (original x r4, rx r5), and the index/ry spill slots swapped
 *   (original index sp+0x18, ry sp+0x1c). Tried without effect: dx = 0 as a call argument (251),
 *   u8 rx/ry, a y=x=0 head, separate x2/x3 per loop, decl order of x/rx/tile; opt_propagation off
 *   (91), opt_common_subs off (758), opt_lifetimes off (25 but x r4, rx r6, tile r5, index/ry swap
 *   stays); callee prototypes re-grepped in src/matched (all match the draft). Without the
 *   pragma and with direct r.b[0]/r.b[1] reads (like matched 021DB938) the slots all match but
 *   both /3 and %3 are hoisted (84); `(u8)k` inline, `cols = 3` local did not stop the hoist.
 * note pass 2 2026-10-06 P2L41: EXACT (c99 and c). Closed with `#pragma opt_lifetimes off` (beside
 *   opt_loop_invariants off), one tile local per loop (tile, tile2, tile3, like y/y2/y3), x declared
 *   before rx, int ry passed straight to func_020413B0 with the u32 x/y prototype used by matched
 *   callers (ov217 021BA284, ov088 021BB810). Under lifetimes off the colour order follows degree
 *   then declaration order: per-loop tiles make the tiles drop out first, then rx, then x, giving
 *   x r4, rx r5, tile r6. Passing ry (not r.b[1]) keeps ry itself as the spilled web, so it takes
 *   the slot after k (sp+0x1c) and index takes sp+0x18.
 */
void func_021DB54C(char *p, int a, int b, int c, u16 index, u16 heap)
{
    void *obj;
    int off;
    char *tab;
    int idx;
    int y, y2, y3;
    int m;
    const Rect_021D9624 *src;
    int k, ry;
    int x, rx, yy, tile, tile2, tile3;
    s16 dx, dy;
    void *dsc;
    Rect_021D9624 r;
    Pos pos;
    Cur_021D9624 cur;
    k = index + c * 4;
    tab = p + 0x28;
    off = k * 0xdc;
    idx = index;
    src = (const Rect_021D9624 *)d_021DF86E + index;
    r = *src;
    if ((a && *(u32 *)(p + 0xad0) == 0) || (a == 0 && *(u32 *)(p + 0xad0))) {
        idx += 4;
        r.b[0] += 32;
        r.b[2] += 32;
    }
    y = 0;
    ry = r.b[1];
    rx = r.b[0];
    m = (u8)k;
    do {
        x = 0;
        yy = ry + y;
        tile = y * 32 + ((m % 3) * 64 + 0x58 + (m / 3) * 2);
        do {
            func_02041300(3, (u16)(x + tile), (u8)(rx + x - 2), (u8)yy, 1, 1, 3);
            x++;
        } while (x < 2);
        y++;
    } while (y < 2);
    if (func_021DBF04((int *)(tab + off)) == 0) {
        y2 = 0;
        do {
            x = 0;
            yy = ry + y2;
            tile2 = y2 * 32 + 384;
            do {
                func_02041300(3, (u16)(x + tile2), (u8)(rx + x), (u8)yy, 1, 1, 3);
                x++;
            } while (x < 12);
            y2++;
        } while (y2 < 7);
        func_02043B5C(func_02045770(*(void **)(p + 0xb08 + idx * 4)), 0);
        func_02045334(*(void **)(p + 0xb08 + idx * 4));
        return;
    }
    y3 = 0;
    do {
        x = 0;
        yy = ry + y3;
        tile3 = y3 * 32 + 0x40;
        do {
            func_02041300(3, (u16)(x + tile3), (u8)(rx + x), (u8)yy, 1, 1, 5);
            x++;
        } while (x < 12);
        y3++;
    } while (y3 < 7);
    func_020413B0(3, r.b[0], ry, 12, 7, (u8)func_021DC03C(tab + off));
    dsc = func_021DBF08(tab + off);
    func_02043814(dsc, func_02045770(*(void **)(p + 0xb08 + idx * 4)));
    func_02045334(*(void **)(p + 0xb08 + idx * 4));
    obj = func_021DBF10(tab + off, heap);
    if (func_021DC024(tab + off) != 1)
        *(int *)(p + 0xb88 + idx * 4) = func_0204AC18(obj, func_021DBF40(tab + off), 0, (u16)((idx + 4) << 5), 0, 1, heap);
    *(int *)(p + 0xb68 + idx * 4) = func_0204AF28(obj, func_021DBFE4(tab + off), func_021DC004(tab + off), heap);
    *(int *)(p + 0xb48 + idx * 4) = func_0204A6C8(obj, func_021DBF9C(tab + off), 0, 0, heap);
    dx = 0;
    func_02049238(obj);
    dy = 0;
    func_02082BCC(&pos, 0, 8);
    pos.y = r.h[3];
    pos.flag = 1;
    if (func_021DC024(tab + off) == 2) {
        dx = 4;
        dy = 8;
    }
    if (a)
        pos.x = r.h[2];
    else if (b)
        pos.x = r.h[2] - 0x100;
    else if (b == 0)
        pos.x = r.h[2] + 0x100;
    else
        pos.x = r.h[2];
    pos.x += dx;
    pos.y += dy;
    *(void **)(p + 0xb28 + idx * 4) = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xb48 + idx * 4),
        func_021DC024(tab + off) == 1 ? *(u32 *)(p + 0xba8) : *(u32 *)(p + 0xb88 + idx * 4),
        *(u32 *)(p + 0xb68 + idx * 4), &pos, 0, *(u16 *)(p + 0x24));
    func_0204B6F4(*(void **)(p + 0xb28 + idx * 4), (u8)func_021DBF70(tab + off), 0);
    func_0204B3DC(*(void **)(p + 0xb28 + idx * 4), 1);
    if (*(u32 *)(p + 0xae0) && *(u16 *)(p + 0xade) == k) {
        cur.x = src->b[0] * 8 - 0x18;
        cur.y = d_021DF86F[index * 8] * 8 - 8;
        if (a == 0) {
            if (b)
                cur.x -= 0x100;
            else if (b == 0)
                cur.x += 0x100;
        }
        func_0204B404(*(void **)(p + 0xaf0), (const struct Vec2 *)(&cur), 0);
    }
}






#pragma opt_lifetimes reset






#pragma opt_loop_invariants reset






void func_021DB938(char *p,int a,u16 index)
{
    Rect_021DB938 rect;
    int y,x,tile;
    int yy;
    rect=*(const Rect_021DB938 *)((const Rect_021D9624 *)d_021DF86E + index);
    if((a && ((struct Obj13956 *)p)->fAD0==0) || (a==0 && ((struct Obj13956 *)p)->fAD0)) {
        index+=4;
        rect.b[0]+=32;
        rect.b[2]+=32;
    }
    for(y=0;y<7;y++) {
        yy=rect.b[1]+y;
        tile=y*32+384;
        for(x=0;x<12;x++)
            func_02041300(3,(u16)(x+tile),(u8)(rect.b[0]+x),yy,1,1,3);
    }
    func_02043B5C(func_02045770(*(void **)(p+0xb08+index*4)),0);
    func_02045334(*(void **)(p+0xb08+index*4));
    if(*(void **)(p+0xb28+index*4)) {
        func_0204B3B4((struct Obj_021DB938 *)(*(void **)(p+0xb28+index*4)));
        *(void **)(p+0xb28+index*4)=0;
        if(*(u32 *)(p+0xb88+index*4)!=-1) {
            func_0204ADA4(*(u32 *)(p+0xb88+index*4));
            *(u32 *)(p+0xb88+index*4)=-1;
        }
        if(*(u32 *)(p+0xb48+index*4)!=-1) {
            func_0204A8D4(*(u32 *)(p+0xb48+index*4));
            *(u32 *)(p+0xb48+index*4)=-1;
        }
        if(*(u32 *)(p+0xb68+index*4)!=-1) {
            func_0204AFD8(*(u32 *)(p+0xb68+index*4));
            *(u32 *)(p+0xb68+index*4)=-1;
        }
    }
}







void func_021DBA78(u8 *p,int a) { int v; if(a) v=-1; else v=1; ((struct Obj13957 *)p)->fADC=v; ((struct Obj13957 *)p)->fAD8=0; }






int func_021DBA94(char *p)
{
    int amount,i;
    s16 xy[4];
    if(((struct Obj02834 *)p)->fADC==0) goto idle;
    amount=(((struct Obj02834 *)p)->fADC*256)/16;
    for(i=0;i<8;i++) {
        if(*(void **)(p+i*4+0xb28)) {
            func_0204B454(*(void **)(p+i*4+0xb28),(struct PtS *)(xy+2),0);
            xy[2]-=(s16)amount;
            func_0204B404((struct Obj_021DB938 *)(*(void **)(p+i*4+0xb28)), (const struct Vec2 *)(xy+2), 0);
            func_0204B454(*(void **)(p+i*4+0xb28),(struct PtS *)xy,0);
            if(xy[0]>=-16 && xy[0]<=272 && xy[1]>=-16 && xy[1]<=208)
                func_0204B3DC((struct Obj_021DB938 *)(*(void **)(p+i*4+0xb28)), 1);
            else func_0204B3DC((struct Obj_021DB938 *)(*(void **)(p+i*4+0xb28)), 0);
        }
    }
    if(((struct Obj02834 *)p)->fAE0) {
        func_0204B454(((struct Obj02834 *)p)->fAF0,(struct PtS *)(xy+2),0);
        xy[2]-=(s16)amount;
        func_0204B404((struct Obj_021DB938 *)(((struct Obj02834 *)p)->fAF0), (const struct Vec2 *)(xy+2), 0);
        if(xy[2]>=-96 && xy[2]<=352 && xy[3]>=-96 && xy[3]<=288)
            func_0204B3DC((struct Obj_021DB938 *)(((struct Obj02834 *)p)->fAF0), 1);
        else func_0204B3DC((struct Obj_021DB938 *)(((struct Obj02834 *)p)->fAF0), 0);
    }
    func_02040618(3,1,amount);
    func_02040618(2,1,amount);
    if((((struct Obj02834 *)p)->fAD8)++>=15) {
        ((struct Obj02834 *)p)->fAD0^=1;
        ((struct Obj02834 *)p)->fADC=0;
    }
    return 0;
idle:
    return 1;
}







/*
 * Rebuild every entry from the list, free slot idx, then pull each later
 * slot down one place (swap into an empty slot), and mark the table dirty.
 */
void func_021DBC08(Obj_021DB938 *o, int idx)
{
    unsigned char buf[0xCC];
    u32 i;

    func_0200A094(o->list, idx);
    for (i = 0; i < func_0200A348((struct Obj_021DB938 *)o->list); i++)
        func_021DBEE4((u32)(&o->items[i]));
    for (i = 0; i < func_0200A348((struct Obj_021DB938 *)o->list); i++) {
        if (func_0200A0E4(o->list, i)) {
            func_0200A000(o->list, i, buf);
            func_021DBDF4((char *)(&o->items[i]), (const Record_021DB938 *)buf, (char *)((Obj_021DB938 *)o), o->f24);
        }
    }
    if (o->slots[idx] != 0) {
        func_021DD980(o->slots[idx]);
        o->slots[idx] = 0;
    }
    for (; idx < 11; idx++) {
        void *tmp = o->slots[idx];
        if (tmp == 0) {
            o->slots[idx] = o->slots[idx + 1];
            o->slots[idx + 1] = tmp;
        }
    }
    o->dirty = 1;
}







/*
 * note 2026-10-05 (lane Y6): no source existed. Same shape as matched sibling
 *   func_021DBC08 (rebuild entries from the list), then two slot teardowns and rebuilds from
 *   the descriptor. EXACT on the first compile with plain struct fields.
 */
void func_021DBCC8(Obj_021DBCC8 *o, u32 a, u32 b)
{
    unsigned char buf[0xCC];
    u32 i;

    func_0200A254(o->list, a, b);
    for (i = 0; i < func_0200A348((struct Obj_021DB938 *)o->list); i++)
        func_021DBEE4((u32)(&o->items[i]));
    for (i = 0; i < func_0200A348((struct Obj_021DB938 *)o->list); i++) {
        if (func_0200A0E4(o->list, i)) {
            func_0200A000(o->list, i, buf);
            func_021DBDF4((char *)(&o->items[i]), (const Record_021DB938 *)buf, (char *)((Obj_021DB938 *)o), o->f24);
        }
    }
    func_021DD980(o->slots[a]);
    func_021DD980(o->slots[b]);
    o->slots[a] = func_021DD24C((Record_021DD24C *)func_021DC02C(&o->items[a]), o->desc, o->ctx, o->f24);
    o->slots[b] = func_021DD24C((Record_021DD24C *)func_021DC02C(&o->items[b]), o->desc, o->ctx, o->f24);
    o->dirty = 1;
}







int func_021DBDB8(char *p) { return 3; }






/*
 * lever: Declare the index before the count, but initialise count first; this places index in r4 and count in r5.
 * prototype: func_0200A348 returns the value used by the bound. Its forwarding target 0200A400 reads only r0, so legacy trailing arguments are omitted.
 */
u32 func_021DBDBC(u32 p) { u32 i; u32 count=0; for (i=0;i<func_0200A348((struct Obj_021DB938 *)(((struct Obj22900 *)p)->fC));i++) { if (func_021DBF04((int *)(p+40+i*220))) count++; } return count; }





void func_021DBDF4(char *out,const Record_021DB938 *src,char *p,u16 heap)
{
    int flags;
    void *text,*other;
    s16 x,y;
    func_02082BCC(out,0,0xdc);
    if(src) {
        ((struct Obj10418 *)out)->f0=1;
        *(Record_021DB938 *)(out+4)=*src;
        ((struct Obj10418 *)out)->fD0=func_02043678(10,2,32,heap);
        flags=src->w[43];
        text=func_020457B0(128,heap);
        other=func_02045EC0(((struct Obj03788 *)p)->f1C,151);
        func_0201EFA4(((struct Obj03788 *)p)->f18,0,(u16)(flags>>16),4,1,1);
        func_0201EFA4(((struct Obj03788 *)p)->f18,1,(u8)(flags>>8),2,0,1);
        func_0201EFA4(((struct Obj03788 *)p)->f18,2,(u8)flags,2,0,1);
        func_0201F250(((struct Obj03788 *)p)->f18,text,other);
        x=40;
        x-=(s16)(func_0201D304(text,*(u32 *)&((struct Obj03788 *)p)->f10,0)/2);
        y=8-(s16)(func_0201D42C(text,((struct Obj03788 *)p)->f10)/2);
        func_0201C7A4(((struct Obj10418 *)out)->fD0,x,y,text,((struct Obj03788 *)p)->f10);
        func_02045808(text);
        func_02045808(other);
    }
}





void func_021DBEE4(u32 p) { if (((struct Obj13958 *)p)->f0) { func_020437AC(*(struct Obj020437AC * *)&((struct Obj13958 *)p)->fD0); func_02082BCC((void *)p,0,220); } }





int func_021DBF04(int *p) { return *p; }





void *func_021DBF08(void *p) { return ((struct Obj22903 *)p)->fD0; }




void *func_021DBF10(void *p,u16 heap) { switch(func_021DC024(p)) { case 1:return func_020490F4(7,heap); case 2:return func_020490F4(25,heap); default:return func_020490F4(34,heap); } }




/*
 * prototype: func_02020E60 item is u16 here, matching caller truncation before the call.
 */
u32 func_021DBF40(void *p) { switch(func_021DC024(p)) { case 1:return func_0201BC3C(); case 2:return func_02020E60(*(u32 *)func_021DC02C(p),2); default:return 3; } }




u32 func_021DBF70(void *p) { char *q; if (func_021DC024(p)==1) { q=func_021DC02C(p); return func_0201BB5C(((struct Obj08097 *)q)->f1A,((struct Obj08097 *)q)->f1C,((struct Obj08097 *)q)->f35,((struct Obj08097 *)q)->f5C); } return 0; }




int func_021DBF9C(void *p)
{
    char *q;
    switch(func_021DC024(p)) {
    case 1:
        q=func_021DC02C(p);
        return func_0201BABC(((struct Obj06452 *)q)->f1A,((struct Obj06452 *)q)->f1C,((struct Obj06452 *)q)->f35,((struct Obj06452 *)q)->f5C);
    case 2:
        q=func_021DC02C(p);
        return func_02020E60((u16)((struct Obj06452 *)q)->f0,1);
    default: return 12;
    }
}




int func_021DBFE4(void *p) { switch(func_021DC024(p)) { case 1: return func_0201BC40(); case 2: return 1; default:return 33; } }




int func_021DC004(void *p) { switch(func_021DC024(p)) { case 1: return func_0201BCB4(); case 2: return 0; default:return 36; } }




int func_021DC024(void *p) { return ((struct Obj22905 *)p)->fB7; }




char *func_021DC02C(void *p) { return (char *)p+4; }


int func_021DC030(u32 p) { return ((Bits *)(p+184))->flag; }


int func_021DC03C(void *p) { int i,add; i=func_021DC024(p); add=func_021DC030((u32)p) ? 0 : 5; return add+d_021DF838[i]; }


int func_021DC064(void *p) { int i,add; i=func_021DC024(p); add=func_021DC030((u32)p) ? 3 : 0; return add+d_021DF848[i]; }


static inline int wrap(int value,int low,int high)
{
    if(value>high) return low;
    if(value<low) return high;
    return value;
}


/*
 * spelling: BF04 uses char-pointer arithmetic and a signed acc read, retaining the post-switch acc reload; raw integer address arithmetic was four bytes short.
 * interfaces: 02035C60's live r0 is consumed by this caller despite its legacy void definition.
 */
void func_021DC08C(void *task,u32 *state,char *p)
{
    u32 repeat;
    int delta,changed,count,next,direction;
    Position_021DC030 pos;
    switch(*state) {
    case 0:
        func_0204B3DC(((struct Obj00061 *)p)->fAF4,1);
        func_0204B3DC(((struct Obj00061 *)p)->fAF8,1);
        func_0204B3DC(((struct Obj00061 *)p)->fAEC,1);
        repeat=func_0203633C();
        changed=0;delta=0;
        if(func_02035C60()) {
            ((struct Obj00061 *)p)->fAAC=*(void **)((u32)p+0xa7c+(u16)(((struct Obj00061 *)p)->fACC+*(u32 *)&((struct Obj00061 *)p)->fAC8*4)*4);
            if(((struct Obj00061 *)p)->fAAC) func_021DDF5C(((struct Obj00061 *)p)->fAAC);
        }
        if(repeat==512) delta=-1;
        else if(repeat==256) delta=1;
        else if(repeat&64) {
            func_020061E4(0x548);
            switch(((struct Obj00061 *)p)->fACC) {
            case 0:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=2;
                else {((struct Obj00061 *)p)->fAE4=1;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 1:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=3;
                else {((struct Obj00061 *)p)->fAE4=0;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 2: ((struct Obj00061 *)p)->fACC=0;break;
            case 3: ((struct Obj00061 *)p)->fACC=1;break;
            case 4:
                if(((struct Obj00061 *)p)->fAE4) ((struct Obj00061 *)p)->fACC=2;
                else ((struct Obj00061 *)p)->fACC=3;
                break;
            }
            changed=1;
        } else if(repeat&128) {
            func_020061E4(0x548);
            switch(((struct Obj00061 *)p)->fACC) {
            case 0: ((struct Obj00061 *)p)->fACC=2;break;
            case 1: ((struct Obj00061 *)p)->fACC=3;break;
            case 2:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=0;
                else {((struct Obj00061 *)p)->fAE4=1;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 3:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=1;
                else {((struct Obj00061 *)p)->fAE4=0;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 4:
                if(((struct Obj00061 *)p)->fAE4) ((struct Obj00061 *)p)->fACC=0;
                else ((struct Obj00061 *)p)->fACC=1;
                break;
            }
            changed=1;
        } else if(repeat&32) {
            func_021DBDB8(p);
            if(((struct Obj00061 *)p)->fACC==0 || ((struct Obj00061 *)p)->fACC==2) delta=-1;
            else if(((struct Obj00061 *)p)->fACC!=4) func_020061E4(0x548);
            if(((struct Obj00061 *)p)->fACC!=4) {
                if(((struct Obj00061 *)p)->fACC<=1) {
                    --((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,0,1);
                } else {
                    --((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,2,3);
                }
                changed=1;
            }
        } else if(repeat&16) {
            func_021DBDB8(p);
            if(((struct Obj00061 *)p)->fACC==1 || ((struct Obj00061 *)p)->fACC==3) delta=1;
            else if(((struct Obj00061 *)p)->fACC!=4) func_020061E4(0x548);
            if(((struct Obj00061 *)p)->fACC!=4) {
                if(((struct Obj00061 *)p)->fACC<=1) {
                    ++((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,0,1);
                } else {
                    ++((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,2,3);
                }
                changed=1;
            }
        } else if(func_020362DC()&1) {
            if(((struct Obj00061 *)p)->fACC==4) {
                if(((struct Obj00061 *)p)->fAE0==0) {
                    func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                    func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                    func_020061E4(0x54c);
                    func_021DA8B0(task,(u32)func_021DCCE4);
                }
            } else if(func_021DBF04((int *)(p+40+220*((u32)*(int *)&((struct Obj00061 *)p)->fACC+*(u32 *)&((struct Obj00061 *)p)->fAC8*4)))) {
                func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                func_020061E4(0x54c);
                if(((struct Obj00061 *)p)->fAE0) func_021DA8B0(task,(u32)func_021DC9CC);
                else func_021DA8B0(task,(u32)func_021DC4F0);
            }
        } else if(func_020362DC()&2) {
            func_020061E4(0x551);
            if(((struct Obj00061 *)p)->fAE0) {
                if(*(u8 * *)&((struct Obj00061 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00061 *)p)->fABC);((struct Obj00061 *)p)->fABC=0;}
                func_0204B3DC(((struct Obj00061 *)p)->fAF0,0);
                ((struct Obj00061 *)p)->fAE0=0;
            } else {
                func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                func_021DA8B0(task,(u32)func_021DCCE4);
            }
        }
        if(delta) {
            count=func_021DBDB8(p);
            if(delta<0) {
                if(((struct Obj00061 *)p)->fAC8) next=((struct Obj00061 *)p)->fAC8-1;
                else next=count-1;
                direction=1;
            } else if(delta>0) {
                if(((struct Obj00061 *)p)->fAC8<count-1) next=((struct Obj00061 *)p)->fAC8+1;
                else next=0;
                direction=0;
            }
            func_020061E4(0x642);
            func_021DBA78((u8 *)p,direction);
            func_021DB528(p,0);
            func_021DB478(p,0,direction,next,((struct Obj00061 *)p)->f24);
            ((struct Obj00061 *)p)->fAC8=next;
            func_0204B3DC(((struct Obj00061 *)p)->fAEC,0);
            func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
            func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
            ((struct Obj00061 *)p)->fBAC=0;
            ((struct Obj00061 *)p)->fA78=1;
            *state=1;
        }
        if(changed) {
            if((int)((struct Obj00061 *)p)->fACC<4) {
                pos.x=data_021DF86E[*(u32 *)(p+0xacc)].c.x*8-24;
                pos.y=data_021DF86E[*(u32 *)(p+0xacc)].c.y*8-8;
                func_0204B878(((struct Obj00061 *)p)->fAEC,0);
            } else {
                pos.x=176;pos.y=152;
                func_0204B878(((struct Obj00061 *)p)->fAEC,11);
            }
            func_0204B404(((struct Obj00061 *)p)->fAEC,(const struct Vec2 *)(&pos),0);
            ((struct Obj00061 *)p)->fBAC=0;
            ((struct Obj00061 *)p)->fA78=1;
        }
        break;
    case 1:
        if(func_021DBA94(p)) *state=0;
        break;
    }
}


void func_021DC4F0(void *task,u32 *state,u8 *p)
{
    Desc_021DC4F0 d;
    Vec v;
    int result;
    switch (*state) {
    case 0:
        if (!((struct Obj00169 *)p)->fABC) {
            ((struct Obj00169 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00169 *)p)->f14,((struct Obj00169 *)p)->f10,29);
            func_021D9FFC(((struct Obj00169 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,116,0);
        *state=1;
        break;
    case 1:
        func_02082BCC(&d,0,36);
        d.v[0]=*(u32 *)&((struct Obj00169 *)p)->f1C; d.v[1]=*(u32 *)&((struct Obj00169 *)p)->f10; d.v[2]=*(u32 *)&((struct Obj00169 *)p)->f14;
        d.v[3]=117;d.v[4]=118;d.v[5]=119;d.v[6]=3;
        d.a=0;d.b=15;d.c=13;d.d=1;
        ((struct Obj00169 *)p)->fAC0=func_021DA038((const u8 *)(&d),((struct Obj00169 *)p)->f24);
        *state=2;
        break;
    case 2:
        result=func_021DA178(((struct Obj00169 *)p)->fAC0);
        ((struct Obj00169 *)p)->fBAC=0x7fff;
        if (result==-1) break;
        if (result==0) {
            ((struct Obj00169 *)p)->fAE0=1;
            v.x=data_021DF86E[*(u32 *)(p+0xacc)].c.x*8-24;
            v.y=data_021DF86E[*(u32 *)(p+0xacc)].c.y*8-8;
            func_0204B404(((struct Obj00169 *)p)->fAF0,(const struct Vec2 *)(&v),0);
            func_0204B3DC(((struct Obj00169 *)p)->fAF0,1);
            ((struct Obj00169 *)p)->fADE=((struct Obj00169 *)p)->fACC+((struct Obj00169 *)p)->fAC8*4;
            if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
            if (*(u8 * *)&((struct Obj00169 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00169 *)p)->fABC);((struct Obj00169 *)p)->fABC=0;}
            if (!((struct Obj00169 *)p)->fABC) {
                ((struct Obj00169 *)p)->fABC=func_021D9D4C(0,15,((struct Obj00169 *)p)->f14,((struct Obj00169 *)p)->f10,29);
                func_021D9FFC(((struct Obj00169 *)p)->fABC,1,13);
            }
            func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,122,0);
            *state=6;
        } else if (result==1) {
            if (func_021DC030((u32)((void *)((u32)p+40+220*(((struct Obj00169 *)p)->fACC+((struct Obj00169 *)p)->fAC8*4))))) *state=7;
            else *state=3;
        } else if (result==2) *state=5;
        break;
    case 3:
        if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
        func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,120,1);
        *state=4;
        break;
    case 4:
        if (func_021D9FF8(((struct Obj00169 *)p)->fABC)) *state=5;
        break;
    case 5:
        if (*(u8 * *)&((struct Obj00169 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00169 *)p)->fABC);((struct Obj00169 *)p)->fABC=0;}
        if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
        func_021DA8B0(task,(u32)func_021DC08C);
        break;
    case 6:
        func_021DA8B0(task,(u32)func_021DC08C);
        break;
    case 7:
        func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;
        func_021DA8B0(task,(u32)func_021DC734);
        break;
    }
    if (*(u8 * *)&((struct Obj00169 *)p)->fABC) func_021D9E50(*(u8 * *)&((struct Obj00169 *)p)->fABC);
}


static inline void window0(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000040=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000044=((y<<8)&0xff00)|(yy&255);
}


static inline void inside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x04000048=v;
}


static inline void outside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x0400004a&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x0400004a=v;
}


/*
 * lever: int coordinate locals retain table loads before SDK window plane writes; u8 locals were 4 bytes short.
 * volatile: display control 021DC82C/838/950/958; window registers 021DC84E..892.
 */
void func_021DC734(void *task,u32 *state,char *p)
{
    Desc_021DC734 d;
    u32 index=W(0xac8)*4+W(0xacc);
    int result;
    int x,y;
    switch(*state) {
    case 0:func_021D9F08(P(0xabc),W(28),123,1);*state=1;break;
    case 1:
        if(func_021D9FF8(P(0xabc))) {
            func_02082BCC(&d,0,36);
            d.v[0]=W(28);d.v[1]=W(16);d.v[2]=W(20);
            d.v[3]=124;d.v[4]=125;d.v[6]=2;
            d.a=0;d.b=15;d.c=13;d.d=1;
            P(0xac0)=func_021DA038((const u8 *)&d,H(36));
            *state=2;
        }
        break;
    case 2:
        result=func_021DA178((char *)P(0xac0));
        H(0xbac)=0x7fff;
        if(result!=-1) {
            func_021DA148(P(0xac0));P(0xac0)=0;
            if(!result) *state=3;
            else {
                if(P(0xabc)) {func_021D9E04(P(0xabc));P(0xabc)=0;}
                func_021DA8B0(task,(u32)func_021DC08C);
            }
        }
        break;
    case 3:
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|0x2000;
        x=d_021DF86E[(u8)(index&3)*8];
        y=d_021DF86F[(u8)(index&3)*8];
        inside(30,1);
        window0(x*8,y*8,(x+12)*8,(y+7)*8);
        outside(30,0);*state=4;break;
    case 4:
        func_0207D658(0x04000050,30,W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=5;}
        break;
    case 5:
        func_021DBC08((Obj_021DB938 *)p, index);
        func_021DB528(p,1);
        func_021DB478(p,1,0,W(0xac8),H(36));
        W(0xa78)=1;*state=6;break;
    case 6:
        func_0207D658(0x04000050,30,16-W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=7;}
        break;
    case 7:
        if(!func_0200A170((char *)P(12))) func_021DA2F0(P(0xab8),1);
        *(volatile u32 *)0x04000000 &= ~0xe000;
        *state=8;break;
    case 8:func_021D9F08(P(0xabc),W(28),121,1);*state=9;break;
    case 9:if(func_021D9FF8(P(0xabc))) *state=10;break;
    case 10:
        if(P(0xabc)) {func_021D9E04(P(0xabc));P(0xabc)=0;}
        func_021DA8B0(task,(u32)func_021DC08C);break;
    }
    if(P(0xabc)) func_021D9E50(P(0xabc));
}


static inline void window1(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000042=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000046=((y<<8)&0xff00)|(yy&255);
}


static inline void inside0(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x04000048=v;
}


static inline void inside1(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f00)|((u32)planes<<8);
    if(effect) v|=32<<8;
    *(volatile u16 *)0x04000048=v;
}


/*
 * lever: index read through a two-field struct, but the row field is re-read as a plain int in the cases (a different type stops the CSE across the switch); previous-cell value shifted unsigned; col declared before row for the slot order. Twin shape: ov121 021DC734.
 * note: 2026-10-05 recoup P23L5: 8 B DIFF first form (asrs for lsrs and row/col slots swapped), then EXACT. Real extent 792 B, not the 46 B of the lane list.
 * volatile: display control 04000000, window registers 04000040..4A.
 */
void func_021DC9CC(void *task,u32 *state,char *p)
{
    u32 index=((Cur_021DC030 *)p)->col+((Cur_021DC030 *)p)->row*4;
    int here,there,mask;
    int x,y;
    u8 now,old;
    int col,row;
    switch(*state) {
    case 0:
        if(P(0xabc)) {func_021D9E04(P(0xabc));P(0xabc)=0;}
        W(0xae0)=0;
        if(index==H(0xade)) {
            func_0204B3DC((struct Obj *)P(0xaf0),0);
            func_021DA8B0(task,(u32)func_021DC08C);
            return;
        }
        *state=1;break;
    case 1:
        now=index&3;
        old=H(0xade)%4;
        here=((*(int *)(p+0xac8))==(index>>2));
        there=((*(int *)(p+0xac8))==((u32)H(0xade)>>2));
        mask=0;if(here) mask|=1;if(there) mask|=2;
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|(mask<<13);
        if(here) {
            x=d_021DF86E[now*8];y=d_021DF86F[now*8];
            inside0(30,1);window0(x*8,y*8,(x+12)*8,(y+7)*8);
        }
        if(there) {
            x=d_021DF86E[old*8];y=d_021DF86F[old*8];
            inside1(30,1);window1(x*8,y*8,(x+12)*8,(y+7)*8);
        }
        outside(30,0);*state=2;break;
    case 2:
        func_0207D658(0x04000050,30,W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=3;}break;
    case 3:
        func_021DBCC8((Obj_021DBCC8 *)p,index,H(0xade));func_020061E4(0x670);
        row=(u32)H(0xade)>>2;col=H(0xade)%4;
        there=((*(int *)(p+0xac8))==row);
        here=((*(int *)(p+0xac8))==(index>>2));
        if(here) {
            func_021DB938(p,1,W(0xacc));
            func_021DB54C(p,1,0,(*(int *)(p+0xac8)),W(0xacc),H(36));
        }
        if(there) {
            func_021DB938(p,1,col);
            func_021DB54C(p,1,0,row,col,H(36));
        }
        func_020409B4(3);W(0xa78)=1;*state=4;break;
    case 4:
        func_0207D658(0x04000050,30,16-W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=5;}break;
    case 5:*(volatile u32 *)0x04000000 &=~0xe000;*state=6;break;
    case 6:
        W(0xae0)=0;func_0204B3DC((struct Obj *)P(0xaf0),0);
        if(P(0xabc)) {func_021D9E04(P(0xabc));P(0xabc)=0;}
        func_021DA8B0(task,(u32)func_021DC08C);break;
    }
}


/*
 * lever: separate case-1 guard tests preserve the branch to the shared state store; a short-circuit guard gives DIFF404.
 */
void func_021DCCE4(void *arg,u32 *state,char *p)
{
    Desc_021DCCE4 d;
    int result;
    int ready;
    switch (*state) {
    case 0:
        *state=1;
        break;
    case 1:
        if (!((struct Obj00253 *)p)->f0) *state=5;
        else if (func_0200A0C8(((struct Obj00253 *)p)->fC)) *state=5;
        else *state=2;
        break;
    case 2:
        if (!((struct Obj00253 *)p)->fABC) {
            ((struct Obj00253 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00253 *)p)->f14,((struct Obj00253 *)p)->f10,29);
            func_021D9FFC(((struct Obj00253 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00253 *)p)->fABC,((struct Obj00253 *)p)->f1C,93,1);
        *state=3;
        break;
    case 3:
        if (func_021D9FF8(((struct Obj00253 *)p)->fABC)) {
            func_02082BCC(&d,0,36);
            d.v[0]=*(u32 *)&((struct Obj00253 *)p)->f1C;
            d.v[1]=*(u32 *)&((struct Obj00253 *)p)->f10;
            d.v[2]=*(u32 *)&((struct Obj00253 *)p)->f14;
            d.v[3]=124;
            d.v[4]=125;
            d.v[6]=2;
            d.a=0; d.b=15; d.c=13; d.d=1;
            ((struct Obj00253 *)p)->fAC0=func_021DA038((const u8 *)(&d),((struct Obj00253 *)p)->f24);
            *state=4;
        }
        break;
    case 4:
        result=func_021DA178(((struct Obj00253 *)p)->fAC0);
        ((struct Obj00253 *)p)->fBAC=0x7fff;
        if (result!=-1) {
            func_021DA148(((struct Obj00253 *)p)->fAC0);
            ((struct Obj00253 *)p)->fAC0=0;
            if (!result) *state=5;
            else {
                if (((struct Obj00253 *)p)->fABC) {
                    func_021D9E04(((struct Obj00253 *)p)->fABC);
                    ((struct Obj00253 *)p)->fABC=0;
                }
                func_021DA8B0(arg,(u32)func_021DC08C);
            }
        }
        break;
    case 5:
        if (((struct Obj00253 *)p)->fAD4) *state=6;
        else *state=10;
        break;
    case 6:
        if (!((struct Obj00253 *)p)->fABC) {
            ((struct Obj00253 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00253 *)p)->f14,((struct Obj00253 *)p)->f10,29);
            func_021D9FFC(((struct Obj00253 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00253 *)p)->fABC,((struct Obj00253 *)p)->f1C,115,2);
        *state=7;
        break;
    case 7:
        if (func_021D9FF8(((struct Obj00253 *)p)->fABC)) *state=8;
        break;
    case 8:
        ready=1;
        if (((struct Obj00253 *)p)->fAAC && !func_021DE014(((struct Obj00253 *)p)->fAAC)) ready=0;
        if (ready) {
            func_0200A2B8(((struct Obj00253 *)p)->fC,(int)(((struct Obj00253 *)p)->f20));
            *state=9;
        }
        break;
    case 9:
        if (func_0200A2D8(((struct Obj00253 *)p)->fC,(int)(((struct Obj00253 *)p)->f20))==2) *state=10;
        break;
    case 10:
        if (((struct Obj00253 *)p)->fABC) {
            func_021D9E04(((struct Obj00253 *)p)->fABC);
            ((struct Obj00253 *)p)->fABC=0;
        }
        func_021DA8B8(arg);
        break;
    }
    if (((struct Obj00253 *)p)->fABC) func_021D9E50(((struct Obj00253 *)p)->fABC);
}


void func_021DCEC4(void *arg,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (!((struct Obj01930 *)p)->fABC)
            ((struct Obj01930 *)p)->fABC=func_021D9CA4(0,15,((struct Obj01930 *)p)->f14,((struct Obj01930 *)p)->f10,29);
        func_021D9FFC(((struct Obj01930 *)p)->fABC,1,13);
        func_021D9F08(((struct Obj01930 *)p)->fABC,((struct Obj01930 *)p)->f1C,92,1);
        *state=1; break;
    case 1:
        if (func_021D9FF8(((struct Obj01930 *)p)->fABC)) *state=2;
        break;
    case 2:
        if (((struct Obj01930 *)p)->fABC) {
            func_021D9E04(((struct Obj01930 *)p)->fABC);
            ((struct Obj01930 *)p)->fABC=0;
        }
        func_021DA8B0(arg,(u32)func_021DC08C);
        break;
    }
    if (((struct Obj01930 *)p)->fABC) func_021D9E50(((struct Obj01930 *)p)->fABC);
}


/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021DCF54(char *p,void *arc,int id,int index,u8 other,u16 heap)
{
    void *res;
    void *allocation;
    char *data;
    func_02082BCC(p,0,0x60);
    allocation=func_02049F78(arc,id,(u32)(&res),heap);
    data=*(char * *)&((struct Obj22906 *)res)->fC;
    func_02082D44(data+index*32,p+0x40,32);
    func_02082D44(data+other*32,p+0x20,32);
    func_020307B0(allocation);
}


void func_021DCFA4(u8 *p,int b,int c,u16 d) {func_021DAB50((void *)b,(u16 *)p,d,c,(const u16 *)(p+32),(const u16 *)(p+64));}


/*
 * lever: const descriptor input places its loads before the outgoing heap store.
 * interfaces: D81C/D898 scalar stack words reproduce the aggregate layout; complete bodies and forwarding targets read no padding, key only low halfword.
 */
void *func_021DCFC8(const Desc_021DCFC8 *p,u16 heap)
{
    char *out;
    Config config;
    Record_021DCFC8 first;
    Record_021DCFC8 second;
    void *arc;
    void *arc2;
    out=func_02030734(heap,208,0,d_021DFBB0,0xcff);
    ((struct Obj00237 *)out)->f88=p->w[5];
    ((struct Obj00237 *)out)->f94=p->w[0];
    ((struct Obj00237 *)out)->f96=p->w[1];
    *(Desc_021DCFC8 *)(out+0xa0)=*p;
    if(p->w[0]<4) {
        ((struct Obj00237 *)out)->f9C=0;
        ((struct Obj00237 *)out)->f98=0;
        ((struct Obj00237 *)out)->f84=1;
    } else {
        ((struct Obj00237 *)out)->f9C=4;
        ((struct Obj00237 *)out)->f98=1;
        ((struct Obj00237 *)out)->f84=0;
    }
    config=d_021DF99C;
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    ((struct Obj00237 *)out)->f0=((void *(*)())func_021DA1BC)((void *)1,(const char *)&config,5,(u16)((struct Obj00237 *)out)->fA4,(u8)((struct Obj00237 *)out)->fAC,((struct Obj00237 *)out)->fC8,((struct Obj00237 *)out)->fC0,((struct Obj00237 *)out)->fC4,heap);
    arc=func_020490F4(34,heap);
    *(int *)&((struct Obj00237 *)out)->f4=func_0204ABF0(arc,3,((struct Obj00237 *)out)->f98,(u16)(p->w[4]<<5),heap);
    *(int *)&((struct Obj00237 *)out)->fC=func_0204AF28(arc,33,36,heap);
    *(int *)&((struct Obj00237 *)out)->f8=func_0204A6C8(arc,12,0,((struct Obj00237 *)out)->f98,heap);
    func_02049238(arc);
    func_02082BCC(&first,0,8);
    first.x=216;first.y=22;
    ((struct Obj00237 *)out)->f1C=func_0204B294((void *)p->w[6],((struct Obj00237 *)out)->f8,((struct Obj00237 *)out)->f4,((struct Obj00237 *)out)->fC,&first,((struct Obj00237 *)out)->f98,heap);
    func_0204B688(((struct Obj00237 *)out)->f1C,0);
    func_0204B3DC(((struct Obj00237 *)out)->f1C,0);
    arc2=(void *)func_0202D7C8(heap);
    *(int *)&((struct Obj00237 *)out)->f10=func_0202D7D8((int)arc2,1,0,0,0,0,0,((struct Obj00237 *)out)->f98,p->w[5]<<5,heap);
    *(int *)&((struct Obj00237 *)out)->f18=func_0202D898(1,0,0,0,0,0,2,((struct Obj00237 *)out)->f98,heap);
    *(int *)&((struct Obj00237 *)out)->f14=func_0202D81C(arc2,1,0,0,0,0,0,0,((struct Obj00237 *)out)->f98,heap);
    func_02049238(arc2);
    func_02082BCC(&second,0,8);
    second.x=184;second.y=112;second.b=p->w[0]&3;
    ((struct Obj00237 *)out)->f8C=second.b;
    ((struct Obj00237 *)out)->f90=p->w[1]&3;
    ((struct Obj00237 *)out)->f20=func_0204B294((void *)p->w[6],((struct Obj00237 *)out)->f14,((struct Obj00237 *)out)->f10,((struct Obj00237 *)out)->f18,&second,((struct Obj00237 *)out)->f98,heap);
    func_0204B570(((struct Obj00237 *)out)->f20,2);
    func_0204B688(((struct Obj00237 *)out)->f20,1);
    func_0204B3DC(((struct Obj00237 *)out)->f20,0);
    return out;
}


void func_021DD1FC(void **p)
{
    func_0204B3B4(p[8]);
    func_0204A8D4((u32)p[5]);
    func_0204AFD8((u32)p[6]);
    func_0204ADA4((u32)p[4]);
    func_0204B3B4(p[7]);
    func_0204A8D4((u32)p[2]);
    func_0204AFD8((u32)p[3]);
    func_0204ADA4((u32)p[1]);
    func_021DA280(p[0]);
    func_020307B0(p);
}


int func_021DD240(void **p) {return func_021DA2C8(*p);}



struct Out_021DC030 *func_021DD24C(Record_021DD24C *a, struct CtxB *b, void *c, u16 heap)
{
    struct Out_021DC030 *out;
    struct Ctx ctx;
    Desc_021DD24C desc;
    void *res;
    u16 idx;
    void *t4;
    int flags;
    void *mon;
    void *gs;
    u8 day;
    u32 month;
    u16 year;
    u32 mode;
    u32 gender;
    u64 rnd;
    u32 species;
    u16 level;
    u16 hid;
    u32 id16;
    u32 id;
    u64 id64;

    out = func_02030734(heap, 0x148, 0, d_021DFBB0, 0xDD4);
    func_02082BCC(out, 0, 0x148);
    out->heap = heap;
    out->a = (struct Rec_021DC030 *)a;
    out->b = b;
    out->c = c;
    func_02082BCC(&ctx, 0, 0x24);
    ctx.f0 = 0;
    ctx.f8 = b->fB8;
    ctx.fC = b->fBC;
    ctx.f10 = b->fC4;
    ctx.f14 = b->fC8;
    ctx.f18 = b->fCC;
    ctx.f1C = b->fC0;
    ctx.f20 = (u32)c;
    func_021DBDF4((char *)out, (const Record_021DB938 *)a, (char *)&ctx, heap);
    desc = d_021DFA14;
    id16 = (heap & 0x7fff) | 0x8000;
    desc.e[1].f8 = func_020457B0(0x25, (u16)id16);
    func_02045994(desc.e[1].f8, (const u16 *)((char *)out->a + 0x60), 0x24);
    if (out->a->fB4b)
        idx = out->a->fB2 + 0x19d;
    else
        idx = out->a->fB2 + 0x9d;
    desc.e[2].f8 = func_02045EC0((void *)b->fC0, idx);
    desc.e[4].f8 = func_020457B0(0x80, heap);
    flags = out->a->fAC;
    t4 = func_02045EC0((void *)b->fC0, 0x9a);
    res = 0;
    func_0201EFA4((void *)b->fCC, 0, (u16)(flags >> 16), 4, 1, 1);
    func_0201EFA4((void *)b->fCC, 1, (u8)(flags >> 8), 2, 0, 1);
    func_0201EFA4((void *)b->fCC, 2, (u8)flags, 2, 0, 1);
    func_0201F250((void *)b->fCC, desc.e[4].f8, t4);
    out->f144 = func_021DA338(*(void **)b, heap);
    func_021DA3EC(out->f144, (char *)(&desc), (void *)b->fC8);
    func_02045808(desc.e[1].f8);
    func_02045808(desc.e[2].f8);
    func_02045808(desc.e[4].f8);
    func_02045808(t4);
    if (func_021DC024(out) == 1) {
        struct Rec_021DC030 *r = out->a;
        u16 mv[4];
        u8 iv[6];
        int i;
        u32 k;
        u32 ivs;

        gs = out->c;
        hid = id16;
        level = r->f5B;
        id = r->f0;
        species = r->species;
        gender = r->f35;
        mode = r->f36;

        iv[0] = r->iv0;
        iv[1] = r->iv1;
        iv[2] = r->iv2;
        iv[3] = r->iv7;
        iv[4] = r->iv3;
        iv[5] = r->iv6;
        mv[0] = r->mv[0];
        mv[1] = r->mv[1];
        mv[2] = r->mv[2];
        mv[3] = r->mv[3];
        if (r->fB3 == 1 && species <= 0x289 && species != 0 && level <= 0x64 && r->f10 <= 0x289 - 0x17) {
            if (level == 0)
                level = (u16)(func_020056EC(0x64) + 1);
            if (r->f0 == 0)
                id = func_02008530((const struct Sub0200852CObj *)func_02012944(gs));
            if (gender == 0xff)
                gender = 2;
            for (i = 0; i < 6; i++) {
                if (iv[i] == 0xff)
                    iv[i] = func_020056EC(0x20);
            }
            id64 = id;
            mon = func_020173F0((u16)species, level, id, 0, hid);
            ivs = (iv[0] & 31) | ((iv[1] & 31) << 5) | ((iv[2] & 31) << 10) | ((iv[3] & 31) << 15) | ((iv[4] & 31) << 20) | ((iv[5] & 31) << 25);
            if (mode == 4)
                mode = (u8)func_020056EC(3);
            switch (mode) {
            case 0:
                i = 0;
                break;
            case 1:
                i = 1;
                break;
            case 2:
                i = 0;
                break;
            case 3:
                i = 2;
                break;
            default:
                res = 0;
                goto end;
            }
            if (r->f8 != 0)
                rnd = r->f8;
            else {
                if (r->f37 == 0)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 0);
                else if (r->f37 == 1)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 2);
                else if (r->f37 == 2)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 1);
            }
            func_02017588(mon, r->species, level, id64, ivs, rnd);
            func_02017E40(mon, 6, r->f10);
            func_02017FA8(mon);
            for (i = 0; i < 4; i++) {
                u16 m = mv[i];
                if (m != 0 && m < 0x230) {
                    if (func_0201808C(mon, m) == 0xffff)
                        func_020180F4(mon, m);
                }
            }
            if (r->f8 == 0 && mode == 2)
                func_02018A00(mon, species, r->form);
            func_02017E40(mon, 0x6f, r->form);
            if (r->fE != 0 && r->fE <= 0x19)
                func_02017E40(mon, 0x98, r->fE);
            else
                func_02017E40(mon, 0x98, 4);
            if (r->f3C != 0)
                func_02017E40(mon, 0x99, r->f3C);
            func_02017E40(mon, 0x13, r->f3D);
            func_02017E40(mon, 0x14, r->f3E);
            func_02017E40(mon, 0x15, r->f3F);
            func_02017E40(mon, 0x16, r->f40);
            func_02017E40(mon, 0x17, r->f41);
            func_02017E40(mon, 0x18, r->f41);
            for (k = 0; k < 15; k++) {
                if (r->fC & (1 << k))
                    func_02017E40(mon, d_021DF8C0[k], 1);
            }
            if (r->f4 == 0)
                func_02017E40(mon, 0x77, g0209DF08);
            else
                func_02017E40(mon, 0x77, r->f4);
            if (r->f1D == 0)
                func_02017E40(mon, 0xc, g0209DF0C);
            else
                func_02017E40(mon, 0xc, r->f1D);
            if (r->f1E == 0) {
                func_020307B0(mon);
                res = 0;
                goto end;
            }
            if (r->f1E != func_02045A98())
                func_02017E40(mon, 0x74, (u32)&r->f1E);
            {
                u32 v = r->f34;
                if (v == 0xff)
                    v = (u8)func_020056EC(0x19);
                func_02017E40(mon, 0x70, v);
            }
            func_02017E40(mon, 0x95, r->f38);
            func_02017E40(mon, 0x96, r->f3A);
            if (r->f4A == 0) {
                func_020307B0(mon);
                res = 0;
                goto end;
            }
            if (r->f4A == func_02045A98())
                func_02017E40(mon, 0x8e, (u32)func_020084F4(func_02012944(gs)));
            else
                func_02017E40(mon, 0x8e, (u32)&r->f4A);
            {
                u32 v = r->f5A;
                if (v <= 2)
                    func_02017E40(mon, 0x9a, v);
                else {
                    v = func_02008550((const struct Sub0200852CObj *)func_02012944(gs));
                    func_02017E40(mon, 0x9a, v);
                }
            }
            if (r->f5C != 0) {
                void *s;
                func_02017E40(mon, 0x4c, 1);
                s = func_02045EC0(gMsgBank, 0x28a);
                func_02017E40(mon, 0x73, (u32)s);
                func_02045808(s);
                func_02017E40(mon, 9, 10);
            }
            {
                int w = r->fAC;
                u32 loc;
                year = w >> 16;
                month = (u8)(w >> 8);
                day = w;
                loc = r->f5C ? r->f38 : r->f3A;
                func_0202F2AC(func_020185F0(mon), loc, year - 2000, month, day);
            }
            func_020185C4(mon);
            res = 0;
            if (func_02017E1C(mon, 3, 0) != 0)
                func_020307B0(mon);
            else
                res = mon;
            goto end;
        }
    end:
        {
            void *arc = (void *)func_0202D7C8((u16)id16);
            u32 a0, a1, a2, a3;
            out->fE4 = r->species;
            out->fE6 = r->form;
            out->fE0 = r->f5C;
            a0 = func_0202D060();
            a1 = func_02017E1C(res, 5, 0);
            a2 = func_02017E1C(res, 0x6f, 0);
            a3 = func_02017E1C(res, 0x6e, 0);
            idx = func_0202D0D4(a0, a1, a2, a3, func_02017EAC(res), 0, func_02017E1C(res, 0x4c, 0));
            out->f13C = func_02049F78(arc, idx, (u32)(&out->f140), out->heap);
            out->f134 = (u32)func_0202D6F4(&out->f138, func_020185F4(res), 0, out->heap);
            func_020307B0(res);
            func_02049238(arc);
        }
    }
    return out;
}
