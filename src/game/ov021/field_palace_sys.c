/*
 * file:     field_palace_sys.c
 * unit:     yes
 * function: func_021D1164, func_021D1194, func_021D11B0, func_021D11D8, func_021D11F4, func_021D1254, func_021D1264, func_021D13F0, func_021D1400, func_021D1418, func_021D1430, func_021D1488, func_021D14C4, func_021D1670, func_021D16D8, func_021D179C, func_021D182C, func_021D1884, func_021D1894, func_021D18E0, func_021D18F4, func_021D1984, func_021D1988, func_021D1A04, func_021D1A54, func_021D1A74, func_021D1A9C, func_021D1AB0, func_021D1AEC, func_021D1B2C, func_021D1B8C, func_021D1BD8, func_021D1C24, func_021D1C8C, func_021D1F48, func_021D1F50, func_021D1F64, func_021D1F78, func_021D201C, func_021D2040, func_021D20BC, func_021D2124, func_021D213C, func_021D21C0, func_021D21E0, func_021D220C, func_021D2278, func_021D2358, func_021D2418, func_021D2440, func_021D2468, func_021D2524, func_021D25A4, func_021D25E8, func_021D25F4, func_021D26AC, func_021D26D0, func_021D2710, func_021D2750, func_021D297C, func_021D29A8, func_021D29F0, func_021D2ADC, func_021D2B18, func_021D2B54, func_021D2CE8, func_021D2D24, func_021D2D50, func_021D2D7C, func_021D2EDC, func_021D2F44, func_021D2F6C, func_021D3018, func_021D3068, func_021D3090, func_021D30B8, func_021D310C, func_021D3164, func_021D317C, func_021D31A4, func_021D31AC, func_021D3244, func_021D324C, func_021D325C, func_021D3270, func_021D3288, func_021D3294, func_021D32A8, func_021D32C4, func_021D32F8, func_021D331C, func_021D3384, func_021D33A8, func_021D33E0, func_021D33F8, func_021D33FC, func_021D3478
 * address:  0x021D1164
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
 *   d_021DE684     0x021DE684  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_020414AC  0x020414AC  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0204384C  0x0204384C  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049238  0x02049238  arm
 *   d_021DB97C     0x021DB97C  data    ov021  a4
 *   func_020437AC  0x020437AC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   d_021DB984     0x021DB984  data  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02040588  0x02040588  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02045768  0x02045768  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_02040B1C  0x02040B1C  arm
 *   d_021DB990     0x021DB990  data  a2
 *   d_021DB9A0     0x021DB9A0  data
 *   d_021DC158     0x021DC158  data
 *   func_0207C768  0x0207C768  arm
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012F8C  0x02012F8C  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_020092D8  0x020092D8  thumb
 *   func_02009390  0x02009390  thumb
 *   func_020093D8  0x020093D8  thumb
 *   func_02009418  0x02009418  thumb
 *   func_02009428  0x02009428  thumb
 *   func_020093F0  0x020093F0  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   func_021BBA6C  0x021BBA6C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   d_021DD5F0     0x021DD5F0  data    ov021  a4
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *   func_0201147C  0x0201147C  thumb
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02011590  0x02011590  thumb
 *   func_02011558  0x02011558  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   d_021DD5E0     0x021DD5E0  data    ov021  a4
 *   func_02011610  0x02011610  thumb
 *   func_02011638  0x02011638  thumb
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159104  0x02159104  thumb  ov010
 *   func_0215910C  0x0215910C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   d_021DD608     0x021DD608  data  a4
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02006984  0x02006984  thumb
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006CBC  0x02006CBC  thumb
 *   func_02006D44  0x02006D44  thumb
 *   func_02006D64  0x02006D64  thumb
 *   func_02006D94  0x02006D94  thumb
 *   func_02006DD8  0x02006DD8  thumb
 *   func_02006E18  0x02006E18  thumb
 *   func_02007B50  0x02007B50  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_020295A4  0x020295A4  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_02034F84  0x02034F84  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   func_02190F9C  0x02190F9C  thumb  ov021
 *   sub_020056BC   0x020056BC  thumb
 *   sub_02006BD0   0x02006BD0  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0204B100  0x0204B100  arm
 *   func_020185F0  0x020185F0  thumb
 *   func_0202D7C8  0x0202D7C8  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_0202D934  0x0202D934  thumb
 *   func_0202D8D0  0x0202D8D0  thumb
 *   func_0202D9A4  0x0202D9A4  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_0204B294  0x0204B294  arm
 *   d_021DD60C     0x021DD60C  data  a2
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0201F548  0x0201F548  thumb
 *   func_02049B90  0x02049B90  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020249B0  0x020249B0  thumb
 *   d_021DD614     0x021DD614  data  ov021  a4
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   data_021DD6BC  0x021DD6BC  data
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A30A4  0x021A30A4  thumb  ov021
 *   func_021CD440  0x021CD440  thumb  ov021
 *   func_02184FD4  0x02184FD4  thumb  ov020
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_02184F88  0x02184F88  thumb  ov020
 *   func_02008B08  0x02008B08  thumb
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   func_02008B94  0x02008B94  thumb
 *   func_02008B98  0x02008B98  thumb
 *   func_020056EC  0x020056EC  thumb
 *   d_021DD6D0     0x021DD6D0  data  a2
 *   func_0202D81C  0x0202D81C  thumb
 *   func_0202D7D8  0x0202D7D8  thumb
 *   func_0202D898  0x0202D898  thumb
 *   d_021DD710     0x021DD710  data  a2
 *   func_020362DC  0x020362DC  arm
 *   func_02012F08  0x02012F08  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013C60  0x02013C60  thumb
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_021A35FC  0x021A35FC  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A36BC  0x021A36BC  thumb  ov021
 *   func_0201296C  0x0201296C  thumb
 *   func_02162890  0x02162890  thumb  ov010
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02186830  0x02186830  thumb  ov020
 *   func_02186844  0x02186844  thumb  ov020
 *   func_0218684C  0x0218684C  thumb  ov020
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_021A0FA8  0x021A0FA8  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045180  0x02045180  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02041300  0x02041300  arm
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_02008DFC  0x02008DFC  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_02012F2C  0x02012F2C  thumb
 *   d_021DD774     0x021DD774  data  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   d_021DD718     0x021DD718  data  a4
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C234  0x0200C234  thumb
 *   d_021DD738     0x021DD738  data  ov021  a4
 *   func_020124E4  0x020124E4  thumb
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ED04  0x0218ED04  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   d_020A1B38     0x020A1B38  data   a2
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_021F3CFC  0x021F3CFC  thumb  ov059
 *   func_021F37B8  0x021F37B8  thumb  ov064
 *   func_021F3970  0x021F3970  thumb  ov064
 *   func_021F3A44  0x021F3A44  thumb  ov064
 *   func_021F3ADC  0x021F3ADC  thumb
 *   func_021F3AC0  0x021F3AC0  thumb  ov064
 *   d_021DE698     0x021DE698  data  ov021  a4
 *   func_020146F8  0x020146F8  thumb
 *   abs_id_e1      0x000000E1  data
 *   d_021BBDE4    0x021BBDE4  data  ov225  a4
 *   d_021DE6C8     0x021DE6C8  data  ov021  a4
 *   d_021DE6AC     0x021DE6AC  data  ov021  a4
 *   func_0207D534  0x0207D534  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0207D658  0x0207D658  arm
 *   func_0207D67C  0x0207D67C  arm
 *   func_0207D6C0  0x0207D6C0  arm
 *   sub_02030734    0x02030734  arm
 *   func_02012138  0x02012138  thumb
 *   func_02013D74  0x02013D74  thumb
 *   func_021D3554  0x021D3554  thumb  ov021
 *   func_0215850C  0x0215850C  thumb  ov010
 *   func_02158468  0x02158468  thumb  ov010
 *   func_02013B38  0x02013B38  thumb
 *   func_0204A39C  0x0204A39C  arm
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/Obj04299.h"
#include "../../matched/include/Obj01509.h"
#include "../../matched/include/Obj18372.h"
#include "../../matched/include/Obj18373.h"
#include "../../matched/include/Obj09751.h"
#include "../../matched/include/Obj18374.h"
#include "../../matched/include/Obj04301.h"
#include "../../matched/include/Obj01673.h"
#include "../../matched/include/Obj18375.h"
#include "../../matched/include/Obj18377.h"
#include "../../matched/include/Obj18378.h"
#include "../../matched/include/Obj04135.h"
#include "../../matched/include/Obj02103.h"
#include "../../matched/include/G_Ent021DD614.h"
#include "../../matched/include/Obj04899.h"
#include "../../matched/include/Obj09759.h"
#include "../../matched/include/Obj07605.h"

#define NRM(i) ((s16_021D1488 *)d_021DB9A0)[i]
struct Anim021D1488;
struct Node;
struct Bmp;
struct Ctx;
struct Sub0200852CObj;
struct Obj020437AC;
struct Obj00020;
struct CharBuf;
struct Light;
struct VecFx32;
struct Descriptor;
struct Cfg;
struct Sub02009210Obj;
struct Sub02009210Ent;
struct U16Vec;
struct Strbuf;
struct WordSet;
struct Vec3;
struct IcaAnime;
struct Actor;
struct Rec12;
struct Desc;
struct Obj;
struct Big;
struct Sub02007AC8Entry;
struct BigObj;
struct P;
struct Fx;
struct Obj2;
struct Evt;
struct Handle;
struct MsgBank;
struct Rec_021D1988;
struct Bank;
struct Sav;
struct PtS;
struct Vec2;
struct Sub02008828Obj;
struct Sub02008AECObj;
struct ArcFile;
struct Record;
struct Obj18028;
struct Stream;
struct Sub02008C20Obj;
struct RtcTime;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16_021D1164;

typedef signed char    s8;

typedef struct { int x, y, z; } V;

typedef struct Step021D1488 {
    u16 v;
    u16 dur;
} Step021D1488;

typedef struct Anim021D1488 {
    u32 f0[5];
    int cnt;
    u32 idx;
} Anim021D1488;

typedef short s16_021D1488;

typedef int fx32;

typedef long long s64;

typedef struct VecFx32_021D14C4 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32_021D14C4;

/* s16_021D1488 (x, y, z) normal triples */
typedef struct Norm021D14C4 {
    s16_021D1488 x;
    s16_021D1488 y;
    s16_021D1488 z;
} Norm021D14C4;

typedef struct Tile021D14C4 {
    u16 type : 2;
    u16 norm : 14;
    u16 d;
    u32 attr : 31;
    u32 flag : 1;
} Tile021D14C4;

typedef struct Sub021D14C4 {
    u16 type : 2;
    u16 norm0 : 14;
    u16 norm1;
    u16 d0;
    u16 d1;
} Sub021D14C4;

typedef struct Map021D14C4 {
    u16 w;
    u16 h;
    Tile021D14C4 tiles[1];
} Map021D14C4;

typedef struct Plane021D14C4 {
    s16_021D1488 x;
    s16_021D1488 y;
    s16_021D1488 z;
    s16_021D1488 pad;
    u32 attr;
    fx32 height;
} Plane021D14C4;

typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

typedef signed short   s16;

