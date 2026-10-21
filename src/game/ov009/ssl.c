/*
 * file:     ssl.c
 * unit:     yes
 * function: find_session_from_id, find_session_from_IP, cache_session, purge_session, date2sec, CPS_GetSslHandshakePriority, CPS_SetSslHandshakePriority, enter_computebound, exit_computebound, CPS_SetRootCa, get_rootCA, cert_item_len, make_dn, parse_time, cert_item, validate_signature, auth_cert, chars_till_end, compare_fqdn, rcv_certificate, rcv_server_hello, has_method, select_method, version_ok, client_hello_v2, client_hello, decrypt_premaster_secret, create_ms_sub, create_master_secret, create_key_block, rcv_client_key_exchange, finished_md5, finished_sha1, rcv_finished, add1_be8, decrypt, make_plaintext, make_ciphertext, tcp_read_raw_nbytes, update_digest, parse_record_in_buf, parse_record, set_random, CPS_SslAddRandomSeed, send_change_cipher_spec_and_finished, send_client_hello, send_client_key_exchange, mustget_change_cipher_spec_and_finished, ssl_connect_try, CPSi_SslConnect, CPSi_SslRead, CPSi_SslConsume, try_fill_record, CPSi_SslGetLength, CPSi_SslWrite2, CPSi_SslShutdown, CPSi_SslClose, CPS_SetSsl, CPSi_SslPeriodical, CPSi_SslCleanup
 * address:  0x0215FDA4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   memcmp  0x020923F0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gCpsSslSessionCache  0x021AA664  data
 *   OS_GetTick  0x020870D0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_GetTick            0x020870D0  arm
 *   MI_CpuCopy8           0x02082D44  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   RTC_GetDate  0x02088864  arm
 *   RTC_GetTime  0x0208890C  arm
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   OS_GetThreadPriority  0x02085A30  arm
 *   OS_SetThreadPriority  0x02085988  arm
 *   gCpsSslConfig  0x021A1D40  data
 *   OS_SetThreadPriority  0x02085988  arm
 *   OSi_ThreadInfo        0x02150FEC  data
 *   strcmp  0x020948E0  arm
 *   cert_item_len  0x0216017C  arm  ov009
 *   strlen         0x0209477C  arm
 *   memcmp         0x020923F0  arm
 *   make_dn        0x021601CC  arm  ov009
 *   parse_time     0x02160238  arm  ov009
 *   sSslObject         0x021A1D48  data
 *   CPSi_big_from_char  0x02164CC4  arm  ov009
 *   CPSi_big_power  0x0216469C  arm  ov009
 *   exit_computebound  0x021600E4  arm  ov009
 *   CPSi_char_from_big  0x02164D20  arm  ov009
 *   CPSiAlloc     0x021A8280  data
 *   CPSiFree     0x021A82B0  data
 *   CPSi_md5_init  0x021633F0  arm  ov009
 *   CPSi_md5_calc  0x02163438  arm  ov009
 *   CPSi_md5_result  0x021634F0  arm  ov009
 *   CPSi_sha1_init  0x02163C9C  arm  ov009
 *   CPSi_sha1_calc  0x02163CF0  arm  ov009
 *   CPSi_sha1_result  0x02163DA8  arm  ov009
 *   RTC_GetDate        0x02088864  arm
 *   auth_cert          0x0216090C  arm  ov009
 *   compare_fqdn       0x02160A10  arm  ov009
 *   validate_signature 0x02160764  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   CPSi_big_from_char  0x02164CC4 arm ov009
 *   CPSi_big_montpower  0x02164AA8 arm ov009
 *   CPSi_big_sub        0x021640B8 arm ov009
 *   CPSi_big_mult       0x02164230 arm ov009
 *   CPSi_big_add        0x02163F7C arm ov009
 *   CPSi_big_sign       0x02163F4C arm ov009
 *   CPSi_big_negate     0x02164078 arm ov009
 *   CPSi_big_div        0x021644D0 arm ov009
 *   CPSi_char_from_big  0x02164D20 arm ov009
 *   CPSiAlloc           0x021A8280 data
 *   CPSiFree            0x021A82B0 data
 *   CPSi_sha1_init    0x02163C9C  arm
 *   CPSi_sha1_calc    0x02163CF0  arm
 *   CPSi_sha1_result  0x02163DA8  arm
 *   CPSi_md5_init     0x021633F0  arm
 *   CPSi_md5_calc     0x02163438  arm
 *   CPSi_md5_result   0x021634F0  arm
 *   gCpsSslSaltA     0x021A1D8C  data
 *   gCpsSslSaltB     0x021A1D90  data
 *   gCpsSslSaltC     0x021A1D94  data
 *   CPSi_rc4_init     0x02163E40  arm
 *   gCpsSslServerId     0x021A1D98  data
 *   gCpsSslClientId     0x021A1DA0  data
 *   CPSi_rc4_crypt  0x02163EB8  arm  ov009
 *   MI_CpuFill8                     0x02082BCC  arm
 *   CPSi_rc4_crypt   0x02163EB8  arm  ov009
 *   CPSi_TcpReadRaw  0x0215AE18  arm  ov009
 *   CPSi_SocConsumeRaw  0x0215AF14  arm  ov009
 *   client_hello             0x02160EE0  arm  ov009
 *   rcv_server_hello         0x02160C9C  arm  ov009
 *   rcv_certificate          0x02160A7C  arm  ov009
 *   rcv_finished             0x02161678  arm  ov009
 *   CPSi_TcpReadRaw       0x0215AE18  arm
 *   CPSi_SocConsumeRaw    0x0215AF14  arm
 *   tcp_read_raw_nbytes   0x02161BE8  arm
 *   client_hello_v2       0x02160E1C  arm
 *   CPS_SslAddRandomSeed  0x02162248  arm  ov009
 *   CPSi_sha1_result_prng  0x02163E10  arm  ov009
 *   pool_initialized  0x021AA648  data
 *   gCpsSslRandCtx  0x021A82E4  data
 *   sSslPool  0x021AA650  data
 *   update_digest  0x02161C54  arm  ov009
 *   make_ciphertext  0x021619CC  arm  ov009
 *   CPSi_TcpWrite2Raw  0x0215B198  arm  ov009
 *   CPSi_TcpWrite2Raw   0x0215B198 arm ov009
 *   set_random          0x02162128 arm ov009
 *   enter_computebound  0x0216009C arm ov009
 *   CPSi_big_power      0x0216469C arm ov009
 *   alert_nocert        0x021A1980 data
 *   parse_record  0x02161F98  arm  ov009
 *   create_key_block  0x021612C8  arm  ov009
 *   mustget_change_cipher_spec_and_finished  0x0216286C  arm  ov009
 *   send_client_key_exchange  0x021625B8  arm  ov009
 *   create_master_secret  0x02161264  arm  ov009
 *   cache_session  0x0215FEE0  arm  ov009
 *   CPSi_TcpConnectRaw  0x0215ABB0  arm  ov009
 *   parse_record_in_buf  0x02161C80  arm  ov009
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   id_string        0x020050F0  data
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OSi_ThreadInfo     0x02150FEC  data
 */
#include "biginteger.h"
#include "cps_ssl_types.h"
#include "arc4.h"
#include "../../matched/arm9_sdk/libc/memcmp/string.h"

#define NELEMS(a) (sizeof(a) / sizeof((a)[0]))
#include "../arm9/os_system.h"
#include "../arm9/mi_memory.h"
#include "../arm9/os_tick.h"
typedef int RTCResult;
#include "../arm9/external.h"
#include "../arm9/convert.h"
#include "../arm9/os_thread.h"
extern int strcmp(const char *s1, const char *s2);
static int cert_item_len(unsigned char **ps);
static void make_dn(char *d, char *s, int len);
static unsigned long parse_time(unsigned char *s, int type);
extern void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
extern void CPSi_big_power(unsigned short *c, unsigned short *a, unsigned short *b, int digits,
                          unsigned short *n);
