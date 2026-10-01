/*
 * function: qr2_parse_queryA
 * address:  0x0219C7C0
 * packet:   pkt_ov009_0219C7C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  register colouring.  The three callee-saved homes are a 3-cycle
 *   against the image (image r7=sender / r6=query / r8=len; this build
 *   r6=sender / r8=query / r7=len) and the frame is one int short (0x188 vs
 *   the image's 0x18c), so 1034 concrete bytes differ across the whole body.
 *   Re-measured 2026-09-30: 38/46 relocs resolve; the 8 unresolved are the
 *   debug format strings with no witness outside 0219C7C0..0219CDA0.
 *   scratch/U44/vD.c (all four U44 fixes below) re-compiles to 1560 bytes /
 *   1061 concrete, i.e. worse, so it is not the lever.  No <=8-byte residue
 *   to permute; the rotation is the blocker.
 *   Re-checked 2026-10-01: the frame split is allocator-only, not a source
 *   defect -- image 9 saved (36) + 0x18c (396) = build 10 saved (40) + 0x188
 *   (392) = 432 bytes of stack either way, so the missing int is the allocator
 *   spending r3 on a saved home.  The `s = s;` colouring lever (idiom
 *   a-no-code-self-assignment-reorders-the-register-colouring) was tried with
 *   self-assignments of query/len/sender at entry: compiled away, still 1504
 *   B / 1034 concrete, inert for whole-function-live parameters.  The 8 strings
 *   are not `@N` initializer templates (they are named data), so the `template`
 *   class does not reach them either.
 *
 * sdk:      qr2_parse_queryA (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * residue:  DIFF, 1504/1532 bytes (the parked body was 1472).  Two real source
 *   defects were read off the image and fixed here:
 *   (1) the vendor calls func_0217D254(3, 0, 0x40, g_021A7874) at entry, before
 *       the qrec == 0 test.  The string was identified from the image's first pool
 *       word: ldr r3,[pc,#0x58c] at +0x20 -> 0x219CD74 holds 0x021A7874.  Without
 *       that call the prologue is 4 bytes out, the whole body is misaligned and the
 *       function is 60 bytes short.
 *   (2) the `len < 7` test uses ptype, not a second *query load, and both bytes are
 *       unsigned: the image emits `and r0, r5, #0xff / cmp r0, #0xfe` and `ldrb` for
 *       query[1], ours emitted `ldrsb` twice.  Now
 *       `(unsigned char)ptype != 0xfe || (unsigned char)query[1] != 0xfd`.
 *   What is left is register assignment and constant hoisting, 300 concrete
 *   instructions, no size-bearing statement: image `push {r4-r8,sb,sl,fp,lr}` +
 *   `sub sp,#0x18c` | ours `push {r3,...}` + `sub sp,#0x188`; image keeps query/len/
 *   sender in r6/r8/r7, ours in r8/r7/r6 (one-register rotation); image hoists &buf
 *   into fp (`add fp, sp, #0x10` at +0048) and rematerialises 0 (`mov r1, #0`),
 *   ours keeps 0 in fp and rematerialises &buf (`add r0, sp, #0xc`).  Ours needs one
 *   more callee-saved register than the image (r3 padding in the push).
 *
 * U44 (measured 2026-09-30, all four verified by compile in scratch/U44/, none of
 *   them was folded into the body below because each one moves the extent):
 *   the `ptype` 8/16-level debug calls use the wrong pool word.  The image's pool
 *   entry at 0x0219CDB0 is 0x021A7A38 (member data local @14962) and it is loaded
 *   by the `+04E8 ldr r3,[pc,#0x100]` in case 8; case 10 loads 0x021A7A58
 *   (`+0508 ldr r3,[pc,#0xe4]`), and only SEND uses 0x021A7A74.  So case 8 is
 *   gsDebugFormat(3,0,0x10,g_021A7A38), case 10 is ...g_021A7A58.  Adding the
 *   missing g_021A7A38 (plus its symbols: line) takes the pool from 17 to the
 *   image's 18 words.
 *   Case 6's two unaligned four-byte copies are memcpy(dst,src,4)/memcpy(&i,query,4)
 *   through the house string.h (`#include "../../matched/arm9_sdk/libc/string.h"`).
 *   The second one matters for the frame, not just the codegen: memcpy(&i,...) is
 *   what gives `i` a memory home at [fb+12], and with it the build produces the
 *   image's `push {r4,r5,r6,r7,r8,sb,sl,fp,lr}` and `sub sp,sp,#0x18c` (the build
 *   below pushes r3 with a 0x188 frame, i.e. it is one 4-byte local short).  With
 *   that fix the prologue and every `str r1,[sp,#0x588]` match; `query += 7;
 *   len -= 7;` must also sit before the qr_add_packet_header call, not after.
 *   Residue after all four: image r7=sender/r6=query/r8=len, this build keeps
 *   r6=sender/r8=query/r7=len (a 3-cycle), and the code region grows to 0x5d0
 *   against the image's 0x5b4 (1560 bytes against 1532, 319 diff rows).
 *   Scratch copies: scratch/U44/vB.c, vC.c, vD.c (vD carries all four fixes).
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   func_0219AB8C  0x0219AB8C  arm  ov009
 *   func_0219BA84  0x0219BA84  arm  ov009
 *   func_0219C5B8  0x0219C5B8  arm  ov009
 *   func_0219C724  0x0219C724  arm  ov009
 *   func_0219C154  0x0219C154  arm  ov009
 *   func_0208CF34  0x0208CF34  arm
 *   func_0219BB54  0x0219BB54  arm  ov009
 *   func_0219BAB4  0x0219BAB4  arm  ov009
 *   func_02092344  0x02092344  arm
 *   func_0219C554  0x0219C554  arm  ov009
 *   func_0219C3A4  0x0219C3A4  arm  ov009
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 *   func_0217D32C  0x0217D32C  arm  ov009
 *   current_rec    0x021A6600  data
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021A7874     0x021A7874  data
 *   g_021A788C     0x021A788C  data
 *   g_021A78B4     0x021A78B4  data
 *   g_021A78F0     0x021A78F0  data
 *   g_021A791C     0x021A791C  data
 *   g_021A7944     0x021A7944  data
 *   g_021A7960     0x021A7960  data
 *   g_021A7980     0x021A7980  data
 *   g_021A7988     0x021A7988  data
 *   g_021A79A8     0x021A79A8  data
 *   g_021A79D8     0x021A79D8  data
 *   g_021A79F4     0x021A79F4  data
 *   g_021A7A14     0x021A7A14  data
 *   g_021A7A58     0x021A7A58  data
 *   g_021A7A74     0x021A7A74  data
 */