typedef struct {
    void *x00;      /* 0x00 */
    void *x04;      /* 0x04 */
    u8 pad08[0xC];
    void *x14;      /* 0x14 */
    void *x18;      /* 0x18 */
    void *x1C;      /* 0x1C */
    void *x20;      /* 0x20 */
    void *x24;      /* 0x24 */
    void *x28;      /* 0x28 */
    void *x2C;      /* 0x2C */
    u32 pad30;
    void *x34;      /* 0x34 */
    u8 pad38[0x18];
    void *x50;      /* 0x50 */
    int x54;        /* 0x54 */
} Work_021D1988;

typedef signed short   s16_021D1F64;

typedef struct {
    u16 h[4];
} Tbl_021D1988;

typedef signed short   s16_021D201C;

typedef short s16_021D2040;

typedef struct {
    s16_021D2040 x;
    s16_021D2040 y;
} Pt;

typedef signed short   s16_021D2124;

typedef struct Ent021DD614 Ent021DD614;

typedef signed short   s16_021D220C;

struct Milestone {
    u16 count;
    u16 msg;
};

typedef struct { int x, y, z; } Vec_021D1988;

typedef struct {
    u16 h[31];
} Tbl_021D2418;

typedef struct {
    u16 a, b, c, d;
} Pos_021D25F4;

typedef signed short   s16_021D26AC;

typedef short          s16_021D2750;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 a;
    u16 b;
    s16_021D2750 c;
} Sub;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad4[0x14];
    u32 kind;
    Sub sub;
    u16 pad22;
} Rec_021D1988;

typedef struct {
    u8 pad[0xB];
    u8 w;
    u8 h;
    u8 pad2[0xF];
} Info;

typedef struct {
    u16 a;
    u16 f2;
    s16_021D2750 c;
    u16 b;
    u16 f8;
} Loc;

typedef struct {
    s16_021D2750 x;
    s16_021D2750 y;
    s16_021D2750 z;
} Pos_021D2750;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Entry;

typedef struct Blk021D2D50 {
    u32 w[6];
} Blk021D2D50;

typedef struct Vec_021D2D7C {
    int x, y, z;
} Vec_021D2D7C;

typedef struct Work_021D2D7C {
    s16 x;
    s16 y;
    s16 dx;
    s16 dy;
    u16 thresh;
    u16 cnt;
    u16 period;
    u8  total;
    u8  left;
    u32 steps;
    u32 tick;
    Vec_021D2D7C *pos;
} Work_021D2D7C;

typedef struct W {
    void *a;
    void *b;
    void **c;
    u16 *d;
} W;

typedef struct {
    u16 h0;
    u16 h2;
    u8 b4[0x28];
    u8 slot[8];
    u8 b34;
    u8 b35;
    signed char s36;
    signed char s37;
} Rec_021D2D7C;

typedef struct St021D3244 {
    u8 pad0[0x2c];
    u8 v[8];
} St021D3244;

typedef struct { u8 pad[0x35]; u8 f35; u8 pad36; u8 f37; } Obj_021D324C;

typedef struct St021D325C {
    u16 kind;
    u16 pad2;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} St021D325C;

