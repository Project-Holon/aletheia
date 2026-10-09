/*
 * file:     trial_house.c
 * unit:     yes
 * function: func_021CEDA0, func_021CEE00, func_021CEE48, func_021CEE78, func_021CEF08, func_021CEF1C, func_021CF068, func_021CF0F4, func_021CF110, func_021CF128, func_021CF12C, func_021CF164, func_021CF17C, func_021CF188, func_021CF194, func_021CF1AC, func_021CF220, func_021CF288, func_021CF2F0, func_021CF31C, func_021CF32C, func_021CF378, func_021CF3A4, func_021CF3B0, func_021CF3DC, func_021CF3FC, func_021CF45C, func_021CF480, func_021CF498, func_021CF51C, func_021CF520, func_021CF52C, func_021CF54C, func_021CF560, func_021CF564, func_021CF580, func_021CF59C, func_021CF5AC, func_021CF5D8, func_021CF748, func_021CF7DC, func_021CF844, func_021CF8E4, func_021CF940, func_021CF9AC, func_021CFA04, func_021CFA1C, func_021CFA58, func_021CFA88, func_021CFAC0, func_021CFB1C, func_021CFB68, func_021CFBA8, func_021CFC14, func_021CFC4C, func_021CFC80, func_021CFCF4, func_021CFD08, func_021CFD88, func_021CFDBC, func_021CFEA0, func_021CFEF0, func_021CFF28, func_021CFF78, func_021CFFDC, func_021D0014, func_021D004C, func_021D0084, func_021D00B8, func_021D0114, func_021D0140, func_021D0160, func_021D0174, func_021D01D8, func_021D0218, func_021D024C, func_021D028C, func_021D029C, func_021D0308, func_021D0328, func_021D034C, func_021D038C, func_021D03B0, func_021D03C4, func_021D0440, func_021D046C, func_021D04A4, func_021D04C4, func_021D04D8, func_021D0504, func_021D0520, func_021D0568, func_021D05D8, func_021D0610, func_021D0634, func_021D0648, func_021D06E0, func_021D072C, func_021D074C, func_021D0750, func_021D07D8, func_021D07FC, func_021D0824, func_021D08B0, func_021D08BC, func_021D08D8, func_021D0914, func_021D096C, func_021D09D0, func_021D0A48, func_021D0A74, func_021D0AB8, func_021D0AC0, func_021D0AE4, func_021D0B58, func_021D0BCC, func_021D0BD8, func_021D0BE4, func_021D0C58, func_021D0DB0, func_021D0FE0, func_021D0FE8, func_021D1028, func_021D1058, func_021D1080, func_021D10A8
 * address:  0x021CEDA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021909E4  0x021909E4  thumb  ov021
 *   func_0203D000  0x0203D000  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_0203CF10  0x0203CF10  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02008494  0x02008494  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02190A6C  0x02190A6C  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008534  0x02008534  thumb
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190A64  0x02190A64  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0203A574  0x0203A574  arm
 *   data_021DB4BC  0x021DB4BC  data
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_021CEAF8  0x021CEAF8  thumb  ov021
 *   func_021CD624  0x021CD624  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203996C  0x0203996C  arm
 *   func_02008468  0x02008468  thumb
 *   func_021CE724  0x021CE724  thumb  ov021
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_021CE6F0  0x021CE6F0  thumb  ov021
 *   func_021CE70C  0x021CE70C  thumb  ov021
 *   func_021CE718  0x021CE718  thumb  ov021
 *   func_0203D378  0x0203D378  arm
 *   func_021CEADC  0x021CEADC  thumb  ov021
 *   func_021CEB04  0x021CEB04  thumb  ov021
 *   func_0203D4D0  0x0203D4D0  arm
 *   d_021DE5FC     0x021DE5FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0203038C  0x0203038C  arm
 *   func_02012374  0x02012374  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021DB4FC     0x021DB4FC  data  a4
 *   func_02034AC4  0x02034AC4  arm
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 *   ov075_id       0x0000004B  data
 *   func_02034A5C  0x02034A5C  arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013E40  0x02013E40  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB2BC  0x021AB2BC  thumb  ov021
 *   func_021AB364  0x021AB364  thumb  ov021
 *   func_021AB37C  0x021AB37C  thumb  ov021
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A3FC  0x0202A3FC  thumb
 *   func_0202A3D8  0x0202A3D8  thumb
 *   func_02188D58  0x02188D58  thumb  ov021
 *   func_020140D8  0x020140D8  thumb
 *   d_021DB7E0     0x021DB7E0  data  ov021  a2
 *   d_021DB7F6     0x021DB7F6  data  ov021  a1
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_020079BC  0x020079BC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBEC  0x0200BBEC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   abs_id_39      0x00000039  data
 *   d_021F3900     0x021F3900  data  ov057  a4
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   d_021DB834  0x021DB834  data  a4
 *   func_021587B0  0x021587B0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02045994  0x02045994  arm
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200E878  0x0200E878  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02009634  0x02009634  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02025C74  0x02025C74  thumb
 *   func_02025B64  0x02025B64  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0201F048  0x0201F048  thumb
 *   func_02008570  0x02008570  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_02009628  0x02009628  thumb
 *   func_0201F198  0x0201F198  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02009590  0x02009590  thumb
 *   sub_020095C8  0x020095C8  thumb
 *   func_02009698  0x02009698  thumb
 *   sub_020095FC  0x020095FC  thumb
 *   sub_02009618  0x02009618  thumb
 *   func_02011330  0x02011330  thumb
 *   d_021DE608     0x021DE608  data  ov021  a4
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   data_021DB8C4  0x021DB8C4  data  a2
 *   data_021DB8CC  0x021DB8CC  data  a2
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021DB8DC     0x021DB8DC  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1E0  0x021AC1E0  thumb
 *   func_02047804  0x02047804  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_020478B8  0x020478B8  arm
 *   data_021DB8F0  0x021DB8F0  data  ov021  a4
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DE618     0x021DE618  data  ov021  a4
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   data_021DB92C  0x021DB92C  data  ov021  a2
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   d_021DB93C     0x021DB93C  data  ov021  a4
 *   d_021DB934     0x021DB934  data  a4
 *   func_020061E4  0x020061E4  thumb
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021C6744  0x021C6744  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   func_021C67A8  0x021C67A8  thumb  ov021
 *   func_021C6664  0x021C6664  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   d_021DB968     0x021DB968  data  ov021  a4
 *   d_021DE664     0x021DE664  data  ov021  a4
 *   func_02046F50  0x02046F50  arm
 *   d_021DB95C     0x021DB95C  data  a4
 *   d_021DB950     0x021DB950  data  ov021  a4
 *   d_021DB954     0x021DB954  data  ov021  a4
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02047888  0x02047888  arm
 *   d_021DE628     0x021DE628  data  ov021  a4
 *   func_0204784C  0x0204784C  arm
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0200E588  0x0200E588  thumb
 *   func_0201A920  0x0201A920  thumb
 *   d_021DE674     0x021DE674  data  a4
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200E5A0  0x0200E5A0  thumb
 *   func_0200E5CC  0x0200E5CC  thumb
 *   func_0200734C  0x0200734C  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_02168878  0x02168878  thumb  ov010
 *   func_0200E5F8  0x0200E5F8  thumb
 *   func_02168AEC  0x02168AEC  thumb  ov010
 *   func_021680C8  0x021680C8  thumb  ov010
 *   d_0209DF0C     0x0209DF0C  data  a1
 *   func_021576D0  0x021576D0  thumb  ov010
 *   func_021578A0  0x021578A0  thumb  ov010
 *   func_02157928  0x02157928  thumb  ov010
 *   func_021578F0  0x021578F0  thumb  ov010
 *   func_02157910  0x02157910  thumb  ov010
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_0200E5E4  0x0200E5E4  thumb
 *   func_0200E608  0x0200E608  thumb
 *   func_02157938  0x02157938  thumb  ov010
 *   func_0203D210  0x0203D210  arm
 *   func_02008C58  0x02008C58  thumb
 *   func_02008E88  0x02008E88  thumb
 *   func_02008E68  0x02008E68  thumb
 *   func_021D1164  0x021D1164  thumb  ov021
 *   func_021D11B0  0x021D11B0  thumb  ov021
 *   func_0200E684  0x0200E684  thumb
 *   func_02012E4C  0x02012E4C  thumb
 *   func_02012E7C  0x02012E7C  thumb
 *   func_021D11D8  0x021D11D8  thumb  ov021
 *   func_021D1194  0x021D1194  thumb  ov021
 */
#include "../../matched/include/Obj00011.h"
#include "../../matched/include/Obj09739.h"
#include "../../matched/include/Obj04295.h"
#include "../../matched/include/Obj20269.h"
#include "../../matched/include/Obj12140.h"
#include "../../matched/include/Obj20270.h"
#include "../../matched/include/Obj03621.h"
#include "../../matched/include/Obj12992.h"
#include "../../matched/include/Obj12993.h"
#include "../../matched/include/Obj20274.h"
#include "../../matched/include/Obj06104.h"
#include "../../matched/include/Obj12997.h"
#include "../../matched/include/Obj09743.h"
#include "../../matched/include/Obj13000.h"
#include "../../matched/include/Obj18369.h"
#include "../../matched/include/Obj09745.h"
#include "../../matched/include/Obj07595.h"
#include "../../matched/include/Obj20289.h"
#include "../../matched/include/Obj20290.h"
#include "../../matched/include/Obj20291.h"
#include "../../matched/include/Obj18370.h"
#include "../../matched/include/Obj20292.h"
#include "../../matched/include/Obj13002.h"
#include "../../matched/include/Obj20293.h"
#include "../../matched/include/Obj20294.h"
#include "../../matched/include/Obj20300.h"
#include "../../matched/include/Obj20301.h"
#include "../../matched/include/Obj18371.h"

#define U32(o) (*(u32 *)(w + (o)))
struct Handle;
struct WordSet;
struct MsgBank;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct Entry;
struct Link;
struct Res021CF;
struct Evt;
struct Obj;
struct Obj00020;
struct Sub020140BCObj;
struct Desc;
struct Ctx;
struct BigObj;
struct Big;
struct IdList021CFA1C;
struct Sub02008828Obj;
struct Rec_021CEDA0;
struct Sub02009470Obj;
struct Sub02009470Ent;
struct Tbl021CFCF4;
struct Stream;
struct Tagged;
struct B_021CF3B0;
struct AnmCtl;
struct G3dSys;
struct Owner;
struct G3dOwner;
struct G3dRec;
struct Arg;
struct W_021CEDA0;
struct Actor;
struct VecFx32;
struct S_021CFC80;
struct Row20;
struct Party;
struct Sub020073D8Ctrl;
struct Sub02007324Ctrl;
struct Flags;
struct Sub02008C20Obj;
typedef unsigned char  u8;

typedef short          s16_021CEDA0;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8  name[0x20];
    u8  mac[6];
    u8  used;
    u8  pad;
    s16_021CEDA0 timer;
    u8  pad2[2];
} Ent_021CEDA0;

typedef struct {
    u32  f0;
    u32  f4;
    Ent_021CEDA0  e[16];
    Ent_021CEDA0 *cur;
    u8   pad[5];
    u8   f2d1;
    u8   pad2[2];
    u16  f2d4;
} N;

typedef struct Sub021CEE48 {
    u8 pad0[6];
    u16 id;
} Sub021CEE48;

typedef struct Ent021CEE48 {
    u8 pad0[0x20];
    Sub021CEE48 sub;
} Ent021CEE48;

