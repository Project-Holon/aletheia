/*
 * file:     fld_faceup_p05.c
 * unit:     yes
 * function: func_021F57D8, func_021F5840
 * address:  0x021F57D8
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020409E0  0x020409E0  arm
 */
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    char fC[0xC];
    char f18[0xC];
} Sub;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u16 value, pad; } Row;

typedef struct { int done, busy; u8 delay, reload; u16 index; u16 tiles[2][6]; } State;

extern void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
void func_021F57D8(int a0, char *p);
void func_021F5840(Row *a, unsigned b, unsigned c, unsigned d, unsigned long e, State *f);


void func_021F57D8(int a0, char *p)
{
    Sub *q = (Sub *)(p + 0x28);
    Sub *r;

    if (q->f4 != 0) {
        func_020409E0(3, q->fC, 0xC, 0x10D);
        func_020409E0(3, q->f18, 0xC, 0x12D);
        q->f4 = 0;
    }
    r = (Sub *)(p + 0x4C);
    if (r->f4 != 0) {
        func_020409E0(3, r->fC, 8, 0x16E);
        func_020409E0(3, r->f18, 8, 0x18E);
        r->f4 = 0;
    }
}


/*
 * lever: unsigned long fifth argument restores parameter homes; nested zero-delay guard and i*e operand order fix the multiply copy. Extent ends with two alignment bytes.
 */
void func_021F5840(Row *a, unsigned b, unsigned c, unsigned d, unsigned long e, State *f)
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
