/*
 * file:     unit_021BFB90_p03.c
 * unit:     yes
 * function: func_021C00C0, func_021C00FC, func_021C011C
 * address:  0x021C00C0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_SPrintf             0x02084F40 arm
 *   ghiAppendDataToBuffer  0x021BFCEC arm ov114
 *   g_021CE594             0x021CE594 data
 *   GSISocketSelect  0x0217ed64  arm  ov009
 *   GOAGetLastError  0x0217ed54  arm  ov009
 *   func_021C0684    0x021c0684  arm  ov114
 */
typedef struct {
    char pad0[4];
    char *data;
    int size;
    int length;
    int pos;
    char pad1[12];
    int fixed;
    char pad2[4];
} GHIBuffer;

typedef struct GHIConnection {
    unsigned char pad0[0x40];
    int f40;
    unsigned char pad1[0x50 - 0x44];
    int f50;
    int f54;
    unsigned char pad2[0x5c - 0x58];
    char *f5c;
    unsigned char pad3[0x64 - 0x60];
    int f64;
    int f68;
    unsigned char pad4[0x124 - 0x6c];
    int f124;
    unsigned char pad5[0x198 - 0x128];
    int f198;
    unsigned char pad6[0x1a8 - 0x19c];
    int f1a8;
} GHIConnection;

extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int GSISocketSelect(int, int *, int *, int *);
extern int GOAGetLastError(int);
extern int func_021C0684(GHIConnection *, char *, int);
int func_021C00C0(GHIBuffer *buffer, int i);
void func_021C00FC(GHIBuffer *buffer);
int func_021C011C(GHIConnection *connection);
extern char g_021CE594[];


/*
 * sdk:      ghiAppendIntToBuffer (ghttpbuffer)
 */
int func_021C00C0(GHIBuffer *buffer, int i)
{
    char intValue[16];
    OS_SPrintf(intValue, g_021CE594, i);
    return ghiAppendDataToBuffer(buffer, intValue, 0);
}


void func_021C00FC(GHIBuffer *buffer)
{
    buffer->length = 0;
    buffer->pos = 0;
    if (buffer->fixed == 0)
        buffer->data[0] = 0;
}


/*
 * sdk:      ghiSendBufferedData (libdwcgsghttp.TWL.HYB.a ghttpbuffer.o)
 *
 * The -2/-1 tail needs the goto spelling (return-1 label between the
 * return-0 and the loop continuation) to keep the returns unpredicated.
 */
int func_021C011C(GHIConnection *connection)
{
    int writeFlag;
    int exceptFlag;
    int rcode;

    for (;;) {
        if (connection->f198 == 0 || connection->f1a8 == 1) {
            rcode = GSISocketSelect(connection->f50, 0, &writeFlag, &exceptFlag);
            if (rcode == -1 || (rcode == 1 && exceptFlag != 0)) {
                connection->f124 = 1;
                connection->f40 = 5;
                connection->f54 = (rcode == -1) ? GOAGetLastError(connection->f50) : 0;
                return 0;
            }
            if (rcode < 1 || writeFlag == 0)
                return 1;
        }
        rcode = func_021C0684(connection, connection->f5c + connection->f68, connection->f64 - connection->f68);
        if (rcode == -2)
            goto done;
        if (rcode != -1)
            goto cont;
        return 0;
    done:
        return 1;
    cont:
        connection->f68 += rcode;
        if (connection->f68 >= connection->f64)
            return 1;
    }
}
