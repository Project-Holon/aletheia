/*
 * function: MONOLITH_TOOL_DrawActiveEntry
 * address:  0x021BA528
 * packet:   pkt_ov071_021BA528
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF10  0x0200BF10  thumb
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   STRBUF_Delete  0x02045808  arm
 */
#include "../include/Obj03178.h"
#include "../include/Obj06193.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct CharBuf;
struct Ctx;
struct MsgBank;
struct PrintSys;
struct Rec1B0;
struct U16Vec;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u8 func_0200BF10(struct Rec1B0 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void STRBUF_Delete(struct U16Vec *vec);

void MONOLITH_TOOL_DrawActiveEntry(u32 **a, u8 *b, u8 *c)
{
    u32 s;
    u32 s2;
    u32 k;
    u32 h;

    k = func_0200BF10((struct Rec1B0 *)func_0200BE48(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)(**a)))));
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f4)), 0);
    if (k == 0x30) {
        s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f28), 0x27);
    } else {
        int off = k * 12;
        s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f20), *(u16 *)(*(u8 * *)&((struct Obj03178 *)b)->f34 + off + 4));
        s2 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f24), *(u16 *)(*(u8 * *)&((struct Obj03178 *)b)->f34 + off + 6));
        h = ((struct Obj03178 *)b)->f8;
        func_0201C6FC((struct PrintSys *)h, (u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f14), 0, 0x10, (void *)s2, ((struct Obj03178 *)b)->fC);
        c[0x18] = 1;
        STRBUF_Delete((struct U16Vec *)s2);
    }
    h = ((struct Obj03178 *)b)->f8;
    func_0201C6FC((struct PrintSys *)h, (u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f14), 0, 0, (void *)s, ((struct Obj03178 *)b)->fC);
    c[0x18] = 1;
    STRBUF_Delete((struct U16Vec *)s);
}
