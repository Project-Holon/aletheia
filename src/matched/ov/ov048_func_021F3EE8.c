/*
 * function: GIMMICK_OBJ_ELBOARD_AddPlaceListMessage
 * address:  0x021F3EE8
 * packet:   pkt_ov048_021F3EE8
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * `sz = 4; sz = 0x100;` is the original's str/adds #0xfc/str pair into one
 * spill slot (a dead store survives in a stack-homed local); f declared
 * before h1 puts its slot highest.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`sz = 4;` before `sz = 0x100;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_CollectHighlights  0x021F44D8  thumb  ov048
 *   WORDSET_Create  0x0201EC74  thumb
 *   func_02045B38  0x02045B38  arm
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GIMMICK_OBJ_ELBOARD_CountHighlights  0x021F4488  thumb  ov048
 *   GIMMICK_OBJ_ELBOARD_AddMessage  0x021F3D38  thumb  ov048
 *   gElboardLabelMsgId     0x021F5124  data  a4
 *   gElboardLayout     0x021F50C0  data  a4
 */
#include "../include/Obj02413.h"
#include "../include/G_T.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 h[4];
    u8  b[4];
} Slots;

extern void GIMMICK_OBJ_ELBOARD_CollectHighlights(int *p, Slots *q);
struct WordSet;
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct U16Vec;
struct WordSet;
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern int GIMMICK_OBJ_ELBOARD_CountHighlights(unsigned char *p);
extern void GIMMICK_OBJ_ELBOARD_AddMessage(int *p, int unused, int b, int *c);
extern u32 gElboardLabelMsgId[];
extern struct T gElboardLayout;

void GIMMICK_OBJ_ELBOARD_AddPlaceListMessage(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } m;
    Slots s;
    int sz;
    int f;
    void *h1;
    u32 a;
    u32 b;
    int i;
    int c;
    u32 s1;
    u32 s2;
    void *h2;
    u32 s3;
    void *buf;

    GIMMICK_OBJ_ELBOARD_CollectHighlights(p, &s);
    sz = 0x100;
    h1 = WORDSET_Create(4, sz, ((struct Obj02413 *)p)->f0);
    a = (u32)func_02045B38(0, 2, 0x59, ((struct Obj02413 *)p)->f0);
    b = (u32)func_02045B38(0, 2, 0x26, ((struct Obj02413 *)p)->f0);
    for (i = 0; i < 4; i++) {
        if (s.h[i] == 0x1AB)
            continue;
        c = s.b[i];
        s1 = (u32)func_02045EC0((struct MsgBank *)a, ZONEDATA_GetPlaceNameId(s.h[i]));
        s2 = (u32)func_02045EC0((struct MsgBank *)b, gElboardLabelMsgId[c]);
        h2 = WORDSET_Create(2, sz, ((struct Obj02413 *)p)->f0);
        s3 = (u32)func_02045EC0((struct MsgBank *)b, 0xc0);
        buf = STRBUF_Create(0x40, ((struct Obj02413 *)p)->f0);
        WORDSET_SetSlotTag(h2, 0, (const void *)s1, 0, 1, 0);
        WORDSET_SetSlotTag(h2, 1, (const void *)s2, 0, 1, 0);
        WORDSET_CopyTaggedText(h2, buf, (void *)s3);
        STRBUF_Delete((struct U16Vec *)s3);
        WORDSET_Delete(h2);
        WORDSET_SetSlotTag(h1, i, (const void *)buf, 0, 1, 0);
        STRBUF_Delete((struct U16Vec *)s1);
        STRBUF_Delete((struct U16Vec *)s2);
        STRBUF_Delete((struct U16Vec *)((u32)buf));
    }
    MSGDATA_Delete((struct Rec *)b);
    MSGDATA_Delete((struct Rec *)a);
    switch (GIMMICK_OBJ_ELBOARD_CountHighlights((unsigned char *)(&s))) {
    case 0:
        break;
    case 1:
        f = 0xc1;
        break;
    case 2:
        f = 0xc2;
        break;
    case 3:
        f = 0xc3;
        break;
    case 4:
        f = 0xc4;
        break;
    }
    m.a = *(u16 *)(((u8 *)&gElboardLayout) + 6);
    m.b = *(int *)(((u8 *)&gElboardLayout) + 0x30);
    m.c = *(int *)(((u8 *)&gElboardLayout) + 0x4c);
    m.d = 2;
    m.e = 0x26;
    m.f = f;
    m.g = (int)h1;
    GIMMICK_OBJ_ELBOARD_AddMessage(p, (int)&m, 2, 0);
    WORDSET_Delete(h1);
}
