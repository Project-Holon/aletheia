/*
 * file:     unit_021D14C4.c
 * unit:     yes
 * function: func_021D14C4, func_021D1670, func_021D16D8, func_021D179C, func_021D182C, func_021D1884, func_021D1894, func_021D18E0, func_021D18F4, func_021D1984, func_021D1988, func_021D1A04, func_021D1A54, func_021D1A74, func_021D1A9C, func_021D1AB0, func_021D1AEC, func_021D1B2C, func_021D1B8C, func_021D1BD8, func_021D1C24, func_021D1C8C, func_021D1F48, func_021D1F50, func_021D1F64, func_021D1F78, func_021D201C, func_021D2040, func_021D20BC, func_021D2124, func_021D213C, func_021D21C0, func_021D21E0, func_021D220C, func_021D2278, func_021D2358, func_021D2418, func_021D2440, func_021D2468, func_021D2524, func_021D25A4, func_021D25E8, func_021D25F4, func_021D26AC, func_021D26D0, func_021D2710, func_021D2750, func_021D297C, func_021D29A8, func_021D29F0, func_021D2ADC, func_021D2B18, func_021D2B54, func_021D2CE8, func_021D2D24, func_021D2D50, func_021D2D7C, func_021D2EDC, func_021D2F44, func_021D2F6C, func_021D3018, func_021D3068, func_021D3090
 * address:  0x021D14C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_palace_sys.c at 0x021D14C4 (no __FILE__ anchor between field_saveanime.c and event_game_manual.c; script command handlers).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02049238  0x02049238  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
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
 *   d_020A1B38     0x020A1B38  data   a2
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_021F3CFC  0x021F3CFC  thumb  ov059
 *   func_021F37B8  0x021F37B8  thumb  ov064
 *   func_021F3970  0x021F3970  thumb  ov064
 *   func_021F3A44  0x021F3A44  thumb  ov064
 *   func_021F3ADC  0x021F3ADC  thumb
 *   func_021F3AC0  0x021F3AC0  thumb  ov064
 */
