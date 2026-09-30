/*
 * function: func_02182554
 * address:  0x02182554
 * packet:   pkt_ov009_02182554
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (capped - see residue)
 *
 * residue (lane T3, 2026-09-30, measured): compiled 224 vs 232 (-8). First diff +0050 image `ldr r3, [r6]` | ours `ldr r2, [r6]`: the image re-reads *pos into a fresh r3 and tests buffer[*pos] through [r8,r3], ours CSEs *pos into r2 and reads through the computed strStart pointer [r4]. Downstream the image also keeps a rotated-loop entry test (`bne` body entry then a same-flags `beq` exit) that ours does not emit. Pin/flag sweep (9x7) best -O4,p at 78 diffs; every other flag worse (101-239). Not re-spelled (budget).
 *
 * sdk:      gsiXmlUtilParseString (gsxml)
 *
 * symbols:
 *   gsiXmlUtilSkipWhiteSpace  0x02181E28 arm ov009
 *   gsiXmlUtilDecodeString    0x0218263C arm ov009
 *
 * note: near miss, 78 bytes differ: original reloads *pos into r3 before each buffer[*pos] read in the peeled first iteration (ldrsb r0,[r8,r3]) and its scan loop tests buffer[*pos] after pos++/length++ with a separate empty-string exit that sets strOut->string without decoding; C form here CSEs the read through r4 and orders the loop tail differently
 */

struct GSIXmlString
{
    char * string;  /* 0x00 */
    int length;     /* 0x04 */
};

extern int gsiXmlUtilSkipWhiteSpace(void *stream, char *buffer, int len, int *pos);
extern int gsiXmlUtilDecodeString(char *buffer, int *len);

int func_02182554(void *stream, char *buffer, int len, int *pos, struct GSIXmlString *strOut)
{
    char *strStart;
    char startCh;

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    startCh = buffer[*pos];
    if (startCh != '"' && startCh != '\'')
        return 0;
    (*pos)++;
    strOut->length = 0;
    strStart = &buffer[*pos];
    if (*pos >= len)
        return 0;
    if (buffer[*pos] == startCh)
    {
        strOut->string = strStart;
        (*pos)++;
        return 1;
    }
    for (;;)
    {
        if (*pos >= len)
            return 0;
        (*pos)++;
        strOut->length++;
        if (buffer[*pos] == startCh)
            break;
    }
    (*pos)++;
    if (!gsiXmlUtilDecodeString(strStart, &strOut->length))
        return 0;
    strOut->string = strStart;
    return 1;
}
