/*
 * function: INTRUDE_OfferEventMain
 * address:  0x021CFBA8
 * packet:   pkt_ov021_021CFBA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies a 20-byte record, opens the 0x0AFC resource, and passes the record's
 * first 8 bytes on to WORDSET_SetSlotTag.
 *
 * symbols:
 *   SCRIPT_SYS_ChangeScriptEvent  0x021587B0  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u16 v[10];
} Rec;

extern int SCRIPT_SYS_ChangeScriptEvent(int a0, int a1, int a2, int a3);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
struct U16Vec;
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *dst, const u16 *src, u32 len);
extern void STRBUF_Delete(struct U16Vec *vec);
struct WordSet;
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);

int INTRUDE_OfferEventMain(u32 a, u32 unused, const Rec *src)
{
    Rec r = *src;
    u32 h;
    u32 x;
    u32 buf;

    h = SCRIPT_SYS_ChangeScriptEvent(a, 0x0AFC, 0, 0x15);
    SCRIPT_WORK_SetParams(h, r.v[8], 0, 0, 0);
    x = (u32)SCRIPT_WORK_GetWordSet((void *)h);
    buf = (u32)STRBUF_Create(8, 0x15);
    STRBUF_SetStringN((struct Strbuf *)buf, (const u16 *)&r, 8);
    WORDSET_SetSlotTag((struct WordSet *)x, 3, (const void *)buf, 1, 1, 2);
    STRBUF_Delete((struct U16Vec *)buf);
    return 0;
}