typedef struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned char data[6];
} SOCSockAddr;

typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    SOCInAddr addr;
} SOCSockAddrIn;

typedef struct qr2_buffer_s {
    char buffer[1400];
    int len;
} qr2_buffer_s;

typedef struct qr2_implementation_s {
    int hbsock;                                        /* 0x000 */
    unsigned char pad0[0x80];
    char instance_key[4];                              /* 0x084 */
    void *server_key_callback;                         /* 0x088 */
    void *player_key_callback;                         /* 0x08C */
    void *team_key_callback;                           /* 0x090 */
    void *key_list_callback;                           /* 0x094 */
    void *playerteam_count_callback;                   /* 0x098 */
    void (*adderror_callback)(int, char *, void *);    /* 0x09C */
    void *nn_callback;                                 /* 0x0A0 */
    void *cm_callback;                                 /* 0x0A4 */
    void *pa_callback;                                 /* 0x0A8 */
    void *cc_callback;                                 /* 0x0AC */
    void (*hr_callback)(void *);                       /* 0x0B0 */
    unsigned int lastheartbeat;                        /* 0x0B4 */
    unsigned int lastka;                               /* 0x0B8 */
    int userstatechangerequested;                      /* 0x0BC */
    int listed_state;                                  /* 0x0C0 */
    int ispublic;                                      /* 0x0C4 */
    int qport;                                         /* 0x0C8 */
    int read_socket;                                   /* 0x0CC */
    int nat_negotiate;                                 /* 0x0D0 */
    char hbaddr[8];                                    /* 0x0D4 */
    void (*cdkeyprocess)(char *, int, SOCSockAddr *);  /* 0x0DC */
    int client_message_keys[10];                       /* 0x0E0 */
    int cur_message_key;                               /* 0x108 */
    unsigned int publicip;                             /* 0x10C */
    unsigned short publicport;                         /* 0x110 */
    void *udata;                                       /* 0x114 */
    unsigned char backendoptions;                      /* 0x118 */
} qr2_implementation_s;

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                   (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

extern qr2_implementation_s *current_rec;
extern unsigned char g_021A5A7C[];
extern char g_021A7874[];
extern char g_021A788C[];
extern char g_021A78B4[];
extern char g_021A78F0[];
extern char g_021A791C[];
extern char g_021A7944[];
extern char g_021A7960[];
extern char g_021A7980[];
extern char g_021A7988[];
extern char g_021A79A8[];
extern char g_021A79D8[];
extern char g_021A79F4[];
extern char g_021A7A14[];
extern char g_021A7A58[];
extern char g_021A7A74[];

extern void func_0217D254(int theCat, int theType, unsigned char theLevel,
                          const char *theTokenStr, ...);
extern int func_020923F0(const void *s1, const void *s2, int n);
extern void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr);
extern void func_0219BA84(qr2_buffer_s *buf, char ptype, char *reqkey);
extern int func_0219C5B8(qr2_implementation_s *qrec, qr2_buffer_s *buf,
                         SOCSockAddrIn *sender);
extern int func_0219C724(qr2_implementation_s *qrec, SOCSockAddrIn *sender,
                         unsigned int ipverify);
extern void func_0219C154(qr2_implementation_s *qrec, qr2_buffer_s *buf,
                          unsigned char *qdata, int len, SOCSockAddr *sender);
