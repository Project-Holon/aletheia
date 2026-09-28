/*
 * function: func_02027FD8
 * address:  0x02027FD8
 * packet:   pkt_02027A04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct TaskMenuState {
    u8 pad[8];
    void *child;
};

extern void sub_020307B0(void *p);

void func_02027FD8(struct TaskMenuState *s)
{
    sub_020307B0(s->child);
    sub_020307B0(s);
}
