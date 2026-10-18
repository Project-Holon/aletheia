/*
 * function: CryptSeqNo
 * address:  0x021B8068
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   AOSS_MALLOC  0x021B61B0  thumb
 *   AOSS_FREE    0x021B61C0  thumb
 *   MakeKey      0x021B80E4  thumb
 *   AddKey       0x021B8118  thumb
 *   Rotate       0x021B813C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol CryptSeqNo (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8068.c \
 *       --func CryptSeqNo --addr 0x021B8068 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

extern void *AOSS_MALLOC(int a);
extern void AOSS_FREE(void *a);
extern void MakeKey(int ID, char *Key, int maclen, char *Wep, int weplen);
extern void AddKey(char *Key, unsigned char *mac, int maclen);
extern void Rotate(unsigned char *mac, int maclen, char *wBuff);

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
