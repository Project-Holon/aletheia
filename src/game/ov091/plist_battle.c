/*
 * file:     plist_battle.c
 * unit:     yes
 * function: func_021B8DB4, func_021B8F68, func_021B8FC4, func_021B9020, func_021B907C, func_021B90F8, func_021B916C, func_021B9750, func_021B9788, func_021B97D4, func_021B9804, func_021B981C, func_021B9968, func_021B999C, func_021B99E4, func_021B9A84, func_021B9AA0, func_021B9AB4, func_021B9AC8, func_021B9BF4, func_021B9C1C, func_021B9C64, func_021B9CB0, func_021B9CF4, func_021B9D58, func_021B9DC0, func_021B9E20, func_021B9E3C, func_021B9E44, func_021B9EB0, func_021B9EC0, func_021B9F34, func_021B9F44, func_021BA004, func_021BA0A8, func_021BA288, func_021BA318, func_021BA3A4, func_021BA454, func_021BA4E4, func_021BA4F8, func_021BA5B4, func_021BA5E0, func_021BA60C, func_021BA624, func_021BA65C, func_021BA670, func_021BA688, func_021BA6A0, func_021BA81C, func_021BA890, func_021BA8CC, func_021BA954, func_021BAA50, func_021BAAE4, func_021BAB04, func_021BAE94, func_021BAF28, func_021BAFA0, func_021BB050, func_021BB0C4, func_021BB1A0, func_021BB200, func_021BB2C0, func_021BB2E0, func_021BB30C, func_021BB358, func_021BB3C4, func_021BB3D4, func_021BB3FC, func_021BB43C, func_021BB440, func_021BB464, func_021BB468, func_021BB46C, func_021BB4A0, func_021BB554, func_021BB56C, func_021BB594, func_021BB5FC, func_021BB644, func_021BB714, func_021BB7A4, func_021BB7D8, func_021BB7E8, func_021BB860, func_021BB8FC, func_021BB910, func_021BB97C, func_021BB98C, func_021BB99C, func_021BB9AC, func_021BB9CC, func_021BB9DC, func_021BB9EC, func_021BBA0C, func_021BBA28, func_021BBA54, func_021BBA68, func_021BBA70, func_021BBA8C, func_021BBAE0, func_021BBAF8, func_021BBB40, func_021BBBA0, func_021BBBD8, func_021BBBE4, func_021BBC04, func_021BBD98, func_021BBDEC, func_021BBE44, func_021BBE50, func_021BBE5C, func_021BBE68, func_021BBE74, func_021BC17C, func_021BC1B4, func_021BC1D0, func_021BC228, func_021BC24C, func_021BC288, func_021BC2C8, func_021BC30C, func_021BC350, func_021BC548, func_021BC5CC, func_021BC628, func_021BC6A0, func_021BC6C0, func_021BC6CC, func_021BCC2C, func_021BCC40, func_021BCC80, func_021BCCCC, func_021BCD80, func_021BCDE8, func_021BCE84, func_021BCE9C, func_021BCEAC, func_021BD058, func_021BD05C, func_021BD18C, func_021BD1BC, func_021BD218, func_021BD454, func_021BD480, func_021BD4EC, func_021BD504, func_021BD59C, func_021BD61C, func_021BD634, func_021BD8B0, func_021BD8E4, func_021BD9C8, func_021BDABC, func_021BDBE0, func_021BDBF8, func_021BDC3C, func_021BDC5C, func_021BDCA0, func_021BDCC0, func_021BDD58, func_021BDD78, func_021BE2B4, func_021BE874, func_021BE914, func_021BE948, func_021BE9BC
 * address:  0x021B8DB4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021BEC2C     0x021BEC2C  data  ov091  a1
 *   func_0204B404  0x0204B404  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0207D658  0x0207D658  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020355D8  0x020355D8  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02041570  0x02041570  arm
 *   func_020355C4  0x020355C4  arm
 *   func_021B8418 0x021B8418 thumb ov091
 *   func_0215EA14 0x0215EA14 thumb ov010
 *   func_02013E04 0x02013E04 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021BEC0C 0x021BEC0C data a4
 *   d_021BEC1C 0x021BEC1C data a4
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021B7B98 0x021B7B98 thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02009050 0x02009050 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0200902C 0x0200902C thumb
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B8180 0x021B8180 thumb ov091
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201AB8C 0x0201AB8C thumb
 *   func_0202130C 0x0202130C thumb
 *   func_020188AC 0x020188AC thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02009020  0x02009020  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_0201A59C  0x0201A59C  thumb
 *   func_0201808C 0x0201808C thumb
 *   func_02018238 0x02018238 thumb
 *   func_020181F4 0x020181F4 thumb
 *   func_020182A0 0x020182A0 thumb
 *   func_0201B7A0 0x0201B7A0 thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_02007E50 0x02007E50 thumb
 *   func_02030734 0x02030734 arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B258 0x0204B258 arm
 *   func_0204B09C 0x0204B09C arm
 *   func_020450F0 0x020450F0 arm
 *   d_021BED18 0x021BED18 data ov091 a1
 *   d_021BEC74 0x021BEC74 data ov091 a1
 *   d_021BEC75 0x021BEC75 data ov091 a1
 *   d_021BEC6C 0x021BEC6C data ov091 a1
 *   d_021BEC6D 0x021BEC6D data ov091 a1
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02017F90  0x02017F90  thumb
 *   func_0204B8F4  0x0204B8F4  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020490F4  0x020490F4  arm
 *   func_020185F4  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0201BBE8  0x0201BBE8  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02018430  0x02018430  thumb
 *   func_0202D01C  0x0202D01C  thumb
 *   func_02043AF4  0x02043AF4  arm
 *   g_020A7370     0x020A7370  data
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02045780 0x02045780 arm
 *   func_02041300  0x02041300  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02019DA4 0x02019DA4 thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_0204B0C8 0x0204B0C8 arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   sub_0203101C   0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   d_021BED28     0x021BED28  data  ov091  a1
 *   func_0202F038  0x0202F038  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_0202865C 0x0202865C thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02028470  0x02028470  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02006238  0x02006238  thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF4C 0x0201EF4C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F140 0x0201F140 thumb
 *   func_02028618 0x02028618 thumb
 *   func_020275E4  0x020275E4  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_02049DB4  0x02049DB4  arm
 *   d_021BED38     0x021BED38  data  ov091  a1
 *   func_02027778  0x02027778  thumb
 *   d_021BEC80     0x021BEC80  data  a4
 *   func_02027858 0x02027858 thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   d_021BEC8C     0x021BEC8C  data  ov091  a4
 *   func_02027FEC  0x02027FEC  thumb
 *   func_02028148  0x02028148  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02028218  0x02028218  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_02020F34 0x02020F34 thumb
 *   func_02021014 0x02021014 thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_02019CF8 0x02019CF8 thumb
 *   func_02017988 0x02017988 thumb
 *   func_02019D00  0x02019D00  thumb
 *   func_02027268 0x02027268 thumb
 *   d_021BECE4 0x021BECE4 data ov091 a2
 *   func_020456F8 0x020456F8 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02018328 0x02018328 thumb
 *   func_02049BDC 0x02049BDC arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02027694 0x02027694 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02082A60 0x02082A60 arm
 *   func_02045924 0x02045924 arm
 *   d_021BED48 0x021BED48 data ov091 a1
 *   func_02061CA4 0x02061CA4 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02040588 0x02040588 arm
 *   func_021B7034 0x021B7034 thumb ov091
 *   func_021B6F28 0x021B6F28 thumb ov091
 *   func_021B7040 0x021B7040 thumb ov091
 *   func_021B6F0C 0x021B6F0C thumb ov091
 *   func_02051614 0x02051614 arm
 *   func_02051574 0x02051574 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02051534 0x02051534 arm
 *   func_02047970 0x02047970 arm
 *   func_02006BD0 0x02006BD0 thumb
 *   func_0205121C 0x0205121C arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_02050C04 0x02050C04 arm
 *   func_02051230 0x02051230 arm
 *   func_020515B4 0x020515B4 arm
 *   d_021BED58 0x021BED58 data ov091 a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02050DB8 0x02050DB8 arm
 *   func_0203D7FC 0x0203D7FC arm
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02011400  0x02011400  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_0201C158 0x0201C158 thumb
 *   func_0201B920 0x0201B920 thumb
 *   func_02018584 0x02018584 thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_0201B970 0x0201B970 thumb
 *   func_021BEA48 0x021BEA48 thumb ov091
 */
#include "../../matched/include/Obj09925.h"
#include "../../matched/include/Obj01229.h"
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj20860.h"
#include "../../matched/include/Obj20861.h"
#include "../../matched/include/Obj20862.h"
#include "../../matched/include/Obj13241.h"
#include "../../matched/include/Obj09926.h"
#include "../../matched/include/Obj13242.h"
#include "../../matched/include/Obj06211.h"
#include "../../matched/include/Obj02771.h"
#include "../../matched/include/Obj09927.h"
#include "../../matched/include/Obj13244.h"
#include "../../matched/include/Obj13245.h"
#include "../../matched/include/Obj13246.h"
#include "../../matched/include/Obj20864.h"
#include "../../matched/include/Obj20865.h"
#include "../../matched/include/Obj20866.h"
#include "../../matched/include/Obj20869.h"
#include "../../matched/include/Obj20870.h"
#include "../../matched/include/Obj20871.h"
#include "../../matched/include/Obj20872.h"
#include "../../matched/include/Obj13247.h"
#include "../../matched/include/Obj03678.h"
#include "../../matched/include/Obj20873.h"
#include "../../matched/include/Obj07731.h"
#include "../../matched/include/Obj05169.h"
#include "../../matched/include/Obj05170.h"
#include "../../matched/include/Obj03183.h"
#include "../../matched/include/Obj20875.h"
#include "../../matched/include/Obj20876.h"
#include "../../matched/include/Obj03679.h"
#include "../../matched/include/Obj20878.h"
#include "../../matched/include/Obj20879.h"
#include "../../matched/include/Obj20880.h"
#include "../../matched/include/Obj13251.h"
#include "../../matched/include/Obj20884.h"
#include "../../matched/include/Obj03680.h"
#include "../../matched/include/Obj20885.h"
#include "../../matched/include/Obj20886.h"
#include "../../matched/include/Obj20887.h"
#include "../../matched/include/Obj09930.h"
#include "../../matched/include/Obj06213.h"
#include "../../matched/include/Obj13252.h"
#include "../../matched/include/Obj20889.h"
#include "../../matched/include/Obj13253.h"
#include "../../matched/include/Obj20890.h"
#include "../../matched/include/Obj20891.h"
#include "../../matched/include/Obj20892.h"
#include "../../matched/include/Obj20893.h"
#include "../../matched/include/Obj20894.h"
#include "../../matched/include/Obj20895.h"
#include "../../matched/include/Obj20896.h"
#include "../../matched/include/Obj03681.h"
#include "../../matched/include/Obj20898.h"
#include "../../matched/include/Obj09931.h"
#include "../../matched/include/Obj20900.h"
#include "../../matched/include/Obj09933.h"
#include "../../matched/include/Obj13254.h"
#include "../../matched/include/Obj07734.h"
#include "../../matched/include/Obj13255.h"
#include "../../matched/include/Obj13256.h"
#include "../../matched/include/Obj20901.h"
#include "../../matched/include/Obj13257.h"
#include "../../matched/include/Obj05174.h"
#include "../../matched/include/Obj07735.h"
#include "../../matched/include/Obj20908.h"
#include "../../matched/include/Obj03682.h"
#include "../../matched/include/Obj07736.h"
#include "../../matched/include/Obj00047.h"
#include "../../matched/include/Obj07737.h"
#include "../../matched/include/Obj01888.h"
#include "../../matched/include/Obj20910.h"
#include "../../matched/include/Obj20911.h"
#include "../../matched/include/Obj20912.h"
#include "../../matched/include/Obj20913.h"
#include "../../matched/include/Obj20914.h"
#include "../../matched/include/Obj20915.h"
#include "../../matched/include/Obj20916.h"
#include "../../matched/include/Obj20917.h"
#include "../../matched/include/Obj20918.h"
#include "../../matched/include/Obj13261.h"
#include "../../matched/include/Obj20919.h"
#include "../../matched/include/Obj20920.h"
#include "../../matched/include/Obj09934.h"
#include "../../matched/include/Obj06214.h"
#include "../../matched/include/Obj20921.h"
#include "../../matched/include/Obj20922.h"
#include "../../matched/include/Obj20923.h"
#include "../../matched/include/Obj20924.h"
#include "../../matched/include/Obj20925.h"
#include "../../matched/include/Obj20926.h"
#include "../../matched/include/Obj04353.h"
#include "../../matched/include/Obj13262.h"
#include "../../matched/include/Obj06215.h"
#include "../../matched/include/Obj09935.h"
#include "../../matched/include/Obj20927.h"
#include "../../matched/include/Obj20928.h"
#include "../../matched/include/Obj20929.h"
#include "../../matched/include/Obj20930.h"
#include "../../matched/include/Obj20931.h"

#define reg_G2_WIN0H  (*(volatile u16 *)0x04000040)
#define reg_G2_WIN0V  (*(volatile u16 *)0x04000044)
#define reg_G2_WININ  (*(volatile u16 *)0x04000048)
#define reg_G2_WINOUT (*(volatile u16 *)0x0400004A)
#define reg_G2_BLDCNT (*(volatile u16 *)0x04000050)
#define A (*(int **)((p+W(0x2c)*4)+0x160))
#define ROW(i) (*(u8 **)(p + (i) * 4 + 0x160))
#define APPEND(v) do { *(u16 *)(s + s[0] * 2 + 2) = (v); s[0]++; } while (0)
#define GET(k) func_02021014(p,(k))
#define DONE(k) {func_020307B0(p);return(k);}
#define F(o) (*(int *)(W(0x280) + (o)))
struct Obj;
struct Vec2;
struct Sub02008F80Obj;
struct Party;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct WordSet;
struct Bank;
struct Cfg;
struct PrintSys;
struct Bmp;
struct CharBuf;
struct Owner;
struct Pt;
struct Tcbl;
struct Rec3;
struct S02031140;
struct Blk;
struct Ctx;
struct Rec;
struct TaskMenu;
struct TaskMenuTmpl;
struct StrObj;
struct Strbuf;
struct Blk37;
struct RtcTime;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Rect_021B8DB4 {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} Rect_021B8DB4;

typedef struct Rect4 {
    Rect_021B8DB4 r[4];
} Rect4;

typedef int BOOL;

typedef struct { int v[4]; } Four;

typedef short s16;

typedef struct {
    u16 id;
    char pad[0x27e];
    int *f;
} P;

typedef signed short   s16_021B9C64;

typedef struct { short x,y; u16 a,b,c,d; int e,f; } Rect_021B9C64;

typedef struct {
    int w0;
    u8 b4;
    u8 pad5[15];
    int w14;
    int pad18;
    int w1c;
} S44;

typedef short s16_021BA624;

typedef struct {
    int w0;
    u16 pad4;
    u16 h6;
    int pad8[2];
    int w10;
    int w14;
    int w18;
    int pad1c;
    u32 w20;
    int pad24[3];
    int w30;
} St_021B9C64;

typedef struct {u16 a,b,c;u8 d,e;} R_021BA954;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R_021BAA50;

typedef signed int     s32;

typedef struct { short x,y; } Pt;

typedef struct { Pt point; short width,height; } Rect;

typedef signed char s8;

typedef struct {
    int obj;
    u16 pad4;
    u16 lo;
    u16 hi;
} S_021BB30C;

typedef signed short s16_021BB2E0;

typedef struct S_021BB358 {
    u8 pad[6];
    u16 a;
    u16 b;
} S_021BB358;

typedef struct { short x,y; } Pair_021B8DB4;

typedef short s16_021BB7E8;

typedef struct Req {
    u32 heap;
    u8 v;
    u8 *p;
    u32 one;
    u8 c[4];
} Req;

typedef struct Tbl {
    u32 a;
    u32 b;
    u32 c;
} Tbl;

typedef struct {
    int a;
    short b;
    int flag;
} St_021BB2E0;

typedef signed short s16_021BC628;

typedef short s16_021BCEAC;

typedef struct {u16 a,b,c;u8 d,e;} R;

typedef signed short s16_021BD634;

typedef short s16_021BDABC;

typedef struct { s16_021BDABC x,y; } Pair_021BD218;

