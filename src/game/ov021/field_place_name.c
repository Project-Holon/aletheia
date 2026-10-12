/*
 * file:     field_place_name.c
 * unit:     yes
 * function: func_021BBDD4, func_021BBE84, func_021BBEF4, func_021BBF10, func_021BBF74, func_021BBF78, func_021BBF9C, func_021BBFB0, func_021BBFB4, func_021BBFB8, func_021BBFF4, func_021BC030, func_021BC048, func_021BC10C, func_021BC138, func_021BC338, func_021BC340, func_021BC388, func_021BC424, func_021BC484, func_021BC4F0, func_021BC550, func_021BC578, func_021BC5A0, func_021BC5BC, func_021BC5D4, func_021BC5E4, func_021BC63C, func_021BC654, func_021BC664, func_021BC6B4, func_021BC6D0, func_021BC6E8, func_021BC704, func_021BC720, func_021BC730, func_021BC748, func_021BC75C, func_021BC788, func_021BC794, func_021BC7B0, func_021BC7BC, func_021BC7D4, func_021BC7F8, func_021BC810, func_021BC824, func_021BC838, func_021BC848, func_021BC910, func_021BC92C, func_021BC948, func_021BC970, func_021BC998, func_021BC9AC, func_021BC9C0, func_021BC9CC, func_021BCA48, func_021BCA64, func_021BCA6C, func_021BCA74, func_021BCA78, func_021BCA80, func_021BCA88, func_021BCA8C, func_021BCAB0, func_021BCB48, func_021BCB9C, func_021BCBC8, func_021BCC3C, func_021BCC80, func_021BCD34, func_021BCD70, func_021BCD84, func_021BCDD8, func_021BCE88, func_021BCEAC, func_021BCEB0, func_021BCEB4, func_021BCF18, func_021BCF1C, func_021BCF20, func_021BCF24, func_021BCF88, func_021BCFA4, func_021BCFD8, func_021BCFE0, func_021BCFF0, func_021BD008, func_021BD01C, func_021BD040, func_021BD054, func_021BD068, func_021BD07C, func_021BD090, func_021BD094, func_021BD098, func_021BD09C, func_021BD0A0, func_021BD0A4, func_021BD0A8, func_021BD0B0, func_021BD0C0, func_021BD0C8, func_021BD0D0, func_021BD0E0, func_021BD0FC, func_021BD118, func_021BD120, func_021BD134, func_021BD138, func_021BD140, func_021BD148, func_021BD184, func_021BD19C, func_021BD1CC, func_021BD1D4, func_021BD1DC, func_021BD1E4, func_021BD1EC, func_021BD1F4, func_021BD1FC, func_021BD204, func_021BD20C, func_021BD214, func_021BD22C, func_021BD234, func_021BD250, func_021BD264, func_021BD278, func_021BD2A4, func_021BD2B8, func_021BD2BC, func_021BD2C0, func_021BD2C4, func_021BD2C8, func_021BD2D0, func_021BD2D8, func_021BD2DC, func_021BD2E8, func_021BD2F4, func_021BD2FC, func_021BD304, func_021BD308, func_021BD30C, func_021BD340, func_021BD36C, func_021BD394, func_021BD3BC, func_021BD3EC, func_021BD430, func_021BD474, func_021BD47C, func_021BD484, func_021BD554, func_021BD57C, func_021BD588, func_021BD5D4, func_021BD5F8, func_021BD604, func_021BD648, func_021BD6C0, func_021BD704, func_021BD734, func_021BD7A8, func_021BD7E0, func_021BD874, func_021BD8C0, func_021BD904, func_021BD93C, func_021BD94C, func_021BD96C, func_021BD988, func_021BD9BC, func_021BDA30, func_021BDA70, func_021BDAA8, func_021BDB1C, func_021BDB5C, func_021BDB9C, func_021BDBF8, func_021BDC0C, func_021BDC2C, func_021BDC80, func_021BDC94, func_021BDCB8, func_021BDCC8, func_021BDD20, func_021BDD34, func_021BDD40, func_021BDD48, func_021BDD58, func_021BDD74, func_021BDD7C, func_021BDD9C, func_021BDDAC, func_021BDDC0, func_021BDEB4, func_021BDFB0, func_021BE068, func_021BE148, func_021BE158, func_021BE17C, func_021BE180, func_021BE184, func_021BE194, func_021BE1A0, func_021BE1B0, func_021BE1C4, func_021BE1DC, func_021BE218
 * address:  0x021BBDD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5FC  0x0216D5FC  thumb  ov010
 *   func_021BBD84  0x021BBD84  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9AF8     0x021D9AF8  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_02050080  0x02050080  arm
 *   func_020508C4  0x020508C4  arm
 *   func_0204F6B4  0x0204F6B4  arm
 *   d_021DE320     0x021DE320  data  a4
 *   func_020307B0  0x020307B0  arm
 *   d_021D9B64  0x021D9B64  data
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0219C98C  0x0219C98C  thumb  ov021
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219C928  0x0219C928  thumb  ov021
 *   func_0219C9E0  0x0219C9E0  thumb  ov021
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020507D0  0x020507D0  arm
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0204F5E4  0x0204F5E4  arm
 *   func_0204F604  0x0204F604  arm
 *   func_0204F654  0x0204F654  arm
 *   func_0204F66C  0x0204F66C  arm
 *   func_0204F684  0x0204F684  arm
 *   func_0204F794  0x0204F794  arm
 *   func_0204F748  0x0204F748  arm
 *   func_0204F764  0x0204F764  arm
 *   d_021D9B40     0x021D9B40  data  a4
 *   d_021D9B58     0x021D9B58  data  a4
 *   d_021D9B4C     0x021D9B4C  data  a4
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_020493D4  0x020493D4  arm
 *   func_02030734  0x02030734  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02062A98  0x02062A98  arm
 *   d_021D9B78     0x021D9B78  data  a4
 *   func_0204B084  0x0204B084  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02049238  0x02049238  arm
 *   func_02045A38  0x02045A38  arm
 *   sub_0201DC6C   0x0201DC6C  thumb
 *   d_021D9B88     0x021D9B88  data  a4
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   func_02045770  0x02045770  arm
 *   func_020439A0  0x020439A0  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb
 *   func_0215841C  0x0215841C  thumb
 *   func_021583EC  0x021583EC  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_020458F8  0x020458F8  arm
 *   func_02012B38  0x02012B38  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 *   func_020414C4  0x020414C4  arm
 *   func_020414EC  0x020414EC  arm
 *   d_021DE354     0x021DE354  data  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02008998  0x02008998  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_020089A0  0x020089A0  thumb
 *   d_021DE368     0x021DE368  data  a4
 *   func_020437AC  0x020437AC  arm
 *   func_0209C494  0x0209C494  arm
 *   _fneq  0x0209BCD0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045A98  0x02045A98  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020257D0  0x020257D0  thumb
 *   func_02025774  0x02025774  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   d_021D9BB0     0x021D9BB0  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02161B1C  0x02161B1C  thumb  ov010
 *   func_02161B74  0x02161B74  thumb  ov010
 *   func_021BFE00  0x021BFE00  thumb  ov021
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02029E08  0x02029E08  thumb
 *   func_02029DFC  0x02029DFC  thumb
 *   func_02012134  0x02012134  thumb
 *   func_0202B580  0x0202B580  thumb
 *   func_0202B434  0x0202B434  thumb
 *   func_0202B438  0x0202B438  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 *   d_021D9BC8     0x021D9BC8  data  ov021  a4
 *   func_021A7B20  0x021A7B20  thumb  ov021
 *   func_021618E0  0x021618E0  thumb  ov010
 *   func_021BF644  0x021BF644  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_0218FF20  0x0218FF20  thumb
 *   d_021DE37C     0x021DE37C  data  a4
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A7B08  0x021A7B08  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_02048F4C  0x02048F4C  arm
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_02162370  0x02162370  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   d_021D9D98     0x021D9D98  data  a4
 *   d_021D9CBC     0x021D9CBC  data  a4
 *   func_02034A5C  0x02034A5C  arm
 *   d_021D9BE0     0x021D9BE0  data  ov021  a4
 */
#include "../../matched/include/Obj20103.h"
#include "../../matched/include/Obj00575.h"
#include "../../matched/include/Obj18190.h"
#include "../../matched/include/Obj18191.h"
#include "../../matched/include/Obj01123.h"
#include "../../matched/include/Obj18195.h"
#include "../../matched/include/Obj18196.h"
#include "../../matched/include/Obj18197.h"
#include "../../matched/include/Obj18198.h"
#include "../../matched/include/Obj18199.h"
#include "../../matched/include/Obj18200.h"
#include "../../matched/include/Obj05061.h"
#include "../../matched/include/Obj00183.h"
#include "../../matched/include/Obj20118.h"
#include "../../matched/include/Obj20119.h"
#include "../../matched/include/Obj18206.h"
#include "../../matched/include/Obj18207.h"
#include "../../matched/include/Obj18208.h"
#include "../../matched/include/Obj18209.h"
#include "../../matched/include/Obj20122.h"
#include "../../matched/include/Obj18210.h"
#include "../../matched/include/Obj20124.h"
#include "../../matched/include/Obj18211.h"
#include "../../matched/include/Obj18214.h"
#include "../../matched/include/Obj18215.h"
#include "../../matched/include/Obj12115.h"
#include "../../matched/include/Obj06054.h"
#include "../../matched/include/Obj18217.h"
#include "../../matched/include/Obj18218.h"
#include "../../matched/include/Obj18219.h"
#include "../../matched/include/Obj18220.h"
#include "../../matched/include/Obj18221.h"
#include "../../matched/include/Obj18222.h"
#include "../../matched/include/Obj18223.h"
#include "../../matched/include/Obj18226.h"
#include "../../matched/include/Obj18227.h"
#include "../../matched/include/Obj18228.h"
#include "../../matched/include/Obj18232.h"
#include "../../matched/include/Obj18234.h"
#include "../../matched/include/Obj02719.h"
#include "../../matched/include/Obj18235.h"
#include "../../matched/include/Obj20132.h"
#include "../../matched/include/Obj12883.h"
#include "../../matched/include/Obj03588.h"
#include "../../matched/include/Obj12889.h"
#include "../../matched/include/Obj18244.h"
#include "../../matched/include/Obj20137.h"
#include "../../matched/include/Obj07540.h"
#include "../../matched/include/Obj12894.h"
#include "../../matched/include/Obj09653.h"
#include "../../matched/include/Obj02661.h"
#include "../../matched/include/Obj05065.h"
#include "../../matched/include/Obj00282.h"
#include "../../matched/include/Obj18252.h"
#include "../../matched/include/Obj03139.h"
#include "../../matched/include/Obj09656.h"
#include "../../matched/include/Obj18253.h"
#include "../../matched/include/Obj18254.h"
#include "../../matched/include/Obj18255.h"
#include "../../matched/include/Obj18256.h"
#include "../../matched/include/Obj09202.h"
#include "../../matched/include/Obj18257.h"

struct Actor;
struct VecFx32;
struct BbActDesc;
struct BbActSys;
struct Manager0204F684;
struct Trip;
struct BgTemplate;
struct Descriptor;
struct Cfg;
struct ArcFile;
struct NitroFileHeader;
struct CharBuf;
struct Obj_021BC730;
struct Bank;
struct U16Vec;
struct Font;
struct Bmp;
struct MsgBank;
struct WordSet;
struct Ctx;
struct BigObj;
struct Sub02014444Obj;
struct Rec;
struct Big;
struct Sub02008828Obj;
struct Obj020437AC;
struct Grid;
struct Param;
struct Sys;
struct Obj;
struct Strbuf;
struct StrObj;
struct Desc;
struct Args;
struct Evt;
struct Obj00020;
struct Obj_021BD9BC;
struct V3;
struct Rec94;
typedef struct V3 { int x, y, z; } V3;

typedef unsigned short u16;


typedef struct Arg_021BBDD4 {
    int a;
    u16 h;
} Arg_021BBDD4;

typedef unsigned int u32;

typedef signed char s8;

typedef struct Head {
    int h0;
    int h4;
    u16 tab[1];
} Head;

typedef struct Src_021BBE84 {
    struct Head *head;
    u16 idx;
    u16 x;
} Src_021BBE84;

typedef struct Res {
    struct Head *head;
    u16 idx;
    u16 x;
    u16 h8;
    unsigned char padA[4];
    short h0e;
} Res;

typedef struct Desc1 {
    u16 a, b, c;
    s8 d;
    int e, f;
} Desc1;

typedef struct Desc2 {
    int pad[3];
    int a;
    Res *b;
} Desc2;

typedef struct Obj_021BBEF4 {
    Head *head;
    int pad4;
    u16 h8;
} Obj_021BBEF4;

typedef signed short s16;

typedef unsigned char u8;

typedef struct Obj_021BBF10 {
    Head *head;
    int pad4;
    u16 h8;
    u16 hA;
    u16 padC;
    s16 h0e;
    int i10;
} Obj_021BBF10;

typedef struct FieldPlaceNameWork2 {
    int f0;
    int f4;
    int f8;
} FieldPlaceNameWork2;

