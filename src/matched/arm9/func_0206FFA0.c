/*
 * function: NNSi_G3dAnmDecodeRotKey
 * address:  0x0206FFA0
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2p2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decodes one packed rotation key into a 3x3 matrix (docs/families/
 * cluster_0206EB00.h, section 5).  id bit 15 set: an axis permutation --
 * clear the matrix, put +-1.0 (bit 4 of the row's first word) on the axis
 * nibble's slot and the two remaining row values (negated by bits 5 and 6)
 * on the slots the four Perm columns name; returns 0.  Bit 15 clear: five
 * quantised s16 row values (>> 3 each) whose low three bits pack a 13-bit
 * sixth value (row 1 col 2, sign-extended); returns 1, and the caller
 * rebuilds row 2 by the cross product.
 *
 * Two levers closed it (75 -> 0 bytes, wave 10):
 *   - the Perm columns are `const`: mwcc then knows a store through `out`
 *     cannot modify them and hoists each column's `ldrb` above the earlier
 *     stores, which is the image's order (load 1998, store out[k], load 1999,
 *     store, store).  Non-const, the loads stay after the stores (32 out);
 *   - the packed arm is written row by row (load, store >> 3, fold into p),
 *     not as five loads followed by the packing chain (53 -> 0 in that arm).
 * The whole-matrix clear is written highest element first.
 *
 * symbols:
 *   g_020A1998      0x020A1998  data  a1
 *   g_020A1999      0x020A1999  data  a1
 *   g_020A199A      0x020A199A  data  a1
 *   g_020A199B      0x020A199B  data  a1
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dAnmDecodeRotKey.c \
 *       --func NNSi_G3dAnmDecodeRotKey --addr 0x0206FFA0 --arm --cc ../2.0/sp2p2
 */
typedef unsigned int   u32;
typedef signed short   s16;
typedef unsigned char  u8;

typedef struct { u8 c; u8 pad[3]; } Perm;
extern const Perm g_020A1998[];
extern const Perm g_020A1999[];
extern const Perm g_020A199A[];
extern const Perm g_020A199B[];

int NNSi_G3dAnmDecodeRotKey(int *out, s16 *a, s16 *b, u32 id)
{
    if (id & 0x8000) {
        u32 i;
        s16 *row;
        int h0, h1, h2, k;

        out[8] = 0;
        out[7] = 0;
        out[6] = 0;
        out[5] = 0;
        out[4] = 0;
        out[3] = 0;
        out[2] = 0;
        out[1] = 0;
        out[0] = 0;
        i = (id & 0x7fff) * 3;
        row = a + i;
        h0 = a[i];
        h1 = row[1];
        h2 = row[2];
        k = h0 & 0xf;
        out[k] = (h0 & 0x10) ? -0x1000 : 0x1000;
        out[g_020A1998[k].c] = h1;
        out[g_020A1999[k].c] = h2;
        out[g_020A199A[k].c] = (row[0] & 0x20) ? -h2 : h2;
        out[g_020A199B[k].c] = (row[0] & 0x40) ? -h1 : h1;
        return 0;
    } else {
        u32 i = (id & 0x7fff) * 5;
        s16 *row = b + i;
        s16 v0, v1, v2, v3, v4, p;

        v4 = row[4];
        out[4] = v4 >> 3;
        p = v4 & 7;
        v0 = b[i];
        out[0] = v0 >> 3;
        p = (v0 & 7) | (p << 3);
        v1 = row[1];
        out[1] = v1 >> 3;
        p = (v1 & 7) | (p << 3);
        v2 = row[2];
        out[2] = v2 >> 3;
        p = (v2 & 7) | (p << 3);
        v3 = row[3];
        out[3] = v3 >> 3;
        p = (v3 & 7) | (p << 3);
        out[5] = (p << 19) >> 19;
        return 1;
    }
}
