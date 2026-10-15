/*
 * function: GFL_NET_ERR_StoreFriendProfile
 * address:  0x0200F520
 * packet:   pkt_0200F38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTATUS_CreateNameStrbuf   0x02008510  thumb
 *   MYSTATUS_GetId   0x02008530  thumb
 *   MYSTATUS_GetProfileId   0x0200853C  thumb
 *   MYSTATUS_GetOutfitVariant   0x02008550  thumb
 *   MYSTATUS_GetOutfit   0x02008554  thumb
 *   WIFILIST_SetFriendInfoField   0x02009918  thumb
 *   WIFILIST_StoreFriendNameFromStrbuf   0x02009A00  thumb
 *   STRBUF_Delete  0x02045808  arm
 */

extern void *MYSTATUS_CreateNameStrbuf(void *a, int b);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub0200852CObj;
struct Sub020097BCObj;
struct U16Vec;
extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern u32 MYSTATUS_GetProfileId(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetOutfitVariant(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetOutfit(const struct Sub0200852CObj *obj);
extern void WIFILIST_SetFriendInfoField(struct Sub020097BCObj *obj, u32 i, u32 field, u32 value);
extern void WIFILIST_StoreFriendNameFromStrbuf(struct Sub020097BCObj *obj, int i, void *dest);
extern void STRBUF_Delete(struct U16Vec *vec);

void GFL_NET_ERR_StoreFriendProfile(void *obj, void *src, int i, int sel, int flag)
{
    if (flag != 0) {
        void *data = MYSTATUS_CreateNameStrbuf(src, sel);
        WIFILIST_StoreFriendNameFromStrbuf(obj, i, data);
        STRBUF_Delete(data);
    }
    WIFILIST_SetFriendInfoField(obj, i, 9, MYSTATUS_GetOutfitVariant(src));
    WIFILIST_SetFriendInfoField(obj, i, 0, MYSTATUS_GetId(src));
    WIFILIST_SetFriendInfoField(obj, i, 1, MYSTATUS_GetProfileId(src));
    WIFILIST_SetFriendInfoField(obj, i, 8, MYSTATUS_GetOutfit(src));
}
