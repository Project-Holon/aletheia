/*
 * file:     union_oneself.c
 * unit:     yes
 * function: func_0217BD9C, func_0217BE44, func_0217BE64, func_0217C03C, func_0217C04C, func_0217C074, func_0217C1F0, func_0217C200, func_0217C2AC, func_0217C444, func_0217C450, func_0217C518, func_0217C5A8, func_0217C888, func_0217C88C, func_0217CAAC, func_0217CEB8, func_0217CFA8, func_0217D18C, func_0217D314, func_0217D51C, func_0217D5B8, func_0217D7A4, func_0217D890, func_0217D9A8, func_0217DC64, func_0217DC94, func_0217DCA8, func_0217DE88, func_0217DEA0, func_0217DFB4, func_0217E0A4, func_0217E188, func_0217E378, func_0217E440, func_0217E5A0, func_0217E838, func_0217E904, func_0217EAD8, func_0217EC04, func_0217EC1C, func_0217EC28, func_0217EC34, func_0217EC40, func_0217EC54, func_0217EC68, func_0217EC78, func_0217EC88, func_0217EC94, func_0217ECA0, func_0217ECAC, func_0217ECB8, func_0217ECD0, func_0217ECE8, func_0217ED04, func_0217ED10, func_0217ED2C, func_0217ED48, func_0217ED64, func_0217ED80, func_0217ED8C, func_0217ED98, func_0217EDA4, func_0217EDB0, func_0217EDBC, func_0217EDC8, func_0217EDD4, func_0217EDE0, func_0217EDEC, func_0217EDF8, func_0217EE04, func_0217EE10, func_0217EE1C, func_0217EE28, func_0217EE34, func_0217EE40, func_0217EE4C, func_0217EE90, func_0217EFE0, func_0217F020, func_0217F044, func_0217F060, func_0217F074, func_0217F098, func_0217F128, func_0217F188, func_0217F1EC, func_0217F210, func_0217F22C, func_0217F24C, func_0217F268, func_0217F2A8, func_0217F2F4, func_0217F310, func_0217F360, func_0217F378, func_0217F380, func_0217F388, func_0217F4AC, func_0217F4B4, func_0217F5E0, func_0217F624, func_0217F640, func_0217F794, func_0217F7B8, func_0217F7E4, func_0217F858, func_0217F894, func_0217F8C0, func_0217F8EC, func_0217F914, func_0217F928, func_0217F93C, func_0217F948, func_0217F958, func_0217F97C, func_0217F9BC, func_0217F9DC, func_0217FA10, func_0217FA54, func_0217FA78, func_0217FA9C, func_0217FABC, func_0217FACC, func_0217FAF0, func_0217FB30, func_0217FB70, func_0217FBD0, func_0217FC08, func_0217FC64, func_0217FCA4, func_0217FCC0, func_0217FCC4, func_0217FCE4, func_0217FD04, func_0217FD38, func_0217FD88, func_0217FDC8, func_0217FDF8, func_0217FE24, func_0217FE38, func_0217FE44, func_0217FEB8, func_0217FEF4, func_0217FF14
 * address:  0x0217BD9C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02030734  0x02030734  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_021736A0  0x021736A0  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   d_021807E8     0x021807E8  data  a4
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_02173AFC  0x02173AFC  thumb  ov012
 *   func_0203D14C  0x0203D14C  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_020392B8  0x020392B8  arm
 *   func_020399A8  0x020399A8  arm
 *   func_020362DC  0x020362DC  arm
 *   memcmp         0x0203EFC8  arm
 *   func_0217BAF0 0x0217BAF0 thumb ov019
 *   d_021807E4     0x021807E4  data a1
 *   func_02034714  0x02034714  arm
 *   func_02173A90  0x02173A90  thumb ov012
 *   func_02173518  0x02173518  thumb  ov012
 *   func_021735FC  0x021735FC  thumb  ov012
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02173B4C  0x02173B4C  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 *   func_02012934  0x02012934  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201AA88  0x0201AA88  thumb
 *   func_02173A04  0x02173A04  thumb ov012
 *   func_0217B9BC  0x0217B9BC  thumb ov019
 *   func_0217BA10  0x0217BA10  thumb ov019
 *   func_0217B974  0x0217B974  thumb ov019
 *   func_0217BAA8  0x0217BAA8  thumb ov019
 *   func_02173A48  0x02173A48  thumb ov012
 *   func_0217AEFC 0x0217AEFC thumb ov019
 *   func_0217AF04  0x0217AF04  thumb ov019
 *   func_0216F40C  0x0216F40C  thumb  ov010
 *   func_02082D44  0x02082D44  arm
 *   func_02173BB0  0x02173BB0  thumb  ov012
 *   func_0216F7F4  0x0216F7F4  thumb  ov010
 *   func_0203D378  0x0203D378  arm
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_021736E0  0x021736E0  thumb  ov012
 *   func_02172EDC  0x02172EDC  thumb  ov012
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02173650  0x02173650  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_02012F2C  0x02012F2C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02173D38  0x02173D38  thumb  ov012
 *   func_02174F4C  0x02174F4C  thumb  ov012
 *   func_02012944  0x02012944  thumb
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_02173CB4  0x02173CB4  thumb  ov012
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021CD5A4  0x021CD5A4  thumb  ov021
 *   func_021CD60C  0x021CD60C  thumb  ov021
 *   func_021CD688  0x021CD688  thumb  ov021
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0217357C  0x0217357C  thumb  ov012
 *   func_02173614  0x02173614  thumb  ov012
 *   func_02174B40  0x02174B40  thumb  ov012
 *   func_02174BB8  0x02174BB8  thumb  ov012
 *   func_02174C34  0x02174C34  thumb  ov012
 *   func_02175094  0x02175094  thumb  ov012
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021750B0  0x021750B0  thumb  ov012
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_021679A4  0x021679A4  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02174CE4  0x02174CE4  thumb  ov012
 *   func_021750D0  0x021750D0  thumb  ov012
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0217BA48  0x0217BA48  thumb  ov019
 *   func_0217BA6C  0x0217BA6C  thumb  ov019
 *   func_0217B9CC  0x0217B9CC  thumb  ov019
 *   func_021CC720  0x021CC720  thumb  ov021
 *   func_021CC810  0x021CC810  thumb  ov021
 *   func_021CC7B4  0x021CC7B4  thumb  ov021
 *   func_0217B9F4  0x0217B9F4  thumb  ov019
 *   func_02174E20  0x02174E20  thumb  ov012
 *   func_02174E64  0x02174E64  thumb  ov012
 *   func_02175240  0x02175240  thumb  ov012
 *   func_02175208  0x02175208  thumb  ov012
 *   func_02175214  0x02175214  thumb  ov012
 *   func_02174D98  0x02174D98  thumb  ov012
 *   func_02174DF0  0x02174DF0  thumb  ov012
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_0201A2A8  0x0201A2A8  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_0217AE20  0x0217AE20  thumb  ov019
 *   func_02174F34  0x02174F34  thumb  ov012
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02173408  0x02173408  thumb  ov012
 *   func_02173524  0x02173524  thumb  ov012
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_02012124  0x02012124  thumb
 *   func_02039338  0x02039338  arm
 *   func_0200855C  0x0200855C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   d_0218031C 0x0218031C data a2
 *   d_0218034C  0x0218034C  data a2
 *   d_02180330  0x02180330  data a2
 *   d_02180348  0x02180348  data a2
 *   d_021805E4 0x021805E4 data a2
 *   d_02180648  0x02180648  data a2
 *   d_0218053C  0x0218053C  data a2
 *   d_02180570  0x02180570  data a2
 *   d_02180300  0x02180300  data a2
 *   d_0218032C  0x0218032C  data a2
 *   d_02180320  0x02180320  data a2
 *   d_02180318  0x02180318  data a2
 *   d_02180328 0x02180328 data a2
 *   d_02180324 0x02180324 data a2
 *   func_020056EC 0x020056EC thumb
 *   d_02180380 0x02180380 data a2
 *   d_0218033C  0x0218033C  data a2
 *   d_02180368 0x02180368 data a2
 *   d_02180370 0x02180370 data a2
 *   d_02180360 0x02180360 data a2
 *   d_02180390     0x02180390  data  a2
 *   d_02180314  0x02180314  data a2
 *   d_02180310  0x02180310  data a2
 *   d_02180340  0x02180340  data a2
 *   d_02180304  0x02180304  data a2
 *   d_02180308  0x02180308  data a2
 *   d_02180344  0x02180344  data a2
 *   d_02180350  0x02180350  data a2
 *   d_02180338  0x02180338  data a2
 *   d_0218035C  0x0218035C  data a2
 *   d_02180358  0x02180358  data a2
 *   d_02180354  0x02180354  data a2
 *   d_021802F8  0x021802F8  data a2
 *   d_021802F0  0x021802F0  data a2
 *   d_021802F4  0x021802F4  data a2
 *   d_02180334  0x02180334  data a2
 *   d_0218030C  0x0218030C  data a2
 *   d_021802FC  0x021802FC  data a2
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   d_021807F8     0x021807F8  data  a1
 *   func_02024988  0x02024988  thumb
 *   func_020249A0  0x020249A0  thumb
 *   d_0218044C     0x0218044C  data
 *   func_0201EC74 0x0201EC74 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   d_021806AC 0x021806AC data a1
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02191558  0x02191558  thumb  ov021
 *   func_021915EC  0x021915EC  thumb  ov021
 *   func_0219160C  0x0219160C  thumb  ov021
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_021916A8  0x021916A8  thumb  ov021
 *   func_021916E0 0x021916E0 thumb ov021
 *   func_02190BE4 0x02190BE4 thumb ov021
 *   func_021909BC 0x021909BC thumb ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02190988  0x02190988  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
 *   d_0218042C 0x0218042C data a4
 *   d_021804DC 0x021804DC data a4
 *   d_0218046C     0x0218046C  data  a4
 *   d_021805A4     0x021805A4  data  a4
 *   d_021807FC     0x021807FC  data  a1
 *   d_0218050C     0x0218050C  data  a4
 *   d_021804B4     0x021804B4  data  a4
 *   d_021803A0     0x021803A0  data  ov019  a1
 *   func_0219161C  0x0219161C  thumb  ov021
 *   func_0201A4D4  0x0201A4D4  thumb
 *   func_0200AE3C  0x0200AE3C  thumb
 *   func_02191648  0x02191648  thumb  ov021
 *   func_02191674  0x02191674  thumb  ov021
 *   func_021904A8 0x021904A8 thumb ov021
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201A570 0x0201A570 thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F8  0x020120F8  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02012AD0  0x02012AD0  thumb
 *   d_02180718     0x02180718  data   ov019 a4
 *   func_02009D50 0x02009D50 thumb
 *   d_02180808     0x02180808  data   ov019 a4
 *   sub_020490F4   0x020490F4  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   sub_02034714   0x02034714  arm
 *   func_02049238  0x02049238  arm
 *   d_02180814     0x02180814  data  ov019 a4
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0204762C 0x0204762C arm
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 *   func_02047910 0x02047910 arm
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_02047AC8 0x02047AC8 arm
 *   func_0216DA30 0x0216DA30 thumb ov010
 *   MTX_Identity33_  0x0207ADC4  arm
 *   d_0218071C       0x0218071C  data   ov019 a4
 *   d_02180758       0x02180758  data   ov019 a4
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   d_02180794     0x02180794  data  ov019  a4
 *   d_0218079C     0x0218079C  data  ov019  a4
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   d_021807AC     0x021807AC  data  ov019  a4
 *   d_021807C0     0x021807C0  data  ov019  a4
 */
#include "../../matched/include/Obj04183.h"
#include "../../matched/include/Obj05947.h"
#include "../../matched/include/Obj12524.h"
#include "../../matched/include/Obj00610.h"
#include "../../matched/include/Obj07385.h"
#include "../../matched/include/Obj00033.h"
#include "../../matched/include/Obj09412.h"
#include "../../matched/include/Obj09414.h"
#include "../../matched/include/Obj07386.h"
#include "../../matched/include/Obj19418.h"
#include "../../matched/include/Obj12527.h"
#include "../../matched/include/Obj19419.h"
#include "../../matched/include/Obj19422.h"
#include "../../matched/include/Obj19424.h"
#include "../../matched/include/Obj19428.h"
#include "../../matched/include/Obj09416.h"
#include "../../matched/include/Obj03570.h"
#include "../../matched/include/Obj05956.h"
#include "../../matched/include/Obj00484.h"
#include "../../matched/include/Obj09417.h"
#include "../../matched/include/Obj09418.h"
#include "../../matched/include/Obj12529.h"
#include "../../matched/include/Obj19442.h"
#include "../../matched/include/Obj09419.h"
#include "../../matched/include/Obj05958.h"
#include "../../matched/include/Obj09420.h"
#include "../../matched/include/Obj02366.h"
#include "../../matched/include/Obj09421.h"
#include "../../matched/include/Obj03097.h"
#include "../../matched/include/Obj07393.h"
#include "../../matched/include/Obj04971.h"
#include "../../matched/include/Obj05959.h"
#include "../../matched/include/Obj04188.h"

struct Big;
struct Entry;
struct Link;
struct BigObj;
struct Ctx_0217BD9C;
struct Self;
struct Profile;
struct L0200ED54;
struct Party;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
struct Obj00020;
struct Obj_0217E188;
struct Rec534;
struct Sub02008700Obj;
struct WordSet;
struct MsgBank;
struct Strbuf;
struct U16Vec;
struct Fx;
struct R;
struct Rec;
struct Handle;
struct Pair;
struct Reg;
struct PrintSys;
struct VecFx32;
struct Sub020097BCObj;
struct E;
struct Tagged;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Actor;
struct Arg;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short          s16;

typedef struct Obj_0217BE64 {
    u8   pad00[0x18];
    u8  *p18;
    u8   pad1C[0x24 - 0x1C];
    u8   addr[6];
    u8   b2A;
    u8   pad2B[0x6C - 0x2B];
    s16  s6C;
} Obj_0217BE64;

typedef struct {
    u8 pad00[0x1c];
    u8 *f1c;
    u8 pad20[0x5a - 0x20];
    u8 lo5a : 2;
    u8 mode : 2;
    u8 pad5b[0x6c - 0x5b];
    s16 f6c;
} Obj_0217C074;

typedef struct {
    u8 pad[7];
    u8 lo : 3;
    u8 flag : 1;
} Sub_0217BD9C;

typedef struct {
    u8 pad00[0x14];
    Sub_0217BD9C *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x5c - 0x2e];
    u8 f5c;
    u8 pad5d[0x6e - 0x5d];
    s16 f6e;
} Obj_0217C2AC;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys_0217BD9C;

typedef struct {
    Sys_0217BD9C *sys;
} Ctx_0217BD9C;

typedef struct {
    u8 pad00[0x14];
    Sub_0217BD9C *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 f2e;
} Obj_0217C450;

typedef struct {
    u8 pad00[0x14];
    Sub_0217BD9C *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 f2e;
    u8 pad2f[0x64 - 0x2f];
    int f64;
    int f68;
    u8 pad6c[0x6e - 0x6c];
    s16 f6e;
} Obj_0217C5A8;

typedef struct {
    u8 pad00[0x14];
    Sub_0217BD9C *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x60 - 0x2e];
    int f60;
    int f64;
    int f68;
    u8 pad6c[0x6e - 0x6c];
    s16 f6e;
} Obj_0217C88C;

typedef struct { u8 pad[7]; u8 lo:3; u8 flag:1; } Sub_0217CAAC;

typedef struct {
    u8 pad00[0x14]; Sub_0217CAAC *f14;
    u8 pad18[0x2d-0x18]; u8 f2d, f2e;
    u8 pad2f[0x58-0x2f]; u16 f58;
    u8 pad5a[0x64-0x5a]; int f64, f68;
} Obj_0217CAAC;

typedef struct { u8 count:3; u8 flag:1; } Bits_0217BD9C;

typedef struct {
    u8 pad00[0x58];
    u16 f58;
} Obj_0217CEB8;

typedef struct {
    u8 pad00[0x14];
    u8 *f14;
    u8 pad18[0x5d - 0x18];
    u8 f5d;
} Obj_0217CFA8;

typedef struct {
    int f00;
    int f04;
    u16 f08;
    u8 f0a;
    u8 f0b;
    int f0c;
    int f10;
} Rec14;

typedef struct {
    u8 pad00[8];
    int f08;
    u8 pad0c[0x14 - 0x0c];
    int f14;
    int pad18;
    int f1c;
    Rec14 *f20;
} Rec30;

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub_0217CEB8;

