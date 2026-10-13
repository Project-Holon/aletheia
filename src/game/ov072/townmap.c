/*
 * file:     townmap.c
 * unit:     yes
 * function: func_021B95A0, func_021B9858, func_021B98F8, func_021B991C, func_021B9938, func_021B9944, func_021B9958, func_021B995C, func_021B9964, func_021B996C, func_021B99AC, func_021B99E8, func_021B9E38, func_021B9F20, func_021B9F50, func_021BA028, func_021BA040, func_021BA04C, func_021BA0D8, func_021BA0E4, func_021BA3BC, func_021BA3CC, func_021BA3E8, func_021BA3EC, func_021BA3F4, func_021BA450, func_021BA488, func_021BA48C, func_021BA490, func_021BA570, func_021BA5AC, func_021BA5B0, func_021BA638, func_021BA69C, func_021BA6A8, func_021BA6C8, func_021BA710, func_021BA774, func_021BA7A4, func_021BA7D4, func_021BA7F8, func_021BA834, func_021BA86C, func_021BAA14, func_021BAA30, func_021BAA90, func_021BACB0, func_021BAD10, func_021BAD84, func_021BADBC, func_021BADF4, func_021BAE44, func_021BAE9C, func_021BAF24, func_021BAF3C, func_021BAF74, func_021BAF9C, func_021BAFA8, func_021BB0B4, func_021BB0DC, func_021BB0E0, func_021BB0E4, func_021BB190, func_021BB19C, func_021BB1BC, func_021BB204, func_021BB220, func_021BB3D0
 * address:  0x021B95A0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   ov067_id       0x00000043  data
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02040618  0x02040618  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020355C4 0x020355C4 arm
 *   d_021BBB78 0x021BBB78 data ov072 a4
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021B6520  0x021B6520  thumb  ov067
 *   d_021BBB8C     0x021BBB8C  data  a4
 *   func_021B639C 0x021B639C thumb ov067
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_0204B454  0x0204B454  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0204B98C  0x0204B98C  arm
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   func_0204B878  0x0204B878  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B6498  0x021B6498  thumb  ov067
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_0203630C  0x0203630C  arm
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Mag        0x0207CBD0  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_020520A4  0x020520A4  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02030734  0x02030734  arm
 *   d_021BBD60     0x021BBD60  data  ov072
 *   func_020307B0 0x020307B0 arm
 *   func_02166C7C 0x02166C7C thumb ov010
 *   func_02166CD0  0x02166CD0  thumb  ov010
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *   BUTTON_MAN_InitSphere  0x02051F1C  arm
 *   BUTTON_MAN_InitSegment  0x0205207C  arm
 *   BUTTON_MAN_SegmentSphereTest  0x02051F34  arm
 *   CLACT_SetActorScale  0x0204B5AC  arm
 *   func_020419E4  0x020419E4  arm
 *   func_021BAF24  0x021BAF24  thumb
 *   func_021BAF3C  0x021BAF3C  thumb
 *   func_021BAF74  0x021BAF74  thumb
 *   func_021BAF9C  0x021BAF9C  thumb
 *   func_021BAFA8  0x021BAFA8  thumb
 *   func_021BB0B4  0x021BB0B4  thumb
 *   func_021BB0DC  0x021BB0DC  thumb
 *   func_021BB0E0  0x021BB0E0  thumb
 *   func_021BB0E4  0x021BB0E4  thumb
 *   func_021BB190  0x021BB190  thumb
 *   func_021BB19C  0x021BB19C  thumb
 *   func_021BB1BC  0x021BB1BC  thumb
 *   func_021BB204  0x021BB204  thumb
 *   func_021BB220  0x021BB220  thumb
 *   func_021BB3D0  0x021BB3D0  thumb
 *   func_021BB3E8  0x021BB3E8  thumb
 *   func_021BB42C  0x021BB42C  thumb
 *   func_021BB448  0x021BB448  thumb
 *   func_021BB49C  0x021BB49C  thumb
 *   func_021BB4B4  0x021BB4B4  thumb
 *   func_021BB534  0x021BB534  thumb
 *   func_021BB548  0x021BB548  thumb
 *   func_021BB5AC  0x021BB5AC  thumb
 *   func_021BB5B4  0x021BB5B4  thumb
 *   func_021BB5D4  0x021BB5D4  thumb
 *   func_021BB5E0  0x021BB5E0  thumb
 *   func_021BB5EC  0x021BB5EC  thumb
 *   func_021BB6AC  0x021BB6AC  thumb
 *   func_021BB6DC  0x021BB6DC  thumb
 *   func_021BB6E4  0x021BB6E4  thumb
 *   func_021BB6E8  0x021BB6E8  thumb
 *   func_021BB738  0x021BB738  thumb
 *   func_021BB758  0x021BB758  thumb
 *   func_021BB764  0x021BB764  thumb
 *   func_021BB778  0x021BB778  thumb
 *   func_021BB784  0x021BB784  thumb
 *   func_021BB790  0x021BB790  thumb
 *   func_021BB7BC  0x021BB7BC  thumb
 *   func_021BB80C  0x021BB80C  thumb
 *   func_021BB820  0x021BB820  thumb
 *   func_021BB968  0x021BB968  thumb
 *   func_021BB9B0  0x021BB9B0  thumb
 *   func_021BB9B8  0x021BB9B8  thumb
 *   func_021BBAB4  0x021BBAB4  thumb
 *   func_021BBAFC  0x021BBAFC  thumb
 *   func_021BBB04  0x021BBB04  thumb
 *   func_021BBB0C  0x021BBB0C  thumb
 *   func_021BBB14  0x021BBB14  thumb
 *   func_021BBB1C  0x021BBB1C  thumb
 *   func_021BBB24  0x021BBB24  thumb
 *   func_021BBB34  0x021BBB34  thumb
 *   func_021BBB3C  0x021BBB3C  thumb
 *   func_02041EE4  0x02041EE4  arm
 *   func_02041FB0  0x02041FB0  arm
 *   func_02041F6C  0x02041F6C  arm
 *   func_02045738  0x02045738  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_021BA5B0  0x021BA5B0  thumb
 *   func_021BA834  0x021BA834  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020456F8 0x020456F8 arm
 *   func_021BA774  0x021BA774  thumb
 */
#include "townmap_types.h"

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct GfFont;
struct HeapTask;
struct Ctx;
struct MsgBank;
struct Node;
struct Rec;
struct S020315D4;
struct Actor;
struct PtS;
struct Vec2;
struct Out;
struct S12;
struct Vec;
struct Pair;
struct BgTemplate;

typedef signed int     s32;

typedef long long s64;

/* Button manager request. */
typedef struct ButtonManRequest {
    u8 *table;
    u32 tableCount;
    int clactSet;
    u32 bgLayer;
    u32 palette;
    u32 tileBase;
    int kind;
    int reserved;
} ButtonManRequest;

typedef struct { u32 w[16]; } ButtonTable;


typedef struct { int x,y,z; } Vec;






struct Vec3 { int x; int y; int z; };













struct Seg {
    struct Vec3 p0;
    struct Vec3 dir;
    u32 pad18;
};

struct Ball {
    struct Vec3 c;
    int r;
};







struct Pt { u16 x; u16 y; };

struct V { int x; int y; int z; };

typedef struct { u32 w[8]; } BgTemplate;

extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct HeapTask *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020120F4(const struct Ctx *p);
extern void func_0201DD78(u32 a, u32 b, u32 c);
extern void func_0201DD68(void);
extern void func_02040618(u32 a, u32 b, u32 c);
extern int func_0203CD98(void);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_020056A0(void (*cb)(void *, void *), void *arg, int pri);
extern void func_02030EAC(struct Node *n);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(s32 handle);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
extern void func_020061E4(u32);
extern u8 func_020355C4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0204A6C8(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern struct Actor *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B92C(struct Actor *p, u32 v);
extern void CLACT_StopActorAnim(struct Actor *a);
extern u32 func_021B62E0(ButtonManRequest *r, int heap);
extern void func_021B6520(u8 *p, u32 v);
extern void func_021B639C(unsigned char *);
extern void func_0204B3B4(struct Actor *p);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_021B63D0(void *buttons);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *a);
extern u16 CLACT_GetActorAnimSeq(struct Actor *p);
extern void func_0204B878(struct Actor *p, u16 value);
extern void CLACT_StartActorAnim(struct Actor *a);
extern int func_021B6448(unsigned char *);
int func_021B6498(unsigned char *p);
extern void func_0204B404(struct Actor *p, const struct Vec2 *delta, unsigned int which);
extern void func_0204B3DC(struct Actor *p, u32 v);
extern void func_0204B84C(int obj, int v);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern unsigned int func_0203630C(void);
extern void VEC_Subtract(const struct Vec3 *a, const struct Vec3 *b, struct Vec3 *d);
extern int VEC_Mag(const struct Vec3 *v);
extern void VEC_Normalize(const struct Vec3 *v, struct Vec3 *d);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *d);
extern void func_0204B9A0(struct Actor *a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02166C7C(void *a, u32 b);
extern int func_02166CD0(void *a, u32 msg);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void BUTTON_MAN_InitSphere(struct Ball *dst, struct Vec *src, unsigned radius);
extern void BUTTON_MAN_InitSegment(char *p, struct S12 *q, struct S12 *r, u32 v);
extern u32 BUTTON_MAN_SegmentSphereTest(struct Seg *seg, struct Ball *b, struct Out *out);
extern void CLACT_SetActorScale(struct Actor *dst, struct Pair *src);
void func_020419E4(void);
int func_021B95A0(void *taskArg, void *unused, TownMapArgs *args);
int func_021B9858(void *taskArg, int unusedA, int unusedB, TownMapWork *work);
int func_021B98F8(int taskArg, int unusedA, int unusedB, TownMapWork *work);
void func_021B991C(TownMapProc *proc, TownMapWork *work, TownMapStepFunc step);
void func_021B9938(TownMapProc *proc);
void func_021B9944(TownMapProc *proc);
int func_021B9958(TownMapProc *proc);
void func_021B995C(TownMapProc *proc, TownMapStepFunc step);
void func_021B9964(TownMapProc *proc);
void func_021B996C(TownMapProc *proc, int *state);
void func_021B99AC(TownMapProc *proc, int *state);
int func_021B99E8(TownMapProc *proc,int *unusedState,TownMapWork *work);
void func_021B9E38(TownMapButtonBar *bar, u32 unusedMode, u32 clactSet, u8 bgLayer, u8 palette, u8 tileBase, u32 ctx, u16 heapId);
void func_021B9F20(TownMapButtonBar *bar);
void func_021B9F50(TownMapButtonBar *bar, void *scroll);
int func_021BA028(TownMapButtonBar *bar);
int func_021BA040(TownMapButtonBar *bar);
void func_021BA04C(TownMapCursor *cursor, void *arrowSprite, void *hoverSprite, int heapId);
void func_021BA0D8(TownMapCursor *cursor);
void func_021BA0E4(TownMapCursor *cursor, TownMapMap *map);
void func_021BA3BC(TownMapCursor *cursor, TownMapPoint *pos);
void func_021BA3CC(TownMapCursor *cursor, const TownMapPoint *pos);
int func_021BA3E8(TownMapCursor *cursor);
int func_021BA3EC(TownMapCursor *cursor);
void func_021BA3F4(TownMapCursor *cursor, TownMapTown *town, const TownMapPoint *scroll);
void func_021BA450(TownMapCursor *cursor, const TownMapPoint *scroll);
TownMapTown *func_021BA488(TownMapCursor *cursor);
void func_021BA48C(TownMapCursor *cursor, int snapToTown);
void func_021BA490(TownMapMap *map, u16 townId, u16 townSubId, int mapInfo, TownMapGfx *gfx, u32 gameData, u16 heapId, int pickMode);
void func_021BA570(TownMapMap *map);
void func_021BA5AC(TownMapMap *map);
void func_021BA5B0(TownMapMap *map, u32 scale, const TownMapPoint *center);
void func_021BA638(TownMapMap *map, const TownMapPoint *scroll);
void func_021BA69C(TownMapMap *map, TownMapPoint *scroll);
void func_021BA6A8(TownMapMap *map, const TownMapPoint *delta);
TownMapTown *func_021BA6C8(TownMapMap *map, TownMapCursor *cursor);
TownMapTown *func_021BA710(TownMapMap *map, TownMapCursor *cursor);
int func_021BA774(TownMapTown *town, int field);
void func_021BA7A4(TownMapMap *map, TownMapTown *selected);
void func_021BA7D4(TownMapMap *map);
TownMapTown *func_021BA7F8(TownMapMap *map, u32 townId, int townSubId);
int func_021BA834(TownMapTown *town);
void func_021BA86C(TownMapTown *town, int mapInfo, int townIndex, int clactSet, int plttRes, int cellRes, int charRes, void *gameData, u16 heapId, int pickMode);
void func_021BAA14(TownMapTown *town);
void func_021BAA30(TownMapTown *town, int shown);
u32 func_021BAA90(TownMapTown *town, const TownMapPoint *pos, const TownMapPoint *scroll);
int func_021BACB0(TownMapTown *town, const TownMapPoint *pos, const TownMapPoint *scroll, u32 *distSq);
void func_021BAD10(TownMapTown *town, int scale, const TownMapPoint *center);
void func_021BAD84(TownMapTown *town, const TownMapPoint *scroll);
void func_021BADBC(TownMapTown *town, int frame);
void func_021BADF4(TownMapTown *town);
void func_021BAE44(TownMapTown *town);
void func_021BAE9C(TownMapMarker *marker, TownMapTown *town, int clactSet, int plttRes, int cellRes, int charRes, u16 heapId);
void func_021BAF24(TownMapMarker *marker);
void func_021BAF3C(TownMapMarker *marker, const TownMapPoint *scroll);
void func_021BAF74(TownMapScroll *scroll, u32 bgIdA, u32 bgIdB, int heapId);
void func_021BAF9C(TownMapScroll *scroll);
void func_021BAFA8(TownMapScroll *scroll, TownMapMap *map);
void func_021BB0B4(TownMapScroll *scroll, int scaleTo, const TownMapPoint *from, const TownMapPoint *to);
int func_021BB0DC(TownMapScroll *scroll);
int func_021BB0E0(TownMapScroll *scroll);
void func_021BB0E4(TownMapScroll *scroll, const TownMapPoint *pos);
void func_021BB190(TownMapScroll *scroll, TownMapPoint *out);
void func_021BB19C(TownMapScroll *scroll, const TownMapPoint *delta);
void func_021BB1BC(TownMapSelection *sel, int bgId, void *font, struct MsgBank *nameMsg, struct MsgBank *detailMsg, u16 heapId);
void func_021BB204(TownMapSelection *sel);
void func_021BB220(TownMapSelection *sel, TownMapTown *town);
void func_021BB3D0(TownMapSelection *sel);
void func_021BB3E8(TownMapTextBox *box, int bgId, void *font, void *msg, u8 x, u8 y, u8 width, u8 height, u16 heapId);
void func_021BB42C(TownMapTextBox *box);
void func_021BB448(TownMapTextBox *box, u32 msgId, int x, int y);
void func_021BB49C(TownMapTextBox *box);
void func_021BB4B4(TownMapLabel *label, int bgId, void *font, void *msg, struct ClactActor *marker, u16 heapId);
void func_021BB534(TownMapLabel *label);
void func_021BB548(TownMapLabel *label);
void func_021BB5AC(TownMapLabel *label, TownMapTown *town);
void func_021BB5B4(TownMapLabel *label, u32 visible);
void func_021BB5D4(TownMapTouch *touch, int heapId);
void func_021BB5E0(TownMapTouch *touch);
void func_021BB5EC(TownMapTouch *touch);
int func_021BB6AC(TownMapTouch *touch, TownMapVec *delta, u32 *dragState);
void func_021BB6DC(TownMapTouch *touch);
void func_021BB6E4(void *task, void *arg);
TownMapGfx *func_021BB6E8(u16 heapId);
void func_021BB738(TownMapGfx *gfx);
void func_021BB758(TownMapGfx *gfx);
u8 func_021BB764(TownMapGfx *gfx, u32 i);
unsigned int func_021BB778(TownMapGfx *gfx, int n);
struct ClactActor *func_021BB784(TownMapGfx *gfx, int n);
void func_021BB790(TownMapGfx *gfx, int *charId, int *cellId, int *palId);
void func_021BB7BC(void);
void func_021BB80C(void *task, void *gfx);
void func_021BB820(TownMapGfx *gfx, u16 heapId);
void func_021BB968(TownMapGfx *gfx);
void func_021BB9B0(TownMapGfx *gfx);
void func_021BB9B8(TownMapSprites *sprites, const struct DispVram *banks, u16 heapId);
void func_021BBAB4(TownMapSprites *sprites);
void func_021BBAFC(int arg);
void func_021BBB04(TownMapSprites *sprites);
struct ClactActor *func_021BBB0C(TownMapSprites *sprites, int n);
unsigned int func_021BBB14(TownMapSprites *sprites, int n);
int func_021BBB1C(TownMapSprites *sprites, int i);
int func_021BBB24(int a);
void func_021BBB34(void *p);
unsigned short func_021BBB3C(char *p, int a, int b);
extern char ov067_id[];
extern const TownMapPoint d_021BBB78;
extern ButtonTable d_021BBB8C;
extern char d_021BBD60[];
extern void func_02041EE4(u32 bgId, u32 which, u32 value);
extern void func_02041FB0(u32 bgId, u32 which, u16 value);
extern void func_02041F6C(u32 bgId, u32 which, u32 value);
extern struct BmpWin *func_020450F0(u32 bgId, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 baseTile);
extern struct StrBuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct StrBuf *text);
extern u32 func_020452E8(struct BmpWin *win);
extern struct Bitmap *func_02045770(struct BmpWin *win);
extern void func_02043B5C(struct Bitmap *bitmap, u8 value);
extern u32 func_02013E4C(u32 townId);
extern void func_02045CAC(struct MsgBank *msg, u32 index, struct StrBuf *dest);
extern u8 func_02045738(struct BmpWin *win);
extern u32 func_0201D304(struct StrBuf *text, void *font, u32 spacing);
extern void func_0201C7A4(struct Bitmap *bitmap, s16 x, s16 y, struct StrBuf *text, void *font);
extern void func_02045334(struct BmpWin *win);
extern void func_02045374(struct BmpWin *win);
extern u8 func_02045730(struct BmpWin *win);
extern void func_02041B6C(u32 bgBit);
extern void func_020456F8(struct BmpWin *win);
extern void func_021BA5B0(TownMapMap *map, u32 scale, const TownMapPoint *pos);
extern int func_021BA774(TownMapTown *town, int field);
extern int func_021BA834(TownMapTown *town);


