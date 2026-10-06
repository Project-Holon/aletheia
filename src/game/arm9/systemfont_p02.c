/*
 * file:     systemfont_p02.c
 * unit:     yes
 * function: func_020463C0, func_020463D8, func_020463E0
 * address:  0x020463C0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146A58   0x02146A58  data
 */
typedef unsigned char u8;

typedef unsigned int  u32;

struct Ctx {
    u8  pad_00[4];
    u32 unk_04;
    u32 unk_08;
};

int func_020463C0(void);
int func_020463D8(void);
void func_020463E0(u32 x, u32 y);
extern struct Ctx *g_02146A58;

int func_020463C0(void){ return *(unsigned char *)((*(int *)(*(int *)(0x2146A58)) + 13)); }

int func_020463D8(void){ return 7; }


/*
 * Replicate a fill byte across a word, twice: both arguments are multiplied
 * by 0x11111111 and the two products go into the context's +4 and +8 words.
 * mwccarm expands the constant multiply into a chain of `orr`s with shifted
 * operands rather than spending a `mul`, and the left-associative nesting
 * puts the bare copy of the value in the last `orr` of each chain, so the
 * shift amounts run 24, 28, 20, 16, 12, 8, 4 and then a plain register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020463E0.c \
 *       --func func_020463E0 --addr 0x020463E0 --cc 1.1p1 --arm
 */
void func_020463E0(u32 x, u32 y)
{
    g_02146A58->unk_04 = (x << 28) | (x << 24) | (x << 20) | (x << 16) |
                         (x << 12) | (x << 8) | (x << 4) | x;
    g_02146A58->unk_08 = (y << 28) | (y << 24) | (y << 20) | (y << 16) |
                         (y << 12) | (y << 8) | (y << 4) | y;
}