typedef struct {
    u16 f0;
    u16 pad2;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Rec_021D3270;

typedef struct {
    u16 f0;
    u16 pad2;
    int f4;
    int f8;
} Rec_021D3288;

typedef struct { u8 p0[2]; u16 t; u8 p1[0x14]; u32 a, b, c, d; } S;

typedef struct Rec {
    u8 k0;
    u8 k1;
    u8 pad[2];
    u8 data[0x20];
} Rec;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_020414AC(int a);
extern void *func_020056A0(void *, void *, int);
extern void func_02030EAC(struct Node *n);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern void func_02049BDC(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void func_02049238(void *h);
extern void func_020437AC(struct Obj020437AC *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048AD0(struct Light *l);
extern void func_02048B30(u32 l, V *out);
extern void func_02048AE8(u32 l, V *out);
extern void func_0207CA00(const V *a, const V *b, V *c);
extern void func_0207CCA4(const V *a, V *b);
extern void func_0207CAE8(const V *a, const V *b, V *c);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_0206DF3C(V *a, int *x, int *y);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02040588(u32 which, u32 enable);
extern void func_02041B6C(u32 bit);
extern void func_02045374(struct Cfg *cfg);
extern void func_020456F8(struct Descriptor *d);
extern u16 func_02045768(struct Descriptor *p);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u16 func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012F8C(u32 *p);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern u8 func_020092D8(const struct Sub02009210Obj *obj);
extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);
extern u32 func_020093D8(const struct Sub02009210Obj *obj);
extern u32 func_02009418(const struct Sub02009210Obj *obj);
extern void func_02009428(struct Sub02009210Obj *obj, int value);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);
extern u16 func_0215A5CC(void *a0);
extern void *func_02158F74(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02188C7C(unsigned char *p);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
extern u32 func_021BBA6C(const void *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_021BBA1C(int *p);
extern void *func_0201147C(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void *func_0216D568(void *p, u32 v);
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern void func_02011558(struct IcaAnime *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u16 func_0216D5F8(void *p);
extern void func_0216E014(void *a, int *p, int b);
extern char *func_0216D570(char *p, u32 v);
extern void func_0216D758(void *a0);
extern u32 func_02011610(struct IcaAnime *a, struct Rec12 *out);
extern u32 func_02011638(struct IcaAnime *a, struct Rec12 *out);
extern void func_0207C9D0(Vec3 *a, Vec3 *b, Vec3 *c);
extern void func_0216D89C(u32 a, Vec3 *v);
extern int func_0216D60C(int a0, int a1);
extern int func_02158F58(int a0);
extern u16 func_02188C84(u8 *p);
extern void func_02159104(u8 *p, u32 v);
extern u32 func_0215910C(void *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(void *p);
extern void func_0215897C(void *vm, void *task);
extern int func_021A0ED4(u32 a);
extern int func_021A0F30(u32 a, u32 b);
extern u32 func_02188CCC(u8 *p);
extern void func_02159144(int n);
extern void func_02159168(int n);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02188C54(u8 *p);
extern int func_021904B0(u32 a, u32 b);
extern struct Obj2 *func_02190F64(struct Fx *a, u32 b);
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_02007B50(void *);
extern void func_02190E74(u32 *p, u32 b, u32 c, u32 d);
extern u32 func_02190EF0(u32 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern void func_02190F7C(struct P *p);
extern void func_02034F84(u32);
extern void *func_02006CBC(u32);
extern void *sub_020056BC(void *);
extern void *func_02190F9C(void **p);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_02006D64(u32);
extern u32 func_02006D94(void);
extern void func_0202F038(u8 *p);
extern u8 *func_020295A4(u8 *p, u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02006DD8(void *a, u32 b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02190EB8(struct P *p, u32 b, u16 c, u32 d);
extern void func_02006D44(void);
extern void func_02034FB8(u32);
extern void *func_02029620(void *a, u32 b, u32 c);
extern void func_02006E18(void *);
extern void func_02006CAC(void **out);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 sub_02006BD0(u32 i);
extern u32 func_0201ED04(struct WordSet *p);
extern int func_02190E40(u32 a);
extern u32 func_021904C8(struct Rec_021D1988 *a0);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_0216D9A0(void *);
extern u32 *func_0216D9E4(void *c);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_020185F0(u32 a);
extern int func_0202D7C8(int a0);
extern u32 func_02017DBC(struct Sav *p);
extern int func_0202D934(int a0, void *a1, int a2, int a3, unsigned short a9);
extern int func_0202D8D0(int a0, void *a1, int a2, int a3, unsigned short a8, unsigned short a9);
extern u32 func_0202D9A4(u32 h, u32 b1, u32 b2, u32 b3, u16 key);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *e, unsigned short f, unsigned short g);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u8 func_0201F548(int i);
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(void *desc, u32 kind);
extern int func_020249B0(u32 a, u16 b);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern u32 func_02188D38(unsigned char *p);
extern int func_021C7858(u32 a, u32 b, u32 c);
extern void func_021C6DE0(unsigned char *p, u32 *a, u32 b);
extern void func_020061E4(u32 a);
extern int func_02006148(u32 a0);
extern int func_02006224(u32 a0);
extern void *func_021A3074(unsigned char *p);
extern void func_021A30A4(u8 *p, u32 b);
extern int func_021CD440(void *a, u16 *out);
extern void *func_02184FD4(void *p, u16 id);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(void *o);
extern u32 func_02188C64(unsigned char *p);
extern void *func_021C7260(u32 a, u16 b, int c);
extern void *func_021C71D4(u32 a, u32 b, u32 c);
extern u32 func_021A01D4(unsigned char *p);
extern void func_021A01FC(unsigned char *p, u32 a, u32 b, u32 c);
extern void *func_02184F88(void *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern u8 func_02008B94(const struct Sub02008AECObj *obj);
extern u8 func_02008B98(const struct Sub02008AECObj *obj);
extern u32 func_020056EC(u32 a);
extern u32 func_0202D81C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 heap);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern u32 func_0202D898(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 heap);
extern u32 func_020362DC(void);
extern void *func_02012F08(int *p);
extern int func_0216BF9C(void *a, int i, void *b);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02162740(u8 *p);
extern u16 func_02162744(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013C60(u32 id);
extern u32 func_021A3098(u8 *p);
extern void func_0216E2E8(const char *ctx, u32 id, struct Record *out);
extern void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c);
extern u32 func_02188CFC(u8 *p);
extern void func_021A36BC(struct Obj18028 *p, void *a1);
extern u32 func_0201296C(const struct BigObj *p);
extern struct Rec_021D1988 *func_02162890(struct Ctx *c, void *a, int key);
extern int *func_021867C4(int a, int id);
extern void *func_02186830(struct ArcFile **p, int b, unsigned int heap);
extern u8 *func_02186844(u8 *t, int i);
extern u8 *func_0218684C(u8 *t, int i);
extern void func_0218683C(void *p);
extern void func_02186804(void **p);
extern int func_021A0F94(u32 link);
extern void func_021A0FA8(int *p);
extern u16 func_02011330(struct Stream *s);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045180(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u32 offset);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_021904AC(u8 *p);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u32 func_02045C04(struct Rec_021D1988 *rec);
extern void func_02041300(int, int, int, int, int, int, int);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u32 func_0201AA18(void *p);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0203F4CC(struct RtcTime *time);
extern void *func_02012F2C(int *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_0200C0F0(void *p);
extern int func_0200C234(void *p);
extern void *func_020124E4(struct Obj *p);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC54(u8 *p);
extern void func_0218ED04(u8 *p, const struct Vec_021D2D7C *v);
extern void func_0218EC30(void *h, Vec_021D2D7C *v);
extern void func_0218F05C(unsigned char *a);
extern void func_0218EC90(void *h, Vec_021D2D7C *v);
extern void *func_0215A5EC(void *p);
extern void *func_021F3CFC(void *a, int *v, u32 b, u32 c);
extern void *func_021F37B8(int a);
extern void *func_021F3970(void *a, int *v, int *w, int c, int d);
extern void func_021F3A44(void *a, int *v);
extern void *func_021F3ADC(void *a);
extern void *func_021F3AC0(void *a);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0207D63C(int, int, int, int, int);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0207D67C(u32 reg, int a, int b, int c, int d, int e);
extern void func_0207D6C0(u32 addr, int brightness);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02013D74(u32 key);
extern int func_021D3554(void *, int);
extern int func_0215850C(int a0, int a1);
extern int func_02158468(int);
extern u32 func_02013B38(u32 id);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void func_02082D44(void *src, void *dst, u32 n);
void *func_021D1164(u32 heap, u32 v);
int func_021D1194(void *a);
void func_021D11B0(u32 *p);
void func_021D11D8(u32 *p);
void func_021D11F4(u32 *p, u32 b);
u32 func_021D1254(u32 a);
void func_021D1264(u8 *p);
u32 func_021D13F0(u32 a);
int func_021D1400(void *a);
int func_021D1418(void *a);
void func_021D1430(u8 *p, u32 n);
void func_021D1488(void *task, Anim021D1488 *p);
void func_021D14C4(Plane021D14C4 *out, int idx, Map021D14C4 *map, VecFx32_021D14C4 *pos, fx32 size, fx32 base);
int func_021D1670(u32 a, u32 b);
int func_021D16D8(u32 a, u32 b);
int func_021D179C(u32 a, u32 b);
u8 *func_021D182C(u32 a, u16 b, Vec3 *c, u16 d);
void func_021D1884(u8 *p);
void func_021D1894(u8 *p, u32 n);
u32 func_021D18E0(u8 *p, u32 a1, u32 a2, u32 a3);
void func_021D18F4(u32 a, u32 b, u8 *p);
void func_021D1984(void);
void func_021D1988(u32 a, u32 b, Vec3 *c);
int func_021D1A04(u32 a, u32 b);
int func_021D1A54(u32 a, u32 b);
int func_021D1A74(u32 a, u32 b);
int func_021D1A9C(u32 a, u32 b, u32 c, u32 d);
int func_021D1AB0(u32 a, u32 b);
int func_021D1AEC(int a, int *seq, u32 *c);
int func_021D1B2C(u32 a, u32 b);
int func_021D1B8C(u32 a, u32 b);
int func_021D1BD8(u32 *a, int *seq);
u32 func_021D1C24(u32 a, u32 b, u32 c);
int func_021D1C8C(void *proc, int *seq, Work_021D1988 *w);
void func_021D1F48(void *unused, int *done);
int func_021D1F50(u32 a);
int func_021D1F64(u32 a);
void func_021D1F78(u32 *w);
int func_021D201C(void *a);
int func_021D2040(u8 *w);
void func_021D20BC(u32 *w);
int func_021D2124(void *a);
int func_021D213C(u32 a, u32 b);
int func_021D21C0(u32 id);
int func_021D21E0(u32 id);
int func_021D220C(void *msg, u8 *pos);
int func_021D2278(u32 a, int *seq, int *w);
int func_021D2358(u32 a, int *seq, int *w);
void *func_021D2418(void *a, u32 b);
void *func_021D2440(void *a, u32 b, u32 c);
int func_021D2468(u32 a, u32 b);
int func_021D2524(u32 a, u32 b);
void func_021D25A4(u32 *p);
void func_021D25E8(u32 *p);
void func_021D25F4(u32 *p, int a, int b, int c, int s0, int s1);
int func_021D26AC(u32 *a);
u32 func_021D26D0(u32 a, u32 *st, u32 *p);
u32 func_021D2710(u32 a, u32 b);
int func_021D2750(u32 a);
void *func_021D297C(void *a);
u32 func_021D29A8(u32 a, u32 *st, u32 *p);
int func_021D29F0(u32 a, u32 b);
int func_021D2ADC(u32 a, u32 b);
int func_021D2B18(u32 a, u32 b);
int func_021D2B54(u32 a, u32 b);
u32 func_021D2CE8(void *a, int i);
u32 func_021D2D24(void *a, u32 v, int c);
void *func_021D2D50(void *a, Blk021D2D50 *src);
int func_021D2D7C(void *task, int *state);
u32 func_021D2EDC(u32 a, u32 b);
int func_021D2F44(u32 a, u32 b);
u32 func_021D2F6C(u32 a, u32 b);
u32 func_021D3018(u32 a, u32 b);
int func_021D3068(u32 a, u32 b);
int func_021D3090(u32 a, u32 b);
void *func_021D30B8(void *a, u16 *b);
u32 func_021D310C(u32 a, u32 *st, u32 *p);
void func_021D3164(u32 *p);
void *func_021D317C(u32 heap);
void func_021D31A4(u32 a);
void func_021D31AC(Rec_021D2D7C *p);
void func_021D3244(St021D3244 *p, int i, u8 v);
void func_021D324C(Obj_021D324C *p, u8 v);
void func_021D325C(St021D325C *p, u32 a, u32 b, u32 c, u32 d);
void func_021D3270(Rec_021D3270 *p, int a, int b, int c, int d, int e);
void func_021D3288(Rec_021D3288 *p, int a, int b);
void func_021D3294(S *p, u32 a, u32 b, u32 c, u32 d);
void func_021D32A8(int a, int sel);
void func_021D32C4(int *p, int main);
void func_021D32F8(u32 *p, int main);
void func_021D331C(const int *p, int sub);
void func_021D335C(u32 *p, int sub);
void func_021D3384(u32 *p, int main);
void *func_021D33A8(u16 heapId, void *a1, void *a2, u16 a3);
void func_021D33E0(u32 *p);
void *func_021D33F8(u32 *p);
void func_021D33FC(u8 *a0, u16 a1, u16 a2);
void func_021D3478(u8 *a, u32 id, int c, int d, u16 heap);
extern char d_021DE684[];
extern const u32 d_021DB97C[];
extern const V d_021DB984;
extern Step021D1488 d_021DB990[];
extern Norm021D14C4 d_021DB9A0[];
extern const fx32 d_021DC158[];
extern int d_021DD5F0[];
extern u32 d_021DD5E0[];
extern u32 d_021DD608[];
extern Tbl_021D1988 d_021DD60C;
extern struct Ent021DD614 d_021DD614[];
extern const struct Milestone data_021DD6BC[5];
extern Tbl_021D2418 d_021DD6D0;
extern Pos_021D25F4 d_021DD710;
extern const Entry d_021DD774[];
extern u32 d_021DD718[];
extern u32 d_021DD738[];
extern const s16 d_020A1B38[];
extern char d_021DE698[];
extern unsigned char abs_id_e1[];
extern char d_021BBDE4[];
extern char d_021DE6C8[];











void *func_021D1164(u32 heap, u32 v)
{
    u32 *p = func_02030734(heap, 0x1c, 1, d_021DE684, 0x8f);

    p[0] = v;
    func_021D11F4(p, heap);
    func_021D1264((u8 *)p);
    return p;
}











/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1194(void *a)
{
func_021D11D8((u32 *)a);
func_021D13F0((u32)a);
func_021D1254((u32)a);
return func_020307B0(a);
}











void func_021D11B0(u32 *p)
{
    func_020414AC(3);
    p[5] = 0;
    func_021D1400(p);
    p[3] = (u32)func_020056A0(func_021D1488, p, 0x80);
}











void func_021D11D8(u32 *p)
{
    if (p[3] != 0) {
        func_02030EAC((struct Node *)p[3]);
        p[3] = 0;
        func_021D1418(p);
    }
}











/*
 * Addresses are Black-image addresses.
 */
void func_021D11F4(u32 *p, u32 b)
{
    void *h = func_020490F4(200, b);
    u32 idx;

    idx = func_02008550((const struct Sub0200852CObj *)func_02012944(func_020120F4(func_02188C80((void *)p[0]))));
    p[4] = (u32)func_0204384C(200, 0, 0, b);
    func_02049BDC(h, 1, 0, d_021DB97C[idx] << 5, 0x120, 0x20, b);
    func_02049238(h);
}











u32 func_021D1254(u32 a)
{
func_020437AC((struct Obj020437AC *)(((struct Obj04299 *)((u8 *)(a)))->f10));
((struct Obj04299 *)((u8 *)(a)))->f10 = 0;
return 0;
}











void func_021D1264(u8 *p)
{
    V pos;
    V d;
    V f;
    V s;
    V u;
    V at;
    V eye;
    int x;
    int y;
    void *o;
    u32 cam;

    o = func_02188CB4(((struct Obj01509 *)p)->f0);
    cam = func_0218EC2C(func_02188C58((void *)(*(u32 *)&((struct Obj01509 *)p)->f0)));
    func_02048AD0((struct Light *)cam);
    func_02048B30(cam, &eye);
    func_02048AE8(cam, &at);
    func_0207CA00(&eye, &at, &d);
    f = d;
    f.y = 0;
    func_0207CCA4(&f, &f);
    func_0207CAE8(&f, &d_021DB984, &s);
    func_0207CAE8(&d, &s, &u);
    func_0207CCA4(&u, &u);
    func_021A3038(o, (struct VecFx32 *)&pos);
    pos.x += (int)(((long long)u.x * -0x1C000 + 0x800) >> 12);
    pos.y += (int)(((long long)u.y * -0x1C000 + 0x800) >> 12);
    pos.z += (int)(((long long)u.z * -0x1C000 + 0x800) >> 12);
    func_0206DF3C(&pos, &x, &y);
    x -= 0x10;
    y -= 0x18;
    ((struct Obj01509 *)p)->f8 = x % 8;
    ((struct Obj01509 *)p)->fA = y % 8;
    x /= 8;
    y /= 8;
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x > 0x1F) {
        x = 0x1F;
    }
    if (y > 0x18) {
        y = 0x18;
    }
    ((struct Obj01509 *)p)->f4 = func_020450F0(3, (u8)x, (u8)y, 5, (u32)5, (u32)9, (u32)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01509 *)p)->f4)), 0);
    func_02045334((struct Descriptor *)((struct Obj01509 *)p)->f4);
    func_021D1430(p, 0);
}











u32 func_021D13F0(u32 a)
{
func_020452E8((struct Descriptor *)(((struct Obj04299 *)((u8 *)(a)))->f4));
((struct Obj04299 *)((u8 *)(a)))->f4 = 0;
return 0;
}











int func_021D1400(void *a)
{
func_02045374((struct Cfg *)(((struct Obj18372 *)((u8 *)(a)))->f4));
func_02041B6C(3);
return func_02040588(3, 1);
}











int func_021D1418(void *a)
{
func_020456F8((struct Descriptor *)(((struct Obj18373 *)((u8 *)(a)))->f4));
func_02041B6C(3);
return func_02040588(3, 0);
}











void func_021D1430(u8 *p, u32 n)
{
    u32 a = func_02045768((struct Descriptor *)(((struct Obj01509 *)p)->f4));
    u32 b = (u32)func_02045770((struct Descriptor *)((struct Obj01509 *)p)->f4);
    u32 x;
    u32 y;

    func_020439A0((struct Bmp *)(((struct Obj01509 *)p)->f10), (struct Bmp *)b, 0, n << 5, ((struct Obj01509 *)p)->f8, ((struct Obj01509 *)p)->fA, 0x20, 0x20, 0xFFFF);
    x = (u32)func_020437D4((const struct Bmp *)b);
    y = func_020437EC((const struct Bmp *)b);
    func_02040B1C(3, (const void *)x, y, a);
}











/*
 * Blocked: d_021DB990 ({u16 v; u16 dur;} step table, two pool words for
 * +0 and +2) is contested: another overlay in the window starts an object at
 * 0x021DB990 and this function has no overlay_id site.
 */
void func_021D1488(void *task, Anim021D1488 *p)
{
    int c = p->cnt + 1;
    u16 d = d_021DB990[p->idx].dur;

    p->cnt = c;
    if (d <= c) {
        p->idx++;
        if (p->idx >= 4) {
            p->idx = 0;
            p->cnt = 0;
        }
        func_021D1430((u8 *)p, d_021DB990[p->idx].v);
    }
}











static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}











static inline void VecSet021D14C4(Plane021D14C4 *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}











/*
 * The a/0/0/8 grid tile reader (see docs/notes/func_021D14C4_tile_record_reader.c.txt):
 * picks the tile under pos, writes its surface normal, attribute word and
 * solved height into out[idx].
 *
 * Shape notes, each one measured:
 * - the normal table is read through an s16_021D1488 pointer cast of a differently
 *   typed object, so mwcc cannot prove it disjoint from out: the setter's
 *   right-to-left arguments then stay as z, y, x temporaries (y spilled) and
 *   the pool word is reloaded per access. A plain s16_021D1488 array sinks the loads.
 * - the height table is const (its load is scheduled above the z store).
 * - the tile record is read through a volatile pointer: the image reloads
 *   the norm halfword after the type test instead of reusing the type load;
 *   no non-volatile spelling (casts, unions, other access paths, const)
 *   stopped mwcc from CSE-ing the two halfword loads.
 * - the row index is x/0x10000 + w * (z/0x10000) in that operand order;
 *   p (= &out[idx]) is live into the tail, where only the x read uses it.
 */
void func_021D14C4(Plane021D14C4 *out, int idx, Map021D14C4 *map, VecFx32_021D14C4 *pos, fx32 size, fx32 base)
{
    fx32 half = size / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int lx = x % 0x10000;
    int lz = z % 0x10000;
    int i = x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000);
    volatile Tile021D14C4 *t = &map->tiles[i];
    fx32 d;
    Plane021D14C4 *p;
    u8 type = t->type;

    if (type == 0) {
        int n = t->norm * 3;
        int di = t->d;
        VecSet021D14C4(p = &out[idx], NRM(n), NRM(n + 1), -NRM(n + 2));
        d = d_021DC158[di];
    } else if (type == 2) {
        Sub021D14C4 *s = (Sub021D14C4 *)(map->tiles + map->w * map->h) + t->d;
        int n;
        int di;
        if (t->flag == 0) {
            if (lx + lz < 0x10000) {
                n = s->norm0 * 3;
                di = s->d0;
            } else {
                n = s->norm1 * 3;
                di = s->d1;
            }
        } else {
            if (lx > lz) {
                n = s->norm0 * 3;
                di = s->d0;
            } else {
                n = s->norm1 * 3;
                di = s->d1;
            }
        }
        VecSet021D14C4(p = &out[idx], NRM(n), NRM(n + 1), -NRM(n + 2));
        d = d_021DC158[di];
    } else {
        VecSet021D14C4(p = &out[idx], 0, 0x1000, 0);
        d = 0;
    }
    {
        fx32 ny = out[idx].y;
        fx32 mz = FX_MUL(out[idx].z, pos->z);
        fx32 mx = FX_MUL(p->x, pos->x);
        out[idx].attr = t->attr;
        out[idx].height = base + func_0207C768(-(d + (mx + mz)), ny);
    }
}











/*
 * func_02012F8C (arm9 Thumb leaf) is filed as src/matched/arm9/func_02012F8C.c
 * to give the witness.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1670(u32 a, u32 b)
{
    void *r7;
    u32 r6;
    u16 *r4;
    u32 r5;

    func_0215A5F4((void *)b);
    func_0215A5DC((void *)b);
    r7 = func_0215A5E4((void *)b);
    r6 = func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    r4 = func_02159AE8((void *)a, (void *)b);
    r5 = func_02012F8C(r7);
    if (r6 == 0) {
        if (func_020092EC((const struct Sub02009210Obj *)r5) == 1 && func_020092D8((const struct Sub02009210Obj *)r5) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
    }
    return 0;
}











int func_021D16D8(u32 a, u32 b)
{
    void *r6;
    u32 r7;
    u32 k1;
    u16 *r4;
    u8 i;
    u16 *e;
    u32 id;

    func_0215A5F4((void *)b);
    func_0215A5DC((void *)b);
    r6 = func_0215A5E4((void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    k1 = func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    r4 = func_02159AE8((void *)a, (void *)b);
    id = func_02012F8C(r6);
    switch (r7) {
    case 0:
        *r4 = 1;
        for (i = 0; i < 5; i++) {
            e = (u16 *)func_02009390((struct Sub02009210Obj *)id, i);
            if (e == 0) {
                *r4 = 0;
            } else if (e[0] == 0x7E || e[0] == 0) {
                *r4 = 0;
            }
        }
        break;
    case 1:
        if (func_020093D8((const struct Sub02009210Obj *)id) == 0x7F) {
            *r4 = 0;
        } else {
            *r4 = 1;
        }
        break;
    case 2:
        if (func_02009418((const struct Sub02009210Obj *)id) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
        break;
    case 3:
        func_02009428((struct Sub02009210Obj *)id, 0);
        break;
    case 4:
        func_020093F0((struct Sub02009210Obj *)id, k1);
        break;
    }
    return 0;
}











int func_021D179C(u32 a, u32 b)
{
    void *r6 = func_0215A5F4((void *)b);
    void *r7;
    u32 s8;
    u32 s12;
    u32 k0;
    u32 k1;
    u16 *e;
    u32 h;
    u32 id;

    func_0215A5DC((void *)b);
    r7 = func_0215A5E4((void *)b);
    s8 = func_0215A5CC((void *)b);
    s12 = (u32)func_02158F74(r6);
    id = func_02012F8C(r7);
    k0 = func_02159B10((void *)a, (void *)b);
    k1 = func_02159B10((void *)a, (void *)b);
    e = (u16 *)func_02009390((struct Sub02009210Obj *)id, k1);
    if (e != 0 && e[0] != 0x7E && e[0] != 0) {
        h = (u32)func_020457B0(0xE, s8);
        func_02045994((struct Strbuf *)h, e + 1, 0xD);
        func_0201EE0C((struct WordSet *)s12, k0, (const void *)h, 0, 0, 2);
        func_02045808((struct U16Vec *)h);
    }
    return 0;
}











/*
 * The spilled second parameter is a u16 (func_0216DE94 compares its id
 * against func_0216D588's u16): as u32/int its reload from [sp] is hoisted
 * above the struct copy's last store. func_021BBA6C takes the result of
 * func_021BB990 (the bl has no argument setup of its own).
 *
 * Addresses are Black-image addresses.
 */
u8 *func_021D182C(u32 a, u16 b, Vec3 *c, u16 d)
{
    void *t = func_02188C7C((void *)a);
    u32 h = func_02188D24((u8 *)a);
    int *w = func_021BB990(-1, (int *)h, d_021DD5F0);
    u8 *p = (u8 *)func_021BBA6C(w);

    *(int * *)&((struct Obj09751 *)p)->f188 = w;
    ((struct Obj09751 *)p)->f19C = d;
    *(Vec3 *)(p + 0x18C) = *c;
    ((struct Obj09751 *)p)->f0 = (u32)func_0216DE94(t, b);
    return p;
}










/*
 * Tail call on the word at +0x188.
 *
 * Addresses are Black-image addresses.
 */
void func_021D1884(u8 *p)
{
    func_021BBA1C((int *)(((struct Obj18374 *)p)->f188));
}










void func_021D1894(u8 *p, u32 n)
{
    ((struct Obj04301 *)p)->f184 = (u32)func_0201147C(((struct Obj04301 *)p)->f19C, 0xCB, n, 10, (u32)(p + 4), 0x180);
    p[0x19A] = 1;
    p[0x199] = n;
    func_021D1988(((struct Obj04301 *)p)->f184, ((struct Obj04301 *)p)->f0, (struct Vec3 *)(p + 0x18C));
    func_0216D568((void *)(((struct Obj04301 *)p)->f0), 0x8000);
}










u32 func_021D18E0(u8 *p, u32 a1, u32 a2, u32 a3)
{
    if (p[0x19a] == 0) {
        return 1;
    }
    return 0;
}








void func_021D18F4(u32 a, u32 b, u8 *p)
{
    Vec3 v;

    if (p[0x19A] == 0) {
        return;
    }
    if (p[0x19A] == 1) {
        if (func_02011590((struct IcaAnime *)(((struct Obj01673 *)p)->f184), 0x1000) == 0) {
            func_021D1988(((struct Obj01673 *)p)->f184, ((struct Obj01673 *)p)->f0, (struct Vec3 *)(p + 0x18C));
        } else {
            func_02011558((struct IcaAnime *)(((struct Obj01673 *)p)->f184));
            ((struct Obj01673 *)p)->f184 = 0;
            p[0x19A] = 0;
            func_0216D88C((const struct Actor *)((struct Obj01673 *)p)->f0, (struct VecFx32 *)&v);
            func_0216E014((void *)(((struct Obj01673 *)p)->f0), (int *)(&v), func_0216D5F8((void *)(((struct Obj01673 *)p)->f0)));
            if (d_021DD5E0[p[0x199]] != 0) {
                func_0216D570((char *)(((struct Obj01673 *)p)->f0), 0x8000);
            }
        }
        func_0216D758((void *)(((struct Obj01673 *)p)->f0));
    }
}






void func_021D1984(void) {}












void func_021D1988(u32 a, u32 b, Vec3 *c)
{
    Vec3 v1;
    Vec3 v0;

    func_02011610((struct IcaAnime *)a, (struct Rec12 *)&v1);
    func_02011638((struct IcaAnime *)a, (struct Rec12 *)&v0);
    func_0207C9D0(&v1, c, &v1);
    func_0216D89C(b, &v1);
    if (v0.y == 0) {
        func_0216D60C(b, 1);
    } else if (v0.y == 0x5A000) {
        func_0216D60C(b, 3);
    } else if (v0.y == 0xB4000) {
        func_0216D60C(b, 0);
    } else if (v0.y == 0x10E000) {
        func_0216D60C(b, 2);
    }
}












int func_021D1A04(u32 a, u32 b)
{
    Vec3 buf;
    void *s = func_0215A5F4((void *)b);
    u32 *q = (u32 *)func_02158F58((int)s);
    u16 t = func_02188C84((u8 *)q[1]);
    u16 k = func_02159B10((void *)a, (void *)b);
    u8 *r;

    func_021A3038(func_02188CB4((struct Obj00020 *)q[1]), (struct VecFx32 *)&buf);
    r = func_021D182C(q[1], k, &buf, t);
    func_02159104(s, (u32)r);
    return 0;
}












/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021D1A54(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);

    func_021D1884((u8 *)func_0215910C(x));
    func_02159104(x, 0);
    return 0;
}












int func_021D1A74(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    u16 k = func_02159B10((void *)a, (void *)b);

    func_021D1894((u8 *)func_0215910C(x), k);
    return 0;
}












int func_021D1A9C(u32 a, u32 b, u32 c, u32 d)
{
if (func_021D18E0((u8 *)(((struct Obj18375 *)((u8 *)(c)))->f0), b, c, d) == 1) {
    return 1;
}
return 0;
}












int func_021D1AB0(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *task = func_020122C0((void *)func_0215A5DC((void *)b), 0, func_021D1A9C, 4);
    u32 *w = func_020124E8(task);

    *w = func_0215910C(x);
    func_0215897C(x, task);
    return 1;
}












int func_021D1AEC(int a, int *seq, u32 *c)
{
    switch (*seq) {
    case 0:
        if (func_021A0ED4(c[0])) {
            func_021A0F30(c[0], c[1]);
            (*seq)++;
        }
        break;
    case 1:
        if (func_021A0ED4(c[0])) {
            return 1;
        }
        break;
    }
    return 0;
}












int func_021D1B2C(u32 a, u32 b)
{
    u32 r4, r5;
    u32 *e;
    void *r7;
    void *r6;
    u32 *p;

    r7 = func_0215A5F4((void *)b);
    e = (u32 *)func_02158F58((int)r7);
    r5 = func_02159B10((void *)a, (void *)b);
    r4 = func_02188CCC((u8 *)e[1]);
    r6 = func_0215A5DC((void *)b);
    r6 = func_020122C0(r6, 0, func_021D1AEC, 8);
    p = func_020124E8(r6);
    r5 = d_021DD608[r5];
    p[0] = r4;
    p[1] = r5;
    func_0215897C(r7, r6);
    func_02159144(8);
    return 1;
}












int func_021D1B8C(u32 a, u32 b)
{
    u32 r4;
    void *r5;
    void *r6;
    u32 *p;

    r5 = func_0215A5F4((void *)b);
    r4 = func_02188CCC((u8 *)(((u32 *)func_02158F58((int)r5))[1]));
    r6 = func_0215A5DC((void *)b);
    r6 = func_020122C0(r6, 0, func_021D1AEC, 8);
    p = func_020124E8(r6);
    p[0] = r4;
    p[1] = 0;
    func_0215897C(r5, r6);
    func_02159168(8);
    return 1;
}












int func_021D1BD8(u32 *a, int *seq)
{
    u32 r4;

    r4 = func_02188CCC((u8 *)(((u32 *)func_02158F58(a[2]))[1]));
    switch (*seq) {
    case 0:
        if (func_021A0ED4(r4)) {
            func_021A0F30(r4, 0);
            func_02159168(8);
            (*seq)++;
        }
        break;
    case 1:
        if (func_021A0ED4(r4)) {
            return 1;
        }
        break;
    }
    return 0;
}












u32 func_021D1C24(u32 a, u32 b, u32 c)
{
    u32 r;
    u32 *p;

    r = (u32)func_020122C0((void *)a, 0, func_021D1C8C, 0x58);
    p = func_020124E8((struct Obj *)r);
    func_02082BCC(p, 0, 0x58);
    p[1] = a;
    p[2] = (u32)func_020120F4((const struct Ctx *)a);
    p[0] = (u32)func_02007B44(func_02012EBC((struct Big *)p[2]));
    p[3] = b;
    p[4] = (u32)func_02188CB4((void *)b);
    p[5] = (u32)func_0201AB28(func_02012934((void *)p[2]), c);
    p[7] = func_02188C54((u8 *)p[3]);
    *((u8 *)p + 0x4e) = c;
    p[0x15] = 0;
    return r;
}












/*
 * Fifteen-state field sequence: sets up handles, runs fades and a message task, then tears down.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1C8C(void *proc, int *seq, Work_021D1988 *w)
{
    void *a;
    void *t;
    u32 buf;

    switch (*seq) {
    case 0:
        func_021D1F50((u32)w);
        *seq = 1;
        break;
    case 1:
        w->x18 = t = (void *)func_021904B0((u32)w->x1C, 88);
        w->x20 = func_02190F64(w->x1C, (u32)t);
        w->x28 = func_0201EC64(21);
        w->x2C = func_020457B0(0x400, 21);
        func_021D20BC((u32 *)w);
        if (func_02007B50(w->x00) == 1) {
            func_02190E74(w->x20, 0, 0, 0);
            *seq = 2;
        } else {
            func_02190E74(w->x20, 0, 0, 6);
            *seq = 4;
        }
        break;
    case 2:
        if (func_02190EF0(w->x20) == 1) {
            w->x24 = func_02190BE4(w->x1C, 0);
            *seq = 3;
        }
        break;
    case 3:
        switch (func_02190C78(w->x24)) {
        case 0:
            func_021909BC((void *)w->x24);
            func_02190F7C(w->x20);
            func_02190E74(w->x20, 0, 0, 6);
            *seq = 4;
            break;
        case 1:
            func_021909BC((void *)w->x24);
            *seq = 13;
            break;
        }
        break;
    case 4:
        if (func_02190EF0(w->x20) == 1) {
            func_02034F84(8);
            a = sub_020056BC(func_02006CBC(21));
            w->x34 = func_0202EE30(a, func_02190F9C(w->x20), 15, 16, 21);
            *seq = 5;
        }
        break;
    case 5:
        func_02006D64(2);
        if (func_02006D94() == 1) {
            func_0202F038(w->x34);
            func_02190F7C(w->x20);
            func_02190E74(w->x20, 0, 0, 1);
            func_02012374(proc, (struct Evt **)func_020295A4(w->x04, 6));
            *seq = 6;
        }
        break;
    case 6:
        if (func_02190EF0(w->x20) == 1) {
            if (func_02006DD8(func_021D1F48, (u32)(&w->x54)) == 0) {
                *seq = 7;
            } else {
                a = func_02045EC0(w->x18, 3);
                func_0201EEF4(w->x28, 0, w->x14);
                func_0201F250(w->x28, w->x2C, a);
                func_02045808(a);
                func_02190F7C(w->x20);
                func_02190EB8(w->x20, 0, 0, (u32)w->x2C);
                func_02006D44();
                func_02034FB8(8);
                func_02012374(proc, func_02029620(w->x04, 0, 30));
                *seq = 12;
            }
        }
        break;
    case 7:
        if (w->x54 == 1) {
            func_02006E18(w->x00);
            func_02006D44();
            func_02034FB8(8);
            func_02012374(proc, func_02029620(w->x04, 0, 30));
            *seq = 8;
        }
        break;
    case 8:
        if (func_021D2040((u8 *)w) == 0) {
            a = func_02045EC0(w->x18, 2);
            func_0201EEF4(w->x28, 0, w->x14);
            func_0201F250(w->x28, w->x2C, a);
            func_02045808(a);
            func_02190F7C(w->x20);
            func_02190EB8(w->x20, 0, 0, (u32)w->x2C);
            *seq = 9;
        }
        break;
    case 9:
        if (func_02190EF0(w->x20) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        func_02006CAC((void **)(&buf));
        w->x50 = (void *)func_02006984(0x1B9, 0, 64, 0, 0, 0, 0, (u32)(&buf));
        *seq = 11;
        break;
    case 11:
        if (sub_02006BD0((u32)w->x50) == 0) {
            *seq = 13;
        }
        break;
    case 12:
        if (func_02190EF0(w->x20) == 1) {
            *seq = 13;
        }
        break;
    case 13:
        func_021D2124(w);
        func_02045808(w->x2C);
        func_0201ED04(w->x28);
        func_02190E40((u32)w->x20);
        func_021904C8(w->x18);
        *seq = 14;
        break;
    case 14:
        func_021D1F64((u32)w);
        return 1;
    }
    return 0;
}











/*
 * Completion callback: writes 1 through its second argument.  Referenced
 * only by address from func_021D1C8C's literal pool.
 *
 * Addresses are Black-image addresses.
 */
void func_021D1F48(void *unused, int *done)
{
    *done = 1;
}












int func_021D1F50(u32 a)
{
return func_0216D9A0(func_02188C7C(func_0201210C((const struct Ctx *)((struct Obj18377 *)((u8 *)(a)))->f4)));
}











int func_021D1F64(u32 a)
{
return (int)func_0216D9E4(func_02188C7C(func_0201210C((const struct Ctx *)((struct Obj18378 *)((u8 *)(a)))->f4)));
}











void func_021D1F78(u32 *w)
{
    u32 r4, r7, t;
    Tbl_021D1988 buf;

    w[0x38 / 4] = (u32)func_0204B100(1, 0, 0x15);
    r4 = func_020185F0(w[0x14 / 4]);
    r7 = func_0202D7C8(0x15);
    t = func_02017DBC((struct Sav *)r4);
    w[0x40 / 4] = func_0202D934(r7, (void *)r4, 0, 0, 0x15);
    w[0x44 / 4] = func_0202D8D0(r7, (void *)r4, 0, 0, 0x60, 0x15);
    w[0x48 / 4] = func_0202D9A4(r4, 0, 1, 0, 0x15);
    func_02017DE4((struct Sav *)r4, t);
    func_02049238((void *)r7);
    buf = d_021DD60C;
    w[0x3c / 4] = (u32)func_0204B294((void *)w[0x38 / 4], w[0x40 / 4], w[0x44 / 4], w[0x48 / 4], &buf, 0, 0x15);
}











int func_021D201C(void *a)
{
func_0204B3B4((struct Obj *)(((struct Obj04135 *)((u8 *)(a)))->f3C));
func_0204A8D4(((struct Obj04135 *)((u8 *)(a)))->f40);
func_0204ADA4(((struct Obj04135 *)((u8 *)(a)))->f44);
func_0204AFD8(((struct Obj04135 *)((u8 *)(a)))->f48);
return func_0204B1CC((struct Bank *)(((struct Obj04135 *)((u8 *)(a)))->f38));
}











int func_021D2040(u8 *w)
{
    Pt pt;

    if (w[0x4c] == 0) {
        ((struct Obj02103 *)w)->f4D = -4;
    }
    if (((struct Obj02103 *)w)->f4D == -4) {
        ((struct Obj02103 *)w)->f4D = 3;
        w[0x4c] = w[0x4c] + 1;
        if (w[0x4c] == 3) {
            return 0;
        }
    }
    func_0204B454((struct Actor *)((struct Obj02103 *)w)->f3C, (struct PtS *)&pt, 0);
    pt.y = pt.y - ((struct Obj02103 *)w)->f4D;
    func_0204B404((struct Obj *)(((struct Obj02103 *)w)->f3C), (const struct Vec2 *)(&pt), 0);
    ((struct Obj02103 *)w)->f4D = ((struct Obj02103 *)w)->f4D - 1;
    return 1;
}











void func_021D20BC(u32 *w)
{
    func_02049B90(5, func_0201F548(0), 0, 0, 0, 0x20, 0x15);
    w[0x30 / 4] = func_020450F0(1, 10, 3, 12, 12, 0, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w[0x30 / 4])), 0x11);
    func_02045334((struct Descriptor *)w[0x30 / 4]);
    func_02045374((struct Cfg *)w[0x30 / 4]);
    func_0201F73C((void *)w[0x30 / 4], 1, 1, 0);
    func_021D1F78(w);
}