int func_021B95A0(void *taskArg, void *unused, TownMapArgs *args)
{
    TownMapPoint pt;
    TownMapPoint org;
    TownMapWork *work;
    u32 ctx;
    int pickMode;
    TownMapTown *town;

    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x44, 0x60000);
    work = func_0203159C(taskArg, 0x144, 0x44);
    func_02082BCC(work, 0, 0x144);
    work->args = args;
    pickMode = work->args->mode == 2;
    work->fontSystem = func_0201D7EC(0x17, 0, 0, 0, 0x44);
    work->nameMsg = func_02045B38(0, 2, 0x59, 0x44);
    work->detailMsg = func_02045B38(0, 2, 0xb9, 0x44);
    work->gfx = func_021BB6E8(0x44);
    work->mapInfo = func_021BBB24(0x44);
    func_021B991C(&work->proc, work, (TownMapStepFunc)func_021B996C);
    ctx = (u32)func_020120F4((const struct Ctx *)work->args->gameCtx);
    if (work->args->mode != 1) {
        func_021BB3E8(&work->panel, func_021BB764(work->gfx, 1), work->fontSystem, work->detailMsg, 0, 0x15, 0x18, 3, 0x44);
        func_0201DD78(0xf, 1, 0);
        func_021BB448(&work->panel, 0, 0x10, 0);
        func_0201DD68();
    }
    func_021B9E38(&work->buttonBar, work->args->mode, func_021BB778(work->gfx, 0), func_021BB764(work->gfx, 0), 0xf, 8, ctx, 0x44);
    func_021BB4B4(&work->label, func_021BB764(work->gfx, 1), work->fontSystem, work->nameMsg, func_021BB784(work->gfx, 0), 0x44);
    func_02040618(func_021BB764(work->gfx, 1), 3, -4);
    func_021BA490(&work->map, args->townId, args->townSubId, work->mapInfo, work->gfx, (u32)func_020120F4((const struct Ctx *)work->args->gameCtx), (u16)0x44, pickMode);
    func_021BA04C(&work->cursor, (void *)func_021BB784(work->gfx, 1), (void *)func_021BB784(work->gfx, 2), 0x44);
    town = func_021BA7F8(&work->map, args->townId, args->townSubId);
    if (town != 0) {
        pt.x = func_021BA774(town, 4);
        pt.y = func_021BA774(town, 5);
    } else {
        pt.x = 0x80;
        pt.y = 0x60;
    }
    func_021BA3CC(&work->cursor, &pt);
    func_021BAF74(&work->scroll, func_021BB764(work->gfx, 3), func_021BB764(work->gfx, 2), 0x44);
    func_021BB1BC(&work->selection, func_021BB764(work->gfx, 5), work->fontSystem, work->nameMsg, work->detailMsg, 0x44);
    func_021BB5D4(&work->touch, 0x44);
    town = func_021BA6C8(&work->map, &work->cursor);
    if (town != 0) {
        func_021BB5AC(&work->label, town);
        func_021BB220(&work->selection, town);
        work->hoverTown = town;
        func_021BA69C(&work->map, &org);
        func_021BA3F4(&work->cursor, town, &org);
    }
    if (func_0203CD98()) {
        func_0203D34C(1, 0x44);
    }
    work->vblankTask = func_020056A0(func_021BB6E4, work, 0);
    return 1;
}


int func_021B9858(void *taskArg, int unusedA, int unusedB, TownMapWork *work)
{
    func_02030EAC((struct Node *)work->vblankTask);
    func_021BB5E0(&work->touch);
    func_021BB204(&work->selection);
    func_021BAF9C(&work->scroll);
    func_021BA570(&work->map);
    func_021BA0D8(&work->cursor);
    func_021BB534(&work->label);
    if (work->args->mode != 1) {
        func_021BB42C(&work->panel);
    }
    func_021B9F20(&work->buttonBar);
    func_021B9938(&work->proc);
    func_021BBB34((void *)work->mapInfo);
    func_021BB738(work->gfx);
    func_02045C04((struct Rec *)work->detailMsg);
    func_02045C04((struct Rec *)work->nameMsg);
    func_0201D83C(work->fontSystem);
    func_020315D4(taskArg);
    func_020306F0(0x44);
    func_02034A5C((u32)ov067_id);
    return 1;
}


int func_021B98F8(int taskArg, int unusedA, int unusedB, TownMapWork *work) {
    func_021B9944(&work->proc);
    func_021BB758(work->gfx);
    return func_021B9958(&work->proc) != 0;
}


void func_021B991C(TownMapProc *proc, TownMapWork *work, TownMapStepFunc step)
{
    func_02082BCC(proc, 0, 16);
    proc->arg = work;
    func_021B995C(proc, step);
}


void func_021B9938(TownMapProc *proc)
{
    func_02082BCC(proc, 0, 0x10);
}


void func_021B9944(TownMapProc *proc) {
    if (proc->finished == 0) proc->call(proc, &proc->stepState, proc->arg);
}


int func_021B9958(TownMapProc *proc)
{
    return proc->finished;
}


void func_021B995C(TownMapProc *proc, TownMapStepFunc step)
{
    proc->call = step;
    proc->stepState = 0;
}


void func_021B9964(TownMapProc *proc)
{
    proc->finished = 1;
}


void func_021B996C(TownMapProc *proc, int *state)
{
    switch (state[0]) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        state[0] = 1;
        break;
    case 1:
        if (func_0204E804() == 0) {
            state[0] = 2;
        }
        break;
    case 2:
        func_021B995C(proc, (TownMapStepFunc)func_021B99E8);
        break;
    }
}


/*
 * note: trailing two-byte alignment padding.
 */
void func_021B99AC(TownMapProc *proc, int *state) {
    switch (*state) {
    case 0: func_0204E720(3,0,16,0); *state = 1; break;
    case 1: if (func_0204E804() == 0) *state = 2; break;
    case 2: func_021B9964(proc); break;
    }
}