static void exit_computebound(unsigned long old_priority);
struct CPSMd5Ctx;
#include "md5.h"
struct CPSSha1Ctx;
#include "sha1.h"
static int auth_cert(CPSSslConnection *con);
static int compare_fqdn(char *name, char *pat);
static int validate_signature(CPSSslConnection *con, SOCLCaInfo *ca);
extern void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
extern void CPSi_big_montpower(unsigned short *c, unsigned short *m, unsigned short *e, int digits, unsigned short *n);
extern void CPSi_big_sub(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_add(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern int CPSi_big_sign(unsigned short *a, int digits);
extern void CPSi_big_negate(unsigned short *a, int digits);
extern void CPSi_big_div(unsigned short *c, unsigned short *a, unsigned short *b, unsigned short *r, int digits, unsigned short *work);
extern unsigned char *CPSi_TcpReadRaw(unsigned int *len, char *soc);
struct CPSSoc;
extern void CPSi_SocConsumeRaw(u32 len, struct CPSSoc *soc);
static void client_hello(CPSSslConnection *con, unsigned char *s);
static void rcv_server_hello(CPSSslConnection *con, unsigned char *s);
static void rcv_certificate(CPSSslConnection *con, unsigned char *s);
static void rcv_finished(CPSSslConnection *con, unsigned char *s);
static int tcp_read_raw_nbytes(unsigned char *d, int len, CPSSoc *soc);
static void client_hello_v2(CPSSslConnection *con, unsigned char *s);
extern void CPS_SslAddRandomSeed(void *random_seed, unsigned long len);
static void update_digest(CPSSslConnection *con, unsigned char *s, unsigned long len);
extern int make_ciphertext(CPSSslConnection *con, unsigned char *s);
extern u32 CPSi_TcpWrite2Raw(u8 *buf, u32 len, u8 *buf2, u32 len2, struct CPSSoc *soc);
static void set_random(unsigned char *d, int len);
extern unsigned long enter_computebound(void);
extern void CPSi_big_power(unsigned short *c, unsigned short *a, unsigned short *b, int digits, unsigned short *n);
static int parse_record(CPSSoc *soc);
static void create_key_block(CPSSslConnection *con);
static int mustget_change_cipher_spec_and_finished(CPSSoc *soc);
static void send_client_key_exchange(CPSSoc *soc);
static void create_master_secret(CPSSslConnection *con);
static void cache_session(CPSSslConnection *con, unsigned long ip, unsigned short port);
extern unsigned long CPSi_TcpConnectRaw(struct CPSSoc *soc);
static void parse_record_in_buf(CPSSslConnection *con, unsigned char *buf);
#include "../arm9/crt0.h"
unsigned long date2sec(void);
unsigned long CPS_GetSslHandshakePriority(void);
void CPS_SetSslHandshakePriority(int len);
struct SOCLCaInfo;
void CPS_SetRootCa(struct SOCLCaInfo **rootCa, int num);
SOCLCaInfo *get_rootCA(CPSSslConnection *con, char *dn);
int chars_till_end(const char *str);
int select_method(int methods, int num, int size);
int version_ok(int major, int minor);
void finished_md5(CPSSslConnection *con, unsigned char *d, int flag);
void finished_sha1(CPSSslConnection *con, unsigned char *d, int flag);
int decrypt(CPSSslConnection *con, u8 *s, int len);
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
extern struct CPSSslSession gCpsSslSessionCache[4];
extern unsigned char *sSslObject[];
extern char gCpsSslSaltA[];
extern char gCpsSslSaltB[];
extern char gCpsSslSaltC[];
extern int gCpsSslServerId;
extern int gCpsSslClientId;
extern Rand32Ctx gCpsSslRandCtx;
extern unsigned char sSslPool[20];
extern unsigned char pool_initialized;
extern unsigned char alert_nocert[7];
extern char id_string[];


/*
 * sdk:      find_session_from_id (libssl.TWL.HYB.a(ssl.o))
 */
static void find_session_from_id(CPSSslConnection *con)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    con->cache = 0;
    for (i = 0; i < 4; i++) {
        p = &gCpsSslSessionCache[i];
        if (p->valid != 0 && p->ip == 0 && p->port == 0 &&
            memcmp((const u8 *)p, con->common1.session_id, 0x20) == 0) {
            MI_CpuCopy8(p->master, con, 0x30);
            con->cache = 1;
            break;
        }
    }
    OS_RestoreInterrupts(enabled);
}


/*
 * sdk:      find_session_from_IP (libssl.TWL.HYB.a(ssl.o))
 */
static void find_session_from_IP(CPSSslConnection *con, unsigned long ip, unsigned short port)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    con->cache = 0;
    for (i = 0; i < 4; i++) {
        p = &gCpsSslSessionCache[i];
        if (p->valid != 0 && p->ip == ip && p->port == port) {
            MI_CpuCopy8(p, con->common1.session_id, 0x20);
            MI_CpuCopy8(p->master, con, 0x30);
            p->last_used = (unsigned long)(OS_GetTick() >> 16);
            con->cache = 1;
            break;
        }
    }
    OS_RestoreInterrupts(enabled);
}


static void cache_session(CPSSslConnection *con, unsigned long ip,
                          unsigned short port)
{
    int i;
    struct CPSSslSession *p;
    struct CPSSslSession *candidate;
    unsigned long biggest;
    unsigned long enabled;
    unsigned long now;

    enabled = OS_DisableInterrupts();
    now = (unsigned long)(OS_GetTick() >> 16);
    biggest = 0;
    candidate = gCpsSslSessionCache;
    for (i = 0; i < 4; i++) {
        p = &gCpsSslSessionCache[i];
        if (p->valid && ip != 0 && ip == p->ip && port != 0 &&
            port == p->port) {
            candidate = p;
            break;
        }
        if (biggest == (unsigned long)-1)
            continue;
        if (!p->valid) {
            biggest = (unsigned long)-1;
            candidate = p;
        } else {
            unsigned long age = now - p->last_used;
            if (age > biggest) {
                biggest = age;
                candidate = p;
            }
        }
    }
    MI_CpuCopy8(con->common1.session_id, candidate, 0x20);
    MI_CpuCopy8(con, candidate->master, 0x30);
    candidate->last_used = now;
    candidate->valid = 1;
    candidate->ip = ip;
    candidate->port = port;
    OS_RestoreInterrupts(enabled);
}


/* * sdk: purge_session (libssl.TWL.HYB.a(ssl.o)) */ static void purge_session(CPSSslConnection *con);


/*
 * sdk:      purge_session (libssl.TWL.HYB.a(ssl.o))
 */
static void purge_session(CPSSslConnection *con)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    for (i = 0; i < 4; i++) {
        p = &gCpsSslSessionCache[i];
        if (p->valid != 0) {
            if (memcmp((const u8 *)p, con->common1.session_id, 0x20) == 0) {
                p->valid = 0;
                break;
            }
        }
    }
    OS_RestoreInterrupts(enabled);
}


/*
 * sdk:      date2sec (libssl.TWL.HYB.a(ssl.o))
 */
unsigned long date2sec(void)
{
	unsigned long sec;
	RTCDate date;
	RTCTime time;

	RTC_GetDate((struct RTCDate *)(&date));
	RTC_GetTime((struct RTCTime *)(&time));
	sec = RTC_ConvertDateTimeToSecond((struct RTCDate *)(&date), (struct RTCTime *)(&time));
	return sec + 946684800;
}


unsigned long CPS_GetSslHandshakePriority(void)
{
	return gCpsSslConfig.priority;
}


void CPS_SetSslHandshakePriority(int len)
{
	gCpsSslConfig.priority = len;
}


/*
 * sdk:      enter_computebound (libssl.TWL.HYB.a(ssl.o))
 */
unsigned long enter_computebound(void)
{
	unsigned long old_priority;
	OSThread *thread;

	if (gCpsSslConfig.priority >= 32) {
		return -1;
	}
	thread = OSi_ThreadInfo.current;
	old_priority = (long unsigned int)OS_GetThreadPriority(thread);
	OS_SetThreadPriority(thread, gCpsSslConfig.priority);
	return old_priority;
}


static void exit_computebound(unsigned long old_priority)
{
    if (old_priority >= 0x20)
        return;
    OS_SetThreadPriority(OSi_ThreadInfo.current, old_priority);
}








/*
 * Hands a and b to the +0xc child of the object at +0xa4 as its +0x814 and
 * +0x818 words.
 */
void CPS_SetRootCa(struct SOCLCaInfo **rootCa, int num)
{
    CPSSoc *soc = (CPSSoc *)OSi_ThreadInfo.current->specific[0];
    CPSSslConnection *con;

    if (soc != 0 && (con = soc->con) != 0) {
        con->rootCa = (SOCLCaInfo **)rootCa;
        con->rootCaNum = num;
    }
}


/*
 * note: a do-while behind an `if (n > 0)` guard puts the list load after the loop entry test.
 *
 * sdk:      get_rootCA (libssl.TWL.HYB.a(ssl.o))
 */
SOCLCaInfo *get_rootCA(CPSSslConnection *con, char *dn)
{
	int i = 0;
	SOCLCaInfo **list;
	int n = con->rootCaNum;
	if (n > 0) {
		list = con->rootCa;
		do {
			SOCLCaInfo *ca = list[i];
			if (strcmp(ca->dn, dn) == 0) {
				return ca;
			}
			i++;
		} while (i < n);
	}
	return 0;
}


/*
 * sdk:      cert_item_len (libssl.TWL.HYB.a(ssl.o))
 */
