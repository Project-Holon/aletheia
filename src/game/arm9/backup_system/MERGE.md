# backup_system (arm9)

Translation unit 020316C8..02034768. It is now three files:

- `backup_system_p01.c`: 020316C8..020319E4
- `backup_system_p02.c`: 020319F0..02031E70
- `backup_system_p03.c`: 02031E7C..02034768

Two ARM linker veneers sit inside the range: veneer_020319E4 and
veneer_02031E70 (12 bytes each, not part of the source). The compiler
output of one file has no gap there, so the code after a veneer would sit
12 bytes too early and every branch and literal after it would differ.
Each file therefore ends at a veneer. Joining them needs a way to place a
veneer between two functions of one file.

func_02031994 was missing from the restructure output (no member or part
held it); it is now part of `backup_system_p01.c`.