int func_021B99E8(TownMapProc *proc,int *unusedState,TownMapWork *work)
{
    u8 moved;
    TownMapTown *hovered;
    int keys;
    TownMapTown *under;
    int pressed;
    moved=0;
    if (func_021BA040(&work->buttonBar) == 0) {
        if (work->zooming!=0 && func_021BB0E0(&work->scroll)==0) {
            TownMapVec touchDelta;
            TownMapPoint pos,delta={0,0};
            u32 touchOut;
            TownMapPoint scrollBefore,scrollAfter;
            func_021BA3BC(&work->cursor,&pos);
            keys=func_021BA3EC(&work->cursor);
            if (pos.y<16 && (keys&0x40)) { delta.y-=4; moved=1; }
            if (pos.y<=168 && pos.y>136 && (keys&0x80)) { delta.y+=4; moved=1; }
            if (pos.x<16 && (keys&0x20)) { delta.x-=4; moved=1; }
            if (pos.x>240 && (keys&0x10)) { delta.x+=4; moved=1; }
            if (func_021BB0E0(&work->scroll)==0 && func_021BB6AC(&work->touch,&touchDelta,&touchOut)) {
                delta.x=-(int)(((s64)touchDelta.x*4096+2048)>>12)>>12;
                delta.y=-(int)(((s64)touchDelta.y*4096+2048)>>12)>>12;
                func_021BB6DC(&work->touch); moved=1;
            }
            if (moved != 0) {
                func_021BA69C(&work->map,&scrollBefore);
                func_021BB19C(&work->scroll,&delta);
                delta.x*=-1; delta.y*=-1;
                func_021BA6A8(&work->map,&delta);
                func_021BA69C(&work->map,&scrollAfter);
                func_021BA450(&work->cursor,&scrollAfter);
            }
        }
        if (moved==0 && func_021BB0E0(&work->scroll)==0) {
            if (work->args->mode==0 || work->args->mode==2) {
                hovered=func_021BA488(&work->cursor);
                under=func_021BA6C8(&work->map, &work->cursor);
                if (hovered!=0 && hovered==under && func_021BA3E8(&work->cursor)!=0 && func_021BA774(hovered,12)!=0) {
                    work->args->result=2;
                    work->args->townId=func_021BA774(hovered,0);
                    work->args->pickedX=func_021BA774(hovered,13);
                    work->args->pickedY=func_021BA774(hovered,14);
                    func_020061E4(0x54c); func_021B995C(proc,(TownMapStepFunc)func_021B99AC);
                }
            }
            if (func_020355C4()==0) pressed=1; else pressed=func_021BA3E8(&work->cursor);
            if (pressed != 0) {
                hovered=func_021BA6C8(&work->map, &work->cursor);
                if (hovered!=work->hoverTown && hovered!=0) {
                    TownMapPoint scrollNow;
                    func_020061E4(0x548);
                    func_021BB220(&work->selection, hovered); func_021BA7A4(&work->map,hovered);
                    work->hoverTown=hovered; func_021BA69C(&work->map,&scrollNow);
                    func_021BA3F4(&work->cursor,hovered,&scrollNow);
                    if (work->zooming==0) func_021BB5AC(&work->label,hovered);
                } else if (hovered==0 && work->hoverTown!=0) {
                    func_021BB3D0(&work->selection); func_021BB5B4(&work->label,0); func_021BA7D4(&work->map);
                    func_021BA3F4(&work->cursor,0,0); work->hoverTown=0;
                }
            }
        }
        if (work->zooming!=0) func_021BB5B4(&work->label,0);
        func_021BA48C(&work->cursor,moved ? 0 : 1);
    }
    func_021B9F50(&work->buttonBar,&work->scroll);
    if (func_021BB0E0(&work->scroll)==0) func_021BA0E4(&work->cursor,&work->map);
    func_021BA5AC(&work->map); func_021BAFA8(&work->scroll,&work->map);
    func_021BB548(&work->label); func_021BB5EC(&work->touch);
    switch (func_021BA028(&work->buttonBar)) {
    case 0:
        work->args->result=1; func_021B995C(proc,(TownMapStepFunc)func_021B99AC); break;
    case 1:
        work->args->result=0; func_021B995C(proc,(TownMapStepFunc)func_021B99AC); break;
    case 7:
        if (work->zooming==0 && func_021BB0E0(&work->scroll)==0) {
            TownMapPoint cursorPos;
            func_021BA3BC(&work->cursor,&cursorPos);
            func_021BB0B4(&work->scroll,8192,&d_021BBB78,&cursorPos);
            func_020061E4(0x648);
            if (work->hoverTown!=0) {
                func_021BB3D0(&work->selection); func_021BB5B4(&work->label,0); func_021BA7D4(&work->map);
                func_021BA3F4(&work->cursor,0,0); work->hoverTown=0;
            }
            work->zooming=1;
        } else if (work->zooming==1 && func_021BB0E0(&work->scroll)==0) {
            TownMapPoint zoomCenter;
            func_021BB190(&work->scroll,&zoomCenter); zoomCenter.x+=128; zoomCenter.y+=96;
            func_021BB0B4(&work->scroll,4096,&zoomCenter,&d_021BBB78);
            func_020061E4(0x649);
            if (work->hoverTown!=0) {
                func_021BB3D0(&work->selection); func_021BB5B4(&work->label,0); func_021BA7D4(&work->map);
                func_021BA3F4(&work->cursor,0,0); work->hoverTown=0;
            }
            work->zooming=0;
        }
        break;
    }
    return func_021BB0DC(&work->scroll);
}


void func_021B9E38(TownMapButtonBar *bar, u32 unusedMode, u32 clactSet, u8 bgLayer, u8 palette, u8 tileBase, u32 ctx, u16 heapId)
{
    ButtonManRequest req;
    ButtonTable table;
    SpriteInit init;
    void *archive;

    func_02082BCC(bar, 0, 0x20);
    bar->ctx = ctx;
    archive = func_020490F4(0x55, heapId);
    bar->charRes = func_0204AC18(archive, 2, 0, 0, 0, 4, heapId);
    bar->plttRes = (s32)func_0204A6C8(archive, 8, 0, 0, (u32)heapId);
    bar->cellRes = func_0204AF28(archive, 0xc, 0x13, heapId);
    func_02049238(archive);
    func_02082BCC(&init, 0, 8);
    init.x = 0xa8;
    init.y = 0xa8;
    init.animSeq = 7;
    bar->sprite = func_0204B294((void *)clactSet, bar->plttRes, bar->charRes, bar->cellRes, &init, 0, heapId);
    func_0204B92C((struct Actor *)bar->sprite, 1);
    CLACT_StopActorAnim((struct Actor *)bar->sprite);
    table = d_021BBB8C;
    func_02082BCC(&req, 0, 0x20);
    req.table = (u8 *)&table;
    req.tableCount = 2;
    req.clactSet = clactSet;
    req.bgLayer = bgLayer;
    req.palette = palette;
    req.tileBase = tileBase + 4;
    req.kind = 2;
    bar->buttonMan = func_021B62E0(&req, heapId);
    func_021B6520((u8 *)bar->buttonMan, 10);
}


void func_021B9F20(TownMapButtonBar *bar)
{
    func_021B639C((unsigned char *)bar->buttonMan);
    func_0204B3B4((struct Actor *)bar->sprite);
    func_0204AFD8(bar->cellRes);
    func_0204A8D4(bar->plttRes);
    func_0204ADA4(bar->charRes);
    func_02082BCC(bar, 0, 32);
}


/*
 * EXACT*: the unlabelled follower at 0x021BA028 (push {r4,lr}; getter
 * over func_021B6448) is outside the handed 216-byte extent.
 * Lever: each sprite-animation pick written as if/else of two calls
 * (tail-merged, h load hoisted over the bne), and func_0204B878's second
 * parameter int here (no truncation before the blx).
 */
