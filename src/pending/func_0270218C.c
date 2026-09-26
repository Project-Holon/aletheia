/*
 * function: func_0270218C
 * address:  0x0270218C
 * packet:   twl_wifi
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * NOT EXACT - 7 bytes differ. Two issues:
 *  1. CW allocates r1=addr, r2=val; original uses r2=addr, r1=val.
 *  2. CW if-converts the mode==1 arm to `orreq r1,r1,#0x2000 / strheq r1,[r2]`
 *     but `strheq` cannot be emitted from an asm void block (unsupported mnemonic)
 *     and cannot be forced from C without also hitting the register-swap issue.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_02004200         0x02004200  data twl a2
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enable);
extern u16 data_02004200;

void func_0270218C(s32 mode)
{
    u32 ie = OS_DisableInterrupts();
    u16 val = data_02004200;
    if (mode == 0) {
        data_02004200 = val & ~0x2000;
    } else if (mode == 1) {
        data_02004200 = val | 0x2000;
    }
    OS_RestoreInterrupts(ie);
}
