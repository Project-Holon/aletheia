/*
 * function: func_02073CEC
 * address:  0x02073CEC
 * packet:   pkt_02073BF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_SndStrmUpdate  0x02073BF0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct A {
    u8  p00[0x2c];
    int b0 : 1;
    int b1 : 1;
    int hi : 30;
    u8  p30[0x10];
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
};

extern void NNSi_SndStrmUpdate(struct A *, u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void func_020894B4(u32, u32, u32, u32);
void func_02073CEC(struct A *a) {
    u32 r;
    if (!a->b1) return;
    while (a->f40 != 0) {
        r = OS_DisableInterrupts();
        NNSi_SndStrmUpdate(a, 1);
        OS_RestoreInterrupts(r);
    }
    func_020894B4(a->f4c, 0, 1u << a->f48, 0);
}
