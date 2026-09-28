/*
 * function: gti2SendFilterCallback
 * address:  0x02195278
 * packet:   pkt_ov009_02195278
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gti2SendFilterCallback (libdwcgsgt2.TWL.HYB.a gt2callback.o)
 * symbols:
 *   ArrayNth         0x02184208 arm
 *   gti2CloseSocket  0x02197FDC arm
 */

extern void *ArrayNth(void *array, int n);
extern void gti2CloseSocket(void *socket);

typedef void (*GT2SendFilterFunc)(void *connection, int filterID,
    unsigned char *message, int len, int reliable);

int gti2SendFilterCallback(void *connection, int filterID, unsigned char *message,
    int len, int reliable)
{
    GT2SendFilterFunc *callback;

    if (connection == 0)
        return 1;
    callback = (GT2SendFilterFunc *)ArrayNth(*(void **)((char *)connection + 0x98),
        filterID);
    if (callback == 0)
        return 1;
    (*(int *)((char *)connection + 0x24))++;
    (*(int *)(*(char **)((char *)connection + 8) + 0x1c))++;
    if (len == 0 || message == 0) {
        message = 0;
        len = 0;
    }
    (*callback)(connection, filterID, message, len, reliable);
    (*(int *)((char *)connection + 0x24))--;
    (*(int *)(*(char **)((char *)connection + 8) + 0x1c))--;
    if (*(int *)(*(char **)((char *)connection + 8) + 0x14) != 0 &&
        *(int *)(*(char **)((char *)connection + 8) + 0x1c) == 0) {
        gti2CloseSocket(*(void **)((char *)connection + 8));
        return 0;
    }
    return 1;
}