typedef struct {
    u8  name[0x20];
    u8  mac[6];
    u8  used;
    u8  pad;
    s16_021CEDA0 timer;
    u8  pad2[2];
} Ent_021CEE78;

typedef signed int     s32;

typedef struct {
    u8 pad0[0x26];
    u8 on;
    u8 pad27[5];
} Ent_021CEF1C;

typedef struct {
    u32 f0, f4, f8;
    u8 padc[0x13c - 0xc];
    u32 f13c;
    u32 f140;
    Ent_021CEF1C ents[16];
    u8 pad404[0x40e - 0x404];
    u8 f40e;
    u8 pad40f[0x528 - 0x40f];
    u16 f528;
} S_021CEDA0;

typedef signed short   s16_021CF0F4;

typedef signed char    s8;

typedef signed short   s16;

typedef struct {
    u8 name[0x20];
    u8 x[8];
} B_021CEDA0;

typedef struct Ent {
    u32 (*fn)(u32, void *, u32);   /* 0x00 */
    u32 f04;                       /* 0x04 */
    int f08;                       /* 0x08 */
    u32 f0c;                       /* 0x0C */
    u32 f10;                       /* 0x10 */
} Ent;

typedef struct Ctx {
    u32 f00;
    u32 f04;
    void *f08;
} Ctx;

typedef struct Res021CF {
    u8 pad0[0xc];
    u32 ids[3];
    int n;
} Res021CF;

typedef int BOOL;

typedef struct Work_021CF7DC {
    u32 f00;
    u32 f04;
    u16 *f08;
    u32 f0c;
} Work_021CF7DC;

typedef struct Work_021CF844 {
    u32 f00;
    int f04;
    u16 *f08;
    int f0c;
} Work_021CF844;

typedef struct IdList021CFA1C {
    int n;
    int ids[50];
} IdList021CFA1C;

typedef struct {
    s16 a0;
    s16 a2;
    s16 a4;
    u16 a6;
} Row8;

typedef struct {
    u16 v[10];
} Slot;

typedef struct {
    u8   pad[0x10];
    Slot slot[20];
} Slots;

typedef struct Rec_021CEDA0 {
    u16 v[10];
} Rec_021CEDA0;

typedef struct Out {
    u8 key;       /* 0x00 */
    u8 count;     /* 0x01 */
    u8 b2;        /* 0x02 */
    u8 val[5];    /* 0x03 */
    u8 slot[5];   /* 0x08 */
} Out;

typedef struct Tbl021CFCF4 {
    u8 f0;
    u8 n;
    u8 pad2[6];
    u8 v[5];
} Tbl021CFCF4;

typedef struct B_021CF3B0 {
    u32 f0;
    u32 f4[4 + 4];
    u32 f24[4];
    u32 f34[8];
} B_021CF3B0;

typedef struct Arg021D0218 {
    u32 h;
    u32 v;
} Arg021D0218;

typedef struct {
    int pad[9];
    int a24[4];
    int a34[1];
} Tbl;

typedef struct {
    Tbl *tbl;
    int cnt;
} Src;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    Src src;
    int obj;
    int sub[4];
} Dst;

typedef struct St021D0328 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u32 f4;
    u32 f8;
    u32 fC;
} St021D0328;

typedef struct V {
    u32 w[15];
} V;

typedef struct T {
    u16 a;
    u16 b;
} T;

typedef struct W_021CEDA0 {
    u16 h[2];
    u32 f4;
    u16 g[2];
} W_021CEDA0;

typedef struct Arg021D046C {
    u32 h1;
    u32 h2;
    u32 b;
    u32 c;
} Arg021D046C;

typedef struct Blk021D04D8 {
    u32 w[4];
} Blk021D04D8;

typedef struct St021D04D8 {
    u8 *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10[2];
    u16 f18;
} St021D04D8;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef struct R {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u16 h18;
    u16 h1a;
    u16 h1c;
    u16 h1e;
    u32 f20;
} R;

typedef struct Arg021D05D8 {
    u32 h;
    void *a;
} Arg021D05D8;

typedef struct Vec021D05D8 {
    int x, y, z;
} Vec021D05D8;

typedef struct S_021CFC80 {
    int f0;
    int a[3];
    int f10;
    int b[2];
    int f1c;
} S_021CFC80;