int func_021D2124(void *a)
{
func_021D201C(a);
func_0201F7A8((void *)(((struct Obj04135 *)((u8 *)(a)))->f30), 1);
return func_020452E8((struct Descriptor *)(((struct Obj04135 *)((u8 *)(a)))->f30));
}











/*
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * Addresses are Black-image addresses.
 */
int func_021D213C(u32 a, u32 b)
{
    u32 base, s, r7, r4;
    u16 *p;

    r4 = func_02159B10((void *)a, (void *)b);
    s = func_02159B10((void *)a, (void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    p = func_02159AE8((void *)a, (void *)b);
    switch (r4) {
    case 1:
        base = 0x5C0;
        r4 = base + 0xBB;
        break;
    case 2:
        base = 0x664;
        r4 = base + 0x53;
        break;
    default:
        *p = 0;
        return 0;
    }
    if (func_020249B0(base, s & 0x7FF) && func_020249B0(r4, r7 & 0x7FF)) {
        *p = 1;
    } else {
        *p = 0;
    }
    return 0;
}











int func_021D21C0(u32 id)
{
    u32 i;

    for (i = 0; i < 0x15; i++) {
        if (id == d_021DD614[i].id) {
            return 1;
        }
    }
    return 0;
}











int func_021D21E0(u32 id)
{
    u32 i;

    for (i = 0; i < 0x15; i++) {
        if (id == d_021DD614[i].id && d_021DD614[i].flag == 1) {
            return 1;
        }
    }
    return 0;
}











/*
 * Shows the milestone message for the counter read from the save block when
 * it equals one of the five table entries at 0x021DD6BC, or message 0x28E1
 * once it passes 500; returns 0 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int func_021D220C(void *msg, u8 *pos)
{
    u16 n = func_02008990(func_02008854(func_02012EBC(func_020120F4(msg))));
    u32 i;

    for (i = 0; i < 5; i++) {
        if (n == data_021DD6BC[i].count)
            return (int)func_02158768((int)msg, data_021DD6BC[i].msg, 0, func_02188C84(pos));
    }
    if (n > 500)
        return (int)func_02158768((int)msg, 0x28E1, 0, func_02188C84(pos));
    return 0;
}











int func_021D2278(u32 a, int *seq, int *w)
{
    Vec_021D1988 v;
    u16 id;
    u32 s;
    void *o;

    switch (*seq) {
    case 0:
        s = func_02188D38((unsigned char *)w[1]);
        v.x = 0;
        v.y = -0x40000;
        v.z = 0;
        func_021C6DE0((unsigned char *)s, (u32 *)func_021C7858(w[1], 0x28, (u32)(&v)), 0);
        w[3] = 8;
        (*seq)++;
        break;
    case 1:
        w[3]--;
        if (w[3] > 0) {
            break;
        }
        func_020061E4(0x63C);
        (*seq)++;
        break;
    case 2:
        if (func_02006224(func_02006148(0x63C)) != 0) {
            break;
        }
        o = func_02188CB4((struct Obj00020 *)w[1]);
        func_021A3074((void *)o);
        func_021A30A4(o, 3);
        func_021CD440((void *)w[1], &id);
        func_02012374((struct Evt *)a, (struct Evt **)func_02184FD4((void *)w[0], id));
        (*seq)++;
        break;
    case 3:
        func_0216D410(func_021A3074(func_02188CB4((struct Obj00020 *)w[1])), 8);
        (*seq)++;
        break;
    case 4:
        if (func_0216D454(func_021A3074(func_02188CB4((struct Obj00020 *)w[1])))) {
            return 1;
        }
        break;
    }
    return 0;
}











int func_021D2358(u32 a, int *seq, int *w)
{
    u32 s, r6, r7, r4;

    s = func_02188D38((unsigned char *)w[1]);
    switch (*seq) {
    case 0:
        func_020061E4(0x63C);
        w[3] = 0x18;
        if (w[2]) {
            r6 = func_02188C64((unsigned char *)w[1]);
            r7 = (u32)func_021C7260(w[1], 0x14, 3);
            r4 = (u32)func_021C71D4(w[1], 0xc, 3);
            func_021C6DE0((unsigned char *)s, (u32 *)r7, 0);
            func_021C6DE0((unsigned char *)s, (u32 *)r4, r7);
            func_021A01FC((unsigned char *)r6, 0x7F0F, func_021A01D4((unsigned char *)r6), 0x1A);
        }
        (*seq)++;
        break;
    case 1:
        func_021A30A4(func_02188CB4((struct Obj00020 *)w[1]), 2);
        (*seq)++;
        break;
    case 2:
        w[3]--;
        if (w[3] > 0) {
            break;
        }
        func_02012374((struct Evt *)a, func_02184F88((void *)w[0]));
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}











void *func_021D2418(void *a, u32 b)
{
    void *task = func_020122C0(a, 0, func_021D2278, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = 0;
    return task;
}











void *func_021D2440(void *a, u32 b, u32 c)
{
    void *task = func_020122C0(a, 0, func_021D2358, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = c;
    return task;
}











int func_021D2468(u32 a, u32 b)
{
    u32 x, y, z, v, w, k;
    u16 *p6, *p4, *p5;
    Tbl_021D2418 t;

    x = (u32)func_0215A5E4((void *)b); /* int-typed on purpose: pointer local changes codegen */
    y = func_02159B10((void *)a, (void *)b);
    p6 = func_02159AE8((void *)a, (void *)b);
    p4 = func_02159AE8((void *)a, (void *)b);
    p5 = func_02159AE8((void *)a, (void *)b);
    t = d_021DD6D0;
    z = (u32)func_02008B08(func_02012EBC((struct Big *)x));
    v = func_021690D0(x);
    w = func_021690E0(x);
    k = func_02008B94((const struct Sub02008AECObj *)z);
    if (w == func_02008B98((const struct Sub02008AECObj *)z) && v == k) {
        *p6 = 0x34;
        *p4 = 0x53;
        *p5 = t.h[30];
    } else {
        u32 i = func_020056EC(y ? 0x1E : 0x16);
        *p6 = i + 0x16;
        *p4 = i + 0x35;
        *p5 = t.h[i];
    }
    return 0;
}











int func_021D2524(u32 a, u32 b)
{
    u32 r5, s1, s2, s3;
    void *r4;
    void *r6;
    void *r7;

    r6 = func_0215A5DC((void *)b);
    func_0201210C(r6);
    s1 = func_02159B10((void *)a, (void *)b);
    s2 = func_02159B10((void *)a, (void *)b);
    s3 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159B10((void *)a, (void *)b);
    r7 = func_0215A5F4((void *)b);
    r4 = func_020122C0(r6, 0, func_021D26D0, 0x18);
    r6 = func_020124E8(r4);
    func_021D25A4(r6);
    func_021D25F4(r6, s1, s2, s3, r5, 0);
    func_0215897C(r7, r4);
    return 1;
}











void func_021D25A4(u32 *p)
{
    p[0] = func_020450F0(1, 10, 3, 12, 12, 13, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[0])), 17);
    func_02045334((struct Descriptor *)p[0]);
    func_02045374((struct Cfg *)p[0]);
    func_0201F73C((void *)p[0], 1, 1, 13);
}