static int cert_item_len(unsigned char **ps)
{
    unsigned char *s;
    int len;
    int lenlen;

    s = *ps;
    len = *s++;
    if (len & 0x80) {
        lenlen = len & 0x7f;
        len = 0;
        while (lenlen--) {
            if (len & 0xff000000)
                return -1;
            len = (len << 8) + *s++;
        }
    }
    *ps = s;
    return len;
}


/*
 * sdk:      make_dn (libssl.TWL.HYB.a(ssl.o))
 */
static void make_dn(char *d, char *s, int len)
{
    char *d0;

    d0 = d;
    if (*d != 0) {
        do
            d++;
        while (*d != 0);
        if (d - d0 >= 255)
            return;
        *d++ = ',';
        *d++ = ' ';
    }
    while (len-- != 0 && d - d0 < 255)
        *d++ = *s++;
    *d = 0;
}


/*
 * sdk:      parse_time (libssl.TWL.HYB.a(ssl.o))
 */
static unsigned long parse_time(unsigned char *s, int type)
{
    unsigned long year;

    year = s[0] * 10 + s[1] - 528;
    s += 2;
    if (type == 0x17) {
        if (year < 50)
            year += 2000;
        else
            year += 1900;
    } else {
        year = year * 100 + (s[0] * 10 + s[1] - 528);
        s += 2;
    }
    return (year << 16) + ((s[0] * 10 + s[1] - 528) << 8) + (s[2] * 10 + s[3] - 528);
}


static int cert_item(CPSSslConnection *con, unsigned char **ps,
                     int level, int seq, int mode)
{
    unsigned char *s;
    unsigned char *end;
    int len;
    int i;
    unsigned char type;

    s = *ps;
    type = *s++;
    len = cert_item_len(&s);
    if (len < 0 || len > 0x7d0)
        return 1;

    switch (type & 0x1f) {
    case 2:
        if (con->keyInfoOid != 0) {
            if (seq == 0) {
                while (*s == 0) {
                    s++;
                    len--;
                }
                switch (mode) {
                case 0:
                    if (len <= 0x100) {
                        MI_CpuCopy8(s, con->modulus, len);
                        con->modlen = len;
                    }
                    break;
                case 2:
                    con->ca.modulo_len = len;
                    con->ca.modulo = s;
                    break;
                }
            } else if (seq == 1) {
                while (*s == 0) {
                    s++;
                    len--;
                }
                switch (mode) {
                case 0:
                    if (len <= 8) {
                        MI_CpuCopy8(s, con->pubexp, len);
                        con->pubexplen = len;
                    }
                    break;
                case 2:
                    con->ca.exponent_len = len;
                    con->ca.exponent = s;
                    break;
                }
            }
        }
        s += len;
        break;
    case 3:
        i = 0;
        if (level == 1 && mode != 2) {
            con->sig = s + 1;
            con->sig_len = len - 1;
        }
        if (con->keyInfoOid != 0) {
            s++;
            if (cert_item(con, &s, level, i, mode) != 0)
                return 1;
            con->keyInfoOid = 0;
            goto done;
        }
        s += len;
        break;
    case 6:
        for (i = 0; i < 6; i++) {
            if (memcmp(s, sSslObject[i], strlen((char *)sSslObject[i])) == 0) {
                switch (i) {
                case 1:
                case 2:
                    if (mode == 0)
                        con->pubkeyAlgo = i;
                    con->keyInfoOid = i;
                    break;
                case 3:
                case 4:
                    if (mode != 2)
                        con->hash_type = i;
                    break;
                case 5:
                    if (mode != 2)
                        con->cnOid = i;
                    break;
                }
                break;
            }
        }
        s += len;
        break;
    case 12:
    case 19:
    case 20:
    case 22:
        i = 0;
        if (mode != 2) {
            if (con->subjectPhase != 0) {
                make_dn((char *)con->subjectDn, (char *)s, len);
                if (con->cnOid == 5 && len <= 0x4f) {
                    MI_CpuCopy8(s, con->commonName, len);
                    con->commonName[len] = 0;
                }
            } else {
                make_dn((char *)con->dn, (char *)s, len);
            }
        }
        con->cnOid = i;
        s += len;
        break;
    case 23:
    case 24:
        i = 1;
        if (mode != 2) {
            unsigned long cert_date;
            cert_date = parse_time(s, type & 0x1f);
            if (seq == 0) {
                if (con->currentDate >= cert_date)
                    con->dateValid = 1;
            } else {
                if (con->currentDate > cert_date)
                    con->dateValid = 0;
            }
        }
        s += len;
        con->subjectPhase = 1;
        goto done;
    case 16:
        if (level == 0 && seq == 0 && mode != 2)
            con->cert_start = s;
        end = s + len;
        i = 0;
        while (s < end) {
            if (cert_item(con, &s, level + 1, i++, mode) != 0)
                return 1;
        }
        if (level == 1 && seq == 0 && mode != 2)
            con->cert_end = s;
        goto done;
    case 17:
        end = s + len;
        while (s < end) {
            if (cert_item(con, &s, level + 1, 0, mode) != 0)
                return 1;
        }
        goto done;
    default:
        if (type == 0xa0) {
            end = s + len;
            while (s < end) {
                if (cert_item(con, &s, level + 1, 0, mode) != 0)
                    return 1;
            }
            goto done;
        }
        s += len;
        break;
    }

done:
    *ps = s;
    return 0;
}


/*
 * sdk:      validate_signature (libssl.TWL.HYB.a(ssl.o))
 *
 * The DWARF declares CPSi_char_from_big(d, s, numbytes); the call site also
 * loads digits into r3, so the file passes it as a fourth argument.
 */
static int validate_signature(CPSSslConnection *con, SOCLCaInfo *ca)
{
    unsigned short *tmp_var;
    unsigned short *b;
    unsigned short *c;
    unsigned short *n;
    int digits;
    unsigned char *s;
    int result;
    int i;
    unsigned long old_priority;

    if (con->sig == 0 || con->sig_len == 0 || ca->exponent == 0 || ca->exponent_len == 0 ||
        ca->modulo == 0 || ca->modulo_len == 0)
        return 2;
    digits = ca->modulo_len * 2 / 2;
    tmp_var = (unsigned short *)CPSiAlloc(digits * 8);
    if (tmp_var == 0)
        return 2;
    b = tmp_var + digits;
    c = b + digits;
    n = c + digits;
    CPSi_big_from_char(b, con->sig, con->sig_len, digits);
    CPSi_big_from_char(c, ca->exponent, ca->exponent_len, digits);
    CPSi_big_from_char(n, ca->modulo, ca->modulo_len, digits);
    old_priority = enter_computebound();
    CPSi_big_power(tmp_var, b, c, digits, n);
    exit_computebound(old_priority);
    s = (unsigned char *)b;
    CPSi_char_from_big(s, tmp_var, ca->modulo_len, digits);
    result = 0;
    if (s[0] != 0 || s[1] != 1) {
        result = 2;
    } else {
        for (i = 2; i < ca->modulo_len; i++) {
            if (s[i] != 0xff)
                break;
        }
        if (i + 1 >= ca->modulo_len || s[i] != 0 || s[i + 1] != 0x30 ||
            memcmp(con->hash, s + ca->modulo_len - con->hash_len, con->hash_len) != 0)
            result = 2;
    }
    CPSiFree(tmp_var);
    return result;
}


/*
 * sdk:      auth_cert (libssl.TWL.HYB.a(ssl.o))
 */
static int auth_cert(CPSSslConnection *con)
{
    int result;
    SOCLCaInfo *p;

    result = 0;
    if (con->dateValid == 0)
        result = 0x8000;
    if (con->pubkeyAlgo == -1)
        return result | 4;
    switch (con->hash_type) {
    case 3:
        CPSi_md5_init(&con->md5_hash_tmp);
        CPSi_md5_calc(&con->md5_hash_tmp, con->cert_start, con->cert_end - con->cert_start);
        CPSi_md5_result(&con->md5_hash_tmp, con->hash);
        con->hash_len = 0x10;
        break;
    case 4:
        CPSi_sha1_init(&con->sha1_hash_tmp);
        CPSi_sha1_calc(&con->sha1_hash_tmp, con->cert_start, con->cert_end - con->cert_start);
        CPSi_sha1_result(&con->sha1_hash_tmp, con->hash);
        con->hash_len = 0x14;
        break;
    default:
        return result | 3;
    }
    p = get_rootCA(con, con->dn);
    if (p == 0)
        return result | 1;
    return result | validate_signature(con, p);
}


/*
 * Length of the text up to the first period or terminator.
 */
int chars_till_end(const char *str)
{
    const char *start = str;

    while (*str != '.' && *str != 0)
        str++;
    return (int)(str - start);
}


/*
 * sdk:      compare_fqdn (libssl.TWL.HYB.a(ssl.o))
 */