typedef struct {
    u8 pad00[0x14];
    Sub_0217CEB8 *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x58 - 0x2e];
    u16 f58;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 pad5b[0x6c - 0x5b];
    s16 f6c;
} Obj_0217D314;

typedef struct {
    u8 f00;
    u8 f01;
    u8 pad02[0x14 - 0x02];
    Sub_0217CEB8 *f14;
    u8 pad18[0x5a - 0x18];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D5B8;

typedef struct {
    u8 pad00[0x14];
    Sub_0217CEB8 *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D7A4;

typedef struct {
    u8 pad00[0x14];
    Sub_0217CEB8 *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D890;

typedef struct {
    u8 f00;
    u8 pad01[0x2d - 1];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D9A8;

typedef struct {
    u8 pad00[8];
    int f8;
} Sys_0217C88C;

typedef struct {
    u8 pad000[0xde];
    u8 fde;
    u8 pad0df[0x168 - 0xdf];
    int f168;
    u8 pad16c[0x16e - 0x16c];
    u8 f16e;
} Work_0217BD9C;

typedef struct {
    u8 pad00[0x20];
    u8 f20[6];
    u8 f26;
    u8 pad27[0x2c - 0x27];
} Ent_0217DC94;

typedef struct {
    u8 pad00[0x18];
    Ent_0217DC94 ents[4];
    u8 padc8[0x134 - 0xc8];
    u32 f134[4];
} Work_0217DC94;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj_0217DEA0;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj_0217DFB4;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj_0217E0A4;

typedef struct {
    u8 f00;
    u8 pad01[0x6e - 1];
    s16 f6e;
} Obj_0217E188;

typedef struct {
    u8 pad00[8];
    int f8;
} Sys_0217E188;

typedef struct {
    Sys_0217E188 *sys;
    u8 pad04[0x3534 - 4];
    int f3534;
    int f3538;
    u8 pad353c[0x355c - 0x353c];
    u8 *w;
} Ctx_0217DC94;

typedef struct {
    int f0;
    int f4;
    void *f8;
} Sys_0217E440;

typedef struct {
    int f0;
    int f4;
    int f8;
} Sys_0217E5A0;

typedef struct {
    int f68;
    int f6c;
    u8 f70;
} Ent_0217DE88;

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fc;
    int f10;
    int f14;
    u8 pad18[0x34 - 0x18];
    int f34;
    u8 pad38[0x60 - 0x38];
    u16 f60;
    u8 pad62[0x64 - 0x62];
    int f64;
    Ent_0217DE88 ent[3];
    int f8c;
    int f90;
    u8 pad94[0xc0 - 0x94];
    int *fc0;
} Req;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys_0217E904;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Bits_0217DC94;

typedef struct {
    int f0;
    int f4;
    int f8;
} Sys_0217EAD8;

typedef struct Rec {
    u8  pad0[7];
    u8  lo7 : 3;
    u8  flag7 : 1;
    u8  hi7 : 4;
    u8  pad8;
    u8  f9;
    u8  padA[2];
    u16 name[13];
    u8  f26;
    u8  f27;
} Rec;

typedef struct Sys {
    u32 f0;
    u32 pad4;
    u32 f8;
} Sys;

typedef struct Sub_0217DC94 {
    u8   pad0[0x14];
    Rec *rec;
} Sub_0217DC94;

typedef struct Tmpl {
    u16 f0;
    u16 f2;
    u32 f4[4];
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1A;
    u32 f1C;
} Tmpl;

typedef struct Ent_0217F388 {
    void *p;
    u8    b;
    u8    pad5[3];
} Ent_0217F388;

typedef struct Pair {
    u32 f0;
    u32 f4;
} Pair;

typedef struct Ent_0217F4B4 {
    Pair *p;
    u8    b;
    u8    pad5[3];
} Ent_0217F4B4;

typedef struct Tiles {
    u32 f0;
    u32 a[6];
    u32 b[6];
} Tiles;

typedef struct Self {
    Sys   *sys;
    u8     pad4[0x2800];
    void  *win2804;
    void  *msg2808;
    u8     pad280C[0xc];
    void  *f2818;
    u8     pad281C[0x2830 - 0x281C];
    Sub_0217DC94    sub;
    u8     pad2848[0x352C - 0x2848];
    void  *f352C;
    Tiles *f3530;
} Self;

struct P16 { short x; short z; };

struct Bits_0217DC94 { u8 pad[7]; unsigned char low:3; unsigned char kind:1; unsigned char high:4; };

struct E { u32 a,b,c,d; u16 h; };

typedef struct { int x,y,z; } VecFx32;

struct B60 { u32 w[15]; };

extern void func_020061E4(u32 a);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const void *site, unsigned short tag);
extern void *func_02012EBC(void *p);
extern void func_0217422C(void *p, int a, int b);
extern int func_02174268(void *a);
extern void func_021736A0(void *a, volatile u16 *s);
extern u32 func_020307B0(void *p);
extern int func_0217BB04(void *p);
extern int func_0217B8E4(void *p, int v);
extern void func_02172D20(void *p);
extern int func_02172D68(void *p);
extern void func_021734A8(void *self, u32 id, u32 v);
extern int  func_02173AFC(int v);
extern void func_0203D14C(int a, int b, void *c);
extern int  func_0203D1B4(void);
extern u32 func_0203D1C0(u32 index);
extern void func_0203D1E8(u32 unused, void *arg);
extern void func_0203D7BC(u8 a0);
extern int  func_020392B8(void);
extern struct Entry *func_020399A8(void);
extern u32 func_020362DC(void);
extern int  memcmp(const void *a, const void *b, u32 n);
extern void func_0217BAF0(void *p, int x, unsigned int v);
void func_02034714(const void *expr, u32 line, const void *file);
int func_02173A90(void);
extern void func_02173518(void *a);
extern int func_021735FC(void *self, const void *p);
extern void func_02039C68(void *a, u32 b, u32 c);
extern u32 func_02039CB4(void *a, u32 b, u32 c);
extern int func_02173B4C(void *a);
extern unsigned int func_02080D24(int a);
void *func_02012934(const void *p);
void *func_020120F4(const void *p);
u32 func_0201AA1C(void *p);
u32 func_0201AAD4(void *p);
u32 func_0201AA88(void *p);
int func_02173A04(int a, ...);
int func_0217B9BC(unsigned int x);
void func_0217BA10(void *p, int x);
int func_0217B974(int id);
int func_0217BAA8(int a, int b, void *p, void *q);
int func_02173A48(int a, ...);
u16 func_0217AEFC(u32);
int func_0217AF04(void *a, u16 key);
extern void func_0216F40C(void *out, void *save, int mode, int flag, volatile u16 heap);
extern void func_02082D44(const void *a, void *b, int c);
extern u32 func_02173BB0(void *p);
extern void *func_0216F7F4(int a, void *b, int c);
extern u32 func_0203D378(void);
extern void *func_0200ED48(void *p);
extern u32 func_0203D1A4(void *p);
extern struct Rec44 *func_02012950(void *p, u32 i);
extern u32 func_02008530(const void *obj);
extern void func_0200ED54(void *l, u32 val);
extern struct Party *func_0201A920(u32 heap);
extern void func_021736E0(unsigned int x);
extern void func_02172EDC(void *a);
extern int func_0203CDBC(void);
extern void func_02173650(int a, void *b);
extern void func_02172D50(void *a);
extern void *func_02012F2C(void *p);
extern u32 func_0200FB24(void);
extern u32 func_02173D38(void *p);
extern int func_02174F4C(int a, int b, int c, int d);
extern u8 *func_02012944(void *p);
extern int func_0217BB20(void *p);
extern int func_02173CB4(void);
extern int func_021CD48C(int a, int b, int c, int d, int e, int f, int g, int h);
extern u32 func_021CD5A4(void *p);
extern void func_021CD60C(int h, void *a, void *b, void *c);
extern u32 func_021CD688(void *p);
extern u8 func_02008554(const void *obj);
extern u8 func_02008550(const void *obj);
extern void func_0217357C(void *p, int a, int b, int c);
extern void func_02173614(void *self, const void *mac);
extern void func_02174B40(u32 p);
extern u32 func_02174BB8(u32 a, u32 b);
extern int func_02174C34(u32 v);
extern void func_02175094(void *w, int v);
extern void *func_02188CB4(void *p);
extern void func_021750B0(void *p, int v);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern int func_021679A4(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void *func_021A3074(void *p);
extern u32 func_02174CE4(void *p);
extern u8 func_021750D0(void *p);
extern int func_0216D3CC(int a0);
extern void func_0216D410(void *h, u16 v);
extern int func_0216D454(void *h);
extern int func_0216D480(void *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);
extern int func_0217BA48(void *p, void *mask);
extern int func_0217BA6C(void *p, void *mask);
extern void *func_0217B9CC(void *p);
extern struct Obj_0217E188 *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern int func_021CC810(void *p);
extern u32 func_021CC7B4(void *p, void *out);
extern void func_0217B9F4(void *p);
u32 func_02174E20(void);
u32 func_02174E64(void);
void func_02175240(void *p, int v);
void func_02175208(void *p);
int func_02175214(void *p);
u32 func_02174D98(u32 p);
int func_02174DF0(u32 v);
void func_0201AC2C(const void *src, void *dst);
void func_0201A2A8(void *a0, void *a1);
void *func_0201292C(const void *p);
struct Sub02008700Obj *func_0200873C(void *sys);
const void *func_020084F4(const void *p);
void func_0217AE20(void *w);
int func_02174F34(void);
void func_02172D38(void *w);
void func_02173408(void *w);
void func_02173524(void *w, void *q);
void func_0217505C(void *p, int x);
void func_02012124(void *p, u32 v);
u16 func_02039338(void);
u8 func_0200855C(const void *obj);
void func_0201F02C(void *p, u32 i, void *a);
extern u32 func_020056EC(u32 v);
extern u8 func_0200856C(const void *obj);
extern u8 func_02008570(const void *obj);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(void *o, const void *src);
extern void func_0201EE0C(void *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(void *vec);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_0201F048(void *p, u32 i, u32 n);
extern void func_0201F094(void *p, u32 i, u32 a, u32 n);
extern void *func_02024988(int a0);
extern void func_020249A0(void *p, int bit);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern u32 func_0201ED04(void *p);
extern unsigned int func_02188C54(void *p);
extern int func_021904B0(u32 a, u32 b);
extern struct R *func_02191558(void *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
extern void func_021915EC(void *r);
extern void func_0219160C(void *p);
extern int func_021915B4(void *a);
extern u32 func_021904C8(void *a0);
extern void func_02045CAC(void *bank, u32 index, void *dest);
extern void func_0201F250(void *ws, void *dst, void *src);
extern void func_021916A8(void *r, u32 b, u16 c, u32 d);
extern u32 func_021916E0(void *p);
extern u32 *func_02190BE4(void *a, u32 b);
extern int func_021909BC(void *a);
extern int func_02190C78(void *h);
extern u32 func_02190A28(const void *arr, int n, u32 c, u16 d);
extern struct Handle *func_02190988(void *a, const void *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
extern int func_0219049C(void *p);
extern int func_021909E4(void *h);
extern void func_0219161C(void *r, int b, int c, u32 d);
extern u8 *func_0201A4D4(void *a0, u32 a1, u16 a2, u32 a3);
extern void *func_0200AE3C(void *p, u32 heap);
extern void func_02191648(void *r, int b, int c, u32 d);
extern void  func_02191674(void *a, int b, u16 c, u32 d, int e);
extern u32 func_021904A8(void *p);
extern u32 func_0201C6B4(const void *p);
extern void func_0201A570(void *p);
extern void *func_02188C80(void *p);
extern u8 *func_020120F8(const void *p);
extern void func_021A3038(void *a, void *v);
extern u16 func_02012AD0(const void *p);
extern int func_02009D50(void *obj, const void *unused, u32 id, u32 kind, void *out);
extern void *sub_020490F4(u32 id, u32 heap);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(void *self);
extern void sub_02034714(const char *expr, u32 line, const char *file);
extern void func_02049238(void *h);
extern int func_020470D0(void *p);
extern void func_02046EFC(void *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(void *a0, const void *a1, int a2);
extern void *func_0204767C(u32 a0, void *a1, int a2);
extern u32 func_020477A4(void *sys, u32 idx);
extern void func_0204762C(void *p);
extern void func_02047738(void *p);
extern void func_02047504(void *p);
extern int func_02047910(void *p, int idx, int amount);
extern void func_0216D88C(const void *a, void *out);
extern int func_02047AC8(void *a, void *b);
extern int func_0216DA30(u32 a);
extern void MTX_Identity33_(void *m);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern u16 func_02188C9C(void *p);
int func_0217BD9C(u8 *a, int b, int c, u8 *d);
int func_0217BE44(void *ctx, void *unused, u8 *a);
int func_0217BE64(void *w, Obj_0217BE64 *obj, u8 *a2, u8 *state);
int func_0217C03C(u8 *self);
int func_0217C04C(void *ctx, void *unused, u8 *a);
int func_0217C074(void *ctx, Obj_0217C074 *obj, u8 *a2, u8 *state);
int func_0217C1F0(u8 *self);
int func_0217C200(u8 *a, u8 *b, int c, u8 *d);
int func_0217C2AC(Ctx_0217BD9C *ctx, Obj_0217C2AC *obj, u8 *a2, u8 *state);
int func_0217C444(void *p);
int func_0217C450(void *ctx, Obj_0217C450 *obj, u8 *a2, u8 *state);
int func_0217C518(u8 *a, u8 *b, int c, u8 *d);
int func_0217C5A8(Ctx_0217BD9C *ctx, Obj_0217C5A8 *obj, u8 *a2, u8 *state);
int func_0217C888(void);
int func_0217C88C(void *ctx, Obj_0217C88C *obj, u8 *a2, u8 *state);
int func_0217CAAC(u8 *ctx, Obj_0217CAAC *obj, u8 *a, u8 *state);
int func_0217CEB8(void *ctx, Obj_0217CEB8 *obj, u8 *a2, u8 *state);
int func_0217CFA8(u8 *a, Obj_0217CFA8 *b, u8 *c, u8 *d);
int func_0217D18C(u8 *a, int b, u8 *c, u8 *d);
int func_0217D314(u8 *a, Obj_0217D314 *b, u8 *c, u8 *d);
int func_0217D51C(u8 *a, int *b, int c, u8 *d);
int func_0217D5B8(u8 *a, Obj_0217D5B8 *b, u8 *c, u8 *d);
int func_0217D7A4(u8 *a, Obj_0217D7A4 *b, u8 *c, u8 *d);
int func_0217D890(u8 *a, Obj_0217D890 *b, u8 *c, u8 *d);
int func_0217D9A8(Ctx_0217BD9C *ctx, Obj_0217D9A8 *obj, u8 *a2, u8 *state);
void func_0217DC64(u8 *base, int obj, int x);
void func_0217DC94(u8 *base, int obj, int x);
int func_0217DCA8(void *ctx, u8 *obj, int a2, u8 *state);
int func_0217DE88(void *ctx, void *unused, int a);
int func_0217DEA0(void *ctx, Obj_0217DEA0 *obj, int a2, u8 *state);
int func_0217DFB4(void *ctx, Obj_0217DFB4 *obj, int a2, u8 *state);
int func_0217E0A4(void *ctx, Obj_0217E0A4 *obj, int a2, u8 *state);
int func_0217E188(Ctx_0217DC94 *ctx, Obj_0217E188 *obj, u8 *a2, u8 *state);
int func_0217E378(u8 *w, void *obj, u8 *a2, u8 *state);
int func_0217E440(u8 *w, void *obj, int a2, u8 *state);
int func_0217E5A0(u8 *w, u8 *obj, u8 *a2, u8 *state);
int func_0217E838(u8 *w, void *obj, void *a2, u8 *state);
int func_0217E904(u8 *w, u8 *obj, u8 *a2, u8 *state);
int func_0217EAD8(u8 *w, void *obj, u8 *a2, u8 *state);
u16 func_0217EC04(void ***ctx);
u16 func_0217EC1C(int i);
u16 func_0217EC28(int i);
u16 func_0217EC34(int i);
u16 func_0217EC40(int i, int j);
u16 func_0217EC54(int i, int j);
u16 func_0217EC68(int i);
u16 func_0217EC78(int i);
u16 func_0217EC88(int i);
u16 func_0217EC94(int i);
u16 func_0217ECA0(int i);
u16 func_0217ECAC(int i);
u16 func_0217ECB8(void ***ctx);
u16 func_0217ECD0(void ***ctx);
u16 func_0217ECE8(int i);
u16 func_0217ED04(int i);
u16 func_0217ED10(int i);
u16 func_0217ED2C(int i);
u16 func_0217ED48(int i);
u16 func_0217ED64(int i);
u16 func_0217ED80(int i);
u16 func_0217ED8C(int i);
u16 func_0217ED98(int i);
u16 func_0217EDA4(int i);
u16 func_0217EDB0(int i);
u16 func_0217EDBC(int i);
u16 func_0217EDC8(int i);
u16 func_0217EDD4(int i);
u16 func_0217EDE0(int i);
u16 func_0217EDEC(int i);
u16 func_0217EDF8(int i);
u16 func_0217EE04(int i);
u16 func_0217EE10(int i);
u16 func_0217EE1C(int i);
u16 func_0217EE28(int i);
u16 func_0217EE34(int i);
u16 func_0217EE40(int i);
int func_0217EE4C(int **p, int x, int y);
void func_0217EE90(Self *self);
void func_0217EFE0(int a, unsigned int n);
void func_0217F020(u8 *p);
void func_0217F044(u8 *p);
int func_0217F060(int i);
void func_0217F074(void *p);
void func_0217F098(unsigned char *base, u8 *x);
void func_0217F128(unsigned char *base);
void func_0217F188(char *p, u32 arg);
u32 func_0217F1EC(u8 *p);
void func_0217F210(u8 *p, u8 *a, u32 b);
void func_0217F22C(u8 *p, u32 a);
void func_0217F24C(u8 *p);
int func_0217F268(char *p, u32 *out);
void func_0217F2A8(char *p, u32 a1, u32 a2, u32 a3, u32 a4);
void func_0217F2F4(u8 *p);
int func_0217F310(char *p, u32 a1);
void func_0217F360(char *p, u32 a);
void func_0217F378(void *p);
int func_0217F380(void *ctx, int a);
void func_0217F388(char *p, int a1, int kind, u8 *arg);
void func_0217F4AC(void *ctx);
int func_0217F4B4(char *p, int *hit, u8 *st, int *flag, u32 a4);
void func_0217F5E0(char *p, u32 a1);
void func_0217F624(char *p);
void func_0217F640(Self *self, u32 a1, u32 mask, int mode, int msg);
u32 func_0217F794(char *p,u32 a);
void func_0217F7B8(char *p);
int func_0217F7E4(u32 arg);
int func_0217F858(int a);
int func_0217F894(void *p,char *q);
void *func_0217F8C0(u16 id);
void func_0217F8EC(char *p);
void func_0217F914(char *p);
void func_0217F928(char *p);
void func_0217F93C(int x, int y);
void func_0217F948(char *p,u32 a,u32 b);
void func_0217F958(char *p,u32 key);
void func_0217F97C(char *p, u32 heap);
void func_0217F9BC(char *p);
void func_0217F9DC(char *p, u32 a);
void func_0217FA10(char *self, u32 *out, u32 a2, u16 a3);
void func_0217FA54(u32 *p);
void func_0217FA78(u32 *p);
void func_0217FA9C(u32 *p, u32 *b);
void func_0217FABC(u32 *p);
void func_0217FACC(u32 *p);
void func_0217FAF0(u32 *p);
struct E *func_0217FB30(struct E *p);
void func_0217FB70(char *p, u32 heap);
void func_0217FBD0(char *p);
void func_0217FC08(char *p, u32 a1, u32 a2);
void func_0217FC64(char *self, u32 *out, u32 a2, u16 a3, int flag);
void func_0217FCA4(u32 *p);
void func_0217FCC0(struct E *e);
void func_0217FCC4(u32 *p, u32 *b);
void func_0217FCE4(struct E *p);
void func_0217FD04(struct E *p);
void func_0217FD38(struct E *p);
u8 *func_0217FD88(u8 *base);
int func_0217FDC8(u8 *p);
int func_0217FDF8(u8 *p);
int func_0217FE24(u8 *p);
void func_0217FE38(u8 *p);
int func_0217FE44(int a, int mode, unsigned *out);
int func_0217FEB8(u8 *p);
int func_0217FEF4(u8 *p);
int func_0217FF14(void *a);
extern int d_021807E8[];
extern char d_021807E4[];
extern const u16 d_0218031C[];
extern const u16 d_0218034C[];
extern const u16 d_02180330[];
extern const u16 d_02180348[];
extern const u16 d_021805E4[][2];
extern const u16 d_02180648[][2];
extern const u16 d_0218053C[];
extern const u16 d_02180570[];
extern const u16 d_02180300[];
extern const u16 d_0218032C[];
extern const u16 d_02180320[];
extern const u16 d_02180318[];
extern const u16 d_02180328[];
extern const u16 d_02180324[];
extern const u16 d_02180380[][2];
extern const u16 d_0218033C[];
extern const u16 d_02180368[][2];
extern const u16 d_02180370[][2];
extern const u16 d_02180360[][2];
extern const u16 d_02180390[][2];
extern const u16 d_02180314[];
extern const u16 d_02180310[];
extern const u16 d_02180340[];
extern const u16 d_02180304[];
extern const u16 d_02180308[];
extern const u16 d_02180344[];
extern const u16 d_02180350[];
extern const u16 d_02180338[];
extern const u16 d_0218035C[];
extern const u16 d_02180358[];
extern const u16 d_02180354[];
extern const u16 d_021802F8[];
extern const u16 d_021802F0[];
extern const u16 d_021802F4[];
extern const u16 d_02180334[];
extern const u16 d_0218030C[];
extern const u16 d_021802FC[];
extern const char d_021807F8[];
extern int d_0218044C[];
extern const u8 d_021806AC[][4];
extern const u32 d_0218042C[];
extern const u32 d_021804DC[];
extern const Tmpl d_0218046C;
extern const Ent_0217F388  d_021805A4[];
extern const char d_021807FC[];
extern const u32  d_0218050C[];
extern const u32  d_021804B4[];
extern const u8  d_021803A0[][2][2];
extern struct P16 d_02180718[];
extern u32 d_02180808[];
extern const char d_02180814[];
extern struct B60 d_0218071C;
extern struct B60 d_02180758;
extern s16 d_02180794[][2];
extern s16 d_0218079C[][2];
extern s16 d_021807AC[][2];
extern s16 d_021807C0[][2];





/*
 * func_021736A0 is an unlabelled ov012 thumb leaf, now filed as
 * src/matched/ov/ov012_func_021736A0.c (pkt_ov012_021736A0), which resolves its call.
 */
int func_0217BD9C(u8 *a, int b, int c, u8 *d)
{
    int *p;
    int *q;
    int x, y;
    switch (*d) {
    case 0:
        if (a[0x282E] == 0)
            return 1;
        a[0x282E] = 0;
        func_020061E4(0x54B);
        p = func_02030734(4, 12, 1, (const char *)d_021807E8, 0x41A);
        *p = (int)func_02012EBC((struct Big *)(*(int *)(((struct Obj04183 *)a)->f0 + 8)));
        *(int * *)&((struct Obj04183 *)a)->f3558 = p;
        func_0217422C(a, 0x1d, (int)p);
        (*d)++;
        break;
    case 1:
        if (func_02174268(a) == 0)
            (*d)++;
        break;
    case 2:
        q = *(int * *)&((struct Obj04183 *)a)->f3558;
        x = q[2];
        y = q[1];
        if (y == 0)
            func_021736A0(a, (volatile u16 *)x);
        func_020307B0(*(int **)(a + 0x3558));
        *(int **)(a + 0x3558) = 0;
        return 1;
    }
    return 0;
}




int func_0217BE44(void *ctx, void *unused, u8 *a)
{
    func_020061E4(0x547);
    func_0217F210(ctx, a, 0xE2);
    return 1;
}





/*
 * Addresses are Black-image addresses.
 */
int func_0217BE64(void *w, Obj_0217BE64 *obj, u8 *a2, u8 *state)
{
    int i;

    if (func_0217BB04(w) == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        func_0203D14C(1, 1, 0);
        obj->s6C = 0;
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 0) {
            break;
        }
        if (func_0203D1B4() > 1) {
            for (i = 2; i < 5; i++) {
                if ((int)func_0203D1C0((u8)i) == 1) {
                    break;
                }
            }
            if (i < 5 || func_020392B8() > 2) {
                func_0217F210(w, a2, func_0217EC04(w));
                func_0217B8E4(w, 0);
                func_02172D20(w);
                *state = 4;
            } else {
                func_0203D7BC(1);
                func_0203D1E8((u32)func_020399A8(), 0);
                *state = 2;
            }
        } else {
            obj->s6C++;
            if (obj->s6C > 600 || (func_020362DC() & 2)) {
                func_02172D20(w);
                func_0217B8E4(w, 0);
                func_021734A8(w, 1, 0);
                if (obj->s6C > 600) {
                    func_0217F210(w, a2, func_0217EC04(w));
                } else {
                    func_0217F210(w, a2, 10);
                }
                *state = 5;
            }
        }
        break;
    case 2:
        if (obj->b2A == 1) {
            if (memcmp(obj->addr, obj->p18 + 0x64, 6) != 0) {
                if (func_02173AFC(2) == 1) {
                    func_0203D7BC(0);
                    *state = 6;
                }
            } else {
                if (func_02173AFC(1) == 1) {
                    func_020061E4(0x806);
                    func_0217B8E4(w, 7);
                    func_021734A8(w, 3, (u32)obj->p18);
                    func_021734A8(w, 1, 0);
                    *state = 3;
                }
            }
        }
        break;
    case 3:
        if (func_0217F1EC(w) == 1) {
            return 1;
        }
        break;
    case 4:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 0xF3)) {
            return 1;
        }
        break;
    case 5:
        if (func_02172D68(w) == 0) {
            *state = 4;
        }
        break;
    case 6:
        if (func_020392B8() <= 1) {
            func_02172D20(w);
            (*state)++;
        }
        break;
    case 7:
        if (func_02172D68(w) == 0) {
            obj->b2A = 0;
            *state = 0;
        }
        break;
    }
    return 0;
}




/*
 * Remaining two bytes are alignment padding.
 */
int func_0217C03C(u8 *self)
{
    func_021734A8(self, 1, 0);
    return 1;
}




int func_0217C04C(void *ctx, void *unused, u8 *a)
{
    func_020061E4(0x806);
    func_0217F210(ctx, a, 7);
    func_0217BAF0(ctx, (int)a, 1);
    return 1;
}





int func_0217C074(void *ctx, Obj_0217C074 *obj, u8 *a2, u8 *state)
{
    if (func_0217BB04(ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (obj->f1c == 0)
            func_02034714(d_021807E4, 0, d_021807E4);
        func_0203D14C(2, 1, obj->f1c + 0x64);
        obj->f6c = 0;
        *state = 1;
        break;
    case 1:
        if (func_0203D1B4() > 1) {
            func_0203D7BC(1);
            *state = 3;
            break;
        }
        obj->f6c++;
        if (obj->f6c > 600 || (func_020362DC() & 2)) {
            func_02172D20(ctx);
            func_0217B8E4(ctx, 0);
            func_021734A8(ctx, 2, 0);
            if (obj->f6c > 600)
                func_0217F210(ctx, a2, 8);
            else
                func_0217F210(ctx, a2, 10);
            *state = 2;
        }
        break;
    case 2:
        if (func_02172D68(ctx) == 0 && func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3))
            return 1;
        break;
    case 3:
        if (func_02173A90() == 1)
            *state = 4;
        break;
    case 4:
        switch (obj->mode) {
        case 1:
            func_021734A8(ctx, 3, (u32)obj->f1c);
            func_021734A8(ctx, 2, 0);
            func_0217B8E4(ctx, 9);
            return 1;
        case 2:
            func_021734A8(ctx, 2, 0);
            func_0217F210(ctx, a2, 8);
            func_02172D20(ctx);
            *state = 5;
            break;
        }
        break;
    case 5:
        if (func_02172D68(ctx) == 0 && func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3)) {
            func_0217B8E4(ctx, 0);
            return 1;
        }
        break;
    }
    return 0;
}




int func_0217C1F0(u8 *self)
{
    func_021734A8(self, 2, 0);
    return 1;
}





int func_0217C200(u8 *a, u8 *b, int c, u8 *d)
{
    int r;
    if (func_0217BB04((char *)a) == 1)
        return 1;
    if (b[0x70] == 10) {
        ((struct Obj05947 *)b)->f6E = 1;
        return 1;
    }
    ((struct Obj05947 *)b)->f6E = 0;
    switch (*d) {
    case 0:
        func_02173518(b + 0x14);
        func_021734A8(a, 4, 1);
        func_021735FC(b + 0x14, (const struct Entry *)(((struct Obj05947 *)b)->f20));
        r = (int)func_020399A8();
        func_02039C68((struct Link *)r, 2, 0x14);
        (*d)++;
        break;
    case 1:
        r = (int)func_020399A8();
        if (func_02039CB4((struct Link *)r, 2, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (func_02173B4C(a) == 1)
            (*d)++;
        break;
    case 3:
        if (func_02080D24(b[0x5b]) > 1)
            return 1;
        break;
    }
    return 0;
}





int func_0217C2AC(Ctx_0217BD9C *ctx, Obj_0217C2AC *obj, u8 *a2, u8 *state)
{
    void *h;
    int r;

    if (func_0217BB04((char *)ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (obj->f6e == 1) {
            obj->f6e = 0;
        } else if (obj->f5c == 0) {
            func_0217F210((u8 *)ctx, a2, func_0217EC1C(obj->f14->flag));
            obj->f5c++;
        } else {
            func_0217F210((u8 *)ctx, a2, func_0217EC88(obj->f14->flag));
        }
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC((u8 *)ctx) == 1)
            (*state)++;
        break;
    case 2:
        func_0217F360((char *)ctx, (u32)a2);
        (*state)++;
        break;
    case 3:
        h = func_02012934((void *)ctx->sys->f8);
        r = func_0217F380(ctx, (int)a2);
        if (r == -1)
            break;
        func_0217F378(ctx);
        if (r == -2 || r == 0) {
            func_0217F210((u8 *)ctx, a2, func_0217EC28(obj->f14->flag));
            obj->f2d = 0;
            func_0217B8E4((char *)ctx, 8);
            return 1;
        }
        if (r == 0x18) {
            func_020120F4((const struct Ctx_0217BD9C *)ctx->sys->fc);
            if ((int)func_0201AA1C(h) < 2) {
                func_0217F210((u8 *)ctx, a2, func_0217ECA0(obj->f14->flag));
                *state = 4;
                break;
            }
        } else if (r == 0x19) {
            if ((int)func_0201AAD4(h) > 0) {
                func_0217F210((u8 *)ctx, a2, func_0217ECB8((void ***)ctx));
                *state = 4;
                break;
            } else if (func_0201AA88(h) == 0) {
                func_0217F210((u8 *)ctx, a2, func_0217ECAC(obj->f14->flag));
                *state = 4;
                break;
            }
        }
        if (r == 0x1b) {
            func_0217B8E4((char *)ctx, 10);
            return 1;
        }
        obj->f2d = r;
        func_0217B8E4((char *)ctx, 8);
        return 1;
    case 4:
        if (func_0217F1EC((u8 *)ctx) == 1)
            *state = 0;
        break;
    }
    return 0;
}





int func_0217C444(void *p)
{
    func_0217F378(p);
    return 1;
}





int func_0217C450(void *ctx, Obj_0217C450 *obj, u8 *a2, u8 *state)
{
    if (func_0217BB04(ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (func_02173A04(obj->f2d) == 1) {
            if (obj->f2d == 0) {
                func_0217B8E4(ctx, 0x27);
                return 1;
            }
            func_0217F210(ctx, a2, func_0217EC40(obj->f2d, obj->f14->flag));
            (*state)++;
        }
        break;
    case 1:
        if (func_0217F1EC(ctx) != 0) {
            if (obj->f2e == 1) {
                func_0217B8E4(ctx, obj->f2d + 11);
                (*state)++;
            } else if (obj->f2e == 0) {
                func_0217B8E4(ctx, 0x27);
                func_0217F210(ctx, a2, func_0217EC54(obj->f2d, obj->f14->flag));
                return 1;
            }
        }
        break;
    case 2:
        if (func_0217F1EC(ctx) == 1)
            return 1;
        break;
    }
    return 0;
}





int func_0217C518(u8 *a, u8 *b, int c, u8 *d)
{
    int r;
    if (func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        func_02173518(b + 0x14);
        func_021734A8(a, 4, 1);
        func_021735FC(b + 0x14, (const struct Entry *)(((struct Obj12524 *)b)->f20));
        r = (int)func_020399A8();
        func_02039C68((struct Link *)r, 2, 0x14);
        (*d)++;
        break;
    case 1:
        r = (int)func_020399A8();
        if (func_02039CB4((struct Link *)r, 2, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (func_02173B4C(a) == 1)
            (*d)++;
        break;
    case 3:
        if (func_02080D24(b[0x5b]) > 1)
            return 1;
        break;
    }
    return 0;
}





int func_0217C5A8(Ctx_0217BD9C *ctx, Obj_0217C5A8 *obj, u8 *a2, u8 *state)
{
    int flag;
    void *h;

    if (func_0217BB04((char *)ctx) == 1)
        return 1;
    if (func_0217F1EC((u8 *)ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        func_0217F210((u8 *)ctx, a2, 9);
        (*state)++;
        break;
    case 1:
        if (obj->f2d == 0xff)
            break;
        if (obj->f2d == 0) {
            func_0217F210((u8 *)ctx, a2, func_0217EC34(obj->f14->flag));
            func_0217B8E4((char *)ctx, 0x27);
            return 1;
        }
        if (obj->f2d < 0x1b) {
            func_0217F210((u8 *)ctx, a2, func_0217EC68(obj->f2d));
            if (func_0217B9BC(obj->f2d) == 1) {
                func_0217BA10((char *)ctx, obj->f2d);
                func_0217F640((struct Self *)ctx, (u32)a2, 0, func_0217B974(obj->f2d), 0);
                *state = 2;
            } else {
                *state = 3;
            }
        } else if (func_02173A48(0) == 1) {
            func_0217F210((u8 *)ctx, a2, 0x13d);
            func_0217B8E4((char *)ctx, 0x27);
            return 1;
        }
        break;
    case 2:
        if (func_0217F794((char *)ctx, (u32)a2) == 1)
            *state = 3;
        break;
    case 3:
        func_0217F7B8((char *)ctx);
        func_0217F22C((u8 *)ctx, (u32)a2);
        (*state)++;
        break;
    case 4:
        obj->f6e = 0;
        if (func_0217F268((char *)ctx, (u32 *)(&flag)) != 1)
            break;
        h = func_02012934((void *)ctx->sys->f8);
        func_0217F24C((u8 *)ctx);
        if (func_0217BAA8((int)ctx, obj->f2d, &obj->f64, &obj->f68) == 0) {
            func_0217F210((u8 *)ctx, a2, 0x13e);
            flag = 0;
        } else if (obj->f2d == 0x18 && flag == 1) {
            func_020120F4((const struct Ctx_0217BD9C *)ctx->sys->fc);
            if ((int)func_0201AA1C(h) < 2) {
                flag = 0;
                obj->f6e = 1;
            }
        } else if (obj->f2d == 0x19 && flag == 1) {
            if ((int)func_0201AAD4(h) > 0) {
                flag = 0;
                obj->f6e = 3;
            } else if (func_0201AA88(h) == 0) {
                flag = 0;
                obj->f6e = 2;
            }
        }
        obj->f2e = flag;
        (*state)++;
        break;
    case 5:
        if (func_02173A48(obj->f2e) == 1) {
            if (obj->f64 != 0 && obj->f68 != 0)
                *state = 6;
            else
                *state = 10;
        }
        break;
    case 6:
        func_0217F640((struct Self *)ctx, (u32)a2, obj->f64, func_0217B974(obj->f2d), 1);
        (*state)++;
        break;
    case 7:
        if (func_0217F794((char *)ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx);
            if (obj->f68 == -1)
                *state = 10;
            else
                (*state)++;
        }
        break;
    case 8:
        func_0217F640((struct Self *)ctx, (u32)a2, obj->f64, func_0217B974(obj->f2d), 2);
        (*state)++;
        break;
    case 9:
        if (func_0217F794((char *)ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx);
            *state = 10;
        }
        break;
    case 10:
        if (obj->f2e == 0) {
            if (obj->f6e == 1)
                func_0217F210((u8 *)ctx, a2, 0x28);
            else if (obj->f6e == 2)
                func_0217F210((u8 *)ctx, a2, 0x2f);
            else if (obj->f6e == 3)
                func_0217F210((u8 *)ctx, a2, func_0217ECD0((void ***)ctx));
            else
                func_0217F210((u8 *)ctx, a2, func_0217EC78(obj->f2d));
            func_0217B8E4((char *)ctx, 0x27);
            return 1;
        }
        func_0217B8E4((char *)ctx, obj->f2d + 11);
        *state = 11;
        break;
    case 11:
        return 1;
    }
    return 0;
}




int func_0217C888(void)
{
    return 1;
}




int func_0217C88C(void *ctx, Obj_0217C88C *obj, u8 *a2, u8 *state)
{
    int f0c;
    int f08;
    int r;

    if (func_0217BB04(ctx) == 1)
        return 1;
    if (func_0217F1EC(ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        obj->f6e = 0;
        (*state)++;
        break;
    case 1:
        if (obj->f6e == 5)
            func_0217F5E0(ctx, (u32)a2);
        else if (obj->f6e == 0)
            func_0217F624(ctx);
        func_0217F388(ctx, (int)a2, obj->f6e, (u8 *)(&obj->f60));
        (*state)++;
        break;
    case 2:
        r = func_0217F4B4(ctx, &f0c, (u8 *)(&obj->f60), &f08, (u32)a2);
        if (f0c == 1) {
            obj->f6e = r;
            func_0217F4AC(ctx);
            (*state)--;
        } else if (r == -2 || r == 0) {
            func_0217F4AC(ctx);
            if (obj->f6e > 0) {
                obj->f6e = 0;
                (*state)--;
            } else {
                func_0217F624(ctx);
                func_0217B8E4(ctx, 7);
                return 1;
            }
        } else if (f08 == 1) {
            func_0217F624(ctx);
            func_0217F4AC(ctx);
            func_0217BA10(ctx, r);
            obj->f2d = r;
            *state = 3;
        } else if (r != -1) {
            func_0217F624(ctx);
            func_0217F4AC(ctx);
            if (func_0217BAA8((int)ctx, r, &obj->f64, &obj->f68) == 0) {
                func_0217F210(ctx, a2, 0x13e);
                *state = 5;
            } else {
                obj->f2d = r;
                func_0217B8E4(ctx, 8);
                return 1;
            }
        }
        break;
    case 3:
        func_0217F640(ctx, (u32)a2, 0, func_0217B974(obj->f2d), 0);
        (*state)++;
        break;
    case 4:
        if (func_0217F794(ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            *state = 1;
        }
        break;
    case 5:
        func_0217F640(ctx, (u32)a2, obj->f64, func_0217B974(obj->f2d), 1);
        (*state)++;
        break;
    case 6:
        if (func_0217F794(ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            if (obj->f68 == -1)
                *state = 9;
            else
                (*state)++;
        }
        break;
    case 7:
        func_0217F640(ctx, (u32)a2, obj->f64, func_0217B974(obj->f2d), 2);
        (*state)++;
        break;
    case 8:
        if (func_0217F794(ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            *state = 9;
        }
        break;
    case 9:
        func_0217F210(ctx, a2, func_0217EC88(obj->f14->flag));
        *state = 0;
        break;
    }
    return 0;
}




int func_0217CAAC(u8 *ctx, Obj_0217CAAC *obj, u8 *a, u8 *state)
{
    int offset, id;
    u32 selected, selected2;
    void *save;
    offset = func_0217AEFC(obj->f58) * 0x8c;
    id = (ctx + offset)[0x291b];
    switch (*state) {
    case 0:
        obj->f2d = id;
        switch (id) {
        case 1: func_0217F210(ctx,a,func_0217ED04(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 2: func_0217F210(ctx,a,func_0217ED10(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
            func_0217F210(ctx,a,func_0217ECE8(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 20: case 21: case 22: case 23:
            if ((int)((Bits_0217BD9C *)((ctx + offset) + 0x2916))->count < func_0217F060(id)) {
                func_0217F210(ctx,a,func_0217ED80(obj->f14->flag));
                func_0217BA10((char *)ctx,id);
                func_0217F640((struct Self *)ctx,(int)a,(int)0,func_0217B974(id),0);
                *state = 3;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ECE8(obj->f14->flag));
            func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 25:
            if ((int)((Bits_0217BD9C *)(ctx + 0x2916 + offset))->count < func_0217F060(id) &&
                ((Bits_0217BD9C *)(ctx + 0x2916 + offset))->flag == 0) {
                func_0217F210(ctx,a,func_0217ED8C(obj->f14->flag));
                *state = 10;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ED64(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 3:
            if ((int)((Bits_0217BD9C *)((ctx + offset) + 0x2916))->count < func_0217F060(id)) {
                func_0217F210(ctx,a,func_0217ED98(obj->f14->flag));
                *state = 10;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ED2C(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 24: func_0217F210(ctx,a,func_0217ED48(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 0: default: func_0217F210(ctx,a,0x151); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        }
        break;
    case 2:
        if (func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3)) return 1;
        break;
    case 1:
        if (func_0217F1EC(ctx) == 1) return 1;
        break;
    case 3:
        if (func_0217F794((char *)ctx,(u32)a) == 1) *state = 4;
        break;
    case 4:
        if (func_0217F1EC(ctx) == 1) {
            func_0217F7B8((char *)ctx); func_0217F22C(ctx,(u32)a); (*state)++;
        }
        break;
    case 5:
        if (func_0217F268((char *)ctx,&selected) == 1) {
            func_0217F24C(ctx);
            if (selected == 0) {
                func_0217F210(ctx,a,func_0217EDA4(obj->f14->flag));
                func_0217B8E4((char *)ctx, 0); *state = 2;
            } else if (func_0217BAA8((int)ctx,obj->f2d,&obj->f64,&obj->f68) == 0) {
                func_0217F210(ctx,a,0x13e); func_0217B8E4((char *)ctx, 0); *state = 6;
            } else {
                obj->f2e = selected; func_0217B8E4((char *)ctx, 0x26);
                func_0217F210(ctx,a,func_0217EE28(obj->f14->flag)); *state = 1;
            }
        }
        break;
    case 6:
        if (func_0217F1EC(ctx) == 1) return 1;
        func_0217F640((struct Self *)ctx,(int)a,(int)obj->f64,func_0217B974(obj->f2d),1); (*state)++;
        break;
    case 7:
        if (func_0217F794((char *)ctx,(u32)a) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx);
            if (obj->f68 == -1) *state = 1; else (*state)++;
        }
        break;
    case 8:
        func_0217F640((struct Self *)ctx,(int)a,(int)obj->f64,func_0217B974(obj->f2d),2); (*state)++;
        break;
    case 9:
        if (func_0217F794((char *)ctx,(u32)a) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx); *state = 1;
        }
        break;
    case 10:
        if (func_0217F1EC(ctx) == 1) {
            func_0217F22C(ctx,(u32)a); (*state)++;
        }
        break;
    case 11:
        if (func_0217F268((char *)ctx,&selected2) == 1) {
            func_0217F24C(ctx);
            if (selected2 == 0) {
                switch (obj->f2d) {
                case 3: func_0217F210(ctx,a,func_0217EDBC(obj->f14->flag)); break;
                case 25: func_0217F210(ctx,a,func_0217EDB0(obj->f14->flag)); break;
                }
                func_0217B8E4((char *)ctx, 0); *state = 2;
            } else {
                obj->f2e = selected2; func_0217B8E4((char *)ctx, 0x26); *state = 1;
                switch (obj->f2d) {
                case 3: func_0217F210(ctx,a,func_0217EE04(obj->f14->flag)); break;
                case 25:
                    save = func_02012934((void *)(*(u32 **)ctx)[2]);
                    if ((int)func_0201AAD4(save) > 0) {
                        func_0217F210(ctx,a,func_0217EDD4(obj->f14->flag));
                        func_0217B8E4((char *)ctx, 0); *state = 2;
                    } else if (func_0201AA88(save) == 0) {
                        func_0217F210(ctx,a,func_0217EDC8(obj->f14->flag));
                        func_0217B8E4((char *)ctx, 0); *state = 2;
                    } else func_0217F210(ctx,a,func_0217EDE0(obj->f14->flag));
                    break;
                }
            }
        }
        break;
    }
done:
    return 0;
}









int func_0217CEB8(void *ctx, Obj_0217CEB8 *obj, u8 *a2, u8 *state)
{
    int r;

    switch (*state) {
    case 0:
        r = func_0217AF04(ctx, obj->f58);
        switch (((u8 *)ctx + func_0217AEFC(obj->f58) * 0x8c)[0x291b]) {
        case 1:
            func_0217F210(ctx, a2, func_0217ED04(r));
            break;
        case 2:
            func_0217F210(ctx, a2, func_0217ED10(r));
            break;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 20: case 21: case 22: case 23:
            func_0217F210(ctx, a2, func_0217ECE8(r));
            break;
        case 25:
            func_0217F210(ctx, a2, func_0217ED64(r));
            break;
        case 3:
            func_0217F210(ctx, a2, func_0217ED2C(r));
            break;
        case 24:
            func_0217F210(ctx, a2, func_0217ED48(r));
            break;
        case 0:
        default:
            func_0217F210(ctx, a2, 0x151);
            break;
        }
        func_0217B8E4((char *)((u8 *)ctx), 0);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3))
            return 1;
        break;
    }
    return 0;
}









int func_0217CFA8(u8 *a, Obj_0217CFA8 *b, u8 *c, u8 *d)
{
    u8 *q;
    if (func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (((struct Obj00610 *)a)->f3540 != 0 || ((struct Obj00610 *)a)->f3544 != 0)
            func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
        ((struct Obj00610 *)a)->f3540 = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B3);
        ((struct Obj00610 *)a)->f3544 = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B5);
        func_0216F40C(((struct Obj00610 *)a)->f3540, (void *)((*(int **)a)[2]), 1, 0, 0x41);
        func_02082D44(((struct Obj00610 *)a)->f3540, ((struct Obj00610 *)a)->f3544, 0x678);
        func_02039C68((struct Link *)func_020399A8(), 3, 0x14);
        func_0217F210(a, c, func_0217EE4C((int **)a, b->f14[0x26], b->f14[0x27]));
        (*d)++;
        break;
    case 1:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (func_02173BB0(a) == 1)
            (*d)++;
        break;
    case 3:
        if (b->f5d == 1 && func_0217F1EC(a) == 1) {
            q = *(u8 * *)&((struct Obj00610 *)a)->f3544;
            q[4] |= 0x20;
            ((struct Obj00610 *)a)->f353C = func_0216F7F4((*(int **)a)[2], ((struct Obj00610 *)a)->f3544, 0x41);
            (*d)++;
        }
        break;
    case 4:
        func_02039C68((struct Link *)func_020399A8(), 4, 0x14);
        (*d)++;
        break;
    case 5:
        if (func_02039CB4((struct Link *)func_020399A8(), 4, 0x14) == 1)
            (*d)++;
        break;
    case 6:
        func_0217422C(a, 1, (int)(((struct Obj00610 *)a)->f353C));
        (*d)++;
        break;
    case 7:
        if (func_02174268(a) == 0)
            (*d)++;
        break;
    case 8:
        func_0217F210(a, c, 0x10);
        func_02039C68((struct Link *)func_020399A8(), 5, 0x14);
        (*d)++;
        break;
    case 9:
        if (func_0217F1EC(a) != 0 && func_02039CB4((struct Link *)func_020399A8(), 5, 0x14) == 1) {
            func_020307B0(((struct Obj00610 *)a)->f3540);
            func_020307B0(((struct Obj00610 *)a)->f3544);
            ((struct Obj00610 *)a)->f353C = 0;
            ((struct Obj00610 *)a)->f3540 = 0;
            ((struct Obj00610 *)a)->f3544 = 0;
            if (func_0203D378() == 1)
                func_0217B8E4((char *)((u8 *)((char *)a)), 7);
            else
                func_0217B8E4((char *)((u8 *)((char *)a)), 9);
            return 1;
        }
        break;
    }
    return 0;
}









int func_0217D18C(u8 *a, int b, u8 *c, u8 *d)
{
    int x, y;
    Rec30 *p;
    Rec14 *q;
    if (*d != 4 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        func_0217F210(a, c, 0x26);
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1) {
            func_02039C68((struct Link *)func_020399A8(), 6, 0x14);
            (*d)++;
        }
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 6, 0x14) == 1) {
            x = (int)func_020120F4((const struct Ctx_0217BD9C *)((*(int **)a)[3]));
            y = (int)func_0200ED48(func_02012EBC((struct Big *)x));
            func_0200ED54((struct L0200ED54 *)y, func_02008530((const struct Sub0200852CObj *)func_02012950((struct Sub24 *)x, func_0203D1A4((struct Link *)((int)func_020399A8())) ^ 1)));
            (*d)++;
        }
        break;
    case 3:
        p = func_02030734(0x41, 0x30, 1, (const char *)d_021807E8, 0xA54);
        p->f14 = (int)func_020120F4((const struct Ctx_0217BD9C *)((*(int **)a)[3]));
        p->f1c = (int)func_0201A920(0x41);
        q = func_02030734(4, 0x14, 0, (const char *)d_021807E8, 0xA5B);
        q->f00 = p->f14;
        q->f04 = p->f1c;
        q->f08 = 0;
        q->f0a = 0;
        q->f0b = 0;
        q->f0c = 1;
        q->f10 = 0;
        p->f20 = q;
        p->f08 = 0;
        *(Rec30 * *)&((struct Obj07385 *)a)->f3558 = p;
        func_0217422C(a, 2, (int)p);
        (*d)++;
        break;
    case 4:
        if (func_02174268(a) == 0) {
            p = *(Rec30 * *)&((struct Obj07385 *)a)->f3558;
            func_020307B0(p->f20);
            func_020307B0((void *)p->f1c);
            func_020307B0(*(Rec30 * *)&((struct Obj07385 *)a)->f3558);
            *(Rec30 * *)&((struct Obj07385 *)a)->f3558 = 0;
            (*d)++;
        }
        break;
    case 5:
        func_0217F210(a, c, 0x10);
        func_02039C68((struct Link *)func_020399A8(), 7, 0x14);
        (*d)++;
        break;
    case 6:
        if (func_0217F1EC(a) != 0 && func_02039CB4((struct Link *)func_020399A8(), 7, 0x14) == 1) {
            if (func_0203D378() == 1)
                func_0217B8E4((char *)((u8 *)((char *)a)), 7);
            else
                func_0217B8E4((char *)((u8 *)((char *)a)), 9);
            return 1;
        }
        break;
    }
    return 0;
}









int func_0217D314(u8 *a, Obj_0217D314 *b, u8 *c, u8 *d)
{
    int idx;
    int n;
    idx = func_0217AEFC(b->f58);
    if (func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        b->b0 = 1;
        func_021736E0(b->f2d);
        func_0203D14C(2, 1, a + 0x2974 + idx * 0x8c);
        b->f6c = 0;
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 0)
            break;
        if (func_0203D1B4() > 1) {
            func_0203D7BC(1);
            n = func_0217F060(b->f2d);
            if (n <= (int)func_0203D1A4((struct Link *)((int)func_020399A8()))) {
                *d = 4;
            } else {
                func_021734A8(a, 3, (u32)(a + 0x2910 + idx * 0x8c));
                b->b1 = 1;
                switch (b->f2d) {
                case 0x14:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x1f);
                    break;
                case 0x15:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x20);
                    break;
                case 0x16:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x21);
                    break;
                case 0x17:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x22);
                    break;
                case 3:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0xe);
                    break;
                case 0x19:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x24);
                    break;
                default:
                    func_02034714((const char *)d_021807E4, (int)0, (const char *)d_021807E4);
                    break;
                }
                *d = 3;
            }
        } else {
            b->f6c++;
            if (b->f6c > 600 || (func_020362DC() & 2)) {
                b->b0 = 0;
                func_0217B8E4((char *)((u8 *)((char *)a)), (int)0);
                *d = 4;
            }
        }
        break;
    case 2:
        switch (b->f2d) {
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            func_0217F210(a, c, func_0217EE40(b->f14->b3));
            break;
        case 3:
            func_0217F210(a, c, func_0217EE1C(b->f14->b3));
            break;
        case 0x19:
            func_0217F210(a, c, func_0217EDF8(b->f14->b3));
            break;
        }
        *d = 3;
        break;
    case 3:
        if (func_0217F1EC(a) == 1)
            return 1;
        break;
    case 4:
        func_02172D20(a);
        (*d)++;
        break;
    case 5:
        if (func_02172D68(a) == 0)
            *d = 2;
        break;
    }
    return 0;
}









int func_0217D51C(u8 *a, int *b, int c, u8 *d)
{
    int r, t;
    if (*d < 3 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        func_02172EDC(a);
        (*d)++;
        break;
    case 1:
        if (func_02172D68(a) != 0)
            break;
        r = func_0203CDBC();
        if (r == 1) {
            t = b[8];
            if (t != 0) {
                func_02173650((int)((u8 *)(b + 5)), (u8 *)t);
                func_021734A8(a, 3, 0);
            }
            func_02172D50(a);
            (*d)++;
        }
        break;
    case 2:
        if (func_02172D68(a) == 0)
            (*d)++;
        break;
    case 3:
        if (func_0217F1EC(a) == 1) {
            if (func_020362DC() & 0xf3)
                return 1;
        }
        break;
    }
    return 0;
}









int func_0217D5B8(u8 *a, Obj_0217D5B8 *b, u8 *c, u8 *d)
{
    int *p;
    if (*d != 4 && *d != 5 && *d != 8 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (b->b1 == 1)
            *d = 6;
        else
            (*d)++;
        break;
    case 1:
        func_02039C68((struct Link *)func_020399A8(), 8, 0x14);
        (*d)++;
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 8, 0x14) == 1)
            (*d)++;
        break;
    case 3:
        if (func_0217F1EC(a) == 1) {
            if (b->f01 == 0xe) {
                p = func_02030734(0x41, 8, 1, (const char *)d_021807E8, 0xB9A);
                p[1] = (*(int **)a)[2];
                *(int * *)&((struct Obj00033 *)a)->f3558 = p;
                func_0217422C(a, 3, (int)p);
            } else {
                p = func_02030734(0x41, 0x18, 1, (const char *)d_021807E8, 0xBA2);
                p[1] = (*(int **)a)[2];
                p[2] = (int)func_02012934((void *)(*(int **)a)[2]);
                p[3] = (int)func_02012EBC((struct Big *)((*(int **)a)[2]));
                p[4] = (int)func_02012F2C((int *)((*(int **)a)[2]));
                *(int * *)&((struct Obj00033 *)a)->f3558 = p;
                func_0217422C(a, 4, (int)p);
            }
            (*d)++;
        }
        break;
    case 4:
        if (func_02174268(a) == 0) {
            func_020307B0(*(int * *)&((struct Obj00033 *)a)->f3558);
            *(int * *)&((struct Obj00033 *)a)->f3558 = 0;
            if (func_0200FB24() != 0) {
                func_0217B8E4((char *)((u8 *)((char *)a)), 1);
                return 1;
            }
            func_02172D50(a);
            (*d)++;
        }
        break;
    case 5:
        if (func_02172D68(a) == 0)
            return 1;
        break;
    case 6:
        if (func_02173D38(a) == 1)
            (*d)++;
        break;
    case 7:
        switch (a[0x282B]) {
        case 1:
            if (b->f01 == 0xe)
                func_0217F210(a, c, func_0217EE10(b->f14->b3));
            else
                func_0217F210(a, c, func_0217EDEC(b->f14->b3));
            *d = 3;
            break;
        case 2:
            if (b->f01 == 0xe)
                func_0217F210(a, c, func_0217EE1C(b->f14->b3));
            else
                func_0217F210(a, c, func_0217EDF8(b->f14->b3));
            func_02172D20(a);
            *d = 8;
            break;
        }
        break;
    case 8:
        if (func_0217F1EC(a) == 1 && func_02172D68(a) == 0) {
            func_021734A8(a, 3, 0);
            return 1;
        }
        break;
    }
    return 0;
}









int func_0217D7A4(u8 *a, Obj_0217D7A4 *b, u8 *c, u8 *d)
{
    int *p;
    if (*d < 4 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (((struct Obj09412 *)a)->f355C != 0)
            func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
        p = *(int * *)&((struct Obj09412 *)a)->f0;
        ((struct Obj09412 *)a)->f355C = func_02174F4C(p[2], p[3], p[0], b->b1);
        func_0217F210(a, c, func_0217EC94(b->f14->b3));
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1)
            (*d)++;
        break;
    case 2:
        func_02039C68((struct Link *)func_020399A8(), 0xb, 0x14);
        (*d)++;
        break;
    case 3:
        if (func_02039CB4((struct Link *)func_020399A8(), 0xb, 0x14) == 1)
            (*d)++;
        break;
    case 4:
        func_0217422C(a, b->f2d + 1, 0);
        (*d)++;
        break;
    case 5:
        if (func_02174268(a) == 0) {
            func_0217BAF0((char *)a, (int)c, 1);
            func_0217B8E4((char *)((u8 *)((char *)a)), 0x28);
            return 1;
        }
        break;
    }
    return 0;
}








int func_0217D890(u8 *a, Obj_0217D890 *b, u8 *c, u8 *d)
{
    int *p;
    if (*d < 4 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (b->b1 == 0)
            func_0217F210(a, c, func_0217EC94(b->f14->b3));
        else
            func_0217F210(a, c, func_0217EE34(b->f14->b3));
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1)
            (*d)++;
        break;
    case 2:
        if (b->b1 == 0)
            func_02039C68((struct Link *)func_020399A8(), 0xb, 0x14);
        (*d)++;
        break;
    case 3:
        if (b->b1 == 0) {
            if (func_02039CB4((struct Link *)func_020399A8(), 0xb, 0x14) == 1)
                (*d)++;
        } else {
            (*d)++;
        }
        break;
    case 4:
        func_0217422C(a, b->f2d + 1, 0);
        (*d)++;
        break;
    case 5:
        if (func_02174268(a) == 0) {
            if (((struct Obj09414 *)a)->f355C != 0)
                func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
            p = *(int * *)&((struct Obj09414 *)a)->f0;
            ((struct Obj09414 *)a)->f355C = func_02174F4C(p[2], p[3], p[0], b->b1);
            func_0217BAF0((char *)a, (int)c, 1);
            func_0217B8E4((char *)((u8 *)((char *)a)), 0x28);
            return 1;
        }
        break;
    }
    return 0;
}








int func_0217D9A8(Ctx_0217BD9C *ctx, Obj_0217D9A8 *obj, u8 *a2, u8 *state)
{
    Work_0217BD9C *w = *(Work_0217BD9C * *)&((struct Obj07386 *)ctx)->f355C;
    int r;

    func_0203D1A4((struct Link *)func_020399A8());
    if (w == 0)
        func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);

    if (func_0217BB20((char *)ctx) == 1) {
        if (w->f168 != 0)
            func_021CD5A4((u32 *)w->f168);
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        if (func_0217F060(obj->f2d) == 2) {
            w->fde = 1;
            if (func_0203D378() == 1) {
                if (func_02173CB4() == 1)
                    *state = 100;
            } else {
                *state = 100;
            }
            break;
        }
        func_0203D7BC(0);
        if (func_0203D378() == 1) {
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), (int)a2,
                                    func_0217F060(obj->f2d),
                                    func_0217F060(obj->f2d), 0x41, 0, 0, 0);
            func_021CD60C(w->f168, ctx, func_0217DC64, func_0217DC94);
        } else if (obj->b1 == 0) {
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), (int)a2,
                                    func_0217F060(obj->f2d),
                                    func_0217F060(obj->f2d), 0x41, 2, 0, 0);
        } else {
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), (int)a2,
                                    func_0217F060(obj->f2d),
                                    func_0217F060(obj->f2d), 0x41, 3, 0, 0);
        }
        if (obj->b1 == 0) {
            func_021736E0(obj->f00);
            func_02039C68((struct Link *)func_020399A8(), 0xc, 0x14);
        }
        (*state)++;
        break;
    case 1:
        if (obj->b1 == 0) {
            if (func_02039CB4((struct Link *)func_020399A8(), 0xc, 0x14) == 1) {
                func_0203D1E8((int)func_020399A8(), (void *)1);
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 2:
        (*state)++;
        break;
    case 3:
        r = func_021CD688((u8 *)w->f168);
        if (r != 0) {
            w->f16e = func_021CD5A4((u32 *)w->f168);
            w->f168 = 0;
            switch (r) {
            case 1:
                *state = 100;
                func_0203D7BC(1);
                break;
            case 2:
                *state = 200;
                break;
            case 3:
                *state = 200;
                break;
            case 4:
                *state = 200;
                break;
            default:
                func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
                break;
            }
        }
        break;
    case 4:
        break;
    case 100:
        w->fde = 1;
        func_0217B8E4((char *)((u8 *)((char *)ctx)), 0x29);
        return 1;
    case 200:
        func_0217F210((u8 *)ctx, a2, 0x14c);
        w->fde = 2;
        (*state)++;
        break;
    case 201:
        if (func_0217F1EC((u8 *)ctx) == 1) {
            func_0217B8E4((char *)((u8 *)((char *)ctx)), 0x32);
            func_0217BAF0((char *)ctx, (int)a2, 1);
            return 1;
        }
        break;
    case 300:
        w->fde = 2;
        func_0217B8E4((char *)((u8 *)((char *)ctx)), 0x32);
        func_0217BAF0((char *)ctx, (int)a2, 1);
        return 1;
    }
    return 0;
}






