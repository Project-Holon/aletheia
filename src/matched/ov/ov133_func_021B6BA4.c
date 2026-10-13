/*
 * function: func_021B6BA4
 * address: 0x021B6BA4
 * packet: pkt_ov133_021B6BA4
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD9r lane78): EXACT. Closed by declaring func_02049658 with its real return type u32
 *   (it returns ARC_UTIL_UploadBgChar's u32 result, as the matched sibling ARC_UTIL_UploadBgCharFromArchive does), not void. The void
 *   prototype hoisted 4 into r7 and turned later zeros into adds rN,r6,#0 copies. 0xd and -128 are literals.
 *   See docs/idioms/a-getter-declared-void-changes-constant-hoisting.md.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct {s16 x,y,index;u8 a,b;} Params;
struct Obj;
typedef signed int     s32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02041EE4(u32,u32,u32);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020409B4(u32);
#define H (*(u16 *)p)
#define W(o) (*(u32 *)(p + (o)))
void func_021B6BA4(u8 *p)
{
    Params cfg;
    void *g = func_020490F4(0x2e, H);
    func_02049B68(g, 4, 0, 0, 0, H);
    func_02049658(g, 7, 3, 0, 0, 0, H);
    func_020498F4(g, 0xc, 3, 0, 0, 0, H);
    func_020498F4(g, 0xb, 2, 0, 0, 0, H);
    func_02049B68(g, 3, 4, 0, 0, H);
    func_02049658(g, 0xa, 4, 0, 0, 0, H);
    func_02049658(g, 9, 7, 0, 0, 0, H);
    func_020498F4(g, 0x10, 4, 0, 0, 0, H);
    func_020498F4(g, 0xf, 6, 0, 0, 0, H);
    func_020498F4(g, 0xe, 5, 0, 0, 0, H);
    func_020498F4(g, 0xd, 7, 0, 0, 0, H);
    func_02041EE4(6, 0, 128);
    func_02041EE4(5, 0, -128);
    *(struct Obj **)(p + 0x1858) = (struct Obj *)CLACT_RegisterPalette(g, 2, 0, 0, H);
    *(struct Obj **)(p + 0x1864) = (struct Obj *)CLACT_RegisterCharacter(g, 8, 0, 0, H);
    *(struct Obj **)(p + 0x1870) = (struct Obj *)CLACT_RegisterCellAnim(g, 0x14, 0x18, H);
    *(struct Obj **)(p + 0x1860) = (struct Obj *)CLACT_RegisterPalette(g, 1, 1, 0, H);
    *(struct Obj **)(p + 0x186c) = (struct Obj *)CLACT_RegisterCharacter(g, 6, 0, 1, H);
    *(struct Obj **)(p + 0x1878) = (struct Obj *)CLACT_RegisterCellAnim(g, 0x13, 0x17, H);
    *(struct Obj **)(p + 0x185c) = (struct Obj *)CLACT_RegisterPalette(g, 0, 0, 0x40, H);
    *(struct Obj **)(p + 0x1868) = (struct Obj *)CLACT_RegisterCharacter(g, 5, 0, 0, H);
    *(struct Obj **)(p + 0x1874) = (struct Obj *)CLACT_RegisterCellAnim(g, 0x11, 0x15, H);
    cfg.x = 32; cfg.y = 224; cfg.index = 0; cfg.a = 0; cfg.b = 2;
    *(struct Obj **)(p + 0x184c) = CLACT_CreateActor((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    cfg.x = 224; cfg.y = 224; cfg.index = 1;
    *(struct Obj **)(p + 0x1850) = CLACT_CreateActor((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    cfg.x = 128; cfg.y = 96; cfg.index = 2; cfg.a = 0; cfg.b = 0;
    *(struct Obj **)(p + 0x1854) = CLACT_CreateActor((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    func_0204B3DC(*(struct Obj **)(p + 0x184c), 1);
    func_0204B3DC(*(struct Obj **)(p + 0x1850), 1);
    func_0204B3DC(*(struct Obj **)(p + 0x1854), 0);
    ARC_TOOL_DeleteHandle(g);
    func_020409B4(3);
    func_020409B4(2);
    func_020409B4(7);
}
