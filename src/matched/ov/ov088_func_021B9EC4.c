/*
 * function: STARTMENU_SpritesInit
 * address:  0x021B9EC4
 * packet:   pkt_ov088_021B9EC4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   d_021BD508     0x021BD508  data  ov088  a4
 */

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
} Local;

extern char gClActorInitParam[];
extern char d_021BD508[];

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned char  u8;
struct Bank;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
typedef signed int     s32;
typedef unsigned int   u32;
struct Bank;
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern int CLACT_RegisterCharacter(void *, int, int, int, int);
extern int CLACT_RegisterPalette(void *, int, int, int, int);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int CLACT_CreateActor(int, int, int, int, Local *, int, int);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void ARC_TOOL_DeleteHandle(void *);

void STARTMENU_SpritesInit(int *p, int heap)
{
    Local s;
    void *h;
    h = func_020490F4(0x1a, heap);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, (unsigned int)d_021BD508, heap);
    p[0] = (int)CLACT_CreateUnit(0x40, 0, heap);
    CLACT_SetUnitDefaultRenderer((void *)p[0]);
    p[12] = CLACT_RegisterCharacter(h, 5, 1, 1, heap);
    p[11] = CLACT_RegisterPalette(h, 4, 1, 0, heap);
    p[13] = CLACT_RegisterCellAnim(h, 6, 7, heap);
    s.a = 0x80;
    s.b = 0x60;
    s.c = 0;
    s.e = 0;
    s.d = 0;
    p[1] = CLACT_CreateActor(p[0], p[12], p[11], p[13], &s, 1, heap);
    CLACT_SetActorAutoAnim((struct Obj *)p[1], 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    ARC_TOOL_DeleteHandle(h);
}
