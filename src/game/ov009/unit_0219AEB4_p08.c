/*
 * file:     unit_0219AEB4_p08.c
 * unit:     yes
 * function: func_0219B540, func_0219B5EC, func_0219B628, func_0219B660
 * address:  0x0219B540
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
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0219CE58  0x0219CE58  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   func_0217F260  0x0217F260  arm  ov009
 *   func_0219922C  0x0219922C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   g_021A7674  0x021A7674  data
 *   g_021A6600  0x021A6600  data
 *   g_021A6604  0x021A6604  data
 *   OS_SPrintf       0x02084F40  arm
 *   g_021A7688       0x021A7688  data
 *   strlen   0x0209477C  arm
 *   memcpy   0x02092344  arm
 */
#include "../../matched/include/G_021A6604.h"

typedef struct qr2_implementation_s {
    int hbsock;
    unsigned char pad4[0xA8];
    int natnegActive;
    unsigned char padAC2[4];
    int lastHeartbeat;
    unsigned char padB8[0xC];
    int stateChanged;
    unsigned char padC8[4];
    int ownsSocket;
} qr2_implementation_s;

struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0219CE58(qr2_implementation_s *qrec, int statechanged);
extern int func_0217EB2C(int sock);
extern void func_0217F260();
extern void func_0219922C(void);
extern void func_0217EAE0(void *ptr);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern unsigned int strlen(const char *s);
extern void *memcpy(void *dst, const void *src, unsigned int n);
/* * sdk: qr2_shutdown (qr2.o) */ void func_0219B540(qr2_implementation_s *qrec);
/* * Appends a byte to the buffer at +0x100 of the block while the count is * under 0xfe and the value is 1..0xfe; 0 when either bound is hit. */ int func_0219B5EC(char *p, int v);
int qr2_buffer_add_int(struct qr2_buffer_s *outbuf, int value);
int qr2_buffer_addA(struct qr2_buffer_s *outbuf, char *value);
extern char g_021A7674[];
extern qr2_implementation_s *g_021A6600;
extern struct G_021A6604 g_021A6604;
extern char g_021A7688[];



/*
 * sdk:      qr2_shutdown (qr2.o)
 */
void func_0219B540(qr2_implementation_s *qrec)
{
    func_0217D254(3, 0, 0x40, g_021A7674);
    if (!qrec)
        qrec = g_021A6600;
    if (qrec->stateChanged)
        func_0219CE58(qrec, 2);
    if (qrec->hbsock != -1 && qrec->ownsSocket)
        func_0217EB2C(qrec->hbsock);
    qrec->hbsock = -1;
    qrec->lastHeartbeat = 0;
    if (qrec->ownsSocket)
        func_0217F260();
    if (qrec->natnegActive)
        func_0219922C();
    if (qrec != ((qr2_implementation_s *)&g_021A6604))
        func_0217EAE0(qrec);
}


/*
 * Appends a byte to the buffer at +0x100 of the block while the count is
 * under 0xfe and the value is 1..0xfe; 0 when either bound is hit.
 */
int func_0219B5EC(char *p, int v)
{
    int n = *(int *)(p + 0x100);

    if (n >= 0xfe) return 0;
    if (v < 1 || v > 0xfe) return 0;
    *(int *)(p + 0x100) = n + 1;
    *(unsigned char *)(p + n) = v;
    return 1;
}



int qr2_buffer_add_int(struct qr2_buffer_s *outbuf, int value)
{
    char temp[20];

    OS_SPrintf(temp, g_021A7688, value);
    return qr2_buffer_addA(outbuf, temp);
}



int qr2_buffer_addA(struct qr2_buffer_s *outbuf, char *value)
{
    int copylen = strlen(value) + 1;

    if (copylen > 1400 - outbuf->len)
        copylen = 1400 - outbuf->len;
    if (copylen <= 0)
        return 0;
    memcpy(outbuf->buffer + outbuf->len, value, copylen);
    outbuf->len += copylen;
    outbuf->buffer[outbuf->len - 1] = 0;
    return 1;
}