typedef signed int s32;

typedef struct Arg_021BBEF4 { u32 a; u32 b; u32 c; u32 d; u32 e; } Arg_021BBEF4;

typedef struct { u32 w[5]; } Blk;


typedef struct {
    char pad[0x10];
    u8 b10;
    char pad2[0xF];
    void *f20;
    int pad24;
    char f28[1];
} Obj_021BC030;


typedef struct {
    char pad[0x10];
    u8 b10;
    char pad2[0xB];
    void *f1C;
    char pad3[0xA];
    u16 h2A;
    char f2C[1];
} Obj_021BC10C;

typedef int            fx32;

typedef struct { fx32 x, y, z; } Vec_021BBEF4;

typedef struct {
    u8 pad0[7];
    u8 f7;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 padC[0x14 - 0xC];
    u32 *f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Param;

typedef struct { u32 f0; u32 f4; u32 pad8[8]; int f28; u32 pad2C[6]; u16 f44; u16 f46; u32 f48; u32 f4C; } X;

typedef struct {
    void *f0;
    char pad[0x42];
    u16 h46;
} Obj_021BD0E0;

typedef struct {
    char pad[0x10];
    void *f10;
} Obj_021BC810;

typedef struct {
    char pad[8];
    void *f8;
} Obj_021BCFE0;


typedef struct {
    char pad[0x1C];
    void *f1C;
} Obj_021BD008;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x2A];
    void *f38;
} Obj_021BC730;



typedef struct FieldPlaceNameWork {
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    int f28;
    int f2C;
    void *f30;
    void *f34[1];
    void *f38;
    int f3C;
    u8 b40;
    u8 pad41[0x42 - 0x41];
    u16 h42;
    u16 h44;
    u16 h46;
    u8 pad48[0x50 - 0x48];
    void *f50[0x1E];
    void *fC8[0x20];
    u8 b148;
    u8 b149;
    u8 b14A;
    u8 pad14B[0x14C - 0x14B];
    int f14C;
    int f150;
} FieldPlaceNameWork;


typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x1E];
    void *f2C;
    void *f30;
    char pad3[0x1C];
    void *f50[0x1E];
} Obj_021BC7D4;











typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    float x;
    float f14;
    float f18;
    float f1C;
    u32 f20;
    u16 ch;
    u16 pad;
} Params;








typedef struct {
    char pad[0xC];
    u16 hC;
} Obj_021BD098;


typedef struct {
    u16 h0;
    char pad[6];
    void *f8;
} Obj_021BD250;

typedef struct {
    void *f0;
    u16 h4;
    u16 h6;
    int f8;
    int fC;
    u8 b10;
    u8 b11;
    u16 h12;
    int f14;
} Desc;

typedef struct {
    char pad[8];
    void *f8;
    void *fC;
} Obj_021BD278;

typedef struct {
    char pad[0xC];
    void *fC;
} Obj_021BD5D4;




typedef struct {
    char pad00[0x10];
    FieldPlaceNameWork t;
} S_021BD3EC_021BBDD4;


typedef struct {
    char pad00[0x10];
    FieldPlaceNameWork t;
} S_021BD3EC_021BD430;

typedef struct FieldPlaceNameWork5 {
    int f0;
    int f4;
    int f8;
    int fC;
    u8 b10;
    u8 b11;
    u8 pad12[0x14 - 0x12];
    void *f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    void *f24;
    u16 h28;
    u16 h2a;
    u8 f2c[4];
    void *f30;
    void *f34;
    u8 pad38[0x44 - 0x38];
    int f44;
    u16 h48;
    u8 pad4A[0x50 - 0x4A];
    u32 f50[30];
    u32 fC8[32];
    u8 f148;
    u8 pad149[0x14B - 0x149];
    u8 f14B;
    void *f14C;
    int f150;
} FieldPlaceNameWork5;


typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    FieldPlaceNameWork s;
} Obj_021BD484;

typedef struct {
    int x, y;
} V2;

typedef struct {
    int a, b, c, d, e, f;
    V2 g;
} Src_021BD554;

typedef struct {
    char pad[0x10];
    int a, b, c, d;
    char pad2[8];
    int e, f;
    V2 g;
} Obj_021BD554;

typedef struct {
    float f0;
    float f4;
} Q;

typedef struct {
    void *f[6];
} Tbl;

typedef struct {
    int f00;
    void *f04;
    char pad08[8];
    unsigned int f10;
} Arg;

typedef struct {
    int f00;
    int f04;
    Arg *f08;
} Work;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
} Cfg;

typedef struct {
    u32 f00;
    u32 f04;
    Cfg *cfg;
} Ctx;

typedef struct {
    char pad[8];
    void *f8;
    char pad2[0x14];
    u16 h20;
    char pad3[0x23];
    u8 b45;
    char pad4[2];
    int f48;
} Inner_021BD904;

typedef struct {
    char pad[8];
    Inner_021BD904 *f8;
} Obj_021BD93C;

typedef struct {
    char pad[4];
    void *f4;
    char pad2[0x44];
    int f4C;
} Inner_021BD96C;

typedef struct {
    char pad[8];
    Inner_021BD96C *f8;
} Obj_021BD96C;

typedef struct {
    u32 x0;
    u32 x4;
    u8 pad8[0x10];
    u16 h18;
    u8 pad1a[6];
    u16 h20;
} Ent;

typedef struct {
    u32 x0;
    u32 x4;
    Ent *e;
} Obj_021BD904;

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fC;
    char pad10[0x28];
    int f38;
    int f3C;
    int f40;
} Sub_021BD988;

typedef struct {
    int f0;
    int f4;
    Sub_021BD988 *f8;
} Obj_021BD988;

typedef struct { u32 v[6]; } T6;

typedef struct {
    int pad0;
    void *f4;
    void *f8;
} Inner_021BDC0C;

typedef struct {
    Inner_021BDC0C *f0;
} Obj_021BD9BC;

typedef struct {
    char pad[0xC];
    void *fC;
    char pad2[0x10];
    s16 s20;
} Inner_021BDC80;

typedef struct {
    Inner_021BDC80 *f0;
} Obj_021BDC2C;


typedef struct {
    void *f0;
    void *f4;
    char pad[0x5C];
    int f64;
} Obj_021BDD7C;

typedef struct FieldPlaceNameWork3 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    Blk f14;
    u32 f28;
    u32 f2C;
    u8 pad30[0x54 - 0x30];
    void *f54;
    V3 f58;
    u8 pad64[0x150 - 0x64];
    FieldPlaceNameWork5 *f150;
} FieldPlaceNameWork3;

typedef struct {
    u16 f0;
    u16 f2;
    int f4;
} Rot;

typedef struct FieldPlaceNameWork4 {
    int f0;
    int f4;
    u8 pad08[0x24 - 0x8];
    Rot f24;
    void *f2C;
    u8 pad30[0x44 - 0x30];
    int f44;
    int f48;
} FieldPlaceNameWork4;

typedef struct {
    u32 f0;
    u32 f4;
    FieldPlaceNameWork4 s;
    u32 f54;
    u8 pad58[0x68 - 0x58];
    int f68;
    int f6C;
} Obj_021BDDC0;

typedef struct {
    u16 f04;
    u16 f06;
    int f08;
    V3 pos;
    V3 rot;
} In_021BDC2C;

typedef struct {
    u32 f00;
    In_021BDC2C  in;
    u8  sub[0x20];
    int f44;
    int f48;
} S_021BDC2C;

typedef struct {
    u32 obj;
    u32 f04;
    S_021BDC2C   s;
    u32 f54;
    u32 pad58[4];
    u32 f68;
    u32 f6C;
} A;

typedef struct Obj_021BDD48 {
    int f00;
    int f04;
    void *f08;
} Obj_021BDD48;

typedef struct {
    void *f0;
    char pad[0x50];
    void *f54;
} Obj_021BDD9C;

struct Q {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    struct V3 f40;
};

typedef struct {
    int f00, f04, f08, f0C, f10;
    V3 v1;
    V3 v2;
    int f2C, f30, f34, f38, f3C;
} Rec;

