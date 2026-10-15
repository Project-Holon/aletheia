/*
 * function: SHINKA_DEMO_BuildString
 * address:  0x02205620
 * packet:   pkt_02205620
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_SetSlotMonName 0x0201EE84 thumb
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 kind;
    u32 val;
} Param;

struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
struct WordSet;
extern void WORDSET_SetSlotMonName(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

u32 SHINKA_DEMO_BuildString(u32 heap, u32 a, u32 b, u32 k0, u32 v0, u32 k1, u32 v1)
{
    Param p[2];
    u32 src, w, r, i;
    int z;

    if (k0 == 4 && k1 == 4) {
        r = (u32)func_02045EC0((struct MsgBank *)a, b);
    } else {
        src = (u32)func_02045EC0((struct MsgBank *)a, b);
        w = (u32)GF_FONT_Create_EC64(heap);
        p[0].kind = k0;
        p[0].val = v0;
        p[1].kind = k1;
        p[1].val = v1;
        for (i = 0, z = i; i < 2; i++) {
            switch (p[i].kind) {
            case 0:
                WORDSET_SetSlotTag((struct WordSet *)w, i, (const void *)p[i].val, z, 1, z);
                break;
            case 1:
                WORDSET_SetSlotMonName((void *)w, i, (void *)p[i].val);
                break;
            case 2:
                WORDSET_SetSlotMonSpecies((void *)w, i, (void *)p[i].val);
                break;
            case 3:
                WORDSET_SetSlotFromMsgCB((struct WordSet *)w, i, *(u16 *)p[i].val);
                break;
            }
        }
        r = (u32)STRBUF_Create(0x100, heap);
        WORDSET_CopyTaggedText((struct WordSet *)w, (void *)r, (void *)src);
        STRBUF_Delete((struct U16Vec *)src);
        WORDSET_DeleteStrbufED04((struct WordSet *)w);
    }
    return r;
}