void func_021B9F50(TownMapButtonBar *bar, void *scroll)
{
    u32 touchX;
    u32 touchY;
    ScreenPos spritePos;
    int hit;

    func_021B63D0((void *)bar->buttonMan);
    bar->pressed = -1;
    switch (bar->animState) {
    case 0:
        hit = 0;
        func_0204B454((void *)bar->sprite, (struct PtS *)&spritePos, 0);
        if (func_02035D20(&touchX, &touchY)) {
            if (touchX - spritePos.x <= 0x18 && touchY - spritePos.y <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        } else if (func_020362DC() & 4) {
            func_020355D8(hit);
            hit = 1;
        }
        if (hit && func_0204B98C((void *)bar->sprite) == 0 && func_021BB0E0(scroll) == 0) {
            if (CLACT_GetActorAnimSeq((void *)bar->sprite) == 7)
                func_0204B878((void *)bar->sprite, 9);
            else
                func_0204B878((void *)bar->sprite, 10);
            CLACT_StartActorAnim((void *)bar->sprite);
            bar->pressed = 7;
            bar->animState = 1;
        }
        break;
    case 1:
        if (func_0204B98C((void *)bar->sprite) == 0) {
            if (CLACT_GetActorAnimSeq((void *)bar->sprite) == 9)
                func_0204B878((void *)bar->sprite, 8);
            else
                func_0204B878((void *)bar->sprite, 7);
            bar->animState = 0;
        }
        break;
    }
}


int func_021BA028(TownMapButtonBar *bar) {
    int pressed;
    pressed = func_021B6448((unsigned char *)bar->buttonMan);
    if (pressed == -1) pressed = bar->pressed;
    return pressed;
}


int func_021BA040(TownMapButtonBar *bar)
{
    return func_021B6498((unsigned char *)bar->buttonMan);
}


void func_021BA04C(TownMapCursor *cursor, void *arrowSprite, void *hoverSprite, int heapId)
{
    int zero = 0;
    int one;

    func_02082BCC(cursor, 0, 0x18);
    cursor->arrowSprite = arrowSprite;
    cursor->hoverSprite = hoverSprite;
    cursor->x = 0x80;
    cursor->y = 0x60;
    func_0204B404(arrowSprite, (const struct Vec2 *)(&cursor->x), 0);
    func_0204B404(cursor->hoverSprite, (const struct Vec2 *)(&cursor->x), 0);
    func_0204B3DC(cursor->arrowSprite, 1);
    one = 1;
    func_0204B3DC(cursor->hoverSprite, 0);
    func_0204B84C((int)cursor->arrowSprite, 0);
    CLACT_SetActorDrawPriority(cursor->arrowSprite, 0);
    func_0204B84C((int)cursor->hoverSprite, 2);
    CLACT_SetActorDrawPriority(cursor->hoverSprite, 3);
    func_0204B92C(cursor->hoverSprite, 1);
    if (func_020355C4() == 0) {
        func_0204B3DC(cursor->arrowSprite, one);
    } else {
        func_0204B3DC(cursor->arrowSprite, zero);
    }
}


void func_021BA0D8(TownMapCursor *cursor)
{
    func_02082BCC(cursor, 0, 0x18);
}


void func_021BA0E4(TownMapCursor *cursor, TownMapMap *map)
{
    struct Vec3 keyDir = { 0, 0, 0 };
    struct Vec3 pull = { 0, 0, 0 };
    struct Vec3 townPos;
    struct Vec3 cursorPos;
    TownMapPoint scroll;
    u32 touchX;
    u32 touchY;
    int moved;
    TownMapTown *town;
    int stepX;
    int stepY;
    s16 clamped;

    moved = 0;
    cursor->pressed = 0;
    if (func_0203630C() & 0x40) {
        func_020355D8(0);
        keyDir.y -= 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x80) {
        func_020355D8(0);
        keyDir.y += 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x20) {
        func_020355D8(0);
        keyDir.x -= 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x10) {
        func_020355D8(0);
        keyDir.x += 0x1000;
        moved = 1;
    }
    if (cursor->snapToTown != 0 && func_020355C4() == 0 && (town = func_021BA710(map, cursor)) != 0) {
        func_021BA69C(map, &scroll);
        townPos.x = FX_F32_TO_FX32(scroll.x + func_021BA774(town, 4));
        townPos.y = FX_F32_TO_FX32(scroll.y + func_021BA774(town, 5));
        townPos.z = 0;
        cursorPos.x = FX_F32_TO_FX32(cursor->x);
        cursorPos.y = FX_F32_TO_FX32(cursor->y);
        cursorPos.z = 0;
        VEC_Subtract(&townPos, &cursorPos, &pull);
        if (VEC_Mag(&pull) > 0x1000) {
            VEC_Normalize(&pull, &pull);
            func_020520A4(&pull, 0x1000, &pull);
        }
        moved = 1;
    }
    if (moved) {
        VEC_Normalize(&keyDir, &keyDir);
        stepX = pull.x + keyDir.x * 3;
        stepY = pull.y + keyDir.y * 3;
        if (stepX > 0 && stepX < 0x1000)
            stepX = 0x1000;
        else if (stepX > -0x1000 && stepX < 0)
            stepX = -0x1000;
        if (stepY > 0 && stepY < 0x1000)
            stepY = 0x1000;
        else if (stepY > -0x1000 && stepY < 0)
            stepY = -0x1000;
        cursor->x += (s16)(stepX >> 12);
        cursor->y += (s16)(stepY >> 12);
        clamped = cursor->x;
        if (clamped > 0xf8)
            clamped = 0xf8;
        else if (clamped < 0)
            clamped = 0;
        cursor->x = clamped;
        clamped = cursor->y;
        if (clamped > 0xa8)
            clamped = 0xa8;
        else if (clamped < 8)
            clamped = 8;
        cursor->y = clamped;
        func_0204B404((struct Actor *)cursor->arrowSprite, (const struct Vec2 *)(&cursor->x), 0);
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        cursor->pressed = 1;
    }
    if (func_02035D20(&touchX, &touchY)) {
        func_020355D8(1);
        if (touchX <= 0xf8 && touchY - 8 <= 0xa0) {
            cursor->pressed = 1;
            cursor->x = touchX;
            cursor->y = touchY;
        }
    }
    if (func_020355C4() == 0)
        func_0204B3DC((struct Actor *)cursor->arrowSprite, 1);
    else
        func_0204B3DC((struct Actor *)cursor->arrowSprite, 0);
}


void func_021BA3BC(TownMapCursor *cursor, TownMapPoint *pos) {
    pos->x = cursor->x;
    pos->y = cursor->y;
}


void func_021BA3CC(TownMapCursor *cursor, const TownMapPoint *pos) {
    cursor->x = pos->x;
    cursor->y = pos->y;
    func_0204B404(cursor->arrowSprite, (const struct Vec2 *)&cursor->x, 0);
}


int func_021BA3E8(TownMapCursor *cursor)
{
    return cursor->pressed;
}


int func_021BA3EC(TownMapCursor *cursor)
{
    return func_0203630C();
}


void func_021BA3F4(TownMapCursor *cursor, TownMapTown *town, const TownMapPoint *scroll)
{
    ScreenPos pos;

    if (town == 0) {
        func_0204B3DC((struct Actor *)cursor->hoverSprite, 0);
        cursor->hoverTown = 0;
        return;
    }
    if (cursor->hoverTown != town) {
        pos.x = scroll->x + func_021BA774(town, 4);
        pos.y = scroll->y + func_021BA774(town, 5);
        func_0204B404((struct Actor *)cursor->hoverSprite, (const struct Vec2 *)(&pos), 0);
        func_0204B3DC((struct Actor *)cursor->hoverSprite, 1);
        func_0204B9A0((struct Actor *)cursor->hoverSprite);
        cursor->hoverTown = town;
    }
}


void func_021BA450(TownMapCursor *cursor, const TownMapPoint *scroll)
{
    ScreenPos pos;

    if (cursor->hoverTown) {
        pos.x = scroll->x + func_021BA774(cursor->hoverTown, 4);
        pos.y = scroll->y + func_021BA774(cursor->hoverTown, 5);
        func_0204B404((struct Actor *)cursor->hoverSprite, (const struct Vec2 *)(&pos), 0);
    }
}


TownMapTown *func_021BA488(TownMapCursor *cursor)
{
    return cursor->hoverTown;
}


void func_021BA48C(TownMapCursor *cursor, int snapToTown)
{
    cursor->snapToTown = snapToTown;
}


void func_021BA490(TownMapMap *map, u16 townId, u16 townSubId, int mapInfo, TownMapGfx *gfx, u32 gameData, u16 heapId, int pickMode)
{
    u32 i;
    u32 clactSet;
    int markerBank0, markerBank1, markerBank2;
    int linkBank0, linkBank1, linkBank2;
    TownMapTown *startTown;

    i = 0;
    clactSet = func_021BB778(gfx, 0);
    func_02082BCC(map, 0, 0x28);
    map->townCount = 0x3d;
    map->gameData = (void *)gameData;
    map->towns = func_02030734(heapId, map->townCount * 0x44, 0, d_021BBD60, 0x8C5);
    func_02082BCC(map->towns, 0, map->townCount * 0x44);
    func_021BB790(gfx, &markerBank0, &markerBank1, &markerBank2);
    for (; i < map->townCount; i++) {
        func_021BA86C(&map->towns[i], mapInfo, i, clactSet, markerBank0, markerBank1, markerBank2, (void *)gameData, heapId, pickMode);
    }
    startTown = func_021BA7F8(map, townId, townSubId);
    func_021BB790(gfx, &linkBank0, &linkBank1, &linkBank2);
    func_021BAE9C(&map->marker, startTown, clactSet, linkBank0, linkBank1, linkBank2, heapId);
    map->minScrollY = 0;
    map->minScrollX = 0;
    map->maxScrollX = 0;
    map->maxScrollY = 0;
    func_021BA7D4(map);
}


void func_021BA570(TownMapMap *map)
{
    u32 i;

    func_021BAF24(&map->marker);
    for (i = 0; i < map->townCount; i++)
        func_021BAA14(&map->towns[i]);
    func_020307B0(map->towns);
    func_02082BCC(map, 0, 40);
}


/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void func_021BA5AC(TownMapMap *map)
{
}


void func_021BA5B0(TownMapMap *map, u32 scale, const TownMapPoint *center)
{
    u32 i;
    TownMapPoint negated;

    if (scale == 0x1000) {
        map->minScrollY = 0;
        map->minScrollX = 0;
        map->maxScrollX = 0;
        map->maxScrollY = 0;
    } else {
        map->minScrollY = -0x48;
        map->minScrollX = -0x80;
        map->maxScrollX = 0x80;
        map->maxScrollY = 0x60;
    }
    negated.x = -center->x;
    negated.y = -center->y;
    func_021BA638(map, &negated);
    for (i = 0; i < map->townCount; i++) {
        func_021BAD10(&map->towns[i], scale, &d_021BBB78);
        func_021BAD84(&map->towns[i], (TownMapPoint *)&map->scrollX);
    }
    func_021BAF3C(&map->marker, (const TownMapPoint *)&map->scrollX);
}


void func_021BA638(TownMapMap *map, const TownMapPoint *scroll)
{
    u32 i;
    int x;
    int y;

    x = map->maxScrollX;
    if (scroll->x <= x) {
        x = map->minScrollX;
        if (scroll->x >= x) {
            x = scroll->x;
        }
    }
    map->scrollX = x;
    y = map->maxScrollY;
    if (scroll->y <= y) {
        y = map->minScrollY;
        if (scroll->y >= y) {
            y = scroll->y;
        }
    }
    map->scrollY = y;
    for (i = 0; i < map->townCount; i++) {
        func_021BAD84(&map->towns[i], (TownMapPoint *)&map->scrollX);
    }
    func_021BAF3C(&map->marker, (const TownMapPoint *)&map->scrollX);
}


/*
 * note:     listing extent (12) runs 2 bytes past the compiled function (10);
 *           trailing alignment padding, no byte difference.  A two-word copy
 *           at a nonzero offset is a struct assignment (hoists both loads and
 *           allocates r2/r0); two locals let the stores reorder and diff.
 */
void func_021BA69C(TownMapMap *map, TownMapPoint *scroll)
{
    *scroll = *(TownMapPoint *)&map->scrollX;
}


void func_021BA6A8(TownMapMap *map, const TownMapPoint *delta)
{
    map->scrollX = delta->x + map->scrollX;
    map->scrollY = map->scrollY + delta->y;
    func_021BA638(map, (TownMapPoint *)&map->scrollX);
}


TownMapTown *func_021BA6C8(TownMapMap *map, TownMapCursor *cursor)
{
    TownMapPoint pos;
    u32 i;

    func_021BA3BC(cursor, &pos);
    for (i = 0; i < map->townCount; i++) {
        if (func_021BAA90(&map->towns[i], &pos, (TownMapPoint *)&map->scrollX) != 0) {
            return &map->towns[i];
        }
    }
    return 0;
}


TownMapTown *func_021BA710(TownMapMap *map, TownMapCursor *cursor)
{
    TownMapPoint pos;
    u32 i;
    u32 bestDist;
    u32 dist;
    int bestIndex;

    func_021BA3BC(cursor, &pos);
    bestIndex = -1;
    bestDist = -1;
    for (i = 0; i < map->townCount; i++) {
        if (func_021BACB0(&map->towns[i], &pos, (TownMapPoint *)&map->scrollX, &dist) != 0 && bestDist > dist) {
            bestIndex = i;
            bestDist = dist;
        }
    }
    if (bestIndex == -1) {
        return 0;
    }
    return &map->towns[bestIndex];
}


/*
 * call width: r1 is explicitly narrowed before the call, so extern takes u16.
 */
int func_021BA774(TownMapTown *town, int field) {
 if (field>=2 && field<=10) return town->values[field-2];
 if (field==12) return town->selectable;
 return func_021BBB3C(town->info,(u16)(town->index),field);
}


void func_021BA7A4(TownMapMap *map, TownMapTown *selected)
{
    u32 i;
    TownMapTown *town;

    for (i = 0; i < map->townCount; i++) {
        town = &map->towns[i];
        if (town == selected)
            func_021BADF4(town);
        else
            func_021BAE44(town);
    }
}


void func_021BA7D4(TownMapMap *map)
{
    u32 i;

    for (i = 0; i < map->townCount; i++)
        func_021BAE44(&map->towns[i]);
}


TownMapTown *func_021BA7F8(TownMapMap *map, u32 townId, int townSubId)
{
    u32 i;
    u32 zoneId;
    TownMapTown *town;

    zoneId = func_02166C7C(map->gameData, townId);
    for (i = 0; i < map->townCount; i++) {
        town = &map->towns[i];
        if (zoneId == func_021BA774(town, 0))
            return town;
    }
    return 0;
}


int func_021BA834(TownMapTown *town)
{
    int flag;

    flag = func_021BBB3C(town->info, (u16)(town->index), 15);
    if ((flag != 65535 && town->visited != 0 && town->locked == 0) || flag == 65535)
        return 1;
    return 0;
}


void func_021BA86C(TownMapTown *town, int mapInfo, int townIndex, int clactSet, int plttRes, int cellRes, int charRes, void *gameData, u16 heapId, int pickMode)
{
    SpriteInit init;
    u32 flag;
    int i;

    func_02082BCC(town, 0, 0x44);
    town->scale = 0x1000;
    town->info = (char *)mapInfo;
    town->index = townIndex;
    flag = func_021BBB3C((char *)mapInfo, (u16)townIndex, 15);
    if (flag != 0xFFFF)
        town->visited = func_02166CD0(gameData, flag);
    else
        town->visited = 0;
    if (pickMode)
        town->visited = 1;
    for (i = 0; i < 9; i++)
        town->values[i] = func_021BBB3C(town->info, (u16)town->index, i + 2);
    if (pickMode)
        town->selectable = 1;
    else
        town->selectable = town->visited && func_021BBB3C(town->info, (u16)town->index, 12);
    flag = func_021BBB3C(town->info, (u16)town->index, 16);
    if (flag != 0xFFFF)
        town->locked = func_02166CD0(gameData, flag) == 0;
    else
        town->locked = 0;
    if (pickMode)
        town->locked = 0;
    switch (func_021BA774(town, 11)) {
    case 0:
        town->frameNormal = 2;
        town->frameHighlight = 1;
        break;
    case 2:
        town->frameNormal = 3;
        town->frameHighlight = 0xff;
        break;
    case 1:
        town->frameNormal = 0xff;
        town->frameHighlight = 0xff;
        break;
    case 3:
        town->frameNormal = 3;
        town->frameHighlight = 0xd;
        break;
    case 4:
        town->frameNormal = 0xf;
        town->frameHighlight = 0xe;
        break;
    case 5:
        town->frameNormal = 0x12;
        if (town->visited)
            town->frameHighlight = 0x11;
        else
            town->frameHighlight = 0x10;
        break;
    }
    if (func_021BA774(town, 11) != 1) {
        func_02082BCC(&init, 0, 8);
        init.x = func_021BA774(town, 2);
        init.y = func_021BA774(town, 3);
        town->sprite = func_0204B294((void *)clactSet, plttRes, charRes, cellRes, &init, 0, heapId);
        CLACT_SetActorAffineMode((struct Actor *)town->sprite, 2);
        func_0204B84C((int)town->sprite, 2);
        CLACT_SetActorDrawPriority((struct Node *)town->sprite, 4);
    }
    func_021BAE44(town);
}


void func_021BAA14(TownMapTown *town)
{
    if (town->sprite)
        func_0204B3B4((struct Actor *)town->sprite);
    func_02082BCC(town, 0, 0x44);
}


void func_021BAA30(TownMapTown *town, int shown)
{
    if (town->sprite == 0 || town->frameShown == 0xff) {
        return;
    }
    if (town->locked != 0) {
        func_0204B3DC((struct Actor *)town->sprite, 0);
        return;
    }
    if (func_021BA774(town, 11) == 4 || func_021BA774(town, 11) == 5) {
        func_021BADBC(town, town->frameHighlight);
        func_0204B3DC((struct Actor *)town->sprite, 1);
    } else {
        func_0204B3DC((struct Actor *)town->sprite, shown);
    }
}


u32 func_021BAA90(TownMapTown *town, const TownMapPoint *pos, const TownMapPoint *scroll)
{
    struct Ball ball;
    struct Seg seg;
    struct Vec3 v0;
    struct Vec3 v1;

    v0.x = FX_F32_TO_FX32(pos->x);
    v0.y = FX_F32_TO_FX32(pos->y);
    v0.z = 0;
    BUTTON_MAN_InitSphere(&ball, (struct Vec *)(&v0), 0);
    v0.x = FX_F32_TO_FX32(scroll->x + func_021BA774(town, 6));
    v0.y = FX_F32_TO_FX32(scroll->y + func_021BA774(town, 7));
    v0.z = 0;
    v1.x = FX_F32_TO_FX32(scroll->x + func_021BA774(town, 8));
    v1.y = FX_F32_TO_FX32(scroll->y + func_021BA774(town, 9));
    v1.z = 0;
    BUTTON_MAN_InitSegment((char *)(&seg), (struct S12 *)(&v0), (struct S12 *)(&v1), FX_F32_TO_FX32(func_021BA774(town, 10)));
    if (town->locked != 0)
        return 0;
    return BUTTON_MAN_SegmentSphereTest(&seg, &ball, 0);
}


int func_021BACB0(TownMapTown *town, const TownMapPoint *pos, const TownMapPoint *scroll, u32 *distSq)
{
    int x;
    int y;
    int dx;
    int dy;
    int scale;
    int limit;

    x = scroll->x + func_021BA774(town, 4);
    y = scroll->y + func_021BA774(town, 5);
    dx = x - pos->x;
    dx = dx * dx;
    dy = y - pos->y;
    dy = dy * dy;
    if (town->locked != 0) {
        return 0;
    }
    scale = town->scale;
    if (scale < 0) {
        scale = -scale;
    }
    limit = (scale * 0x90) >> 12;
    if ((u32)(dx + dy) < limit) {
        if (distSq != 0) {
            *distSq = dx + dy;
        }
        return 1;
    }
    return 0;
}


void func_021BAD10(TownMapTown *town, int scale, const TownMapPoint *center)
{
    int i;
    int base;
    int d;
    int scaleXY[2];

    for (i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            base = center->x;
        } else {
            base = center->y;
        }
        d = func_021BBB3C(town->info, (u16)town->index, i + 2) - base;
        d = d * scale >> 12;
        town->values[i] = d + base;
    }
    town->values[8] = scale * func_021BBB3C(town->info, (u16)town->index, 10) >> 12;
    town->scale = scale;
    if (town->sprite != 0) {
        scaleXY[0] = scale;
        scaleXY[1] = scale;
        CLACT_SetActorScale((struct Actor *)town->sprite, (struct Pair *)scaleXY);
    }
}


