/*
 * function: DWC_CheckProfanityExAsync
 * address:  0x0217BC44
 * packet:   pkt_ov009_0217BC44
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CheckProfanityExAsync (dwc_prof.o)
 *
 * The region letter default is the byte at 0x02FFFE0F, a literal address
 * (no relocation in the object).
 *
 * symbols:
 *   DWCi_CheckProfanityAsync  0x0217B828  arm  ov009
 */

extern int DWCi_CheckProfanityAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, char *region);

int DWC_CheckProfanityExAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region)
{
    char regionLetter;

    if (region == 0x80) {
        regionLetter = 'A';
    } else {
        regionLetter = *(char *)0x02FFFE0F;
    }
    return DWCi_CheckProfanityAsync(words, wordsnum, reserved, timeout, result, badwordsnum, &regionLetter);
}
