/*
 * function: DWCi_GetGT2ConnectionByProfileID
 * address:  0x0216BBDC
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_GetGT2ConnectionByProfileID: the connection slot whose peer profile id matches, or null.
 *
 * symbols:
 *   gDwcConnectionArray  0x021AA8A0  data
 *   gt2GetConnectionData  0x02195E78  arm  ov009
 *   DWCi_GetGT2ConnectionByIdx  0x0216BBCC  arm  ov009
 */

extern int gDwcConnectionArray[];
extern int gt2GetConnectionData(const int *p);
extern int *DWCi_GetGT2ConnectionByIdx(int i);

int *DWCi_GetGT2ConnectionByProfileID(int pid, int flag)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (gDwcConnectionArray[i] != 0 && pid == *(int *)(gt2GetConnectionData((const int *)gDwcConnectionArray[i]) + 4)) {
            return DWCi_GetGT2ConnectionByIdx(i);
        }
    }
    return 0;
}
