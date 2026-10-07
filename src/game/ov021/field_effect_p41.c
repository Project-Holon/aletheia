/*
 * file:     field_effect_p41.c
 * unit:     yes
 * function: func_021AB840, func_021AB868
 * address:  0x021AB840
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A39C  0x0204A39C  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

typedef struct {
    int f0;
    u32 f4;
    int f8[2];
} S_021AB840;

typedef struct {
    void *f0;
    int f4;
} S_021AB868;

extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 func_020307B0(void *p);
void func_021AB840(S_021AB840 *s, int i, int b, int d);
void func_021AB868(S_021AB868 *s);


void func_021AB840(S_021AB840 *s, int i, int b, int d)
{
    u32 out;
    s->f0 = (int)func_0204A39C((void *)s->f8[i], b, 0, d, &out);
    s->f4 = out / 0x48;
}


void func_021AB868(S_021AB868 *s)
{
    if (s->f0 != 0) {
        func_020307B0(s->f0);
        s->f0 = 0;
        s->f4 = 0;
    }
}
