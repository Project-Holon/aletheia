/*
 * function: func_021DDB38
 * address:  0x021DDB38
 * packet:   pkt_021DDB38
 * region:   ov175
 * status:   EXACT
 * symbols:
 *   sakeiValidateRequestFields  0x021DDB38  arm
 */
typedef struct {
    char *name;
    int type;
    void *p;
    int len;
} ReqField;

int func_021DDB38(ReqField *req, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        if (req[i].name == 0 || *req[i].name == 0)
            return 7;
        if (req[i].type >= 10)
            return 8;
        if (req[i].type == 4 && req[i].p == 0)
            return 9;
        if (req[i].type == 5 && req[i].p == 0)
            return 9;
        if (req[i].type == 8) {
            if (req[i].len < 0)
                return 9;
            if (req[i].p == 0 && req[i].len > 0)
                return 9;
        }
    }
    return 0;
}