extern int func_0208CF34(char *src, char *fmt, ...);
extern void func_0219BB54(qr2_implementation_s *qrec, char *buffer);
extern void func_0219BAB4(qr2_implementation_s *qrec, qr2_buffer_s *buf,
                          char *challenge, int challengelen);
extern void func_02092344(void *dst, void *src, unsigned long size);
extern int func_0219C554(qr2_implementation_s *qrec, int msgkey);
extern void func_0219C3A4(qr2_implementation_s *qrec, char *buf, int len);
extern int func_0217ECA4(int sock, char *buf, int len, int flags,
                         SOCSockAddr *addr, int tolen);
extern void func_0217D32C(int theCat, int theType, unsigned char theLevel,
                          char *theBuffer, int theLength);

void qr2_parse_queryA(qr2_implementation_s *qrec, char *query, int len,
                      SOCSockAddr *sender)
{
    char ptype;
    char *reqkey;
    qr2_buffer_s buf;
    int i;
    unsigned char backendoptions;

    buf.len = 0;
    func_0217D254(3, 0, 0x40, g_021A7874);
    if (qrec == 0)
        qrec = current_rec;
    ptype = *query;
    if (ptype == ';') {
        if (qrec->cdkeyprocess != 0) {
            func_0217D254(3, 0, 8, g_021A788C);
            qrec->cdkeyprocess(query, len, sender);
            return;
        }
        func_0217D254(3, 0, 2, g_021A78B4);
        return;
    }
    if (len >= 6 && func_020923F0(query, g_021A5A7C, 6) == 0) {
        func_0217D254(3, 0, 8, g_021A78F0);
        func_0219AB8C(query, len, (SOCSockAddrIn *)sender);
        return;
    }
    if (len < 7 || (unsigned char)ptype != 0xfe || (unsigned char)query[1] != 0xfd)
        return;
    if (qrec->listed_state > 0)
        qrec->listed_state = 0;
    reqkey = query + 3;
    ptype = query[2];
    func_0219BA84(&buf, ptype, reqkey);
    query += 7;
    len -= 7;
    if ((unsigned char)ptype > 10)
        return;

    switch (ptype) {
    case 0:
        func_0217D254(3, 0, 8, g_021A7944);
        if ((qrec->backendoptions & 0x80) == 0x80) {
            unsigned int ipverify;

            if (len < 4)
                return;
            ipverify = *(unsigned int *)query;
            query += 4;
            len -= 4;
            if (func_0219C724(qrec, (SOCSockAddrIn *)sender,
                              SWAP32(ipverify)) == 0)
                return;
        }
        func_0219C154(qrec, &buf, (unsigned char *)query, len, sender);
        return;
    case 1:
        func_0217D254(3, 0, 8, g_021A7960);
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len >= 15) {
            char *end = query + len;

            func_0208CF34(end - 15, g_021A7980, &backendoptions);
            qrec->backendoptions = backendoptions;
            func_0217D254(3, 4, 8, g_021A7988, backendoptions & 0xff);
            if (qrec->pa_callback != 0)
                func_0219BB54(qrec, end - 13);
            else
                func_0217D254(3, 0, 8, g_021A79A8);
        }
        func_0219BAB4(qrec, &buf, query, len);
        goto SEND;
    case 2:
        func_0217D254(3, 0, 8, g_021A79D8);
        if (len > 0x20)
            len = 0x20;
        buf.buffer[0] = 5;
        func_02092344(&buf.buffer[buf.len], query, len);
        buf.len += len;
        goto SEND;
    case 3:
        return;
    case 4:
        func_0217D254(3, 0, 2, g_021A79F4);
        if (qrec->listed_state == -1)
            return;
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len < 2)
            return;
        qrec->listed_state = -1;
        qrec->adderror_callback(*query, query + 1, qrec->udata);
        return;
    case 5:
        return;
    case 6:
        func_0217D254(3, 0, 8, g_021A7A14);
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len < 4)
            return;
        buf.buffer[0] = 7;
        i = *(int *)query;
        *(int *)&buf.buffer[buf.len] = *(int *)query;
        buf.len += 4;
        if (func_0219C554(qrec, i) == 0)
            func_0219C3A4(qrec, query + 4, len - 4);
        goto SEND;
    case 7:
        return;
    case 8:
        func_0217D254(3, 0, 0x10, g_021A7A58);
        return;
    case 9:
        func_0217D254(3, 0, 8, g_021A791C);
        if (func_0219C5B8(qrec, &buf, (SOCSockAddrIn *)sender) != 0)
            goto SEND;
        return;
    case 10:
        func_0217D254(3, 0, 0x10, g_021A7A74);
        if (qrec->hr_callback == 0)
            return;
        qrec->hr_callback(qrec->udata);
        return;
    }

SEND:
    func_0217ECA4(qrec->hbsock, buf.buffer, buf.len, 0, sender, 8);
    func_0217D254(3, 0, 0x10, g_021A7A74, buf.len);
    func_0217D32C(3, 0, 0x20, buf.buffer, buf.len);
}
