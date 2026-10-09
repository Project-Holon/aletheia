/*
 * file:     unit_0215FDA4_p13.c
 * unit:     yes
 * function: func_02162968, func_021629BC, func_02162A94, func_02162AE4
 * address:  0x02162968
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
 *   func_0215ABB0  0x0215ABB0  arm  ov009
 *   func_02163C9C  0x02163C9C  arm  ov009
 *   func_021633F0  0x021633F0  arm  ov009
 *   func_0216289C  0x0216289C  arm  ov009
 *   func_02161BE8  0x02161BE8  arm  ov009
 *   func_02161C80  0x02161C80  arm  ov009
 *   func_02161F98  0x02161F98  arm  ov009
 *   g_021A82B0  0x021A82B0  data
 *   CPSiFree                         0x021a82b0 data
 *   func_0215AE18  0x0215AE18  arm  ov009
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0215AF14  0x0215AF14  arm  ov009
 *   g_021A8280     0x021A8280  data ov009
 */
struct Soc;
struct _CPSSoc;
typedef struct CPSSslConnection_02162968 {
    unsigned char pad0[0x1d4];
    int f1d4;                           /* +0x1d4 */
    unsigned char pad1d8[0x2ec - 0x1d8];
    unsigned char sha1[0x3a4 - 0x2ec];  /* +0x2ec */
    unsigned char md5[0x454 - 0x3a4];   /* +0x3a4 */
    unsigned char f454;                 /* +0x454 */
    unsigned char f455;                 /* +0x455 */
} CPSSslConnection_02162968;

typedef struct CPSSoc_02162968 {
    unsigned char pad0[8];
    unsigned char state;                /* +0x8 */
    unsigned char pad9[3];
    CPSSslConnection_02162968 *con;              /* +0xc */
} CPSSoc_02162968;

typedef struct CPSSslConnection_0215FDA4 {
    unsigned char pad0[0x456];
    unsigned char have_record;          /* +0x456 */
    unsigned char pad457[0x824 - 0x457];
    unsigned char *buf;                 /* +0x824 */
    unsigned long end;                  /* +0x828 */
    unsigned long pos;                  /* +0x82c */
} CPSSslConnection_0215FDA4;

typedef struct CPSSoc_0215FDA4 {
    unsigned char pad0[0xc];
    CPSSslConnection_0215FDA4 *con;              /* +0xc */
} CPSSoc_0215FDA4;

struct _CPSSslConnection {
	unsigned char pad[0x824];
	void *buf;
	unsigned long avail;
	unsigned long acked;
};

struct _CPSSoc {
	unsigned char pad[0xc];
	struct _CPSSslConnection *con;
};

typedef struct CPSSoc {
    unsigned char pad0[0xC];
    struct CPSSslConnection *con;
    unsigned char pad1[0x40];
    unsigned long rcvbufp;
} CPSSoc;

typedef struct CPSSslConnection {
    unsigned char pad0[0x455];
    unsigned char state;
    unsigned char inbuf_decrypted;
    unsigned char pad1[0x824 - 0x457];
    unsigned char *inbuf;
    long inbuf_len;
    long inbuf_pnt;
} CPSSslConnection;

extern unsigned long func_0215ABB0(struct Soc *soc);
extern void func_02163C9C(void *ctx);
extern void func_021633F0(void *ctx);
extern int func_0216289C(CPSSoc_02162968 *soc);
extern int func_02161BE8(unsigned char *d, int len, CPSSoc_0215FDA4 *soc);
extern void func_02161C80(CPSSslConnection_0215FDA4 *con, unsigned char *buf);
extern int func_02161F98(CPSSoc_0215FDA4 *soc);
extern unsigned char *func_0215AE18(unsigned long *len, char *soc);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void func_0215AF14(unsigned long len, struct _CPSSoc *soc);
unsigned long func_02162968(CPSSoc_02162968 *soc);
unsigned char *func_021629BC(unsigned long *len, CPSSoc_0215FDA4 *soc);
void CPSi_SslConsume(unsigned long len, struct _CPSSoc *soc);
void func_02162AE4(CPSSoc *soc);



/*
 * sdk:      CPSi_SslConnect (libssl.TWL.HYB.a(ssl.o))
 */
unsigned long func_02162968(CPSSoc_02162968 *soc)
{
    int result;
    CPSSslConnection_02162968 *con;

    con = soc->con;
    if (soc->state != 4) {
        if (func_0215ABB0((struct Soc *)soc) != 0)
            return 1;
    }
    con->f455 = 0;
    con->f1d4 = 0;
    con->f454 = 0;
    func_02163C9C(con->sha1);
    func_021633F0(con->md5);
    return func_0216289C(soc);
}




extern void (*g_021A82B0)(void *p);




/*
 * sdk:      CPSi_SslRead (libssl.TWL.HYB.a(ssl.o))
 */
unsigned char *func_021629BC(unsigned long *len, CPSSoc_0215FDA4 *soc)
{
    CPSSslConnection_0215FDA4 *con;

    con = soc->con;
    if (con->buf != 0 && con->have_record == 0) {
        if (func_02161BE8(con->buf + con->pos, con->end - con->pos, soc) != 0) {
            g_021A82B0(con->buf);
            con->buf = 0;
            *len = 0;
            return 0;
        }
        func_02161C80(con, con->buf);
        if (con->have_record == 0)
            con->buf = 0;
    }
    while (con->buf == 0) {
        if (func_02161F98(soc) == 9) {
            *len = 0;
            return 0;
        }
    }
    *len = con->end - con->pos;
    return con->buf + con->pos;
}




extern void (*CPSiFree)(void *ptr);




void CPSi_SslConsume(unsigned long len, struct _CPSSoc *soc)
{
	struct _CPSSslConnection *con = soc->con;

	if (len >= con->avail - con->acked) {
		if (con->buf != 0)
			CPSiFree(con->buf);
		con->buf = 0;
	} else {
		con->acked += len;
	}
}


extern unsigned char *(*g_021A8280)(unsigned long size);


/*
 * sdk:      try_fill_record (libssl.TWL.HYB.a ssl.o)
 *
 * Static SSL record reassembly: reads the socket receive buffer into an allocated record buffer, parses it when complete.
 */
void func_02162AE4(CPSSoc *soc)
{
    int got_all;
    unsigned long len;
    unsigned char *s;
    CPSSslConnection *con = soc->con;

    if (con->inbuf == 0) {
        if (soc->rcvbufp < 5) return;
        s = func_0215AE18(&len, (char *)soc);
        len = (s[3] << 8) + s[4] + 5;
        if (len > 0x4805) {
            con->state = 9;
            return;
        }
        con->inbuf = g_021A8280(len);
        if (con->inbuf == 0) {
            con->state = 9;
            return;
        }
        con->inbuf_len = len;
        con->inbuf_pnt = 0;
        con->inbuf_decrypted = 0;
    } else if (soc->rcvbufp == 0) {
        return;
    }
    s = func_0215AE18(&len, (char *)soc);
    if (len >= (unsigned long)(con->inbuf_len - con->inbuf_pnt)) {
        len = con->inbuf_len - con->inbuf_pnt;
        got_all = 1;
    } else {
        got_all = 0;
    }
    MI_CpuCopy8(s, con->inbuf + con->inbuf_pnt, len);
    func_0215AF14(len, (struct _CPSSoc *)soc);
    if (got_all) {
        func_02161C80((CPSSslConnection_0215FDA4 *)con, con->inbuf);
        if (con->inbuf_decrypted == 0) con->inbuf = 0;
    } else {
        con->inbuf_pnt += len;
    }
}
