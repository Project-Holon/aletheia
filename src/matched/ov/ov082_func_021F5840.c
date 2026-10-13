/*
 * function: FLD_FACEUP_StepAnim
 * address: 0x021F5840
 * packet: pkt_ov082_021F5840
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: unsigned long fifth argument restores parameter homes; nested zero-delay guard and i*e operand order fix the multiply copy. Extent ends with two alignment bytes.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 value, pad; } Row;
typedef struct { int done, busy; u8 delay, reload; u16 index; u16 tiles[2][6]; } State;

void FLD_FACEUP_StepAnim(Row *a, unsigned b, unsigned c, unsigned d, unsigned long e, State *f)
{
    int i;
    unsigned j;
    unsigned base;

    if (f->busy != 0)
        return;
    if (f->delay == 0) {
        if (f->index == 0 && f->done != 0)
            return;
        f->busy = 1;
        base = c + d * a[f->index].value;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < e; j++) {
                f->tiles[i][j] = (u16)(base + i * e + j);
            }
        }
        f->delay = f->reload;
        f->index++;
        if (f->index >= b) {
            f->index = 0;
            f->done = 1;
        }
    } else {
        f->delay--;
    }
}
