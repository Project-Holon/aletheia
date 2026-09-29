/*
 * function: func_0689ADDC
 * address:  0x0689ADDC
 * packet:   pkt_ov095_0689ADDC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689AE24  0x0689AE24  thumb  ov095
 *   d_0689D82C     0x0689D82C  data   ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 n; u8 pad[2]; u8 d[16]; } St;

extern u8 func_0689AE24(u32 a, u8 b);
extern u8 d_0689D82C[];

int func_0689ADDC(St *st, int idx, u32 a, u8 *out)
{
    u8 i;

    if (st->n != 0) {
        *out = func_0689AE24(a, d_0689D82C[idx]);
        for (i = 0; i < st->n; i++) {
            if (*out == st->d[i])
                return 1;
        }
        return 0;
    }
    *out = 6;
    return 1;
}