int func_021ABEA0(u32 a, u32 b);
u16 func_0216D5F8(void *p);
u16 func_0216D5FC(void *p);
int func_021BBD84(int a, int n, int x, int y);
void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
int func_0216D804(void *p);
int func_0216D81C(void *p);
void func_02164280(int x, int y, int *p);
void func_021ABFA8(int a, void *b, FieldPlaceNameWork2 *c, int d, Arg_021BBDD4 *e, int f);
extern int func_021AC1AC(u32 a);
extern void func_021AC1B8(int a, Desc2 *d);
extern void func_021AC154(int a);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_02050080(u32 *p);
extern u32 func_020508C4(u32 a, u16 b);
extern void func_0204F6B4(u8 *a0, int i, u8 *px);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *p);
extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern int func_0216E1A4(int a0, int a1);
extern void func_0219C98C(u32 a, u16 *b);
extern int func_0216E1C4(int a0, int a1);
extern int func_0216DC34(void *a0);
extern int func_0216D7A8(void *p, unsigned int v);
extern void *func_0216E3C4(void *p);
extern int func_0219C928(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1);
extern void func_0219C9E0(u32 a, u16 *b, u16 *c);
extern u32 func_021ABE14(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern int func_020507D0(u32 a, u16 b);
extern int func_020507A0(void *p, int idx, u32 x);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_0216D8B0(u8 *p, u8 *q);
extern int func_02163E58(u32 a, Vec_021BBEF4 *v, int *y);
extern void func_0216D8D0(u8 *p, u8 *q);
extern u32 func_0216D7DC(void *p);
extern u16 func_021AB0F8(u32 attr);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048B30(u32 cam, Vec_021BBEF4 *out);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern void func_0204F5E4(u8 *a0, u32 i, u16 *out);
extern void func_0204F604(void *p, u32 idx, u16 *src);
extern void func_0204F654(u32 h, u32 i, s16 *v);
extern void func_0204F66C(int p0, int p1, int p2);
extern void func_0204F684(struct Manager0204F684 *mgr, int idx, const s16 *p12, const s16 *p14);
extern void func_0204F794(void *p, u32 idx, u32 *val);
extern u32 func_0204F748(u8 *a0, int i);
extern void func_0204F764(void *p, u32 idx, u32 *val);
extern u32 func_021904AC(u8 *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020403F4(u32 i);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int a, int b, int c, int d, int e);
extern void func_020414AC(int a);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct Obj_021BC730 *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B084(u32 v);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_0204ADA4(u32 i);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(u32 v);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern u32 sub_0201DC6C(struct Font *p, u16 ch);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_02025588(void *a);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern u32 func_02013E4C(u32 id);
extern unsigned int func_02012138(const struct Ctx *a);
extern int func_02158344(int a);
extern int func_0215841C(int a);
extern int func_021583EC(int a, int b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern unsigned int func_0201444C(struct Sub02014444Obj *o);
extern u32 func_02013D5C(u32 id);
extern void func_020414C4(u32 idx);
extern void func_020414EC(u32 i);
extern void func_02082BCC(void *, int, int);
extern void *func_020120F4(const struct Ctx *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008998(const struct Sub02008828Obj *obj);
extern u32 func_020089A0(u32, u32);
extern u32 func_02013E6C(u32 id);
extern u16 func_02045A98(void);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0202570C(struct Grid *g);
extern u32 func_0209C494(u32 v);
extern void func_02045994(struct Strbuf *a, const u16 *b, u32 c);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_020257D0(struct Obj *o);
extern void func_0202590C(void *a, int b, int c);
extern void func_02025774(u8 *g, unsigned int a);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(void *p);
extern void func_020061E4(u32);
extern void *func_021A7E3C(struct Args *a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02161B1C(void *a);
extern int func_02161B74(int a0);
extern void *func_021BFE00(int a0, void *p, int a2);
extern int func_0218F0F8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_0218F0A8(u8 *a);
extern void func_0218EC54(u8 *p);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_02029E08(int a0, int a1);
extern void *func_02029DFC(const void *p);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B580(void *obj);
extern u32 func_0202B434(u8 *p);
extern u32 func_0202B438(u8 *p, u32 id);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_021A3098(u8 *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02029D44(u32 a, u32 b, u16 c, u8 d);
extern u8 *func_0202952C(u8 *p, u32 a);
extern void *func_021A7B20(struct Args *a);
extern void *func_021618E0(void *a, void *b);
extern int func_021BF644(int a, int b, int c);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_02029D7C(u32, u32);
extern u8 *func_020294C0(u8 *p, u32 a);
extern u32 func_02188D20(u8 *p);
extern u16 func_02188C84(u8 *p);
extern void func_0218FEA0(u8 *p, u32 v);
extern int func_0218FF00(u32 a);
extern void func_0218FF20(u8 *a);
extern void *func_0218FE80(void *a);
extern void func_0218FE98(void);
extern u16 func_021A3050(u8 *p);
extern void func_021A7B08(int a, struct V3 *b);
extern void func_021A3038(unsigned char *a, struct VecFx32 *out);
extern void func_0218FEA4(u32 a);
extern void func_0218FE78(u32 a, void *dst);
extern void func_0218FEC0(u8 *o);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0218E104(u8 *a, u32 b);
extern int func_0218EC60(u32 a);
extern u32 func_0218EC90(u32, u32);
extern u32 func_02162370(u32);
extern void *func_02188C80(void *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern int func_02034AC4(int);
extern void func_02034A5C(int handle);
void func_021BBDD4(int a, int b, int c);
void func_021BBE84(int a0, Res *r);
void func_021BBEF4(int a0, Obj_021BBEF4 *p);
void func_021BBF10(int a0, Obj_021BBF10 *p);
void func_021BBF74(void);
FieldPlaceNameWork2 *func_021BBF78(int a, int b);
void func_021BBF9C(u32 a, u8 *p);
void func_021BBFB0(void);
void func_021BBFB4(void *p);
void func_021BBFB8(u32 a, u32 b, u32 c, u32 d);
void func_021BBFF4(u32 a, FieldPlaceNameWork3 *o);
void func_021BC030(int a0, Obj_021BC030 *p);
void func_021BC048(u32 a0, FieldPlaceNameWork5 *p);
void func_021BC10C(int a0, Obj_021BC10C *p);
void func_021BC138(u16 id, Param *p);
int func_021BC338(u32 a);
int func_021BC340(int a, int b);
int func_021BC388(int a, int b, int c);
void func_021BC424(u32 a);
void func_021BC484(u32 a);
void func_021BC4F0(int a);
void func_021BC550(void *p, int v);
void func_021BC578(void *p, int v);
void func_021BC5A0(void *p, int v);
int func_021BC5BC(u8 *a);
void func_021BC5D4(u8 *p);
void func_021BC5E4(int *p);
void func_021BC63C(void *p);
void func_021BC654(u8 *p);
void func_021BC664(FieldPlaceNameWork *p);
void func_021BC6B4(FieldPlaceNameWork5 *p);
void func_021BC6D0(FieldPlaceNameWork3 *p);
void func_021BC6E8(FieldPlaceNameWork *p);
void func_021BC704(FieldPlaceNameWork *p);
void func_021BC720(FieldPlaceNameWork5 *p);
void func_021BC730(Obj_021BC730 *p);
void func_021BC748(u8 *p);
void func_021BC75C(FieldPlaceNameWork4 *p);
void func_021BC788(u8 *p);
void func_021BC794(FieldPlaceNameWork5 *p);
void func_021BC7B0(u8 *p);
void func_021BC7BC(FieldPlaceNameWork *p, int i);
void func_021BC7D4(Obj_021BC7D4 *p);
void func_021BC7F8(FieldPlaceNameWork *p);
void func_021BC810(Obj_021BC810 *p);
void func_021BC824(u8 *p);
void func_021BC838(char *p);
void func_021BC848(FieldPlaceNameWork5 *p);
int func_021BC910(FieldPlaceNameWork *p);
void func_021BC92C(FieldPlaceNameWork *p);
void func_021BC948(FieldPlaceNameWork *p);
void func_021BC970(FieldPlaceNameWork *p);
void func_021BC998(FieldPlaceNameWork5 *p);
void func_021BC9AC(FieldPlaceNameWork *p);
void func_021BC9C0(char *p);
void func_021BC9CC(char *p);
int func_021BCA48(FieldPlaceNameWork *p);
void func_021BCA64(u8 *p);
u8 *func_021BCA6C(u8 *p);
u32 func_021BCA74(u8 *p);
void func_021BCA78(u8 *p);
void func_021BCA80(u8 *p);
u32 func_021BCA88(u8 *p);
int func_021BCA8C(FieldPlaceNameWork *p);
void func_021BCAB0(int *p);
int func_021BCB48(int *p, int b);
void func_021BCB9C(void *p, int keep);
void func_021BCBC8(char *p);
void func_021BCC3C(void *p);
void func_021BCC80(char *p);
void func_021BCD34(FieldPlaceNameWork *p);
void func_021BCD70(FieldPlaceNameWork *p);
void func_021BCD84(char *p);
void func_021BCDD8(char *p);
void func_021BCE88(char *p);
void func_021BCEAC(int a);
void func_021BCEB0(int a);
void func_021BCEB4(char *p);
void func_021BCF18(int a);
void func_021BCF1C(int a);
void func_021BCF20(int a);
void func_021BCF24(char *p);
void *func_021BCF88(int a);
void func_021BCFA4(X *x, u32 b);
void func_021BCFD8(int a);
void func_021BCFE0(Obj_021BCFE0 *p);
void func_021BCFF0(FieldPlaceNameWork5 *p);
void func_021BD008(Obj_021BD008 *p);
void func_021BD01C(FieldPlaceNameWork5 *p);
void func_021BD040(Obj_021BCFE0 *p);
void func_021BD054(u8 *p);
void func_021BD068(u8 *p);
void func_021BD07C(FieldPlaceNameWork5 *p);
u16 func_021BD090(u8 *p);
u32 func_021BD094(u8 *p);
void func_021BD098(Obj_021BD098 *p, int v);
void func_021BD09C(u8 *p, u32 v);
void func_021BD0A0(FieldPlaceNameWork *p, int v);
u32 func_021BD0A4(u8 *p);
void func_021BD0A8(char *p);
void func_021BD0B0(FieldPlaceNameWork *p);
u8 func_021BD0C0(u8 *p);
void func_021BD0C8(char *p);
void func_021BD0D0(FieldPlaceNameWork *p);
void func_021BD0E0(Obj_021BD0E0 *p);
int func_021BD0FC(u32 a);
u16 func_021BD118(u8 *p);
void func_021BD120(FieldPlaceNameWork *p, u16 v);
u32 func_021BD134(u8 *p);
u8 func_021BD138(u8 *p);
u32 func_021BD140(u32 a);
void *func_021BD148(int a0, int a1, u16 a2, int a3);
void func_021BD184(void *a);
void func_021BD19C(u32 a, u32 b);
void func_021BD1CC(void *a);
void func_021BD1D4(void *a);
int func_021BD1DC(u8 *a0);
void func_021BD1E4(void *p, unsigned int a);
int func_021BD1EC(u8 *a0);
int func_021BD1F4(u8 *a0);
u32 func_021BD1FC(u32 *a0);
u32 func_021BD204(u32 *a0);
unsigned int func_021BD20C(char *p);
void *func_021BD214(int a);
u32 func_021BD22C(void *a0);
void func_021BD234(FieldPlaceNameWork5 *p);
void func_021BD250(Obj_021BD250 *p);
void func_021BD264(u8 *p);
void func_021BD278(Obj_021BD278 *p, int a, u16 b, int c);
void func_021BD2A4(Obj_021BD5D4 *p);
u16 func_021BD2B8(u8 *p);
void func_021BD2BC(u8 *p, int v);
u32 func_021BD2C0(u8 *p);
void func_021BD2C4(u8 *p, u32 v);
u16 func_021BD2C8(u8 *p);
void func_021BD2D0(u8 *p, u16 v);
u32 func_021BD2D8(u8 *p);
u32 func_021BD2DC(u32 *p);
u32 func_021BD2E8(u32 *p);
u8 func_021BD2F4(u8 *p);
u8 func_021BD2FC(u8 *p);
u8 *func_021BD304(u8 *p);
int func_021BD308(u8 *p);
void func_021BD30C(char *p);
int func_021BD340(void *a);
int func_021BD36C(void *p);
int func_021BD394(void *p);
void func_021BD3BC(void *p);
void func_021BD3EC(S_021BD3EC_021BBDD4 *p);
void func_021BD430(S_021BD3EC_021BD430 *p);
void func_021BD474(FieldPlaceNameWork5 *p);
void func_021BD47C(u8 *p);
void func_021BD484(Obj_021BD484 *obj);
void func_021BD554(Obj_021BD554 *p, Src_021BD554 *s);
void func_021BD57C(u8 *p);
void func_021BD588(u32 *p);
void func_021BD5D4(Obj_021BD5D4 *p);
void func_021BD5F8(void *p, unsigned int a);
void func_021BD604(u32 a, u16 b, u32 c, u8 *d, u8 *e);
void *func_021BD648(Arg *p);
u32 func_021BD6C0(u32 a, int *st, u32 *ctx);
int func_021BD704(u32 a, int *st, u32 *ctx);
u32 func_021BD734(u32 a, int *st, u32 *ctx);
int func_021BD7A8(void *task, u32 *state, Ctx *ctx);
u32 func_021BD7E0(u32 a, int *st, u32 *ctx);
u32 func_021BD874(u32 a, int *st, u32 *ctx);
u32 func_021BD8C0(u32 *ctx);
int func_021BD904(Obj_021BD904 *o);
u32 func_021BD93C(void *a);
void func_021BD94C(Obj_021BD93C *p);
void func_021BD96C(Obj_021BD96C *p, void *b);
void func_021BD988(Obj_021BD988 *o, int b);
int func_021BD9BC(u32 *p);
u32 func_021BDA30(u32 a, int *st, u32 *ctx);
u32 func_021BDA70(u32 a, u32 *st, u32 *p);
u32 func_021BDAA8(u32 a, int *st, u32 *ctx);
u32 func_021BDB1C(u32 a, int *st, u32 *ctx);
u32 func_021BDB5C(u32 a, int *st, u32 *ctx);
u32 func_021BDB9C(u32 a, int *st, u32 *ctx);
int func_021BDBF8(u32 a);
void func_021BDC0C(Obj_021BD9BC *p, void *b);
void func_021BDC2C(u32 *ctx, u32 a);
void func_021BDC80(Obj_021BDC2C *p);
void *func_021BDC94(void *a);
void func_021BDCB8(u8 *p);
void func_021BDCC8(char *a, int *b);
void func_021BDD20(FieldPlaceNameWork3 *p);
void func_021BDD34(u8 *p);
int func_021BDD40(void *a);
int func_021BDD48(Obj_021BDD48 *o);
void *func_021BDD58(int a);
void func_021BDD74(void *p);
void func_021BDD7C(Obj_021BDD7C *p, void *a);
void func_021BDD9C(Obj_021BDD9C *p, void *x);
void func_021BDDAC(FieldPlaceNameWork3 *p);
void func_021BDDC0(Obj_021BDDC0 *p);
void func_021BDEB4(A *a);
void func_021BDFB0(char *a);
void func_021BE068(A *a);
void func_021BE148(void *dst, int b);
int func_021BE158(u32 a, u32 b);
u32 func_021BE17C(u8 *p);
u8 *func_021BE180(u8 *p);
void func_021BE184(FieldPlaceNameWork3 *p, const V3 *v);
int func_021BE194(u32 a);
int func_021BE1A0(u32 a);
int func_021BE1B0(u32 a);
int func_021BE1C4(u32 a);
void func_021BE1DC(void *arg);
void func_021BE218(void *arg);
extern int d_021D9AF8;
extern int d_021DE320;
extern u8 d_021D9B64[];
extern const fx32 d_021D9B40[];
extern const fx32 d_021D9B58[];
extern const fx32 d_021D9B4C[];
extern int d_021D9B78;
extern const Params d_021D9B88;
extern int d_021DE354;
extern int d_021DE368;
extern Tbl d_021D9BB0;
extern const T6 d_021D9BC8;
extern int d_021DE37C;
extern void *d_021D9D98[];











void func_021BBDD4(int a, int b, int c)
{
    int x;
    int t;
    int u;
    int w;
    FieldPlaceNameWork2 v;
    Arg_021BBDD4 s;

    x = func_021ABEA0(b, 5);
    s.a = x;
    t = func_0216D5F8((void *)a);
    u = func_0216D5FC((void *)a);
    w = (u16)func_021BBD84(x, c, t, u);
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    t = func_0216D804((void *)a);
    func_02164280(t, func_0216D81C((void *)a), (int *)(&v));
    if (c == 0 && (u16)(w + 0xFFFE) <= 1) {
        v.f8 -= 0x2000;
    } else if (c == 4 && (u16)(w + 0xFFFE) <= 1) {
        v.f8 -= 0x2000;
    }
    if (c == 4) {
        v.f4 -= ((struct Obj20103 *)x)->f3C;
    }
    s.h = w;
    func_021ABFA8(b, &d_021D9AF8, (FieldPlaceNameWork2 *)&v, 0, (Arg_021BBDD4 *)&s, 0);
}











void func_021BBE84(int a0, Res *r)
{
    Desc2 d2;
    Desc1 d1;
    Src_021BBE84 *s = (Src_021BBE84 *)func_021AC1AC(a0);

    *(Src_021BBE84 *)r = *s;
    r->h0e = 0x1f;
    d1.a = r->head->tab[r->idx];
    d1.b = 0x1000;
    d1.c = 0x1000;
    d1.d = r->h0e;
    d1.e = 1;
    d1.f = 1;
    d2.a = 0;
    d2.b = r;
    func_021AC1B8(a0, &d2);
    r->h8 = func_02050340((void *)r->head->h4, 0, (const struct BbActDesc *)(&d1), 1, 3);
    if (r->h8 == 0xFFFF) {
        func_021AC154(a0);
    }
}













void func_021BBEF4(int a0, Obj_021BBEF4 *p)
{
    int h = p->head->h4;
    u16 i = p->h8;

    if (i != 0xFFFF) {
        func_02050468((struct BbActSys *)h, i, 1);
    }
}













/*
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
 */
void func_021BBF10(int a0, Obj_021BBF10 *p)
{
    u8 c;
    int r4, r6;
    u16 t;

    switch (p->hA) {
    case 0:
        p->i10 = p->i10 + 1;
        if (p->i10 >= 0x10) {
            p->hA = p->hA + 1;
        }
        break;
    case 1:
        p->h0e = p->h0e - 2;
        if (p->h0e < 0) {
            func_021AC154(a0);
            return;
        }
        c = p->h0e;
        r4 = p->head->h4;
        r6 = func_02050080((u32 *)r4);
        t = (int)func_020508C4((u32)r4, (u16)p->h8);
        func_0204F6B4((u8 *)r6, t, &c);
        break;
    }
}











void func_021BBF74(void) {}
















FieldPlaceNameWork2 *func_021BBF78(int a, int b)
{
    FieldPlaceNameWork2 *q = func_02030734(b, 4, 1, (const char *)&d_021DE320, 0x78);

    q->f0 = a;
    func_021BBFB0();
    return q;
}
















/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBF9C(u32 a, u8 *p)
{
    func_021BBFB4(p);
    func_020307B0(p);
}
















/*
 * An empty function.
 */
void func_021BBFB0(void)
{
}
















void func_021BBFB4(void *p)
{
}
















void func_021BBFB8(u32 a, u32 b, u32 c, u32 d)
{
    Arg_021BBEF4 s;

    s.b = d;
    s.c = b;
    s.d = a;
    s.e = func_0219C9DC((u8 *)func_0216D520((void *)a));
    s.a = func_021ABEA0(c, 6);
    func_021ABFA8(c, d_021D9B64, (FieldPlaceNameWork2 *)0, 0, (Arg_021BBDD4 *)&s, 0);
}















/*
 * Addresses are Black-image addresses.
 */
void func_021BBFF4(u32 a, FieldPlaceNameWork3 *o)
{
    u32 *p = (u32 *)func_021AC1AC(a);

    o->f14 = *(Blk *)p;
    o->f0C = 0x40;
    o->f00 = 0;
    o->f08 = 0;
    if (o->f14.w[1] == 2) {
        o->f0C = 0;
    }
    func_0216E1A4(p[2], (int)(&o->f2C));
}















void func_021BC030(int a0, Obj_021BC030 *p)
{
    if (p->b10) {
        p->b10 = 0;
        func_0219C98C((u32)p->f20, (u16 *)p->f28);
    }
}













/*
 * The zeroed V3 is a block-scope declaration with an initialiser: that is
 * what materialises `add r6, sp, #0xc` before the three stores and keeps r6
 * across the func_0216E3C4 call (plain element stores fold to sp-relative).
 */
void func_021BC048(u32 a0, FieldPlaceNameWork5 *p)
{
    u16 s[2];
    int h;

    if (func_0216E1C4(p->f1c, (int)p->f2c) == 0 || func_0216DC34((void *)p->f1c) == 0) {
        func_021AC154((int)a0);
        return;
    }
    h = func_0216D7A8((void *)p->f1c, 0);
    if (p->b10 == 0) {
        if (h == 0xFFFF) return;
        {
            V3 v = {0, 0, 0};
            func_0219C928(p->f20, func_0216E3C4((void *)p->f1c), &p->h28, &v,
                          (u32)func_021BC138, (u32)p);
        }
        p->b10 = 1;
    }
    if (p->h2a == 0xFFFF) return;
    if (p->b11 == 0) {
        int t;
        func_0219C9E0(p->f1c, &s[1], &s[0]);
        t = s[1];
        p->f0 = t;
        p->f4 = s[0];
        p->f8 = t;
        p->b11 = 1;
    }
    p->f8 += p->fC;
    if (p->f8 >= p->f0 + 0x400) {
        p->f8 = p->f0 + 0x400;
        p->fC = -p->fC;
        return;
    }
    if (p->f8 <= p->f0 - 0x400) {
        p->f8 = p->f0 - 0x400;
        p->fC = -p->fC;
    }
}













void func_021BC10C(int a0, Obj_021BC10C *p)
{
    if (func_0216E1C4((int)p->f1C, (int)p->f2C) == 1 && p->b10 != 0 && p->h2A != 0xFFFF) {
        func_021BC138(p->h2A, (Param *)p);
    }
}















/*
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
 *
 * The u16 `slot` local is what truncates func_020507D0's result straight
 * into r2 (a (u16) cast or a u16 parameter adds a copy first).
 *
 * Addresses are Black-image addresses.
 */
void func_021BC138(u16 id, Param *p)
{
    Vec_021BBEF4 v;
    Vec_021BBEF4 w;
    Vec_021BBEF4 u;
    int y;
    u32 flag;
    s16 rot[4];
    u16 kind;
    u32 h2;
    u32 h;
    int idx;
    u32 obj;
    Info *info;
    u32 i1;
    u32 i2;
    u16 slot;

    h2 = p->f24;
    h = func_02050080((u32 *)h2);
    idx = func_0216D7A8((void *)p->f1C, 0);
    if (id == 0xFFFF) {
        return;
    }
    kind = func_02188C9C((u8 *)func_021ABE14((u8 *)(*p->f14)));
    slot = func_020507D0(h2, idx);
    func_020507A0((void *)h2, id, slot);
    func_020507F0((void *)h2, id, 0);
    obj = p->f1C;
    info = func_0216E3C4((void *)obj);
    func_0216D88C((const struct Actor *)obj, (struct VecFx32 *)&v);
    v.z += d_021D9B40[info->f7];
    func_0216D8B0((u8 *)obj, (u8 *)(&w));
    v.x += w.x;
    v.z -= w.z;
    if (func_02163E58(obj, (Vec_021BBEF4 *)&v, &y) == 1) {
        v.y = y;
    }
    v.y += d_021D9B58[p->f18];
    func_0216D8D0((u8 *)obj, (u8 *)(&w));
    v.x += w.x;
    v.y -= w.y;
    v.z -= w.z;
    v.y += d_021D9B4C[info->f7];
    if (info->f7 == 2) {
        if (func_021AB0F8(func_0216D7DC((void *)obj)) & 0x40) {
            v.y -= 0x3800;
        } else {
            v.y -= 0x8000;
        }
    }
    v.y += func_021BC340(kind, info->f7);
    func_02048B30(func_0218EC2C(func_02188C58((void *)func_021ABE14((u8 *)(*p->f14)))), (Vec_021BBEF4 *)&u);
    v.x += (v.x / 4096 - u.x / 4096) * 298;
    func_0204F638((u8 *)h, id, (struct Trip *)(&v));
    flag = 1;
    i1 = func_020508C4(h2, idx);
    i2 = func_020508C4(h2, id);
    rot[3] = p->f8;
    rot[2] = p->f4;
    rot[2] += (s16)func_021BC338(kind);
    rot[1] = 0;
    rot[0] = 0;
    func_0204F5E4((u8 *)h, i1, (u16 *)(&rot[1]));
    func_0204F604((void *)h, i2, (u16 *)(&rot[1]));
    func_0204F654(h, i1, &rot[0]);
    func_0204F66C(h, i2, (int)(&rot[0]));
    func_0204F684((struct Manager0204F684 *)h, i2, &rot[3], &rot[2]);
    func_0204F794((void *)h, i2, &flag);
    flag = func_0204F748((u8 *)h, i1);
    func_0204F764((void *)h, i2, &flag);
}















int func_021BC338(u32 a)
{
return (~255);
}














int func_021BC340(int a, int b)
{
    int r = 0;

    if (a == 0x71 || a == 0x159) {
        if (b == 0) {
            r = -0x800;
        }
    } else if (a == 0x8f) {
        if (b == 0) {
            r = 2 << 10;
        }
    } else if (a == 0x159 + 0x12) {
        if (b == 0) {
            r = -0x5800;
        }
    } else {
        if (b == 0) {
            r = 6 << 10;
        }
    }
    return r;
}















int func_021BC388(int a, int b, int c)
{
    int r4;

    r4 = (int)func_021BCF88(b);
    func_021BCFA4((X *)r4, (u32)a);
    func_021BD0E0((Obj_021BD0E0 *)r4);
    func_021BC810((Obj_021BC810 *)r4);
    func_021BCFE0((Obj_021BCFE0 *)r4);
    func_021BCFF0((FieldPlaceNameWork5 *)r4);
    func_021BD008((Obj_021BD008 *)r4);
    func_021BD098((Obj_021BD098 *)r4, b);
    func_021BD09C((u8 *)r4, func_021904AC((u8 *)c));
    func_021BC730((Obj_021BC730 *)r4);
    func_021BC75C((FieldPlaceNameWork4 *)r4);
    func_021BC794((FieldPlaceNameWork5 *)r4);
    func_021BC7BC((FieldPlaceNameWork *)r4, 0);
    func_021BC998((FieldPlaceNameWork5 *)r4);
    func_021BC7D4((Obj_021BC7D4 *)r4);
    func_0203FCA0(3, (const struct BgTemplate *)0x021DE334, 0);
    func_021BC664((FieldPlaceNameWork *)((FieldPlaceNameWork *)r4));
    func_021BC6E8((FieldPlaceNameWork *)r4);
    func_021BD01C((FieldPlaceNameWork5 *)r4);
    func_021BCB9C((void *)r4, 0);
    return r4;
}















void func_021BC424(u32 a)
{
    func_021BD0FC(a);
    func_021BC6B4((FieldPlaceNameWork5 *)a);
    func_021BC7F8((FieldPlaceNameWork *)a);
    func_021BD068((u8 *)a);
    func_021BC9AC((FieldPlaceNameWork *)a);
    func_021BC7B0((u8 *)a);
    func_021BC788((u8 *)a);
    func_021BC748((u8 *)a);
    func_021BD040((Obj_021BCFE0 *)a);
    func_021BD054((u8 *)a);
    func_021BD07C((FieldPlaceNameWork5 *)a);
    func_021BC704((FieldPlaceNameWork *)a);
    func_021BC824((u8 *)a);
    func_020403F4(3);
    func_021BCFD8(a);
}















void func_021BC484(u32 a)
{
    func_021BD0B0((FieldPlaceNameWork *)a);
    switch (func_021BD0A4((u8 *)a)) {
    case 0:
        func_021BCC3C((void *)a);
        break;
    case 1:
        func_021BCC80((char *)a);
        break;
    case 2:
        func_021BCD34((FieldPlaceNameWork *)a);
        break;
    case 3:
        func_021BCD70((FieldPlaceNameWork *)a);
        break;
    case 4:
        func_021BCD84((char *)a);
        break;
    case 5:
        func_021BCDD8((char *)a);
        break;
    case 6:
        func_021BCE88((char *)a);
        break;
    }
    func_021BC970((FieldPlaceNameWork *)a);
}















void func_021BC4F0(int a)
{
    switch (func_021BD0A4((u8 *)a)) {
    case 0:
        func_021BCEAC(a);
        break;
    case 1:
        func_021BCEB0(a);
        break;
    case 2:
        func_021BCEB4((char *)a);
        break;
    case 3:
        func_021BCF18(a);
        break;
    case 4:
        func_021BCF1C(a);
        break;
    case 5:
        func_021BCF20(a);
        break;
    case 6:
        func_021BCF24((char *)a);
        break;
    }
}















void func_021BC550(void *p, int v)
{
    func_021BD120(p, (u16)v);
    if (func_021BD140((u16)v)) {
        func_021BCBC8(p);
        func_021BCA78(p);
    }
}















void func_021BC578(void *p, int v)
{
    func_021BD120(p, (u16)v);
    if (func_021BD140((u16)v)) {
        func_021BCBC8(p);
        func_021BCA64(p);
    }
}















void func_021BC5A0(void *p, int v)
{
    func_021BD120(p, (u16)v);
    func_021BCBC8(p);
    func_021BCA64(p);
}















int func_021BC5BC(u8 *a)
{
func_021BCB9C((void *)a, 0);
func_021BCA80((u8 *)a);
return (int)func_021BCA6C(a);
}















void func_021BC5D4(u8 *p)
{
    func_021BC654(p);
    func_021BC720((FieldPlaceNameWork5 *)p);
}















void func_021BC5E4(int *p)
{
    int r4;

    func_021BC6D0((FieldPlaceNameWork3 *)((int)p));
    func_021BC6E8((FieldPlaceNameWork *)((int)p));
    func_021BD01C((FieldPlaceNameWork5 *)((int)p));
    r4 = p[9];
    func_02045334((struct Descriptor *)r4);
    func_02045374((struct Cfg *)r4);
    func_020409B4(func_02045730((struct Descriptor *)r4));
    func_0204047C(3, 1);
    func_02040588(3, 0);
    func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
}















void func_021BC63C(void *p)
{
    func_020414AC(3);
    func_021BC704((FieldPlaceNameWork *)p);
    func_021BD07C((FieldPlaceNameWork5 *)p);
}















void func_021BC654(u8 *p)
{
    func_021BC63C(p);
    func_021BC5E4((int *)p);
}















void func_021BC664(FieldPlaceNameWork *p)
{
    int r4, r6, h;

    r4 = func_021BD090((u8 *)((int)p));
    r6 = func_021BD094((u8 *)((int)p));
    h = (int)func_02030734(r4, func_020493D4((struct ArcFile *)r6, 1), 0, (const char *)0x021DE354, 0x2c8);
    p->f14C = h;
    func_0204932C((struct ArcFile *)r6, 1, (void *)h);
    func_02062A98((struct NitroFileHeader *)p->f14C, (void **)((int)&p->f150));
}















void func_021BC6B4(FieldPlaceNameWork5 *p)
{
    if (p->f14C != 0) {
        func_020307B0(p->f14C);
        p->f14C = 0;
        p->f150 = 0;
    }
}















void func_021BC6D0(FieldPlaceNameWork3 *p)
{
    func_02040E78(3, (void *)p->f150->fC, 0x20, 0);
}















void func_021BC6E8(FieldPlaceNameWork *p)
{
    if (p->f28 == -1) {
        p->f28 = func_0203FA08(3, 0x20, 0);
    }
}














void func_021BC704(FieldPlaceNameWork *p)
{
    if (p->f28 != -1) {
        func_0203FB44(3, p->f28, 0x20);
        p->f28 = -1;
    }
}














void func_021BC720(FieldPlaceNameWork5 *p)
{
    func_02043B5C(func_02045770(p->f24), 3);
}














void func_021BC730(Obj_021BC730 *p)
{
    p->f38 = func_0204B034((u8 *)(&d_021D9B78), 1, p->hC);
}














/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC748(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f38;
    if (v != 0) {
        func_0204B084(v);
        ((struct Obj00575 *)p)->f38 = 0;
    }
}














void func_021BC75C(FieldPlaceNameWork4 *p)
{
    u16 a = func_021BD090((u8 *)p);
    u32 b = func_021BD094((u8 *)p);

    p->f2C = (void *)func_0204AC18((void *)b, 3, 0, 0x20, 0, 1, a);
}














/*
 * Tail-call thunk: the object's word at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC788(u8 *p)
{
    func_0204ADA4(((struct Obj18190 *)p)->f2C);
}














void func_021BC794(FieldPlaceNameWork5 *p)
{
    p->f34 = func_0204B100(0x1E, 1, func_021BD090((unsigned char *)p));
    func_0204B22C(p->f34, 1);
}














/*
 * Tail-call thunk: the object's word at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC7B0(u8 *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj18191 *)p)->f34));
}














void func_021BC7BC(FieldPlaceNameWork *p, int i)
{
    if (p->f38 != 0) {
        func_0204B258(p->f34[i], p->f38);
    }
}














void func_021BC7D4(Obj_021BC7D4 *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        p->f50[i] = func_021BD148(p->hC, (int)p->f30, 0, (int)p->f2C);
    }
}














void func_021BC7F8(FieldPlaceNameWork *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        func_021BD184(p->f50[i]);
    }
}














void func_021BC810(Obj_021BC810 *p)
{
    p->f10 = func_020490F4(0x54, func_021BD090((u8 *)p));
}














void func_021BC824(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f10;
    if (v != 0) {
        func_02049238(v);
        ((struct Obj00575 *)p)->f10 = 0;
    }
}













/*
 * Unlabelled leaf: clears bytes +0x148 and +0x14B.
 */
void func_021BC838(char *p)
{
    p[0x148] = 0;
    p[0x14b] = 0;
}














/*
 * The x accumulation is a compound add inside each if/else arm (the two arms
 * cross-jump into one shared `ldr x; _fadd; str x` tail), then `+= 1.0f`
 * after the join, which is why the original re-loads x it has just stored:
 * a single `x += w` after the if/else forwards the value instead.
 * The call argument is the assignment itself: `f(p->fC8[n] = v, &prm)`
 * gives the `str r0, [r2, r1]` with the fC8 base hoisted.
 */
void func_021BC848(FieldPlaceNameWork5 *p)
{
    int n;
    int i;
    u16 buf[32];
    Params prm;

    n = p->f148;
    func_02045A38((struct U16Vec *)func_021BD134((u8 *)p), buf, 32);
    prm = d_021D9B88;
    prm.f20 = p->f18;
    prm.ch = buf[n];
    for (i = 0; i < n; i++) {
        if (p->fC8[i] == 0) {
            prm.x += sub_0201DC6C((struct Font *)p->f18, 0x20);
        } else {
            prm.x += func_021BD1EC((u8 *)p->fC8[i]);
        }
        prm.x += 1.0f;
    }
    if (prm.ch == 0x20) {
        p->fC8[n] = 0;
        p->f14B++;
    } else {
        func_021BD19C(p->fC8[n] = p->f50[n - p->f14B], (u32)(&prm));
    }
    p->f148++;
}














int func_021BC910(FieldPlaceNameWork *p)
{
    if (func_021BD138((u8 *)p) <= p->b148) {
        return 1;
    }
    return 0;
}














void func_021BC92C(FieldPlaceNameWork *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        func_021BD1E4(p->f50[i], 0);
    }
}














void func_021BC948(FieldPlaceNameWork *p)
{
    u8 i = p->b149++;

    if (p->fC8[i] != 0) {
        func_021BD1D4(p->fC8[i]);
        func_021BD1E4(p->fC8[i], 1);
    }
}














void func_021BC970(FieldPlaceNameWork *p)
{
    int n = func_021BD138((u8 *)p);
    int i;

    for (i = 0; i < n; i++) {
        if (p->fC8[i] != 0) {
            func_021BD1CC(p->fC8[i]);
        }
    }
}














void func_021BC998(FieldPlaceNameWork5 *p)
{
    p->f30 = func_02025538(func_021BD090((u8 *)p), p->f34);
}















void func_021BC9AC(FieldPlaceNameWork *p)
{
    if (p->f30 != 0) {
        func_02025588(p->f30);
        p->f30 = 0;
    }
}














void func_021BC9C0(char *p)
{
    p[0x14a] = 0;
}















void func_021BC9CC(char *p)
{
    int r4;
    int a, b;
    u16 c, d, e, f;

    r4 = *(int *)(p + 0xc8 + 4 * ((struct Obj01123 *)p)->f14A);
    if (r4 != 0) {
        a = func_021BD1DC((u8 *)r4);
        b = (int)func_02045770((struct Descriptor *)*(int *)&((struct Obj01123 *)p)->f24);
        c = func_021BD1FC((u32 *)r4);
        d = func_021BD204((u32 *)r4) - 8;
        e = func_021BD1EC((u8 *)r4);
        f = func_021BD1F4((u8 *)r4);
        func_020439A0((struct Bmp *)a, (struct Bmp *)b, 0, 0, c, d, e, f, 0);
    }
    (((struct Obj01123 *)p)->f14A)++;
}















int func_021BCA48(FieldPlaceNameWork *p)
{
    if ((int)func_021BD138((u8 *)p) <= p->b14A) {
        return 1;
    }
    return 0;
}















void func_021BCA64(u8 *p)
{
    ((struct Obj18195 *)p)->f4C = 1;
}















u8 *func_021BCA6C(u8 *p)
{
    ((struct Obj18196 *)p)->f4C = 0;
    return p;
}















/*
 * Loads the 32-bit word at byte +0x48 of the object.
 */
u32 func_021BCA74(u8 *p)
{
    return ((struct Obj18197 *)p)->f48;
}















void func_021BCA78(u8 *p)
{
    ((struct Obj18198 *)p)->f48 = 1;
}















void func_021BCA80(u8 *p)
{
    ((struct Obj18199 *)p)->f48 = 0;
}















/*
 * Loads the 32-bit word at byte +0x4c of the object.
 */
u32 func_021BCA88(u8 *p)
{
    return ((struct Obj18200 *)p)->f4C;
}















int func_021BCA8C(FieldPlaceNameWork *p)
{
    int a = func_02013E4C(p->h44);

    if (a != func_02013E4C(p->h46)) {
        return 1;
    }
    return 0;
}















void func_021BCAB0(int *p)
{
    int r6, r7;
    unsigned int r4;

    r6 = func_021BD118((u8 *)((int)p));
    r4 = func_02013E4C((unsigned int)r6);
    if (r4 >= 0x75) {
        r4 = 0;
    }
    if (r4 == 0) {
        func_021BC5BC((u8 *)p);
        return;
    }
    if (func_021BCB48((int *)((int)p), r6) != 0) {
        func_02158344((int)func_02012138((const struct Ctx *)p[0]));
        r7 = func_021583EC(p[1], func_0215841C(p[1]));
        r6 = (int)func_02045EC0((struct MsgBank *)p[5], 3);
        func_02045CAC((struct MsgBank *)p[5], r4, (void *)p[7]);
        func_0201F02C((struct WordSet *)p[2], 0, (void *)r7);
        func_0201F158((struct WordSet *)p[2], 1, r4);
        func_0201F250((struct WordSet *)p[2], (void *)p[7], (void *)r6);
        func_02045808((struct U16Vec *)r6);
    } else {
        func_02045CAC((struct MsgBank *)p[5], r4, (void *)p[7]);
    }
    *((unsigned char *)p + 0x20) = func_020458F8((struct U16Vec *)p[7]);
}















int func_021BCB48(int *p, int b)
{
    int r4, r6, t;

    r4 = func_02158344((int)func_02012138((const struct Ctx *)p[0]));
    t = (int)func_02012B38((const struct BigObj *)p[1]);
    r6 = func_02012B58((const struct BigObj *)p[1]);
    if (r4 != 0) {
        r4 = func_0215841C(p[1]);
        if (func_0201444C((struct Sub02014444Obj *)t) == 1) {
            return 1;
        }
        if (func_02013D5C(b) != 0 && r6 != r4) {
            return 1;
        }
    }
    return 0;
}















void func_021BCB9C(void *p, int keep)
{
    func_021BD0A0((FieldPlaceNameWork *)p, keep);
    func_021BD0A8(p);
    func_021BD0C8(p);
    if (keep == 0) {
        func_02040588(3, 0);
        func_021BC92C((FieldPlaceNameWork *)p);
    }
}















void func_021BCBC8(char *p)
{
    int r6;
    int r5;

    switch (((struct Obj05061 *)p)->f3C) {
    case 0:
    case 4:
    case 6:
        return;
    case 3:
    case 5:
        r6 = 5;
        r5 = 30;
        break;
    case 2:
        r6 = 6;
        r5 = (int)(20.0f * (1.0f - (float)(u32)((struct Obj05061 *)p)->f42 / 10.0f));
        break;
    case 1:
        r6 = 0;
        r5 = 0;
        break;
    }
    func_021BCB9C(p, r6);
    ((struct Obj05061 *)p)->f42 = r5;
}















void func_021BCC3C(void *p)
{
    int r = 0;

    if (func_021BCA88(p)) {
        r = 1;
        func_021BCA6C(p);
    } else if (func_021BCA74(p)) {
        if (func_021BCA8C(p)) {
            r = 1;
        }
        func_021BCA80(p);
    }
    if (r) {
        func_021BCB9C(p, 1);
    }
}













void func_021BCC80(char *p)
{
    u32 w;

    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        func_021BCAB0((int *)p);
        func_021BD0D0((FieldPlaceNameWork *)p);
        break;
    case 1:
        func_020414C4(3);
        func_020414EC(3);
        func_021BC6D0((FieldPlaceNameWork3 *)p);
        func_021BD0D0((FieldPlaceNameWork *)p);
        break;
    case 2:
        func_021BC720((FieldPlaceNameWork5 *)p);
        w = *(u32 *)&((struct Obj00183 *)p)->f24;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        func_0204047C(3, 1);
        func_02040588(3, 0);
        func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
        func_021BC838(p);
        func_021BD0D0((FieldPlaceNameWork *)p);
        break;
    case 3:
        func_021BC848((FieldPlaceNameWork5 *)p);
        if (func_021BC910((FieldPlaceNameWork *)p)) {
            func_021BCB9C(p, 2);
        }
        break;
    }
}












void func_021BCD34(FieldPlaceNameWork *p)
{
    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        func_021BCEB4((char *)p);
        func_02040588(3, 1);
        func_021BD0D0((FieldPlaceNameWork *)p);
        break;
    case 1:
        if (p->h42 > 10) {
            func_021BCB9C(p, 3);
        }
        break;
    }
}












void func_021BCD70(FieldPlaceNameWork *p)
{
    if (p->h42 > 10) {
        func_021BCB9C(p, 4);
    }
}











void func_021BCD84(char *p)
{
    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        p[0x149] = 0;
        func_021BD0D0((FieldPlaceNameWork *)p);
        break;
    case 1:
        if (((struct Obj01123 *)p)->f42 % 3 == 0) {
            func_021BC948((FieldPlaceNameWork *)p);
            if (((struct Obj01123 *)p)->f20 <= ((struct Obj01123 *)p)->f149) {
                func_021BCB9C(p, 5);
            }
        }
        break;
    }
}











void func_021BCDD8(char *p)
{
    int r6 = 1;
    int i;

    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        for (i = 0; i < ((struct Obj01123 *)p)->f20; i++) {
            u32 v = *(u32 *)(p + 0xc8 + i * 4);
            if (v != 0 && func_021BD20C((char *)v) != 0) {
                r6 = 0;
                break;
            }
        }
        if (r6 != 0) {
            func_021BC9C0(p);
            func_021BD0D0((FieldPlaceNameWork *)p);
        }
        break;
    case 1:
        func_021BC9CC(p);
        if (func_021BCA48((FieldPlaceNameWork *)p) != 0) {
            func_021BD0D0((FieldPlaceNameWork *)p);
        }
        break;
    case 2:
        func_02045334((struct Descriptor *)((struct Obj01123 *)p)->f24);
        func_021BD0D0((FieldPlaceNameWork *)p);
        break;
    case 3:
        func_021BC92C((FieldPlaceNameWork *)p);
        func_021BD0D0((FieldPlaceNameWork *)p);
        break;
    case 4:
        if (((struct Obj01123 *)p)->f42 > 0x1e) {
            func_021BCB9C(p, 6);
        }
        break;
    }
}











void func_021BCE88(char *p)
{
    if (((struct Obj01123 *)p)->f42 > 0x14) {
        func_021BCB9C(p, 0);
        func_02040588(3, 0);
        func_021BC92C((FieldPlaceNameWork *)p);
    }
}










void func_021BCEAC(int a)
{
}










/*
 * Unlabelled leaf (bx lr stub) filed as the blocker of func_021BC4F0.
 */
void func_021BCEB0(int a)
{
}











void func_021BCEB4(char *p)
{
    float t;
    int a;

    t = (float)(u32)((struct Obj20118 *)p)->f42 / 10.0f;
    a = (int)(16.0f * t);
    func_0207D63C(0x04000050, 8, 0x11, a, (int)(4.0f + 12.0f * (1.0f - t)));
}










void func_021BCF18(int a)
{
}









/*
 * Unlabelled leaf (bx lr stub) filed as the blocker of func_021BC4F0.
 */
void func_021BCF1C(int a)
{
}









void func_021BCF20(int a)
{
}










void func_021BCF24(char *p)
{
    float t;
    int a;

    t = (float)(u32)((struct Obj20119 *)p)->f42 / 20.0f;
    a = (int)(16.0f * (1.0f - t));
    func_0207D63C(0x04000050, 8, 0x11, a, (int)(4.0f + 12.0f * t));
}










void *func_021BCF88(int a)
{
    return func_02030734(a, 0x154, 1, (const char *)&d_021DE354, 0x73C);
}









/*
 * Addresses are Black-image addresses.
 */
void func_021BCFA4(X *x, u32 b)
{
    func_02082BCC(x, 0, 0x154);
    x->f0 = b;
    x->f4 = (u32)func_020120F4((const struct Ctx *)b);
    x->f28 = -1;
    x->f4C = 0;
    x->f48 = 0;
    x->f44 = 0x1AB;
    x->f46 = 0x1AB;
}










/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCFD8(int a)
{
    func_020307B0((void *)a);
}










void func_021BCFE0(Obj_021BCFE0 *p)
{
    p->f8 = func_0201EC64(func_021BD090((u8 *)p));
}










void func_021BCFF0(FieldPlaceNameWork5 *p)
{
    p->f14 = func_02045B38(0, 2, 0x59, func_021BD090((u8 *)p));
}










void func_021BD008(Obj_021BD008 *p)
{
    p->f1C = func_020457B0(0x21, func_021BD090((u8 *)p));
}










void func_021BD01C(FieldPlaceNameWork5 *p)
{
    func_021BD090((unsigned char *)p);
    p->f24 = (void *)func_020450F0(3, 0, 1, 0x20, 2, 0, 0);
}










void func_021BD040(Obj_021BCFE0 *p)
{
    if (p->f8 != 0) {
        func_0201ED04(p->f8);
        p->f8 = 0;
    }
}










/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD054(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f14;
    if (v != 0) {
        func_02045C04((struct Rec *)v);
        ((struct Obj00575 *)p)->f14 = 0;
    }
}










void func_021BD068(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f1C;
    if (v != 0) {
        func_02045808((struct U16Vec *)v);
        ((struct Obj00575 *)p)->f1C = 0;
    }
}










void func_021BD07C(FieldPlaceNameWork5 *p)
{
    if (p->f24 != 0) {
        func_020452E8(p->f24);
        p->f24 = 0;
    }
}










/*
 * Loads the 16-bit halfword at +0xc of the object.
 */
u16 func_021BD090(u8 *p)
{
    return ((struct Obj18206 *)p)->fC;
}










u32 func_021BD094(u8 *p)
{
    return ((struct Obj18207 *)p)->f10;
}










void func_021BD098(Obj_021BD098 *p, int v)
{
    p->hC = v;
}










/*
 * Field setter at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD09C(u8 *p, u32 v)
{
    ((struct Obj18208 *)p)->f18 = v;
}










void func_021BD0A0(FieldPlaceNameWork *p, int v)
{
    p->f3C = v;
}










u32 func_021BD0A4(u8 *p)
{
    return ((struct Obj18209 *)p)->f3C;
}










void func_021BD0A8(char *p)
{
    ((struct Obj20122 *)p)->f42 = 0;
}










void func_021BD0B0(FieldPlaceNameWork *p)
{
    p->h42++;
}










u8 func_021BD0C0(u8 *p)
{
    return ((struct Obj18210 *)p)->f40;
}










void func_021BD0C8(char *p)
{
    ((struct Obj20124 *)p)->f40 = 0;
}










void func_021BD0D0(FieldPlaceNameWork *p)
{
    p->b40++;
}










void func_021BD0E0(Obj_021BD0E0 *p)
{
    p->h46 = func_02008998(func_02008854(func_02012EBC(func_020120F4(p->f0))));
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BD0FC(u32 a)
{
return func_020089A0((u32)func_02008854(func_02012EBC(func_020120F4((const struct Ctx *)(((struct Obj00575 *)((u8 *)(a)))->f0)))), *(u16 *)((u8 *)((a + 70))));
}










u16 func_021BD118(u8 *p)
{
    return ((struct Obj18211 *)p)->f46;
}










void func_021BD120(FieldPlaceNameWork *p, u16 v)
{
    p->h44 = p->h46;
    p->h46 = v;
}










u32 func_021BD134(u8 *p)
{
    return ((struct Obj18214 *)p)->f1C;
}










/*
 * Loads the byte at byte +0x20 of the object.
 */
u8 func_021BD138(u8 *p)
{
    return ((struct Obj18215 *)p)->f20;
}










u32 func_021BD140(u32 a)
{
    return func_02013E6C(a);
}










void *func_021BD148(int a0, int a1, u16 a2, int a3)
{
    void *p = func_021BD214(a0);
    func_021BD234((FieldPlaceNameWork5 *)p);
    func_021BD2BC(p, a0);
    func_021BD250((Obj_021BD250 *)p);
    func_021BD278(p, a1, a2, a3);
    func_021BD5F8(p, 0);
    return p;
}










void func_021BD184(void *a)
{
func_021BD2A4(a);
func_021BD264((u8 *)a);
func_021BD22C(a);
}










void func_021BD19C(u32 a, u32 b)
{
func_021BD2C4((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f20);
func_021BD2D0((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f24);
func_021BD30C((char *)a);
func_021BD57C((u8 *)a);
func_021BD588((u32 *)a);
func_021BD554((Obj_021BD554 *)a, (Src_021BD554 *)b);
}










/*
 * Tail-call thunk: forwards to func_021BD3BC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD1CC(void *a)
{
    func_021BD3BC(a);
}










void func_021BD1D4(void *a)
{
    func_021BD474((FieldPlaceNameWork5 *)a);
}










/*
 * Tail-call thunk: forwards to func_021BD308 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021BD1DC(u8 *a0)
{
    return func_021BD308(a0);
}










/*
 * Tail-call thunk: forwards to func_021BD5F8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD1E4(void *p, unsigned int a)
{
func_021BD5F8(p, a);
}












int func_021BD1EC(u8 *a0)
{
    return func_021BD2F4(a0);
}












/*
 * Tail-call thunk: forwards to func_021BD2FC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021BD1F4(u8 *a0)
{
    return func_021BD2FC(a0);
}












/*
 * Tail-call thunk: forwards to func_021BD2DC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD1FC(u32 *a0)
{
    return func_021BD2DC(a0);
}












/*
 * Tail-call thunk: forwards to func_021BD2E8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD204(u32 *a0)
{
    return func_021BD2E8(a0);
}












/*
 * Unlabelled leaf: tail call to func_021BD2D8 (loads +0x44).
 */
unsigned int func_021BD20C(char *p)
{
    return func_021BD2D8((u8 *)p);
}












void *func_021BD214(int a)
{
    return func_02030734(a, 0x4C, 0, (const char *)&d_021DE368, 0x170);
}












/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD22C(void *a0)
{
    return func_020307B0(a0);
}












void func_021BD234(FieldPlaceNameWork5 *p)
{
    func_02082BCC(p, 0, 0x4C);
    p->f44 = 0;
    p->h48 = func_02045A98();
}












void func_021BD250(Obj_021BD250 *p)
{
    p->f8 = func_02043678(2, 2, 0x20, p->h0);
}












void func_021BD264(u8 *p)
{
    u32 v = ((struct Obj06054 *)p)->f8;
    if (v != 0) {
        func_020437AC((struct Obj020437AC *)v);
        ((struct Obj06054 *)p)->f8 = 0;
    }
}












void func_021BD278(Obj_021BD278 *p, int a, u16 b, int c)
{
    Desc d;

    d.f0 = p->f8;
    d.h4 = 0;
    d.h6 = 0;
    d.f8 = c;
    d.fC = 0;
    d.b10 = 0;
    d.b11 = 0;
    d.h12 = b;
    d.f14 = 0;
    p->fC = func_020255A0((struct Sys *)a, (const struct Param *)(&d));
}












void func_021BD2A4(Obj_021BD5D4 *p)
{
    if (p->fC != 0) {
        func_0202570C(p->fC);
        p->fC = 0;
    }
}












/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BD2B8(u8 *p)
{
    return ((struct Obj18217 *)p)->f0;
}












/*
 * Field setter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2BC(u8 *p, int v)
{
    ((struct Obj18218 *)p)->f0 = v;
}












/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021BD2C0(u8 *p)
{
    return ((struct Obj18219 *)p)->f4;
}












void func_021BD2C4(u8 *p, u32 v)
{
    ((struct Obj18220 *)p)->f4 = v;
}












/*
 * Loads the halfword at byte +0x48 of the object.
 */
u16 func_021BD2C8(u8 *p)
{
    return ((struct Obj18221 *)p)->f48;
}












/*
 * Field setter at +0x48 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2D0(u8 *p, u16 v)
{
    ((struct Obj18222 *)p)->f48 = v;
}












/*
 * Loads the 32-bit word at byte +0x44 of the object.
 */
u32 func_021BD2D8(u8 *p)
{
    return ((struct Obj18223 *)p)->f44;
}












/*
 * Unlabelled tail-call thunk on the word at +0x10; callee of func_021BD1FC.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD2DC(u32 *p)
{
    return func_0209C494(p[4]);
}












/*
 * Unlabelled tail-call thunk on the word at +0x14; callee of func_021BD204.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD2E8(u32 *p)
{
    return func_0209C494(p[5]);
}












u8 func_021BD2F4(u8 *p)
{
    return ((struct Obj18226 *)p)->f40;
}












/*
 * Unlabelled leaf byte getter at +0x41.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021BD2FC(u8 *p)
{
    return ((struct Obj18227 *)p)->f41;
}












/*
 * Returns the object pointer advanced by 0x10 bytes.
 */
u8 *func_021BD304(u8 *p)
{
    return p + 0x10;
}












int func_021BD308(u8 *p)
{
    return ((struct Obj18228 *)p)->f8;
}












void func_021BD30C(char *p)
{
    u32 a;
    u16 b;

    a = func_021BD2C0((u8 *)p);
    b = func_021BD2C8((u8 *)p);
    func_021BD604(a, b, func_021BD2B8((u8 *)p), (u8 *)p + 0x40, (u8 *)p + 0x41);
}











int func_021BD340(void *a)
{
if (func_021BD2D8((u8 *)a) == 0) {
    return 1;
}
if (func_021BD36C((void *)a) != 0) {
    if (func_021BD394((void *)a) != 0) {
        return 1;
    }
}
return 0;
}











int func_021BD36C(void *p)
{
    FieldPlaceNameWork *q = (FieldPlaceNameWork *)func_021BD304(p);

    if (func_021BD2D8(p) == 0) {
        return 1;
    }
    if (q->f28 <= 0) {
        return 1;
    }
    return 0;
}











int func_021BD394(void *p)
{
    FieldPlaceNameWork *q = (FieldPlaceNameWork *)func_021BD304(p);

    if (func_021BD2D8(p) == 0) {
        return 1;
    }
    if (q->f2C <= 0) {
        return 1;
    }
    return 0;
}









void func_021BD3BC(void *p)
{
    if (func_021BD2D8(p)) {
        func_021BD3EC(p);
        func_021BD430(p);
        func_021BD5D4((Obj_021BD5D4 *)p);
        if (func_021BD340(p) == 1) {
            func_021BD47C(p);
        }
    }
}








void func_021BD3EC(S_021BD3EC_021BBDD4 *p)
{
    FieldPlaceNameWork *q;

    if (func_021BD36C(p) == 1) {
        return;
    }
    q = &p->t;
    p->t.f00 = p->t.f00 + (q->f08 + q->f10 / 2.0f);
    q->f08 = q->f08 + q->f10;
    q->f28 = q->f28 - 1;
    if (q->f28 == 0) {
        q->f00 = q->f18;
    }
}








void func_021BD430(S_021BD3EC_021BD430 *p)
{
    FieldPlaceNameWork *q;

    if (func_021BD394(p) == 1) {
        return;
    }
    q = &p->t;
    q->f04 = q->f04 + (q->f0c + q->f14 / 2.0f);
    q->f0c = q->f0c + q->f14;
    q->f2C = q->f2C - 1;
    if (q->f2C == 0) {
        q->f04 = q->f1c;
    }
}









void func_021BD474(FieldPlaceNameWork5 *p)
{
    p->f44 = 1;
}









void func_021BD47C(u8 *p)
{
    ((struct Obj18232 *)p)->f44 = 0;
}









void func_021BD484(Obj_021BD484 *obj)
{
    float dx;
    float dy;
    FieldPlaceNameWork *s;

    s = &obj->s;
    dx = s->f18 - obj->s.f00;
    dy = s->f1c - s->f04;

    if (dx != 0.0f) {
        s->f10 = (s->f20 * s->f20 - s->f08 * s->f08) / (2.0f * dx);
    }
    if (dy != 0.0f) {
        s->f14 = (s->f24 * s->f24 - s->f0c * s->f0c) / (2.0f * dy);
    }
    if (s->f10 != 0.0f) {
        s->f28 = (s->f20 - s->f08) / s->f10;
    }
    if (s->f14 != 0.0f) {
        s->f2C = (s->f24 - s->f0c) / s->f14;
    }
}











void func_021BD554(Obj_021BD554 *p, Src_021BD554 *s)
{
    p->a = s->a;
    p->b = s->b;
    p->c = s->c;
    p->d = s->d;
    p->e = s->e;
    p->f = s->f;
    p->g = s->g;
    func_021BD484((Obj_021BD484 *)p);
}











/*
 * Tail call on the word at +8 with a zero second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD57C(u8 *p)
{
    func_02043B5C((struct CharBuf *)(((struct Obj18234 *)p)->f8), 0);
}











void func_021BD588(u32 *p)
{
    u16 buf[2];
    u32 h;

    buf[0] = func_021BD2C8((u8 *)p);
    buf[1] = func_02045A98();
    h = (u32)func_020457B0(2, ((struct Obj02719 *)p)->f0);
    func_02045994((struct Strbuf *)h, buf, 2);
    func_0201C7D0((void *)p[2], 0, 0, (void *)h, (void *)p[1], 0x440);
    func_020257D0((struct Obj *)p[3]);
    func_02045808((struct U16Vec *)h);
}











void func_021BD5D4(Obj_021BD5D4 *p)
{
    Q *q = (Q *)func_021BD304((u8 *)p);
    int x = (int)q->f0;
    int y = (int)q->f4;

    func_0202590C(p->fC, x, y);
}











/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD5F8(void *p, unsigned int a)
{
func_02025774((u8 *)((struct Obj18235 *)p)->fC, a);
}











void func_021BD604(u32 a, u16 b, u32 c, u8 *d, u8 *e)
{
    u16 buf[2];
    u32 h;

    buf[0] = b;
    buf[1] = func_02045A98();
    h = (u32)func_020457B0(2, c);
    func_02045994((struct Strbuf *)h, buf, 2);
    *d = func_0201D304((struct StrObj *)h, a, 0);
    *e = func_0201D42C((struct StrObj *)h, (void *)a);
    func_02045808((struct U16Vec *)h);
}











void *func_021BD648(Arg *p)
{
    Tbl t = d_021D9BB0;
    int i;
    void *task;
    Work *w;

    switch (p->f10) {
    case 0:
        i = 0;
        break;
    case 1:
        i = 0;
        break;
    case 2:
        i = 2;
        break;
    case 3:
        i = 1;
        break;
    case 4:
        i = 2;
        break;
    case 5:
        i = 3;
        break;
    case 6:
        i = 5;
        break;
    default:
        i = 4;
        break;
    }
    task = func_020122C0(p->f04, (void *)p->f00, t.f[i], 12);
    w = func_020124E8(task);
    w->f04 = 0;
    w->f08 = p;
    return task;
}











/*
 * Addresses are Black-image addresses.
 */
u32 func_021BD6C0(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];

    switch (*st) {
    case 0:
        func_021BD94C((Obj_021BD93C *)ctx);
        if (((struct Obj20132 *)p)->f38 != 2)
            func_020061E4(0x559);
        func_021BD988((Obj_021BD988 *)ctx, a);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}











int func_021BD704(u32 a, int *st, u32 *ctx)
{
    u32 p = ctx[2];

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7E3C((struct Args *)p));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}











u32 func_021BD734(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 x = ((struct Obj12883 *)p)->fC;

    switch (*st) {
    case 0:
        if (func_021BD8C0(ctx))
            func_021BD96C((Obj_021BD96C *)ctx, (void *)a);
        else
            func_021BD94C((Obj_021BD93C *)ctx);
        ctx[1] = func_02161B1C((void *)x);
        (*st)++;
        break;
    case 1:
        if (func_02161B74(ctx[1])) {
            if (((struct Obj12883 *)p)->f38 != 2)
                func_020061E4(0x559);
            func_021BD988((Obj_021BD988 *)ctx, a);
            (*st)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}










int func_021BD7A8(void *task, u32 *state, Ctx *ctx)
{
    Cfg *cfg = ctx->cfg;
    u32 x = cfg->f04;
    u32 y = cfg->f0C;

    switch (*state) {
    case 0:
        func_02012374(task, func_021BFE00(0, (void *)x, y));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}










u32 func_021BD7E0(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 h = (u32)func_02188C58((void *)(*(u32 *)&((struct Obj03588 *)p)->fC));

    switch (*st) {
    case 0:
        if (func_0218F0F8((u8 *)h) && func_0218F0E8((u8 *)h)) {
            func_0218F0A8((u8 *)h);
            *st = 1;
        } else {
            *st = 2;
        }
        return 0x21;
    case 1:
        if (!func_0218F0F8((u8 *)h)) {
            *st = 2;
            return 0x21;
        }
        if (func_0218F0E8((u8 *)h))
            break;
        func_0218EC54((u8 *)h);
        *st = 2;
        return 0x21;
    case 2:
        func_02012374((struct Evt *)a, func_021A7E3C((struct Args *)((u32)p)));
        *st = 3;
        return 0x21;
    case 3:
        return 1;
    }
    return 0;
}










u32 func_021BD874(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[2];
    u32 x = p[1];
    u32 y = p[3];

    switch (*st) {
    case 0:
        func_021BD94C((Obj_021BD93C *)ctx);
        func_020061E4(0x737);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE8D4((void *)x, y, 2, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}








u32 func_021BD8C0(u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 q = ((struct Obj12889 *)p)->f8;

    if (!func_021BD904((Obj_021BD904 *)ctx))
        return 0;
    if (func_02029E08(q, ((struct Obj12889 *)p)->f20))
        return 0;
    if (func_021BD93C(ctx) == 1 && (u32)func_02029DFC((const void *)q) == 0x3F4)
        return 0;
    return 1;
}









int func_021BD904(Obj_021BD904 *o)
{
    Ent *e = o->e;
    void *s = (void *)func_0202B580((void *)func_02012134((u32 *)e->x4));

    if (func_0202B434(s) && func_0202B438(s, e->h18) && func_0202B438(s, e->h20)) {
        return 1;
    }
    return 0;
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD93C(void *a)
{
return func_021A3098(func_02188CB4((struct Obj00020 *)(*(u32 *)((u8 *)(((struct Obj18244 *)((u8 *)(a)))->f8) + 12))));
}










void func_021BD94C(Obj_021BD93C *p)
{
    Inner_021BD904 *q = p->f8;
    void *r = q->f8;

    func_02029D44(func_02012A30(r), (u32)r, q->h20, q->b45);
    q->f48 = 1;
}









void func_021BD96C(Obj_021BD96C *p, void *b)
{
    Inner_021BD96C *q = p->f8;

    func_02012374(b, (struct Evt **)func_0202952C(q->f4, 0x1E));
    q->f4C = 1;
}









void func_021BD988(Obj_021BD988 *o, int b)
{
    Sub_021BD988 *s = o->f8;
    int sel = s->f40;
    void *p = s->f4;
    int c = s->fC;

    if (sel != 0) {
        func_02012374((struct Evt *)b, (struct Evt **)func_021BE8D4(p, c, 0, 0));
    } else {
        func_02012374((struct Evt *)b, (struct Evt **)func_021BE8D4(p, c, s->f38, 0));
    }
}









/*
 * Addresses are Black-image addresses.
 */
int func_021BD9BC(u32 *p)
{
    T6 t = d_021D9BC8;
    u32 i;
    u32 r;

    switch (p[5]) {
    case 0:
        i = 0;
        break;
    case 1:
        i = 0;
        break;
    case 2:
        i = 2;
        break;
    case 3:
        i = 1;
        break;
    case 4:
        i = 2;
        break;
    case 5:
        i = 3;
        break;
    case 6:
        i = 5;
        break;
    default:
        i = 4;
        break;
    }
    r = (u32)func_020122C0((void *)p[1], (void *)p[0], (void *)t.v[i], 4);
    *(u32 *)func_020124E8((void *)r) = (u32)p;
    return r;
}









u32 func_021BDA30(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];

    switch (*st) {
    case 0:
        if (((struct Obj20137 *)p)->f48 != 0)
            func_021BDBF8((u32)ctx);
        func_021BDC2C(ctx, a);
        (*st)++;
        break;
    case 1:
        func_021BDC80((Obj_021BDC2C *)ctx);
        return 1;
    }
    return 0;
}








u32 func_021BDA70(u32 a, u32 *st, u32 *p)
{
    u32 v = p[0];
    switch (st[0]) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7B20((struct Args *)v));
        st[0]++;
        break;
    case 1:
        func_021BDC80((Obj_021BDC2C *)p);
        return 1;
    }
    return 0;
}









u32 func_021BDAA8(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj07540 *)p)->f4;
    u32 y = ((struct Obj07540 *)p)->fC;

    switch (*st) {
    case 0:
        func_021BDC2C(ctx, a);
        (*st)++;
        break;
    case 1:
        if (((struct Obj07540 *)p)->f48 != 0)
            func_021BDBF8((u32)ctx);
        else if (((struct Obj07540 *)p)->f4C != 0)
            func_021BDC0C((Obj_021BD9BC *)ctx, (void *)a);
        (*st)++;
        break;
    case 2:
        func_02012374((struct Evt *)a, (struct Evt **)func_021618E0((void *)x, (void *)y));
        (*st)++;
        break;
    case 3:
        func_021BDC80((Obj_021BDC2C *)ctx);
        return 1;
    }
    return 0;
}








u32 func_021BDB1C(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj12894 *)p)->f4;
    u32 y = ((struct Obj12894 *)p)->fC;

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BF644(0, x, y));
        (*st)++;
        break;
    case 1:
        func_021BDC80((Obj_021BDC2C *)ctx);
        return 1;
    }
    return 0;
}








