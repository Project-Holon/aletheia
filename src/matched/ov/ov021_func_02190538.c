/*
 * function: FIELD_MSGBG_DeleteMsgPrint
 * address:  0x02190538
 * packet:   pkt_ov021_02190538
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);

void FIELD_MSGBG_DeleteMsgPrint(Slot *s)
{
    s->f08 = 0;
    s->f0c = 0;
    STRBUF_Delete((struct U16Vec *)s->f18);
    s->f18 = 0;
    s->f10 = 0;
}
