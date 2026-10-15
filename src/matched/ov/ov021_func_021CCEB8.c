/*
 * function: PARTY_SELECT_LIST_InitMessageResources
 * address:  0x021CCEB8
 * packet:   pkt_ov021_021CCEB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fetches three handles for the work block: an ov021 object, a 0x54 sub-entry of it, and the record for the work's id.
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *f0;
    u8 pad4[8];
    u16 hC;
    u8 padE[0xa0 - 0xe];
    void *fA0;
    void *fA4;
    void *fA8;
} Work;

extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);

void PARTY_SELECT_LIST_InitMessageResources(Work *w)
{
    void *o = (void *)FIELDMAP_GetMsgBg(w->f0);
    w->fA8 = (void *)FIELD_MSGBG_CreateMsgData((u32)o, 0x54);
    w->fA4 = o;
    w->fA0 = WORDSET_CreateDefault(w->hC);
}