u32 func_021BDB5C(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[0];

    func_02188C58((void *)p[3]);
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7B20((struct Args *)((u32)p)));
        (*st)++;
        break;
    case 1:
        func_021BDC80((Obj_021BDC2C *)ctx);
        return 1;
    }
    return 0;
}








u32 func_021BDB9C(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj09653 *)p)->f4;
    u32 y = ((struct Obj09653 *)p)->fC;

    switch (*st) {
    case 0:
        if (((struct Obj09653 *)p)->f48 != 0)
            func_021BDBF8((u32)ctx);
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 2, 0, 0, 0, 0));
        (*st)++;
        break;
    case 2:
        func_021BDC80((Obj_021BDC2C *)ctx);
        return 1;
    }
    return 0;
}







int func_021BDBF8(u32 a)
{
return func_02029D7C(func_02012A30((const struct BigObj *)*(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8)), *(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8));
}







void func_021BDC0C(Obj_021BD9BC *p, void *b)
{
    Inner_021BDC0C *q = p->f0;
    void *r = q->f4;

    func_02012A30(q->f8);
    func_02012374(b, (struct Evt **)func_020294C0(r, 6));
}






void func_021BDC2C(u32 *ctx, u32 a)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj05065 *)p)->f4;
    u32 y = ((struct Obj05065 *)p)->fC;

    if (((struct Obj05065 *)p)->f40 != 0)
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 3, 0, 0, p[0x44], p[0x45]));
    else
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, ((struct Obj05065 *)p)->f3C, 0, 1, 0, 0));
}






