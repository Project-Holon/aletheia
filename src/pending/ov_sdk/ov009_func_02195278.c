/*
 * function: gti2SendFilterCallback
 * address:  0x02195278
 * packet:   pkt_ov009_02195278
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (capped - see residue)
 *
 * residue (lane T3, 2026-09-30, measured): 38 concrete bytes. The callback pointer is allocated to r2 instead of r0, which shifts every temporary in the body. First diff +0024 image `cmp r0, #0` | ours `movs r2, r0`. Pin/flag sweep (9x7) best -O4,p at 38 diffs (-O2/-O3 also 38; -O1 164, -O0 225). Three body shapes tried: assignment-in-if, void*-with-cast, function-pointer-value -> 38/38/63 diffs. Capped, register allocation.
 * extra (lane T3, second pass): extra spellings (lane T3, second pass): named local (baseline) 38, assignment-in-if 38, negated assignment-in-if 38, hoisted list local 38, hoisted connection->8 local 38, body-inside-the-if 121, if(callback!=0){body} return 0/1 form 121. The single divergence at +0024 is `cmp r0, #0` (image) vs `movs r2, r0` (ours): the callback pointer's home register is r0 in the image and r2 in ours, so the image's increment temporaries start at r1/r2/r3 and ours at r0/r1. Capped, register allocation.
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