static int compare_fqdn(char *name, char *pat)
{
    int pat_len;
    int pat_cnt;
    char c2;
    char c1;

    for (;;) {
        while (c2 = *pat++, c1 = *name++, c1 == c2) {
            if (c1 == 0)
                return 0;
        }
        if (c2 != '*')
            return 1;
        name--;
        pat_cnt = chars_till_end(name);
        pat_len = chars_till_end(pat);
        if (pat_len > pat_cnt)
            return 1;
        name += pat_cnt - pat_len;
    }
}


static void rcv_certificate(CPSSslConnection *con, unsigned char *s)
{
    RTCDate date;
    int result0;
    int result;
    int remaining_certlen;
    int this_certlen;
    unsigned char *s2;
    int parse_mode;
    int level;

    remaining_certlen = (((s[0] << 8) + s[1]) << 8) + s[2];
    s += 3;
    con->pubkeyAlgo = -1;
    RTC_GetDate(&date);
    parse_mode = 0;
    level = 0;
    con->currentDate = ((date.year + 2000) << 16) + (date.month << 8) + date.day;
    con->subjectDn[0] = 0;
    con->pubexplen = 0;
    con->modlen = 0;
    for (;;) {
        this_certlen = (((s[0] << 8) + s[1]) << 8) + s[2];
        s += 3;
        remaining_certlen -= this_certlen + 3;
        con->hash_type = -1;
        con->keyInfoOid = 0;
        con->subjectPhase = 0;
        con->dateValid = 0;
        con->subjectDn[0] = 0;
        con->dn[0] = 0;
        con->commonName[0] = 0;
        con->certData = s;
        con->certLen = this_certlen;

        if (cert_item(con, &s, 0, 0, parse_mode) != 0 || (unsigned int)con->modlen < 0x33 ||
            con->pubexplen == 0) {
            con->state = 9;
            return;
        }
        result = auth_cert(con);
        if (level == 0 && con->hostName != 0) {
            if (compare_fqdn(con->hostName, (char *)con->commonName) != 0)
                result |= 0x4000;
        }
        result0 = result & 0xff;
        if (result0 == 1 && remaining_certlen != 0) {
            s2 = s + 3;
            con->keyInfoOid = 0;
            if (cert_item(con, &s2, 0, 0, 2) != 0) {
                con->state = 9;
                return;
            }
            result = (result & ~0xff) | validate_signature(con, &con->ca);
        }
        if (con->f810 != 0)
            result = con->f810(result, con, level);
        level++;
        if (result0 == 0 || result != 0 || remaining_certlen == 0)
            break;
        parse_mode = 1;
    }
    if (result == 0)
        con->state = 3;
    else
        con->state = 9;
}




/* * sdk: has_method (libssl.TWL.HYB.a(ssl.o)) */ static int has_method(unsigned char *s, int num, int size, unsigned short method);


/*
 * sdk:      rcv_server_hello (libssl.TWL.HYB.a(ssl.o))
 */
static void rcv_server_hello(CPSSslConnection *con, unsigned char *s)
{
    int session_id_len;
    unsigned char cached;

    MI_CpuCopy8(s + 2, con->server_random, 0x20);
    cached = con->cache;
    session_id_len = s[0x22];
    s += 0x23;
    if (cached != 0 && session_id_len == 0x20 &&
        memcmp(con->common1.session_id, s, 0x20) == 0) {
        con->resumed = 1;
    } else {
        if (cached != 0)
            purge_session(con);
        if (session_id_len != 0) {
            MI_CpuCopy8(s, con->common1.session_id, 0x20);
            con->cache = 1;
        } else {
            con->cache = 0;
        }
        con->resumed = 0;
    }
    s += session_id_len;
    con->method = (s[0] << 8) + s[1];
    if (con->method != 4 && con->method != 5)
        con->state = 9;
    else
        con->state = 2;
}


/*
 * sdk:      has_method (libssl.TWL.HYB.a(ssl.o))
 */
static int has_method(unsigned char *s, int num, int size, unsigned short method)
{
    unsigned long n;
    int i;

    for (i = 0; i < num; i++) {
        n = (s[0] << 8) + s[1];
        if (size == 3)
            n = (n << 8) + s[2];
        if (n == method)
            return 1;
        s += size;
    }
    return 0;
}


/*
 * Scans the two halfword entries of a table, returning the first entry the
 * helper accepts, else zero.
 */
int select_method(int methods, int num, int size)
{
    u32 i;

    for (i = 0; i < 2; i++) {
        if (has_method((unsigned char *)methods, num, size, gCpsSslConfig.methods[i]))
            return gCpsSslConfig.methods[i];
    }
    return 0;
}


/*
 * True when the major version is 3; the minor version is not tested.
 */
int version_ok(int major, int minor)
{
    return major == 3;
}






/*
 * sdk:      client_hello_v2 (libssl.TWL.HYB.a(ssl.o))
 *
 * The offset `pairlist_len + 8 + sessionID_len` needs a local of its own
 * (`offset`); accumulating it back into pairlist_len colours r4/r5/r6/r7 as
 * pairlist_len/s/con/random_len where the vendor has pairlist_len/random_len/
 * s/con, which also pushes the s[4] temp out of r5 and into ip.  With the
 * separate name the coalescer merges pairlist_len and offset back into one
 * register and all four land as the vendor has them.
 *
 * Declaration order is inert here: all 24 permutations of the four locals
 * compile to the same 26-byte DIFF.
 */
static void client_hello_v2(CPSSslConnection *con, unsigned char *s)
{
    int pairlist_len;
    int offset;
    int sessionID_len;
    int random_len;
    unsigned short method;

    if (!version_ok(s[0], s[1]))
        return;
    pairlist_len = (s[2] << 8) + s[3];
    method = select_method((sptr)(s + 8), pairlist_len / 3, 3);
    if (method == 0)
        return;
    con->method = method;
    sessionID_len = (s[4] << 8) + s[5];
    random_len = (s[6] << 8) + s[7];
    con->cache = 0;
    offset = pairlist_len + 8 + sessionID_len;
    if (random_len >= 0x20) {
        MI_CpuCopy8(s + offset, con->client_random, 0x20);
    } else {
        MI_CpuFill8(con->client_random, 0, 0x20 - random_len);
        MI_CpuCopy8(s + offset, con->client_random + 0x20 - random_len, random_len);
    }
    con->state = 1;
}


/*
 * sdk:      client_hello (libssl.TWL.HYB.a(ssl.o))
 */
static void client_hello(CPSSslConnection *con, unsigned char *s)
{
    int sessionID_len;
    unsigned short method;

    if (!version_ok(s[0], s[1]))
        return;
    s += 2;
    MI_CpuCopy8(s, con->client_random, 0x20);
    s += 0x20;
    sessionID_len = *s++;
    if (sessionID_len != 0x20) {
        con->cache = 0;
    } else {
        MI_CpuCopy8(s, con->common1.session_id, 0x20);
        find_session_from_id(con);
    }
    s += sessionID_len;
    method = select_method((sptr)(s + 2), ((s[0] << 8) + s[1]) / 2, 2);
    con->method = method;
    if (method != 0)
        con->state = 1;
}


static void decrypt_premaster_secret(unsigned char *d, unsigned char *s, CPSPrivateKey *k)
{
    int digits;
    unsigned short *tmp_var;
    unsigned short *b;
    unsigned short *c;
    unsigned short *k1;
    unsigned short *k2;
    unsigned short *n;
    unsigned short *l;
    unsigned short *divwork;
    unsigned long old_priority;

    if (k == 0 || k->size == 0)
        return;

    digits = (k->size * 2) / 2 + 1;
    tmp_var = (unsigned short *)CPSiAlloc(digits * 20);
    if (tmp_var == 0)
        return;

    b = tmp_var + digits;
    c = b + digits;
    k1 = c + digits;
    k2 = k1 + digits;
    n = k2 + digits;
    l = n + digits;
    divwork = l + digits;

    CPSi_big_from_char(tmp_var, s, k->size, digits);
    CPSi_big_from_char(b, k->p3, k->l3, digits);
    CPSi_big_from_char(n, k->p1, k->l1, digits);
    old_priority = enter_computebound();
    CPSi_big_montpower(k1, tmp_var, b, digits, n);
    CPSi_big_from_char(b, k->p4, k->l4, digits);
    CPSi_big_from_char(n, k->p2, k->l2, digits);
    CPSi_big_montpower(k2, tmp_var, b, digits, n);
    exit_computebound(old_priority);
    CPSi_big_sub(tmp_var, k1, k2, digits);
    CPSi_big_from_char(b, k->p5, k->l5, digits);
    CPSi_big_mult(c, tmp_var, b, digits);
    CPSi_big_from_char(b, k->p2, k->l2, digits);
    CPSi_big_mult(tmp_var, c, b, digits);
    CPSi_big_add(c, tmp_var, k2, digits);
    CPSi_big_from_char(b, k->p0, k->size, digits);
    if (CPSi_big_sign(c, digits) < 0) {
        CPSi_big_negate(c, digits);
        CPSi_big_div(0, c, b, l, digits, divwork);
        CPSi_big_sub(l, b, l, digits);
    } else {
        CPSi_big_div(0, c, b, l, digits, divwork);
    }
    CPSi_char_from_big(d, l, 0x30, digits);
    CPSiFree(tmp_var);
}