void func_021BDC80(Obj_021BDC2C *p)
{
    Inner_021BDC80 *q = p->f0;

    func_021BC550((void *)func_02188D20(q->fC), q->s20);
}






void *func_021BDC94(void *a)
{
    void *x = (void *)func_02188C84(a);
    void *r = func_021BDD58((int)x);

    func_021BDD7C((Obj_021BDD7C *)r, a);
    func_021BDD9C((Obj_021BDD9C *)r, x);
    return r;
}






void func_021BDCB8(u8 *p)
{
    func_021BDDAC((FieldPlaceNameWork3 *)p);
    func_021BDD74(p);
}






void func_021BDCC8(char *a, int *b)
{
    func_021BE184((FieldPlaceNameWork3 *)a, (V3 *)b);
    func_0218FEA0(((struct Obj00282 *)a)->f54, (u32)(a + 8));
    if (func_021BE1A0((u32)a) != 0) {
        switch (b[1]) {
        case 0:
            func_021BDFB0(a);
            break;
        case 1:
            func_021BE068((A *)a);
            break;
        }
    } else {
        switch (b[1]) {
        case 0:
            func_021BDDC0((Obj_021BDDC0 *)a);
            break;
        case 1:
            func_021BDEB4((A *)a);
            break;
        }
    }
    ((struct Obj00282 *)a)->f64 = 1;
}






