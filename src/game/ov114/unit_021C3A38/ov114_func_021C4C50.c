/*
 * function: func_021C4C50
 * address:  0x021C4C50
 * packet:   pkt_ov114_021C4C50
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiProcessIncomingFileData (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_02094A28  0x02094A28  arm
 *   func_021C4C00  0x021C4C00  arm  ov114
 *   func_021C4BD8  0x021C4BD8  arm  ov114
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021C4B18  0x021C4B18  arm  ov114
 *   g_021CF24C     0x021CF24C  data
 *   g_021CF25C     0x021CF25C  data
 *   g_021CF274     0x021CF274  data
 *   g_021CF28C     0x021CF28C  data
 *   g_021CF2A0     0x021CF2A0  data
 */

typedef struct GHIConnection {
    char pad000[0x40];
    int result;                    /* 0x040 */
    char pad044[0xE0];
    int completed;                 /* 0x124 */
    char pad128[0x10];
    int chunkedTransfer;           /* 0x138 */
    char chunkHeader[12];          /* 0x13C */
    int chunkHeaderLen;            /* 0x148 */
    int chunkBytesLeft;            /* 0x14C */
    int chunkReadingState;         /* 0x150 */
} GHIConnection;

extern char *func_02094A28(const char *s, int c);
extern void func_021C4C00(GHIConnection *connection, char *data, int len);
extern int func_021C4BD8(GHIConnection *connection);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_021C4B18(GHIConnection *connection, char *data, int len);
extern char g_021CF24C[];
extern char g_021CF25C[];
extern char g_021CF274[];
extern char g_021CF28C[];
extern char g_021CF2A0[];

int func_021C4C50(GHIConnection *connection, char *data, int len)
{
    char *endOfHeader;
    char *endOfFooter;
    int toWrite;

    if (connection->chunkedTransfer)
    {
        while (len > 0)
        {
            if (connection->chunkReadingState == 0)
            {
                endOfHeader = func_02094A28(data, '\n');
                if (endOfHeader != 0)
                {
                    func_021C4C00(connection, data, endOfHeader - data);
                    endOfHeader++;
                    len -= endOfHeader - data;
                    data = endOfHeader;
                    connection->chunkBytesLeft = func_021C4BD8(connection);
                    if (connection->chunkBytesLeft == -1)
                    {
                        connection->completed = 1;
                        connection->result = 7;
                        return 0;
                    }
                    if (connection->chunkBytesLeft == 0)
                    {
                        connection->chunkReadingState = 3;
                        func_0217D254(8, 0, 0x20, g_021CF24C);
                    }
                    else
                    {
                        connection->chunkReadingState = 1;
                        func_0217D254(8, 0, 0x20, g_021CF25C, connection->chunkBytesLeft);
                    }
                }
                else
                {
                    func_021C4C00(connection, data, len);
                    return 1;
                }
            }
            else if (connection->chunkReadingState == 1)
            {
                toWrite = connection->chunkBytesLeft;
                if (toWrite >= len)
                    toWrite = len;
                func_0217D254(8, 0, 0x20, g_021CF274, toWrite);
                if (!func_021C4B18(connection, data, toWrite))
                    return 0;
                data += toWrite;
                len -= toWrite;
                connection->chunkBytesLeft -= toWrite;
                if (connection->chunkBytesLeft == 0)
                    connection->chunkReadingState = 2;
            }
            else if (connection->chunkReadingState == 2)
            {
                endOfFooter = func_02094A28(data, '\n');
                if (endOfFooter == 0)
                    return 1;
                endOfFooter++;
                len -= endOfFooter - data;
                data = endOfFooter;
                connection->chunkHeader[0] = '\0';
                connection->chunkHeaderLen = 0;
                connection->chunkBytesLeft = 0;
                connection->chunkReadingState = 0;
                func_0217D254(8, 0, 0x20, g_021CF28C);
            }
            else if (connection->chunkReadingState == 3)
            {
                connection->completed = 1;
                func_0217D254(8, 0, 0x20, g_021CF2A0);
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    return func_021C4B18(connection, data, len);
}
