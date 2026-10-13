/*
 * file:     unit_020461D4.c
 * unit:     no
 * function: MSGDATA_SetLanguage
 * address:  0x020461D4
 * packet:   pkt_02045C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_Byte_02146A54  0x02146A54  data
 *
 * The one-byte global setter that closes pkt_02045C44.  It saves nothing,
 * so disasm.py folded it into MSGDATA_GetLanguageIndex's extent and reported that
 * function as EXACT* until this file existed
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x020461D4
 * wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_SetLanguage.c \
 *       --func MSGDATA_SetLanguage --addr 0x020461D4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

extern u8 g_Byte_02146A54;

/* Stores the current text language code.  The getter at 0x020461E4 returns
 * this byte; the message bank loader (msgdata.c) clamps it to the language
 * count of the file it opens, and the config code and the save-control
 * screen set it. */
void MSGDATA_SetLanguage(u8 languageId)
{
    g_Byte_02146A54 = languageId;
}