void func_0217DC64(u8 *base, int obj, int x)
{
    int a = func_02008554((const struct Sub0200852CObj *)obj);
    int b = func_02008550((const struct Sub0200852CObj *)obj);
    func_0217357C(base + 0x2844, x, a, (u8)b);
}






void func_0217DC94(u8 *base, int obj, int x)
{
    func_02173614(base + 0x2844, (const u8 *)x);
}






int func_0217DCA8(void *ctx, u8 *obj, int a2, u8 *state)
{
    Work_0217DC94 *w = *(Work_0217DC94 * *)&((struct Obj19418 *)ctx)->f355C;
    int me;
    int n;
    int i;
    int a;
    int x;

    me = func_0203D1A4((struct Link *)((int)func_020399A8()));
    if (w == 0)
        func_02034714((const char *)d_021807E4, (int)0, (const char *)d_021807E4);

    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        func_02039C68((struct Link *)func_020399A8(), 0xd, 0x14);
        (*state)++;
        break;
    case 1:
        if (func_02039CB4((struct Link *)func_020399A8(), 0xd, 0x14) == 1)
            (*state)++;
        break;
    case 2:
        func_02174B40((u32)ctx);
        func_02039C68((struct Link *)func_020399A8(), 0xe, 0x14);
        (*state)++;
        break;
    case 3:
        if (func_02039CB4((struct Link *)func_020399A8(), 0xe, 0x14) == 1)
            (*state)++;
        break;
    case 4:
        if (func_02174BB8((u32)(&w->ents[me]), 0) == 1)
            (*state)++;
        break;
    case 5:
        if (func_0217FDC8((u8 *)w) == 1) {
            n = func_0203D1B4();
            for (i = 0; i < n; i++) {
                if (w->ents[i].f26 == 1) {
                    a = func_02008554((const struct Sub0200852CObj *)(&w->ents[i]));
                    func_0217357C(obj + 0x14, (int)w->ents[i].f20, a,
                                  (u8)(int)func_02008550((const struct Sub0200852CObj *)(&w->ents[i])));
                }
            }
            (*state)++;
        }
        break;
    case 6:
        func_02039C68((struct Link *)func_020399A8(), 0xf, 0x14);
        (*state)++;
        break;
    case 7:
        if (func_02039CB4((struct Link *)func_020399A8(), 0xf, 0x14) == 1)
            (*state)++;
        break;
    case 8:
        if (func_02174C34(w->f134[me]) == 1)
            (*state)++;
        break;
    case 9:
        if (func_0217FDF8((u8 *)w) == 1)
            (*state)++;
        break;
    case 10:
        x = (int)func_0200ED48(func_02012EBC(func_020120F4((const struct Ctx_0217DC94 *)((*(int **)ctx)[3]))));
        n = func_0203D1B4();
        for (i = 0; i < n; i++) {
            if (w->ents[i].f26 == 1 && i != func_0203D1A4((struct Link *)((int)func_020399A8())))
                func_0200ED54((struct L0200ED54 *)x, (int)func_02008530((const struct Sub0200852CObj *)(&w->ents[i])));
        }
        func_02175094(w, 1);
        func_0217B8E4(ctx, 0x2a);
        return 1;
    }
    return 0;
}