void func_021BAD84(TownMapTown *town, const TownMapPoint *scroll)
{
    ScreenPos pos;

    pos.x = scroll->x + func_021BA774(town, 2);
    pos.y = scroll->y + func_021BA774(town, 3);
    if (town->sprite)
        func_0204B404((struct Actor *)town->sprite, (const struct Vec2 *)(&pos), 0);
}


void func_021BADBC(TownMapTown *town, int frame)
{
    town->frameShown = frame;
    if (town->frameShown != 255) {
        if (town->sprite) {
            func_0204B3DC((struct Actor *)town->sprite, 1);
            func_0204B878((struct Actor *)(town->sprite), town->frameShown);
        }
    } else {
        if (town->sprite)
            func_0204B3DC((struct Actor *)town->sprite, 0);
    }
}


void func_021BADF4(TownMapTown *town)
{
    int special;

    special = 0;
    if (func_021BA774(town, 11) == 4 || func_021BA774(town, 11) == 5) {
        special = 1;
        if (town->locked != 0) {
            special = 0;
        }
    }
    if (town->visited != 0 || special != 0) {
        func_021BAA30(town, 1);
        func_021BADBC(town, town->frameNormal);
    } else {
        func_021BAA30(town, 0);
    }
}


void func_021BAE44(TownMapTown *town)
{
    int special;

    special = 0;
    if (func_021BA774(town, 11) == 4 || func_021BA774(town, 11) == 5) {
        special = 1;
        if (town->locked != 0) {
            special = 0;
        }
    }
    if (town->visited != 0 || special != 0) {
        if (town->sprite != 0) {
            func_021BAA30(town, 1);
            func_021BADBC(town, town->frameHighlight);
        }
    } else {
        func_021BAA30(town, 0);
    }
}


