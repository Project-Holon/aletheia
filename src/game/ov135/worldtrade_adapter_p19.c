/*
 * file:     worldtrade_adapter_p19.c
 * unit:     yes
 * function: func_021FE974, func_021FE9B0
 * address:  0x021FE974
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020061E4 0x020061E4 thumb
 *   func_02034714  0x02034714  arm
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    unsigned char pad0[0x24];
    int f24;
    int f28;
    int f2C;
} State;

typedef struct {
    unsigned char pad0[0xE00];
    State *st;
} Work;

extern void func_021FF318(u8 *p, u32 k, int b, int c, int d);
extern void func_021F4E98(char *,unsigned,unsigned);
extern void func_021F4EC0(void *,unsigned,unsigned);
extern void func_020061E4(int);
extern void func_02034714(const char *expr, u32 line, const char *file);
int func_021FE974(char *p);
int func_021FE9B0(Work *p);

int func_021FE974(char *p) {func_021FF318((u8 *)p,172,4,0,0xf0f);func_021F4E98(p,24,3);func_021F4EC0(p,0,21);func_020061E4(0x557);return 2;}


/*
 * Return the current cursor slot of the state block at +0xE00: the +0x28
 * word while the +0x24 flag is clear, else the +0x2C word plus four.
 * A slot of seven or more reports through func_02034714 (the raw-address
 * assert shape; 0x02203E2C is a plain constant, as in func_02202B20).
 */
int func_021FE9B0(Work *p)
{
    State *s = p->st;
    int r;

    if (s->f24 == 0) {
        r = s->f28;
    } else {
        r = s->f2C + 4;
    }
    if (r >= 7) {
        func_02034714((void *)0x02203E2C, 0, (void *)0x02203E2C);
    }
    return r;
}