typedef struct S_021D072C {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S_021D072C;

typedef struct Src021D072C {
    int *f0;
    int f4;
} Src021D072C;

typedef struct S_021D0750 {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S_021D0750;

typedef struct S_021D07D8 {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S_021D07D8;

typedef struct Row20 {
    u32 f0;
    int f4;
    u32 f8[3];
} Row20;

typedef struct S_021D07FC {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    Row20 rows[6];
} S_021D07FC;

typedef short s16_021D0750;

typedef long long s64;

typedef struct Blk021D08D8 {
    u32 w[3];
} Blk021D08D8;

typedef struct Big {
    int w[72];
} Big;

typedef signed short   s16_021D0A74;

typedef struct Work_021D0750 {
    int f00;
    u8 f04;
    u8 pad05;
    u16 f06;
    int f08;
    int f0C;
    int f10;
    int f14;
    u8 pad18[0x78 - 0x18];
    int f78;
    u8 pad7C[0x80 - 0x7C];
    int f80;
    u8 *f84;
    u16 *f88;
    int f8C;
} Work_021D0750;

typedef struct {
    u8 pad0[0x7c];
    u32 f7c;
    u32 f80;
    u8 *f84;
    u16 *f88;
    int f8c;
} W_021D0750;

typedef struct {
    u16 species;
    u8 b2;
    u8 b3;
} Mon;

typedef struct {
    u8 valid;
    u8 kind;
    u16 score;
    Mon mons[4];
} Rec_021D0750;

typedef struct Work_021D0C58 {
    void *f00;
    int f04;
    int f08;
    int f0C;
} Work_021D0C58;

typedef struct Flags {
    u8 pad[0x28];
    u8 bits[16];
} Flags;

extern int func_021909E4(struct Handle *h);
extern void func_0203D000(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021CE9E4(u8 *p, u32 m);
extern u32 func_0203CF10(u32 a);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_02008494(void *src, void *dst);
extern u16 func_02045A98(void);
extern void func_02190A6C(u32 a);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02190A64(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020362DC(void);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_0219049C(u8 *p);
extern int func_021909BC(void *a);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_0203D1C0(u32 index);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void func_0203A5E4(u32 v);
extern void *func_021CEAF8(void *p);
extern u32 func_021CD624(u32, u32, u32, u32, u32);
extern void func_02082BCC();
extern void func_02087C6C(void *p);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern struct Entry *func_0203996C(s32 idx);
extern int func_02008468(void);
extern void func_021CE724(u8 *p);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021CE6F0(u8 *p, u8 i);
extern void func_021CE70C(u8 *p);
extern void func_021CE718(u8 *p);
extern u32 func_0203D378(void);
extern u8 *func_021CEADC(u8 *p);
extern u32 func_021CEB04(u32, u32);
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_02188C80(void *p);
extern u32  func_0203038C(u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020124E8(struct Obj *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern u16 func_02188C9C(u8 *p);
extern u16 func_02013E40(u32 a);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_021A30C8(void **ctx);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern BOOL func_021AB2BC(u16 id);
extern BOOL func_021AB364(u16 id);
extern int func_021AB37C(u32 id);
extern u32 func_0202A230(void *a, u32 idx);
extern u8 func_0202A3FC(u32 key);
extern u8 func_0202A3D8(u32 key);
extern u32 func_02188D58(u8 *p);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern void *func_0215A5F4(void *vm);
extern u16 *func_02159AE8(void *c, void *vm);
extern void  func_0215897C(void *vm, void *task);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_020124E4(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32   func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0201293C(const struct BigObj *p);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BBEC(void *base, u32 i, u32 j);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02158F74(void *p);
extern void func_02045994(struct Strbuf *dst, const u16 *src, u32 len);
extern u16 *func_0200BE48(void *sys);
extern int func_02012F38(int base);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern int func_0200E878(u8 *p);
extern u32 func_02009634(const struct Sub02009470Obj *obj, u32 i, u32 field);
extern struct Sub02009470Ent *func_0200973C(struct Sub02009470Obj *obj, int i);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02025C74(u32 x);
extern u8 func_02025B64(u32 v);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern void func_0201F198(struct WordSet *p, u32 i, u32 v);
extern unsigned int func_02159B10(void *a, void *b);
extern u8 func_02009590(void *a, u32 b, u32 c);
extern u8 sub_020095C8(const struct Sub02009470Obj *obj);
extern void func_02009698(struct Sub02009470Obj *obj, int i, u32 field, u32 value);
extern void sub_020095FC(struct Sub02009470Obj *obj, int value);
extern void sub_02009618(struct Sub02009470Obj *obj, int value);
extern u16 func_02011330(struct Stream *s);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern void func_02047504(struct Rec_021CEDA0 *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *b, u32 c, u32 d, void *e, u32 f);
extern int func_021AC1E0(u32 a);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern int func_020477D4(struct Owner *owner, u32 index);
extern int func_021AC1AC(u32 a);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern void func_02047738(struct Rec_021CEDA0 *p);
extern void func_0204762C(struct Rec_021CEDA0 *p);
extern int func_020478B8(void *a, int idx, int amount);
extern void func_0207ADC4(void *a);
extern void func_021AC1B8(u32 a, V *v);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern u32 func_021ABE18(u8 *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *, u16);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u16 func_021C6590(u32, u32, u32, u32);
extern void func_021C67D8(u32, u32, u32);
extern u32 func_021C6628(u32, u32);
extern void func_021C6580(u8 *p, int i);
extern void func_020061E4(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern int func_0216E1C4(int a0, int a1);
extern void func_0219BF3C(int a, u32 v);
extern void func_021AC154(u32 a);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern int func_02163E58(u32 m, Vec3 *pos, int *h);
extern void func_021AC1CC(u32 a, Vec3 *v);
extern void func_021C6744(u32 *a, int idx, int mode, u32 val);
extern int func_021C6694(u32 *a, int idx, int v);
extern u32 func_021C67A8(u32 a, u32 b, u32 c);
extern void func_021C6664(u32 a, u32 b, Vec3 *v);
extern void func_021C67F4(u32 a, u32 b);
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern int func_0216D3CC(int p);
extern int func_02047888(int *a, int idx, int *out);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern u16 func_0216D5F8(void *p);
extern int func_0216D55C(int a, int b);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_0219E784(u32 o, u32 idx, s16_021D0750 *v);
extern void func_0207CDB8(s16_021D0750 *a, s16_021D0750 *b);
extern u32 func_0200E588(void);
extern struct Party *func_0201A920(u32 heap);
extern int func_020072CC(int a, int b, int c, void *d, int e);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern int func_0200E5A0(void *a0);
extern int func_0200E5CC(void *p);
extern void func_0200734C(struct Sub02007324Ctrl *a, unsigned int b);
void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_020056EC(u32 range);
extern int func_02168878(u8 *a, int b, int c, int d, int e, int f, u16 g);
extern Big *func_0200E5F8(int a, int b);
u16 func_02168AEC(u16 a0);
extern u32 func_021680C8(u32, u32, u32, u32);
extern void *func_021576D0(u8 *p);
extern int func_021578A0(u32 *p);
extern void func_02157928(u8 *p);
extern int func_021578F0(void *p);
extern int func_02157910(u8 *p);
extern void *func_0200E8F8(void *sys);
extern u16 func_0200E5E4(void *p);
extern void func_0200E608(void *sys, void *dst, u32 heap);
extern int func_02157938(void *a0);
extern u32 func_0203D210(void);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void func_02008E88(struct Sub02008C20Obj *obj, u32 value);
extern void func_02008E68(struct Sub02008C20Obj *obj, u32 value);
extern void *func_021D1164(u32 heap, u32 v);
extern void func_021D11B0(u32 *p);
extern void func_0200E684(void *obj);
extern void func_02012E4C(u8 *a, u32 b);
extern int func_02012E7C(char *p, int a1);
extern void func_021D11D8(u32 *p);
extern int func_021D1194(void *a);
int func_021CEDA0(u8 *p);
void func_021CEE00(u8 *p);
void func_021CEE48(u8 *p);
void func_021CEE78(u8 *p, u8 *a, u32 b);
void func_021CEF08(u8 *p, int i);
void func_021CEF1C(S_021CEDA0 *p);
int func_021CF068(u8 *p);
void func_021CF0F4(u8 *p);
void func_021CF110(u8 *p, u32 v, void *a);
u32 func_021CF128(void);
int func_021CF12C(int mask);
void func_021CF164(u32 a);
void func_021CF17C(void);
void *func_021CF188(u32 a, void *b);
int func_021CF194(u32 a, u32 b, u32 c, u32 d);
u32 func_021CF1AC(u32 a, u32 b, u32 c);
void func_021CF214(u32 a, u32 b, u32 c, u32 d);
void func_021CF220(u32 a, u32 flag, u32 c);
void func_021CF27C(u32 a, u32 b, u32 c, u32 d);
void func_021CF288(u32 a, u32 flag, u32 c);
void func_021CF2E4(u32 a, u32 b, u32 c, u32 d);
void func_021CF2F0(int mode);
void func_021CF31C(u32 a, u32 b, u32 c, u8 *d);
u32 func_021CF32C(u32 flag);
void func_021CF36C(u32 a, u32 b, u32 c, u32 d);
void func_021CF378(int mode);
void func_021CF3A4(u32 a, u32 b, u32 c, u8 *d);
void func_021CF3B0(int mode);
int func_021CF3DC(u32 a, u32 b, u32 c, u8 *d);
void func_021CF3FC(u32 a, u32 b, int c);
void *func_021CF45C(u32 heap, u32 v);
int func_021CF480(void *a);
void func_021CF498(Ctx *c, u32 x, int idx);
u32 func_021CF51C(u32 *p);
void func_021CF520(u32 a, u32 b, u32 c, u32 d);
void func_021CF52C(u8 *p, u32 size, u32 heap);
void func_021CF54C(u8 *p);
u32 func_021CF560(u32 *p);
void func_021CF564(Res021CF *r, u32 id);
void func_021CF580(void *r);
void func_021CF59C(struct Res021CF *r);
void func_021CF5AC(Res021CF *r);
void func_021CF5D8(int id, int kind, int flag, struct Obj00020 *pos, u32 *outType, u16 *outMsg);
void func_021CF748(u32 a, u32 x, int *out, u16 *out2);
int func_021CF7DC(void *c, void *vm);
int func_021CF844(void *a, int *task, Work_021CF844 *w);
int func_021CF8E4(void *a, void *src, int c);
int func_021CF940(void *a, void *src, void *b, int *c);
int func_021CF9AC(void *a, void *heap, int x, int y);
int func_021CFA04(int a, int v, void *l);
int func_021CFA1C(int v, IdList021CFA1C *l);
int func_021CFA58(void *a, void *b);
int func_021CFA88(void *a, void *b);
int func_021CFAC0(u8 *base, int a, int b, int c, int d);
void func_021CFB1C(Slots *base, int i, Slot *dst);
const Row8 *func_021CFB68(u8 *base, int *idx);
int func_021CFBA8(u32 a, u32 unused, const Rec_021CEDA0 *src);
void *func_021CFC14(void *a, void *unused, void *c);
void func_021CFC4C(void *a, int b, void *c);
void func_021CFC80(void *a, Out *out, u32 key, u32 b);
u8 func_021CFCF4(Tbl021CFCF4 *p, u32 i);
int func_021CFD08(u32 a, u32 b, u8 *c, int d, u32 e);
int func_021CFD88(int a, u32 b, u32 c, int d, int e);
void func_021CFDBC(void *ws, u32 h, u32 x);
int func_021CFEA0(u32 a, u32 b);
int func_021CFEF0(u32 a, u32 b);
int func_021CFF28(u32 a, u32 b);
int func_021CFF78(u32 a, u32 b);
int func_021CFFDC(u32 a, u32 b);
int func_021D0014(u32 a, u32 b);
int func_021D004C(u32 a, u32 b);
int func_021D0084(u32 a, u32 b, u32 c, u32 d);
int func_021D00B8(u32 a, u32 b);
int func_021D0114(u32 a, u32 b);
void *func_021D0140(u32 v, u32 heap);
void func_021D0160(u32 a, u8 *p);
void func_021D0174(B_021CF3B0 *p, int i);
void func_021D01D8(u32 *p);
void func_021D0218(void *a, u32 v, u32 c);
void func_021D024C(void *obj, u32 sel);
void func_021D028C(void *obj, u32 v);
void func_021D029C(void *p, Dst *d);
void func_021D0308(void *unused, u32 *p);
void func_021D0328(void *unused, St021D0328 *p);
void func_021D034C(u32 a, u8 *b);
void *func_021D038C(u32 v, u32 heap);
void func_021D03B0(u32 a, u8 *p);
void func_021D03C4(W_021CEDA0 *p);
void func_021D0440(u16 *p);
void func_021D046C(void *a, u32 b, u32 c);
void func_021D04A4(void *a);
int func_021D04C4(u32 a);
void func_021D04D8(void *a, St021D04D8 *s);
void func_021D0504(void *a, St021D04D8 *s);
void func_021D0520(u32 a, u8 *b);
void func_021D0568(u32 a, R *b);
void func_021D05D8(void *a, void *b);
void *func_021D0610(u32 v, u32 heap);
void func_021D0634(u32 a, u8 *p);
void func_021D0648(S_021CFC80 *p);
void func_021D06E0(S_021CFC80 *p);
void func_021D072C(void *a, S_021D072C *s);
void func_021D074C(void);
void func_021D0750(int unused, S_021D0750 *s);
void func_021D07D8(void *a, S_021D07D8 *s);
Row20 *func_021D07FC(S_021D07FC *s);
void func_021D0824(int *p, int a);
void func_021D08B0(u32 a);
void func_021D08BC(Row20 *r, int v);
void func_021D08D8(Row20 *r, int a);
int func_021D0914(int a, s16_021D0750 *v);
void *func_021D096C(int a);
void func_021D09D0(int a, char *out);
void func_021D0A48(void *a, u8 **pp);
void func_021D0A74(int *p, u32 mode);
void func_021D0AB8(int *p, int v);
void func_021D0AC0(void *a, u8 *p, u32 c);
void func_021D0AE4(char *p, u32 mode);
void func_021D0B58(int a, Big *dst, int idx);
void func_021D0BCC(char *p);
int func_021D0BD8(u32 a, u32 b, u32 c, u32 d);
void *func_021D0BE4(void *a, u8 *b, u16 *c);
int func_021D0C58(u32 unused, u32 *state, W_021D0750 *w);
void func_021D0DB0(u32 a, u8 *w, u16 *outRank, u16 *outScore);
int func_021D0FE0(int x, int *p);
void *func_021D0FE8(void *a, int unused, int c);
int func_021D1028(const struct Ctx *a0);
u8 func_021D1058(Flags *p, u32 n);
void func_021D1080(Flags *p, u32 n);
int func_021D10A8(u32 a, u32 *b, u32 *c);
extern const u8 data_021DB4BC[];
extern char d_021DE5FC[];
extern Ent d_021DB4FC[];
extern char abs_id_4b[];
extern char abs_id_4d[];
extern unsigned char ov075_id[];
extern const u16 d_021DB7E0[];
extern const u8  d_021DB7F6[];
extern char abs_id_39[];
extern char d_021F3900[];
extern const Row8 d_021DB834[];
extern char d_021DE608[];
extern const u16 data_021DB8CC[];
extern const u16 data_021DB8C4[];
extern char d_021DB8DC[];
extern const V data_021DB8F0;
extern char d_021DE618[];
extern const T data_021DB92C[];
extern char d_021DB93C[];
extern int d_021DB934[];
extern char d_021DB968[];
extern char d_021DE664[];
extern int d_021DB95C[3];
extern int d_021DB950;
extern int d_021DB954[2];
extern Blk021D08D8 d_021DE628;
extern char d_021DE674[];
extern u8 d_0209DF0C;












/*
 * Addresses are Black-image addresses.
 */
int func_021CEDA0(u8 *p)
{
    N *n = (N *)(p + 0x13c);
    int r;

    r = func_021909E4((struct Handle *)n->f4);
    switch (r) {
    case -2:
        return 0;
    case -1:
        break;
    default:
        if (n->e[r].used == 1) {
            n->cur = &n->e[r];
            func_0203D000(n->cur->name + 0x20);
            func_0201F02C((struct WordSet *)(((struct Obj00011 *)p)->f4), 0, (void *)((int)n->cur));
            func_021CE9E4(p, 0x20);
            n->f2d4 = 0;
        }
        break;
    }
    return 1;
}












void func_021CEE00(u8 *p)
{
    u8 *q = p + 0x13c;
    int i;

    for (i = 0; i < 16; i++) {
        u8 *e = q + i * 0x2c;

        if (e[0x2e] == 1) {
            ((struct Obj09739 *)e)->f30 -= 1;
            if (((struct Obj09739 *)e)->f30 <= 0) {
                func_021CEF08(p, i);
                q[0x2d1] = 1;
            }
        }
    }
}












/*
 * func_021CEE78 takes three arguments: the entry itself is the third, which
 * is why the 0203CF10 result lives in r2 and is copied to r1 for the +0x20
 * address.  (The earlier two-argument prototype left it in r1.)
 */
void func_021CEE48(u8 *p)
{
    int i;
    Ent021CEE48 *e;

    for (i = 0; i < 0x10; i++) {
        e = (Ent021CEE48 *)func_0203CF10(i);
        if (e != 0 && e->sub.id == 0x3a0b) {
            func_021CEE78(p, (u8 *)&e->sub, (u32)e);
        }
    }
}












/*
 * the range). Verified EXACT arm9 thumb leaf C for it:
 *   extern void func_02082D44(const void *a, void *b, unsigned n);  (arm)
 *   void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 *
 * Addresses are Black-image addresses.
 */
void func_021CEE78(u8 *p, u8 *a, u32 b)
{
    N *n = (N *)(p + 0x13c);
    int i;

    for (i = 0; i < 16; i++) {
        if (n->e[i].used == 1 && func_0203EFC8(n->e[i].mac, a, 6) == 0) {
            n->e[i].timer = 150;
            return;
        }
    }
    for (i = 0; i < 16; i++) {
        if (n->e[i].used == 0) {
            func_02082D44(a, n->e[i].mac, 6);
            func_02008494((void *)b, n->e[i].name);
            n->e[i].timer = 150;
            n->e[i].used = 1;
            n->f2d1 = 1;
            return;
        }
    }
}












void func_021CEF08(u8 *p, int i)
{
    (p + i * 0x2c)[0x16a] = 0;
}












void func_021CEF1C(S_021CEDA0 *p)
{
    u16 ch;
    u32 c, a, b, d;
    int i;

    ch = func_02045A98();
    if (p->f40e == 1) {
        func_02190A6C(p->f13c);
    }
    a = (u32)func_020457B0(0x40, p->f528);
    b = (u32)func_020457B0(0x40, p->f528);
    c = (u32)func_020457B0(0x40, p->f528);
    d = (u32)func_020457B0(4, p->f528);
    func_02045CAC((struct MsgBank *)p->f8, 0x1a, (void *)a);
    func_02045CAC((struct MsgBank *)p->f8, 0x1b, (void *)b);
    for (i = 0; i < 16; i++) {
        func_0201EFA4((struct WordSet *)p->f4, 0, i + 1, 2, 2, 1);
        if (p->ents[i].on == 1) {
            func_0201F02C((struct WordSet *)p->f4, 1, &p->ents[i]);
            func_0201EFA4((struct WordSet *)p->f4, 2, func_02008534((const struct Sub0200852CObj *)(&p->ents[i])), 5, 2, 1);
            func_0201F250((struct WordSet *)p->f4, (void *)c, (void *)b);
        } else {
            func_02045924((struct Strbuf *)d, &ch);
            func_0201EE0C((struct WordSet *)p->f4, 1, (const void *)d, 0, 1, 2);
            func_0201EE0C((struct WordSet *)p->f4, 2, (const void *)d, 0, 1, 2);
            func_0201F250((struct WordSet *)p->f4, (void *)c, (void *)a);
        }
        func_02190A64(p->f13c, c, i, p->f528);
    }
    func_02045808((struct U16Vec *)b);
    func_02045808((struct U16Vec *)a);
    func_02045808((struct U16Vec *)c);
    func_02045808((struct U16Vec *)d);
    p->f40e = 1;
}












int func_021CF068(u8 *p)
{
    u8 *q = p + 0x130;
    u32 r;

    switch (q[8]) {
    case 0:
        if (func_020362DC() & 2) {
            ((struct Obj04295 *)q)->f0 = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0)), 0);
            func_021CE9E4(p, 0x23);
            q[8] = 1;
        }
        break;
    case 1:
        r = func_02190C78((struct Handle *)(((struct Obj04295 *)q)->f0));
        if (func_0219049C((u8 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0))) == 1 && p[0x576] == 1)
            r = 1;
        if (r != 2) {
            func_021909BC((void *)(((struct Obj04295 *)q)->f0));
            ((struct Obj04295 *)q)->f0 = 0;
            if (r == 1) {
                q[8] = 0;
                func_021CE9E4(p, 0x22);
            } else {
                return 2;
            }
        }
        return 1;
    }
    return 0;
}












void func_021CF0F4(u8 *p)
{
    u32 *q = (u32 *)(p + 0x130);

    if (q[0] != 0) {
        func_021909BC((void *)q[0]);
        q[0] = 0;
    }
    ((u8 *)q)[8] = 0;
}












void func_021CF110(u8 *p, u32 v, void *a)
{
    ((struct Obj20269 *)p)->f52C = v;
    func_02008494(a, p + 0x530);
}












/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CF128(void)
{
return 132;
}












int func_021CF12C(int mask)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (i != func_0203D1A4((struct Link *)((int)func_020399A8())) && ((1 << i) & mask) && func_0203D1C0(i) == 1) {
            return 1;
        }
    }
    return 0;
}











/*
 * Opens the ov021 resource 0x021DB4BC in heap 0x2700 with 8 entries.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF164(u32 a)
{
    func_0203A574(0x2700, (u32)data_021DB4BC, 8, a);
}











/*
 * Tail call with 0x2700.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF17C(void)
{
    func_0203A5E4(0x2700);
}








void *func_021CF188(u32 a, void *b) { return func_021CEAF8(b); }










int func_021CF194(u32 a, u32 b, u32 c, u32 d)
{
return func_021CD624(d, a, c, *(u8 *)((u8 *)((c + 38))), (c + 32));
}










/*
 * the range). Verified EXACT arm9 thumb leaf C for it:
 *   extern void func_02082D44(const void *a, void *b, unsigned n);  (arm)
 *   void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 * func_021CF214 (unlabelled) is a tail-call stub into func_021CF110.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CF1AC(u32 a, u32 b, u32 c)
{
    B_021CEDA0 buf;

    func_02082BCC(&buf, 0, 0x28);
    func_02008494((void *)a, &buf);
    func_02087C6C(buf.x);
    buf.x[6] = b;
    if (c == 1)
        func_0203D3F8((u32)func_020399A8(), 0xff, 0x2700, 0x28, (u32)(&buf), 0, 0, 0);
    else
        return func_0203D3F8((u32)func_020399A8(), 0, 0x2700, 0x28, (u32)(&buf), 0, 0, 0);
}










void func_021CF214(u32 a, u32 b, u32 c, u32 d)
{
    func_021CF110((u8 *)d, 1, (void *)c);
}










void func_021CF220(u32 a, u32 flag, u32 c)
{
    u32 h;

    if (flag == 1) {
        h = (u32)func_0203996C(0xff);
        func_0203D3F8(h, a, 0x2701, func_02008468(), c, 0, 0, 0);
    } else {
        h = (u32)func_020399A8();
        func_0203D3F8(h, a, 0x2701, func_02008468(), c, 0, 0, 0);
    }
}










/*
 * func_021CF27C (unlabelled) is a tail-call stub into func_021CF110.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF27C(u32 a, u32 b, u32 c, u32 d)
{
    func_021CF110((u8 *)d, 2, (void *)c);
}










/*
 * func_021CF2E4 (unlabelled) is a tail-call stub into func_021CE724.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF288(u32 a, u32 flag, u32 c)
{
    u32 h;

    if (flag == 1) {
        h = (u32)func_0203996C(0xff);
        func_0203D3F8(h, a, 0x2702, func_02008468(), c, 0, 0, 0);
    } else {
        h = (u32)func_020399A8();
        func_0203D3F8(h, a, 0x2702, func_02008468(), c, 0, 0, 0);
    }
}










void func_021CF2E4(u32 a, u32 b, u32 c, u32 d)
{
    func_021CE724((u8 *)d);
}










void func_021CF2F0(int mode)
{
    if (mode == 1) {
        func_0203D3A8(func_0203996C(0xff), 0x2703, 0, 0);
    } else {
        func_0203D3A8(func_020399A8(), 0x2703, 0, 0);
    }
}






void func_021CF31C(u32 a, u32 b, u32 c, u8 *d) { func_021CE6F0(d, a); }







/*
 * func_021CF36C (unlabelled) is a tail-call stub into func_021CE70C.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CF32C(u32 flag)
{
    if (flag == 1)
        func_0203D3F8((u32)func_020399A8(), 0xff, 0x2704, 0, 0, 0, 0, 0);
    else
        return func_0203D3F8((u32)func_020399A8(), 0, 0x2704, 0, 0, 0, 0, 0);
}







void func_021CF36C(u32 a, u32 b, u32 c, u32 d)
{
    func_021CE70C((u8 *)d);
}







void func_021CF378(int mode)
{
    if (mode == 1) {
        func_0203D3A8(func_0203996C(0xff), 0x2705, 0, 0);
    } else {
        func_0203D3A8(func_020399A8(), 0x2705, 0, 0);
    }
}




void func_021CF3A4(u32 a, u32 b, u32 c, u8 *d) { func_021CE718(d); }








void func_021CF3B0(int mode)
{
    if (mode == 1) {
        func_0203D3A8(func_0203996C(0xff), 0x2706, 0, 0);
    } else {
        func_0203D3A8(func_020399A8(), 0x2706, 0, 0);
    }
}








int func_021CF3DC(u32 a, u32 b, u32 c, u8 *d)
{
if (func_0203D378() == 1) {
    return (int)func_021CEADC(d);
}
return func_021CEB04((u32)d, c);
}








/*
 * Calls func_0203D4D0 with 0x2707 on the handle of func_0203996C(0xff) when c == 1,
 * otherwise on the handle of func_020399A8().
 *
 * Addresses are Black-image addresses.
 */
void func_021CF3FC(u32 a, u32 b, int c)
{
    u32 h;

    if (c == 1) {
        h = (u32)func_0203996C(0xff);
        func_0203D4D0(h, b, 0x2707, func_021CF128(), a, 0, 0, 1);
    } else {
        h = (u32)func_020399A8();
        func_0203D4D0(h, b, 0x2707, func_021CF128(), a, 0, 0, 1);
    }
}








void *func_021CF45C(u32 heap, u32 v)
{
    u32 *p = func_02030734(heap, 0x20, 1, d_021DE5FC, 0x6c);

    p[2] = v;
    p[6] = 0;
    return p;
}








int func_021CF480(void *a)
{
func_021CF54C((u8 *)a);
func_021CF5AC((Res021CF *)((struct Res021CF *)a));
return func_020307B0(a);
}








/*
 * Picks a row of the 0x25-entry table at 0x021DB4FC (0x14 bytes each) and calls its
 * builder.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF498(Ctx *c, u32 x, int idx)
{
    u32 r;
    u32 y;
    void *p = c->f08;

    y = (u32)func_02188C80(p);

    if (idx >= 0x25) {
        idx = 0;
    }
    if (func_0203038C(0x15) < d_021DB4FC[idx].f10) {
        idx = 7;
    }
    if (d_021DB4FC[idx].f08 != -1) {
        func_021CF564((Res021CF *)((struct Res021CF *)c), (u32)d_021DB4FC[idx].f08);
    }
    r = d_021DB4FC[idx].fn(y, p, d_021DB4FC[idx].f0c);
    func_02012374((struct Evt *)x, (struct Evt **)r);
    c->f00 = (u32)func_020124E8((struct Obj *)r);
    c->f04 = d_021DB4FC[idx].f04;
}








/*
 * Unlabelled 4-byte accessor (returns the first word of its argument),
 * filed 2026-10-04 (wave D2) because it blocks ov077/ov078 callers.
 */
u32 func_021CF51C(u32 *p) { return *p; }








void func_021CF520(u32 a, u32 b, u32 c, u32 d)
{
if (((struct Obj12140 *)((u8 *)(a)))->f4 != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(a) + 4))(a, ((struct Obj12140 *)((u8 *)(a)))->f4, c, d);
}
}








void func_021CF52C(u8 *p, u32 size, u32 heap)
{
    ((struct Obj20270 *)p)->f1C = func_02030734(heap, size, 1, d_021DE5FC, 0xe3);
}








/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF54C(u8 *p)
{
    u32 v = ((struct Obj03621 *)p)->f1C;
    if (v != 0) {
        func_020307B0((void *)v);
        ((struct Obj03621 *)p)->f1C = 0;
    }
}










u32 func_021CF560(u32 *p)
{
    return p[7];
}










void func_021CF564(Res021CF *r, u32 id)
{
    func_02034AC4(id);
    r->ids[r->n++] = id;
}










/*
 * 0x4B and 0x4D are FS_OVERLAY_ID symbols: func_021CF564 forwards its r1
 * to func_02034AC4 (overlay_id class, ov021-qualified consumer entry,
 * 2026-10-02).  The listing extent (44 bytes) also covers an unlabelled
 * thunk at 0x021CF59C.
 */
void func_021CF580(void *r)
{
    func_021CF564(r, (u32)abs_id_4b);
    func_021CF564(r, (u32)abs_id_4d);
}










/*
 * Thumb tail call through r3; the second argument is the ov075 overlay id
 * (a pool word, 0x4B).
 */
void func_021CF59C(struct Res021CF *r)
{
    func_021CF564(r, (u32)ov075_id);
}










void func_021CF5AC(Res021CF *r)
{
    int i;

    if (r->n > 0) {
        while (r->n > 0) {
            i = r->n - 1;
            if (r->ids[i] != 0) {
                func_02034A5C(r->ids[i]);
            }
            r->n--;
        }
    }
}










/*
 * func_02013E40 returns u16 (its body ends in ldrh); declaring it u32, or
 * keeping its result in a u32 local, hoists the spilled local's reload
 * above the final *outType store (4 bytes).
 *
 * Addresses are Black-image addresses.
 */
void func_021CF5D8(int id, int kind, int flag, struct Obj00020 *pos, u32 *outType, u16 *outMsg)
{
    u32 attr;
    u16 m;
    u16 sp;
    u32 type;
    u16 msg;

    sp = func_02013E40(func_02188C9C((u8 *)pos));
    switch (id) {
    case 0x23B:
        *outMsg = 0x469;
        *outType = 0x23;
        return;
    case 0x283:
        *outMsg = 0x474;
        *outType = 0x20;
        return;
    case 0x284:
        *outMsg = 0x475;
        *outType = 0x20;
        return;
    case 0x286:
        *outMsg = 0x476;
        *outType = 0x20;
        return;
    case 0x27D:
        *outMsg = 0x468;
        *outType = 0x1f;
        return;
    case 0x1EE:
        *outMsg = 0x478;
        *outType = 0x1f;
        return;
    case 0x27E:
    case 0x27F:
    case 0x280:
    case 0x287:
        *outMsg = 0x478;
        *outType = 0x22;
        return;
    case 0x281:
    case 0x282:
    case 0x285:
        *outMsg = 0x477;
        *outType = 0x21;
        return;
    }
    if (kind == 1) {
        *outMsg = 0x469;
        *outType = 0x1f;
        return;
    }
    if (kind == 4) {
        if (sp == 0xd6) {
            *outMsg = 0x469;
        } else {
            *outMsg = 0x468;
        }
        *outType = 2;
        return;
    }
    attr = func_021A30C8(func_02188CB4(pos));
    m = func_021AB0F0(attr);
    if (func_021AB0F8(attr) & 2) {
        msg = 0x468;
        type = 2;
    } else if (func_021AB2BC(m)) {
        if (flag) {
            msg = 0x469;
            type = 1;
        } else {
            msg = 0x468;
            type = 0;
        }
    } else if (func_021AB364(m)) {
        msg = 0x468;
        type = 0;
    } else {
        if (func_021AB37C(m)) {
            msg = 0x468;
            type = 4;
        } else {
            msg = 0x468;
            type = 3;
        }
    }
    *outType = type;
    if (sp == 0xd6) {
        *outMsg = 0x469;
    } else {
        *outMsg = msg;
    }
}










/*
 * Picks a value pair from two small tables, or a state code from the field
 * state when the index is out of range.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF748(u32 a, u32 x, int *out, u16 *out2)
{
    int flag = 1;
    u32 t = func_0202A230((void *)a, 1);
    u32 k = func_0202A3FC(t);
    u32 m = func_0202A3D8(t);
    int code;

    if (k < 0xb) {
        *out2 = d_021DB7E0[k];
        *out = d_021DB7F6[m];
        return;
    }
    {
        u32 y = func_021A30C8(func_02188CB4((void *)x));
        u32 z = func_021AB0F0(y);

        if (func_021AB0F8(y) & 2) {
            code = 6;
        } else if (func_021AB37C(z) != 0) {
            code = 8;
        } else {
            if (func_020140D8((struct Sub020140BCObj *)func_02188D58((u8 *)x)) == 0) {
                flag = 0;
            }
            code = 5;
            if (flag == 0) {
                code = 7;
            }
        }
    }
    *out2 = 0x46a;
    *out = code;
}










/*
 * Script command: starts the func_021CF844 task over a 0xD8-byte work and
 * fills its header.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF7DC(void *c, void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *sys = func_0215A5DC(vm);
    void *heap = func_0215A5E4(vm);
    u16 *var = func_02159AE8(c, vm);
    void *task;
    void *h2;
    Work_021CF7DC *w;

    task = func_020122C0(sys, 0, func_021CF844, 0xd8);
    h2 = func_02012944(heap);
    w = func_020124E8(task);
    w->f00 = func_02008530(h2);
    w->f0c = 0;
    w->f04 = 0;
    w->f08 = var;
    func_0215897C(owner, task);
    return 1;
}










/*
 * Task body started by func_021CF7DC: a three-state counter walk.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF844(void *a, int *task, Work_021CF844 *w)
{
    int *out;
    int flag = 0;
    void *sys;
    int i;

    sys = func_020120F4(func_020124E4(a));
    switch (*task) {
    case 0:
        func_021CF8E4((void *)w->f00, sys, (int)(&w->f0c));
        (*task)++;
        break;
    case 1: {
        int base = w->f04;
        out = &w->f0c;
        for (i = flag; i < 2; i++) {
            func_021CF940((void *)w->f00, sys, (void *)(base + i), out);
            w->f04++;
            if (w->f04 >= 0x18) {
                (*task)++;
                break;
            }
        }
        break;
    }
    case 2:
        func_021CF9AC((void *)w->f00, sys, flag, (int)(&w->f0c));
        flag = 1;
        break;
    }
    if (w->f0c >= 0x32) {
        flag = 1;
    }
    if (flag) {
        *w->f08 = w->f0c;
        return 1;
    }
    return 0;
}










/*
 * Counts the party members whose value func_021CFA04 accepts.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF8E4(void *a, void *src, int c)
{
    void *party = func_02012934(src);
    int cnt = func_0201AA18(party);
    int n = 0;
    int i;

    for (i = 0; i < cnt; i++) {
        void *p = func_0201AB28(party, i);
        if (func_02017E1C(p, 0x4c, 0) == 0) {
            u32 v = func_02017E1C(p, 7, 0);
            if (func_021CFA04((int)a, v, (void *)c) != 0) {
                n++;
            }
        }
    }
    return n;
}










/*
 * Counts the 30 slots whose value func_021CFA04 accepts.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF940(void *a, void *src, void *b, int *c)
{
    void *h = (void *)func_0201293C(src);
    int n = 0;
    int i;

    for (i = 0; i < 30; i++) {
        if (func_020079BC(h, (u32)b, i, 0xa9, 0) != 0) {
            if (func_020079BC(h, (u32)b, i, 0x4c, 0) == 0) {
                u32 v = func_020079BC(h, (u32)b, i, 7, 0);
                if (func_021CFA04((int)a, v, (void *)c) != 0) {
                    n++;
                }
            }
        }
    }
    return n;
}










/*
 * Counts the six entries for which func_021CFA04 accepts the value read from them.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF9AC(void *a, void *heap, int x, int y)
{
    void *h;
    int i;
    int n;

    h = func_0200BAC8(func_02012EBC(heap));
    n = 0;
    for (i = 0; i < 6; i++) {
        void *p = func_0200BBEC(h, x, i);
        if (func_02017E88(p, 0xa9, 0) != 0) {
            u32 v = func_02017E88(p, 7, 0);
            if (func_021CFA04((int)a, v, (void *)y) != 0) {
                n++;
            }
        }
    }
    return n;
}










int func_021CFA04(int a, int v, void *l)
{
    int r = 0;

    if (a != v) {
        r = func_021CFA1C(v, l);
    }
    return r;
}










int func_021CFA1C(int v, IdList021CFA1C *l)
{
    int i;

    if (l->n >= 50) {
        return 0;
    }
    for (i = 0; i < l->n; i++) {
        if (v == l->ids[i]) {
            return 0;
        }
    }
    l->ids[i] = v;
    l->n++;
    return 1;
}










/*
 * 2026-10-02: abs_id_39 is overlay id 57 (pool ABS32 0x39, the id argument
 * of func_021BB990); d_021F3900 resolves as ov057 data once the symbols line
 * carries the ov057 region hint (this function loads ov057).
 */
int func_021CFA58(void *a, void *b)
{
    func_0215A5F4(b);
    func_021BB990((int)abs_id_39, (int *)func_02188D24((u8 *)((u32)func_0201210C((void *)func_0215A5DC(b)))), (const int *)d_021F3900);
    return 0;
}










int func_021CFA88(void *a, void *b)
{
    void *h;
    u16 *q;

    func_0215A5F4(b);
    h = func_02008854(func_02012EBC(func_020120F4((void *)func_0215A5DC(b))));
    q = func_02159AE8(a, b);
    *q = func_02008990(h);
    return 0;
}










/*
 * Searches the 20 slots (stride 0x14, from +0x10) for one whose table row matches.
 *
 * Addresses are Black-image addresses.
 */
int func_021CFAC0(u8 *base, int a, int b, int c, int d)
{
    int i;
    u8 *p = base + 0x10;

    for (i = 0; i < 20; i++, p += 0x14) {
        const Row8 *r;
        if (((struct Obj12992 *)p)->f10 == 0) {
            return 0xff;
        }
        r = &d_021DB834[p[0x12]];
        if (r->a6 == a && r->a0 == b && r->a4 == d && r->a2 - 1 <= c && c <= r->a2 + 1) {
            return i;
        }
    }
    return 0xff;
}










/*
 * func_021CFB1C removes slot i (copies it out, shifts the later ones down).
 * func_021CFB68 (unlabelled, 0x021CFB68) walks to the next used slot.
 *
 * Addresses are Black-image addresses.
 */
void func_021CFB1C(Slots *base, int i, Slot *dst)
{
    *dst = base->slot[i];
    for (i++; i < 20; i++) {
        base->slot[i - 1] = base->slot[i];
    }
    ((struct Obj20274 *)base)->f19C = 0;
}










const Row8 *func_021CFB68(u8 *base, int *idx)
{
    int i = *idx;

    if (i < 20) {
        do {
            u8 *p = base + i * 0x14;
            if (((struct Obj12993 *)p)->f20 != 0) {
                const Row8 *r = &d_021DB834[p[0x22]];
                (*idx)++;
                return r;
            }
            i = ++*idx;
        } while (i < 20);
    }
    return 0;
}









/*
 * Copies a 20-byte record, opens the 0x0AFC resource, and passes the record's
 * first 8 bytes on to func_0201EE0C.
 *
 * Addresses are Black-image addresses.
 */
int func_021CFBA8(u32 a, u32 unused, const Rec_021CEDA0 *src)
{
    Rec_021CEDA0 r = *src;
    u32 h;
    u32 x;
    u32 buf;

    h = func_021587B0(a, 0x0AFC, 0, 0x15);
    func_02159058(h, r.v[8], 0, 0, 0);
    x = (u32)func_02158F74((void *)h);
    buf = (u32)func_020457B0(8, 0x15);
    func_02045994((struct Strbuf *)buf, (const u16 *)&r, 8);
    func_0201EE0C((struct WordSet *)x, 3, (const void *)buf, 1, 1, 2);
    func_02045808((struct U16Vec *)buf);
    return 0;
}









void *func_021CFC14(void *a, void *unused, void *c)
{
    void *task = func_020122C0(a, 0, func_021CFBA8, 0x14);
    void *work = func_020124E8(task);

    func_021CFB1C((Slots *)(func_0200BE48(func_02012EBC(func_020120F4(a)))), (int)c, (Slot *)work);
    return task;
}







void func_021CFC4C(void *a, int b, void *c)
{
    void *sys = func_020120F4(a);
    u8 *sv = (u8 *)func_02012F38((int)sys);

    if (b < 0xe9) {
        func_021CFC80((void *)((u32)func_02009470(func_02012EBC(sys))), (Out *)sv, b, (u32)c);
        return;
    }
    func_0200E878(sv);
}











/*
 * Collects up to five matching entries of a 20-slot list into out.
 *
 * Addresses are Black-image addresses.
 */
void func_021CFC80(void *a, Out *out, u32 key, u32 b)
{
    int i;

    out->key = key;
    out->b2 = b;
    out->count = 0;
    for (i = 0; i < 20; i++) {
        if ((u8)func_02009634(a, i, 6) != 0) {
            void *p = func_0200973C(a, i);
            u32 k;
            if (p != 0 && (k = func_0200856C(p), k == key)) {
                u32 v = func_02008554(p);
                if (v > 0xf) {
                    v = (func_02008550(p) != 0) ? 0xf : 0xb;
                }
                out->slot[out->count] = i;
                out->val[out->count] = func_02025C74(v);
                out->count++;
                if (out->count >= 5) {
                    break;
                }
            }
        }
    }
}












u8 func_021CFCF4(Tbl021CFCF4 *p, u32 i)
{
    u8 r = 0xff;

    if (i < 5 && i < p->n) {
        r = p->v[i];
    }
    return r;
}












int func_021CFD08(u32 a, u32 b, u8 *c, int d, u32 e)
{
    u32 v, t, w, s, x, g, h;
    u32 flag;

    flag = 0;
    h = (u32)func_020120F4((const struct Ctx *)b);
    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    if (d >= 5) {
        return 4;
    }
    x = ((u8 *)(c + d))[8];
    func_021CFDBC((void *)a, h, x);
    v = (u32)func_0200973C((struct Sub02009470Obj *)g, x);
    s = func_02008550((const struct Sub0200852CObj *)v);
    w = func_02009634((const struct Sub02009470Obj *)g, x, 4);
    t = func_02008530((const struct Sub0200852CObj *)v);
    if (func_02025B64(*((u8 *)func_02012F38(h)))) {
        flag = 1;
    }
    return func_021CFD88(s, t, w, e, flag);
}












int func_021CFD88(int a, u32 b, u32 c, int d, int e)
{
    int off;

    if (e != 0) {
        off = 4;
    } else {
        off = 0x44;
    }
    if (c < 5) {
        off += c * 0xc;
    }
    if (a != 0) {
        off += 6;
    }
    if (d == 0) {
        off++; off += b % 5;
    }
    return off;
}












void func_021CFDBC(void *ws, u32 h, u32 x)
{
    u32 g, e, v;
    u8 k;

    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    k = *((u8 *)func_02012F38(h));
    e = (u32)func_0200973C((struct Sub02009470Obj *)g, x);
    func_0201F048(ws, 0, k);
    if (func_02025B64(k)) {
        func_0201F094(ws, 1, k, func_02008570((const struct Sub0200852CObj *)e));
    }
    func_0201F02C(ws, 3, func_02012944((void *)h));
    func_0201EE60(ws, 5, func_02009634((const struct Sub02009470Obj *)g, x, 0));
    func_0201F198(ws, 6, func_02009628((const struct Sub02009470Obj *)g));
    func_0201F02C(ws, 7, (void *)e);
    v = func_02009634((const struct Sub02009470Obj *)g, x, 3);
    if (v == 0) {
        v = 1;
    }
    func_0201EFA4(ws, 8, v, 3, 0, 1);
    func_0201EE60(ws, 9, func_02009634((const struct Sub02009470Obj *)g, x, 1));
    k = func_02009634((const struct Sub02009470Obj *)g, x, 2);
    func_0201F198(ws, 10, k);
}












int func_021CFEA0(u32 a, u32 b)
{
    u32 k, h, g;
    void *x;
    u16 *out;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    h = (u32)func_020120F4(x);
    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    *out = func_02009590((void *)g, (u32)func_02012944((void *)h), k);
    return 0;
}












int func_021CFEF0(u32 a, u32 b)
{
    void *x;
    u16 *q;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    q = func_02159AE8((void *)a, (void *)b);
    *q = sub_020095C8(func_02009470(func_02012EBC(func_020120F4((void *)x))));
    return 0;
}












int func_021CFF28(u32 a, u32 b)
{
    u32 h, p, r;
    u8 k;

    func_0215A5F4((void *)b);
    h = (u32)func_020120F4(func_0215A5DC((void *)b));
    p = func_02012F38(h);
    k = func_02159B10((void *)a, (void *)b);
    r = func_021CFCF4((struct Tbl021CFCF4 *)p, k);
    if (r != 0xff) {
        func_02009698(func_02009470(func_02012EBC((struct Big *)h)), r, 5, 1);
    }
    return 0;
}












int func_021CFF78(u32 a, u32 b)
{
    u32 h, p, k, r;
    u16 *out;

    func_0215A5F4((void *)b);
    h = (u32)func_020120F4(func_0215A5DC((void *)b));
    p = func_02012F38(h);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    *out = 0;
    r = func_021CFCF4((struct Tbl021CFCF4 *)p, k);
    if (r != 0xff) {
        if ((u8)func_02009634(func_02009470(func_02012EBC((struct Big *)h)), r, 5)) {
            *out = 1;
        }
    }
    return 0;
}











int func_021CFFDC(u32 a, u32 b)
{
    void *x;
    u8 v;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    v = func_02159B10((void *)a, (void *)b);
    sub_020095FC(func_02009470(func_02012EBC(func_020120F4((void *)x))), v);
    return 0;
}











int func_021D0014(u32 a, u32 b)
{
    void *x;
    u8 v;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    v = func_02159B10((void *)a, (void *)b);
    sub_02009618(func_02009470(func_02012EBC(func_020120F4((void *)x))), v);
    return 0;
}











int func_021D004C(u32 a, u32 b)
{
    void *x;
    u16 *q;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    q = func_02159AE8((void *)a, (void *)b);
    *q = func_02009628(func_02009470(func_02012EBC(func_020120F4((void *)x))));
    return 0;
}











int func_021D0084(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5F4((void *)b);
func_021CFC4C(func_0215A5DC((void *)b), func_02159B10((void *)a, (void *)b), (void *)func_02159B10((void *)a, (void *)b));
return 0;
}











int func_021D00B8(u32 a, u32 b)
{
    u32 s, k, g;
    void *p;
    void *x;
    u8 *f;
    u16 *out;

    p = func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    f = (u8 *)func_02012F38((int)func_020120F4(x));
    s = (u32)func_02158F74(p);
    k = func_02159B10((void *)a, (void *)b);
    g = func_02011330((struct Stream *)a);
    out = func_02159AE8((void *)a, (void *)b);
    *out = func_021CFD08(s, (u32)x, f, k, g);
    return 0;
}











int func_021D0114(u32 a, u32 b)
{
    u16 *q = func_02159AE8((void *)a, (void *)b);

    *q = func_0200856C((const struct Sub0200852CObj *)func_02012944(func_020120F4((void *)func_0215A5DC((void *)b)))) != 0 ? 1 : 0;
    return 0;
}











void *func_021D0140(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0x54, 1, d_021DE608, 0x5f);

    p[0] = v;
    return p;
}











