/*
 * function: func_021C0318
 * address:  0x021C0318
 * packet:   pkt_ov114_021C0318
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiCallPostCallback (ghttpcallbacks)
 *
 * symbols:
 *   ArrayLength  0x02184200 arm ov009
 */

typedef struct GHIConnection {
    char pad0[4];
    int request;
    char pad1[0x44];
    void *param;
    char pad2[0x118];
    void *postingState;
    int postingFileBytesPosted;
    int postingTotalBytes;
    int postingCurrentFile;
    void (*postCallback)(int, int, int, int, int, void *);
} GHIConnection;

extern int ArrayLength(void *array);

void func_021C0318(GHIConnection *connection)
{
    if (connection->postCallback != 0)
        connection->postCallback(connection->request, connection->postingTotalBytes, connection->postingCurrentFile, connection->postingFileBytesPosted, ArrayLength(connection->postingState), connection->param);
}
