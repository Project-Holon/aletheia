/*
 * function: func_02024168
 * address:  0x02024168
 * packet:   pkt_02024168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 *
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Pair { u16 x,y; } Pair;
typedef struct Input {
    u8 mode; u8 pad01[15]; u16 values10[4]; u16 values18[2];
} Input;
void func_02024168(const Input *p,u16 *a,u16 *b) {
    Pair v;
    switch(p->mode) {
    case 0: a[0]=p->values18[0]; break;
    case 1:
        v=*(const Pair *)p->values18; *(Pair *)a=v; break;
    case 2:
        b[0]=p->values10[0]; b[1]=p->values10[1];
        v=*(const Pair *)(p->values10+2); *(Pair *)(b+2)=v; break;
    }
}
