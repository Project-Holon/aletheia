#ifndef GAME_OV016_AOSS_H
#define GAME_OV016_AOSS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of aoss.c, prototypes copied from their definitions. */

struct aoss_info;
typedef struct aoss_info AOSS_INFO;

#include "../ov016/wlla_types.h"

void *AOSS_MALLOC(int size);
void AOSS_FREE(void *mem);
int AOSSi_Init(struct aoss_info *aossInfo);
int AOSS_Init_old(struct aoss_info *aossInfo);
unsigned long aoss_IP_sta(unsigned long ipAp, unsigned long nMask);
void aoss_release(void);
void aoss_data_init(AOSS_INFO *aossInfo);
void aoss_set_error(unsigned int type);
unsigned int aoss_get_error(void);
int AOSS_seq_data_copy(struct aoss_info *aossInfo);
int aoss_check_str(char *ptr, int count);
int checkAP(WLLA_BSS_LIST *list);
int AOSS_set_APInfo(WLLA_CONNECT_PARAM *ap);
int AOSS_StatusExclusion(int stat);
int DecodePacket(unsigned char *tpkt);
int CheckSeqID(unsigned short CMD, unsigned char *RecvSeqID);
int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID);
unsigned long aoss_get_bin(void *ptr, int num);
short SetStaData(char *StaData);
void PacketDataSet(int Type, unsigned char *pData, unsigned char *pPlaneData, short *packet_size, short *CryptType, unsigned char *crc8);
int SendPacketUDP(unsigned char *packet, int size, unsigned char Mac, int port);
int EncodeRC4(unsigned char *srcData, unsigned char *EncodeData, int SizeOfData, unsigned char *CRC, unsigned char *iv, unsigned char *key, int keylen);
int DecodeRC4(unsigned char *srcData, unsigned char *DecodeData, int SizeOfData, unsigned char CRC, unsigned char *iv, unsigned char *key, int keylen);
unsigned char crc(unsigned char *buf, int len);
unsigned long update_crc(unsigned long crc, unsigned char *buf, int len, int crc_table_computed, unsigned long *crc_table);
void make_crc_table(int crc_table_computed, unsigned long *crc_table);
int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
void MakeKey(int ID, char *Key, int maclen, char *Wep, int weplen);
void AddKey(char *Key, unsigned char *mac, int maclen);
void Rotate(unsigned char *mac, int maclen, char *wBuff);
int AOSS_SetIPAddr(unsigned long ip, unsigned long sm, unsigned long gw);
int AOSS_Disconnect(void);
int AOSS_Memcmp(void *s1, void *s2, int n);
void AOSS_Memcpy(void *dest, void *src, int n);
void AOSS_Memset(void *s, int c, int n);
int AOSS_Recvfrom(int s, void *buf, int len, int flags, void *from, int *fromlen);
int AOSS_Sendto(int s, void *msg, int len, int flags, void *to, int tolen);
int AOSS_Setsockopt(int s, int level, int optname, void *optval, int optlen);
int AOSS_Socket(int domain, int type, int protocol);
int AOSS_Bind(int s, void *addr, int addrlen);
int AOSS_Close(int fd);
unsigned long AOSS_Htonl(unsigned long hostlong);
unsigned short AOSS_Htons(unsigned short hostshort);
unsigned long AOSS_Ntohl(unsigned long netlong);
unsigned short AOSS_Ntohs(unsigned short netshort);
int AOSS_Strlen(char *s);
int AOSS_Rand(void);
/* END mkheaders: generated region */

#endif
