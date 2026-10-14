/*
 * function: BTLV_MCSS_LookupShadowEntry
 * address:  0x02201A20
 * packet:   pkt_ov094_02201A20
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvMcssShadowTable  0x0220A1E8  data  ov094
 *   gBtlvMcssShadowTableOffsetX  0x0220A1EA  data  ov094
 *   gBtlvMcssShadowTableOffsetZ  0x0220A1EC  data  ov094
 *   gBtlvMcssShadowTableRotateZ  0x0220A1EE  data  ov094
 *
 * lever: `(b & 1) == e->flag` written inline in the condition; a hoisted local `f = b & 1` costs a different register order.
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct {
    u16 key : 14;
    u16 flag : 1;
    u16 hi : 1;
} Ent;

extern const char gBtlvMcssShadowTable[];
extern const char gBtlvMcssShadowTableOffsetX[];
extern const char gBtlvMcssShadowTableOffsetZ[];
extern const char gBtlvMcssShadowTableRotateZ[];

int BTLV_MCSS_LookupShadowEntry(int a, int b, int *o1, u16 *o2, int *o3)
{
    int found = 0;
    unsigned i;

    for (i = 0; i < 0x30; i++) {
        const Ent *e = (const Ent *)(gBtlvMcssShadowTable + i * 8);
        unsigned o = i * 8;

        if (a == e->key && (b & 1) == e->flag) {
            o1[0] = *(const s16 *)(gBtlvMcssShadowTableOffsetX + o);
            o1[1] = 0;
            o1[2] = *(const s16 *)(gBtlvMcssShadowTableOffsetZ + o);
            *o2 = *(const u16 *)(gBtlvMcssShadowTableRotateZ + o);
            *o3 = e->hi;
            found = 1;
            break;
        }
    }
    return found;
}
