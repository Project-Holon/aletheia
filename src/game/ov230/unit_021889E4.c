/*
 * file:     unit_021889E4.c
 * unit:     yes
 * function: func_021889E4, func_02188A0C, func_02188A48
 * address:  0x021889E4
 * region:   ov230
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021899A0  0x021899A0  data  ov230
 */
typedef unsigned int u32;

asm void func_021889E4(void *addr, unsigned int size);
int func_02188A0C(unsigned word);
void func_02188A48(u32 *t);
extern char d_021899A0[];


/*
 * note:     cache maintenance over [r0, r0 + r1): per 32-byte line it
 *           invalidates the I-cache line, drains the write buffer and cleans
 *           and invalidates the D-cache line. CP15 writes have no C
 *           spelling, so this is an asm function like DC_StoreRange.
 */
asm void func_021889E4(void *addr, unsigned int size)
{
    add     r1, r1, r0
    mov     ip, #0
    bic     r0, r0, #0x1f
loc_021889F0:
    mcr     p15, 0, r0, c7, c5, 1
    mcr     p15, 0, ip, c7, c10, 4
    mcr     p15, 0, r0, c7, c14, 1
    add     r0, r0, #0x20
    cmp     r0, r1
    blt     loc_021889F0
    bx      lr
}


/*
 * extent: lead60B; larger loader follower02188A48..02188B48, then encoded payload through02188CB0.
 */
int func_02188A0C(unsigned word)
{
    unsigned char opcode=word>>24;
    if ((opcode&14)==10) {
        if ((opcode&240)==240) return 1;
        if (opcode&1) return 2;
        else return 3;
    }
    return 0;
}


void func_02188A48(u32 *t)
{
    u32 *h;
    u32 size;
    u32 *end;
    u32 key;
    u32 w;
    u32 bss;
    u32 *p;

    h = t - 3;
    h[0] = h[1] = h[2] = 0;
    bss = (u32)d_021899A0;
    do {
        p = (u32 *)(t[0] - 0x1600);
        size = t[1] - bss - 0x1600;
        end = p + size / 4;
        key = 0xF0618C46;
        for (; p < end; p++) {
            switch (func_02188A0C(*p)) {
            case 1:
            case 3:
                w = *p;
                w = ((w & 0xFF000000) ^ 0x01000000) | (((w & 0xFFFFFF) + 0xFFFFFA7E) & 0xFFFFFF);
                *p = w;
                key = (key ^ (w >> 24)) & 0xFFFFFF;
                break;
            case 2:
                *p ^= 0x01000000;
            default:
                w = *p ^ key;
                key = (key ^ w ^ (w >> 8)) & 0xFFFFFF;
                *p = w;
                break;
            }
        }
        func_021889E4((void *)(t[0] - 0x1600), size);
        t[1] = 0;
        t[0] = 0;
        t += 2;
    } while (*t != 0);
}