static void create_ms_sub(unsigned char *d, char *salt,
                          CPSSslConnection *con)
{
    unsigned char tmp[20];

    CPSi_sha1_init(&con->sha1_hash_tmp);
    CPSi_sha1_calc(&con->sha1_hash_tmp, salt, strlen(salt));
    CPSi_sha1_calc(&con->sha1_hash_tmp, con->master_secret, 0x30);
    CPSi_sha1_calc(&con->sha1_hash_tmp, con->client_random, 0x40);
    CPSi_sha1_result(&con->sha1_hash_tmp, tmp);
    CPSi_md5_init(&con->md5_hash_tmp);
    CPSi_md5_calc(&con->md5_hash_tmp, con->master_secret, 0x30);
    CPSi_md5_calc(&con->md5_hash_tmp, tmp, 0x14);
    CPSi_md5_result(&con->md5_hash_tmp, d);
}


static void create_master_secret(CPSSslConnection *con)
{
    unsigned char tmp[48];

    create_ms_sub(tmp, gCpsSslSaltA, con);
    create_ms_sub(tmp + 0x10, gCpsSslSaltB, con);
    create_ms_sub(tmp + 0x20, gCpsSslSaltC, con);
    MI_CpuCopy8(tmp, con->master_secret, 0x30);
}


static void create_key_block(CPSSslConnection *con)
{
    int i, j;
    unsigned char c;
    unsigned char tmp[20];
    void *p;
    int size1, size2, size3;
    int len;

    switch (con->method) {
    case 4:
        size1 = 16;
        size2 = 16;
        size3 = 0;
        break;
    case 5:
        size1 = 20;
        size2 = 16;
        size3 = 0;
        break;
    }
    len = (size1 + size2 + size3) * 2;
    for (i = 0; i * 16 < len; i++) {
        p = &con->sha1_hash_tmp;
        CPSi_sha1_init(p);
        c = 'A' + i;
        for (j = 0; j < i + 1; j++)
            CPSi_sha1_calc(p, &c, 1);
        CPSi_sha1_calc(p, con->master_secret, 48);
        CPSi_sha1_calc(p, con->server_random, 32);
        CPSi_sha1_calc(p, con->client_random, 32);
        CPSi_sha1_result(p, tmp);
        p = &con->md5_hash_tmp;
        CPSi_md5_init(p);
        CPSi_md5_calc(p, con->master_secret, 48);
        CPSi_md5_calc(p, tmp, 20);
        CPSi_md5_result(p, con->common1.key_block + i * 16);
    }
    if (con->server) {
        con->rcv_mac = con->common1.key_block;
        con->rcv_key = con->common1.key_block + size1 * 2;
        con->send_mac = con->common1.key_block + size1;
        con->send_key = con->send_mac + size1 + size2;
    } else {
        con->send_mac = con->common1.key_block;
        con->send_key = con->common1.key_block + size1 * 2;
        con->rcv_mac = con->common1.key_block + size1;
        con->rcv_key = con->rcv_mac + size1 + size2;
    }
    CPSi_rc4_init(&con->rcv_cipher.rc4, con->rcv_key, 16);
    CPSi_rc4_init(&con->send_cipher.rc4, con->send_key, 16);
}


static void rcv_client_key_exchange(CPSSslConnection *con, unsigned char *s)
{
    decrypt_premaster_secret((unsigned char *)con, s, con->privkey);
    create_master_secret(con);
    cache_session(con, 0, 0);
    create_key_block(con);
    con->state = 5;
}


/*
 * sdk:      finished_md5 (ssl.o)
 */
void finished_md5(CPSSslConnection *con, unsigned char *d, int flag)
{
    unsigned char tmp[48];
    CPSMd5Ctx *p = &con->md5_hash;

    if ((con->server ^ flag) != 0)
        CPSi_md5_calc(p, &gCpsSslServerId, 4);
    else
        CPSi_md5_calc(p, &gCpsSslClientId, 4);
    CPSi_md5_calc(p, con->master_secret, 48);
    MI_CpuFill8(tmp, 0x36, 48);
    CPSi_md5_calc(p, tmp, 48);
    CPSi_md5_result(p, d);
    CPSi_md5_init(p);
    CPSi_md5_calc(p, con->master_secret, 48);
    MI_CpuFill8(tmp, 0x5c, 48);
    CPSi_md5_calc(p, tmp, 48);
    CPSi_md5_calc(p, d, 16);
    CPSi_md5_result(p, d);
}


/*
 * sdk:      finished_sha1 (ssl.o)
 */
void finished_sha1(CPSSslConnection *con, unsigned char *d, int flag)
{
    unsigned char tmp[40];
    CPSSha1Ctx *p = &con->sha1_hash;

    if ((con->server ^ flag) != 0)
        CPSi_sha1_calc(p, &gCpsSslServerId, 4);
    else
        CPSi_sha1_calc(p, &gCpsSslClientId, 4);
    CPSi_sha1_calc(p, con->master_secret, 48);
    MI_CpuFill8(tmp, 0x36, 40);
    CPSi_sha1_calc(p, tmp, 40);
    CPSi_sha1_result(p, d);
    CPSi_sha1_init(p);
    CPSi_sha1_calc(p, con->master_secret, 48);
    MI_CpuFill8(tmp, 0x5c, 40);
    CPSi_sha1_calc(p, tmp, 40);
    CPSi_sha1_calc(p, d, 20);
    CPSi_sha1_result(p, d);
}


/*
 * sdk:      rcv_finished (libssl.TWL.HYB.a(ssl.o))
 */
static void rcv_finished(CPSSslConnection *con, unsigned char *s)
{
    unsigned char tmp[20];

    MI_CpuCopy8(&con->md5_hash, &con->md5_hash_tmp, 0x58);
    finished_md5(con, tmp, 1);
    MI_CpuCopy8(&con->md5_hash_tmp, &con->md5_hash, 0x58);
    if (memcmp(s, tmp, 0x10) != 0) {
        con->state = 9;
        return;
    }
    MI_CpuCopy8(&con->sha1_hash, &con->sha1_hash_tmp, 0x5c);
    finished_sha1(con, tmp, 1);
    MI_CpuCopy8(&con->sha1_hash_tmp, &con->sha1_hash, 0x5c);
    if (memcmp(s + 0x10, tmp, 0x14) != 0)
        con->state = 9;
    else
        con->state = 6;
}


static void add1_be8(u8 *d)
{
    int i;
    u8 tmp;

    for (i = 8; i != 0; i--) {
        tmp = *--d + 1;
        *d = tmp;
        if (tmp != 0)
            return;
    }
}


/*
 * Forwards (p + 0x1e0) to CPSi_rc4_crypt and returns the third argument.
 */
int decrypt(CPSSslConnection *con, u8 *s, int len)
{
    CPSi_rc4_crypt(&con->rcv_cipher.rc4, s, len);
    return len;
}


