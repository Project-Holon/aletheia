/*
 * function: BTLV_INPUT_BgScrollOffsetTaskMain
 * address:  0x022049C8
 * packet:   pkt_ov094_022049C8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02040618  0x02040618  arm
 *   func_02040588  0x02040588  arm
 *   BTLV_INPUT_DeleteTask  0x0220687C  thumb  ov094
 */
typedef unsigned char u8;

typedef struct Ctx {
    void *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Ctx;

typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_BgScrollOffsetTaskMain(int a0, Ctx *c)
{
    if (c->f4 != -1) {
        func_02040618((u8)c->f4, (int)0, (int)c->f8);
        func_02040618((u8)c->f4, (int)3, (int)c->fc);
    }
    if (c->f10 != 2) {
        func_02040588((int)4, (u8)c->f10);
    }
    if (c->f14 != 2) {
        func_02040588((int)5, (u8)c->f14);
    }
    if (c->f18 != 2) {
        func_02040588((int)6, (u8)c->f18);
    }
    if (c->f1c != 2) {
        func_02040588((int)7, (u8)c->f1c);
    }
    BTLV_INPUT_DeleteTask(c->main, (void *)a0);
}
