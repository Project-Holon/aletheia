/*
 * file:     unit_021B6D8C_p05.c
 * unit:     yes
 * function: func_021B7FF8, func_021B8030, func_021B8068, func_021B80E4, func_021B8118, func_021B813C
 * address:  0x021B7FF8
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   AOSS_MALLOC  0x021B61B0  thumb
 *   AOSS_FREE    0x021B61C0  thumb
 *   _s32_div_f  0x0209C0A4  arm
 *   AOSS_Memcpy  0x021B8230  thumb
 */
extern void *AOSS_MALLOC(int a);
extern void AOSS_FREE(void *a);
extern void *AOSS_Memcpy(void *dest, void *src, int n);
unsigned long update_crc(unsigned long crc, unsigned char *buf, int len, int crc_table_computed, unsigned long *crc_table);
void make_crc_table(int crc_table_computed, unsigned long *crc_table);
int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
void MakeKey(int ID, char *Key, int maclen, char *Wep, int weplen);
void AddKey(char *Key, unsigned char *mac, int maclen);
void Rotate(unsigned char *mac, int maclen, char *wBuff);


unsigned long update_crc(unsigned long crc, unsigned char *buf, int len,
                         int crc_table_computed, unsigned long *crc_table)
{
    unsigned long c = crc;
    int n;

    if (!crc_table_computed)
        make_crc_table(crc_table_computed, crc_table);
    for (n = 0; n < len; n++) {
        c = crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
    }
    return c;
}

void make_crc_table(int crc_table_computed, unsigned long *crc_table)
{
    unsigned long c;
    int n, k;

    for (n = 0; n < 256; n++) {
        c = (unsigned long)n;
        for (k = 0; k < 8; k++) {
            if (c & 1)
                c = 0xedb88320L ^ (c >> 1);
            else
                c = c >> 1;
        }
        *crc_table++ = c;
    }
}


int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen)
{
    int i;
    char *Key, *wBuff;

    Key = AOSS_MALLOC(Datalen / 2);
    if (Key == 0)
        return -1;
    wBuff = AOSS_MALLOC(Datalen);
    if (wBuff == 0) {
        AOSS_FREE(Key);
        return -1;
    }
    for (i = 0; i < 2; i++) {
        MakeKey(i, Key, Datalen, KeyData, Keylen);
        AddKey(Key, Data, Datalen);
        Rotate(Data, Datalen, wBuff);
    }
    AOSS_FREE(Key);
    AOSS_FREE(wBuff);
    return 0;
}

void MakeKey(int ID, char *Key, int maclen, char *Wep, int weplen)
{
    int i, size, pos;

    size = maclen / 2;
    pos = ID % weplen;
    for (i = 0; i < size; i++) {
        Key[i] = i;
        Key[i] = Key[i] ^ Wep[pos];
        pos++;
        if (pos >= weplen)
            pos = 0;
    }
}

void AddKey(char *Key, unsigned char *mac, int maclen)
{
    int i, size;

    size = maclen / 2;
    for (i = 0; i < size; i++) {
        mac[size + i] ^= Key[i];
    }
}


void Rotate(unsigned char *mac, int maclen, char *wBuff)
{
    int size;

    size = maclen / 2;
    AOSS_Memcpy(wBuff, mac + size, size);
    AOSS_Memcpy(wBuff + size, mac, size);
    AOSS_Memcpy(mac, wBuff, maclen);
}
