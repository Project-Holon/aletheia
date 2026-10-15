/*
 * function: sakeiFreeOutputRecords
 * address:  0x021DE8AC
 * packet:   pkt_021DE8AC
 * region:   ov175
 * status:   EXACT
 * symbols:
 *   gsifree  0x0217EAE0  arm
 */
typedef struct {
    int f0;
    int type;
    void *p8;
    int f12;
} Ent;

void gsifree(void *p);

void sakeiFreeOutputRecords(int a, int b, Ent **arr)
{
    int i, j;

    if (arr == 0)
        return;
    for (i = 0; i < b; i++) {
        if (arr[i] == 0)
            continue;
        for (j = 0; j < a; j++) {
            if (arr[i][j].type == 8 && arr[i][j].p8 != 0)
                gsifree(arr[i][j].p8);
            if (arr[i][j].type == 5)
                gsifree(arr[i][j].p8);
        }
        gsifree(arr[i]);
        arr[i] = 0;
    }
    gsifree(arr);
}