void func_021BDD20(FieldPlaceNameWork3 *p)
{
    if (func_021BE1C4((u32)p)) {
        func_0218FF00((u32)p->f54);
    }
}






/*
 * Tail-call thunk: the object's word at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BDD34(u8 *p)
{
    func_0218FF20((u8 *)(((struct Obj18252 *)p)->f54));
}






int func_021BDD40(void *a)
{
    return func_021BE1C4((u32)a);
}






int func_021BDD48(Obj_021BDD48 *o)
{
    if (o->f08 == 0) {
        return 1;
    }
    return 0;
}






void *func_021BDD58(int a)
{
    return func_02030734(a, 0x70, 0, (const char *)&d_021DE37C, 0x12A);
}






/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BDD74(void *p)
{
    func_020307B0(p);
}






void func_021BDD7C(Obj_021BDD7C *p, void *a)
{
    func_02082BCC(p, 0, 0x70);
    p->f0 = a;
    p->f4 = func_02188C58(a);
    p->f64 = 0;
}






void func_021BDD9C(Obj_021BDD9C *p, void *x)
{
    p->f54 = func_0218FE80(p->f0);
}






void func_021BDDAC(FieldPlaceNameWork3 *p)
{
    if (p->f54 != 0) {
        func_0218FE98();
        p->f54 = 0;
    }
}






/*
 * The unused `zero` vector is a dead initialised local: an initialiser keeps
 * its three stores (plain assignments are eliminated), and declaring it in an
 * inner block schedules them between the two func_0218FE78 calls.  The
 * rotation halfword is u16 (pool word 0x0000F5F7, not 0xFFFFF5F7).
 */
