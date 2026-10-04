/*
 * function: func_02192E10
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
 *   func_0217EAB0  0x0217eab0  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_0219091C  0x0219091c  arm   ov009
 *   func_0218E240  0x0218e240  arm   ov009
 *   func_0217EAE0  0x0217eae0  arm   ov009
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

extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(int *p, int b);
extern int func_0219091C(void **connection, GPIOperation *operation);
extern void func_0218E240(void **connection, GPIOperation *operation);
extern void func_0217EAE0(void *ptr);
extern char g_021A5280[];

int func_02192E10(void **connection)
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
        searchList = (GPIOperation **)func_0217EAB0(iconnection->numSearches * sizeof(GPIOperation *));
        if (searchList == 0) {
            func_02193734((int *)connection, (int)g_021A5280);
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
            result = func_0219091C(connection, searchList[i]);
            if (result != 0)
                searchList[i]->result = result;
        }
        for (i = 0; i < num; i++) {
            data = searchList[i]->data;
            data->processing = 0;
            if (data->remove)
                func_0218E240(connection, searchList[i]);
        }
        func_0217EAE0(searchList);
    }
    return 0;
}