void func_021BAE9C(TownMapMarker *marker, TownMapTown *town, int clactSet, int plttRes, int cellRes, int charRes, u16 heapId)
{
    SpriteInit init;

    func_02082BCC(marker, 0, 8);
    marker->town = town;
    func_02082BCC(&init, 0, 8);
    if (town != 0) {
        init.x = func_021BA774(town, 2);
        init.y = func_021BA774(town, 3);
    }
    marker->sprite = func_0204B294((void *)clactSet, plttRes, charRes, cellRes, &init, 0, heapId);
    func_0204B84C((int)marker->sprite, 2);
    CLACT_SetActorDrawPriority((struct Node *)marker->sprite, 2);
    func_0204B878((struct Actor *)marker->sprite, 6);
    func_0204B92C((struct Actor *)marker->sprite, 1);
    if (town == 0) {
        func_0204B3DC((struct Actor *)marker->sprite, 0);
    }
}

/* Marker actor of a town. */
void func_021BAF24(TownMapMarker *marker)
{
    func_0204B3B4((struct Actor *)marker->sprite);
    func_02082BCC(marker, 0, sizeof(TownMapMarker));
}

void func_021BAF3C(TownMapMarker *marker, const TownMapPoint *scroll)
{
    ScreenPos pos;

    if (marker->town != 0) {
        pos.x = scroll->x + func_021BA774(marker->town, 2);
        pos.y = scroll->y + func_021BA774(marker->town, 3);
    }
    func_0204B404((struct Actor *)marker->sprite, (const struct Vec2 *)&pos, 0);
}

/* Scroll and zoom of the map layers. */
void func_021BAF74(TownMapScroll *scroll, u32 bgIdA, u32 bgIdB, int heapId)
{
    u16 zero = 0;

    func_02082BCC(scroll, 0, sizeof(TownMapScroll));
    scroll->bgId[0] = bgIdA;
    scroll->bgId[1] = bgIdB;
    scroll->scale = 0x1000;
    scroll->minY = zero;
    scroll->minX = zero;
    scroll->maxX = zero;
    scroll->maxY = zero;
}

void func_021BAF9C(TownMapScroll *scroll)
{
    func_02082BCC(scroll, 0, sizeof(TownMapScroll));
}