/*
 * Tail call with the leading word and a constant one.
 *
 * Addresses are Black-image addresses.
 */
void func_021D25E8(u32 *p)
{
    func_0201F7A8((void *)p[0], 1);
}











/*
 * The pooled 0x8015 is the heap id as a plain literal: it is too wide for a
 * Thumb movs, so the compiler pools it by itself; no symbol is needed. int
 * params were the fix for register allocation.
 *
 * Addresses are Black-image addresses.
 */
void func_021D25F4(u32 *p, int a, int b, int c, int s0, int s1)
{
    Pos_021D25F4 loc;
    u32 t;

    p[1] = (u32)func_0204B100(1, 0, 0x8015);
    t = func_0202D7C8(0x8015);
    p[3] = func_0202D81C(t, a, b, c, s0, 0, 0, s1, 0, 0x8015);
    p[4] = (u32)func_0202D7D8((u32)t, (u32)a, (u32)b, (u32)c, (u32)s0, (u32)0, (u32)0, (u32)0, (u32)0, (u32)0x8015);
    func_02049238((void *)t);
    p[5] = func_0202D898(a, b, c, s0, 0, 0, 1, 0, 0x8015);
    loc = d_021DD710;
    p[2] = (u32)func_0204B294((void *)p[1], p[3], p[4], p[5], &loc, 0, 0x8015);
}