int func_0217DE88(void *ctx, void *unused, int a)
{
    func_0217F074(ctx);
    func_0217BAF0(ctx, a, 0);
    return 1;
}






int func_0217DEA0(void *ctx, Obj_0217DEA0 *obj, int a2, u8 *state)
{
    u8 *w = *(u8 * *)&((struct Obj19419 *)ctx)->f355C;
    void *a;
    int m;
    unsigned out;
    int k;
    s16 v[3];

    a = func_02188CB4((void *)a2);
    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    if (*state == 0) {
        if (func_0217FE44(a2, func_0217F060(obj->f2d), &out) == 1) {
            func_021750B0(w, out);
            func_0217B8E4(ctx, 0x2b);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_0217FEF4(w) == 1) {
            func_0217B8E4(ctx, 0x32);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_0217FF14((void *)a2) == 1) {
            func_0217B8E4(ctx, 0x31);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_020362DC() & 1) {
            k = 0;
            func_021A3460((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
            if (func_021679A4((void *)(((struct Obj12527 *)w)->f0), v[2], v[1], v[0], (int)(&m), (int)(&k)) == 1) {
                w[0x16c] = m;
                func_0217B8E4(ctx, 0x33);
                func_0217BAF0(ctx, a2, 1);
                return 1;
            }
        }
    }
    return 0;
}






int func_0217DFB4(void *ctx, Obj_0217DFB4 *obj, int a2, u8 *state)
{
    void *w = ((struct Obj19422 *)ctx)->f355C;
    void *h;
    unsigned out;
    int r;

    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        (*state)++;
        break;
    case 1:
        if (func_02174CE4(w) == 1)
            (*state)++;
        break;
    case 2:
        if (func_0217F1EC(ctx) != 0) {
            r = func_021750D0(w);
            if (r == 1) {
                (*state)++;
            } else if (r == 0) {
                func_0217B8E4(ctx, 0x2c);
                return 1;
            }
        }
        break;
    case 3:
        h = func_021A3074(func_02188CB4((void *)a2));
        if (func_0216D3CC((int)h) == 1) {
            func_0217FE44(a2, func_0217F060(obj->f2d), &out);
            func_0216D410(h, (out & 1) ? 2 : 3);
            (*state)++;
        }
        break;
    case 4:
        h = func_021A3074(func_02188CB4((void *)a2));
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4(ctx, 0x2d);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217E0A4(void *ctx, Obj_0217E0A4 *obj, int a2, u8 *state)
{
    void *w = ((struct Obj19424 *)ctx)->f355C;
    void *h;
    unsigned out;

    h = func_021A3074(func_02188CB4((void *)a2));
    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        func_021750B0(w, 0xff);
        (*state)++;
        break;
    case 1:
        if (func_02174CE4(w) == 1)
            (*state)++;
        break;
    case 2:
        if (func_021750D0(w) != 0xff)
            (*state)++;
        break;
    case 3:
        func_0217F074(ctx);
        (*state)++;
        break;
    case 4:
        if (func_0216D3CC((int)h) == 1) {
            func_0217FE44(a2, func_0217F060(obj->f2d), &out);
            func_0216D410(h, (out & 1) ? 0xb : 0xa);
            (*state)++;
        }
        break;
    case 5:
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4(ctx, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217E188(Ctx_0217DC94 *ctx, Obj_0217E188 *obj, u8 *a2, u8 *state)
{
    u8 *w = ctx->w;
    int o1c;
    int o18;
    int o14;
    int o10;
    int f1;
    int f2;
    int r;

    if (func_0217F1EC((u8 *)ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        obj->f6e = 0;
        (*state)++;
    case 1:
        if (func_0200BBA8(func_0200BAC8(func_02012EBC((struct Big *)ctx->sys->f8))) == 1) {
            (*state)++;
        } else {
            w[0x16d] = 0;
            obj->f6e++;
            *state = 4;
        }
        break;
    case 2:
        func_0217F074(ctx);
        func_0217BA48((char *)ctx, (unsigned int *)(&o1c));
        func_0217BA6C((char *)ctx, (unsigned int *)(&o18));
        f1 = o1c != 0;
        f2 = o18 != 0;
        ctx->f3538 = (int)func_0217B9CC((char *)ctx);
        ctx->f3534 = (int)func_021CC720((u32)a2, (u32)func_02012934((void *)ctx->sys->f8), ctx->f3538, f1, f2, 0x15);
        (*state)++;
        break;
    case 3:
        if (func_021CC810((struct Obj_0217E188 *)ctx->f3534) == 1) {
            r = func_021CC7B4((struct Obj_0217E188 *)ctx->f3534, (u32 *)(&o14));
            ctx->f3534 = 0;
            if (r == 2) {
                func_0217B9F4((void *)ctx->f3538);
                ctx->f3538 = 0;
                func_0217B8E4((char *)ctx, 0x2c);
                return 1;
            }
            switch (r) {
            case 0:
                w[0x16d] = 0;
                break;
            case 1:
                w[0x16d] = 1;
                break;
            }
            func_0217B9F4((void *)ctx->f3538);
            ctx->f3538 = 0;
            (*state)++;
        }
        break;
    case 4:
        o10 = 0;
        if (w[0x16d] == 0) {
            func_0217BA48((char *)ctx, (unsigned int *)(&o10));
            f1 = 1;
        } else {
            func_0217BA6C((char *)ctx, (unsigned int *)(&o10));
            f1 = 2;
        }
        if (o10 != 0) {
            func_0217F098((unsigned char *)ctx, a2);
            func_0217F640((struct Self *)ctx, (u32)a2, o10, func_0217B974(obj->f00), f1);
            *state = 5;
        } else {
            func_0217B8E4((char *)ctx, 0x2e);
            return 1;
        }
        break;
    case 5:
        if (func_0217F794((char *)ctx, (u32)a2) == 1) {
            func_0217F210((u8 *)ctx, (u8 *)a2, 0x115);
            (*state)++;
        }
        break;
    case 6:
        if (func_020362DC() & 3) {
            func_0217F7B8((char *)ctx);
            if (obj->f6e == 0) {
                *state = 0;
            } else {
                func_0217B8E4((char *)ctx, 0x2c);
                return 1;
            }
        }
        break;
    }
    return 0;
}






int func_0217E378(u8 *w, void *obj, u8 *a2, u8 *state)
{
    u8 *p;

    p = *(u8 * *)&((struct Obj19428 *)w)->f355C;
    if (func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    if (p[0xcb] == 1) {
        func_0217B8E4((char *)w, 0x2f);
        p[0xcb] = 0;
        p[0xdf] = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        func_0217F210(w, a2, 0x116);
        (*state)++;
        break;
    case 1:
        if (func_02174E20() == 1) {
            p[0xdf] = 1;
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 2))
            *state = 100;
        break;
    case 100:
        if (func_02174E64() == 1)
            (*state)++;
        break;
    case 101:
        if (p[0xdf] == 0) {
            func_0217B8E4((char *)w, 0x2c);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217E440(u8 *w, void *obj, int a2, u8 *state)
{
    u8 *p;
    int idx;
    void *h;

    p = *(u8 * *)&((struct Obj09416 *)w)->f355C;
    idx = func_0203D1A4((struct Link *)((int)func_020399A8()));
    if (func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        switch (p[0x16d]) {
        case 0:
        default:
            func_0201AC2C(func_02012934((*(Sys_0217E440 * *)&((struct Obj09416 *)w)->f0)->f8), (struct Rec534 *)(((int *)(p + 0x148))[idx]));
            break;
        case 1:
            h = func_0217B9CC((char *)w);
            func_0201AC2C(h, (struct Rec534 *)(((int *)(p + 0x148))[idx]));
            func_0217B9F4(h);
            break;
        }
        func_0201A2A8((void *)(((struct Obj09416 *)w)->f352C), (void *)(((int *)(p + 0x148))[idx]));
        (*state)++;
        break;
    case 1:
        func_02175240(p, 1);
        func_0217FE38(p);
        func_02175208(p);
        func_02039C68((struct Link *)func_020399A8(), 0x14, 0x14);
        (*state)++;
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x14, 0x14) == 1)
            (*state)++;
        break;
    case 3:
        if (func_02174D98(((int *)(p + 0x148))[idx]) == 1)
            (*state)++;
        break;
    case 4:
        if (func_02175214(p) == 1)
            (*state)++;
        break;
    case 5:
        func_02039C68((struct Link *)func_020399A8(), 0x10, 0x14);
        (*state)++;
        break;
    case 6:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x10, 0x14) == 1)
            (*state)++;
        break;
    case 7:
        if (func_0203D378() == 1) {
            if (func_02174DF0((u32)(p + 0xcc)) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 8:
        if (func_0217FE24(p) == 1) {
            func_0217B8E4((char *)w, 0x30);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217E5A0(u8 *w, u8 *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int idx;
    int msg;
    Req *q;
    int i;
    int cnt;
    int k;

    p = *(u8 * *)&((struct Obj03570 *)w)->f355C;
    idx = func_0203D1A4((struct Link *)((int)func_020399A8()));
    if (*state < 3 && func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_0217F1EC(w) != 1)
            break;
        switch (obj[0x2d]) {
        default:
            msg = 0x117;
            break;
        case 6:
        case 7:
        case 22:
        case 23:
            msg = 0x118;
            break;
        case 20:
        case 21:
            msg = 0x11b;
            break;
        case 10:
        case 11:
        case 18:
        case 19:
            msg = 0x119;
            break;
        case 14:
        case 15:
            msg = 0x11a;
            break;
        }
        func_0217F210(w, a2, msg);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 1) {
            func_02039C68((struct Link *)func_020399A8(), 0x11, 0x14);
            (*state)++;
        }
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x11, 0x14) == 1) {
            func_0217F074(w);
            (*state)++;
        }
        break;
    case 3:
        q = func_02030734(0x41, 0xc4, 1, (const char *)d_021807E8, 0x10c4);
        q->f0 = ((int *)(p + 0x148))[idx];
        q->f4 = func_0201292C((const struct BigObj *)((*(Sys_0217E5A0 * *)&((struct Obj03570 *)w)->f0)->f8));
        q->fc = (int)func_0200873C(func_02012EBC((struct Big *)((*(Sys_0217E5A0 * *)&((struct Obj03570 *)w)->f0)->f8)));
        q->f34 = 0x1a;
        q->f14 = ((struct Obj03570 *)w)->f352C;
        q->fc0 = func_02030734(0x41, 0x70, 1, (const char *)d_021807E8, 0x10ce);
        cnt = 0;
        for (i = 0; i < func_0203D1B4(); i++) {
            if (i == idx)
                continue;
            if ((p[idx + 0x15c] & 1) == (p[i + 0x15c] & 1))
                k = 0;
            else
                k = ++cnt;
            q->ent[k].f68 = ((int *)(p + 0x148))[i];
            q->ent[k].f6c = (int)func_020084F4(p + 0x18 + i * 0x2c);
            q->ent[k].f70 = func_02008550((const struct Sub0200852CObj *)(p + 0x18 + i * 0x2c));
        }
        switch (obj[0x2d]) {
        case 20:
        case 21:
        case 22:
        case 23:
            q->f64 = 2;
            break;
        default:
            q->f64 = 1;
            break;
        }
        q->f8c = 1;
        q->f90 = 0;
        q->f60 = 0;
        *(Req * *)&((struct Obj03570 *)w)->f3558 = q;
        func_0217422C(w, 0x1a, (int)q);
        (*state)++;
        break;
    case 4:
        if (func_02174268(w) == 1)
            break;
        func_020307B0((*(Req * *)&((struct Obj03570 *)w)->f3558)->fc0);
        func_020307B0(*(Req * *)&((struct Obj03570 *)w)->f3558);
        *(Req * *)&((struct Obj03570 *)w)->f3558 = 0;
        func_0217B8E4((char *)w, 0x2c);
        return 1;
    }
    return 0;
}






int func_0217E838(u8 *w, void *obj, void *a2, u8 *state)
{
    void *h;
    int flag;

    h = func_021A3074(func_02188CB4(a2));
    if (func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        func_0217F210(w, (u8 *)a2, 0x14e);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) != 0) {
            func_0217F22C(w, (u32)a2);
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F268((char *)w, (u32 *)(&flag)) == 1) {
            func_0217F24C(w);
            if (flag == 0) {
                *state = 3;
            } else {
                func_0217B8E4((char *)w, 0x32);
                return 1;
            }
        }
        break;
    case 3:
        if (func_0216D3CC((int)h) == 1) {
            func_0216D410(h, 8);
            (*state)++;
        }
        break;
    case 4:
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4((char *)w, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}





int func_0217E904(u8 *w, u8 *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int m;
    int i;

    p = *(u8 * *)&((struct Obj00033 *)w)->f355C;
    if (*state < 7 && func_0200FB24() != 0 && func_0217F1EC(w) == 1) {
        func_0217BAF0((char *)w, (int)a2, (int)1);
        *state = 7;
    }
    switch (*state) {
    case 0:
        func_0217BAF0((char *)w, (int)a2, (int)1);
        if (p[0xde] == 2) {
            if (func_0217F1EC(w) == 1)
                *state = 6;
        } else {
            func_0217F210(w, a2, 0x14c);
            (*state)++;
        }
        break;
    case 1:
        if (func_02174F34() == 1)
            (*state)++;
        break;
    case 2:
        if (func_0217FEB8(p) == 1)
            (*state)++;
        break;
    case 3:
        if (func_0217F1EC(w) == 1)
            (*state)++;
        break;
    case 4:
        func_02039C68((struct Link *)func_020399A8(), 0x13, 0x14);
        (*state)++;
        break;
    case 5:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x13, 0x14) == 1) {
            func_0203D7BC(0);
            (*state)++;
        }
        break;
    case 6:
        if (func_0203D378() == 1) {
            m = p[0x16e];
            if (func_020392B8() <= 1) {
                (*state)++;
                break;
            }
            for (i = 0; i < 5; i++) {
                if (i != func_02039338() && ((1 << i) & m)) {
                    if ((int)func_0203D1C0((u8)i) == 1)
                        break;
                }
            }
            if (i == 5)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 7:
        if (((Bits_0217DC94 *)(p + 0xc8))->b1 == 1 && func_02172D68(w) == 1)
            return 0;
        if (func_0200FB24() != 0) {
            func_0217F074(w);
            func_02012124((struct Ctx_0217DC94 *)((*(Sys_0217E904 * *)&((struct Obj00033 *)w)->f0)->fc), 1);
            return 0;
        }
        func_02172D38(w);
        (*state)++;
        break;
    case 8:
        if (func_02172D68(w) == 0)
            (*state)++;
        break;
    case 9:
        p[0xc9] = 1;
        func_02173408(w);
        func_0217AE20(w);
        func_02173524(w, obj + 0x14);
        func_0217422C(w, 0x19, 0);
        (*state)++;
        break;
    case 10:
        if (func_02174268(w) == 0) {
            if (*(u8 **)(w + 0x355C) != 0) {
                func_0217505C((int *)(*(u8 **)(w + 0x355C)), (*(Sys_0217E904 * *)&((struct Obj00033 *)w)->f0)->fc);
                *(u8 **)(w + 0x355C) = 0;
            }
            func_02172D50(w);
            (*state)++;
        }
        break;
    case 11:
        if (func_02172D68(w) == 0)
            return 1;
        break;
    }
    return 0;
}





int func_0217EAD8(u8 *w, void *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int t;
    int v;
    int msg;
    void *q;

    p = *(u8 * *)&((struct Obj05956 *)w)->f355C;
    switch (*state) {
    case 0:
        func_0217BAF0((char *)w, (int)a2, 1);
        t = func_0200855C((const struct Sub0200852CObj *)(p + 0x18 + p[0x16c] * 0x2c));
        if (t == 0x14 || t == 0x15) {
            v = (*(u8 **)(p + 0x134 + p[0x16c] * 4))[3];
            if (v < 5) {
                msg = 0x156 + v;
            } else if (v == 5) {
                switch (t) {
                case 0x15:
                    msg = 0x15c;
                    break;
                case 0x14:
                    msg = 0x15b;
                    break;
                default:
                    msg = 0x15d;
                    break;
                }
            } else {
                msg = 0x15d;
            }
        } else {
            msg = 0x15d;
        }
        func_0217F098(w, a2);
        func_0201F02C((struct WordSet *)(((struct Obj05956 *)w)->f2804), 0, p + 0x18 + p[0x16c] * 0x2c);
        func_0217F188((char *)w, msg);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 3)) {
            func_0217F074(w);
            (*(u8 **)(p + 0x134 + p[0x16c] * 4))[4] |= 0x20;
            q = func_0216F7F4((*(Sys_0217EAD8 * *)&((struct Obj05956 *)w)->f0)->f8, *(u8 **)(p + 0x134 + p[0x16c] * 4), 0x41);
            ((struct Obj05956 *)w)->f3558 = q;
            func_0217422C(w, 0x1c, (int)q);
            (*state)++;
        }
        break;
    case 2:
        if (func_02174268(w) == 0) {
            ((struct Obj05956 *)w)->f3558 = 0;
            (*state)++;
        }
        break;
    case 3:
        func_0217B8E4((char *)w, 0x2a);
        return 1;
    }
    return 0;
}




/*
 * Followers EC1C, EC28 and EC34 are already filed separately.
 */
u16 func_0217EC04(void ***ctx)
{
    return d_0218031C[func_02008550(**ctx)];
}





/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C2AC.
 */
u16 func_0217EC1C(int i)
{
    return d_0218034C[i];
}





u16 func_0217EC28(int i)
{
    return d_02180330[i];
}





/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C5A8.
 */
u16 func_0217EC34(int i)
{
    return d_02180348[i];
}




u16 func_0217EC40(int i, int j)
{
    return d_021805E4[i - 2][j];
}





u16 func_0217EC54(int i, int j)
{
    return d_02180648[i - 2][j];
}





u16 func_0217EC68(int i)
{
    return d_0218053C[i - 2];
}





u16 func_0217EC78(int i)
{
    return d_02180570[i - 2];
}





/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C2AC and func_0217C88C.
 */
u16 func_0217EC88(int i)
{
    return d_02180300[i];
}





/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217D7A4 / func_0217D890.
 */
u16 func_0217EC94(int i)
{
    return d_0218032C[i];
}





u16 func_0217ECA0(int i)
{
    return d_02180320[i];
}





u16 func_0217ECAC(int i)
{
    return d_02180318[i];
}




u16 func_0217ECB8(void ***ctx)
{
    return d_02180328[func_02008550(**ctx)];
}




u16 func_0217ECD0(void ***ctx)
{
    return d_02180324[func_02008550(**ctx)];
}




/*
 * Extent follower func_0217ED04 is already filed separately.
 */
u16 func_0217ECE8(int i)
{
    return d_02180380[func_020056EC(4)][i];
}





/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217CEB8.
 */
u16 func_0217ED04(int i)
{
    return d_0218033C[i];
}




u16 func_0217ED10(int i)
{
    return d_02180368[func_020056EC(2)][i];
}




u16 func_0217ED2C(int i)
{
    return d_02180370[func_020056EC(4)][i];
}




u16 func_0217ED48(int i)
{
    return d_02180360[func_020056EC(2)][i];
}





u16 func_0217ED64(int i)
{
    return d_02180390[func_020056EC(4)][i];
}





/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of func_0217ED64.
 */
u16 func_0217ED80(int i)
{
    return d_02180314[i];
}





u16 func_0217ED8C(int i)
{
    return d_02180310[i];
}





u16 func_0217ED98(int i)
{
    return d_02180340[i];
}





u16 func_0217EDA4(int i)
{
    return d_02180304[i];
}





u16 func_0217EDB0(int i)
{
    return d_02180308[i];
}





u16 func_0217EDBC(int i)
{
    return d_02180344[i];
}





u16 func_0217EDC8(int i)
{
    return d_02180350[i];
}





u16 func_0217EDD4(int i)
{
    return d_02180338[i];
}





u16 func_0217EDE0(int i)
{
    return d_0218035C[i];
}





u16 func_0217EDEC(int i)
{
    return d_02180358[i];
}





u16 func_0217EDF8(int i)
{
    return d_02180354[i];
}





u16 func_0217EE04(int i)
{
    return d_021802F8[i];
}





u16 func_0217EE10(int i)
{
    return d_021802F0[i];
}





u16 func_0217EE1C(int i)
{
    return d_021802F4[i];
}






/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of func_0217ED64.
 */
u16 func_0217EE28(int i)
{
    return d_02180334[i];
}






/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217D890.
 */
u16 func_0217EE34(int i)
{
    return d_0218030C[i];
}






u16 func_0217EE40(int i)
{
    return d_021802FC[i];
}






int func_0217EE4C(int **p, int x, int y)
{
    int v = (int)func_02012944((void *)((*p)[2]));
    int a = func_0200856C((const struct Sub0200852CObj *)v);
    int b = func_02008570((const struct Sub0200852CObj *)v);

    if (x == 0)
        return 15;
    if (a != x) {
        if (y == 0)
            return 13;
        return 12;
    }
    if (y == 0 || b == y)
        return 15;
    return 14;
}






void func_0217EE90(Self *self)
{
    void *t;
    void *s;
    u32 x;
    u16 *buf;
    Sub_0217DC94 *sub = &self->sub;
    int kind;
    u8 flag;
    int id;
    Rec *r;

    x = self->sys->f0;
    if (self->msg2808 == 0)
        func_02034714(d_021807F8, 0, d_021807F8);
    if (self->win2804 == 0)
        func_02034714(d_021807F8, 0, d_021807F8);

    r = sub->rec;
    if (r != 0) {
        buf = r->name;
        kind = r->f9;
        flag = r->flag7;
    } else {
        buf = (u16 *)func_020084F4((const void *)x);
        kind = 2;
        flag = (int)func_02008550((const struct Sub0200852CObj *)x);
    }

    s = func_020457B0(0x20, 0x41);
    func_02045924(s, buf);
    func_0201EE0C(self->win2804, 0, s, flag, 1, kind);
    func_02045808(s);
    func_0201F02C(self->win2804, 1, (void *)x);

    switch (kind) {
    case 1: id = 0xe7; break;
    case 2: id = 0xe8; break;
    case 3: id = 0xe9; break;
    case 4: id = 0xea; break;
    case 5: id = 0xeb; break;
    case 7: id = 0xec; break;
    case 8: id = 0xee; break;
    default: id = 0xed; break;
    }
    t = func_02045EC0(self->msg2808, id);
    func_0201EE0C(self->win2804, 2, t, flag, 1, kind);
    func_02045808(t);

    if (sub->rec != 0 && sub->rec->f26 != 0) {
        func_0201F048(self->win2804, 3, sub->rec->f26);
        if (sub->rec->f27 != 0)
            func_0201F094(self->win2804, 4, sub->rec->f26, sub->rec->f27);
    }
    func_0217EFE0(self->sys->f8, kind);
}






void func_0217EFE0(int a, unsigned int n)
{
    int r;
    unsigned short i;
    r = (int)func_02024988((int)func_02012EBC((struct Big *)a));
    i = n - 1;
    if (n >= 1 && n <= 8) {
        if (i < 8) {
            func_020249A0((int *)r, d_0218044C[i]);
            return;
        }
        func_020249A0((int *)r, 7);
        return;
    }
    func_020249A0((int *)r, 7);
}





void func_0217F020(u8 *p)
{
    if (((struct Obj00484 *)p)->f2804 == 0) {
        ((struct Obj00484 *)p)->f2804 = func_0201EC74(5, 0x40, 0x41);
        func_0217EE90((Self *)p);
    }
}





void func_0217F044(u8 *p)
{
    if (((struct Obj09417 *)p)->f2804 != 0) {
        func_0201ED04(((struct Obj09417 *)p)->f2804);
        ((struct Obj09417 *)p)->f2804 = 0;
    }
}





int func_0217F060(int i)
{
    if (i >= 27) return 0;
    return d_021806AC[i][0];
}





void func_0217F074(void *p)
{
    func_0217F7B8(p);
    func_0217F624(p);
    func_0217F24C(p);
    func_0217F2F4(p);
    func_0217F128(p);
}






void func_0217F098(unsigned char *base, u8 *x)
{
    int r6;
    if (((struct Obj00484 *)base)->f280C == 0) {
        if (*(int *)&((struct Obj00484 *)base)->f2808 != 0)
            func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
        r6 = func_02188C54(x);
        *(int *)(base + 0x2808) = func_021904B0(r6, 200);
        *(int *)&((struct Obj00484 *)base)->f2820 = (int)func_020457B0(0x100, 0x41);
        *(int *)&((struct Obj00484 *)base)->f2824 = (int)func_020457B0(0x100, 0x41);
        func_0217F020(base);
        ((struct Obj00484 *)base)->f280C = (int)func_02191558((struct Fx *)r6, *(int *)(base + 0x2808), 0, 1, 0x13, 0x1e, 4);
    } else {
        func_021915EC((struct R *)(((struct Obj00484 *)base)->f280C));
    }
}






void func_0217F128(unsigned char *base)
{
    if (*(int *)&((struct Obj00033 *)base)->f280C != 0) {
        func_0219160C((int *)(*(int *)&((struct Obj00033 *)base)->f280C));
        func_021915B4((void *)(*(int *)&((struct Obj00033 *)base)->f280C));
        *(int *)&((struct Obj00033 *)base)->f280C = 0;
        *(base + 0x2828) = 0;
        func_02045808((struct U16Vec *)(((struct Obj00033 *)base)->f2820));
        func_02045808((struct U16Vec *)(((struct Obj00033 *)base)->f2824));
        ((struct Obj00033 *)base)->f2820 = 0;
        ((struct Obj00033 *)base)->f2824 = 0;
    }
    if (((struct Obj00033 *)base)->f2808 != 0) {
        func_0217F044(base);
        func_021904C8((struct Rec *)(((struct Obj00033 *)base)->f2808));
        ((struct Obj00033 *)base)->f2808 = 0;
    }
}






/*
 * Addresses are Black-image addresses.
 */
void func_0217F188(char *p, u32 arg)
{
    if (*(u32 *)&((struct Obj00484 *)p)->f280C == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00484 *)p)->f2808), arg, (void *)(((struct Obj00484 *)p)->f2820));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00484 *)p)->f2804), (void *)(((struct Obj00484 *)p)->f2824), (void *)(((struct Obj00484 *)p)->f2820));
    func_021916A8((struct R *)(*(u32 *)(p + 0x280c)), 0, 0, ((struct Obj00484 *)p)->f2824);
    ((struct Obj00484 *)p)->f2828 = 1;
}





