/*
 * function: func_021BD1D4
 * address:  0x021BD1D4
 * packet:   pkt_ov016_021BD1D4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CMNlLoadResource (libdwcutil.TWL.HYB.a(common.o))
 *
 * symbols:
 *   func_021BD170  0x021bd170  arm  ov016
 *   func_021D4B68  0x021d4b68  arm  ov016
 *   func_020862F0  0x020862f0  arm
 *   func_021D4C68  0x021d4c68  arm  ov016
 */

extern char *func_021BD170(char *name);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void func_020862F0(void *startAddr, unsigned long nBytes);
extern void func_021D4C68(void *file);

void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long))
{
    char *n;
    unsigned long size;
    void *data;

    n = func_021BD170(file);
    data = func_021D4B68(n, &size, 4);
    func_020862F0(data, size);
    func(data, 0, size);
    func_021D4C68(data);
}