int func_021D26AC(u32 *a)
{
func_0204B3B4((struct Obj *)(((struct Obj04899 *)((u8 *)(a)))->f8));
func_0204A8D4(((struct Obj04899 *)((u8 *)(a)))->fC);
func_0204ADA4(((struct Obj04899 *)((u8 *)(a)))->f10);
func_0204AFD8(((struct Obj04899 *)((u8 *)(a)))->f14);
return func_0204B1CC((struct Bank *)(((struct Obj04899 *)((u8 *)(a)))->f4));
}











u32 func_021D26D0(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        if (func_020362DC() & 3) {
            func_021D26AC(p);
            func_021D25E8(p);
            st[0]++;
        }
        break;
    case 1:
        func_020452E8((struct Descriptor *)p[0]);
        return 1;
    }
    return 0;
}











u32 func_021D2710(u32 a, u32 b)
{
    u32 r7;
    u16 *r5;
    u32 t;
    u32 r6;

    r7 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159AE8((void *)a, (void *)b);
    t = (u32)func_020120F4((const struct Ctx *)func_0215A5DC((void *)b));
    r6 = (u32)func_02012F08((int *)t);
    *r5 = func_0216BF9C((void *)r6, r7, func_02012944((void *)t));
    return 0;
}











/*
 * Spill slots follow declaration order (h, f, list, y, x, id, q, hdl, n from
 * the top down); the tail loops' counter and table pointer are block locals
 * declared j before t, which puts j in r4 and t in r5.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`q
 * = (Sub *)e;` before `q = &e->sub;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * Addresses are Black-image addresses.
 */
int func_021D2750(u32 a)
{
    Info info;
    V3 v;
    Loc loc;
    Pos_021D2750 pos;
    u32 h, f;
    Rec_021D1988 *list;
    void *y;
    void *x;
    void *o;
    u32 id;
    Rec_021D1988 *e;
    Sub *q;
    int hdl;
    int i;
    int n;
    u8 *p;
    u32 r5;
    void *r4;

    h = (u32)func_020120F4((const struct Ctx *)a);
    f = func_02012844((const struct BigObj *)h);
    list = (Rec_021D1988 *)func_02162740((u8 *)f);
    n = func_02162744((u8 *)f);
    y = func_0201210C((void *)a);
    x = func_02188C7C((void *)y);
    o = func_02188CB4((void *)y);
    id = func_02188C9C(y);
    if ((int)func_02013C60((u16)id) == 0) {
        return 0;
    }
    if ((u32)(func_021A3098(o) - 2) <= 1) {
        return 0;
    }
    if ((list == 0 || n == 0) && id != 0 && id != 0x1A8) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        e = &list[i];
        if (e->kind == 0) {
            q = &e->sub;
            func_0216E2E8(x, e->f2, (struct Record *)&info);
            func_021A35FC(o, (u16 *)(&pos.z), (u16 *)(&pos.y), (u16 *)(&pos.x));
            if (e->sub.a <= pos.z && pos.z < e->sub.a + info.w) {
                if (q->b - info.h < pos.x && pos.x <= q->b) {
                    return 0;
                }
            }
        } else if (e->kind == 1) {
            q = &e->sub;
            if (func_02188CFC(y) == 1) {
                func_021A36BC(o, &loc);
                if (q->a == loc.a && q->b == loc.b && q->c == loc.c) {
                    return 0;
                }
            }
        }
    }
    if (func_02188CFC(y) == 0) {
        r4 = func_021A3074((void *)o);
        r5 = func_0201296C((const struct BigObj *)h);
        func_0216D88C(r4, (struct VecFx32 *)&v);
        if (func_02162890((struct Ctx *)f, (void *)r5, (int)(&v))) {
            return 0;
        }
    }
    if (id == 0 || id == 0x1A8) {
        int j;
        u8 *t;
        func_021A35FC(o, (u16 *)(&pos.z), (u16 *)(&pos.y), (u16 *)(&pos.x));
        hdl = (int)func_021867C4(0, 0x8015);
        t = func_02186830((struct ArcFile **)hdl, id != 0, 0x8015);
        for (j = 0; j < 10; j++) {
            p = func_02186844(t, j);
            if (p[0] == pos.z && p[1] == pos.x) {
                func_0218683C(t);
                func_02186804((void **)hdl);
                return 0;
            }
        }
        for (j = 0; j < 10; j++) {
            p = func_0218684C(t, j);
            if (p[0] == pos.z && p[1] == pos.x) {
                func_0218683C(t);
                func_02186804((void **)hdl);
                return 0;
            }
        }
        func_0218683C(t);
        func_02186804((void **)hdl);
    }
    return 1;
}











