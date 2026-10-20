#ifndef GAME_OV009_QR2_H
#define GAME_OV009_QR2_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of qr2.c, prototypes copied from their definitions. */

struct QRSplitQueryProgress;
typedef struct QRSplitQueryProgress QRSplitQueryProgress;

#include "../ov009/qr2_types.h"
#include "../ov009/qr2_types.h"
#include "../ov009/qr2_types.h"
#include "../ov009/qr2_types.h"
#include "../ov009/qr2_types.h"
#include "../sdk_soc.h"

int qr2_init_socketA(qr2_implementation_s **qrec, int s, int boundport, char *gamename, char *secret_key, int ispublic, int natnegotiate, void (*server_key_callback)(int, qr2_buffer_s *, void *), void (*player_key_callback)(int, int, qr2_buffer_s *, void *), void (*team_key_callback)(int, int, qr2_buffer_s *, void *), void (*key_list_callback)(qr2_key_type, qr2_keybuffer_s *, void *), int (*playerteam_count_callback)(qr2_key_type, void *), void (*adderror_callback)(int, char *, void *), void *userdata);
void qr2_register_natneg_callback(qr2_implementation_s *qrec, void (*nncallback)(int, void *));
void qr2_register_clientmessage_callback(qr2_implementation_s *qrec, void (*cmcallback)(char *, int, void *));
void qr2_register_publicaddress_callback(qr2_implementation_s *qrec, void (*pacallback)(unsigned int, unsigned short, void *));
void qr2_think(qr2_implementation_s *qrec);
void qr2_check_queries(qr2_implementation_s *qrec);
void qr2_check_send_heartbeat(qr2_implementation_s *qrec);
void qr2_send_statechanged(qr2_implementation_s *qrec);
void qr2_shutdown(qr2_implementation_s *qrec);
int qr2_keybuffer_add(qr2_keybuffer_s *keybuffer, int keyid);
int qr2_buffer_add_int(qr2_buffer_s *outbuf, int value);
int qr2_buffer_addA(qr2_buffer_s *outbuf, char *value);
void swap_byte(unsigned char *p, unsigned char *q);
void gs_encode(unsigned char *ins, int size, unsigned char *result);
void gs_encrypt(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len);
void NatNegProgressCallback(int state, void *userdata);
void NatNegCompletedCallback(int result, int gamesocket, SOCSockAddrIn *remoteaddr, void *userdata);
void qr_add_packet_header(qr2_buffer_s *buf, char ptype, char *reqkey);
void compute_challenge_response(qr2_implementation_s *qrec, qr2_buffer_s *buf, char *challenge, int challengelen);
void handle_public_address(qr2_implementation_s *qrec, char *buffer);
void qr_build_partial_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, qr2_key_type keytype, int keycount, unsigned char *keys);
void qr_build_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, int serverkeycount, unsigned char *serverkeys, int playerkeycount, unsigned char *playerkeys, int teamkeycount, unsigned char *teamkeys);
int qr_build_split_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, QRSplitQueryProgress *progress);
void qr_process_query(qr2_implementation_s *qrec, qr2_buffer_s *buf, unsigned char *qdata, int len, SOCSockAddr *sender);
void qr_process_client_message(qr2_implementation_s *qrec, char *buf, int len);
int qr2_process_ip_verify(qr2_implementation_s *qrec, qr2_buffer_s *buf, SOCSockAddrIn *sender);
void qr2_expire_ip_verify(qr2_implementation_s *qrec);
void qr2_parse_queryA(qr2_implementation_s *qrec, char *query, int len, SOCSockAddr *sender);
void send_keepalive(qr2_implementation_s *qrec);
void send_heartbeat(qr2_implementation_s *qrec, int statechanged);
/* END mkheaders: generated region */

#endif
