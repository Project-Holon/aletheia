/*
 * function: func_020520FC
 * address:  0x020520FC
 * packet:   pkt_020520A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   tbl_020A1B38   0x020A1B38  data
 *   MTX_Identity33_  0x0207ADC4  arm
 *   MTX_RotX33_      0x0207AF00  thumb
 *   MTX_RotY33_      0x0207AF1C  thumb
 *   MTX_RotZ33_      0x0207AF38  thumb
 *   MTX_Concat33     0x0207B388  arm
 *
 * Build a 3x3 rotation matrix from three angles, composed X, then Y, then Z.
 * The destination (r3) is used both as the identity seed and as the running
 * accumulator; a 0x24-byte stack scratch holds the per-axis rotation before
 * each MTX_Concat33 folds it in.
 *
 * Each angle feeds the shared interleaved sin/cos halfword table at
 * 0x020A1B38 (see src/matched/func_0203F684.c): index i = angle >> 4, with
 * sin at tbl[2*i] and cos at tbl[2*i+1].  The `asr #4` is a shift, not a
 * division, and the arguments are signed, which is what makes `ldrsh` with a
 * register offset the load (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * The X rotation is applied straight onto the identity in the destination,
 * with no scratch; the Y and Z rotations each build into the stack scratch and
 * are folded in by MTX_Concat33(dst, &tmp, dst).  Both Concat33 calls take the
 * destination as the LEFT operand: swapping the last one to
 * MTX_Concat33(&tmp, dst, dst) is byte-correct everywhere except the two
 * `mov` bytes at +00A4/+00A8, the only residue the whole function had.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020520FC.c \
 *       --func func_020520FC --addr 0x020520FC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */

typedef short s16;

struct Mtx33 {
    int m[9];
};

extern s16 tbl_020A1B38[];

extern void MTX_Identity33_(struct Mtx33 *m);
extern void MTX_RotX33_(struct Mtx33 *m, s16 sinv, s16 cosv);
extern void MTX_RotY33_(struct Mtx33 *m, s16 sinv, s16 cosv);
extern void MTX_RotZ33_(struct Mtx33 *m, s16 sinv, s16 cosv);
extern void MTX_Concat33(const struct Mtx33 *a, const struct Mtx33 *b,
                         struct Mtx33 *dst);

void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst)
{
    struct Mtx33 tmp;
    int i;

    MTX_Identity33_(dst);

    i = ax >> 4;
    MTX_RotX33_(dst, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);

    i = ay >> 4;
    MTX_RotY33_(&tmp, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);

    i = az >> 4;
    MTX_RotZ33_(&tmp, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);
}