static int make_plaintext(CPSSslConnection *con, u8 *s)
{
    int len;
    int hash_len;
    u8 tmp[20];
    u8 pad[48];

    len = decrypt(con, s + 5, (s[3] << 8) + s[4]);
    switch (con->method) {
    case 4:
        len -= 0x10;
        s[3] = len >> 8;
        s[4] = len;
        CPSi_md5_init(&con->md5_hash_tmp);
        hash_len = 0x10;
        CPSi_md5_calc(&con->md5_hash_tmp, con->rcv_mac, hash_len);
        MI_CpuFill8(pad, 0x36, 0x30);
        CPSi_md5_calc(&con->md5_hash_tmp, pad, 0x30);
        CPSi_md5_calc(&con->md5_hash_tmp, con->rcv_seq, 8);
        CPSi_md5_calc(&con->md5_hash_tmp, s, 1);
        CPSi_md5_calc(&con->md5_hash_tmp, s + 3, len + 2);
        CPSi_md5_result(&con->md5_hash_tmp, tmp);
        CPSi_md5_init(&con->md5_hash_tmp);
        CPSi_md5_calc(&con->md5_hash_tmp, con->rcv_mac, hash_len);
        MI_CpuFill8(pad, 0x5c, 0x30);
        CPSi_md5_calc(&con->md5_hash_tmp, pad, 0x30);
        CPSi_md5_calc(&con->md5_hash_tmp, tmp, hash_len);
        CPSi_md5_result(&con->md5_hash_tmp, tmp);
        break;
    case 5:
        len -= 0x14;
        s[3] = len >> 8;
        s[4] = len;
        CPSi_sha1_init(&con->sha1_hash_tmp);
        hash_len = 0x14;
        CPSi_sha1_calc(&con->sha1_hash_tmp, con->rcv_mac, hash_len);
        MI_CpuFill8(pad, 0x36, 0x28);
        CPSi_sha1_calc(&con->sha1_hash_tmp, pad, 0x28);
        CPSi_sha1_calc(&con->sha1_hash_tmp, con->rcv_seq, 8);
        CPSi_sha1_calc(&con->sha1_hash_tmp, s, 1);
        CPSi_sha1_calc(&con->sha1_hash_tmp, s + 3, len + 2);
        CPSi_sha1_result(&con->sha1_hash_tmp, tmp);
        CPSi_sha1_init(&con->sha1_hash_tmp);
        CPSi_sha1_calc(&con->sha1_hash_tmp, con->rcv_mac, hash_len);
        MI_CpuFill8(pad, 0x5c, 0x28);
        CPSi_sha1_calc(&con->sha1_hash_tmp, pad, 0x28);
        CPSi_sha1_calc(&con->sha1_hash_tmp, tmp, hash_len);
        CPSi_sha1_result(&con->sha1_hash_tmp, tmp);
        break;
    }
    if (memcmp(s + 5 + len, tmp, hash_len) != 0)
        con->state = 9;
    add1_be8(con->rcv_seq + 8);
    return len + 5;
}


int make_ciphertext(CPSSslConnection *con, unsigned char *s)
{
    void *p;
    int len;
    unsigned char tmp[48];
    unsigned char *mac;

    len = (s[3] << 8) + s[4];
    p = s + 5;
    switch (con->method) {
    case 4: {
        CPSMd5Ctx *ctx = &con->md5_hash_tmp;
        CPSi_md5_init(ctx);
        CPSi_md5_calc(ctx, con->send_mac, 16);
        MI_CpuFill8(tmp, 0x36, 48);
        CPSi_md5_calc(ctx, tmp, 48);
        CPSi_md5_calc(ctx, con->send_seq, 8);
        CPSi_md5_calc(ctx, s, 1);
        CPSi_md5_calc(ctx, s + 3, len + 2);
        mac = (unsigned char *)p + len;
        CPSi_md5_result(ctx, mac);
        CPSi_md5_init(ctx);
        CPSi_md5_calc(ctx, con->send_mac, 16);
        MI_CpuFill8(tmp, 0x5c, 48);
        CPSi_md5_calc(ctx, tmp, 48);
        CPSi_md5_calc(ctx, mac, 16);
        CPSi_md5_result(ctx, mac);
        len += 16;
        break;
    }
    case 5: {
        CPSSha1Ctx *ctx = &con->sha1_hash_tmp;
        CPSi_sha1_init(ctx);
        CPSi_sha1_calc(ctx, con->send_mac, 20);
        MI_CpuFill8(tmp, 0x36, 40);
        CPSi_sha1_calc(ctx, tmp, 40);
        CPSi_sha1_calc(ctx, con->send_seq, 8);
        CPSi_sha1_calc(ctx, s, 1);
        CPSi_sha1_calc(ctx, s + 3, len + 2);
        mac = (unsigned char *)p + len;
        CPSi_sha1_result(ctx, mac);
        CPSi_sha1_init(ctx);
        CPSi_sha1_calc(ctx, con->send_mac, 20);
        MI_CpuFill8(tmp, 0x5c, 40);
        CPSi_sha1_calc(ctx, tmp, 40);
        CPSi_sha1_calc(ctx, mac, 20);
        CPSi_sha1_result(ctx, mac);
        len += 20;
        break;
    }
    }
    s[3] = len >> 8;
    s[4] = len;
    CPSi_rc4_crypt(&con->send_cipher.rc4, s + 5, len);
    add1_be8(con->send_seq + 8);
    return len + 5;
}


/*
 * sdk:      tcp_read_raw_nbytes (libssl.TWL.HYB.a(ssl.o))
 */
static int tcp_read_raw_nbytes(unsigned char *d, int len, CPSSoc *soc)
{
    unsigned long thislen;
    unsigned char *s;

    do {
        s = CPSi_TcpReadRaw((u32 *)(&thislen), (char *)soc);
        if (thislen == 0)
            return -1;
        if (thislen > len)
            thislen = len;
        MI_CpuCopy8(s, d, thislen);
        CPSi_SocConsumeRaw(thislen, (struct CPSSoc *)soc);
        len -= thislen;
        d += thislen;
    } while (len > 0);
    return 0;
}


static void update_digest(CPSSslConnection *con, unsigned char *s,
                          unsigned long len)
{
    CPSi_sha1_calc(&con->sha1_hash, s, len);
    CPSi_md5_calc(&con->md5_hash, s, len);
}


static void parse_record_in_buf(CPSSslConnection *con, unsigned char *buf)
{
    unsigned char *s;
    unsigned char type;
    unsigned long len;
    int sub;

    if (con->state == 9) {
        CPSiFree(buf);
        return;
    }

    type = buf[0];
    len = (buf[3] << 8) + buf[4] + 5;
    if (con->rcv_mac != 0 &&
        (((con->state == 7 || con->state == 8) && type != 0x15) ||
         (type == 0x15 && len > 7))) {
        len = make_plaintext(con, buf);
        if (con->state == 9) {
            CPSiFree(buf);
            return;
        }
    }

    s = buf + 5;
    len -= 5;

    switch (type) {
    case 0x14:
        if (con->rcv_mac == 0) {
            con->state = 9;
        } else {
            MI_CpuFill8(con->rcv_seq, 0, 8);
            con->state = 7;
        }
        break;
    case 0x15:
        if (len != 2 || s[0] == 2)
            con->state = 9;
        break;
    case 0x16:
        if (len < 4) {
            con->state = 9;
            break;
        }
        do {
            type = s[0];
            sub = (s[1] << 16) + (s[2] << 8) + s[3];
            if ((s[1] << 16) + (s[2] << 8) + s[3] > len) {
                con->state = 9;
                break;
            }
            s += 4;
            switch (type) {
            case 1:
                if (con->server != 0 && con->state == 0)
                    client_hello(con, s);
                else
                    con->state = 9;
                break;
            case 0x10:
                if (con->server == 0)
                    con->state = 9;
                else
                    rcv_client_key_exchange(con, s);
                break;
            case 2:
                if (sub >= 0x26 && con->server == 0)
                    rcv_server_hello(con, s);
                else
                    con->state = 9;
                break;
            case 0xb:
                if (con->state == 2 && con->server == 0) {
                    rcv_certificate(con, s);
                    con->subjectPhase = 0;
                } else {
                    con->state = 9;
                }
                break;
            case 0xd:
                if (con->state == 3 && con->server == 0)
                    con->subjectPhase = 1;
                else
                    con->state = 9;
                break;
            case 0xe:
                if (con->server == 0 && con->state == 3)
                    con->state = 4;
                else
                    con->state = 9;
                break;
            case 0x14:
                rcv_finished(con, s);
                break;
            default:
                con->state = 9;
                break;
            }
            if (con->state != 9) {
                update_digest(con, s - 4, sub + 4);
                s += sub;
                len -= sub + 4;
            }
        } while (len != 0 && con->state != 9);
        break;
    case 0x17:
        if (con->state != 8) {
            con->state = 9;
        } else {
            con->buf = buf;
            con->pos = 5;
            con->end = len + 5;
            con->have_record = 1;
            return;
        }
        break;
    default:
        con->state = 9;
        break;
    }
    CPSiFree(buf);
}


static int parse_record(CPSSoc *soc)
{
    unsigned char *buf;
    unsigned long len;
    unsigned char *s;
    CPSSslConnection *con = soc->con;

    for (;;) {
        buf = CPSi_TcpReadRaw((u32 *)(&len), (char *)soc);
        if (len >= 5)
            break;
        if (len == 0 || soc->state == 0) {
            con->state = 9;
            return 9;
        }
    }

    if (buf[0] == 0x80) {
        if (con->server != 0 && con->state == 0) {
            len = buf[1];
            CPSi_SocConsumeRaw(2, (struct CPSSoc *)soc);
            s = (unsigned char *)CPSiAlloc(len);
            if (s == 0) {
                con->state = 9;
                return 9;
            }
            if (tcp_read_raw_nbytes(s, len, soc) != 0 || s[0] != 1)
                con->state = 9;
            else
                client_hello_v2(con, s + 1);
            update_digest(con, s, len);
            CPSiFree(s);
        } else {
            con->state = 9;
        }
    } else {
        len = (buf[3] << 8) + buf[4] + 5;
        if (len > 0x4805) {
            con->state = 9;
            return 9;
        }
        s = (unsigned char *)CPSiAlloc(len);
        if (s == 0) {
            con->state = 9;
            return 9;
        }
        if (tcp_read_raw_nbytes(s, len, soc) != 0) {
            CPSiFree(s);
            con->state = 9;
            return 9;
        }
        parse_record_in_buf(con, s);
    }
    return con->state;
}