void func_021BDDC0(Obj_021BDDC0 *p)
{
    FieldPlaceNameWork4 *s = &p->s;
    Rot *t = &s->f24;
    FieldPlaceNameWork2 out;
    void *h;
    int mode;

    func_021BE17C((u8 *)p);
    h = func_02188CB4((struct Obj00020 *)p->f0);
    mode = func_021A3050(h);
    switch (mode) {
    case 2:
    case 3:
        p->f68 = 1;
        p->f6C = 0;
        break;
    case 0:
    case 1:
        p->f68 = 0;
        p->f6C = 0;
        break;
    }
    if (p->f68 == 0) {
        return;
    }
    s->f48 = 0;
    s->f44 = 0;
    if (func_021BE1B0((u32)p)) {
        func_021A7B08(p->f0, (struct V3 *)(&out));
    } else {
        func_021A3038(h, (struct VecFx32 *)&out);
    }
    func_0218FEA4(p->f54);
    func_0218FE78(p->f4, &s->f4);
    {
        FieldPlaceNameWork2 zero = {0, 0, 0};
        func_0218FE78(p->f4, t);
    }
    switch (mode) {
    case 0:
        t->f4 = 0xB4000;
        break;
    case 1:
        break;
    case 2:
        t->f2 = 0xA09;
        break;
    case 3:
        t->f2 = -0xA09;
        break;
    }
    switch (mode) {
    case 0:
        s->f0 = 0;
        break;
    case 1:
        s->f0 = 0;
        break;
    case 2:
        s->f0 = 10;
        break;
    case 3:
        s->f0 = 10;
        break;
    }
}





