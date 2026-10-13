/*
 * unit:     no
 * function: MSGDATA_DecryptStrbuf
 * address:  0x02045E04
 * packet:   pkt_02045C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   sub_02045E3C  0x02045E3C  arm
 *   STRBUF_Truncate  0x02045900  arm
 *
 * Advance the object by one: read its current index (STRBUF_GetLength), ask
 * sub_02045E3C for the entry one past it in the list STRBUF_GetChars returns,
 * and install the answer with STRBUF_Truncate.
 *
 * Three of the four calls need the object pointer, so it is pinned in r6
 * for the whole body; the incoming second argument survives in r5 across
 * two calls before reaching sub_02045E3C's r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_DecryptStrbuf.c \
 *       --func MSGDATA_DecryptStrbuf --addr 0x02045E04 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Obj {
    u8 unk_00[1];
};

struct U16Vec;
extern unsigned short STRBUF_GetLength(struct U16Vec *vec);
extern unsigned short *STRBUF_GetChars(struct U16Vec *vec);
typedef unsigned short u16;
extern u32 sub_02045E3C(u16 *str, u32 count, u32 msgIndex);
struct U16Vec;
extern void STRBUF_Truncate(struct U16Vec *vec, u32 index);

void MSGDATA_DecryptStrbuf(struct Obj *o, u32 mode)
{
    s32 index = STRBUF_GetLength((struct U16Vec *)o);

    STRBUF_Truncate((struct U16Vec *)o, sub_02045E3C(STRBUF_GetChars((struct U16Vec *)o), index + 1, mode));
}
