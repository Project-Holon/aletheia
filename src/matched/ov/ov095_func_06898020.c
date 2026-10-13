/*
 * function: HAND_FIELD_AddFactor
 * address:  0x06898020
 * packet:   pkt_ov095_06898020
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gHandFieldEffectTable     0x0689D650  data   ov095  a4
 *   func_06898070  0x06898070  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int key;
    int (*fn)(u32 *);
} Ent;

extern Ent gHandFieldEffectTable[8];
extern void *func_06898070(int id, u16 key, int pri, u32 sub_pri, u32 sub, u32 f8, u16 f16);

void *HAND_FIELD_AddFactor(int a, int b)
{
    u32 i;
    u32 v;

    for (i = 0; i < 8; i++) {
        if (a == gHandFieldEffectTable[i].key) {
            int r = gHandFieldEffectTable[i].fn(&v);
            return func_06898070(3, a, 3, 0, b, r, v);
        }
    }
    return 0;
}
