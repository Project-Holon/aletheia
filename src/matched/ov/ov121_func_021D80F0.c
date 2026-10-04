/*
 * function: func_021D80F0
 * address: 0x021D80F0
 * packet: pkt_ov121_021D80F0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D6E3C 0x021D6E3C thumb ov121
 */
typedef unsigned char u8;
extern void func_021D9F08(u8 *, int, int, int);
typedef unsigned int   u32;
extern unsigned func_021D9FF8(u8 *p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021D6E3C(void *task, u32 *state, u8 *p);
void func_021D80F0(void *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: func_021D9F08(*(u8 **)(p + 0x284), *(int *)(p + 0x3a0), 22, 1); *state = 1; break;
    case 1: if (func_021D9FF8(*(void **)(p + 0x284))) func_021DA8B0(a, (u32)func_021D6E3C); break;
    }
}
