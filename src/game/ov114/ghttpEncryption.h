#ifndef GAME_OV114_GHTTPENCRYPTION_H
#define GAME_OV114_GHTTPENCRYPTION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ghttpEncryption.c, prototypes copied from their definitions. */

#include "../ov009/cps_ssl_types.h"
#include "../ov114/ghttp_types.h"
#include "../ov114/ghttp_types.h"

int ghttpSetRequestEncryptionEngine(int request, int engine);
int ghiEncyptorSetRootCAList(char *url, void *theRootCAList);
int ghiEncryptorCleanupRootCAList(char *url);
int ghiCompareCertUrl(void *a, void *b);
void *ghiEncryptorGetRootCAList(char *url);
void ghiFreeCertificateInfo(void *element);
int ghiEncryptorSetTwlRootCA(char *url, void *theRootCAList);
int ghiEncryptorCleanupTwlRootCA(char *url);
int SslAuthCallback(int result, CPSSslConnection *con, int level);
CPSSslConnection *ghiTwlSSLInit(char *url);
int ghiEncryptorSslInitFunc(GHIConnection *connection, GHIEncryptor *theEncryptor);
int ghiEncryptorSslStartFunc(GHIConnection *connection, GHIEncryptor *theEncryptor);
int ghiEncryptorSslSendFunc(void *connection, void *encryptor, char *buffer, int bufferLen, int *bytesSent);
int ghiEncryptorSslReceiveFunc(void *connection, void *encryptor, char *buffer, int *bufferLen);
int ghiEncryptorSslEncryptFunc(GHIConnection *connection, void *encryptor, const char *plainText, int plainTextLen, char *cipherText, int *cipherTextLen);
int ghiEncryptorSslDecryptFunc(GHIConnection *connection, void *encryptor, char *readPos, int *readLen, char *writePos, int *writeLen);
int ghiEncryptorSslCleanupFunc(GHIConnection *connection, GHIEncryptor *encryptor);
/* END mkheaders: generated region */

#endif
