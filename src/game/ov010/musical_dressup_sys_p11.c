/*
 * file:     musical_dressup_sys_p11.c
 * unit:     yes
 * function: func_02156F24, func_02156F68
 * address:  0x02156F24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F8480  0x021F8480  thumb ov132
 *   func_021F879C  0x021F879C  thumb
 *   func_021F8640  0x021F8640  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172754  0x02172754  data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Stage {
    void *f00;          /* 0x00 */
    void *f04[4];       /* 0x04 */
    u8 pad14[0x20 - 0x14];
} Stage;

extern u8 *func_021F8480(u8 *input, int heap);
extern int func_021F879C(int);
extern void func_021F8640(int);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
int func_02156F24(int a, int *state, int c, int *d);
Stage *func_02156F68(u32 heap, void *p);
extern const char d_02172754[];


int func_02156F24(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = (int)func_021F8480((u8 *)d[0], 0x2e);
        *state = 1;
        break;
    case 1:
        if (func_021F879C(d[1]) == 1)
            *state = 2;
        break;
    case 2:
        func_021F8640(d[1]);
        return 1;
    }
    return 0;
}


Stage *func_02156F68(u32 heap, void *p)
{
    Stage *s;
    u8 i;

    s = func_02030734(heap, 0x20, 0, d_02172754, 0xBE);
    s->f00 = p;
    for (i = 0; i < 4; i++)
        s->f04[i] = 0;
    return s;
}
