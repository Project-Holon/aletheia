/*
 * function: SCRCMD_CollectPartnersByLanguage
 * address:  0x021CFC80
 * packet:   pkt_ov021_021CFC80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Collects up to five matching entries of a 20-slot list into out.
 *
 * symbols:
 *   func_02009634  0x02009634  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   CURSOR_MOVE_GetTableValue  0x02025C74  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Out {
    u8 key;       /* 0x00 */
    u8 count;     /* 0x01 */
    u8 b2;        /* 0x02 */
    u8 val[5];    /* 0x03 */
    u8 slot[5];   /* 0x08 */
} Out;

struct Sub0200852CObj;
struct Sub02009470Ent;
struct Sub02009470Obj;
extern u32 func_02009634(const struct Sub02009470Obj *obj, u32 i, u32 field);
extern struct Sub02009470Ent *func_0200973C(struct Sub02009470Obj *obj, int i);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 CURSOR_MOVE_GetTableValue(u32 x);

void SCRCMD_CollectPartnersByLanguage(void *a, Out *out, u32 key, u32 b)
{
    int i;

    out->key = key;
    out->b2 = b;
    out->count = 0;
    for (i = 0; i < 20; i++) {
        if ((u8)func_02009634(a, i, 6) != 0) {
            void *p = func_0200973C(a, i);
            u32 k;
            if (p != 0 && (k = func_0200856C(p), k == key)) {
                u32 v = func_02008554(p);
                if (v > 0xf) {
                    v = (func_02008550(p) != 0) ? 0xf : 0xb;
                }
                out->slot[out->count] = i;
                out->val[out->count] = CURSOR_MOVE_GetTableValue(v);
                out->count++;
                if (out->count >= 5) {
                    break;
                }
            }
        }
    }
}