void *func_021D297C(void *a)
{
    void *task = func_020122C0(a, 0, func_021D29A8, 8);
    u32 *w = func_020124E8(task);

    w[0] = (u32)func_0201210C((void *)a);
    w[1] = func_02188CCC((u8 *)w[0]);
    return task;
}











u32 func_021D29A8(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        func_021A0F30(p[1], 9);
        st[0]++;
        break;
    case 1:
        if (func_021A0F94(p[1]) == 14) {
            func_021A0FA8((int *)p[1]);
            st[0]++;
        }
        break;
    case 2:
        func_021A0F30(p[1], 0);
        return 1;
    }
    return 0;
}











int func_021D29F0(u32 a, u32 b)
{
    void **q;
    u32 heap, msg, win, s;
    void *m;

    q = (void **)func_02158F58((int)func_0215A5F4((void *)b));
    heap = func_02188C84(q[1]);
    m = (void *)func_02188C54(q[1]);
    if (func_02011330((struct Stream *)a)) {
        msg = (u32)func_02045B38(0, 2, 0x16, heap);
        win = func_02045180(2, 1, 1, 0x1E, 10, 14, 0x40);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)win)), 0xF);
        func_02045334((struct Descriptor *)win);
        func_02045374((struct Cfg *)win);
        func_0201F73C((void *)win, 0, 1, 0xD);
        s = (u32)func_020457B0(0xB4, heap);
        func_02045CAC((struct MsgBank *)msg, 3, (void *)s);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)win)), 0, 0, (void *)s, (void *)func_021904AC(m));
        func_02045334((struct Descriptor *)win);
        func_02041B6C(2);
        func_02045808((struct U16Vec *)s);
        func_02045C04((struct Rec_021D1988 *)msg);
        func_020452E8((struct Descriptor *)win);
    } else {
        func_02041300(2, 0, 0, 0, 0x20, 0xC, 0x11);
        func_02041B6C(2);
    }
    return 0;
}











int func_021D2ADC(u32 a, u32 b)
{
    void *x = func_0215A5DC((void *)b);
    u32 k1 = func_02159B10((void *)a, (void *)b);
    u32 k2 = func_02159B10((void *)a, (void *)b);

    func_02008DAC(func_02008C58(func_02012EBC(func_020120F4((void *)x))), k1, k2);
    return 0;
}











int func_021D2B18(u32 a, u32 b)
{
    void *x = func_0215A5DC((void *)b);
    u32 k = func_02159B10((void *)a, (void *)b);
    u16 *q = func_02159AE8((void *)a, (void *)b);

    *q = func_02008DFC(func_02008C58(func_02012EBC(func_020120F4((void *)x))), k);
    return 0;
}











int func_021D2B54(u32 a, u32 b)
{
    void *h;
    u32 name, ws, v;
    void *o;
    u16 *out;
    void *party;
    int i, n;
    void *mon;
    RtcTime t;
    int base;
    int k;
    u32 s0, s1;
    u32 tr;
    u32 e0, e1;

    o = func_0215A5F4((void *)b);
    h = func_020120F4(func_0215A5DC((void *)b));
    name = (u32)func_02012944(h);
    ws = (u32)func_02158F74(o);
    v = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    func_0201F02C((struct WordSet *)ws, 0, (void *)name);
    party = func_02012934(h);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            func_0201EE60((struct WordSet *)ws, 3, func_02017E1C(mon, 5, 0));
            break;
        }
    }
    func_0203F4CC((struct RtcTime *)(&t));
    if (t.minute < 10) {
        base = 0;
        k = func_020056EC(0x1D);
        s0 = 0;
        s1 = 0;
        tr = (u32)func_02012F2C(h);
        e0 = d_021DD774[k].a;
        if (e0 != -1) {
            s0 = func_02008DFC((struct Sub02008C20Obj *)tr, e0);
            func_0201EFA4((struct WordSet *)ws, 1, s0, d_021DD774[k].c, 0, 1);
        }
        e1 = d_021DD774[k].b;
        if (e1 != -1) {
            s1 = func_02008DFC((struct Sub02008C20Obj *)tr, e1);
            func_0201EFA4((struct WordSet *)ws, 2, s1, d_021DD774[k].d, 0, 1);
        }
        if (k < 11) {
            if (e0 != -1 && e1 != -1) {
                if (s0 == 0 || s1 == 0) {
                    k = 0;
                }
            } else if (e1 == -1 && s0 == 0) {
                k = 0;
            }
        }
        if (k < 11) {
            if ((u8)(int)func_02008550((const struct Sub0200852CObj *)name) == 1) {
                k += 11;
            }
        } else {
            k += 11;
        }
    } else if (t.minute < 0x23) {
        base = 0x28;
        k = func_020056EC(0x32);
    } else {
        base = 0x5A;
        k = func_020056EC(0x50);
    }
    *out = func_021D2D24(h, func_021D2CE8(h, base + k), v);
    return 0;
}









/*
 * The 0x0C-random-plus-0x5A path returns through its own temporary (an
 * else arm with a local); a direct `return f() + 0x5a` merges into v. The
 * loop index reuses the second parameter's register: v is copied out and the
 * parameter becomes the index, which gives the image's r1/r2/r3 colouring
 * (a fresh int index rotates them by one).
 */
u32 func_021D2CE8(void *a, int i)
{
    u32 v = i;
    void *h = func_0200C0F0(func_02012EBC(a));

    for (i = 0; i < 8; i++) {
        if (v == d_021DD718[i]) {
            if (func_0200C234(h)) {
                return v;
            } else {
                u32 r = func_020056EC(0xc);
                return r + 0x5a;
            }
        }
    }
    return v;
}









u32 func_021D2D24(void *a, u32 v, int c)
{
    int i;

    if (c == 0) {
        for (i = 0; i < 0xf; i++) {
            if (v == d_021DD738[i]) {
                return func_020056EC(0x14) + 0x6e;
            }
        }
    }
    return v;
}









void *func_021D2D50(void *a, Blk021D2D50 *src)
{
    void *task = func_020122C0(a, 0, func_021D2D7C, 0x1c);

    *(Blk021D2D50 *)func_020124E8(task) = *src;
    return task;
}












/*
 * Task step: case 2 swings the object on a sine of tick/steps. The zero
 * vector is a block-scoped `= {0, 0, 0}` (base pointer then three stores);
 * the offset's products are named locals stored after the position copy.
 *
 * Addresses are Black-image addresses.
 */
