/*
 * function: func_021BCC40
 * address:  0x021BCC40
 * packet:   pkt_ov172_021BCC40
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_0201EC64  0x0201EC64  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   COMM_PLAYER_SUPPORT_GetRecordFieldPtr  0x0202E930  thumb
 *   STRBUF_SetStringN  0x02045994  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   COMM_PLAYER_SUPPORT_GetRecordField  0x0202E938  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Redraws one dirty list row (+0 set): an empty row (+0x18 == 0xff) just clears its window; otherwise prints the entry's name, its level (message 0xe) and, for kind 0x20 entries, the extra count (message 0x10), then records whether the entry is selectable (+0xc of the entry) and marks the row window for transfer (+4).
 *
 * Blocker: byte-correct (MATCH); the arm9 callees 0x0202E930 and 0x0202E938 are
 *     unlabelled Thumb functions with no witness outside this function.  Seed and
 *     match them and this file is EXACT.
 */
#include "../include/Obj01166.h"
#include "../include/Obj02882.h"
#include "../include/Obj24102.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct FlagsA {
    u8 pad[0x21];
    u8 on : 1;
    u8 rest : 7;
};

struct FlagsB {
    u8 pad[2];
    u8 low : 6;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern u16 func_021BE00C(u16 *p);
extern u32 func_021BE034(void *p);
extern u32 func_021BE03C(void *p);
extern u32 func_021BE044(void *p);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *win);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(void *p);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, unsigned int len);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 COMM_PLAYER_SUPPORT_GetRecordField(void *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

static inline u8 func_021BCC40_show(u32 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}

void func_021BCC40(void *ctx, char *list, char *row, int idx)
{
    u32 buf2;
    u32 fmt2;
    u32 msgs;
    u32 sys;
    u32 str;
    u32 buf;
    u8 *p;
    u32 heap;
    u32 fmt;
    u32 font;
    char *e;
    u32 ws;

    if (((struct Obj02882 *)row)->f0 != 1)
        return;
    if (((struct Obj02882 *)row)->f18 != 0xff) {
        heap = func_021BE00C(ctx);
        font = func_021BE034(ctx);
        msgs = func_021BE03C(ctx);
        sys = func_021BE044(ctx);
        e = list + 0x1e4 + ((struct Obj02882 *)row)->f18 * 0x24;
        ws = (u32)func_0201EC64(heap);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14)), 0);
        str = (u32)STRBUF_Create(0x20, heap);
        if (((struct Obj01166 *)e)->f18 == 0x20)
            STRBUF_SetStringN((struct Strbuf *)str, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(((struct Obj01166 *)e)->f14), 8);
        else
            STRBUF_SetStringN((struct Strbuf *)str, (const u16 *)(*(char * *)&((struct Obj01166 *)e)->f14 + 0x1a), 8);
        PRINTSYS_PrintQueColor((void *)sys, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 6, 0, str, font, 0x3c40);
        STRBUF_Delete((struct U16Vec *)str);
        fmt = (u32)func_02045EC0((struct MsgBank *)msgs, 0xe);
        buf = (u32)STRBUF_Create(0x20, heap);
        if (((struct Obj01166 *)e)->f18 == 0x20)
            func_0201EFA4((struct WordSet *)ws, 0, COMM_PLAYER_SUPPORT_GetRecordField(((struct Obj01166 *)e)->f14), 5, 2, 1);
        else
            func_0201EFA4((struct WordSet *)ws, 0, ((struct Obj24102 *)(*(char * *)&((struct Obj01166 *)e)->f14))->f18, 5, 2, 1);
        func_0201F250((struct WordSet *)ws, (void *)buf, (void *)fmt);
        STRBUF_Delete((struct U16Vec *)fmt);
        PRINTSYS_PrintQueColor((void *)sys, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 0x50, 0, buf, font, 0x3c40);
        STRBUF_Delete((struct U16Vec *)buf);
        if (((struct Obj01166 *)e)->f18 == 0x20) {
            p = *(u8 * *)&((struct Obj01166 *)e)->f14;
            ((struct Obj01166 *)e)->f1F = p[0x20];
            fmt2 = (u32)func_02045EC0((struct MsgBank *)msgs, 0x10);
            buf2 = (u32)STRBUF_Create(0x20, heap);
            p += 0x20;
            func_0201EFA4((struct WordSet *)ws, 0, *p, 1, 0, 1);
            func_0201F250((struct WordSet *)ws, (void *)buf2, (void *)fmt2);
            STRBUF_Delete((struct U16Vec *)fmt2);
            PRINTSYS_PrintQueColor((void *)sys, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 0x90, 0, buf2, font, 0x3c40);
            STRBUF_Delete((struct U16Vec *)buf2);
        } else {
            ((struct Obj01166 *)e)->f1F = 0;
        }
        if (((struct Obj01166 *)e)->f18 == 0x20) {
            if ((*(struct FlagsA * *)&((struct Obj01166 *)e)->f14)->on == 1)
                ((struct Obj01166 *)e)->fC = 1;
            else
                ((struct Obj01166 *)e)->fC = 0;
        } else if ((*(struct FlagsB * *)&((struct Obj01166 *)e)->f14)->b7 == 1 && (*(struct FlagsB * *)&((struct Obj01166 *)e)->f14)->b6 == 0) {
            ((struct Obj01166 *)e)->fC = 1;
        } else {
            ((struct Obj01166 *)e)->fC = 0;
        }
        func_0201ED04((struct WordSet *)ws);
        ((struct Obj02882 *)row)->f4 = 1;
    } else {
        func_02041B6C(func_021BCC40_show(((struct Obj02882 *)row)->f14));
    }
    ((struct Obj02882 *)row)->f0 = 0;
}