void func_021D0160(u32 a, u8 *p)
{
    func_021D01D8((u32 *)p);
    func_020307B0(p);
}











void func_021D0174(B_021CF3B0 *p, int i)
{
    u32 x;
    const u16 *s;
    const u16 *t;
    int j;

    x = func_021ABE24((u8 *)p->f0);
    s = data_021DB8CC;
    if (p->f4[i] == 0) {
        p->f4[i] = (u32)func_02046E24(x, s[i]);
        func_02046FF8((int *)p->f4[i]);
        p->f34[i] = (u32)func_02047400((void *)p->f4[i], 0, (void *)p->f4[i]);
    }
    t = data_021DB8C4;
    for (j = 0; j < 4; j++, t++) {
        if (p->f24[j] == 0) {
            p->f24[j] = (u32)func_02046E24(x, *t);
        }
    }
}











void func_021D01D8(u32 *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (p[1 + i] != 0) {
            func_02047504((struct Rec_021CEDA0 *)p[13 + i]);
            func_020470D0((u32 *)p[1 + i]);
            func_02046EFC((struct Tagged *)p[1 + i]);
        }
    }
    for (i = 0; i < 4; i++) {
        if (p[9 + i] != 0) {
            func_02046EFC((struct Tagged *)p[9 + i]);
        }
    }
}