u32 func_0217F1EC(u8 *p)
{
    if (*(u32 * *)&((struct Obj00033 *)p)->f280C == 0 || ((struct Obj00033 *)p)->f2828 == 0) return 1;
    return func_021916E0(*(u32 * *)&((struct Obj00033 *)p)->f280C);
}





void func_0217F210(u8 *p, u8 *a, u32 b)
{
    func_0217F098(p, a);
    func_0217EE90((Self *)p);
    func_0217F188((char *)p, b);
}





void func_0217F22C(u8 *p, u32 a)
{
    if (*(u32 * *)&((struct Obj00033 *)p)->f2814 == 0) {
        *(u32 * *)&((struct Obj00033 *)p)->f2814 = func_02190BE4((u16 *)func_02188C54((u8 *)a), 0);
    }
}





void func_0217F24C(u8 *p)
{
    if (((struct Obj00033 *)p)->f2814 != 0) {
        func_021909BC((void *)(((struct Obj00033 *)p)->f2814));
        ((struct Obj00033 *)p)->f2814 = 0;
    }
}






int func_0217F268(char *p, u32 *out)
{
    int r;

    if (*(u32 *)&((struct Obj00033 *)p)->f2814 == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    r = func_02190C78((struct Handle *)(*(u32 *)(p + 0x2814)));
    if (r == 2) {
        return 0;
    }
    *out = (r == 0) ? 1 : 0;
    return 1;
}









void func_0217F2A8(char *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 h = func_02188C54((u8 *)a1);

    if (((struct Obj09418 *)p)->f2810 == 0) {
        u32 x = func_02190A28((const struct Pair *)a2, a3, ((struct Obj09418 *)p)->f2808, 0x41);
        ((struct Obj09418 *)p)->f2810 = (u32)func_02190988((u16 *)h, (const u8 *)a4, x, 0, 0, 0, 0, 1);
    }
}








void func_0217F2F4(u8 *p)
{
    if (((struct Obj00033 *)p)->f2810 != 0) {
        func_021909BC((void *)(((struct Obj00033 *)p)->f2810));
        ((struct Obj00033 *)p)->f2810 = 0;
    }
}









int func_0217F310(char *p, u32 a1)
{
    u32 h = func_02188C54((u8 *)a1);

    if (h == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    if (h != 0 && func_0219049C((u8 *)h) == 0) {
        return -1;
    }
    if (((struct Obj12529 *)p)->f2810 == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    return func_021909E4((struct Handle *)(((struct Obj12529 *)p)->f2810));
}








void func_0217F360(char *p, u32 a)
{
    func_0217F2A8(p, a, (u32)d_021804DC, 6, (u32)d_0218042C);
}








void func_0217F378(void *p) { func_0217F2F4(p); }









/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * func_0217C2AC.
 */
int func_0217F380(void *ctx, int a)
{
    return func_0217F310(ctx, a);
}









void func_0217F388(char *p, int a1, int kind, u8 *arg)
{
    Tmpl t;
    u8 v;
    u32 *obj;

    arg[3] = kind;
    t = d_0218046C;
    v = d_021805A4[kind].b;
    t.f0 = v;
    t.f2 = v;
    t.f1A = t.f0 << 1;
    if (kind == 1 || kind == 5)
        t.f18 = 0x1e;
    if (kind >= 5)
        t.f16 = 5;

    if (kind == 1) {
        obj = func_02030734(0x41, 0x30, 1, d_021807FC, 0x647);
        func_02082D44(d_0218050C, obj, 0x30);
        obj[0] = arg[0] + 0xff;
        obj[2] = arg[1] + 0x104;
        obj[4] = arg[2] + 0x106;
        func_0217F2A8(p, a1, (u32)obj, v, (u32)(&t));
        func_020307B0(obj);
    } else if (kind == 5) {
        obj = func_02030734(0x41, 0x28, 1, d_021807FC, 0x657);
        func_02082D44(d_021804B4, obj, 0x28);
        obj[0] = arg[1] + 0x104;
        obj[2] = arg[2] + 0x106;
        func_0217F2A8(p, a1, (u32)obj, v, (u32)(&t));
        func_020307B0(obj);
    } else {
        func_0217F2A8(p, a1, (u32)d_021805A4[kind].p, v, (u32)(&t));
    }
}









/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * func_0217C88C.
 */
void func_0217F4AC(void *ctx)
{
    func_0217F2F4(ctx);
}









#pragma opt_propagation off








/*
 * note: final push 2026-10-05 G4L6. Case -2 reads the entry table by byte offset (off = st[3] * 8,
 *   set after the zero test) with opt_propagation off, so the table address stays one live value
 *   for the pair-pointer load (indexed) and the count byte (+4). Struct-index forms and the
 *   un-pragma'd forms propagate the address into each use (two pool words) or hoist the pool load.
 */
int func_0217F4B4(char *p, int *hit, u8 *st, int *flag, u32 a4)
{
    u32 key;
    u32 i;
    const Pair *pairs;

    *hit = 0;
    *flag = 0;
    key = func_0217F310(p, a4);
    switch (key) {
    case (u32)-1:
        return key;
    case (u32)-2: {
        u32 off;
        const u8 *base;
        if (st[3] == 0)
            return key;
        off = st[3] * 8;
        base = (const u8 *)d_021805A4;
        pairs = *(const Pair * const *)(base + off);
        key = pairs[*(base + off + 4) - 1].f4;
        break;
    }
    case 0x64:
        return d_021803A0[st[0]][st[1]][st[2]];
    case 0x96:
        *flag = 1;
        return d_021803A0[st[0]][st[1]][st[2]];
    }

    if (st[3] == 0) {
        if (key == (u32)d_0218050C) {
            if (st[0] == 4)
                st[0] = 0;
        } else if (key == (u32)d_021804B4) {
            st[0] = 4;
        }
    }

    for (i = 0; (i < 8) ? 1 : 0; i++) {
        if (d_021805A4[i].p == (const Pair *)key) {
            *hit = 1;
            return i;
        }
        switch (st[3]) {
        case 0:
        case 1:
            break;
        case 2:
            if (key < 5) {
                st[0] = key;
                *hit = 1;
                return 1;
            }
            break;
        case 3:
        case 6:
            if (key < 2) {
                st[1] = key;
                *hit = 1;
                if (st[3] == 6)
                    return 5;
                return 1;
            }
            break;
        case 4:
        case 7:
            if (key < 2) {
                st[2] = key;
                *hit = 1;
                if (st[3] == 7)
                    return 5;
                return 1;
            }
            break;
        case 5:
            break;
        }
    }
    func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    return 0;
}








#pragma opt_propagation reset








#pragma opt_propagation reset









void func_0217F5E0(char *p, u32 a1)
{
    if (*(u32 *)&((struct Obj00033 *)p)->f2818 == 0) {
        u32 x = (u32)func_02191558((struct Fx *)func_02188C54((u8 *)a1), *(u32 *)&((struct Obj00033 *)p)->f2808, 0, 1, 1, 0x1e, 2);
        *(u32 *)&((struct Obj00033 *)p)->f2818 = x;
        func_0219161C((struct R *)x, 0, 0, 0x103);
    }
}








void func_0217F624(char *p) { if (((struct Obj00033 *)p)->f2818) { func_021915B4((void *)(((struct Obj00033 *)p)->f2818)); ((struct Obj00033 *)p)->f2818=0; } }









/*
 * pass 4 2026-10-06 P4L11: closed. The palette value is assigned as a full
 * constant in each arm (pal = 0x1040 / 0x440). mwcc splits each constant into
 * movs + lsls #6 and merges the common shift at the join, which gives the same
 * stream as "pal = 0x41 / 0x11; pal <<= 6;" but a different pre-allocation
 * graph: self r5, h and pal r7, flag and tile temps r6 as in the original.
 * EXACT under --lang c99 and --lang c.
 */
void func_0217F640(Self *self, u32 a1, u32 mask, int mode, int msg)
{
    u32 h = func_02188C54((u8 *)a1);
    void *s;
    long i;
    int flag;

    if (self->win2804 == 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (self->f2818 != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (self->f3530 != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);

    flag = 1;
    if (mode != 1)
        flag = 0;
    self->f2818 = func_02191558((struct Fx *)h, (u32)self->msg2808, 0, 1, 1, 0x1a, 0x10);
    self->f3530 = (Tiles *)func_0201A4D4(self->f352C, (u32)self->win2804, 0x41, flag);
    func_0217EE90(self);

    if (msg == 0) {
        s = func_0200AE3C(self->f352C, 0x41);
        func_02191648(self->f2818, 0, 0, (u32)s);
        func_02045808(s);
    } else {
        func_0219161C(self->f2818, 0, 0, msg == 1 ? 0x14f : 0x150);
    }

    for (i = 0; i < 6; i++) {
        int pal;
        if (mask & (1 << i)) {
            pal = 0x1040;
        } else {
            pal = 0x440;
        }
        func_02191674(self->f2818, 0, (i * 2 + 4) * 8, self->f3530->a[i], pal);
        func_02191674(self->f2818, 0x70, (i * 2 + 4) * 8, self->f3530->b[i], pal);
    }
}








u32 func_0217F794(char *p,u32 a) { u32 h=func_021904A8((u32 *)func_02188C54((u8 *)a)); if(((struct Obj00033 *)p)->f3530==0) return 1; return func_0201C6B4((void *)h); }








void func_0217F7B8(char *p) { if(((struct Obj00033 *)p)->f3530) { func_021915B4((void *)(((struct Obj00033 *)p)->f2818)); ((struct Obj00033 *)p)->f2818=0; func_0201A570(((struct Obj00033 *)p)->f3530); ((struct Obj00033 *)p)->f3530=0; } }









int func_0217F7E4(u32 arg)
{
    int v[3];
    u32 r4;
    void *h5;
    u32 i;
    int x, z;

    h5 = func_02188CB4((void *)arg);
    r4 = (u32)func_020120F8((const struct Ctx_0217DC94 *)func_02188C80((void *)arg));
    func_021A3038(h5, (struct VecFx32 *)v);
    v[0] = (v[0] >> 4) / 4096;
    v[2] = (v[2] >> 4) / 4096;
    func_02012AD0((const struct Rec44 *)r4);
    x = v[0];
    z = v[2];
    for (i = 0; i < 1; i++) {
        if (x == d_02180718[i].x && z == d_02180718[i].z) {
            return 1;
        }
    }
    return 0;
}








int func_0217F858(int a) { if(a>=4 && a<=23) return 1; switch(a) { case 3:return 4; case 24:return 2; case 25:return 5; case 26:return 3; default:return 0; } }








int func_0217F894(void *p,char *q) { u32 out; if(func_02009D50(p,q+12,((struct Obj19442 *)q)->f5C, ((struct Bits_0217DC94 *)q)->kind,&out)==1) { return 1; } else { return 0; } }









/*
 * Target of src/pending/func_021881D8.c (called at +0x0C4 with the id).  The
 * only caller image-wide is inside func_021881D8's range, so the two ov019
 * callees and the ov019 data argument are carried by `sole-ref` with the
 * region hint; the allocator is an arm9 `matched` (sub_02030734).  Allocates
 * 0xf4 bytes from heap 0x8e, runs two field-init helpers, returns the block.
 *
 * Addresses are Black-image addresses.
 */
void *func_0217F8C0(u16 id)
{
    void *p = func_02030734(id, 0xf4, 1, (const char *)d_02180808, 0x8e);
    func_0217F97C(p, id);
    func_0217FB70((char *)p + 0x20, id);
    return p;
}








void func_0217F8EC(char *p) { if(p) { func_0217FCE4((struct E *)(p+0x20)); func_0217FBD0(p+0x20); func_0217FABC((u32 *)p); func_0217F9BC(p); func_020307B0(p); } }








void func_0217F914(char *p) { if(p) { func_0217FD04((struct E *)(p+0x20)); func_0217FACC((u32 *)p); } }








void func_0217F928(char *p) { if(p) { func_0217FD38((struct E *)(p+0x20)); func_0217FAF0((u32 *)p); } }









void func_0217F93C(int x, int y)
{
    if (x != 0)
        func_0217F9DC((char *)x, y);
}







void func_0217F948(char *p,u32 a,u32 b) { if(p) func_0217FC08(p+0x20,a,b); }







void func_0217F958(char *p,u32 key) { char *base=p+0x20; int i; for(i=0;i<10;i++) { u32 value=*(u32 *)(base+i*20); if(value==key) { func_0217FCA4((u32 *)(base+i*20)); return; } } }






/*
 * Sub_0217DC94-object constructor reached from func_0217F8C0 (called at +0x10 with the
 * block base).  Same shape as func_0217FB70: handle sub_020490F4(0x59) with
 * the r1 "owner" word a leftover, fill two fields from func_02046E24(h, idx),
 * assert the first through func_02046FF8 / sub_02034714 (d_02180814), then
 * release the handle.  Only the first index is checked here.
 *
 * Addresses are Black-image addresses.
 */
void func_0217F97C(char *p, u32 heap)
{
    void *h = sub_020490F4((u32)((void *)0x59), heap);

    *(u32 *)&((struct Obj09419 *)p)->f14 = (u32)func_02046E24((u32)h, 0x14);
    ((struct Obj09419 *)p)->f18 = (u32)func_02046E24((u32)h, 0x15);
    if (func_02046FF8(*(int * *)&((struct Obj09419 *)p)->f14) == 0) {
        sub_02034714(d_02180814, 0, d_02180814);
    }
    func_02049238(h);
}







void func_0217F9BC(char *p) { func_020470D0(((struct Obj05958 *)p)->f14); func_02046EFC(((struct Obj05958 *)p)->f18); ((struct Obj05958 *)p)->f18=0; func_02046EFC(((struct Obj05958 *)p)->f14); ((struct Obj05958 *)p)->f14=0; }







void func_0217F9DC(char *p, u32 a)
{
    struct E *e;
    if (((struct Obj09420 *)p)->f14 == 0) func_02034714(d_02180814,0,d_02180814);
    e=func_0217FB30((struct E *)p);
    func_0217FA10(p,(u32 *)e,a,((struct Obj09420 *)p)->f1C);
    (((struct Obj09420 *)p)->f1C)++;
}








/*
 * Addresses are Black-image addresses.
 */
void func_0217FA10(char *self, u32 *out, u32 a2, u16 a3)
{
    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    ((struct Obj02366 *)out)->f10 = a3;
    out[1] = (u32)func_02047400((void *)(((struct Obj09421 *)self)->f14), 0, (void *)(((struct Obj09421 *)self)->f14));
    out[2] = (u32)func_02047564((struct G3dOwner *)out[1], (const struct G3dOwner *)(((struct Obj09421 *)self)->f18), 0);
    out[3] = (u32)func_0204767C(out[1], &out[2], 1);
    func_020477A4((struct G3dSys *)out[3], 0);
}







void func_0217FA54(u32 *p) { func_0204762C((struct Rec *)p[2]); func_02047738((struct Rec *)p[3]); func_02047504((struct Rec *)p[1]); func_02082BCC(p,0,0x14); }







void func_0217FA78(u32 *p)
{
    func_02047910((void *)p[3], 0, 0x1000);
    (((struct Obj03097 *)p)->f12)++;
    if (((struct Obj03097 *)p)->f12 > 90) func_0217FA54(p);
}







void func_0217FA9C(u32 *p, u32 *b) { func_0216D88C((const struct Actor *)p[0], (struct VecFx32 *)b); b[1] -= 0x6000; func_02047AC8((void *)p[3], (struct Arg *)b); }






void func_0217FABC(u32 *p) { if (p[3] != 0) func_0217FA54(p); }






void func_0217FACC(u32 *p)
{
    if (p[3] != 0) {
        if (func_0216DA30(p[0]) == 1) func_0217FA78(p);
        else func_0217FA54(p);
    }
}









/*
 * Addresses are Black-image addresses.
 */
void func_0217FAF0(u32 *p)
{
    struct B60 b = d_0218071C;

    MTX_Identity33_(&b.w[6]);
    if (p[3] != 0 && func_0216DA30(p[0]) == 1) {
        func_0217FA9C(p, (u32 *)(&b));
    }
}









struct E *func_0217FB30(struct E *p)
{
    int i, best = 0;

    for (i = 0; i < 1; i++) {
        struct E *e = &p[i];
        if (e->d == 0) {
            return e;
        }
        if (e->h < p[best].h) {
            best = i;
        }
    }
    func_0217FA54((u32 *)(&p[best]));
    return &p[best];
}









/*
 * Sub_0217DC94-object constructor reached from func_0217F8C0 (called at +0x14 with
 * p+0x20).  Grabs a handle from sub_020490F4(0x59) -- the r1 "owner" word is a
 * leftover of the caller, so only r0 is set, the one-argument forwarding shape
 * -- then fills two fields from func_02046E24(h, index) and asserts each with
 * func_02046FF8; a zero result goes to sub_02034714 against d_02180814.
 *
 * Addresses are Black-image addresses.
 */
void func_0217FB70(char *p, u32 heap)
{
    void *h = sub_020490F4((u32)((void *)0x59), heap);

    *(u32 *)&((struct Obj07393 *)p)->fC8 = (u32)func_02046E24((u32)h, 0x16);
    *(u32 *)&((struct Obj07393 *)p)->fCC = (u32)func_02046E24((u32)h, 0x17);
    if (func_02046FF8(*(int * *)&((struct Obj07393 *)p)->fC8) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    if (func_02046FF8(*(int * *)&((struct Obj07393 *)p)->fCC) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    func_02049238(h);
}








void func_0217FBD0(char *p)
{
    func_020470D0(*(u32 * *)&((struct Obj04971 *)p)->fC8);
    func_020470D0(*(u32 * *)&((struct Obj04971 *)p)->fCC);
    func_02046EFC(*(struct Tagged * *)&((struct Obj04971 *)p)->fC8);
    func_02046EFC(*(struct Tagged * *)&((struct Obj04971 *)p)->fCC);
    *(u32 *)&((struct Obj04971 *)p)->fC8=0;
    *(u32 *)&((struct Obj04971 *)p)->fCC=0;
}









void func_0217FC08(char *p, u32 a1, u32 a2)
{
    if (((struct Obj05959 *)p)->fC8 == 0) {
        func_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    if (((struct Obj05959 *)p)->fCC == 0) {
        func_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    func_0217FC64(p, (u32 *)func_0217FD88((u8 *)p), a1, ((struct Obj05959 *)p)->fD0, a2);
    ((struct Obj05959 *)p)->fD0 = ((struct Obj05959 *)p)->fD0 + 1;
}









/*
 * The reload of out[1] before the last call is spelled with a volatile read.
 *
 * Addresses are Black-image addresses.
 */
void func_0217FC64(char *self, u32 *out, u32 a2, u16 a3, int flag)
{
    u32 *q;

    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    ((struct Obj04188 *)out)->f10 = a3;
    if (flag == 0) {
        q = (u32 *)(self + 0xc8);
    } else {
        q = (u32 *)(self + 0xcc);
    }
    out[1] = (u32)func_02047400((void *)(*q), 0, (void *)(*q));
    out[3] = (u32)func_0204767C(*(volatile u32 *)&out[1], 0, 0);
}








void func_0217FCA4(u32 *p) { func_02047738((struct Rec *)p[3]); func_02047504((struct Rec *)p[1]); func_02082BCC(p,0,0x14); }








void func_0217FCC0(struct E *e)
{
}







void func_0217FCC4(u32 *p, u32 *b) { func_0216D88C((const struct Actor *)p[0], (struct VecFx32 *)b); b[1] -= 0x6800; func_02047AC8((void *)p[3], (struct Arg *)b); }







void func_0217FCE4(struct E *p) { int i; for(i=0;i<10;i++) { struct E *e=&p[i]; if(e->d != 0) func_0217FCA4((u32 *)e); } }







void func_0217FD04(struct E *p)
{
    int i;
    for (i=0;i<10;i++) {
        struct E *e=&p[i];
        if (e->d != 0) {
            if (func_0216DA30(e->a) == 1) func_0217FCC0(e);
            else func_0217FCA4((u32 *)e);
        }
    }
}








void func_0217FD38(struct E *p)
{
    struct B60 b = d_02180758;
    int i;

    MTX_Identity33_(&b.w[6]);
    for (i = 0; i < 10; i++) {
        struct E *e = &p[i];
        if (e->d != 0 && func_0216DA30(e->a) == 1) {
            func_0217FCC4((u32 *)e, (u32 *)(&b));
        }
    }
}








u8 *func_0217FD88(u8 *base)
{
    int i;
    int best = 0;
    u8 *e;

    for (i = 0; i < 10; i++) {
        e = base + i * 20;
        if (*(int *)&((struct Obj04188 *)e)->fC == 0)
            return e;
        if (((struct Obj04188 *)e)->f10 < *(u16 *)(base + best * 20 + 16))
            best = i;
    }
    e = base + best * 20;
    func_0217FCA4((u32 *)e);
    return e;
}







int func_0217FDC8(u8 *p)
{
    int n=0; int i;
    for (i=0;i<4;i++) { if (p[0x3e + i*0x2c] == 1) n++; }
    if (n >= func_0203D1B4()) return 1;
    return 0;
}








int func_0217FDF8(u8 *p)
{
    int i;
    int n = 0;

    for (i = 0; i < 4; i++) {
        if (p[0x144 + i] == 1)
            n++;
    }
    if (n >= func_0203D1B4())
        return 1;
    return 0;
}








/*
 * note:     unlabelled leaf (prints as .word in ov019.s); called from
 *           func_0217E440.
 */
int func_0217FE24(u8 *p)
{
    if (p[0x160] == 1)
        return 1;
    return 0;
}








void func_0217FE38(u8 *p)
{
    p[0x160] = 0;
}








int func_0217FE44(int a, int mode, unsigned *out)
{
    unsigned i;
    int x;
    void *y;
    int y2;
    void *h;

    h = func_02188CB4((void *)a);
    *out = 0;
    y = func_021A3074((void *)h);
    x = func_0216D83C(y);
    y2 = func_0216D86C(y);
    if (mode == 2) {
        for (i = 0; i < 2; i++) {
            if (d_02180794[i][0] == x && d_02180794[i][1] == y2) {
                *out = i;
                return 1;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (d_0218079C[i][0] == x && d_0218079C[i][1] == y2) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}







int func_0217FEB8(u8 *p)
{
    int n=0; int i; int value=p[0x16e];
    for (i=0;i<4;i++) { if(p[0x162+i] == 1) n++; }
    if (n >= func_0203D1B4() || n >= (int)func_02080D24(value)) return 1;
    return 0;
}







int func_0217FEF4(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p[i + 0x162] == 1) return 1;
    }
    return 0;
}








int func_0217FF14(void *a)
{
    int v[3];
    s16 (*t)[2];
    int i;
    int n;

    func_021A3038(func_02188CB4(a), (struct VecFx32 *)v);
    v[0] >>= 12;
    v[2] >>= 12;
    if (func_02188C9C(a) == 0x96) {
        t = d_021807AC;
        n = 5;
    } else {
        t = d_021807C0;
        n = 5;
    }
    for (i = 0; i < n; i++) {
        if (v[0] == t[i][0] && v[2] == t[i][1])
            return 1;
    }
    return 0;
}
