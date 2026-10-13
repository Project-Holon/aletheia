/*
 * function: ParseSignHash
 * address:  0x021CA734
 * packet:   pkt_ov114_021CA734
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ParseSignHash (sign.o)
 *
 * symbols:
 *   ASN1Skip  0x021CA5E4  arm  ov114
 */

extern int ASN1Skip(unsigned char **datap, unsigned int *dlenp, unsigned char type, unsigned int *lenp);

int ParseSignHash(unsigned char *data, unsigned int dlen, unsigned char **ppdgst_adrs, unsigned int *pdgst_size, unsigned char **pphash_adrs, unsigned int *phash_size)
{
    unsigned int len;

    if (!ASN1Skip(&data, &dlen, 0x30, 0))
        return 0;
    if (!ASN1Skip(&data, &dlen, 0x30, 0))
        return 0;
    if (!ASN1Skip(&data, &dlen, 0x06, &len))
        return 0;
    if (ppdgst_adrs)
        *ppdgst_adrs = data;
    if (pdgst_size)
        *pdgst_size = len;
    data += len;
    if (dlen < len)
        return 0;
    dlen -= len;
    if (!ASN1Skip(&data, &dlen, 0x05, &len))
        return 0;
    data += len;
    if (dlen < len)
        return 0;
    dlen -= len;
    if (!ASN1Skip(&data, &dlen, 0x04, &len))
        return 0;
    if (dlen != len)
        return 0;
    if (pphash_adrs)
        *pphash_adrs = data;
    if (phash_size)
        *phash_size = len;
    return 1;
}