void func_021D0218(void *a, u32 v, u32 c)
{
    Arg021D0218 arg;

    arg.h = func_021ABEA0((u32)a, 0xe);
    arg.v = v;
    func_021D0174((struct B_021CF3B0 *)arg.h, v);
    func_021ABFA8(a, d_021DB8DC, c, 0, &arg, 0);
}











/*
 * Highlights button sel of four and records it.
 *
 * Addresses are Black-image addresses.
 */
void func_021D024C(void *obj, u32 sel)
{
    int i;
    u8 *q;

    if (obj == 0)
        return;
    q = (u8 *)func_021AC1E0((u32)obj);
    for (i = 0; i < 4; i++) {
        func_02047804((struct AnmCtl *)(((struct Obj06104 *)q)->fC), (u16)i);
        if (i == sel)
            func_020477A4((struct G3dSys *)(((struct Obj06104 *)q)->fC), (u16)i);
        else
            func_020477D4((struct Owner *)(((struct Obj06104 *)q)->fC), (u16)i);
    }
    q[2] = sel;
    q[3] = 0;
}











/*
 * Stores v at +1 of the object's state.
 *
 * Addresses are Black-image addresses.
 */
void func_021D028C(void *obj, u32 v)
{
    if (obj != 0)
        ((u8 *)func_021AC1E0((u32)obj))[1] = v;
}











