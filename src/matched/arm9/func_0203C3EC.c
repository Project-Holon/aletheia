/*
 * function: func_0203C3EC
 * address:  0x0203C3EC
 * packet:   pkt_0203C3EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf (saves no register, so disasm.py gives it no func_
 * label): a channel-id classifier that reads the pointer at g_021469DC, then
 * the u32 at +8 of the record, and maps five distinct table addresses to
 * 0/1/3/4/5 (anything else returns 2).
 *
 * The five constants sit in their own pool words at 0x0203C450..0x0203C460
 * and are each loaded with `ldr` from pc, so they are link-time absolute
 * (R_ARM_ABS32) values that the compiler cannot fold against one another.
 * They are spelled as the addresses of the matched arm9 functions that live
 * at those addresses, taken as integers, so each becomes its own relocation
 * and no `sub`/constant-fold is possible.
 *
 * symbols:
 *   func_0203C3EC  0x0203C3EC  arm
 *   g_021469DC     0x021469DC  data  a4
 *   func_0203C0F4  0x0203C0F4  arm
 *   func_0203C0B4  0x0203C0B4  arm
 *   func_0203C068  0x0203C068  arm
 *   func_0203C060  0x0203C060  arm
 *   func_0203C064  0x0203C064  arm
 */

typedef struct Hdr021469DC {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int v8;
} Hdr021469DC;

extern unsigned int g_021469DC;
extern void func_0203C0F4(void *p);
extern void func_0203C0B4(void);
extern void func_0203C068(void);
extern void func_0203C060(void);
extern void func_0203C064(void);

int func_0203C3EC(void)
{
    Hdr021469DC **pp = (Hdr021469DC **)(&g_021469DC);
    unsigned int v = (*pp)->v8;

    if (v == (unsigned int)(void *)func_0203C0F4) {
        return 0;
    }
    if (v == (unsigned int)(void *)func_0203C0B4) {
        return 1;
    }
    if (v == (unsigned int)(void *)func_0203C068) {
        return 3;
    }
    if (v == (unsigned int)(void *)func_0203C060) {
        return 4;
    }
    if (v == (unsigned int)(void *)func_0203C064) {
        return 5;
    }
    return 2;
}
