#ifndef GAME_OV009_SSL_H
#define GAME_OV009_SSL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ssl.c, prototypes copied from their definitions. */

struct SOCLCaInfo;

#include "../ov009/cps_ssl_types.h"
#include "../ov009/cps_ssl_types.h"
#include "../types.h"

unsigned long date2sec(void);
unsigned long CPS_GetSslHandshakePriority(void);
void CPS_SetSslHandshakePriority(int len);
unsigned long enter_computebound(void);
void CPS_SetRootCa(struct SOCLCaInfo **rootCa, int num);
SOCLCaInfo *get_rootCA(CPSSslConnection *con, char *dn);
int chars_till_end(const char *str);
int select_method(int methods, int num, int size);
int version_ok(int major, int minor);
void finished_md5(CPSSslConnection *con, unsigned char *d, int flag);
void finished_sha1(CPSSslConnection *con, unsigned char *d, int flag);
int decrypt(CPSSslConnection *con, u8 *s, int len);
int make_ciphertext(CPSSslConnection *con, unsigned char *s);
void CPS_SslAddRandomSeed(void *random_seed, unsigned long len);
void send_change_cipher_spec_and_finished(CPSSoc *soc);
unsigned long CPSi_SslConnect(CPSSoc *soc);
unsigned char *CPSi_SslRead(unsigned long *len, CPSSoc *soc);
void CPSi_SslConsume(unsigned long len, CPSSoc *soc);
void try_fill_record(CPSSoc *soc);
long CPSi_SslGetLength(CPSSoc *soc);
unsigned long CPSi_SslWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, CPSSoc *soc);
void CPSi_SslShutdown(CPSSoc *p);
void CPSi_SslClose(CPSSoc *soc);
void CPS_SetSsl(int mode);
void CPSi_SslPeriodical(unsigned long now);
void CPSi_SslCleanup(void);
/* END mkheaders: generated region */

#endif