void func_021D029C(void *p, Dst *d)
{
    Src *s;
    Tbl *tbl;
    int cnt;
    int j;
    int i;

    s = (Src *)func_021AC1AC((u32)p);
    d->src = *s;
    tbl = d->src.tbl;
    cnt = d->src.cnt;
    for (i = 0; i < 4; i++)
        d->sub[i] = (int)func_02047564((struct G3dOwner *)tbl->a34[cnt], (const struct G3dOwner *)tbl->a24[i], 0);
    d->f2 = 4;
    d->obj = (int)func_0204767C((int)tbl->a34[cnt], (u32 *)d->sub, 4);
    for (j = 0; j < 4; j++)
        func_020477D4((struct Owner *)d->obj, (u16)j);
}











void func_021D0308(void *unused, u32 *p)
{
    int i;

    func_02047738((struct Rec_021CEDA0 *)p[3]);
    for (i = 0; i < 4; i++) {
        func_0204762C((struct Rec_021CEDA0 *)p[4 + i]);
    }
}










void func_021D0328(void *unused, St021D0328 *p)
{
    if (p->f2 != 4) {
        p->f3 = 0;
        if (func_020478B8((void *)p->fC, p->f2, 0x1000) == 0) {
            p->f3 = 1;
        }
    }
}










void func_021D034C(u32 a, u8 *b)
{
    V v;

    if (b[1] == 0) {
        v = data_021DB8F0;
        func_0207ADC4(&v.w[6]);
        func_021AC1B8(a, &v);
        func_02047AC8((void *)(((struct Obj12997 *)b)->fC), (struct Arg *)(&v));
    }
}










void *func_021D038C(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0xc, 1, d_021DE618, 0x6b);

    p[1] = v;
    func_021D03C4((struct W_021CEDA0 *)p);
    return p;
}










void func_021D03B0(u32 a, u8 *p)
{
    func_021D0440((u16 *)p);
    func_020307B0(p);
}










