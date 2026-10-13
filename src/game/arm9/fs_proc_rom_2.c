/*
 * file:     fs_proc_rom_2.c
 * unit:     yes
 * function: FSi_ReadDummyCallback, FSi_WriteDummyCallback, FSi_SeekDummyCallback
 * address:  0x0207AAF8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
int FSi_ReadDummyCallback(void);
int FSi_WriteDummyCallback(void);
int FSi_SeekDummyCallback(void);

/*
 * sdk:      FSi_ReadDummyCallback (libfs.TWL.HYB.a fs_proc_rom.o, static; no catalog row, named by the ABS32 relocation of its caller)
 */
int FSi_ReadDummyCallback(void)
{
    return 4;
}

/*
 * sdk:      FSi_WriteDummyCallback (libfs.TWL.HYB.a fs_proc_rom.o, static; no catalog row, named by the ABS32 relocation of its caller)
 */
int FSi_WriteDummyCallback(void)
{
    return 4;
}

int FSi_SeekDummyCallback(void)
{
    return 0;
}
