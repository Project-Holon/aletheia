# unit_020898A8.c (arm9)

Remaining after the merge lane: 3 part file(s) and 4 member file(s) in this folder.

Why it is not one file:

snd_command.o statics are viewed through partial SNDCommandState structs with different field sets in each member (sFreeList), plus SND_* macros and prototypes that differ (SND_FlushCommand, SND_RecvCommandReply, OS_DisableInterrupts). Unifying needs one full SndCommandBss layout (offsets +0 freeList .. +0x20 currentTag, see func_020898A8) and renamed field accesses in every member.

Members left in this folder, in address order:

- `func_020898A8.c`
- `func_02089978.c`
- `SND_FlushCommand.c`
- `func_02089DBC.c`
