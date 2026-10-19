/*
 * function: SPLAnim_Texture
 * address:  0x02057B5C
 * packet:   pkt_02057B5C
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * wave r8 lane rigD: the wave r6 residue (80 bytes, register plan) is closed.
 *
 * The frame is a symptom, not a target: `push {r4,r5,lr}` + `sub sp, sp, #4`
 * is what mwcc emits for ANY function that needs r4 and r5 (12 bytes of
 * saves, realigned to 16).  So the job is to make the pointer land in r5,
 * and the lever is the wave r6 note's "r5-resident pointer": the loop must
 * carry TWO step values.  `end += p->step` in the loop update (the field,
 * re-read) together with a `step` local used by the test gives the fourth
 * live value the frame needs; with only one spelling of step the compiler
 * merges them and emits 80 bytes with `push {r4, lr}`.
 *
 * Two more spellings, each worth real bytes:
 *  - `i = 0;` is a statement before the guard and `end = 0;` sits after it,
 *    so the scheduler keeps `mov r4, #0` above the test and `mov lr, r4`
 *    in the loop preheader (both in the for-header comes out 100 bytes but
 *    28 bytes wrong).
 *  - the loop's continuation test reads `p->n` (the field) while the guard
 *    tests the local `n`: that is what assigns n to r3 and step to ip.
 *    Testing `n` in both places is 6 bytes out (n and step swap registers);
 *    everything else in the function is already right at that point.
 *
 * `-proc arm946e` measured, not assumed: at `arm7tdmi` (this range's
 * proc_hints entry) the same source is 41 bytes out at the same 100-byte
 * size; wave r6's measurement of the family's small rows holds for this row.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;

struct P {
    u8 vals[8];
    u8 n;
    u8 step;
};

struct O {
    char _00[0x2c];
    u8 f2c;
};

struct S {
    char _00[0x10];
    struct P *f10;
};

void SPLAnim_Texture(struct O *o, struct S *s, int t)
{
    struct P *p;
    int i;
    int end;
    int n;
    int step;

    p = s->f10;
    i = 0;
    n = p->n;
    if (n <= 0) {
        return;
    }
    step = p->step;
    end = 0;
    do {
        if (t < end + step) {
            o->f2c = p->vals[i];
            return;
        }
        i++;
        end += p->step;
    } while (i < p->n);
}