#include "../../matched/include/G_Ent021DD614.h"
#define NRM(i) ((NormComp *)d_021DB9A0)[i]
struct Ctx;
struct ScrcmdWork;
struct Sub0200852CObj;
struct Obj00020;
struct CharBuf;
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
#include "../arm9/script_vm_types.h"
#include "unit_021D14C4_types.h"
typedef short NormComp;
typedef int fx32;
typedef long long s64;
typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;
/* NormComp (x, y, z) normal triples */
typedef struct NormTriple {
    NormComp x;
    NormComp y;
    NormComp z;
} NormTriple;
typedef struct MapTile {
    u16 type : 2;
    u16 norm : 14;
    u16 d;
    u32 attr : 31;
    u32 flag : 1;
} MapTile;
typedef struct MapTileSplit {
    u16 type : 2;
    u16 norm0 : 14;
    u16 norm1;
    u16 d0;
    u16 d1;
} MapTileSplit;
typedef struct TileMap {
    u16 w;
    u16 h;
    MapTile tiles[1];
} TileMap;
typedef struct TilePlane {
    NormComp x;
    NormComp y;
    NormComp z;
    NormComp pad;
    u32 attr;
    fx32 height;
} TilePlane;
typedef int            s32;
typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct {
    u16 v[4];
} ClactInitParam;
typedef struct {
    s16 x;
    s16 y;
} SpritePos;
typedef struct Ent021DD614 Ent021DD614;
struct Milestone {
    u16 count;
    u16 msg;
};
typedef struct {
    u16 textId[31];
} TextIdTable;
typedef struct {
    u16 gridX;
    u16 gridZ;
    s16 height;
} TileCoord;
typedef struct MapEventRec {
    u16 eventId;
    u16 modelId;
    u8 pad04[0x14];
    u32 kind;
    TileCoord tile;
    u16 pad22;
} MapEventRec;
typedef struct {
    u8 pad00[0xB];
    u8 w;
    u8 h;
    u8 pad0D[0xF];
} MmdlModelInfo;
typedef struct {
    u16 gridX;
    u16 gridXFrac;
    s16 height;
    u16 gridZ;
    u16 gridZFrac;
} FacingTile;
typedef struct {
    s16 gridZ;
    s16 height;
    s16 gridX;
} GridPos;
typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;
typedef struct {
    u32 idA;
    u32 idB;
    u32 digitsA;
    u32 digitsB;
} CounterMsgEntry;
typedef struct CameraShakeWork {
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
    Vec3 *pos;
} CameraShakeWork;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049238(void *h);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C58(void *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void func_02045374(struct Cfg *cfg);
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
extern u32 func_021904C8(void *msgData);
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
extern MapEventRec *func_02162890(struct Ctx *c, void *a, int key);
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
extern u32 func_02045C04(void *msgBank);
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
extern void func_0218ED04(u8 *p, const struct Vec3 *v);
extern void func_0218EC30(void *h, Vec3 *v);
extern void func_0218F05C(unsigned char *a);
extern void func_0218EC90(void *h, Vec3 *v);
extern void *func_0215A5EC(void *p);
extern void *func_021F3CFC(void *a, int *v, u32 b, u32 c);
extern void *func_021F37B8(int a);
extern void *func_021F3970(void *a, int *v, int *w, int c, int d);
extern void func_021F3A44(void *a, int *v);
extern void *func_021F3ADC(void *a);
extern void *func_021F3AC0(void *a);
void func_021D14C4(TilePlane *out, int idx, TileMap *map, VecFx32 *pos, fx32 size, fx32 base);
int func_021D1670(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D16D8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D179C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
MmdlIcaWork *func_021D182C(u32 fieldWork, u16 mmdlId, Vec3 *offset, u16 heapId);
void func_021D1884(MmdlIcaWork *p);
void func_021D1894(MmdlIcaWork *p, u32 n);
u32 func_021D18E0(MmdlIcaWork *p, u32 a1, u32 a2, u32 a3);
void func_021D18F4(u32 event, u32 state, MmdlIcaWork *work);
void func_021D1984(void);
void func_021D1988(struct IcaAnime *icaAnime, void *mmdl, Vec3 *offset);
int func_021D1A04(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D1A54(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D1A74(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D1A9C(u32 event, u32 state, u32 work, u32 arg);
int func_021D1AB0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D1AEC(int event, int *seq, SubscreenModeWork *work);
int func_021D1B2C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D1B8C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D1BD8(u32 *event, int *seq);
u32 func_021D1C24(void *gameSystem, void *fieldMap, u32 partySlot);
int func_021D1C8C(void *event, int *seq, PerapRecordWork *w);
void func_021D1F48(void *unused, int *done);
int func_021D1F50(PerapRecordWork *work);
int func_021D1F64(PerapRecordWork *work);
void func_021D1F78(PerapRecordWork *w);
int func_021D201C(PerapRecordWork *work);
int func_021D2040(PerapRecordWork *w);
void func_021D20BC(PerapRecordWork *w);
int func_021D2124(PerapRecordWork *work);
int func_021D213C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D21C0(u32 id);
int func_021D21E0(u32 id);
int func_021D220C(void *msg, u8 *pos);
int func_021D2278(u32 event, int *seq, RippleWarpWork *w);
int func_021D2358(u32 event, int *seq, RippleWarpWork *w);
void *func_021D2418(void *field, u32 fieldWork);
void *func_021D2440(void *field, u32 fieldWork, u32 useSpin);
int func_021D2468(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D2524(ScriptVm *vm, struct ScrcmdWork *cmdWork);
void func_021D25A4(PokeIconWork *p);
void func_021D25E8(PokeIconWork *p);
void func_021D25F4(PokeIconWork *p, int species, int form, int isEgg, int gender, int charFlags);
int func_021D26AC(PokeIconWork *work);
u32 func_021D26D0(u32 event, u32 *state, PokeIconWork *p);
u32 func_021D2710(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D2750(u32 gameSystem);
void *func_021D297C(void *field);
u32 func_021D29A8(u32 event, u32 *state, SubscreenAnimWork *work);
int func_021D29F0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D2ADC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D2B18(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D2B54(ScriptVm *vm, struct ScrcmdWork *cmdWork);
u32 func_021D2CE8(void *gameData, int i);
u32 func_021D2D24(void *gameData, u32 msgIndex, int fixedMsg);
void *func_021D2D50(void *a, CameraShakeParams *src);
int func_021D2D7C(void *task, int *state);
u32 func_021D2EDC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D2F44(ScriptVm *vm, struct ScrcmdWork *cmdWork);
u32 func_021D2F6C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
u32 func_021D3018(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D3068(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D3090(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern NormTriple d_021DB9A0[];
extern const fx32 d_021DC158[];
extern int d_021DD5F0[];
extern u32 d_021DD5E0[];
extern u32 d_021DD608[];
extern ClactInitParam d_021DD60C;
extern struct Ent021DD614 d_021DD614[];
extern const struct Milestone data_021DD6BC[5];
extern TextIdTable d_021DD6D0;
extern ClactInitParam d_021DD710;
extern const CounterMsgEntry d_021DD774[];
extern u32 d_021DD718[];
extern u32 d_021DD738[];
extern const s16 d_020A1B38[];

static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

static inline void TilePlane_Set(TilePlane *p, int x, int y, int z)
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
 * - the normal table is read through an NormComp pointer cast of a differently
 *   typed object, so mwcc cannot prove it disjoint from out: the setter's
 *   right-to-left arguments then stay as z, y, x temporaries (y spilled) and
 *   the pool word is reloaded per access. A plain NormComp array sinks the loads.
 * - the height table is const (its load is scheduled above the z store).
 * - the tile record is read through a volatile pointer: the image reloads
 *   the norm halfword after the type test instead of reusing the type load;
 *   no non-volatile spelling (casts, unions, other access paths, const)
 *   stopped mwcc from CSE-ing the two halfword loads.
 * - the row index is x/0x10000 + w * (z/0x10000) in that operand order;
 *   p (= &out[idx]) is live into the tail, where only the x read uses it.
 */
void func_021D14C4(TilePlane *out, int idx, TileMap *map, VecFx32 *pos, fx32 size, fx32 base)
{
    fx32 half = size / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int lx = x % 0x10000;
    int lz = z % 0x10000;
    int i = x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000);
    volatile MapTile *t = &map->tiles[i];
    fx32 d;
    TilePlane *p;
    u8 type = t->type;

    if (type == 0) {
        int n = t->norm * 3;
        int di = t->d;
        TilePlane_Set(p = &out[idx], NRM(n), NRM(n + 1), -NRM(n + 2));
        d = d_021DC158[di];
    } else if (type == 2) {
        MapTileSplit *s = (MapTileSplit *)(map->tiles + map->w * map->h) + t->d;
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
        TilePlane_Set(p = &out[idx], NRM(n), NRM(n + 1), -NRM(n + 2));
        d = d_021DC158[di];
    } else {
        TilePlane_Set(p = &out[idx], 0, 0x1000, 0);
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
int func_021D1670(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *saveData;
    u32 flagKind;
    u16 *resultVar;
    u32 wifiList;

    func_0215A5F4(cmdWork);
    func_0215A5DC(cmdWork);
    saveData = func_0215A5E4(cmdWork);
    flagKind = func_02159B10(vm, cmdWork);
    func_02159B10(vm, cmdWork);
    func_02159B10(vm, cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    wifiList = func_02012F8C(saveData);
    if (flagKind == 0) {
        if (func_020092EC((const struct Sub02009210Obj *)wifiList) == 1 && func_020092D8((const struct Sub02009210Obj *)wifiList) == 1) {
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
    }
    return 0;
}

int func_021D16D8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *saveData;
    u32 operation;
    u32 operand;
    u16 *resultVar;
    u8 i;
    u16 *entry;
    u32 wifiList;

    func_0215A5F4(cmdWork);
    func_0215A5DC(cmdWork);
    saveData = func_0215A5E4(cmdWork);
    operation = func_02159B10(vm, cmdWork);
    operand = func_02159B10(vm, cmdWork);
    func_02159B10(vm, cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    wifiList = func_02012F8C(saveData);
    switch (operation) {
    case 0:
        *resultVar = 1;
        for (i = 0; i < 5; i++) {
            entry = (u16 *)func_02009390((struct Sub02009210Obj *)wifiList, i);
            if (entry == 0) {
                *resultVar = 0;
            } else if (entry[0] == 0x7E || entry[0] == 0) {
                *resultVar = 0;
            }
        }
        break;
    case 1:
        if (func_020093D8((const struct Sub02009210Obj *)wifiList) == 0x7F) {
            *resultVar = 0;
        } else {
            *resultVar = 1;
        }
        break;
    case 2:
        if (func_02009418((const struct Sub02009210Obj *)wifiList) == 1) {
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
        break;
    case 3:
        func_02009428((struct Sub02009210Obj *)wifiList, 0);
        break;
    case 4:
        func_020093F0((struct Sub02009210Obj *)wifiList, operand);
        break;
    }
    return 0;
}

int func_021D179C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptCtx = func_0215A5F4(cmdWork);
    void *saveData;
    u32 heapId;
    u32 wordSet;
    u32 wordSlot;
    u32 entryIndex;
    u16 *entry;
    u32 nameBuf;
    u32 wifiList;

    func_0215A5DC(cmdWork);
    saveData = func_0215A5E4(cmdWork);
    heapId = func_0215A5CC(cmdWork);
    wordSet = (u32)func_02158F74(scriptCtx);
    wifiList = func_02012F8C(saveData);
    wordSlot = func_02159B10(vm, cmdWork);
    entryIndex = func_02159B10(vm, cmdWork);
    entry = (u16 *)func_02009390((struct Sub02009210Obj *)wifiList, entryIndex);
    if (entry != 0 && entry[0] != 0x7E && entry[0] != 0) {
        nameBuf = (u32)func_020457B0(0xE, heapId);
        func_02045994((struct Strbuf *)nameBuf, entry + 1, 0xD);
        func_0201EE0C((struct WordSet *)wordSet, wordSlot, (const void *)nameBuf, 0, 0, 2);
        func_02045808((struct U16Vec *)nameBuf);
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
MmdlIcaWork *func_021D182C(u32 fieldWork, u16 mmdlId, Vec3 *offset, u16 heapId)
{
    void *mmdlSys = func_02188C7C((void *)fieldWork);
    u32 subprocMgr = func_02188D24((u8 *)fieldWork);
    int *handle = func_021BB990(-1, (int *)subprocMgr, d_021DD5F0);
    MmdlIcaWork *p = (MmdlIcaWork *)func_021BBA6C(handle);

    p->subprocHandle = handle;
    p->heapId = heapId;
    *(Vec3 *)p->offset = *offset;
    p->mmdl = func_0216DE94(mmdlSys, mmdlId);
    return p;
}

/*
 * Tail call on the word at +0x188.
 *
 * Addresses are Black-image addresses.
 */
void func_021D1884(MmdlIcaWork *p)
{
    func_021BBA1C((int *)p->subprocHandle);
}

void func_021D1894(MmdlIcaWork *p, u32 n)
{
    p->icaAnime = func_0201147C(p->heapId, 0xCB, n, 10, (u32)p->icaBuffer, 0x180);
    p->state = 1;
    p->animKind = n;
    func_021D1988(p->icaAnime, p->mmdl, (Vec3 *)p->offset);
    func_0216D568(p->mmdl, 0x8000);
}

u32 func_021D18E0(MmdlIcaWork *p, u32 a1, u32 a2, u32 a3)
{
    if (p->state == 0) {
        return 1;
    }
    return 0;
}

void func_021D18F4(u32 event, u32 state, MmdlIcaWork *work)
{
    Vec3 v;

    if (work->state == 0) {
        return;
    }
    if (work->state == 1) {
        if (func_02011590(work->icaAnime, 0x1000) == 0) {
            func_021D1988(work->icaAnime, work->mmdl, (Vec3 *)work->offset);
        } else {
            func_02011558(work->icaAnime);
            work->icaAnime = 0;
            work->state = 0;
            func_0216D88C((const struct Actor *)work->mmdl, (struct VecFx32 *)&v);
            func_0216E014(work->mmdl, (int *)(&v), func_0216D5F8(work->mmdl));
            if (d_021DD5E0[work->animKind] != 0) {
                func_0216D570((char *)work->mmdl, 0x8000);
            }
        }
        func_0216D758(work->mmdl);
    }
}

void func_021D1984(void) {}

void func_021D1988(struct IcaAnime *icaAnime, void *mmdl, Vec3 *offset)
{
    Vec3 pos;
    Vec3 dir;

    func_02011610(icaAnime, (struct Rec12 *)&pos);
    func_02011638(icaAnime, (struct Rec12 *)&dir);
    func_0207C9D0(&pos, offset, &pos);
    func_0216D89C((u32)mmdl, &pos);
    if (dir.y == 0) {
        func_0216D60C((int)mmdl, 1);
    } else if (dir.y == 0x5A000) {
        func_0216D60C((int)mmdl, 3);
    } else if (dir.y == 0xB4000) {
        func_0216D60C((int)mmdl, 0);
    } else if (dir.y == 0x10E000) {
        func_0216D60C((int)mmdl, 2);
    }
}

int func_021D1A04(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    Vec3 pos;
    void *scriptCtx = func_0215A5F4(cmdWork);
    u32 *fieldWork = (u32 *)func_02158F58((int)scriptCtx);
    u16 heapId = func_02188C84((u8 *)fieldWork[1]);
    u16 mmdlId = func_02159B10(vm, cmdWork);
    MmdlIcaWork *icaWork;

    func_021A3038(func_02188CB4((struct Obj00020 *)fieldWork[1]), (struct VecFx32 *)&pos);
    icaWork = func_021D182C(fieldWork[1], mmdlId, &pos, heapId);
    func_02159104(scriptCtx, (u32)icaWork);
    return 0;
}

/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021D1A54(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptCtx = func_0215A5F4(cmdWork);

    func_021D1884((MmdlIcaWork *)func_0215910C(scriptCtx));
    func_02159104(scriptCtx, 0);
    return 0;
}

int func_021D1A74(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptCtx = func_0215A5F4(cmdWork);
    u16 animKind = func_02159B10(vm, cmdWork);

    func_021D1894((MmdlIcaWork *)func_0215910C(scriptCtx), animKind);
    return 0;
}

int func_021D1A9C(u32 event, u32 state, u32 work, u32 arg)
{
    if (func_021D18E0(((MmdlIcaWaitWork *)work)->ica, state, work, arg) == 1) {
        return 1;
    }
    return 0;
}

int func_021D1AB0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptCtx = func_0215A5F4(cmdWork);
    void *task = func_020122C0((void *)func_0215A5DC(cmdWork), 0, func_021D1A9C, 4);
    MmdlIcaWaitWork *w = func_020124E8(task);

    w->ica = (MmdlIcaWork *)func_0215910C(scriptCtx);
    func_0215897C(scriptCtx, task);
    return 1;
}

int func_021D1AEC(int event, int *seq, SubscreenModeWork *work)
{
    switch (*seq) {
    case 0:
        if (func_021A0ED4(work->subscreen)) {
            func_021A0F30(work->subscreen, work->mode);
            (*seq)++;
        }
        break;
    case 1:
        if (func_021A0ED4(work->subscreen)) {
            return 1;
        }
        break;
    }
    return 0;
}

int func_021D1B2C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 subscreen, mode;
    u32 *fieldWork;
    void *scriptCtx;
    void *task;
    SubscreenModeWork *work;

    scriptCtx = func_0215A5F4(cmdWork);
    fieldWork = (u32 *)func_02158F58((int)scriptCtx);
    mode = func_02159B10(vm, cmdWork);
    subscreen = func_02188CCC((u8 *)fieldWork[1]);
    task = func_0215A5DC(cmdWork);
    task = func_020122C0(task, 0, func_021D1AEC, 8);
    work = func_020124E8(task);
    mode = d_021DD608[mode];
    work->subscreen = subscreen;
    work->mode = mode;
    func_0215897C(scriptCtx, task);
    func_02159144(8);
    return 1;
}

int func_021D1B8C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 subscreen;
    void *scriptCtx;
    void *task;
    SubscreenModeWork *work;

    scriptCtx = func_0215A5F4(cmdWork);
    subscreen = func_02188CCC((u8 *)(((u32 *)func_02158F58((int)scriptCtx))[1]));
    task = func_0215A5DC(cmdWork);
    task = func_020122C0(task, 0, func_021D1AEC, 8);
    work = func_020124E8(task);
    work->subscreen = subscreen;
    work->mode = 0;
    func_0215897C(scriptCtx, task);
    func_02159168(8);
    return 1;
}

int func_021D1BD8(u32 *event, int *seq)
{
    u32 subscreen;

    subscreen = func_02188CCC((u8 *)(((u32 *)func_02158F58(event[2]))[1]));
    switch (*seq) {
    case 0:
        if (func_021A0ED4(subscreen)) {
            func_021A0F30(subscreen, 0);
            func_02159168(8);
            (*seq)++;
        }
        break;
    case 1:
        if (func_021A0ED4(subscreen)) {
            return 1;
        }
        break;
    }
    return 0;
}

u32 func_021D1C24(void *gameSystem, void *fieldMap, u32 partySlot)
{
    u32 task;
    PerapRecordWork *work;

    task = (u32)func_020122C0(gameSystem, 0, func_021D1C8C, sizeof(PerapRecordWork));
    work = func_020124E8((struct Obj *)task);
    func_02082BCC(work, 0, sizeof(PerapRecordWork));
    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    work->perapVoice = func_02007B44(func_02012EBC(work->gameData));
    work->fieldMap = fieldMap;
    work->fieldPlayer = func_02188CB4(fieldMap);
    work->partyMon = func_0201AB28(func_02012934(work->gameData), partySlot);
    work->msgBg = (void *)func_02188C54(work->fieldMap);
    work->partySlot = partySlot;
    work->recordDone = 0;
    return task;
}

/*
 * Fifteen-state field sequence: sets up handles, runs fades and a message task, then tears down.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1C8C(void *event, int *seq, PerapRecordWork *w)
{
    void *string;
    void *taskList;
    void *msgData;
    u32 micBuf;

    switch (*seq) {
    case 0:
        func_021D1F50(w);
        *seq = 1;
        break;
    case 1:
        w->msgData = msgData = (void *)func_021904B0((u32)w->msgBg, 88);
        w->sysWin = func_02190F64(w->msgBg, (u32)msgData);
        w->wordSet = func_0201EC64(21);
        w->msgBuf = func_020457B0(0x400, 21);
        func_021D20BC(w);
        if (func_02007B50(w->perapVoice) == 1) {
            func_02190E74(w->sysWin, 0, 0, 0);
            *seq = 2;
        } else {
            func_02190E74(w->sysWin, 0, 0, 6);
            *seq = 4;
        }
        break;
    case 2:
        if (func_02190EF0(w->sysWin) == 1) {
            w->yesNoMenu = func_02190BE4(w->msgBg, 0);
            *seq = 3;
        }
        break;
    case 3:
        switch (func_02190C78(w->yesNoMenu)) {
        case 0:
            func_021909BC(w->yesNoMenu);
            func_02190F7C(w->sysWin);
            func_02190E74(w->sysWin, 0, 0, 6);
            *seq = 4;
            break;
        case 1:
            func_021909BC(w->yesNoMenu);
            *seq = 13;
            break;
        }
        break;
    case 4:
        if (func_02190EF0(w->sysWin) == 1) {
            func_02034F84(8);
            taskList = sub_020056BC(func_02006CBC(21));
            w->timeIcon = func_0202EE30(taskList, func_02190F9C(w->sysWin), 15, 16, 21);
            *seq = 5;
        }
        break;
    case 5:
        func_02006D64(2);
        if (func_02006D94() == 1) {
            func_0202F038(w->timeIcon);
            func_02190F7C(w->sysWin);
            func_02190E74(w->sysWin, 0, 0, 1);
            func_02012374(event, (struct Evt **)func_020295A4(w->gameSystem, 6));
            *seq = 6;
        }
        break;
    case 6:
        if (func_02190EF0(w->sysWin) == 1) {
            if (func_02006DD8(func_021D1F48, (u32)&w->recordDone) == 0) {
                *seq = 7;
            } else {
                string = func_02045EC0(w->msgData, 3);
                func_0201EEF4(w->wordSet, 0, w->partyMon);
                func_0201F250(w->wordSet, w->msgBuf, string);
                func_02045808(string);
                func_02190F7C(w->sysWin);
                func_02190EB8(w->sysWin, 0, 0, (u32)w->msgBuf);
                func_02006D44();
                func_02034FB8(8);
                func_02012374(event, func_02029620(w->gameSystem, 0, 30));
                *seq = 12;
            }
        }
        break;
    case 7:
        if (w->recordDone == 1) {
            func_02006E18(w->perapVoice);
            func_02006D44();
            func_02034FB8(8);
            func_02012374(event, func_02029620(w->gameSystem, 0, 30));
            *seq = 8;
        }
        break;
    case 8:
        if (func_021D2040(w) == 0) {
            string = func_02045EC0(w->msgData, 2);
            func_0201EEF4(w->wordSet, 0, w->partyMon);
            func_0201F250(w->wordSet, w->msgBuf, string);
            func_02045808(string);
            func_02190F7C(w->sysWin);
            func_02190EB8(w->sysWin, 0, 0, (u32)w->msgBuf);
            *seq = 9;
        }
        break;
    case 9:
        if (func_02190EF0(w->sysWin) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        func_02006CAC((void **)&micBuf);
        w->voiceHandle = (void *)func_02006984(0x1B9, 0, 64, 0, 0, 0, 0, (u32)(&micBuf));
        *seq = 11;
        break;
    case 11:
        if (sub_02006BD0((u32)w->voiceHandle) == 0) {
            *seq = 13;
        }
        break;
    case 12:
        if (func_02190EF0(w->sysWin) == 1) {
            *seq = 13;
        }
        break;
    case 13:
        func_021D2124(w);
        func_02045808(w->msgBuf);
        func_0201ED04(w->wordSet);
        func_02190E40((u32)w->sysWin);
        func_021904C8(w->msgData);
        *seq = 14;
        break;
    case 14:
        func_021D1F64(w);
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

int func_021D1F50(PerapRecordWork *work)
{
    return func_0216D9A0(func_02188C7C(func_0201210C(work->gameSystem)));
}

int func_021D1F64(PerapRecordWork *work)
{
    return (int)func_0216D9E4(func_02188C7C(func_0201210C(work->gameSystem)));
}

void func_021D1F78(PerapRecordWork *w)
{
    u32 monData, resMgr, savedState;
    ClactInitParam buf;

    w->clactUnit = (u32)func_0204B100(1, 0, 0x15);
    monData = func_020185F0((u32)w->partyMon);
    resMgr = func_0202D7C8(0x15);
    savedState = func_02017DBC((struct Sav *)monData);
    w->charRes = func_0202D934(resMgr, (void *)monData, 0, 0, 0x15);
    w->palRes = func_0202D8D0(resMgr, (void *)monData, 0, 0, 0x60, 0x15);
    w->cellRes = func_0202D9A4(monData, 0, 1, 0, 0x15);
    func_02017DE4((struct Sav *)monData, savedState);
    func_02049238((void *)resMgr);
    buf = d_021DD60C;
    w->clactActor = (u32)func_0204B294((void *)w->clactUnit, w->charRes, w->palRes, w->cellRes, &buf, 0, 0x15);
}

int func_021D201C(PerapRecordWork *work)
{
    func_0204B3B4((struct Obj *)work->clactActor);
    func_0204A8D4(work->charRes);
    func_0204ADA4(work->palRes);
    func_0204AFD8(work->cellRes);
    return func_0204B1CC((struct Bank *)work->clactUnit);
}

int func_021D2040(PerapRecordWork *w)
{
    SpritePos pt;

    if (w->hopCount == 0) {
        w->hopSpeed = -4;
    }
    if (w->hopSpeed == -4) {
        w->hopSpeed = 3;
        w->hopCount = w->hopCount + 1;
        if (w->hopCount == 3) {
            return 0;
        }
    }
    func_0204B454((struct Actor *)w->clactActor, (struct PtS *)&pt, 0);
    pt.y = pt.y - w->hopSpeed;
    func_0204B404((struct Obj *)(w->clactActor), (const struct Vec2 *)(&pt), 0);
    w->hopSpeed = w->hopSpeed - 1;
    return 1;
}

void func_021D20BC(PerapRecordWork *w)
{
    func_02049B90(5, func_0201F548(0), 0, 0, 0, 0x20, 0x15);
    w->bmpWin = func_020450F0(1, 10, 3, 12, 12, 0, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w->bmpWin)), 0x11);
    func_02045334((struct Descriptor *)w->bmpWin);
    func_02045374((struct Cfg *)w->bmpWin);
    func_0201F73C((void *)w->bmpWin, 1, 1, 0);
    func_021D1F78(w);
}

int func_021D2124(PerapRecordWork *work)
{
    func_021D201C(work);
    func_0201F7A8((void *)work->bmpWin, 1);
    return func_020452E8((struct Descriptor *)work->bmpWin);
}

/*
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * Addresses are Black-image addresses.
 */
int func_021D213C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 flagBase, idA, idB, kind, flagEnd;
    u16 *resultVar;

    kind = func_02159B10(vm, cmdWork);
    idA = func_02159B10(vm, cmdWork);
    idB = func_02159B10(vm, cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    switch (kind) {
    case 1:
        flagBase = 0x5C0;
        flagEnd = flagBase + 0xBB;
        break;
    case 2:
        flagBase = 0x664;
        flagEnd = flagBase + 0x53;
        break;
    default:
        *resultVar = 0;
        return 0;
    }
    if (func_020249B0(flagBase, idA & 0x7FF) && func_020249B0(flagEnd, idB & 0x7FF)) {
        *resultVar = 1;
    } else {
        *resultVar = 0;
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

int func_021D2278(u32 event, int *seq, RippleWarpWork *w)
{
    Vec3 v;
    u16 warpId;
    u32 effectMgr;
    void *player;

    switch (*seq) {
    case 0:
        effectMgr = func_02188D38((unsigned char *)w->fieldWork);
        v.x = 0;
        v.y = -0x40000;
        v.z = 0;
        func_021C6DE0((unsigned char *)effectMgr, (u32 *)func_021C7858(w->fieldWork, 0x28, (u32)(&v)), 0);
        w->waitFrames = 8;
        (*seq)++;
        break;
    case 1:
        w->waitFrames--;
        if (w->waitFrames > 0) {
            break;
        }
        func_020061E4(0x63C);
        (*seq)++;
        break;
    case 2:
        if (func_02006224(func_02006148(0x63C)) != 0) {
            break;
        }
        player = func_02188CB4((struct Obj00020 *)w->fieldWork);
        func_021A3074(player);
        func_021A30A4(player, 3);
        func_021CD440((void *)w->fieldWork, &warpId);
        func_02012374((struct Evt *)event, (struct Evt **)func_02184FD4((void *)w->field, warpId));
        (*seq)++;
        break;
    case 3:
        func_0216D410(func_021A3074(func_02188CB4((struct Obj00020 *)w->fieldWork)), 8);
        (*seq)++;
        break;
    case 4:
        if (func_0216D454(func_021A3074(func_02188CB4((struct Obj00020 *)w->fieldWork)))) {
            return 1;
        }
        break;
    }
    return 0;
}

int func_021D2358(u32 event, int *seq, RippleWarpWork *w)
{
    u32 effectMgr, fogCtl, spinTaskA, spinTaskB;

    effectMgr = func_02188D38((unsigned char *)w->fieldWork);
    switch (*seq) {
    case 0:
        func_020061E4(0x63C);
        w->waitFrames = 0x18;
        if (w->useSpin) {
            fogCtl = func_02188C64((unsigned char *)w->fieldWork);
            spinTaskA = (u32)func_021C7260(w->fieldWork, 0x14, 3);
            spinTaskB = (u32)func_021C71D4(w->fieldWork, 0xc, 3);
            func_021C6DE0((unsigned char *)effectMgr, (u32 *)spinTaskA, 0);
            func_021C6DE0((unsigned char *)effectMgr, (u32 *)spinTaskB, spinTaskA);
            func_021A01FC((unsigned char *)fogCtl, 0x7F0F, func_021A01D4((unsigned char *)fogCtl), 0x1A);
        }
        (*seq)++;
        break;
    case 1:
        func_021A30A4(func_02188CB4((struct Obj00020 *)w->fieldWork), 2);
        (*seq)++;
        break;
    case 2:
        w->waitFrames--;
        if (w->waitFrames > 0) {
            break;
        }
        func_02012374((struct Evt *)event, func_02184F88((void *)w->field));
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

void *func_021D2418(void *field, u32 fieldWork)
{
    void *task = func_020122C0(field, 0, func_021D2278, sizeof(RippleWarpWork));
    RippleWarpWork *w = func_020124E8(task);

    w->field = field;
    w->fieldWork = fieldWork;
    w->useSpin = 0;
    return task;
}

void *func_021D2440(void *field, u32 fieldWork, u32 useSpin)
{
    void *task = func_020122C0(field, 0, func_021D2358, sizeof(RippleWarpWork));
    RippleWarpWork *w = func_020124E8(task);

    w->field = field;
    w->fieldWork = fieldWork;
    w->useSpin = useSpin;
    return task;
}

int func_021D2468(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 gameData, sceneFlag, trainerRecord, currentA, currentB, recordA;
    u16 *outA, *outB, *outC;
    TextIdTable table;

    gameData = (u32)func_0215A5E4(cmdWork); /* int-typed on purpose: pointer local changes codegen */
    sceneFlag = func_02159B10(vm, cmdWork);
    outA = func_02159AE8(vm, cmdWork);
    outB = func_02159AE8(vm, cmdWork);
    outC = func_02159AE8(vm, cmdWork);
    table = d_021DD6D0;
    trainerRecord = (u32)func_02008B08(func_02012EBC((struct Big *)gameData));
    currentA = func_021690D0(gameData);
    currentB = func_021690E0(gameData);
    recordA = func_02008B94((const struct Sub02008AECObj *)trainerRecord);
    if (currentB == func_02008B98((const struct Sub02008AECObj *)trainerRecord) && currentA == recordA) {
        *outA = 0x34;
        *outB = 0x53;
        *outC = table.textId[30];
    } else {
        u32 i = func_020056EC(sceneFlag ? 0x1E : 0x16);
        *outA = i + 0x16;
        *outB = i + 0x35;
        *outC = table.textId[i];
    }
    return 0;
}

int func_021D2524(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 gender, species, form, isEgg;
    void *task;
    void *gameSystem;
    void *work;
    void *scriptCtx;

    gameSystem = func_0215A5DC(cmdWork);
    func_0201210C(gameSystem);
    species = func_02159B10(vm, cmdWork);
    form = func_02159B10(vm, cmdWork);
    isEgg = func_02159B10(vm, cmdWork);
    gender = func_02159B10(vm, cmdWork);
    scriptCtx = func_0215A5F4(cmdWork);
    task = func_020122C0(gameSystem, 0, func_021D26D0, 0x18);
    work = func_020124E8(task);
    func_021D25A4(work);
    func_021D25F4(work, species, form, isEgg, gender, 0);
    func_0215897C(scriptCtx, task);
    return 1;
}

void func_021D25A4(PokeIconWork *p)
{
    p->bmpWin = func_020450F0(1, 10, 3, 12, 12, 13, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->bmpWin)), 17);
    func_02045334((struct Descriptor *)p->bmpWin);
    func_02045374((struct Cfg *)p->bmpWin);
    func_0201F73C((void *)p->bmpWin, 1, 1, 13);
}

/*
 * Tail call with the leading word and a constant one.
 *
 * Addresses are Black-image addresses.
 */
void func_021D25E8(PokeIconWork *p)
{
    func_0201F7A8((void *)p->bmpWin, 1);
}

/*
 * The pooled 0x8015 is the heap id as a plain literal: it is too wide for a
 * Thumb movs, so the compiler pools it by itself; no symbol is needed. int
 * params were the fix for register allocation.
 *
 * Addresses are Black-image addresses.
 */
void func_021D25F4(PokeIconWork *p, int species, int form, int isEgg, int gender, int charFlags)
{
    ClactInitParam loc;
    u32 t;

    p->clactUnit = (u32)func_0204B100(1, 0, 0x8015);
    t = func_0202D7C8(0x8015);
    p->charRes = func_0202D81C(t, species, form, isEgg, gender, 0, 0, charFlags, 0, 0x8015);
    p->palRes = (u32)func_0202D7D8((u32)t, (u32)species, (u32)form, (u32)isEgg, (u32)gender, (u32)0, (u32)0, (u32)0, (u32)0, (u32)0x8015);
    func_02049238((void *)t);
    p->cellRes = func_0202D898(species, form, isEgg, gender, 0, 0, 1, 0, 0x8015);
    loc = d_021DD710;
    p->clactActor = (u32)func_0204B294((void *)p->clactUnit, p->charRes, p->palRes, p->cellRes, &loc, 0, 0x8015);
}

int func_021D26AC(PokeIconWork *work)
{
    func_0204B3B4((struct Obj *)work->clactActor);
    func_0204A8D4(work->charRes);
    func_0204ADA4(work->palRes);
    func_0204AFD8(work->cellRes);
    return func_0204B1CC((struct Bank *)work->clactUnit);
}

u32 func_021D26D0(u32 event, u32 *state, PokeIconWork *p)
{
    switch (state[0]) {
    case 0:
        if (func_020362DC() & 3) {
            func_021D26AC(p);
            func_021D25E8(p);
            state[0]++;
        }
        break;
    case 1:
        func_020452E8((struct Descriptor *)p->bmpWin);
        return 1;
    }
    return 0;
}

u32 func_021D2710(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 slot;
    u16 *resultVar;
    u32 gameData;
    u32 partyBlock;

    slot = func_02159B10(vm, cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    gameData = (u32)func_020120F4((const struct Ctx *)func_0215A5DC(cmdWork));
    partyBlock = (u32)func_02012F08((int *)gameData);
    *resultVar = func_0216BF9C((void *)partyBlock, slot, func_02012944((void *)gameData));
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
int func_021D2750(u32 gameSystem)
{
    MmdlModelInfo modelInfo;
    Vec3 playerPos;
    FacingTile facing;
    GridPos gridPos;
    u32 gameData, eventData;
    MapEventRec *list;
    void *fieldWork;
    void *mapCtx;
    void *player;
    u32 mapId;
    MapEventRec *event;
    TileCoord *tile;
    int arcHandle;
    int i;
    int n;
    u8 *entry;
    u32 partyData;
    void *playerActor;

    gameData = (u32)func_020120F4((const struct Ctx *)gameSystem);
    eventData = func_02012844((const struct BigObj *)gameData);
    list = (MapEventRec *)func_02162740((u8 *)eventData);
    n = func_02162744((u8 *)eventData);
    fieldWork = func_0201210C((void *)gameSystem);
    mapCtx = func_02188C7C((void *)fieldWork);
    player = func_02188CB4((void *)fieldWork);
    mapId = func_02188C9C(fieldWork);
    if ((int)func_02013C60((u16)mapId) == 0) {
        return 0;
    }
    if ((u32)(func_021A3098(player) - 2) <= 1) {
        return 0;
    }
    if ((list == 0 || n == 0) && mapId != 0 && mapId != 0x1A8) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        event = &list[i];
        if (event->kind == 0) {
            tile = &event->tile;
            func_0216E2E8(mapCtx, event->modelId, (struct Record *)&modelInfo);
            func_021A35FC(player, (u16 *)(&gridPos.gridX), (u16 *)(&gridPos.height), (u16 *)(&gridPos.gridZ));
            if (event->tile.gridX <= gridPos.gridX && gridPos.gridX < event->tile.gridX + modelInfo.w) {
                if (tile->gridZ - modelInfo.h < gridPos.gridZ && gridPos.gridZ <= tile->gridZ) {
                    return 0;
                }
            }
        } else if (event->kind == 1) {
            tile = &event->tile;
            if (func_02188CFC(fieldWork) == 1) {
                func_021A36BC(player, &facing);
                if (tile->gridX == facing.gridX && tile->gridZ == facing.gridZ && tile->height == facing.height) {
                    return 0;
                }
            }
        }
    }
    if (func_02188CFC(fieldWork) == 0) {
        playerActor = func_021A3074((void *)player);
        partyData = func_0201296C((const struct BigObj *)gameData);
        func_0216D88C(playerActor, (struct VecFx32 *)&playerPos);
        if (func_02162890((struct Ctx *)eventData, (void *)partyData, (int)(&playerPos))) {
            return 0;
        }
    }
    if (mapId == 0 || mapId == 0x1A8) {
        int j;
        u8 *table;
        func_021A35FC(player, (u16 *)(&gridPos.gridX), (u16 *)(&gridPos.height), (u16 *)(&gridPos.gridZ));
        arcHandle = (int)func_021867C4(0, 0x8015);
        table = func_02186830((struct ArcFile **)arcHandle, mapId != 0, 0x8015);
        for (j = 0; j < 10; j++) {
            entry = func_02186844(table, j);
            if (entry[0] == gridPos.gridX && entry[1] == gridPos.gridZ) {
                func_0218683C(table);
                func_02186804((void **)arcHandle);
                return 0;
            }
        }
        for (j = 0; j < 10; j++) {
            entry = func_0218684C(table, j);
            if (entry[0] == gridPos.gridX && entry[1] == gridPos.gridZ) {
                func_0218683C(table);
                func_02186804((void **)arcHandle);
                return 0;
            }
        }
        func_0218683C(table);
        func_02186804((void **)arcHandle);
    }
    return 1;
}

void *func_021D297C(void *field)
{
    void *task = func_020122C0(field, 0, func_021D29A8, sizeof(SubscreenAnimWork));
    SubscreenAnimWork *work = func_020124E8(task);

    work->fieldWork = (u32)func_0201210C(field);
    work->subscreen = func_02188CCC((u8 *)work->fieldWork);
    return task;
}

u32 func_021D29A8(u32 event, u32 *state, SubscreenAnimWork *work)
{
    switch (state[0]) {
    case 0:
        func_021A0F30(work->subscreen, 9);
        state[0]++;
        break;
    case 1:
        if (func_021A0F94(work->subscreen) == 14) {
            func_021A0FA8((int *)work->subscreen);
            state[0]++;
        }
        break;
    case 2:
        func_021A0F30(work->subscreen, 0);
        return 1;
    }
    return 0;
}

int func_021D29F0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void **fieldWork;
    u32 heapId, msgData, bmpWin, msgBuf;
    void *msgBg;

    fieldWork = (void **)func_02158F58((int)func_0215A5F4(cmdWork));
    heapId = func_02188C84(fieldWork[1]);
    msgBg = (void *)func_02188C54(fieldWork[1]);
    if (func_02011330((struct Stream *)vm)) {
        msgData = (u32)func_02045B38(0, 2, 0x16, heapId);
        bmpWin = func_02045180(2, 1, 1, 0x1E, 10, 14, 0x40);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)bmpWin)), 0xF);
        func_02045334((struct Descriptor *)bmpWin);
        func_02045374((struct Cfg *)bmpWin);
        func_0201F73C((void *)bmpWin, 0, 1, 0xD);
        msgBuf = (u32)func_020457B0(0xB4, heapId);
        func_02045CAC((struct MsgBank *)msgData, 3, (void *)msgBuf);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)bmpWin)), 0, 0, (void *)msgBuf, (void *)func_021904AC(msgBg));
        func_02045334((struct Descriptor *)bmpWin);
        func_02041B6C(2);
        func_02045808((struct U16Vec *)msgBuf);
        func_02045C04((struct Rec_021D1988 *)msgData);
        func_020452E8((struct Descriptor *)bmpWin);
    } else {
        func_02041300(2, 0, 0, 0, 0x20, 0xC, 0x11);
        func_02041B6C(2);
    }
    return 0;
}

int func_021D2ADC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    u32 index = func_02159B10(vm, cmdWork);
    u32 delta = func_02159B10(vm, cmdWork);

    func_02008DAC(func_02008C58(func_02012EBC(func_020120F4((void *)gameSystem))), index, delta);
    return 0;
}

int func_021D2B18(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    u32 index = func_02159B10(vm, cmdWork);
    u16 *resultVar = func_02159AE8(vm, cmdWork);

    *resultVar = func_02008DFC(func_02008C58(func_02012EBC(func_020120F4((void *)gameSystem))), index);
    return 0;
}

int func_021D2B54(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData;
    u32 name, wordSet, argValue;
    void *scriptCtx;
    u16 *out;
    void *party;
    int i, n;
    void *mon;
    RtcTime t;
    int base;
    int msgIndex;
    u32 countA, countB;
    u32 counters;
    u32 idA, idB;

    scriptCtx = func_0215A5F4(cmdWork);
    gameData = func_020120F4(func_0215A5DC(cmdWork));
    name = (u32)func_02012944(gameData);
    wordSet = (u32)func_02158F74(scriptCtx);
    argValue = func_02159B10(vm, cmdWork);
    out = func_02159AE8(vm, cmdWork);
    func_0201F02C((struct WordSet *)wordSet, 0, (void *)name);
    party = func_02012934(gameData);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            func_0201EE60((struct WordSet *)wordSet, 3, func_02017E1C(mon, 5, 0));
            break;
        }
    }
    func_0203F4CC((struct RtcTime *)(&t));
    if (t.minute < 10) {
        base = 0;
        msgIndex = func_020056EC(0x1D);
        countA = 0;
        countB = 0;
        counters = (u32)func_02012F2C(gameData);
        idA = d_021DD774[msgIndex].idA;
        if (idA != -1) {
            countA = func_02008DFC((struct Sub02008C20Obj *)counters, idA);
            func_0201EFA4((struct WordSet *)wordSet, 1, countA, d_021DD774[msgIndex].digitsA, 0, 1);
        }
        idB = d_021DD774[msgIndex].idB;
        if (idB != -1) {
            countB = func_02008DFC((struct Sub02008C20Obj *)counters, idB);
            func_0201EFA4((struct WordSet *)wordSet, 2, countB, d_021DD774[msgIndex].digitsB, 0, 1);
        }
        if (msgIndex < 11) {
            if (idA != -1 && idB != -1) {
                if (countA == 0 || countB == 0) {
                    msgIndex = 0;
                }
            } else if (idB == -1 && countA == 0) {
                msgIndex = 0;
            }
        }
        if (msgIndex < 11) {
            if ((u8)(int)func_02008550((const struct Sub0200852CObj *)name) == 1) {
                msgIndex += 11;
            }
        } else {
            msgIndex += 11;
        }
    } else if (t.minute < 0x23) {
        base = 0x28;
        msgIndex = func_020056EC(0x32);
    } else {
        base = 0x5A;
        msgIndex = func_020056EC(0x50);
    }
    *out = func_021D2D24(gameData, func_021D2CE8(gameData, base + msgIndex), argValue);
    return 0;
}

/*
 * The 0x0C-random-plus-0x5A path returns through its own temporary (an
 * else arm with a local); a direct `return f() + 0x5a` merges into v. The
 * loop index reuses the second parameter's register: v is copied out and the
 * parameter becomes the index, which gives the image's r1/r2/r3 colouring
 * (a fresh int index rotates them by one).
 */
u32 func_021D2CE8(void *gameData, int i)
{
    u32 v = i;
    void *checker = func_0200C0F0(func_02012EBC(gameData));

    for (i = 0; i < 8; i++) {
        if (v == d_021DD718[i]) {
            if (func_0200C234(checker)) {
                return v;
            } else {
                u32 rolled = func_020056EC(0xc);
                return rolled + 0x5a;
            }
        }
    }
    return v;
}

u32 func_021D2D24(void *gameData, u32 msgIndex, int fixedMsg)
{
    int i;

    if (fixedMsg == 0) {
        for (i = 0; i < 0xf; i++) {
            if (msgIndex == d_021DD738[i]) {
                return func_020056EC(0x14) + 0x6e;
            }
        }
    }
    return msgIndex;
}

void *func_021D2D50(void *a, CameraShakeParams *src)
{
    void *task = func_020122C0(a, 0, func_021D2D7C, sizeof(CameraShakeWork));

    *(CameraShakeParams *)func_020124E8(task) = *src;
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
    CameraShakeWork *w;
    void *o;
    void *h;
    int done;
    u16 ang;
    int swingScale;

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
            w->pos = (Vec3 *)func_0218EC5C(h);
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
            Vec3 zero = {0, 0, 0};
            func_0218ED04(h, &zero);
            func_0218EC30(h, w->pos);
            func_0218F05C(h);
            (*state)++;
        } else {
            Vec3 pos;
            Vec3 ofs;
            int ox, oy;
            swingScale = d_020A1B38[(ang >> 4) * 2];
            ox = w->x * swingScale;
            oy = w->y * swingScale;
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

u32 func_021D2EDC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int pos[3];
    void *scriptCtx;
    void *gameSystem;
    u32 mmdlId;
    u32 targetId;
    void *task;

    scriptCtx = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_0201210C(gameSystem);
    mmdlId = func_02159B10(vm, cmdWork);
    targetId = func_02159B10(vm, cmdWork);
    func_0216D88C((const struct Actor *)func_0216DE94(func_0215A5EC(cmdWork), mmdlId), (struct VecFx32 *)pos);
    task = func_021F3CFC(gameSystem, pos, mmdlId, targetId);
    if (task == 0) {
        return 1;
    }
    func_0215897C(scriptCtx, task);
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
int func_021D2F44(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptCtx = func_0215A5F4(cmdWork);
    void *task = func_021F37B8((int)func_0215A5DC(cmdWork));

    if (task == 0) {
        return 1;
    }
    func_0215897C(scriptCtx, task);
    return 1;
}

u32 func_021D2F6C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int pos[3];
    int target[3];
    void *scriptCtx;
    void *gameSystem;
    void *fieldWork;
    int mmdlId;
    int tileX;
    int tileY;
    int tileZ;
    int radius;
    int param;
    void *task;

    scriptCtx = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    fieldWork = func_0201210C(gameSystem);
    mmdlId = (int)func_02159B10(vm, cmdWork);
    tileX = (int)func_02159B10(vm, cmdWork);
    tileY = (int)func_02159B10(vm, cmdWork);
    tileZ = (int)func_02159B10(vm, cmdWork);
    radius = (int)func_02159B10(vm, cmdWork);
    param = (int)func_02159B10(vm, cmdWork);
    task = func_0216DE94(func_02188C7C((void *)fieldWork), mmdlId);
    if (task != 0) {
        func_0216D88C(task, (struct VecFx32 *)pos);
    }
    target[0] = (tileX << 16) + 0x8000;
    target[1] = tileY << 15;
    target[2] = (tileZ << 16) + 0x8000;
    task = func_021F3970(gameSystem, pos, target, radius << 15, param);
    if (task == 0) {
        return 1;
    }
    func_0215897C(scriptCtx, task);
    return 1;
}

u32 func_021D3018(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int pos[3];
    void *gameSystem;
    int tileX;
    int tileY;
    int tileZ;

    gameSystem = func_0215A5DC(cmdWork);
    tileX = (int)func_02159B10(vm, cmdWork);
    tileY = (int)func_02159B10(vm, cmdWork);
    tileZ = (int)func_02159B10(vm, cmdWork);
    pos[0] = (tileX << 16) + 0x8000;
    pos[1] = tileY << 15;
    pos[2] = (tileZ << 16) + 0x8000;
    func_021F3A44(gameSystem, pos);
    return 0;
}

int func_021D3068(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptCtx = func_0215A5F4(cmdWork);
    void *task = func_021F3ADC(func_0215A5DC(cmdWork));

    if (task == 0) {
        return 1;
    }
    func_0215897C(scriptCtx, task);
    return 1;
}

/*
 * func_021F3AC0 resolves in ov064: the only Thumb function starting there
 * that takes one argument (ov043's takes two), and the neighbouring ov021
 * functions func_021D2F6C and func_021D3018 already call ov064 code.
 */
int func_021D3090(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptCtx = func_0215A5F4(cmdWork);
    void *task = func_021F3AC0(func_0215A5DC(cmdWork));

    if (task == 0) {
        return 1;
    }
    func_0215897C(scriptCtx, task);
    return 1;
}