extern int func_02035C08(const void *p);
extern void func_020061E4(u32 id);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B84C(int h, int f);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_02041B6C(u32 bit);
extern void func_020355D8(int a);
extern void func_0207D63C(u16 *r, int a, int b, int c, int d);
extern void func_02041570(int channel, u16 val);
extern u8 func_020355C4(void);
extern void func_020409B4(u32 index);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern void func_02017E40(void *,u32,u32);
extern u32 func_020307B0(void *p);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern void func_021B8180(u8 *);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021B7B98(u8 *);
extern void func_021B8418(u8 *);
extern int func_0215EA14(int a0, int a1);
extern u32 func_02013E04(u32 id);
extern unsigned func_020362DC(void);
extern int func_02035C60(void);
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);
extern u32 func_0202130C(u32 id);
extern u32 func_020188AC(void *p, int v);
extern u32 func_0201B2B0(void *,void *,u32,u32,u8,u32 *,u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, short b, short c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C7D0(void *x, s16_021B9C64 y, s16_021B9C64 z, void *s, void *w, u16 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int   func_02009020(void *obj, int v);
extern void *func_02008F08(int a0);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern int func_0201A59C(void *a0, void *a1, void *a2);
extern u32 func_0201808C(void *,u32);
extern u32 func_02018238(void *,u16);
extern void func_020181F4(void *,u16,u32);
extern void func_020182A0(void *,u16,u32);
extern void func_0201B7A0(void *, int, int, int);
extern u32 func_02007FB8(u8 *, u16, u16);
extern u32 func_02007F1C(u8 *, u16, u16, u16);
extern u32 func_02007E50(u8 *, u16, u16, u16);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_0204B09C(void *,int,void *);
extern u32 func_020450F0(int,u8,u8,int,u8,u8,u8);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B084(void *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A8D4(u32);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_02017F90(void *p);
extern u32 func_0204B8F4(struct Obj *p);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_020185F4(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *a);
extern int func_0201BBE8(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02018430(void *p);
extern u8 func_0202D01C(u32 a, u32 b, u32 c);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02045780(struct Descriptor *p, u8 v);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_02019DA4(void *a, void *b);
extern u8 func_0202D034(u32 a, u32 b);
extern void func_0204B0C8(struct Owner *owner, u32 index, struct Pt *out);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct Tcbl *sub_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(int a, int b, int c, u16 d);
extern u32 func_0201C440(void *p);
extern void func_0202F038(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_0202865C(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02028470(u8 *p, u32 v);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16_021BB7E8 a1, s16_021BB7E8 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int a, int b);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern int func_02006238(void);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF4C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F140(struct WordSet *p, u32 i, u32 v);
extern void func_02028618(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern u32 func_020275E4(void);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027858(struct TaskMenu *m);
void func_02027974(int);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void func_02028148(u8 *p);
extern void func_02028178(u8 *p);
extern void func_02028218(struct Obj *obj, u32 a);
void func_0202822C(char *p, int v);
extern void *func_02020F34(u32 item, u32 which, u32 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern unsigned int func_02020FE4(void *,unsigned int,unsigned int);
extern u32 func_0201AA18(void *);
extern unsigned int func_02019CF8(unsigned int item);
extern u32 func_02017988(void *,u32);
extern u32 func_02019D00(u32 id);
extern void func_02027268(int);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_020456F8(struct Descriptor *d);
extern u16 func_02018328(void *p, u32 *idx, u32 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02027694(void);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082A60(void *, void *, unsigned long);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern int func_02061CA4(void *,u32,u32,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021B7034(char *);
extern void func_021B6F28(char *);
extern void func_021B7040(unsigned p);
extern void func_021B6F0C(void *p);
extern int func_02051614(int **p);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern u32 func_02006BD0(u32 i);
extern int func_02051574(void);
extern void func_02047964(void);
extern void func_020479D8(void);
extern int func_02051534(void);
extern void func_02047970(void);
extern int func_0205121C(u32,u32,u32);
extern void *func_0203D7C8(u32,u32,const char *,u16);
extern int func_02050C04(int,int,int,int);
extern u32 func_020056BC(void);
extern void func_02051230(u8 *,u32,u32,u32);
extern int func_020515B4(void *p, int b, int c);
extern void func_02050DB8(u8 *);
extern void func_0203D7FC(void *);
extern void func_0200CDE0(struct Blk37 *, void *);
extern u8 func_02011400(int row, int col);
extern void func_0203F4CC(struct RtcTime *time);
extern u8 func_0201C158(u16, u32);
extern u8 func_0201B920(void *, u32);
extern u32 func_02018584(u16, u16, u16);
extern void func_020185C4(void *);
extern u32 func_0201B970(void *, u32, u32);
extern int func_021BEA48(int, int, int, int, u16, int);
void func_021B8DB4(u8 *p);
void func_021B8F68(u8 *p, int idx);
void func_021B8FC4(u8 *p, int idx);
void func_021B9020(u8 *p);
void func_021B907C(u8 *p);
void func_021B90F8(u8 *p);
void func_021B916C(u8 *p);
void func_021B9750(unsigned p);
void func_021B9788(u8 *p, int a1, int a2, int a3);
void func_021B97D4(u8 *p);
void func_021B9804(u8 *p, int a1);
void func_021B981C(u8 *p);
void func_021B9968(unsigned char *p);
void func_021B999C(u8 *p);
int func_021B99E4(void *p, int i);
int func_021B9A84(u32 p);
int func_021B9AA0(u32 p);
int func_021B9AB4(u8 *p);
int func_021B9AC8(u8 *p, void *mon, u8 bit);
u32 func_021B9BF4(u8 *p, void *mon, u32 param);
void func_021B9C1C(u8 *p, u32 win, u32 id, int x, s16 y, u16 color);
void func_021B9C64(u8 *p, u32 win, u32 idx, u32 x, s16_021B9C64 y, u16 color);
void func_021B9CB0(u8 *p, u32 win, u32 idx, u32 x, s16_021B9C64 y, u16 color);
void func_021B9CF4(u8 *p, u32 win, void *set, u32 idx, s16_021B9C64 x, s16_021B9C64 y, u16 color);
void func_021B9D58(u8 *p, u32 win, void *set, u32 idx, s16_021B9C64 x, s16_021B9C64 y, u16 color);
void func_021B9DC0(u8 *p, u32 win, void *set, u32 idx, s16_021B9C64 x, s16_021B9C64 y, u16 color);
void func_021B9E20(u8 *p);
void func_021B9E3C(u8 *p);
void func_021B9E44(u8 *p);
void func_021B9EB0(u8 *p);
void func_021B9EC0(u8 *p, u32 state);
void func_021B9F34(u8 *p);
void func_021B9F44(u8 *p, u32 state);
void func_021BA004(u8 *p);
void func_021BA098(u8 *p);
void func_021BA0A8(u8 *p,int action);
void func_021BA288(u8 *p);
void func_021BA318(u8 *p);
void func_021BA394(u8 *p);
void func_021BA3A4(u8 *p, u32 state);
void func_021BA444(u8 *p);
void func_021BA454(u8 *a, int k);
void func_021BA4E4(u8 *p);
void func_021BA4F8(u8 *a);
u32 func_021BA5B4(u8 *p, void *q);
void func_021BA5E0(u8 *p, void *q, u32 slot);
void func_021BA60C(u8 *p, void *q);
void func_021BA624(u8 *p, void *q, u16 id);
u32 func_021BA65C(u8 *p, u16 id);
u32 func_021BA670(u8 *p, u16 id);
u32 func_021BA688(u8 *p, u16 id);
u8 *func_021BA6A0(u8 *p, int k, void *mon);
S44 *func_021BA81C(u8 *a, int k);
void func_021BA890(void *ignored,u8 *p);
void func_021BA8CC(u32 a, St_021B9C64 *s);
void func_021BA954(u8 *p,u8 *s);
void func_021BAA50(u8 *a, u8 *s);
void func_021BAAE4(u8 *a,u8 *s,int k);
void func_021BAB04(u8 *a, u8 *s, int k);
void func_021BAE94(u8 *a, u8 *s);
void func_021BAF28(u8 *a, u8 *s);
void func_021BAFA0(u8 *a, u8 *s, int k);
void func_021BB050(int unused, u8 *s, int k);
void func_021BB0C4(u8 *p,const u8 *s,int d);
void func_021BB1A0(int unused, u8 *s, int d);
void func_021BB200(u8 *a, u8 *s, int p, int q);
void func_021BB2C0(u8 *a,u8 *s);
void func_021BB2E0(u8 *a,u8 *s);
void func_021BB30C(u8 *a, S_021BB30C *s);
int func_021BB358(u8 *p, S_021BB358 *s);
int func_021BB3C4(void *unused, u32 p);
void func_021BB3D4(void *a,u8 *s,u16 *out);
void func_021BB3FC(int unused, u8 *s, u8 *out);
int func_021BB43C(int *p);
void func_021BB440(u8 *p, u32 *q, int v);
unsigned short func_021BB464(int unused, unsigned short *p);
int func_021BB468(int unused, int *p);
void func_021BB46C(u8 *p, u32 *q);
int func_021BB4A0(u8 *p, int *s);
u8 func_021BB554(u32 p);
void func_021BB56C(u32 p,int x,int y,u16 *out);
u32 *func_021BB594(u16 *h);
void func_021BB5FC(void *a, int *s);
void func_021BB644(u8 *p,u8 *s);
void func_021BB714(void *a, u32 *s, u32 k);
void func_021BB7A4(void *p,u32 *s);
int func_021BB7D8(void *unused, u32 p);
void func_021BB7E8(u8 *a, u32 *s, u32 x);
void func_021BB860(u8 *a, u32 *s, u32 x, u32 y);
int func_021BB8FC(void *unused, u32 p);
int func_021BB910(int k);
void func_021BB97C(u16 *p,u32 s);
void func_021BB98C(void *p,u32 s);
void func_021BB99C(int a,int b,int c,int d);
void func_021BB9AC(int a,int b,int c,int d);
void func_021BB9BC(int a, u32 b, u32 c, int d);
void func_021BB9CC(int a,int b,int c,int d);
void func_021BB9DC(int a,int b,int c,int d);
void func_021BB9EC(int a,int b,int c,int d,unsigned char e);
void func_021BBA0C(int a,int b,int c,const void *d,int e);
void func_021BBA28(int a,int b);
void func_021BBA54(unsigned short *a, u32 b);
void func_021BBA68(u8 *p, u8 *s);
void func_021BBA70(int a,int b);
u32 *func_021BBA8C(u16 *h);
void func_021BBAE0(int a,unsigned char *b);
void func_021BBAF8(u8 *a, u8 *b, int *items);
void func_021BBB40(u8 *a, u8 *b);
void func_021BBBA0(unsigned char *a,unsigned char *b);
void func_021BBBD8(int unused, int *p);
unsigned int func_021BBBE4(int a,unsigned char *b);
void func_021BBC04(u8 *p, u8 *s, int *items);
int func_021BBD98(int a, int unused, int idx);
int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5);
void func_021BBE44(int x);
void func_021BBE50(int x);
void func_021BBE5C(int x, int f);
void func_021BBE68(int p, int v);
int func_021BBE74(int id);
int func_021BC17C(unsigned short *p,int id);
int func_021BC1B4(unsigned short *p,void *id);
int func_021BC1D0(P *p);
int func_021BC228(int unused,int id);
void func_021BC24C(void *unused,void *a,int b);
void func_021BC288(int unused, int a, int b);
void func_021BC2C8(int p);
void func_021BC30C(int p);
int func_021BC350(u8 *p,int v);
void func_021BC548(int p);
void func_021BC5CC(int p);
void func_021BC628(int p);
void func_021BC6A0(char *p);
void func_021BC6C0(char *p);
void func_021BC6CC(u8 *p);
int func_021BCC2C(void *p, int i, int a2);
void func_021BCC40(int p, int id);
void func_021BCC80(int p, int id, int v);
void func_021BCCCC(int p);
void func_021BCD80(char *a);
void func_021BCDE8(char *a);
void func_021BCE84(char *p);
void func_021BCE9C(unsigned int p);
void func_021BCEAC(u8 *p);
void func_021BD058(char *a);
u32 *func_021BD05C(u8 *p, u32 *list, u8 x, u8 y, u8 w);
void func_021BD18C(char *a,char *p);
void func_021BD1BC(char *a, int *b);
u32 *func_021BD218(u8 *p,void *mon,s16 x,u16 y);
void func_021BD454(char *unused,char *p);
void func_021BD480(char *a, int *b);
void func_021BD4EC(char *p);
void func_021BD504(char *a);
void func_021BD59C(char *p);
void func_021BD61C(char *p);
void func_021BD634(u8 *p);
void func_021BD8B0(char *p);
void func_021BD8E4(u8 *p);
void func_021BD9C8(u8 *p);
void func_021BDABC(u8 *p);
void func_021BDBE0(unsigned int p);
int func_021BDBF8(char *p, void *q);
void func_021BDC3C(u32 p, void *m);
int func_021BDC5C(char *p, void *q);
void func_021BDCA0(u32 p, void *m);
int func_021BDCC0(char *p, u32 a1);
void func_021BDD58(u32 p, void *m);
int func_021BDD78(void *a, u32 id, int slot, u32 heap);
int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
int func_021BE874(void *a, int b, int c);
void func_021BE914(void *p, u32 v, u32 limit, u32 step);
int func_021BE948(int a0, int a1, int a2, int a3);
int func_021BE9BC(void *a, void *b);
extern Rect4 d_021BEC2C;
extern const Four d_021BEC0C,d_021BEC1C;
extern const char d_021BED18[];
extern const u8 d_021BEC74[];
extern const u8 d_021BEC75[];
extern const u8 d_021BEC6C[];
extern const u8 d_021BEC6D[];
extern void *g_020A7370;
extern u8 d_021BED28[];
extern u8 d_021BED38[];
extern Tbl d_021BEC80;
extern int d_021BEC8C[];
extern u16 d_021BECE4[];
extern const char d_021BED48[];
extern s16_021BD634 d_020A1B38[];
extern u8 d_021BED58[];

#define T(k) (*(u32 *)(S+(k)))

#define P(k) (*(int *)(p+(k)))



#define H(k) (*(u16 *)(S+(k)))





#define S (*(u8 **)(p+0x280))







#define W(o) (*(int *)(p + (o)))







void func_021B8DB4(u8 *p)
{
    Rect_021B8DB4 list[7];
    Rect4 fixed;
    u8 map[6];
    u8 i;
    u8 n;
    int hit;
    int old;
    int r;

    n = 0;
    for (i = 0; i < 6; i++) {
        if (func_021BB3C4(p, *(int *)(p + i * 4 + 0x160)) == 1) {
            map[n] = i;
            func_021BB3FC((int)p, (u8 *)(*(int *)(p + i * 4 + 0x160)), (u8 *)(&list[n]));
            n++;
        }
    }
    list[n].top = 0xff;
    hit = func_02035C08(list);
    if (hit != -1) {
        if (W(0x28) == 0 && hit <= 5 && func_021BB468((int)p, (int *)(*(int *)(p + hit * 4 + 0x160))) == 1) {
            func_020061E4(0x557);
        } else {
            p[0xf] = 3;
            old = W(0x2c);
            W(0x2c) = map[hit];
            if (old <= 5) {
                func_021BAFA0(p, (u8 *)(*(int *)(p + old * 4 + 0x160)), 0);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(old - 6) * 4 + 0x108), 0);
            }
            if (W(0x2c) <= 5) {
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                func_0204B3DC((struct Obj *)W(0x1d8), 0);
            }
            p[0x100] = 0xc;
        }
        W(8) = 1;
    }
    if (hit == -1) {
        fixed = d_021BEC2C;
        if (func_021B9A84((u32)p) == 1) {
            if (func_021B9AA0((u32)p) == 1) {
                fixed.r[1].top = 0xa8;
                fixed.r[1].bottom = 0xc0;
                fixed.r[1].left = 0xb0;
                fixed.r[1].right = 0xff;
                fixed.r[0].top = 0xa8;
                fixed.r[0].bottom = 0xc0;
                fixed.r[0].left = 0x60;
                fixed.r[0].right = 0xb0;
            } else {
                fixed.r[0].top = 0xa8;
                fixed.r[0].bottom = 0xc0;
                fixed.r[0].left = 0xb0;
                fixed.r[0].right = 0xff;
            }
        } else {
            if (func_021B9AB4(p) == 1) {
                fixed.r[1].top = 0xa8;
                fixed.r[1].bottom = 0xc0;
                fixed.r[1].left = 0xe0;
                fixed.r[1].right = 0xf8;
            }
            if (W(0x14) == 1) {
                fixed.r[2].top = 0xa8;
                fixed.r[2].bottom = 0xc0;
                fixed.r[2].left = 0xc8;
                fixed.r[2].right = 0xe0;
            }
        }
        r = func_02035C08(&fixed);
        if (r != -1) {
            p[0xf] = r;
            W(8) = 1;
        }
    }
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







void func_021B8F68(u8 *p, int idx)
{
    int buf;

    func_021BB3D4(p, (u8 *)(*(int *)(p + idx * 4 + 0x160)), (u16 *)(&buf));
    func_0204B404((struct Obj *)W(0x1d8), (const struct Vec2 *)(&buf), 0);
    func_0204B3DC((struct Obj *)W(0x1d8), 1);
    func_0204B84C(W(0x1d8), 3);
    if (idx == 0) {
        func_0204B878((struct Obj *)W(0x1d8), 0);
    } else {
        func_0204B878((struct Obj *)W(0x1d8), 1);
    }
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







void func_021B8FC4(u8 *p, int idx)
{
    int buf;

    func_021BB3D4(p, (u8 *)(*(int *)(p + idx * 4 + 0x160)), (u16 *)(&buf));
    func_0204B404((struct Obj *)W(0x1dc), (const struct Vec2 *)(&buf), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 1);
    func_0204B84C(W(0x1dc), 2);
    if (idx == 0) {
        func_0204B878((struct Obj *)W(0x1dc), 2);
    } else {
        func_0204B878((struct Obj *)W(0x1dc), 3);
    }
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







void func_021B9020(u8 *p)
{
    int r;

    switch (p[0xe]) {
    case 0:
        func_021B907C(p);
        p[0xe] = 1;
        break;
    case 1:
        func_021BBBD8((int)p, (int *)W(0x154));
        r = func_021BBBE4((int)p, (unsigned char *)((int *)W(0x154)));
        if (r != 0x17) {
            W(0x3c) = r;
            p[0xe] = 2;
        }
        if (*(u8 *)(W(0x280) + 0x63) == 1) {
            p[0xe] = 2;
        }
        break;
    case 2:
        func_021B90F8(p);
        func_021B916C(p);
        break;
    }
}







static inline void G2_SetBlendBrightness(int plane, int brightness)
{
    func_0207D658((u32)&reg_G2_BLDCNT, plane, brightness);
}







static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    reg_G2_WIN0H = (u16)(((x1 << 8) & 0xff00) | ((x2 << 0) & 0x00ff));
    reg_G2_WIN0V = (u16)(((y1 << 8) & 0xff00) | ((y2 << 0) & 0x00ff));
}







static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WININ = (u16)tmp;
}







static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WINOUT = (u16)tmp;
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







/*
 * volatile: WININ 0x04000048 and WINOUT 0x0400004A read-modify-written by the SDK inlines G2_SetWnd0InsidePlane/G2_SetWndOutsidePlane; WIN0H/WIN0V/BLDCNT hardware registers
 */
void func_021B907C(u8 *p)
{
    p[0xc] = 6;
    p[0xe] = 0;
    G2_SetBlendBrightness(0x1e, 8);
    G2_SetWnd0Position(0xe0, 0xa8, 0xf8, 0xc0);
    G2_SetWnd0InsidePlane(0x1f, 0);
    G2_SetWndOutsidePlane(0x1f, 1);
    W(0x10) = 1;
    func_0204B3DC((struct Obj *)W(0x1e4), 0);
    func_0204B3DC((struct Obj *)W(0x1e0), 0);
    func_02041B6C(0);
    func_020355D8(W(8));
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







void func_021B90F8(u8 *p)
{
    func_021BBBA0((unsigned char *)((int)p), (unsigned char *)((int *)W(0x154)));
    func_021BB7A4(p, (u32 *)W(0x150));
    if (func_021B9A84((u32)p) == 1 || func_021B9AB4(p) == 0) {
        func_0204B3DC((struct Obj *)W(0x1e0), 0);
    } else {
        func_0204B3DC((struct Obj *)W(0x1e0), 1);
    }
    if (W(0x3c) != 4 && W(0x3c) != 5) {
        func_0207D63C((u16 *)0x04000050, 0x14, 8, 0x10, 0xa);
        W(0x10) = 0;
    }
    func_02041570(0, 0);
    W(8) = func_020355C4();
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(k) (*(u32 *)(p+(k)))






void func_021B916C(u8 *p)
{
    struct { u32 n; Four b; Four a; } L;
    u32 old;
    int r,level;
    u32 flag;
    u8 i;
    u8 *q;
    if (S[0x63] == 1) { p[0xc]=19; return; }
    switch (W(0x3c)) {
    case 6:
        func_021B8F68(p,W(0x2c)); W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    case 3:
        func_021B8F68(p,W(0x2c)); func_021B8FC4(p,W(0x2c));
        W(0x30)=W(0x2c); p[0xc]=3; W(0x38)=0; W(0x14)=0;
        func_021BB714(p,(u32 *)W(0x150),0); func_021BB7E8(p,(u32 *)W(0x150),11);
        func_021B8418(p); return;
    case 4:
        L.a=d_021BEC0C;
        func_021B907C(p); func_021BB714(p,(u32 *)W(0x150),2);
        func_021BB7E8(p,(u32 *)W(0x150),19);
        func_021BBAF8(p,(u8 *)W(0x154),L.a.v); func_020409B4(0); return;
    case 5:
        L.b=d_021BEC1C;
        func_021B907C(p); func_021BB714(p,(u32 *)W(0x150),2);
        func_021BB7E8(p,(u32 *)W(0x150),19);
        func_021BBAF8(p,(u8 *)W(0x154),L.b.v); func_020409B4(0); return;
    case 0:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=1; return;
    case 20:
        q=(u8 *)T(0x14); flag=0;
        r=func_021BB4A0(p,A);
        if (r == 0) {
            func_021BB440(p,(u32 *)A,p[0x105]); p[0x105]=p[0x105]+1;
            func_021B7B98(p);
            if (p[0x105] == q[3]) flag=1;
            p[0xc]=2;
        } else if (r == 2) {
            func_021B9788(p,0x90,1,(int)func_021B9E20); func_020061E4(0x557);
        } else if (r == 3) {
            func_021B9788(p,0x91,1,(int)func_021B9E20); func_020061E4(0x557);
        } else if (r == 4) {
            func_021B9788(p,q[3]+0x5c,1,(int)func_021B9E20); func_020061E4(0x557);
        }
        W(0x38)=0;
        if (flag==1) {
            func_021BAFA0(p,(u8 *)((u32)A),0); W(0x2c)=6;
            if (W(8)==0) {
                func_021BBE5C(*(int *)((p+(u8)(W(0x2c)-6)*4)+0x108),1);
                func_0204B3DC((struct Obj *)W(0x1d8),0); return;
            }
        } else if (W(8)==0) func_021B8F68(p,W(0x2c));
        return;
    case 21:
        level=func_021BB43C(A);
        for (i=0; i<6; i++) {
            r=func_021BB43C(*(int **)((p+i*4)+0x160));
            if (r <= 5 && r > level) func_021BB440(p,(u32 *)(*(int **)((p+i*4)+0x160)),r-1);
        }
        func_021BB440(p,(u32 *)A,6); p[0x105]=p[0x105]-1;
        if (W(8)==0) func_021B8F68(p,W(0x2c));
        W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    case 10:
        old=func_02017E1C((void *)W(0x38),6,0);
        func_021BC24C(p,(void *)W(0x38),0); func_021BC288((int)p,(int)((void *)W(0x38)),0);
        if (old==0) {
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021B9788(p,0x3d,1,(int)func_021B9E20); func_021BB98C(p,W(0x150)); return;
        }
        if (func_021BA65C(p,old)==999) {
            func_021B9788(p,0x3f,1,(int)func_021B9E20); return;
        }
        func_021BA624(p,(void *)W(0x38),0); func_021BB2C0(p,(u8 *)((u32)A));
        func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)old);
        if (func_021BDC5C((char *)p,(void *)W(0x38))==1) {
            func_021BDCA0((u32)p,(void *)W(0x38)); func_021B9788(p,0x3e,1,(int)func_021BA4E4); W(0x264)=2;
        } else func_021B9788(p,0x3e,1,(int)func_021B9E20);
        func_021BB98C(p,W(0x150)); return;
    case 11:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    case 9:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=3; return;
    case 12:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=7; return;
    case 13:
        func_021B9788(p,0x17,0,(int)func_021BA394); return;
    case 7:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    case 16: case 17: case 18: case 19:
        if (T(0x34)==5) {
            if (func_021BDD78((void *)W(0x38),H(0x44),(u16)(W(0x3c)-16),*(u16 *)p)==1) {
                old=func_02017E1C((void *)W(0x38),W(0x3c)+0x26,0);
                func_020409B4(0); func_021BC350(p,old);
                func_021BE2B4((void *)W(0x38),H(0x44),(u16)(W(0x3c)-16),H(0x30),*(u16 *)p);
                func_021BB2C0(p,(u8 *)((u32)A)); func_021BA670(p,H(0x44)); func_020061E4(0x56f);
            } else func_021BC30C((int)p);
            return;
        }
        r=func_021B99E4((void *)W(0x38),(u8)(W(0x3c)-16));
        if ((u32)(r-22)<=1) {
            if (func_02013E04(H(0x30))==0) {
                func_021B9788(p,0x50,1,(int)func_021B9E20); return;
            }
            L.n=func_02017E1C((void *)W(0x38),0xa1,0);
            old=func_02017E1C((void *)W(0x38),0xa0,0);
            if (old > L.n/5) {
                func_021B8F68(p,W(0x2c)); func_021B8FC4(p,W(0x2c)); W(0x34)=W(0x2c);
                p[0xc]=4; W(0x38)=0; W(0x14)=0;
                func_021BB714(p,(u32 *)W(0x150),0); func_021BB7E8(p,(u32 *)W(0x150),17);
                func_021B8418(p);
            } else func_021B9788(p,0x6b,1,(int)func_021B9E20);
            return;
        }
        switch (func_0215EA14(r-11,(int)(S+0x1c))) {
        case 0: p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=r; return;
        case 1: func_021B9788(p,0x50,1,(int)func_021B9E20); return;
        case 2: func_021B9788(p,0x38,1,(int)func_021B9E20); return;
        case 3: func_021B9788(p,0x9f,1,(int)func_021B9E20); return;
        case 4: func_021B9788(p,0x4f,1,(int)func_021B9E20); return;
        }
        return;
    default:
        func_021B8F68(p,W(0x2c)); W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    }
}






void func_021B9750(unsigned p) { if(func_021BB8FC((void *)p,((struct Obj09925 *)p)->f150)==1) { if(func_020362DC()&1) ((struct Obj09925 *)p)->f8=0; if(func_02035C60()==1) ((struct Obj09925 *)p)->f8=1; (*(void (**)(unsigned))(p+328))(p); } }






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







void func_021B9788(u8 *p, int a1, int a2, int a3)
{
    p[0xc] = 7;
    W(0x144) = a2;
    W(0x148) = a3;
    func_021BB714(p, (u32 *)W(0x150), 3);
    func_021BB860(p, (u32 *)W(0x150), a1, a2);
    func_0204B3DC((struct Obj *)W(0x1e0), 0);
    func_0204B3DC((struct Obj *)W(0x1e4), 0);
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







void func_021B97D4(u8 *p)
{
    int r;

    func_021BBBD8((int)p, (int *)W(0x154));
    r = func_021BBBE4((int)p, (unsigned char *)((int *)W(0x154)));
    if (r != 0x17) {
        ((void (*)(u8 *, int))W(0x14c))(p, r);
        func_021BBBA0((unsigned char *)((int)p), (unsigned char *)((int *)W(0x154)));
    }
}







/*
 * func_021B9804 is an unlabelled tail-call stub inside the extent.
 */
void func_021B9804(u8 *p, int a1)
{
    p[0xc] = 9;
    W(0x14c) = a1;
    func_021BBB40(p, (u8 *)W(0x154));
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(o) (*(int *)(p + (o)))






void func_021B981C(u8 *p)
{
    switch (p[0xe]) {
    case 3:
        func_021BB1A0((int)p, ROW(W(0x2c)), p[0x104]);
        func_021BB1A0((int)p, ROW(W(0x30)), p[0x104]);
        p[0x104]++;
        func_021BB0C4(p, ROW(W(0x2c)), p[0x104]);
        func_021BB0C4(p, ROW(W(0x30)), p[0x104]);
        if (p[0x104] >= 16) {
            func_0201AB8C((struct Party *)(*(int *)W(0x280)), W(0x2c), W(0x30), ((struct Obj01229 *)p)->f0);
            func_021BB200(p, ROW(W(0x2c)), (int)func_0201AB28(*(void **)W(0x280), W(0x2c)), p[0x104]);
            func_021BB200(p, ROW(W(0x30)), (int)func_0201AB28(*(void **)W(0x280), W(0x30)), p[0x104]);
            p[0xe] = 4;
            func_020061E4(0x642);
        }
        break;
    case 4:
        func_021BB1A0((int)p, ROW(W(0x2c)), p[0x104]);
        func_021BB1A0((int)p, ROW(W(0x30)), p[0x104]);
        p[0x104]--;
        func_021BB0C4(p, ROW(W(0x2c)), p[0x104]);
        func_021BB0C4(p, ROW(W(0x30)), p[0x104]);
        if (p[0x104] == 0)
            func_021B999C(p);
        break;
    }
}






void func_021B9968(unsigned char *p) { p[12]=5; p[14]=3; p[260]=0; func_020061E4(0x641); func_0204B3DC((struct Obj *)((struct Obj00009 *)p)->f1D8,0); func_0204B3DC((struct Obj *)((struct Obj00009 *)p)->f1DC,0); }






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







void func_021B999C(u8 *p)
{
    W(0x38) = 0;
    p[0xc] = 2;
    func_021B8F68(p, W(0x2c));
    func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x30) * 4 + 0x160)), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 0);
    W(0x30) = 9;
    *(int *)(W(0x280) + 0x3c) = W(0x2c);
    func_021B7B98(p);
}







int func_021B99E4(void *p, int i)
{
    switch (func_02017E1C(p, i + 0x36, 0)) {
    case 0xf:
        return 0xb;
    case 0x13:
        return 0xf;
    case 0x39:
        return 0xc;
    case 0x46:
        return 0xe;
    case 0x7f:
        return 0xd;
    case 0x94:
        return 0x10;
    case 0x64:
        return 0x11;
    case 0x5b:
        return 0x12;
    case 0xe6:
        return 0x13;
    case 0x1c0:
        return 0x14;
    case 0x123:
        return 0x15;
    case 0xd0:
        return 0x16;
    case 0x87:
        return 0x17;
    }
    return 0;
}






int func_021B9A84(u32 p) {
    u32 v = *(u32 *)(((struct Obj20860 *)p)->f280 + 52);
    if (v == 1 || v == 22 || v == 23) return 1;
    return 0;
}






int func_021B9AA0(u32 p) {
    if (*(u32 *)(((struct Obj20861 *)p)->f280 + 52) != 1) return 1;
    return 0;
}






int func_021B9AB4(u8 *p) { return ((struct Obj20862 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34 != 21; }






int func_021B9AC8(u8 *p, void *mon, u8 bit)
{
    int empty = 0;
    u8 i;
    u32 a, b, c;
    u32 v;
    if (*(int *)(p + 0x18) == 1) {
        a = *(u16 *)(*(u8 **)(p + 0x280) + 0x46);
        if (a == 0xfffe) {
            a = 0x152;
            b = a - 0x1f;
            c = a - 0x1e;
        } else if (a == 0xfffd) {
            a = 0x280;
            a = a - 0x78;
            b = 0x280;
            b = b - 0x79;
            c = 0x280 - 0x7a;
        } else {
            b = a;
            c = a;
        }
        for (i = 0; i < 4; i++) {
            v = func_02017E1C(mon, i + 0x36, 0);
            if (v == a || v == b || v == c) return 3;
            if (v == 0) empty = 1;
        }
        if ((*(u8 *)(*(u8 **)(p + 0x280) + 0x5e) & (1 << bit)) != 0) {
            if (empty == 1) return 0;
            return 1;
        } else return 2;
    } else {
        for (i = 0; i < 4; i++) {
            v = func_02017E1C(mon, i + 0x36, 0);
            if (v == *(u16 *)(*(u8 **)(p + 0x280) + 0x46)) return 3;
            if (v == 0) empty = 1;
        }
        if (*(u16 *)(*(u8 **)(p + 0x280) + 0x44) != 0) {
            u32 id = func_0202130C(*(u16 *)(*(u8 **)(p + 0x280) + 0x44));
            if (id != 0xff && func_020188AC(mon, id) == 1) {
                int result = 0;
                if (empty != 1) result = 1;
                return result;
            } else return 2;
        } else {
            int result = 0;
            if (empty != 1) result = 1;
            return result;
        }
    }
}






u32 func_021B9BF4(u8 *p, void *mon, u32 param) { u8 *s=*(u8 * *)&((struct Obj00009 *)p)->f280; return func_0201B2B0(((struct Obj13241 *)s)->f0,mon,3,param,s[0x5f],0,((struct Obj00009 *)p)->f0); }






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))







void func_021B9C1C(u8 *p, u32 win, u32 id, int x, s16 y, u16 color)
{
    void *text;

    text = func_02045EC0((void *)W(0x134), id);
    func_0201C724((void *)W(0x140), (u32)func_02045770((struct Descriptor *)win), (s16)x, (s16)y, (u32)text, W(0x138), color);
    func_02045808(text);
}





#undef S




#undef S



#undef S


#undef S

#undef S



#define S (*(u8 **)(p+0x280))









void func_021B9C64(u8 *p, u32 win, u32 idx, u32 x, s16_021B9C64 y, u16 color)
{
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj09926 *)p)->f134), idx);
    func_0201C724((void *)(((struct Obj09926 *)p)->f140), (u32)func_02045770((struct Descriptor *)win), (s16_021B9C64)x, (s16_021B9C64)y, (u32)text,
                  ((struct Obj09926 *)p)->f13C, color);
    func_02045808(text);
}









void func_021B9CB0(u8 *p, u32 win, u32 idx, u32 x, s16_021B9C64 y, u16 color)
{
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj13242 *)p)->f134), idx);
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)win)), x, y, text, (void *)(((struct Obj13242 *)p)->f13C), color);
    func_02045808(text);
}









