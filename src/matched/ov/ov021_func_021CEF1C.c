/*
 * function: COMM_ENTRY_BuildParentItems
 * address:  0x021CEF1C
 * packet:   pkt_ov021_021CEF1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   FIELD_MSGBG_DeleteMenuItems  0x02190A6C  thumb  ov021
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   func_02008534  0x02008534  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_AddMenuItemStr  0x02190A64  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x26];
    u8 on;
    u8 pad27[5];
} Ent;

typedef struct {
    u32 f0, f4, f8;
    u8 padc[0x13c - 0xc];
    u32 f13c;
    u32 f140;
    Ent ents[16];
    u8 pad404[0x40e - 0x404];
    u8 f40e;
    u8 pad40f[0x528 - 0x40f];
    u16 f528;
} S;

extern u16 STRBUF_GetEosChar(void);
extern void FIELD_MSGBG_DeleteMenuItems(u32 a);
struct MsgBank;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern int FIELD_MSGBG_AddMenuItemStr(u32 a, u32 b, u32 c, u32 d);
extern void STRBUF_Delete(struct U16Vec *vec);

void COMM_ENTRY_BuildParentItems(S *p)
{
    u16 ch;
    u32 c, a, b, d;
    int i;

    ch = STRBUF_GetEosChar();
    if (p->f40e == 1) {
        FIELD_MSGBG_DeleteMenuItems(p->f13c);
    }
    a = (u32)STRBUF_Create(0x40, p->f528);
    b = (u32)STRBUF_Create(0x40, p->f528);
    c = (u32)STRBUF_Create(0x40, p->f528);
    d = (u32)STRBUF_Create(4, p->f528);
    MSGDATA_ReadString((struct MsgBank *)p->f8, 0x1a, (void *)a);
    MSGDATA_ReadString((struct MsgBank *)p->f8, 0x1b, (void *)b);
    for (i = 0; i < 16; i++) {
        WORDSET_SetSlotNumber((struct WordSet *)p->f4, 0, i + 1, 2, 2, 1);
        if (p->ents[i].on == 1) {
            WORDSET_SetSlotMyStatus((struct WordSet *)p->f4, 1, &p->ents[i]);
            WORDSET_SetSlotNumber((struct WordSet *)p->f4, 2, func_02008534((const struct Sub0200852CObj *)(&p->ents[i])), 5, 2, 1);
            WORDSET_CopyTaggedText((struct WordSet *)p->f4, (void *)c, (void *)b);
        } else {
            STRBUF_SetString((struct Strbuf *)d, &ch);
            WORDSET_SetSlotTag((struct WordSet *)p->f4, 1, (const void *)d, 0, 1, 2);
            WORDSET_SetSlotTag((struct WordSet *)p->f4, 2, (const void *)d, 0, 1, 2);
            WORDSET_CopyTaggedText((struct WordSet *)p->f4, (void *)c, (void *)a);
        }
        FIELD_MSGBG_AddMenuItemStr(p->f13c, c, i, p->f528);
    }
    STRBUF_Delete((struct U16Vec *)b);
    STRBUF_Delete((struct U16Vec *)a);
    STRBUF_Delete((struct U16Vec *)c);
    STRBUF_Delete((struct U16Vec *)d);
    p->f40e = 1;
}