void func_021BAFA8(TownMapScroll *scroll, TownMapMap *map)
{
    int dy;
    int dx;
    int scaleStep;

    scroll->zoomDone = 0;
    if (scroll->zooming == 0)
        return;
    scaleStep = (scroll->scaleTo - scroll->scaleFrom) / 10;
    scroll->scale = scroll->scaleFrom + scaleStep * scroll->step;
    dy = (scroll->dst.y - scroll->src.y) << 12;
    dx = (scroll->dst.x - scroll->src.x) << 12;
    scroll->pos.x = scroll->src.x + ((dx * scroll->step) / 10 >> 12);
    scroll->pos.y = scroll->src.y + ((dy * scroll->step) / 10 >> 12);
    if (scroll->scaleTo == 0x1000) {
        scroll->minY = -96 - (-96 - 0) / 10 * scroll->step;
        scroll->maxY = 72 - (72 - 0) / 10 * scroll->step;
        scroll->minX = -128 - (-128 - 0) / 10 * scroll->step;
        scroll->maxX = 128 - (128 - 0) / 10 * scroll->step;
    } else {
        scroll->minY = 0 + (-96 - 0) / 10 * scroll->step;
        scroll->maxY = 0 + (72 - 0) / 10 * scroll->step;
        scroll->minX = 0 + (-128 - 0) / 10 * scroll->step;
        scroll->maxX = 0 + (128 - 0) / 10 * scroll->step;
    }
    if (scroll->step++ >= 10) {
        scroll->step = 0;
        scroll->zooming = 0;
        scroll->scale = scroll->scaleTo;
        scroll->pos = scroll->dst;
        if (scroll->scaleTo == 0x1000) {
            scroll->minY = 0;
            scroll->minX = 0;
            scroll->maxX = 0;
            scroll->maxY = 0;
        } else {
            scroll->minY = -0x60;
            scroll->minX = -0x80;
            scroll->maxX = 0x80;
            scroll->maxY = 0x48;
        }
        scroll->zoomDone = 1;
    }
    func_021BA5B0(map, scroll->scale, &scroll->pos);
    func_021BB0E4(scroll, &scroll->pos);
}

/* stand-in: an enum typed local keeps the flag in a register across the load of from->x, as the original does. */
typedef enum { ZOOM_OFF, ZOOM_ON } ZoomFlag;

void func_021BB0B4(TownMapScroll *scroll, int scaleTo, const TownMapPoint *from, const TownMapPoint *to)
{
    int x;
    ZoomFlag one;

    scroll->scaleTo = scaleTo;
    scroll->scaleFrom = scroll->scale;
    one = ZOOM_ON;
    x = from->x;
    scroll->zooming = one;
    scroll->src.x = x - 0x80;
    scroll->src.y = from->y - 0x60;
    scroll->dst.x = to->x - 0x80;
    scroll->dst.y = to->y - 0x60;
}

int func_021BB0DC(TownMapScroll *scroll)
{
    return scroll->zoomDone;
}

int func_021BB0E0(TownMapScroll *scroll)
{
    return scroll->zooming;
}

void func_021BB0E4(TownMapScroll *scroll, const TownMapPoint *pos)
{
    scroll->pos.x = (pos->x > scroll->maxX) ? scroll->maxX : ((pos->x < scroll->minX) ? scroll->minX : pos->x);
    scroll->pos.y = (pos->y > scroll->maxY) ? scroll->maxY : ((pos->y < scroll->minY) ? scroll->minY : pos->y);

    func_02041EE4(scroll->bgId[0], 0, scroll->pos.x);
    func_02041EE4(scroll->bgId[0], 3, scroll->pos.y);
    func_02041FB0(scroll->bgId[0], 9, 0x80);
    func_02041FB0(scroll->bgId[0], 12, 0x60);
    func_02041F6C(scroll->bgId[0], 3, scroll->scale);
    func_02041F6C(scroll->bgId[0], 6, scroll->scale);
    func_02041EE4(scroll->bgId[1], 0, scroll->pos.x);
    func_02041EE4(scroll->bgId[1], 3, scroll->pos.y);
    func_02041FB0(scroll->bgId[1], 9, 0x80);
    func_02041FB0(scroll->bgId[1], 12, 0x60);
    func_02041F6C(scroll->bgId[1], 3, scroll->scale);
    func_02041F6C(scroll->bgId[1], 6, scroll->scale);
}

void func_021BB190(TownMapScroll *scroll, TownMapPoint *out)
{
    *out = scroll->pos;
}

void func_021BB19C(TownMapScroll *scroll, const TownMapPoint *delta)
{
    scroll->pos.x = delta->x + scroll->pos.x;
    scroll->pos.y += delta->y;
    func_021BB0E4(scroll, &scroll->pos);
}

/* Town description shown on the bottom screen. */
void func_021BB1BC(TownMapSelection *sel, int bgId, void *font, struct MsgBank *nameMsg, struct MsgBank *detailMsg, u16 heapId)
{
    func_02082BCC(sel, 0, sizeof(TownMapSelection));
    sel->box.font = font;
    sel->detailMsg = detailMsg;
    sel->box.msg = nameMsg;
    sel->box.win = func_020450F0(bgId, 0, 0, 0x20, 0x18, 0xe, 0);
    sel->box.text = func_020457B0(0xff, heapId);
}

void func_021BB204(TownMapSelection *sel)
{
    func_02045808(sel->box.text);
    func_020452E8(sel->box.win);
    func_02082BCC(sel, 0, sizeof(TownMapSelection));
}

void func_021BB220(TownMapSelection *sel, TownMapTown *town)
{
    struct Bitmap *bitmap;
    struct BmpWin *win;
    s16 centerX;
    s16 halfWidth;
    u16 msgId;

    bitmap = func_02045770(sel->box.win);
    func_02043B5C(bitmap, 0);
    if (town != 0) {
        func_02045CAC(sel->box.msg, func_02013E4C((u16)func_021BA774(town, 0)), sel->box.text);
        centerX = ((u32)func_02045738(sel->box.win) << 3) / 2;
        halfWidth = func_0201D304(sel->box.text, sel->box.font, 0) >> 1;
        centerX = centerX - halfWidth;
        func_0201C7A4(bitmap, centerX, 0x30, sel->box.text, sel->box.font);
        msgId = func_021BA774(town, 0x11);
        if (msgId != 0xFFFF) {
            func_02045CAC(sel->detailMsg, msgId, sel->box.text);
            func_0201C7A4(bitmap, 0x1c, 0x50, sel->box.text, sel->box.font);
        }
        if (func_021BA834(town)) {
            msgId = func_021BA774(town, 0x12);
            if (msgId != 0xFFFF) {
                func_02045CAC(sel->detailMsg, msgId, sel->box.text);
                func_0201C7A4(bitmap, 0x10, 0x80, sel->box.text, sel->box.font);
            }
            msgId = func_021BA774(town, 0x13);
            if (msgId != 0xFFFF) {
                func_02045CAC(sel->detailMsg, msgId, sel->box.text);
                func_0201C7A4(bitmap, 0x10, 0x90, sel->box.text, sel->box.font);
            }
            msgId = func_021BA774(town, 0x14);
            if (msgId != 0xFFFF) {
                func_02045CAC(sel->detailMsg, msgId, sel->box.text);
                func_0201C7A4(bitmap, 0x10, 0xa0, sel->box.text, sel->box.font);
            }
            msgId = func_021BA774(town, 0x15);
            if (msgId != 0xFFFF) {
                func_02045CAC(sel->detailMsg, msgId, sel->box.text);
                func_0201C7A4(bitmap, 0x88, 0x80, sel->box.text, sel->box.font);
            }
            msgId = func_021BA774(town, 0x16);
            if (msgId != 0xFFFF) {
                func_02045CAC(sel->detailMsg, msgId, sel->box.text);
                func_0201C7A4(bitmap, 0x88, 0x90, sel->box.text, sel->box.font);
            }
            msgId = func_021BA774(town, 0x17);
            if (msgId != 0xFFFF) {
                func_02045CAC(sel->detailMsg, msgId, sel->box.text);
                func_0201C7A4(bitmap, 0x88, 0xa0, sel->box.text, sel->box.font);
            }
        }
    }
    win = sel->box.win;
    func_02045334(win);
    func_02045374(win);
    func_02041B6C(func_02045730(win));
}

void func_021BB3D0(TownMapSelection *sel)
{
    struct BmpWin *win = sel->box.win;

    func_020456F8(win);
    func_02041B6C(func_02045730(win));
}
