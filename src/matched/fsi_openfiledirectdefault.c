/*
 * function: FSi_OpenFileDirectDefault
 * address:  0x02079B70
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (36 bytes, no relocation):
 *   ldr r3, [r0, #0x30]
 *   ldr r2, [r0, #0x34]
 *   ldr r1, [r0, #0x38]
 *   str r3, [r0, #0x24]
 *   str r3, [r0, #0x2c]
 *   str r2, [r0, #0x28]
 *   str r1, [r0, #0x20]
 *   mov r0, #0
 *   bx  lr
 */

typedef unsigned int u32;

int FSi_OpenFileDirectDefault(void *p)
{
    u32 a = *(u32 *)((char *)p + 0x30);
    u32 b = *(u32 *)((char *)p + 0x34);
    u32 c = *(u32 *)((char *)p + 0x38);
    *(u32 *)((char *)p + 0x24) = a;
    *(u32 *)((char *)p + 0x2c) = a;
    *(u32 *)((char *)p + 0x28) = b;
    *(u32 *)((char *)p + 0x20) = c;
    return 0;
}
