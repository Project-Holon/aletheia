# gfl_use (arm9)

9 parts left (was 5 parts + 5 members). Round 3 merged 0200545C..0200566C with the 0200567C part after unifying GflSys/GflHeaps (one global g_020AA194, prototypes of func_02030D28 and func_02030DA8).

The remaining boundaries are real: ARM linker veneers (ldr pc,[pc,#-4]) at 020053E4, 02005420/28, 02005454 and the ARM function at 02005B6C interleave with Thumb code, so isa differs between neighbours (settings).