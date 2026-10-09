/*
 * file:     unit_02181E28_p04.c
 * unit:     yes
 * function: gsiXmlUtilTagMatches
 * address:  0x02183D98
 * packet:   pkt_ov009_02183D98
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilTagMatches (gsxml.o)
 *
 * symbols:
 *   strlen                           0x0209477c arm
 *   strchr                           0x02094a28 arm
 *   strncmp                          0x020949f4 arm
 */

struct GSIXmlString
{
    unsigned char * string;  /* 0x00 */
    int length;              /* 0x04 */
};

extern unsigned int strlen(const char *s);
extern char *strchr(const char *s, int c);
extern int strncmp(const char *s1, const char *s2, unsigned int n);

static int gsiXmlUtilTagMatches(char *matchtag, struct GSIXmlString *xmlstr)
{
    char * matchNoNamespace;
    unsigned char * string;
    int xmlNamespacePos = 0;
    int matchTagLen;

    if (matchtag == 0)
        return 1;
    if (*(matchtag + strlen(matchtag) - 1) == ':')
        return 0;

    matchNoNamespace = strchr(matchtag, ':');
    if (matchNoNamespace == 0)
        matchNoNamespace = matchtag;

    while ((xmlNamespacePos < xmlstr->length) && (xmlstr->string[xmlNamespacePos] != ':'))
        xmlNamespacePos++;
    if (xmlNamespacePos == xmlstr->length)
        xmlNamespacePos = 0;
    else
        xmlNamespacePos++;

    string = xmlstr->string;
    matchTagLen = xmlstr->length - xmlNamespacePos;
    if (matchTagLen <= strlen(matchNoNamespace))
        matchTagLen = strlen(matchNoNamespace);

    return (strncmp(matchNoNamespace, (char *)(string + xmlNamespacePos), matchTagLen) == 0);
}
