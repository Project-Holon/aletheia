/*
 * function: func_02201A20
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
 *   d_0220A1E8  0x0220A1E8  data  ov094
 *   d_0220A1EA  0x0220A1EA  data  ov094
 *   d_0220A1EC  0x0220A1EC  data  ov094
 *   d_0220A1EE  0x0220A1EE  data  ov094
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

extern const char d_0220A1E8[];
extern const char d_0220A1EA[];
extern const char d_0220A1EC[];
extern const char d_0220A1EE[];

int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3)
{
    int found = 0;
    unsigned i;

    for (i = 0; i < 0x30; i++) {
        const Ent *e = (const Ent *)(d_0220A1E8 + i * 8);
        unsigned o = i * 8;

        if (a == e->key && (b & 1) == e->flag) {
            o1[0] = *(const s16 *)(d_0220A1EA + o);
            o1[1] = 0;
            o1[2] = *(const s16 *)(d_0220A1EC + o);
            *o2 = *(const u16 *)(d_0220A1EE + o);
            *o3 = e->hi;
            found = 1;
            break;
        }
    }
    return found;
}
