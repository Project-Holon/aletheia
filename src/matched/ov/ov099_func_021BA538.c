/*
 * unit:     yes
 * function: func_021BA538, func_021BA578, func_021BA590
 * address:  0x021BA538
 * packet:   pkt_ov099_021BA538
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021BA578 (counter reload leaf) and func_021BA590 (returns 0) are
 * the unlabelled leaves after the lead function (seed function_starts
 * 0x021BA578, 0x021BA590).
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021BA594  0x021BA594  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
} S;

typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
extern int func_021C49A4(u8 *p, unsigned int i);
extern void func_021BA594(char *p, int a, int b, int c);

int func_021BA538(void *w, S *s)
{
    int r;

    s->f8 = s->f8 - 1;
    if (s->f8 <= 0) {
        s->f8 = func_020056EC(0x400) + 0x100;
        r = func_020056EC(4);
        func_021BA594(w, 0, r, func_021C49A4(s->f0, 4));
    }
    return 0;
}

int func_021BA578(void *w, S *s)
{
    s->f8 = s->f8 - 1;
    if (s->f8 < 0) {
        s->f8 = 0x1c;
    }
    return 0;
}

int func_021BA590(void)
{
    return 0;
}
