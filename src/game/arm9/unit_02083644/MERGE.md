# unit_02083644 (arm9)

Merge status: 2 files remain (every file verified EXACT).

- `unit_02083644_p01.c`: func_02083644 .. func_02083DC8 (NVRAM init, read, write; 0x02083644..0x02083EB8). One NVRAMWork, one NvramBss (nvramInitialized, nvramTemp) and `u8 nvramTemp[32]`.
- `unit_02083644_p02.c`: func_02083EB8 .. func_02084570 (verify, the PXI command senders, the lock dispatch; 0x02083EB8..0x020845DC). NVRAMi_IsInitialized is now plain C (`g_02150EA0.nvramInitialized == 2`), no asm.

Blocker between the two files: the `arg[3]` member of NVRAMWork. NVRAMi_WriteCallback (p01) only matches when `arg` is `volatile u32 arg[3]` (a member qualifier; a cast on each access or a local volatile pointer adds address arithmetic and 3 instructions). NVRAMi_VerifyCallback (p02) only matches when `arg` is NOT volatile (volatile gives extra reloads). The original source cannot have had one `arg` declaration for both, or the two callbacks were written differently (for example with locals). Needs a spelling of VerifyCallback that matches with a volatile `arg` (cache each arg[i] read in a local), then the files merge.