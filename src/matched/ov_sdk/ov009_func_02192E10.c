/*
 * function: gpiProcessSearches
 * address:  0x02192E10
 * packet:   pkt_ov009_02192E10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessSearches (libdwcgsgp.TWL.HYB.a gpisearch.o)
 *
 * symbols:
 *   gsimalloc  0x0217eab0  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiProcessSearch  0x0219091c  arm   ov009
 *   gpiRemoveOperation  0x0218e240  arm   ov009
 *   gsifree  0x0217eae0  arm   ov009
 *   g_021A5280     0x021a5280  data
 */

typedef struct GPISearchData {
    char pad[0x184];
    int processing;
    int remove;
} GPISearchData;

typedef struct GPIOperation_s {
    int type;
    GPISearchData *data;
    char pad[0xc];
    int state;
    char pad2[4];
    int result;
    struct GPIOperation_s *pnext;
} GPIOperation;

typedef struct {
    char pad[0x238];
    int numSearches;
    char pad2[0x388];
    GPIOperation *operationList;
} GPIConnection;

extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(int *p, int b);
extern int gpiProcessSearch(void **connection, GPIOperation *operation);
struct GPIOperation;
extern void gpiRemoveOperation(void **connection, struct GPIOperation *operation);
extern void gsifree(void *ptr);
extern char g_021A5280[];

int gpiProcessSearches(void **connection)
{
    int i;
    int num;
    int result;
    GPISearchData *data;
    GPIOperation *operation;
    GPIOperation **searchList;
    GPIConnection *iconnection;

    iconnection = (GPIConnection *)*connection;
    num = 0;
    if (iconnection->numSearches > 0) {
        searchList = (GPIOperation **)gsimalloc(iconnection->numSearches * sizeof(GPIOperation *));
        if (searchList == 0) {
            gpiSetErrorString((int *)connection, (int)g_021A5280);
            return 1;
        }
        for (operation = iconnection->operationList; operation != 0; operation = operation->pnext) {
            if (operation->type == 3 && operation->state != 5) {
                if (operation->data->processing == 0) {
                    searchList[num++] = operation;
                    operation->data->processing = 1;
                }
            }
        }
        for (i = 0; i < num; i++) {
            result = gpiProcessSearch(connection, searchList[i]);
            if (result != 0)
                searchList[i]->result = result;
        }
        for (i = 0; i < num; i++) {
            data = searchList[i]->data;
            data->processing = 0;
            if (data->remove)
                gpiRemoveOperation(connection, (struct GPIOperation *)searchList[i]);
        }
        gsifree(searchList);
    }
    return 0;
}