void func_021B9CF4(u8 *p, u32 win, void *set, u32 idx, s16_021B9C64 x, s16_021B9C64 y, u16 color)
{
    void *buf = func_020457B0(16, ((struct Obj06211 *)p)->f0);
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj06211 *)p)->f134), idx);
    func_0201F250(set, buf, text);
    func_0201C724((void *)(((struct Obj06211 *)p)->f140), (u32)func_02045770((struct Descriptor *)win), x, y, (u32)buf,
                  ((struct Obj06211 *)p)->f138, color);
    func_02045808(text);
    func_02045808(buf);
}









void func_021B9D58(u8 *p, u32 win, void *set, u32 idx, s16_021B9C64 x, s16_021B9C64 y, u16 color)
{
    void *buf = func_020457B0(16, ((struct Obj02771 *)p)->f0);
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj02771 *)p)->f134), idx);
    func_0201F250(set, buf, text);
    func_0201C724((void *)(((struct Obj02771 *)p)->f140), (u32)func_02045770((struct Descriptor *)win), x, y, (u32)buf,
                  ((struct Obj02771 *)p)->f13C, color);
    func_02045808(text);
    func_02045808(buf);
}









void func_021B9DC0(u8 *p, u32 win, void *set, u32 idx, s16_021B9C64 x, s16_021B9C64 y, u16 color)
{
    void *buf = func_020457B0(16, ((struct Obj09927 *)p)->f0);
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj09927 *)p)->f134), idx);
    func_0201F250(set, buf, text);
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)win)), x, y, buf, (void *)(((struct Obj09927 *)p)->f13C), color);
    func_02045808(text);
    func_02045808(buf);
}








void func_021B9E20(u8 *p) { func_021BB7A4(p,(u32 *)(*(u32 *)&((struct Obj00009 *)p)->f150)); p[12]=2; func_021B7B98(p); }








void func_021B9E3C(u8 *p) { p[12]=19; }





#undef W




#undef W



#undef W


#undef W

#undef W




#define W(o) (*(u32 *)(p + (o)))









void func_021B9E44(u8 *p)
{
    if (func_021BA65C(p, *(u16 *)(W(0x280) + 0x44))) {
        func_021BB7A4(p, (u32 *)W(0x150));
        p[0xc] = 2;
        func_021B7B98(p);
        return;
    }
    func_021BB7A4(p, (u32 *)W(0x150));
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB9AC((int)p, W(0x150), 0, *(u16 *)(W(0x280) + 0x44));
    func_021B9788(p, 0xb3, 1, (int)func_021B9E3C);
    func_021BB98C(p, W(0x150));
}









void func_021B9EB0(u8 *p)
{
    func_021B9804(p, (int)func_021B9EC0);
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))









void func_021B9EC0(u8 *p, u32 state)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    if (state == 14) {
        u32 *q = (u32 *)W(0x280);
        if (q[0x34 / 4] == 5 || q[0x34 / 4] == 8) {
            q[0x40 / 4] = 5;
        } else {
            q[0x40 / 4] = 4;
        }
        func_021B9788(p, 0x27, 1, (int)func_021B9E3C);
        return;
    }
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    func_021B9788(p, 0x23, 0, (int)func_021B9F34);
    func_021BB98C(p, W(0x150));
}









void func_021B9F34(u8 *p)
{
    func_021B9804(p, (int)func_021B9F44);
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))









void func_021B9F44(u8 *p, u32 state)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    if (state == 14) {
        *(u32 *)(W(0x280) + 0x40) = 10;
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
        if (*(u32 *)(W(0x280) + 0x34) == 5 || *(u32 *)(W(0x280) + 0x34) == 8) {
            func_021B9788(p, 0x26, 1, (int)func_021BC6C0);
        } else {
            func_021B9788(p, 0x26, 1, (int)func_021B9E3C);
        }
        func_021BB98C(p, W(0x150));
        return;
    }
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB99C((int)p, W(0x150), 0, W(0x38));
    func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    func_021B9788(p, 0x20, 0, (int)func_021B9EB0);
    func_021BB98C(p, W(0x150));
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))









void func_021BA004(u8 *p)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB99C((int)p, W(0x150), 0, W(0x38));
    func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    if (*(u32 *)(W(0x280) + 0x34) == 5 || *(u32 *)(W(0x280) + 0x34) == 8) {
        func_021B9788(p, 0x29, 1, (int)func_021BC6C0);
    } else {
        func_021B9788(p, 0x29, 1, (int)func_021B9E3C);
        func_021BA60C(p, (void *)W(0x38));
        *(u32 *)(W(0x280) + 0x40) = 10;
    }
    func_021BB98C(p, W(0x150));
    func_021BA5E0(p, (void *)W(0x38), *(u8 *)(W(0x280) + 0x48));
}