void func_021D03C4(W_021CEDA0 *p)
{
    u32 buf[9];
    u32 k;
    u32 h;
    int i = 0;
    const T *t = data_021DB92C;
    u16 *hp = (u16 *)p;
    u16 *q;

    k = func_021ABE24((u8 *)p->f4);
    h = func_021ABE18((u8 *)p->f4);
    for (; i < 2; i++, t++) {
        func_021C6AE0((u32)buf);
        func_021C6AF0((u32)buf, k, t->a);
        func_021C6AF8((u32 *)buf, k);
        func_021C6AFC(buf, t->b);
        q = hp + i;
        hp[i] = func_021C6574(h, (u32)buf, 0);
        q[4] = func_021C6590(h, hp[i], 0, 0);
        func_021C67D8(h, q[4], 1);
    }
}










void func_021D0440(u16 *p)
{
    int i = 0;
    u32 h = func_021ABE18((u8 *)(((struct Obj09743 *)p)->f4));

    for (; i < 2; i++) {
        func_021C6628(h, p[4 + i]);
        func_021C6580((u8 *)h, p[i]);
    }
}










void func_021D046C(void *a, u32 b, u32 c)
{
    Arg021D046C arg;

    arg.h1 = func_021ABEA0((u32)a, 0xf);
    arg.h2 = func_021ABE18(a);
    arg.b = b;
    arg.c = c;
    func_021ABFA8(a, d_021DB93C, 0, 0, &arg, 0);
}









/*
 * Blocked: d_021DB934 (u32 table indexed by e->fC) is contested: another
 * overlay in the window starts an object at 0x021DB934 and this function has
 * no overlay_id site, so the ABS32 word stays wildcarded.
 */
void func_021D04A4(void *a)
{
    u8 *e;

    if (a != 0) {
        e = (u8 *)func_021AC1E0((u32)a);
        ((struct Obj13000 *)e)->f1A = 1;
        func_020061E4(d_021DB934[((struct Obj13000 *)e)->fC]);
    }
}









int func_021D04C4(u32 a)
{
if (a != 0) {
    return ((struct Obj18369 *)((u8 *)(func_021AC1E0(a))))->f1C;
}
return 1;
}









void func_021D04D8(void *a, St021D04D8 *s)
{
    *(Blk021D04D8 *)s = *((Blk021D04D8 *)func_021AC1AC((u32)a));
    func_0216E1A4(s->f8, (int)s->f10);
    s->f18 = ((u16 *)(s->f0 + 8))[s->fC];
}









void func_021D0504(void *a, St021D04D8 *s)
{
    if (func_0216E1C4(s->f8, (int)s->f10) == 1) {
        func_0219BF3C(s->f8, 0);
    }
}









void func_021D0520(u32 a, u8 *b)
{
    int h;
    Vec3 v;

    if (func_0216E1C4(((struct Obj09745 *)b)->f8, (int)((u16 *)(b + 0x10))) == 0) {
        func_021AC154(a);
        return;
    }
    func_0216D88C((const struct Actor *)((struct Obj09745 *)b)->f8, (struct VecFx32 *)&v);
    if (func_02163E58(((struct Obj09745 *)b)->f8, &v, &h) == 1) {
        v.y = h;
    }
    func_021AC1CC(a, &v);
}









void func_021D0568(u32 a, R *b)
{
    Vec3 v;

    if (b->h1a == 1 && b->h1c == 0) {
        func_021C6744((u32 *)b->f4, b->h18, 0, b->f20);
        if (func_021C6694((u32 *)b->f4, b->h18, 0x1000) == 0) {
            b->h1c = 1;
        }
        b->f20 = func_021C67A8(b->f4, b->h18, 0);
    } else {
        func_021C6744((u32 *)b->f4, b->h18, 0, b->f20);
    }
    func_021AC1B8(a, (V *)&v);
    func_021C6664(b->f4, b->h18, &v);
    func_021C67F4(b->f4, b->h18);
}









void func_021D05D8(void *a, void *b)
{
    Arg021D05D8 arg;
    Vec021D05D8 v;

    arg.h = func_021ABEA0((u32)b, 0x10);
    arg.a = a;
    func_0216D88C(a, (struct VecFx32 *)&v);
    func_021ABFA8(b, d_021DB968, (u32)&v, 0, &arg, 0);
}









void *func_021D0610(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0x20, 1, d_021DE664, 0xd5);

    p[0] = v;
    func_021D0648((struct S_021CFC80 *)p);
    return p;
}








void func_021D0634(u32 a, u8 *p)
{
    func_021D06E0((struct S_021CFC80 *)p);
    func_020307B0(p);
}








void func_021D0648(S_021CFC80 *p)
{
    int h;
    int i;
    int j;
    int k;

    h = func_021ABE24((u8 *)p->f0);
    for (i = 0; i < 3; i++) {
        p->a[i] = (int)func_02046E24(h, d_021DB95C[i]);
        if (func_02046F50((struct Tagged *)p->a[i], 2)) {
            func_02046FF8((int *)p->a[i]);
        }
    }
    j = 0;
    p->f10 = (int)func_02047400((void *)p->a[d_021DB950], 0, (void *)p->a[d_021DB950]);
    k = j;
    for (i = 0; i < 2; i++) {
        p->b[i] = (int)func_02047564((struct G3dOwner *)p->f10, (const struct G3dOwner *)p->a[d_021DB954[i]], k);
    }
    p->f1c = (int)func_0204767C((int)p->f10, (u32 *)p->b, 2);
    for (k = 0; k < 2; k++) {
        func_020477A4((struct G3dSys *)p->f1c, (u16)k);
    }
}








void func_021D06E0(S_021CFC80 *p)
{
    int i;

    func_02047738((struct Rec_021CEDA0 *)p->f1c);
    for (i = 0; i < 2; i++) {
        func_0204762C((struct Rec_021CEDA0 *)p->b[i]);
    }
    func_02047504((struct Rec_021CEDA0 *)p->f10);
    for (i = 0; i < 3; i++) {
        if (func_02046F50((struct Tagged *)p->a[i], 2)) {
            func_020470D0((u32 *)p->a[i]);
        }
        func_02046EFC((struct Tagged *)p->a[i]);
    }
}






void func_021D072C(void *a, S_021D072C *s)
{
    Src021D072C *r = (Src021D072C *)func_021AC1AC((u32)a);

    *(Src021D072C *)s = *r;
    s->fA = 0x78;
    s->f8 = func_0216D3CC(s->f4);
    s->f9 = 5;
}



void func_021D074C(void) {}







/*
 * func_02047888 (arm9 ARM leaf) is filed as src/matched/arm9/func_02047888.c
 * to give the witness.  EXACT*: the listing extent includes 2 pad bytes.
 */
void func_021D0750(int unused, S_021D0750 *s)
{
    int v;
    int i;
    void *r;

    s->fA++;
    if (s->fA >= 0x78) {
        r = (struct Row20 *)func_021D07FC((S_021D07FC *)s);
        if (r) {
            func_021D0824(r, s->f4);
        }
        s->fA = 0;
    }
    if (s->f8 != func_0216D3CC(s->f4)) {
        s->f9++;
        if (s->f9 >= 5) {
            r = (struct Row20 *)func_021D07FC((S_021D07FC *)s);
            if (r) {
                func_021D0824(r, s->f4);
            }
            s->f9 = 0;
        }
        s->f8 = func_0216D3CC(s->f4);
    }
    func_02047888((int *)s->f0[7], 0, &v);
    for (i = 0; i < 6; i++) {
        func_021D08BC((Row20 *)((struct Row20 *)s->rows[i]), v);
    }
}








void func_021D07D8(void *a, S_021D07D8 *s)
{
    int i;

    for (i = 0; i < 6; i++) {
        func_021D08D8((Row20 *)((struct Row20 *)s->rows[i]), s->f0[7]);
    }
}








Row20 *func_021D07FC(S_021D07FC *s)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (s->rows[i].f0 == 0) {
            return &s->rows[i];
        }
    }
    return 0;
}







void func_021D0824(int *p, int a)
{
    s16_021D0750 v[3];
    int k;

    p[0] = 1;
    p[1] = 0;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)(p + 2));
    if (func_021D0914(a, (s16_021D0750 *)v) == 0) {
        k = 0xE000;
    } else {
        k = 1 << 14;
    }
    p[3] += 0x7000;
    p[2] += (int)(((s64)v[0] * k + 0x800) >> 12);
    p[4] += (int)(((s64)v[2] * k + 0x800) >> 12);
}







/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 20.
 *
 * Addresses are Black-image addresses.
 */
void func_021D08B0(u32 a)
{
    func_02082BCC(a, 0, 20);
}







void func_021D08BC(Row20 *r, int v)
{
    if (r->f0 != 0) {
        r->f4 += 0x1000;
        if (r->f4 > v) {
            func_021D08B0((u32)r);
        }
    }
}







void func_021D08D8(Row20 *r, int a)
{
    int i;

    if (r->f0 != 0) {
        d_021DE628 = *(Blk021D08D8 *)r->f8;
        for (i = 0; i < 2; i++) {
            func_0204784C((struct AnmCtl *)a, (u16)i, &r->f4);
        }
        func_02047AC8((void *)a, (struct Arg *)(&d_021DE628));
    }
}







int func_021D0914(int a, s16_021D0750 *v)
{
    int r;

    r = func_0216D5F8((void *)a);
    if (func_0216D55C(a, 0x1000 * 2) == 0) {
        v[1] = 0;
        v[0] = func_021641E8(r);
        v[2] = func_021641F8(r);
        v[0] = v[0] << 16;
        v[2] = v[2] << 16;
    } else {
        func_0219E784(a, r, (s16_021D0750 *)v);
        v[1] = 0;
    }
    func_0207CDB8((s16_021D0750 *)v, (s16_021D0750 *)v);
    return r;
}







/*
 * Callee witnesses filed in wave A1 (witness lane).
 */
void *func_021D096C(int a)
{
    char *p;
    int r7;

    r7 = func_0200E588();
    func_02012EBC(func_020120F4((const struct Ctx *)a));
    p = func_02030734(5, 0x154, 1, d_021DE674, 0x5D);
    ((struct Obj07595 *)p)->f120 = 5;
    ((struct Obj07595 *)p)->f14C = (int)func_02030734(5, r7, 1, d_021DE674, 0x5F);
    func_021D09D0(a, p);
    ((struct Obj07595 *)p)->f128 = (int)func_0201A920(((struct Obj07595 *)p)->f120);
    return p;
}







void func_021D09D0(int a, char *out)
{
    int v;
    int t;
    int h;
    void *buf;

    h = (int)func_02012EBC(func_020120F4((const struct Ctx *)a));
    buf = func_02030734(0x8004, 0x8004 >> 3, 1, d_021DE674, 0x79);
    v = 0x8004 >> 3;
    func_020072CC(h, 5, 0x8004, buf, v);
    v = 0;
    t = (int)func_020073D8((struct Sub020073D8Ctrl *)h, 5, 0);
    if (func_0200E5A0((void *)t)) {
        int r = func_0200E5CC((void *)t);
        v = 1;
        if (r == 0) {
            v = 2;
        }
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 5);
    func_020307B0(buf);
    ((struct Obj20289 *)out)->f150 = v;
}







void func_021D0A48(void *a, u8 **pp)
{
    if (*pp != 0) {
        func_020307B0(((struct Obj20290 *)(*pp))->f14C);
        func_020307B0(((struct Obj20291 *)(*pp))->f128);
        func_020307B0(*pp);
        *pp = 0;
    }
}






/*
 * The 0x124 store is written in each arm of the mode test (cross-jumped
 * into one tail) and the 0x12C store after it: that puts the two stores in
 * different blocks when constants are derived, so the second offset is
 * rematerialised (`movs #0x4b; lsls`) instead of `adds r0,#8`.
 * Extent runs into func_021D0AB8 (filed separately).
 */
