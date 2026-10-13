/*
 * function: VS_MULTI_LIST_PrintName
 * address: 0x021F6B7C
 * packet: pkt_ov097_021F6B7C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Named monster base/index and byte gender if/else retain the original scheduling; inline print helpers retain owner spills.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`windows = p;` before `windows = p + 0x20;`; `dirty = p;` before `dirty =
 * p + 0x24;`). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   func_0201D304 0x0201D304 thumb
 */
#include "../include/Obj05257.h"
#include "../include/Obj07929.h"
#include "../include/Obj13675.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u8 POKE_TOOL_GetGender(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
static inline void print_text(int p, u32 windows, u32 dirty, int i, void *s, int x, int y, u16 color)
{
    void *owner = ((struct Obj13675 *)p)->f1C;
    PRINTSYS_PrintQueColor(owner, (u32)BMP_WIN_GetBmp(*(void **)(windows + i * 8)), x, y, (u32)s, ((struct Obj13675 *)p)->fC, color);
    *(u8 *)(dirty + i * 8) = 1;
}
static inline void print_right(int p, u32 windows, u32 dirty, int i, void *window, u32 id, u16 color)
{
    void *s = func_02045EC0(((struct Obj07929 *)p)->f14, id);
    u32 font = ((struct Obj07929 *)p)->fC;
    u32 w = BMP_WIN_GetWidth(window);
    s16 x = (s16)(w * 8 - func_0201D304(s, ((struct Obj07929 *)p)->fC, 0));
    void *owner = ((struct Obj07929 *)p)->f1C;
    PRINTSYS_PrintQueColor(owner, (u32)BMP_WIN_GetBmp(*(void **)(windows + i * 8)), x, 7, (u32)s, font, color);
    *(u8 *)(dirty + i * 8) = 1;
    STRBUF_Delete(s);
}
void VS_MULTI_LIST_PrintName(int p, int i)
{
    u32 windows, dirty, mons, mi;
    u8 gender;
    void *window, *t, *s;
    windows = p + 0x20;
    window = *(void **)(windows + i * 8);
    t = STRBUF_Create(0xc, 0x8071);
    s = func_02045EC0(((struct Obj05257 *)p)->f14, 0);
    mons = p + 0xf8;
    mi = i * 4;
    func_0201EEF4(((struct Obj05257 *)p)->f18, 0, *(void **)(mons + mi));
    func_0201F250(((struct Obj05257 *)p)->f18, t, s);
    dirty = p + 0x24;
    print_text(p, windows, dirty, i, t, 0x20, 7, 0x3dc0);
    STRBUF_Delete(s);
    STRBUF_Delete(t);
    if (POKE_TOOL_GetPartyValue(*(void **)(mons + mi), 0xad, 0) == 1 &&
        POKE_TOOL_GetPartyValue(*(void **)(mons + mi), 0x4c, 0) == 0) {
        gender = POKE_TOOL_GetGender(*(void **)(mons + mi));
        if (gender == 0) print_right(p, windows, dirty, i, window, 0x16, 0x2960);
        else if (gender == 1) print_right(p, windows, dirty, i, window, 0x17, 0x31a0);
    }
}
