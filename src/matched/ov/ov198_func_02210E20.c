/*
 * function: B_PLIST_MAIN_PrintStatusMessage
 * address: 0x02210E20
 * packet: pkt_ov198_02210E20
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever (wave 82 R8): the switch has no default arm. The image's `bhi`
 *   for a selector above 6 goes straight to the shared tail with `text`
 *   (r7) never assigned, exactly what the C says (see
 *   docs/idioms/switch-arms-tail-merge.md); matched B_PLIST_MAIN_GetRowStatus returns
 *   only 0..6, so that path is never taken. A `case 0: default: return 1;`
 *   arm is DIFF54. The `adds r5,r4,#4` above the multiply needs the index
 *   multiplied in its own statement after base (`index*=76;`); `76*f()`
 *   and `f()*76` initialisers are DIFF4.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_GetRowStatus 0x02210DA8 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern int B_PLIST_MAIN_GetRowStatus(u8 *);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
int B_PLIST_MAIN_PrintStatusMessage(u8 *p)
{
    u32 index=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[32]);
    u8 *base=p+4;
    void *text;
    index*=76;
    switch((u32)B_PLIST_MAIN_GetRowStatus(p)) {
    case 1: text=func_02045EC0(*(void **)(p+0x1EA0),90); break;
    case 2:
        text=func_02045EC0(*(void **)(p+0x1EA0),87);
        WORDSET_SetSlotMonNickname(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 3:
        text=func_02045EC0(*(void **)(p+0x1EA0),86);
        WORDSET_SetSlotMonNickname(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 4:
        text=func_02045EC0(*(void **)(p+0x1EA0),103);
        WORDSET_SetSlotMonNickname(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 5: text=func_02045EC0(*(void **)(p+0x1EA0),89); break;
    case 6:
        index=76*(*(u8 **)p)[33];
        text=func_02045EC0(*(void **)(p+0x1EA0),88);
        WORDSET_SetSlotMonNickname(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 0: return 1;
    }
    WORDSET_CopyTaggedText(*(void **)(p+0x1EA4),*(void **)(p+0x1EA8),text);
    STRBUF_Delete(text);
    return 0;
}