void func_021BA098(u8 *p)
{
    func_021B9804(p, (int)func_021BA0A8);
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(k) (*(u32 *)(p+(k)))








void func_021BA0A8(u8 *p,int action)
{
    u32 old;
    int a,b;
    if (action == 0xe) {
        old = func_02017E1C((void *)W(0x38),6,0);
        if (func_021BA65C(p,old) == 0x3e7) {
            if (*(int *)(S+0x34) == 0xa) {
                *(int *)(S+0x34) = 0;
                func_021BB7A4(p,(u32 *)W(0x150));
                func_021B9788(p,0x3f,1,(int)func_021B9E20);
            } else {
                p[0xc] = 0x13;
                func_021BB7A4(p,(u32 *)W(0x150));
                func_021B9788(p,0x3f,1,(int)func_021B9E3C);
            }
        } else if (func_0202136C(*(u16 *)(S+0x44)) == 1) {
            *(u32 *)(S+0x3c) = W(0x2c);
            p[0xc] = 0x13;
            *(int *)(S+0x40) = 6;
        } else {
            func_021BB7A4(p,(u32 *)W(0x150));
            func_021BA624(p,(void *)W(0x38),*(u16 *)(S+0x44));
            func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
            func_021BC24C(p,(void *)W(0x38),(u16)(*(u16 *)(S+0x44)));
            func_021BC288((int)p,(int)((void *)W(0x38)),*(u16 *)(S+0x44));
            a = func_021BDBF8((char *)p,(void *)W(0x38));
            b = func_021BDC5C((char *)p,(void *)W(0x38));
            func_021BB97C((u16 *)p,W(0x150));
            func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)old);
            func_021BB9AC((int)p,(u32)W(0x150),(u32)2,(u16)(*(u16 *)(S+0x44)));
            if (*(int *)(S+0x34) == 0xa) {
                *(int *)(S+0x34) = 0;
                if (a == 1) {
                    func_021BDC3C((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 1;
                } else if (b == 1) {
                    func_021BDCA0((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 2;
                } else {
                    func_021B9788(p,0x40,1,(int)func_021B9E20);
                }
            } else {
                *(int *)(S+0x40) = 0xa;
                if (a == 1) {
                    func_021BDC3C((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 1;
                } else if (b == 1) {
                    func_021BDCA0((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 2;
                } else {
                    func_021B9788(p,0x40,1,(int)func_021B9E3C);
                }
            }
            func_021BB98C(p,W(0x150));
        }
    } else {
        if (*(int *)(S+0x34) == 0xa) {
            *(int *)(S+0x34) = 0;
            func_021BB7A4(p,(u32 *)W(0x150));
            p[0xc] = 2;
            func_021B7B98(p);
        } else p[0xc] = 0x13;
    }
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))









void func_021BA288(u8 *p)
{
    void *o1;
    void *o2;
    u32 b, c, d, e;

    o1 = func_0201AB28((void *)*(u32 *)W(0x280), W(0x34));
    func_02017E1C(o1, 0xa0, 0);
    b = func_02017E1C(o1, 0xa1, 0);
    o2 = func_0201AB28((void *)*(u32 *)W(0x280), ((u32 *)W(0x280))[0x3c / 4]);
    c = func_02017E1C((void *)W(0x38), 0xa0, 0);
    d = func_02017E1C((void *)W(0x38), 0xa1, 0);
    W(0x2c) = ((u32 *)W(0x280))[0x3c / 4];
    e = c + b / 5;
    if (e > d) {
        func_02017E40(o2, 0xa0, d);
    } else {
        func_02017E40(o2, 0xa0, e);
    }
    W(0x120) = (u32)func_021BA318;
    p[0xc] = 10;
    W(0x24) = 1;
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))









void func_021BA318(u8 *p)
{
    u16 r;
    u16 t;

    r = func_021BB464((int)p, (u16 *)((u32 *)(p + 0x160))[((u32 *)W(0x280))[0x3c / 4]]);
    W(0x2c) = ((u32 *)W(0x280))[0x3c / 4];
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB99C((int)p, W(0x150), 0, W(0x38));
    t = ((struct Obj13244 *)p)->f11C;
    if (t) {
        func_021BB9EC((int)p, (u32)W(0x150), (u32)1, (u16)(r - t), 3);
        func_021B9788(p, 0x2c, 1, (int)func_021B9E20);
    }
    func_021BB98C(p, W(0x150));
}









void func_021BA394(u8 *p)
{
    func_021B9804(p, (int)func_021BA3A4);
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))









void func_021BA3A4(u8 *p, u32 state)
{
    int r;
    void *buf;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (state == 14) {
        r = func_02009020((void *)((u32 *)W(0x280))[2], 0);
        if (r >= 0) {
            buf = func_02008F08(((struct Obj13245 *)p)->f0);
            func_02017E1C((void *)W(0x38), 0xa7, (u32)buf);
            func_0200903C((void *)((u32 *)W(0x280))[2], 0, r, buf);
            func_020307B0(buf);
            func_02017E40((void *)W(0x38), 6, 0);
            func_021BB2C0(p, (u8 *)(((u32 *)(p + 0x160))[W(0x2c)]));
            func_021B9788(p, 0x1a, 1, (int)func_021B9E20);
        } else {
            func_021B9788(p, 0x1e, 1, (int)func_021B9E20);
        }
        return;
    }
    func_021B9788(p, 0x1b, 0, (int)func_021BA444);
}









void func_021BA444(u8 *p)
{
    func_021B9804(p, (int)func_021BA454);
}









void func_021BA454(u8 *a, int k)
{
    func_021BB7A4(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150));
    if (k == 0xe) {
        int v = func_02017E1C((void *)*(int *)&((struct Obj00009 *)a)->f38, 6, 0);

        if (func_021BA65C(a, v) == 0x3e7) {
            func_021B9788(a, 0x3f, 1, (int)func_021B9E20);
            return;
        }
        func_021BA688(a, v);
        func_02017E40((void *)(*(int *)&((struct Obj00009 *)a)->f38), 6, 0);
        func_021BB2C0(a, (u8 *)(*(int *)(a + ((struct Obj00009 *)a)->f2C * 4 + 0x160)));
        func_021B9788(a, 0x1f, 1, (int)func_021B9E20);
    } else {
        func_021BB7A4(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150));
        a[0xc] = 2;
        func_021B7B98(a);
    }
}








void func_021BA4E4(u8 *p) { func_021BB7A4(p, (u32 *)(((struct Obj13246 *)p)->f150)); p[12]=14; }









void func_021BA4F8(u8 *a)
{
    u8 i;
    u8 j;
    u8 *rules;
    int st;

    if (((struct Obj00009 *)a)->f250 != 0)
        return;
    st = a[0xc];
    if (st == 0x13)
        return;
    if (st == 0x15)
        return;
    if (st == 0)
        return;
    if (st == 1)
        return;
    if (st == 6)
        func_021B90F8(a);
    ((struct Obj00009 *)a)->f250 = 1;
    if (((struct Obj00009 *)a)->f278 == 1)
        a[0xc] = 0x11;
    else
        a[0xc] = 0x14;
    ((struct Obj20864 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f3C = 6;
    ((struct Obj20865 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f40 = 0;
    if (((struct Obj00009 *)a)->f118 != 0)
        return;
    for (i = 0; i < 6; i++)
        (*(u8 **)(a + 0x280))[0x49 + i] = 0;
    rules = *(u8 * *)&((struct Obj20866 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f14;
    if (func_0201A59C(rules, (void *)(**(int * *)&((struct Obj00009 *)a)->f280), *(u8 * *)&((struct Obj00009 *)a)->f280 + 0x49) != 0)
        return;
    for (i = 0; i < 6; i++)
        (*(u8 **)(a + 0x280))[0x49 + i] = 0;
    for (j = 0; j < rules[2]; j++)
        (*(u8 **)(a + 0x280))[0x49 + j] = j + 1;
}








u32 func_021BA5B4(u8 *p, void *q) { u8 *s=*(u8 **)(p+0x280); if (*(u32 *)(s+0x34)==5 || *(u32 *)(s+0x34)==8) return func_0201808C(q,*(u16 *)(s+0x46)); else return func_02018238(q,*(u16 *)(s+0x46)); }








/*
 * Verified blocker C (one --thumb, no region, EXACT, 8 bytes):
 * typedef unsigned char u8; typedef unsigned short u16;
 * extern void func_020182A8(void *,u16,u8);
 * void func_020182A0(void *p,u16 move,u8 slot) { func_020182A8(p,move,slot); }
 * Extent ends with two bytes alignment padding.
 *
 * 2026-10-05 (D8 lane 15): 020182A0 now filed EXACT as src/matched/arm9/func_020182A0.c.
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void func_021BA5E0(u8 *p, void *q, u32 slot) { u8 *s=*(u8 **)(p+0x280); if (*(u32 *)(s+0x34)==5 || *(u32 *)(s+0x34)==8) func_020181F4(q,*(u16 *)(s+0x46),slot); else func_020182A0(q,*(u16 *)(s+0x46),slot); }








void func_021BA60C(u8 *p, void *q) { func_0201B7A0(q,7,((struct Obj20869 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f30,((struct Obj00009 *)p)->f0); }







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(k) (*(u32 *)(s+(k)))







#undef S






#undef S





#undef S




#undef S



#undef S


#undef S

#undef S
#define S(k) (*(int *)(s+(k)))








void func_021BA624(u8 *p, void *q, u16 id) { u32 old=func_02017E1C(q,6,0); if(old) func_021BA688(p,old); func_02017E40(q,6,id); if(id) func_021BA670(p,id); }








u32 func_021BA65C(u8 *p, u16 id) { return func_02007FB8(*(u8 * *)&((struct Obj20870 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f4, id, ((struct Obj00009 *)p)->f0); }








u32 func_021BA670(u8 *p, u16 id) { return func_02007F1C(*(u8 * *)&((struct Obj20871 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f4,id,1,((struct Obj00009 *)p)->f0); }








u32 func_021BA688(u8 *p, u16 id) { return func_02007E50(*(u8 * *)&((struct Obj20872 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f4,id,1,((struct Obj00009 *)p)->f0); }








u8 *func_021BA6A0(u8 *p, int k, void *mon)
{
    u8 x = d_021BEC74[k*2];
    u8 y = d_021BEC75[k*2];
    u8 i;
    u8 *s;
    int t;
    int zero = 0;
    enum Selector { SEL_ZERO, SEL_ONE } selector;
    Rect_021B9C64 r;
    s = func_02030734(*(u16 *)p,0x44,0,d_021BED18,0x9f);
    s[4] = k;
    W(0) = (u32)mon;
    W(0x14) = 0;
    W(0x10) = 0;
    W(0x18) = 0;
    *(u16 *)(s+6) = func_02017E1C(mon,0xa0,0);
    *(u16 *)(s+8) = *(u16 *)(s+6);
    if (k != 0) zero = 1;
    selector = k != 0;
    t = x + 0x10;
    func_020410D0(2,(u8)t,y,0x10,6,(u32)(*(u8 **)(p+0x15c)+0xc),
                 d_021BEC6C[selector*2],d_021BEC6D[zero*2],0x20,0x20);
    W(0xc) = func_02017E1C((void *)W(0),0x4c,0);
    r.a = 0;
    r.b = 0;
    r.c = 0x100;
    r.d = 0xc0;
    r.e = 0;
    r.f = 0;
    W(0x24) = (u32)func_0204B034((u8 *)(&r.a),1,*(u16 *)p);
    W(0x28) = (u32)func_0204B100(6,0,*(u16 *)p);
    func_0204B258((void *)W(0x28),(void *)W(0x24));
    func_021BA954(p,s);
    func_021BAA50(p,s);
    r.x = -x*8;
    r.y = -y*8;
    func_0204B09C((void *)W(0x24), (int)0, &r);
    W(0x20) = (u32)(void *)func_020450F0(1, t, (u8)y, 0x10, 6, 0xd, 1);
    func_021BB46C(p,(u32 *)s);
    if (func_021B9A84((u32)p) == 1) {
        for (i = 0; i < 6; i++) {
            if (s[4] + 1 == *(u8 *)(*(u8 **)(p+0x280)+i+0x49)) W(0x1c) = i;
        }
    }
    func_021BAFA0(p,s,0);
    func_021BAAE4(p,s,0);
    return s;
}









S44 *func_021BA81C(u8 *a, int k)
{
    S44 *p = func_02030734(((struct Obj13247 *)a)->f0, 0x44, 0, d_021BED18, 0xea);
    u8 *q = *(u8 * *)&((struct Obj13247 *)a)->f15C + 0xc;

    func_020410D0(2, (u8)(d_021BEC74[k * 2] + 0x10), d_021BEC75[k * 2], 0x10, 6,
                  (u32)q, 0, 0x13, 0x20, 0x20);
    p->b4 = k;
    p->w0 = 0;
    p->w14 = 1;
    p->w1c = 8;
    func_02041B6C(2);
    return p;
}








void func_021BA890(void *ignored,u8 *p) { if (!((struct Obj03678 *)p)->f14) { func_020452E8(((struct Obj03678 *)p)->f20); func_0204B3B4(((struct Obj03678 *)p)->f30); func_0204B3B4(((struct Obj03678 *)p)->f34); func_0204B3B4(((struct Obj03678 *)p)->f38); func_0204B084(((struct Obj03678 *)p)->f24); func_0204B1CC(((struct Obj03678 *)p)->f28); func_0204A8D4(((struct Obj03678 *)p)->f2C); } func_020307B0(p); }









void func_021BA8CC(u32 a, St_021B9C64 *s)
{
    s16_021BA624 buf[2];

    if (s->w14 != 0)
        return;
    if (s->w18 == 1) {
        u32 t = (u32)func_02045770((struct Descriptor *)s->w20);

        if (func_0201C6C4((struct PrintSys *)(((struct Obj20873 *)a)->f140), (void *)t) == 0) {
            a = s->w20;
            s->w18 = 0;
            func_02045334((struct Descriptor *)a);
            func_02045374((struct Cfg *)a);
            func_02041B6C(func_02045730((struct Descriptor *)a));
        }
    }
    if (s->w10 == 1 && func_02017F90((void *)s->w0) == 0 && s->h6 != 0) {
        func_021BB56C((u32)s, 0x1a, 0x13, (u16 *)buf);
        if (func_0204B8F4((struct Obj *)s->w30) == 1)
            buf[1] = buf[1] - 6;
        func_0204B404((struct Obj *)s->w30, (const struct Vec2 *)buf, 0);
    }
}








void func_021BA954(u8 *p,u8 *s)
{
    R_021BA954 a;
    R_021BA954 b;
    R_021BA954 c;
    R_021BA954 d;
    int x;
    a.a=16;a.b=16;a.c=0;a.d=1;a.e=2;
    x=(int)func_0204B294((void *)S(0x28),P(0x19c),P(0x178),P(0x1b8),&a,0,((struct Obj07731 *)p)->f0);
    S(0x34)=x;
    func_0204B92C((struct Obj *)x,1);
    b.a=0x54;b.b=0x1c;b.c=0;b.d=0;b.e=2;
    S(0x38)=(int)func_0204B294((void *)S(0x28),P(0x1b0),P(0x18c),P(0x1cc),&b,0,((struct Obj07731 *)p)->f0);
    c.a=32;c.b=24;c.c=0;c.d=0;c.e=2;
    x=(int)func_0204B294((void *)S(0x28),P(0x1a4),P(0x180),P(0x1c0),&c,0,((struct Obj07731 *)p)->f0);
    S(0x3c)=x;
    func_0204B3DC((struct Obj *)x,0);
    d.a=32;d.b=42;d.c=0;d.d=0;d.e=2;
    x=(int)func_0204B294((void *)S(0x28),P(0x1ac),P(0x188),P(0x1c8),&d,0,((struct Obj07731 *)p)->f0);
    S(0x40)=x;
    func_0204B3DC((struct Obj *)x,0);
}









void func_021BAA50(u8 *a, u8 *s)
{
    void *h;
    int t;
    int r;
    R_021BAA50 rc;

    h = func_020490F4(7, ((struct Obj05169 *)a)->f0);
    t = (int)func_020185F4(func_0201AB28(**(void ** *)&((struct Obj05169 *)a)->f280, s[4]));
    ((struct Obj05170 *)s)->f2C = func_0204A6C8(h, func_0201BA68((void *)t), 0, 0, ((struct Obj05169 *)a)->f0);
    func_02049238(h);
    r = func_0201BBE8((void *)t);
    rc.a = 0x18;
    rc.b = 0x10;
    rc.c = 1;
    rc.d = 0;
    rc.e = 2;
    {
        int x = (int)func_0204B294((void *)((struct Obj05170 *)s)->f28, ((struct Obj05170 *)s)->f2C, ((struct Obj05169 *)a)->f190,
                              ((struct Obj05169 *)a)->f1D0, &rc, 0, ((struct Obj05169 *)a)->f0);
        ((struct Obj05170 *)s)->f30 = x;
        func_0204B6F4((struct Obj *)x, r, 1);
    }
    func_0204B92C((struct Obj *)((struct Obj05170 *)s)->f30, 1);
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(int *)(s + (o)))







void func_021BAAE4(u8 *a,u8 *s,int k) { if(((struct Obj03183 *)s)->fC==0) {func_021BAB04(a,s,k);func_021BAE94(a,s);} else func_021BAF28(a,s); }








void func_021BAB04(u8 *a, u8 *s, int k)
{
    int f = 0;
    u32 ws;
    u32 ws2;
    u32 ws3;
    u32 code;
    u32 m;
    u32 r5;
    u32 r6;
    u32 v;
    u16 r;
    u8 *obj;

    if (*(int *)(*(u8 **)(a + 0x280) + 0x34) == 6 || *(int *)(a + 0x18) == 1) {
        f = 1;
    }
    if (k == 0) {
        ws = (u32)func_0201EC64(*(u16 *)a);
        func_0201EEF4((struct WordSet *)ws, 0, *(void **)s);
        func_021B9CF4(a, W(0x20), (void *)ws, 3, 0x29, 9, 0x440);
        func_0201ED04((struct WordSet *)ws);
    }
    if (k == 0) {
        if (func_02017E1C(*(void **)s, 0xad, 0) == 1) {
            v = func_02017E1C(*(void **)s, 0x6e, 0);
            if (v == 0) {
                func_021B9C1C(a, W(0x20), (u16)7, 0x69, 9, 0x14c0);
            } else if (v == 1) {
                func_021B9C1C(a, W(0x20), (u16)8, 0x69, 9, 0xc80);
            }
        }
    }
    if (f == 0) {
        if ((func_02017F90(*(void **)s) == 0 && *(u16 *)(s + 6) != 0) || W(0x1c) != 8) {
            ws2 = (u32)func_0201EC64(*(u16 *)a);
            func_0201EFA4((struct WordSet *)ws2, 0, func_02018430(*(void **)s), 3, 0, 1);
            if (k == 0) {
                func_021B9D58(a, W(0x20), (void *)ws2, 2, 9, 0x23, 0x440);
            } else {
                func_021B9DC0(a, W(0x20), (void *)ws2, 2, 9, 0x23, 0x440);
            }
            func_0201ED04((struct WordSet *)ws2);
            func_0204B3DC((struct Obj *)W(0x40), 0);
        } else {
            if (*(u16 *)(s + 6) == 0) {
                func_0204B878((struct Obj *)W(0x40), 6);
            } else {
                switch (func_02017F90(*(void **)s)) {
                case 1: func_0204B878((struct Obj *)W(0x40), 1); break;
                case 2: func_0204B878((struct Obj *)W(0x40), 3); break;
                case 3: func_0204B878((struct Obj *)W(0x40), 2); break;
                case 4: func_0204B878((struct Obj *)W(0x40), 5); break;
                case 5: func_0204B878((struct Obj *)W(0x40), 4); break;
                }
            }
            func_0204B3DC((struct Obj *)W(0x40), 1);
        }
    }
    m = W(0x1c);
    if (m != 8) {
        if (m == 6) {
            m = 0x81;
        } else if (m == 7) {
            m = 0x82;
        } else {
            m = m + 0x83;
        }
        func_021B9C1C(a, W(0x20), (u16)m, 0x2e, 0x1f, 0x440);
        func_0204B3DC((struct Obj *)W(0x38), 0);
    } else if (f == 1) {
        switch (func_021B9AC8(a, *(void **)s, s[4])) {
        case 0:
        case 1: code = 0x89; break;
        case 2: code = 0x8a; break;
        case 3: code = 0x8b; break;
        }
        func_021B9C1C(a, W(0x20), (u16)code, 0x1d, 0x1f, 0x440);
        func_0204B3DC((struct Obj *)W(0x38), 0);
    } else {
        obj = *(u8 **)(a + 0x280);
        if (*(int *)(obj + 0x34) == 0x10) {
            v = func_021B9BF4(a, *(void **)s, *(u16 *)(obj + 0x44));
            m = 0x8d;
            if (v != 0) {
                m = 0x8c;
            }
            func_021B9C1C(a, W(0x20), (u16)m, 0x2e, 0x1f, 0x440);
            func_0204B3DC((struct Obj *)W(0x38), 0);
        } else {
            ws2 = (u32)func_0201EC64(*(u16 *)a);
            func_0201EFA4((struct WordSet *)ws2, 0, func_02017E1C(*(void **)s, 0xa1, 0), 3, 0, 1);
            if (k == 0) {
                func_021B9D58(a, W(0x20), (void *)ws2, 4, 0x5b, 0x23, 0x440);
            } else {
                func_021B9DC0(a, W(0x20), (void *)ws2, 4, 0x5b, 0x23, 0x440);
            }
            func_0201ED04((struct WordSet *)ws2);
            ws3 = (u32)func_0201EC64(*(u16 *)a);
            func_0201EFA4((struct WordSet *)ws3, 0, *(u16 *)(s + 6), 3, 1, 1);
            if (k == 0) {
                func_021B9D58(a, W(0x20), (void *)ws3, 5, 0x39, 0x23, 0x440);
            } else {
                func_021B9DC0(a, W(0x20), (void *)ws3, 5, 0x39, 0x23, 0x440);
            }
            func_0201ED04((struct WordSet *)ws3);
            if (k == 0) {
                func_021B9C64(a, W(0x20), 6, 0x52, 0x23, 0x440);
            } else {
                func_021B9CB0(a, W(0x20), 6, 0x52, 0x23, 0x440);
            }
        }
    }
    r5 = func_02017E1C(*(void **)s, 6, 0);
    if (r5 != 0) {
        func_0204B3DC((struct Obj *)W(0x3c), 1);
        if (func_0202136C(r5) == 1) {
            func_0204B878((struct Obj *)W(0x3c), 1);
        } else {
            func_0204B878((struct Obj *)W(0x3c), 0);
        }
    } else {
        func_0204B3DC((struct Obj *)W(0x3c), 0);
    }
    r6 = func_021BB554((u32)s);
    r = 1;
    if (r6 == 3) {
        r = 0;
    } else if (func_02017F90(*(void **)s) != 0) {
        r = 5;
    } else if (r6 == 2) {
        r = 4;
    } else if (r6 == 1) {
        r = 3;
    } else if (r6 == 0) {
        r = 2;
    }
    func_0204B878((struct Obj *)W(0x30), r);
    W(0x18) = 1;
}




#undef W



#undef W


#undef W

#undef W

#define W(k) (*(u32 *)(s+(k)))








void func_021BAE94(u8 *a, u8 *s)
{
    u8 r;
    int x;
    int y;
    int h;
    u32 w;

    if (func_021B9A84((u32)a) != 0)
        return;
    if (((struct Obj20876 *)(*(u8 * *)&((struct Obj20875 *)a)->f280))->f34 == 6)
        return;
    r = func_021BB554((u32)s);
    h = func_0202D01C(((struct Obj03183 *)s)->f6, func_02017E1C((void *)((struct Obj03183 *)s)->f0, 0xa1, 0), 0x30);
    w = (u32)func_02045770((struct Descriptor *)((struct Obj03183 *)s)->f20);
    if (r == 2 || r == 3) {
        x = 0xe;
        y = 0xf;
    } else if (r == 1) {
        x = 0xc;
        y = 0xd;
    } else {
        x = 0xa;
        y = 0xb;
    }
    func_02043AF4((struct Bmp *)w, 0x3d, 0x1b, h, 1, x);
    func_02043AF4((struct Bmp *)w, 0x3d, 0x1c, h, 1, y);
    func_0204B3DC((struct Obj *)((struct Obj03183 *)s)->f38, 1);
}








void func_021BAF28(u8 *a, u8 *s)
{
    u32 r6;
    u32 r7;

    r6 = (u32)func_0201EC64(((struct Obj06211 *)a)->f0);
    r7 = (u32)func_02045EC0(g_020A7370, 0x28a);
    func_0201EE0C((struct WordSet *)r6, 0, (const void *)r7, 0, 1, 2);
    func_021B9CF4(a, ((struct Obj03183 *)s)->f20, (void *)r6, 3, (s16_021B9C64)0x29, (s16_021B9C64)9, 0x440);
    func_02045808((struct U16Vec *)r7);
    func_0201ED04((struct WordSet *)r6);
    func_0204B3DC((struct Obj *)((struct Obj03183 *)s)->f38, 0);
    func_0204B878((struct Obj *)(((struct Obj03183 *)s)->f30), 1);
    ((struct Obj03183 *)s)->f18 = 1;
}








static inline s16 *get(u8 *s, int x, int y, s16 *buf)
{
    func_021BB56C((u32)s, x, y, (u16 *)buf);
    return buf;
}








void func_021BAFA0(u8 *a, u8 *s, int k)
{
    s16 b1[2];
    s16 b0[2];
    s16 *p;

    if (k == 1) {
        if ((u8)(a[0xc] + 253) <= 1)
            func_021BB050((int)a, s, 8);
        else if (func_021B9A84((u32)a) == 1 && ((struct Obj03679 *)s)->f1C < 6)
            func_021BB050((int)a, s, 8);
        else
            func_021BB050((int)a, s, 6);
        func_0204B878((struct Obj *)(((struct Obj03679 *)s)->f34), 1);
        p = get(s, 0x1a, 0x13, b1);
    } else {
        if ((a[0xc] == 3 && ((struct Obj00009 *)a)->f30 == s[4]) ||
            (a[0xc] == 4 && ((struct Obj00009 *)a)->f34 == s[4]))
            func_021BB050((int)a, s, 5);
        else if (func_021B9A84((u32)a) == 1 && ((struct Obj03679 *)s)->f1C < 6)
            func_021BB050((int)a, s, 5);
        else
            func_021BB050((int)a, s, 3);
        func_0204B878((struct Obj *)(((struct Obj03679 *)s)->f34), 0);
        p = get(s, 0x18, 0x10, b0);
    }
    func_0204B404((struct Obj *)(((struct Obj03679 *)s)->f30), (const struct Vec2 *)p, 0);
    ((struct Obj03679 *)s)->f10 = k;
}








void func_021BB050(int unused, u8 *s, int k)
{
    if (k == 3 && func_021BB554((u32)s) == 3)
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, 4);
    else if (k == 6 && func_021BB554((u32)s) == 3)
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, 7);
    else
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, k);
    func_02041B6C(2);
}







void func_021BB0C4(u8 *p,const u8 *s,int d)
{
    int i=s[4];
    int x=d_021BEC74[i*2];
    u8 y=d_021BEC75[i*2];
    Pt pt;
    int zero;
    enum Selector {SEL_ZERO,SEL_ONE} selector;
    if (i % 2 == 0) d=-d;
    func_02045780((void *)W(0x20),d+(x+16));
    pt.x=-(x+d)*8;
    pt.y=-y*8;
    func_0204B09C((void *)W(0x24), 0, &pt);
    zero=0;
    if (s[4] != 0) zero=1;
    selector=s[4] != 0;
    x+=16;
    d=(unsigned)x+d;
    func_020410D0(2,(u8)d,y,16,6,(u32)(*(u8 **)(p+0x15c)+12),d_021BEC6C[selector*2],d_021BEC6D[zero*2],32,32);
    func_020413B0(2,d,y,16,6,5);
    func_02045374((void *)W(0x20));
    func_02041B6C(1);
    func_02041B6C(2);
}







void func_021BB1A0(int unused, u8 *s, int d)
{
    int i = s[4];
    int x = d_021BEC74[i * 2];
    u8 y = d_021BEC75[i * 2];
    int z;

    if (i % 2 == 0)
        d = -d;
    z = x + 0x10 + d;
    func_02041300(2, 0, z, y, 0x10, 6, 5);
    func_02041300(1, 0, z, y, 0x10, 6, 5);
}







void func_021BB200(u8 *a, u8 *s, int p, int q)
{
    s16 b[4];
    int i = s[4];
    int x = d_021BEC74[i * 2];
    int y = d_021BEC75[i * 2];

    if (i % 2 == 0)
        q = -q;
    *(int *)s = p;
    *(int *)(s + 0x18) = 0;
    *(int *)(s + 0xc) = func_02017E1C((void *)p, 0x4c, 0);
    *(u16 *)(s + 6) = func_02017E1C((void *)(*(int *)s), 0xa0, 0);
    *(u16 *)(s + 8) = *(u16 *)(s + 6);
    func_0204B3B4((struct Obj *)(*(int *)(s + 0x30)));
    func_0204A8D4(*(int *)(s + 0x2c));
    func_02043B5C(func_02045770((struct Descriptor *)(*(u32 *)(s + 0x20))), 0);
    func_0204B3DC((struct Obj *)(*(int *)(s + 0x3c)), 0);
    func_0204B3DC((struct Obj *)(*(int *)(s + 0x40)), 0);
    b[2] = 0;
    b[3] = 0;
    func_0204B09C((void *)(*(int *)(s + 0x24)), 0, &b[2]);
    func_021BAA50(a, s);
    b[0] = -(x + q) * 8;
    b[1] = -y * 8;
    func_0204B09C((void *)(*(int *)(s + 0x24)), 0, b);
    func_021BAAE4(a, s, 0);
}






void func_021BB2C0(u8 *a,u8 *s) {func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj20878 *)s)->f20)),0);func_021BAAE4(a,s,0);}



#undef H


#undef H

#undef H
#define H(k) (*(u16 *)(p+(k)))



#undef W


#undef W

#undef W



#define W(o) (*(u32 *)(s+(o)))










void func_021BB2E0(u8 *a,u8 *s) {func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj20879 *)s)->f20)),0,26,128,22,0);func_021BAAE4(a,s,1);}











void func_021BB30C(u8 *a, S_021BB30C *s)
{
    s->hi = func_02017E1C((void *)s->obj, 0xa0, 0);
    ((s8 *)a)[0x11e] = (s->hi - s->lo) / 100;
    if (s->hi > s->lo)
        ((s8 *)a)[0x11e] = ((s8 *)a)[0x11e] + 1;
    else
        ((s8 *)a)[0x11e] = ((s8 *)a)[0x11e] - 1;
}











int func_021BB358(u8 *p, S_021BB358 *s)
{
    if (s->a < s->b) {
        if (s->a == 0) {
            func_021BB050((int)p, (u8 *)s, 6);
        }
        {
            u16 cur = s->a;
            signed char st = p[0x11E];
            u16 lim = s->b;
            if (cur + st > lim) {
                s->a = lim;
            } else {
                s->a = cur + (u16)st;
            }
        }
        func_021BB2E0(p, (u8 *)s);
        return 0;
    }
    if (s->a > s->b) {
        signed char st = p[0x11E];
        if (s->a + st < s->b) {
            s->a = s->b;
        } else {
            s->a = s->a + (u16)st;
        }
        func_021BB2E0(p, (u8 *)s);
        return 0;
    }
    return 1;
}










int func_021BB3C4(void *unused, u32 p) { if (((struct Obj20880 *)p)->f14 != 1) return 1; return 0; }










void func_021BB3D4(void *a,u8 *s,u16 *out) { out[0]=(d_021BEC74[s[4]*2]+8)<<3; out[1]=(d_021BEC75[s[4]*2]+3)<<3; }











void func_021BB3FC(int unused, u8 *s, u8 *out)
{
    out[2] = d_021BEC74[s[4] * 2] << 3;
    out[0] = d_021BEC75[s[4] * 2] << 3;
    out[3] = (d_021BEC74[s[4] * 2] + 16) << 3;
    out[1] = (d_021BEC75[s[4] * 2] + 6) << 3;
}










int func_021BB43C(int *p)
{
    return p[7];
}










void func_021BB440(u8 *p, u32 *q, int v)
{
    if (q[7] != v) {
        if (v < 6) {
            q[7] = v;
        } else {
            func_021BB46C(p, (u32 *)q);
        }
        func_021BB2C0(p, (u8 *)q);
    }
}










unsigned short func_021BB464(int unused, unsigned short *p)
{
    (void)unused;
    return p[3];
}










int func_021BB468(int unused, int *p)
{
    (void)unused;
    return p[3];
}










void func_021BB46C(u8 *p, u32 *q)
{
    if (func_021B9A84((u32)p) == 0) {
        q[7] = 8;
        return;
    }
    if (func_02019DA4(*(void **)(*(u8 **)(p + 0x280) + 0x14), (void *)q[0]) == 0) {
        q[7] = 6;
        return;
    }
    q[7] = 7;
}











int func_021BB4A0(u8 *p, int *s)
{
    int a;
    int b;
    u8 *q;
    u8 i;

    if (s[7] != 6) {
        return 1;
    }
    i = 0;
    a = func_02017E1C((void *)s[0], 5, 0);
    b = func_02017E1C((void *)s[0], 6, 0);
    q = *(u8 * *)&((struct Obj20884 *)(*(u8 * *)&((struct Obj13251 *)p)->f280))->f14;
    do {
        u8 v;
        v = (*(u8 **)(p + 0x280))[i + 0x49];
        if (v >= 1) {
            void *e = **(void ***)(p + 0x15C + v * 4);
            int x = func_02017E1C(e, 5, 0);
            int y = func_02017E1C(e, 6, 0);
            if (a == x && q[8] == 0) {
                return 2;
            }
            if (b == y && b != 0 && q[9] == 0) {
                return 3;
            }
        }
        i = i + 1;
    } while (i < 6);
    if (p[0x105] == q[3]) {
        return 4;
    }
    return 0;
}










u8 func_021BB554(u32 p) { return func_0202D034(((struct Obj03680 *)p)->f6,func_02017E1C(((struct Obj03680 *)p)->f0,0xa1,0)); }










void func_021BB56C(u32 p,int x,int y,u16 *out) { Pair_021B8DB4 pos; func_0204B0C8((struct Owner *)(((struct Obj20885 *)p)->f24),0,(struct Pt *)(&pos)); out[0]=x-pos.x; out[1]=y-pos.y; }











u32 *func_021BB594(u16 *h)
{
    u32 *r;
    u32 z;

    r = func_02030734(*h, 0x38, 0, (const char *)d_021BED28, 0x64);
    z = 0;
    func_0201F5BC(0, 1, 0xc, 0, *h);
    r[2] = (u32)sub_0203101C(*h, *h, 1, 0);
    r[3] = z;
    r[0] = 4;
    r[9] = z;
    r[8] = z;
    r[11] = z;
    r[13] = z;
    r[12] = z;
    r[5] = func_02028590(0xf, 1, 1, *h);
    r[10] = func_0201C440((void *)(*h));
    return r;
}











void func_021BB5FC(void *a, int *s)
{
    if (s[0] != 4) {
        func_021BB7A4(a, (u32 *)s);
    }
    if (s[13] != 0) {
        func_0202F038((u8 *)s[13]);
    }
    if (s[3] != 0) {
        func_0201CE48((struct Rec3 *)s[3]);
        func_02045808((struct U16Vec *)s[4]);
    }
    func_0201C6EC((struct PrintSys *)s[10]);
    func_0201C4C0((struct PrintSys *)s[10]);
    func_02028604(s[5]);
    func_02031140((struct S02031140 *)s[2]);
    func_020307B0(s);
}










void func_021BB644(u8 *p,u8 *s)
{
    func_020310C4((struct Tcbl *)W(8));
    if (W(0xc) != 0) {
        func_020286C4((struct Ctx *)W(0x14),(void *)W(0xc),(void *)W(4));
        if (func_02028484((struct Blk *)(s+0x18),(void *)W(0xc)) == 1) {
            if (W(0x20) == 0 || (func_020362DC() & 3) != 0 || func_02035C60() == 1) {
                if (W(0x20) == 1) func_020061E4(0x547);
                func_0201CE48((struct Rec3 *)W(0xc));
                W(0xc)=0;
                func_02045808((struct U16Vec *)W(0x10));
            } else {
                func_0202865C((struct Ctx *)W(0x14),(const struct Bmp *)((u32)func_02045770((struct Descriptor *)W(4))),15);
                func_02045334((struct Descriptor *)W(4));
            }
        }
    }
    if (W(0x24) == 1 && func_0201C6C4((struct PrintSys *)W(0x28),(void *)((u32)func_02045770((struct Descriptor *)W(4)))) == 0) {
        u32 t=W(4);
        W(0x24)=0;
        func_02045334((struct Descriptor *)t);
        func_02045374((struct Cfg *)t);
        func_02041B6C(func_02045730((struct Descriptor *)t));
        if (W(0x30) == 1) {
            W(0x30)=0;
            W(0x34)=(u32)func_0202EE8C(W(8),(void *)W(4),15,16,((struct Obj20886 *)p)->f0);
        }
    }
    func_0201C4E4((struct PrintSys *)W(0x28));
}











void func_021BB714(void *a, u32 *s, u32 k)
{
    s[0] = k;
    switch (k) {
    case 0:
        s[1] = func_020450F0((int)0, (u8)1, (u8)0x15, (int)0x15, 2, 0xe, 1);
        break;
    case 1:
        s[1] = func_020450F0((int)0, (u8)1, (u8)0x15, (int)0x14, 2, 0xe, 1);
        break;
    case 2:
        s[1] = func_020450F0((int)0, (u8)2, (u8)0x13, (int)0xe, 4, 0xe, 1);
        break;
    case 3:
        s[1] = func_020450F0((int)0, (u8)2, (u8)0x13, (int)0x1c, 4, 0xe, 1);
        break;
    }
    func_0201F73C((void *)s[1], 1, 1, 0xc);
    func_021BBA28((int)a, (int)s);
}










void func_021BB7A4(void *p,u32 *s) { if(s[0]!=4) { if(s[13]!=0) {func_0202F038((u8 *)s[13]);s[13]=0;} func_0201F7A8((void *)s[1],1); func_020452E8((struct Descriptor *)s[1]); func_0201C6EC((struct PrintSys *)s[10]); s[0]=4; } }










int func_021BB7D8(void *unused, u32 p) { if (((struct Obj20887 *)p)->f0 != 4) return 1; return 0; }











void func_021BB7E8(u8 *a, u32 *s, u32 x)
{
    u32 t;
    u32 n;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj09930 *)a)->f134), x);
    if (s[11] != 0) {
        n = (u32)func_020457B0(0x100, ((struct Obj09930 *)a)->f0);
        func_0201F250((struct WordSet *)s[11], (void *)n, (void *)t);
        func_02045808((struct U16Vec *)t);
        t = n;
    }
    func_021BBA28((int)a, (int)s);
    func_0201C6EC((struct PrintSys *)s[10]);
    func_0201C724((void *)s[10], (u32)func_02045770((struct Descriptor *)s[1]), 1, 1, t, ((struct Obj09930 *)a)->f138, 0x440);
    s[9] = 1;
    func_02045808((struct U16Vec *)t);
}











void func_021BB860(u8 *a, u32 *s, u32 x, u32 y)
{
    u32 t;
    u32 n;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06213 *)a)->f134), x);
    if (s[11] != 0) {
        n = (u32)func_020457B0(0x100, ((struct Obj06213 *)a)->f0);
        func_0201F250((struct WordSet *)s[11], (void *)n, (void *)t);
        func_02045808((struct U16Vec *)t);
        t = n;
    }
    func_021BBA28((int)a, (int)s);
    if (s[3] != 0) {
        func_0201CE48((struct Rec3 *)s[3]);
        func_02045808((struct U16Vec *)s[4]);
    }
    s[8] = y;
    s[4] = t;
    func_02028470((u8 *)(s + 6), 6);
    s[3] = (u32)func_0201CD10(s[1], 0, 0, s[4], ((struct Obj06213 *)a)->f138, func_02012FFC(), s[2], 0,
                         ((struct Obj06213 *)a)->f0, 0xf, (u32)func_021BB910);
}










int func_021BB8FC(void *unused, u32 p) { if (((struct Obj13252 *)p)->fC==0 && ((struct Obj13252 *)p)->f24==0) return 1; return 0; }











int func_021BB910(int k)
{
    switch (k) {
    case 2:
        func_02005DE4((void *)1);
        func_02005E64();
        func_02005D90(0x515, 0xffff);
        break;
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
            return 0;
        }
        return 1;
    case 6:
        return func_02006238();
    }
    return 0;
}










void func_021BB97C(u16 *p,u32 s) { ((struct Obj20889 *)s)->f2C=(u32)func_0201EC64(*p); }










void func_021BB98C(void *p,u32 s) { func_0201ED04((struct WordSet *)(((struct Obj13253 *)s)->f2C)); ((struct Obj13253 *)s)->f2C=0; }










void func_021BB99C(int a,int b,int c,int d) {func_0201EEF4(((struct Obj20890 *)b)->f2C,c,(void *)d);}










void func_021BB9AC(int a,int b,int c,int d) {func_0201EF40((struct WordSet *)(((struct Obj20891 *)b)->f2C),c,d);}










void func_021BB9BC(int a, u32 b, u32 c, int d) {func_0201EF4C((struct WordSet *)(((struct Obj20892 *)b)->f2C),c,d);}










void func_021BB9CC(int a,int b,int c,int d) {func_0201EF34((struct WordSet *)(((struct Obj20893 *)b)->f2C),c,d);}










void func_021BB9DC(int a,int b,int c,int d) {func_0201F140((struct WordSet *)(((struct Obj20894 *)b)->f2C),c,(unsigned char)d);}










void func_021BB9EC(int a,int b,int c,int d,unsigned char e) {func_0201EFA4((struct WordSet *)(((struct Obj20895 *)b)->f2C),c,d,e,0,1);}










void func_021BBA0C(int a,int b,int c,const void *d,int e) {func_0201EE0C((struct WordSet *)(((struct Obj20896 *)b)->f2C),c,d,e,1,2);}










void func_021BBA28(int a,int b) {unsigned int q; func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj03681 *)b)->f4)),15); q=((struct Obj03681 *)b)->f4; func_02045334((struct Descriptor *)q);func_02045374((struct Cfg *)q);func_02041B6C(func_02045730((struct Descriptor *)q));}










void func_021BBA54(unsigned short *a, u32 b) {func_0201F5BC(0,1,12,0,*a);}











/*
 * Unlabelled store-and-return leaf (listed as .word at 0x021BBA68) called
 * from func_021B68F0 with (p, *(p + 0x150)).
 */
void func_021BBA68(u8 *p, u8 *s)
{
    ((struct Obj20898 *)s)->f30 = 1;
}










void func_021BBA70(int a,int b) {func_02028618((struct Ctx *)(((struct Obj09931 *)b)->f14),(const struct Bmp *)((unsigned int)func_02045770((struct Descriptor *)((struct Obj09931 *)b)->f4)),15);func_02045334((struct Descriptor *)((struct Obj09931 *)b)->f4);}











u32 *func_021BBA8C(u16 *h)
{
    u32 *r;

    r = func_02030734(*h, 0x84, 0, (const char *)d_021BED38, 0x63);
    func_02049B40(func_020275E4(), 0x1f, 0, 0x20, 0x40, *h);
    r[0x20] = (u32)func_02049DB4(func_020275E4(), 0x20, 0, (u32)((void **)&r[0x1f]), *h);
    return r;
}










void func_021BBAE0(int a,unsigned char *b) {func_020307B0(((struct Obj20900 *)b)->f80);func_020307B0(b);}











void func_021BBAF8(u8 *a, u8 *b, int *items)
{
    Req r;

    func_021BBC04(a, b, items);
    r.heap = ((struct Obj09933 *)a)->f0;
    r.v = b[0];
    r.p = b + 0x14;
    r.one = 1;
    r.c[0] = 0x20;
    r.c[1] = 0x18;
    r.c[2] = 0xd;
    r.c[3] = 3;
    func_020355D8((int)(((struct Obj09933 *)a)->f8));
    ((struct Obj13254 *)b)->f74 = (int)func_02027778((struct TaskMenuTmpl *)(&r), (void *)(((struct Obj09933 *)a)->f254));
}











void func_021BBB40(u8 *a, u8 *b)
{
    Req r;
    Tbl t = d_021BEC80;

    func_021BBC04(a, b, (int *)(&t));
    r.heap = ((struct Obj07734 *)a)->f0;
    r.v = b[0];
    r.p = b + 0x14;
    r.one = 1;
    r.c[0] = 0x20;
    r.c[1] = 0x12;
    r.c[2] = 8;
    r.c[3] = 3;
    func_020355D8((int)(((struct Obj07734 *)a)->f8));
    ((struct Obj13255 *)b)->f74 = (int)func_02027778((struct TaskMenuTmpl *)(&r), (void *)(((struct Obj07734 *)a)->f254));
}









void func_021BBBA0(unsigned char *a,unsigned char *b) {unsigned char i;func_02027858((struct TaskMenu *)(((struct Obj13256 *)b)->f74));for(i=0;i<b[0];i++)func_02045808((struct U16Vec *)(*(unsigned int *)((unsigned int)b+(unsigned int)i*12+20)));((struct Obj20901 *)a)->f8=func_020355C4();}










void func_021BBBD8(int unused, int *p)
{
    (void)unused;
    func_02027974(p[29]);
}









unsigned int func_021BBBE4(int a,unsigned char *b) {if(func_020279E8(((struct Obj13257 *)b)->f74)==0)return 23;return *(unsigned short *)((unsigned int)b+func_02027A04((const u8 *)(*(int *)&((struct Obj13257 *)b)->f74))*2+2);}









void func_021BBC04(u8 *p, u8 *s, int *items)
{
    int n, i;
    u8 j;
    int v;
    n = 0;
    while (items[n] != 16) {
        n++;
        if (n >= 8)
            break;
    }
    s[0] = 0;
    for (i = 0; i < n; i++) {
        switch (items[i]) {
        case 0: APPEND(0); break;
        case 1:
            for (j = 0; j < 4; j++) {
                if (func_021B99E4(((struct Obj05174 *)p)->f38, j))
                    APPEND(j + 16);
            }
            break;
        case 2:
            for (j = 0; j < 4; j++) {
                if (func_02017E1C(((struct Obj05174 *)p)->f38, j + 0x36, 0))
                    APPEND(j + 16);
            }
            break;
        case 3: APPEND(3); break;
        case 4: APPEND(4); break;
        case 5: APPEND(5); break;
        case 6: APPEND(6); break;
        case 7: APPEND(7); break;
        case 8:
            v = func_021BB43C(*(int **)(p + ((struct Obj05174 *)p)->f2C * 4 + 0x160));
            if (v == 6)
                APPEND(20);
            else if (v <= 5)
                APPEND(21);
            break;
        case 9: APPEND(9); break;
        case 10: APPEND(10); break;
        case 11: APPEND(11); break;
        case 12: APPEND(12); break;
        case 13: APPEND(13); break;
        case 14: APPEND(14); break;
        case 15: APPEND(15); break;
        }
    }
    for (n = 0; n < s[0]; n++) {
        u8 *entry;
        *(int *)(s + n * 12 + 0x14) = func_021BBD98((int)p, (int)s, *(u16 *)(s + n * 2 + 2));
        entry = s + n * 12;
        if (*(u16 *)(s + n * 2 + 2) >= 16 && *(u16 *)(s + n * 2 + 2) <= 19 && (*(int **)(p + 0x280))[0x34 / 4] != 5)
            ((struct Obj07735 *)entry)->f18 = 0x35e0;
        else
            ((struct Obj07735 *)entry)->f18 = 0x39e0;
        if (*(u16 *)(s + n * 2 + 2) == 6)
            ((struct Obj07735 *)entry)->f1C = 1;
        else
            ((struct Obj07735 *)entry)->f1C = 0;
    }
}










int func_021BBD98(int a, int unused, int idx)
{
    int r;
    int h;
    if (idx >= 0x10 && idx <= 0x13) {
        r = func_02017E1C((void *)*(int *)&((struct Obj05174 *)a)->f38, idx + 0x26, 0);
        h = (int)func_02045B38(0, 2, 0xcb, ((struct Obj05174 *)a)->f0);
        r = (int)func_02045EC0((struct MsgBank *)h, r);
        func_02045C04((struct Rec *)h);
    } else {
        r = (int)func_02045EC0((struct MsgBank *)(((struct Obj05174 *)a)->f134), d_021BEC8C[idx]);
    }
    return r;
}










int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5)
{
    St_021BB2E0 s;
    int r;
    s.a = (int)func_02045EC0((struct MsgBank *)(((struct Obj00009 *)p)->f134), id);
    s.b = 0x39e3;
    if (a5 == 0) {
        s.flag = 0;
    } else {
        s.flag = 1;
    }
    r = func_02027FEC(((struct Obj00009 *)p)->f254, (u32)(&s), r3, a4, 10, ((struct Obj00009 *)p)->f0);
    func_02045808((struct U16Vec *)s.a);
    return r;
}










/*
 * Three null-guarded wrappers, each into an ARM9 routine.
 */
void func_021BBE44(int x)
{
    if (x != 0)
        func_02028148((u8 *)x);
}










void func_021BBE50(int x)
{
    if (x != 0)
        func_02028178((u8 *)x);
}










void func_021BBE5C(int x, int f)
{
    if (x != 0)
        func_02028218((struct Obj *)x, f);
}










/*
 * (no witness at all), and no branch outside this 12-byte range reaches it,
 * so the `bl` site cannot be resolved.  All bytes are correct.
 *
 * DUPLICATE: src/matched/func_021BBE68.c (packet pkt_021BBE68) is the
 * promoted EXACT entry for this address; this copy shares the same packet
 * and is left parked so the address is not sharded twice.
 */
void func_021BBE68(int p, int v)
{
    if (p) {
        func_0202822C((char *)p, v);
    }
}









/*
 * extent: 774 bytes of code; final two zero bytes align the next function.
 */
int func_021BBE74(int id)
{
    void *p=func_02020F34(id,0,23);
    int mask;
    int val;
    if(GET(14)!=1) DONE(29);
    if(GET(30)!=0 || GET(31)!=0 || GET(32)!=0 || GET(33)!=0 || GET(34)!=0 || GET(35)!=0 || GET(36)!=0) DONE(0);
    if(GET(27)!=0) DONE(1);
    if(GET(28)!=0) DONE(2);
    mask=GET(18);
    mask+=GET(19)*2;
    mask+=GET(20)*4;
    mask+=GET(21)*8;
    mask+=GET(22)*16;
    mask+=GET(23)*32;
    switch(mask) {
    case 1:DONE(3);
    case 2:DONE(4);
    case 4:DONE(5);
    case 8:DONE(6);
    case 16:DONE(7);
    case 32:DONE(8);
    case 63:
        if(GET(41)!=0) DONE(11);
        DONE(9);
    }
    if(GET(24)!=0) DONE(10);
    if(GET(41)!=0) DONE(11);
    if(GET(26)!=0) DONE(12);
    val=GET(52);
    if(val>0) DONE(13);
    if(val<0) DONE(19);
    val=GET(53);
    if(val>0) DONE(14);
    if(val<0) DONE(20);
    val=GET(54);
    if(val>0) DONE(15);
    if(val<0) DONE(21);
    val=GET(55);
    if(val>0) DONE(16);
    if(val<0) DONE(22);
    val=GET(56);
    if(val>0) DONE(17);
    if(val<0) DONE(23);
    val=GET(57);
    if(val>0) DONE(18);
    if(val<0) DONE(24);
    if(GET(29)!=0) DONE(25);
    if(GET(37)!=0) DONE(26);
    if(GET(38)!=0) DONE(27);
    if(GET(39)!=0 || GET(40)!=0) DONE(28);
    DONE(29);
}









int func_021BC17C(unsigned short *p,int id) { switch(func_021BBE74(id)) { case 26:return 1; case 27:return 1; case 28: if(func_02020FE4((void *)id,39,*p)) return 1; break; } return 0; }








int func_021BC1B4(unsigned short *p,void *id) { if(func_02020FE4(id,27,*p)) return 1; return 0; }









int func_021BC1D0(P *p)
{
    u8 n;
    u8 i;
    n = func_0201AA18((void *)*p->f);
    for (i = 0; i < n; i++) {
        int **q = &p->f;
        int e = (int)func_0201AB28((void *)*p->f, i);
        if (func_021BDD78((void *)e, ((struct Obj20908 *)((char *)*q))->f44, 0, p->id) == 1)
            return i;
    }
    return -1;
}








int func_021BC228(int unused,int id) { switch(func_021BBE74(id)) { case 26: case 27: return 22; case 28: return 21; default: return 21; } }








/*
 * 2026-10-05 (D8 lane 15): the leaf func_02019CF8 is now filed EXACT in src/matched/arm9, so every
 * relocation resolves and this file is EXACT.
 */
void func_021BC24C(void *unused,void *a,int b) { u32 t=0; int r; if(func_02017E1C(a,5,0)==0x1ED) { t=func_02017E1C(a,0x6F,t); r=func_02019CF8(b); if(t!=r)func_02017988(a,r); } }









void func_021BC288(int unused, int a, int b)
{
    int t = 0;
    int r;
    if (func_02017E1C((void *)a, 5, 0) == 0x289) {
        t = func_02017E1C((void *)a, 0x6f, t);
        r = func_02019D00(b);
        if (t != r) {
            func_02017988((void *)a, (u16)r);
        }
    }
}








void func_021BC2C8(int p)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB9AC(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44));
    func_021B9788((u8 *)p, 0x51, 1, (int)func_021B9E3C);
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}








void func_021BC30C(int p)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB9AC(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44));
    func_021B9788((u8 *)p, 0x51, 1, (int)func_021B9E20);
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(k) (*(int *)(p+(k)))





int func_021BC350(u8 *p,int v)
{
    int n=func_021BBE74(*(u16 *)(W(0x280)+0x44));
    int t;
    u8 i;
    u16 z;
    switch(n) {
    case 0:case 8:case 10:case 25:case 29:break;
    case 1:{
        int row=W(0x2c);
        ((struct Obj00009 *)p)->fC=10;
        H(0x11c)=func_021BB464((int)p,(short unsigned int *)(*(int *)(p+row*4+0x160)));
        W(0x120)=(int)func_021BC5CC;
        break;
    }
    case 2:
        t=(int)func_02018430((void *)W(0x38));
        func_021BB97C((u16 *)p, (int)W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021BB9EC((int)p,W(0x150),1,(u16)(t+1),3);
        func_021B9788(p,0x9d,1,(int)func_021BC6A0);
        func_021BB98C(p,W(0x150));
        t=(int)func_020457B0(12,H(0));
        func_02017E1C((void *)W(0x38),0x73,t);
        func_02027268(t);
        func_02045808((struct U16Vec *)t);
        for(i=0;i<6;i++) {
            int j=i*2;
            *(u16 *)(p+j+0x124)=func_02017E1C((void *)W(0x38),*(u16 *)((u8 *)d_021BECE4+j),0);
        }
        break;
    case 3:func_021BCC40((int)p,0x47);break;
    case 4:func_021BCC40((int)p,0x2d);break;
    case 5:func_021BCC40((int)p,0x2f);break;
    case 6:func_021BCC40((int)p,0x30);break;
    case 7:func_021BCC40((int)p,0x2e);break;
    case 9:func_021BCC40((int)p,0x33);break;
    case 11:case 12:{
        int row=W(0x2c);
        ((struct Obj00009 *)p)->fC=10;
        H(0x11c)=func_021BB464((int)p,(short unsigned int *)(*(int *)(p+row*4+0x160)));
        W(0x120)=(int)func_021BC548;
        break;
    }
    case 13:case 14:case 15:case 16:case 17:case 18:
        func_021BCC80((int)p,0x37,(u16)(n-13));break;
    case 19:case 20:case 21:case 22:case 23:case 24:
        z=n-19;
        if(func_021BCC2C((void *)W(0x38),z+13,*(u16 *)(W(0x280)+0x44))==0) func_021BCC80((int)p,0x55,z);
        else if(func_02017E1C((void *)W(0x38),9,0)==255) func_021BCC80((int)p,0x54,z);
        else func_021BCC80((int)p,0x53,z);
        break;
    case 26:case 27:
        func_021BB97C((u16 *)p, (int)W(0x150));
        func_021BB9CC((int)p,W(0x150),0,(u16)v);
        func_021B9788(p,0x34,1,(int)func_021B9E44);
        func_021BB98C(p,W(0x150));
        break;
    case 28:func_021BCC40((int)p,0x31);break;
    }
    return n;
}






void func_021BC548(int p)
{
    u16 h;
    u16 v;
    h = func_021BB464(p, (short unsigned int *)(*(int *)(p + ((struct Obj03682 *)p)->f2C * 4 + 0x160)));
    *(int *)(((struct Obj03682 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, ((struct Obj03682 *)p)->f150);
    func_021BB99C(p, ((struct Obj03682 *)p)->f150, 0, ((struct Obj03682 *)p)->f38);
    v = ((struct Obj03682 *)p)->f11C;
    if (v != 0) {
        func_021BB9EC(p, ((struct Obj03682 *)p)->f150, 1, (u16)(h - v), (int)3);
        func_021B9788((u8 *)p, 0x2c, 1, (int)func_021B9E44);
    } else {
        func_021B9788((u8 *)p, 0x32, 1, (int)func_021B9E44);
    }
    func_021BB98C((void *)p, ((struct Obj03682 *)p)->f150);
}






void func_021BC5CC(int p)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB99C(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(int *)&((struct Obj00009 *)p)->f38);
    if (func_021BC1D0((P *)p) != -1) {
        func_021B9788((u8 *)p, 0x32, 1, (int)func_021BC628);
    } else {
        func_021B9788((u8 *)p, 0x32, 1, (int)func_021B9E3C);
    }
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}


#undef S

#undef S

#define S ((u8 *)W(0x280))


#undef W

#undef W


#define W(k) (*(u32 *)(p+(k)))


#undef H

#undef H

#define H(k) (*(u16 *)(p+(k)))





void func_021BC628(int p)
{
    int n = func_021BC1D0((P *)p);
    func_021BB7A4((void *)p, (u32 *)(*(int *)&((struct Obj00009 *)p)->f150));
    func_021BB050(p, (u8 *)(*(int *)(p + ((struct Obj00009 *)p)->f2C * 4 + 0x160)), 3);
    ((struct Obj00009 *)p)->f2C = n;
    *(int *)&((struct Obj00009 *)p)->f38 = (int)func_0201AB28(**(void ** *)&((struct Obj00009 *)p)->f280, n);
    func_021BC350((u8 *)p, 0);
    func_021BE2B4((void *)(*(int *)&((struct Obj00009 *)p)->f38),
                  *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44), 0,
                  *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x30), ((struct Obj00009 *)p)->f0);
    func_021BB2C0((u8 *)p, (u8 *)(*(int *)(p + ((struct Obj00009 *)p)->f2C * 4 + 0x160)));
    func_020061E4(0x56f);
}





void func_021BC6A0(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 0;
    *(int *)(((struct Obj07736 *)p)->f280 + 0x50) = 0;
    func_021BBA70((int)p, ((struct Obj07736 *)p)->f150);
}





void func_021BC6C0(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 6;
}




void func_021BC6CC(u8 *p)
{
    u8 i,j,x;
    u32 q,result,off;
    switch(p[0xe]) {
    case 0: {
        u8 flag;
        u32 delta,buf,tmp,text;
        int y;
        u16 width;
        flag=0;
        W(0x130)=func_020450F0((int)0, (u8)1, (u8)1, (int)14, 12, 14, 1);
        func_0201F73C((void *)W(0x130),1,1,12);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)W(0x130))),15);
        q=W(0x130); func_02045334((struct Descriptor *)q); func_02045374((struct Cfg *)q); func_02041B6C(func_02045730((struct Descriptor *)q));
        for(i=0;i<6;i++) {
            off=i; off=off*2;
            delta=func_02017E1C((void *)W(0x38),*(u16 *)((u8 *)d_021BECE4+off),0)-*(u16 *)(p+off+0x124);
            if(delta>=10) flag=1;
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),i+0x95); y=i<<4;
            func_0201C724((void *)W(0x140),(u32)func_02045770((struct Descriptor *)W(0x130)),0,(s16_021BC628)(i<<4),buf,W(0x138),0x440);
            func_02045808((struct U16Vec *)buf);
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9c); tmp=(u32)func_020457B0(0x20,H(0)); text=(u32)func_0201EC64(H(0));
            func_0201EFA4((struct WordSet *)text,0,delta,3,0,1); func_0201F250((struct WordSet *)text,(void *)tmp,(void *)buf);
            width=func_0201D304((struct StrObj *)tmp,W(0x138),0);
            func_0201C724((void *)W(0x140),(u32)func_02045770((struct Descriptor *)W(0x130)),(s16_021BC628)(104-width),(s16_021BC628)y,tmp,W(0x138),0x440);
            func_02045808((struct U16Vec *)buf); func_02045808((struct U16Vec *)tmp); func_0201ED04((struct WordSet *)text);
        }
        for(j=0;j<6;j++) {
            x=flag==1 ? 72 : 80;
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9b);
            func_0201C724((void *)W(0x140),(u32)func_02045770((struct Descriptor *)W(0x130)),x,(s16_021BC628)(j<<4),buf,W(0x138),0x440);
            func_02045808((struct U16Vec *)buf);
        }
        p[0xe]=1; break;
    }
    case 1:
        if(func_0201C6C4((struct PrintSys *)W(0x140),(void *)((u32)func_02045770((struct Descriptor *)W(0x130))))==0) {
            q=W(0x130); func_02045334((struct Descriptor *)q); func_02045374((struct Cfg *)q); func_02041B6C(func_02045730((struct Descriptor *)q)); p[0xe]=2;
        } break;
    case 2:
        if((func_020362DC()&1)||(func_020362DC()&2)||func_02035C60()==1) { func_020061E4(0x547); p[0xe]=3; }
        break;
    case 3: {
        u16 width;
        u32 delta,buf,tmp,text;
        func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)W(0x130))),0x50,0,0x20,0x60,15);
        for(i=0;i<6;i++) {
            delta=func_02017E1C((void *)W(0x38),d_021BECE4[i],0);
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9c); tmp=(u32)func_020457B0(0x20,H(0)); text=(u32)func_0201EC64(H(0));
            func_0201EFA4((struct WordSet *)text,0,delta,3,0,1); func_0201F250((struct WordSet *)text,(void *)tmp,(void *)buf);
            width=func_0201D304((struct StrObj *)tmp,W(0x138),0);
            func_0201C724((void *)W(0x140),(u32)func_02045770((struct Descriptor *)W(0x130)),(s16_021BC628)(104-width),(s16_021BC628)(i<<4),tmp,W(0x138),0x440);
            func_02045808((struct U16Vec *)buf); func_02045808((struct U16Vec *)tmp); func_0201ED04((struct WordSet *)text);
        }
        p[0xe]=4; break;
    }
    case 4:
        if(func_0201C6C4((struct PrintSys *)W(0x140),(void *)((u32)func_02045770((struct Descriptor *)W(0x130))))==0) {
            q=W(0x130); func_02045334((struct Descriptor *)q); func_02045374((struct Cfg *)q); func_02041B6C(func_02045730((struct Descriptor *)q)); p[0xe]=5;
        } break;
    case 5:
        if((func_020362DC()&1)||(func_020362DC()&2)||func_02035C60()==1) {
            p[0xe]=6; func_020061E4(0x547); func_020456F8((struct Descriptor *)W(0x130)); func_0201F7A8((void *)W(0x130),1); func_020452E8((struct Descriptor *)W(0x130)); W(0x130)=0;
        } break;
    case 6:
        result=func_02018328((void *)W(0x38),(u32 *)(S+0x50),H(0)); func_021BB7A4(p,(u32 *)W(0x150));
        if(result==0) { p[0xe]=7; return; }
        if(result==0xfffe) { p[0xe]=7; return; }
        if(result&0x8000) {
            *(u16 *)(S+0x46)=result-0x8000;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,*(u16 *)(S+0x46));
            func_021B9788(p,0x20,0,(int)func_021B9EB0); func_021BB98C(p,W(0x150));
        } else {
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,result);
            func_021B9788(p,0x29,1,(int)func_021BC6C0); func_021BB98C(p,W(0x150));
        } break;
    case 7:
        func_02017E1C((void *)W(0x38),5,0);
        if(func_0201B2B0((void *)T(0),(void *)W(0x38),0,*(u16 *)(S+0x30),S[0x5f],0,H(0))!=0) {
            p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=9;
        } else {
            T(0x34)=5; T(0x3c)=W(0x2c); T(0x40)=10; func_021B9E44(p);
        } break;
    }
}




