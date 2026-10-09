# unit_02079304 (arm9)

Merge status: 2 files remain (every file verified EXACT).

- `unit_02079304_p01.c`: func_02079304 .. FS_LoadArchive (0x02079304..0x0207A51C), one canonical FS type block (FSResult, FSArchive, FSFile, FSROMFAT* structs). Includes the hidden function func_02079BF4 (`return FS_RESULT_SUCCESS;`, the do-nothing handler in FSi_TranslateCommand's default_table).
- `unit_02079304_p02.c`: func_0207A528 .. func_0207A7A8 (0x0207A528..0x0207A7B8).

Real boundary: a 12-byte linker veneer at 0x0207A51C (`ldr ip, [pc]; bx ip; .word 0x02078588`) sits between FS_LoadArchive and func_0207A528. It is not source code, so the two files stay split.

Left over: FSi_ROMFAT_GetFileLength, FSi_ROMFAT_GetFilePosition, FSi_ROMFAT_GetArchiveCaps and FSi_ROMFAT_CloseDirectory are still stand-ins with `void *` parameters and offset arithmetic; their field meaning (the file argument holds a pointer to the file property at +4) is not settled.