/*
 * Same object layout as func_021BE068. The first switch's arms are laid
 * out in source order, cases 1-3 ahead of case 0 (its table entry for 0 is
 * the later block); the identical arms of the second switch are separate
 * blocks cross-jumped into the case-3 store.
 */
void func_021BDEB4(A *a)
{
    V3 v;
    u32 h;
    void *t;
    int m;
    S_021BDC2C *s = &a->s;
    u8 *sub = s->sub;

    h = func_021BE17C((u8 *)a);
    t = func_02188CB4((struct Obj00020 *)a->obj);
    m = func_021A3050(t);
    switch (m) {
    case 1:
    case 2:
    case 3:
        a->f68 = 0;
        a->f6C = 1;
        break;
    case 0:
        a->f68 = 0;
        a->f6C = 0;
        break;
    }
    if (a->f6C == 0)
        return;
    s->f48 = 0;
    s->f44 = 0;
    if (func_021BE1B0((u32)a) != 0)
        func_021A7B08(a->obj, (struct V3 *)(&v));
    else
        func_021A3038(t, (struct VecFx32 *)&v);
    switch (m) {
    case 0:
        s->f00 = 0;
        break;
    case 1:
        s->f00 = 10;
        break;
    case 2:
        s->f00 = 10;
        break;
    case 3:
        s->f00 = 10;
        break;
    }
    if (func_021BE1B0((u32)a) != 0)
        func_021BE158(h, (u32)(&v));
    func_0218FEA4(a->f54);
    func_0218FE78(a->f04, &s->in);
    switch (m) {
    case 0:
        break;
    case 1:
        s->in.f08 = 0xB4000;
        break;
    case 2:
        s->in.f06 = 0xF5F7;
        break;
    case 3:
        s->in.f06 = 0xA09;
        break;
    }
    func_0218FE78(a->f04, sub);
    if (a->f6C != 0)
        func_0218FEC0((u8 *)a->f54);
}




void func_021BDFB0(char *a)
{
    char *r6 = a + 8;
    char *r4 = r6 + 0x24;
    struct Q q;
    void *r7;
    int t30;
    int x;
    int y;
    int z;

    func_021BE17C((unsigned char *)a);
    r7 = func_02188CB4((struct Obj00020 *)(*(unsigned char * *)&((struct Obj00282 *)a)->f0));
    func_021A3050(r7);
    func_021BE148(&q, func_021BE194((u32)a));
    ((struct Obj09656 *)r6)->f48 = q.f3c;
    ((struct Obj09656 *)r6)->f44 = q.f38;
    t30 = q.f30;
    ((struct Obj00282 *)a)->f68 = t30;
    *(int *)&((struct Obj00282 *)a)->f6C = q.f34;
    if (t30 == 0) {
        return;
    }
    if (func_021BE1B0((u32)a) != 0) {
        func_021A7B08(*(int *)&((struct Obj00282 *)a)->f0, &q.f40);
    } else {
        func_021A3038(r7, (struct VecFx32 *)(&q.f40));
    }
    func_0218FEA4(*(int *)&((struct Obj00282 *)a)->f54);
    func_0218FE78(*(int *)&((struct Obj00282 *)a)->f4, r6 + 4);
    ((struct Obj09656 *)r6)->f0 = q.f2c;
    ((struct Obj03139 *)r4)->f0 = q.f4;
    ((struct Obj03139 *)r4)->f2 = q.f8;
    ((struct Obj03139 *)r4)->f4 = q.fc << 12;
    z = q.f28 << 12;
    y = q.f24 << 12;
    x = q.f20 << 12;
    ((struct Obj03139 *)r4)->f14 = x;
    ((struct Obj03139 *)r4)->f18 = y;
    ((struct Obj03139 *)r4)->f1C = z;
    if (q.f10 != 0) {
        z = q.f1c << 12;
        y = q.f18 << 12;
        x = q.f14 << 12;
        ((struct Obj03139 *)r4)->f8 = x;
        ((struct Obj03139 *)r4)->fC = y;
        ((struct Obj03139 *)r4)->f10 = z;
    } else {
        *(struct V3 *)(r4 + 8) = q.f40;
    }
}




static inline void vset(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}




/*
 * Twin of func_021BDFB0 with the pose block at a+0xC instead of a+0x2C.
 * A function-scope In_021BDC2C pointer is what keeps the else-arm copy's
 * destination as (s+4)+8 in a fresh register; &s->in.pos folds to s+0xC.
 * The two rot/pos V3 writes are VEC_Set-style inline setters (arguments
 * evaluated right to left). The EXACT* is the 2-byte pad after the pop.
 */
void func_021BE068(A *a)
{
    V3 v;
    Rec rec;
    void *t;
    S_021BDC2C *s = &a->s;
    u8 *sub = s->sub;
    In_021BDC2C *in = &s->in;
    u32 h = func_021BE17C((u8 *)a);

    t = func_02188CB4((struct Obj00020 *)a->obj);
    func_021A3050(t);
    func_021BE148(&rec, func_021BE194((u32)a));
    s->f48 = rec.f3C;
    s->f44 = rec.f38;
    a->f68 = rec.f30;
    a->f6C = rec.f34;
    if (a->f6C == 0)
        return;
    if (func_021BE1B0((u32)a) != 0)
        func_021A7B08(a->obj, (struct V3 *)(&v));
    else
        func_021A3038(t, (struct VecFx32 *)&v);
    if (s->f44 != 0 && func_021BE1B0((u32)a) != 0)
        func_021BE158(h, (u32)(&v));
    func_0218FEA4(a->f54);
    func_0218FE78(a->f04, sub);
    s->f00 = rec.f2C;
    in->f04 = rec.f04;
    in->f06 = rec.f08;
    in->f08 = rec.f0C << 12;
    vset(&in->rot, rec.v2.x << 12, rec.v2.y << 12, rec.v2.z << 12);
    if (rec.f10 != 0) {
        vset(&in->pos, rec.v1.x << 12, rec.v1.y << 12, rec.v1.z << 12);
    } else {
        in->pos = v;
    }
    if (a->f6C != 0)
        func_0218FEC0((u8 *)a->f54);
}





void func_021BE148(void *dst, int b)
{
    func_02048F4C(dst, 0xb3, b - 7);
}





int func_021BE158(u32 a, u32 b)
{
func_0218EC54((u8 *)a);
func_0218EC90(a, b);
func_0218E104((u8 *)a, 0);
return func_0218EC60(a);
}





u32 func_021BE17C(u8 *p)
{
    return ((struct Obj18253 *)p)->f4;
}





/*
 * Returns the object pointer advanced by 0x58 bytes.
 */
u8 *func_021BE180(u8 *p)
{
    return p + 0x58;
}




void func_021BE184(FieldPlaceNameWork3 *p, const V3 *v)
{
    p->f58 = *v;
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE194(u32 a)
{
return ((struct Obj18254 *)((u8 *)(func_021BE180((u8 *)a))))->f0;
}




/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02162370 (0x02162370) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE1A0(u32 a)
{
return func_02162370(((struct Obj18255 *)((u8 *)(func_021BE180((u8 *)a))))->f0);
}




int func_021BE1B0(u32 a)
{
if (((struct Obj18256 *)((u8 *)(func_021BE180((u8 *)a))))->f8 == 0) {
    return 1;
}
return 0;
}




int func_021BE1C4(u32 a)
{
if (((struct Obj18257 *)((u8 *)(func_021BE180((u8 *)a))))->f4 == 0) {
    return ((struct Obj09202 *)((u8 *)(a)))->f68;
}
return ((struct Obj09202 *)((u8 *)(a)))->f6C;
}



extern void (*d_021D9CBC[])(void *);




void func_021BE1DC(void *arg)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(arg))));
    if (i != -1) {
        if (d_021D9D98[i] != 0) {
            func_02034AC4((int)d_021D9D98[i]);
        }
        d_021D9CBC[i](arg);
    }
}




extern void (*d_021D9BE0[])(void *);




void func_021BE218(void *arg)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(arg))));
    if (i != -1) {
        if (d_021D9BE0[i] != 0) {
            d_021D9BE0[i](arg);
        }
        if (d_021D9D98[i] != 0) {
            func_02034A5C((int)d_021D9D98[i]);
        }
    }
}
