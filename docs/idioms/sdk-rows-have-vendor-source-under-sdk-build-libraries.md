# Many TwlSDK rows have their vendor source under sdk/TwlSDK/build/libraries

summary: sdk/TwlSDK/build/libraries carries about 90 vendor .c files (card, fs, fx_mtx44, os, mi, gx, wm, spi pm/tp, snd, mb, wxc, ...). Before drafting an SDK function, grep there: the vendor body usually compiles EXACT under dsi/1.1p1 with the header's types inlined.

Found in: src/matched/CARDi_IdentifyBackupCore2.c (0x020766D8), src/matched/MTX_Concat44.c (0x0207BE14)

The files are Shift-JIS; decode with `iconv -f SHIFT-JIS -t UTF-8` or
Python `decode('shift_jis')`. Drop the SDK_*_ASSERT lines (they compile away
in the ROM build). CARDi_IdentifyBackupCore2 (840 B) matched on the first
compile, with CARDiCommandArg and CARDBackupTypeInfo written out from the
image offsets. MTX_Concat44 had been a near miss at 864 B out of 956, drafted
from DWARF plus an MI_Copy64B asm guess. It closed once the vendor
`*ab = tmp;` was used (see
struct-assignment-copy-is-ldm-stm-with-spilled-pointers). The shipped source
is SDK 5.3; stop trusting it when the image and the source disagree.
Libraries with no source there (nvram, math/dgt, fx_mtx43) still need drafting
from DWARF.
