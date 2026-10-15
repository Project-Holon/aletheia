/*
 * function: MISC_SAVEDATA_GetMacStructSize
 * address:  0x0200E9DC
 * packet:   pkt_0200E994
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A four-byte constant getter with no register-saving prologue; it was
 * hiding as the unlabelled follower behind MISC_SAVEDATA_FindKey's EXACT* extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). Its own
 * follower, sub_0200E9E0, already carries a label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_GetMacStructSize.c \
 *       --func MISC_SAVEDATA_GetMacStructSize --addr 0x0200E9DC --cc 1.1p1
 */

unsigned int MISC_SAVEDATA_GetMacStructSize(void)
{
    return 0x9c;
}
