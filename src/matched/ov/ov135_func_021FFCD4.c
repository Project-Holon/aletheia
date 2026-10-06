/*
 * function: func_021FFCD4
 * address:  0x021FFCD4
 * packet:   pkt_021FFCD4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xE18];
    u16 active;
    u8 padE1A[2];
    void *buf[16];
    u8 padE5C[0xE9C - 0xE5C];
    void *main;
} Work;

extern u32 func_020307B0(void *p);

void func_021FFCD4(Work *p)
{
    int i;

    if (p->active != 0) {
        if (p->main != 0) {
            func_020307B0(p->main);
            p->main = 0;
        }
        for (i = 0; i < 16; i++) {
            if (p->buf[i] != 0) {
                func_020307B0(p->buf[i]);
                p->buf[i] = 0;
            }
        }
    }
}