int func_021D2D7C(void *task, int *state)
{
    Work_021D2D7C *w;
    void *o;
    void *h;
    int done;
    u16 ang;
    int s;

    done = 0;
    o = func_0201210C(func_020124E4(task));
    w = func_020124E8(task);
    h = func_02188C58(o);

    switch (*state) {
    case 0:
        func_0218F0A8(h);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0) {
            w->pos = (Vec_021D2D7C *)func_0218EC5C(h);
            func_0218EC54(h);
            (*state)++;
        }
        break;
    case 2:
        w->tick++;
        ang = (w->tick << 16) / w->steps;
        if (w->thresh != 0 && w->total - w->left >= w->thresh) {
            w->cnt++;
            if (w->cnt >= w->period) {
                w->cnt = 0;
                w->y -= w->dy;
                w->x -= w->dx;
                if (w->y <= 0) {
                    w->y = 1;
                }
                if (w->x <= 0) {
                    w->x = 1;
                }
            }
        }
        if (w->tick >= w->steps) {
            w->left--;
            w->tick = 0;
        }
        if (w->left == 0) {
            w->tick = 0;
            done = 1;
        }
        if (done) {
            Vec_021D2D7C zero = {0, 0, 0};
            func_0218ED04(h, &zero);
            func_0218EC30(h, w->pos);
            func_0218F05C(h);
            (*state)++;
        } else {
            Vec_021D2D7C pos;
            Vec_021D2D7C ofs;
            int ox, oy;
            s = d_020A1B38[(ang >> 4) * 2];
            ox = w->x * s;
            oy = w->y * s;
            pos = *w->pos;
            pos.x += ox;
            pos.y += oy;
            ofs.x = ox;
            ofs.y = oy;
            ofs.z = 0;
            func_0218EC90(h, &pos);
            func_0218ED04(h, &ofs);
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}












u32 func_021D2EDC(u32 a, u32 b)
{
    int v[3];
    void *r7;
    void *s0;
    u32 r6;
    u32 r5;
    void *r;

    r7 = func_0215A5F4((void *)b);
    s0 = func_0215A5DC((void *)b);
    func_0201210C(s0);
    r6 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159B10((void *)a, (void *)b);
    func_0216D88C((const struct Actor *)func_0216DE94(func_0215A5EC((void *)b), r6), (struct VecFx32 *)v);
    r = func_021F3CFC(s0, v, r6, r5);
    if (r == 0) {
        return 1;
    }
    func_0215897C(r7, r);
    return 1;
}












/*
 * func_021F37B8 resolves in ov064 (2026-10-02, lane gA2). Starts exist at
 * 0x021F37B8 in ov041, ov050, ov060 and ov064. ov050 is void(void) and ov060
 * takes two arguments. ov041 is out on two counts: its body ends in a tail
 * call to func_021BE418, which is void (src/matched/ov/ov021_func_021BE418.c,
 * EXACT), so it returns no value for the `t == 0` test; and it hands its
 * argument straight to func_02188D2C and func_021897A0, the type that
 * func_0201210C returns, while this call passes func_0215A5DC(b), which the
 * sibling func_021D2F6C feeds to func_0201210C. ov064's function applies
 * func_0201210C to its argument and returns func_020122C0(arg, 0, cb, 0), a
 * task, which is what func_0215897C(x, t) receives here and in the same-shape
 * siblings func_021D3068 (ov064-only func_021F3ADC) and func_021D3090
 * (func_021F3AC0, ov064). func_021D2F6C and func_021D3018 also call ov064.
 */
int func_021D2F44(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *t = func_021F37B8((int)func_0215A5DC((void *)b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}












u32 func_021D2F6C(u32 a, u32 b)
{
    int v[3];
    int w[3];
    void *s10;
    void *sc;
    void *s14;
    int s18;
    int s8;
    int s4;
    int r7;
    int r6;
    int r4;
    void *r;

    s10 = func_0215A5F4((void *)b);
    sc = func_0215A5DC((void *)b);
    s14 = func_0201210C(sc);
    s18 = (int)func_02159B10((void *)a, (void *)b);
    s8 = (int)func_02159B10((void *)a, (void *)b);
    s4 = (int)func_02159B10((void *)a, (void *)b);
    r7 = (int)func_02159B10((void *)a, (void *)b);
    r6 = (int)func_02159B10((void *)a, (void *)b);
    r4 = (int)func_02159B10((void *)a, (void *)b);
    r = func_0216DE94(func_02188C7C((void *)s14), s18);
    if (r != 0) {
        func_0216D88C(r, (struct VecFx32 *)v);
    }
    w[0] = (s8 << 16) + 0x8000;
    w[1] = s4 << 15;
    w[2] = (r7 << 16) + 0x8000;
    r = func_021F3970(sc, v, w, r6 << 15, r4);
    if (r == 0) {
        return 1;
    }
    func_0215897C(s10, r);
    return 1;
}












u32 func_021D3018(u32 a, u32 b)
{
    int v[3];
    void *s0;
    int r6;
    int r7;
    int z;

    s0 = func_0215A5DC((void *)b);
    r6 = (int)func_02159B10((void *)a, (void *)b);
    r7 = (int)func_02159B10((void *)a, (void *)b);
    z = (int)func_02159B10((void *)a, (void *)b);
    v[0] = (r6 << 16) + 0x8000;
    v[1] = r7 << 15;
    v[2] = (z << 16) + 0x8000;
    func_021F3A44(s0, v);
    return 0;
}












int func_021D3068(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *t = func_021F3ADC(func_0215A5DC((void *)b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}












/*
 * func_021F3AC0 resolves in ov064: the only Thumb function starting there
 * that takes one argument (ov043's takes two), and the neighbouring ov021
 * functions func_021D2F6C and func_021D3018 already call ov064 code.
 */
int func_021D3090(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *t = func_021F3AC0(func_0215A5DC((void *)b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}












void *func_021D30B8(void *a, u16 *b)
{
    void *r7;
    void *s4;
    void *s8;
    W *w;

    r7 = func_020120F4(a);
    s4 = func_0201210C(a);
    s8 = func_020122C0(a, 0, func_021D310C, 0x10);
    w = func_020124E8(s8);
    w->a = a;
    w->b = s4;
    w->d = b;
    w->c = func_02030734(4, 8, 0, d_021DE698, 0x4a);
    *w->c = r7;
    return s8;
}












/*
 * abs_id_e1 is FS_OVERLAY_ID(ov225) (overlay_id).  d_021BBDE4 is ov225's
 * proc table (Thumb entries 0x021B95A1, 0x021B96BD, 0x021B9661), handed
 * to the proc loader with ov225's id; it resolves as sole-ref/data in
 * ov225 through the loaded-overlay exception to the own-window rule
 * (attest_xwin_loaded(), 2026-10-02).  No overlay listing labels
 * 0x021BBDE4 as a function; ov114 has ARM code there.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021D310C(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        func_02012374((struct Evt *)a, func_020146F8((char *)p[0], p[1], (int)abs_id_e1, (int)d_021BBDE4, p[2]));
        st[0]++;
        break;
    case 1:
        func_021D3164(p);
        func_020307B0((void *)p[2]);
        return 1;
    }
    return 0;
}











void func_021D3164(u32 *p)
{
    if (((u32 *)p[2])[1] == 0) {
        *(u16 *)p[3] = 0;
    } else {
        *(u16 *)p[3] = 1;
    }
}











void *func_021D317C(u32 heap)
{
    u8 *p = func_02030734(heap, 0x38, 1, d_021DE6C8, 0x80);

    func_02082BCC(p + 0x2c, 0xff, 8);
    return p;
}











/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021D31A4(u32 a)
{
    func_020307B0((void *)a);
}









extern void (*d_021DE6AC[])(void *, int);









/*
 * The slot byte is func_02040588's second argument (it takes two, like every
 * other caller): passing p->slot[i] is what puts the ldrb in r1.
 *
 * Addresses are Black-image addresses.
 */
void func_021D31AC(Rec_021D2D7C *p)
{
    int i;

    if (d_021DE6AC[p->h0] != 0) {
        d_021DE6AC[p->h0]((u8 *)p + 4, 1);
        p->h0 = 0;
    }
    if (d_021DE6AC[p->h2] != 0) {
        d_021DE6AC[p->h2]((u8 *)p + 0x18, 0);
        p->h2 = 0;
    }
    for (i = 0; i < 8; i++) {
        if (p->slot[i] != 0xff) {
            func_02040588((u8)i, p->slot[i]);
            p->slot[i] = 0xff;
        }
    }
    if (p->b34 != 0) {
        func_0207D534((volatile u16 *)0x0400006C, p->s36);
        p->b34 = 0;
    }
    if (p->b35 != 0) {
        func_0207D534((volatile u16 *)0x0400106C, p->s37);
        p->b35 = 0;
    }
}








void func_021D3244(St021D3244 *p, int i, u8 v)
{
    p->v[i] = v;
}




void func_021D324C(Obj_021D324C *p, u8 v) { p->f35 = 1; p->f37 = v; }





void func_021D325C(St021D325C *p, u32 a, u32 b, u32 c, u32 d)
{
    p->kind = 2;
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}






void func_021D3270(Rec_021D3270 *p, int a, int b, int c, int d, int e)
{
    p->f0 = 4;
    p->f4 = a;
    p->f8 = b;
    p->fC = c;
    p->f10 = d;
    p->f14 = e;
}






/*
 * Unlabelled 10-byte leaf (movs/strh/str/str/bx lr) between labelled code;
 * called from func_021C622C.
 */
void func_021D3288(Rec_021D3288 *p, int a, int b)
{
    p->f0 = 5;
    p->f4 = a;
    p->f8 = b;
}






/*
 * Unlabelled Thumb leaf (a .word in ov021.s), blocker of ov032 func_021F0208.
 * Storing the u16 tag first is what makes the compiler save r3/r4 and keep
 * the constant in r4; the plain-pointer spelling gave a shorter body.
 */
void func_021D3294(S *p, u32 a, u32 b, u32 c, u32 d)
{
    p->t = 2;
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}


void func_021D32A8(int a, int sel)
{
    if (sel != 0) {
        *(volatile unsigned short *)0x04000050 = 0;
    } else {
        *(volatile unsigned short *)0x04001050 = 0;
    }
}




void func_021D32C4(int *p, int main)
{
    if (main) {
        func_0207D63C(0x04000050, p[0], p[1], p[2], p[3]);
    } else {
        func_0207D63C(0x04001050, p[0], p[1], p[2], p[3]);
    }
}




void func_021D32F8(u32 *p, int main)
{
    if (main) {
        func_0207D658(0x04000050, p[0], p[1]);
    } else {
        func_0207D658(0x04001050, p[0], p[1]);
    }
}




/*
 * Addresses are Black-image addresses.
 * func_021D335C is an unlabelled leaf after the first function's pool.
 */
void func_021D331C(const int *p, int sub)
{
    if (sub) {
        func_0207D67C(0x04000050, p[0], p[1], p[2], p[3], p[4]);
    } else {
        func_0207D67C(0x04001050, p[0], p[1], p[2], p[3], p[4]);
    }
}




void func_021D335C(u32 *p, int sub)
{
    if (sub) {
        *(volatile u16 *)0x04000052 = p[0] | (p[1] << 8);
    } else {
        *(volatile u16 *)0x04001052 = p[0] | (p[1] << 8);
    }
}




void func_021D3384(u32 *p, int main)
{
    if (main) {
        func_0207D6C0(0x04000050, p[0]);
    } else {
        func_0207D6C0(0x04001050, p[0]);
    }
}




/*
 * Recursive MATCH unblocker: target named by the parked ov021 func_021881D8
 * (+0110 region) and part of the field_palace_sys.c tree
 * (layout/file_anchors.txt row 021D33DC -> 0x021DE6D4).  Allocates a 0xc-byte
 * record through the debug allocator, fills two words and a zero, and hands
 * it to func_021D33FC.
 *
 * Addresses are Black-image addresses.
 */
void *func_021D33A8(u16 heapId, void *a1, void *a2, u16 a3)
{
    void *p = sub_02030734(heapId, 0xc, 1, (const char *)0x021DE6D4, 0x43);

    ((struct Obj09759 *)p)->f0 = (u32)a1;
    ((struct Obj09759 *)p)->f4 = (u32)a2;
    ((struct Obj09759 *)p)->f8 = 0;
    func_021D33FC(p, a3, heapId);
    return p;
}




void func_021D33E0(u32 *p)
{
    if (p[2] != 0) {
        func_020307B0((void *)p[2]);
    }
    func_020307B0(p);
}




/*
 * Getter: returns the word at +0x08.  Unlabelled in the listing; called
 * from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void *func_021D33F8(u32 *p)
{
    return (void *)p[2];
}




/*
 * 2026-10-02: EXACT.  The prologue and final call-setup residue of the
 * earlier draft was parameter width: a1 and a2 are u16 (a1 is the u16 key
 * func_021D3554 compares, a2 the u16 heap id of func_021D3478), which pins
 * their home stores to the front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 *
 * Recursive MATCH unblocker attempt: non-SDK dep of the matched func_021D33A8
 * (its +0010 branch target in the field_palace_sys.c tree).  Every relocation
 * resolves (0x0215850C / 0x02158468 as EXACT ov010 `matched`, 0x021D3478 as
 * `sole-ref`), the size is exact, and the logic is recovered.  The residue
 * that remained was scheduling, closed by the u16 parameters above.
 *
 * Addresses are Black-image addresses.
 */
void func_021D33FC(u8 *a0, u16 a1, u16 a2)
{
    int r6;
    int r7;
    void *r4;
    int t;
    int s;

    r6 = (int)func_02012138(((struct Obj07605 *)a0)->f0);
    if (func_02013D74(a1) != 1)
        return;
    if (r6 == 0)
        return;
    r4 = func_020120F4(((struct Obj07605 *)a0)->f0);
    r7 = func_021D3554(r4, a1);
    t = func_0215850C(r6, (int)r4);
    s = 0xffff;
    if (t == 2) {
        if (r7 == 1)
            s = 1;
        else
            s = 0;
    } else if (t == 1) {
        if (r7 == 1)
            s = 3;
        else
            s = 2;
    }
    if (s == 0xffff)
        return;
    func_021D3478(a0, s, a1, func_02158468(r6), a2);
}




/*
 * field_palace_sys.c (layout/file_anchors.txt row 021D3550 -> 0x021DE6D4).
 *
 * Addresses are Black-image addresses.
 */
void func_021D3478(u8 *a, u32 id, int c, int d, u16 heap)
{
    u32 size;
    int found;
    void *h;
    u32 i;
    Rec *p;
    u32 hv;
    u16 v;

    found = 0;
    hv = (heap & 0x7fff) | 0x8000;
    h = func_020490F4(0xe0, hv & 0xffff);
    v = ((int)func_02013B38((int)c) - 2) / 4 + 1;
    p = func_0204A39C(h, (u32)id, (u32)0, (u16)hv, &size);
    for (i = 1; i < size / 0x24; i++) {
        if ((v == p[i].k0 || p[i].k0 == 0xff) && (d == p[i].k1 || p[i].k1 == 0xff)) {
            found = 1;
            break;
        }
    }
    if (!found) {
        i = 0;
    }
    ((struct Obj07605 *)a)->f8 = func_02030734(heap, 0x20, 0, (const char *)0x021DE6D4, 0xd4);
    func_02082D44(p[i].data, ((struct Obj07605 *)a)->f8, 0x20);
    func_020307B0(p);
    func_02049238(h);
}