int func_021BCC2C(void *p, int i, int a2) { int r = 0; if (func_02017E1C(p,i,0)) r=1; return r; }





void func_021BCC40(int p, int id)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB99C(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(int *)&((struct Obj00009 *)p)->f38);
    func_021B9788((u8 *)p, id, 1, (int)func_021B9E44);
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}





void func_021BCC80(int p, int id, int v)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB99C(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(int *)&((struct Obj00009 *)p)->f38);
    func_021BB9DC(p, *(int *)&((struct Obj00009 *)p)->f150, 1, v);
    func_021B9788((u8 *)p, id, 1, (int)func_021B9E44);
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}





void func_021BCCCC(int p)
{
    int r;
    func_021BCE84((char *)p);
    func_021BCEAC((u8 *)p);
    r = ((struct Obj00047 *)p)->f280;
    if (((struct Obj07737 *)r)->f8C == 1) {
        switch (((struct Obj07737 *)r)->f64) {
        case 1:
            ((struct Obj00047 *)p)->f1F4 = (int)func_021BD05C((u8 *)p, (u32 *)(r + 0x74), 10, 0, 2);
            break;
        case 2:
            ((struct Obj00047 *)p)->f1F0 = (int)func_021BD05C((u8 *)p, (u32 *)(r + 0x68), 0, 0, 0);
            ((struct Obj00047 *)p)->f1F4 = (int)func_021BD05C((u8 *)p, (u32 *)(((struct Obj00047 *)p)->f280 + 0x74), 0xb, 0, 0);
            ((struct Obj00047 *)p)->f1F8 = (int)func_021BD05C((u8 *)p, (u32 *)(((struct Obj00047 *)p)->f280 + 0x80), 0x16, 0, 0);
            break;
        }
    }
    r = ((struct Obj00047 *)p)->f280;
    ((struct Obj00047 *)p)->f20C = ((struct Obj07737 *)r)->f94;
    ((struct Obj00047 *)p)->f20D = 0;
    if (((struct Obj07737 *)r)->f90 == 1) {
        func_021BD59C((char *)p);
    }
    ((struct Obj00047 *)p)->f24E = 0;
}