/*
 * sdk:      set_random (libssl.TWL.HYB.a(ssl.o))
 */
static void set_random(unsigned char *d, int len)
{
    unsigned long enabled;
    CPSSha1Ctx ctx;
    unsigned char x[20];
    int i;
    int j;
    int r;
    unsigned int carry;
    unsigned long tmp;

    if (pool_initialized == 0) {
        gCpsSslRandCtx.x = gCpsSslRandCtx.a * gCpsSslRandCtx.x + gCpsSslRandCtx.c;
        tmp = (unsigned long)(gCpsSslRandCtx.x >> 32);
        CPS_SslAddRandomSeed(&tmp, 4);
    }
    r = 20;
    for (i = 0; i < len;) {
        if (r == 20) {
            CPSi_sha1_init(&ctx);
            enabled = OS_DisableInterrupts();
            CPSi_sha1_calc(&ctx, sSslPool, 20);
            CPSi_sha1_result_prng(&ctx, x);
            carry = 1;
            for (j = 19; j >= 0; j--) {
                tmp = sSslPool[j] + x[j] + carry;
                sSslPool[j] = (unsigned char)tmp;
                carry = tmp >> 8;
            }
            OS_RestoreInterrupts(enabled);
            r = 0;
        }
        {
            unsigned char b = x[r++];
            if (b != 0)
                d[i++] = b;
        }
    }
}


void CPS_SslAddRandomSeed(void *random_seed, unsigned long len)
{
    CPSSha1Ctx ctx;
    unsigned long enabled;

    CPSi_sha1_init(&ctx);
    enabled = OS_DisableInterrupts();
    CPSi_sha1_calc(&ctx, sSslPool, 0x14);
    CPSi_sha1_calc(&ctx, random_seed, len);
    CPSi_sha1_result(&ctx, sSslPool);
    OS_RestoreInterrupts(enabled);
    pool_initialized = 1;
}


/*
 * sdk:      send_change_cipher_spec_and_finished (libssl.TWL.HYB.a ssl.o)
 *
 * Static SSL handshake tail: builds the ChangeCipherSpec and Finished records, hashes and encrypts them, sends them.
 */
void send_change_cipher_spec_and_finished(CPSSoc *soc)
{
    unsigned char *buf;
    CPSSslConnection *con = soc->con;

    buf = (unsigned char *)CPSiAlloc(131);
    if (buf == 0) {
        con->state = 9;
        return;
    }
    buf[0] = 20;
    buf[1] = 3;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 1;
    buf[5] = 1;
    MI_CpuFill8(con->send_seq, 0, 8);
    buf[6] = 22;
    buf[7] = 3;
    buf[8] = 0;
    buf[9] = 0;
    buf[10] = 40;
    buf[11] = 20;
    buf[12] = 0;
    buf[13] = 0;
    buf[14] = 36;
    MI_CpuCopy8(&con->md5_hash, &con->md5_hash_tmp, 0x58);
    finished_md5(con, buf + 15, 0);
    MI_CpuCopy8(&con->md5_hash_tmp, &con->md5_hash, 0x58);
    MI_CpuCopy8(&con->sha1_hash, &con->sha1_hash_tmp, 0x5C);
    finished_sha1(con, buf + 31, 0);
    MI_CpuCopy8(&con->sha1_hash_tmp, &con->sha1_hash, 0x5C);
    update_digest(con, buf + 11, 40);
    CPSi_TcpWrite2Raw(buf, make_ciphertext(con, buf + 6) + 6, 0, 0, (struct CPSSoc *)soc);
    CPSiFree(buf);
}


/*
 * sdk:      send_client_hello (libssl.TWL.HYB.a(ssl.o))
 */
static void send_client_hello(CPSSoc *soc)
{
    CPSSslConnection *con = soc->con;
    unsigned long sec;
    unsigned char *buf;
    unsigned char *d;
    int i;

    buf = (unsigned char *)CPSiAlloc(0x98);
    if (buf == 0) {
        con->state = 9;
        return;
    }
    buf[9] = 3;
    buf[10] = 0;
    sec = date2sec();
    con->client_random[0] = sec >> 24;
    con->client_random[1] = sec >> 16;
    con->client_random[2] = sec >> 8;
    con->client_random[3] = sec;
    set_random(con->client_random + 4, 28);
    MI_CpuCopy8(con->client_random, buf + 11, 32);
    find_session_from_IP(con, soc->remote_ip, soc->remote_port);
    if (con->cache == 0) {
        buf[43] = 0;
        d = buf + 44;
    } else {
        buf[43] = 32;
        MI_CpuCopy8(con->common1.session_id, buf + 44, 32);
        d = buf + 76;
    }
    d[0] = 0;
    d[1] = 4;
    d += 2;
    for (i = 0; i < NELEMS(gCpsSslConfig.methods); i++) {
        d[0] = gCpsSslConfig.methods[i] >> 8;
        d[1] = gCpsSslConfig.methods[i];
        d += 2;
    }
    d[0] = 1;
    d[1] = 0;
    d += 2;
    i = d - buf - 5;
    buf[0] = 22;
    buf[1] = 3;
    buf[2] = 0;
    buf[3] = i >> 8;
    buf[4] = i;
    buf[5] = 1;
    buf[6] = (i - 4) >> 16;
    buf[7] = (i - 4) >> 8;
    buf[8] = i - 4;
    CPSi_TcpWrite2Raw(buf, i + 5, 0, 0, (struct CPSSoc *)soc);
    update_digest(con, buf + 5, i);
    CPSiFree(buf);
}


static void send_client_key_exchange(CPSSoc *soc)
{
    CPSSslConnection *con;
    unsigned short *a;
    unsigned short *n;
    int digits;
    unsigned char *buf;
    int modlen;
    unsigned short *b;
    unsigned short *tmp_var;
    unsigned long old_priority;
    int i;
    unsigned char *tmp;
    unsigned char *d;

    con = soc->con;
    if (con->subjectPhase != 0)
        CPSi_TcpWrite2Raw(alert_nocert, 7, 0, 0, (struct CPSSoc *)soc);

    con->master_secret[0] = 3;
    con->master_secret[1] = 0;
    set_random(&con->master_secret[2], 0x2e);

    modlen = con->modlen;
    digits = modlen * 2 / 2;
    buf = (unsigned char *)CPSiAlloc(modlen);
    if (buf == 0) {
        con->state = 9;
        return;
    }
    buf[0] = 0;
    buf[1] = 2;
    set_random(&buf[2], modlen - 0x33);
    buf[modlen - 0x31] = 0;
    MI_CpuCopy8(con->master_secret, buf + modlen - 0x30, 0x30);

    a = (unsigned short *)CPSiAlloc(digits * 8);
    if (a == 0) {
        CPSiFree(buf);
        con->state = 9;
        return;
    }
    tmp_var = a + digits;
    b = tmp_var + digits;
    n = b + digits;
    CPSi_big_from_char(tmp_var, buf, modlen, digits);
    CPSi_big_from_char(b, con->pubexp, con->pubexplen, digits);
    CPSi_big_from_char(n, con->modulus, modlen, digits);
    old_priority = enter_computebound();
    CPSi_big_power(a, tmp_var, b, digits, n);
    exit_computebound(old_priority);

    tmp = (unsigned char *)CPSiAlloc(modlen + 0x49);
    if (tmp == 0) {
        CPSiFree(buf);
        CPSiFree(a);
        con->state = 9;
        return;
    }
    tmp[0] = 0x16;
    tmp[1] = 3;
    tmp[2] = 0;
    tmp[3] = (modlen + 4) >> 8;
    tmp[4] = modlen + 4;
    tmp[5] = 0x10;
    tmp[6] = modlen >> 16;
    tmp[7] = modlen >> 8;
    tmp[8] = modlen;
    d = &tmp[9];
    if (modlen & 1) {
        tmp[9] = a[modlen / 2];
        d = &tmp[10];
    }
    for (i = modlen / 2 - 1; i >= 0; i--) {
        *d++ = a[i] >> 8;
        *d++ = a[i];
    }
    CPSi_TcpWrite2Raw(tmp, modlen + 9, 0, 0, (struct CPSSoc *)soc);
    update_digest(con, &tmp[5], modlen + 4);
    CPSiFree(tmp);
    CPSiFree(a);
    CPSiFree(buf);
}


static int mustget_change_cipher_spec_and_finished(CPSSoc *soc)
{
    if (parse_record(soc) != 7)
        return 1;
    if (parse_record(soc) != 6)
        return 1;
    return 0;
}