void func_021D0A74(int *p, u32 mode)
{
    if (p == 0) {
        return;
    }
    if (mode <= 1) {
        int y;
        if (mode == 0) {
            y = 0;
            p[0x49] = 3;
        } else {
            y = 1;
            p[0x49] = 4;
        }
        p[0x4B] = y;
    } else {
        p[0x4B] = 0;
        p[0x49] = 3;
    }
    func_0201A954((struct Party *)p[0x4A], p[0x49]);
}






/*
 * Unlabelled ov021 leaf hidden in a word run: stores the second argument at
 * +0x130 of the first.  Matched to supply the `matched` witness for the
 * pending ov010 caller func_0216A594.
 */
void func_021D0AB8(int *p, int v)
{
    ((struct Obj18370 *)p)->f130 = v;
}






void func_021D0AC0(void *a, u8 *p, u32 c)
{
    if (((struct Obj20292 *)p)->f130 != 0) {
        func_021D0B58((int)a, (struct Big *)p, c);
    } else {
        func_021D0AE4((char *)p, c);
    }
    func_021D0BCC((char *)p);
}






void func_021D0AE4(char *p, u32 mode)
{
    int a;
    int b;
    int s;
    u16 v;

    switch (mode) {
    case 0:
        a = 0x32;
        b = 0x14;
        break;
    case 1:
        a = 0x6E;
        b = 0x32;
        break;
    case 2:
        a = 0xA0;
        b = 0x14;
        break;
    case 3:
        a = 0xF0;
        b = 0x1E;
        break;
    case 4:
        a = 0x10E;
        b = 0x1E;
        break;
    default:
        a = 0x32;
        b = 0x14;
        break;
    }
    s = a + func_020056EC(b);
    v = ((struct Obj13002 *)p)->f120;
    func_02168878((u8 *)p, (u16)s, ((struct Obj13002 *)p)->f124, 0, 0, 0, (v & 0x7FFF) | 0x8000);
}






void func_021D0B58(int a, Big *dst, int idx)
{
    int h;
    void *buf;
    int v;

    h = (int)func_02012EBC(func_020120F4((const struct Ctx *)a));
    buf = func_02030734(0x8004, 0x8004 >> 3, 1, d_021DE674, 0x14C);
    v = 0x8004 >> 3;
    if (func_020072CC(h, 5, 0x8004, buf, v) == 1) {
        *dst = *func_0200E5F8((int)func_020073D8((struct Sub020073D8Ctrl *)h, 5, 0), idx);
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 5);
    func_020307B0(buf);
}






/*
 * Unblocked by matching func_02168AEC (ov010, EXACT): the +0008 ABS32 site now
 * attests as `matched`.
 */
void func_021D0BCC(char *p)
{
    func_02168AEC(((struct Obj20293 *)p)->f4);
}






int func_021D0BD8(u32 a, u32 b, u32 c, u32 d)
{
return func_021680C8(a, b, c, ((d << 16) >> 16));
}






void *func_021D0BE4(void *a, u8 *b, u16 *c)
{
    void *task;
    Work_021D0750 *w;

    task = func_020122C0(a, 0, func_021D0C58, 0x90);
    w = func_020124E8(task);
    w->f80 = (int)a;
    w->f88 = c;
    w->f84 = b;
    w->f8C = 0;
    w->f00 = 0x2E;
    w->f08 = func_0200E588();
    w->f0C = ((struct Obj20294 *)b)->f14C;
    w->f10 = d_0209DF0C;
    w->f14 = 0x200000;
    w->f78 = 1;
    w->f04 = 0;
    w->f06 = 0x8015;
    return task;
}





/*
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * Addresses are Black-image addresses.
 */
int func_021D0C58(u32 unused, u32 *state, W_021D0750 *w)
{
    u32 x;
    u32 h, sv;
    u8 *rec;
    int n, ok, r;

    x = w->f80;
    switch (*state) {
    case 0:
        w->f7c = (u32)func_021576D0((u8 *)w);
        if (func_021578A0((u32 *)w->f7c) == 0) {
            *w->f88 = 0;
            *state = 4;
        } else {
            *state = 1;
        }
        break;
    case 1:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928((u8 *)w->f7c);
        if (++w->f8c > 120) {
            *state = 2;
        }
        break;
    case 2:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928((u8 *)w->f7c);
        if (func_021578F0((void *)w->f7c)) {
            *state = 3;
        } else {
            *w->f88 = 0;
            *state = 4;
        }
        break;
    case 3:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928((u8 *)w->f7c);
        if (func_02157910((u8 *)w->f7c) == 0) {
            break;
        }
        h = (u32)func_020120F4((const struct Ctx *)x);
        rec = func_0200E8F8(func_02012EBC((struct Big *)h));
        sv = ((struct Obj20300 *)(w->f84))->f14C;
        n = func_0200E5E4((void *)sv);
        ok = func_0200E5A0((void *)sv);
        r = func_021D1058((Flags *)((struct Flags *)rec), n);
        if (ok != 0 && (r == 0 || n == 0)) {
            func_021D1080((Flags *)((struct Flags *)rec), n);
            func_0200E608((void *)h, (void *)(((struct Obj20301 *)(w->f84))->f14C), 0x8004);
            *w->f88 = 1;
        } else if (r != 0) {
            *w->f88 = 2;
        } else {
            *w->f88 = 0;
        }
        *state = 4;
        break;
    case 4:
        func_02157938((void *)w->f7c);
        *state = 5;
        break;
    case 5:
        if (func_0203D210()) {
            *state = 6;
        }
        break;
    case 6:
        func_021D09D0(x, (char *)w->f84);
        return 1;
    }
    return 0;
}





/*
 * The listing extent (568 B) runs over the unlabelled 8-byte follower leaf
 * at 0x021D0FE0 (return *(u32 *)(r1 + 0x150)); the function is 560 B.
 * s is u32 with (int) casts on the clamp (signed clamp, unsigned rank
 * ladder); that and the h, s, rec, rank declaration order give the
 * stack slots.
 *
 * Addresses are Black-image addresses.
 */
void func_021D0DB0(u32 a, u8 *w, u16 *outRank, u16 *outScore)
{
    u16 *st;
    u32 h;
    u32 s;
    u8 *rec;
    u32 rank;
    Rec_021D0750 *e;
    int i;
    Mon *m;
    void *mon;
    u32 h2;
    void *buf;
    void *x;

    st = (u16 *)(w + 0x134);
    s = 0;
    s += st[7] * 1000;
    s += st[8] * 80;
    s += st[1] * 5;
    s += st[3];
    s += st[5] * 5;
    s += st[6] * 2;
    s += st[11] * 15;
    s -= st[0] * 10;
    s -= st[2] * 10;
    s -= st[4] * 2;
    s -= st[9] * 80;
    s -= 500 - st[10];
    if ((int)s < 0) {
        s = 0;
    } else if ((int)s > 9999) {
        s = 9999;
    }

    if (s >= 6000) {
        rank = 6;
    } else if (s >= 5000) {
        rank = 5;
    } else if (s >= 4000) {
        rank = 4;
    } else if (s >= 3000) {
        rank = 3;
    } else if (s >= 2000) {
        rank = 2;
    } else if (s >= 1000) {
        rank = 1;
    } else {
        rank = 0;
    }
    *outRank = rank;
    *outScore = s;

    h = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
    rec = func_0200E8F8((void *)h);
    e = (Rec_021D0750 *)(rec + (u8)(U32(0x150) != 0) * 20);
    e->valid = 1;
    if (U32(0x124) == 3) {
        e->kind = 0;
    } else if (U32(0x124) == 4) {
        e->kind = 1;
    } else {
        e->kind = 0;
    }
    e->score = s;
    func_02082BCC(e->mons, 0, 0x10);
    for (i = 0; i < (int)U32(0x124); i++) {
        m = &e->mons[i];
        mon = func_0201AB28((void *)U32(0x128), i);
        m->species = func_02017E1C(mon, 5, 0);
        m->b2 = func_02017E1C(mon, 0x6f, 0);
        m->b3 = func_02017E1C(mon, 0x6e, 0);
    }

    if (U32(0x150) != 0) {
        h2 = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
        buf = func_02030734(0x8004, 0x8004 >> 3, 1, d_021DE674, 0x277);
        if (func_020072CC(h2, 5, 0x8004, buf, 0x8004 >> 3) == 1) {
            func_02082D44((u8 *)func_020073D8((struct Sub020073D8Ctrl *)h2, 5, 0) + 0x5a0, rec += 0x38, 0x22);
        }
        func_020307B0(buf);
        func_0200734C((struct Sub02007324Ctrl *)h2, 5);
    }

    x = func_02008C58((void *)h);
    func_02008E88(x, s);
    func_02008E68(x, (u8)rank);
}





/*
 * Unlabelled ov021 leaf hidden in a word run: returns the word at +0x150 of
 * its pointer argument (the second argument register).  Matched to supply the
 * `matched` witness for the pending ov010 caller func_0216A6B4.
 */
int func_021D0FE0(int x, int *p)
{
    return ((struct Obj18371 *)p)->f150;
}





void *func_021D0FE8(void *a, int unused, int c)
{
    void *task;
    Work_021D0C58 *w;
    int v;

    task = func_020122C0(a, 0, func_021D10A8, 0x10);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = 0;
    w->f08 = c;
    v = (int)func_021D1164(0x8015, (u32)func_0201210C(a));
    w->f0C = v;
    func_021D11B0((u32 *)v);
    return task;
}




int func_021D1028(const struct Ctx *a0)
{
    u8 *p = func_0200E8F8(func_02012EBC((struct Big *)func_020120F4(a0)));

    if (p[0] != 0) {
        if (p[0x14] != 0) {
            return 3;
        }
        return 1;
    }
    if (p[0x14] != 0) {
        return 2;
    }
    return 0;
}




u8 func_021D1058(Flags *p, u32 n)
{
    if (n < 0x80) {
        return (p->bits[(u8)(n >> 3)] >> (u8)(n & 7)) & 1;
    }
    return 1;
}




/*
 * Bit set in the 128-bit field at +0x28, ignoring out-of-range indices.
 * Region ov021 for the same reason as func_021D1058 (wave A1 witness).
 * Addresses are Black-image addresses.
 */
void func_021D1080(Flags *p, u32 n)
{
    if (n < 0x80) {
        p->bits[(u8)(n >> 3)] |= (u8)(1 << (u8)(n & 7));
    }
}




int func_021D10A8(u32 a, u32 *b, u32 *c)
{
    u32 s4 = (u32)func_020120F4((const struct Ctx *)c[0]);
    u32 r6 = (u32)func_02012EBC((struct Big *)s4);
    u32 x;

    switch (b[0]) {
    case 0:
        c[1] = (u32)func_02030734(0x8004, 0x1000, 0, d_021DE674, 0x34C);
        func_020072CC(r6, 5, 0x8004, (void *)c[1], 0x1000);
        x = (u32)func_020073D8((struct Sub020073D8Ctrl *)r6, 5, 0);
        if (c[2] == 1) {
            func_0200E684((void *)x);
        } else {
            func_02082BCC(x, 0, func_0200E588());
        }
        func_02012E4C((u8 *)s4, 5);
        b[0] = b[0] + 1;
        break;
    case 1:
        if (func_02012E7C((char *)s4, 5) == 2) {
            func_0200734C((struct Sub02007324Ctrl *)r6, 5);
            func_020307B0((void *)c[1]);
            func_021D11D8((u32 *)c[3]);
            func_021D1194((void *)c[3]);
            return 1;
        }
        break;
    }
    return 0;
}