void func_021BCD80(char *a)
{
    if (((struct Obj20910 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f90 == 1)
        func_021BD61C(a);
    if (((struct Obj20911 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f8C == 1) {
        switch (((struct Obj20912 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f64) {
        case 1:
            func_021BD18C(a, (char *)(((struct Obj01888 *)a)->f1F4));
            break;
        case 2:
            func_021BD18C(a, (char *)(((struct Obj01888 *)a)->f1F0));
            func_021BD18C(a, (char *)(((struct Obj01888 *)a)->f1F4));
            func_021BD18C(a, (char *)(((struct Obj01888 *)a)->f1F8));
            break;
        }
    }
    func_021BD058(a);
    func_021BCE9C((unsigned int)a);
}





void func_021BCDE8(char *a)
{
    if (((struct Obj20913 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f8C == 1) {
        switch (((struct Obj20914 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f64) {
        case 1:
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F4));
            break;
        case 2:
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F0));
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F4));
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F8));
            break;
        }
    }
    if (((struct Obj00009 *)a)->f20C != ((struct Obj20915 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 && ((struct Obj00009 *)a)->fC == 2) {
        func_021BD504(a);
        ((struct Obj00009 *)a)->f20C = ((struct Obj20916 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94;
    }
    if (((struct Obj20917 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f90 == 1)
        func_021BD634((u8 *)a);
    if (((struct Obj20918 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f63 == 1)
        func_021BA4F8((u8 *)a);
}




void func_021BCE84(char *p) { *(struct Bank * *)&((struct Obj13261 *)p)->f1EC=func_0204B100(36,8,((struct Obj13261 *)p)->f0); }




void func_021BCE9C(unsigned int p) { func_0204B1CC((struct Bank *)(((struct Obj20919 *)p)->f1EC)); }



#undef H


#undef H

#undef H

#define H (*(u16 *)p)



#undef W


#undef W

#undef W
#define W(o) (*(u32 *)(p + (o)))




void func_021BCEAC(u8 *p)
{
    void *h, *h2;
    h = func_020490F4(0x4c, H);
    func_02049BDC((void *)((u32)h), 1, 4, 0x20, 0x20, 0x20, H);
    func_02049B68(h, 0, 4, 0x1a0, 0x20, H);
    func_02049658((void *)((u32)h), 9, 6, 0, 0, 0, H);
    if (F(0x8c) == 1) {
        switch (F(0x64)) {
        case 1: func_020498F4((void *)((u32)h), 0x11, 6, 0, 0, 0, H); break;
        case 2: func_020498F4((void *)((u32)h), 0x10, 6, 0, 0, 0, H); break;
        }
    }
    func_02049238(h);
    h2 = func_020490F4(func_020275E4(), H);
    W(0x184) = func_0204ABF0((void *)h, func_02027694(), 1, 0x60, H);
    W(0x1a8) = func_0204A6C8((void *)((u32)h), func_02027698(), 0, 1, H);
    W(0x1c4) = func_0204AF28((void *)((u32)h), func_0202769C(2), func_020276A0(2), H);
    if (F(0x90) == 1) {
        func_02049B68(h, func_02027624(), 4, 0x40, 0x20, H);
        func_02049658((void *)((u32)h), func_02027628(), 5, 0, 0, 0, H);
        func_020498F4((void *)((u32)h), func_0202762C(), 5, 0, 0, 0, H);
        func_020413B0(5, 0, 0, 0x20, 0x20, 2);
        func_02041B6C(5);
    }
    func_02049238(h2);
    h = func_020490F4(7, H);
    W(0x194) = func_0204ACEC((void *)((u32)h), func_0201BC3C(), 1, 0xc0, H);
    func_02049238(h);
    func_02082A60((void *)0x05000440, p + 0x20e, 0x20);
}




/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void func_021BD058(char *a)
{
}





u32 *func_021BD05C(u8 *p, u32 *list, u8 x, u8 y, u8 w)
{
    u32 *r;
    u8 n;
    u8 i;
    u32 bmp;
    u32 flag;

    r = (u32 *)func_02030734(*(u16 *)p, 0x20, 0, d_021BED48, 0x143);
    n = func_0201AA18((void *)list[0]);
    for (i = 0; i < 6; i++) {
        if (i < n) {
            int par = i % 2;
            u8 xx = x + par * (w + 5);
            u8 yy = y + (i / 2) * 6 + 4;
            int col = 4;
            if (par != 0) col = 0;
            r[2 + i] = (u32)func_021BD218(p, func_0201AB28((void *)list[0], i), (u8)((u8)col + (xx << 3)), (u8)(yy << 3));
        } else {
            r[2 + i] = 0;
        }
    }
    flag = 1;
    r[1] = func_020450F0((int)4, (u8)(x + 1 + ((u32)w >> 1)), (u8)(y + 1), (int)10, 2, 0xe, flag);
    bmp = (u32)func_020457B0(0x10, *(u16 *)p);
    func_02045924((struct Strbuf *)bmp, (const u16 *)list[1]);
    func_0201C724((void *)(*(u32 *)(p + 0x140)), (u32)func_02045770((struct Descriptor *)r[1]), 0, 0, bmp, *(u32 *)(p + 0x138), 0x3c40);
    func_02045808((struct U16Vec *)bmp);
    r[0] = flag;
    return r;
}




void func_021BD18C(char *a,char *p) { u8 i; for(i=0;i<6;i++) { char *q=*(char **)(p+i*4+8); if(q)func_021BD454(a,q); } func_020452E8(*(struct Descriptor * *)&((struct Obj20920 *)p)->f4); func_020307B0(p); }





void func_021BD1BC(char *a, int *b)
{
    u8 i;
    int q;
    for (i = 0; i < 6; i++) {
        if (b[2 + i] != 0)
            func_021BD480(a, (int *)b[2 + i]);
    }
    if (b[0] == 1 && func_0201C6C4((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)func_02045770((struct Descriptor *)b[1])) == 0) {
        q = b[1];
        b[0] = 0;
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)q);
        func_02041B6C(func_02045730((struct Descriptor *)q));
    }
}

#undef H

#define H(k) (*(u16 *)(p+(k)))

#undef T
#define T (*(u16 *)((u8 *)P(0x280)+0x60))

#undef P




#define P(k) (*(u32 *)(p+(k)))





/*
 * lever: u16 y pins x's front spill; declare the u8 offset before gx to restore r7/r6 allocation.
 */
u32 *func_021BD218(u8 *p,void *mon,s16 x,u16 y)
{
    R a;
    R b;
    u32 *s;
    void *h;
    int species;
    int frame;
    u32 gender;
    u32 special;
    int level;
    int egg;
    int rem;
    u8 z;
    int gx;
    u32 gy;
    u32 text;
    s=func_02030734(((struct Obj02771 *)p)->f0,24,0,d_021BED48,0x199);
    egg=func_02017E1C(mon,0x4c,0);
    h=func_020490F4(7,((struct Obj02771 *)p)->f0);
    species=(int)func_020185F4(mon);
    s[3]=func_0204A6C8(h,func_0201BA68((void *)species),0,1,((struct Obj02771 *)p)->f0);
    func_02049238(h);
    frame=func_0201BBE8((void *)species);
    a.a=x+16;a.b=y+8;a.c=1;a.d=16;a.e=2;
    {
        int obj=(int)func_0204B294((void *)P(0x1ec),s[3],P(0x194),P(0x1d0),&a,1,((struct Obj02771 *)p)->f0);
        s[4]=obj;
        func_0204B6F4((struct Obj *)obj,frame,1);
    }
    func_0204B92C((struct Obj *)s[4],1);
    gender=func_02017E1C(mon,6,0);
    b.a=x+32;b.b=y+16;b.c=0;b.d=8;b.e=2;
    s[5]=(u32)func_0204B294((void *)P(0x1ec),P(0x1a8),P(0x184),P(0x1c4),&b,1,((struct Obj02771 *)p)->f0);
    if(gender!=0) {
        func_0204B3DC((struct Obj *)s[5],1);
        if(func_0202136C(gender)==1) func_0204B878((struct Obj *)s[5],1);
        else func_0204B878((struct Obj *)s[5],0);
    } else func_0204B3DC((struct Obj *)s[5],0);
    special=func_02017E1C(mon,0x6e,0);
    rem=x%8;
    z=rem;
    gy=(u32)y>>3;
    gx=(u32)x>>3;
    s[1]=func_020450F0(4, (u8)gx+3, gy, 3, 2, 13, 1);
    if(egg==0) {
        if(special==0) func_021B9C1C(p,s[1],7,(u16)(z+4),0,0x14c0);
        else if(special==1) func_021B9C1C(p,s[1],8,(u16)(z+4),0,0xc80);
    }
    level=func_02018430((void *)((int)mon));
    z=rem;
    s[2]=func_020450F0(4, (u8)gx, (u8)gy+3, 6, 1, 14, 1);
    if(egg==0) {
        text=(u32)func_0201EC64(((struct Obj02771 *)p)->f0);
        func_0201EFA4((struct WordSet *)text,0,level,3,0,1);
        func_021B9D58(p, s[2], (void *)text, 2, (s16_021B9C64)z, (s16_021B9C64)0, 0x3c40);
        func_0201ED04((struct WordSet *)text);
    }
    s[0]=1;
    return s;
}





void func_021BD454(char *unused,char *p) { func_020452E8(*(struct Descriptor * *)&((struct Obj06214 *)p)->f4); func_020452E8(*(struct Descriptor * *)&((struct Obj06214 *)p)->f8); func_0204B3B4(*(struct Obj * *)&((struct Obj06214 *)p)->f14); func_0204B3B4(*(struct Obj * *)&((struct Obj06214 *)p)->f10); func_0204A8D4(((struct Obj06214 *)p)->fC); func_020307B0(p); }






void func_021BD480(char *a, int *b)
{
    int q;
    if (b[0] == 1
        && func_0201C6C4((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)func_02045770((struct Descriptor *)b[1])) == 0
        && func_0201C6C4((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)func_02045770((struct Descriptor *)b[2])) == 0) {
        q = b[1];
        b[0] = 0;
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)q);
        func_02041B6C(func_02045730((struct Descriptor *)q));
        q = b[2];
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)q);
        func_02041B6C(func_02045730((struct Descriptor *)q));
    }
}





void func_021BD4EC(char *p) { func_021BD504(p); ((struct Obj00009 *)p)->f20C=((struct Obj20921 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f94; }






void func_021BD504(char *a)
{
    int t;
    if (((struct Obj20922 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 == 0)
        return;
    if (func_021BB7D8(a, *(int *)&((struct Obj00009 *)a)->f150) == 0)
        func_021BB714(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), 1);
    if (((struct Obj20923 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f64 == 1) {
        t = (int)func_020457B0(0x10, ((struct Obj00009 *)a)->f0);
        func_02045924((struct Strbuf *)t, (const u16 *)(((struct Obj20924 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f78));
        func_021BB97C((u16 *)a, *(int *)&((struct Obj00009 *)a)->f150);
        func_021BBA0C((int)a, *(int *)&((struct Obj00009 *)a)->f150, 0, (const void *)t, ((struct Obj20925 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f7C);
        func_021BB7E8((u8 *)a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), 0xA9);
        func_021BB98C(a, *(int *)&((struct Obj00009 *)a)->f150);
        func_02045808((struct U16Vec *)t);
    } else {
        func_021BB7E8((u8 *)a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), ((struct Obj20926 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 + 0xA9);
    }
}




#undef P



#undef P


#undef P

#undef P

#define P(k) (*(void **)(p+(k)))






void func_021BD59C(char *p)
{
    int s;
    ((struct Obj04353 *)p)->f1FC = func_020450F0(4, 7, 0x15, 0xB, 3, 0xE, 1);
    ((struct Obj04353 *)p)->f200 = func_020450F0(4, 0x14, 0x15, 5, 3, 0xE, 1);
    s = (int)func_02045EC0((struct MsgBank *)(((struct Obj04353 *)p)->f134), 0xAD);
    func_0201C724((void *)(((struct Obj04353 *)p)->f140), (int)func_02045770((struct Descriptor *)((struct Obj04353 *)p)->f1FC), 0, 4, s,
                  ((struct Obj04353 *)p)->f138, 0x3C40);
    func_02045808((struct U16Vec *)s);
    ((struct Obj04353 *)p)->f204 = 1;
}





void func_021BD61C(char *p) { func_020452E8(*(struct Descriptor * *)&((struct Obj13262 *)p)->f1FC); func_020452E8(*(struct Descriptor * *)&((struct Obj13262 *)p)->f200); }

#undef W




#define W(k) (*(u32 *)(p+(k)))





/*
 * note: minute and second are u8 locals: widening the explicit byte casts
 *   to u32 keeps the size but moves the text spill before outgoing stores.
 */
void func_021BD634(u8 *p)
{
    u32 width;
    u8 minute;
    u8 second;
    void *text;
    struct U16Vec *buf;
    struct WordSet *words;
    u16 timer;
    struct Descriptor *window;
    u8 amount;
    u8 i;
    u8 red;
    u8 green;
    u8 blue;
    u16 color;
    int value;
    timer=T;
    if(p[0x20d]!=timer) {
        minute=(u8)(timer/60);
        second=(u8)(timer%60);
        buf=func_020457B0(32,H(0));
        words=func_0201EC64(H(0));
        if(minute==0) {
            text=func_02045EC0(P(0x134),175);
            func_0201EFA4(words,1,second,2,1,1);
        } else {
            text=func_02045EC0(P(0x134),174);
            func_0201EFA4(words,0,minute,2,1,1);
            func_0201EFA4(words,1,second,2,2,1);
        }
        func_02043B5C(func_02045770(P(0x200)),0);
        func_0201F250(words,buf,text);
        width=func_0201D304((struct StrObj *)buf,W(0x138),0);
        func_0201C724(P(0x140),(u32)func_02045770(P(0x200)),(s16_021BD634)(36-width),4,(u32)buf,W(0x138),0x3c40);
        func_0201ED04(words);
        func_02045808(buf);
        func_02045808(text);
        W(0x208)=1;
        p[0x20d]=T;
    }
    if(T==0) func_021BA4F8(p);
    if(W(0x208)==1) {
        if(func_0201C6C4(P(0x140),func_02045770(P(0x200)))==0) {
            W(0x208)=0;
            window=P(0x200);
            func_02045334(window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730(window));
        }
    }
    if(W(0x204)==1) {
        if(func_0201C6C4(P(0x140),func_02045770(P(0x1fc)))==0) {
            W(0x204)=0;
            window=P(0x1fc);
            func_02045334(window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730(window));
        }
    }
    if(T<=10) {
        amount=(d_020A1B38[(((H(0x24e)<<16)/60)>>4)*2+1]+4096)*32/8192;
        for(i=0;i<16;i++) {
            color=*(u16 *)(p+(u32)i*2+0x20e);
            green=(color&0x3e0)>>5;
            blue=(color&0x7c00)>>10;
            red=color&31;
            value=red+amount;
            if(value>31) value=31;
            red=value;
            *(u16 *)(p+(u32)i*2+0x22e)=(blue<<10)|(red|(green<<5));
        }
        func_02061CA4((void *)31,64,(u32)(p+0x22e),32);
        H(0x24e)++;
        if(H(0x24e)>=60) H(0x24e)=0;
    }
}





void func_021BD8B0(char *p) { ((struct Obj00009 *)p)->f268=0; ((struct Obj00009 *)p)->f26C=0; ((struct Obj00009 *)p)->f270=0; func_02040588(0,0); func_021B7034(p); func_021B6F28(p); func_021BDABC((u8 *)p); p[12]=15; }





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(o) (*(u32 *)(p+(o)))





void func_021BD8E4(u8 *p)
{
    void (*cb)(u8 *);
    func_021BDBE0((unsigned int)p);
    func_021B7040((unsigned int)p);
    func_021B6F0C(p);
    func_021BBA54((short unsigned int *)p,W(0x150));
    if (W(0x264) == 1) {
        cb = (void (*)(u8 *))func_021B9E3C;
        if (*(u32 *)(W(0x280)+0x34) == 0) cb = func_021B9E20;
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)cb);
        func_021BB98C(p,W(0x150));
    } else if (W(0x264) == 2) {
        cb = (void (*)(u8 *))func_021B9E3C;
        if (*(u32 *)(W(0x280)+0x34) == 0) cb = func_021B9E20;
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)cb);
        func_021BB98C(p,W(0x150));
    } else if (W(0x264) == 3) {
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)func_021B9E3C);
        func_021BB98C(p,W(0x150));
    } else {
        p[0xc] = 0x13;
    }
}





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(o) (*(u32 *)(p+(o)))





/*
 *   unsigned int func_02051614(unsigned int **p) { return (*p)[2]; }
 */
void func_021BD9C8(u8 *p)
{
    u32 species,form;
    if (W(0x26c) == 0) {
        p[0x268]++;
        if (p[0x268] == 1) {
            func_02040588(0,1);
            if (W(0x264)-1 <= 1) func_020061E4(0x643);
            else if (W(0x264) == 3) func_020061E4(0x644);
        }
        if (p[0x268] > p[0x269]) {
            func_021BB200(p,*(u8 **)(p+W(0x2c)*4+0x160),W(0x38),0);
            W(0x26c) = 1;
        }
    }
    if (func_02051614((int **)W(0x260)) <= 0 && func_02006238() == 0) {
        if (W(0x270) == 0) {
            species = func_02017E1C((void *)W(0x38),5,0);
            form = func_02017E1C((void *)W(0x38),0x6f,0);
            W(0x274) = func_02006984(species,form,0x40,0,0,0,0,0);
            W(0x270) = 1;
        } else {
            if (func_02006BD0(W(0x274)) == 0) p[0xc] = 0x10;
        }
    }
    func_02051574();
    func_02047964();
    func_020479D8();
    func_02051534();
    func_02047970();
}





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(o) (*(u32 *)(p+(o)))





/*
 * lever: two-halfword coordinate struct keeps its address sp-relative; int alias added 4 B.
 */
void func_021BDABC(u8 *p)
{
    u8 count;
    int member;
    int handle;
    Pair_021BD218 xy;
    int vec[3];
    u8 i;
    count = 0;
    member = 0x1c;
    if (W(0x264)-1 <= 1) {
        member = 0x1b;
        count = 3;
        p[0x269] = 0x41;
    } else if (W(0x264) == 3) {
        count = 2;
        p[0x269] = 0x26;
    }
    handle = func_0205121C(0x4c,member,((struct Obj06215 *)p)->f0);
    W(0x25c) = (u32)func_0203D7C8(((struct Obj06215 *)p)->f0,0x5000,(const char *)d_021BED58,0xea);
    W(0x260) = func_02050C04(W(0x25c),0x5000,0,((struct Obj06215 *)p)->f0);
    func_02051230((u8 *)W(0x260),handle,0,func_020056BC());
    func_021BB3D4(p,(u8 *)(*(int *)(p+W(0x2c)*4+0x160)),(u16 *)(&xy));
    xy.x -= 0x28;
    xy.y += 4;
    if (xy.x > 0) vec[0] = (int)(0.5f+(float)(xy.x<<12))/0x26;
    else vec[0] = (int)((float)(xy.x<<12)-0.5f)/0x26;
    if (xy.y > 0) vec[1] = (int)(0.5f+(float)(xy.y<<12))/0x26;
    else vec[1] = (int)((float)(xy.y<<12)-0.5f)/0x26;
    vec[2] = 0x40000;
    for (i=0;i<count;i++) func_020515B4((void *)W(0x260),i,(int)vec);
}





void func_021BDBE0(unsigned int p)
{
    func_02050DB8(*(u8 * *)&((struct Obj09935 *)p)->f260);
    func_0203D7FC(((struct Obj09935 *)p)->f25C);
}






int func_021BDBF8(char *p, void *q)
{
    int r = 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 5, 0) != 0x1E7)
        return 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 6, r) != 0x70)
        return 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 0x6F, r) == 0)
        r = 1;
    return r;
}





/*
 * Extent tail: two bytes of alignment padding at 0x021BDC5A.
 */
void func_021BDC3C(u32 p, void *m)
{
    func_02017988(m, 1);
    func_0200CDE0(*(struct Blk37 **)(((struct Obj20927 *)p)->f280 + 0x18), m);
}





int func_021BDC5C(char *p, void *q)
{
    int r = 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 6, 0) == 0x70)
        return 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 5, r) != 0x1E7)
        return 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 0x6F, r) == 1)
        r = 1;
    return r;
}