static int ssl_connect_try(CPSSoc *soc)
{
    CPSSslConnection *con;
    int state;

    con = soc->con;
    send_client_hello(soc);
    for (;;) {
        state = parse_record(soc);
        if (state == 9)
            return 1;
        if (state == 4)
            break;
        if (con->resumed != 0)
            break;
    }
    if (con->resumed != 0) {
        create_key_block(con);
        if (mustget_change_cipher_spec_and_finished(soc) != 0)
            return 1;
        send_change_cipher_spec_and_finished(soc);
    } else {
        send_client_key_exchange(soc);
        create_master_secret(con);
        if (con->cache != 0)
            cache_session(con, soc->remote_ip, soc->remote_port);
        create_key_block(con);
        send_change_cipher_spec_and_finished(soc);
        if (mustget_change_cipher_spec_and_finished(soc) != 0)
            return 1;
    }
    con->state = 8;
    return 0;
}


/*
 * sdk:      CPSi_SslConnect (libssl.TWL.HYB.a(ssl.o))
 */
unsigned long CPSi_SslConnect(CPSSoc *soc)
{
    int result;
    CPSSslConnection *con;

    con = soc->con;
    if (soc->state != 4) {
        if (CPSi_TcpConnectRaw((struct CPSSoc *)soc) != 0)
            return 1;
    }
    con->state = 0;
    con->rcv_mac = 0;
    con->server = 0;
    CPSi_sha1_init(&con->sha1_hash);
    CPSi_md5_init(&con->md5_hash);
    return ssl_connect_try(soc);
}


/*
 * sdk:      CPSi_SslRead (libssl.TWL.HYB.a(ssl.o))
 */
unsigned char *CPSi_SslRead(unsigned long *len, CPSSoc *soc)
{
    CPSSslConnection *con;

    con = soc->con;
    if (con->buf != 0 && con->have_record == 0) {
        if (tcp_read_raw_nbytes(con->buf + con->pos, con->end - con->pos, soc) != 0) {
            CPSiFree(con->buf);
            con->buf = 0;
            *len = 0;
            return 0;
        }
        parse_record_in_buf(con, con->buf);
        if (con->have_record == 0)
            con->buf = 0;
    }
    while (con->buf == 0) {
        if (parse_record(soc) == 9) {
            *len = 0;
            return 0;
        }
    }
    *len = con->end - con->pos;
    return con->buf + con->pos;
}


void CPSi_SslConsume(unsigned long len, CPSSoc *soc)
{
	CPSSslConnection *con = soc->con;

	if (len >= con->end - con->pos) {
		if (con->buf != 0)
			CPSiFree(con->buf);
		con->buf = 0;
	} else {
		con->pos += len;
	}
}


/*
 * sdk:      try_fill_record (libssl.TWL.HYB.a ssl.o)
 *
 * Static SSL record reassembly: reads the socket receive buffer into an allocated record buffer, parses it when complete.
 */
void try_fill_record(CPSSoc *soc)
{
    int got_all;
    unsigned long len;
    unsigned char *s;
    CPSSslConnection *con = soc->con;

    if (con->buf == 0) {
        if (soc->rcvbufp < 5) return;
        s = CPSi_TcpReadRaw((u32 *)(&len), (char *)soc);
        len = (s[3] << 8) + s[4] + 5;
        if (len > 0x4805) {
            con->state = 9;
            return;
        }
        con->buf = (unsigned char *)CPSiAlloc(len);
        if (con->buf == 0) {
            con->state = 9;
            return;
        }
        con->end = len;
        con->pos = 0;
        con->have_record = 0;
    } else if (soc->rcvbufp == 0) {
        return;
    }
    s = CPSi_TcpReadRaw((u32 *)(&len), (char *)soc);
    if (len >= (con->end - con->pos)) {
        len = con->end - con->pos;
        got_all = 1;
    } else {
        got_all = 0;
    }
    MI_CpuCopy8(s, con->buf + con->pos, len);
    CPSi_SocConsumeRaw(len, (struct CPSSoc *)soc);
    if (got_all) {
        parse_record_in_buf(con, con->buf);
        if (con->have_record == 0) con->buf = 0;
    } else {
        con->pos += len;
    }
}


/*
 * sdk:      CPSi_SslGetLength (libssl.TWL.HYB.a(ssl.o))
 */
long CPSi_SslGetLength(CPSSoc *soc)
{
    CPSSslConnection *con;

    con = soc->con;
    if (con->buf == 0 || con->have_record == 0)
        try_fill_record(soc);
    if (con->buf != 0 && con->have_record != 0)
        return con->end - con->pos;
    if (con->buf == 0) {
        if (soc->state != 4 || con->state == 9)
            return -1;
    }
    return 0;
}


/*
 * sdk:      CPSi_SslWrite2 (libssl.TWL.HYB.a ssl.o)
 *
 * Writes a two-part buffer as SSL application-data records of at most 2895 bytes; returns the bytes sent.
 */
unsigned long CPSi_SslWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, CPSSoc *soc)
{
    CPSSslConnection *con = soc->con;
    unsigned char *tmp;
    long total_len;
    long part1_len;
    long this_len;
    long part2_len;
    long total_sent_len;
    long this_sent_len;
    total_sent_len = 0;
    total_len = len + len2;
    do {
        this_len = (total_len > 2895) ? 2895 : total_len;
        tmp = (unsigned char *)CPSiAlloc(this_len + 25);
        if (!tmp) break;
        part1_len = (len >= (unsigned long)this_len) ? this_len : len;
        part2_len = this_len - part1_len;
        MI_CpuCopy8(buf, tmp + 5, part1_len);
        buf += part1_len;
        len -= part1_len;
        MI_CpuCopy8(buf2, tmp + 5 + part1_len, part2_len);
        tmp[0] = 23;
        tmp[1] = 3;
        tmp[2] = 0;
        tmp[3] = this_len >> 8;
        buf2 += part2_len;
        tmp[4] = this_len;
        this_sent_len = make_ciphertext(con, tmp);
        if (CPSi_TcpWrite2Raw(tmp, this_sent_len, 0, 0, (struct CPSSoc *)soc) < (unsigned long)this_sent_len) this_len = 0;
        CPSiFree(tmp);
        total_sent_len += this_len;
        total_len -= this_len;
        if (total_len == 0) break;
    } while (this_len != 0);
    return total_sent_len;
}


/*
 * Flush a queued request when the object reached through +0xc is in state 8:
 * a 7-byte header is laid down on the stack, make_ciphertext fills the rest of
 * the buffer and returns its length, and that buffer (plus the length) is
 * handed to CPSi_TcpWrite2Raw along with the two zero flags and this object.  The
 * state byte is cleared either way.
 */
void CPSi_SslShutdown(CPSSoc *p)
{
    CPSSslConnection *q;
    u8 buf[0x1c];

    q = p->con;
    if (q->state == 8) {
        buf[0] = 0x15;
        buf[1] = 3;
        buf[2] = 0;
        buf[3] = 0;
        buf[4] = 2;
        buf[5] = 1;
        buf[6] = 0;
        CPSi_TcpWrite2Raw(buf, make_ciphertext(q, buf), 0, 0, (struct CPSSoc *)p);
    }
    q->state = 0;
}


void CPSi_SslClose(CPSSoc *soc)
{
    CPSSslConnection *con = soc->con;
    void *p;

    con->state = 0;
    p = con->buf;
    if (p != 0)
        CPSiFree(p);
    con->buf = 0;
}


void CPS_SetSsl(int mode)
{
    CPSSoc *soc;

    OSi_ReferSymbol(id_string);
    soc = *(CPSSoc **)((char *)OSi_ThreadInfo.current + 0xa4);
    if (soc != 0)
        soc->ssl = mode;
}


/*
 * sdk:      CPSi_SslPeriodical (ssl.o)
 */
void CPSi_SslPeriodical(unsigned long now)
{
    int i;
    CPSSoc *soc;
    OSThread *t;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    for (i = 0; i < 4; i++) {
        struct CPSSslSession *p = &gCpsSslSessionCache[i];
        if (p->valid && (long)(now - p->last_used) > 957)
            p->valid = 0;
    }
    OS_RestoreInterrupts(enabled);

    for (t = OSi_ThreadInfo.list; t != 0; t = t->next) {
        soc = (CPSSoc *)t->specific[0];
        if (soc && soc->thread && soc->ssl && soc->state == 4 &&
            soc->con->state < 8 &&
            (long)(now - soc->when) > 239 && soc->block_type == 2) {
            soc->state = 0;
            soc->block_type = 0;
            OS_WakeupThreadDirect(soc->thread);
        }
    }
}


void CPSi_SslCleanup(void)
{
    MI_CpuFill8(gCpsSslSessionCache, 0, 0x170);
}
