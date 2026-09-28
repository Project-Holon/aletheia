# A chained assignment stores the rightmost target first

summary: `a = b = x;` emits the store to `b` before the store to `a`, so when the image writes a field and then its backup copy, the source chain names the backup on the left (`ctx->fat_bak = ctx->fat = fat;`); the other order swaps the two stores and nothing else.

Found in: src/matched/FS_LoadArchive.c (0x0207A4B0)

FS_LoadArchive stores `fnt` to +0x34 (fnt) and then +0x40 (fnt_bak), and `fat`
to +0x2c (fat) and then +0x3c (fat_bak). `context->fat = context->fat_bak =
fat;` gives the four stores in the opposite pairs (4 lines out, same length);
`context->fat_bak = context->fat = fat;` is EXACT.