/*
 * Extent tail: two bytes of alignment padding at 0x021BDCBE.
 */
void func_021BDCA0(u32 p, void *m)
{
    func_02017988(m, 0);
    func_0200CDE0(*(struct Blk37 **)(((struct Obj20928 *)p)->f280 + 0x18), m);
}





int func_021BDCC0(char *p, u32 a1)
{
    u32 t[3];
    u32 lo, hi;
    int r = 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 5, 0) != 0x1EC)
        return r;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 0x6F, r) != 0)
        return r;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 0x6D, r) != 1)
        return r;
    if (func_02017F90(((struct Obj00009 *)p)->f38) & 0x20)
        return r;
    lo = func_02011400(((struct Obj20929 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f5F, r);
    hi = func_02011400(((struct Obj20930 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f5F, 3);
    func_0203F4CC((struct RtcTime *)t);
    if (t[0] < lo || t[0] >= hi)
        return 0;
    return 1;
}




void func_021BDD58(u32 p, void *m)
{
    func_02017988(m, 1);
    func_0200CDE0(*(struct Blk37 **)(((struct Obj20931 *)p)->f280 + 0x18), m);
}




int func_021BDD78(void *a, u32 id, int slot, u32 heap)
{
  void *p;
  u32 r;
  u32 sex;
  u32 hp;
  int i;
  long s1;
  long s2;
  long s3;
  long s4;
  long s5;
  long s0;
  int flag;
  int v;
  int tmp;
  p = func_02020F34(id, 0, (u16)heap);
  r = 0;
  if (func_02021014(p, 14) != 1)
  {
    func_020307B0(p);
    return r;
  }
  ;
  sex = func_02017F90(a);
  if ((func_02021014(p, 18) != 0) && (sex == 2))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((func_02021014(p, 19) != 0) && (sex == 5))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((func_02021014(p, 20) != 0) && (sex == 4))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((func_02021014(p, 21) != 0) && (sex == 3))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((func_02021014(p, 22) != 0) && (sex == 1))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  hp = func_02017E1C(a, 0xA0, 0);
  if (((func_02021014(p, 26) != 0) || (func_02021014(p, 27) != 0)) && (func_02021014(p, 28) == 0))
  {
    if (hp == 0)
    {
      func_020307B0(p);
      return 1;
    }
    ;
  }
  else
    if (((func_02021014(p, 41) != 0) && (hp != 0)) && (hp < func_02017E1C(a, 0xA1, 0)))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((func_02021014(p, 28) != 0) && (func_02017E1C(a, 0x9E, 0) < 100))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((func_02021014(p, 37) != 0) || (func_02021014(p, 38) != 0))
  {
    r = 0;
    if ((func_02017E1C(a, slot + 0x3E, 0) < 3) && (func_0201C158((u16) func_02017E1C(a, slot + 0x36, 0), r) >= 5))
    {
      func_020307B0(p);
      return 1;
    }
    ;
  }
  if ((func_02021014(p, 39) != 0) && (func_0201B920(a, slot) == 1))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if (func_02021014(p, 40) != 0)
  {
    for (i = 0; i < 4; i++)
    {
      if (func_0201B920(a, i) == 1)
      {
        func_020307B0(p);
        return 1;
      }
      ;
    }

  }
  s0 = func_02017E1C(a, 13, 0);
  s1 = func_02017E1C(a, 14, 0);
  s2 = func_02017E1C(a, 15, 0);
  s3 = func_02017E1C(a, 16, 0);
  s4 = func_02017E1C(a, 17, 0);
  s5 = func_02017E1C(a, 18, 0);
  flag = func_02021014(p, 48);
  if (func_02017E1C(a, 5, 0) != 0x124)
    if (func_02021014(p, 42) != 0)
  {
    v = func_02021014(p, 52);
    if (v > 0)
    {
      if ((((s0 < 100) || (flag != 0)) && (s0 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s0 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (func_021BE9BC(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (func_02021014(p, 43) != 0)
  {
    v = func_02021014(p, 53);
    if (v > 0)
    {
      if ((((s1 < 100) || (flag != 0)) && (s1 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s1 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (func_021BE9BC(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (func_02021014(p, 44) != 0)
  {
    v = func_02021014(p, 54);
    if (v > 0)
    {
      if ((((s2 < 100) || (flag != 0)) && (s2 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s2 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (func_021BE9BC(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (func_02021014(p, 45) != 0)
  {
    v = func_02021014(p, 55);
    if (v > 0)
    {
      if ((((s3 < 100) || (flag != 0)) && (s3 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s3 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (func_021BE9BC(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (func_02021014(p, 46) != 0)
  {
    v = func_02021014(p, 56);
    if (v > 0)
    {
      if ((((s4 < 100) || (flag != 0)) && (s4 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s4 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (func_021BE9BC(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (func_02021014(p, 47) != 0)
  {
    v = func_02021014(p, 57);
    tmp = v > 0;
    if (tmp)
    {
      if ((((s5 < 100) || (flag != 0)) && (s5 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s5 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (func_021BE9BC(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  {
    func_020307B0(p);
    return 0;
  }
  ;
}



/*
 * levers: wave 82 R12. Real callee prototypes (02020F34 heap u32, 021BEA48 first int)
 *   with the caller-side (u16)heap narrowing the listing shows before 02020F34; item and
 *   moveSlot are u16 parameters (callers pass ldrh values / constant 0). u16 item
 *   fixed 31 of 35 bytes (spill reloads of item), u16 or u8 moveSlot the last 4 (r2 spill
 *   order); u16 chosen with item/arg, no byte evidence between u16 and u8.
 */
int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap)
{
    void *rec;
    int changed = 0;
    int applicable;
    int originalStatus, status, spa, spd, allowAbove100, amount;
    int hpStat, hp, atk, maxHp, def, speed, level, oldLevel, result, i;
    rec = func_02020F34(item, 0, (u16)heap);
    if (func_02021014(rec, 14) != 1) { func_020307B0(rec); return changed; }
    applicable = 0;
    originalStatus = func_02017E1C(mon, 157, 0);
    status = originalStatus;
    if (func_02021014(rec, 18)) { status = 0; applicable = 1; }
    if (func_02021014(rec, 19)) { status = 0; applicable = 1; }
    if (func_02021014(rec, 20)) { status = 0; applicable = 1; }
    if (func_02021014(rec, 21)) { status = 0; applicable = 1; }
    if (func_02021014(rec, 22)) { status = 0; applicable = 1; }
    if (originalStatus != status) { func_02017E40(mon, 157, status); changed = 1; }
    hp = func_02017E1C(mon, 160, 0);
    maxHp = func_02017E1C(mon, 161, 0);
    if ((func_02021014(rec, 26) || func_02021014(rec, 27)) && !func_02021014(rec, 28)) {
        if (hp == 0) {
            func_021BE914(mon, hp, maxHp, func_02021014(rec, 58));
            changed = 1;
        }
        applicable = 1;
    } else if (func_02021014(rec, 41)) {
        if (hp < maxHp) { func_021BE914(mon, hp, maxHp, func_02021014(rec, 58)); changed = 1; }
        applicable = 1;
    }
    level = func_02017E1C(mon, 158, 0);
    if (func_02021014(rec, 28)) {
        if (level < 100) {
            i = func_02017E1C(mon, 5, 0);
            result = func_02017E1C(mon, 111, 0);
            func_02017E40(mon, 8, func_02018584(i, result, level + 1));
            func_020185C4(mon);
            if (hp == 0) {
                result = func_02017E1C(mon, 161, 0);
                func_021BE914(mon, hp, result, result - maxHp);
            }
            changed = 1;
        }
        applicable = 1;
    }
    if (func_02021014(rec, 29)) applicable = 1;
    if (func_02021014(rec, 37)) {
        applicable = 1;
        if (func_021BE874(mon, moveSlot, 1) == 1) changed = 1;
        applicable = 1;
    } else if (func_02021014(rec, 38)) {
        if (func_021BE874(mon, moveSlot, 3) == 1) changed = 1;
        applicable = 1;
    }
    if (func_02021014(rec, 39)) {
        if (func_0201B970(mon, moveSlot, func_02021014(rec, 59)) == 1) changed = 1;
        applicable = 1;
    } else if (func_02021014(rec, 40)) {
        for (i = 0; i < 4; i++) if (func_0201B970(mon, i, func_02021014(rec, 59)) == 1) changed = 1;
        applicable = 1;
    }
    hpStat = func_02017E1C(mon, 13, 0);
    atk = func_02017E1C(mon, 14, 0);
    def = func_02017E1C(mon, 15, 0);
    speed = func_02017E1C(mon, 16, 0);
    spa = func_02017E1C(mon, 17, 0);
    spd = func_02017E1C(mon, 18, 0);
    allowAbove100 = func_02021014(rec, 48);
    if (func_02017E1C(mon, 5, 0) != 292 && func_02021014(rec, 42)) {
        amount = func_02021014(rec, 52);
        result = func_021BE948(hpStat, spd + (spa + (speed + (atk + def))), amount, allowAbove100);
        if (result != -1) { hpStat = result; func_02017E40(mon, 13, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 43)) {
        amount = func_02021014(rec, 53);
        result = func_021BE948(atk, spd + (spa + (speed + (hpStat + def))), amount, allowAbove100);
        if (result != -1) { atk = result; func_02017E40(mon, 14, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 44)) {
        amount = func_02021014(rec, 54);
        result = func_021BE948(def, spd + (spa + (speed + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { def = result; func_02017E40(mon, 15, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 45)) {
        amount = func_02021014(rec, 55);
        result = func_021BE948(speed, spd + (spa + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { speed = result; func_02017E40(mon, 16, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 46)) {
        amount = func_02021014(rec, 56);
        result = func_021BE948(spa, spd + (speed + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { spa = result; func_02017E40(mon, 17, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(rec, 47)) {
        amount = func_02021014(rec, 57);
        result = func_021BE948(spd, spa + (speed + (def + (hpStat + atk))), amount, allowAbove100);
        if (result != -1) { func_02017E40(mon, 18, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (changed == 0 && applicable == 1) { func_020307B0(rec); return 0; }
    oldLevel = func_02017E1C(mon, 9, 0);
    if (oldLevel < 100) {
        if (func_02021014(rec, 49)) {
            func_021BEA48((int)mon, oldLevel, func_02021014(rec, 60), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    } else if (oldLevel >= 100 && oldLevel < 200) {
        if (func_02021014(rec, 50)) {
            func_021BEA48((int)mon, oldLevel, func_02021014(rec, 61), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    } else if (oldLevel >= 200 && oldLevel <= 255) {
        if (func_02021014(rec, 51)) {
            func_021BEA48((int)mon, oldLevel, func_02021014(rec, 62), item, arg, heap);
            func_020307B0(rec); return changed;
        }
    }
    func_020307B0(rec);
    return changed;
}




int func_021BE874(void *a, int b, int c)
{
    int r = 0;
    u16 x;
    u32 y;
    u32 v;
    u32 n;
    int t;
    n = (u8)func_02017E1C(a, b + 0x3E, 0);
    if (n == 3)
        return r;
    x = (u16)func_02017E1C(a, b + 0x36, r);
    if (func_0201C158(x, r) < 5)
        return r;
    v = (u8)func_02017E1C(a, b + 0x3A, r);
    y = func_0201C158(x, n);
    t = n + c;
    if ((u32)t > 3)
        n = 3;
    else
        n = (u8)t;
    v = (u8)(v + func_0201C158(x, n) - y);
    func_02017E40(a, b + 0x3E, n);
    func_02017E40(a, b + 0x3A, v);
    return 1;
}



void func_021BE914(void *p, u32 v, u32 limit, u32 step)
{
    if (limit == 1) step = 1;
    else if (step == 0xff) step = limit;
    else if (step == 0xfe) step = limit >> 1;
    else if (step == 0xfd) step = limit >> 2;
    v += step;
    if (v > limit) v = limit;
    func_02017E40(p, 0xa0, v);
}



int func_021BE948(int a0, int a1, int a2, int a3)
{
    if (a0 == 0 && a2 < 0)
        return -1;
    if (a0 == 0xff && a2 > 0)
        return -1;
    if (a0 >= 100 && a3 == 0 && a2 > 0)
        return -1;
    if (a0 + a1 >= 0x1FE && a2 > 0)
        return -1;
    a0 += a2;
    if (a2 > 0 && a0 > 100 && a3 == 0)
        a0 = 100;
    else if (a0 < 0)
        a0 = 0;
    if (a0 + a1 > 0x1FE)
        a0 = 0x1FE - a1;
    return a0;
}




int func_021BE9BC(void *a, void *b)
{
    int r = 0;
    int v = func_02017E1C(a, 9, 0);
    if (v >= 0xFF)
        return r;
    if (v < 100) {
        if ((int)func_02021014(b, 0x31) != 0 && (int)func_02021014(b, 0x3C) > 0)
            return 1;
        return 0;
    }
    if (v >= 100 && v < 200) {
        if ((int)func_02021014(b, 0x32) != 0 && (int)func_02021014(b, 0x3D) > 0)
            return 1;
        return 0;
    }
    if (v >= 200 && v < 0xFF) {
        if ((int)func_02021014(b, 0x33) != 0 && (int)func_02021014(b, 0x3E) > 0)
            return 1;
        return 0;
    }
    return 0;
}
