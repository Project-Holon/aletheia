/*
 * file:     unit_021BD170_p01.c
 * unit:     yes
 * function: func_021BD1D4, func_021BD214
 * address:  0x021BD1D4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD170  0x021bd170  arm  ov016
 *   func_021D4B68  0x021d4b68  arm  ov016
 *   func_020862F0  0x020862f0  arm
 *   func_021D4C68  0x021d4c68  arm  ov016
 *   func_021C0E64  0x021c0e64  arm  ov016
 *   func_021D0040  0x021d0040  arm  ov016
 *   func_021D05BC  0x021d05bc  arm  ov016
 */
extern unsigned char *func_021BD170(unsigned char *name);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void func_020862F0(void *startAddr, unsigned long nBytes);
extern void func_021D4C68(void *file);
extern void func_021C0E64(void **param0, void **param1);
extern void func_021D0040(int step);
extern void func_021D05BC(int step);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
void func_021BD214(int step);


void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long))
{
    char *n;
    unsigned long size;
    void *data;

    n = (char *)func_021BD170((unsigned char *)file);
    data = func_021D4B68(n, &size, 4);
    func_020862F0(data, size);
    func(data, 0, size);
    func_021D4C68(data);
}


void func_021BD214(int step)
{
    int prm;

    func_021C0E64((void **)&prm, 0);
    if (prm == 1)
        func_021D0040(step);
    else if (prm == 2)
        func_021D05BC(step);
}
